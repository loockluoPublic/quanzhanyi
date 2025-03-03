import { Button, Checkbox, message, Select, Table } from 'antd';
import { useRecoilState } from 'recoil';
import { Data, getInitAgainTable } from '../atom/globalState';
import PointsVector3 from '../components/PointVector3';
import { CustomVector3 } from '../class/CustomVector3';
import { juXingFuCe, rad2ang } from '../utils/utils';
import { SDFBOptions, sdmOptions } from './CubeResult';
import { useEffect } from 'react';
import CubeFitting from '../components/Module3D/CubeModule';

export default function () {
  const [data, setData] = useRecoilState(Data);
  console.log('%c Line:7 🥃 data', 'color:#42b983', data);

  const width = data?.cubeResult?.b?.toFixed(4);
  const hight = data?.cubeResult?.h?.toFixed(4);

  const onChange = (v: CustomVector3, i: number, key: string) => {
    if (v.label === 'A') {
      v.color = 'red';
    } else if (v.label === 'B') {
      v.color = '#fab005';
    }
    const tableData: any =
      data.cubeAgainTable?.map?.((item) => {
        const newItem = {
          ...item,
        };
        if (item.i === i) {
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
      title: '下游换能器',
      dataIndex: 'p1',
      key: 'p1',
      align: 'center',
      render: (_v, row) => {
        console.log('%c Line:55 🍕 row', 'color:#2eafb0', row.i, 2 * row.i - 1);
        return (
          <PointsVector3
            value={_v}
            before={() => {
              const slnum =
                data.sdm?.length === 2 && row.sdm === 'B'
                  ? row.i - data.sdfb
                  : row.i;
              CustomVector3.setPublicInfo(row.sdm, 2 * slnum - 2);
            }}
            onChange={(v) => {
              onChange(v, row.i, 'p1');
            }}
          />
        );
      },
    },
    {
      title: '上游换能器',
      dataIndex: 'p2',
      key: 'p2',
      align: 'center',
      render: (_v, row) => {
        return (
          <PointsVector3
            before={() => {
              const slnum =
                data.sdm?.length === 2 && row.sdm === 'B'
                  ? row.i - data.sdfb
                  : row.i;
              CustomVector3.setPublicInfo(row.sdm, 2 * slnum - 1);
            }}
            value={_v}
            onChange={(v) => onChange(v, row.i, 'p2')}
          />
        );
      },
    },
    {
      title: '声道长',
      dataIndex: 'sdc',
      key: 'sdc',
      align: 'right',
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },
    {
      title: '声道角',
      dataIndex: 'sdj',
      key: 'sdj',
      align: 'right',
      render: (v) => {
        return typeof v === 'number' ? rad2ang(v, true)?.toFixed(3) : '';
      },
    },
    {
      title: 'LT偏移',
      dataIndex: 'ltOffset',
      key: 'ltOffset',
      align: 'right',
      render: (v) => {
        return v?.toFixed?.(4);
      },
    },
    {
      title: '声道相对高度',
      dataIndex: 'sdH',
      key: 'sdH',
      align: 'right',
      render: (v) => {
        if (isNaN((data?.cubeResult?.h / 2) * v)) return '';
        return `${((data?.cubeResult?.h / 2) * v)?.toFixed?.(
          4
        )}米 ${v?.toFixed?.(4)} `;
      },
    },
    {
      title: '高斯-勒让德',
      dataIndex: 'Wquanzhong3',
      key: 'Wquanzhong3',
      align: 'right',
      render: (v) => {
        return v?.toFixed?.(6);
      },
    },

    {
      title: '矩形优化',
      dataIndex: 'Wquanzhong4',
      key: 'Wquanzhong4',
      align: 'right',
      render: (v) => {
        return v?.toFixed?.(6);
      },
    },
  ].filter((item) => item.key !== data.sfType);

  const calcFuCe = () => {
    if (!data.cubeResult) {
      message.warning('缺少拟合参数，请返回上一步');
      return;
    }

    for (const item of data.cubeAgainTable) {
      if (!item.p1 || !item.p2) {
        message.warning(`第${(item as any).i}声道缺少复测点，请采集`);
        return;
      }
    }

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

  const comp = (
    <div>
      <h3>参数设置：</h3>
      <div className='q-flex q-justify-between'>
        <div>
          <span>
            声道面：
            <Checkbox.Group
              value={data.sdm}
              options={sdmOptions}
              onChange={(sdm: ('A' | 'B')[]) => {
                setData({
                  ...data,
                  sdm,
                });
              }}
            ></Checkbox.Group>
          </span>
          <span className='q-ml-8'>
            声道分布：
            <Select
              value={data.sdfb}
              className=' !q-w-32'
              options={SDFBOptions}
              onChange={(sdfb) => {
                setData({
                  ...data,
                  sdfb,
                });
              }}
            />
          </span>
          <span className='q-ml-8'>
            积分方法：
            <Select
              value={data.sfType}
              className=' !q-w-30'
              options={[
                { label: '高斯-勒让德', value: 'Wquanzhong4' },
                { label: '矩形优化法', value: 'Wquanzhong3' },
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
      <div className=' q-my-4'>
        <span>
          方涵宽度：
          {width ?? '--'} 米
        </span>
        <span className='q-ml-8'>方涵高度：{hight ?? '--'} 米</span>
        <span className='q-ml-8'>
          声道配置： {data.sdm.length}E{data.sdfb * data.sdm.length}P
        </span>
      </div>
      <h3 className='border-top q-pt-4'>
        复测结果：
        <div className='q-float-right q-mb-2'>
          <Button type='primary' onClick={calcFuCe}>
            计算
          </Button>
        </div>
      </h3>
      <Table
        rowKey={'id'}
        columns={columns}
        dataSource={data.cubeAgainTable}
        pagination={{
          pageSize: 10,
          hideOnSinglePage: true,
          showSizeChanger: false,
        }}
        size='small'
      />
    </div>
  );

  const mPoints = data.cubeAgainTable?.reduce((acc, cur) => {
    return [...acc, cur.p1, cur.p2];
  }, []);
  // const pA = [],
  //   pB = [];

  // data.cubeAgainTable?.forEach((item: any) => {
  //   item.p1 && mPoints.push(item.p1);
  //   item.p2 && mPoints.push(item.p2);
  //   if (item.sdm === "A") {
  //     pA.push(item.p1, item.p2);
  //   } else {
  //     pB.push(item.p1, item.p2);
  //   }
  // });

  return (
    <CubeFitting
      component={comp}
      firstPoints={data.firstPoints}
      trianglePoints={data.trianglePoints}
      points={mPoints}
      sdm={data.sdm}
    ></CubeFitting>
  );
}
