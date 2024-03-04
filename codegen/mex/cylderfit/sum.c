/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo le_emlrtRSI =
    {
        20,    /* lineNo */
        "sum", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sum."
        "m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\combineVectorElements.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\blockedSummation.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T sum(const emlrtStack *sp, const real_T x_data[], int32_T x_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &le_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &me_emlrtRSI;
  c_st.site = &ne_emlrtRSI;
  if (x_size == 0) {
    y = 0.0;
  } else {
    d_st.site = &oe_emlrtRSI;
    e_st.site = &pe_emlrtRSI;
    f_st.site = &qe_emlrtRSI;
    y = sumColumnB(&f_st, x_data, x_size);
  }
  return y;
}

/* End of code generation (sum.c) */
