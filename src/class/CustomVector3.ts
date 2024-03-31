import { Vector3, Spherical } from "three";

export class CustomVector3 extends Vector3 {
  static count = 0;
  public key: number;
  public label?: string;
  enable: boolean;

  constructor(
    x?: number,
    y?: number,
    z?: number,
    label?: string,
    key?: number
  ) {
    super(x, y, z);
    CustomVector3.count++;
    this.key = key ?? CustomVector3.count;
    this.label = label;
    this.enable = true;
  }

  setEnable(e: boolean) {
    this.enable = e;
  }

  // 添加toSpherical方法
  toSpherical() {
    const spherical = new Spherical();

    spherical.setFromVector3(this);

    return spherical;
  }

  // 添加toSpherical方法
  toVector3() {
    return new Vector3(this.x, this.y, this.z);
  }

  toCArray() {
    return [this.y, this.z, this.x];
  }

  fromCArray(arr: [number, number, number]) {
    this.x = arr[2];
    this.y = arr[0];
    this.z = arr[1];
    return this;
  }

  fromCustomVector3(cv3 = this) {
    const newCV3 = new CustomVector3(cv3.x, cv3.y, cv3.z, cv3.label, cv3.key);
    newCV3.enable = cv3.enable;
    return newCV3;
  }
}
