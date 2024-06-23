import { Button } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { measureAndGetSimpleCoord } from "../utils/commond";
import { div } from "three/examples/jsm/nodes/Nodes.js";
import { MinusCircleOutlined } from "@ant-design/icons";
import { useEffect, useState } from "react";

export default function PointsVector3(props: {
  value?: CustomVector3;
  style?: React.CSSProperties;
  showGetPoints?: boolean;
  onChange?: (v: CustomVector3) => void;
  remove?: () => void;
  autoMeasure?: boolean;
}) {
  const { showGetPoints = true } = props;
  const [loading, setLoading] = useState(false);
  const getPoints = () => {
    setLoading(true);
    measureAndGetSimpleCoord()
      .then((res) => {
        console.log("%c Line:12 🍩 res", "color:#ed9ec7", res);
        props.onChange?.(res);
      })
      .finally(() => {
        setLoading(false);
      });
  };
  useEffect(() => {
    props.autoMeasure && getPoints();
  }, []);

  return (
    <div className=" ">
      <span style={props.style}>
        <span>{`ID:${props?.value?.key ?? ""} ${
          props?.value?.label || ""
        }`}</span>
        <span>x:</span>
        <span>{props?.value?.x?.toFixed(3)}</span>
        <span> y:</span>
        <span>{props?.value?.y?.toFixed(3)}</span>
        <span> z:</span>
        <span>{props?.value?.z?.toFixed(3)}</span>
      </span>
      {showGetPoints && (
        <span>
          {props.remove && (
            <MinusCircleOutlined
              style={{ marginLeft: "10px" }}
              className="dynamic-delete-button"
              onClick={props.remove}
            />
          )}

          <Button
            style={{ marginLeft: "10px" }}
            type="primary"
            onClick={getPoints}
            loading={loading}
            size="small"
          >
            采集
          </Button>
        </span>
      )}
    </div>
  );
}
