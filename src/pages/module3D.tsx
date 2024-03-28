import { Canvas } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import * as THREE from "three";
import "./index.css";
import "../utils/utils";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef } from "react";
import { GenerateMultiLayeredMeasurementPoints } from "../utils/utils";
import PointsVector3 from "../components/PointVector3";
import { pointToAndMeasure } from "../utils/commond";
import { message } from "antd";

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

// function PointsLabel(props: {
//   points: { label: string; position: CustomVector3 }[];
// }) {
//   return props?.points?.map((item) => {
//     console.log("%c Line:79 🍪 item.position", "color:#7f2b82", item.position);
//     return (
//       <Html position={item.position.toVector3()}>
//         <div className="q-w-20 relative">{item.label}</div>
//       </Html>
//     );
//   });
// }

export default function Index(props: { className?: string; height: string }) {
  // const [data, setData] = useRecoilState(Data);

  // const points = [...(data?.firstPoints ?? []), ...(data?.points ?? [])]?.map?.(
  //   (p, i) => {
  //     return {
  //       label: `第${i + 1}个点`,
  //       position: p,
  //     };
  //   }
  // );

  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:15 🥔 data", "color:#ed9ec7", data);

  const { measure, loading, points } = useMeasure();

  const flag = useRef(true);
  useEffect(() => {
    if (flag.current) {
      flag.current = false;
      const waitingPoints2 = GenerateMultiLayeredMeasurementPoints(
        data.mdPoints,
        data.layNum,
        data.numPerLay,
        data.firstPoints[0],
        data.firstPoints[1]
      );
      setData({
        ...data,
        waitingPoints2,
      });
      measure(waitingPoints2);
    }
  }, []);

  useEffect(() => {
    if (!loading && points.length > 0) {
      setData({
        ...data,
        mPoints2: points,
      });
    }
  }, [loading, points]);

  if (data)
    return (
      <>
        {" "}
        {loading ? "测量中。。。。" : "测量完成"}
        <h3>待测量方向点</h3>
        <div className="q-overflow-y-scroll">
          {data?.waitingPoints?.map((value, i) => {
            return (
              <div key={`${i}-${value.x}`}>
                <PointsVector3 value={value} />
              </div>
            );
          })}
        </div>
        <h3>已经测量数据</h3>
        <div className=" q-overflow-y-scroll">
          {points?.map((value, i) => {
            return (
              <div
                className=" q-cursor-pointer"
                key={`${i}-${value.x}`}
                onClick={() => {
                  pointToAndMeasure(value).then((res) => {
                    message.success(JSON.stringify(res), 5);
                  });
                }}
              >
                <PointsVector3 value={value} />
              </div>
            );
          })}
        </div>
      </>
    );

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
        <Box position={[0, 0, 0]} />
        {/* <PointsLabel points={points} /> */}
        <OrbitControls />
      </Canvas>
    </>
  );
}
