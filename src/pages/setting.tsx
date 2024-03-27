import { Button, Form, Steps } from "antd";
import { useState } from "react";
import Module3D from "./module3D";
import Connect from "../components/ConnectDevice";
import { getLine, getPoint } from "../utils/commond";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import BaseInfo from "./BaseInfo";
import GetPoints from "./GetPoints";
import { Module3DPoint } from "./Module3DPoint";
import { CustomVector3 } from "../class/CustomVector3";

export default function Setting() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useState(0);

  const [form] = Form.useForm();

  const pickPoint = (key: string, field?: any) => {
    const arr = form.getFieldValue(key);

    return getPoint().then((res) => {
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
    setStep(value);
  };

  const getFromPoints = (): CustomVector3[] => {
    const { firstPoints, points } = form.getFieldsValue() ?? {};
    return [...(firstPoints ?? []), ...(points ?? [])];
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
      // onNext: GetPoints,
    },
    {
      title: "拟合",
      conponents: <Module3DPoint />,
    },
    {
      title: "标记",
      conponents: (
        <Module3D className="q-mb-4" height={"calc( 100vh - 268px - 1em )"} />
      ),
    },
  ];

  const next = () => {
    const formValues = form.getFieldsValue();
    setData({ ...data, ...formValues });
    setStep(step + 1);
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
        >
          {steps[step].conponents}
          <div className=" q-text-center">
            <Button type="primary" htmlType="submit">
              下一步
            </Button>
          </div>
        </Form>
      </div>
    </>
  );
}
