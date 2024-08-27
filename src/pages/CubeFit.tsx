import CubeFitting from "../components/Module3D/CubeModule";
import BoundPoints from "../components/BoundPoints";
import GetCubePoints from "../components/GetCubePoints";
import { useRecoilState, useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import { Button } from "antd";
import { CalculateRectangleFromVertex, Planefit4 } from "../utils/utils";
import { CustomVector3 } from "../class/CustomVector3";

function CubeFit() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:12 🌽 data", "color:#e41a6a", data);

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
  };

  const comp = (
    <div>
      <Button type="primary" onClick={planefit}>
        拟合
      </Button>
    </div>
  );

  return (
    <CubeFitting
      component={comp}
      MxPoints={data.MxPoints}
      trianglePoints={data.trianglePoints}
    ></CubeFitting>
  );
}

export default CubeFit;
