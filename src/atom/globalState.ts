import { atom } from "recoil";

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
  default: {}, // 默认值
});
