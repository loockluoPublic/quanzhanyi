import { Button } from "antd";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { generateUnitCircleWithNormalVector } from "../utils/utils";
import useMeasure from "../utils/useMeasure";
import { useEffect } from "react";
import Module3D from "../components/Module3D";
import { CustomVector3 } from "../class/CustomVector3";

export function MeasurePoints() {
  const [data, setData] = useRecoilState(Data);

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
    <Module3D
      loading={loading}
      mPoints={data.mPoints ?? []}
      height="500px"
      direct={data?.direct}
      setData={setMData}
      pointsShowType="points"
      component={
        <div className="options q-mb-4">
          <Button type="primary" loading={loading} onClick={run}>
            运行
          </Button>
        </div>
      }
    ></Module3D>
  );
}
