import React from "react";
import { Canvas } from "@react-three/fiber";
import { Cylinder, Line } from "@react-three/drei";
import * as THREE from "three";
import { CustomVector3 } from "../../class/CustomVector3";

const MyCylinder = (props: any) => {
  console.log("%c Line:7 🍪 props", "color:#33a5ff", props);

  if (!props?.Bottom_round_center) return null;
  //   console.log(
  //     "%c Line:16 🥝 midpoint2",
  //     "color:#fca650",
  //     midpoint2.subVectors(
  //       props?.Bottom_round_center?.[0],
  //       props?.Bottom_round_center?.[1]
  //     )
  //     // props?.mTaon?.normalize?.()
  //   );
  const midpoint = new CustomVector3();

  midpoint.addVectors(
    props?.Bottom_round_center?.[0]?.toVector3(),
    props?.Bottom_round_center?.[1]?.toVector3()
  );

  const height = (props?.Bottom_round_center?.[0] as CustomVector3).distanceTo(
    props?.Bottom_round_center?.[1]
  );

  console.log(
    "%c Line:37 🍰 props?.mTaon",
    "color:#ed9ec7",
    props?.mTaon?.toVector3()?.normalize(),
    midpoint?.toVector3()?.normalize()
  );
  return (
    <>
      <Cylinder
        args={[props.R, props.R, 2, 32, 1, true]}
        position={props?.center?.toVector3() || []} // 设置位置
        rotation={midpoint?.calcRotation()} // 设置旋转
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
          points={
            props?.Bottom_round_center?.map((item: CustomVector3) =>
              item.toVector3()
            ) ?? []
          }
        />
      )}
    </>
  );
};

export default MyCylinder;
