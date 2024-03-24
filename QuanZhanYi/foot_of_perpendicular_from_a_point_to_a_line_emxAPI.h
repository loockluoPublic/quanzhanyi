/*
 * File: foot_of_perpendicular_from_a_point_to_a_line_emxAPI.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 17:37:00
 */

#ifndef FOOT_OF_PERPENDICULAR_FROM_A_POINT_TO_A_LINE_EMXAPI_H
#define FOOT_OF_PERPENDICULAR_FROM_A_POINT_TO_A_LINE_EMXAPI_H

/* Include Files */
#include "foot_of_perpendicular_from_a_point_to_a_line_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for foot_of_perpendicular_from_a_point_to_a_line_emxAPI.h
 *
 * [EOF]
 */
