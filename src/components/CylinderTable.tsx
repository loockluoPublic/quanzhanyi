import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";

const columns: any = [
  {
    title: "",
    dataIndex: "enable",
    key: "enable",
    with: 10,
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
    title: "点",
    dataIndex: "x",
    align: "left",
    key: "x",

    render: (_, item) => {
      return `${item.key} ( ${item?.x?.toFixed?.(4)}, ${item.y?.toFixed?.(
        3
      )}, ${item.z?.toFixed?.(4)} )`;
    },
  },
  {
    title: "初始标准差倍数",
    dataIndex: "originDiff",
    tip: "asda",
    key: "originDiff",
    align: "right",
  },
  {
    title: "当前标准差倍数",
    dataIndex: "diff",
    key: "difference",
    align: "right",
  },
];

export default function CylinderTable() {
  const d = useRecoilValue(Data);
  const originStandardDeviation = d.originStandardDeviation;
  const renderStandardDeviation = (v) => {
    if (typeof v === "number") {
      return `${(v / originStandardDeviation).toFixed(2)} δ`;
    } else {
      return `-- δ`;
    }
  };

  const data = d.mPoints.map((item) => {
    return {
      originDiff: renderStandardDeviation(item.originDiff),
      diff: renderStandardDeviation(item.difference),
      enable: item.enable,
      key: `${item.label ?? ""}${item.key}`,
      label: item.label,
      x: item.x,
      y: item.y,
      z: item.z,
    };
  });
  console.log("%c Line:60 🌮  data", "color:#ffdd4d", data);
  return (
    <div>
      <Table
        rowKey={"key"}
        className="q-w-full"
        dataSource={data}
        columns={columns}
        pagination={{
          pageSize: 10,
          hideOnSinglePage: true,
          showSizeChanger: false,
        }}
        size="small"
      />
    </div>
  );
}
