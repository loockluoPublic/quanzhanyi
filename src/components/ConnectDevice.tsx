import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button } from "antd";
import { useRecoilState } from "recoil";
import { deviceInfo } from "../atom/globalState";
import * as commond from "../utils/commond";
import { getDeviceInfo } from "../utils/commond";
import { availablePorts } from "../utils/serialport";
import Next from "./Next";
import logo from "../assets/logo.png";

(window as any).commond = commond;
export const serial = new SerialMonitor({ mode: "text", parseLines: true });

export default function Connect() {
  const [deviceInfoData, setDeviceInfo] = useRecoilState(deviceInfo);
  return (
    <div className="q-mb-4 q-text-center">
      <table className="q-mb-4 ">
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
        </tbody>
      </table>
      {deviceInfoData ? (
        <>
          <Button
            onClick={() => {
              availablePorts();
            }}
          >
            断开连接
          </Button>
          <Next className="q-mt-4" />
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
  );
}
