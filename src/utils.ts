import EmxArray_real_T, { pickCol } from "./class/EmxArray_real_T";
import { data, ev, p3array, p4array } from "./mockData";

const {
  _generate_unit_circle_with_normal_vector,
  _Generate_multi_layered_measurement_points,
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
  _generate_unit_circle_with_normal_vector(
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

  const i = 1;

  const x2 = new EmxArray_real_T(pickCol(data[i], 0));
  const y2 = new EmxArray_real_T(pickCol(data[i], 1));
  const z2 = new EmxArray_real_T(pickCol(data[i], 2));

  const p3 = new EmxArray_real_T(p3array[i]);
  const p4 = new EmxArray_real_T(p4array[i]);
  const resultPoints = new EmxArray_real_T(3, 15);

  console.log("%c Line:76 🍫", "color:#7f2b82", resultPoints.toJSON());

  const res = _Generate_multi_layered_measurement_points(
    x2.ptr,
    y2.ptr,
    z2.ptr,
    5,
    3,
    p3.arrayPtr,
    p4.arrayPtr,
    resultPoints.ptr
  );
  console.log("%c Line:55 🍷 res", "color:#ed9ec7", res);
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

  console.log("x,y,z:", x2.toJSON(), y2.toJSON(), z2.toJSON());

  console.log("p3,p4:", p3.toJSON(), p4.toJSON());
  console.log("num,laynum:", 5, 3);

  console.log("%c Line:76 🍫", "color:#7f2b82", resultPoints.toJSON());
  // x.free();
};

init();
