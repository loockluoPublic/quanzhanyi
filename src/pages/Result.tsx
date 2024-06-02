import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMemo } from "react";
import { Button, Table } from "antd";
import { getDataFromTable } from "../utils/utils";

const columns: any = [
  {
    title: "坐标",
    dataIndex: "x",
    align: "center",
    key: "x",
    render: (_, item) => {
      return `( ${item?.x?.toFixed?.(4)}, ${item.y?.toFixed?.(
        4
      )}, ${item.z?.toFixed?.(4)} )`;
    },
  },
  {
    title: "声道高度角",
    dataIndex: "a",
    key: "a",
    align: "center",
  },
  {
    title: "声道长",
    dataIndex: "d",
    key: "d",
    align: "left",
  },
  {
    title: "相对声道高度",
    dataIndex: "t",
    key: "t",
    align: "left",
  },
  {
    title: "高斯-雅克比",
    dataIndex: "Gy",
    key: "Gy",
    align: "left",
  },
  {
    title: "圆形优化法",
    dataIndex: "Wy",
    key: "Wy",
    align: "left",
  },
  {
    title: "操作",
    dataIndex: "Wy1",
    key: "Wy1",
    align: "center",
    render: () => {
      return <Button>指示</Button>;
    },
  },
];

export default function ResultTable() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:6 🍢 data", "color:#f5ce50", data);
  const { sdfb, sdm, AB } = data;
  const dataSource = useMemo(() => {
    const tableData = [];
    sdm?.map((element) => {
      switch (element) {
        case "A":
          AB?.bottomA?.forEach?.((point, index) => {
            const d: any =
              getDataFromTable(sdfb, index % Math.ceil(sdfb / 2)) || {};
            console.log("%c Line:56 🥒 d", "color:#ffdd4d", d);
            tableData.push({
              x: point.x,
              y: point.y,
              z: point.z,
              a: d.ai,
              t: d.ti,
              Gy: d.Gy,
              Wy: d.Wy,
            });
          });

          break;
        case "B":
          break;

        default:
          break;
      }
    });

    return tableData;
  }, [sdfb, sdm, AB]);
  return (
    <div>
      <Table dataSource={dataSource} columns={columns}></Table>
    </div>
  );
}
