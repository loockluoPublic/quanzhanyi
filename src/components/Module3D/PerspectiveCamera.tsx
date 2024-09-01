import { PerspectiveCamera } from "@react-three/drei";
import { button, useControls } from "leva";
import { useEffect, useRef } from "react";
import { PerspectiveCamera as PerspectiveCameraType } from "three";
import * as THREE from "three";
import { getLine, goToCV, measureAndGetSimpleCoord } from "../../utils/commond";

export default function Perspective(props) {
  const camera = useRef<PerspectiveCameraType>();
  // const { far, fov, near } = useControls("相机控制", {
  //   fov: { value: 7, min: 1, max: 20 },
  //   near: { value: 0.1, min: 0.1, max: 50 },
  //   far: { value: 100, min: 0.1, max: 100 },
  // });

  useEffect(() => {
    camera.current.updateProjectionMatrix();
  }, []);

  return (
    <PerspectiveCamera
      aspect={2}
      makeDefault
      // far={far}
      // fov={fov}
      // near={near}
      position={[0, 10, 20]}
      // updateProjectionMatrix={new THREE.Matrix4().makeScale(-1, 1, 1)}
      // projectionMatrix={new THREE.Matrix4().makeScale(-1, -1, -1)}
      ref={camera}
      {...props}
    />
  );
}
