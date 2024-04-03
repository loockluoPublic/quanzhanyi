/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double A[3]
 *                double B
 *                double Y[3]
 * Return Type  : void
 */
void mldivide(const double A[3], double B, double Y[3])
{
  double b_A[3];
  double vn1_idx_0;
  double vn1_idx_1;
  int j;
  int pvt;
  signed char jpvt[3];
  b_A[0] = A[0];
  jpvt[0] = 1;
  vn1_idx_0 = fabs(A[0]);
  b_A[1] = A[1];
  jpvt[1] = 2;
  vn1_idx_1 = fabs(A[1]);
  b_A[2] = A[2];
  jpvt[2] = 3;
  pvt = 0;
  if (vn1_idx_1 > vn1_idx_0) {
    pvt = 1;
    vn1_idx_0 = vn1_idx_1;
  }
  if (fabs(A[2]) > vn1_idx_0) {
    pvt = 2;
  }
  if (pvt + 1 != 1) {
    b_A[0] = b_A[pvt];
    jpvt[0] = jpvt[pvt];
  }
  pvt = 0;
  vn1_idx_0 = fabs(b_A[0]);
  if (!(vn1_idx_0 <= 6.6613381477509392E-15 * vn1_idx_0)) {
    pvt = 1;
  }
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  if (0 <= pvt - 1) {
    Y[jpvt[0] - 1] = B;
  }
  for (j = pvt; j >= 1; j--) {
    Y[jpvt[0] - 1] /= b_A[0];
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
