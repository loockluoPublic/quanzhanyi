import { PerspectiveCamera } from "@react-three/drei";

import { useRef } from "react";
import { PerspectiveCamera as PerspectiveCameraType } from "three";

export default function Perspective(props) {
  const camera = useRef<PerspectiveCameraType>();

  return (
    <PerspectiveCamera
      aspect={2}
      makeDefault
      position={[5, 5, -5]}
      ref={camera}
      {...props}
    />
  );
}
