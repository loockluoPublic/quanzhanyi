import { Vector3 } from "three";

export default function PointsVector3(props: {
  value?: Vector3;
  style?: React.CSSProperties;
}) {
  return (
    <span style={props.style}>
      <span>x:</span>
      <span>{props?.value?.x?.toFixed(3)}</span>
      <span> y:</span>
      <span>{props?.value?.y?.toFixed(3)}</span>
      <span> z:</span>
      <span>{props?.value?.z?.toFixed(3)}</span>
    </span>
  );
}
