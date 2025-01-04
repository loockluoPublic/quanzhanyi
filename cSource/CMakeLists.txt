cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(mycylinderfit2)


set(ROOT /src)

set(SRCDIR ${ROOT}/matlabBuild)

set(EXECUTABLE_OUTPUT_PATH ${ROOT}/public)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
# 设置编译参数
# set(CMAKE_CXX_FLAGS "-s EXTRA_EXPORTED_RUNTIME_METHODS=['addFunction']")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}  -g4 --source-map-base http://localhost:5173/ -s ALLOW_MEMORY_GROWTH -s EXPORTED_FUNCTIONS=['getValue','setValue','setValue','_malloc','_free'] -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")

# 获取所有默认变量
get_cmake_property(_variableNames CACHE_VARIABLES)

# 遍历并打印所有默认变量
foreach(_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

message(编译器       ${CMAKE_CXX_COMPILER})
message(编译工具链   ${CMAKE_TOOLCHAIN_FILE})
message(输出文件夹   ${EXECUTABLE_OUTPUT_PATH})
message(库输出文件夹   ${LIBRARY_OUTPUT_PATH})
# message(${CMAKE_CXX_FLAGS})


file(GLOB SOURCES "${SRCDIR}/*.c" )


include_directories(
    ${SRCDIR}
    ${SRCDIR}/interface
    ${ROOT}/cSource/extern/include
    ${ROOT}/cSource/vision/include
    ${ROOT}/cSource/vision/export/include/vision
)

add_executable(mycylinderfit    ${SOURCES}  "main.c"  )

