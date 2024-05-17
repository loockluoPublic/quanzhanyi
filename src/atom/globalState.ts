import { atom } from "recoil";
import { mockData } from "../utils/mockData";
import { CustomVector3 } from "../class/CustomVector3";

export const connectState = atom({
  key: "connectState", // 唯一标识这个状态
  default: false, // 默认值
});

export const deviceInfo = atom({
  key: "deviceInfo", // 唯一标识这个状态
  default: undefined, // 默认值
});

export const Data = atom<Record<string, any>>({
  key: "data", // 唯一标识这个状态
  default: {
    mPoints: mockData.mPoints.map((item) => {
      return new CustomVector3(item.x, item.y, item.z);
    }),
  }, // 默认值
});
