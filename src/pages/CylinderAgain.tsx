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
      <div className="q-flex">
        <PointsVector3
          value={value?.[0]}
          style={{ width: "70%" }}
          showGetPoints={false}
        />

        <Button
          style={{ marginLeft: "10px" }}
          type="primary"
          onClick={() => {
            measureAndGetSimpleCoord().then((res) => {
              onChange([res, value?.[1]]);
            });
          }}
          size="small"
        >
          采集
        </Button>
      </div>

      <div className="q-flex">
        <PointsVector3
          value={value?.[1]}
          style={{ width: "70%" }}
          showGetPoints={false}
        />

        <Button
          size="small"
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

export default function () {
  const [data, setData] = useRecoilState(Data);

  const initialValue = Array(data.sdfb || Math.ceil(data.sdfb / 2)).fill([
    1, 2,
  ]);

  return (
    <div>
      <Form.List name="cylinderAgain" initialValue={initialValue}>
        {(fields) => {
          console.log("%c Line:18 🥥 fields", "color:#42b983", fields);
          return (
            <>
              {fields.map((field) => (
                <Form.Item
                  label={`声道${field.key + 1}`}
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
      <div>
        <Button
          onClick={() => {
            const cylinderAgain = (window as any).form.getFieldValue(
              "cylinderAgain"
            );
            setData((d) => {
              return {
                ...d,
                cylinderAgain,
              };
            });
          }}
        >
          保存全局以备导出
        </Button>
      </div>
    </div>
  );
}
