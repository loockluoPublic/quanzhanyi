/*
 * rigid3d.c
 *
 * Code generation for function 'rigid3d'
 *
 */

/* Include files */
#include "rigid3d.h"
#include "cylderfit_data.h"
#include "det.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo ye_emlrtRSI = {
    132,               /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo af_emlrtRSI = {
    142,               /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo bf_emlrtRSI = {
    146,               /* lineNo */
    "rigid3d/rigid3d", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo cf_emlrtRSI = {
    431,                      /* lineNo */
    "validateRotationMatrix", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo df_emlrtRSI = {
    387,                                   /* lineNo */
    "rigid3d/isTransformationMatrixRigid", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo ef_emlrtRSI = {
    388,                                   /* lineNo */
    "rigid3d/isTransformationMatrixRigid", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo ff_emlrtRSI = {
    395,                                   /* lineNo */
    "rigid3d/isTransformationMatrixRigid", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pathName
                                                                          */
};

static emlrtRSInfo yg_emlrtRSI = {
    128,                 /* lineNo */
    "affine3d/affine3d", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\affine3d.m" /* pathName
                                                                           */
};

static emlrtRSInfo ah_emlrtRSI = {
    331,              /* lineNo */
    "affine3d/set.T", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\affine3d.m" /* pathName
                                                                           */
};

static emlrtRSInfo bh_emlrtRSI = {
    336,              /* lineNo */
    "affine3d/set.T", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\affine3d.m" /* pathName
                                                                           */
};

static emlrtRTEInfo n_emlrtRTEI = {
    143,               /* lineNo */
    21,                /* colNo */
    "rigid3d/rigid3d", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\rigid3d.m" /* pName
                                                                          */
};

static emlrtRTEInfo o_emlrtRTEI = {
    337,              /* lineNo */
    17,               /* colNo */
    "affine3d/set.T", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\affine3d.m" /* pName
                                                                           */
};

static emlrtRTEInfo p_emlrtRTEI = {
    342,              /* lineNo */
    17,               /* colNo */
    "affine3d/set.T", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\images\\images\\affine3d.m" /* pName
                                                                           */
};

static emlrtRTEInfo q_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" /* pName */
};

/* Function Declarations */
static boolean_T c_rigid3d_isTransformationMatri(const emlrtStack *sp,
                                                 const real_T T[16]);

/* Function Definitions */
static boolean_T c_rigid3d_isTransformationMatri(const emlrtStack *sp,
                                                 const real_T T[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T T_data[49];
  real_T b_T[9];
  real_T singularValues[3];
  real_T absx;
  real_T b_ex;
  real_T c_ex;
  real_T ex;
  int32_T T_size[2];
  int32_T exponent;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  boolean_T isRigid;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &df_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gf_emlrtRSI;
  c_st.site = &if_emlrtRSI;
  T_size[0] = 3;
  T_size[1] = 3;
  for (k = 0; k < 3; k++) {
    idx = k << 2;
    T_data[3 * k] = T[idx];
    T_data[3 * k + 1] = T[idx + 1];
    T_data[3 * k + 2] = T[idx + 2];
  }
  d_st.site = &jf_emlrtRSI;
  p = flatVectorAllOrAny(T_data, T_size);
  if (p) {
    b_st.site = &hf_emlrtRSI;
    c_st.site = &lf_emlrtRSI;
    d_st.site = &mf_emlrtRSI;
    for (k = 0; k < 3; k++) {
      idx = k << 2;
      b_T[3 * k] = T[idx];
      b_T[3 * k + 1] = T[idx + 1];
      b_T[3 * k + 2] = T[idx + 2];
    }
    e_st.site = &nf_emlrtRSI;
    xzsvdc(&e_st, b_T, singularValues);
  } else {
    singularValues[0] = rtNaN;
    singularValues[1] = rtNaN;
    singularValues[2] = rtNaN;
  }
  st.site = &ef_emlrtRSI;
  b_st.site = &bg_emlrtRSI;
  c_st.site = &cg_emlrtRSI;
  d_st.site = &dg_emlrtRSI;
  p = muDoubleScalarIsNaN(singularValues[0]);
  if (!p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = singularValues[0];
  } else {
    ex = singularValues[idx - 1];
    idx++;
    for (k = idx; k < 4; k++) {
      absx = singularValues[k - 1];
      if (ex < absx) {
        ex = absx;
      }
    }
  }
  st.site = &ef_emlrtRSI;
  b_st.site = &kg_emlrtRSI;
  c_st.site = &lg_emlrtRSI;
  d_st.site = &mg_emlrtRSI;
  if (!p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    b_ex = singularValues[0];
  } else {
    b_ex = singularValues[idx - 1];
    idx++;
    for (k = idx; k < 4; k++) {
      absx = singularValues[k - 1];
      if (b_ex > absx) {
        b_ex = absx;
      }
    }
  }
  st.site = &ef_emlrtRSI;
  b_st.site = &bg_emlrtRSI;
  c_st.site = &cg_emlrtRSI;
  d_st.site = &dg_emlrtRSI;
  if (!p) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!muDoubleScalarIsNaN(singularValues[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    c_ex = singularValues[0];
  } else {
    c_ex = singularValues[idx - 1];
    idx++;
    for (k = idx; k < 4; k++) {
      absx = singularValues[k - 1];
      if (c_ex < absx) {
        c_ex = absx;
      }
    }
  }
  st.site = &ef_emlrtRSI;
  b_st.site = &ke_emlrtRSI;
  absx = muDoubleScalarAbs(c_ex);
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
  if (ex - b_ex < 1000.0 * absx) {
    for (k = 0; k < 3; k++) {
      idx = k << 2;
      b_T[3 * k] = T[idx];
      b_T[3 * k + 1] = T[idx + 1];
      b_T[3 * k + 2] = T[idx + 2];
    }
    st.site = &ff_emlrtRSI;
    absx = det(&st, b_T) - 1.0;
    if (muDoubleScalarAbs(absx) < 2.2204460492503131E-13) {
      isRigid = true;
    } else {
      isRigid = false;
    }
  } else {
    isRigid = false;
  }
  return isRigid;
}

void rigid3d_rigid3d(const emlrtStack *sp, const real_T varargin_1[9],
                     real_T this_AffineTform_T[16])
{
  static const int8_T varargin_2[4] = {0, 0, 0, 1};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T x1;
  int32_T i;
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ye_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &cf_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) &&
        (!muDoubleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigid3d:expectedFinite", 3, 4, 3, "rot");
  }
  for (i = 0; i < 3; i++) {
    k = i << 2;
    this_AffineTform_T[k] = varargin_1[3 * i];
    this_AffineTform_T[k + 1] = varargin_1[3 * i + 1];
    this_AffineTform_T[k + 2] = varargin_1[3 * i + 2];
    this_AffineTform_T[i + 12] = 0.0;
  }
  this_AffineTform_T[3] = 0.0;
  this_AffineTform_T[7] = 0.0;
  this_AffineTform_T[11] = 0.0;
  this_AffineTform_T[15] = 1.0;
  st.site = &af_emlrtRSI;
  if (!c_rigid3d_isTransformationMatri(&st, this_AffineTform_T)) {
    emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                  "images:geotrans:invalidRigidMatrix",
                                  "images:geotrans:invalidRigidMatrix", 0);
  }
  st.site = &bf_emlrtRSI;
  b_st.site = &yg_emlrtRSI;
  c_st.site = &ah_emlrtRSI;
  d_st.site = &eb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16)) {
    if ((!muDoubleScalarIsInf(this_AffineTform_T[k])) &&
        (!muDoubleScalarIsNaN(this_AffineTform_T[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:affine3d:set:T:expectedFinite", 3, 4, 1, "T");
  }
  d_st.site = &eb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16)) {
    if (!muDoubleScalarIsNaN(this_AffineTform_T[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &r_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:affine3d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }
  c_st.site = &bh_emlrtRSI;
  x1 = b_det(&c_st, this_AffineTform_T);
  p = (x1 == 0.0);
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!(this_AffineTform_T[k + 12] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
                                  "images:geotrans:invalidAffineMatrix",
                                  "images:geotrans:invalidAffineMatrix", 0);
  }
}

/* End of code generation (rigid3d.c) */
