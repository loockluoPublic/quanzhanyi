/*
 * File: Generate_multi_layered_measurement_points_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

#ifndef GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_EMXUTIL_H
#define GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_EMXUTIL_H

/* Include Files */
#include "Generate_multi_layered_measurement_points_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Generate_multi_layered_measurement_points_emxutil.h
 *
 * [EOF]
 */
