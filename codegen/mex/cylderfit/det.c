/*
 * det.c
 *
 * Code generation for function 'det'
 *
 */

/* Include files */
#include "det.h"
#include "cylderfit_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    pg_emlrtRSI =
        {
            21,    /* lineNo */
            "det", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\d"
            "et.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo rg_emlrtRSI = {
    50,        /* lineNo */
    "xzgetrf", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    58,        /* lineNo */
    "xzgetrf", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xgeru.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    45,     /* lineNo */
    "xger", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\xger.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    41,      /* lineNo */
    "xgerx", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

/* Function Definitions */
real_T b_det(const emlrtStack *sp, const real_T x[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_x[16];
  real_T s;
  real_T smax;
  real_T y;
  int32_T b_tmp;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int32_T n;
  int8_T ipiv[4];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pg_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  memcpy(&b_x[0], &x[0], 16U * sizeof(real_T));
  b_st.site = &qg_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    n = 4 - j;
    jA = 0;
    smax = muDoubleScalarAbs(b_x[b_tmp]);
    for (k = 2; k <= n; k++) {
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + jA] != 0.0) {
      if (jA != 0) {
        jA += j;
        ipiv[j] = (int8_T)(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 4];
        b_x[j + 4] = b_x[jA + 4];
        b_x[jA + 4] = smax;
        smax = b_x[j + 8];
        b_x[j + 8] = b_x[jA + 8];
        b_x[jA + 8] = smax;
        smax = b_x[j + 12];
        b_x[j + 12] = b_x[jA + 12];
        b_x[jA + 12] = smax;
      }
      k = (b_tmp - j) + 4;
      c_st.site = &rg_emlrtRSI;
      for (jA = jp1j; jA <= k; jA++) {
        b_x[jA - 1] /= b_x[b_tmp];
      }
    }
    n = 2 - j;
    c_st.site = &sg_emlrtRSI;
    d_st.site = &tg_emlrtRSI;
    e_st.site = &ug_emlrtRSI;
    f_st.site = &vg_emlrtRSI;
    jA = b_tmp + 6;
    g_st.site = &xg_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_x[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0) {
        k = (jA - j) + 2;
        g_st.site = &wg_emlrtRSI;
        if ((jA <= k) && (k > 2147483646)) {
          h_st.site = &nc_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (ijA = jA; ijA <= k; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -smax;
        }
      }
      jA += 4;
    }
  }
  isodd = (ipiv[0] > 1);
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  y = b_x[0] * b_x[5] * b_x[10] * b_x[15];
  if (ipiv[2] > 3) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

real_T det(const emlrtStack *sp, const real_T x[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_x[9];
  real_T s;
  real_T smax;
  real_T y;
  int32_T b_tmp;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int32_T n;
  int8_T ipiv[3];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pg_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  b_st.site = &qg_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (j = 0; j < 2; j++) {
    b_tmp = j << 2;
    jp1j = b_tmp + 2;
    n = 3 - j;
    jA = 0;
    smax = muDoubleScalarAbs(b_x[b_tmp]);
    for (k = 2; k <= n; k++) {
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + jA] != 0.0) {
      if (jA != 0) {
        jA += j;
        ipiv[j] = (int8_T)(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 3];
        b_x[j + 3] = b_x[jA + 3];
        b_x[jA + 3] = smax;
        smax = b_x[j + 6];
        b_x[j + 6] = b_x[jA + 6];
        b_x[jA + 6] = smax;
      }
      k = (b_tmp - j) + 3;
      c_st.site = &rg_emlrtRSI;
      for (jA = jp1j; jA <= k; jA++) {
        b_x[jA - 1] /= b_x[b_tmp];
      }
    }
    n = 1 - j;
    c_st.site = &sg_emlrtRSI;
    d_st.site = &tg_emlrtRSI;
    e_st.site = &ug_emlrtRSI;
    f_st.site = &vg_emlrtRSI;
    jA = b_tmp + 5;
    g_st.site = &xg_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_x[(b_tmp + jp1j * 3) + 3];
      if (smax != 0.0) {
        k = (jA - j) + 1;
        g_st.site = &wg_emlrtRSI;
        if ((jA <= k) && (k > 2147483646)) {
          h_st.site = &nc_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (ijA = jA; ijA <= k; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -smax;
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = b_x[0] * b_x[4] * b_x[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

/* End of code generation (det.c) */
