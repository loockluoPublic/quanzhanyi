/*
 * File: QuanZhanYi_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
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
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeStruct_captured_var(b_captured_var *pStruct);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitStruct_captured_var(b_captured_var *pStruct);

extern void emxInitStruct_captured_var1(b_captured_var *pStruct);

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
