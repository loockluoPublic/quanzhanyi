import { Table } from "antd";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMemo } from "react";
import CylinderModule from "../components/Module3D";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";

export default function () {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:7 🥃 data", "color:#42b983", data);

  const onChange = (v: CustomVector3, i: number, key: string) => {
    const tableData: any =
      data.cylinderAgainTable?.map?.((item, index) => {
        const newItem = {
          ...item,
        };
        if (index === i) {
          debugger;
          newItem[key] = v;
        }
        return newItem;
      }) ?? [];
    setData((d) => {
      return {
        ...d,
        cylinderAgainTable: tableData,
      };
    });
  };

  const columns: any = [
    {
      title: "声道面",
      dataIndex: "sdm",
      align: "center",
      key: "sdm",
    },
    {
      title: "声道",
      dataIndex: "i",
      align: "center",
      key: "i",
      render: (i, _i) => {
        return <>第{i}声道</>;
      },
    },
    {
      title: "声道点1",
      dataIndex: "p1",
      key: "p1",
      align: "center",
      render: (_v, _, i) => {
        return (
          <PointsVector3 value={_v} onChange={(v) => onChange(v, i, "p1")} />
        );
      },
    },
    {
      title: "声道点2",
      dataIndex: "p2",
      key: "p3",
      align: "center",
      render: (_v, _, i) => {
        return (
          <PointsVector3 value={_v} onChange={(v) => onChange(v, i, "p2")} />
        );
      },
    },
    {
      title: "声道长",
      dataIndex: "sdc",
      key: "sdc",
      align: "right",
    },
    {
      title: "声道角",
      dataIndex: "sdj",
      key: "sdj",
      align: "right",
    },
    {
      title: "LT偏移",
      dataIndex: "ltOffset",
      key: "ltOffset",
      align: "right",
    },
    {
      title: "声道相对高度",
      dataIndex: "sdH",
      key: "sdH",
      align: "right",
    },
    {
      title: "权系数",
      dataIndex: "qxs",
      key: "difference",
      align: "right",
    },
  ];

  const comp = (
    <div>
      <h3>拟合参数：</h3>
      <div className=" q-my-4">
        <span>
          声道分布：
          {data.sdfb}
        </span>
        <span className="q-ml-8">
          拟合标准差： {data?.standardDeviation?.toFixed(4) ?? "--"} 米
        </span>
        <span className="q-ml-8">
          声道配置： {data.sdm.length}E{data.sdfb}P
        </span>
      </div>
      <h3>复测结果：</h3>
      <Table
        columns={columns}
        dataSource={data.cylinderAgainTable}
        pagination={{
          pageSize: 10,
          hideOnSinglePage: true,
          showSizeChanger: false,
        }}
        size="small"
      />
    </div>
  );

  const mPoints = [];
  data.cylinderAgainTable?.forEach((item) => {
    item.p1 && mPoints.push(item.p1);
    item.p2 && mPoints.push(item.p2);
  });

  return (
    <CylinderModule
      component={comp}
      calulateRes={data.calulateRes}
      mPoints={mPoints}
    ></CylinderModule>
  );
}
