/*
 * File: angle2point.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

/* Include Files */
#include "angle2point.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
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
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  *x = Mradial * cos(ANG);
  *y = Mradial * sin(ANG);
  *z = -((d + a * *x) + b * *y) / c;
}

/*
 * File trailer for angle2point.c
 *
 * [EOF]
 */
