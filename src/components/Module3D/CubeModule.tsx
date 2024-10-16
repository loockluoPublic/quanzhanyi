import { Canvas } from "@react-three/fiber";
import { Cylinder, Html, OrbitControls } from "@react-three/drei";
import * as THREE from "three";
import "./index.css";
import "../../utils/utils";

import { ReactNode, useEffect, useRef, useState } from "react";

import { CustomVector3 } from "../../class/CustomVector3";

import PerspectiveCamera from "./PerspectiveCamera";

import React from "react";
import Rectangular from "../Rectangular";
import PointsLabel from "./PointsLabel";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
// import { button, useControls } from "leva";

const MxColor = [
  "#5352ed",
  "#e74c3c",
  "#1e90ff",
  "#e67e22",
  "#1e90ff",
  "#7bed9f",
  "#f39c12",
  "#9b59b6",
];

const pointsData: any = [];
for (let i = 0; i < 10; i++) {
  pointsData.push(new THREE.Vector2(Math.sin(i * 0.2) * 3 + 5, (i - 5) * 2));
}

// function PointsLabel(props: {
//   points: CustomVector3[];
//   style?: React.CSSProperties;
//   color?: string;
//   disabledColor?: string;
// }) {
//   return props?.points?.map((item) => {
//     if (!item) return null;
//     const color = item.enable ? props.color : props.disabledColor;
//     return (
//       <Html position={item.toVector3()} key={item.key}>
//         <div
//           className="q-w-20 relative"
//           style={{ "--point-color": color } as any}
//         >
//           {item.label || ""}
//           {item.key}
//         </div>
//       </Html>
//     );
//   });
// }

export default function Index(props: {
  className?: string;
  MxPoints?: Record<string, CustomVector3[]>;
  loading?: boolean;
  setData?: (md: CustomVector3[]) => void;
  direct?: number[];
  component?: ReactNode;
  pointsShowType?: "points" | "table" | false;
  trianglePoints?: CustomVector3[];
  [k: string]: any;
}) {
  const [showPoints, setPoints] = useState<CustomVector3[]>([]);

  const [h, setH] = useState(0);

  const ref = useRef<any>();

  const getShowPoints = () => {
    return showPoints
      .filter((p) => p.enable)
      ?.map((p) => p.fromCustomVector3());
  };

  useEffect(() => {
    if (!props.loading) {
      const md = getShowPoints();
      if (md?.length > 0) props?.setData?.(md);
    }
  }, [props.loading]);

  useEffect(() => {
    // props 不允许更改，必须重新创建对象
    setPoints(props.mPoints?.map?.((p) => p.fromCustomVector3()) ?? []);
  }, [props.mPoints]);

  useEffect(() => {
    const keys = showPoints
      .map((p) => (p.enable ? p.key : null))
      .filter((p) => !!p);
  }, [showPoints]);

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
        <group scale={[1, 1, -1]}>
          <axesHelper args={[10]} />
          <ambientLight intensity={Math.PI / 2} />
          <spotLight
            position={[10, 10, 10]}
            angle={0.15}
            penumbra={1}
            decay={0}
            intensity={Math.PI}
          />

          <Rectangular
            trianglePoints={props.trianglePoints as CustomVector3[]}
          ></Rectangular>

          {Object.values(props.MxPoints ?? [])?.map((pArr, i) => {
            return (
              <PointsLabel
                key={i}
                points={pArr}
                color={MxColor[i]}
                disabledColor="#ccc"
              />
            );
          })}

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
        </group>

        <OrbitControls />
      </Canvas>
      {props?.component && (
        <div
          style={{ maxHeight: h, overflow: "scroll" }}
          className="q-flex-shrink-0 q-flex-grow-0  border-style"
        >
          {props?.component}
        </div>
      )}
    </div>
  );
}
