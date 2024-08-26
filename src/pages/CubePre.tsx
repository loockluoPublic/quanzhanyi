import CubeFitting from "../components/Module3D/CubeModule";
import BoundPoints from "../components/BoundPoints";
import GetCubePoints from "../components/GetCubePoints";
import { useRecoilValue } from "recoil";
import { Data } from "../atom/globalState";

function CubePre() {
  const data = useRecoilValue(Data);
  console.log("%c Line:9 🥛 data", "color:#4fff4B", data);

  const comp = (
    <div>
      <BoundPoints />
      <GetCubePoints />
    </div>
  );
  return <CubeFitting component={comp} MxPoints={data.MxPoints}></CubeFitting>;
}

export default CubePre;
