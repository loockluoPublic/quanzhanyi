import CubeFitting from "../components/Module3D/CubeModule";
import BoundPoints from "../components/BoundPoints";
import GetCubePoints from "../components/GetCubePoints";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";
import Block from "../components/Block";

function CubePre() {
  const data = useRecoilValue(Data);
  console.log("%c Line:9 🥛 data", "color:#4fff4B", data);

  const comp = (
    <div>
      <h3>基础参数：</h3>
      <BoundPoints />
      <GetCubePoints />
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

export default CubePre;
