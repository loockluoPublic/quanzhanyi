/*
 * File: rigid3dImpl.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "rigid3dImpl.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double T[16]
 * Return Type  : boolean_T
 */
boolean_T c_rigid3dImpl_isTransformationM(const double T[16])
{
  double b_T[9];
  double rot[9];
  double singularValues[3];
  double absx;
  double s;
  int b_tmp;
  int exponent;
  int i;
  int j;
  int jA;
  int jp1j;
  int k;
  int mmj_tmp;
  signed char ipiv[3];
  boolean_T isRigid;
  boolean_T isodd;
  for (i = 0; i < 3; i++) {
    jA = i << 2;
    rot[3 * i] = T[jA];
    rot[3 * i + 1] = T[jA + 1];
    rot[3 * i + 2] = T[jA + 2];
  }
  isodd = true;
  for (k = 0; k < 9; k++) {
    if (isodd) {
      absx = T[k % 3 + ((k / 3) << 2)];
      if (rtIsInf(absx) || rtIsNaN(absx)) {
        isodd = false;
      }
    } else {
      isodd = false;
    }
  }
  if (isodd) {
    for (i = 0; i < 3; i++) {
      jA = i << 2;
      b_T[3 * i] = T[jA];
      b_T[3 * i + 1] = T[jA + 1];
      b_T[3 * i + 2] = T[jA + 2];
    }
    svd(b_T, singularValues);
  } else {
    singularValues[0] = rtNaN;
    singularValues[1] = rtNaN;
    singularValues[2] = rtNaN;
  }
  s = maximum(singularValues);
  absx = fabs(s);
  if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }
  } else {
    absx = rtNaN;
  }
  if (s - minimum(singularValues) < 1000.0 * absx) {
    ipiv[0] = 1;
    ipiv[1] = 2;
    for (j = 0; j < 2; j++) {
      mmj_tmp = 1 - j;
      b_tmp = j << 2;
      jp1j = b_tmp + 2;
      jA = 3 - j;
      exponent = 0;
      absx = fabs(rot[b_tmp]);
      for (k = 2; k <= jA; k++) {
        s = fabs(rot[(b_tmp + k) - 1]);
        if (s > absx) {
          exponent = k - 1;
          absx = s;
        }
      }
      if (rot[b_tmp + exponent] != 0.0) {
        if (exponent != 0) {
          jA = j + exponent;
          ipiv[j] = (signed char)(jA + 1);
          absx = rot[j];
          rot[j] = rot[jA];
          rot[jA] = absx;
          absx = rot[j + 3];
          rot[j + 3] = rot[jA + 3];
          rot[jA + 3] = absx;
          absx = rot[j + 6];
          rot[j + 6] = rot[jA + 6];
          rot[jA + 6] = absx;
        }
        i = (b_tmp - j) + 3;
        for (jA = jp1j; jA <= i; jA++) {
          rot[jA - 1] /= rot[b_tmp];
        }
      }
      jA = b_tmp;
      for (exponent = 0; exponent <= mmj_tmp; exponent++) {
        absx = rot[(b_tmp + exponent * 3) + 3];
        if (absx != 0.0) {
          i = jA + 5;
          k = (jA - j) + 6;
          for (jp1j = i; jp1j <= k; jp1j++) {
            rot[jp1j - 1] += rot[((b_tmp + jp1j) - jA) - 4] * -absx;
          }
        }
        jA += 3;
      }
    }
    isodd = (ipiv[0] > 1);
    absx = rot[0] * rot[4] * rot[8];
    if (ipiv[1] > 2) {
      isodd = !isodd;
    }
    if (isodd) {
      absx = -absx;
    }
    if (fabs(absx - 1.0) < 2.2204460492503131E-13) {
      isRigid = true;
    } else {
      isRigid = false;
    }
  } else {
    isRigid = false;
  }
  return isRigid;
}

/*
 * File trailer for rigid3dImpl.c
 *
 * [EOF]
 */
