import EmxArray_real_T from "../class/EmxArray_real_T";
import { CustomVector3 } from "../class/CustomVector3";
import { tableData } from "./config";
import { ICycle } from "../atom/type";
import _ from "loadsh";

const {
  _generateUnitCircleWithNormalVector,
  _CalculateAccurateCylindersFromMultipleMeasurementPoints,
  _CalculatAAndBPoints,
  _Repeat_Survey,
  _offsetCalculate,
  _shengLuJiaoJiSuan,
  _shengDaoGaoDu,
  _Planefit4,
  _Planefit8,
  _CalculateRectangleFromVertex,
  _CalcJuXingAAndBPointsAfterOffest,
  _CalculateRectangleFromVertex8,
  _juXingFuCe,
  _yuanXingFuCe,
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
  P2: CustomVector3,
  r: number
): Promise<CustomVector3[]> => {
  const points = new EmxArray_real_T(3, numPerLay * laynum);
  const p3 = new EmxArray_real_T(P1);
  const p4 = new EmxArray_real_T(P2);
  console.log("%c Line:55 🥓 r", "color:#6ec1c2", r);
  _generateUnitCircleWithNormalVector(
    azimuth,
    elevation,
    numPerLay,
    laynum,
    p3.arrayPtr,
    p4.arrayPtr,
    r,
    points.ptr
  );
  const res = points.toVector3();

  console.table(res);
  points.free();
  return res;
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

const fitArr = (arr: any[]) => {
  return [...arr, ...arr.reverse()];
};

const toSd = (array: any) => {
  const res: any[] = [];
  for (let index = 0; index < array.length; index = index + 2) {
    res.push([array[index], array[index + 1]]);
  }
  return res;
};

/**
 * @description 计算AB面点
 * @param MTaon 圆柱轴线方向向量
 * @param Mcenter 圆柱中心点
 * @param R 圆半径
 * @param PAB 中心点垂直面所在点
 * @param phi 声路角
 * 下面是三个1*2n的参数
 * @param ang   手动修正角度
 * @param tOff  轴向位移
 * @param rOff  径向位移
 * @returns
 */
const CalculatAAndBPointsFn = (
  MTaon: CustomVector3,
  Mcenter: CustomVector3,
  R: number,
  PAB: CustomVector3,
  phi: number,
  resultTable: ICycle["resultTable"],
  sdm: "A" | "B",
  sign: boolean
) => {
  const tOff = fitArr(
    resultTable?.map?.((item) => {
      return item.tOff;
    }) ?? []
  );

  const rOff = fitArr(
    resultTable?.map?.((item) => {
      return item.rOff;
    }) ?? []
  );

  const ang = fitArr(
    resultTable?.map?.((item) => {
      return ang2rad(item.ang);
    }) ?? []
  );

  const mTaon = new EmxArray_real_T(MTaon);
  const mCenter = new EmxArray_real_T(Mcenter);
  const _PAB = new EmxArray_real_T(PAB);
  const _ang = new EmxArray_real_T(ang);
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
    sign ? B.ptr : A.ptr,
    sign ? A.ptr : B.ptr
  );

  CustomVector3.setPublicInfo("A", 0);
  const bottomA = A.toVector3();
  for (let i = 0, j = bottomA.length - 1; i <= j; i++, j--) {
    bottomA[i].key = 2 * i + 1;
    bottomA[j].key = 2 * i + 2;
  }
  bottomA
    .sort((a, b) => a.key - b.key)
    .forEach((p) => {
      p.color = "red";
    });

  CustomVector3.setPublicInfo("B", 0);
  const bottomB = B.toVector3();
  for (let i = 0, j = bottomB.length - 1; i <= j; i++, j--) {
    bottomB[i].key = 2 * i + 1;
    bottomB[j].key = 2 * i + 2;
  }

  bottomB
    .sort((a, b) => a.key - b.key)
    .forEach((p) => {
      p.color = "#fab005";
    });

  const res = sdm === "A" ? toSd(bottomA) : toSd(bottomB);

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
 * @description 计算AB面点
 * @param MTaon 圆柱轴线方向向量
 * @param Mcenter 圆柱中心点
 * @param R 圆半径
 * @param PAB 中心点垂直面所在点
 * @param phi 声路角
 * @returns
 */
export const CalculatAAndBPoints = async (
  MTaon: CustomVector3,
  Mcenter: CustomVector3,
  R: number,
  PAB: CustomVector3,
  phi: number,
  resultTable: ICycle["resultTable"],
  sign: boolean
) => {
  const res = _.partition(resultTable, (t) => {
    return t.sdm === "A";
  }).reduce((acc, cur) => {
    if (cur?.length === 0) return acc;
    return [
      ...acc,
      ...CalculatAAndBPointsFn(
        MTaon,
        Mcenter,
        R,
        PAB,
        phi,
        cur,
        cur[0].sdm,
        sign
      ),
    ];
  }, []);

  return res;
};

export const CalculatAAndBPoints4 = (data) => {
  const res = _.partition(data.cubeTable, (t) => {
    return t.sdm === "A";
  }).reduce((acc, cur) => {
    if (cur?.length === 0) return acc;
    const tOff =
      cur?.map?.((item) => {
        return item.tOff;
      }) ?? [];

    const Ti =
      cur?.map?.((item) => {
        return item.h;
      }) ?? [];

    return [
      ...acc,
      ...CalcJuXingAAndBPointsAfterOffest(
        data.cubeResult,
        data.centerPoint,
        ang2rad(data.sdj),
        data.sdfb,
        Ti,
        tOff,
        cur[0].sdm
      ),
    ];
  }, []);

  return res;
};

export const CalculatAAndBPoints8 = (data, MxPortsArr) => {
  const res = _.partition(data.cubeTable, (t) => {
    return t.sdm === "A";
  }).reduce((acc, cur) => {
    if (cur?.length === 0) return acc;
    const a =
      cur?.map?.((item) => {
        return item.a;
      }) ?? [];

    const Ti =
      cur?.map?.((item) => {
        return item.h;
      }) ?? [];

    return [
      ...acc,
      ...CalculateRectangleFromVertex8(
        MxPortsArr,
        data.firstPoints[0],
        data.firstPoints[1],
        data.centerPoint,
        ang2rad(data.sdj),
        data.sdfb,
        Ti,
        a,
        data.distanceThreshold,
        cur[0].sdm
      ),
    ];
  }, []);

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
  return JSON.parse(jsonStr, (_, v) => {
    if (
      typeof v === "object" &&
      Object.prototype.hasOwnProperty.call(v, "x") &&
      Object.prototype.hasOwnProperty.call(v, "y") &&
      Object.prototype.hasOwnProperty.call(v, "z")
    ) {
      return new CustomVector3(v.x, v.y, v.z, v);
    }
    return v;
  });
};

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
    ?.map((row) => row.map((v) => Number(v.toFixed(4))));
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

interface IPlanefit {
  planeParaOut: number[][];
  trianglePoints: CustomVector3[];
  distanceThreshold: number;
  MxPoints: number[];
}

export const Planefit = (
  MPoints: CustomVector3[][],
  BoundPoint1: CustomVector3,
  BoundPoint2: CustomVector3,
  distanceThreshold: number
): IPlanefit | {} => {
  const len = MPoints.length;

  if (![4, 8].includes(len)) {
    console.error("采集面需要4或8个面");
    return {};
  }

  let totalPoints = 0;
  const mP = MPoints.map((item) => {
    totalPoints += item.length;
    return new EmxArray_real_T(item);
  });

  const boundPoint1 = new EmxArray_real_T(BoundPoint1);
  const boundPoint2 = new EmxArray_real_T(BoundPoint2);

  const planeParaOut = new EmxArray_real_T(4, len);
  const trianglePoints = new EmxArray_real_T(3, len * 2 * 3);
  const MaxDis = new EmxArray_real_T(len, 1);

  const LenDaoJiao = new EmxArray_real_T(8, 1);

  const distancesFianal = new EmxArray_real_T(totalPoints, 1);

  if (len === 4) {
    _Planefit4(
      ...mP.map((p) => p.ptr),
      boundPoint1.arrayPtr,
      boundPoint2.arrayPtr,
      distanceThreshold,
      planeParaOut.ptr,
      trianglePoints.ptr,
      MaxDis.arrayPtr,
      distancesFianal.ptr
    );
  } else {
    _Planefit8(
      ...mP.map((p) => p.ptr),
      boundPoint1.arrayPtr,
      boundPoint2.arrayPtr,
      distanceThreshold,
      planeParaOut.ptr,
      trianglePoints.ptr,
      MaxDis.arrayPtr,
      distancesFianal.ptr,
      LenDaoJiao.arrayPtr
    );
  }

  const _max = Number(Math.max(...MaxDis.toJSON()?.[0]).toFixed(4));

  let _distancesFianal = distancesFianal.toJSON()?.[0];

  let i = 0;

  const res = {
    planeParaOut: planeParaOut.toJSON(),
    trianglePoints: trianglePoints.toVector3(),
    distanceThreshold: _max,
    MxPoints: MPoints.map((arr) => {
      return arr.map((p) => {
        const curDiff = _distancesFianal[i++];
        const newP = p.cloneCustomVector3();
        newP.difference = curDiff;
        newP.enable = curDiff < _max;
        return newP;
      });
    }),
    LenDaoJiao: LenDaoJiao.toJSON()?.[0],
  };

  mP.forEach((p) => p.free()), boundPoint1.free();

  boundPoint2.free();
  planeParaOut.free();
  trianglePoints.free();

  return res;
};

export const CalculateRectangleFromVertex = (
  TrianglePoints: CustomVector3[]
) => {
  const trianglePoints = new EmxArray_real_T(TrianglePoints);
  const Pin = new EmxArray_real_T(3, 1);
  const Pout = new EmxArray_real_T(3, 1);
  const UPP = new EmxArray_real_T(3, 1);
  const b = new EmxArray_real_T(1, 1);
  const h = new EmxArray_real_T(1, 1);
  const w = new EmxArray_real_T(1, 1);
  const Tao = new EmxArray_real_T(3, 1);

  _CalculateRectangleFromVertex(
    trianglePoints.ptr,
    Pin.arrayPtr,
    Pout.arrayPtr,
    UPP.arrayPtr,
    b.arrayPtr,
    h.arrayPtr,
    w.arrayPtr,
    Tao.arrayPtr
  );

  const res = {
    pIn: Pin.toVector3()[0],
    pOut: Pout.toVector3()[0],
    UPP: UPP.toVector3()[0],
    b: b.toJSON()?.[0],
    h: h.toJSON()?.[0],
    w: w.toJSON()?.[0],
    Tao: Tao.toVector3()[0],
  };

  trianglePoints.free();
  Pin.free();
  Pout.free();
  UPP.free();
  b.free();
  h.free();
  w.free();
  Tao.free();
  return res;
};

export const CalculateRectangleFromVertex8 = (
  MPoints: CustomVector3[][],
  BoundPoint1: CustomVector3,
  BoundPoint2: CustomVector3,
  PAB: CustomVector3,
  phi: number,
  sdfb: number,
  _ti: number[],
  __a: number[],
  distanceThreshold: number,
  sdm: "A" | "B"
) => {
  const ti = fitArr(_ti);
  const a = fitArr(__a);

  let totalPoints = 0;
  const mP = MPoints.map((item) => {
    totalPoints += item.length;
    return new EmxArray_real_T(item);
  });

  const boundPoint1 = new EmxArray_real_T(BoundPoint1);
  const boundPoint2 = new EmxArray_real_T(BoundPoint2);

  const _PAB = new EmxArray_real_T(PAB);

  const Ti = new EmxArray_real_T(ti);

  const _a = new EmxArray_real_T(a);
  const A = new EmxArray_real_T(3, ti.length);
  const B = new EmxArray_real_T(3, ti.length);
  const XieMianPianYi = new EmxArray_real_T(ti.length, 1);

  _CalculateRectangleFromVertex8(
    ...mP.map((p) => p.ptr),
    boundPoint1.arrayPtr,
    boundPoint2.arrayPtr,
    _PAB.arrayPtr,
    phi,
    sdfb,
    Ti.ptr,
    _a.ptr,
    distanceThreshold,
    B.ptr,
    A.ptr,
    XieMianPianYi.ptr
  );
  const rOff = XieMianPianYi.toJSON()[0];
  let res = [];
  if (sdm === "A") {
    CustomVector3.setPublicInfo("A", 0);
    const bottomA = A.toVector3();
    for (let i = 0, j = bottomA.length - 1; i <= j; i++, j--) {
      bottomA[i].key = 2 * i + 1;
      bottomA[j].key = 2 * i + 2;

      bottomA[i].difference = rOff[i];
      bottomA[j].difference = rOff[j];
    }
    bottomA
      .sort((a, b) => a.key - b.key)
      .forEach((p) => {
        p.color = "red";
      });
    res = toSd(bottomA);
  } else {
    CustomVector3.setPublicInfo("B", 0);

    const bottomB = B.toVector3();
    for (let i = 0, j = bottomB.length - 1; i <= j; i++, j--) {
      bottomB[i].key = 2 * i + 1;
      bottomB[j].key = 2 * i + 2;

      bottomB[i].difference = rOff[i];
      bottomB[j].difference = rOff[j];
    }
    bottomB
      .sort((a, b) => a.key - b.key)
      .forEach((p) => {
        p.color = "#fab005";
      });
    res = toSd(bottomB);
  }

  mP.map((p) => p.free());

  boundPoint1.free();
  boundPoint2.free();

  _PAB.free();
  Ti.free();
  _a.free();
  A.free();
  B.free();
  XieMianPianYi.free();

  return res;
};

/**
 * 计算相对高度
 * @param numShengLu
 * @returns
 */
export const shengDaoGaoDu = (numShengLu: number) => {
  const ti = new EmxArray_real_T(1, numShengLu * 2);

  _shengDaoGaoDu(numShengLu, ti.ptr);

  const res = ti.toJSON();
  console.log("%c Line:696 🥖 res", "color:#42b983", res);

  ti.free();
  return res.slice(0, res.length / 2);
};

/**
 * 矩形tOff计算
 * @param a 插入深度
 * @param sdj 声道角
 * @param sign 符号
 * @returns
 */
export const cubeTOff = (a: number, sdj: number) => {
  console.log("%c Line:710 🍤 90 - sdj", "color:#f5ce50", 90 - sdj);
  return Number((a / Math.tan(ang2rad(90 - sdj))).toFixed(4));
};

/**
 * 计算矩形安装位置
 * @param cubeRes
 * @param PAB 中心点
 * @param sdj 声道角
 * @param sdfb 声道分布
 */
export const CalcJuXingAAndBPointsAfterOffest = (
  cubeRes: ReturnType<typeof CalculateRectangleFromVertex>,
  PAB: CustomVector3,
  sdj: number,
  sdfb: number,
  _Ti: number[],
  _TOff: number[],
  sdm: "A" | "B"
) => {
  const Ti = fitArr(_Ti);

  const TOff = [..._TOff?.map((n) => -n), ..._TOff.reverse()];

  const Pin = new EmxArray_real_T(cubeRes.pIn);
  const UPP = new EmxArray_real_T(cubeRes.UPP);
  const Tao = new EmxArray_real_T(cubeRes.Tao);
  const pab = new EmxArray_real_T(PAB);
  const ti = new EmxArray_real_T(Ti);
  const tOff = new EmxArray_real_T(TOff);

  const A = new EmxArray_real_T(3, Ti.length);
  const B = new EmxArray_real_T(3, Ti.length);

  _CalcJuXingAAndBPointsAfterOffest(
    Tao.arrayPtr,
    UPP.arrayPtr,
    Pin.arrayPtr,
    cubeRes.b,
    cubeRes.h,
    pab.arrayPtr,
    sdj,
    sdfb,
    ti.ptr,
    tOff.ptr,
    B.ptr,
    A.ptr
  );

  let res: any[] = [];
  CustomVector3.setPublicInfo(sdm, 0);
  if (sdm === "A") {
    const bottomA = A.toVector3();
    for (let i = 0, j = bottomA.length - 1; i <= j; i++, j--) {
      bottomA[i].key = 2 * i + 1;
      bottomA[j].key = 2 * i + 2;
    }
    bottomA
      .sort((a, b) => a.key - b.key)
      .forEach((p) => {
        p.color = "red";
      });
    res = toSd(bottomA);
  } else {
    const bottomB = B.toVector3();
    for (let i = 0, j = bottomB.length - 1; i <= j; i++, j--) {
      bottomB[i].key = 2 * i + 1;
      bottomB[j].key = 2 * i + 2;
    }
    bottomB
      .sort((a, b) => a.key - b.key)
      .forEach((p) => {
        p.color = "#fab005";
      });
    res = toSd(bottomB);
  }

  Pin.free();
  UPP.free();
  Tao.free();
  pab.free();
  ti.free();
  tOff.free();
  A.free();
  B.free();

  return res;
};

/**
 * 根据声道数计算角度 ang
 * @param numSL
 * @returns
 */

export const shengLuJiao2Ang = (numSL: number) => {
  const angs = new EmxArray_real_T(numSL * 2, 1);
  _shengLuJiaoJiSuan(numSL, angs.ptr);
  const res = angs.toJSON()?.[0]?.map((v) => {
    return Number(rad2ang(v).toFixed(6));
  });
  angs.free();
  console.log("%c Line:727 🥐 res", "color:#465975", res);
  const nw: any = [];
  for (let i = res.length / 2; i < res.length; i++) {
    // const element = array[index];
    nw.push(res[i]);
  }
  console.log("%c Line:728 🥐 nw", "color:#b03734", nw);
  return nw;
};

/**
 * 根据声道数计算角度 ang
 * @param numSL
 * @returns
 */
const juXingFuCeFn = (
  cubeRes: ReturnType<typeof CalculateRectangleFromVertex> & {
    LenDaoJiao: number[];
  },
  planeParaOut: number[][],
  cubeAgainTable: { p1: CustomVector3; p2: CustomVector3 }[],
  sdfb: number
) => {
  console.log("%c Line:780 🍒 sdfb", "color:#33a5ff", cubeRes.LenDaoJiao);
  const PointIn = new EmxArray_real_T(
    cubeAgainTable?.reduce?.((acc, cur) => {
      return [...acc, cur.p1, cur.p2];
    }, []) ?? []
  );
  const Pin = new EmxArray_real_T(cubeRes.pIn);
  const Tao = new EmxArray_real_T(cubeRes.Tao);
  const PlaneParaOut = new EmxArray_real_T(planeParaOut);

  const Distance = new EmxArray_real_T(sdfb, 1);
  const theta = new EmxArray_real_T(sdfb, 1);
  const LTPY = new EmxArray_real_T(sdfb, 1);
  const TiC = new EmxArray_real_T(sdfb, 1);
  const LenDaoJiao = new EmxArray_real_T(cubeRes.LenDaoJiao);
  const Wquanzhong3 = new EmxArray_real_T(sdfb, 1);
  const Wquanzhong4 = new EmxArray_real_T(sdfb, 1);

  _juXingFuCe(
    PointIn.ptr,
    sdfb,
    Pin.arrayPtr,
    Tao.arrayPtr,
    cubeRes.h,
    PlaneParaOut.ptr,
    LenDaoJiao.arrayPtr,
    Distance.ptr,
    theta.ptr,
    LTPY.ptr,
    TiC.ptr,
    Wquanzhong3.ptr,
    Wquanzhong4.ptr
  );

  const _Distance = Distance.toJSON()[0];
  const _theta = theta.toJSON()[0];
  const _LTPY = LTPY.toJSON()[0];
  const _TiC = TiC.toJSON()[0];
  console.log("%c Line:834 🥒 _TiC", "color:#f5ce50", _TiC);
  const _Wquanzhong3 = Wquanzhong3.toJSON()[0];
  const _Wquanzhong4 = Wquanzhong4.toJSON()[0];

  Distance.free();
  theta.free();
  LTPY.free();
  TiC.free();
  Wquanzhong3.free();
  Wquanzhong4.free();

  return _Distance.map((d, i) => {
    return {
      sdc: d,
      sdj: _theta[i],
      ltOffset: _LTPY[i],
      sdH: _TiC[i],
      Wquanzhong3: _Wquanzhong3[i],
      Wquanzhong4: _Wquanzhong4[i],
    };
  });
};

export const juXingFuCe = (
  cubeRes: ReturnType<typeof CalculateRectangleFromVertex> & {
    LenDaoJiao: number[];
  },
  planeParaOut: number[][],
  cubeAgainTable: { p1: CustomVector3; p2: CustomVector3 }[],
  sdfb: number,
  sdmNum: number
) => {
  if (sdmNum === 2) {
    const resA = juXingFuCeFn(
      cubeRes,
      planeParaOut,
      cubeAgainTable.slice(0, sdfb),
      sdfb
    );
    const resB = juXingFuCeFn(
      cubeRes,
      planeParaOut,
      cubeAgainTable.slice(sdfb),
      sdfb
    );
    return [...resA, ...resB];
  } else {
    return juXingFuCeFn(cubeRes, planeParaOut, cubeAgainTable, sdfb);
  }
};

const yuanXingFuCeFn = (
  calulateRes: Awaited<
    ReturnType<typeof CalculateAccurateCylindersFromMultipleMeasurementPoints>
  >,
  cylinderAgainTable: { p1: CustomVector3; p2: CustomVector3 }[],
  sdfb: number,
  sdj: number
) => {
  const PointIn = new EmxArray_real_T(
    cylinderAgainTable?.reduce?.((acc, cur) => {
      return [...acc, cur.p1, cur.p2];
    }, []) ?? []
  );

  const Mcenter = new EmxArray_real_T(calulateRes.center);
  const MTaon = new EmxArray_real_T(calulateRes.mTaon);

  const Distance = new EmxArray_real_T(sdfb, 1);
  const theta = new EmxArray_real_T(sdfb, 1);
  const LTPY = new EmxArray_real_T(sdfb, 1);
  const TiC = new EmxArray_real_T(sdfb, 1);
  const Wquanzhong3 = new EmxArray_real_T(sdfb, 1);
  const Wquanzhong4 = new EmxArray_real_T(sdfb, 1);

  _yuanXingFuCe(
    PointIn.ptr,
    sdfb,
    Mcenter.arrayPtr,
    MTaon.arrayPtr,
    calulateRes.R,
    sdj,
    Distance.ptr,
    theta.ptr,
    LTPY.ptr,
    TiC.ptr,
    Wquanzhong3.ptr,
    Wquanzhong4.ptr
  );

  const _Distance = Distance.toJSON()[0];
  const _theta = theta.toJSON()[0];
  const _LTPY = LTPY.toJSON()[0];
  const _TiC = TiC.toJSON()[0];
  const _Wquanzhong3 = Wquanzhong3.toJSON()[0];
  const _Wquanzhong4 = Wquanzhong4.toJSON()[0];

  Distance.free();
  theta.free();
  LTPY.free();
  TiC.free();
  Wquanzhong3.free();
  Wquanzhong4.free();

  return _Distance.map((d, i) => {
    return {
      sdc: d,
      sdj: _theta[i],
      ltOffset: _LTPY[i],
      sdH: _TiC[i],
      Wquanzhong3: _Wquanzhong3[i],
      Wquanzhong4: _Wquanzhong4[i],
    };
  });
};

export const yuanXingFuCe = (
  calulateRes: Awaited<
    ReturnType<typeof CalculateAccurateCylindersFromMultipleMeasurementPoints>
  >,
  cylinderAgainTable: { p1: CustomVector3; p2: CustomVector3 }[],
  sdfb: number,
  sdj: number,
  sdmNum: number
) => {
  if (sdmNum === 2) {
    const resA = yuanXingFuCeFn(calulateRes, cylinderAgainTable, sdfb, sdj);
    const resB = yuanXingFuCeFn(calulateRes, cylinderAgainTable, sdfb, sdj);
    return [...resA, ...resB];
  } else {
    return yuanXingFuCeFn(calulateRes, cylinderAgainTable, sdfb, sdj);
  }
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
export const rad2ang = (rad: number, abs?: boolean) => {
  const ang = rad * (180 / Math.PI);
  if (abs && ang > 90) {
    return 180 - ang;
  } else {
    return ang;
  }
};

/**
 * 声道角 实际值转换为 可见值
 * @param n
 */
export const sdj_n2v = (n: number) => 90 - n;

/**
 * 声道角 转换
 * @param n
 */
export const sdj_v2n = (v: number) => 90 - v;

// export jux
