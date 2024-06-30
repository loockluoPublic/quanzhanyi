/*
 * File: angle2point.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 13:50:22
 */

/* Include Files */
#include "angle2point.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double ANG
 *                double a
 *                double b
 *                double c
 *                double d
 *                double Mradial
 *                double *x
 *                double *y
 *                double *z
 * Return Type  : void
 */
void angle2point(double ANG, double a, double b, double c, double d,
                 double Mradial, double *x, double *y, double *z)
{
  *x = Mradial * cos(ANG);
  *y = Mradial * sin(ANG);
  *z = -((d + a * *x) + b * *y) / c;
}

/*
 * File trailer for angle2point.c
 *
 * [EOF]
 */
