/*
 * File: nchoosek.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 22:01:39
 */

/* Include Files */
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * Arguments    : double n
 *                double k
 * Return Type  : double
 */
double nCk(double n, double k)
{
  double nmk;
  double y;
  int i;
  int j;
  if (!rtIsNaN(n)) {
    if (3.0 > n / 2.0) {
      k = n - 3.0;
    }
    if (k > 1000.0) {
      y = rtInf;
    } else {
      y = 1.0;
      nmk = n - k;
      i = (int)k;
      for (j = 0; j < i; j++) {
        y *= (((double)j + 1.0) + nmk) / ((double)j + 1.0);
      }
      y = rt_roundd_snf(y);
    }
  } else {
    y = rtNaN;
  }
  return y;
}

/*
 * File trailer for nchoosek.c
 *
 * [EOF]
 */
