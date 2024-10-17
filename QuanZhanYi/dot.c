/*
 * File: dot.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 17-Oct-2024 11:31:37
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
