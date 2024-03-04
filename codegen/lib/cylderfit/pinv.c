/*
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
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
 * Arguments    : const double A[49]
 *                double X[49]
 * Return Type  : void
 */
void pinv(const double A[49], double X[49])
{
  double U[49];
  double V[49];
  double s[7];
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
  for (br = 0; br < 49; br++) {
    X[br] = 0.0;
    if ((!p) || (rtIsInf(A[br]) || rtIsNaN(A[br]))) {
      p = false;
    }
  }
  if (!p) {
    for (i = 0; i < 49; i++) {
      X[i] = rtNaN;
    }
  } else {
    b_svd(A, U, s, V);
    absx = fabs(s[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = ldexp(1.0, vcol - 53);
      }
    } else {
      absx = rtNaN;
    }
    absx *= 7.0;
    r = -1;
    br = 0;
    while ((br < 7) && (s[br] > absx)) {
      r++;
      br++;
    }
    if (r + 1 > 0) {
      vcol = 1;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / s[j];
        i = vcol + 6;
        for (br = vcol; br <= i; br++) {
          V[br - 1] *= absx;
        }
        vcol += 7;
      }
      for (vcol = 0; vcol <= 42; vcol += 7) {
        i = vcol + 1;
        j = vcol + 7;
        if (i <= j) {
          memset(&X[i + -1], 0, ((j - i) + 1) * sizeof(double));
        }
      }
      br = 0;
      for (vcol = 0; vcol <= 42; vcol += 7) {
        ar = -1;
        br++;
        i = br + 7 * r;
        for (ib = br; ib <= i; ib += 7) {
          j = vcol + 1;
          i1 = vcol + 7;
          for (ic = j; ic <= i1; ic++) {
            X[ic - 1] += U[ib - 1] * V[(ar + ic) - vcol];
          }
          ar += 7;
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
