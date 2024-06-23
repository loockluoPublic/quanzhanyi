import { Button, Form, InputNumber } from "antd";
import PointsVector3 from "./PointVector3";
import PointsVector2 from "./PointVector2";
import { CustomVector3 } from "../class/CustomVector3";
import initData from "../utils/mockData";
import { bounders } from "../utils/cubeMockData";

function CubePre() {
  return (
    <div className="q-w-[500px]">
      <Form.List name="cubeBounders" initialValue={bounders}>
        {(fields) => {
          return (
            <>
              {fields.map((field, index) => (
                <Form.Item
                  label={["方涵范围点1", "方涵范围点2"][index]}
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
    </div>
  );
}

export default CubePre;
