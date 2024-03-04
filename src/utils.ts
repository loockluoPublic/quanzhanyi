// var factory = require("./matlab/apb.js");
import * as factory from "./matlab/apb.js";

import * as wasmModule from "./matlab/apb.wasm";
console.log("%c Line:3 🌽 factory", "color:#fca650", wasmModule.apb(1, 2));

// factory().then((instance) => {
//   console.log("%c Line:4 🧀 instance", "color:#33a5ff", instance);
// });
