/*
 * pcnormals.h
 *
 * Code generation for function 'pcnormals'
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
void pcnormals(const emlrtStack *sp, pointCloud *ptCloud,
               emxArray_real_T *normals);

/* End of code generation (pcnormals.h) */
