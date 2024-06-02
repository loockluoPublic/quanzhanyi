import { Button, Form, Steps } from "antd";
import { useState } from "react";
import Connect from "../components/ConnectDevice";
import { getLine, measureAndGetSimpleCoord } from "../utils/commond";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import BaseInfo from "../components/BaseInfo";
import GetPoints from "../components/GetPoints";
import { MeasurePoints } from "./MeasurePoints";
import { CalculateAccurateCylinders } from "./CalculateAccurateCylinders";
import { CalculateResultPoints } from "./CalculateResultPoints";
import ResultTable from "./Result";

export default function Setting() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useState(0);
  console.log("%c Line:15 🍔 data", "color:#42b983", data);

  const [form] = Form.useForm();

  const pickPoint = (key: string, field?: any) => {
    const arr = form.getFieldValue(key);

    return measureAndGetSimpleCoord().then((res) => {
      console.log("%c Line:22 🍩 res", "color:#fca650", res, field);
      if (field) {
        arr[field.key] = res;
        form.setFieldValue(key, [...arr]);
      } else {
        form.setFieldValue(key, res);
      }
      return res;
    });
  };

  const getDirect = (key: string) => {
    getLine().then((res) => {
      form.setFieldValue(key, res);
    });
  };

  const onChange = (value: number) => {
    console.log("%c Line:42 🍿 value", "color:#b03734", value);
    setStep(value);
  };

  const steps = [
    {
      title: "设备连接",
      conponents: <Connect />,
    },
    {
      title: "基本参数",
      conponents: <BaseInfo />,
    },
    {
      title: "手动采点",
      conponents: <GetPoints pickPoint={pickPoint} getDirect={getDirect} />,
    },
    {
      title: "自动圆面点采集",
      conponents: <MeasurePoints />,
    },
    {
      title: "圆柱拟合",
      conponents: <CalculateAccurateCylinders />,
    },
    {
      title: "计算安装位",
      conponents: <CalculateResultPoints />,
    },
    {
      title: "结果",
      conponents: <ResultTable />,
    },
  ];
  const updateFormData = () => {
    const formValues = form.getFieldsValue();
    console.log("%c Line:68 🍬 formValues", "color:#ed9ec7", formValues);
    setData({ ...data, ...formValues });
  };
  const next = () => {
    updateFormData();
    if (step < steps.length) {
      setStep(step + 1);
    }
  };

  return (
    <>
      <Steps
        className=" q-bg-white !q-pt-4 q-mb-4"
        current={step}
        type="navigation"
        size="small"
        onChange={onChange}
        items={steps}
      />
      <div className=" q-flex q-justify-center q-bg-white q-m-4 q-p-8 q-rounded-xl">
        <Form
          onFinish={next}
          className={step > 2 ? " q-w-full" : ""}
          form={form}
          onChange={updateFormData}
        >
          {steps[step].conponents}
          {steps.length - 1 > step && (
            <div className=" q-text-center">
              <Button type="primary" htmlType="submit">
                下一步
              </Button>
            </div>
          )}
        </Form>
      </div>
    </>
  );
}
