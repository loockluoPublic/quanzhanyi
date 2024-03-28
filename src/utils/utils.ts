import EmxArray_real_T from "../class/EmxArray_real_T";
import { CustomVector3 } from "../class/CustomVector3";
import { data, p3array, p4array } from "./mockData";

const {
  _generateUnitCircleWithNormalVector,
  _GenerateMultiLayeredMeasurementPoints,
  _CalculateAccurateCylindersFromMultipleMeasurementPoints,
} = (window as any).Module;

export const generateUnitCircleWithNormalVector = (
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

export const GenerateMultiLayeredMeasurementPoints = (
  Points: CustomVector3[],
  num: number,
  laynum: number,
  P3: CustomVector3,
  P4: CustomVector3
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
    mTaon: mTaon.toJSON()[0],
    Mradial: Mradial.toJSON()[0],
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
  let v1 = new CustomVector3(1, 2, 3);
  const points = new EmxArray_real_T(v1);
  console.log("%c Line:105 🍤 points", "color:#b03734", points);

  console.log(
    "%c Line:105 🍤 points",
    "color:#f5ce50",
    v1,
    v1.toSpherical(),
    points.toJSON(),
    points.toVector3()
  );
  v1 = new CustomVector3(0, 1, 0);

  console.log("%c Line:103 🍇 1", "color:#f5ce50", v1, v1.toSpherical());
  v1 = new CustomVector3(1, 0, 0);

  console.log("%c Line:103 🍇 1", "color:#f5ce50", v1, v1.toSpherical());

  const azimuth = Math.PI / 2;
  const elevation = Math.PI / 2;
  let start = performance.now();
  console.log("%c Line:122 🍅 方向", "color:#3f7cff", azimuth, elevation);
  const res = generateUnitCircleWithNormalVector(azimuth, elevation, 5);
  console.table(res);
  console.table(res.map((t) => t.toSpherical()));

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
    return new CustomVector3(...item);
  });
  const p3 = new CustomVector3(...p3array[i]);
  const p4 = new CustomVector3(...p4array[i]);
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
      pointsFlat.push(new CustomVector3(...item));
    });
  }
  console.log("%c Line:125 🍧 pointsFlat", "color:#ea7e5c", pointsFlat);
  start = performance.now();
  const res3 = CalculateAccurateCylindersFromMultipleMeasurementPoints(
    pointsFlat,
    pointsFlat[0],
    pointsFlat[24]
  );
  console.log(
    "%c Line:108 🍌 start",
    "color:#4fff4B",
    performance.now() - start
  );
  console.log("%c Line:132 🍭 res3", "color:#b03734", res3);
};
setTimeout(init, 500);
// init();
