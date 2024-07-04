import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMemo } from "react";
import { Button, Table, Tabs, TabsProps } from "antd";
import { getDataFromTable } from "../utils/utils";
import ResultsTable2 from "../components/ResultsTable2";
import Result3 from "../components/Result3";
import { goToCV } from "../utils/commond";
import Module3D from "../components/Module3D";

const columns: any = [
  {
    title: "声道面",
    dataIndex: "type",
    key: "type",
    align: "center",
  },
  {
    title: "坐标",
    dataIndex: "x",
    align: "center",
    key: "x",
    render: (_, item) => {
      return `${item.id}( ${item?.x?.toFixed?.(4)}, ${item.y?.toFixed?.(
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
    title: "声道高度",
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
    render: (_, row) => {
      return (
        <Button
          onClick={() => {
            goToCV(row.x, row.y, row.z);
          }}
        >
          指示
        </Button>
      );
    },
  },
];

const trasfrom =
  (type: "A" | "B", sdfb: number, tableData: any[], R: number) =>
  (point, index) => {
    const d: any = getDataFromTable(sdfb, index) || {};
    console.log("%c Line:56 🥒 d", "color:#ffdd4d", d);
    tableData.push({
      type,
      id: point.label + point.key,
      x: point.x,
      y: point.y,
      z: point.z,
      a: d.ai,
      t: Math.sin(d.ai).toFixed(6),
      Gy: d.Gy,
      Wy: d.Wy,
      d: (Math.sin(d.ai) * R).toFixed(6),
    });
  };

export default function ResultTable() {
  const [data] = useRecoilState(Data);
  console.log("%c Line:6 🍢 data", "color:#f5ce50", data);
  const { sdfb, sdm, AB } = data;

  const R = data.calulateRes?.R;
  const dataSource = useMemo(() => {
    const tableData = [];
    sdm?.map((element) => {
      switch (element) {
        case "A":
          AB?.bottomA?.forEach?.(trasfrom("A", sdfb, tableData, R));

          break;
        case "B":
          AB?.bottomB?.forEach?.(trasfrom("B", sdfb, tableData, R));
          break;

        default:
          break;
      }
    });

    return tableData;
  }, [sdfb, sdm, AB]);

  const items: TabsProps["items"] = [
    {
      key: "1",
      label: "安装参数",
      children: <Table dataSource={dataSource} columns={columns}></Table>,
    },
    {
      key: "2",
      label: "测量点",
      children: <ResultsTable2 />,
    },
    {
      key: "3",
      label: "圆柱参数",
      children: <Result3 />,
    },
  ];

  return (
    <div className="q-flex">
      <div className="q-w-[500px]">
        <Module3D
          height="500px"
          direct={data?.direct}
          {...data}
          mPoints={[]}
        ></Module3D>
      </div>
      <Tabs className=" q-flex-1" defaultActiveKey="1" items={items} />
    </div>
  );
}
