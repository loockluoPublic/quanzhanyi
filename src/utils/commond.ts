import { CustomVector3 } from "../class/CustomVector3";
import { serial } from "../components/ConnectDevice";

const mock = new URLSearchParams(location.search).has("mock");

export const sendText = (text): Promise<string> => {
  return new Promise((resolve) => {
    if (import.meta.env.DEV || mock) {
      const mockData = {
        "2023:": "0",
        "5003:": "3216936",
        "5004:": '"TS16 A 1" R500"',
        "5008:": "2024,'03','13','05','16','0e'",
        "5034:": "4,11,489",
        "2009:": "1.4878,1.9127,-1.0183,0",
        "2011:": "0",
        "9027:1,1": "0",
        "2008:1,1": "0",
        "2116:300,1": `${Math.random() * 10 - 5},${Math.random() * 10 - 5},${
          Math.random() * 10 - 5
        }`,
        "1004:0": "0",
        "2107:1": "1.069995191213058,1.000012316348839",
      };
      setTimeout(() => {
        resolve(mockData[text]);
      }, 1000);
      return;
    }
    const flag = setTimeout(() => {
      resolve("");
    }, 12000);
    const handleSerialEvent = (event) => {
      console.log(
        "%c Line:11 🍪 接收到的原始数据 event.detail：",
        "color:#f5ce50",
        event.detail
      );
      resolve(event.detail?.replace(/%R1P,0,0:0,?/, ""));
      window.clearTimeout(flag);
      serial.removeEventListener("serial-data", handleSerialEvent);
    };
    serial.addEventListener("serial-data", handleSerialEvent);
    serial.send(`%R1Q,${text}\r\n`);
  });
};

// %R1Q,2023: ==> %R1P,0,0:0,0

//  %R1Q,5003: ==> %R1P,0,0:0,3216936

//  %R1Q,5004: ==> %R1P,0,0:0,"TS16 A 1\" R500"

//  %R1Q,5008: ==> %R1P,0,0:0,2024,'03','13','05','16','0e'

// %R1Q,5034: ==> %R1P,0,0:0,4,11,489

// %R1Q,2009: ==> %R1P,0,0:0,1.4878,1.9127,-1.0183,0

// %R1Q,2011: ==> %R1P,0,0:0,0

// %R1Q,2023: ==> %R1P,0,0:0,0

// %R1Q,9027:1,1 ==> %R1P,0,0:0

// %R1Q,2008:1,1 ==> %R1P,0,0:0

// %R1Q,2116:300,1 ==> %R1P,0,0:0,3.235880297852099,2.869479796171803,0.261194858393121
// %R1Q,1004:0 ==> %R1P,0,0:0
// %R1Q,2107:2 ==> %R1P,0,0:0,1.069995191213058,1.000012316348839

/**
 * 设置当前为原点
 * @returns
 */
export const setOrigin = () =>
  sendText(`2010:0,0,0,0`).then((res) => {
    console.log("%c Line:67 🍖 9027", "color:#7f2b82", res);
    return res;
  });

/**
 * 获取站点信息,包括东坐标（E0）、北坐标（N0）、高程（H0）和高程增量（Hi）。
 * @returns
 */
export const getDevicePosition = () =>
  sendText("2009:").then((res) => {
    console.log("%c Line:51 🍓 2009", "color:#f5ce50", res);
  });

export const getDeviceInfo = async () => {
  const dInfo = {
    SerialNo: "",
    InstrumentName: "",
    SoftwareVersion: "",
  };

  // 获取序列号
  await sendText("5003:").then((res) => {
    console.log("%c Line:31 🍋 5003", "color:#ea7e5c", res);
    dInfo.SerialNo = res;
  });

  // 获取仪器名称
  await sendText("5004:").then((res) => {
    console.log("%c Line:36 🥚 5004", "color:#ea7e5c", res);
    dInfo.InstrumentName = res;
  });

  // 获取软件版本
  await sendText("5034:").then((res) => {
    console.log("%c Line:46 🎂 5034", "color:#42b983", res);
    dInfo.SoftwareVersion = res.replace(/,/g, ".");
  });

  // 设置当前位置为原点
  await setOrigin();

  // 设置模式，设置后才能采集点
  await setMode();

  const dp = await getDevicePosition();
  console.log("%c Line:121 🍰 dp", "color:#e41a6a", dp);

  return dInfo;
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
export const setMode = () =>
  sendText(`2008:1,1`).then((res) => {
    console.log("%c Line:71 🥛 2008", "color:#2eafb0", res);
    return res;
  });

/**
 * 测量点坐标
 * @returns
 */
export const getPoint = () =>
  sendText(`2116:300,1`).then((res) => {
    const d = res.split(",")?.map((i) => Number(i));
    if (d?.length === 3) return new CustomVector3(...d);
  });

/**
 * 测量方向
 * @returns
 */
export const getLine = (): Promise<number[]> =>
  sendText(`2107:1`).then((res) => {
    console.log("%c Line:71 🥛 2107", "color:#2eafb0", res);
    return res.split(",").map((s) => Number(s));
  });

/**
 * 指向点的方向，并测量
 * @param v
 * @returns Promise<CustomVector3>
 */
export const pointToAndMeasure = (v: CustomVector3) => {
  const s = v.toSpherical();
  return goTo(s.theta, s.phi).then(getPoint);
};
