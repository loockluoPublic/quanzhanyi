/*
 * pointCloudBase.h
 *
 * Code generation for function 'pointCloudBase'
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
void pointCloudBase_get_ZLimits(const emlrtStack *sp, pointCloud *this,
                                emxArray_real_T *zlim);

void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                              const emxArray_uint8_T *value);

void pointCloudBase_set_Intensity(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *value);

void pointCloudBase_set_Normal(const emlrtStack *sp, pointCloud *this,
                               const emxArray_real_T *value);

/* End of code generation (pointCloudBase.h) */
