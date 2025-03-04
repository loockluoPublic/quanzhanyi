import { Canvas } from "@react-three/fiber";
import { Html, Line, OrbitControls } from "@react-three/drei";
import * as THREE from "three";

import "./index.css";
import "../../utils/utils";
import { ReactNode, useEffect, useMemo, useRef, useState } from "react";

import { CustomVector3 } from "../../class/CustomVector3";
import PerspectiveCamera from "./PerspectiveCamera";
import MyCylinder from "./MyCylinder";
import React from "react";
import PointsLabel from "./PointsLabel";
import { useRecoilState, useRecoilValue } from "recoil";
import { ShowLabel } from "../../atom/globalState";
import { Switch } from "antd";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
// import { button, useControls } from "leva";

const Direct = (props: { direct: number[] }) => {
  const line = useMemo(() => {
    if (
      typeof props.direct[0] === "number" &&
      typeof props.direct[1] === "number"
    ) {
      return [
        new CustomVector3()
          .fromSpherical(-1, props.direct[1], props.direct[0])
          .toVector3(),
        new CustomVector3()
          .fromSpherical(1, props.direct[1], props.direct[0])
          .toVector3(),
      ];
    } else {
      return null;
    }
  }, [props.direct]);

  if (!line) return null;

  console.log("%c Line:64 🍻 line", "color:#93c0a4", line);
  return (
    <Line color="#778beb" points={line} side={THREE.DoubleSide} lineWidth={2} />
  );
};

export default function Index(props: {
  className?: string;
  mPoints?: CustomVector3[];
  loading?: boolean;
  direct?: number[];
  firstPoints?: CustomVector3[];
  component?: ReactNode;
  [k: string]: any;
}) {
  const [v, setV] = useRecoilState(ShowLabel);
  const [h, setH] = useState(0);

  const ref = useRef<any>();

  useEffect(() => {
    setH(ref.current?.clientHeight);
  }, []);

  return (
    <div
      className=" q-flex q-w-full q-h-full q-overflow-hidden q-relative"
      ref={ref}
    >
      <Canvas
        dpr={window.devicePixelRatio}
        className={`${props.className} q-grow q-cursor-pointer canvas-style`}
        style={{ height: h }}
      >
        <PerspectiveCamera />
        <group scale={[1, 1, -1]}>
          <ambientLight intensity={Math.PI / 2} />
          <spotLight
            position={[10, 10, 10]}
            angle={0.15}
            penumbra={1}
            decay={0}
            intensity={Math.PI}
          />
          <axesHelper args={[10]} />
          <MyCylinder {...props?.calulateRes} />

          <PointsLabel
            points={props?.mPoints}
            color="#000"
            disabledColor="#ccc"
            showLabel={v}
          />
          {props.firstPoints?.length > 0 && (
            <PointsLabel points={props.firstPoints} color="red" showLabel={v} />
          )}

          {props.points?.length > 0 && (
            <PointsLabel points={props.points} color="red" showLabel={v} />
          )}
        </group>
        <OrbitControls />
      </Canvas>
      {props?.component && (
        <div
          style={{ maxHeight: h, overflow: "auto" }}
          className="q-flex-shrink-0 q-flex-grow-0 border-style"
        >
          {props?.component}
        </div>
      )}
      <div className="q-absolute q-bottom-0 q-left-0 q-p-2">
        <Switch
          checkedChildren="标签"
          unCheckedChildren="标签"
          checked={v}
          onChange={(v) => {
            setV(v);
          }}
        />
      </div>
    </div>
  );
}
