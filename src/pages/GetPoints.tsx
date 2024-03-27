import { MinusCircleOutlined } from "@ant-design/icons";
import { Button, Form, InputNumber } from "antd";
import PointsVector3 from "../components/PointVector3";

export function GetPoints(props: {
  pickPoint: (key: string, field: any) => void;
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
        <InputNumber min={2} max={10} />
      </Form.Item>
      <Form.Item
        label="每层采点数"
        name="numPerLay"
        rules={[{ required: true }]}
        wrapperCol={{ span: 3 }}
        initialValue={3}
      >
        <InputNumber min={3} max={7} />
      </Form.Item>
      <h3>定位点</h3>
      <Form.List name="firstPoints" initialValue={["", ""]}>
        {(fields) => {
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
                  <Button
                    style={{ marginLeft: "10px" }}
                    type="primary"
                    onClick={() => props.pickPoint("firstPoints", field)}
                  >
                    采集
                  </Button>
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
