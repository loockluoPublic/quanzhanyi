import CylinderModule from "../components/Module3D";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { Checkbox, InputNumber, message, Table, Tooltip } from "antd";
import { SettingOutlined } from "@ant-design/icons";
import { Point } from "../components/Point";
import { useEffect, useRef } from "react";
import Select, { DefaultOptionType } from "antd/es/select";
import {
  CalculatAAndBPoints,
  offsetCalculate,
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

  const sdfbPreRef = useRef<any>("");

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
        return <>{v?.toFixed?.(4) ?? "--"}米</>;
      },
    },
    {
      title: "轴向偏移",
      dataIndex: "tOff",
      key: "tOff",
      align: "center",
      render: (v) => {
        return <>{v?.toFixed?.(4) ?? "--"}米</>;
      },
    },
    {
      title: "安装点",
      dataIndex: "points",
      key: "points",
      align: "center",
      render: (v) => {
        return (
          <div className="q-flex q-justify-center">
            {v?.map?.((p) => (
              <Point
                className={`${p.key % 2 === 0 ? "q-ml-2" : ""}`}
                key={`${p.label}${p.key}`}
                p={p}
              />
            ))}
          </div>
        );
      },
    },
  ];

  const updateOffset2 = (_data, _resultTable) => {
    const paramAng =
      _resultTable?.map?.((item) => {
        return item.ang;
      }) ?? [];
    const paramA =
      _resultTable?.map?.((item) => {
        return item.a;
      }) ?? [];

    if (!paramAng || !paramA) return _resultTable;
    if (!(_resultTable?.length > 0)) return _resultTable;
    if (!_data?.calulateRes?.R) return _resultTable;

    const res = offsetCalculate(
      _data.calulateRes.R,
      _data.sdj,
      paramAng,
      paramA
    ) ?? [[], []];

    return _resultTable.map((item, i) => {
      const newItem = {
        ...item,
        rOff: res[i][0],
        tOff: res[i][1],
      };

      return newItem;
    });
  };

  const key = `${data.sdfb}${data.sdm?.join("")}`;
  const init = () => {
    if (
      sdfbPreRef.current === "" &&
      data.resultTable?.length > 0 &&
      data.resultTable[0].tOff !== undefined
    )
      return;

    if (key !== sdfbPreRef.current) {
      const plant = shengLuJiao2Ang(data.sdfb).map((ang) => {
        return { ang, a: 0.015 };
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
          resultTable: updateOffset2(data, resultTable),
        };
      });
    }
  };

  useEffect(() => {
    init();
    sdfbPreRef.current = key;
  }, [key]);

  const paramAng =
    data.resultTable?.map?.((item) => {
      return item.ang;
    }) ?? [];
  const paramA =
    data.resultTable?.map?.((item) => {
      return item.a;
    }) ?? [];

  useEffect(() => {
    setData((d) => {
      return {
        ...d,
        key: Math.random(),
        resultTable: updateOffset2(d, d.resultTable),
      };
    });
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

    let tableData = data.resultTable;
    if (tOff[0] === undefined) {
      tableData = updateOffset2(data, data.resultTable);
    }
    CalculatAAndBPoints(
      calulateRes.mTaon,
      calulateRes.center,
      calulateRes.R,
      data.centerPoint,
      data.sdj,
      tableData
    ).then((AB) => {
      const resultTable = tableData.map((row, i) => {
        console.log("%c Line:264 🥛 sdm,i", "color:#4fff4B", row.sdm, row.i);
        return { ...row, points: AB?.[i] };
      });

      setData((d) => {
        return {
          ...d,
          resultTable,
        };
      });
    });
  };

  useEffect(() => {
    if (data.centerPoint) calcPoint();
    else {
      message.warning("请采集AB面交点");
    }
  }, [data.centerPoint, data.key]);

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
            value={data.sdj}
            addonAfter="度"
            min={0}
            max={90}
            onChange={(sdj) => {
              setData({
                ...data,
                sdj,
              });
            }}
          />
        </span>
      </div>
      <div className="q-my-1">
        <span>
          声道面：
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
            before={() => {
              CustomVector3.setPublicInfo("AB", 0);
            }}
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
          dataSource={data.resultTable ?? []}
          columns={columns}
          pagination={{ hideOnSinglePage: true }}
        />
      </div>
    </div>
  );

  const points = data?.resultTable?.reduce((acc, cur) => {
    acc.push(...(cur?.points ?? []));
    return [...acc, ...(cur?.points ?? [])];
  }, []);

  return (
    <CylinderModule
      component={comp}
      firstPoints={data.firstPoints}
      calulateRes={data.calulateRes}
      sdm={data.sdm}
      points={points}
    ></CylinderModule>
  );
}

export default CylinderFit;
