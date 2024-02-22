import { useEffect, useRef, useState } from "react";
import { Canvas, useFrame } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import * as THREE from "three";

// https://demo.vidol.chat/demos/leva
// https://github.com/rdmclin2/fe-demos/blob/master/src/pages/demos/leva/panel.tsx
import { button, useControls } from "leva";
import SerialMonitor from "@ridge18/web-serial-monitor";

const serial = new SerialMonitor({ mode: "text", parseLines: true });

const points = [];
for (let i = 0; i < 10; i++) {
  points.push(new THREE.Vector2(Math.sin(i * 0.2) * 3 + 5, (i - 5) * 2));
}

console.log(points);

async function blList() {
  navigator.bluetooth
    .requestDevice({
      filters: [{ services: [0xffe0] }],
    })
    .then((device) => {
      console.log("已连接到设备: " + device.name);
      return device.gatt.connect();
    })
    .then((server) => {
      return server.getPrimaryServices();
    })
    .then((services) => {
      console.log("已发现的service:");
      services.forEach((service) => {
        console.log("Service UUID: " + service.uuid, service);
      });
    })
    .catch((error) => {
      console.log("连接蓝牙设备时出错: " + error);
    });
  // navigator.bluetooth
  //   .requestDevice({
  //     // 蓝牙名称前缀
  //     filters: [{ namePrefix: "vivo" }],
  //     // 蓝牙uuid
  //     optionalServices: [0xffe0],
  //   })
  //   .then(async (device) => {
  //     console.log("Name: " + device.name, device);
  //     // 连接设备
  //     let server = await device.gatt.connect();
  //     console.log(`server`, server);
  //     // 获取蓝牙uuid相关内容
  //     let service = await server.getPrimaryService(0xffe0);
  //     console.log(`service`, service);
  //     // 获取可以读写字符流的服务
  //     let characteristic = await service.getCharacteristic(0xffe1);
  //     // 写入字节(括号中的方法为把字符串转为字符流,传输给蓝牙)
  //     characteristic.writeValue(
  //       new Uint8Array(new TextEncoder("utf-8").encode("大师兄"))
  //     );
  //   })
  //   .catch(function (error) {
  //     // 监听错误
  //     console.log("Something went wrong. " + error);
  //   });
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

const uuid = "6e400001-b5a3-f393-e0a9-e50e24dcca9e";
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

  const getB = () => {
    const deviceOptions = {
      optionalServices: [
        "00001f10-0000-1000-8000-00805f9b34fb",
        "00010203-0405-0607-0809-0a0b0c0d1912",
        "ebe0ccb0-7a0a-4b0c-8a1a-6ff2997da3a6",
        "22210000-554a-4546-5542-46534450464d",
        0x180a,
        0x181c,
        0x181e,
        0xfe95,
        0x1f10,
        0x1f11,
        0x181a,
        0xfff9,
        0xfdcd,
        0xffe0,
        0xfcd2,
      ],
      services: [
        0x180a, 0x181c, 0x181e, 0xfe95, 0x1f10, 0x1f11, 0x181a, 0xfff9, 0xfcd2,
        0xfdcd, 0xffe0,
      ],
      acceptAllDevices: true,
    };
    navigator.bluetooth
      .requestDevice(deviceOptions)
      .then(async function (device) {
        console.log("名称：" + device.name);

        device.addEventListener("gattserverdisconnected", () => {
          console.log("%c Line:84 🥥 gattserverdisconnected", "color:#f5ce50");
        });

        // device.gatt
        //   .connect()
        //   .then((server) => {
        //     console.log("Found GATT server");

        //     console.log("%c Line:92 🍏 server", "color:#fca650", server);
        //     return server.getPrimaryServices();
        //   })
        //   .then((services) => {
        //     console.log("%c Line:96 🍌 services", "color:#f5ce50", services);

        //     return service.getCharacteristic(
        //       "00001f1f-0000-1000-8000-00805f9b34fb"
        //     );
        //   })
        //   .then((characteristic) => {
        //     // 发送数据
        //     let data = new TextEncoder().encode("helloworld");
        //     return characteristic.writeValue(data);
        //   })
        //   .then(() => {
        //     console.log("数据成功发送到蓝牙设备");
        //   })
        //   .catch((error) => {
        //     console.error("发送数据时出现错误:", error);
        //   });

        // try {
        //   // 连接到 GATT 服务器
        //   const server = await device.gatt.connect();

        //   // 获取所有服务
        //   const services = await server.getPrimaryServices();

        //   // 遍历服务，输出服务 UUID
        //   services.forEach((service) => {
        //     console.log("服务 UUID:", service.uuid);
        //   });

        //   // 获取第一个服务
        //   const service = services[0];

        //   // 获取服务中的所有特征
        //   const characteristics = await service.getCharacteristics();

        //   // 遍历特征，输出特征 UUID
        //   characteristics.forEach((characteristic) => {
        //     console.log("特征 UUID:", characteristic.uuid);
        //   });

        //   console.log("获取服务和特征成功！");
        // } catch (error) {
        //   console.error("出现错误：", error);
        // }
      })
      .catch(function (error) {
        console.log("出现错误： " + error);
      });
  };

  // useEffect(()=>{
  //   console.log("bluetooth： " + bluetooth);
  //   if(bluetooth){
  //     getB()
  //   }
  // },[bluetooth])
  return (
    <>
      {/* <button onClick={blList}>打开蓝牙</button>
      <button onClick={connectSerial}>打开串口</button> */}
      <Canvas dpr={window.devicePixelRatio}>
        <ambientLight intensity={Math.PI / 2} />
        <axesHelper args={[10]} />
        <spotLight
          position={[10, 10, 10]}
          angle={0.15}
          penumbra={1}
          decay={0}
          intensity={Math.PI}
        />

        <Box position={[0, 0, 0]} />
        <OrbitControls />
      </Canvas>
    </>
  );
}
