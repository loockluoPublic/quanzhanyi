import React, { PropsWithChildren } from "react";
import type { MenuProps } from "antd";
import { Layout, Menu, Switch } from "antd";
import { BrowserRouter as Router, Routes } from "react-router-dom";
import { Data, Mode, TMode, TType } from "./atom/globalState";
import { useRecoilState, useRecoilValue } from "recoil";
import { downLoadFile } from "./utils/utils";
import UploadFile from "./components/UploadFile";
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
  const [data, setData] = useRecoilState(Data);

  return (
    <Router>
      <Layout>
        <Header style={{ display: "flex", alignItems: "center" }}>
          <Menu
            theme="dark"
            mode="horizontal"
            defaultSelectedKeys={[data.type]}
            items={items1}
            style={{ flex: 1, minWidth: 0 }}
            onClick={({ key }) => {
              setData({ ...data, type: key as TType });
            }}
          />
          <Switch
            className="h-button"
            checkedChildren="复测"
            unCheckedChildren="首测"
            checked={mode === TMode.second}
            onChange={(v) => {
              setMode(v ? TMode.second : TMode.first);
            }}
          />
          <div
            className=" q-text-white q-cursor-pointer q-ml-6"
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
