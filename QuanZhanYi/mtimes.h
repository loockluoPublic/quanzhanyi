/*
 * File: mtimes.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 21-Dec-2024 00:53:50
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
void b_mtimes(const emxArray_real_T *A, const double B[9], emxArray_real_T *C);

void c_mtimes(const double A[4], const emxArray_real_T *B, emxArray_real_T *C);

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
