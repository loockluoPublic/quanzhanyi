/*
 * File: QuanZhanYi_emxutil.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
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
extern void emxCopyStruct_cell_wrap_6(cell_wrap_6 *dst, const cell_wrap_6 *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_6(cell_wrap_6 pMatrix[4]);

extern void emxFreeMatrix_cell_wrap_61(cell_wrap_6 pMatrix[8]);

extern void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_6(cell_wrap_6 pMatrix[4]);

extern void emxInitMatrix_cell_wrap_61(cell_wrap_6 pMatrix[8]);

extern void emxInitStruct_cell_wrap_6(cell_wrap_6 *pStruct);

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
