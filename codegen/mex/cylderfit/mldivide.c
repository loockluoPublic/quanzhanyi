/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wh_emlrtRSI =
    {
        20,         /* lineNo */
        "mldivide", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\mldivide"
        ".m" /* pathName */
};

static emlrtRSInfo xh_emlrtRSI =
    {
        42,      /* lineNo */
        "mldiv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\mldivide"
        ".m" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    61,        /* lineNo */
    "lusolve", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo ai_emlrtRSI = {
    293,          /* lineNo */
    "lusolve3x3", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo bi_emlrtRSI = {
    90,              /* lineNo */
    "warn_singular", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\lusolve.m" /* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[3],
              real_T Y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &xh_emlrtRSI;
  c_st.site = &yh_emlrtRSI;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(A[0]);
  a21 = muDoubleScalarAbs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (muDoubleScalarAbs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  b_A[r2] = A[r2] / A[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
    d_st.site = &ai_emlrtRSI;
    e_st.site = &bi_emlrtRSI;
    b_warning(&e_st);
  }
  Y[1] = B[r2] - B[r1] * b_A[r2];
  Y[2] = (B[r3] - B[r1] * b_A[r3]) - Y[1] * b_A[r3 + 3];
  Y[2] /= b_A[r3 + 6];
  Y[0] = B[r1] - Y[2] * b_A[r1 + 6];
  Y[1] -= Y[2] * b_A[r2 + 6];
  Y[1] /= b_A[r2 + 3];
  Y[0] -= Y[1] * b_A[r1 + 3];
  Y[0] /= b_A[r1];
}

/* End of code generation (mldivide.c) */
