import { Button, Form, Steps } from "antd";
import { useEffect, useState } from "react";
import Connect from "../components/ConnectDevice";
import { getLine, measureAndGetSimpleCoord } from "../utils/commond";
import { useRecoilState } from "recoil";
import { Data, Mode, TMode } from "../atom/globalState";
import BaseInfo from "../components/BaseInfo";
import GetPoints from "../components/GetPoints";
import { MeasurePoints } from "./MeasurePoints";
import { CalculateAccurateCylinders } from "./CalculateAccurateCylinders";
import { CalculateResultPoints } from "./CalculateResultPoints";
import ResultTable from "./Result";
import CylinderAgain from "./CylinderAgain";

export default function Setting() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useState(0);
  const [mode] = useRecoilState(Mode);

  useEffect(() => {
    setStep(0);
  }, [mode]);

  const [form] = Form.useForm();

  const pickPoint = (key: string, field?: any) => {
    const arr = form.getFieldValue(key);

    return measureAndGetSimpleCoord().then((res) => {
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
    if (value <= step + 1) setStep(value);
  };

  const steps = [
    {
      title: "设备连接",
      components: <Connect />,
    },
    {
      title: "基本参数",
      components: <BaseInfo />,
    },
    {
      title: "手动采点",
      components: <GetPoints pickPoint={pickPoint} getDirect={getDirect} />,
    },
    {
      title: "自动圆面点采集",
      components: <MeasurePoints />,
    },
    {
      title: "圆柱拟合",
      components: <CalculateAccurateCylinders />,
    },
    {
      title: "计算安装位",
      components: <CalculateResultPoints />,
      hideType: TMode.second,
    },
    {
      title: "结果",
      components: <ResultTable />,
      hideType: TMode.second,
    },

    {
      title: "采集",
      components: <CylinderAgain pickPoint={pickPoint} />,
      hideType: TMode.first,
    },
  ].filter((item) => item.hideType !== mode);

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
  console.log(
    "%c Line:101 🍪 steps?.[step]?.components",
    "color:#f5ce50",
    steps?.[step]?.components
  );
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
          {steps?.[step]?.components}
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
