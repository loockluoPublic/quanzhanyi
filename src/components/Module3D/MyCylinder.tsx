import { Cylinder, Line } from "@react-three/drei";
import * as THREE from "three";
import { CustomVector3 } from "../../class/CustomVector3";
import { useMemo } from "react";

const MyCylinder = (props: any) => {
  if (!props?.Bottom_round_center) return null;

  const midpoint = new CustomVector3();

  midpoint.subVectors(
    props?.Bottom_round_center?.[0]?.toVector3(),
    props?.Bottom_round_center?.[1]?.toVector3()
  );

  const center = useMemo(() => {
    return new CustomVector3(
      (props?.Bottom_round_center?.[0]?.x +
        props?.Bottom_round_center?.[1]?.x) /
        2,
      (props?.Bottom_round_center?.[0]?.y +
        props?.Bottom_round_center?.[1]?.y) /
        2,
      (props?.Bottom_round_center?.[0]?.z +
        props?.Bottom_round_center?.[1]?.z) /
        2
    );
  }, [props?.Bottom_round_center]);

  const height = (props?.Bottom_round_center?.[0] as CustomVector3).distanceTo(
    props?.Bottom_round_center?.[1]
  );

  // 计算旋转四元数
  const axis = new THREE.Vector3(0, 1, 0); // 默认朝向为 y 轴
  const quaternion = new THREE.Quaternion().setFromUnitVectors(
    axis,
    midpoint.clone().normalize()
  );

  return (
    <>
      <Cylinder
        args={[props.R, props.R, height * 1.2, 32, 1, true]}
        position={center?.toVector3()} // 设置位置
        quaternion={quaternion}
      >
        <meshStandardMaterial
          color={"#00aec7"}
          side={THREE.DoubleSide}
          opacity={0.7}
          transparent={true}
        />
      </Cylinder>
      {props?.Bottom_round_center && (
        <Line
          side={THREE.DoubleSide}
          color="blue"
          points={
            props?.Bottom_round_center?.map((item: CustomVector3) =>
              item.toVector3()
            ) ?? []
          }
          lineWidth={2}
        />
      )}
    </>
  );
};

export default MyCylinder;
