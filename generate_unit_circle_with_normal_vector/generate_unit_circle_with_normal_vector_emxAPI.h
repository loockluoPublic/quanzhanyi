/*
 * File: generate_unit_circle_with_normal_vector_emxAPI.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 21-Mar-2024 21:48:40
 */

#ifndef GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_EMXAPI_H
#define GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_EMXAPI_H

/* Include Files */
#include "generate_unit_circle_with_normal_vector_types.h"
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
 * File trailer for generate_unit_circle_with_normal_vector_emxAPI.h
 *
 * [EOF]
 */
