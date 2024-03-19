import { MinusCircleOutlined } from "@ant-design/icons";
import {
  Button,
  Checkbox,
  Form,
  InputNumber,
  Radio,
  Select,
  Steps,
} from "antd";
import { DefaultOptionType } from "antd/es/select";
import { useState } from "react";
import Module3D from "./module3D";
import Connect from "../components/ConnectDevice";
import { getPoint } from "../components/commond";
import PointsVector3 from "../components/PointVector3";
import { useRecoilState } from "recoil";
import { Data } from "../atom/globalState";

const { Item } = Form;

const SDFBOptions = (() => {
  const options: DefaultOptionType[] = [];
  for (let index = 1; index <= 10; index++) {
    options.push({ value: index, label: `${index}声道` });
  }
  return options;
})();

const sdmOptions = [
  { label: "声道面A", value: "A" },
  { label: "声道面B", value: "B" },
];

export default function Setting() {
  const [data, setData] = useRecoilState(Data);
  const [step, setStep] = useState(2);
  console.log("%c Line:34 🍌 step", "color:#ffdd4d", step);

  const [form] = Form.useForm();

  const pickPoint = (key: string, field: any) => {
    console.log("%c Line:39 🎂 key", "color:#42b983", key, field);
    const arr = form.getFieldValue(key);
    console.log("%c Line:42 🌽 arr", "color:#42b983", arr);
    getPoint().then((res) => {
      console.log("%c Line:44 🥪 res", "color:#4fff4B", res);
      arr[field.key] = res;
      form.setFieldValue(key, [...arr]);
    });
  };

  const onChange = (value: number) => {
    setStep(value);
  };

  const next = () => {
    switch (step) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
    }
    const formValues = form.getFieldsValue();
    setData({ ...data, ...formValues });
    setStep(step + 1);
  };

  const getFromPoints = () => {
    const { firstPoints, points } = form.getFieldsValue() ?? {};
    console.log("%c Line:61 🥝 points", "color:#ffdd4d", points);
    return [...(firstPoints ?? []), ...(points ?? [])];
  };
  const panel = () => {
    switch (step) {
      case 0:
        return <Connect />;

      case 1: {
        return (
          <>
            <Item
              label="管道类型"
              name="type"
              rules={[{ required: true }]}
              initialValue={1}
            >
              <Radio.Group>
                <Radio value={1}>管道</Radio>
                <Radio value={2}>方涵</Radio>
              </Radio.Group>
            </Item>

            <Item
              label="声道分布"
              name="sdfb"
              rules={[{ required: true }]}
              wrapperCol={{ span: 3 }}
              initialValue={1}
            >
              <Select className=" !q-w-32" options={SDFBOptions} />
            </Item>

            <Item
              label="声道面"
              name="sdm"
              rules={[{ required: true }]}
              initialValue={["A"]}
            >
              <Checkbox.Group options={sdmOptions}></Checkbox.Group>
            </Item>
          </>
        );
      }

      case 2: {
        return (
          <div className="q-w-[500px]">
            <h3>定位点</h3>
            <Form.List name="firstPoints" initialValue={["", ""]}>
              {(fields) => {
                return (
                  <>
                    {fields.map((field, index) => (
                      <Form.Item
                        label={["圆柱顶面点", "圆柱底面点"][index]}
                        required={true}
                        key={field.key}
                      >
                        <Form.Item
                          {...field}
                          rules={[
                            {
                              required: true,
                            },
                          ]}
                          noStyle
                        >
                          <PointsVector3 style={{ width: "70%" }} />
                        </Form.Item>
                        <Button
                          style={{ marginLeft: "10px" }}
                          type="primary"
                          onClick={() => pickPoint("firstPoints", field)}
                        >
                          采集
                        </Button>
                      </Form.Item>
                    ))}
                  </>
                );
              }}
            </Form.List>
            <h3>初始拟合点</h3>
            <Form.List name="points" initialValue={["", "", "", "", ""]}>
              {(fields, { add, remove }) => {
                return (
                  <>
                    {fields.map((field, index) => (
                      <Form.Item
                        label={`采集第${index + 1}个点`}
                        required={true}
                        key={field.key}
                      >
                        <Form.Item
                          {...field}
                          rules={[
                            {
                              required: true,
                            },
                          ]}
                          noStyle
                        >
                          <PointsVector3 style={{ width: "70%" }} />
                        </Form.Item>
                        {fields.length > 5 ? (
                          <MinusCircleOutlined
                            style={{ marginLeft: "10px" }}
                            className="dynamic-delete-button"
                            onClick={() => remove(field.name)}
                          />
                        ) : null}
                        <Button
                          style={{ marginLeft: "10px" }}
                          type="primary"
                          onClick={() => pickPoint("points", field)}
                        >
                          采集
                        </Button>
                      </Form.Item>
                    ))}
                    <Form.Item>
                      <Button
                        type="dashed"
                        onClick={() => add()}
                        className=" q-w-full"
                      >
                        新增采集点
                      </Button>
                    </Form.Item>
                  </>
                );
              }}
            </Form.List>
          </div>
        );
      }

      case 3:
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
                {getFromPoints().map((value, i) => {
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

      case 4: {
        return (
          <Module3D className="q-mb-4" height={"calc( 100vh - 268px - 1em )"} />
        );
      }
    }
  };
  return (
    <>
      <Steps
        className=" q-bg-white !q-pt-4 q-mb-4"
        current={step}
        type="navigation"
        size="small"
        onChange={onChange}
        items={[
          {
            title: "设备连接",
          },
          {
            title: "基本参数",
          },
          {
            title: "手动采点",
          },
          {
            title: "拟合",
          },
          {
            title: "标记",
          },
        ]}
      />

      <div className=" q-flex q-justify-center q-bg-white q-m-4 q-p-8 q-rounded-xl">
        <Form
          onFinish={next}
          className={step > 2 ? " q-w-full" : ""}
          form={form}
        >
          {panel()}
          <div className=" q-text-center">
            <Button type="primary" htmlType="submit">
              下一步
            </Button>
          </div>
          {/* {step >= 0 && (
            <Item wrapperCol={{ offset: 10, span: 16 }}>
              <Button type="primary" htmlType="submit">
                下一步
              </Button>
            </Item>
          )} */}
        </Form>
      </div>
    </>
  );
}
