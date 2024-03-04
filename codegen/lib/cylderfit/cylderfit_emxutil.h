/*
 * File: cylderfit_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

#ifndef CYLDERFIT_EMXUTIL_H
#define CYLDERFIT_EMXUTIL_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
c_emxFree_pointclouds_internal_(c_emxArray_pointclouds_internal **pEmxArray);

extern void
c_emxInit_pointclouds_internal_(c_emxArray_pointclouds_internal **pEmxArray,
                                int numDimensions);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray,
                                       int oldNumel);

extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxFreeStruct_pointCloud(pointCloud *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInitStruct_pointCloud(pointCloud *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
                              int numDimensions);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for cylderfit_emxutil.h
 *
 * [EOF]
 */
