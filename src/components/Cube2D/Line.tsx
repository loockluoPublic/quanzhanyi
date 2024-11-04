import React, { useMemo } from "react";

// ArrowLine 组件
const ArrowLine = ({
  points,
  showLine = true,
  showLabel = true,
  scale = 1,
}) => {
  console.log("%c Line:5 🥪 points", "color:#e41a6a", scale, points);

  const curCsale = scale || 1;

  const [pointA, pointB] = useMemo(() => {
    return [
      { x: points[0].x * scale, y: points[0].y * scale },
      { x: points[1].x * scale, y: points[1].y * scale },
    ];
  }, [points]);

  // 计算线段的角度
  const dx = pointB.x - pointA.x;
  const dy = pointB.y - pointA.y;
  const angle = Math.atan2(dy, dx);

  // 计算线段长度
  const length = (Math.sqrt(dx * dx + dy * dy) / curCsale).toFixed(3);

  // 字号
  const fontSize = 20;
  const offset = fontSize; // 偏移量为1倍字号

  // 计算AC和BD的端点
  const ax = pointA.x + offset * Math.cos(angle - Math.PI / 2);
  const ay = pointA.y + offset * Math.sin(angle - Math.PI / 2);
  const bx = pointB.x + offset * Math.cos(angle - Math.PI / 2);
  const by = pointB.y + offset * Math.sin(angle - Math.PI / 2);
  console.log(
    "%c Line:35 🥟 Math.cos(angle - Math.PI / 2)",
    "color:#ffdd4d",
    length,
    Math.cos(angle - Math.PI / 2),
    Math.sin(angle - Math.PI / 2)
  );

  // 计算EF中点
  const ex = (ax + bx) / 2 + offset * Math.cos(angle - Math.PI / 2);
  const ey = (ay + by) / 2 + offset * Math.sin(angle - Math.PI / 2);

  if (dx * dx + dy * dy === 0) return null;

  return (
    <g>
      {/* 条件展示线段 */}
      {showLine && (
        <line
          x1={pointA.x}
          y1={pointA.y}
          x2={pointB.x}
          y2={pointB.y}
          stroke="black"
          strokeWidth={3}
        />
      )}

      {/* 条件展示标注 */}
      {showLabel && (
        <>
          {/* 垂直线AC和BD，颜色为绿色 */}
          <line
            x1={pointA.x}
            y1={pointA.y}
            x2={ax}
            y2={ay}
            stroke="green"
            strokeWidth={1}
          />
          <line
            x1={pointB.x}
            y1={pointB.y}
            x2={bx}
            y2={by}
            stroke="green"
            strokeWidth={1}
          />

          {/* 标注线EF，颜色为绿色 */}
          <line
            x1={ax}
            y1={ay}
            x2={bx}
            y2={by}
            stroke="green"
            strokeWidth={2}
            markerEnd="url(#arrowEnd)"
            markerStart="url(#arrowStart)"
          />

          {/* 标注文本 */}
          <text
            x={ex}
            y={ey}
            fontSize={fontSize}
            fill="black"
            textAnchor="middle"
            // dy="-50%"
          >
            {length}
          </text>

          {/* 定义箭头 */}
          <defs>
            <marker
              id="arrowStart"
              markerWidth="6"
              markerHeight="6"
              refX="0"
              refY="3"
              orient="auto"
              markerUnits="strokeWidth"
            >
              <path d="M0,3 L6,6 L6,0 z" fill="green" />
            </marker>
            <marker
              id="arrowEnd"
              markerWidth="6"
              markerHeight="6"
              refX="6"
              refY="3"
              orient="auto"
              markerUnits="strokeWidth"
            >
              <path d="M6,3 L0,6 L0,0 z" fill="green" />
            </marker>
          </defs>
        </>
      )}
    </g>
  );
};

export default ArrowLine;
