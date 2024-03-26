/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 20:09:07
 */

/* Include Files */
#include "xaxpy.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                double a
 *                const double x[49]
 *                int ix0
 *                double y[7]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[49], int ix0, double y[7], int iy0)
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
void c_xaxpy(int n, double a, const double x[7], int ix0, double y[49], int iy0)
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
 *                double y[49]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[49], int iy0)
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
