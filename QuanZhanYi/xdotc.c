/*
 * File: xdotc.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Sep-2024 22:03:53
 */

/* Include Files */
#include "xdotc.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                const double x[16]
 *                int ix0
 *                const double y[16]
 *                int iy0
 * Return Type  : double
 */
double b_xdotc(int n, const double x[16], int ix0, const double y[16], int iy0)
{
  double d;
  int i;
  int k;
  d = 0.0;
  i = (unsigned char)n;
  for (k = 0; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/*
 * Arguments    : int n
 *                const double x[8]
 *                int ix0
 *                const double y[8]
 *                int iy0
 * Return Type  : double
 */
double c_xdotc(int n, const double x[8], int ix0, const double y[8], int iy0)
{
  double d;
  int i;
  int k;
  d = 0.0;
  i = (unsigned char)n;
  for (k = 0; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/*
 * Arguments    : const double x[4]
 *                const double y[4]
 * Return Type  : double
 */
double d_xdotc(const double x[4], const double y[4])
{
  return x[0] * y[2] + x[1] * y[3];
}

/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 *                const double y[9]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[9], int ix0, const double y[9], int iy0)
{
  double d;
  int i;
  int k;
  d = 0.0;
  i = (unsigned char)n;
  for (k = 0; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
