/*
 * File: initializeRansacModel.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

#ifndef INITIALIZERANSACMODEL_H
#define INITIALIZERANSACMODEL_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void initializeRansacModel(const b_pointCloud *ptCloud, pointCloud *iobj_0,
                           int *status, pointCloud **pc,
                           double validPtCloudIndices_data[],
                           int *validPtCloudIndices_size);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for initializeRansacModel.h
 *
 * [EOF]
 */
