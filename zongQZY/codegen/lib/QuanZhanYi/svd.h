/*
 * File: svd.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

#ifndef SVD_H
#define SVD_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_svd(const emxArray_real_T *A, emxArray_real_T *U, double s_data[],
           int *s_size, double V[16]);

void d_svd(const emxArray_real_T *A, emxArray_real_T *U, double s_data[],
           int *s_size, double V[9]);

void e_svd(const double A[8], double U[4], double s[2], double V[16]);

void svd(const double A[9], double U[9], double s[3], double V[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for svd.h
 *
 * [EOF]
 */
