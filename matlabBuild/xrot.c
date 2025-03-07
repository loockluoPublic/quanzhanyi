/*
 * File: xrot.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Mar-2025 21:42:51
 */

/* Include Files */
#include "xrot.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x[16]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void b_xrot(double x[16], int ix0, int iy0, double c, double s)
{
  double temp;
  double temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = c * temp - s * temp_tmp;
  x[ix0 - 1] = c * temp_tmp + s * temp;
  temp = c * x[ix0] + s * x[iy0];
  x[iy0] = c * x[iy0] - s * x[ix0];
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = c * temp - s * temp_tmp;
  x[ix0 + 1] = c * temp_tmp + s * temp;
  temp = x[iy0 + 2];
  temp_tmp = x[ix0 + 2];
  x[iy0 + 2] = c * temp - s * temp_tmp;
  x[ix0 + 2] = c * temp_tmp + s * temp;
}

/*
 * Arguments    : double x[4]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void c_xrot(double x[4], int ix0, int iy0, double c, double s)
{
  double temp;
  double temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = c * temp - s * temp_tmp;
  x[ix0 - 1] = c * temp_tmp + s * temp;
  temp = c * x[ix0] + s * x[iy0];
  x[iy0] = c * x[iy0] - s * x[ix0];
  x[ix0] = temp;
}

/*
 * Arguments    : double x[9]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(double x[9], int ix0, int iy0, double c, double s)
{
  double temp;
  double temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = c * temp - s * temp_tmp;
  x[ix0 - 1] = c * temp_tmp + s * temp;
  temp = c * x[ix0] + s * x[iy0];
  x[iy0] = c * x[iy0] - s * x[ix0];
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = c * temp - s * temp_tmp;
  x[ix0 + 1] = c * temp_tmp + s * temp;
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
