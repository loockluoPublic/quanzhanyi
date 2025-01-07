import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { useRecoilState, useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import PointsVector3 from "./PointVector3";

export default function CylinderTable() {
  const [d, sd] = useRecoilState(Data);
  const originStandardDeviation = d.originStandardDeviation;
  const renderStandardDeviation = (v) => {
    if (typeof v === "number") {
      return `${(v / originStandardDeviation).toFixed(2)} δ`;
    } else {
      return `-- δ`;
    }
  };

  const remove = (item: any) => {

    const m = [...d.mPoints].filter(p => !(item.key === p.key && item.label === p.label));

    sd((d) => {
      return {
        ...d,
        mPoints: m,
      };
    });
  };

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
      title: "采样点坐标",
      dataIndex: "x",
      align: "left",
      key: "x",

      render: (_, item) => {
        console.log("%c Line:51 🥪 item", "color:#ea7e5c", item);
        return (
          <PointsVector3
            value={item}
            showGetPoints={false}
            remove={() => {
              remove(item);
            }}
          />
        );
      },
    },
    {
      title: "初始标准差倍数",
      dataIndex: "originDiff",
      key: "originDiff",
      align: "right",
    },
    {
      title: "当前标准差倍数",
      dataIndex: "diff",
      key: "difference",
      align: "right",
      render: (v, row) => {
        return row.enable && v;
      },
    },
  ];

  const data = d.mPoints.map((item) => {
    return {
      originDiff: renderStandardDeviation(item.originDiff),
      diff: renderStandardDeviation(item.difference),
      enable: item.enable,
      id: `${item.label ?? ""}${item.key}-${item.x}-${item.y}-${item.z}`,
      key: item.key,
      label: item.label,
      x: item.x,
      y: item.y,
      z: item.z,
    };
  });

  return (
    <div>
      <Table
        rowKey={"id"}
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
