/*
 * xgesvd.h
 *
 * Code generation for function 'xgesvd'
 *
 */

#pragma once

/* Include files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void ceval_xgesvd(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *U,
                  real_T S_data[], int32_T *S_size, real_T V_data[],
                  int32_T V_size[2], int32_T *info);

/* End of code generation (xgesvd.h) */
