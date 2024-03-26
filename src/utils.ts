import { Vector3 } from "three";
import EmxArray_real_T, { pickCol } from "./class/EmxArray_real_T";
import { data, p3array, p4array } from "./mockData";

const {
  _generateUnitCircleWithNormalVector,
  _GenerateMultiLayeredMeasurementPoints,
  _CalculateAccurateCylindersFromMultipleMeasurementPoints,
} = (window as any).Module;

const generateUnitCircleWithNormalVector = (
  azimuth: number,
  elevation: number,
  num: number
) => {
  const points = new EmxArray_real_T(3, num);
  _generateUnitCircleWithNormalVector(azimuth, elevation, num, points.ptr);
  const res = points.toVector3();
  points.free();
  return res;
};

const GenerateMultiLayeredMeasurementPoints = (
  Points: Vector3[],
  num: number,
  laynum: number,
  P3: Vector3,
  P4: Vector3
) => {
  const points = new EmxArray_real_T(Points);
  const p3 = new EmxArray_real_T(P3);
  const p4 = new EmxArray_real_T(P4);
  // const resultPoints = new EmxArray_real_T(3, num * laynum);
  const resultPoints = new EmxArray_real_T([
    [1, 2, 4, 5],
    [1, 2, 4, 5],
    [1, 2, 4, 5],
  ]);

  console.log(
    "%c Line:44 🥑 points.getSize()",
    "color:#fca650",
    points.getSize()
  );

  console.log(
    "%c Line:38 🍇 points.getDebugInfo().size",
    "color:#e41a6a",
    points.getDebugInfo().size,
    points.getDebugInfo()
  );
  console.log(
    "%c Line:39 🥖 resultPoints.getDebugInfo().size",
    "color:#6ec1c2",
    resultPoints.getDebugInfo().size,
    resultPoints.getDebugInfo()
  );
  console.log(
    "%c Line:47 🥟 points.ptr",
    "color:#ed9ec7",
    points.ptr,
    resultPoints.ptr
  );
  // _GenerateMultiLayeredMeasurementPoints(
  //   points.ptr,
  //   num,
  //   laynum,
  //   p3.arrayPtr,
  //   p4.arrayPtr,
  //   resultPoints.ptr
  // );
  const resoult = resultPoints.toVector3();
  points.free();
  resultPoints.free();
  p3.free();
  p4.free();
  return resoult;
};

const CalculateAccurateCylindersFromMultipleMeasurementPoints = (
  Points: Vector3[],
  azimuth: number,
  elevation: number,
  P_bound1: Vector3,
  P_bound2: Vector3
) => {
  const points = new EmxArray_real_T(Points);
  const p1 = new EmxArray_real_T(P_bound1);
  const p2 = new EmxArray_real_T(P_bound2);
  const center = new EmxArray_real_T(3, 1);
  const mTaon = new EmxArray_real_T(3, 1);
  const Mradial = new EmxArray_real_T(1, 1);
  const Err_every = new EmxArray_real_T(1, Points.length);
  const Bottom_round_center1 = new EmxArray_real_T(3, 2);
  _CalculateAccurateCylindersFromMultipleMeasurementPoints(
    points.ptr,
    azimuth,
    elevation,
    p1.arrayPtr,
    p2.arrayPtr,
    center.arrayPtr,
    mTaon.arrayPtr,
    Mradial.arrayPtr,
    Err_every.ptr,
    Bottom_round_center1.arrayPtr,
    Bottom_round_center1.arrayPtr + Float64Array.BYTES_PER_ELEMENT * 3
  );
  const result = {
    center: center.toVector3(),
    Err_every: Err_every.toJSON(),
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
const init = () => {
  // const azimuth = Math.PI / 3;
  // const elevation = Math.PI / 4;
  // const res = generateUnitCircleWithNormalVector(azimuth, elevation, 5);
  // console.log(
  //   "%c Line:90 🥪 generateUnitCircleWithNormalVector",
  //   "color:#6ec1c2",
  //   res
  // );
  const i = 0;
  const v = data[i].map((item) => {
    return new Vector3(...item);
  });
  const p3 = new Vector3(...p3array[i]);
  const p4 = new Vector3(...p4array[i]);
  console.log("%c Line:103 🥛 p3", "color:#e41a6a", p3, p4);
  const res2 = GenerateMultiLayeredMeasurementPoints(v, 3, 5, p3, p4);
  // console.log(
  //   "%c Line:105 🍯 GenerateMultiLayeredMeasurementPoints",
  //   "color:#b03734",
  //   res2
  // );
};
setTimeout(init, 500);
// init();
