import { Canvas } from "@react-three/fiber";
import { Html, OrbitControls } from "@react-three/drei";
import * as THREE from "three";
// import "./index.css";
import "../utils/utils";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef, useState } from "react";
import { GenerateMultiLayeredMeasurementPoints } from "../utils/utils";
import PointsVector3 from "./PointVector3";
import { pointToAndMeasure } from "../utils/commond";
import { Tree, message } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { Line } from "@react-three/drei";

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

function PointsLabel(props: { points: CustomVector3[] }) {
  return props?.points?.map((item) => {
    return (
      <Html position={item.toVector3()} key={item.key}>
        <div className="q-w-20 relative">
          {item.key}-{item.label}
        </div>
      </Html>
    );
  });
}

export default function Index(props: {
  className?: string;
  height: string;
  points: CustomVector3[];
  loading?: boolean;
  setData?: (md: CustomVector3[]) => void;
}) {
  const [showPoints, setPoints] = useState<CustomVector3[]>([]);
  const [selectedKeys, setSelectedKeys] = useState<number[]>([]);

  const getShowPoints = () => {
    return showPoints
      .filter((p) => p.enable)
      ?.map((p) => p.fromCustomVector3());
  };

  useEffect(() => {
    if (!props.loading) {
      props?.setData?.(getShowPoints());
    }
  }, [props.loading]);

  useEffect(() => {
    // props 不允许更改，必须重新创建对象
    setPoints(props.points.map((p) => p.fromCustomVector3()));
    console.log("%c Line:94 🍺 props.points", "color:#6ec1c2", props.points);
  }, [props.points]);

  useEffect(() => {
    const keys = showPoints
      .map((p) => (p.enable ? p.key : null))
      .filter((p) => !!p);
    setSelectedKeys(keys);
  }, [showPoints]);

  return (
    <div className=" q-flex q-w-full">
      <Canvas
        dpr={window.devicePixelRatio}
        className={`${props.className} q-grow`}
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
        <Box position={[0, 0, 0]} />
        <PointsLabel points={showPoints.filter((p) => p.enable)} />
        <OrbitControls />
      </Canvas>
      <div className=" q-w-[300px]">
        <Tree
          checkable
          checkedKeys={selectedKeys}
          multiple={true}
          titleRender={(nodeData) => {
            return <PointsVector3 key={nodeData.key} value={nodeData} />;
          }}
          treeData={showPoints}
          onCheck={(sk) => {
            showPoints.forEach((p) => {
              p.setEnable((sk as any).includes(p.key));
            });
            props?.setData?.(getShowPoints());
            setPoints([...showPoints]);
          }}
        />
      </div>
    </div>
  );
}
