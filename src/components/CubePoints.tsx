import { Button, Form, InputNumber } from "antd";
import PointsVector3 from "./PointVector3";
import styles from "./index.module.css";
import PointsVector2 from "./PointVector2";
import { CustomVector3 } from "../class/CustomVector3";
import initData from "../utils/mockData";
import { MinusCircleOutlined } from "@ant-design/icons";
import { measureAndGetSimpleCoord } from "../utils/commond";
import { Planefit } from "../utils/utils";
import * as mockCubeData from "../utils/cubeMockData2";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";

function CubePoints(props: { pointsKeys: string }) {
  const { pointsKeys } = props;
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:17 🍔 data", "color:#3f7cff", data);

  const calPlanefit = () => {
    const points = (window as any).form.getFieldValue(pointsKeys);
    console.log("%c Line:17 🧀 arr", "color:#3f7cff", points);
    Planefit(
      points,
      data.planeParaOut ?? [],
      data?.cubeBounders?.[0],
      data?.cubeBounders?.[1]
    ).then((res) => {
      console.log("%c Line:24 🍔 res", "color:#b03734", res);
      setData((d) => {
        return {
          ...d,
          ...res,
        };
      });
    });
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
                <Button
                  className="q-mx-4"
                  onClick={() => {
                    console.log(
                      "%c Line:54 🍞 mockCubeData[pointsKeys]",
                      "color:#6ec1c2",
                      pointsKeys,
                      mockCubeData[pointsKeys]
                    );
                    (window as any).form.setFieldValue(
                      pointsKeys,
                      mockCubeData[pointsKeys]
                    );
                  }}
                >
                  设置模拟数据
                </Button>
                <Button className="q-mx-4" onClick={calPlanefit}>
                  计算
                </Button>
                {/* <Button
                  className="q-mx-4"
                  onClick={() => {
                    setData((d) => {
                      return {
                        ...d,
                        cubeBounders: [],
                        planeParaOut: [],
                      };
                    });
                  }}
                >
                  清空
                </Button> */}
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
