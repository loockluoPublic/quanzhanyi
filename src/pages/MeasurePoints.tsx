import { Button, Col, Form, InputNumber, Row, message } from "antd";
// import Module3D from "./module3D";
import PointsVector3 from "../components/PointVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { generateUnitCircleWithNormalVector } from "../utils/utils";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef } from "react";
import { pointToAndMeasure } from "../utils/commond";
import Module3D from "../components/Module3D";
import mockData from "../utils/mockData";
import { CustomVector3 } from "../class/CustomVector3";

export function MeasurePoints() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:19 🥒 data", "color:#465975", data);

  const { measure, loading, points } = useMeasure();

  const run = () => {
    CustomVector3.setPublicInfo("P", 1);
    generateUnitCircleWithNormalVector(
      data?.direct?.[0],
      data?.direct?.[1],
      data.numPerLay,
      data.layNum,
      data?.firstPoints?.[0],
      data?.firstPoints?.[1]
    ).then((waitingPoints) => {
      setData({
        ...data,
        waitingPoints,
      });
      measure(waitingPoints);
    });
  };

  const setMockData = () => {
    CustomVector3.setPublicInfo("P", 0);
    setData({
      ...data,
      mPoints: mockData.mPoints.map(
        (item) => new CustomVector3(item.x, item.y, item.z)
      ),
    });
  };

  useEffect(() => {
    if (!loading && points.length > 0) {
      console.log("%c Line:50 🍷 points", "color:#33a5ff", points);
      setData({
        ...data,
        mPoints: points,
      });
    }
  }, [loading, points]);

  const setMData = (md: typeof points) => {
    if (md?.length > 0)
      setData({
        ...data,
        mPoints: md,
      });
  };

  return (
    <div>
      <Module3D
        loading={loading}
        mPoints={data.mPoints ?? []}
        height="500px"
        direct={data?.direct}
        setData={setMData}
        pointsShowType="points"
        component={
          <div className="q-flex-shrink-0 q-flex-grow-0 q-w-[200px]">
            <Button type="primary" loading={loading} onClick={run}>
              运行
            </Button>
            <Button onClick={setMockData}>测试数据</Button>
          </div>
        }
      ></Module3D>
    </div>
  );
}
