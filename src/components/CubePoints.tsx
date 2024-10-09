import { Button, Form } from "antd";
import PointsVector3 from "./PointVector3";
import styles from "./index.module.css";
import { Planefit } from "../utils/utils";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";

function CubePoints(props: { pointsKeys: string }) {
  const { pointsKeys } = props;
  const data = useRecoilValue(Data);

  const calPlanefit = () => {
    const points = (window as any).form.getFieldValue(pointsKeys);
    console.log("%c Line:17 🧀 arr", "color:#3f7cff", points);
    Planefit(
      points,
      data.planeParaOut ?? [],
      data?.cubeBounders?.[0],
      data?.cubeBounders?.[1]
    );
  };

  return (
    <div className={"q-w-[500px] " + styles["form-item"]}>
      <Form.List name={pointsKeys}>
        {(fields, { add, remove }) => {
          return (
            <>
              <Form.Item>
                <Button type="primary" onClick={add}>
                  新增采集点
                </Button>

                <Button className="q-mx-4" onClick={calPlanefit}>
                  计算
                </Button>
              </Form.Item>
              {fields.map((field, index) => (
                <Form.Item
                  label={`第${index + 1}个点`}
                  required={true}
                  key={field.key}
                >
                  <Form.Item
                    {...field}
                    rules={[
                      {
                        required: true,
                      },
                    ]}
                    noStyle
                  >
                    <PointsVector3
                      style={{ width: "70%" }}
                      showGetPoints={true}
                      remove={() => remove(field.name)}
                      autoMeasure={true}
                    />
                  </Form.Item>
                </Form.Item>
              ))}
            </>
          );
        }}
      </Form.List>
    </div>
  );
}

export default CubePoints;
