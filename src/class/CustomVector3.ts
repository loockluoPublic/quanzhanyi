import { Vector3, Spherical } from "three";

export class CustomVector3 extends Vector3 {
  constructor(x?: number, y?: number, z?: number) {
    super(x, y, z);
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
}
