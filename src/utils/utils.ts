import EmxArray_real_T from "../class/EmxArray_real_T";
import { CustomVector3 } from "../class/CustomVector3";
import { data, p3array, p4array } from "./mockData";
import { tableData } from "./config";

const {
  _generateUnitCircleWithNormalVector,
  _GenerateMultiLayeredMeasurementPoints,
  _CalculateAccurateCylindersFromMultipleMeasurementPoints,
  _CalculatAAndBPoints,
  _Repeat_Survey,
} = (window as any).Module;

/**
 * @description 根据轴线方向和范围生成测点
 * @param azimuth 极角
 * @param elevation 赤道角
 * @param numPerLay 每层采样点数
 * @param laynum  采样层数
 * @param P1 圆面顶面
 * @param P2 圆面底面
 * @returns CustomVector3[] 算法坐标待测量点
 */
export const generateUnitCircleWithNormalVector = async (
  azimuth: number,
  elevation: number,
  numPerLay: number,
  laynum: number,
  P1: CustomVector3,
  P2: CustomVector3
): Promise<CustomVector3[]> => {
  const points = new EmxArray_real_T(3, numPerLay * laynum);
  const p3 = new EmxArray_real_T(P1);
  const p4 = new EmxArray_real_T(P2);
  _generateUnitCircleWithNormalVector(
    azimuth,
    elevation,
    numPerLay,
    laynum,
    p3.arrayPtr,
    p4.arrayPtr,
    points.ptr
  );
  const res = points.toVector3();
  console.log(
    "%c Line:22 🥝 _generateUnitCircleWithNormalVector",
    "color:#93c0a4",
    azimuth,
    elevation,
    numPerLay,
    laynum,
    P1,
    P2,
    res
  );
  console.table(res);
  points.free();
  return res;
};

export const GenerateMultiLayeredMeasurementPoints = (
  Points: CustomVector3[],
  numPerLay: number,
  laynum: number,
  P1: CustomVector3,
  P2: CustomVector3
) => {
  const points = new EmxArray_real_T(Points);
  const p3 = new EmxArray_real_T(P1);
  const p4 = new EmxArray_real_T(P2);
  const resultPoints = new EmxArray_real_T(3, numPerLay * laynum);
  console.group("GenerateMultiLayeredMeasurementPoints");

  console.log(
    "%c Line:40 🥪 num",
    "color:#93c0a4",
    numPerLay,
    laynum,
    p3.toVector3(),
    p4.toVector3()
  );
  _GenerateMultiLayeredMeasurementPoints(
    points.ptr,
    numPerLay,
    laynum,
    p3.arrayPtr,
    p4.arrayPtr,
    resultPoints.ptr
  );
  console.log(
    "%c Line:45 🥥 GenerateMultiLayeredMeasurementPoints resultPoints",
    "color:#ea7e5c",
    resultPoints.toVector3()
  );
  console.groupEnd();
  const resoult = resultPoints.toVector3();
  points.free();
  resultPoints.free();
  p3.free();
  p4.free();
  return resoult;
};

/**
 * @description 圆柱拟合
 * @param Points 测量点
 * @param P1 圆面顶面
 * @param P2 圆面底面
 * @returns
 */
export const CalculateAccurateCylindersFromMultipleMeasurementPoints = async (
  Points: CustomVector3[],
  P1: CustomVector3,
  P2: CustomVector3
) => {
  const points = new EmxArray_real_T(Points);
  const p1 = new EmxArray_real_T(P1);
  const p2 = new EmxArray_real_T(P2);
  const center = new EmxArray_real_T(3, 1);
  const mTaon = new EmxArray_real_T(3, 1);
  const Mradial = new EmxArray_real_T(1, 1);
  const Err_every = new EmxArray_real_T(Points.length, 1);
  const Bottom_round_center1 = new EmxArray_real_T(3, 2);

  _CalculateAccurateCylindersFromMultipleMeasurementPoints(
    points.ptr,
    p1.arrayPtr,
    p2.arrayPtr,
    center.arrayPtr,
    mTaon.arrayPtr,
    Mradial.arrayPtr,
    Err_every.ptr,
    Bottom_round_center1.arrayPtr,
    Bottom_round_center1.arrayPtr + 8 * 3
  );
  const result = {
    center: center.toVector3()[0],
    Err_every: Err_every.toJSON()[0],
    mTaon: mTaon.toVector3()[0],
    R: Mradial.toJSON()?.[0],
    Bottom_round_center: Bottom_round_center1.toVector3(),
  };

  center.free();
  mTaon.free();
  Mradial.free();
  Err_every.free();
  p1.free();
  p2.free();
  return result;
};

/**
 * @description 计算AB面点
 * @param MTaon 圆柱轴线方向向量
 * @param Mcenter 圆柱中心点
 * @param r 圆半径
 * @param Bottom_round_center1 圆柱顶面
 * @param Bottom_round_center2 圆柱地面
 * @param testP AB面交点垂直面所在点
 * @param numShengLu 声道数量
 * @param phi 声路角
 * @returns
 */
export const CalculatAAndBPoints = async (
  MTaon: CustomVector3,
  Mcenter: CustomVector3,
  r: number,
  Bottom_round_center1: CustomVector3,
  Bottom_round_center2: CustomVector3,
  testP: CustomVector3,
  numShengLu: number,
  phi: number,
  tOff: number,
  rOff: number
) => {
  const mTaon = new EmxArray_real_T(MTaon);
  const mCenter = new EmxArray_real_T(Mcenter);
  const bottom_round_center1 = new EmxArray_real_T(Bottom_round_center1);
  const bottom_round_center2 = new EmxArray_real_T(Bottom_round_center2);
  const _testP = new EmxArray_real_T(testP);
  const A = new EmxArray_real_T(3, numShengLu * 2);
  const B = new EmxArray_real_T(3, numShengLu * 2);
  _CalculatAAndBPoints(
    mTaon.arrayPtr,
    mCenter.arrayPtr,
    r,
    bottom_round_center1.arrayPtr,
    bottom_round_center2.arrayPtr,
    _testP.arrayPtr,
    numShengLu,
    phi,
    tOff,
    rOff,
    A.ptr,
    B.ptr
  );

  const res = {
    bottomA: A.toVector3(),
    bottomB: B.toVector3(),
  };

  A.free();
  B.free();
  return res;
};

/**
 * 复测计算声路角和生路长
 */
export const repeatSurvey = (
  point1: CustomVector3,
  point2: CustomVector3,
  Bottom_round_center1: CustomVector3,
  Bottom_round_center2: CustomVector3
) => {
  const bottom_round_center1 = new EmxArray_real_T(Bottom_round_center1);
  const bottom_round_center2 = new EmxArray_real_T(Bottom_round_center2);
  const P1 = new EmxArray_real_T(point1);
  const P2 = new EmxArray_real_T(point2);
  const SoundAngle = new EmxArray_real_T(1, 1);
  const SoundLength = new EmxArray_real_T(1, 1);

  _Repeat_Survey(
    P1.ptr,
    P2.ptr,
    bottom_round_center1.ptr,
    bottom_round_center2.ptr,
    SoundAngle.arrayPtr,
    SoundLength.arrayPtr
  );
  const res = {
    soundLength: SoundLength.toJSON()?.[0],
    soundAngle: SoundAngle.toJSON()?.[0],
  };

  bottom_round_center1.free();
  bottom_round_center2.free();
  P1.free();
  P2.free();
  SoundAngle.free();
  SoundLength.free();
  return res;
};

/**
 *  计算标准差
 * @param points
 * @returns
 */
export const calculateStandardDeviation = (points: CustomVector3[]) => {
  console.log("%c Line:214 🥒 points", "color:#f5ce50", points);
  const mean =
    points.reduce((acc, cur) => {
      return acc + cur.difference;
    }, 0) / points.length;

  const squaredDifferences = points.map((item) =>
    Math.pow(item.difference - mean, 2)
  );

  const totalSquaredDifference = squaredDifferences.reduce(
    (acc, val) => acc + val,
    0
  );

  const variance = Math.sqrt(totalSquaredDifference / points.length);

  return variance;
};

/**
 * 从参数表中获得固定参数
 * @param sdfb
 * @param index
 */
export const getDataFromTable = (sdfb: number, index: number) => {
  return tableData.find((item) => {
    return item.N === sdfb && item.i === index + 1;
  });
};
