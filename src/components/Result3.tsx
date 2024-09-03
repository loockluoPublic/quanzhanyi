import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";

export default function ResultsTable2() {
  const data = useRecoilValue(Data);
  console.log("%c Line:8 🍧 d", "color:#33a5ff", data);
  const [A, B] = data?.calulateRes?.Bottom_round_center ?? [];

  const every = data?.calulateRes?.Err_every;

  const res =
    every.reduce((acc, cur) => {
      return acc + Math.abs(cur);
    }, 0) / every.length;

  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>半径：</td>
            <td>{data?.calulateRes?.R?.toFixed?.(4)}米</td>
          </tr>
          <tr>
            <td>圆度：</td>
            <td>{res?.toFixed?.(6)}</td>
          </tr>
          <tr>
            <td>管道总长：</td>
            <td>{A?.distanceTo?.(B)?.toFixed?.(4)}米</td>
          </tr>
        </tbody>
      </table>
    </div>
  );
}
