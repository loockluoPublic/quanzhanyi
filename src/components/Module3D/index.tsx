import { Canvas } from "@react-three/fiber";
import { Cylinder, Html, OrbitControls } from "@react-three/drei";
import * as THREE from "three";
import "./index.css";
import "../../utils/utils";
import { useRecoilState } from "recoil";
import { Data } from "../../atom/globalState";
import useMeasure from "../../utils/useMeasure";
import { ReactNode, useEffect, useRef, useState } from "react";
import { GenerateMultiLayeredMeasurementPoints } from "../../utils/utils";
import PointsVector3 from "../PointVector3";
import { pointToAndMeasure } from "../../utils/commond";
import { Tree, message } from "antd";
import { CustomVector3 } from "../../class/CustomVector3";
import { Line } from "@react-three/drei";
import PerspectiveCamera from "./PerspectiveCamera";
import MyCylinder from "./MyCylinder";
import React from "react";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
// import { button, useControls } from "leva";

const pointsData: any = [];
for (let i = 0; i < 10; i++) {
  pointsData.push(new THREE.Vector2(Math.sin(i * 0.2) * 3 + 5, (i - 5) * 2));
}

function Box(props) {
  // This reference gives us direct access to the THREE.Mesh object
  // const ref = useRef()
  // // Hold state for hovered and clicked events
  // const [hovered, hover] = useState(false)
  // const [clicked, click] = useState(false)
  // // Subscribe this component to the render-loop, rotate the mesh every frame
  // useFrame((state, delta) => (ref.current.rotation.x += delta))
  // // Return the view, these are regular Threejs elements expressed in JSX
  return (
    <mesh
      {...props}
      // ref={ref}
      // scale={clicked ? 1.5 : 1}
      // onClick={(event) => click(!clicked)}
      // onPointerOver={(event) => (event.stopPropagation(), hover(true))}
      // onPointerOut={(event) => hover(false)}
    >
      {/* <boxGeometry args={[1, 1, 1]} /> */}
      {/* <cylinderGeometry args={[ 5, 5, 20, 32]} /> */}
      <latheGeometry args={[pointsData]} />
      <points />
      <meshBasicMaterial
        color={"#00aec7"}
        side={THREE.DoubleSide}
        opacity={0.5}
        transparent={true}
      />
    </mesh>
  );
}

function PointsLabel(props: {
  points: CustomVector3[];
  style?: React.CSSProperties;
  color?: string;
}) {
  return props?.points?.map((item) => {
    return (
      <Html position={item.toVector3()} key={item.key}>
        <div
          className="q-w-20 relative"
          style={{ "--point-color": props.color } as any}
        >
          {item.label || ""}
          {item.key}
        </div>
      </Html>
    );
  });
}

export default function Index(props: {
  className?: string;
  height: string;
  mPoints: CustomVector3[];
  loading?: boolean;
  setData?: (md: CustomVector3[]) => void;
  direct?: number[];
  component?: ReactNode;
  pointsShowType?: "points" | "table" | false;
  [k: string]: any;
}) {
  const pointsShowType = props.pointsShowType || false;
  console.log("%c Line:82 🥚 props", "color:#b03734", props);
  const [showPoints, setPoints] = useState<CustomVector3[]>([]);
  const [selectedKeys, setSelectedKeys] = useState<number[]>([]);

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
    setPoints(props.mPoints.map((p) => p.fromCustomVector3()));
    console.log("%c Line:94 🍺 props.points", "color:#6ec1c2", props.points);
  }, [props.mPoints]);

  useEffect(() => {
    const keys = showPoints
      .map((p) => (p.enable ? p.key : null))
      .filter((p) => !!p);
    setSelectedKeys(keys);
    console.log("%c Line:119 🥚 showPoints", "color:#3f7cff", showPoints);
  }, [showPoints]);

  const showPointsDom = () => {
    switch (pointsShowType) {
      case false:
        return null;

      default:
      case "table":
        return (
          <div className="cm-w-[400px]">
            {props.mPoints?.map((item) => {
              return (
                <PointsVector3
                  showGetPoints={false}
                  key={item.key}
                  value={item}
                />
              );
            })}
          </div>
        );
    }
  };

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
        {/* <Box position={[0, 0, 0]} /> */}
        <PointsLabel points={showPoints.filter((p) => p.enable)} color="#000" />

        {props?.sdm?.includes("A") && (
          <PointsLabel
            points={props?.AB?.map?.((item) => item.pointA)}
            color="green"
          />
        )}

        {props?.sdm?.includes("B") && (
          <PointsLabel
            points={props?.AB?.map?.((item) => item.pointB)}
            color="red"
          />
        )}

        {/* {props?.direct?.length > 0 && (
          <Line
            points={[
              new THREE.Vector3().setFromSpherical(
                new THREE.Spherical(1, props.direct[1], props.direct[0])
              ),
              new THREE.Vector3().setFromSpherical(
                new THREE.Spherical(-1, props.direct[1], props.direct[0])
              ),
            ]}
          />
        )} */}

        <OrbitControls />
      </Canvas>
      {props?.component && (
        <div>
          {props?.component}

          {showPointsDom()}
        </div>
      )}
    </div>
  );
}
