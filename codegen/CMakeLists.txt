cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(SRC lib/cylderfit)
set(ROOT ../)


include_directories(
    # ${CMAKE_CURRENT_SOURCE_DIR}/examples
    ${SRC}
    ${ROOT}/cSource/extern/include
    ${ROOT}/cSource/vision/include
    ${ROOT}/cSource/vision/export/include/vision
    )

# 添加可执行文件
add_executable(MyExecutable ${SRC}/examples/main.c)

# 添加头文件路径
target_include_directories(MyExecutable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/examples)



# 添加其他依赖项
# target_link_libraries(MyExecutable some_library)

# 设置编译选项
# target_compile_options(MyExecutable PRIVATE -Wall -Wextra)

# 设置安装规则
# install(TARGETS MyExecutable DESTINATION bin)
