import "./utils/utils";
import { Route } from "react-router-dom";

import Layout from "./Layout";
import Index from "./pages";
import { useGlobalEffect } from "./atom/globalEffect";

export default function App() {
  useGlobalEffect();
  return (
    <Layout>
      <Route path="/" element={<Index />}></Route>
    </Layout>
  );
}
