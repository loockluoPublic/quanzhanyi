/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "mycylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xaxpy(int n, double a, int ix0, double y[49], int iy0);

void c_xaxpy(int n, double a, const double x[49], int ix0, double y[7],
             int iy0);

void d_xaxpy(int n, double a, const double x[7], int ix0, double y[49],
             int iy0);

void e_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y);

void f_xaxpy(int n, double a, const emxArray_real_T *x, emxArray_real_T *y,
             int iy0);

void g_xaxpy(double a, const double x[3], double y[9], int iy0);

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
