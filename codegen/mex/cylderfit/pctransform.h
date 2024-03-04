/*
 * pctransform.h
 *
 * Code generation for function 'pctransform'
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
pointCloud *pctransform(const emlrtStack *sp, const pointCloud *ptCloudIn,
                        const real_T tform_AffineTform_T[16],
                        pointCloud *iobj_0);

/* End of code generation (pctransform.h) */
