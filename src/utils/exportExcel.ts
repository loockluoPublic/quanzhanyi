export const export2excel = (data: (string | number)[][]) => {
  // 构造数据字符，换行需要用\r\n
  let CsvString = data.map((data) => data.join(",")).join("\r\n");
  // 加上 CSV 文件头标识
  CsvString =
    "data:application/vnd.ms-excel;charset=utf-8,\uFEFF" +
    encodeURIComponent(CsvString);
  // 通过创建a标签下载
  const link = document.createElement("a");
  link.href = CsvString;
  // 对下载的文件命名
  link.download = `e.csv`;
  // 模拟点击下载
  link.click();
  // 移除a标签
  link.remove();
};
const getDatas = (arr, res, title: string) => {
  const x = ["x"],
    y = ["y"],
    z = ["z"],
    label = [title];

  arr.forEach((item) => {
    label.push(`${item.label}${item.key}`);
    x.push(item.x);
    y.push(item.y);
    z.push(item.z);
  });
  res.push([], label, x, y, z);
};

const options = [
  { value: 0, label: "左面", pK: "L" },
  { value: 1, label: "顶面", pK: "T" },
  { value: 2, label: "右面", pK: "R" },
  { value: 3, label: "底面", pK: "B" },
  { value: 4, label: "左下面", pK: "LB" },
  { value: 5, label: "左上面", pK: "LT" },
  { value: 6, label: "右上面", pK: "RT" },
  { value: 7, label: "右下面", pK: "RB" },
].reduce((acc, cur) => {
  return {
    ...acc,
    [`m${cur.value}`]: cur.label,
  };
}, {});
export const transformJSON2Excel = (data: any) => {
  const csvData = [];
  if (data?.firstPoints?.[0] && data?.firstPoints?.[1]) {
    csvData.push(
      ...data?.firstPoints?.map((item) => [item.label, item.x, item.y, item.z])
    );
  }

  if (data?.direct?.length > 0) {
    csvData.push(["轴线方向"], [data?.direct?.[0], data?.direct?.[1]]);
  }

  if (data?.mPoints?.length > 0) {
    const x = ["x"],
      y = ["y"],
      z = ["z"],
      label = ["拟合采集点"];

    data?.mPoints.forEach((item) => {
      label.push(`${item.label}${item.key}`);
      x.push(item.x);
      y.push(item.y);
      z.push(item.z);
    });
    csvData.push([], label, x, y, z);
  }

  if (data.type === "cube" && data?.MxPoints) {
    Object.keys(data?.MxPoints).forEach((k) => {
      getDatas(data?.MxPoints?.[k], csvData, options[k]);
    });
  }

  const againTable =
    data.type === "cube" ? data?.cubeAgainTable : data?.cylinderAgainTable;

  if (againTable?.length > 0) {
    const label = ["复测采集点"],
      x = ["x"],
      y = ["y"],
      z = ["z"];

    againTable.forEach((item) => {
      [item.p1, item.p2].forEach((p) => {
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

  export2excel(csvData);
};
