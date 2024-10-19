import { Button, Checkbox, message, Select, Table } from "antd";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import CylinderModule from "../components/Module3D";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";
import { rad2ang, yuanXingFuCe } from "../utils/utils";
import { SDFBOptions, sdmOptions } from "./CubeResult";

export default function () {
  const [data, setData] = useRecoilState(Data);

  const onChange = (v: CustomVector3, i: number, key: string) => {
    const tableData: any =
      data.cylinderAgainTable?.map?.((item, index) => {
        const newItem = {
          ...item,
        };
        if (index === i) {
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
      title: "下游换能器",
      dataIndex: "p1",
      key: "p1",
      align: "center",
      render: (_v, row, i) => {
        return (
          <PointsVector3
            value={_v}
            before={() => {
              const slnum =
                data.sdm?.length === 2 && row.sdm === "B"
                  ? row.i - data.sdfb
                  : row.i;
              console.log("%c Line:63 🍏 slnum", "color:#6ec1c2", row.i, slnum);
              CustomVector3.setPublicInfo(row.sdm, 2 * slnum - 2);
            }}
            onChange={(v) => onChange(v, i, "p1")}
          />
        );
      },
    },
    {
      title: "上游换能器",
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
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },
    {
      title: "声道角",
      dataIndex: "sdj",
      key: "sdj",
      align: "right",
      render: (v) => {
        return typeof v === "number" ? rad2ang(v, true)?.toFixed(2) : "";
      },
    },
    {
      title: "LT偏移",
      dataIndex: "ltOffset",
      key: "ltOffset",
      align: "right",
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },
    {
      title: "声道相对高度",
      dataIndex: "sdH",
      key: "sdH",
      align: "center",
      render: (v) => {
        if (isNaN((data?.calulateRes?.R / 2) * v)) return "";
        return `${(data?.calulateRes?.R * v)?.toFixed?.(4)}米 ${v?.toFixed?.(
          4
        )} `;
      },
    },
    {
      title: "高斯-雅克比",
      dataIndex: "Wquanzhong3",
      key: "Wquanzhong3",
      align: "right",
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },

    {
      title: "圆形优化法",
      dataIndex: "Wquanzhong4",
      key: "Wquanzhong4",
      align: "right",
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },
  ].filter((item) => item.key !== data.sfType);

  const calcFuCe = () => {
    if (!data.calulateRes) {
      message.warning("缺少拟合参数，请返回上一步");
      return;
    }

    for (const item of data.cylinderAgainTable) {
      console.log("%c Line:163 🥐 item", "color:#ea7e5c", item);
      if (!item.p1 || !item.p2) {
        message.warning(`第${(item as any).i}声道缺少复测点，请采集`);
        return;
      }
    }

    const res = yuanXingFuCe(
      data.calulateRes,
      data.cylinderAgainTable,
      data.sdfb,
      data.sdj,
      data.sdm.length
    );

    const newTable = data.cylinderAgainTable?.map((item, i) => {
      return {
        ...item,
        ...res?.[i],
      };
    });

    setData((d) => {
      return {
        ...d,
        cylinderAgainTable: newTable,
      };
    });
  };

  const comp = (
    <div>
      <h3>参数设置：</h3>
      <div className="q-flex q-justify-between">
        <div>
          <span>
            声道面：{" "}
            <Checkbox.Group
              value={data.sdm}
              options={sdmOptions}
              onChange={(sdm: ("A" | "B")[]) => {
                setData({
                  ...data,
                  sdm,
                });
              }}
            ></Checkbox.Group>
          </span>
          <span className="q-ml-8">
            声道分布：
            <Select
              value={data.sdfb}
              className=" !q-w-32"
              options={SDFBOptions}
              onChange={(sdfb) => {
                setData({
                  ...data,
                  sdfb,
                });
              }}
            />
          </span>
          <span className="q-ml-8">
            积分方法：
            <Select
              value={data.sfType}
              className=" !q-w-30"
              options={[
                { label: "高斯-雅克比", value: "Wquanzhong4" },
                { label: "圆形优化法", value: "Wquanzhong3" },
              ]}
              onChange={(sfType) => {
                setData({
                  ...data,
                  sfType,
                });
              }}
            />
          </span>
        </div>
      </div>
      <div className=" q-my-4">
        <span>
          管道半径：
          {data?.calulateRes?.R?.toFixed(4) ?? "--"} 米
        </span>
        <span className="q-ml-8">
          声道配置： {data.sdm.length}E{data.sdfb}P
        </span>
      </div>
      <h3 className="border-top q-pt-4">
        复测结果：
        <div className="q-float-right q-mb-2">
          <Button type="primary" onClick={calcFuCe}>
            计算
          </Button>
        </div>
      </h3>
      <Table
        rowKey={"i"}
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
  const pA = [],
    pB = [];

  data.cylinderAgainTable?.forEach((item: any) => {
    item.p1 && mPoints.push(item.p1);
    item.p2 && mPoints.push(item.p2);
    if (item.sdm === "A") {
      pA.push(item.p1, item.p2);
    } else {
      pB.push(item.p1, item.p2);
    }
  });

  return (
    <CylinderModule
      component={comp}
      trianglePoints={data.trianglePoints}
      calulateRes={data.calulateRes}
      AB={pA.map((item, i) => {
        return {
          pointA: item,
          pointB: pB[i],
        };
      })}
      sdm={data.sdm}
    ></CylinderModule>
  );
}
