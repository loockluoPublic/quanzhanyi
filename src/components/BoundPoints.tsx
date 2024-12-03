import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import PointsVector3 from "./PointVector3";
import { CustomVector3 } from "../class/CustomVector3";

export default function BoundPoints() {
  const [data, setData] = useRecoilState(Data);

  const boundPoints = data.firstPoints;

  return (
    <div className="q-flex">
      <span>
        上游边界点：
        <PointsVector3
          hideLabel
          className="!q-inline-flex"
          value={boundPoints?.[0]}
          before={() => {
            CustomVector3.setPublicInfo("上游点", 0);
          }}
          onChange={(v) => {
            v.color = "blue";
            setData({ ...data, firstPoints: [v, boundPoints?.[1]] });
          }}
        />
      </span>
      <span className="q-ml-8">
        下游边界点：
        <PointsVector3
          hideLabel
          className="!q-inline-flex"
          value={boundPoints?.[1]}
          before={() => {
            CustomVector3.setPublicInfo("下游点", 1);
          }}
          onChange={(v) => {
            setData({ ...data, firstPoints: [boundPoints?.[0], v] });
          }}
        />
      </span>
    </div>
  );
}
