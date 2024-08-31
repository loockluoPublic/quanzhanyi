import CylinderModule from "../components/Module3D";
import { useRecoilState } from "recoil";
import { Data, GlobalData } from "../atom/globalState";
import { Button, Checkbox, InputNumber, message, Table, Tooltip } from "antd";
import { SettingOutlined } from "@ant-design/icons";
import { Point } from "./CalculateResultPoints";
import React, { useEffect, useRef, useState } from "react";
import Select, { DefaultOptionType } from "antd/es/select";
import {
  ang2rad,
  CalcJuXingAAndBPointsAfterOffest,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  calculateStandardDeviation,
  cubeTOff,
  generateUnitCircleWithNormalVector,
  rad2ang,
  shengDaoGaoDu,
} from "../utils/utils";
import PointsVector3 from "../components/PointVector3";
import { CustomVector3 } from "../class/CustomVector3";
import PointsVector2 from "../components/PointVector2";
import { getLine } from "../utils/commond";

import mockData from "../utils/mockData";
import useMeasure from "../utils/useMeasure";
import ResultsTable2 from "../components/ResultsTable2";

const SDFBOptions = (() => {
  const options: DefaultOptionType[] = [];
  for (let index = 2; index <= 10; index++) {
    options.push({ value: index, label: `${index}声道` });
  }
  return options;
})();

const sdmOptions = [
  { label: "声道面A", value: "A" },
  { label: "声道面B", value: "B" },
];

function CylinderPre() {
  const [data, setData] = useRecoilState(Data);

  const { measure, loading, points } = useMeasure();

  const autoGetPoints = () => {
    if (!(data?.direct?.[0] && data?.direct?.[1])) {
      message.error("缺少轴线方向，请采集");
      return;
    }

    if (!(data?.firstPoints?.[0] && data?.firstPoints?.[1])) {
      message.error("缺少边界点，请采集");
      return;
    }

    CustomVector3.setPublicInfo("P", 1);

    generateUnitCircleWithNormalVector(
      data?.direct?.[0],
      data?.direct?.[1],
      data.numPerLay,
      data.layNum,
      data?.firstPoints?.[0],
      data?.firstPoints?.[1]
    ).then((waitingPoints) => {
      setData({
        ...data,
        waitingPoints,
      });
      measure(waitingPoints);
    });
  };

  const setMockData = () => {
    CustomVector3.setPublicInfo("P", 0);
    setData({
      ...data,
      mPoints: mockData.mPoints.map(
        (item) => new CustomVector3(item.x, item.y, item.z)
      ),
    });
  };

  useEffect(() => {
    if (!loading && points.length > 0) {
      setData({
        ...data,
        mPoints: points,
      });
    }
  }, [loading, points]);

  const [cyLoading, setLoading] = useState(false);

  const [customStandardDeviation, setStandardDeviation] = useState(3);

  const calculateCylinders = (curData: GlobalData, isFirst?: boolean) => {
    const enablePoints = curData.mPoints.filter((item) => item.enable);
    return new Promise((reslove) => {
      setTimeout(() => {
        CalculateAccurateCylindersFromMultipleMeasurementPoints(
          enablePoints,
          curData.firstPoints[0],
          curData.firstPoints[1]
        ).then((calulateRes) => {
          const differences = calulateRes.Err_every;

          enablePoints.forEach((item, i) => {
            item.difference = differences[i];
          });

          if (isFirst) {
            enablePoints.forEach((item, i) => {
              item.originDiff = differences[i];
            });
          }

          const standardDeviation = calculateStandardDeviation(enablePoints);

          const nd: any = {
            ...curData,
            mPoints: curData.mPoints,
            calulateRes,
            [isFirst ? "originStandardDeviation" : "standardDeviation"]:
              standardDeviation,
            standardDeviation,
          };

          setTimeout(() => {
            setData(nd);
            reslove(nd);
          }, 200);
        });
      }, 200);
    });
  };

  const reRun = (curData: GlobalData) => {
    const newMP = curData.mPoints.map((item) => {
      return item
        .fromCustomVector3()
        .setEnable(Math.abs(item.difference) < curData.standardDeviation);
    });

    const nD = {
      ...curData,
      mPoints: newMP,
    };
    setLoading(true);
    calculateCylinders(nD).then(() => {
      setLoading(false);
    });
  };

  const cyFit = () => {
    setLoading(true);

    calculateCylinders(
      {
        ...data,
        mPoints: data.mPoints.map((d) => d.fromCustomVector3()),
      },
      true
    )
      .then((newData: any) => {
        reRun(newData);
        setLoading(false);
      })
      .catch((err) => {
        console.error("%c Line:80 🍺 err", "color:#93c0a4", err);
      });
  };

  const disableFit = data.mPoints?.length > 0;
  console.log("%c Line:176 🍧 data.mPoints", "color:#6ec1c2", data.mPoints);

  const comp = (
    <div>
      <div>
        <span>
          采样层数：
          <InputNumber
            value={data.layNum}
            min={2}
            max={10}
            onChange={(v) => {
              setData({ ...data, layNum: v });
            }}
          />
        </span>
        <span className="q-ml-8">
          每层采点数：
          <InputNumber
            value={data.numPerLay}
            min={3}
            max={50}
            onChange={(v) => {
              setData({ ...data, numPerLay: v });
            }}
          />
        </span>
        <span className="q-ml-8">
          管道轴线方向：
          <span>
            <PointsVector2 value={data.direct} />
            <Button
              style={{ marginLeft: "10px" }}
              type="primary"
              onClick={() => {
                getLine().then((direct) => {
                  setData({ ...data, direct });
                });
              }}
              size="small"
            >
              采集
            </Button>
          </span>
        </span>
      </div>
      <div>
        <span className="">
          边界点1：
          <PointsVector3
            className="!q-inline-flex"
            value={data.firstPoints[0] as CustomVector3}
            onChange={(v) => {
              setData({ ...data, firstPoints: [v, data.firstPoints[1]] });
            }}
          />
        </span>
        <span className="q-ml-8">
          边界点2：
          <PointsVector3
            className="!q-inline-flex"
            value={data.firstPoints[1] as CustomVector3}
            onChange={(v) => {
              setData({ ...data, firstPoints: [data.firstPoints[0], v] });
            }}
          />
        </span>
      </div>

      <div className=" q-flex q-justify-end">
        <Button className="q-ml-2" size="small" onClick={setMockData}>
          测试数据
        </Button>
        <Button
          className="q-ml-2"
          type="primary"
          loading={loading}
          onClick={autoGetPoints}
        >
          开始采集
        </Button>
        <Button
          disabled={!disableFit}
          className="q-ml-2"
          type="primary"
          loading={cyLoading}
          onClick={cyFit}
        >
          管道拟合
        </Button>
      </div>

      <div className="q-my-4">
        <div className="q-grid q-grid-cols-4">
          <div>
            半径：
            <span className=" q-font-bold">
              {data?.calulateRes?.R?.toFixed(4) ?? "--"} 米
            </span>
          </div>
          <div>
            初始标准差δ：
            <span className=" q-font-bold">
              {data?.originStandardDeviation?.toFixed(4) ?? "--"} 米
            </span>
          </div>
          <div>
            标准差：
            <span className=" q-font-bold">
              {data?.standardDeviation?.toFixed(4) ?? "--"} 米
            </span>
          </div>

          <span>
            有效点：
            <span className=" q-font-bold">
              {data.mPoints.filter((item) => item.enable).length}/
              {data.mPoints.length}
            </span>
          </span>
        </div>

        <div
          className="q-flex q-items-center q-my-2"
          style={{
            visibility:
              typeof data.standardDeviation !== "number" ? "hidden" : "initial",
          }}
        >
          阈值：
          <InputNumber
            step={0.01}
            style={{ width: "200px" }}
            value={customStandardDeviation}
            onChange={(standardDeviation) => {
              setStandardDeviation(standardDeviation);
            }}
            addonAfter="δ"
          />
          <Button
            className="q-float-right q-ml-4"
            loading={cyLoading}
            onClick={() => {
              reRun({
                ...data,
                standardDeviation:
                  customStandardDeviation * data.standardDeviation,
              });
            }}
            type="primary"
          >
            再次拟合
          </Button>
        </div>
        <ResultsTable2 />
      </div>
    </div>
  );
  return (
    <CylinderModule
      component={comp}
      mPoints={data.mPoints}
      calulateRes={data.calulateRes}
    ></CylinderModule>
  );
}

export default CylinderPre;
