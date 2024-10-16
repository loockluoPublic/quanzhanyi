import { message, Steps } from "antd";
import { useEffect } from "react";
import Connect from "../components/ConnectDevice";
import { useRecoilState, useRecoilValue } from "recoil";
import {
  Data,
  deviceInfo,
  Mode,
  Step,
  TMode,
  TType,
} from "../atom/globalState";
import CylinderAgain from "./CylinderAgain";
import CubePre from "./CubePre";
import CubeFit from "./CubeResult";
import CylinderPre from "./CylinderPre";
import CylinderFit from "./CylinderFit";
import CubeAgain from "./CubeAgain";

message.config({
  maxCount: 1,
});

export default function Setting() {
  const deviceInfoData = useRecoilValue(deviceInfo);
  const data = useRecoilValue(Data);
  console.log("%c Line:27 🌭 data", "color:#ed9ec7", data);
  const [step, setStep] = useRecoilState(Step);
  const [mode] = useRecoilState(Mode);

  useEffect(() => {
    setStep(0);
  }, [data.type]);

  const onChange = (value: number) => {
    setStep(value);
    // if (deviceInfoData.auth || location.search.includes("mock")) {
    //   setStep(value);
    // } else {
    //   message.error("请验证秘钥");
    // }
  };

  const CycleSteps = [
    {
      title: "设备连接",
      components: <Connect />,
    },
    {
      title: "自动采点&管道拟合",
      components: <CylinderPre />,
    },
    // {
    //   title: "安装点计算",
    //   components: <CylinderFit />,
    // },
  ];

  if (mode === TMode.second) {
    CycleSteps.push({
      title: "管道复测",
      components: <CylinderAgain />,
    });
  } else {
    CycleSteps.push({
      title: "安装点计算",
      components: <CylinderFit />,
    });
  }

  const CubeSteps = [
    {
      title: "设备连接",
      components: <Connect />,
    },
    {
      title: "手动采点&方涵拟合",
      components: <CubePre />,
    },
    // {
    //   title: "安装点计算",
    //   components: <CubeFit />,
    // },
  ];

  if (mode === TMode.second) {
    CubeSteps.push({
      title: "管道复测",
      components: <CubeAgain />,
    });
  } else {
    CubeSteps.push({
      title: "安装点计算",
      components: <CubeFit />,
    });
  }

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
