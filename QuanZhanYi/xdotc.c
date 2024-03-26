/*
 * File: xdotc.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 20:09:07
 */

/* Include Files */
#include "xdotc.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                const double x[49]
 *                int ix0
 *                const double y[49]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[49], int ix0, const double y[49], int iy0)
{
  double d;
  int k;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
