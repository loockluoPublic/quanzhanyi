#![cfg_attr(
  all(not(debug_assertions), target_os = "windows"),
  windows_subsystem = "windows"
)]

fn main() {
  let context = tauri::generate_context!();
  tauri::Builder::default()
    .menu(if cfg!(target_os = "macos") {
      tauri::Menu::os_default(&context.package_info().name)
    } else {
      tauri::Menu::default()
    })
    .plugin(tauri_plugin_serialport::init())
    .run(context)
    .expect("failed to run app");
}


// use tauri_plugin_serialport;
// // Prevents additional console window on Windows in release, DO NOT REMOVE!!
// // #![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

// fn main() {
//   tauri::Builder::default()
//     .plugin(tauri_plugin_serialport::init())
//     .run(tauri::generate_context!())
//     .expect("error while running tauri application");
// }
