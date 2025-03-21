/*
 * File: mldivide.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 29-Sep-2024 01:27:40
 */

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_mldivide(const double A[9], const double B_data[], double Y[3]);

void c_mldivide(const double A[9], const double B[3], double Y[3]);

void d_mldivide(const double A[6], const double B[2], double Y[3]);

void mldivide(const emxArray_real_T *A, const emxArray_real_T *B, double Y[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mldivide.h
 *
 * [EOF]
 */
