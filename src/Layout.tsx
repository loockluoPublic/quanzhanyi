import React, { PropsWithChildren } from "react";
import type { MenuProps } from "antd";
import { Layout, Menu } from "antd";
import { BrowserRouter as Router, Routes } from "react-router-dom";
import { Data, Mode, TMode } from "./atom/globalState";
import { useRecoilState, useRecoilValue } from "recoil";
import { downLoadFile } from "./utils/utils";
import UploadFile from "./components/UploadFile";
const { Header, Content } = Layout;

const items1: MenuProps["items"] = [
  {
    key: TMode.first,
    label: `定位模式`,
  },
  {
    key: TMode.second,
    label: `复测模式`,
  },
];

const App: React.FC<PropsWithChildren> = (props) => {
  const [mode, setMode] = useRecoilState(Mode);
  const [data, setData] = useRecoilState(Data);

  return (
    <Router>
      <Layout>
        <Header style={{ display: "flex", alignItems: "center" }}>
          <Menu
            theme="dark"
            mode="horizontal"
            defaultSelectedKeys={[TMode.first]}
            items={items1}
            style={{ flex: 1, minWidth: 0 }}
            onClick={({ key }) => {
              setMode(key as TMode);
            }}
          />
          <div
            className=" q-text-white q-cursor-pointer"
            onClick={() => downLoadFile(data)}
          >
            导出
          </div>

          <UploadFile />
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
  );
};

export default App;
