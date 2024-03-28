import { Form, InputNumber, message } from "antd";
import Module3D from "./module3D";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";
import { useMount } from "ahooks";
import { generateUnitCircleWithNormalVector } from "../utils/utils";
import useMeasure from "../utils/useMeasure";
import { useEffect, useRef } from "react";
import { pointToAndMeasure } from "../utils/commond";
const { Item } = Form;

export function Module3DPoint() {
  const [data, setData] = useRecoilState(Data);
  console.log("%c Line:15 🥔 data", "color:#ed9ec7", data);

  const { measure, loading, points } = useMeasure();

  const flag = useRef(true);
  useEffect(() => {
    if (flag.current) {
      flag.current = false;
      const waitingPoints = generateUnitCircleWithNormalVector(
        data?.direct[0],
        data?.direct[1],
        data.numPerLay
      );
      setData({
        ...data,
        waitingPoints,
      });
      measure(waitingPoints);
    }
  }, []);

  useEffect(() => {
    if (!loading && points.length > 0) {
      setData({
        ...data,
        mdPoints: points,
      });
    }
  }, [loading, points]);

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
        {loading ? "测量中。。。。" : "测量完成"}
        <h3>待测量方向点</h3>
        <div className="q-overflow-y-scroll">
          {data?.waitingPoints?.map((value, i) => {
            return (
              <div key={`${i}-${value.x}`}>
                <PointsVector3 value={value} />
              </div>
            );
          })}
        </div>
        <h3>已经测量数据</h3>
        <div className=" q-overflow-y-scroll">
          {points?.map((value, i) => {
            return (
              <div
                className=" q-cursor-pointer"
                key={`${i}-${value.x}`}
                onClick={() => {
                  pointToAndMeasure(value).then((res) => {
                    message.success(JSON.stringify(res), 5);
                  });
                }}
              >
                <PointsVector3 value={value} />
              </div>
            );
          })}
        </div>
      </div>
    </div>
  );
}
