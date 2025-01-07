import { useState } from "react";
import { CustomVector3 } from "../class/CustomVector3";
import { pointToAndMeasure } from "./commond";
import { useBoolean } from "ahooks";

export default function useMeasure() {
  const [loading, { setTrue, setFalse }] = useBoolean(false);
  const [points, setPoints] = useState<CustomVector3[]>([]);

  const addPoint = (point: CustomVector3) => {
    setPoints((p) => {
      return [ point,...p];
    });
  };

  const measure = async (
    ps: CustomVector3[],
    onData?: (p: CustomVector3) => void
  ) => {
    setTrue();
    setPoints([]);
    let i =0
    CustomVector3.setPublicInfo("P", 0);
    for await (const p of ps) {
      const np: any = await pointToAndMeasure(p).catch((err) => {
        console.log("%c Line:25 🌭 err", "color:#ffdd4d", err);
      });
      np.key = ++i
      if (np) {
        addPoint?.(np);
        onData?.(np);
      }
    }
    setFalse();
  };

  return {
    measure,
    loading,
    points,
  };
}
