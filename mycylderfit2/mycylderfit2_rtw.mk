###########################################################################
## Makefile generated for component 'mycylderfit2'. 
## 
## Makefile     : mycylderfit2_rtw.mk
## Generated on : Mon Mar 11 23:25:00 2024
## Final product: ./mycylderfit2.lib
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

PRODUCT_NAME              = mycylderfit2
MAKEFILE                  = mycylderfit2_rtw.mk
MATLAB_ROOT               = E:/SystemInstallation/Matlab
MATLAB_BIN                = E:/SystemInstallation/Matlab/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/XWT/Desktop/qzy_matlab/codegen/lib/mycylderfit2
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
CMD_FILE                  = mycylderfit2_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = mycylderfit2.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2021a
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

PRODUCT = ./mycylderfit2.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/Users/XWT/Desktop/QZY_MA~1 -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=mycylderfit2

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/mycylderfit2_data.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/mycylderfit2_initialize.c $(START_DIR)/mycylderfit2_terminate.c $(START_DIR)/mycylderfit2.c $(START_DIR)/pinv.c $(START_DIR)/svd.c $(START_DIR)/xnrm2.c $(START_DIR)/xdotc.c $(START_DIR)/minOrMax.c $(START_DIR)/xaxpy.c $(START_DIR)/xrotg.c $(START_DIR)/xrot.c $(START_DIR)/xswap.c $(START_DIR)/mycylderfit2_emxutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = mycylderfit2_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj mycylderfit2_initialize.obj mycylderfit2_terminate.obj mycylderfit2.obj pinv.obj svd.obj xnrm2.obj xdotc.obj minOrMax.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj mycylderfit2_emxutil.obj

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


%.obj : C:/Users/XWT/Desktop/qzy_matlab/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mycylderfit2_data.obj : $(START_DIR)/mycylderfit2_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mycylderfit2_initialize.obj : $(START_DIR)/mycylderfit2_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mycylderfit2_terminate.obj : $(START_DIR)/mycylderfit2_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mycylderfit2.obj : $(START_DIR)/mycylderfit2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pinv.obj : $(START_DIR)/pinv.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


svd.obj : $(START_DIR)/svd.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xnrm2.obj : $(START_DIR)/xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdotc.obj : $(START_DIR)/xdotc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


minOrMax.obj : $(START_DIR)/minOrMax.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xaxpy.obj : $(START_DIR)/xaxpy.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrotg.obj : $(START_DIR)/xrotg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xrot.obj : $(START_DIR)/xrot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xswap.obj : $(START_DIR)/xswap.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mycylderfit2_emxutil.obj : $(START_DIR)/mycylderfit2_emxutil.c
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
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


