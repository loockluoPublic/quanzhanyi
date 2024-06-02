import React, { PropsWithChildren } from "react";
import type { MenuProps } from "antd";
import { Layout, Menu } from "antd";
import { BrowserRouter as Router, Routes } from "react-router-dom";
import { Mode, TMode } from "./atom/globalState";
import { useRecoilState } from "recoil";
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
  return (
    <Router>
      <Layout>
        <Header style={{ display: "flex", alignItems: "center" }}>
          <div className="demo-logo" />
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
