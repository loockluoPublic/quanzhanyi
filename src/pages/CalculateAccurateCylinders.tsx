import { useRecoilState } from "recoil";
import { Data, GlobalData } from "../atom/globalState";
import {
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  calculateStandardDeviation,
} from "../utils/utils";
import { useState } from "react";
import Module3D from "../components/Module3D";
import { Button, InputNumber } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import { PointsTable } from "../components/Module3D/PointsTable";

export function CalculateAccurateCylinders() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:14 🍌 data", "color:#3f7cff", data);
  const [loading, setLoading] = useState(false);

  const [customStandardDeviation, setStandardDeviation] = useState(0);

  const calculateCylinders = (curData: GlobalData) => {
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

          const standardDeviation = calculateStandardDeviation(enablePoints);

          const nd = {
            ...curData,
            mPoints: curData.mPoints,
            standardDeviation,
            calulateRes,
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
    // setData(nD);
    calculateCylinders(nD).then(() => {
      setLoading(false);
    });
  };

  const run = () => {
    setLoading(true);
    calculateCylinders({
      ...data,
      mPoints: data.mPoints.map((d) => d.fromCustomVector3()),
    })
      .then((newData: any) => {
        // const standardDeviation = calculateStandardDeviation(newData.mPoints);

        // const _newData = {
        //   ...newData,
        //   // mPoints: newPoints,
        //   standardDeviation,
        // };

        // setData(_newData);

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
      height="500px"
      direct={data?.direct}
      {...data}
      component={
        <>
          <Button loading={loading} onClick={run}>
            计算标准差
          </Button>
          <div>
            <div>标准差：{data.standardDeviation}</div>
            <div>半径：{data.calulateRes?.R}</div>
            <PointsTable mPoints={data.mPoints} />

            <div className=" q-mt-6">人工干预</div>
            <div>
              阈值：
              <InputNumber
                style={{ width: "200px" }}
                value={customStandardDeviation}
                onChange={(standardDeviation) => {
                  setStandardDeviation(standardDeviation);
                }}
                addonAfter={
                  <div
                    className=" q-cursor-pointer"
                    onClick={() => {
                      reRun({
                        ...data,
                        standardDeviation: customStandardDeviation,
                      });
                    }}
                  >
                    计算
                  </div>
                }
              />
            </div>
          </div>
        </>
      }
    ></Module3D>
  );
}
