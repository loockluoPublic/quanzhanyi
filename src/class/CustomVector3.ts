import { Vector3, Spherical } from "three";

export class CustomVector3 extends Vector3 {
  static count = 0;
  static publicLable;
  public key: number;
  public label?: string;
  public color?: string;
  public enable: boolean;

  difference?: number;
  originDiff?: number;

  static setPublicInfo(newLabel: string, newCount?: number) {
    CustomVector3.count = newCount ?? 0;
    CustomVector3.publicLable = newLabel;
  }

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
          difference?: number;
          originDiff?: number;
        },
    key?: number
  ) {
    super(x, y, z);
    if ((label as any)?.key) {
      this.label = (label as any)?.label ?? CustomVector3.publicLable;
      this.key = (label as any)?.key ?? ++CustomVector3.count;
      this.color = (label as any)?.color;
      this.enable = (label as any)?.enable ?? true;
      this.difference = (label as any)?.difference;
      this.originDiff = (label as any)?.originDiff;
    } else if (typeof label === "string") {
      this.key = key ?? ++CustomVector3.count;
      this.label = (label as string) ?? CustomVector3.publicLable;
      this.enable = true;
    } else {
      this.key = key ?? ++CustomVector3.count;
      this.label = CustomVector3.publicLable;
      this.enable = true;
    }
  }

  cloneCustomVector3() {
    return new CustomVector3(this.x, this.y, this.z, {
      key: this.key,
      label: this.label,
      enable: this.enable,
      color: this.color,
      difference: this.difference,
      originDiff: this.originDiff,
    });
  }

  setEnable(e: boolean) {
    this.enable = e;
    return this;
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

  static fromCArray(arr: [number, number, number]) {
    return new CustomVector3(arr[2], arr[0], arr[1]);
  }

  fromCustomVector3(cv3 = this) {
    const newCV3 = new CustomVector3(cv3.x, cv3.y, cv3.z, {
      key: cv3.key,
      label: cv3.label,
      color: cv3.color,
      enable: cv3.enable,
      difference: cv3.difference,
      originDiff: cv3.originDiff,
    });

    return newCV3;
  }

  fromJSONArray(arr: any[]) {
    return arr.map(({ x, y, z, ...style }) => {
      return new CustomVector3(x, y, z, style);
    });
  }

  calcRotation() {
    return [
      Math.atan2(this.y, this.z),
      -Math.atan2(this.z, this.x),
      Math.atan2(this.x, this.y),
    ];
  }

  toAngles() {
    return [
      (this.toSpherical().theta * 180) / Math.PI,
      (this.toSpherical().phi * 180) / Math.PI,
    ];
  }
}
