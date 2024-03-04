/*
 * pointCloud.h
 *
 * Code generation for function 'pointCloud'
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
pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *varargin_1);

void pointCloud_surfaceNormalImpl(const emlrtStack *sp, pointCloud *this,
                                  emxArray_real_T *normals);

/* End of code generation (pointCloud.h) */
