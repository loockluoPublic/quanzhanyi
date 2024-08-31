import React from "react";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";

export default function Item(props: { path: string; label: string }) {
  const [data, setData] = useRecoilState(Data);

  return <div></div>;
}
