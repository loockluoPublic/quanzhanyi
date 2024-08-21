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
  _Planefit,
  _offsetCalculate,
  _shengLuJiaoJiSuan,
  _shengDaoGaoDu,
  _Planefit4,
  _CalculateRectangleFromVertex,
  _CalcJuXingAAndBPointsAfterOffest,
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
 * @param R 圆半径
 * @param PAB AB面交点垂直面所在点
 * @param phi 声路角
 * 下面是三个1*2n的参数
 * @param ang   手动修正角度
 * @param tOff  轴向位移
 * @param rOff  径向位移
 * @returns
 */
export const CalculatAAndBPoints = async (
  MTaon: CustomVector3,
  Mcenter: CustomVector3,
  R: number,
  PAB: CustomVector3,
  phi: number,
  ang: number[],
  tOff: number[],
  rOff: number[]
) => {
  const mTaon = new EmxArray_real_T(MTaon);
  const mCenter = new EmxArray_real_T(Mcenter);
  const _PAB = new EmxArray_real_T(PAB);
  const _ang = new EmxArray_real_T(ang.map(ang2rad));
  const _tOff = new EmxArray_real_T(tOff);
  const _rOff = new EmxArray_real_T(rOff);
  const A = new EmxArray_real_T(3, ang.length);
  const B = new EmxArray_real_T(3, ang.length);

  _CalculatAAndBPoints(
    mTaon.arrayPtr,
    mCenter.arrayPtr,
    R,
    _PAB.arrayPtr,
    ang2rad(phi),
    _ang.ptr,
    _tOff.ptr,
    _rOff.ptr,
    A.ptr,
    B.ptr
  );

  CustomVector3.setPublicInfo("A", 0);
  const bottomA = A.toVector3();
  CustomVector3.setPublicInfo("B", 0);
  const bottomB = B.toVector3();

  const res = bottomA.map((a, i) => {
    return {
      pointA: a,
      pointB: bottomB[i],
    };
  });
  mTaon.free();
  mCenter.free();
  _PAB.free();
  _ang.free();
  _tOff.free();
  _rOff.free();
  A.free();
  B.free();
  return res;
};

/**
 * @description 矩形面拟合
 * @param Points 计算面的点
 * @param PlaneParaIn 已计算的平面参数
 * @param BoundPoint1 边界1
 * @param BoundPoint2 边界2
 * @param PlaneParaOut 输出平面参数
 * @param TrianglePoints 三角面的点
 * @returns
 */
export const Planefit = async (
  Points: CustomVector3[],
  PlaneParaIn: number[][],
  BoundPoint1: CustomVector3,
  BoundPoint2: CustomVector3
) => {
  const plantNum = PlaneParaIn.length + 1;
  const points = new EmxArray_real_T(Points);
  const planeParaIn = new EmxArray_real_T(PlaneParaIn);
  const boundPoint1 = new EmxArray_real_T(BoundPoint1);
  const boundPoint2 = new EmxArray_real_T(BoundPoint2);
  const planeParaOut = new EmxArray_real_T(4, plantNum);
  const trianglePoints = new EmxArray_real_T(3, plantNum * 2 * 3);

  _Planefit(
    points.ptr,
    planeParaIn.ptr,
    boundPoint1.arrayPtr,
    boundPoint2.arrayPtr,
    planeParaOut.ptr,
    trianglePoints.ptr
  );
  trianglePoints.getSize();
  const res = {
    planeParaOut: planeParaOut.toJSON(),
    trianglePoints: trianglePoints.toVector3(),
  };

  points.free();
  planeParaIn.free();
  planeParaOut.free();
  boundPoint1.free();
  boundPoint2.free();
  trianglePoints.free();
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
    P1.arrayPtr,
    P2.arrayPtr,
    bottom_round_center1.arrayPtr,
    bottom_round_center2.arrayPtr,
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

export const downLoadFile = (data, filename = "data.json") => {
  // 将JSON对象转换为字符串
  const jsonString = JSON.stringify(data, null, 2);

  // 创建一个Blob对象
  const blob = new Blob([jsonString], { type: "application/json" });

  // 创建一个链接元素
  const link = document.createElement("a");

  // 创建一个URL对象
  const url = URL.createObjectURL(blob);

  // 将URL对象赋值给链接元素的href属性
  link.href = url;

  // 设置下载文件的默认名称
  link.download = filename;

  // 将链接元素添加到DOM中（为了触发点击事件）
  document.body.appendChild(link);

  // 触发点击事件以下载文件
  link.click();

  // 移除链接元素
  document.body.removeChild(link);

  // 释放URL对象
  URL.revokeObjectURL(url);
};

export const loadFile = (jsonStr: string) => {
  return JSON.parse(jsonStr, (k, v) => {
    console.log(
      "%c Line:473 🥤 k,v",
      "color:#f5ce50",
      k,
      typeof v,
      v,
      Object.prototype.hasOwnProperty.call(v, "x"),
      Object.prototype.hasOwnProperty.call(v, "y"),
      Object.prototype.hasOwnProperty.call(v, "z")
    );
    if (
      typeof v === "object" &&
      Object.prototype.hasOwnProperty.call(v, "x") &&
      Object.prototype.hasOwnProperty.call(v, "y") &&
      Object.prototype.hasOwnProperty.call(v, "z")
    ) {
      console.log("%c Line:473 🍖 d v", "color:#ea7e5c", v);
      return new CustomVector3(v.x, v.y, v.z, v);
    }
    return v;
  });
};

// loadFile("");

/**
 * 根据声道数计算角度
 * @param R
 * @param phi
 * @param ang
 * @param a
 * @returns  [roff (径向),toff(轴向）][]
 */
export const offsetCalculate = (
  R: number,
  phi: number, // 声道角
  ang: number[], // 每个点的角度
  a: number[]
) => {
  const _ang = new EmxArray_real_T(ang.map(ang2rad));
  const _a = new EmxArray_real_T(a);
  const _offset = new EmxArray_real_T(2, a.length);
  _offsetCalculate(R, ang2rad(phi), _ang.ptr, _a.ptr, _offset.ptr);

  const res = _offset
    .toJSON()
    ?.map((row) => row.map((v) => Number(v.toFixed(6))));
  _ang.free();
  _a.free();
  _offset.free();
  return res;
};

/**
 * 矩形拟合
 * @param M1Points 左面点
 * @param M2Points 上面点
 * @param M3Points 右面点
 * @param M4Points 下面点
 * @param BoundPoint1 矩形范围点
 * @param BoundPoint2 矩形范围点
 * @returns
 */
export const Planefit4 = (
  M1Points: CustomVector3[],
  M2Points: CustomVector3[],
  M3Points: CustomVector3[],
  M4Points: CustomVector3[],
  BoundPoint1: CustomVector3,
  BoundPoint2: CustomVector3
) => {
  const m1 = new EmxArray_real_T(M1Points);
  const m2 = new EmxArray_real_T(M2Points);
  const m3 = new EmxArray_real_T(M3Points);
  const m4 = new EmxArray_real_T(M4Points);

  const boundPoint1 = new EmxArray_real_T(BoundPoint1);
  const boundPoint2 = new EmxArray_real_T(BoundPoint2);
  const planeParaOut = new EmxArray_real_T(4, 4);
  const trianglePoints = new EmxArray_real_T(3, 4 * 2 * 3);

  _Planefit4(
    m1.ptr,
    m2.ptr,
    m3.ptr,
    m4.ptr,
    boundPoint1.arrayPtr,
    boundPoint2.arrayPtr,
    planeParaOut.ptr,
    trianglePoints.ptr
  );

  const res = {
    planeParaOut: planeParaOut.toJSON(),
    trianglePoints: trianglePoints.toVector3(),
  };

  m1.free();
  m2.free();
  m3.free();
  m4.free();
  boundPoint1.free();
  boundPoint2.free();
  planeParaOut.free();
  trianglePoints.free();

  return res;
};

export const CalculateRectangleFromVertex = () => {
  _CalculateRectangleFromVertex();
};

/**
 * 计算相对高度
 * @param numShengLu
 * @returns
 */
export const shengDaoGaoDu = (numShengLu: number) => {
  const ti = new EmxArray_real_T(3, numShengLu * 2);

  _shengDaoGaoDu(numShengLu, ti.ptr);

  const res = ti.toVector3();

  ti.free();
  return res;
};

/**
 * 根据声道数计算角度 ang
 * @param numSL
 * @returns
 */
export const shengLuJiao2Ang = (numSL: number) => {
  const angs = new EmxArray_real_T(2 * numSL, 1);
  _shengLuJiaoJiSuan(numSL, angs.ptr);
  const res = angs.toJSON()?.[0]?.map((v) => {
    return Number(rad2ang(v).toFixed(6));
  });
  angs.free();
  return res;
};

/**
 * 角度转弧度
 * @param ang 角度
 * @returns
 */
export const ang2rad = (ang: number) => ang * (Math.PI / 180);

/**
 * 弧度转角度
 * @param rad 弧度
 * @returns
 */
export const rad2ang = (rad: number) => rad * (180 / Math.PI);
