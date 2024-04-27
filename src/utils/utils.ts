import EmxArray_real_T from "../class/EmxArray_real_T";
import { CustomVector3 } from "../class/CustomVector3";
import { data, p3array, p4array } from "./mockData";

const {
  _generateUnitCircleWithNormalVector,
  _GenerateMultiLayeredMeasurementPoints,
  _CalculateAccurateCylindersFromMultipleMeasurementPoints,
  _CalculatAAndBPoints,
} = (window as any).Module;

export const generateUnitCircleWithNormalVector = (
  azimuth: number,
  elevation: number,
  numPerLay: number,
  laynum: number,
  P3: CustomVector3,
  P4: CustomVector3
) => {
  const points = new EmxArray_real_T(3, numPerLay * laynum);
  const p3 = new EmxArray_real_T(P3);
  const p4 = new EmxArray_real_T(P4);
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
    P3,
    P4,
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
  P3: CustomVector3,
  P4: CustomVector3
) => {
  const points = new EmxArray_real_T(Points);
  const p3 = new EmxArray_real_T(P3);
  const p4 = new EmxArray_real_T(P4);
  const resultPoints = new EmxArray_real_T(3, numPerLay * laynum);
  console.group("GenerateMultiLayeredMeasurementPoints");
  console.log("%c Line:35 🥪 points", "color:#4fff4B", points.toVector3());

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

export const CalculateAccurateCylindersFromMultipleMeasurementPoints = (
  Points: CustomVector3[],
  P_bound1: CustomVector3,
  P_bound2: CustomVector3
) => {
  const points = new EmxArray_real_T(Points);
  const p1 = new EmxArray_real_T(P_bound1);
  const p2 = new EmxArray_real_T(P_bound2);
  const center = new EmxArray_real_T(3, 1);
  const mTaon = new EmxArray_real_T(3, 1);
  const Mradial = new EmxArray_real_T(1, 1);
  const Err_every = new EmxArray_real_T(1, Points.length);
  const Bottom_round_center1 = new EmxArray_real_T(3, 2);
  console.group("GenerateMultiLayeredMeasurementPoints");
  console.log("%c Line:73 🍤 points", "color:#93c0a4", points.toVector3());
  console.log("%c Line:74 🍰 p1", "color:#33a5ff", p1.toVector3());
  console.log("%c Line:75 🥔 p2", "color:#93c0a4", p2.toVector3());

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
    Err_every: Err_every.toJSON(),
    mTaon: mTaon.toJSON()?.[0],
    Mradial: Mradial.toJSON()?.[0],
    Bottom_round_center: Bottom_round_center1.toVector3(),
  };
  console.log("%c Line:93 🍿 result", "color:#ea7e5c", result);

  console.groupEnd();
  center.free();
  mTaon.free();
  Mradial.free();
  Err_every.free();
  p1.free();
  p2.free();
  return result;
};

export const CalculatAAndBPoints = (
  MTaon: CustomVector3,
  Mcenter: CustomVector3,
  r: number,
  Bottom_round_center1: CustomVector3,
  Bottom_round_center2: CustomVector3,
  testP: CustomVector3,
  numShengLu: number,
  phi: number
) => {
  const mTaon = new EmxArray_real_T(MTaon);
  const mCenter = new EmxArray_real_T(Mcenter);
  const bottom_round_center1 = new EmxArray_real_T(Bottom_round_center1);
  const bottom_round_center2 = new EmxArray_real_T(Bottom_round_center2);
  const _testP = new EmxArray_real_T(testP);

  _CalculatAAndBPoints(
    mTaon.arrayPtr,
    mCenter.arrayPtr,
    r,
    bottom_round_center1.arrayPtr,
    bottom_round_center2.arrayPtr,
    _testP.arrayPtr,
    numShengLu,
    phi
  );

  return {
    bottomA: bottom_round_center1.toVector3(),
    bottomB: bottom_round_center2.toVector3(),
  };
};
