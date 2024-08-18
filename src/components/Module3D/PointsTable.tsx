import { Button, Modal, Table } from "antd";
import { CustomVector3 } from "../../class/CustomVector3";
import { useMemo, useState } from "react";
import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import ResultsTable2 from "../ResultsTable2";

export function PointsTable(props: { mPoints: CustomVector3[] }) {
  const [isModalOpen, setIsModalOpen] = useState(false);

  const showModal = () => {
    setIsModalOpen(true);
  };

  const handleOk = () => {
    setIsModalOpen(false);
  };

  const handleCancel = () => {
    setIsModalOpen(false);
  };

  return (
    <div className=" q-flex q-justify-between">
      <span>有效点：</span>
      <span className=" q-font-bold">
        {props.mPoints.filter((item) => item.enable).length}/
        {props.mPoints.length}
      </span>
      <Button type="primary" onClick={showModal} size="small">
        查看详情
      </Button>
      <Modal
        width={800}
        title="测点详情"
        open={isModalOpen}
        onOk={handleOk}
        onCancel={handleCancel}
        footer={null}
        zIndex={9999}
      >
        <ResultsTable2 />
      </Modal>
    </div>
  );
}
