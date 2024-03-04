/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo rh_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power."
        "m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI =
    {
        80,         /* lineNo */
        "fltpower", /* fcnName */
        "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power."
        "m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    52,      /* lineNo */
    "ixfun", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\ixfun.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo vh_emlrtRSI = {
    200,        /* lineNo */
    "flatIter", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    127,                         /* lineNo */
    6,                           /* colNo */
    "applyBinaryScalarFunction", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rh_emlrtRSI;
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
  b_st.site = &sh_emlrtRSI;
  c_st.site = &th_emlrtRSI;
  d_st.site = &uh_emlrtRSI;
  nx = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&d_st, y, nx, &pd_emlrtRTEI);
  nx = a->size[0];
  e_st.site = &vh_emlrtRSI;
  if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
    f_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (k = 0; k < nx; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

/* End of code generation (power.c) */
