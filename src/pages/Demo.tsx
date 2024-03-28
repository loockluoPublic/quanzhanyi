import { Canvas } from "@react-three/fiber";
import { Html, OrbitControls } from "@react-three/drei";
import * as THREE from "three";
import "./index.css";
import "../utils/utils";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef, useState } from "react";
import { GenerateMultiLayeredMeasurementPoints } from "../utils/utils";
import PointsVector3 from "../components/PointVector3";
import { pointToAndMeasure } from "../utils/commond";
import { message } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { Spherical } from "three";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
// import { button, useControls } from "leva";

const pointsData = [];
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

// const vertices = new Float32Array([
//   -1.0,
//   -1.0,
//   1.0, // v0
//   1.0,
//   -1.0,
//   1.0, // v1
//   1.0,
//   1.0,
//   1.0, // v2

//   1.0,
//   1.0,
//   1.0, // v3
//   -1.0,
//   1.0,
//   1.0, // v4
//   -1.0,
//   -1.0,
//   1.0, // v5
// ]);

function PointsLabel(props: {
  points: { label: string; position: CustomVector3 }[];
}) {
  return props?.points?.map((item) => {
    console.log("%c Line:79 🍪 item.position", "color:#7f2b82", item.position);
    return (
      <Html position={item.position.toVector3()}>
        <div className="q-w-20 relative">{item.label}</div>
      </Html>
    );
  });
}

const ps = [
  { label: `x`, position: new CustomVector3(1, 0, 0) },
  { label: `y`, position: new CustomVector3(0, 1, 0) },
  { label: `z`, position: new CustomVector3(0, 0, 1) },
  { label: `-x`, position: new CustomVector3(-1, 0, 0) },
  { label: `-y`, position: new CustomVector3(0, -1, 0) },
  { label: `-z`, position: new CustomVector3(0, 0, -1) },
];
const log = ps.map((item) => {
  return {
    label: item.label,
    ...item.position.toSpherical(),
  };
});
console.table(log);

export default function Index(props: { className?: string; height?: string }) {
  // const [data, setData] = useRecoilState(Data);
  const [p, setP] = useState([]);

  const points = ps;

  setTimeout(() => {
    setP(
      window.s.map((i) => {
        return { label: `.`, position: i };
      })
    );
  }, 1000);

  return (
    <>
      <Canvas
        dpr={window.devicePixelRatio}
        className={props.className}
        style={{ height: props.height ?? "500px" }}
      >
        <ambientLight intensity={Math.PI / 2} />
        <axesHelper args={[10]} />
        <spotLight
          position={[10, 10, 10]}
          angle={0.15}
          penumbra={1}
          decay={0}
          intensity={Math.PI}
        />
        {/* <Box position={[0, 0, 0]} /> */}
        <PointsLabel points={p} />
        <OrbitControls />
      </Canvas>
    </>
  );
}
