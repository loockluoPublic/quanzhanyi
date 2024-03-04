/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "sqrt.h"
#include "cylderfit_data.h"
#include "cylderfit_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1];
  b_st.site = &ld_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &nc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    x->data[k] = 1.0;
  }
}

/* End of code generation (sqrt.c) */
