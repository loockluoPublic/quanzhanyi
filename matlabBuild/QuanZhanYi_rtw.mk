###########################################################################
## Makefile generated for component 'QuanZhanYi'. 
## 
## Makefile     : QuanZhanYi_rtw.mk
## Generated on : Mon Mar 10 22:42:00 2025
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
START_DIR                 = C:/Users/XWT/Desktop/quanzhanyi2/matlabBuild
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
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

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/Users/XWT/Desktop/QUANZH~2/zongQZY/test3 -I$(MATLAB_ROOT)/extern/include

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

SRCS = $(START_DIR)/QuanZhanYi_data.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/QuanZhanYi_initialize.c $(START_DIR)/QuanZhanYi_terminate.c $(START_DIR)/angle2point.c $(START_DIR)/Calculat_A_and_B_Points.c $(START_DIR)/norm.c $(START_DIR)/dot.c $(START_DIR)/pinv.c $(START_DIR)/svd.c $(START_DIR)/xnrm2.c $(START_DIR)/xdotc.c $(START_DIR)/Calculat_A_and_B_Points_after_Offest2.c $(START_DIR)/Calculat_JuXing_A_and_B_Points_after_Offest.c $(START_DIR)/mtimes.c $(START_DIR)/Calculate_accurate_cylinders_from_multiple_measurement_points2.c $(START_DIR)/svd1.c $(START_DIR)/xzsvdc.c $(START_DIR)/mldivide.c $(START_DIR)/ixfun.c $(START_DIR)/combineVectorElements.c $(START_DIR)/Calculate_rectangle_from_vertex.c $(START_DIR)/Calculate_rectangle_from_vertex8.c $(START_DIR)/planefit4.c $(START_DIR)/nchoosek.c $(START_DIR)/find.c $(START_DIR)/mean.c $(START_DIR)/polyfit.c $(START_DIR)/minOrMax.c $(START_DIR)/CrossLine.c $(START_DIR)/GenerateTrianglePoints.c $(START_DIR)/planefit8.c $(START_DIR)/validate_print_arguments.c $(START_DIR)/rand.c $(START_DIR)/foot_of_perpendicular_from_a_point_to_a_line.c $(START_DIR)/fitcircle.c $(START_DIR)/Generate_multi_layered_measurement_points.c $(START_DIR)/generate_unit_circle_with_normal_vector.c $(START_DIR)/generate_unit_circle_with_normal_vector2.c $(START_DIR)/JuXingFuCe.c $(START_DIR)/prod.c $(START_DIR)/myvrrotvec2mat.c $(START_DIR)/OffsetCalculate.c $(START_DIR)/planefit.c $(START_DIR)/RepeatSurvey.c $(START_DIR)/ShengDaoGaoDu.c $(START_DIR)/ShengLuJiaoJiSuan.c $(START_DIR)/YuanXingFuCe.c $(START_DIR)/YuanZhuJiaoDian.c $(START_DIR)/xgeev.c $(START_DIR)/eml_rand_mt19937ar_stateful.c $(START_DIR)/xaxpy.c $(START_DIR)/xrotg.c $(START_DIR)/xrot.c $(START_DIR)/xswap.c $(START_DIR)/xgeqp3.c $(START_DIR)/xzgebal.c $(START_DIR)/xdlahqr.c $(START_DIR)/xzlascl.c $(START_DIR)/unsafeSxfun.c $(START_DIR)/cat.c $(START_DIR)/div.c $(START_DIR)/QuanZhanYi_emxutil.c $(START_DIR)/QuanZhanYi_emxAPI.c $(START_DIR)/QuanZhanYi_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = QuanZhanYi_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj QuanZhanYi_initialize.obj QuanZhanYi_terminate.obj angle2point.obj Calculat_A_and_B_Points.obj norm.obj dot.obj pinv.obj svd.obj xnrm2.obj xdotc.obj Calculat_A_and_B_Points_after_Offest2.obj Calculat_JuXing_A_and_B_Points_after_Offest.obj mtimes.obj Calculate_accurate_cylinders_from_multiple_measurement_points2.obj svd1.obj xzsvdc.obj mldivide.obj ixfun.obj combineVectorElements.obj Calculate_rectangle_from_vertex.obj Calculate_rectangle_from_vertex8.obj planefit4.obj nchoosek.obj find.obj mean.obj polyfit.obj minOrMax.obj CrossLine.obj GenerateTrianglePoints.obj planefit8.obj validate_print_arguments.obj rand.obj foot_of_perpendicular_from_a_point_to_a_line.obj fitcircle.obj Generate_multi_layered_measurement_points.obj generate_unit_circle_with_normal_vector.obj generate_unit_circle_with_normal_vector2.obj JuXingFuCe.obj prod.obj myvrrotvec2mat.obj OffsetCalculate.obj planefit.obj RepeatSurvey.obj ShengDaoGaoDu.obj ShengLuJiaoJiSuan.obj YuanXingFuCe.obj YuanZhuJiaoDian.obj xgeev.obj eml_rand_mt19937ar_stateful.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj xgeqp3.obj xzgebal.obj xdlahqr.obj xzlascl.obj unsafeSxfun.obj cat.obj div.obj QuanZhanYi_emxutil.obj QuanZhanYi_emxAPI.obj QuanZhanYi_rtwutil.obj

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


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : C:/Users/XWT/Desktop/quanzhanyi2/zongQZY/test3/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_data.obj : $(START_DIR)/QuanZhanYi_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_initialize.obj : $(START_DIR)/QuanZhanYi_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_terminate.obj : $(START_DIR)/QuanZhanYi_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


angle2point.obj : $(START_DIR)/angle2point.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_A_and_B_Points.obj : $(START_DIR)/Calculat_A_and_B_Points.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


norm.obj : $(START_DIR)/norm.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


dot.obj : $(START_DIR)/dot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pinv.obj : $(START_DIR)/pinv.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


svd.obj : $(START_DIR)/svd.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xnrm2.obj : $(START_DIR)/xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdotc.obj : $(START_DIR)/xdotc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_A_and_B_Points_after_Offest2.obj : $(START_DIR)/Calculat_A_and_B_Points_after_Offest2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculat_JuXing_A_and_B_Points_after_Offest.obj : $(START_DIR)/Calculat_JuXing_A_and_B_Points_after_Offest.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mtimes.obj : $(START_DIR)/mtimes.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_accurate_cylinders_from_multiple_measurement_points2.obj : $(START_DIR)/Calculate_accurate_cylinders_from_multiple_measurement_points2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


svd1.obj : $(START_DIR)/svd1.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzsvdc.obj : $(START_DIR)/xzsvdc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mldivide.obj : $(START_DIR)/mldivide.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ixfun.obj : $(START_DIR)/ixfun.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


combineVectorElements.obj : $(START_DIR)/combineVectorElements.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_rectangle_from_vertex.obj : $(START_DIR)/Calculate_rectangle_from_vertex.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Calculate_rectangle_from_vertex8.obj : $(START_DIR)/Calculate_rectangle_from_vertex8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit4.obj : $(START_DIR)/planefit4.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nchoosek.obj : $(START_DIR)/nchoosek.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


find.obj : $(START_DIR)/find.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mean.obj : $(START_DIR)/mean.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


polyfit.obj : $(START_DIR)/polyfit.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


minOrMax.obj : $(START_DIR)/minOrMax.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


CrossLine.obj : $(START_DIR)/CrossLine.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


GenerateTrianglePoints.obj : $(START_DIR)/GenerateTrianglePoints.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit8.obj : $(START_DIR)/planefit8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


validate_print_arguments.obj : $(START_DIR)/validate_print_arguments.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rand.obj : $(START_DIR)/rand.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


foot_of_perpendicular_from_a_point_to_a_line.obj : $(START_DIR)/foot_of_perpendicular_from_a_point_to_a_line.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


fitcircle.obj : $(START_DIR)/fitcircle.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Generate_multi_layered_measurement_points.obj : $(START_DIR)/Generate_multi_layered_measurement_points.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


generate_unit_circle_with_normal_vector.obj : $(START_DIR)/generate_unit_circle_with_normal_vector.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


generate_unit_circle_with_normal_vector2.obj : $(START_DIR)/generate_unit_circle_with_normal_vector2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


JuXingFuCe.obj : $(START_DIR)/JuXingFuCe.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


prod.obj : $(START_DIR)/prod.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


myvrrotvec2mat.obj : $(START_DIR)/myvrrotvec2mat.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


OffsetCalculate.obj : $(START_DIR)/OffsetCalculate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


planefit.obj : $(START_DIR)/planefit.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


RepeatSurvey.obj : $(START_DIR)/RepeatSurvey.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ShengDaoGaoDu.obj : $(START_DIR)/ShengDaoGaoDu.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ShengLuJiaoJiSuan.obj : $(START_DIR)/ShengLuJiaoJiSuan.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


YuanXingFuCe.obj : $(START_DIR)/YuanXingFuCe.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


YuanZhuJiaoDian.obj : $(START_DIR)/YuanZhuJiaoDian.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xgeev.obj : $(START_DIR)/xgeev.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/eml_rand_mt19937ar_stateful.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xaxpy.obj : $(START_DIR)/xaxpy.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrotg.obj : $(START_DIR)/xrotg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrot.obj : $(START_DIR)/xrot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xswap.obj : $(START_DIR)/xswap.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xgeqp3.obj : $(START_DIR)/xgeqp3.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzgebal.obj : $(START_DIR)/xzgebal.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdlahqr.obj : $(START_DIR)/xdlahqr.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlascl.obj : $(START_DIR)/xzlascl.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


unsafeSxfun.obj : $(START_DIR)/unsafeSxfun.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cat.obj : $(START_DIR)/cat.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


div.obj : $(START_DIR)/div.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_emxutil.obj : $(START_DIR)/QuanZhanYi_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_emxAPI.obj : $(START_DIR)/QuanZhanYi_emxAPI.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


QuanZhanYi_rtwutil.obj : $(START_DIR)/QuanZhanYi_rtwutil.c
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


