/*
 * File: pinv.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 17-May-2024 11:16:59
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
  int br;
  int i;
  int ib;
  int ic;
  int j;
  int vcol;
  boolean_T p;
  p = true;
  for (br = 0; br < 9; br++) {
    X[br] = 0.0;
    if ((!p) || (rtIsInf(A[br]) || rtIsNaN(A[br]))) {
      p = false;
    }
  }
  if (!p) {
    for (i = 0; i < 9; i++) {
      X[i] = rtNaN;
    }
  } else {
    double U[9];
    double V[9];
    double s[3];
    double absx;
    int r;
    svd(A, U, s, V);
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
          memset(&X[i + -1], 0, ((j - i) + 1) * sizeof(double));
        }
      }
      br = 0;
      for (vcol = 0; vcol <= 6; vcol += 3) {
        int ar;
        ar = -1;
        br++;
        i = br + 3 * r;
        for (ib = br; ib <= i; ib += 3) {
          int i1;
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
