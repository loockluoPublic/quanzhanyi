/*
 * File: pinv.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Sep-2024 15:15:59
 */

/* Include Files */
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[9]
 *                double X[9]
 * Return Type  : void
 */
void pinv(const double A[9], double X[9])
{
  double U[9];
  double V[9];
  double s[3];
  double absx;
  int ar;
  int br;
  int i;
  int i1;
  int ib;
  int ic;
  int j;
  int r;
  int vcol;
  boolean_T p;
  p = true;
  for (br = 0; br < 9; br++) {
    X[br] = 0.0;
    if (p) {
      absx = A[br];
      if (rtIsInf(absx) || rtIsNaN(absx)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    for (i = 0; i < 9; i++) {
      X[i] = rtNaN;
    }
  } else {
    svd(A, U, s, V);
    absx = fabs(s[0]);
    if (rtIsInf(absx) || rtIsNaN(absx)) {
      absx = rtNaN;
    } else if (absx < 4.4501477170144028E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &vcol);
      absx = ldexp(1.0, vcol - 53);
    }
    absx *= 3.0;
    r = -1;
    br = 0;
    while ((br < 3) && (s[br] > absx)) {
      r++;
      br++;
    }
    if (r + 1 > 0) {
      vcol = 1;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / s[j];
        i = vcol + 2;
        for (br = vcol; br <= i; br++) {
          V[br - 1] *= absx;
        }
        vcol += 3;
      }
      for (vcol = 0; vcol <= 6; vcol += 3) {
        i = vcol + 1;
        j = vcol + 3;
        if (i <= j) {
          memset(&X[i + -1], 0, (unsigned int)((j - i) + 1) * sizeof(double));
        }
      }
      br = 0;
      for (vcol = 0; vcol <= 6; vcol += 3) {
        ar = -1;
        br++;
        i = br + 3 * r;
        for (ib = br; ib <= i; ib += 3) {
          j = vcol + 1;
          i1 = vcol + 3;
          for (ic = j; ic <= i1; ic++) {
            X[ic - 1] += U[ib - 1] * V[(ar + ic) - vcol];
          }
          ar += 3;
        }
      }
    }
  }
}

/*
 * File trailer for pinv.c
 *
 * [EOF]
 */
