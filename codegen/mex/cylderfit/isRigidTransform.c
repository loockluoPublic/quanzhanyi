/*
 * isRigidTransform.c
 *
 * Code generation for function 'isRigidTransform'
 *
 */

/* Include files */
#include "isRigidTransform.h"
#include "cylderfit_data.h"
#include "det.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo nh_emlrtRSI = {
    10,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\isRigidTransform.m" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    11,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\isRigidTransform.m" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    12,                 /* lineNo */
    "isRigidTransform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\isRigidTransform.m" /* pathName */
};

/* Function Definitions */
boolean_T isRigidTransform(const emlrtStack *sp, const real_T T[16])
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
  boolean_T p;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nh_emlrtRSI;
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
  st.site = &oh_emlrtRSI;
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
  st.site = &oh_emlrtRSI;
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
  st.site = &oh_emlrtRSI;
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
  st.site = &oh_emlrtRSI;
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
  if (ex - b_ex < 100.0 * absx) {
    st.site = &ph_emlrtRSI;
    absx = b_det(&st, T) - 1.0;
    if (muDoubleScalarAbs(absx) < 2.2204460492503131E-14) {
      tf = true;
    } else {
      tf = false;
    }
  } else {
    tf = false;
  }
  return tf;
}

/* End of code generation (isRigidTransform.c) */
