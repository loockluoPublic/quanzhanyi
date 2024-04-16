import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { CalculateAccurateCylindersFromMultipleMeasurementPoints } from "../utils/utils";
import { useEffect, useRef } from "react";

export function Module3DPointsMeasure() {
  const [data, setData] = useRecoilState(Data);

  const flag = useRef(true);
  useEffect(() => {
    if (flag.current) {
      flag.current = false;
      console.log(
        "%c Line:17 🥚 CalculateAccurateCylindersFromMultipleMeasurementPoints",
        "color:#ed9ec7",
        data.mPoints,
        data.firstPoints[0],
        data.firstPoints[1]
      );

      const res = CalculateAccurateCylindersFromMultipleMeasurementPoints(
        data.mPoints,
        data.firstPoints[0],
        data.firstPoints[1]
      );
      console.log("%c Line:25 🥤 res", "color:#f5ce50", res);
      setData({
        ...data,
        calulateRes: res,
      });
    }
  }, []);

  return (
    <div>
      <div>center： {JSON.stringify(data?.calulateRes?.center)}</div>
      <div>圆心： {JSON.stringify(data?.calulateRes?.Mradial)}</div>
      <div>{JSON.stringify(data?.calulateRes)}</div>
    </div>
  );
}
