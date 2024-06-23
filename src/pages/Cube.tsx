import { Canvas } from "@react-three/fiber";
import { OrbitControls, PerspectiveCamera } from "@react-three/drei";
import Rectangular from "../components/Rectangular";
import CubePoints from "../components/CubePoints";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { CustomVector3 } from "../class/CustomVector3";

function Cube(props: { pointsKeys: string }) {
  const [data] = useRecoilState(Data);

  return (
    <div className=" q-flex q-w-full">
      <Canvas
        dpr={window.devicePixelRatio}
        className={` q-grow q-h-full`}
        style={{ height: "500px" }}
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
        <Rectangular
          trianglePoints={data.trianglePoints as CustomVector3[]}
        ></Rectangular>

        <OrbitControls />
      </Canvas>
      <div className=" q-w-[400px]">
        <CubePoints pointsKeys={props.pointsKeys} />
      </div>
    </div>
  );
}

export default Cube;
