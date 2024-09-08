import CylinderModule from "../components/Module3D";
import { useRecoilState } from "recoil";
import { Data, getInitCylinderAgainTable } from "../atom/globalState";
import { Checkbox, InputNumber, message, Table, Tooltip } from "antd";
import { SettingOutlined } from "@ant-design/icons";
import { Point } from "./CalculateResultPoints";
import React, { useEffect, useRef } from "react";
import Select, { DefaultOptionType } from "antd/es/select";
import {
  CalculatAAndBPoints,
  offsetCalculate,
  sdj_n2v,
  sdj_v2n,
  shengLuJiao2Ang,
} from "../utils/utils";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";

const SDFBOptions = (() => {
  const options: DefaultOptionType[] = [];
  for (let index = 2; index <= 10; index++) {
    options.push({ value: index, label: `${index}声道` });
  }
  return options;
})();

const sdmOptions = [
  { label: "声道面A", value: "A" },
  { label: "声道面B", value: "B" },
];

function CylinderFit() {
  const [data, setData] = useRecoilState(Data);

  const sdfbPreRef = useRef<any>();

  const onChange = (v: number, i: number, key: string) => {
    const tableData = data.resultTable.map((item, index) => {
      const newItem = {
        ...item,
      };
      if (index === i) {
        newItem[key] = v;
      }
      return newItem;
    });
    setData((d) => {
      return {
        ...d,
        resultTable: tableData,
      };
    });
  };

  const setA = (i: number) => {
    const a = data.resultTable[i].a;
    const tableData = data.resultTable.map((item) => {
      const newItem = {
        ...item,
        a,
      };

      return newItem;
    });
    setData((d) => {
      return {
        ...d,
        resultTable: tableData,
      };
    });
  };

  const columns: any = [
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
                </Tooltip>{" "}
              </div>
            }
          />
        );
      },
    },
    {
      title: "声道高度角",
      dataIndex: "ang",
      key: "ang",
      align: "center",
      render: (v, _, i) => {
        return (
          <InputNumber
            value={v}
            onChange={(v) => onChange(v, i, "ang")}
            addonAfter={`度`}
          />
        );
      },
    },
    {
      title: "圆周偏移",
      dataIndex: "rOff",
      key: "rOff",
      align: "center",
      render: (v) => {
        return <>{v?.toFixed?.(3) ?? "--"}米</>;
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
      title: "安装点",
      width: 100,
      dataIndex: "AB",
      key: "AB",
      align: "center",
      render: (v) => {
        console.log("%c Line:148 🥖 v", "color:#3f7cff", v);
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
  ];

  useEffect(() => {
    if (
      (typeof data?.resultTable?.[0]?.ang !== "number" &&
        typeof data.sdfb === "number") ||
      data.sdfb !== sdfbPreRef.current
    ) {
      const resultTable = shengLuJiao2Ang(data.sdfb).map((ang) => {
        return { ang, a: 0.015, tOff: 0, rOff: 0 };
      });

      setData((d) => {
        return {
          ...d,
          resultTable,
        };
      });
    }
    sdfbPreRef.current = data.sdfb;
  }, [data.sdfb, data?.resultTable?.[0]?.ang]);

  const paramAng =
    data.resultTable?.map?.((item) => {
      return item.ang;
    }) ?? [];
  const paramA =
    data.resultTable?.map?.((item) => {
      return item.a;
    }) ?? [];

  const updateOffset = () => {
    if (!data.centerPoint || !paramAng || !paramA) return;
    if (!(data.resultTable?.length > 0)) return;

    const res = offsetCalculate(
      data.calulateRes.R,
      data.sdj,
      paramAng,
      paramA
    ) ?? [[], []];

    const tableData = data.resultTable.map((item, i) => {
      const newItem = {
        ...item,
        rOff: res[i][0],
        tOff: res[i][1],
      };

      return newItem;
    });
    setData((d) => {
      return {
        ...d,
        resultTable: tableData,
      };
    });
  };

  useEffect(() => {
    updateOffset();
  }, [[...paramAng, ...paramA, data.sdj].join(",")]);

  const tOff =
    data.resultTable?.map?.((item) => {
      return item.tOff;
    }) ?? [];

  const rOff =
    data.resultTable?.map?.((item) => {
      return item.rOff;
    }) ?? [];

  const calcPoint = () => {
    const { calulateRes } = data;

    if (!calulateRes) {
      message.error("缺少拟合参数，请退回上一步");
      return;
    }

    if (tOff.length > 0) {
      CalculatAAndBPoints(
        calulateRes.mTaon,
        calulateRes.center,
        calulateRes.R,
        data.centerPoint,
        data.sdj,
        paramAng,
        tOff,
        rOff
      ).then((AB) => {
        setData((d) => {
          return {
            ...d,
            AB,
          };
        });
      });
    }
  };

  useEffect(() => {
    if (data.centerPoint) calcPoint();
  }, [[...rOff, ...tOff].join(","), data.centerPoint]);

  useEffect(() => {
    setData((d) => ({
      ...d,
      cylinderAgainTable: getInitCylinderAgainTable(data.sdfb, data.sdm) as any,
    }));
  }, [data.sdfb, data.sdm]);

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
                cylinderAgainTable: new Array(sdfb) as any,
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
            onChange={(sdj) => {
              setData({
                ...data,
                sdj: sdj_v2n(sdj),
              });
            }}
          />
        </span>
      </div>
      <div className="q-my-1">
        <span>
          声道面：{" "}
          <Checkbox.Group
            value={data.sdm}
            options={sdmOptions as any}
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
            data.resultTable?.map((item, i) => {
              return {
                ...item,
                key: i,
                AB: data.AB?.[i],
              };
            }) ?? []
          }
          columns={columns}
          pagination={{ hideOnSinglePage: true }}
        />
      </div>
    </div>
  );
  return (
    <CylinderModule
      component={comp}
      calulateRes={data.calulateRes}
      sdm={data.sdm}
      AB={data.AB}
    ></CylinderModule>
  );
}

export default CylinderFit;
