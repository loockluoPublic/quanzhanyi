import { MinusCircleOutlined } from "@ant-design/icons";
import { Button, Checkbox, Form, Input, Radio, Select, Steps } from "antd";
import { DefaultOptionType } from "antd/es/select";
import { useState } from "react";
import Module3D from "./module3D";
import Connect from "../components/ConnectDevice";

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
  const [step, setStep] = useState(0);
  const onChange = (value: number) => {
    setStep(value);
  };

  const next = () => {
    setStep(step + 1);
  };

  const panel = () => {
    switch (step) {
      case 0:
        return <Connect onConnected={next} />;

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
            <Form.List name="points" initialValue={["", "", "", "", ""]}>
              {(fields, { add, remove }) => {
                return (
                  <>
                    {fields.map((field, index) => (
                      <Form.Item
                        label={`手动采集第${index + 1}个点`}
                        required={true}
                        key={field.key}
                      >
                        <Form.Item
                          {...field}
                          validateTrigger={["onChange", "onBlur"]}
                          rules={[
                            {
                              required: true,
                              whitespace: true,
                              message:
                                "Please input passenger's name or delete this field.",
                            },
                          ]}
                          noStyle
                        >
                          <Input disabled style={{ width: "70%" }} />
                        </Form.Item>
                        {fields.length > 5 ? (
                          <MinusCircleOutlined
                            style={{ marginLeft: "10px" }}
                            className="dynamic-delete-button"
                            onClick={() => remove(field.name)}
                          />
                        ) : null}
                        <Button style={{ marginLeft: "10px" }} type="primary">
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

      <div className=" q-flex q-justify-center q-bg-white q-m-4 q-p-8">
        <Form onFinish={next} className={step > 1 ? " q-w-full" : ""}>
          {panel()}

          {step !== 0 && (
            <Item wrapperCol={{ offset: 10, span: 16 }}>
              <Button type="primary" htmlType="submit">
                下一步
              </Button>
            </Item>
          )}
        </Form>
      </div>
    </>
  );
}
