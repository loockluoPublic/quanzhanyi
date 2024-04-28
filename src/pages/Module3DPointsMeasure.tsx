import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import {
  CalculatAAndBPoints,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
} from "../utils/utils";
import { useEffect, useRef } from "react";
import Module3D from "../components/Module3D";

export function Module3DPointsMeasure() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:12 🍷 data", "color:#b03734", data);

  const flag = useRef(true);
  useEffect(() => {
    if (flag.current) {
      flag.current = false;

      const res = CalculateAccurateCylindersFromMultipleMeasurementPoints(
        data.mPoints,
        data.firstPoints[0],
        data.firstPoints[1]
      );
      console.log("%c Line:25 🥤 res", "color:#f5ce50", res);

      const AB = CalculatAAndBPoints(
        res.mTaon,
        res.center,
        res.R,
        res.Bottom_round_center[0],
        res.Bottom_round_center[1],
        res.Bottom_round_center[1],
        data.sdfb,
        0.6
      );
      setData({
        ...data,
        calulateRes: res,
        AB,
      });
    }
  }, []);

  // return (
  //   <div>
  //     <div>center： {JSON.stringify(data?.calulateRes?.center)}</div>
  //     <div>圆心： {JSON.stringify(data?.calulateRes?.Mradial)}</div>
  //     <div>{JSON.stringify(data?.calulateRes)}</div>
  //   </div>
  // );
  return (
    <div>
      <div className="q-w-[800px] q-inline-block">
        <div className="q-overflow-y-auto">
          <Module3D
            points={data.mPoints ?? []}
            height="500px"
            direct={data?.direct}
            {...data}
          />
        </div>
      </div>
      <div className="q-w-[400px]   q-inline-block ">
        {JSON.stringify(data?.calulateRes)}
      </div>
    </div>
  );
}
