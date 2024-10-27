import { useRecoilState } from "recoil";
import { Data, getInitAgainTable, TType } from "./globalState";
import { useEffect } from "react";

export function useGlobalEffect() {
  const [data, setData] = useRecoilState(Data);

  useEffect(() => {
    setData((d) => {
      const key =
        d.type === TType.cycle ? "cylinderAgainTable" : "cubeAgainTable";
      return {
        ...d,
        [key]: getInitAgainTable(data.sdfb, data.sdm) as any,
      };
    });
  }, [data.sdfb, data.sdm?.join(""), data.type]);
}
