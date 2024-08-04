/*
 * File: svd1.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 05-Aug-2024 00:10:26
 */

#ifndef SVD1_H
#define SVD1_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
           double V[16]);

void d_svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
           double V[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for svd1.h
 *
 * [EOF]
 */
