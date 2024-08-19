import { useRecoilState } from "recoil";
import { Data, GlobalData } from "../atom/globalState";
import {
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  calculateStandardDeviation,
} from "../utils/utils";
import { useState } from "react";
import Module3D from "../components/Module3D";
import { Button, InputNumber } from "antd";
import ResultsTable2 from "../components/ResultsTable2";

export function CalculateAccurateCylinders() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:14 🥛 data", "color:#33a5ff", data);

  const [loading, setLoading] = useState(false);

  const [customStandardDeviation, setStandardDeviation] = useState(3);

  const calculateCylinders = (curData: GlobalData, isFirst?: boolean) => {
    const enablePoints = curData.mPoints.filter((item) => item.enable);
    return new Promise((reslove) => {
      setTimeout(() => {
        CalculateAccurateCylindersFromMultipleMeasurementPoints(
          enablePoints,
          curData.firstPoints[0],
          curData.firstPoints[1]
        ).then((calulateRes) => {
          const differences = calulateRes.Err_every;

          enablePoints.forEach((item, i) => {
            item.difference = differences[i];
          });

          if (isFirst) {
            enablePoints.forEach((item, i) => {
              item.originDiff = differences[i];
            });
          }

          const standardDeviation = calculateStandardDeviation(enablePoints);

          const nd: any = {
            ...curData,
            mPoints: curData.mPoints,
            calulateRes,
            [isFirst ? "originStandardDeviation" : "standardDeviation"]:
              standardDeviation,
            standardDeviation,
          };

          setTimeout(() => {
            setData(nd);
            reslove(nd);
          }, 200);
        });
      }, 200);
    });
  };

  const reRun = (curData: GlobalData) => {
    const newMP = curData.mPoints.map((item) => {
      return item
        .fromCustomVector3()
        .setEnable(Math.abs(item.difference) < curData.standardDeviation);
    });

    const nD = {
      ...curData,
      mPoints: newMP,
    };
    setLoading(true);
    calculateCylinders(nD).then(() => {
      setLoading(false);
    });
  };

  const run = () => {
    setLoading(true);

    calculateCylinders(
      {
        ...data,
        mPoints: data.mPoints.map((d) => d.fromCustomVector3()),
      },
      true
    )
      .then((newData: any) => {
        reRun(newData);
        setLoading(false);
      })
      .catch((err) => {
        console.error("%c Line:80 🍺 err", "color:#93c0a4", err);
      });
  };

  return (
    <Module3D
      loading={loading}
      mPoints={data.mPoints ?? []}
      direct={data?.direct}
      {...data}
      component={
        <>
          <div className="options">
            <Button loading={loading} onClick={run} type="primary">
              圆柱面拟合
            </Button>
          </div>
          <div className="q-my-4">
            <div className="q-grid q-grid-cols-2">
              <div>
                初始标准差δ：
                <span className=" q-font-bold">
                  {data?.originStandardDeviation?.toFixed(6) ?? "--"} 米
                </span>
              </div>
              <div>
                标准差：
                <span className=" q-font-bold">
                  {data?.standardDeviation?.toFixed(6) ?? "--"} 米
                </span>
              </div>
              <div>
                半径：
                <span className=" q-font-bold">
                  {data?.calulateRes?.R?.toFixed(6) ?? "--"} 米
                </span>
              </div>
              <span>
                有效点：
                <span className=" q-font-bold">
                  {data.mPoints.filter((item) => item.enable).length}/
                  {data.mPoints.length}
                </span>
              </span>
            </div>

            <div
              className="q-flex q-items-center q-my-2"
              style={{
                visibility:
                  typeof data.standardDeviation !== "number"
                    ? "hidden"
                    : "initial",
              }}
            >
              阈值：
              <InputNumber
                step={0.01}
                style={{ width: "200px" }}
                value={customStandardDeviation}
                onChange={(standardDeviation) => {
                  setStandardDeviation(standardDeviation);
                }}
                addonAfter="δ"
              />
              <Button
                className="q-float-right q-ml-4"
                loading={loading}
                onClick={() => {
                  reRun({
                    ...data,
                    standardDeviation:
                      customStandardDeviation * data.standardDeviation,
                  });
                }}
                type="primary"
              >
                再次拟合
              </Button>
            </div>
            <ResultsTable2 />
          </div>
        </>
      }
    ></Module3D>
  );
}
