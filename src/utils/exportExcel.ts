import dayjs from 'dayjs';
import { GlobalData, TType } from '../atom/globalState';
import { rad2ang } from './utils';

export const export2excel = (data: (string | number)[][], filename: string) => {
  // 构造数据字符，换行需要用\r\n
  let CsvString = data
    .map((d) => {
      return d?.join?.(',');
    })
    .join('\r\n');
  // 加上 CSV 文件头标识
  CsvString =
    'data:application/vnd.ms-excel;charset=utf-8,\uFEFF' +
    encodeURIComponent(CsvString);
  // 通过创建a标签下载
  const link = document.createElement('a');
  link.href = CsvString;
  // 对下载的文件命名
  link.download = filename;
  // 模拟点击下载
  link.click();
  // 移除a标签
  link.remove();
};

const options = [
  { value: 0, label: '左面', pK: 'L' },
  { value: 1, label: '顶面', pK: 'T' },
  { value: 2, label: '右面', pK: 'R' },
  { value: 3, label: '底面', pK: 'B' },
  { value: 4, label: '左下面', pK: 'LB' },
  { value: 5, label: '左上面', pK: 'LT' },
  { value: 6, label: '右上面', pK: 'RT' },
  { value: 7, label: '右下面', pK: 'RB' },
].reduce((acc, cur) => {
  return {
    ...acc,
    [`m${cur.value}`]: cur.label,
  };
}, {});
export const transformJSON2Excel = (data: GlobalData, type = false) => {
  console.log('%c Line:42 🍪 data', 'color:#b03734', data);
  const csvData = [];

  const getDatas = (arr, title: string = '') => {
    const x = ['x'],
      y = ['y'],
      z = ['z'],
      label = [title];

    arr?.forEach?.((item) => {
      label.push(`${item.label}${item.key}`);
      x.push(item.x);
      y.push(item.y);
      z.push(item.z);
    });
    csvData.push([], label, x, y, z);
  };

  if (data.centerPoint) {
    getDatas([data.centerPoint], '中心点');
  }

  if (data?.triPoints?.length > 0) {
    const x = ['x'],
      y = ['y'],
      z = ['z'],
      label = ['圆周点'];

    data?.triPoints?.forEach?.((item: any) => {
      label.push(`${item.label}${item.key}`);
      x.push(item.x);
      y.push(item.y);
      z.push(item.z);
    });
    csvData.push([], label, x, y, z);
  }

  if (data?.mPoints?.length > 0) {
    const x = ['x'],
      y = ['y'],
      z = ['z'],
      label = ['拟合采集点'];

    data?.mPoints?.forEach?.((item: any) => {
      label.push(`${item.label}${item.key}`);
      x.push(item.x);
      y.push(item.y);
      z.push(item.z);
    });
    csvData.push([], label, x, y, z);
  }

  if (data.type === TType.cycle) {
    if (data.calulateRes.mTaon)
      csvData.push(getDatas(data.calulateRes.mTaon, 'mTaon'));
    if (data.calulateRes.center)
      csvData.push(getDatas(data.calulateRes.center, 'center'));

    csvData.push([  ['声道角', data.sdj]]);
  }

  if (data.type === 'cube' && data?.MxPoints) {
    Object.keys(data?.MxPoints)?.forEach?.((k) => {
      getDatas(data?.MxPoints?.[k], options[k]);
    });
  }

  const againTable =
    data.type === 'cube' ? data?.cubeAgainTable : data?.cylinderAgainTable;

  if (againTable?.length > 0) {
    const label = ['声道采集点'],
      x = ['x'],
      y = ['y'],
      z = ['z'];

    againTable?.forEach?.((item) => {
      [item.p1, item.p2].forEach?.((p) => {
        if (p) {
          label.push(`${p.label}${p.key}`);
          x.push(p.x);
          y.push(p.y);
          z.push(p.z);
        }
      });
    });
    csvData.push([], label, x, y, z);
  }

  if (data?.firstPoints?.length > 0) {
    const x = ['x'],
      y = ['y'],
      z = ['z'],
      label = ['边界点'];

    data?.firstPoints?.forEach?.((item: any) => {
      label.push(`${item.label}${item.key}`);
      x.push(item.x);
      y.push(item.y);
      z.push(item.z);
    });
    csvData.push([], label, x, y, z);
  }

  if (type) {
    return csvData;
  } else {
    export2excel(csvData, '测试excel.csv');
  }
};

const tableRender = (
  columns: { title: string; render: (row) => string | number }[],
  data: any[]
) => {
  const csvData: any[] = [];
  csvData.push(columns?.map((item) => item.title));
  data?.forEach?.((row) => {
    csvData.push(columns?.map((item) => item.render(row)));
  });

  return csvData;
};

const exportCylinder = (data: GlobalData) => {
  const csvData: any[] = [['管道复测']];

  csvData.push([], ['声道面', data.sdm?.join(',')]);

  csvData.push([], ['声道分布', data.sdfb]);

  csvData.push([], ['管道半径', data.calulateRes?.R]);

  csvData.push([], ['复测结果']);

  const tableData = tableRender(
    [
      { title: '声道面', render: (row) => row.sdm },
      { title: '声道', render: (row) => `第${row.i}声道` },
      {
        title: '下游换能器x',
        render: (row) => row?.p1?.x,
      },
      {
        title: '下游换能器y',
        render: (row) => row?.p1?.y,
      },
      {
        title: '下游换能器z',
        render: (row) => row?.p1?.z,
      },
      {
        title: '上游换能器x',
        render: (row) => row?.p2?.x,
      },
      {
        title: '上游换能器y',
        render: (row) => row?.p2?.y,
      },
      {
        title: '上游换能器z',
        render: (row) => row?.p2?.z,
      },
      { title: '声道长', render: (row) => row.sdc },
      { title: '声道角', render: (row) =>  rad2ang(row.sdj) },
      { title: 'LT偏移', render: (row) => row.ltOffset },
      {
        title: '声道相对高度',
        render: (row) => data?.calulateRes?.R * row.sdH,
      },
      { title: '高斯-雅克比', render: (row) => row.Wquanzhong3 },
      { title: '圆形优化法', render: (row) => row.Wquanzhong4 },
    ],
    data.cylinderAgainTable
  );

  csvData.push(...tableData);

  return csvData;
};

const exportCube = (data: GlobalData) => {
  const csvData: any[] = [['方涵复测']];

  csvData.push([], ['声道面', data.sdm?.join(',')]);

  csvData.push([], ['声道分布', data.sdfb]);

  csvData.push([], ['方涵宽度', data?.cubeResult?.b]);

  csvData.push([], ['方涵高度', data?.cubeResult?.h]);

  csvData.push([], ['导角参数']);

  const djKey = [],
    djValue = [];
  data?.cubeResult?.LenDaoJiao?.forEach?.((value, index) => {
    djKey.push(`L${index + 1}`);
    djValue.push(value);
  });

  if (data?.cubeResult?.LenDaoJiao?.length > 0) {
    csvData.push(djKey, djValue);
  }

  csvData.push([], ['复测结果']);

  const tableData = tableRender(
    [
      { title: '声道面', render: (row) => row.sdm },
      { title: '声道', render: (row) => `第${row.i}声道` },
      {
        title: '下游换能器x',
        render: (row) => row?.p1?.x,
      },
      {
        title: '下游换能器y',
        render: (row) => row?.p1?.y,
      },
      {
        title: '下游换能器z',
        render: (row) => row?.p1?.z,
      },
      {
        title: '上游换能器x',
        render: (row) => row?.p2?.x,
      },
      {
        title: '上游换能器y',
        render: (row) => row?.p2?.y,
      },
      {
        title: '上游换能器z',
        render: (row) => row?.p2?.z,
      },

      { title: '声道长', render: (row) => row.sdc },
      { title: '声道角', render: (row) => rad2ang(row.sdj) },
      { title: 'LT偏移', render: (row) => row.ltOffset },
      {
        title: '声道相对高度',
        render: (row) => data?.cubeResult?.h * row.sdH,
      },
      { title: '高斯-勒让德', render: (row) => row.Wquanzhong3 },
      { title: '矩形优化', render: (row) => row.Wquanzhong4 },
    ],
    data.cubeAgainTable
  );

  csvData.push(...tableData);

  return csvData;
};

export const exportExcel = (data: GlobalData) => {
  const detailData = transformJSON2Excel(data, true);
  if (data.type === TType.cube) {
    const excelData = exportCube(data);
    console.log('%c Line:209 🥪 excelData', 'color:#3f7cff', excelData);

    export2excel(
      [...excelData, [], [], [], [['详情数据']], ...detailData],
      `方涵复测${dayjs().format('_YYYY_MM_DD')}.csv`
    );
  } else {
    const excelData = exportCylinder(data);
    export2excel(
      [...excelData, [], [], [], [['详情数据']], ...detailData],
      `管道复测${dayjs().format('_YYYY_MM_DD')}.csv`
    );
  }
};
