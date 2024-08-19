import "./utils/utils";
import { Route } from "react-router-dom";

import Layout from "./Layout";
import Index from "./pages";

export default function App() {
  return (
    <Layout>
      <Route path="/" element={<Index />}></Route>
    </Layout>
  );
}
