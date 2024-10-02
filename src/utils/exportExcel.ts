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

  if (data?.cylinderAgainTable?.length > 0) {
    const label = ["复测采集点"],
      x = ["x"],
      y = ["y"],
      z = ["z"];

    data?.cylinderAgainTable.forEach((item) => {
      [item.p1, item.p2].forEach((p) => {
        label.push(`${p.label}${p.key}`);
        x.push(p.x);
        y.push(p.y);
        z.push(p.z);
      });
    });
    csvData.push([], label, x, y, z);
  }

  export2excel(csvData);
};
