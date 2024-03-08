cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(mycylinderfit)


set(projectDir ../)

set(SRCDIR ${projectDir}/codegen/lib/cylderfit)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../../../public/matlab)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_EXECUTABLE_SUFFIX ".html")

# 添加源文件
set(SRCDIR
    ${SRCDIR}/mycylderfit_data.c
    ${SRCDIR}/rt_nonfinite.c
    ${SRCDIR}/rtGetNaN.c
    ${SRCDIR}/rtGetInf.c
    ${SRCDIR}/mycylderfit_initialize.c
    ${SRCDIR}/mycylderfit_terminate.c
    ${SRCDIR}/mycylderfit.c
    ${SRCDIR}/pointCloud.c
    ${SRCDIR}/pca.c
    ${SRCDIR}/xzsvdc.c
    ${SRCDIR}/xnrm2.c
    ${SRCDIR}/svd.c
    ${SRCDIR}/minOrMax.c
    ${SRCDIR}/pctransform.c
    ${SRCDIR}/pointCloudBase.c
    ${SRCDIR}/pinv.c
    ${SRCDIR}/xdotc.c
    ${SRCDIR}/xaxpy.c
    ${SRCDIR}/xrotg.c
    ${SRCDIR}/xrot.c
    ${SRCDIR}/xswap.c
    ${SRCDIR}/mycylderfit_emxutil.c
    ${SRCDIR}/mycylderfit_emxAPI.c
)
# /Users/alsc/myFile/quanzhaunyi/cSource
# 设置头文件路径

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    # ${CMAKE_CURRENT_SOURCE_DIR}/examples
    ${projectDir}/cSource/extern/include
    ${projectDir}/cSource/vision/include
    ${projectDir}/cSource/vision/export/include/vision
)

# add_executable(mycylinderfit2 examples/main.c)

# 生成静态库
add_library(mycylinderfit STATIC ${SRCDIR})

# 链接外部库
target_link_libraries(mycylinderfit 
    ${projectDir}/cSource/extern/lib/win64/microsoft/libmwkdtree.lib
)
