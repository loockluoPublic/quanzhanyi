import EmxArray_real_T, { pickCol } from "./class/EmxArray_real_T";
import { data, ev, p3array, p4array } from "./mockData";

const {
  _generateUnitCircleWithNormalVector,
  _GenerateMultiLayeredMeasurementPoints,
} = (window as any).Module;

const init = () => {
  // const de = new EmxArray_real_T([
  //   [1, 2, 3],
  //   [4, 5, 6],
  // ]);
  // const de2 = new EmxArray_real_T([1, 2, 3]);
  // const de23 = new EmxArray_real_T([[1, 2, 3]]);
  // const de1 = new EmxArray_real_T(3, 2);
  // const de11 = new EmxArray_real_T(1, 20);
  // const de12 = new EmxArray_real_T(10, 1);
  // console.log(
  //   "%c Line:157 🥕 3,2",
  //   "color:#42b983",
  //   de.toJSON(),
  //   de2.toJSON(),
  //   de23.toJSON(),
  //   de1.toJSON(),
  //   de11.toJSON(),
  //   de12.toJSON()
  // );
  const x = new EmxArray_real_T(1, 9);
  const y = new EmxArray_real_T(1, 9);
  const z = new EmxArray_real_T(1, 9);
  _generateUnitCircleWithNormalVector(
    Math.PI / 3,
    Math.PI / 4,
    6,
    x.ptr,
    y.ptr,
    z.ptr
  );

  console.log(
    "%c Line:50 🍤 _generate_unit_circle_with_normal_vector-x",
    "color:#b03734",
    x.toJSON()
  );

  const i = 0;

  const x2 = new EmxArray_real_T(pickCol(data[i], 0));
  const y2 = new EmxArray_real_T(pickCol(data[i], 1));
  const z2 = new EmxArray_real_T(pickCol(data[i], 2));

  const p3 = new EmxArray_real_T(p3array[i]);
  const p4 = new EmxArray_real_T(p4array[i]);
  const resultPoints = new EmxArray_real_T(3, 15);
  const debugRes = new EmxArray_real_T(1,10);

  // console.log("%c Line:76 🍫", "color:#7f2b82", resultPoints.toJSON());

 const res = _GenerateMultiLayeredMeasurementPoints(
    x2.ptr,
    y2.ptr,
    z2.ptr,
    5,
    3,
    p3.arrayPtr,
    p4.arrayPtr,
    resultPoints.ptr,
    debugRes.arrayPtr
  )
  console.log("%c Line:55 🍷 中断变量值：", "color:#ed9ec7",res, debugRes.toJSON());
  // // console.log("%c Line:67 🍊 res", "color:#fca650", res);
  // // const numDimensions = callTest((window as any).Module, a, data, size);
  // // console.log("%c Line:64 🥤 numDimensions", "color:#ffdd4d", numDimensions);
  // const de112 = new EmxArray_real_T(3, 5);
  // _generate_unit_circle_with_normal_vector(
  //   Math.PI / 3,
  //   Math.PI / 4,
  //   5,
  //   de112.ptr
  // );
  // console.log("%c Line:51 🥪 de112", "color:#ffdd4d", res);

  console.log("x,y,z:");
  console.table([x2.toJSON(), y2.toJSON(), z2.toJSON()]);

  console.log("p3,p4:");
  console.table([p3.toJSON(), p4.toJSON()]);
  console.log("num,laynum:", 5, 3);

  console.log("%c Line:76 🍫 结果：", "color:#7f2b82");
  console.table(resultPoints.toJSON());

  // const x22 = new EmxArray_real_T(pickCol(data[i], 0).slice(0, 3));
  // const y22 = new EmxArray_real_T(pickCol(data[i], 1).slice(0, 3));
  // const z22 = new EmxArray_real_T(pickCol(data[i], 2).slice(0, 3));
  // const ss = new EmxArray_real_T(1, 3);
  // const zzzz = new EmxArray_real_T(1, 10);

  // _Three_Points_Initial_Rough_Cylindrical_Judgment(
  //   x22.arrayPtr,
  //   y22.arrayPtr,
  //   z22.arrayPtr,
  //   ss.arrayPtr,
  //   zzzz.arrayPtr,
  //   zzzz.arrayPtr + Float64Array.BYTES_PER_ELEMENT,
  //   zzzz.arrayPtr + 2 * Float64Array.BYTES_PER_ELEMENT
  // );

  // console.log("%c Line:91 🥪 x22", "color:#fca650", x22.toJSON());
  // console.log("%c Line:91 🥪 y22", "color:#fca650", y22.toJSON());
  // console.log("%c Line:91 🥪 z22", "color:#fca650", z22.toJSON());
  // console.log("%c Line:99 🍑 ss", "color:#e41a6a", ss.toJSON());
  // console.log("%c Line:99 🍑 xyz", "color:#e41a6a", zzzz.toJSON());

  // x.free();
};

init();
