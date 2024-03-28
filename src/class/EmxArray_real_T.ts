import { CustomVector3 } from "./CustomVector3";

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
  /**
   * @description 结构体的指针
   * @memberof EmxArray_real_T
   */
  ptr: number;
  // 多维数组平铺后的一维数组
  #arrayFlat: number[] = [];
  /**
   * @description 分配的数组指针
   * @memberof EmxArray_real_T
   */
  arrayPtr: number;

  // n*m维度的 矩阵
  size: [number, number];
  sizePtr: number;

  /**
   * 创建对象
   * @param m 一维数组，二维数组，二维数组的宽度
   * @param n 一维数组的长度
   * @memberof EmxArray_real_T
   */
  constructor(
    m: number[][] | number[] | number | CustomVector3 | CustomVector3[],
    n: number = 1
  ) {
    if (typeof m === "number") {
      this.#arrayFlat = new Array(m * n).fill(0);
      this.#setSize(m, n);
      return this.#init();
    } else if (m instanceof CustomVector3) {
      this.#arrayFlat = m.toCArray();
      this.#setSize(3, 1);
      return this.#init();
    } else if (Array.isArray(m)) {
      if (Array.isArray(m[0])) {
        // m*n的矩阵， m >= 2
        this.#arrayFlat = [];
        for (const row of m) {
          //@ts-ignore
          this.#arrayFlat.push(...row);
        }
        this.#setSize(m[0].length, m.length);
      } else if (m[0] instanceof CustomVector3) {
        this.#arrayFlat = [];
        for (const row of m) {
          //@ts-ignore
          this.#arrayFlat.push(...(row as CustomVector3).toCArray());
        }
        this.#setSize(3, m.length);
      } else {
        // 1 * n 的矩阵
        this.#arrayFlat = m as unknown as number[];
        this.#setSize(1, m.length);
      }
      return this.#init();
    }
    throw new Error(`EmxArray_real_T 参数错误：, ${m}, ${n}`);
  }

  #init() {
    //  为一个结构体分配线性内存空间，一个结构体为大小 8(指针)+8(指针)+4（int + 4(bool) =

    var emxArrayPtr = emModule._malloc(24);

    // 设置线性内存的数据
    const arrayF64 = new Float64Array(this.#arrayFlat);

    this.arrayPtr = emModule._malloc(
      arrayF64.length * Float64Array.BYTES_PER_ELEMENT
    );
    // emModule.setValue(this.arrayPtr, arrayF64, "double");
    emModule.HEAPF64.set(
      arrayF64,
      this.arrayPtr / Float64Array.BYTES_PER_ELEMENT
    );

    // 设置结构体 size 的数据
    const sizeI32 = new Int32Array(this.size);
    this.sizePtr = emModule._malloc(
      sizeI32.length * Int32Array.BYTES_PER_ELEMENT
    );

    emModule.HEAP32.set(sizeI32, this.sizePtr / Int32Array.BYTES_PER_ELEMENT);

    // 设置一个可移动的指针，让他等于初始地址
    let dynamicPtr = emxArrayPtr;
    // this.#dataPtr  是一个指针，占据8个字节（8*8=64位）。
    // double *data;
    emModule.setValue(dynamicPtr, this.arrayPtr, "*");

    // 64 位电脑占用  指针所占用的内存大小为 64 bit 即 8 bytes
    //  int *size;
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, this.sizePtr, "*");

    // 设置数组长度
    // int allocatedSize;
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, arrayF64.length, "i32");

    // 设置维度
    // int numDimensions;
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, 2, "i32");

    // 设置是否可以被释放内存，0为否
    // boolean_T canFreeData;
    dynamicPtr += Int32Array.BYTES_PER_ELEMENT;
    emModule.setValue(dynamicPtr, 0, "i8");

    // 读取size指针
    const sizePtr = emModule.getValue(emxArrayPtr + 8, "i32");

    const numDimensions = 2;
    const sizeArray = new Int32Array(numDimensions);
    for (let i = 0; i < numDimensions; i++) {
      sizeArray[i] = emModule.HEAP32[sizePtr / 4 + i];
    }

    this.ptr = emxArrayPtr;

    return this;
  }

  #setSize(m: number, n: number) {
    this.size = [m, n];
  }

  getSize() {
    // 从结构体中获取allocatedSize（即数组长度）
    var size = emModule.getValue(this.ptr + 8, "i32");
    var allocatedSize = emModule.getValue(this.ptr + 16, "i32");

    const a = Array.from(
      new Int32Array(emModule.HEAP32.buffer, this.sizePtr, 2)
    );
    console.log("%c Line:129 🥑 size", "color:#42b983", size, allocatedSize, a);
  }
  toJSON() {
    if (!this.ptr) return null;
    var dataPtr = emModule.getValue(this.ptr, "*");

    // 从结构体中获取allocatedSize（即数组长度）
    var allocatedSize = emModule.getValue(this.ptr + 8, "i32");

    // 创建一个Float64Array视图来读取data数组的值
    var data = Array.from(
      new Float64Array(emModule.HEAPF64.buffer, dataPtr, allocatedSize)
    );

    const [m, n] = this.size;

    if (m > 1 && n > 1) {
      const res = [];
      for (let index = 0; index < data.length; index += m) {
        const row = [];
        for (let rowIndex = 0; rowIndex < m; rowIndex++) {
          row.push(data[index + rowIndex]);
        }
        res.push(row);
      }
      return res;
    } else if (m === 1) {
      return data;
    } else if (n === 1) {
      return [data];
    }
  }

  valueOf() {
    return this.toJSON();
  }
  /**
   * 转换为 Threejs的 Vector3
   * @returns Vector3[]
   */
  toVector3() {
    if (this.size[0] === 3) {
      return this.toJSON().map((row) => {
        return new CustomVector3().fromCArray(row);
      });
    }
    return [];
  }

  getDebugInfo() {
    return {
      size: this.size,
      sizePtr: this.sizePtr,
      arrayFlat: this.#arrayFlat,
    };
  }

  free() {
    // 首先，释放data数组的内存
    emModule._free(this.arrayPtr);

    // 然后，释放size数组的内存
    emModule._free(this.sizePtr);

    // 最后，释放结构体本身的内存
    emModule._free(this.ptr);

    // 清理类实例中的指针，以防止悬挂指针（虽然这不是必需的，但是是个好习惯）
    this.ptr = null;
    this.arrayPtr = null;
    this.sizePtr = null;
  }
}

/**
 * 从二维数组中提取某列
 * @param array
 * @param index
 * @returns
 */
export const pickCol = (array: number[][], index: number) => {
  const res = [];
  for (const row of array) {
    res.push(row[index]);
  }
  return res;
};
