export default function PointsVector2(props: {
  value?: number[];
  style?: React.CSSProperties;
}) {
  return <span style={props.style}>{props?.value?.join?.(",")}</span>;
}
