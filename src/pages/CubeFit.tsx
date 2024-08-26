import CubeFitting from "../components/Module3D/CubeModule";
import BoundPoints from "../components/BoundPoints";
import GetCubePoints from "../components/GetCubePoints";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import { Button } from "antd";
import { Planefit4 } from "../utils/utils";
import { CustomVector3 } from "../class/CustomVector3";

function CubeFit() {
  const data = useRecoilValue(Data);

  const planefit = () => {
    const paramArr: [
      CustomVector3[],
      CustomVector3[],
      CustomVector3[],
      CustomVector3[],
      CustomVector3,
      CustomVector3
    ] = [...Object.values(data.MxPoints), ...data.firstPoints] as any;
    const res = Planefit4(...paramArr);
    console.log("%c Line:23 🥤 res", "color:#42b983", res);
  };

  const comp = (
    <div>
      <Button type="primary" onClick={planefit}>
        拟合
      </Button>
    </div>
  );

  return <CubeFitting component={comp} MxPoints={data.MxPoints}></CubeFitting>;
}

export default CubeFit;
