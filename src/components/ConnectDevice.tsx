import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button, Input, message } from "antd";
import { useRecoilState } from "recoil";
import { deviceInfo } from "../atom/globalState";
import * as commond from "../utils/commond";
import { getDeviceInfo } from "../utils/commond";
import { availablePorts } from "../utils/serialport";
import Next from "./Next";
import logo from "../assets/logo.png";
import banner from "../assets/bg.jpg";
import qzy from "../assets/qzy.png";
import bgLogo from "../assets/bgLogo.png";
import { useState } from "react";
import { encode } from "../utils/secret";

(window as any).commond = commond;
export const serial = new SerialMonitor({ mode: "text", parseLines: true });

export default function Connect() {
  const [deviceInfoData, setDeviceInfo] = useRecoilState(deviceInfo);

  const [pwd, setPwd] = useState("");

  return (
    <div
      style={{ backgroundImage: `url(${banner})` }}
      className="q-w-full q-bg-no-repeat q-bg-center q-bg-cover q-shadow-lg q-rounded-lg"
    >
      <div className="q-absolute q-w-[320px] q-p-6 q-shadow-md q-rounded-xl q-mt-32 q-left-1/2 q-ml-[-160px] q-text-center q-bg-[#e9ecef88]">
        <table className="q-mb-4 q-m-auto">
          <tbody>
            <tr>
              <td>设备名称：</td>
              <td>{deviceInfoData?.InstrumentName}</td>
            </tr>
            <tr>
              <td>序列号：</td>
              <td>{deviceInfoData?.SerialNo}</td>
            </tr>
            <tr>
              <td>软件版本：</td>
              <td>{deviceInfoData?.SoftwareVersion}</td>
            </tr>
            <tr></tr>
          </tbody>
        </table>

        {deviceInfoData?.SerialNo ? (
          <>
            <div className="q-inline-flex q-items-center  ">
              <div className="q-w-14">秘钥：</div>
              <Input.Password
                value={pwd}
                type="password"
                onChange={(v) => setPwd(v.target.value)}
              />
            </div>
            <div className="q-text-center q-mt-2">
              <Button
                className="q-mt-2 q-mr-2"
                onClick={() => {
                  availablePorts();
                }}
              >
                断开连接
              </Button>
              <Button
                className="q-mt-2"
                type="primary"
                onClick={() => {
                  if (pwd === encode(deviceInfoData?.SerialNo)) {
                    setDeviceInfo({ ...deviceInfoData, auth: true });
                    message.success("秘钥验证成功");
                  } else {
                    message.error("秘钥验证错误，请确定秘钥与设备是否对应");
                  }
                }}
              >
                验证秘钥
              </Button>
            </div>
          </>
        ) : (
          <Button
            type="primary"
            onClick={() => {
              serial
                .connect(19200)
                .then(() => {
                  return getDeviceInfo();
                })
                .then((res) => {
                  setDeviceInfo(res);
                  setPwd(encode(res?.SerialNo));
                })
                .catch(() => {
                  console.log("Something went wrong...");
                });
            }}
          >
            连接设备
          </Button>
        )}
      </div>
      <div className="q-absolute q-bottom-10 q-left-0 q-w-full q-text-center">
        <div className=" q-text-white">
          Copyright © 2024
          <a className=" q-text-white" href="https://www.qingwanshui.com/">
            {" "}
            青岛清万水技术有限公司
          </a>
        </div>
      </div>

      <img
        src={bgLogo}
        alt=""
        className=" q-h-[40%] q-absolute q-bottom-[80px] q-right-[10%]"
      />
      <img
        src={qzy}
        alt=""
        className="  q-w-[250px]  q-absolute q-bottom-0 q-left-[15%]"
      />
    </div>
  );
}
