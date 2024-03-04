/*
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[3]);

void c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[49]);

void d_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[7]);

void mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[9]);

/* End of code generation (mtimes.h) */
