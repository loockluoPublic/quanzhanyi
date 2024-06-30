import { Button, Form, InputNumber } from "antd";
import PointsVector3 from "./PointVector3";
import PointsVector2 from "./PointVector2";
import { CustomVector3 } from "../class/CustomVector3";
import initData from "../utils/mockData";

function GetPoints(props: {
  pickPoint: (key: string, field?: any) => void;
  getDirect: (key: string) => void;
}) {
  return (
    <div className="q-w-[500px]">
      <Form.Item
        label="采样层数"
        name="layNum"
        rules={[{ required: true }]}
        wrapperCol={{ span: 3 }}
        initialValue={5}
      >
        <InputNumber
        // min={2}
        //  max={10}
        />
      </Form.Item>
      <Form.Item
        label="每层采点数"
        name="numPerLay"
        rules={[{ required: true }]}
        wrapperCol={{ span: 3 }}
        initialValue={5}
      >
        <InputNumber
        // min={3} max={7}
        />
      </Form.Item>
      <Form.Item label="管道轴线方向" required={true}>
        <Form.Item
          rules={[
            {
              required: true,
            },
          ]}
          name={"direct"}
          noStyle
          initialValue={initData.direct}
        >
          <PointsVector2 />
        </Form.Item>
        <Button
          style={{ marginLeft: "10px" }}
          type="primary"
          onClick={() => props.getDirect("direct")}
          size="small"
        >
          采集
        </Button>
      </Form.Item>

      <Form.List
        name="firstPoints"
        initialValue={[
          new CustomVector3(
            initData.firstPoints[0].x,
            initData.firstPoints[0].y,
            initData.firstPoints[0].z,
            {
              color: "#3498db",
              label: "P1",
            }
          ),

          new CustomVector3(
            initData.firstPoints[1].x,
            initData.firstPoints[1].y,
            initData.firstPoints[1].z,
            {
              color: "#3498db",
              label: "P2",
            }
          ),
        ]}
      >
        {(fields) => {
          console.log("%c Line:50 🍋 fields", "color:#b03734", fields);
          return (
            <>
              {fields.map((field, index) => (
                <Form.Item
                  label={["圆柱顶面点", "圆柱底面点"][index]}
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
                    <PointsVector3 style={{ width: "70%" }} />
                  </Form.Item>
                </Form.Item>
              ))}
            </>
          );
        }}
      </Form.List>
      <Form.List
        name="centerPoint"
        initialValue={[
          new CustomVector3(-0.162, -0.156, -0.273, {
            color: "#3498db",
            label: "P1",
          }),
        ]}
      >
        {(fields) => {
          console.log("%c Line:50 🍋 fields", "color:#b03734", fields);
          return (
            <>
              {fields.map((field) => (
                <Form.Item label="AB面交点" required={true} key={field.key}>
                  <Form.Item
                    {...field}
                    rules={[
                      {
                        required: true,
                      },
                    ]}
                    noStyle
                  >
                    <PointsVector3 style={{ width: "70%" }} />
                  </Form.Item>
                  {/* <Button
                    style={{ marginLeft: "10px" }}
                    type="primary"
                    onClick={() => props.pickPoint("centerPoint", field)}
                  >
                    采集
                  </Button> */}
                </Form.Item>
              ))}
            </>
          );
        }}
      </Form.List>
      {/* <h3>初始拟合点</h3>
      <Form.List name="points" initialValue={["", "", "", "", ""]}>
        {(fields, { add, remove }) => {
          return (
            <>
              {fields.map((field, index) => (
                <Form.Item
                  label={`采集第${index + 1}个点`}
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
                    <PointsVector3 style={{ width: "70%" }} />
                  </Form.Item>
                  {fields.length > 5 ? (
                    <MinusCircleOutlined
                      style={{ marginLeft: "10px" }}
                      className="dynamic-delete-button"
                      onClick={() => remove(field.name)}
                    />
                  ) : null}
                  <Button
                    style={{ marginLeft: "10px" }}
                    type="primary"
                    onClick={() => props.pickPoint("points", field)}
                  >
                    采集
                  </Button>
                </Form.Item>
              ))}
              <Form.Item>
                <Button
                  type="dashed"
                  onClick={() => add()}
                  className=" q-w-full"
                >
                  新增采集点
                </Button>
              </Form.Item>
            </>
          );
        }}
      </Form.List> */}
    </div>
  );
}

export default GetPoints;
