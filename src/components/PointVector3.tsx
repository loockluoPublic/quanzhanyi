import { Button } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { measureAndGetSimpleCoord } from "../utils/commond";
import { MinusCircleOutlined } from "@ant-design/icons";
import { useEffect, useState } from "react";

export default function PointsVector3(props: {
  value?: CustomVector3;
  style?: React.CSSProperties;
  showGetPoints?: boolean;
  onChange?: (v: CustomVector3) => void;
  remove?: () => void;
  autoMeasure?: boolean;
  className?: string;
}) {
  const { showGetPoints = true, value } = props;

  const [loading, setLoading] = useState(false);
  const getPoints = () => {
    setLoading(true);
    measureAndGetSimpleCoord()
      .then((res) => {
        props.onChange?.(res);
      })
      .finally(() => {
        setLoading(false);
      });
  };
  useEffect(() => {
    !props.value && props.autoMeasure && getPoints();
  }, []);

  let w = 200;

  if (showGetPoints) {
    w = w + 50;
  }
  if (props.remove) {
    w = w + 30;
  }

  return (
    <div
      className={"q-flex q-justify-between q-my-2 " + props.className}
      style={{ width: `${w}px` }}
    >
      <span style={props.style}>
        <span>{`${props?.value?.label || ""}${props?.value?.key ?? ""}`}</span>
        <span>
          （
          {`${props?.value?.x?.toFixed(3) ?? "--"}, ${
            props?.value?.y?.toFixed(3) ?? "--"
          }, ${props?.value?.z?.toFixed(3) ?? "--"}`}
          ）
        </span>
      </span>
      {(showGetPoints || props.remove) && (
        <span>
          {props.remove && (
            <MinusCircleOutlined
              style={{ marginLeft: "10px" }}
              className="dynamic-delete-button"
              onClick={props.remove}
            />
          )}

          {showGetPoints && (
            <Button
              style={{ marginLeft: "10px" }}
              type="primary"
              onClick={getPoints}
              loading={loading}
              size="small"
            >
              采集
            </Button>
          )}
        </span>
      )}
    </div>
  );
}
