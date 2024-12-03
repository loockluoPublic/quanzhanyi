import { useRecoilState } from "recoil";
import { Data, getInitAgainTable, TType } from "./globalState";
import { useEffect } from "react";
import { appWindow } from "@tauri-apps/api/window";

export function useGlobalEffect() {
  const [data, setData] = useRecoilState(Data);

  useEffect(() => {
    const handleKeyDown = async (event) => {
      if (event.key === "Escape") {
        // 如果按下的是 Esc 键，则退出全屏
        const isFullscreen = await appWindow.isFullscreen();
        if (isFullscreen) {
          await appWindow.setFullscreen(false);
        }
      } else if (event.key === "F11") {
        // 如果按下的是 F11 键，则切换全屏状态
        const isFullscreen = await appWindow.isFullscreen();
        await appWindow.setFullscreen(!isFullscreen);
        // 阻止默认行为（例如浏览器的默认全屏行为）
        event.preventDefault();
      }
    };

    // 添加事件监听器
    window.addEventListener("keydown", handleKeyDown);

    // 在组件卸载时清除事件监听器
    return () => {
      window.removeEventListener("keydown", handleKeyDown);
    };
  }, []); // 空依赖数组表示只在组件挂载和卸载时运行

  useEffect(() => {
    setData((d) => {
      const key =
        d.type === TType.cycle ? "cylinderAgainTable" : "cubeAgainTable";
      return {
        ...d,
        [key]: getInitAgainTable(data.sdfb, data.sdm) as any,
      };
    });
  }, [data.sdfb, data.sdm?.join(""), data.type]);
}
