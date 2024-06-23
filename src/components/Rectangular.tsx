import * as THREE from "three";
import { CustomVector3 } from "../class/CustomVector3";
import { useMemo } from "react";
const id = [0, 1, 2];

const ar = [
  0.5162918275161452, 0.00723298974618225, 0.9857370008742805,
  0.5326985796083867, 0.00723298974618225, 0.015341215153180876,
  0.5523981665029891, 0.9943921959776958, 0.015341215153180876,
];

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

    console.log(
      "%c Line:34 🍧 trianglePoints",
      "color:#93c0a4",
      trianglePoints
    );
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
