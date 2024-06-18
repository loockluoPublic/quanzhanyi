import * as THREE from "three";

const Rectangular = () => {
  // 创建 BufferGeometry
  const geometry = new THREE.BufferGeometry();

  // 定义顶点
  const vertices = new Float32Array([
    1,
    1,
    0, // 顶点 A
    -1,
    1,
    0, // 顶点 B
    -1,
    -1,
    0, // 顶点 C
    1,
    -1,
    0, // 顶点 D
  ]);

  // 索引定义三角形面
  const indices = [
    0,
    1,
    2, // 面 ABC
    0,
    2,
    3, // 面 ACD
  ];

  // 设置几何体的顶点和索引
  geometry.setAttribute("position", new THREE.BufferAttribute(vertices, 3));
  geometry.setIndex(indices);

  // 材质
  const material = new THREE.MeshBasicMaterial({
    color: 0x00ff00,
    side: THREE.DoubleSide,
  });

  return <mesh geometry={geometry} material={material} />;
};

export default Rectangular;
