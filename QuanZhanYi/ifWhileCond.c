/*
 * File: ifWhileCond.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:09:52
 */

/* Include Files */
#include "ifWhileCond.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[3]
 * Return Type  : boolean_T
 */
boolean_T ifWhileCond(const boolean_T x[3])
{
  int k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return y;
}

/*
 * File trailer for ifWhileCond.c
 *
 * [EOF]
 */
