import React from "react";

const SvgCanvas: React.FC<
  React.PropsWithChildren<{ viewBox: string; maxHeight: number }>
> = ({ children, viewBox, maxHeight }) => {
  return (
    <div
      className="canvas-style q-flex q-w-full q-h-full q-overflow-hidden q-relative"
      style={{ maxHeight }}
    >
      <svg width="100%" height="100%" viewBox={viewBox}>
        {children}
      </svg>
    </div>
  );
};

export default SvgCanvas;
