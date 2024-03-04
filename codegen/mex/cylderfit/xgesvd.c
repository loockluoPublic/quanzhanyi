/*
 * xgesvd.c
 *
 * Code generation for function 'xgesvd'
 *
 */

/* Include files */
#include "xgesvd.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = {
    197,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    47,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    44,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    75,       /* lineNo */
    24,       /* colNo */
    "xgesvd", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

/* Function Definitions */
void ceval_xgesvd(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *U,
                  real_T S_data[], int32_T *S_size, real_T V_data[],
                  int32_T V_size[2], int32_T *info)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'v', 'd'};
  ptrdiff_t info_t;
  emlrtStack st;
  real_T Vt_data[9];
  real_T superb_data[2];
  int32_T m;
  int32_T minmn;
  int32_T minnm;
  st.prev = sp;
  st.tls = sp->tls;
  m = A->size[0];
  minnm = muIntScalarMin_sint32(3, m);
  minmn = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = minnm;
  emxEnsureCapacity_real_T(sp, U, minmn, &tc_emlrtRTEI);
  *S_size = minnm;
  if (A->size[0] != 0) {
    info_t = LAPACKE_dgesvd(102, 'S', 'S', (ptrdiff_t)A->size[0], (ptrdiff_t)3,
                            &A->data[0], (ptrdiff_t)A->size[0], &S_data[0],
                            &U->data[0], (ptrdiff_t)A->size[0], &Vt_data[0],
                            (ptrdiff_t)minnm, &superb_data[0]);
    *info = (int32_T)info_t;
  } else {
    *info = 0;
  }
  minmn = muIntScalarMin_sint32(m, 3);
  V_size[0] = 3;
  V_size[1] = minmn;
  for (m = 0; m < minmn; m++) {
    V_data[3 * m] = Vt_data[m];
    V_data[3 * m + 1] = Vt_data[m + minnm];
    V_data[3 * m + 2] = Vt_data[m + minnm * 2];
  }
  st.site = &nd_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(
          &st, &j_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0], 12, *info);
    }
  }
}

/* End of code generation (xgesvd.c) */
