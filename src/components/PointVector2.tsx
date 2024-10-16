import { rad2ang } from "../utils/utils";

export default function PointsVector2(props: {
  value?: number[];
  style?: React.CSSProperties;
}) {
  const value = props.value?.map((v) => rad2ang(v).toFixed(2));
  return (
    <span style={props.style}>
      (p: {value?.[0] ?? "--"}°，t: {value?.[1] ?? "--"}° )
    </span>
  );
}
