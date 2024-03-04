/*
 * pinv.h
 *
 * Code generation for function 'pinv'
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
void pinv(const emlrtStack *sp, const real_T A[49], real_T X[49]);

/* End of code generation (pinv.h) */
