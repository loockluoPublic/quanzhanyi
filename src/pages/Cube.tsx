import { Canvas } from "@react-three/fiber";
import { OrbitControls, PerspectiveCamera } from "@react-three/drei";
import Rectangular from "../components/Rectangular";

function Cube(props) {
  return (
    <div className=" q-flex q-w-full">
      <Canvas
        dpr={window.devicePixelRatio}
        className={`${props.className} q-grow`}
        style={{ height: props.height }}
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
        <Rectangular></Rectangular>

        <OrbitControls />
      </Canvas>
    </div>
  );
}

export default Cube;
