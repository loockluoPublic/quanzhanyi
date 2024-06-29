import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";

const columns: any = [
  {
    title: "",
    dataIndex: "enable",
    key: "enable",
    with: 30,
    align: "center",
    render: (enable) => {
      return enable ? (
        <CheckCircleOutlined style={{ color: "#40c057" }} />
      ) : (
        <CloseCircleOutlined style={{ color: "" }} />
      );
    },
  },
  {
    title: "ID",
    dataIndex: "key",
    key: "ID",
    with: 200,
  },
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
    title: "差值",
    dataIndex: "diff",
    key: "difference",
    align: "right",
    render: (v) => {
      return v?.toFixed?.(8);
    },
  },
];

export default function ResultsTable2() {
  const d = useRecoilValue(Data);

  const data = d.mPoints.map((item) => {
    return {
      diff: item.difference,
      enable: item.enable,
      key: `${item.label}${item.key}`,
      x: item.x,
      y: item.y,
      z: item.z,
    };
  });
  return (
    <Table dataSource={data} columns={columns} pagination={{ pageSize: 10 }} />
  );
}
