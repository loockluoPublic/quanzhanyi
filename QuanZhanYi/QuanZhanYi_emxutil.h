/*
 * File: QuanZhanYi_emxutil.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 22-Sep-2024 11:56:57
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
extern void emxCopyStruct_cell_wrap_1(cell_wrap_1 *dst, const cell_wrap_1 *src);

extern void emxCopyStruct_cell_wrap_4(cell_wrap_4 *dst, const cell_wrap_4 *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_1(cell_wrap_1 pMatrix[8]);

extern void emxFreeMatrix_cell_wrap_11(cell_wrap_1 pMatrix[4]);

extern void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[8]);

extern void emxFreeMatrix_cell_wrap_41(cell_wrap_4 pMatrix[4]);

extern void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct);

extern void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_1(cell_wrap_1 pMatrix[8]);

extern void emxInitMatrix_cell_wrap_11(cell_wrap_1 pMatrix[4]);

extern void emxInitMatrix_cell_wrap_4(cell_wrap_4 pMatrix[8]);

extern void emxInitMatrix_cell_wrap_41(cell_wrap_4 pMatrix[4]);

extern void emxInitStruct_cell_wrap_1(cell_wrap_1 *pStruct);

extern void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for QuanZhanYi_emxutil.h
 *
 * [EOF]
 */
