import { Badge, Button, Checkbox, InputNumber, message, Select } from "antd";
import { useState } from "react";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { measureAndGetSimpleCoord } from "../utils/commond";
import PointsVector3 from "./PointVector3";

import * as mockData from "../utils/cubeMockData";
import { cubePoints } from "../utils/cubeMockData8";
import { CustomVector3 } from "../class/CustomVector3";
import { CalculateRectangleFromVertex, Planefit } from "../utils/utils";
import CubeTable from "./CubeTable";

const mx = [
  mockData.cubePointsL,
  mockData.cubePointsT,
  mockData.cubePointsR,
  mockData.cubePointsB,
];

export default function () {
  const [data, setData] = useRecoilState(Data);

  const [loading, setLoading] = useState(false);
  const [planeFitLoading, setPlaneFitLoadint] = useState(false);

  const options = [
    { value: 0, label: "左面" },
    { value: 1, label: "顶面" },
    { value: 2, label: "右面" },
    { value: 3, label: "底面" },
    { value: 4, label: "左下面" },
    { value: 5, label: "左上面" },
    { value: 6, label: "右上面" },
    { value: 7, label: "右下面" },
  ].filter((item) => {
    if (data.hasChamfer) return true;
    return item.value < 4;
  });

  const planeFit = async () => {
    let MxPortsArr: CustomVector3[][] = [];
    let MxPorts8Arr: CustomVector3[][] = [];
    for (const item of options) {
      const key = `m${item.value}`;
      if (data.MxPoints[key]?.length > 9) {
        MxPortsArr.push(data.MxPoints[key]);
      } else {
        message.error(`【${item.label}】采集点少于10个，请补充采集点`);
        return;
      }
    }

    if (!(data.firstPoints[0] && data.firstPoints[1])) {
      message.error(`缺少边界点，请补充采集点`);
      return;
    }

    if (options.length === 8) {
      const [l, t, r, b, lb, lt, rt, rb] = MxPortsArr;
      MxPorts8Arr = [lt, t, rt, r, rb, b, lb, l];
      MxPortsArr = [l, t, r, b];
    }
    setPlaneFitLoadint(true);
    setTimeout(() => {
      const res4: any = Planefit(
        MxPortsArr,
        ...data.firstPoints,
        data.distanceThreshold
      );

      const cubeResult4 = CalculateRectangleFromVertex(res4.trianglePoints);

      const newData = {
        ...data,
        ...res4,
        cubeResult: cubeResult4,
      };
      // // 当8个面时，8个面的拟合结果仅仅用于展示3D模型
      if (options.length === 8) {
        const res8: any = Planefit(
          MxPorts8Arr,
          ...data.firstPoints,
          data.distanceThreshold
        );
        newData.trianglePoints = res8.trianglePoints;
      }

      setPlaneFitLoadint(false);

      setData(newData);
    }, 500);
  };

  const [num, setNum] = useState(0);

  const points = data.MxPoints?.[`m${num}`];

  const getPoints = () => {
    setLoading(true);
    measureAndGetSimpleCoord()
      .then((res) => {
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
      .finally(() => {
        setLoading(false);
      });
  };

  const remove = (i) => {
    const m = [...data.MxPoints?.[`m${num}`]];
    m.splice(i, 1);
    setData((d) => {
      return {
        ...d,
        MxPoints: {
          ...data.MxPoints,
          [`m${num}`]: m,
        },
      };
    });
  };

  const setMock = () => {
    setData((d) => {
      return {
        ...d,
        firstPoints: mockData.bounders as [CustomVector3, CustomVector3],
      };
    });

    const MxPoints: any = {};
    for (let i = 0; i < options.length; i++) {
      MxPoints[`m${i}`] = cubePoints[i];
    }

    setData((d) => {
      return {
        ...d,
        MxPoints,
      };
    });
  };

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
        <span className="q-ml-8">
          阈值：
          <InputNumber
            step={0.001}
            min={0.001}
            max={0.1}
            value={data.distanceThreshold}
            style={{ width: 120 }}
            onChange={(distanceThreshold) => {
              setData({ ...data, distanceThreshold });
            }}
          />
        </span>
      </div>
      <div className="q-mt-2 q-flex q-justify-end">
        <Button
          size="small"
          className="q-mt-2  q-ml-4"
          onClick={setMock}
          type="dashed"
        >
          全部模拟
        </Button>
        <Button
          size="small"
          type="dashed"
          className=" q-mt-2  q-ml-4"
          onClick={() => {
            setData((d) => {
              return {
                ...d,
                firstPoints: mockData.bounders as [
                  CustomVector3,
                  CustomVector3
                ],
              };
            });
          }}
        >
          模拟边界
        </Button>
        <Button
          type="dashed"
          size="small"
          className="q-mt-2  q-mx-4"
          onClick={() => {
            setData((d) => {
              return {
                ...d,
                MxPoints: {
                  ...data.MxPoints,
                  [`m${num}`]: cubePoints[num],
                },
              };
            });
          }}
        >
          模拟数据
        </Button>

        <Button loading={loading} type="primary" onClick={getPoints}>
          采集点
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
      <h3 className="q-mt-4 border-top q-pt-2">{options[num].label}采集点：</h3>
      <CubeTable points={points} />
    </div>
  );
}
