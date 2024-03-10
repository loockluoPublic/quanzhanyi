/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "xswap.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x[49]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[49], int ix0, int iy0)
{
  double temp;
  int i;
  int k;
  int temp_tmp;
  for (k = 0; k < 7; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    i = (iy0 + k) - 1;
    x[temp_tmp] = x[i];
    x[i] = temp;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
