/*
 * File: mtimes.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 20:27:52
 */

#ifndef MTIMES_H
#define MTIMES_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_mtimes(const double A[4], const emxArray_real_T *B, emxArray_real_T *C);

void c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, double C[9]);

void d_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, double C[3]);

void mtimes(const emxArray_real_T *A, const double B[9], emxArray_real_T *C);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mtimes.h
 *
 * [EOF]
 */
