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
import Cube from "./Cube";
import CubePre from "../components/CubePre";

const isVoild = (b) => (b & 0b0011) > 0;
enum SHOWTYPE {
  /** 圆柱-复测 */
  yf = 0b1010,
  /** 圆柱-测量 */
  yc = 0b1001,
  /** 方涵-复测 */
  ff = 0b0110,
  /** 方涵-测量 */
  fc = 0b0101,
  bf = 0b1110,
  bc = 0b1101,
  yb = 0b1011,
  fb = 0b0111,
  bb = 0b1111,
  f = 0b0100,
  y = 0b1000,
  c = 0b0001,
  F = 0b0010,
}

export default function Setting() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useState(0);
  const [mode] = useRecoilState(Mode);
  console.log("%c Line:40 🍩 data", "color:#4fff4B", data);

  useEffect(() => {
    setStep(0);
  }, [mode]);

  const [form] = Form.useForm();
  (window as any).form = form;
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

  const currentType =
    (mode !== TMode.first ? SHOWTYPE.F : SHOWTYPE.c) |
    (data.type === 2 ? SHOWTYPE.f : SHOWTYPE.y);

  const steps = [
    {
      title: "设备连接",
      components: <Connect />,
      type: SHOWTYPE.bb,
    },
    {
      title: "基本参数",
      components: <BaseInfo />,
      type: SHOWTYPE.bb,
    },
    /** 圆形 */
    {
      title: "手动采点",
      components: <GetPoints pickPoint={pickPoint} getDirect={getDirect} />,
      type: SHOWTYPE.yb,
    },
    {
      title: "自动圆面点采集",
      components: <MeasurePoints />,
      type: SHOWTYPE.yb,
    },
    {
      title: "圆柱拟合",
      components: <CalculateAccurateCylinders />,
      type: SHOWTYPE.yb,
    },

    /** 圆形-测量 */
    {
      title: "计算安装位",
      components: <CalculateResultPoints hideMode={true} />,
      type: SHOWTYPE.yc,
    },
    {
      title: "报表",
      components: <ResultTable />,
      type: SHOWTYPE.yc,
    },

    /** 圆形-复测 */
    {
      title: "采集",
      components: <CylinderAgain />,
      type: SHOWTYPE.yf,
    },

    /** 方形 */
    {
      title: "矩形范围",
      components: <CubePre />,
      type: SHOWTYPE.fb,
    },
    {
      title: "手动采点左侧面",
      components: <Cube pointsKeys="cubePointsL" />,
      type: SHOWTYPE.fb,
    },
    {
      title: "手动采点顶面",
      components: <Cube pointsKeys="cubePointsT" />,
      type: SHOWTYPE.fb,
    },
    {
      title: "手动采点右侧面",
      components: <Cube pointsKeys="cubePointsR" />,
      type: SHOWTYPE.fb,
    },
    {
      title: "手动采点低面",
      components: <Cube pointsKeys="cubePointsB" />,
      type: SHOWTYPE.fb,
    },
    {
      title: "计算安装位",
      components: <Cube pointsKeys="demo" />,
      type: SHOWTYPE.fb,
    },
  ].filter((item) => {
    const res = currentType & item.type;
    return isVoild(res) && isVoild(res >> 2);
  });

  const updateFormData = () => {
    const formValues = form.getFieldsValue();

    setData({ ...data, ...formValues });
  };

  const next = () => {
    updateFormData();
    if (step < steps.length) {
      setStep(step + 1);
    }
  };

  return (
    <div className="q-flex q-flex-col q-h-full">
      <Steps
        className=" q-bg-white !q-pt-4 q-mb-2"
        current={step}
        type="navigation"
        size="small"
        onChange={onChange}
        items={steps}
      />
      <div className=" q-flex q-justify-center q-bg-white q-m-4 q-p-4 q-rounded-xl q-flex-1">
        <Form
          key={step}
          onFinish={next}
          className={step > 2 ? " q-w-full" : ""}
          form={form}
          onValuesChange={updateFormData}
          initialValues={data}
        >
          {steps?.[step]?.components}
        </Form>
      </div>
    </div>
  );
}
