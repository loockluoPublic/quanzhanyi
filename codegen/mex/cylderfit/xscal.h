/*
 * xscal.h
 *
 * Code generation for function 'xscal'
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
void b_xscal(const emlrtStack *sp, real_T a, real_T x[3], int32_T ix0);

void c_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[49],
             int32_T ix0);

void d_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[7],
             int32_T ix0);

void e_xscal(const emlrtStack *sp, real_T a, real_T x[49], int32_T ix0);

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0);

/* End of code generation (xscal.h) */
