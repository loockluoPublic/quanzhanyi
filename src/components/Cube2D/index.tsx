import SvgCanvas from "./Canvas";
import ArrowLine from "./Line";

const containerWidth = 500;

export default function Cube2D(props: {
  width: number;
  height: number;
  containerHeight: number;
  tris: number[];
}) {
  const tris = props.tris ?? new Array(8).fill(0);
  const { width: w = 0, height: h = 0 } = props;

  const max = Math.max(w, h);
  const scale = containerWidth / max;

  if (max <= 0)
    return (
      <SvgCanvas
        viewBox={`-100 -100 700 700`}
        maxHeight={props.containerHeight}
      >
        {null}
      </SvgCanvas>
    );

  return (
    <SvgCanvas viewBox={`-100 -100 800 700`} maxHeight={props.containerHeight}>
      {/* 宽 */}
      <ArrowLine
        points={[
          { x: w, y: h },
          { x: 0, y: h },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
        arrLineOffset={60}
      />
      {/* 高 */}
      <ArrowLine
        points={[
          { x: w, y: 0 },
          { x: w, y: h },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
        arrLineOffset={70}
      />
      {/* 左上角斜边 */}
      <ArrowLine
        points={[
          { x: 0, y: 0 },
          { x: tris[1], y: 0 },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      <ArrowLine
        points={[
          { x: 0, y: tris[0] },
          { x: 0, y: 0 },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      ,
      <ArrowLine
        points={[
          { x: 0, y: tris[0] },
          { x: tris[1], y: 0 },
        ]}
        scale={scale}
        showLabel={false}
      />
      {/* 上边 */}
      <ArrowLine
        points={[
          { x: tris[1], y: 0 },
          { x: w - tris[2], y: 0 },
        ]}
        scale={scale}
        showLabel={false}
        showLine={true}
      />
      {/* 右上角斜边 */}
      <ArrowLine
        points={[
          { x: w - tris[2], y: 0 },
          { x: w, y: 0 },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      <ArrowLine
        points={[
          { x: w, y: 0 },
          { x: w, y: tris[3] },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      <ArrowLine
        points={[
          { x: w - tris[2], y: 0 },
          { x: w, y: tris[3] },
        ]}
        scale={scale}
        showLabel={false}
      />
      {/* 右边 */}
      <ArrowLine
        points={[
          { x: w, y: tris[3] },
          { x: w, y: h - tris[4] },
        ]}
        scale={scale}
        showLabel={false}
        showLine={true}
      />
      {/* 右下角斜边 */}
      <ArrowLine
        points={[
          { x: w, y: h - tris[4] },
          { x: w - tris[5], y: h },
        ]}
        scale={scale}
        showLabel={false}
      />
      <ArrowLine
        points={[
          { x: w, y: h - tris[4] },
          { x: w, y: h },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      <ArrowLine
        points={[
          { x: w, y: h },
          { x: w - tris[5], y: h },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      {/* 下边 */}
      <ArrowLine
        points={[
          { x: w - tris[5], y: h },
          { x: tris[6], y: h },
        ]}
        scale={scale}
        showLabel={false}
        showLine={true}
      />
      {/* 左下角斜边 */}
      <ArrowLine
        points={[
          { x: tris[6], y: h },
          { x: 0, y: h - tris[7] },
        ]}
        scale={scale}
        showLabel={false}
      />
      <ArrowLine
        points={[
          { x: tris[6], y: h },
          { x: 0, y: h },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      <ArrowLine
        points={[
          { x: 0, y: h },
          { x: 0, y: h - tris[7] },
        ]}
        scale={scale}
        showLabel={true}
        showLine={false}
      />
      {/* 左边 */}
      <ArrowLine
        points={[
          { x: 0, y: h - tris[7] },
          { x: 0, y: tris[0] },
        ]}
        scale={scale}
        showLabel={false}
        showLine={true}
      />
    </SvgCanvas>
  );
}
