import EmxArray_real_T from "./class/EmxArray_real_T";

const {
  _generate_unit_circle_with_normal_vector,
  _Generate_multi_layered_measurement_points,
} = (window as any).Module;

const init = () => {
  const de = new EmxArray_real_T([
    [1, 2, 3],
    [4, 5, 6],
  ]);
  const de2 = new EmxArray_real_T([1, 2, 3]);
  const de23 = new EmxArray_real_T([[1, 2, 3]]);
  const de1 = new EmxArray_real_T(3, 2);
  const de11 = new EmxArray_real_T(1, 20);
  const de12 = new EmxArray_real_T(10, 1);
  console.log(
    "%c Line:157 🥕 3,2",
    "color:#42b983",
    de.toJSON(),
    de2.toJSON(),
    de23.toJSON(),
    de1.toJSON(),
    de11.toJSON(),
    de12.toJSON()
  );
  const x = new EmxArray_real_T(1, 5); //emxArray_real_T();
  const y = new EmxArray_real_T(1, 5); //emxArray_real_T();
  const z = new EmxArray_real_T(1, 5); //emxArray_real_T();
  console.log("%c Line:50 🍤 res.toJSON()", "color:#b03734", x.toJSON());
  let res = _generate_unit_circle_with_normal_vector(
    Math.PI / 3,
    Math.PI / 4,
    5,
    x.ptr,
    y.ptr,
    z.ptr
  );
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
  console.log("%c Line:51 🥪 de112", "color:#ffdd4d", res);

  // console.log("计算结果:", x.toJSON(), y.toJSON(), z.toJSON());
  // x.free();
};

init();
