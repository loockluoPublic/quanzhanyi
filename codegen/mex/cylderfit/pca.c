/*
 * pca.c
 *
 * Code generation for function 'pca'
 *
 */

/* Include files */
#include "pca.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "warning.h"
#include "xgesvd.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = {
    104,                                                         /* lineNo */
    "pca",                                                       /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    101,                                                         /* lineNo */
    "pca",                                                       /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    117,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    154,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    155,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    156,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    165,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    168,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    169,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    171,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    172,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    220,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    221,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    226,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    227,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    239,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    242,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    250,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    253,                                                         /* lineNo */
    "local_pca",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    702,                                                         /* lineNo */
    "nanreport",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    703,                                                         /* lineNo */
    "nanreport",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    711,                                                         /* lineNo */
    "nanreport",                                                 /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    635,                                                         /* lineNo */
    "wnanmean",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    632,                                                         /* lineNo */
    "wnanmean",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    623,                                                         /* lineNo */
    "wnanmean",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    620,                                                         /* lineNo */
    "wnanmean",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    378,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    379,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    384,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    385,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    393,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    406,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    407,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    411,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    412,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    416,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    419,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    432,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    433,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    438,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    442,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    443,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    468,                                                         /* lineNo */
    "localSVD",                                                  /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    488,                                                         /* lineNo */
    "localTSquared",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    496,                                                         /* lineNo */
    "localTSquared",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    506,                                                         /* lineNo */
    "localTSquared",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    507,                                                         /* lineNo */
    "localTSquared",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    508,                                                         /* lineNo */
    "localTSquared",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    768,                                                         /* lineNo */
    "removeNaNRows",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    771,                                                         /* lineNo */
    "removeNaNRows",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    788,                                                         /* lineNo */
    "insertNaNRows",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI = {
    790,                                                         /* lineNo */
    "insertNaNRows",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    795,                                                         /* lineNo */
    "insertNaNRows",                                             /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pathName */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    1272,                                                         /* lineNo */
    10,                                                           /* colNo */
    "",                                                           /* aName */
    "anyNonPos",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    775,                                                          /* lineNo */
    26,                                                           /* colNo */
    "",                                                           /* aName */
    "removeNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    761,                                                         /* lineNo */
    1,                                                           /* colNo */
    "removeNaNRows",                                             /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    712,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "nanreport",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    704,                                                          /* lineNo */
    12,                                                           /* colNo */
    "",                                                           /* aName */
    "nanreport",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    705,                                                          /* lineNo */
    37,                                                           /* colNo */
    "",                                                           /* aName */
    "nanreport",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    157,                                                          /* lineNo */
    26,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    157,                                                          /* lineNo */
    17,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    769,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "removeNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    228,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    228,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    775,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "removeNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    789,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "insertNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    254,                                                          /* lineNo */
    30,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    254,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    791,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "insertNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    796,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "insertNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    796,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "insertNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    251,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    243,                                                          /* lineNo */
    31,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    246,                                                          /* lineNo */
    35,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    222,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "local_pca",                                                  /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    772,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "removeNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    772,                                                          /* lineNo */
    25,                                                           /* colNo */
    "",                                                           /* aName */
    "removeNaNRows",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    637,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    636,                                                          /* lineNo */
    29,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    626,                                                          /* lineNo */
    33,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    625,                                                          /* lineNo */
    33,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    624,                                                          /* lineNo */
    41,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    624,                                                          /* lineNo */
    25,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    637,                                                          /* lineNo */
    32,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    626,                                                          /* lineNo */
    36,                                                           /* colNo */
    "",                                                           /* aName */
    "wnanmean",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    408,                                                          /* lineNo */
    43,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    386,                                                          /* lineNo */
    35,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    386,                                                          /* lineNo */
    18,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    417,                                                          /* lineNo */
    17,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    408,                                                          /* lineNo */
    22,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    408,                                                          /* lineNo */
    46,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    408,                                                          /* lineNo */
    9,                                                            /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    431,                                                          /* lineNo */
    32,                                                           /* colNo */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    4 /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    439,                                                          /* lineNo */
    28,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    439,                                                          /* lineNo */
    13,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    434,                                                          /* lineNo */
    33,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    434,                                                          /* lineNo */
    17,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    444,                                                          /* lineNo */
    17,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    444,                                                          /* lineNo */
    33,                                                           /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    413,                                                          /* lineNo */
    9,                                                            /* colNo */
    "",                                                           /* aName */
    "localSVD",                                                   /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    507,                                                          /* lineNo */
    26,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = {
    489,                                                         /* lineNo */
    5,                                                           /* colNo */
    "localTSquared",                                             /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    488,                                                          /* lineNo */
    52,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    746,                                                          /* lineNo */
    8,                                                            /* colNo */
    "",                                                           /* aName */
    "num_greater_than",                                           /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    509,                                                          /* lineNo */
    28,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    509,                                                          /* lineNo */
    9,                                                            /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    510,                                                          /* lineNo */
    23,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    510,                                                          /* lineNo */
    37,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    510,                                                          /* lineNo */
    54,                                                           /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    510,                                                          /* lineNo */
    9,                                                            /* colNo */
    "",                                                           /* aName */
    "localTSquared",                                              /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    58,                                                          /* lineNo */
    59,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    104,                                                         /* lineNo */
    36,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    117,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    762,                                                         /* lineNo */
    20,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    765,                                                         /* lineNo */
    25,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    233,                                                         /* lineNo */
    5,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    225,                                                         /* lineNo */
    31,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    786,                                                         /* lineNo */
    20,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    149,                                                         /* lineNo */
    12,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    110,                                                         /* lineNo */
    61,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    378,                                                         /* lineNo */
    13,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    379,                                                         /* lineNo */
    16,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    393,                                                         /* lineNo */
    53,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    431,                                                         /* lineNo */
    20,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    464,                                                         /* lineNo */
    5,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    393,                                                         /* lineNo */
    2,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    479,                                                         /* lineNo */
    5,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    504,                                                         /* lineNo */
    30,                                                          /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    505,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    504,                                                         /* lineNo */
    1,                                                           /* colNo */
    "pca",                                                       /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\stats\\eml\\pca.m" /* pName */
};

static emlrtRTEInfo
    yc_emlrtRTEI =
        {
            1,      /* lineNo */
            19,     /* colNo */
            "sqrt", /* fName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sq"
            "rt.m" /* pName */
};

/* Function Declarations */
static void b_localSVD(const emlrtStack *sp, const emxArray_real_T *x,
                       int32_T DOF, const emxArray_real_T *Weights,
                       const real_T VariableWeights_data[],
                       real_T coeffOut_data[], int32_T coeffOut_size[2],
                       emxArray_real_T *scoreOut, real_T latentOut_data[],
                       int32_T *latentOut_size, emxArray_real_T *tsquared,
                       real_T explained_data[], int32_T *explained_size);

static void localSVD(const emlrtStack *sp, const emxArray_real_T *x,
                     int32_T DOF, const emxArray_real_T *Weights,
                     const real_T VariableWeights_data[],
                     real_T coeffOut_data[], int32_T coeffOut_size[2],
                     emxArray_real_T *scoreOut, real_T latentOut_data[],
                     int32_T *latentOut_size, emxArray_real_T *tsquared,
                     real_T explained_data[], int32_T *explained_size);

static void localTSquared(const emlrtStack *sp, const emxArray_real_T *score,
                          const real_T latent_data[], int32_T latent_size,
                          int32_T DOF, emxArray_real_T *tsquared);

static void local_pca(const emlrtStack *sp, emxArray_real_T *x,
                      const emxArray_real_T *Weights,
                      const real_T VariableWeights_data[],
                      real_T coeffOut_data[], int32_T coeffOut_size[2],
                      emxArray_real_T *scoreOut, real_T latent_data[],
                      int32_T *latent_size, emxArray_real_T *tsquared,
                      real_T explained_data[], int32_T *explained_size,
                      real_T mu_data[], int32_T mu_size[2]);

static void wnanmean(const emlrtStack *sp, const emxArray_real_T *X,
                     const emxArray_real_T *W, boolean_T noNaNs,
                     real_T M_data[], int32_T M_size[2]);

/* Function Definitions */
static void b_localSVD(const emlrtStack *sp, const emxArray_real_T *x,
                       int32_T DOF, const emxArray_real_T *Weights,
                       const real_T VariableWeights_data[],
                       real_T coeffOut_data[], int32_T coeffOut_size[2],
                       emxArray_real_T *scoreOut, real_T latentOut_data[],
                       int32_T *latentOut_size, emxArray_real_T *tsquared,
                       real_T explained_data[], int32_T *explained_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  emxArray_real_T *r;
  emxArray_real_T *score;
  real_T coeff_data[9];
  real_T latent_data[3];
  real_T d;
  int32_T coeff_size[2];
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T latent_size;
  int32_T nrows;
  int32_T nx;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 1, &nc_emlrtRTEI, true);
  st.site = &sc_emlrtRSI;
  i = b_x->size[0];
  b_x->size[0] = Weights->size[0];
  emxEnsureCapacity_real_T(&st, b_x, i, &yc_emlrtRTEI);
  nx = Weights->size[0];
  for (i = 0; i < nx; i++) {
    b_x->data[i] = Weights->data[i];
  }
  b_st.site = &kd_emlrtRSI;
  nx = Weights->size[0];
  c_st.site = &ld_emlrtRSI;
  if ((1 <= Weights->size[0]) && (Weights->size[0] > 2147483646)) {
    d_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    b_x->data[k] = 1.0;
  }
  emxInit_real_T(&b_st, &r, 2, &oc_emlrtRTEI, true);
  k = b_x->size[0];
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = 3;
  emxEnsureCapacity_real_T(sp, r, i, &oc_emlrtRTEI);
  r->data[0] = VariableWeights_data[0];
  r->data[1] = VariableWeights_data[1];
  r->data[2] = VariableWeights_data[2];
  st.site = &tc_emlrtRSI;
  b_sqrt(&st, r);
  nrows = x->size[0];
  st.site = &uc_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  emxFree_real_T(&r);
  emxFree_real_T(&b_x);
  for (j = 0; j < 3; j++) {
    st.site = &vc_emlrtRSI;
    if (overflow) {
      b_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < nrows; i++) {
      if (i + 1 > k) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, k, &ub_emlrtBCI, (emlrtCTX)sp);
      }
      if (i + 1 > x->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &vb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
    }
  }
  emxInit_real_T(sp, &c_x, 2, &pc_emlrtRTEI, true);
  st.site = &wc_emlrtRSI;
  i = c_x->size[0] * c_x->size[1];
  c_x->size[0] = x->size[0];
  c_x->size[1] = 3;
  emxEnsureCapacity_real_T(&st, c_x, i, &pc_emlrtRTEI);
  nx = x->size[0] * x->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    c_x->data[i] = x->data[i];
  }
  emxInit_real_T(&st, &score, 2, &sc_emlrtRTEI, true);
  b_st.site = &md_emlrtRSI;
  ceval_xgesvd(&b_st, c_x, score, latent_data, &latent_size, coeff_data,
               coeff_size, &nx);
  nx = score->size[1];
  st.site = &xc_emlrtRSI;
  emxFree_real_T(&c_x);
  for (j = 0; j < nx; j++) {
    st.site = &yc_emlrtRSI;
    if ((1 <= nrows) && (nrows > 2147483646)) {
      b_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < nrows; i++) {
      if (i + 1 > k) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, k, &tb_emlrtBCI, (emlrtCTX)sp);
      }
      if (i + 1 > score->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &xb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > score->size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &xb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &yb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (i + 1 > score->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > score->size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      score->data[i + score->size[0] * j] *= latent_data[j];
    }
  }
  st.site = &ad_emlrtRSI;
  for (j = 0; j < nx; j++) {
    st.site = &bd_emlrtRSI;
    if (j + 1 > coeff_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &hc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  st.site = &cd_emlrtRSI;
  for (j = 0; j < nx; j++) {
    if (j + 1 > latent_size) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &wb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d = latent_data[j];
    d = d * d / (real_T)DOF;
    latent_data[j] = d;
  }
  st.site = &dd_emlrtRSI;
  localTSquared(&st, score, latent_data, latent_size, DOF, tsquared);
  if (DOF < 3) {
    nx = muIntScalarMin_sint32(DOF, nx);
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = nrows;
    emxEnsureCapacity_real_T(sp, scoreOut, i, &qc_emlrtRTEI);
    if (nx < 0) {
      emlrtNonNegativeCheckR2012b(nx, &emlrtDCI, (emlrtCTX)sp);
    }
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[1] = nx;
    emxEnsureCapacity_real_T(sp, scoreOut, i, &qc_emlrtRTEI);
    st.site = &ed_emlrtRSI;
    for (j = 0; j < nx; j++) {
      st.site = &fd_emlrtRSI;
      if ((1 <= nrows) && (nrows > 2147483646)) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < nrows; i++) {
        if (i + 1 > score->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &dc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (j + 1 > score->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &dc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (i + 1 > scoreOut->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, scoreOut->size[0],
                                        &ec_emlrtBCI, (emlrtCTX)sp);
        }
        if (j + 1 > scoreOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, scoreOut->size[1],
                                        &ec_emlrtBCI, (emlrtCTX)sp);
        }
        scoreOut->data[i + scoreOut->size[0] * j] =
            score->data[i + score->size[0] * j];
      }
    }
    *latentOut_size = nx;
    st.site = &gd_emlrtRSI;
    for (j = 0; j < nx; j++) {
      if (j + 1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &bc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > *latentOut_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, *latentOut_size, &cc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      latentOut_data[j] = latent_data[j];
    }
    coeffOut_size[0] = 3;
    coeffOut_size[1] = nx;
    st.site = &hd_emlrtRSI;
    for (j = 0; j < nx; j++) {
      st.site = &id_emlrtRSI;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      coeffOut_data[3 * j] = coeff_data[3 * j];
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = 3 * j + 1;
      coeffOut_data[i] = coeff_data[i];
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = 3 * j + 2;
      coeffOut_data[i] = coeff_data[i];
    }
  } else {
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = score->size[0];
    scoreOut->size[1] = score->size[1];
    emxEnsureCapacity_real_T(sp, scoreOut, i, &rc_emlrtRTEI);
    nx = score->size[0] * score->size[1];
    for (i = 0; i < nx; i++) {
      scoreOut->data[i] = score->data[i];
    }
    *latentOut_size = latent_size;
    if (0 <= latent_size - 1) {
      memcpy(&latentOut_data[0], &latent_data[0], latent_size * sizeof(real_T));
    }
    coeffOut_size[0] = 3;
    coeffOut_size[1] = coeff_size[1];
    nx = 3 * coeff_size[1];
    if (0 <= nx - 1) {
      memcpy(&coeffOut_data[0], &coeff_data[0], nx * sizeof(real_T));
    }
  }
  emxFree_real_T(&score);
  st.site = &jd_emlrtRSI;
  d = sum(&st, latentOut_data, *latentOut_size);
  *explained_size = *latentOut_size;
  for (i = 0; i < *latentOut_size; i++) {
    explained_data[i] = 100.0 * latentOut_data[i] / d;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void localSVD(const emlrtStack *sp, const emxArray_real_T *x,
                     int32_T DOF, const emxArray_real_T *Weights,
                     const real_T VariableWeights_data[],
                     real_T coeffOut_data[], int32_T coeffOut_size[2],
                     emxArray_real_T *scoreOut, real_T latentOut_data[],
                     int32_T *latentOut_size, emxArray_real_T *tsquared,
                     real_T explained_data[], int32_T *explained_size)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_x;
  emxArray_real_T *r;
  emxArray_real_T *score;
  real_T coeff_data[9];
  real_T latent_data[3];
  real_T d;
  int32_T coeff_size[2];
  int32_T OmegaSqrt_size_idx_1;
  int32_T i;
  int32_T j;
  int32_T latent_size;
  int32_T nrows;
  int32_T nsv;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r, 2, &nc_emlrtRTEI, true);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Weights->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &nc_emlrtRTEI);
  nsv = Weights->size[1];
  for (i = 0; i < nsv; i++) {
    r->data[i] = Weights->data[i];
  }
  st.site = &sc_emlrtRSI;
  b_sqrt(&st, r);
  OmegaSqrt_size_idx_1 = r->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = 3;
  emxEnsureCapacity_real_T(sp, r, i, &oc_emlrtRTEI);
  r->data[0] = VariableWeights_data[0];
  r->data[1] = VariableWeights_data[1];
  r->data[2] = VariableWeights_data[2];
  st.site = &tc_emlrtRSI;
  b_sqrt(&st, r);
  nrows = x->size[0];
  st.site = &uc_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  emxFree_real_T(&r);
  for (j = 0; j < 3; j++) {
    st.site = &vc_emlrtRSI;
    if (overflow) {
      b_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < nrows; i++) {
      if (i + 1 > OmegaSqrt_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, OmegaSqrt_size_idx_1,
                                      &ub_emlrtBCI, (emlrtCTX)sp);
      }
      if (i + 1 > x->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &vb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
    }
  }
  emxInit_real_T(sp, &b_x, 2, &pc_emlrtRTEI, true);
  st.site = &wc_emlrtRSI;
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = 3;
  emxEnsureCapacity_real_T(&st, b_x, i, &pc_emlrtRTEI);
  nsv = x->size[0] * x->size[1] - 1;
  for (i = 0; i <= nsv; i++) {
    b_x->data[i] = x->data[i];
  }
  emxInit_real_T(&st, &score, 2, &sc_emlrtRTEI, true);
  b_st.site = &md_emlrtRSI;
  ceval_xgesvd(&b_st, b_x, score, latent_data, &latent_size, coeff_data,
               coeff_size, &nsv);
  nsv = score->size[1];
  st.site = &xc_emlrtRSI;
  emxFree_real_T(&b_x);
  for (j = 0; j < nsv; j++) {
    st.site = &yc_emlrtRSI;
    if ((1 <= nrows) && (nrows > 2147483646)) {
      b_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = 0; i < nrows; i++) {
      if (i + 1 > OmegaSqrt_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, OmegaSqrt_size_idx_1,
                                      &tb_emlrtBCI, (emlrtCTX)sp);
      }
      if (i + 1 > score->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &xb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > score->size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &xb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &yb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (i + 1 > score->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > score->size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      score->data[i + score->size[0] * j] *= latent_data[j];
    }
  }
  st.site = &ad_emlrtRSI;
  for (j = 0; j < nsv; j++) {
    st.site = &bd_emlrtRSI;
    if (j + 1 > coeff_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &hc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  st.site = &cd_emlrtRSI;
  for (j = 0; j < nsv; j++) {
    if (j + 1 > latent_size) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &wb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d = latent_data[j];
    d = d * d / (real_T)DOF;
    latent_data[j] = d;
  }
  st.site = &dd_emlrtRSI;
  localTSquared(&st, score, latent_data, latent_size, DOF, tsquared);
  if (DOF < 3) {
    nsv = muIntScalarMin_sint32(DOF, nsv);
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = nrows;
    emxEnsureCapacity_real_T(sp, scoreOut, i, &qc_emlrtRTEI);
    if (nsv < 0) {
      emlrtNonNegativeCheckR2012b(nsv, &emlrtDCI, (emlrtCTX)sp);
    }
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[1] = nsv;
    emxEnsureCapacity_real_T(sp, scoreOut, i, &qc_emlrtRTEI);
    st.site = &ed_emlrtRSI;
    for (j = 0; j < nsv; j++) {
      st.site = &fd_emlrtRSI;
      if ((1 <= nrows) && (nrows > 2147483646)) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < nrows; i++) {
        if (i + 1 > score->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &dc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (j + 1 > score->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &dc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (i + 1 > scoreOut->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, scoreOut->size[0],
                                        &ec_emlrtBCI, (emlrtCTX)sp);
        }
        if (j + 1 > scoreOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, scoreOut->size[1],
                                        &ec_emlrtBCI, (emlrtCTX)sp);
        }
        scoreOut->data[i + scoreOut->size[0] * j] =
            score->data[i + score->size[0] * j];
      }
    }
    *latentOut_size = nsv;
    st.site = &gd_emlrtRSI;
    for (j = 0; j < nsv; j++) {
      if (j + 1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, latent_size, &bc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > *latentOut_size) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, *latentOut_size, &cc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      latentOut_data[j] = latent_data[j];
    }
    coeffOut_size[0] = 3;
    coeffOut_size[1] = nsv;
    st.site = &hd_emlrtRSI;
    for (j = 0; j < nsv; j++) {
      st.site = &id_emlrtRSI;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      coeffOut_data[3 * j] = coeff_data[3 * j];
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = 3 * j + 1;
      coeffOut_data[i] = coeff_data[i];
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j + 1 > coeff_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeff_size[1], &gc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i = 3 * j + 2;
      coeffOut_data[i] = coeff_data[i];
    }
  } else {
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = score->size[0];
    scoreOut->size[1] = score->size[1];
    emxEnsureCapacity_real_T(sp, scoreOut, i, &rc_emlrtRTEI);
    nsv = score->size[0] * score->size[1];
    for (i = 0; i < nsv; i++) {
      scoreOut->data[i] = score->data[i];
    }
    *latentOut_size = latent_size;
    if (0 <= latent_size - 1) {
      memcpy(&latentOut_data[0], &latent_data[0], latent_size * sizeof(real_T));
    }
    coeffOut_size[0] = 3;
    coeffOut_size[1] = coeff_size[1];
    nsv = 3 * coeff_size[1];
    if (0 <= nsv - 1) {
      memcpy(&coeffOut_data[0], &coeff_data[0], nsv * sizeof(real_T));
    }
  }
  emxFree_real_T(&score);
  st.site = &jd_emlrtRSI;
  d = sum(&st, latentOut_data, *latentOut_size);
  *explained_size = *latentOut_size;
  for (i = 0; i < *latentOut_size; i++) {
    explained_data[i] = 100.0 * latentOut_data[i] / d;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void localTSquared(const emlrtStack *sp, const emxArray_real_T *score,
                          const real_T latent_data[], int32_T latent_size,
                          int32_T DOF, emxArray_real_T *tsquared)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *standScores;
  real_T absx;
  int32_T exponent;
  int32_T i;
  int32_T m;
  int32_T q;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if ((score->size[0] == 0) || (score->size[1] == 0)) {
    i = tsquared->size[0] * tsquared->size[1];
    tsquared->size[0] = score->size[0];
    tsquared->size[1] = score->size[1];
    emxEnsureCapacity_real_T(sp, tsquared, i, &uc_emlrtRTEI);
    exponent = score->size[0] * score->size[1];
    for (i = 0; i < exponent; i++) {
      tsquared->data[i] = score->data[i];
    }
  } else {
    if (DOF > 1) {
      if (1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(1, 1, latent_size, &jc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &fe_emlrtRSI;
      absx = muDoubleScalarAbs(latent_data[0]);
      if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
        if (absx <= 2.2250738585072014E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &exponent);
          absx = ldexp(1.0, exponent - 53);
        }
      } else {
        absx = rtNaN;
      }
      absx *= (real_T)muIntScalarMax_sint32(DOF, 3);
      q = 0;
      for (exponent = 0; exponent < latent_size; exponent++) {
        if (exponent + 1 > latent_size) {
          emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, latent_size,
                                        &kc_emlrtBCI, &st);
        }
        if (latent_data[exponent] > absx) {
          q++;
        }
      }
      if ((q < 0) || (q > latent_size)) {
        emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      if (DOF < 3) {
        m = 2;
      } else {
        m = 3;
      }
      if (q < m) {
        st.site = &ge_emlrtRSI;
        warning(&st, q);
      }
    } else {
      q = 0;
    }
    emxInit_real_T(sp, &standScores, 2, &xc_emlrtRTEI, true);
    m = score->size[0];
    i = standScores->size[0] * standScores->size[1];
    standScores->size[0] = score->size[0];
    standScores->size[1] = q;
    emxEnsureCapacity_real_T(sp, standScores, i, &vc_emlrtRTEI);
    i = tsquared->size[0] * tsquared->size[1];
    tsquared->size[0] = score->size[0];
    tsquared->size[1] = 1;
    emxEnsureCapacity_real_T(sp, tsquared, i, &wc_emlrtRTEI);
    exponent = score->size[0];
    for (i = 0; i < exponent; i++) {
      tsquared->data[i] = 0.0;
    }
    st.site = &he_emlrtRSI;
    if ((1 <= q) && (q > 2147483646)) {
      b_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (exponent = 0; exponent < q; exponent++) {
      st.site = &ie_emlrtRSI;
      if (exponent + 1 > latent_size) {
        emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, latent_size,
                                      &ic_emlrtBCI, &st);
      }
      absx = latent_data[exponent];
      if (absx < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      absx = muDoubleScalarSqrt(absx);
      st.site = &je_emlrtRSI;
      if (m > 2147483646) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < m; i++) {
        if (i + 1 > score->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &lc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (exponent + 1 > score->size[1]) {
          emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, score->size[1],
                                        &lc_emlrtBCI, (emlrtCTX)sp);
        }
        if (i + 1 > standScores->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, standScores->size[0],
                                        &mc_emlrtBCI, (emlrtCTX)sp);
        }
        if (exponent + 1 > standScores->size[1]) {
          emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, standScores->size[1],
                                        &mc_emlrtBCI, (emlrtCTX)sp);
        }
        standScores->data[i + standScores->size[0] * exponent] =
            score->data[i + score->size[0] * exponent] / absx;
        if (i + 1 > tsquared->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, tsquared->size[0],
                                        &nc_emlrtBCI, (emlrtCTX)sp);
        }
        if (i + 1 > standScores->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, standScores->size[0],
                                        &oc_emlrtBCI, (emlrtCTX)sp);
        }
        if (exponent + 1 > standScores->size[1]) {
          emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, standScores->size[1],
                                        &oc_emlrtBCI, (emlrtCTX)sp);
        }
        if (i + 1 > standScores->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, standScores->size[0],
                                        &pc_emlrtBCI, (emlrtCTX)sp);
        }
        if (exponent + 1 > standScores->size[1]) {
          emlrtDynamicBoundsCheckR2012b(exponent + 1, 1, standScores->size[1],
                                        &pc_emlrtBCI, (emlrtCTX)sp);
        }
        if (i + 1 > tsquared->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, tsquared->size[0],
                                        &qc_emlrtBCI, (emlrtCTX)sp);
        }
        tsquared->data[i] +=
            standScores->data[i + standScores->size[0] * exponent] *
            standScores->data[i + standScores->size[0] * exponent];
      }
    }
    emxFree_real_T(&standScores);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void local_pca(const emlrtStack *sp, emxArray_real_T *x,
                      const emxArray_real_T *Weights,
                      const real_T VariableWeights_data[],
                      real_T coeffOut_data[], int32_T coeffOut_size[2],
                      emxArray_real_T *scoreOut, real_T latent_data[],
                      int32_T *latent_size, emxArray_real_T *tsquared,
                      real_T explained_data[], int32_T *explained_size,
                      real_T mu_data[], int32_T mu_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *naninfo_isNaN;
  emxArray_int32_T *naninfo_nNaNsInRow;
  emxArray_real_T *WNoNaNs;
  emxArray_real_T *b_score;
  emxArray_real_T *b_tsquared;
  emxArray_real_T *score;
  emxArray_real_T *xNoNaNs;
  real_T coeff_data[9];
  real_T absc;
  real_T absc_tmp;
  real_T b_absc_tmp;
  real_T maxval;
  real_T sgn;
  int32_T coeff_size[2];
  int32_T DOF;
  int32_T b_n;
  int32_T i;
  int32_T j;
  int32_T n;
  int32_T ns1;
  int32_T p;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &naninfo_nNaNsInRow, 1, &fc_emlrtRTEI, true);
  n = x->size[0];
  st.site = &sb_emlrtRSI;
  b_n = x->size[0];
  p = 0;
  ns1 = 0;
  i = naninfo_nNaNsInRow->size[0];
  naninfo_nNaNsInRow->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&st, naninfo_nNaNsInRow, i, &fc_emlrtRTEI);
  DOF = x->size[0];
  for (i = 0; i < DOF; i++) {
    naninfo_nNaNsInRow->data[i] = 0;
  }
  emxInit_boolean_T(&st, &naninfo_isNaN, 2, &fc_emlrtRTEI, true);
  i = naninfo_isNaN->size[0] * naninfo_isNaN->size[1];
  naninfo_isNaN->size[0] = x->size[0];
  naninfo_isNaN->size[1] = 3;
  emxEnsureCapacity_boolean_T(&st, naninfo_isNaN, i, &fc_emlrtRTEI);
  DOF = x->size[0] * 3;
  for (i = 0; i < DOF; i++) {
    naninfo_isNaN->data[i] = muDoubleScalarIsNaN(x->data[i]);
  }
  b_st.site = &kc_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  for (j = 0; j < 3; j++) {
    b_st.site = &lc_emlrtRSI;
    if (overflow) {
      c_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < b_n; i++) {
      if (i + 1 > naninfo_isNaN->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_isNaN->size[0],
                                      &q_emlrtBCI, &st);
      }
      if (naninfo_isNaN->data[i + naninfo_isNaN->size[0] * j]) {
        if (i + 1 > naninfo_nNaNsInRow->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_nNaNsInRow->size[0],
                                        &r_emlrtBCI, &st);
        }
        naninfo_nNaNsInRow->data[i]++;
        p++;
      }
    }
  }
  emxFree_boolean_T(&naninfo_isNaN);
  b_st.site = &mc_emlrtRSI;
  if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (i = 0; i < b_n; i++) {
    if (i + 1 > naninfo_nNaNsInRow->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_nNaNsInRow->size[0],
                                    &p_emlrtBCI, &st);
    }
    if (naninfo_nNaNsInRow->data[i] > 0) {
      ns1++;
    }
  }
  overflow = (p <= 0);
  DOF = x->size[0] - ns1;
  if (DOF >= 1) {
    DOF--;
  }
  st.site = &tb_emlrtRSI;
  wnanmean(&st, x, Weights, overflow, mu_data, mu_size);
  st.site = &ub_emlrtRSI;
  for (j = 0; j < 3; j++) {
    st.site = &vb_emlrtRSI;
    for (i = 0; i < n; i++) {
      if (i + 1 > x->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (i + 1 > x->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      x->data[i + x->size[0] * j] -= mu_data[j];
    }
  }
  emxInit_real_T(sp, &score, 2, &lc_emlrtRTEI, true);
  if (overflow) {
    st.site = &wb_emlrtRSI;
    localSVD(&st, x, DOF, Weights, VariableWeights_data, coeff_data, coeff_size,
             score, latent_data, latent_size, tsquared, explained_data,
             explained_size);
  } else {
    st.site = &xb_emlrtRSI;
    n = x->size[0];
    b_n = x->size[0] - ns1;
    if ((b_n < 0) || (b_n > x->size[0])) {
      emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    emxInit_real_T(&st, &xNoNaNs, 2, &mc_emlrtRTEI, true);
    emxInit_real_T(&st, &WNoNaNs, 1, &mc_emlrtRTEI, true);
    i = xNoNaNs->size[0] * xNoNaNs->size[1];
    xNoNaNs->size[0] = b_n;
    xNoNaNs->size[1] = 3;
    emxEnsureCapacity_real_T(&st, xNoNaNs, i, &gc_emlrtRTEI);
    i = WNoNaNs->size[0];
    WNoNaNs->size[0] = b_n;
    emxEnsureCapacity_real_T(&st, WNoNaNs, i, &hc_emlrtRTEI);
    b_n = 0;
    b_st.site = &te_emlrtRSI;
    for (i = 0; i < n; i++) {
      if (i + 1 > naninfo_nNaNsInRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_nNaNsInRow->size[0],
                                      &u_emlrtBCI, &st);
      }
      if (naninfo_nNaNsInRow->data[i] == 0) {
        b_n++;
        b_st.site = &ue_emlrtRSI;
        if ((b_n < 1) || (b_n > xNoNaNs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, xNoNaNs->size[0], &jb_emlrtBCI,
                                        &st);
        }
        if (i + 1 > x->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &kb_emlrtBCI,
                                        &st);
        }
        xNoNaNs->data[b_n - 1] = x->data[i];
        if (b_n > xNoNaNs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, xNoNaNs->size[0], &jb_emlrtBCI,
                                        &st);
        }
        if (i + 1 > x->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &kb_emlrtBCI,
                                        &st);
        }
        xNoNaNs->data[(b_n + xNoNaNs->size[0]) - 1] = x->data[i + x->size[0]];
        if (b_n > xNoNaNs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, xNoNaNs->size[0], &jb_emlrtBCI,
                                        &st);
        }
        if (i + 1 > x->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, x->size[0], &kb_emlrtBCI,
                                        &st);
        }
        xNoNaNs->data[(b_n + xNoNaNs->size[0] * 2) - 1] =
            x->data[i + x->size[0] * 2];
        if (i + 1 > Weights->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, Weights->size[1], &o_emlrtBCI,
                                        &st);
        }
        if (b_n > WNoNaNs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_n, 1, WNoNaNs->size[0], &x_emlrtBCI,
                                        &st);
        }
        WNoNaNs->data[b_n - 1] = 1.0;
      }
    }
    emxInit_real_T(&st, &b_score, 2, &mc_emlrtRTEI, true);
    emxInit_real_T(&st, &b_tsquared, 2, &mc_emlrtRTEI, true);
    st.site = &yb_emlrtRSI;
    b_localSVD(&st, xNoNaNs, DOF, WNoNaNs, VariableWeights_data, coeff_data,
               coeff_size, b_score, latent_data, latent_size, b_tsquared,
               explained_data, explained_size);
    st.site = &ac_emlrtRSI;
    n = naninfo_nNaNsInRow->size[0];
    p = b_score->size[1] - 1;
    i = score->size[0] * score->size[1];
    score->size[0] = naninfo_nNaNsInRow->size[0];
    score->size[1] = b_score->size[1];
    emxEnsureCapacity_real_T(&st, score, i, &kc_emlrtRTEI);
    b_n = 0;
    b_st.site = &ve_emlrtRSI;
    emxFree_real_T(&WNoNaNs);
    emxFree_real_T(&xNoNaNs);
    if ((1 <= naninfo_nNaNsInRow->size[0]) &&
        (naninfo_nNaNsInRow->size[0] > 2147483646)) {
      c_st.site = &nc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < n; i++) {
      if (i + 1 > naninfo_nNaNsInRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_nNaNsInRow->size[0],
                                      &y_emlrtBCI, &st);
      }
      if (naninfo_nNaNsInRow->data[i] > 0) {
        b_st.site = &we_emlrtRSI;
        for (j = 0; j <= p; j++) {
          if (i + 1 > score->size[0]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0],
                                          &cb_emlrtBCI, &st);
          }
          if (j + 1 > score->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1],
                                          &cb_emlrtBCI, &st);
          }
          score->data[i + score->size[0] * j] = rtNaN;
        }
      } else {
        b_n++;
        b_st.site = &xe_emlrtRSI;
        for (j = 0; j <= p; j++) {
          if ((b_n < 1) || (b_n > b_score->size[0])) {
            emlrtDynamicBoundsCheckR2012b(b_n, 1, b_score->size[0],
                                          &db_emlrtBCI, &st);
          }
          if (j + 1 > b_score->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_score->size[1],
                                          &db_emlrtBCI, &st);
          }
          if (i + 1 > score->size[0]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0],
                                          &eb_emlrtBCI, &st);
          }
          if (j + 1 > score->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1],
                                          &eb_emlrtBCI, &st);
          }
          score->data[i + score->size[0] * j] =
              b_score->data[(b_n + b_score->size[0] * j) - 1];
        }
      }
    }
    emxFree_real_T(&b_score);
    st.site = &bc_emlrtRSI;
    n = naninfo_nNaNsInRow->size[0];
    p = b_tsquared->size[1] - 1;
    i = tsquared->size[0] * tsquared->size[1];
    tsquared->size[0] = naninfo_nNaNsInRow->size[0];
    tsquared->size[1] = b_tsquared->size[1];
    emxEnsureCapacity_real_T(&st, tsquared, i, &kc_emlrtRTEI);
    b_n = 0;
    b_st.site = &ve_emlrtRSI;
    for (i = 0; i < n; i++) {
      if (i + 1 > naninfo_nNaNsInRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, naninfo_nNaNsInRow->size[0],
                                      &y_emlrtBCI, &st);
      }
      if (naninfo_nNaNsInRow->data[i] > 0) {
        b_st.site = &we_emlrtRSI;
        for (j = 0; j <= p; j++) {
          if (i + 1 > tsquared->size[0]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, tsquared->size[0],
                                          &cb_emlrtBCI, &st);
          }
          if (j + 1 > tsquared->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, tsquared->size[1],
                                          &cb_emlrtBCI, &st);
          }
          tsquared->data[i + tsquared->size[0] * j] = rtNaN;
        }
      } else {
        b_n++;
        b_st.site = &xe_emlrtRSI;
        for (j = 0; j <= p; j++) {
          if ((b_n < 1) || (b_n > b_tsquared->size[0])) {
            emlrtDynamicBoundsCheckR2012b(b_n, 1, b_tsquared->size[0],
                                          &db_emlrtBCI, &st);
          }
          if (j + 1 > b_tsquared->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_tsquared->size[1],
                                          &db_emlrtBCI, &st);
          }
          if (i + 1 > tsquared->size[0]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, tsquared->size[0],
                                          &eb_emlrtBCI, &st);
          }
          if (j + 1 > tsquared->size[1]) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, tsquared->size[1],
                                          &eb_emlrtBCI, &st);
          }
          tsquared->data[i + tsquared->size[0] * j] =
              b_tsquared->data[(b_n + b_tsquared->size[0] * j) - 1];
        }
      }
    }
    emxFree_real_T(&b_tsquared);
  }
  emxFree_int32_T(&naninfo_nNaNsInRow);
  ns1 = score->size[0];
  if (3 < DOF) {
    coeffOut_size[0] = 3;
    coeffOut_size[1] = 3;
    st.site = &cc_emlrtRSI;
    i = coeff_size[1];
    for (j = 0; j < 3; j++) {
      st.site = &dc_emlrtRSI;
      if (j + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &ib_emlrtBCI, (emlrtCTX)sp);
      }
      coeffOut_data[3 * j] = coeff_data[3 * j];
      if (j + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &ib_emlrtBCI, (emlrtCTX)sp);
      }
      b_n = 3 * j + 1;
      coeffOut_data[b_n] = coeff_data[b_n];
      if (j + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &ib_emlrtBCI, (emlrtCTX)sp);
      }
      b_n = 3 * j + 2;
      coeffOut_data[b_n] = coeff_data[b_n];
    }
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = score->size[0];
    scoreOut->size[1] = 3;
    emxEnsureCapacity_real_T(sp, scoreOut, i, &jc_emlrtRTEI);
    st.site = &ec_emlrtRSI;
    overflow = ((1 <= score->size[0]) && (score->size[0] > 2147483646));
    for (j = 0; j < 3; j++) {
      st.site = &fc_emlrtRSI;
      if (overflow) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < ns1; i++) {
        if (i + 1 > score->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, score->size[0], &v_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (j + 1 > score->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, score->size[1], &v_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (i + 1 > scoreOut->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, scoreOut->size[0],
                                        &w_emlrtBCI, (emlrtCTX)sp);
        }
        scoreOut->data[i + scoreOut->size[0] * j] =
            score->data[i + score->size[0] * j];
      }
    }
  } else {
    coeffOut_size[0] = 3;
    coeffOut_size[1] = coeff_size[1];
    DOF = 3 * coeff_size[1];
    if (0 <= DOF - 1) {
      memcpy(&coeffOut_data[0], &coeff_data[0], DOF * sizeof(real_T));
    }
    i = scoreOut->size[0] * scoreOut->size[1];
    scoreOut->size[0] = score->size[0];
    scoreOut->size[1] = score->size[1];
    emxEnsureCapacity_real_T(sp, scoreOut, i, &ic_emlrtRTEI);
    DOF = score->size[0] * score->size[1];
    for (i = 0; i < DOF; i++) {
      scoreOut->data[i] = score->data[i];
    }
  }
  emxFree_real_T(&score);
  p = coeffOut_size[1];
  st.site = &gc_emlrtRSI;
  for (j = 0; j < p; j++) {
    maxval = 0.0;
    sgn = 1.0;
    st.site = &hc_emlrtRSI;
    if (j + 1 > coeffOut_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &gb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    absc_tmp = coeffOut_data[3 * j];
    absc = muDoubleScalarAbs(absc_tmp);
    if (absc > 0.0) {
      maxval = absc;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &hb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sgn = muDoubleScalarSign(absc_tmp);
    }
    if (j + 1 > coeffOut_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &gb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_n = 3 * j + 1;
    b_absc_tmp = coeffOut_data[b_n];
    absc = muDoubleScalarAbs(b_absc_tmp);
    if (absc > maxval) {
      maxval = absc;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &hb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sgn = muDoubleScalarSign(b_absc_tmp);
    }
    if (j + 1 > coeffOut_size[1]) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &gb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = 3 * j + 2;
    absc = coeffOut_data[i];
    if (muDoubleScalarAbs(absc) > maxval) {
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &hb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sgn = muDoubleScalarSign(absc);
    }
    if (sgn < 0.0) {
      st.site = &ic_emlrtRSI;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      coeffOut_data[3 * j] = -absc_tmp;
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      coeffOut_data[b_n] = -coeffOut_data[b_n];
      if (j + 1 > coeffOut_size[1]) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, coeffOut_size[1], &fb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      coeffOut_data[i] = -coeffOut_data[i];
      st.site = &jc_emlrtRSI;
      if ((1 <= ns1) && (ns1 > 2147483646)) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < ns1; i++) {
        if (i + 1 > scoreOut->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, scoreOut->size[0],
                                        &ab_emlrtBCI, (emlrtCTX)sp);
        }
        if (j + 1 > scoreOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, scoreOut->size[1],
                                        &ab_emlrtBCI, (emlrtCTX)sp);
        }
        if (i + 1 > scoreOut->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, scoreOut->size[0],
                                        &bb_emlrtBCI, (emlrtCTX)sp);
        }
        if (j + 1 > scoreOut->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, scoreOut->size[1],
                                        &bb_emlrtBCI, (emlrtCTX)sp);
        }
        scoreOut->data[i + scoreOut->size[0] * j] =
            -scoreOut->data[i + scoreOut->size[0] * j];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void wnanmean(const emlrtStack *sp, const emxArray_real_T *X,
                     const emxArray_real_T *W, boolean_T noNaNs,
                     real_T M_data[], int32_T M_size[2])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T wcol;
  real_T xcol;
  int32_T i;
  int32_T j;
  int32_T m;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = X->size[0];
  if (!noNaNs) {
    st.site = &rc_emlrtRSI;
    M_size[0] = 1;
    M_size[1] = 3;
    overflow = ((1 <= X->size[0]) && (X->size[0] > 2147483646));
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      st.site = &qc_emlrtRSI;
      if (overflow) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < m; i++) {
        if (i + 1 > W->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, W->size[1], &qb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (i + 1 > X->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, X->size[0], &pb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (!muDoubleScalarIsNaN(X->data[i + X->size[0] * j])) {
          if (i + 1 > W->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, W->size[1], &ob_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          wcol++;
          if (i + 1 > W->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, W->size[1], &nb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (i + 1 > X->size[0]) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, X->size[0], &sb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          xcol += X->data[i + X->size[0] * j];
        }
      }
      M_data[j] = xcol / wcol;
    }
  } else {
    st.site = &pc_emlrtRSI;
    M_size[0] = 1;
    M_size[1] = 3;
    overflow = ((1 <= X->size[0]) && (X->size[0] > 2147483646));
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      st.site = &oc_emlrtRSI;
      if (overflow) {
        b_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (i = 0; i < m; i++) {
        if (i + 1 > W->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, W->size[1], &mb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        wcol++;
        if (i + 1 > W->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, W->size[1], &lb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (i + 1 > X->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, X->size[0], &rb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        xcol += X->data[i + X->size[0] * j];
      }
      M_data[j] = xcol / wcol;
    }
  }
}

void pca(const emlrtStack *sp, const emxArray_real_T *x,
         real_T varargout_1_data[], int32_T varargout_1_size[2],
         emxArray_real_T *varargout_2, real_T varargout_3_data[],
         int32_T *varargout_3_size, emxArray_real_T *varargout_4,
         real_T varargout_5_data[], int32_T *varargout_5_size,
         real_T varargout_6_data[], int32_T varargout_6_size[2])
{
  emlrtStack st;
  emxArray_real_T *b_x;
  emxArray_real_T *r;
  real_T tmp_data[3];
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &rb_emlrtRSI;
  i = x->size[0];
  for (k = 0; k < i; k++) {
    if (k + 1 > x->size[0]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, x->size[0], &n_emlrtBCI, &st);
    }
  }
  emxInit_real_T(&st, &r, 2, &dc_emlrtRTEI, true);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = x->size[0];
  emxEnsureCapacity_real_T(sp, r, i, &dc_emlrtRTEI);
  k = x->size[0];
  for (i = 0; i < k; i++) {
    r->data[i] = 1.0;
  }
  emxInit_real_T(sp, &b_x, 2, &ec_emlrtRTEI, true);
  tmp_data[0] = 1.0;
  tmp_data[1] = 1.0;
  tmp_data[2] = 1.0;
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = 3;
  emxEnsureCapacity_real_T(sp, b_x, i, &ec_emlrtRTEI);
  k = x->size[0] * x->size[1] - 1;
  for (i = 0; i <= k; i++) {
    b_x->data[i] = x->data[i];
  }
  st.site = &pb_emlrtRSI;
  local_pca(&st, b_x, r, tmp_data, varargout_1_data, varargout_1_size,
            varargout_2, varargout_3_data, varargout_3_size, varargout_4,
            varargout_5_data, varargout_5_size, varargout_6_data,
            varargout_6_size);
  emxFree_real_T(&b_x);
  emxFree_real_T(&r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (pca.c) */
