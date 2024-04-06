import { Button, Form, InputNumber } from "antd";
import PointsVector3 from "./PointVector3";
import PointsVector2 from "./PointVector2";
import { CustomVector3 } from "../class/CustomVector3";

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
        <InputNumber min={2} max={10} />
      </Form.Item>
      <Form.Item
        label="每层采点数"
        name="numPerLay"
        rules={[{ required: true }]}
        wrapperCol={{ span: 3 }}
        initialValue={5}
      >
        <InputNumber min={3} max={7} />
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
          initialValue={[5.13589906, 1.578973501]}
        >
          <PointsVector2 />
        </Form.Item>
        <Button
          style={{ marginLeft: "10px" }}
          type="primary"
          onClick={() => props.getDirect("direct")}
        >
          采集
        </Button>
      </Form.Item>
      {/* <h3>定位点</h3> */}
      <Form.List
        name="firstPoints"
        initialValue={[
          new CustomVector3(0.326251015, 0.956199453, -0.723689948),
          new CustomVector3(-0.501883731, 2.408888592, 0.615044378),
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

export default GetPoints;
