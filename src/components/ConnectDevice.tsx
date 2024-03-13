import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button } from "antd";
import { useRecoilState } from "recoil";
import { connectState } from "../atom/globalState";

export const serial = new SerialMonitor({ mode: "text", parseLines: true });

export default function Connect(props: { onConnected: () => void }) {
  const [connected, setConnected] = useRecoilState(connectState);
  return (
    <>
      {connected ? (
        <Button
          onClick={() => {
            serial.disconnect();
            setConnected(false);
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
                setConnected(true);
                props?.onConnected?.();
              })
              .catch(() => {
                console.log("Something went wrong...");
              });
          }}
        >
          连接设备
        </Button>
      )}
    </>
  );
}
