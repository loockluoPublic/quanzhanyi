/*
 * cylderfit.h
 *
 * Code generation for function 'cylderfit'
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
void cylderfit(const emlrtStack *sp, const emxArray_real_T *x,
               const emxArray_real_T *y, const emxArray_real_T *z, real_T *xn1,
               real_T *xn2, real_T *xn3, real_T *xn4, real_T *xn5, real_T *xn6,
               real_T *xn7);

/* End of code generation (cylderfit.h) */
