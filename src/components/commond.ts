import { serial } from "./ConnectDevice";

export const sendText = (text): Promise<string> => {
  return new Promise((resolve) => {
    const flag = setTimeout(() => {
      resolve("");
    }, 3000);

    const handleSerialEvent = (event) => {
      resolve(event.detail);
      window.clearTimeout(flag);
      serial.removeEventListener("serial-data", handleSerialEvent);
    };

    serial.addEventListener("serial-data", handleSerialEvent);
    serial.send(`${text}\r\n`);
  });
};

export const getDeviceInfo = () => sendText("").then((res) => {});
export const goTo = () => sendText(``).then((res) => {});
export const getPoint = () => sendText(``).then((res) => {});
