/*
 * mldivide.h
 *
 * Code generation for function 'mldivide'
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
void mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[3],
              real_T Y[3]);

/* End of code generation (mldivide.h) */
