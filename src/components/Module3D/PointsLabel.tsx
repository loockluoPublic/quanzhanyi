import { Html } from "@react-three/drei";
import { CustomVector3 } from "../../class/CustomVector3";

export default function PointsLabel(props: {
  points: CustomVector3[];
  style?: React.CSSProperties;
  color?: string;
  disabledColor?: string;
}) {
  return props?.points?.map((item) => {
    if (!item) return null;
    const color = item.enable ? props.color : props.disabledColor;
    return (
      <Html position={item.toVector3()} key={item.key}>
        <div
          className="q-w-20 relative"
          style={{ "--point-color": color } as any}
        >
          {item.label || ""}
          {item.key}
        </div>
      </Html>
    );
  });
}
