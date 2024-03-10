cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(mycylinderfit)

set(CMAKE_C_STANDARD 11) 

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(SRCDIR ${ROOT}/codegen/lib/cylderfit)

set(CMAKE_BINARY_DIR ${ROOT}/public/matlab)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXECUTABLE_SUFFIX ".html")

MESSAGE(${CMAKE_CURRENT_SOURCE_DIR})

# file(GLOB SOURCES "${SRCDIR}/*.c" )



include_directories(
    ${SRCDIR}
    ${SRCDIR}/interface
    ${ROOT}/cSource/extern/include
    ${ROOT}/cSource/vision/include
    ${ROOT}/cSource/vision/export/include/vision
)

# # # # 生成静态库
# add_library(mycylinderfit STATIC ${SOURCES})


add_executable(main   main.c  )

link_directories(${ROOT}/codegen)

target_link_libraries(main  ${ROOT}/codegen/libmycylinderfit.a)