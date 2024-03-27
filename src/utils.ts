import { Vector3 } from "three";
import EmxArray_real_T, { pickCol } from "./class/EmxArray_real_T";
import { data, p3array, p4array } from "./mockData";

const {
  _test,
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
  const resultPoints = new EmxArray_real_T(3, num * laynum);
  console.log(
    "%c Line:35 🥪 resultPoints",
    "color:#4fff4B",
    resultPoints.toVector3()
  );

  _GenerateMultiLayeredMeasurementPoints(
    points.ptr,
    num,
    laynum,
    p3.arrayPtr,
    p4.arrayPtr,
    resultPoints.ptr
  );
  console.log(
    "%c Line:45 🥥 resultPoints",
    "color:#ea7e5c",
    resultPoints,
    points.toJSON()
  );
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
  const azimuth = Math.PI / 3;
  const elevation = Math.PI / 4;
  let start = performance.now();
  const res = generateUnitCircleWithNormalVector(azimuth, elevation, 5);
  console.log(
    "%c Line:108 🍌 start",
    "color:#4fff4B",
    performance.now() - start
  );
  console.log(
    "%c Line:90 🥪 generateUnitCircleWithNormalVector",
    "color:#6ec1c2",
    res
  );

  let i = 0;
  const v = data[i].map((item) => {
    return new Vector3(...item);
  });
  const p3 = new Vector3(...p3array[i]);
  const p4 = new Vector3(...p4array[i]);
  console.log("%c Line:103 🥛 p3", "color:#e41a6a", p3, p4);
  start = performance.now();
  const res2 = GenerateMultiLayeredMeasurementPoints(v, 3, 5, p3, p4);
  console.log(
    "%c Line:108 🍌 start",
    "color:#4fff4B",
    performance.now() - start
  );
  console.log("%c Line:128 🥖 res2", "color:#2eafb0", res2);

  const pointsFlat = [];
  for (const dataIndex of data) {
    dataIndex.forEach((item) => {
      pointsFlat.push(new Vector3(...item));
    });
  }
  console.log("%c Line:125 🍧 pointsFlat", "color:#ea7e5c", pointsFlat);
  start = performance.now();
  const res3 = CalculateAccurateCylindersFromMultipleMeasurementPoints(
    pointsFlat,
    1,
    2,
    pointsFlat[0],
    pointsFlat[24]
  );
  console.log(
    "%c Line:108 🍌 start",
    "color:#4fff4B",
    performance.now() - start
  );
  console.log("%c Line:132 🍭 res3", "color:#b03734", res3);

  // const resultPoints = new EmxArray_real_T([
  //   [1, 2, 4, 5],
  //   [1, 2, 4, 5],
  //   [1, 2, 4, 5],
  // ]);
  // _test(resultPoints.ptr);
  // console.log(
  //   "%c Line:44 🥑 points.getSize()",
  //   "color:#fca650",
  //   resultPoints,
  //   resultPoints.getSize(),
  //   resultPoints.toJSON()
  // );

  // console.log(
  //   "%c Line:105 🍯 GenerateMultiLayeredMeasurementPoints",
  //   "color:#b03734",
  //   res2
  // );
};
setTimeout(init, 500);
// init();
