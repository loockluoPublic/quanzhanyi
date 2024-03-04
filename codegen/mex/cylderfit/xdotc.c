/*
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "cylderfit_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo yd_emlrtRSI = {
    32,      /* lineNo */
    "xdotc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xdotc.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    35,     /* lineNo */
    "xdot", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xdot.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    15,     /* lineNo */
    "xdot", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdot.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    42,      /* lineNo */
    "xdotx", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" /* pathName */
};

/* Function Definitions */
real_T b_xdotc(const emlrtStack *sp, int32_T n, const real_T x[49], int32_T ix0,
               const real_T y[49], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  d = 0.0;
  d_st.site = &ce_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    e_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < n; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
             const real_T y[9], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  d = 0.0;
  d_st.site = &ce_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    e_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < n; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/* End of code generation (xdotc.c) */
