/*
 * xdotc.h
 *
 * Code generation for function 'xdotc'
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
real_T b_xdotc(const emlrtStack *sp, int32_T n, const real_T x[49], int32_T ix0,
               const real_T y[49], int32_T iy0);

real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
             const real_T y[9], int32_T iy0);

/* End of code generation (xdotc.h) */
