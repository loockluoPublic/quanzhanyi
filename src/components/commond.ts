import { serial } from "./ConnectDevice";

export const sendText = (text): Promise<string> => {
  return new Promise((resolve) => {
    const flag = setTimeout(() => {
      resolve("");
    }, 3000);

    const handleSerialEvent = (event) => {
      console.log(
        "%c Line:11 🍪 接收到的原始数据 event.detail：",
        "color:#f5ce50",
        event.detail
      );

      resolve(event.detail?.replace("%R1P,", ""));
      window.clearTimeout(flag);
      serial.removeEventListener("serial-data", handleSerialEvent);
    };

    serial.addEventListener("serial-data", handleSerialEvent);
    serial.send(`%R1Q,${text}\r\n`);
  });
};

export const getDeviceInfo = async () => {
  const dInfo: any = {};

  // 获取序列号
  await sendText("%R1Q,5003:").then((res) => {
    console.log("%c Line:31 🍋 5003", "color:#ea7e5c", res);
    dInfo.SerialNo = res;
  });

  // 获取仪器名称
  await sendText("%R1Q,5004:").then((res) => {
    console.log("%c Line:36 🥚 5004", "color:#ea7e5c", res);
    dInfo.InstrumentName = res;
  });

  // 获取当前时间
  await sendText("%R1Q,5008:").then((res) => {
    console.log("%c Line:41 🧀 5008", "color:#ffdd4d", res);
    dInfo.CurrentTime = res;
  });

  // 获取软件版本
  await sendText("%R1Q,5034:").then((res) => {
    console.log("%c Line:46 🎂 5034", "color:#42b983", res);
    dInfo.SoftwareVersion = res;
  });

  // 获取站点信息,包括东坐标（E0）、北坐标（N0）、高程（H0）和高程增量（Hi）。
  await sendText("%R1Q,2009:").then((res) => {
    console.log("%c Line:51 🍓 2009", "color:#f5ce50", res);
    dInfo.StationInfo = res;
  });

  // 获取反射器高度
  await sendText("%R1Q,2011:").then((res) => {
    console.log("%c Line:56 🍩 2011", "color:#465975", res);
    dInfo.ReflectorHeight = res;
  });

  // 获取棱镜常数
  await sendText("%R1Q,2023:").then((res) => {
    console.log("%c Line:61 🍭 2023", "color:#ffdd4d", res);
    dInfo.PrismConstant = res;
  });
};

/**
 * 转动到某个方向
 * @param h
 * @param v
 * @returns
 */
export const goTo = (h, v) =>
  sendText(`9027:${h},${v}`).then((res) => {
    console.log("%c Line:67 🍖 9027", "color:#7f2b82", res);
    return res;
  });

/**
 *  测量全站仪坐标
 * @returns
 */
export const getPoint = () =>
  sendText(`2008:1,1`).then((res) => {
    console.log("%c Line:71 🥛 2008", "color:#2eafb0", res);
  });

/**
 * 测量点坐标
 * @returns
 */
export const getPoint2 = () =>
  sendText(`2116:300,1`).then((res) => {
    console.log("%c Line:71 🥛 2008", "color:#2eafb0", res);
  });

/**
 * 测量方向
 * @returns
 */
export const getLine = () =>
  sendText(`2107:1`).then((res) => {
    console.log("%c Line:71 🥛 2008", "color:#2eafb0", res);
  });
