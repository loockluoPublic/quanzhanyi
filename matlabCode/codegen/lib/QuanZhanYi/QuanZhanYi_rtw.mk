###########################################################################
## Makefile generated for component 'QuanZhanYi'. 
## 
## Makefile     : QuanZhanYi_rtw.mk
## Generated on : Sun Dec 08 18:48:25 2024
## Final product: ./QuanZhanYi.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = QuanZhanYi
MAKEFILE                  = QuanZhanYi_rtw.mk
MATLAB_ROOT               = E:/SystemInstallation/matlab2023b
MATLAB_BIN                = E:/SystemInstallation/matlab2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/XWT/Desktop/zongQZY/test3
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
CMD_FILE                  = QuanZhanYi_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = QuanZhanYi.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = "$(CC_PATH)/lcc64"

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = "$(LD_PATH)/lcclnk64"

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = "$(AR_PATH)/lcclib64"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./QuanZhanYi.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/QuanZhanYi -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=QuanZhanYi

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_data.c $(START_DIR)/codegen/lib/QuanZhanYi/rt_nonfinite.c $(START_DIR)/codegen/lib/QuanZhanYi/rtGetNaN.c $(START_DIR)/codegen/lib/QuanZhanYi/rtGetInf.c $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_initialize.c $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_terminate.c $(START_DIR)/codegen/lib/QuanZhanYi/angle2point.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_A_and_B_Points.c $(START_DIR)/codegen/lib/QuanZhanYi/norm.c $(START_DIR)/codegen/lib/QuanZhanYi/dot.c $(START_DIR)/codegen/lib/QuanZhanYi/pinv.c $(START_DIR)/codegen/lib/QuanZhanYi/svd.c $(START_DIR)/codegen/lib/QuanZhanYi/xnrm2.c $(START_DIR)/codegen/lib/QuanZhanYi/xdotc.c $(START_DIR)/codegen/lib/QuanZhanYi/mtimes.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_A_and_B_Points_after_Offest2.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_JuXing_A_and_B_Points_after_Offest.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_accurate_cylinders_from_multiple_measurement_points2.c $(START_DIR)/codegen/lib/QuanZhanYi/svd1.c $(START_DIR)/codegen/lib/QuanZhanYi/xzsvdc.c $(START_DIR)/codegen/lib/QuanZhanYi/mldivide.c $(START_DIR)/codegen/lib/QuanZhanYi/ixfun.c $(START_DIR)/codegen/lib/QuanZhanYi/combineVectorElements.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_rectangle_from_vertex.c $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_rectangle_from_vertex8.c $(START_DIR)/codegen/lib/QuanZhanYi/planefit8.c $(START_DIR)/codegen/lib/QuanZhanYi/planefit4.c $(START_DIR)/codegen/lib/QuanZhanYi/nchoosek.c $(START_DIR)/codegen/lib/QuanZhanYi/find.c $(START_DIR)/codegen/lib/QuanZhanYi/mean.c $(START_DIR)/codegen/lib/QuanZhanYi/polyfit.c $(START_DIR)/codegen/lib/QuanZhanYi/minOrMax.c $(START_DIR)/codegen/lib/QuanZhanYi/CrossLine.c $(START_DIR)/codegen/lib/QuanZhanYi/GenerateTrianglePoints.c $(START_DIR)/codegen/lib/QuanZhanYi/validate_print_arguments.c $(START_DIR)/codegen/lib/QuanZhanYi/rand.c $(START_DIR)/codegen/lib/QuanZhanYi/foot_of_perpendicular_from_a_point_to_a_line.c $(START_DIR)/codegen/lib/QuanZhanYi/fitcircle.c $(START_DIR)/codegen/lib/QuanZhanYi/Generate_multi_layered_measurement_points.c $(START_DIR)/codegen/lib/QuanZhanYi/generate_unit_circle_with_normal_vector.c $(START_DIR)/codegen/lib/QuanZhanYi/generate_unit_circle_with_normal_vector2.c $(START_DIR)/codegen/lib/QuanZhanYi/JuXingFuCe.c $(START_DIR)/codegen/lib/QuanZhanYi/prod.c $(START_DIR)/codegen/lib/QuanZhanYi/myvrrotvec2mat.c $(START_DIR)/codegen/lib/QuanZhanYi/OffsetCalculate.c $(START_DIR)/codegen/lib/QuanZhanYi/planefit.c $(START_DIR)/codegen/lib/QuanZhanYi/RepeatSurvey.c $(START_DIR)/codegen/lib/QuanZhanYi/ShengDaoGaoDu.c $(START_DIR)/codegen/lib/QuanZhanYi/ShengLuJiaoJiSuan.c $(START_DIR)/codegen/lib/QuanZhanYi/YuanXingFuCe.c $(START_DIR)/codegen/lib/QuanZhanYi/YuanZhuJiaoDian.c $(START_DIR)/codegen/lib/QuanZhanYi/xgeev.c $(START_DIR)/codegen/lib/QuanZhanYi/eml_rand_mt19937ar_stateful.c $(START_DIR)/codegen/lib/QuanZhanYi/xaxpy.c $(START_DIR)/codegen/lib/QuanZhanYi/xrotg.c $(START_DIR)/codegen/lib/QuanZhanYi/xrot.c $(START_DIR)/codegen/lib/QuanZhanYi/xswap.c $(START_DIR)/codegen/lib/QuanZhanYi/sortrows.c $(START_DIR)/codegen/lib/QuanZhanYi/xgeqp3.c $(START_DIR)/codegen/lib/QuanZhanYi/xzgebal.c $(START_DIR)/codegen/lib/QuanZhanYi/xdlahqr.c $(START_DIR)/codegen/lib/QuanZhanYi/xzlascl.c $(START_DIR)/codegen/lib/QuanZhanYi/eml_mtimes_helper.c $(START_DIR)/codegen/lib/QuanZhanYi/cat.c $(START_DIR)/codegen/lib/QuanZhanYi/unsafeSxfun.c $(START_DIR)/codegen/lib/QuanZhanYi/div.c $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_emxutil.c $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_emxAPI.c $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = QuanZhanYi_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj QuanZhanYi_initialize.obj QuanZhanYi_terminate.obj angle2point.obj Calculat_A_and_B_Points.obj norm.obj dot.obj pinv.obj svd.obj xnrm2.obj xdotc.obj mtimes.obj Calculat_A_and_B_Points_after_Offest2.obj Calculat_JuXing_A_and_B_Points_after_Offest.obj Calculate_accurate_cylinders_from_multiple_measurement_points2.obj svd1.obj xzsvdc.obj mldivide.obj ixfun.obj combineVectorElements.obj Calculate_rectangle_from_vertex.obj Calculate_rectangle_from_vertex8.obj planefit8.obj planefit4.obj nchoosek.obj find.obj mean.obj polyfit.obj minOrMax.obj CrossLine.obj GenerateTrianglePoints.obj validate_print_arguments.obj rand.obj foot_of_perpendicular_from_a_point_to_a_line.obj fitcircle.obj Generate_multi_layered_measurement_points.obj generate_unit_circle_with_normal_vector.obj generate_unit_circle_with_normal_vector2.obj JuXingFuCe.obj prod.obj myvrrotvec2mat.obj OffsetCalculate.obj planefit.obj RepeatSurvey.obj ShengDaoGaoDu.obj ShengLuJiaoJiSuan.obj YuanXingFuCe.obj YuanZhuJiaoDian.obj xgeev.obj eml_rand_mt19937ar_stateful.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj sortrows.obj xgeqp3.obj xzgebal.obj xdlahqr.obj xzlascl.obj eml_mtimes_helper.obj cat.obj unsafeSxfun.obj div.obj QuanZhanYi_emxutil.obj QuanZhanYi_emxAPI.obj QuanZhanYi_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) /out:$(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/codegen/lib/QuanZhanYi/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_data.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/codegen/lib/QuanZhanYi/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/codegen/lib/QuanZhanYi/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/codegen/lib/QuanZhanYi/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_initialize.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_terminate.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


angle2point.obj : $(START_DIR)/codegen/lib/QuanZhanYi/angle2point.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_A_and_B_Points.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_A_and_B_Points.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


norm.obj : $(START_DIR)/codegen/lib/QuanZhanYi/norm.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


dot.obj : $(START_DIR)/codegen/lib/QuanZhanYi/dot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pinv.obj : $(START_DIR)/codegen/lib/QuanZhanYi/pinv.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


svd.obj : $(START_DIR)/codegen/lib/QuanZhanYi/svd.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xnrm2.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdotc.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xdotc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mtimes.obj : $(START_DIR)/codegen/lib/QuanZhanYi/mtimes.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_A_and_B_Points_after_Offest2.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_A_and_B_Points_after_Offest2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_JuXing_A_and_B_Points_after_Offest.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculat_JuXing_A_and_B_Points_after_Offest.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_accurate_cylinders_from_multiple_measurement_points2.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_accurate_cylinders_from_multiple_measurement_points2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


svd1.obj : $(START_DIR)/codegen/lib/QuanZhanYi/svd1.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzsvdc.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xzsvdc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mldivide.obj : $(START_DIR)/codegen/lib/QuanZhanYi/mldivide.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ixfun.obj : $(START_DIR)/codegen/lib/QuanZhanYi/ixfun.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


combineVectorElements.obj : $(START_DIR)/codegen/lib/QuanZhanYi/combineVectorElements.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_rectangle_from_vertex.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_rectangle_from_vertex.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_rectangle_from_vertex8.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Calculate_rectangle_from_vertex8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit8.obj : $(START_DIR)/codegen/lib/QuanZhanYi/planefit8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit4.obj : $(START_DIR)/codegen/lib/QuanZhanYi/planefit4.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nchoosek.obj : $(START_DIR)/codegen/lib/QuanZhanYi/nchoosek.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


find.obj : $(START_DIR)/codegen/lib/QuanZhanYi/find.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mean.obj : $(START_DIR)/codegen/lib/QuanZhanYi/mean.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


polyfit.obj : $(START_DIR)/codegen/lib/QuanZhanYi/polyfit.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


minOrMax.obj : $(START_DIR)/codegen/lib/QuanZhanYi/minOrMax.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


CrossLine.obj : $(START_DIR)/codegen/lib/QuanZhanYi/CrossLine.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


GenerateTrianglePoints.obj : $(START_DIR)/codegen/lib/QuanZhanYi/GenerateTrianglePoints.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


validate_print_arguments.obj : $(START_DIR)/codegen/lib/QuanZhanYi/validate_print_arguments.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rand.obj : $(START_DIR)/codegen/lib/QuanZhanYi/rand.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


foot_of_perpendicular_from_a_point_to_a_line.obj : $(START_DIR)/codegen/lib/QuanZhanYi/foot_of_perpendicular_from_a_point_to_a_line.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


fitcircle.obj : $(START_DIR)/codegen/lib/QuanZhanYi/fitcircle.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Generate_multi_layered_measurement_points.obj : $(START_DIR)/codegen/lib/QuanZhanYi/Generate_multi_layered_measurement_points.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


generate_unit_circle_with_normal_vector.obj : $(START_DIR)/codegen/lib/QuanZhanYi/generate_unit_circle_with_normal_vector.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


generate_unit_circle_with_normal_vector2.obj : $(START_DIR)/codegen/lib/QuanZhanYi/generate_unit_circle_with_normal_vector2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


JuXingFuCe.obj : $(START_DIR)/codegen/lib/QuanZhanYi/JuXingFuCe.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


prod.obj : $(START_DIR)/codegen/lib/QuanZhanYi/prod.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


myvrrotvec2mat.obj : $(START_DIR)/codegen/lib/QuanZhanYi/myvrrotvec2mat.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


OffsetCalculate.obj : $(START_DIR)/codegen/lib/QuanZhanYi/OffsetCalculate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit.obj : $(START_DIR)/codegen/lib/QuanZhanYi/planefit.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


RepeatSurvey.obj : $(START_DIR)/codegen/lib/QuanZhanYi/RepeatSurvey.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ShengDaoGaoDu.obj : $(START_DIR)/codegen/lib/QuanZhanYi/ShengDaoGaoDu.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ShengLuJiaoJiSuan.obj : $(START_DIR)/codegen/lib/QuanZhanYi/ShengLuJiaoJiSuan.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


YuanXingFuCe.obj : $(START_DIR)/codegen/lib/QuanZhanYi/YuanXingFuCe.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


YuanZhuJiaoDian.obj : $(START_DIR)/codegen/lib/QuanZhanYi/YuanZhuJiaoDian.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xgeev.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xgeev.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/codegen/lib/QuanZhanYi/eml_rand_mt19937ar_stateful.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xaxpy.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xaxpy.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrotg.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xrotg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrot.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xrot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xswap.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xswap.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sortrows.obj : $(START_DIR)/codegen/lib/QuanZhanYi/sortrows.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xgeqp3.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xgeqp3.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzgebal.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xzgebal.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdlahqr.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xdlahqr.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlascl.obj : $(START_DIR)/codegen/lib/QuanZhanYi/xzlascl.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eml_mtimes_helper.obj : $(START_DIR)/codegen/lib/QuanZhanYi/eml_mtimes_helper.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cat.obj : $(START_DIR)/codegen/lib/QuanZhanYi/cat.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


unsafeSxfun.obj : $(START_DIR)/codegen/lib/QuanZhanYi/unsafeSxfun.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


div.obj : $(START_DIR)/codegen/lib/QuanZhanYi/div.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_emxutil.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_emxAPI.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_emxAPI.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_rtwutil.obj : $(START_DIR)/codegen/lib/QuanZhanYi/QuanZhanYi_rtwutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


