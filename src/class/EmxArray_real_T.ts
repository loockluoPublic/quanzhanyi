/**
struct emxArray_real_T {
    double *data;
    int *size;
    int allocatedSize;
    int numDimensions;
    boolean_T canFreeData;
};
*/

const emModule = (window as any).Module;
export default class EmxArray_real_T {
  ptr: number;
  #dataPtr: number;
  #sizePtr: number;
  #numDimensions = 1;
  constructor(array: number[], numDimensions = 1) {
    this.#numDimensions = numDimensions;
    const arrayF64 = new Float64Array(array);
    //  为一个结构体分配线性内存空间，一个结构体为大小 8(指针)+8(指针)+4（int + 1(bool) =
    var emxArrayPtr = emModule._malloc(24);

    // Allocate and set data pointer
    this.#dataPtr = emModule._malloc(
      arrayF64.length * Float64Array.BYTES_PER_ELEMENT
    ); // 8 bytes per double
    emModule.HEAPF64.set(
      arrayF64,
      this.#dataPtr / Float64Array.BYTES_PER_ELEMENT
    );
    const size = new Int32Array([arrayF64.length]);

    // Allocate and set size pointer
    this.#sizePtr = emModule._malloc(
      size.length * Int32Array.BYTES_PER_ELEMENT
    ); // 4 bytes per int
    emModule.HEAP32.set(size, this.#sizePtr / Int32Array.BYTES_PER_ELEMENT);

    // 设置一个可移动的指针，让他等于初始地址
    let dynamicPtr = emxArrayPtr;
    // this.#dataPtr  是一个指针，占据8个字节（8*8=64位）。
    emModule.setValue(dynamicPtr, this.#dataPtr, "*");

    // 64 位电脑占用  指针所占用的内存大小为 64 bit 即 8 bytes
    dynamicPtr += Float64Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, this.#sizePtr, "*");

    // 设置数组长度
    dynamicPtr += Float64Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, arrayF64.length, "i32");

    // 设置维度
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, this.#numDimensions, "i32");
    console.log(
      "%c Line:55 🍌 this.#numDimensions",
      "color:#465975",
      this.#numDimensions
    );

    // 设置是否可以被释放内存，0为否
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, 0, "i8");
    this.ptr = emxArrayPtr;
    return this;
  }

  toJSON() {
    if (!this.ptr) return null;
    var dataPtr = emModule.getValue(this.ptr, "*");

    // 从结构体中获取allocatedSize（即数组长度）
    var allocatedSize = emModule.getValue(this.ptr + 16, "i32");

    // 创建一个Float64Array视图来读取data数组的值
    var data = new Float64Array(
      emModule.HEAPF64.buffer,
      dataPtr,
      allocatedSize
    );

    // 返回一个JavaScript数组，包含data的值
    return Array.from(data);
  }

  get() {
    return this.toJSON();
  }

  valueOf() {
    return this.toJSON();
  }

  free() {
    // 首先，释放data数组的内存
    emModule._free(this.#dataPtr);

    // 然后，释放size数组的内存
    emModule._free(this.#sizePtr);

    // 最后，释放结构体本身的内存
    emModule._free(this.ptr);

    // 清理类实例中的指针，以防止悬挂指针（虽然这不是必需的，但是是个好习惯）
    this.ptr = null;
    this.#dataPtr = null;
    this.#sizePtr = null;
  }
}
