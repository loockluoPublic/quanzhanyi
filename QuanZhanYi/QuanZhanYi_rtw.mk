###########################################################################
## Makefile generated for component 'QuanZhanYi'. 
## 
## Makefile     : QuanZhanYi_rtw.mk
## Generated on : Sun Jun 30 16:41:35 2024
## Final product: .\QuanZhanYi.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = QuanZhanYi
MAKEFILE                  = QuanZhanYi_rtw.mk
MATLAB_ROOT               = D:\Program Files\MATLAB\R2022a
MATLAB_BIN                = D:\Program Files\MATLAB\R2022a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\DELLPC\Desktop\test3
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ..\..\..
COMPILER_COMMAND_FILE     = QuanZhanYi_rtw_comp.rsp
CMD_FILE                  = QuanZhanYi_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = QuanZhanYi.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2022 v17.0 | nmake (64-bit Windows)
# Supported Version(s):    17.0
# ToolchainInfo Version:   2022a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251 /Zc:__cplusplus
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\QuanZhanYi.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

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

SRCS = $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_data.c $(START_DIR)\codegen\lib\QuanZhanYi\rt_nonfinite.c $(START_DIR)\codegen\lib\QuanZhanYi\rtGetNaN.c $(START_DIR)\codegen\lib\QuanZhanYi\rtGetInf.c $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_initialize.c $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_terminate.c $(START_DIR)\codegen\lib\QuanZhanYi\angle2point.c $(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points.c $(START_DIR)\codegen\lib\QuanZhanYi\norm.c $(START_DIR)\codegen\lib\QuanZhanYi\pinv.c $(START_DIR)\codegen\lib\QuanZhanYi\svd.c $(START_DIR)\codegen\lib\QuanZhanYi\xnrm2.c $(START_DIR)\codegen\lib\QuanZhanYi\xdotc.c $(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points_after_Offest.c $(START_DIR)\codegen\lib\QuanZhanYi\Calculate_accurate_cylinders_from_multiple_measurement_points2.c $(START_DIR)\codegen\lib\QuanZhanYi\mldivide.c $(START_DIR)\codegen\lib\QuanZhanYi\qrsolve.c $(START_DIR)\codegen\lib\QuanZhanYi\ixfun.c $(START_DIR)\codegen\lib\QuanZhanYi\mean.c $(START_DIR)\codegen\lib\QuanZhanYi\CrossLine.c $(START_DIR)\codegen\lib\QuanZhanYi\fitcircle.c $(START_DIR)\codegen\lib\QuanZhanYi\foot_of_perpendicular_from_a_point_to_a_line.c $(START_DIR)\codegen\lib\QuanZhanYi\Generate_multi_layered_measurement_points.c $(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector.c $(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector2.c $(START_DIR)\codegen\lib\QuanZhanYi\GenerateTrianglePoints.c $(START_DIR)\codegen\lib\QuanZhanYi\myvrrotvec2mat.c $(START_DIR)\codegen\lib\QuanZhanYi\planefit.c $(START_DIR)\codegen\lib\QuanZhanYi\polyfit.c $(START_DIR)\codegen\lib\QuanZhanYi\minOrMax.c $(START_DIR)\codegen\lib\QuanZhanYi\RepeatSurvey.c $(START_DIR)\codegen\lib\QuanZhanYi\xaxpy.c $(START_DIR)\codegen\lib\QuanZhanYi\xrotg.c $(START_DIR)\codegen\lib\QuanZhanYi\xrot.c $(START_DIR)\codegen\lib\QuanZhanYi\xswap.c $(START_DIR)\codegen\lib\QuanZhanYi\unsafeSxfun.c $(START_DIR)\codegen\lib\QuanZhanYi\cat.c $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxutil.c $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxAPI.c $(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = QuanZhanYi_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj QuanZhanYi_initialize.obj QuanZhanYi_terminate.obj angle2point.obj Calculat_A_and_B_Points.obj norm.obj pinv.obj svd.obj xnrm2.obj xdotc.obj Calculat_A_and_B_Points_after_Offest.obj Calculate_accurate_cylinders_from_multiple_measurement_points2.obj mldivide.obj qrsolve.obj ixfun.obj mean.obj CrossLine.obj fitcircle.obj foot_of_perpendicular_from_a_point_to_a_line.obj Generate_multi_layered_measurement_points.obj generate_unit_circle_with_normal_vector.obj generate_unit_circle_with_normal_vector2.obj GenerateTrianglePoints.obj myvrrotvec2mat.obj planefit.obj polyfit.obj minOrMax.obj RepeatSurvey.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj unsafeSxfun.obj cat.obj QuanZhanYi_emxutil.obj QuanZhanYi_emxAPI.obj QuanZhanYi_rtwutil.obj

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

CFLAGS_ = /source-charset:utf-8
CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = /source-charset:utf-8
CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\QuanZhanYi}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\QuanZhanYi}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


QuanZhanYi_data.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_data.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_data.c"


rt_nonfinite.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\rt_nonfinite.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\rt_nonfinite.c"


rtGetNaN.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\rtGetNaN.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\rtGetNaN.c"


rtGetInf.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\rtGetInf.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\rtGetInf.c"


QuanZhanYi_initialize.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_initialize.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_initialize.c"


QuanZhanYi_terminate.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_terminate.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_terminate.c"


angle2point.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\angle2point.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\angle2point.c"


Calculat_A_and_B_Points.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points.c"


norm.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\norm.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\norm.c"


pinv.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\pinv.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\pinv.c"


svd.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\svd.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\svd.c"


xnrm2.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xnrm2.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xnrm2.c"


xdotc.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xdotc.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xdotc.c"


Calculat_A_and_B_Points_after_Offest.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points_after_Offest.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\Calculat_A_and_B_Points_after_Offest.c"


Calculate_accurate_cylinders_from_multiple_measurement_points2.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\Calculate_accurate_cylinders_from_multiple_measurement_points2.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\Calculate_accurate_cylinders_from_multiple_measurement_points2.c"


mldivide.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\mldivide.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\mldivide.c"


qrsolve.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\qrsolve.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\qrsolve.c"


ixfun.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\ixfun.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\ixfun.c"


mean.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\mean.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\mean.c"


CrossLine.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\CrossLine.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\CrossLine.c"


fitcircle.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\fitcircle.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\fitcircle.c"


foot_of_perpendicular_from_a_point_to_a_line.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\foot_of_perpendicular_from_a_point_to_a_line.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\foot_of_perpendicular_from_a_point_to_a_line.c"


Generate_multi_layered_measurement_points.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\Generate_multi_layered_measurement_points.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\Generate_multi_layered_measurement_points.c"


generate_unit_circle_with_normal_vector.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector.c"


generate_unit_circle_with_normal_vector2.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector2.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\generate_unit_circle_with_normal_vector2.c"


GenerateTrianglePoints.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\GenerateTrianglePoints.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\GenerateTrianglePoints.c"


myvrrotvec2mat.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\myvrrotvec2mat.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\myvrrotvec2mat.c"


planefit.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\planefit.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\planefit.c"


polyfit.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\polyfit.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\polyfit.c"


minOrMax.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\minOrMax.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\minOrMax.c"


RepeatSurvey.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\RepeatSurvey.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\RepeatSurvey.c"


xaxpy.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xaxpy.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xaxpy.c"


xrotg.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xrotg.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xrotg.c"


xrot.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xrot.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xrot.c"


xswap.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\xswap.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\xswap.c"


unsafeSxfun.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\unsafeSxfun.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\unsafeSxfun.c"


cat.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\cat.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\cat.c"


QuanZhanYi_emxutil.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxutil.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxutil.c"


QuanZhanYi_emxAPI.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxAPI.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_emxAPI.c"


QuanZhanYi_rtwutil.obj : "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_rtwutil.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\QuanZhanYi\QuanZhanYi_rtwutil.c"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


