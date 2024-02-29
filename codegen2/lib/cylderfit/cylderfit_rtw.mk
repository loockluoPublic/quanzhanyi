###########################################################################
## Makefile generated for component 'cylderfit'. 
## 
## Makefile     : cylderfit_rtw.mk
## Generated on : Thu Feb 29 21:50:28 2024
## Final product: ./cylderfit.lib
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

PRODUCT_NAME              = cylderfit
MAKEFILE                  = cylderfit_rtw.mk
MATLAB_ROOT               = E:/SystemInstallation/Matlab
MATLAB_BIN                = E:/SystemInstallation/Matlab/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/XWT/Desktop/codegen/lib/cylderfit
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
CMD_FILE                  = cylderfit_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = cylderfit.lib

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

PRODUCT = ./cylderfit.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/Users/XWT/Desktop -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/toolbox/vision/builtins/src/vision/include -I$(MATLAB_ROOT)/toolbox/vision/builtins/src/vision/export/include/vision

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=cylderfit

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/cylderfit_data.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/cylderfit_initialize.c $(START_DIR)/cylderfit_terminate.c $(START_DIR)/cylderfit.c $(START_DIR)/initializeRansacModel.c $(START_DIR)/find.c $(START_DIR)/msac.c $(START_DIR)/rand.c $(START_DIR)/combineVectorElements.c $(START_DIR)/eml_rand_mt19937ar_stateful.c $(START_DIR)/pcfitcylinder.c $(START_DIR)/cylderfit_emxutil.c $(START_DIR)/cylderfit_emxAPI.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = cylderfit_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj cylderfit_initialize.obj cylderfit_terminate.obj cylderfit.obj initializeRansacModel.obj find.obj msac.obj rand.obj combineVectorElements.obj eml_rand_mt19937ar_stateful.obj pcfitcylinder.obj cylderfit_emxutil.obj cylderfit_emxAPI.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/lib/win64/microsoft/libmwkdtree.lib

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


%.obj : C:/Users/XWT/Desktop/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/vision/builtins/src/vision/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit_data.obj : $(START_DIR)/cylderfit_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit_initialize.obj : $(START_DIR)/cylderfit_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit_terminate.obj : $(START_DIR)/cylderfit_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit.obj : $(START_DIR)/cylderfit.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


initializeRansacModel.obj : $(START_DIR)/initializeRansacModel.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


find.obj : $(START_DIR)/find.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


msac.obj : $(START_DIR)/msac.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rand.obj : $(START_DIR)/rand.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


combineVectorElements.obj : $(START_DIR)/combineVectorElements.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/eml_rand_mt19937ar_stateful.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pcfitcylinder.obj : $(START_DIR)/pcfitcylinder.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit_emxutil.obj : $(START_DIR)/cylderfit_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


cylderfit_emxAPI.obj : $(START_DIR)/cylderfit_emxAPI.c
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


