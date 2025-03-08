import { atom } from 'recoil';
import { BaseInfo, ICube, ICycle, ICycleBase } from './type';
import { CustomVector3 } from '../class/CustomVector3';

export enum TType {
  cycle = 'cycle',
  cube = 'cube',
}

export const connectState = atom({
  key: 'connectState', // 唯一标识这个状态
  default: false, // 默认值
});

export const deviceInfo = atom<any>({
  key: 'deviceInfo', // 唯一标识这个状态
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

export const getInitAgainTable = (sdfb: number, sdm: string[]): any => {
  const res = [];
  let i = 1;
  sdm.forEach((m) => {
    for (let j = 1; j <= sdfb; i++, j++) {
      res.push({ sdm: m, i });
    }
  });

  return res;
};

export const Data = atom<GlobalData>({
  key: 'data', // 唯一标识这个状态
  default: {
    virtualR: 0.6,
    sdfb: 4,
    sdj: 45,
    customStandardDeviation: 3,
    sdm: ['A', 'B'],
    MxPoints: {},
    hasChamfer: true,
    firstPoints: [] as any,
    triPoints: [] as any,
    type: TType.cycle,
    distanceThreshold: 0.1,
    layNum: 2,
    numPerLay: 3,
    mPoints: [],
    sfType: 'Wquanzhong4',
  }, // 默认值
});

export enum TMode {
  first = 'first',
  second = 'second',
}
export const Mode = atom<TMode>({
  key: 'mode', // 唯一标识这个状态
  default: TMode.first, // 默认值
});

export const Step = atom<number>({
  key: 'stop',
  default: 0,
});

export const ShowLabel = atom<boolean>({
  key: 'showLabel',
  default: true,
});

export const ShowCube = atom<boolean>({
  key: 'showCube',
  default: true,
});

export const Auth = atom<boolean>({
  key: 'auth',
  default: location.href.includes('auth'),
});
