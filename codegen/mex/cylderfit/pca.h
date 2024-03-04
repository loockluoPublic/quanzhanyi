/*
 * pca.h
 *
 * Code generation for function 'pca'
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
void pca(const emlrtStack *sp, const emxArray_real_T *x,
         real_T varargout_1_data[], int32_T varargout_1_size[2],
         emxArray_real_T *varargout_2, real_T varargout_3_data[],
         int32_T *varargout_3_size, emxArray_real_T *varargout_4,
         real_T varargout_5_data[], int32_T *varargout_5_size,
         real_T varargout_6_data[], int32_T varargout_6_size[2]);

/* End of code generation (pca.h) */
