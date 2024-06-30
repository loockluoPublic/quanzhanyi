import React, { useState } from "react";
import { Upload, Button, message } from "antd";
import { UploadOutlined } from "@ant-design/icons";

function AntdFileReader() {
  //   const
  const [fileContent, setFileContent] = useState("");
  console.log("%c Line:7 🥤 fileContent", "color:#465975", fileContent);

  const handleFileChange = (file) => {
    const reader = new FileReader();
    reader.readAsText(file);
    reader.onload = () => {
      // 获取文件内容存进tempFile
      setFileContent(reader.result as string);
    };
  };

  return (
    <Upload
      beforeUpload={handleFileChange} // 阻止自动上传
      //   onChange={handleFileChange}
      showUploadList={false} // 隐藏上传列表
    >
      <Button icon={<UploadOutlined />}>上传文件</Button>
    </Upload>
  );
}

export default AntdFileReader;
