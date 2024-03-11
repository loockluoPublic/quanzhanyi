/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "xaxpy.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[49]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, int ix0, double y[49], int iy0)
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
 *                const double x[49]
 *                int ix0
 *                double y[7]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[49], int ix0, double y[7], int iy0)
{
  int i;
  int i1;
  int k;
  if (!(a == 0.0)) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y[i1] += a * x[(ix0 + k) - 1];
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[7]
 *                int ix0
 *                double y[49]
 *                int iy0
 * Return Type  : void
 */
void d_xaxpy(int n, double a, const double x[7], int ix0, double y[49], int iy0)
{
  int i;
  int i1;
  int k;
  if (!(a == 0.0)) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y[i1] += a * x[(ix0 + k) - 1];
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
void e_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
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
void f_xaxpy(int n, double a, const emxArray_real_T *x, emxArray_real_T *y,
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
 * Arguments    : double a
 *                const double x[3]
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void g_xaxpy(double a, const double x[3], double y[9], int iy0)
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
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
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
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
