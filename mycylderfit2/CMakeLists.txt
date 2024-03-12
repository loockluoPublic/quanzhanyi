cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(mycylinderfit2)


set(ROOT /src)

set(SRCDIR ${ROOT}/mycylderfit2)

# set(CMAKE_BINARY_DIR ${ROOT}/public/matlab)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(CMAKE_EXECUTABLE_SUFFIX ".html")
MESSAGE(${ROOT})

file(GLOB SOURCES "${SRCDIR}/*.c" )


include_directories(
    ${SRCDIR}
    ${SRCDIR}/interface
    ${ROOT}/cSource/extern/include
    ${ROOT}/cSource/vision/include
    ${ROOT}/cSource/vision/export/include/vision
)

add_executable(mycylinderfit    ${SOURCES}   )
# # 生成静态库
# add_library(mycylinderfit STATIC ${SOURCES})

