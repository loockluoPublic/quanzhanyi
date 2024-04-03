/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 22:27:47
 */

/* Include Files */
#include "mldivide.h"
#include "QuanZhanYi_types.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double Y[3]
 * Return Type  : void
 */
void mldivide(const emxArray_real_T *A, const emxArray_real_T *B, double Y[3])
{
  double A_data[9];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  int rtemp;
  if ((A->size[0] == 0) || (B->size[0] == 0)) {
    Y[0] = 0.0;
    Y[1] = 0.0;
    Y[2] = 0.0;
  } else if (A->size[0] == 3) {
    for (r1 = 0; r1 < 9; r1++) {
      A_data[r1] = A->data[r1];
    }
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = fabs(A->data[0]);
    a21 = fabs(A->data[1]);
    if (a21 > maxval) {
      maxval = a21;
      r1 = 1;
      r2 = 0;
    }
    if (fabs(A->data[2]) > maxval) {
      r1 = 2;
      r2 = 1;
      r3 = 0;
    }
    A_data[r2] = A->data[r2] / A->data[r1];
    A_data[r3] /= A_data[r1];
    A_data[r2 + 3] -= A_data[r2] * A_data[r1 + 3];
    A_data[r3 + 3] -= A_data[r3] * A_data[r1 + 3];
    A_data[r2 + 6] -= A_data[r2] * A_data[r1 + 6];
    A_data[r3 + 6] -= A_data[r3] * A_data[r1 + 6];
    if (fabs(A_data[r3 + 3]) > fabs(A_data[r2 + 3])) {
      rtemp = r2;
      r2 = r3;
      r3 = rtemp;
    }
    A_data[r3 + 3] /= A_data[r2 + 3];
    A_data[r3 + 6] -= A_data[r3 + 3] * A_data[r2 + 6];
    Y[1] = B->data[r2] - B->data[r1] * A_data[r2];
    Y[2] = (B->data[r3] - B->data[r1] * A_data[r3]) - Y[1] * A_data[r3 + 3];
    Y[2] /= A_data[r3 + 6];
    Y[0] = B->data[r1] - Y[2] * A_data[r1 + 6];
    Y[1] -= Y[2] * A_data[r2 + 6];
    Y[1] /= A_data[r2 + 3];
    Y[0] -= Y[1] * A_data[r1 + 3];
    Y[0] /= A_data[r1];
  } else {
    qrsolve(A, B, Y);
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
