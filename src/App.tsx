import { useEffect, useRef, useState } from "react";
import { Canvas, useFrame } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import * as THREE from "three";
import "./utils";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
import { button, useControls } from "leva";
import SerialMonitor from "@ridge18/web-serial-monitor";

const serial = new SerialMonitor({ mode: "text", parseLines: true });

const points = [];
for (let i = 0; i < 10; i++) {
  points.push(new THREE.Vector2(Math.sin(i * 0.2) * 3 + 5, (i - 5) * 2));
}

const connectSerial = () => {
  const handleSerialEvent = (ev) => {
    console.log(ev.detail);
  };
  serial.addEventListener("serial-connected", handleSerialEvent);

  serial.addEventListener("serial-disconnected", handleSerialEvent);

  serial.addEventListener("serial-error", handleSerialEvent);

  serial.addEventListener("serial-data", handleSerialEvent);

  // This will open a browser dialog which prompts the user to select a serial device.
  // If no device is selected, then a serial-error event is fired.
  serial
    .connect(19200)
    .then(() => {
      // connect at 57600 bauds rate.
      serial.send("Hello serial\n");
    })
    .catch(() => {
      console.log("Something went wrong...");
    });

  serial.disconnect();
};
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
      <latheGeometry args={[points]} />
      <meshBasicMaterial
        color={"#00aec7"}
        side={THREE.DoubleSide}
        opacity={0.5}
        transparent={true}
      />
    </mesh>
  );
}

export default function App() {
  const { name, aNumber, bluetooth } = useControls({
    // aNumber: 0,

    a指令: "%R1Q,9027:1.5,1.5,0,0,0",
    // bluetooth: false,
    打开串口: button(connectSerial),
    关闭串口: button(() => {
      serial.disconnect();
    }),
    // vector: { v: 0, h: 0 },
    发送: button((get) => {
      console.log(
        "%c Line:135 🍏 发送指令",
        "color:#ea7e5c",
        `${get("a指令")}`
      );
      serial.send(`${get("a指令")}\r\n`);
    }),
    读取: button((get) => {
      console.log(
        "%c Line:135 🍏 发送读取指令",
        "color:#ea7e5c",
        `%R1Q,2107:2`
      );
      serial.send(`%R1Q,2107:2\r\n`);
    }),
  });

  return <div>测试</div>;

  // return (
  //   <>
  //     <Canvas dpr={window.devicePixelRatio}>
  //       <ambientLight intensity={Math.PI / 2} />
  //       <axesHelper args={[10]} />
  //       <spotLight
  //         position={[10, 10, 10]}
  //         angle={0.15}
  //         penumbra={1}
  //         decay={0}
  //         intensity={Math.PI}
  //       />

  //       <Box position={[0, 0, 0]} />
  //       <OrbitControls />
  //     </Canvas>
  //   </>
  // );
}
