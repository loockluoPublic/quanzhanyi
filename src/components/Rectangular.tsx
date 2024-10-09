import * as THREE from "three";
import { CustomVector3 } from "../class/CustomVector3";
import { useMemo } from "react";

const Rectangular = (props: { trianglePoints: CustomVector3[] }) => {
  const trianglePoints = props.trianglePoints ?? [];

  // 创建 BufferGeometry
  const geometry = new THREE.BufferGeometry();

  const drawParams = useMemo(() => {
    const pointsArr: number[] = [];
    const indices: number[] = [];

    trianglePoints?.forEach((p, i) => {
      pointsArr.push(...p.toArray());
      const t = i * 3;
      indices.push(t, t + 1, t + 2);
    });
    const vertices = new Float32Array(pointsArr);

    return {
      vertices,
      indices,
    };
  }, [trianglePoints]);

  // 设置几何体的顶点和索引
  geometry.setAttribute(
    "position",
    new THREE.BufferAttribute(drawParams.vertices, 3)
  );

  geometry.setIndex(drawParams.indices);

  return (
    <mesh>
      <meshBasicMaterial
        color={"#00ff00"}
        side={THREE.DoubleSide}
        opacity={0.5}
        transparent={true}
      />
      <bufferGeometry
        attributes={{
          position: new THREE.BufferAttribute(drawParams.vertices, 3),
        }}
      />
    </mesh>
  );
};

export default Rectangular;
