/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Nov-2024 20:42:34
 */

/* Include Files */
#include "xaxpy.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  double *y_data;
  int i;
  int i1;
  int k;
  y_data = y->data;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y_data[i1] += a * y_data[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const emxArray_real_T *x
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0)
{
  const double *x_data;
  double *y_data;
  int i;
  int i1;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y_data[i1] += a * x_data[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[16]
 *                int iy0
 * Return Type  : void
 */
void d_xaxpy(int n, double a, int ix0, double y[16], int iy0)
{
  int i;
  int i1;
  int k;
  if (!(a == 0.0)) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[8]
 *                int iy0
 * Return Type  : void
 */
void e_xaxpy(int n, double a, int ix0, double y[8], int iy0)
{
  int i;
  int i1;
  int k;
  if (!(a == 0.0)) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : double a
 *                double y[4]
 * Return Type  : void
 */
void f_xaxpy(double a, double y[4])
{
  if (!(a == 0.0)) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[8]
 *                int ix0
 *                double y[2]
 * Return Type  : void
 */
void g_xaxpy(int n, double a, const double x[8], int ix0, double y[2])
{
  if ((n >= 1) && (!(a == 0.0))) {
    y[1] += a * x[ix0 - 1];
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[2]
 *                double y[8]
 *                int iy0
 * Return Type  : void
 */
void h_xaxpy(int n, double a, const double x[2], double y[8], int iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    y[iy0 - 1] += a * x[1];
  }
}

/*
 * Arguments    : double a
 *                const double x[9]
 *                int ix0
 *                double y[3]
 * Return Type  : void
 */
void i_xaxpy(double a, const double x[9], int ix0, double y[3])
{
  int k;
  if (!(a == 0.0)) {
    for (k = 0; k < 2; k++) {
      y[k + 1] += a * x[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : double a
 *                const double x[3]
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void j_xaxpy(double a, const double x[3], double y[9], int iy0)
{
  int i;
  int k;
  if (!(a == 0.0)) {
    for (k = 0; k < 2; k++) {
      i = (iy0 + k) - 1;
      y[i] += a * x[k + 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const emxArray_real_T *x
 *                int ix0
 *                emxArray_real_T *y
 * Return Type  : void
 */
void k_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y)
{
  const double *x_data;
  double *y_data;
  int i;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y_data[k + 1] += a * x_data[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const emxArray_real_T *x
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void l_xaxpy(int n, double a, const emxArray_real_T *x, emxArray_real_T *y,
             int iy0)
{
  const double *x_data;
  double *y_data;
  int i;
  int i1;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y_data[i1] += a * x_data[k + 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[9], int iy0)
{
  int i;
  int i1;
  int k;
  if (!(a == 0.0)) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
