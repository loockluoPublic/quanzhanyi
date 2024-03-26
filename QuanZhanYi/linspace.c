/*
 * File: linspace.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 15:14:21
 */

/* Include Files */
#include "linspace.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double d1
 *                double d2
 *                double y[60]
 * Return Type  : void
 */
void linspace(double d1, double d2, double y[60])
{
  double delta1;
  double delta2;
  int k;
  y[59] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    delta1 = d2 / 59.0;
    for (k = 0; k < 58; k++) {
      y[k + 1] = (2.0 * ((double)k + 2.0) - 61.0) * delta1;
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) &&
             ((fabs(d1) > 8.9884656743115785E+307) ||
              (fabs(d2) > 8.9884656743115785E+307))) {
    delta1 = d1 / 59.0;
    delta2 = d2 / 59.0;
    for (k = 0; k < 58; k++) {
      y[k + 1] = (d1 + delta2 * ((double)k + 1.0)) - delta1 * ((double)k + 1.0);
    }
  } else {
    delta1 = (d2 - d1) / 59.0;
    for (k = 0; k < 58; k++) {
      y[k + 1] = d1 + ((double)k + 1.0) * delta1;
    }
  }
}

/*
 * File trailer for linspace.c
 *
 * [EOF]
 */
