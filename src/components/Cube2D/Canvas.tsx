import React from "react";

const SvgCanvas = ({ children, viewBox }) => {
  return (
    <div style={{ width: "500px", height: "500px", border: "1px solid black" }}>
      <svg
        width="100%"
        height="100%"
        viewBox={viewBox}
        preserveAspectRatio="xMidYMid meet"
      >
        {children}
      </svg>
    </div>
  );
};

export default SvgCanvas;
