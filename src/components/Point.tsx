import { Tooltip } from "antd";
import { goToCV } from "../utils/commond";

export const Point = (props) => {
  const v = props.p;

  if (typeof v?.x === "number") {
    const name = v.label + v.key;
    return (
      <div className={props.className}>
        <Tooltip
          autoAdjustOverflow
          title={`${name} (${v.x.toFixed(4)}, ${v.y.toFixed(4)}, ${v.z.toFixed(
            3
          )})`}
        >
          <a
            className="q-cursor-pointer visited:q-text-gray-50"
            onClick={() => goToCV(v.x, v.y, v.z)}
          >
            {name}
          </a>
        </Tooltip>
      </div>
    );
  }
  return null;
};
