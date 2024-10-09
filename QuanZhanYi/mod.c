/*
 * File: mod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 09-Oct-2024 11:13:17
 */

/* Include Files */
#include "mod.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_mod(double x)
{
  double r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    }
  }
  return r;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
