/*
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T b_xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0);

real_T c_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[49],
               int32_T ix0);

real_T d_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[7], int32_T ix0);

real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0);

/* End of code generation (xnrm2.h) */
