import { Steps } from "antd";
import { useEffect, useState } from "react";
import Connect from "../components/ConnectDevice";
import { useRecoilState } from "recoil";
import { Data, Mode, TMode, TType } from "../atom/globalState";
import CylinderAgain from "./CylinderAgain";
import CubePre from "./CubePre";
import CubeFit from "./CubeResult";
import CylinderPre from "./CylinderPre";
import CylinderFit from "./CylinderFit";

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

  useEffect(() => {
    setStep(0);
  }, [data.type]);

  const onChange = (value: number) => {
    if (value <= step + 1) setStep(value);
  };

  const CycleSteps = [
    {
      title: "设备连接",
      components: <Connect />,
      type: SHOWTYPE.bb,
    },

    {
      title: "自动采点&管道拟合",
      components: <CylinderPre />,
      type: SHOWTYPE.yb,
    },
    {
      title: "安装点计算",
      components: <CylinderFit />,
      type: SHOWTYPE.yb,
    },

    // {
    //   title: "基本参数",
    //   components: <BaseInfo />,
    //   type: SHOWTYPE.bb,
    // },

    // /** 圆形 */
    // {
    //   title: "手动采点",
    //   components: <GetPoints pickPoint={pickPoint} getDirect={getDirect} />,
    //   type: SHOWTYPE.yb,
    // },
    // {
    //   title: "自动圆面点采集",
    //   components: <MeasurePoints />,
    //   type: SHOWTYPE.yb,
    // },
    // {
    //   title: "圆柱拟合",
    //   components: <CalculateAccurateCylinders />,
    //   type: SHOWTYPE.yb,
    // },
    // {
    //   title: "计算安装位",
    //   components: <CalculateResultPoints />,
    //   type: SHOWTYPE.yc,
    // },
  ];

  if (mode === TMode.second) {
    CycleSteps[CycleSteps.length - 1] = {
      title: "采集",
      components: <CylinderAgain />,
      type: SHOWTYPE.yf,
    };
  }

  const CubeSteps = [
    {
      title: "设备连接",
      components: <Connect />,
      type: SHOWTYPE.bb,
    },
    {
      title: "手动采点&方涵拟合",
      components: <CubePre />,
      type: SHOWTYPE.bb,
    },
    {
      title: "安装点计算",
      components: <CubeFit />,
      type: SHOWTYPE.bb,
    },
  ];

  let steps = data.type === TType.cube ? CubeSteps : CycleSteps;

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
      <div className=" q-flex q-justify-center q-bg-white q-m1x-2 q-p-4 q-rounded-xl q-flex-1">
        {steps?.[step]?.components}
      </div>
    </div>
  );
}
