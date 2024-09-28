import { Button, Checkbox, Select, Table } from "antd";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMemo } from "react";
import CylinderModule from "../components/Module3D";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";
import { juXingFuCe, rad2ang } from "../utils/utils";
import { SDFBOptions, sdmOptions } from "./CubeResult";

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
      render: (v) => {
        return v?.toFixed(4);
      },
    },
    {
      title: "声道角",
      dataIndex: "sdj",
      key: "sdj",
      align: "right",
      render: (v) => {
        return typeof v === "number" ? rad2ang(v)?.toFixed(2) : "";
      },
    },
    {
      title: "LT偏移",
      dataIndex: "ltOffset",
      key: "ltOffset",
      align: "right",
      render: (v) => {
        return v?.toFixed(4);
      },
    },
    {
      title: "声道相对高度",
      dataIndex: "sdH",
      key: "sdH",
      align: "right",
      render: (v) => {
        return v?.toFixed(4);
      },
    },
    {
      title: "高斯勒让德权重",
      dataIndex: "Wquanzhong3",
      key: "Wquanzhong3",
      align: "right",
      render: (v) => {
        return v?.map?.((item) => item?.toFixed(4))?.join?.("，");
      },
    },

    {
      title: "矩形优化权重",
      dataIndex: "Wquanzhong4",
      key: "Wquanzhong4",
      align: "right",
      render: (v) => {
        return v?.map?.((item) => item?.toFixed(4))?.join?.("，");
      },
    },
  ].filter((item) => item.key !== data.sfType);

  const setMockData = () => {
    const AB = [
      ...data.AB.map((item) => item.pointA),
      ...data.AB.map((item) => item.pointB),
    ].sort((a, b) => (`${a.label}${a.key}` > `${b.label}${b.key}` ? 1 : -1));

    console.log("%c Line:153 🍕 AB", "color:#ea7e5c", AB);
    const newTable = data.cubeAgainTable?.map((item, i) => {
      return {
        ...item,
        p1: AB[2 * i],
        p2: AB[2 * i + 1],
      };
    });

    setData((d) => {
      return {
        ...d,
        cubeAgainTable: newTable,
      };
    });
  };

  const calcFuCe = () => {
    const res = juXingFuCe(
      data.cubeResult,
      data.planeParaOut,
      data.cubeAgainTable,
      data.sdfb,
      data.sdm?.length
    );

    const newTable = data.cubeAgainTable?.map((item, i) => {
      return {
        ...item,
        ...res?.[i],
      };
    });

    setData((d) => {
      return {
        ...d,
        cubeAgainTable: newTable,
      };
    });
  };

  const width = data?.cubeResult?.b?.toFixed(4);
  const hight = data?.cubeResult?.h?.toFixed(4);
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
            优化方法：
            <Select
              value={data.sfType}
              className=" !q-w-40"
              options={[
                { label: "高斯勒让德权重", value: "Wquanzhong4" },
                { label: "矩形优化权重", value: "Wquanzhong3" },
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
          方涵宽度：
          {width} 米
        </span>
        <span className="q-ml-8">方涵高度：{hight} 米</span>
        <span className="q-ml-8">
          声道配置： {data.sdm.length}E{data.sdfb}P
        </span>
      </div>
      <h3 className="border-top q-pt-4">
        复测结果：
        <div className="q-float-right q-mb-2">
          <Button onClick={setMockData}>模拟数据</Button>
          <Button type="primary" onClick={calcFuCe}>
            计算
          </Button>
        </div>
      </h3>
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
