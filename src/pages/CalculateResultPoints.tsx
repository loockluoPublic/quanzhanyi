import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import {
  CalculatAAndBPoints,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  offsetCalculate,
  shengLuJiao2Ang,
} from "../utils/utils";
import { useEffect, useRef, useState } from "react";
import Module3D from "../components/Module3D";
import { Button, Form, InputNumber, Table, Tooltip } from "antd";
import BaseInfo from "../components/BaseInfo";
import { goToCV } from "../utils/commond";
import { SettingOutlined } from "@ant-design/icons";
const { Item } = Form;
/**
 * shengLuJiaoJiSuan(声道数)  ==>  10个角度
 *
 * offsetCalculate = (
  R: number,
  phi: number,
  ang: number[],
  a: number[]      插入深度，只是手动设置，手动全部设置
)  ==>  得到 偏移   [rof,tof]
 *
 */

const Point = (props) => {
  const v = props.p;
  if (typeof v?.x === "number")
    return (
      <div>
        ({v.x.toFixed(3)},{v.y.toFixed(3)},{v.z.toFixed(3)})
      </div>
    );

  return null;
};

const defaultA = 0.015;

export function CalculateResultPoints(props: { hideMode?: true }) {
  const [data, setData] = useRecoilState(Data);

  const sdfbPreRef = useRef();

  const [loading, setLoading] = useState(false);

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
      render: (v, _, i) => {
        return (
          <InputNumber
            value={v}
            onChange={(v) => onChange(v, i, "rOff")}
            addonAfter="米"
          />
        );
      },
    },
    {
      title: "轴向偏移",
      dataIndex: "tOff",
      key: "tOff",
      align: "center",
      render: (v, _, i) => {
        return (
          <InputNumber
            value={v}
            onChange={(v) => onChange(v, i, "tOff")}
            addonAfter="米"
          />
        );
      },
    },

    {
      title: "A面点",
      dataIndex: "bottomA",
      key: "bottomA",
      align: "center",
      render: (v) => {
        console.log("%c Line:148 🥖 v", "color:#3f7cff", v);
        return <Point p={v} />;
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
        return { ang, a: defaultA, tOff: 0, rOff: 0 };
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
  }, [[...paramAng, ...paramA].join(",")]);

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

    if (tOff.length > 0) {
      CalculatAAndBPoints(
        calulateRes.mTaon,
        calulateRes.center,
        calulateRes.R,
        data.centerPoint[0],
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
    calcPoint();
  }, [[...rOff, ...tOff].join(",")]);

  return (
    <Module3D
      loading={loading}
      height="500px"
      direct={data?.direct}
      {...data}
      mPoints={[]}
      component={
        <div className="q-flex-shrink-0 q-flex-grow-0 q-w-[800px]">
          <Button type="primary" loading={loading}>
            运行
          </Button>
          <div className="q-flex">
            <BaseInfo hideMode={props.hideMode} />
          </div>
          <div>
            <Table
              key={data.sdfb}
              dataSource={
                data.resultTable?.map((item, i) => {
                  console.log(
                    "%c Line:282 🍑 data.AB",
                    "color:#42b983",
                    data.AB
                  );
                  return {
                    ...item,
                    bottomA: data.AB?.bottomA?.[i],
                  };
                }) ?? []
              }
              columns={columns}
            ></Table>
          </div>
        </div>
      }
    ></Module3D>
  );
}
