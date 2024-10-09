import { PerspectiveCamera } from "@react-three/drei";
import { button, useControls } from "leva";
import { useEffect, useRef } from "react";
import { PerspectiveCamera as PerspectiveCameraType } from "three";
import * as THREE from "three";
import { getLine, goToCV, measureAndGetSimpleCoord } from "../../utils/commond";

const leftHandedMatrix = new THREE.Matrix4();
leftHandedMatrix.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -10, 0, 0, 0, 0, 1);

export default function Perspective(props) {
  const camera = useRef<PerspectiveCameraType>();

  return (
    <PerspectiveCamera
      aspect={2}
      makeDefault
      // far={far}
      // fov={fov}
      // near={near}
      position={[5, 5, -5]}
      ref={camera}
      {...props}
    />
  );
}
