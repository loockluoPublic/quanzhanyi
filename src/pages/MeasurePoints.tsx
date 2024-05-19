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
const { Item } = Form;

const mock = new URLSearchParams(location.search).has("mock");

export function MeasurePoints() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:19 🥒 data", "color:#465975", data);

  const { measure, loading, points } = useMeasure();

  const run = () => {
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
    setData({
      ...data,
      mPoints: mockData.mPoints.map(
        (item) => new CustomVector3(item.x, item.y, item.z)
      ),
    });
  };

  useEffect(() => {
    if (!loading && points.length > 0) {
      setData({
        ...data,
        mPoints: points,
      });
    }
  }, [loading, points]);

  const setMData = (md: typeof points) => {
    setData({
      ...data,
      mPoints: md,
    });
  };

  return (
    <div>
      <Module3D
        loading={loading}
        points={data.mPoints ?? []}
        height="500px"
        direct={data?.direct}
        setData={setMData}
        component={
          <>
            <Button loading={loading} onClick={run}>
              运行
            </Button>
            <Button onClick={setMockData}>测试数据</Button>
          </>
        }
      ></Module3D>
    </div>
  );
}
