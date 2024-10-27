import { Badge, Button, Checkbox, InputNumber, message, Select } from "antd";
import { useEffect, useState } from "react";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { measureAndGetSimpleCoord } from "../utils/commond";
import { CustomVector3 } from "../class/CustomVector3";
import { CalculateRectangleFromVertex, Planefit } from "../utils/utils";
import CubeTable from "./CubeTable";
import { generateUniformPointsInPolygonWithSort } from "../utils/genCubePoints";
import useMeasure from "../utils/useMeasure";

export default function () {
  const [data, setData] = useRecoilState(Data);

  const [loading, setLoading] = useState(false);
  const [planeFitLoading, setPlaneFitLoadint] = useState(false);

  const autoMeasure = useMeasure();

  const options = [
    { value: 0, label: "左面", pK: "L" },
    { value: 1, label: "顶面", pK: "T" },
    { value: 2, label: "右面", pK: "R" },
    { value: 3, label: "底面", pK: "B" },
    { value: 4, label: "左下面", pK: "LB" },
    { value: 5, label: "左上面", pK: "LT" },
    { value: 6, label: "右上面", pK: "RT" },
    { value: 7, label: "右下面", pK: "RB" },
  ].filter((item) => {
    if (data.hasChamfer) return true;
    return item.value < 4;
  });

  const planeFit = async () => {
    const MxPortsArr: CustomVector3[][] = [];
    let MxPoint8Arr: { i: number; v: CustomVector3[] }[] = [];

    for (const item of options) {
      const key = `m${item.value}`;
      if (item.value < 4) {
        if (data.MxPoints[key]?.length > 4) {
          MxPortsArr.push(data.MxPoints[key]);
        } else {
          message.error(`【${item.label}】采集点少于5个，请补充采集点`);
          return;
        }
      } else {
        MxPortsArr.push(data.MxPoints[key] ?? []);
      }
    }

    if (!(data.firstPoints[0] && data.firstPoints[1])) {
      message.error(`缺少边界点，请补充采集点`);
      return;
    }

    if (data.hasChamfer) {
      const [l, t, r, b, lb, lt, rt, rb] = MxPortsArr;
      MxPoint8Arr = [
        { i: 0, v: l },
        { i: 5, v: lt },
        { i: 1, v: t },
        { i: 6, v: rt },
        { i: 2, v: r },
        { i: 7, v: rb },
        { i: 3, v: b },
        { i: 4, v: lb },
      ];
    }
    setPlaneFitLoadint(true);

    setTimeout(() => {
      const res: any = Planefit(
        data.hasChamfer ? MxPoint8Arr.map((item) => item.v) : MxPortsArr,
        ...data.firstPoints,
        data.distanceThreshold
      );

      let MxPoints = {};
      if (data.hasChamfer) {
        MxPoints = MxPoint8Arr.map((item, i) => {
          return {
            ...item,
            v: res.MxPoints?.[i],
          };
        })
          .sort((a, b) => a.i - b.i)
          .reduce((acc, cur, i) => {
            return {
              ...acc,
              [`m${i}`]: cur.v,
            };
          }, {});

        // 用户复测入参
        const res8temp: any = Planefit(
          MxPortsArr.slice(0, 4),
          ...data.firstPoints,
          data.distanceThreshold
        );

        const cubeResult8temp = CalculateRectangleFromVertex(
          res8temp.trianglePoints
        );

        const newData = {
          ...data,
          ...res,
          planeParaOut: res8temp.planeParaOut,
          MxPoints,
          cubeResult: cubeResult8temp,
        };

        setPlaneFitLoadint(false);
        setData(newData);
      } else {
        const cubeResult = CalculateRectangleFromVertex(res.trianglePoints);

        MxPoints = (res.MxPoints as any[]).reduce((acc, cur, i) => {
          return {
            ...acc,
            [`m${i}`]: cur,
          };
        }, {});
        const newData = {
          ...data,
          ...res,
          MxPoints,
          cubeResult: cubeResult,
        };

        setPlaneFitLoadint(false);
        setData(newData);
      }
    }, 500);
  };

  const [num, setNum] = useState(0);

  const points = data.MxPoints?.[`m${num}`];

  const getMaxKey = () => {
    return Math.max(0, ...(points?.map((p) => p.key) ?? []));
  };

  const getPoints = () => {
    setLoading(true);

    const k = getMaxKey();
    CustomVector3.setPublicInfo(options[num].pK, k);

    measureAndGetSimpleCoord()
      .then((res) => {
        if (data.tc && num === 3 && data.tcH) {
          res.y = res.y - data.tcH;
        }
        setData((d) => {
          return {
            ...d,
            MxPoints: {
              ...data.MxPoints,
              [`m${num}`]: [res, ...(data.MxPoints?.[`m${num}`] ?? [])],
            },
          };
        });
      })
      .catch((err) => {
        console.error("%c Line:125 🍆 err", "color:#3f7cff", err);
        message.error("获取点坐标失败，请更换测量点后重试");
      })
      .finally(() => {
        setLoading(false);
      });
  };

  useEffect(() => {
    CustomVector3.setPublicInfo("P", 0);
  }, []);

  const autoMeasureCube = () => {
    const bounder = data.MxPoints[`m${num}`];
    if (bounder.length > 3) {
      const res = generateUniformPointsInPolygonWithSort(bounder, 20);

      autoMeasure.measure(res);
    } else {
      message.warning("请顺时针或者逆时针采集矩形4个顶点，后开始自动采集");
    }
  };

  const width = data?.cubeResult?.b?.toFixed(4);
  const hight = data?.cubeResult?.h?.toFixed(4);

  return (
    <div>
      <div className="q-mt-2">
        <Checkbox
          checked={data.hasChamfer}
          onChange={({ target }) => {
            setData({
              ...data,
              hasChamfer: target.checked,
            });
          }}
        >
          是否包含导角
        </Checkbox>
        <span className="q-ml-8">
          采集面：
          <Select
            defaultValue={0}
            style={{ width: 120 }}
            onChange={(v) => setNum(v)}
            options={options.map((item) => {
              return {
                ...item,
                label: (
                  <Badge dot={!(data.MxPoints?.[`m${item.value}`]?.length > 0)}>
                    <span className="q-mr-1">{item.label}</span>
                  </Badge>
                ),
              };
            })}
          />
        </span>
        {num === 3 && (
          <>
            <Checkbox
              className="q-ml-8"
              checked={data.tc}
              onChange={({ target }) => {
                setData({
                  ...data,
                  tc: target.checked,
                });
              }}
            >
              使用塔尺
            </Checkbox>

            {data.tc && (
              <span className="q-ml-4">
                偏移高度：
                <InputNumber
                  step={0.2}
                  min={0}
                  max={1}
                  value={data.tcH}
                  style={{ width: 120 }}
                  addonAfter="米"
                  onChange={(tcH) => {
                    setData({ ...data, tcH });
                  }}
                />
              </span>
            )}
          </>
        )}
      </div>
      <div className="q-mt-2">
        <span className="q-flex q-items-center">
          拟合阈值：
          <InputNumber
            step={0.001}
            min={0.001}
            max={0.1}
            value={data.distanceThreshold}
            style={{ width: 120 }}
            onChange={(distanceThreshold) => {
              setData({ ...data, distanceThreshold });
            }}
            addonAfter="米"
          />
        </span>
      </div>

      <div className="q-mt-2 q-flex q-justify-between">
        <div className="q-mt-2">
          <span>
            方涵宽度：
            {width ?? "--"} 米
          </span>
          <span className="q-ml-8">方涵高度：{hight ?? "--"} 米</span>
        </div>
        <div>
          <Button loading={loading} type="primary" onClick={getPoints}>
            手动采点
          </Button>
          <Button
            className="q-ml-4"
            type="primary"
            loading={autoMeasure.loading}
            onClick={planeFit}
          >
            自动采点
          </Button>
          <Button
            className="q-ml-4"
            type="primary"
            loading={planeFitLoading}
            onClick={planeFit}
          >
            方涵拟合
          </Button>
        </div>
      </div>
      <h3 className="q-mt-4 border-top q-pt-2">{options[num].label}采集点：</h3>
      <CubeTable points={points} num={num} />
    </div>
  );
}
