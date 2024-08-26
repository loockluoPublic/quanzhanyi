import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import PointsVector3 from "./PointVector3";

export default function BoundPoints() {
  const [data, setData] = useRecoilState(Data);

  const boundPoints = data.firstPoints;

  return (
    <div>
      <div className="q-font-bold">边界范围点：</div>
      <div className="q-flex">
        <span>
          <PointsVector3
            value={boundPoints?.[0]}
            autoMeasure
            onChange={(v) => {
              setData({ ...data, firstPoints: [v, boundPoints?.[1]] });
            }}
          />
        </span>
        <span className="q-ml-8">
          <PointsVector3
            value={boundPoints?.[1]}
            onChange={(v) => {
              setData({ ...data, firstPoints: [boundPoints?.[0], v] });
            }}
          />
        </span>
      </div>
    </div>
  );
}
