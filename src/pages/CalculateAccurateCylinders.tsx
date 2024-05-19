import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import {
  CalculatAAndBPoints,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
} from "../utils/utils";
import { useEffect, useRef, useState } from "react";
import Module3D from "../components/Module3D";
import { Button } from "antd";
import BaseInfo from "../components/BaseInfo";

export function CalculateAccurateCylinders() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:14 🍌 data", "color:#3f7cff", data);
  const [loading, setLoading] = useState(false);

  const run = () => {
    setLoading(true);
    setTimeout(() => {
      CalculateAccurateCylindersFromMultipleMeasurementPoints(
        data.mPoints,
        data.firstPoints[0],
        data.firstPoints[1]
      )
        .then((res) => {
          setData({
            ...data,
            calulateRes: res,
          });
          return CalculatAAndBPoints(
            res.mTaon,
            res.center,
            res.R,
            res.Bottom_round_center[0],
            res.Bottom_round_center[1],
            data.centerPoint[0],
            data.sdfb,
            data.sdj,
            data.tOff,
            data.rOff
          );
        })
        .then((AB) => {
          setLoading(false);
          setData({
            ...data,
            AB,
          });
        });
    }, 200);
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
            <BaseInfo />
          </div>
        </>
      }
    ></Module3D>
  );
}
