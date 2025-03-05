import CubeFitting from '../components/Module3D/CubeModule';
import { useRecoilState } from 'recoil';
import { Data } from '../atom/globalState';
import { Checkbox, InputNumber, message, Table, Tooltip } from 'antd';
import { SettingOutlined } from '@ant-design/icons';
import { Point } from '../components/Point';
import { useEffect, useRef } from 'react';
import Select, { DefaultOptionType } from 'antd/es/select';
import {
  CalculatAAndBPoints4,
  CalculatAAndBPoints8,
  cubeTOff,
  sdj_n2v,
  sdj_v2n,
  shengDaoGaoDu,
} from '../utils/utils';
import PointsVector3 from '../components/PointVector3';
import { CustomVector3 } from '../class/CustomVector3';

export const SDFBOptions = (() => {
  const options: DefaultOptionType[] = [];
  for (let index = 2; index <= 10; index++) {
    options.push({ value: index, label: `${index}声道` });
  }
  return options;
})();

export const sdmOptions = [
  { label: '声道面A', value: 'A' },
  { label: '声道面B', value: 'B' },
];
const defaultA = 0.015;

enum EActions {
  sdfb,
  sdj,
  sdm,
  center,
  h,
  a,
  cubeTable,
  setAll,
}

/**
 * 初始化表格
 * @param data
 * @returns
 */
const init = (data) => {
  const sdgd = shengDaoGaoDu(data.sdfb);

  const cubeTable: any = [];

  data.sdm?.forEach?.((m, p) => {
    sdgd.forEach((ti, i) => {
      const h = Number(ti.toFixed(6));
      cubeTable.push({
        ...ti,
        sdm: m,
        i: i + 1,
        updateIndex: p * sdgd.length + i,
        h,
        a: defaultA,
        tOff: cubeTOff(defaultA, data.sdj),
      });
    });
  });

  console.log('%c Line:67 🥔 cubeTable', 'color:#b03734', cubeTable);
  return cubeTable;
};

/**
 * 计算安装点
 * @param data
 * @returns
 */
const calcPoint = (data): any[] | undefined => {
  console.log('%c Line:127 🍡', 'color:#e41a6a');

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

  if (!data.centerPoint) {
    message.error('请采集中心点');
    return;
  }

  if (!data.cubeResult) {
    message.error('缺少拟合参数，请退回上一步拟合');
    return;
  }

  if (tOff.length > 0 && Ti.length > 0) {
    try {
      let points;

      if (data.hasChamfer) {
        let MxPortsArr: CustomVector3[][] = [];
        for (let i = 0; i < 9; i++) {
          const key = `m${i}`;
          if (i < 4) {
            if (data.MxPoints[key]?.length > 4) {
              MxPortsArr.push(data.MxPoints[key]);
            } else {
              message.error(`${key}面采集点少于4个，请补充采集点`);
              return;
            }
          } else {
            MxPortsArr.push(data.MxPoints[key]);
          }
        }

        const [l, t, r, b, lb = [], lt = [], rt = [], rb = []] = MxPortsArr;

        MxPortsArr = [l, lt, t, rt, r, rb, b, lb];

        points = CalculatAAndBPoints8(data, MxPortsArr);
      } else {
        points = CalculatAAndBPoints4(data);
      }

      return data?.cubeTable?.map((item, i) => {
        return {
          ...item,
          points: points[i],
        };
      });
    } catch (error) {
      console.log(
        '%c Line:108 🌰 error',
        'color:#ed9ec7',
        data.cubeResult,
        error
      );
    }
  }
};

/**
 * 计算轴向偏移
 * @param data
 * @returns
 */
const updateOffset = (data) => {
  if (!(data.cubeTable?.length > 0)) return;

  const tableData = data.cubeTable.map((item) => {
    const newItem = {
      ...item,
      tOff: cubeTOff(item.a, data.sdj),
    };

    return newItem;
  });

  return tableData;
};

function CubeResult() {
  const [data, setData] = useRecoilState(Data);

  const onChange = (v: number, i: number, key: string) => {
    console.log('%c Line:153 🌮 v', 'color:#3f7cff', v, i, key);
    const cubeTable = data.cubeTable.map((item, index) => {
      const newItem = {
        ...item,
      };
      if (index === i) {
        newItem[key] = v;
        if (key === 'a') {
          newItem.tOff = cubeTOff(newItem.a, data.sdj);
        }
      }
      return newItem;
    });

    dispatch(EActions.cubeTable, cubeTable);
  };

  const dispatch = (type: EActions, payload: any) => {
    let newData = { ...data };
    switch (type) {
      case EActions.sdfb:
        newData.sdfb = payload;
        newData.cubeTable = init(newData);
        if (newData.centerPoint) {
          newData.cubeTable = updateOffset(newData);
          newData.cubeTable = calcPoint(newData);
        }

        break;
      case EActions.sdm:
        newData.sdm = payload;
        newData.cubeTable = init(newData);
        if (newData.centerPoint) {
          newData.cubeTable = updateOffset(newData);
          newData.cubeTable = calcPoint(newData);
        }

        break;
      case EActions.sdj:
        newData.sdj = payload;
        newData.cubeTable = updateOffset(newData);
        newData.cubeTable = calcPoint(newData);
        break;
      case EActions.cubeTable:
        newData.cubeTable = payload;
        newData.cubeTable = updateOffset(newData);
        newData.cubeTable = calcPoint(newData);
        break;
      case EActions.center:
        newData.centerPoint = payload;
        newData.cubeTable = calcPoint(newData);
        break;

      case EActions.setAll:
        const a = newData.cubeTable[payload].a;
        newData.cubeTable = newData.cubeTable.map((item) => {
          const newItem = {
            ...item,
            a,
          };
          return newItem;
        });
        newData.cubeTable = updateOffset(newData);
        newData.cubeTable = calcPoint(newData);
        break;
    }

    setData(newData);
  };

  useEffect(() => {
    if (!(data.cubeTable?.length > 0)) {
      dispatch(EActions.sdm, ['A', 'B']);
    }
  }, []);

  const columns: any = [
    {
      title: '声道面',
      dataIndex: 'sdm',
      align: 'center',
      key: 'sdm',
    },
    {
      title: '声道',
      dataIndex: 'i',
      align: 'center',
      key: 'i',
      render: (i, _i) => {
        return <>第{i}声道</>;
      },
    },
    {
      title: '声道相对高度',
      dataIndex: 'h',
      key: 'h',
      align: 'center',
      render: (v, row) => {
        return (
          <InputNumber
            step={0.1}
            value={v}
            max={1}
            min={-1}
            onChange={(v) => onChange(v, row.updateIndex, 'h')}
          />
        );
      },
    },
    {
      title: '换能器凸出',
      dataIndex: 'a',
      key: 'a',
      align: 'center',
      render: (v, row) => {
        return (
          <InputNumber
            step={0.01}
            value={v}
            onChange={(v) => onChange(v, row.updateIndex, 'a')}
            addonAfter={
              <div>
                米
                <Tooltip title='应用到全部' className='q-cursor-pointer'>
                  <SettingOutlined
                    onClick={() => dispatch(EActions.setAll, row.updateIndex)}
                  />
                </Tooltip>
              </div>
            }
          />
        );
      },
    },

    {
      title: '轴向偏移',
      dataIndex: 'tOff',
      key: 'tOff',
      align: 'center',
      render: (v) => {
        return <>{v?.toFixed?.(3) ?? '--'}米</>;
      },
    },
    {
      title: '斜面偏移',
      dataIndex: 'rOff',
      key: 'rOff',
      align: 'center',
      render: (_, row) => {
        return row?.points?.map?.((p, i) => {
          return (
            <span className={`${i % 2 === 1 ? 'q-ml-2' : ''}`}>
              {p?.difference?.toFixed?.(3) ?? '--'}米
            </span>
          );
        });
      },
    },

    {
      title: '安装点',
      dataIndex: 'points',
      key: 'points',
      align: 'center',
      render: (v) => {
        return (
          <div className='q-flex q-justify-center'>
            {v?.map?.((p) => (
              <Point
                className={`${p.key % 2 === 0 ? 'q-ml-2' : ''}`}
                key={`${p.label}${p.key}`}
                p={p}
              />
            ))}
          </div>
        );
      },
    },
  ].filter((item) => {
    return (!data.hasChamfer && item.key !== 'rOff') || data.hasChamfer;
  });

  const comp = (
    <div>
      <h3>声道参数：</h3>
      <div>
        <span>
          声道分布：
          <Select
            value={data.sdfb}
            className=' !q-w-32'
            options={SDFBOptions}
            onChange={(sdfb) => {
              dispatch(EActions.sdfb, sdfb);
            }}
          />
        </span>
        <span className='q-ml-8'>
          声道角：
          <InputNumber
            value={sdj_n2v(data.sdj)}
            addonAfter='度'
            min={0}
            max={90}
            onChange={(sdj: number) => {
              dispatch(EActions.sdj, sdj_v2n(sdj));
            }}
          />
        </span>
      </div>
      <div>
        <span>
          声道面：{' '}
          <Checkbox.Group
            value={data.sdm}
            options={sdmOptions}
            onChange={(sdm: ('A' | 'B')[]) => {
              dispatch(EActions.sdm, sdm);
            }}
          ></Checkbox.Group>
        </span>
        <span className='q-ml-8'>
          中心点：
          <PointsVector3
            hideLabel
            className='!q-inline-flex'
            value={data.centerPoint as CustomVector3}
            before={() => {
              CustomVector3.setPublicInfo('AB', 0);
            }}
            onChange={(v) => {
              dispatch(EActions.center, v);
            }}
          />
        </span>
      </div>
      <h3 className='q-mt-2 border-top q-pt-2'>安装点详情：</h3>
      <div>
        <Table
          size='small'
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

  const points = data?.cubeTable?.reduce((acc, cur) => {
    acc.push(...(cur?.points ?? []));
    return [...acc, ...(cur?.points ?? [])];
  }, []);

  return (
    <CubeFitting
      component={comp}
      firstPoints={data.firstPoints}
      trianglePoints={data.trianglePoints}
      points={points}
      sdm={data.sdm}
    ></CubeFitting>
  );
}

export default CubeResult;
