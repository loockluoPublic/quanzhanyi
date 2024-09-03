import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import { CustomVector3 } from "../class/CustomVector3";

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
      return `${item.key ?? ""} ( ${item?.x?.toFixed?.(4)}, ${item.y?.toFixed?.(
        4
      )}, ${item.z?.toFixed?.(4)} )`;
    },
  },
  // {
  //   title: "初始标准差倍数",
  //   dataIndex: "originDiff",
  //   tip: "asda",
  //   key: "originDiff",
  //   align: "right",
  // },
  // {
  //   title: "当前标准差倍数",
  //   dataIndex: "diff",
  //   key: "difference",
  //   align: "right",
  // },
];

export default function CubeTable(props: { points: CustomVector3[] }) {
  const d = useRecoilValue(Data);
  const originStandardDeviation = d.originStandardDeviation;
  const renderStandardDeviation = (v) => {
    if (typeof v === "number") {
      return `${(v / originStandardDeviation).toFixed(2)} δ`;
    } else {
      return `-- δ`;
    }
  };
  const data = props?.points?.map?.((item) => {
    return {
      // originDiff: renderStandardDeviation(item.originDiff),
      // diff: renderStandardDeviation(item.difference),
      enable: item.enable,
      key: `${item.label ?? ""}${item.key}`,
      label: item.label,
      x: item.x,
      y: item.y,
      z: item.z,
    };
  });
  return (
    <div>
      <Table
        className="q-w-full"
        dataSource={data ?? []}
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
