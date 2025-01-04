import CylinderModule from '../components/Module3D';
import { useRecoilState, useRecoilValue } from 'recoil';
import { Auth, Data, GlobalData } from '../atom/globalState';
import { Button, InputNumber, message } from 'antd';
import { useEffect, useState } from 'react';
import {
  ang2rad,
  CalculateAccurateCylindersFromMultipleMeasurementPoints,
  calculateStandardDeviation,
  generateUnitCircleWithNormalVector,
  rad2ang,
} from '../utils/utils';
import PointsVector3 from '../components/PointVector3';
import { CustomVector3 } from '../class/CustomVector3';
import PointsVector2 from '../components/PointVector2';
import { getLine } from '../utils/commond';
import useMeasure from '../utils/useMeasure';
import CylinderTable from '../components/CylinderTable';

function CylinderPre() {
  const [data, setData] = useRecoilState(Data);
  const auth = useRecoilValue(Auth);

  const { measure, loading, points } = useMeasure();

  const autoGetPoints = () => {
    if (!(data?.direct?.[0] && data?.direct?.[1])) {
      message.error('缺少轴线方向，请采集');
      return;
    }

    if (!(data?.firstPoints?.[0] && data?.firstPoints?.[1])) {
      message.error('缺少边界点，请采集');
      return;
    }

    CustomVector3.setPublicInfo('P', 1);

    generateUnitCircleWithNormalVector(
      data.triPoints,
      data.numPerLay,
      data.layNum,
      data?.firstPoints?.[0],
      data?.firstPoints?.[1]
    ).then((waitingPoints) => {
      console.log(
        '%c Line:45 🥤 waitingPoints',
        'color:#4fff4B',
        waitingPoints
      );
      setData({
        ...data,
        waitingPoints,
      });
      measure(waitingPoints);
    });
  };

  useEffect(() => {
    if (points.length > 0) {
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
            [isFirst ? 'originStandardDeviation' : 'standardDeviation']:
              standardDeviation,
            standardDeviation,
          };

          setTimeout(() => {
            setData(nd);
            reslove(nd);
          }, 200);
        });
      }, 400);
    });
  };

  const reRun = (curData: GlobalData, isFirst = false) => {
    console.log(
      '%c Line:115 🍫 curData',
      'color:#465975',
      curData.standardDeviation,
      data.standardDeviation
    );
    const newMP = curData.mPoints.map((item) => {
      return item
        .fromCustomVector3()
        .setEnable(
          Math.abs(item.originDiff) <
            (isFirst
              ? 3 * curData.standardDeviation
              : curData.standardDeviation)
        );
    });

    const nD = {
      ...curData,
      mPoints: newMP,
    };

    setLoading(true);
    calculateCylinders(nD).finally(() => {
      setLoading(false);
    });
  };

  const cyFit = () => {
    setLoading(true);

    calculateCylinders(
      {
        ...data,
        mPoints: data.mPoints.map((d) => d.fromCustomVector3().setEnable(true)),
      },
      true
    )
      .then((newData: any) => {
        reRun(newData, true);
      })
      .catch((err) => {
        console.error('%c Line:80 🍺 err', 'color:#93c0a4', err);
      });
  };

  const disableFit = data.mPoints?.length > 0;

  const comp = (
    <div>
      <h3>自动采样参数：</h3>

      <div className='q-mt-2 q-flex '>
        <div className='q-fle1x'>
          <span className=' '>
            上游边界点：
            <PointsVector3
              hideLabel
              className='!q-inline-flex !q-my-1'
              value={data.firstPoints[0] as CustomVector3}
              before={() => {
                CustomVector3.setPublicInfo('上游点', 0);
              }}
              onChange={(v) => {
                v.color = 'blue';
                setData({ ...data, firstPoints: [v, data.firstPoints[1]] });
              }}
            />
          </span>
          <span className='q-ml-8'>
            下游边界点：
            <PointsVector3
              hideLabel
              className='!q-inline-flex !q-my-1'
              value={data.firstPoints[1] as CustomVector3}
              before={() => {
                CustomVector3.setPublicInfo('下游点', 1);
              }}
              onChange={(v) => {
                setData({ ...data, firstPoints: [data.firstPoints[0], v] });
              }}
            />
          </span>
        </div>

        {/* <span className=' q-block q-ml-8'>
          管道轴线方向：
          <span>
            <PointsVector2 value={data.direct} />
            <Button
              disabled={!auth}
              style={{ marginLeft: '10px' }}
              type='primary'
              onClick={() => {
                getLine().then((direct) => {
                  if (rad2ang(direct[1]) > 180) {
                    direct[1] = ang2rad(360 - rad2ang(direct[1]));
                  }
                  setData({ ...data, direct });
                });
              }}
              size='small'
            >
              采集
            </Button>
          </span>
        </span> */}
      </div>

      <h3 className='border-top  q-mt-4 q-pt-2'></h3>
      <div className='q-my-1 q-flex '>
        <div className='q-fle1x'>
          <span className=' '>
            圆周点1：
            <PointsVector3
              hideLabel
              className='!q-inline-flex !q-my-1'
              value={data.firstPoints[0] as CustomVector3}
              before={() => {
                CustomVector3.setPublicInfo('T', 0);
              }}
              onChange={(v) => {
                v.color = 'red';
                setData({
                  ...data,
                  triPoints: [v, data.triPoints[1], data.triPoints[2]],
                });
              }}
            />
          </span>
          <span className='q-ml-8'>
            圆周点2：
            <PointsVector3
              hideLabel
              className='!q-inline-flex !q-my-1'
              value={data.firstPoints[1] as CustomVector3}
              before={() => {
                CustomVector3.setPublicInfo('T', 1);
              }}
              onChange={(v) => {
                v.color = 'red';
                setData({
                  ...data,
                  triPoints: [data.triPoints[0], v, data.triPoints[2]],
                });
              }}
            />
          </span>
          <span className='q-block'>
            圆周点3：
            <PointsVector3
              hideLabel
              className='!q-inline-flex !q-my-1'
              value={data.firstPoints[1] as CustomVector3}
              before={() => {
                CustomVector3.setPublicInfo('T', 2);
              }}
              onChange={(v) => {
                v.color = 'red';
                setData({
                  ...data,
                  triPoints: [data.triPoints[0], data.triPoints[1], v],
                });
              }}
            />
          </span>
        </div>
      </div>
      <h3 className='border-top  q-mt-4 q-pt-2'></h3>
      <div className='q-mb-4'>
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
        <span className='q-ml-8'>
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
        {/* <span className='q-ml-8'>
          预估半径：
          <InputNumber
            value={data.virtualR}
            min={0.1}
            max={50}
            onChange={(virtualR) => {
              setData({ ...data, virtualR });
            }}
          />
        </span> */}
      </div>

      <div className='q-my-1 q-flex q-justify-end'>
        <Button
          className='q-ml q-ml-8'
          type='primary'
          loading={loading}
          onClick={autoGetPoints}
          disabled={!auth}
        >
          自动采集
        </Button>

        <PointsVector3
          type='button'
          buttonProps={{
            className: 'q-ml q-ml-8',
            size: 'middle',
          }}
          buttonText='手动采集'
          before={() => {
            const maxKey = Math.max(
              0,
              ...data.mPoints?.map((item) => item.key)
            );

            CustomVector3.setPublicInfo('P', maxKey);
          }}
          onChange={(v) => {
            setData((d) => ({
              ...d,
              mPoints: [v, ...d.mPoints],
            }));
          }}
        />

        <Button
          className=' q-ml-8 '
          disabled={!disableFit}
          type='primary'
          loading={cyLoading}
          onClick={cyFit}
        >
          管道拟合
        </Button>
      </div>

      <h3 className='border-top q-mt-4 q-pt-2'>拟合结果：</h3>
      <div className='q-my-2'>
        <div className='q-grid q-grid-cols-4'>
          <div>
            半径：
            <span className=' q-font-bold'>
              {data?.calulateRes?.R?.toFixed(4) ?? '--'} 米
            </span>
          </div>
          <div>
            初始标准差δ：
            <span className=' q-font-bold'>
              {data?.originStandardDeviation?.toFixed(4) ?? '--'} 米
            </span>
          </div>
          <div className='q-ml-4'>
            标准差：
            <span className=' q-font-bold'>
              {data?.standardDeviation?.toFixed(4) ?? '--'} 米
            </span>
          </div>

          <span>
            有效点：
            <span className=' q-font-bold'>
              {data.mPoints.filter((item) => item.enable).length}/
              {data.mPoints.length}
            </span>
          </span>
        </div>

        <div
          className='q-flex q-items-center q-my-2  q-justify-end'
          style={{
            visibility:
              typeof data.standardDeviation !== 'number' ? 'hidden' : 'initial',
          }}
        >
          阈值：
          <InputNumber
            step={0.01}
            style={{ width: '200px' }}
            value={customStandardDeviation}
            onChange={(standardDeviation) => {
              // setData(() => {
              //   return {
              //     ...data,
              //     // standardDeviation:standardDeviation*
              //   };
              // });
              setStandardDeviation(standardDeviation);
            }}
            addonAfter='δ'
          />
          <Button
            className='q-float-right q-ml-4'
            loading={cyLoading}
            onClick={() => {
              console.log(
                '%c Line:332 🥛 customStandardDeviation * data.originStandardDeviation',
                'color:#2eafb0',
                customStandardDeviation,
                data.originStandardDeviation
              );
              reRun({
                ...data,
                standardDeviation:
                  customStandardDeviation * data.originStandardDeviation,
              });
            }}
          >
            再次拟合
          </Button>
        </div>
        <CylinderTable />
      </div>
    </div>
  );
  return (
    <CylinderModule
      direct={data.direct}
      firstPoints={[...data.firstPoints, ...data.triPoints]}
      component={comp}
      mPoints={data.mPoints}
      calulateRes={data.calulateRes}
    ></CylinderModule>
  );
}

export default CylinderPre;
