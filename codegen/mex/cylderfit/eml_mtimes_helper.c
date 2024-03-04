/*
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "cylderfit_data.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *b,
                         int32_T innerDimA, int32_T innerDimB)
{
  if (innerDimA != innerDimB) {
    if (b->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          sp, &u_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &t_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
}

/* End of code generation (eml_mtimes_helper.c) */
