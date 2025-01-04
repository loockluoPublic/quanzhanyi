/*
 * File: dot.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

/* Include Files */
#include "dot.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double a[3]
 *                const double b[3]
 * Return Type  : double
 */
double dot(const double a[3], const double b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

/*
 * File trailer for dot.c
 *
 * [EOF]
 */
