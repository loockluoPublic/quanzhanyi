import { useState } from "react";
import { CustomVector3 } from "../class/CustomVector3";
import { pointToAndMeasure } from "./commond";
import { useBoolean } from "ahooks";

export default function useMeasure() {
  const [loading, { setTrue, setFalse }] = useBoolean(false);
  const [points, setPoints] = useState<CustomVector3[]>([]);
  const addPoint = (point: CustomVector3) => {
    points.push(point);
    setPoints([...points]);
  };
  const measure = async (ps: CustomVector3[]) => {
    console.log("%c Line:14 🍇 ps", "color:#2eafb0", ps);
    setTrue();
    for await (const p of ps) {
      const np = await pointToAndMeasure(p);
      np && addPoint(np);
    }
    setFalse();
  };
  return {
    measure,
    loading,
    points,
  };
}
