import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";
import { RecoilRoot } from "recoil";
import "./index.css";
import Secret from "./pages/Secret";
ReactDOM.createRoot(document.getElementById("root")!).render(
  <React.StrictMode>
    <RecoilRoot>
      {location.pathname === "/secret" ? <Secret /> : <App />}
    </RecoilRoot>
  </React.StrictMode>
);
