cmake_minimum_required(VERSION 3.10)

project(quanzhanyi)

# 设置构建目录
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXECUTABLE_SUFFIX ".html") # 编译生成.html

# 设置源文件目录
set(SRC_DIR "./")
set(LIB_DIR "../codegen/lib/cylderfit")
set(INC_DIR "../codegen/lib/cylderfit/interface" 
    "../codegen/lib/cylderfit"
    "./include"
)
# 查找所有源文件
file(GLOB SOURCES "${SRC_DIR}/*.c")

# 添加头文件目录
include_directories(${INC_DIR})

# 生成可执行文件
add_executable(quanzhanyi ${SOURCES})

# # 添加链接库
# add_subdirectory(${LIB_DIR})
# target_link_libraries(quanzhanyi mylib)
