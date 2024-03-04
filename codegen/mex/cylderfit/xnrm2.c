/*
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "xnrm2.h"
#include "cylderfit_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = {
    23,      /* lineNo */
    "xnrm2", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xnrm2.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    38,      /* lineNo */
    "xnrm2", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xnrm2.m" /* pathName */
};

/* Function Definitions */
real_T b_xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = ix0 + 1;
  b_st.site = &td_emlrtRSI;
  if ((ix0 <= ix0 + 1) && (ix0 + 1 > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * muDoubleScalarSqrt(y);
}

real_T c_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[49], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  b_st.site = &td_emlrtRSI;
  if ((ix0 <= kend) && (kend > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * muDoubleScalarSqrt(y);
}

real_T d_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[7], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  b_st.site = &td_emlrtRSI;
  if ((ix0 <= kend) && (kend > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * muDoubleScalarSqrt(y);
}

real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  b_st.site = &td_emlrtRSI;
  if ((ix0 <= kend) && (kend > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * muDoubleScalarSqrt(y);
}

/* End of code generation (xnrm2.c) */
