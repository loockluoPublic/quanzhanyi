import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";

export default function ResultTable() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:6 🍢 data", "color:#f5ce50", data);
  return <div>12</div>;
}
