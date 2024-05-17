// const arr2cptr = (array) => {
//   const arr = new Float64Array(array);
//   const ptr = Module._malloc(arr.length * arr.BYTES_PER_ELEMENT);
//   const arrayPointer = ptr / arr.BYTES_PER_ELEMENT;
//   Module.HEAPF64.set(array, arrayPointer);
//   return ptr;
// };

// setTimeout(() => {
//   // 创建要传递的 double 类型数组
//   const xData = [
//     1.3257, 1.4889, 1.4926, 1.9508, 1.7806, 1.8947, 2.1897, 2.0686, 2.3529,
//     2.3566, 1.2149, 2.3569, 1.8862, 1.8854, 1.684, 1.0448, 1.0864, 1.2046,
//     1.3173, 1.3629, 1.2119, 1.1062, 1.3259, 1.3701, 1.6091, 1.659, 1.6089,
//     1.3806, 1.609, 1.6563, 1.7775, 1.8991, 1.9016, 1.6587, 1.9439, 2.0645,
//     2.1869, 2.239, 1.9464, 2.185, 2.2329, 2.4724, 2.5232, 2.4689, 2.2356,
//   ];
//   const yData = [
//     2.0913, 1.5992, 1.5981, 2.0882, 1.512, 0.8509, 1.8332, 1.426, 1.341, 1.3399,
//     1.7185, 1.341, 1.8284, 1.8369, 1.1628, 1.1151, 1.2797, 1.6843, 2.098,
//     2.2773, 1.6822, 1.2833, 1.0286, 1.1932, 2.0096, 2.1848, 2.0136, 1.1968,
//     0.9412, 1.1067, 1.5131, 1.9212, 1.9218, 1.1057, 1.0191, 1.4273, 1.8337,
//     2.0024, 1.0184, 0.7588, 0.932, 1.7467, 1.9137, 1.743, 0.9311,
//   ];
//   const zData = [
//     -1.0991, -0.0726, -1.2741, -0.6723, -1.2731, -0.6714, -1.0962, -1.2721,
//     -0.0697, -1.2712, -1.2722, -1.2709, -1.1721, -0.1779, -0.1931, -0.6797,
//     -0.2555, -0.0784, -0.2419, -0.6667, -1.2724, -1.0968, -0.6774, -0.2517,
//     -0.2434, -0.668, -1.0994, -1.0966, -0.6749, -0.2489, -0.0756, -0.2454,
//     -1.0977, -1.0971, -0.2453, -0.073, -0.247, -0.6712, -1.0963, -0.6675,
//     -0.2429, -0.2492, -0.6724, -1.094, -1.0955,
//   ];

//   // 创建输入参数数组
//   const x = new Float64Array(xData);
//   const y = new Float64Array(yData);
//   const z = new Float64Array(zData);

//   // 分配内存并将数组数据复制到 WebAssembly 内存中
//   const xPtr = arr2cptr(xData);

//   const yPtr = arr2cptr(yData);

//   const zPtr = arr2cptr(zData);

//   // 分配内存给输出参数
//   const XXX1Ptr = Module._malloc(8); // double类型占用8个字节
//   const XXX2Ptr = Module._malloc(8);
//   const XXX3Ptr = Module._malloc(8);
//   const XXX4Ptr = Module._malloc(8);
//   const XXX5Ptr = Module._malloc(8);
//   const XXX6Ptr = Module._malloc(8);
//   const XXX7Ptr = Module._malloc(8);

//   Module._mycylderfit2(
//     xPtr,
//     yPtr,
//     zPtr,
//     XXX1Ptr,
//     XXX2Ptr,
//     XXX3Ptr,
//     XXX4Ptr,
//     XXX5Ptr,
//     XXX6Ptr,
//     XXX7Ptr
//   );

//   // 从内存中获取输出参数的值
//   const XXX1 = Module.HEAPF64[XXX1Ptr / 8]; // 除以8是因为double类型占用8个字节
//   const XXX2 = Module.HEAPF64[XXX2Ptr / 8];
//   const XXX3 = Module.HEAPF64[XXX3Ptr / 8];
//   const XXX4 = Module.HEAPF64[XXX4Ptr / 8];
//   const XXX5 = Module.HEAPF64[XXX5Ptr / 8];
//   const XXX6 = Module.HEAPF64[XXX6Ptr / 8];
//   const XXX7 = Module.HEAPF64[XXX7Ptr / 8];

//   // 释放内存
//   Module._free(xPtr);
//   Module._free(yPtr);
//   Module._free(zPtr);
//   Module._free(XXX1Ptr);
//   Module._free(XXX2Ptr);
//   Module._free(XXX3Ptr);
//   Module._free(XXX4Ptr);
//   Module._free(XXX5Ptr);
//   Module._free(XXX6Ptr);
//   Module._free(XXX7Ptr);
// }, 500);

const init = () => {
  const {
    _free,
    HEAPF64,
    HEAP32,
    _malloc,
    _test,
    _generate_unit_circle_with_normal_vector,
  } = window.Module;

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

  console.log("%c Line:27 🥚 init", "color:#42b983", _test);
  var emxArrayX = {
    data: Float64ArrayPtr([0, 0, 0, 0, 0]), // 指向数据的指针
    size: HEAP32ArrayPtr([5]), // size数组
    allocatedSize: 5, // 分配的大小
    numDimensions: 1, // 维度
    canFreeData: false, // 是否可以释放数据
  };
  _test(1);
  console.log("%c Line:29 🍣 _test(1)", "color:#ffdd4d", _test(1, emxArrayX));
};

setTimeout(() => {
  init();
}, 500);
