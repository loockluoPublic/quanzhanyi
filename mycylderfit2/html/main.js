setTimeout(() => {
  // 创建要传递的 double 类型数组
  const array = new Float64Array([1.112, 2.2, 3.3, 4.4, 5.5]);

  // 分配内存并将数组数据复制到 WebAssembly 内存中
  const ptr = Module._malloc(array.length * array.BYTES_PER_ELEMENT);
  const arrayPointer = ptr / array.BYTES_PER_ELEMENT;
  Module.HEAPF64.set(array, arrayPointer);

  // // 调用 WebAssembly 函数并传递数组的指针和长度
  // const result = Module._processDoubleArray(arrayPointer, array.length);
  // console.log("Result:", result);

  Module._mycylderfit2(ptr);

  // 释放数组的内存
  Module._free(ptr);
}, 500);
