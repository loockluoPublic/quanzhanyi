/*
 * cylderfit_data.c
 *
 * Code generation for function 'cylderfit_data'
 *
 */

/* Include files */
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131610U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "cylderfit",                                        /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {892782427U, 3065947397U, 579142498U, 3627885865U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo t_emlrtRSI = {
    33,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

emlrtRSInfo u_emlrtRSI = {
    34,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

emlrtRSInfo v_emlrtRSI = {
    44,                      /* lineNo */
    "pointCloud/pointCloud", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

emlrtRSInfo x_emlrtRSI = {
    87,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

emlrtRSInfo y_emlrtRSI = {
    88,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI = {
    89,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

emlrtRSInfo eb_emlrtRSI = {
    76,                   /* lineNo */
    "validateattributes", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateatt"
    "ributes.m" /* pathName */
};

emlrtRSInfo nc_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_"
    "forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo
    kd_emlrtRSI =
        {
            16,     /* lineNo */
            "sqrt", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sq"
            "rt.m" /* pathName */
};

emlrtRSInfo ld_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

emlrtRSInfo ke_emlrtRSI =
    {
        46,    /* lineNo */
        "eps", /* fcnName */
        "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\eps."
        "m" /* pathName */
};

emlrtRSInfo me_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\sumprod.m" /* pathName */
};

emlrtRSInfo
    gf_emlrtRSI =
        {
            12,    /* lineNo */
            "svd", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\s"
            "vd.m" /* pathName */
};

emlrtRSInfo
    hf_emlrtRSI =
        {
            15,    /* lineNo */
            "svd", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\s"
            "vd.m" /* pathName */
};

emlrtRSInfo if_emlrtRSI = {
    29,             /* lineNo */
    "anyNonFinite", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\anyNonFinite.m" /* pathName */
};

emlrtRSInfo jf_emlrtRSI = {
    44,          /* lineNo */
    "vAllOrAny", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo lf_emlrtRSI = {
    29,    /* lineNo */
    "svd", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\svd."
    "m" /* pathName */
};

emlrtRSInfo mf_emlrtRSI = {
    108,          /* lineNo */
    "callLAPACK", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\svd."
    "m" /* pathName */
};

emlrtRSInfo nf_emlrtRSI = {
    34,       /* lineNo */
    "xgesvd", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

emlrtRSInfo bg_emlrtRSI =
    {
        15,    /* lineNo */
        "max", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\max."
        "m" /* pathName */
};

emlrtRSInfo cg_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\minOrMax.m" /* pathName */
};

emlrtRSInfo dg_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\minOrMax.m" /* pathName */
};

emlrtRSInfo kg_emlrtRSI =
    {
        15,    /* lineNo */
        "min", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\min."
        "m" /* pathName */
};

emlrtRSInfo lg_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\minOrMax.m" /* pathName */
};

emlrtRSInfo mg_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\minOrMax.m" /* pathName */
};

emlrtRSInfo kh_emlrtRSI = {
    91,                  /* lineNo */
    "eml_mtimes_helper", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\eml_"
    "mtimes_helper.m" /* pathName */
};

emlrtRSInfo qh_emlrtRSI = {
    60,                  /* lineNo */
    "eml_mtimes_helper", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\eml_"
    "mtimes_helper.m" /* pathName */
};

emlrtRTEInfo
    emlrtRTEI =
        {
            13,     /* lineNo */
            9,      /* colNo */
            "sqrt", /* fName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sq"
            "rt.m" /* pName */
};

emlrtRTEInfo f_emlrtRTEI = {
    13,               /* lineNo */
    37,               /* colNo */
    "validatescalar", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatescalar.m" /* pName */
};

emlrtRTEInfo t_emlrtRTEI = {
    135,                   /* lineNo */
    23,                    /* colNo */
    "dynamic_size_checks", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\eml_"
    "mtimes_helper.m" /* pName */
};

emlrtRTEInfo u_emlrtRTEI = {
    130,                   /* lineNo */
    23,                    /* colNo */
    "dynamic_size_checks", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\eml_"
    "mtimes_helper.m" /* pName */
};

emlrtRTEInfo mb_emlrtRTEI = {
    85,               /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

covrtInstance emlrtCoverageInstance;

/* End of code generation (cylderfit_data.c) */
