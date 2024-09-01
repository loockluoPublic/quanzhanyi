import React, { ReactElement } from "react";
interface IProps {
  title?: string;
  children: ReactElement;
}
export default function Block(props: IProps) {
  return (
    <div className="q-shadow-inner">
      <div>{props.title}</div>
      <div>{props.children}</div>
    </div>
  );
}
