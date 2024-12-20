import React, { PropsWithChildren } from "react";
import type { MenuProps } from "antd";
import { ConfigProvider, Layout, Menu, Switch } from "antd";
import { BrowserRouter as Router, Routes } from "react-router-dom";
import { Data, Mode, Step, TMode, TType } from "./atom/globalState";
import { useRecoilState, useRecoilValue } from "recoil";
import { downLoadFile } from "./utils/utils";
import UploadFile from "./components/UploadFile";
import zhCN from "antd/es/locale/zh_CN";
import { exportExcel, transformJSON2Excel } from "./utils/exportExcel";

const { Header, Content } = Layout;

const items1: MenuProps["items"] = [
  {
    key: TType.cycle,
    label: `管道`,
  },
  {
    key: TType.cube,
    label: `方涵`,
  },
];

const App: React.FC<PropsWithChildren> = (props) => {
  const [mode, setMode] = useRecoilState(Mode);
  const step = useRecoilValue(Step);
  const [data, setData] = useRecoilState(Data);

  const showExportExcel = step === 2 && mode === TMode.second;

  return (
    <ConfigProvider locale={zhCN}>
      <Router>
        <Layout>
          <Header style={{ display: "flex", alignItems: "center" }}>
            <div className="q-contents">
              <Menu
                theme="dark"
                mode="horizontal"
                selectedKeys={[data.type]}
                items={items1}
                style={{ flex: 1, minWidth: 0 }}
                onClick={({ key }) => {
                  setData({ ...data, type: key as TType });
                }}
              />
              <Switch
                className="h-button"
                checkedChildren="复测"
                unCheckedChildren="定位"
                checked={mode === TMode.second}
                onChange={(v) => {
                  // setStep(0);
                  setMode(v ? TMode.second : TMode.first);
                }}
              />
            </div>
            <div className="q-text-white q-flex-1 q-text-center">
              <h2>超声换能器自动测算系统</h2>
            </div>
            <div className="q-inline-flex q-items-center">
              {/* {showExportExcel && (
                <div
                  className=" q-text-white q-cursor-pointer q-ml-6"
                  onClick={() => exportExcel(data)}
                >
                  导出Excel
                </div>
              )} */}
              <div
                className=" q-text-white q-cursor-pointer q-ml-6"
                onClick={() => exportExcel(data)}
              >
                导出Excel
              </div>

              <div
                className=" q-text-white q-cursor-pointer q-ml-6"
                onClick={() => downLoadFile({ ...data, mode })}
              >
                导出
              </div>

              <UploadFile />
            </div>
          </Header>

          <Layout>
            <Layout>
              <Content>
                <Routes>{props.children}</Routes>
              </Content>
            </Layout>
          </Layout>
        </Layout>
      </Router>
    </ConfigProvider>
  );
};

export default App;
