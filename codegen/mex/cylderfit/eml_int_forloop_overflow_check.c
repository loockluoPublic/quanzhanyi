/*
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "eml_int_forloop_overflow_check.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = {
    88,                             /* lineNo */
    9,                              /* colNo */
    "check_forloop_overflow_error", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_"
    "forloop_overflow_check.m" /* pName */
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(
      sp, &i_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
