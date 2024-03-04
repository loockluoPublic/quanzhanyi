/*
 * cylderfit.c
 *
 * Code generation for function 'cylderfit'
 *
 */

/* Include files */
#include "cylderfit.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "eml_mtimes_helper.h"
#include "handle.h"
#include "mldivide.h"
#include "mtimes.h"
#include "pca.h"
#include "pcnormals.h"
#include "pctransform.h"
#include "pinv.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "power.h"
#include "rigid3d.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,                                     /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    4,                                     /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    7,                                     /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    8,                                     /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    29,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    31,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    32,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    34,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    36,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    40,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    62,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    65,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    66,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    67,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    90,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    16,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    18,                                    /* lineNo */
    "cylderfit",                           /* fcnName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    22,    /* lineNo */
    "cat", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat."
    "m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    96,         /* lineNo */
    "cat_impl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat."
    "m" /* pathName */
};

static emlrtRSInfo
    ci_emlrtRSI =
        {
            44,       /* lineNo */
            "mpower", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\mpow"
            "er.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    9,                                      /* lineNo */
    18,                                     /* colNo */
    "coeff",                                /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                                    /* nDims */
    29,                                    /* lineNo */
    14,                                    /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                                    /* nDims */
    27,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                    /* nDims */
    28,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    -1,                                    /* nDims */
    29,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    41,                                     /* lineNo */
    18,                                     /* colNo */
    "zlimit",                               /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    41,                                     /* lineNo */
    30,                                     /* colNo */
    "zlimit",                               /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    51,                                     /* lineNo */
    20,                                     /* colNo */
    "x",                                    /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    52,                                     /* lineNo */
    20,                                     /* colNo */
    "y",                                    /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    53,                                     /* lineNo */
    20,                                     /* colNo */
    "z",                                    /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    271,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat."
    "m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    55,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    57,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    58,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    59,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    60,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    61,                                     /* lineNo */
    13,                                     /* colNo */
    "Bn",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    62,                                     /* lineNo */
    13,                                     /* colNo */
    "Ln",                                   /* aName */
    "cylderfit",                            /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    293,   /* lineNo */
    14,    /* colNo */
    "cat", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\cat."
    "m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    20,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    21,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    24,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    25,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    27,                                    /* lineNo */
    14,                                    /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    28,                                    /* lineNo */
    14,                                    /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    44,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    45,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    18,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    3,                                     /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    7,                                     /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    1,                                     /* lineNo */
    42,                                    /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    40,                                    /* lineNo */
    5,                                     /* colNo */
    "cylderfit",                           /* fName */
    "C:\\Users\\XWT\\Desktop\\cylderfit.m" /* pName */
};

/* Function Definitions */
void cylderfit(const emlrtStack *sp, const emxArray_real_T *x,
               const emxArray_real_T *y, const emxArray_real_T *z, real_T *xn1,
               real_T *xn2, real_T *xn3, real_T *xn4, real_T *xn5, real_T *xn6,
               real_T *xn7)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *Bn;
  emxArray_real_T *L;
  emxArray_real_T *a__1;
  emxArray_real_T *a__3;
  emxArray_real_T *normals;
  emxArray_real_T *r;
  emxArray_real_T *xc;
  emxArray_real_T *yc;
  emxArray_real_T *zlimit;
  pointCloud circleCloud;
  pointCloud ptCloud;
  real_T NBBn[49];
  real_T a[49];
  real_T tform_AffineTform_T[16];
  real_T NBB[9];
  real_T coeff_data[9];
  real_T rot[9];
  real_T Wn[7];
  real_T Xn[7];
  real_T deltX[7];
  real_T W[3];
  real_T X[3];
  real_T a__5_data[3];
  real_T Bn_tmp;
  real_T Bn_tmp_tmp;
  real_T a0;
  real_T b0;
  real_T b_Bn_tmp_tmp;
  real_T b_y1;
  real_T c0;
  real_T c_Bn_tmp_tmp;
  real_T denom;
  real_T r0;
  real_T z1;
  int32_T a__5_size[2];
  int32_T coeff_size[2];
  int32_T b_i;
  int32_T count;
  int32_T i;
  int32_T loop_ub;
  int32_T n;
  boolean_T b;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInitStruct_pointCloud(sp, &circleCloud, &hb_emlrtRTEI, true);
  emxInitStruct_pointCloud(sp, &ptCloud, &ib_emlrtRTEI, true);
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &circleCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  circleCloud.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ptCloud,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  ptCloud.matlabCodegenIsDeleted = true;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  st.site = &emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  b = (y->size[0] == x->size[0]);
  if (!b) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (z->size[0] != x->size[0]) {
    b = false;
  }
  if (!b) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(&c_st, &normals, 2, &jb_emlrtRTEI, true);
  i = normals->size[0] * normals->size[1];
  normals->size[0] = x->size[0];
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(sp, normals, i, &x_emlrtRTEI);
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    normals->data[i] = x->data[i];
  }
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    normals->data[i + normals->size[0]] = y->data[i];
  }
  loop_ub = z->size[0];
  for (i = 0; i < loop_ub; i++) {
    normals->data[i + normals->size[0] * 2] = z->data[i];
  }
  emxInit_real_T(sp, &a__1, 2, &kb_emlrtRTEI, true);
  emxInit_real_T(sp, &a__3, 2, &kb_emlrtRTEI, true);
  st.site = &emlrtRSI;
  pointCloud_pointCloud(&st, &ptCloud, normals);
  st.site = &b_emlrtRSI;
  n = ptCloud.Location->size[0];
  /*     %%
   * -----------------------------计算点云法向量----------------------------- */
  st.site = &c_emlrtRSI;
  pcnormals(&st, &ptCloud, normals);
  /*  计算点云法向量 */
  st.site = &d_emlrtRSI;
  pca(&st, normals, coeff_data, coeff_size, a__1, W, &loop_ub, a__3, X, &count,
      a__5_data, a__5_size);
  emxFree_real_T(&a__3);
  emxFree_real_T(&a__1);
  if (3 > coeff_size[1]) {
    emlrtDynamicBoundsCheckR2012b(3, 1, coeff_size[1], &emlrtBCI, (emlrtCTX)sp);
  }
  a0 = coeff_data[6];
  b0 = coeff_data[7];
  c0 = coeff_data[8];
  /*  构建旋转矩阵 */
  denom = muDoubleScalarHypot(coeff_data[6], coeff_data[7]);
  rot[0] = coeff_data[7] / denom;
  rot[3] = -coeff_data[6] / denom;
  rot[6] = 0.0;
  rot[1] = coeff_data[6] * coeff_data[8] / denom;
  rot[4] = coeff_data[7] * coeff_data[8] / denom;
  rot[7] = -denom;
  rot[2] = coeff_data[6];
  rot[5] = coeff_data[7];
  rot[8] = coeff_data[8];
  for (i = 0; i < 3; i++) {
    NBB[3 * i] = rot[i];
    NBB[3 * i + 1] = rot[i + 3];
    NBB[3 * i + 2] = rot[i + 6];
  }
  emxInit_real_T(sp, &xc, 1, &y_emlrtRTEI, true);
  st.site = &p_emlrtRSI;
  rigid3d_rigid3d(&st, NBB, tform_AffineTform_T);
  /* 变换点云 */
  st.site = &q_emlrtRSI;
  pctransform(&st, &ptCloud, tform_AffineTform_T, &circleCloud);
  loop_ub = circleCloud.Location->size[0];
  i = xc->size[0];
  xc->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, xc, i, &y_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    xc->data[i] = circleCloud.Location->data[i];
  }
  emxInit_real_T(sp, &yc, 1, &ab_emlrtRTEI, true);
  loop_ub = circleCloud.Location->size[0];
  i = yc->size[0];
  yc->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, yc, i, &ab_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    yc->data[i] = circleCloud.Location->data[i + circleCloud.Location->size[0]];
  }
  /*     %%
   * --------------------------初始化矩阵系数-------------------------------- */
  i = normals->size[0] * normals->size[1];
  normals->size[0] = n;
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(sp, normals, i, &bb_emlrtRTEI);
  loop_ub = n * 3;
  for (i = 0; i < loop_ub; i++) {
    normals->data[i] = 1.0;
  }
  emxInit_real_T(sp, &L, 1, &cb_emlrtRTEI, true);
  i = L->size[0];
  L->size[0] = n;
  emxEnsureCapacity_real_T(sp, L, i, &cb_emlrtRTEI);
  for (i = 0; i < n; i++) {
    L->data[i] = 0.0;
  }
  emxInit_real_T(sp, &r, 1, &kb_emlrtRTEI, true);
  /*  系数矩阵L */
  /*  赋值 */
  i = r->size[0];
  r->size[0] = xc->size[0];
  emxEnsureCapacity_real_T(sp, r, i, &db_emlrtRTEI);
  loop_ub = xc->size[0];
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = xc->data[i] * 2.0;
  }
  emlrtSubAssignSizeCheckR2012b(&n, 1, &r->size[0], 1, &b_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    normals->data[i] = r->data[i];
  }
  i = r->size[0];
  r->size[0] = yc->size[0];
  emxEnsureCapacity_real_T(sp, r, i, &eb_emlrtRTEI);
  loop_ub = yc->size[0];
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = yc->data[i] * 2.0;
  }
  emlrtSubAssignSizeCheckR2012b(&normals->size[0], 1, &r->size[0], 1,
                                &c_emlrtECI, (emlrtCTX)sp);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    normals->data[i + normals->size[0]] = r->data[i];
  }
  st.site = &e_emlrtRSI;
  power(&st, xc, r);
  st.site = &e_emlrtRSI;
  power(&st, yc, xc);
  emxFree_real_T(&yc);
  if (r->size[0] != xc->size[0]) {
    emlrtSizeEqCheck1DR2012b(r->size[0], xc->size[0], &emlrtECI, (emlrtCTX)sp);
  }
  emlrtSubAssignSizeCheckR2012b(&n, 1, &r->size[0], 1, &d_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    L->data[i] = r->data[i] + xc->data[i];
  }
  emxFree_real_T(&r);
  /*  间接平差求解 */
  st.site = &f_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  b_st.site = &kh_emlrtRSI;
  mtimes(normals, normals, NBB);
  st.site = &g_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  dynamic_size_checks(&b_st, L, normals->size[0], L->size[0]);
  b_st.site = &kh_emlrtRSI;
  b_mtimes(normals, L, W);
  /*  参数求解 */
  st.site = &h_emlrtRSI;
  mldivide(&st, NBB, W, X);
  st.site = &i_emlrtRSI;
  b_st.site = &ci_emlrtRSI;
  st.site = &i_emlrtRSI;
  b_st.site = &ci_emlrtRSI;
  st.site = &i_emlrtRSI;
  denom = (X[0] * X[0] + X[1] * X[1]) + X[2];
  emxFree_real_T(&L);
  emxFree_real_T(&normals);
  if (denom < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  r0 = muDoubleScalarSqrt(denom);
  denom = X[0];
  b_y1 = X[1];
  for (i = 0; i < 3; i++) {
    W[i] = (denom * rot[3 * i] + b_y1 * rot[3 * i + 1]) + 0.0 * rot[3 * i + 2];
  }
  emxInit_real_T(sp, &zlimit, 2, &lb_emlrtRTEI, true);
  /*  旋转矩阵的逆与转置相等 */
  denom = W[0];
  b_y1 = W[1];
  st.site = &j_emlrtRSI;
  pointCloudBase_get_ZLimits(&st, &ptCloud, zlimit);
  /*  计算点云z坐标最值 */
  i = zlimit->size[0] * zlimit->size[1];
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &b_emlrtBCI, (emlrtCTX)sp);
  }
  i = zlimit->size[0] * zlimit->size[1];
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &c_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &Bn, 2, &fb_emlrtRTEI, true);
  z1 = (zlimit->data[0] + zlimit->data[1]) * 0.5;
  /*     %%
   * ------------------------------最小二乘迭代--------------------------- */
  i = Bn->size[0] * Bn->size[1];
  Bn->size[0] = n;
  Bn->size[1] = 7;
  emxEnsureCapacity_real_T(sp, Bn, i, &fb_emlrtRTEI);
  loop_ub = n * 7;
  emxFree_real_T(&zlimit);
  for (i = 0; i < loop_ub; i++) {
    Bn->data[i] = 1.0;
  }
  i = xc->size[0];
  xc->size[0] = n;
  emxEnsureCapacity_real_T(sp, xc, i, &gb_emlrtRTEI);
  for (i = 0; i < n; i++) {
    xc->data[i] = 1.0;
  }
  Xn[0] = W[0];
  Xn[1] = W[1];
  Xn[2] = z1;
  Xn[3] = coeff_data[6];
  Xn[4] = coeff_data[7];
  Xn[5] = coeff_data[8];
  Xn[6] = r0;
  count = 1;
  exitg1 = false;
  while ((!exitg1) &&
         covrtLogWhile(&emlrtCoverageInstance, 0U, 0U, 0, r0 > 0.001)) {
    for (b_i = 0; b_i < n; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
      if ((b_i + 1 < 1) || (b_i + 1 > x->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, x->size[0], &d_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if ((b_i + 1 < 1) || (b_i + 1 > y->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &e_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if ((b_i + 1 < 1) || (b_i + 1 > z->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, z->size[0], &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &g_emlrtBCI, (emlrtCTX)sp);
      }
      Bn_tmp_tmp = x->data[b_i] - denom;
      b_Bn_tmp_tmp = y->data[b_i] - b_y1;
      c_Bn_tmp_tmp = z->data[b_i] - z1;
      Bn_tmp = (a0 * Bn_tmp_tmp + b0 * b_Bn_tmp_tmp) + c0 * c_Bn_tmp_tmp;
      Bn->data[b_i] = (2.0 * denom - x->data[b_i] * 2.0) + 2.0 * a0 * Bn_tmp;
      loop_ub = Bn->size[0];
      for (i = 0; i < loop_ub; i++) {
        Bn->data[i + Bn->size[0]] =
            (2.0 * b_y1 - 2.0 * y->data[b_i]) + 2.0 * b0 * Bn_tmp;
      }
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &h_emlrtBCI, (emlrtCTX)sp);
      }
      Bn->data[b_i + Bn->size[0] * 2] =
          (2.0 * z1 - 2.0 * z->data[b_i]) + 2.0 * c0 * Bn_tmp;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      Bn->data[b_i + Bn->size[0] * 3] = -2.0 * Bn_tmp_tmp * Bn_tmp;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &j_emlrtBCI, (emlrtCTX)sp);
      }
      Bn->data[b_i + Bn->size[0] * 4] = -2.0 * b_Bn_tmp_tmp * Bn_tmp;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &k_emlrtBCI, (emlrtCTX)sp);
      }
      Bn->data[b_i + Bn->size[0] * 5] = -2.0 * c_Bn_tmp_tmp * Bn_tmp;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > Bn->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, Bn->size[0],
                                      &l_emlrtBCI, (emlrtCTX)sp);
      }
      Bn->data[b_i + Bn->size[0] * 6] = -2.0 * r0;
      st.site = &k_emlrtRSI;
      b_st.site = &ci_emlrtRSI;
      st.site = &k_emlrtRSI;
      b_st.site = &ci_emlrtRSI;
      st.site = &k_emlrtRSI;
      b_st.site = &ci_emlrtRSI;
      st.site = &k_emlrtRSI;
      b_st.site = &ci_emlrtRSI;
      st.site = &k_emlrtRSI;
      b_st.site = &ci_emlrtRSI;
      if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > xc->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, xc->size[0],
                                      &m_emlrtBCI, (emlrtCTX)sp);
      }
      xc->data[b_i] =
          -((((Bn_tmp_tmp * Bn_tmp_tmp + b_Bn_tmp_tmp * b_Bn_tmp_tmp) +
              c_Bn_tmp_tmp * c_Bn_tmp_tmp) -
             Bn_tmp * Bn_tmp) -
            r0 * r0);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
    /*  间接平差求解 */
    st.site = &l_emlrtRSI;
    b_st.site = &qh_emlrtRSI;
    b_st.site = &kh_emlrtRSI;
    c_mtimes(Bn, Bn, NBBn);
    st.site = &m_emlrtRSI;
    b_st.site = &qh_emlrtRSI;
    dynamic_size_checks(&b_st, xc, Bn->size[0], xc->size[0]);
    b_st.site = &kh_emlrtRSI;
    d_mtimes(Bn, xc, Wn);
    st.site = &n_emlrtRSI;
    pinv(&st, NBBn, a);
    for (i = 0; i < 7; i++) {
      denom = 0.0;
      for (loop_ub = 0; loop_ub < 7; loop_ub++) {
        denom += a[i + 7 * loop_ub] * Wn[loop_ub];
      }
      deltX[i] = denom;
      Xn[i] += denom;
    }
    /*  获取迭代增量 */
    denom = deltX[0];
    b_y1 = deltX[1];
    z1 = deltX[2];
    a0 = deltX[3];
    b0 = deltX[4];
    c0 = deltX[5];
    r0 = deltX[6];
    count++;
    /* 迭代次数足够多，跳出迭代。 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, count >= 10)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
      exitg1 = true;
    }
  }
  emxFree_real_T(&Bn);
  emxFree_real_T(&xc);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
  /*     %% ------------------------------返回值--------------------------- */
  *xn1 = Xn[0];
  *xn2 = Xn[1];
  *xn3 = Xn[2];
  *xn4 = Xn[3];
  *xn5 = Xn[4];
  *xn6 = Xn[5];
  *xn7 = Xn[6];
  st.site = &o_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &ptCloud);
  st.site = &o_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &circleCloud);
  emxFreeStruct_pointCloud(&ptCloud);
  emxFreeStruct_pointCloud(&circleCloud);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (cylderfit.c) */
