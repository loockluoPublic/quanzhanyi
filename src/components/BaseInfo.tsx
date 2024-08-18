import { Checkbox, Radio, Select, Form, InputNumber } from "antd";
import { DefaultOptionType } from "antd/es/select";
import Next from "./Next";

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
export default function BaseInfo(props: { hideMode?: boolean }) {
  return (
    <>
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
        initialValue={45}
      >
        <InputNumber addonAfter="度" />
      </Item>

      {!props.hideMode && <Next className="q-mt-4" />}

      {/* <Item
        label="轴向偏移"
        name="tOff"
        rules={[{ required: true }]}
        initialValue={0.01}
      >
        <InputNumber addonAfter="米" />
      </Item>

      <Item
        label="周向偏移"
        name="rOff"
        rules={[{ required: true }]}
        initialValue={0.02}
      >
        <InputNumber addonAfter="米" />
      </Item> */}
    </>
  );
}
