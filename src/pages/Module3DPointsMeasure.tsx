import { Form, InputNumber, message } from "antd";
import Module3D from "./module3D";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMount } from "ahooks";
import {
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  generateUnitCircleWithNormalVector,
} from "../utils/utils";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef } from "react";
import { pointToAndMeasure } from "../utils/commond";
const { Item } = Form;

export function Module3DPointsMeasure() {
  const [data, setData] = useRecoilState(Data);

  const flag = useRef(true);
  useEffect(() => {
    if (flag.current) {
      flag.current = false;
      const res = CalculateAccurateCylindersFromMultipleMeasurementPoints(
        data.mdPoints,
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
      <div>center： {JSON.stringify(data.calulateRes.center)}</div>
      <div>圆心： {JSON.stringify(data.calulateRes.Mradial)}</div>
      <div>{JSON.stringify(data.calulateRes)}</div>
    </div>
  );
}
