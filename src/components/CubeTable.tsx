import { CheckCircleOutlined, CloseCircleOutlined } from "@ant-design/icons";
import { Table } from "antd";
import { CustomVector3 } from "../class/CustomVector3";
import PointsVector3 from "./PointVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";

export default function CubeTable(props: {
  points: CustomVector3[];
  num: number;
}) {
  // const data = props?.points;
  const [data, setData] = useRecoilState(Data);
  const remove = (i) => {
    const m = [...data.MxPoints?.[`m${props.num}`]];
    m.splice(i, 1);
    setData((d) => {
      return {
        ...d,
        MxPoints: {
          ...data.MxPoints,
          [`m${props.num}`]: m,
        },
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
      title: "点",
      dataIndex: "x",
      align: "left",
      key: "x",

      render: (_, item, i) => {
        return (
          <PointsVector3
            value={item}
            showGetPoints={false}
            remove={() => remove(i)}
          />
        );
      },
    },
    {
      title: "点到平面距离",
      dataIndex: "originDiff",
      tip: "asda",
      key: "originDiff",
      align: "right",
      render: (_, item) => {
        return <>{item.difference?.toFixed?.(6) ?? "--"}米</>;
      },
    },
    // {
    //   title: "当前标准差倍数",
    //   dataIndex: "diff",
    //   key: "difference",
    //   align: "right",
    // },
  ];

  return (
    <div>
      <Table
        className="q-w-full"
        dataSource={props?.points ?? []}
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
