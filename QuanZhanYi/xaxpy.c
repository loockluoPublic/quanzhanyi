/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
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
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, int ix0, double y[9], int iy0)
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
 *                const double x[9]
 *                int ix0
 *                double y[3]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[9], int ix0, double y[3], int iy0)
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
 *                const double x[3]
 *                int ix0
 *                double y[9]
 *                int iy0
 * Return Type  : void
 */
void d_xaxpy(int n, double a, const double x[3], int ix0, double y[9], int iy0)
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
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void e_xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  int i;
  int i1;
  int k;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y->data[i1] += a * y->data[(ix0 + k) - 1];
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
void f_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0)
{
  int i;
  int i1;
  int k;
  if ((n >= 1) && (!(a == 0.0))) {
    i = n - 1;
    for (k = 0; k <= i; k++) {
      i1 = (iy0 + k) - 1;
      y->data[i1] += a * x->data[(ix0 + k) - 1];
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
void xaxpy(int n, double a, int ix0, double y[16], int iy0)
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
