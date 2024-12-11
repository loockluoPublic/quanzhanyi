import { Upload } from "antd";
import { useRecoilState } from "recoil";
import { Data, Mode, Step } from "../atom/globalState";
import { loadFile } from "../utils/utils";

const compareSdcs = (data: any, old: any) => {
  return data.sdm?.join("") === old.sdm?.join("") && data.sdfb === old.sdfb;
};

function AntdFileReader() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useRecoilState(Step);
  const [_, setMode] = useRecoilState(Mode);
  const handleFileChange = (file) => {
    const reader = new FileReader();
    reader.readAsText(file);
    reader.onload = () => {
      const importData = loadFile((reader.result as string) || "{}");
      (window as any).mock = true;
      setStep(1);
      setData(importData);
      setMode(importData.mode);
    
      if (!compareSdcs(data, importData)) {
        setTimeout(() => {
          setData(importData);
          if (step === 0) {
            setTimeout(() => {
              setStep(1);
            }, 200);
          }
        }, 100);
      }
    };
  };

  return (
    <Upload
      accept=".json"
      className=" q-inline-block"
      beforeUpload={handleFileChange} // 阻止自动上传
      showUploadList={false} // 隐藏上传列表
    >
      <div className="q-ml-4 q-text-white  q-cursor-pointer ">导入</div>
    </Upload>
  );
}

export default AntdFileReader;
