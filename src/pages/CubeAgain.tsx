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
      data.cubeAgainTable?.map?.((item, index) => {
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
        cubeAgainTable: tableData,
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
      render: (_v, row, i) => {
        console.log("%c Line:55 🍕 row", "color:#2eafb0", row.i, 2 * row.i - 1);
        return (
          <PointsVector3
            value={_v}
            before={() => {
              const slnum =
                data.sdm?.length === 2 && row.sdm === "B"
                  ? row.i - data.sdfb
                  : row.i;
              CustomVector3.setPublicInfo(row.sdm, 2 * slnum - 2);
            }}
            onChange={(v) => onChange(v, i, "p1")}
          />
        );
      },
    },
    {
      title: "声道点2",
      dataIndex: "p2",
      key: "p3",
      align: "center",
      render: (_v, row, i) => {
        return (
          <PointsVector3
            before={() => {
              const slnum =
                data.sdm?.length === 2 && row.sdm === "B"
                  ? row.i - data.sdfb
                  : row.i;
              CustomVector3.setPublicInfo(row.sdm, 2 * slnum - 1);
            }}
            value={_v}
            onChange={(v) => onChange(v, i, "p2")}
          />
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

  const w = "--";
  const h = "--";
  const comp = (
    <div>
      <h3>拟合参数：</h3>
      <div className=" q-my-4">
        <span>
          方涵宽度：
          {w} 米
        </span>
        <span className="q-ml-8">方涵高度： {h} 米</span>
        <span className="q-ml-8">
          声道配置： {data.sdm.length}E{data.sdfb}P
        </span>
      </div>
      <h3>复测结果：</h3>
      <Table
        columns={columns}
        dataSource={data.cubeAgainTable}
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
  data.cubeAgainTable?.forEach((item: any) => {
    item.p1 && mPoints.push(item.p1);
    item.p2 && mPoints.push(item.p2);
  });

  return (
    <CylinderModule
      component={comp}
      trianglePoints={data.trianglePoints}
      mPoints={mPoints}
    ></CylinderModule>
  );
}
