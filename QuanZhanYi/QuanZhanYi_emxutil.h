/*
 * File: QuanZhanYi_emxutil.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Dec-2024 22:58:37
 */

#ifndef QUANZHANYI_EMXUTIL_H
#define QUANZHANYI_EMXUTIL_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxCopyStruct_cell_wrap_5(cell_wrap_5 *dst, const cell_wrap_5 *src);

extern void emxCopyStruct_cell_wrap_8(cell_wrap_8 *dst, const cell_wrap_8 *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_5(cell_wrap_5 pMatrix[8]);

extern void emxFreeMatrix_cell_wrap_51(cell_wrap_5 pMatrix[4]);

extern void emxFreeMatrix_cell_wrap_8(cell_wrap_8 pMatrix[8]);

extern void emxFreeMatrix_cell_wrap_81(cell_wrap_8 pMatrix[4]);

extern void emxFreeStruct_cell_wrap_5(cell_wrap_5 *pStruct);

extern void emxFreeStruct_cell_wrap_8(cell_wrap_8 *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_5(cell_wrap_5 pMatrix[8]);

extern void emxInitMatrix_cell_wrap_51(cell_wrap_5 pMatrix[4]);

extern void emxInitMatrix_cell_wrap_8(cell_wrap_8 pMatrix[8]);

extern void emxInitMatrix_cell_wrap_81(cell_wrap_8 pMatrix[4]);

extern void emxInitStruct_cell_wrap_5(cell_wrap_5 *pStruct);

extern void emxInitStruct_cell_wrap_8(cell_wrap_8 *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxReserve_real_T(emxArray_real_T *emxArray);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for QuanZhanYi_emxutil.h
 *
 * [EOF]
 */
