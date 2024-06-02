import { Checkbox, Radio, Select, Form, InputNumber } from "antd";
import { DefaultOptionType } from "antd/es/select";

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
const { Item } = Form;
export default function BaseInfo() {
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
        initialValue={4}
      >
        <Select className=" !q-w-32" options={SDFBOptions} />
      </Item>

      <Item
        label="声道面"
        name="sdm"
        rules={[{ required: true }]}
        initialValue={["A", "B"]}
      >
        <Checkbox.Group options={sdmOptions}></Checkbox.Group>
      </Item>
      <Item
        label="声道角"
        name="sdj"
        rules={[{ required: true }]}
        initialValue={0.6}
      >
        <InputNumber />
      </Item>
      <Item
        label="轴向偏移"
        name="tOff"
        rules={[{ required: true }]}
        initialValue={0.1}
      >
        <InputNumber />
      </Item>
      <Item
        label="径向偏移"
        name="rOff"
        rules={[{ required: true }]}
        initialValue={0.2}
      >
        <InputNumber />
      </Item>
    </>
  );
}
