import { Canvas } from "@react-three/fiber";
import { Html, Line, OrbitControls } from "@react-three/drei";

import "./index.css";
import "../../utils/utils";
import { ReactNode, useEffect, useMemo, useRef, useState } from "react";

import { CustomVector3 } from "../../class/CustomVector3";
import PerspectiveCamera from "./PerspectiveCamera";
import MyCylinder from "./MyCylinder";
import React from "react";
import { Spherical, Vector3 } from "three";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
// import { button, useControls } from "leva";

function PointsLabel(props: {
  points: CustomVector3[];
  style?: React.CSSProperties;
  color?: string;
}) {
  return props?.points?.map((item, i) => {
    if (item instanceof CustomVector3) {
      return (
        <Html position={item.toVector3()} key={`${item.key}_${i}`}>
          <div
            className="q-w-20 relative"
            style={{ "--point-color": props.color } as any}
          >
            {item.label || ""}
            {item.key}
          </div>
        </Html>
      );
    } else {
      return null;
    }
  });
}

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

  return <Line color="#778beb" points={line} />;
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
  const [h, setH] = useState(0);

  const ref = useRef<any>();

  useEffect(() => {
    setH(ref.current?.clientHeight);
  }, []);

  return (
    <div className=" q-flex q-w-full q-h-full q-overflow-hidden" ref={ref}>
      <Canvas
        dpr={window.devicePixelRatio}
        className={`${props.className} q-grow q-cursor-pointer canvas-style`}
        style={{ height: h }}
      >
        <PerspectiveCamera />
        <ambientLight intensity={Math.PI / 2} />
        <axesHelper args={[10]} />
        <spotLight
          position={[10, 10, 10]}
          angle={0.15}
          penumbra={1}
          decay={0}
          intensity={Math.PI}
        />
        <MyCylinder {...props?.calulateRes} />

        <PointsLabel
          points={props?.mPoints
            ?.filter?.((p) => p.enable)
            .filter((p) => p.enable)}
          color="#000"
        />

        {props.direct && <Direct direct={props.direct} />}

        {props.firstPoints?.length > 0 && (
          <PointsLabel points={props.firstPoints} color="red" />
        )}

        {props?.sdm?.includes("A") && (
          <PointsLabel
            points={props?.AB?.map?.((item) => item.pointA)}
            color="red"
          />
        )}

        {props?.sdm?.includes("B") && (
          <PointsLabel
            points={props?.AB?.map?.((item) => item.pointB)}
            color="#fab005"
          />
        )}

        <OrbitControls />
      </Canvas>
      {props?.component && (
        <div
          style={{ maxHeight: h, overflow: "scroll" }}
          className="q-flex-shrink-0 q-flex-grow-0 border-style"
        >
          {props?.component}
        </div>
      )}
    </div>
  );
}
