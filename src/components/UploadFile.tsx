import React, { useState } from "react";
import { Upload, Button, message } from "antd";
import { UploadOutlined } from "@ant-design/icons";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { loadFile } from "../utils/utils";

function AntdFileReader() {
  const [data, setData] = useRecoilState(Data);

  const handleFileChange = (file) => {
    const reader = new FileReader();
    reader.readAsText(file);
    reader.onload = () => {
      setData(loadFile((reader.result as string) || "{}"));
    };
  };

  return (
    <Upload
      beforeUpload={handleFileChange} // 阻止自动上传
      showUploadList={false} // 隐藏上传列表
    >
      <div className="q-ml-4 q-text-white  q-cursor-pointer">导入</div>
    </Upload>
  );
}

export default AntdFileReader;
