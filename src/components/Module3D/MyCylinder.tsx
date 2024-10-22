import { Cylinder, Line } from "@react-three/drei";
import * as THREE from "three";
import { CustomVector3 } from "../../class/CustomVector3";

const MyCylinder = (props: any) => {
  console.log("%c Line:7 🍪 props", "color:#33a5ff", props);

  if (!props?.Bottom_round_center) return null;

  const midpoint = new CustomVector3();

  midpoint.subVectors(
    props?.Bottom_round_center?.[0]?.toVector3(),
    props?.Bottom_round_center?.[1]?.toVector3()
  );

  const height = (props?.Bottom_round_center?.[0] as CustomVector3).distanceTo(
    props?.Bottom_round_center?.[1]
  );

  console.log(
    "%c Line:26 🍰 props?.center?.toVector3()",
    "color:#6ec1c2",
    props
  );
  return (
    <>
      <Cylinder
        args={[props.R, props.R, height * 1.2, 32, 1, true]}
        position={props?.center?.toVector3() || []} // 设置位置
        rotation={midpoint?.calcRotation() as any} // 设置旋转
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
