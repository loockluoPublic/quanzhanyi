import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button } from "antd";
import { useRecoilState } from "recoil";
import { deviceInfo } from "../atom/globalState";
import * as commond from "../utils/commond";
import { getDeviceInfo } from "../utils/commond";
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
        <Button
          onClick={() => {
            serial.disconnect();
            setDeviceInfo(undefined);
          }}
        >
          断开连接
        </Button>
      ) : (
        <Button
          type="primary"
          onClick={() => {
            serial
              .connect(19200)
              .then(() => {
                // props?.onConnected?.();
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
    </div>
  );
}
