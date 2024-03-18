import { Canvas } from "@react-three/fiber";
import { OrbitControls, Html } from "@react-three/drei";
import * as THREE from "three";
import "./index.css";
import "../utils";
import { useMemo, useRef } from "react";

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

const vertices = new Float32Array([
  -1.0,
  -1.0,
  1.0, // v0
  1.0,
  -1.0,
  1.0, // v1
  1.0,
  1.0,
  1.0, // v2

  1.0,
  1.0,
  1.0, // v3
  -1.0,
  1.0,
  1.0, // v4
  -1.0,
  -1.0,
  1.0, // v5
]);

function PointsLabel(props: {
  points: { label: string; position: THREE.Vector3 }[];
}) {
  return props?.points?.map((item) => {
    return (
      <Html position={item.position}>
        <div className="q-w-20 relative">{item.label}</div>
      </Html>
    );
  });
}

export default function Index(props: { className?: string; height: string }) {
  // const value = useControls({
  //   // aNumber: 0,

  //   a指令: "%R1Q,9027:1.5,1.5,0,0,0",
  //   // bluetooth: false,
  //   打开串口: button(connectSerial),
  //   关闭串口: button(() => {
  //     serial.disconnect();
  //   }),
  //   // vector: { v: 0, h: 0 },
  //   发送: button((get) => {
  //     console.log(
  //       "%c Line:135 🍏 发送指令",
  //       "color:#ea7e5c",
  //       `${get("a指令")}`
  //     );
  //     serial.send(`${get("a指令")}\r\n`);
  //   }),
  //   读取: button(() => {
  //     console.log(
  //       "%c Line:135 🍏 发送读取指令",
  //       "color:#ea7e5c",
  //       `%R1Q,2107:2`
  //     );
  //     serial.send(`%R1Q,2107:2\r\n`);
  //   }),
  // });
  // console.log("%c Line:78 🥛 value", "color:#6ec1c2", value);

  // return <div>测试</div>;

  return (
    <>
      <Canvas
        dpr={window.devicePixelRatio}
        className={props.className}
        style={{ height: props.height }}
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
        {/* <Html position={new THREE.Vector3(1, 0, 0)}>
          <div className="q-w-20">第一个点</div>
        </Html> */}
        <Box position={[0, 0, 0]} />
        <PointsLabel
          points={[
            { label: "第1个点", position: new THREE.Vector3(1, 0, 0) },
            { label: "第2个点", position: new THREE.Vector3(1, 1, 0) },
            { label: "第2个点", position: new THREE.Vector3(1, 1, 1) },
            { label: "第2个点", position: new THREE.Vector3(1, 0, 1) },
            { label: "第2个点", position: new THREE.Vector3(0, 1, 0) },
            { label: "第2个点", position: new THREE.Vector3(0, 0, 0) },
            { label: "第2个点", position: new THREE.Vector3(0, 1, 1) },
            { label: "第2个点", position: new THREE.Vector3(0, 0, 1) },
          ]}
        />
        <OrbitControls />
      </Canvas>
    </>
  );
}
