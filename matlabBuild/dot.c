/*
 * File: dot.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Feb-2025 18:54:26
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
