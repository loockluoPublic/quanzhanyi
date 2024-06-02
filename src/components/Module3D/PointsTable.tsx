import { Button, Modal, Table } from "antd";
import { CustomVector3 } from "../../class/CustomVector3";
import { useMemo, useState } from "react";
import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";

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
export function PointsTable(props: { mPoints: CustomVector3[] }) {
  const [isModalOpen, setIsModalOpen] = useState(false);

  const data = props.mPoints.map((item) => {
    return {
      diff: item.difference,
      enable: item.enable,
      key: item.key,
      x: item.x,
      y: item.y,
      z: item.z,
    };
  });
  console.log("%c Line:26 🍰 data", "color:#465975", data);

  const showModal = () => {
    setIsModalOpen(true);
  };

  const handleOk = () => {
    setIsModalOpen(false);
  };

  const handleCancel = () => {
    setIsModalOpen(false);
  };

  console.log("%c Line:41 🍉 props.mPoints", "color:#b03734", props.mPoints);
  return (
    <div className=" q-flex q-justify-between">
      <span>有效点：</span>
      <span>
        {props.mPoints.filter((item) => item.enable).length}/
        {props.mPoints.length}
      </span>
      <Button type="primary" onClick={showModal} size="small">
        查看详情
      </Button>
      <Modal
        title="测点详情"
        open={isModalOpen}
        onOk={handleOk}
        onCancel={handleCancel}
        footer={null}
        zIndex={9999}
      >
        <Table
          dataSource={data}
          columns={columns}
          pagination={{ pageSize: 10 }}
        />
      </Modal>
    </div>
  );
}
