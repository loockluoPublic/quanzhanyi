import { atom } from "recoil";
import mockData from "../utils/mockData";
import { CustomVector3 } from "../class/CustomVector3";
import { BaseInfo, ICube, ICycle, ICycleBase } from "./type";

export enum TType {
  cycle = "cycle",
  cube = "cube",
}

export const connectState = atom({
  key: "connectState", // 唯一标识这个状态
  default: false, // 默认值
});

export const deviceInfo = atom<any>({
  key: "deviceInfo", // 唯一标识这个状态
  default: {
    auth: false,
  }, // 默认值
});

export interface GlobalData
  extends Partial<BaseInfo & ICycleBase & ICycle & ICube> {
  /**
   * 类型，管道或者方涵
   */
  type: TType;
  [k: string]: any;
}
export const Data = atom<GlobalData>({
  key: "data", // 唯一标识这个状态
  default: {
    sdfb: 4,
    sdj: 45,
    sdm: ["A", "B"],
    MxPoints: {},
    hasChamfer: false,
    firstPoints: [] as any,
    type: TType.cycle,
    distanceThreshold: 0.1,

    layNum: 2,
    numPerLay: 3,

    mPoints: [],
  }, // 默认值
});

export enum TMode {
  first = "first",
  second = "second",
}
export const Mode = atom<TMode>({
  key: "mode", // 唯一标识这个状态
  default: TMode.first, // 默认值
});
