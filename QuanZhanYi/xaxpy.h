/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 18-Jun-2024 11:44:39
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
void b_xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0);

void c_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0);

void d_xaxpy(int n, double a, int ix0, double y[16], int iy0);

void e_xaxpy(int n, double a, int ix0, double y[8], int iy0);

void f_xaxpy(double a, double y[4]);

void g_xaxpy(int n, double a, const double x[8], int ix0, double y[2]);

void h_xaxpy(int n, double a, const double x[2], double y[8], int iy0);

void i_xaxpy(double a, const double x[9], int ix0, double y[3]);

void j_xaxpy(double a, const double x[3], double y[9], int iy0);

void k_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y);

void l_xaxpy(int n, double a, const emxArray_real_T *x, emxArray_real_T *y,
             int iy0);

void xaxpy(int n, double a, int ix0, double y[9], int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
