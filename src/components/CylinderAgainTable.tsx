import {
  CheckCircleOutlined,
  CloseCircleOutlined,
  SettingOutlined,
} from "@ant-design/icons";
import { InputNumber, Table, Tooltip } from "antd";
import { useRecoilState, useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import { shengLuJiao2Ang } from "../utils/utils";
import { useEffect, useRef } from "react";

export default function CylinderAgainTable(props) {
  console.log("%c Line:49 🍬 props", "color:#fca650", props);
  const sdfbPreRef = useRef<any>();
  const [data, setData] = useRecoilState(Data);

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
                米
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
      dataIndex: "tOff11",
      key: "tOff",
      align: "center",
    },
  ];

  useEffect(() => {
    if (
      (typeof data?.resultTable?.[0]?.ang !== "number" &&
        typeof data.sdfb === "number") ||
      data.sdfb !== sdfbPreRef.current
    ) {
      const plant = shengLuJiao2Ang(data.sdfb).map((ang) => {
        return { ang, a: 0.015, tOff: 0, rOff: 0 };
      });

      const resultTable: any = [];

      data.sdm?.forEach?.((m) => {
        plant.forEach((item, i) => {
          resultTable.push({ ...item, sdm: m, i: i + 1 });
        });
      });

      setData((d) => {
        return {
          ...d,
          resultTable,
        };
      });
    }
    sdfbPreRef.current = data.sdfb;
  }, [data.sdfb, data?.resultTable?.[0]?.ang, data.sdm]);

  return (
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
  );
}
