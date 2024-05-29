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

export function CalculateResultPoints() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:14 🍌 data", "color:#3f7cff", data);
  const [loading, setLoading] = useState(false);

  const run = () => {
    setLoading(true);
    setTimeout(async () => {
      const calulateRes =
        await CalculateAccurateCylindersFromMultipleMeasurementPoints(
          data.mPoints,
          data.firstPoints[0],
          data.firstPoints[1]
        );

      CalculatAAndBPoints(
        calulateRes.mTaon,
        calulateRes.center,
        calulateRes.R,
        calulateRes.Bottom_round_center[0],
        calulateRes.Bottom_round_center[1],
        data.centerPoint[0],
        data.sdfb,
        data.sdj,
        data.tOff,
        data.rOff
      ).then((AB) => {
        setLoading(false);
        setData({
          ...data,
          AB,
          calulateRes,
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
