import CubeFitting from "../components/Module3D/CubeModule";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { Checkbox, InputNumber, message, Table, Tooltip } from "antd";
import { SettingOutlined } from "@ant-design/icons";
import { Point } from "../components/Point";
import { useEffect, useRef } from "react";
import Select, { DefaultOptionType } from "antd/es/select";
import {
  ang2rad,
  CalcJuXingAAndBPointsAfterOffest,
  CalculateRectangleFromVertex8,
  cubeTOff,
  sdj_n2v,
  sdj_v2n,
  shengDaoGaoDu,
} from "../utils/utils";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";

export const SDFBOptions = (() => {
  const options: DefaultOptionType[] = [];
  for (let index = 2; index <= 10; index++) {
    options.push({ value: index, label: `${index}声道` });
  }
  return options;
})();

export const sdmOptions = [
  { label: "声道面A", value: "A" },
  { label: "声道面B", value: "B" },
];
const defaultA = 0.015;
function CubeResult() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:32 🍰 data", "color:#f5ce50", data);

  const sdfbPreRef = useRef(0);

  useEffect(() => {
    if (typeof data.sdfb === "number" && data.sdfb !== sdfbPreRef.current) {
      const cubeTable = shengDaoGaoDu(data.sdfb).map((ti, i) => {
        const sign = i < data.sdfb ? -1 : 1;
        const h = Number(ti.toFixed(6));
        return {
          h,
          a: defaultA,
          tOff: cubeTOff(defaultA, data.sdj, sign),
          sign,
        };
      });
      setData((d) => {
        return {
          ...d,
          cubeTable,
        };
      });
    }
    sdfbPreRef.current = data.sdfb;
  }, [data.sdfb, data?.cubeTable]);

  const updateOffset = () => {
    if (!(data.cubeTable?.length > 0)) return;

    const tableData = data.cubeTable.map((item) => {
      const newItem = {
        ...item,
        tOff: cubeTOff(item.a, data.sdj, item.sign),
      };

      return newItem;
    });
    setData((d) => {
      return {
        ...d,
        cubeTable: tableData,
      };
    });
  };

  useEffect(() => {
    updateOffset();
  }, [data.sdj]);

  const tOff =
    data.cubeTable?.map?.((item) => {
      return item.tOff;
    }) ?? [];

  const a =
    data.cubeTable?.map?.((item) => {
      return item.a;
    }) ?? [];

  const Ti =
    data.cubeTable?.map?.((item) => {
      return item.h;
    }) ?? [];

  const calcPoint = () => {
    if (!data.centerPoint) {
      message.error("请采集AB面交点");
      return;
    }

    if (!data.cubeResult) {
      message.error("缺少拟合参数，请退回上一步拟合");
      return;
    }

    if (tOff.length > 0 && Ti.length > 0) {
      try {
        let AB;

        if (data.hasChamfer) {
          let MxPortsArr: CustomVector3[][] = [];
          for (let i = 0; i < 8; i++) {
            const key = `m${i}`;
            if (data.MxPoints[key]?.length > 9) {
              MxPortsArr.push(data.MxPoints[key].slice(0, 50));
            } else {
              message.error(`${key}面采集点少于10个，请补充采集点`);
              return;
            }
          }

          const [l, t, r, b, lb, lt, rt, rb] = MxPortsArr;
          MxPortsArr = [l, lt, t, rt, r, rb, b, lb];

          AB = CalculateRectangleFromVertex8(
            MxPortsArr,
            data.firstPoints[0],
            data.firstPoints[1],
            data.centerPoint,
            ang2rad(data.sdj),
            data.sdfb,
            Ti,
            a,
            data.distanceThreshold
          );
        } else {
          AB = CalcJuXingAAndBPointsAfterOffest(
            data.cubeResult,
            data.centerPoint,
            ang2rad(data.sdj),
            data.sdfb,
            Ti,
            tOff
          );
        }

        const tableData = data.cubeTable.map((item, i) => {
          const newItem = {
            ...item,
            AB: AB[i],
            rOff: AB?.[i]?.rOff,
          };

          return newItem;
        });
        setData((d) => {
          return {
            ...d,
            AB,
            cubeTable: tableData,
          };
        });
      } catch (error) {
        console.log(
          "%c Line:108 🌰 error",
          "color:#ed9ec7",
          data.cubeResult,
          error
        );
      }
    }
  };

  useEffect(() => {
    if (data.centerPoint) calcPoint();
  }, [[...Ti, ...tOff, ...a].join(","), data.centerPoint]);

  const onChange = (v: number, i: number, key: string) => {
    console.log("%c Line:153 🌮 v", "color:#3f7cff", v, i, key);
    const tableData = data.cubeTable.map((item, index) => {
      const newItem = {
        ...item,
      };
      if (index === i) {
        newItem[key] = v;
        if (key === "a") {
          newItem.tOff = cubeTOff(newItem.a, data.sdj, item.sign);
        }
      }
      return newItem;
    });
    setData((d) => {
      return {
        ...d,
        cubeTable: tableData,
      };
    });
  };

  /**
   * 当前a值应用到全部
   * @param i
   */
  const setA = (i: number) => {
    const a = data.cubeTable[i].a;
    const tableData = data.cubeTable.map((item) => {
      const newItem = {
        ...item,
        a,
      };

      return newItem;
    });

    setData((d) => {
      return {
        ...d,
        cubeTable: tableData,
      };
    });
  };

  const columns: any = [
    {
      title: "声道相对高度",
      dataIndex: "h",
      key: "h",
      align: "center",
      render: (v, _, i) => {
        return <InputNumber value={v} onChange={(v) => onChange(v, i, "h")} />;
      },
    },
    {
      title: "插入深度",
      dataIndex: "a",
      key: "a",
      align: "center",
      render: (v, _, i) => {
        return (
          <InputNumber
            step={0.01}
            value={v}
            onChange={(v) => onChange(v, i, "a")}
            addonAfter={
              <div>
                米{" "}
                <Tooltip title="应用到全部" className="q-cursor-pointer">
                  <SettingOutlined onClick={() => setA(i)} />
                </Tooltip>
              </div>
            }
          />
        );
      },
    },

    {
      title: "轴向偏移",
      dataIndex: "tOff",
      key: "tOff",
      align: "center",
      render: (v) => {
        return <>{v?.toFixed?.(3) ?? "--"}米</>;
      },
    },
    {
      title: "斜面偏移",
      dataIndex: "rOff",
      key: "rOff",
      align: "center",
      render: (v) => {
        return <>{v?.toFixed?.(3) ?? "--"}米</>;
      },
    },

    {
      title: "安装点",
      width: 100,
      dataIndex: "AB",
      key: "AB",
      align: "center",
      render: (v) => {
        return (
          <div className="q-flex q-justify-center">
            {data?.sdm?.includes("A") && <Point p={v?.pointA} />}
            {data?.sdm?.includes("B") && (
              <Point className="q-ml-2" p={v?.pointB} />
            )}
          </div>
        );
      },
    },
  ].filter((item) => {
    return (!data.hasChamfer && item.key !== "rOff") || data.hasChamfer;
  });

  const comp = (
    <div>
      <h3>声道参数：</h3>
      <div>
        <span>
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
          声道角：
          <InputNumber
            value={sdj_n2v(data.sdj)}
            addonAfter="度"
            min={0}
            max={90}
            onChange={(sdj: number) => {
              setData({
                ...data,
                sdj: sdj_v2n(sdj),
              });
            }}
          />
        </span>
      </div>
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
          AB面交点：
          <PointsVector3
            className="!q-inline-flex"
            value={data.centerPoint as CustomVector3}
            onChange={(v) => {
              setData({ ...data, centerPoint: v });
            }}
          />
        </span>
      </div>
      <h3 className="q-mt-2 border-top q-pt-2">安装点详情：</h3>
      <div>
        <Table
          size="small"
          key={data.sdfb}
          dataSource={
            data.cubeTable?.map((item, i) => {
              return {
                ...item,
                key: i,
                AB: data.AB?.[i],
              };
            }) ?? []
          }
          columns={columns}
          pagination={{ hideOnSinglePage: true }}
        ></Table>
      </div>
    </div>
  );
  return (
    <CubeFitting
      component={comp}
      firstPoints={data.firstPoints}
      trianglePoints={data.trianglePoints}
      AB={data.AB}
      sdm={data.sdm}
    ></CubeFitting>
  );
}

export default CubeResult;
