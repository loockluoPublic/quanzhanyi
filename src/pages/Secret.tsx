import SerialMonitor from "@ridge18/web-serial-monitor";
import { Button, Input } from "antd";

import * as commond from "../utils/commond";

import banner from "../assets/bg.jpg";
import qzy from "../assets/qzy.png";
import bgLogo from "../assets/bgLogo.png";
import { useState } from "react";
import { encode } from "../utils/secret";
import { Typography } from "antd";

const { Paragraph } = Typography;

(window as any).commond = commond;
export const serial = new SerialMonitor({ mode: "text", parseLines: true });

export default function Secret() {
  const [code, setCode] = useState("");

  const [pwd, setPwd] = useState("");

  console.log("%c Line:21 🍞 banner", "color:#ea7e5c", banner);

  return (
    <div
      style={{ backgroundImage: `url(${banner})` }}
      className="q-w-full q-h-full q-bg-no-repeat q-bg-center q-bg-cover q-shadow-lg q-rounded-lg"
    >
      <div className="q-absolute q-w-[320px] q-p-10 q-shadow-md q-rounded-xl q-mt-48 q-left-1/2 q-ml-[-160px] q-text-center q-bg-[#e9ecef88]">
        <div className="q-text-center  ">
          <div>
            <div className="q-w-[4em] q-inline-block q-text-black">
              设备号：
            </div>
            <Input
              className="q-inline-block q-w-[200px]"
              value={code}
              onChange={(v) => setCode(v.target.value)}
            />
          </div>
        </div>
        {pwd && (
          <div className="q-text-center q-mt-4 ">
            <div>
              <div className="q-w-[4em] q-inline-block q-text-black">
                秘钥：
              </div>
              <div className="q-inline-block q-w-[200px]">
                <Paragraph
                  copyable={{
                    text: pwd,
                    tooltips: ["点击复制", "已复制到剪切板"],
                  }}
                >
                  {pwd}
                </Paragraph>
              </div>
            </div>
          </div>
        )}

        <div className="q-text-center q-mt-2">
          <Button
            className="q-mt-2"
            type="primary"
            onClick={() => {
              setPwd(encode(code));
            }}
          >
            生成秘钥
          </Button>
        </div>
      </div>
      <div className="q-absolute q-bottom-10 q-left-0 q-w-full q-text-center">
        <div className=" q-text-white">
          Copyright © 2024
          <a className=" q-text-white" href="https://www.qingwanshui.com/">
            青岛清万水技术有限公司
          </a>
        </div>
      </div>

      <img
        src={bgLogo}
        alt=""
        className=" q-h-[40%] q-absolute q-bottom-[80px] q-right-[10%]"
      />
      <img
        src={qzy}
        alt=""
        className="  q-w-[250px]  q-absolute q-bottom-0 q-left-[15%]"
      />
    </div>
  );
}
