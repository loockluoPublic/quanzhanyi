/*
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 */

/* Include files */
#include "pinv.h"
#include "cylderfit_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "xscal.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo li_emlrtRSI =
    {
        21,     /* lineNo */
        "pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI =
    {
        42,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo ni_emlrtRSI =
    {
        46,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo oi_emlrtRSI =
    {
        53,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo pi_emlrtRSI =
    {
        68,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo qi_emlrtRSI =
    {
        69,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo ri_emlrtRSI =
    {
        72,         /* lineNo */
        "eml_pinv", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\pinv."
        "m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    53,    /* lineNo */
    "svd", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\svd."
    "m" /* pathName */
};

static emlrtRSInfo yi_emlrtRSI = {
    63,      /* lineNo */
    "xgemm", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xgemm.m" /* pathName */
};

static emlrtRSInfo aj_emlrtRSI = {
    65,      /* lineNo */
    "xgemm", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo bj_emlrtRSI = {
    128,     /* lineNo */
    "xgemm", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo cj_emlrtRSI = {
    135,     /* lineNo */
    "xgemm", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

/* Function Definitions */
void pinv(const emlrtStack *sp, const real_T A[49], real_T X[49])
{
  static const int32_T iv[2] = {7, 7};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T U[49];
  real_T V[49];
  real_T b_A[49];
  real_T S[7];
  real_T absx;
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T cr;
  int32_T ib;
  int32_T ic;
  int32_T j;
  int32_T r;
  int32_T vcol;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &li_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  memset(&X[0], 0, 49U * sizeof(real_T));
  b_st.site = &mi_emlrtRSI;
  c_st.site = &if_emlrtRSI;
  d_st.site = &jf_emlrtRSI;
  p = flatVectorAllOrAny(A, iv);
  if (!p) {
    for (vcol = 0; vcol < 49; vcol++) {
      X[vcol] = rtNaN;
    }
  } else {
    b_st.site = &ni_emlrtRSI;
    c_st.site = &si_emlrtRSI;
    d_st.site = &mf_emlrtRSI;
    memcpy(&b_A[0], &A[0], 49U * sizeof(real_T));
    e_st.site = &nf_emlrtRSI;
    b_xzsvdc(&e_st, b_A, U, S, V);
    b_st.site = &oi_emlrtRSI;
    c_st.site = &ke_emlrtRSI;
    absx = muDoubleScalarAbs(S[0]);
    if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = ldexp(1.0, vcol - 53);
      }
    } else {
      absx = rtNaN;
    }
    absx *= 7.0;
    r = 0;
    vcol = 0;
    while ((vcol < 7) && (S[vcol] > absx)) {
      r++;
      vcol++;
    }
    if (r > 0) {
      vcol = 1;
      b_st.site = &pi_emlrtRSI;
      if (r > 2147483646) {
        c_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (j = 0; j < r; j++) {
        b_st.site = &qi_emlrtRSI;
        e_xscal(&b_st, 1.0 / S[j], V, vcol);
        vcol += 7;
      }
      b_st.site = &ri_emlrtRSI;
      c_st.site = &yi_emlrtRSI;
      for (cr = 0; cr <= 42; cr += 7) {
        vcol = cr + 1;
        j = cr + 7;
        d_st.site = &aj_emlrtRSI;
        if (vcol <= j) {
          memset(&X[vcol + -1], 0, ((j - vcol) + 1) * sizeof(real_T));
        }
      }
      br = 0;
      for (cr = 0; cr <= 42; cr += 7) {
        ar = -1;
        br++;
        j = br + 7 * (r - 1);
        d_st.site = &bj_emlrtRSI;
        if ((br <= j) && (j > 2147483640)) {
          e_st.site = &nc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (ib = br; ib <= j; ib += 7) {
          vcol = cr + 1;
          b = cr + 7;
          d_st.site = &cj_emlrtRSI;
          for (ic = vcol; ic <= b; ic++) {
            X[ic - 1] += U[ib - 1] * V[(ar + ic) - cr];
          }
          ar += 7;
        }
      }
    }
  }
}

/* End of code generation (pinv.c) */
