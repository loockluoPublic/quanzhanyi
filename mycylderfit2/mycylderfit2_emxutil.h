/*
 * File: mycylderfit2_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

#ifndef MYCYLDERFIT2_EMXUTIL_H
#define MYCYLDERFIT2_EMXUTIL_H

/* Include Files */
#include "mycylderfit2_types.h"
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
 * File trailer for mycylderfit2_emxutil.h
 *
 * [EOF]
 */
