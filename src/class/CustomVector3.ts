import { Vector3, Spherical } from "three";

export class CustomVector3 extends Vector3 {
  static count = 0;
  public key: number;
  public label?: string;
  public color?: string;
  public enable: boolean;

  constructor(
    x?: number,
    y?: number,
    z?: number,
    label?:
      | string
      | {
          label?: string;
          key?: number;
          color?: string;
          enable?: boolean;
        },
    key?: number
  ) {
    super(x, y, z);
    if ((label as any)?.label) {
      this.label = (label as any)?.label;
      this.key = (label as any)?.key ?? ++CustomVector3.count;
      this.color = (label as any)?.color;
      this.enable = (label as any)?.enable ?? true;
    } else if (typeof label === "string") {
      this.key = key ?? ++CustomVector3.count;
      this.label = label as string;
      this.enable = true;
    } else {
      this.key = key ?? ++CustomVector3.count;
      this.enable = true;
    }
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
    const newCV3 = new CustomVector3(cv3.x, cv3.y, cv3.z, {
      key: cv3.key,
      label: cv3.label,
      color: cv3.color,
      enable: cv3.enable,
    });

    return newCV3;
  }

  fromJSONArray(arr: any[]) {
    return arr.map(({ x, y, z, ...style }) => {
      return new CustomVector3(x, y, z, style);
    });
  }
}
