import "./utils/utils";
import { Route } from "react-router-dom";

import Layout from "./Layout";
import Setting from "./pages/setting";

export default function App() {
  return (
    <Layout>
      <Route path="/" element={<Setting />}></Route>
    </Layout>
  );
}
