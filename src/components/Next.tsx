import { Button } from "antd";

export default function Next(props: { className?: string }) {
  return (
    <div className={`${props.className || ""} q-text-center`}>
      <Button type="primary" htmlType="submit">
        下一步
      </Button>
    </div>
  );
}
