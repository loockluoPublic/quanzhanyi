import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import {
  CalculatAAndBPoints,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  calculateStandardDeviation,
  filterIndex,
} from "../utils/utils";
import { useEffect, useRef, useState } from "react";
import Module3D from "../components/Module3D";
import { Button, InputNumber } from "antd";
import BaseInfo from "../components/BaseInfo";
import { CustomVector3 } from "../class/CustomVector3";

export function CalculateAccurateCylinders() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:14 🍌 data", "color:#3f7cff", data);
  const [loading, setLoading] = useState(false);

  const CalculateCylinders = () => {
    console.log("%c Line:21 🍓 CalculateCylinders", "color:#b03734");
    return new Promise((reslove) => {
      setTimeout(() => {
        console.log("%c Line:24 🍓 setTimeout", "color:#42b983");
        CalculateAccurateCylindersFromMultipleMeasurementPoints(
          data.mPoints,
          data.firstPoints[0],
          data.firstPoints[1]
        ).then((calulateRes) => {
          console.log(
            "%c Line:30 🍓 calulateRes",
            "color:#ea7e5c",
            calulateRes
          );

          setData({
            ...data,
            calulateRes,
          });
          reslove("");
        });
      }, 200);
    });
  };

  const reRun = () => {
    const disableIndex = filterIndex(
      data?.calulateRes?.Err_every ?? [],
      data.standardDeviation
    );
    data.mPoints.forEach((item, i) => {
      item.enable = !disableIndex.includes(i);
    });
    setData({
      ...data,
      mPoints: data.mPoints,
    });
    CalculateCylinders();
  };

  const run = () => {
    setLoading(true);
    CalculateCylinders()
      .then(() => {
        console.log("%c Line:56 🍓 CalculateCylinders.then", "color:#465975");
        const standardDeviation = calculateStandardDeviation(
          data.calulateRes.Err_every
        );

        setData({
          ...data,
          standardDeviation,
        });
        // console.log(
        //   "%c Line:72 🍓 standardDeviation",
        //   "color:#e41a6a",
        //   standardDeviation
        // );
        setLoading(false);
      })
      .catch((err) => {
        console.log("%c Line:80 🍺 err", "color:#93c0a4", err);
      });
  };

  return (
    <Module3D
      loading={loading}
      points={data.mPoints ?? []}
      height="500px"
      direct={data?.direct}
      {...data}
      component={
        <>
          <Button loading={loading} onClick={run}>
            运行
          </Button>
          <div>
            标准差：
            <InputNumber
              style={{ width: "200px" }}
              value={data.standardDeviation}
              onChange={(standardDeviation) => {
                setData({
                  ...data,
                  standardDeviation,
                });
              }}
            />
          </div>
        </>
      }
    ></Module3D>
  );
}
