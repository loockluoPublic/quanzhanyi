/*
 * xzsvdc.h
 *
 * Code generation for function 'xzsvdc'
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
void b_xzsvdc(const emlrtStack *sp, real_T A[49], real_T U[49], real_T S[7],
              real_T V[49]);

void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3]);

/* End of code generation (xzsvdc.h) */
