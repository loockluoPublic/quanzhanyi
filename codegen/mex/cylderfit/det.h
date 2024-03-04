/*
 * det.h
 *
 * Code generation for function 'det'
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
real_T b_det(const emlrtStack *sp, const real_T x[16]);

real_T det(const emlrtStack *sp, const real_T x[9]);

/* End of code generation (det.h) */
