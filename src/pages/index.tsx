import { message, Steps, Tag } from "antd";
import { useEffect } from "react";
import Connect from "../components/ConnectDevice";
import { useRecoilState, useRecoilValue } from "recoil";
import {
  Auth,
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
  console.log("%c Line:27 🍔 deviceInfoData", "color:#42b983", deviceInfoData);
  const data = useRecoilValue(Data);
  const [step, setStep] = useRecoilState(Step);
  const [mode] = useRecoilState(Mode);
  const auth = useRecoilValue(Auth);

  useEffect(() => {
    setStep(0);
  }, [data.type]);

  const onChange = (value: number) => {
    if (auth || deviceInfoData.auth || (window as any).mock) {
      setStep(value);
    } else {
      message.error("请验证秘钥");
    }
  };

  const connectStatus = <>设备连接 <Tag color={deviceInfoData.auth ? 'success' : 'default'}>{deviceInfoData.auth ? '已连接' : '未连接'} </Tag></>

  const CycleSteps = [
    {
      title: connectStatus,
      components: (
        <Connect
          next={() => {
            setStep(step + 1);
          }}
        />
      ),
    },
    {
      title: "自动采点&管道拟合",
      components: <CylinderPre />,
    },
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
      title: connectStatus,
      components: (
        <Connect
          next={() => {
            setStep(step + 1);
          }}
        />
      ),
    },
    {
      title: "手动采集&方涵拟合",
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
