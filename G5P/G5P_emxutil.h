/*
 * File: G5P_emxutil.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Mar-2024 19:53:49
 */

#ifndef G5P_EMXUTIL_H
#define G5P_EMXUTIL_H

/* Include Files */
#include "G5P_types.h"
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
 * File trailer for G5P_emxutil.h
 *
 * [EOF]
 */
