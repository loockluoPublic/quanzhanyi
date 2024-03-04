/*
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "cylderfit_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo re_emlrtRSI = {
    178,          /* lineNo */
    "sumColumnB", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    210,         /* lineNo */
    "sumColumn", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T sumColumnB(const emlrtStack *sp, const real_T x_data[], int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &re_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = x_data[0];
  b_st.site = &se_emlrtRSI;
  if ((1 <= vlen - 1) && (vlen - 1 > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k <= vlen - 2; k++) {
    y += x_data[k + 1];
  }
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */
