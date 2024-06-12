import { Button, Form } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import PointsVector3 from "../components/PointVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useState } from "react";
import { measureAndGetSimpleCoord } from "../utils/commond";

const SLCPicker = (props) => {
  const { value, onChange } = props;
  console.log(
    "%c Line:10 🥤 value, onChange",
    "color:#f5ce50",
    props,
    value,
    onChange
  );
  return (
    <div className=" q-flex q-justify-between q-w-[600px]">
      <div>
        <PointsVector3 value={value?.[0]} style={{ width: "70%" }} />

        <Button
          style={{ marginLeft: "10px" }}
          type="primary"
          onClick={() => {
            measureAndGetSimpleCoord().then((res) => {
              onChange([res, value?.[1]]);
            });
          }}
        >
          采集
        </Button>
      </div>

      <div>
        <PointsVector3 value={value?.[1]} style={{ width: "70%" }} />

        <Button
          style={{ marginLeft: "10px" }}
          type="primary"
          onClick={() => {
            measureAndGetSimpleCoord().then((res) => {
              onChange([value?.[0], res]);
            });
          }}
        >
          采集
        </Button>
      </div>
    </div>
  );
};

export default function (props: {
  pickPoint: (key: string, field?: any) => void;
}) {
  const [data, setData] = useRecoilState(Data);
  //   return <div>123</div>;
  const initialValue = Array(data.sdfb || Math.ceil(data.sdfb / 2)).fill([
    1, 2,
  ]);
  console.log("%c Line:13 🍏 initialValue", "color:#2eafb0", initialValue);
  return (
    <Form.List name="cylinderAgain" initialValue={initialValue}>
      {(fields) => {
        console.log("%c Line:18 🥥 fields", "color:#42b983", fields);
        return (
          <>
            {fields.map((field) => (
              <Form.Item
                label={`声路${field.key + 1}`}
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
                  <SLCPicker />
                </Form.Item>
              </Form.Item>
            ))}
          </>
        );
      }}
    </Form.List>
  );
}
