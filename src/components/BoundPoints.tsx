import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import PointsVector3 from "./PointVector3";
import Block from "./Block";

export default function BoundPoints() {
  const [data, setData] = useRecoilState(Data);

  const boundPoints = data.firstPoints;

  return (
    <div className="q-flex">
      <span>
        边界点1：
        <PointsVector3
          className="!q-inline-flex"
          value={boundPoints?.[0]}
          autoMeasure
          onChange={(v) => {
            setData({ ...data, firstPoints: [v, boundPoints?.[1]] });
          }}
        />
      </span>
      <span className="q-ml-8">
        边界点2：
        <PointsVector3
          className="!q-inline-flex"
          value={boundPoints?.[1]}
          onChange={(v) => {
            setData({ ...data, firstPoints: [boundPoints?.[0], v] });
          }}
        />
      </span>
    </div>
  );
}
