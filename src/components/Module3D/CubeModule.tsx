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
import { Switch } from "antd";
import { useRecoilState, useRecoilValue } from "recoil";
import { Data, ShowCube, ShowLabel } from "../../atom/globalState";
import Cube2D from "../Cube2D";

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
  const [data] = useRecoilState(Data);
  const showCube = useRecoilValue(ShowCube);
  const [v, setV] = useRecoilState(ShowLabel);
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
    <div
      className=" q-flex q-w-full q-h-full q-overflow-hidden q-relative"
      ref={ref}
    >
      {showCube ? (
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
                  showLabel={v}
                />
              );
            })}

            {props.firstPoints?.length > 0 && (
              <PointsLabel
                points={props.firstPoints}
                color="red"
                showLabel={v}
              />
            )}

            {props.points?.length > 0 && (
              <PointsLabel points={props.points} color="red" showLabel={v} />
            )}
          </group>

          <OrbitControls />
        </Canvas>
      ) : (
        <Cube2D
          width={data.cubeResult?.b}
          height={data.cubeResult?.h}
          tris={data.cubeResult?.LenDaoJiao}
        />
      )}

      {props?.component && (
        <div
          style={{ maxHeight: h, overflow: "scroll" }}
          className="q-flex-shrink-0 q-flex-grow-0  border-style"
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

// export default () => {
//   const [data] = useRecoilState(Data);
//   const [showCube] = useRecoilState(ShowCube);

//   if (showCube) return <Index />;

//   return (
//     <Cube2D
//       width={data.cubeResult.b}
//       height={data.cubeResult.w}
//       tris={data.cubeResult.LenDaoJiao}
//     />
//   );
// };
