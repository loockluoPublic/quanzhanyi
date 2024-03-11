import React, { PropsWithChildren } from "react";
import type { MenuProps } from "antd";
import { Layout, Menu, theme } from "antd";
import { BrowserRouter as Router, Routes } from "react-router-dom";
const { Header, Content, Sider } = Layout;

const items1: MenuProps["items"] = [
  {
    key: "1",
    label: `定位模式`,
  },
  {
    key: "2",
    label: `复测模式`,
  },
];

const App: React.FC<PropsWithChildren> = (props) => {
  return (
    <Router>
      <Layout>
        <Header style={{ display: "flex", alignItems: "center" }}>
          <div className="demo-logo" />
          <Menu
            theme="dark"
            mode="horizontal"
            defaultSelectedKeys={["1"]}
            items={items1}
            style={{ flex: 1, minWidth: 0 }}
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
