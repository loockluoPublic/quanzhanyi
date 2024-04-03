/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "xswap.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x[9]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void b_xswap(double x[9], int ix0, int iy0)
{
  double temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

/*
 * Arguments    : double x[16]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[16], int ix0, int iy0)
{
  double temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
  temp = x[ix0 + 2];
  x[ix0 + 2] = x[iy0 + 2];
  x[iy0 + 2] = temp;
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
