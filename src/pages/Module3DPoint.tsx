import { Form, InputNumber } from "antd";
import Module3D from "./module3D";
import PointsVector3 from "../components/PointVector3";
const { Item } = Form;

export function Module3DPoint(props: { getFromPoints: () => any[] }) {
  return (
    <div className="q-flex">
      <Module3D
        className="q-mb-4 q-grow"
        height={"calc( 100vh - 268px - 1em )"}
      />
      <div className="q-w-[400px]  q-ml-3 q-pl-2 ">
        <Item
          label="算法生成测点数量"
          name="autoPointsNum"
          rules={[{ required: true }]}
          initialValue={40}
        >
          <InputNumber min={10} max={100} />
        </Item>

        <Item
          label="xxx阈值"
          name="autoPointsOfffset"
          rules={[{ required: true }]}
          initialValue={1}
        >
          <InputNumber min={0} />
        </Item>
        <div className="q-h-[600px] q-overflow-y-scroll">
          {props.getFromPoints().map((value, i) => {
            return (
              <div key={i}>
                <PointsVector3 value={value} />
              </div>
            );
          })}
        </div>
      </div>
    </div>
  );
}
