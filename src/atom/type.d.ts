import { CustomVector3 } from "../class/CustomVector3";

interface BaseInfo {
  /**
   * 声道分布
   */
  sdfb: number;

  /**
   * 声道面
   */
  sdm: ("A" | "B")[];

  /**
   * 声道角
   */
  sdj: number;
}

interface AgainTable {
  /**
   * 声道角
   */
  sdj: number;
  /**
   * 声道长
   */
  sdc: number;

  /**
   * 所在声道面
   */
  sdm: "A" | "B";

  /**
   * LT 偏移
   */
  ltOffset: number;

  /**
   * 声道相对高度
   */
  sdH: number;

  /**
   * 权系数
   */
  qxs: number;
}

interface ICycleBase {
  /**
   * 采样层数
   */
  layNum: number;

  /**
   * 每层采样点数
   */
  numPerLay: number;

  /**
   * 管道轴线方向
   */
  direct: number[];

  /**
   * 圆柱顶/底面点
   */
  firstPoints: [CustomVector3, CustomVector3];

  /**
   * AB面交点
   */
  centerPoint: CustomVector3;
}

interface ICycle {
  /**
   * 算法计算待测量点
   */
  waitingPoints: CustomVector3[];

  /**
   * 已测量点
   */
  mPoints: CustomVector3[];

  /**
   * 圆柱拟合结果
   */
  calulateRes: {
    /**
     * 圆柱几何中心点
     */
    center: CustomVector3;
    /**
     * 圆柱几何中心点
     */
    Err_every: number[];
    /**
     * 圆柱几何中心点
     */
    mTaon: CustomVector3;
    /**
     * 圆柱半径
     */
    R: number;
    /**
     * 圆柱底面中心点
     */
    Bottom_round_center: CustomVector3[];
  };

  /**
   * 标准差
   */
  standardDeviation: number;

  /**
   * 初始标准差
   */
  originStandardDeviation: number;

  /**
   * 计算参数Table
   */
  resultTable: {
    i: number;
    ang: number;
    a: number;
    tOff: number;
    rOff: number;
    sdm: "A" | "B";
    points?: CustomVector3[];
  }[];

  cubeTable: {
    i: number;
    ang: number;
    a: number;
    tOff: number;
    h: number;
    sdm: "A" | "B";
    points?: CustomVector3[];
  }[];
  /**
   * 安装点位置
   */
  AB: {
    pointA: CustomVector3;
    pointB: CustomVector3;
  }[];

  /**
   * 复测表格
   */
  cylinderAgainTable: {
    p1: CustomVector3;
    p2: CustomVector3;
  }[];
}

interface ICube {
  /**
   * 是否包含倒角
   */
  hasChamfer: boolean;

  /**
   * 矩形面采集点
   */
  MxPoints: Record<string, CustomVector3[]>;

  /**
   * 三角面顶点
   */
  trianglePoints?: CustomVector3[];

  /**
   * 平面拟合误差
   */
  distanceThreshold: number;

  /**
   * 是否使用塔尺
   */
  tc: boolean;

  /**
   * 塔尺高度
   */
  tcH: number;

  /**
   * 矩形拟合结果
   */
  cubeResult: {
    pIn: CustomVector3;
    pOut: CustomVector3;
    UPP: CustomVector3;
    b: number;
    h: number;
    w: number;
    Tao: CustomVector3;
  };
}
