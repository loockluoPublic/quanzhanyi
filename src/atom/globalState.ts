import { atom } from "recoil";

export const connectState = atom({
  key: "connectState", // 唯一标识这个状态
  default: false, // 默认值
});
