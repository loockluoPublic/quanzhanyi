import { Badge, Button, Checkbox, InputNumber, Select } from "antd";
import { useEffect, useState } from "react";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { measureAndGetSimpleCoord } from "../utils/commond";
import PointsVector3 from "./PointVector3";

import * as mockData from "../utils/cubeMockData";
import { CustomVector3 } from "../class/CustomVector3";
import { CalculateRectangleFromVertex, Planefit4 } from "../utils/utils";

const mx = [
  mockData.cubePointsL,
  mockData.cubePointsT,
  mockData.cubePointsR,
  mockData.cubePointsB,
];

export default function () {
  const [data, setData] = useRecoilState(Data);

  const options = [
    { value: 0, label: "左面" },
    { value: 1, label: "顶面" },
    { value: 2, label: "右面" },
    { value: 3, label: "底面" },
    { value: 4, label: "左下" },
    { value: 5, label: "左上" },
    { value: 6, label: "右上" },
    { value: 7, label: "右下" },
  ].map((item) => {
    return {
      ...item,
      label: (
        <Badge dot={!(data.MxPoints?.[`m${item.value}`]?.length > 0)}>
          <span className="q-mr-1">{item.label}</span>
        </Badge>
      ),
    };
  });

  const planeFit = () => {
    const paramArr: [
      CustomVector3[],
      CustomVector3[],
      CustomVector3[],
      CustomVector3[],
      CustomVector3,
      CustomVector3,
      number
    ] = [
      ...Object.values(data.MxPoints),
      ...data.firstPoints,
      data.distanceThreshold,
    ] as any;
    console.log("%c Line:53 🍩 paramArr", "color:#465975", paramArr);
    const res = Planefit4(...paramArr);

    const cubeResult = CalculateRectangleFromVertex(res.trianglePoints);

    setData({
      ...data,
      ...res,
      cubeResult,
    });
  };

  const [num, setNum] = useState(0);

  const [loading, setLoading] = useState(false);

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
    for (let i = 0; i < 4; i++) {
      MxPoints[`m${i}`] = mx[i];
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
            options={options.filter((item) => {
              if (data.hasChamfer) return true;
              return item.value < 4;
            })}
          />
        </span>
        <span className="q-ml-8">
          误差：
          <InputNumber
            step={0.01}
            value={data.distanceThreshold}
            style={{ width: 120 }}
            onChange={(distanceThreshold) => {
              setData({ ...data, distanceThreshold });
            }}
          />
        </span>
      </div>
      <div className="q-mt-2">
        <Button
          loading={loading}
          type="primary"
          // className="q-float-right"
          onClick={getPoints}
        >
          采集点
        </Button>
      </div>
      <div>
        <Button className=" q-float-right q-mt-2  q-ml-4" onClick={planeFit}>
          方涵拟合
        </Button>
        <Button
          size="small"
          className=" q-float-right q-mt-2  q-ml-4"
          onClick={setMock}
        >
          全部模拟
        </Button>
        <Button
          size="small"
          className=" q-float-right q-mt-2  q-ml-4"
          onClick={() => {
            setData((d) => {
              return {
                ...d,
                MxPoints: {
                  ...data.MxPoints,
                  [`m${num}`]: mx[num],
                },
              };
            });
          }}
        >
          模拟数据
        </Button>
        <Button
          size="small"
          className=" q-float-right q-mt-2"
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
      </div>
      <div className="q-flex q-flex-wrap q-justify-between q-w-[530px] q-mt-4">
        {points?.map?.((item, i) => {
          return (
            <PointsVector3
              key={item.key}
              value={item}
              showGetPoints={false}
              remove={() => remove(i)}
            />
          );
        })}
      </div>
    </div>
  );
}
