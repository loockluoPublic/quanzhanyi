import { Button, message } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { measureAndGetSimpleCoord } from "../utils/commond";
import { MinusCircleOutlined } from "@ant-design/icons";
import { useEffect, useState } from "react";

export default function PointsVector3(props: {
  hideLabel?: boolean;
  value?: CustomVector3;
  style?: React.CSSProperties;
  showGetPoints?: boolean;
  before?: () => void;
  onChange?: (v: CustomVector3) => void;
  remove?: () => void;
  autoMeasure?: boolean;
  className?: string;
}) {
  const { showGetPoints = true, value } = props;

  const [loading, setLoading] = useState(false);

  const getPoints = () => {
    console.log("%c Line:22 🥑 getPoints", "color:#2eafb0", getPoints);
    setLoading(true);
    props?.before?.();
    measureAndGetSimpleCoord()
      .then((res) => {
        props.onChange?.(res);
      })
      .catch((err) => {
        console.error("%c Line:125 🍆 err", "color:#3f7cff", err);
        message.error("获取点坐标失败，请更换测量点后重试");
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

  if (props.hideLabel) w = -30;

  return (
    <div
      className={" q-inline-flex q-justify-end q-my-2 " + props.className}
      style={{ minWidth: `${w}px` }}
    >
      <span style={props.style}>
        {!props.hideLabel && (
          <span>{`${props?.value?.label || ""}${
            props?.value?.key ?? ""
          }`}</span>
        )}

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
