import { PerspectiveCamera } from "@react-three/drei";
import { button, useControls } from "leva";
import { useEffect, useRef } from "react";
import { PerspectiveCamera as PerspectiveCameraType } from "three";
import * as THREE from "three";
import { getLine, goToCV, measureAndGetSimpleCoord } from "../../utils/commond";

export default function Perspective(props) {
  const camera = useRef<PerspectiveCameraType>();
  const { far, fov, near } = useControls("相机控制", {
    fov: { value: 7, min: 1, max: 20 },
    near: { value: 0.1, min: 0.1, max: 50 },
    far: { value: 100, min: 0.1, max: 100 },
  });

  const [{ 转向点 }, set, get] = useControls("全站仪控制", () => ({
    转向点: {
      x: 0,
      y: 0,
      z: 0,
    },
    转向并测量: button(() => {
      const v = get("转向点");
      console.log("%c Line:25 🍅 v", "color:#42b983", v);
      goToCV(v.x, v.y, v.z)
        .then(() => {
          return measureAndGetSimpleCoord();
        })
        .then((res) => {
          set({
            测量结果: {
              x: res.x,
              y: res.y,
              z: res.z,
            },
          });
        })
        .then(() => {
          return getLine();
        })
        .then((res: [number, number]) => {
          set({
            测量角度: {
              p: res[0],
              h: res[1],
            },
          });
        });
    }),
    测量结果: { x: 0, y: 0, z: 0 },
    测量角度: { p: 0, h: 0 },
  }));

  useEffect(() => {
    camera.current.updateProjectionMatrix();
  }, []);

  return (
    <PerspectiveCamera
      aspect={2}
      far={far}
      fov={fov}
      makeDefault
      near={near}
      position={[0, 10, 20]}
      // updateProjectionMatrix={new THREE.Matrix4().makeScale(-1, 1, 1)}
      // projectionMatrix={new THREE.Matrix4().makeScale(-1, -1, -1)}
      ref={camera}
      {...props}
    />
  );
}
