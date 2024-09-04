import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button, Input, message } from "antd";
import { useRecoilState } from "recoil";
import { deviceInfo } from "../atom/globalState";
import * as commond from "../utils/commond";
import { getDeviceInfo } from "../utils/commond";
import { availablePorts } from "../utils/serialport";
import Next from "./Next";
import logo from "../assets/logo.png";
import banner from "../assets/banner.jpg";
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
      className="q-w-full q-bg-no-repeat q-bg-center q-bg-contain"
    >
      <div className="q-mb-4 q-text-center q-mt-40 q-flex q-flex-col q-w-[200px] q-m-auto">
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
            <div className="q-inline-flex q-items-center q-mt-2 ">
              <div className="q-w-14">秘钥：</div>
              <Input
                defaultValue={encode(deviceInfoData?.SerialNo)}
                type="password"
                onChange={(v) => setPwd(v.target.value)}
              />
            </div>
            <Button
              className="q-block q-mt-2"
              type="primary"
              onClick={() => {
                console.log(
                  "%c Line:60 🍅 pwd",
                  "color:#6ec1c2",
                  pwd,
                  "s",
                  encode(deviceInfoData?.SerialNo)
                );
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
            <Button
              className="q-mt-2"
              onClick={() => {
                availablePorts();
              }}
            >
              断开连接
            </Button>
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
                })
                .catch(() => {
                  console.log("Something went wrong...");
                });
            }}
          >
            连接设备
          </Button>
        )}

        <div className="q-absolute q-bottom-10 q-left-0 q-w-full ">
          <img className="q-w-[100px]" src={logo} alt="" />
          <div>
            Copyright © 2024
            <a href="https://www.qingwanshui.com/"> 青岛清万水技术有限公司</a>
          </div>
        </div>
      </div>
    </div>
  );
}
