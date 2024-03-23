import EmxArray_real_T from "./class/EmxArray_real_T";

const { _free, HEAPF64, HEAP32, _malloc, _test, _G5P } = (window as any).Module;

const Float64ArrayPtr = (array) => {
  const arr = new Float64Array(array);
  const ptr = _malloc(arr.length * arr.BYTES_PER_ELEMENT);
  const arrayPointer = ptr / arr.BYTES_PER_ELEMENT;
  HEAPF64.set(array, arrayPointer);
  return ptr;
};

const HEAP32ArrayPtr = (array) => {
  const arr = new Int32Array(array);
  const ptr = _malloc(arr.length * arr.BYTES_PER_ELEMENT);
  const arrayPointer = ptr / arr.BYTES_PER_ELEMENT;
  HEAPF64.set(array, arrayPointer);
  return ptr;
};

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
  // const x = new EmxArray_real_T([1, 2, 3, 4, 5, 6]); //emxArray_real_T();
  // const y = new EmxArray_real_T([1, 2, 3, 4, 5, 6]); //emxArray_real_T();
  // const z = new EmxArray_real_T([1, 2, 3, 4, 5, 6]); //emxArray_real_T();
  // // const y = emxArray_real_T();
  // // const z = emxArray_real_T();
  // // let res = _generate_unit_circle_with_normal_vector(1, 0, 5, x, y, z);
  // // console.log("%c Line:67 🍊 res", "color:#fca650", res);
  // // const numDimensions = callTest((window as any).Module, a, data, size);
  // // console.log("%c Line:64 🥤 numDimensions", "color:#ffdd4d", numDimensions);
  const de112 = new EmxArray_real_T(3, 5);
  _G5P(Math.PI / 3, Math.PI / 4, 5, de112.ptr);
  console.log("%c Line:51 🥪 de112", "color:#ffdd4d", de112.toJSON());

  // console.log("计算结果:", x.toJSON(), y.toJSON(), z.toJSON());
  // x.free();
};

init();

export const getPoints = () => {
  var emxArrayX = {
    data: Float64ArrayPtr([0, 0, 0, 0, 0]), // 指向数据的指针
    size: HEAP32ArrayPtr([5]), // size数组
    allocatedSize: 5, // 分配的大小
    numDimensions: 1, // 维度
    canFreeData: false, // 是否可以释放数据
  };

  var emxArrayY = {
    data: Float64ArrayPtr([0, 0, 0, 0, 0]), // 指向数据的指针
    size: HEAP32ArrayPtr([5]), // size数组
    allocatedSize: 5, // 分配的大小
    numDimensions: 1, // 维度
    canFreeData: false, // 是否可以释放数据
  };

  var emxArrayZ = {
    data: Float64ArrayPtr([0, 0, 0, 0, 0]), // 指向数据的指针
    size: HEAP32ArrayPtr([5]), // size数组
    allocatedSize: 5, // 分配的大小
    numDimensions: 1, // 维度
    canFreeData: false, // 是否可以释放数据
  };

  _generate_unit_circle_with_normal_vector(
    1,
    0,
    5,
    emxArrayX,
    emxArrayY,
    emxArrayZ
  );

  console.log(
    "%c Line:35 🍒 emxArrayX",
    "color:#7f2b82",
    emxArrayX,
    emxArrayY,
    emxArrayZ
  );
};
