/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 22:27:47
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0);

void c_xaxpy(int n, double a, int ix0, double y[16], int iy0);

void d_xaxpy(int n, double a, int ix0, double y[9], int iy0);

void e_xaxpy(int n, double a, const double x[9], int ix0, double y[3], int iy0);

void f_xaxpy(int n, double a, const double x[3], int ix0, double y[9], int iy0);

void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
