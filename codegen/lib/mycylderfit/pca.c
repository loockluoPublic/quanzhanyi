/*
 * File: pca.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

/* Include Files */
#include "pca.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void localTSquared(const emxArray_real_T *score,
                          const double latent_data[], int latent_size, int DOF,
                          emxArray_real_T *tsquared);

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *score
 *                const double latent_data[]
 *                int latent_size
 *                int DOF
 *                emxArray_real_T *tsquared
 * Return Type  : void
 */
static void localTSquared(const emxArray_real_T *score,
                          const double latent_data[], int latent_size, int DOF,
                          emxArray_real_T *tsquared)
{
  double absx;
  double d;
  int exponent;
  int i;
  int m;
  int q;
  if ((score->size[0] == 0) || (score->size[1] == 0)) {
    i = tsquared->size[0] * tsquared->size[1];
    tsquared->size[0] = score->size[0];
    tsquared->size[1] = score->size[1];
    emxEnsureCapacity_real_T(tsquared, i);
    exponent = score->size[0] * score->size[1];
    for (i = 0; i < exponent; i++) {
      tsquared->data[i] = score->data[i];
    }
  } else {
    if (DOF > 1) {
      absx = fabs(latent_data[0]);
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
      if (DOF > 3) {
        exponent = DOF;
      } else {
        exponent = 3;
      }
      absx *= (double)exponent;
      q = 0;
      for (exponent = 0; exponent < latent_size; exponent++) {
        if (latent_data[exponent] > absx) {
          q++;
        }
      }
    } else {
      q = 0;
    }
    m = score->size[0];
    i = tsquared->size[0] * tsquared->size[1];
    tsquared->size[0] = score->size[0];
    tsquared->size[1] = 1;
    emxEnsureCapacity_real_T(tsquared, i);
    exponent = score->size[0];
    for (i = 0; i < exponent; i++) {
      tsquared->data[i] = 0.0;
    }
    for (exponent = 0; exponent < q; exponent++) {
      absx = sqrt(latent_data[exponent]);
      for (i = 0; i < m; i++) {
        d = score->data[i + score->size[0] * exponent] / absx;
        tsquared->data[i] += d * d;
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                emxArray_real_T *varargout_2
 *                double varargout_3_data[]
 *                int *varargout_3_size
 *                emxArray_real_T *varargout_4
 *                double varargout_5_data[]
 *                int *varargout_5_size
 *                double varargout_6_data[]
 *                int varargout_6_size[2]
 * Return Type  : void
 */
void pca(const emxArray_real_T *x, double varargout_1_data[],
         int varargout_1_size[2], emxArray_real_T *varargout_2,
         double varargout_3_data[], int *varargout_3_size,
         emxArray_real_T *varargout_4, double varargout_5_data[],
         int *varargout_5_size, double varargout_6_data[],
         int varargout_6_size[2])
{
  emxArray_boolean_T *naninfo_isNaN;
  emxArray_int32_T *naninfo_nNaNsInRow;
  emxArray_real_T *b_score;
  emxArray_real_T *b_x;
  emxArray_real_T *score;
  emxArray_real_T *tsquared;
  emxArray_real_T *xNoNaNs;
  double b_coeff_data[9];
  double coeff_data[9];
  double latent_data[3];
  double absc;
  double d;
  double d1;
  double wcol;
  double xcol;
  int coeff_size[2];
  int DOF;
  int b_n;
  int i;
  int j;
  int loop_ub;
  int n;
  int nrows;
  int nsv;
  int p;
  boolean_T noNaNs;
  emxInit_real_T(&b_x, 2);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = 3;
  emxEnsureCapacity_real_T(b_x, i);
  loop_ub = x->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = x->data[i];
  }
  emxInit_int32_T(&naninfo_nNaNsInRow, 1);
  n = x->size[0];
  b_n = x->size[0] - 1;
  nrows = 0;
  p = 0;
  i = naninfo_nNaNsInRow->size[0];
  naninfo_nNaNsInRow->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(naninfo_nNaNsInRow, i);
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    naninfo_nNaNsInRow->data[i] = 0;
  }
  emxInit_boolean_T(&naninfo_isNaN, 2);
  i = naninfo_isNaN->size[0] * naninfo_isNaN->size[1];
  naninfo_isNaN->size[0] = x->size[0];
  naninfo_isNaN->size[1] = 3;
  emxEnsureCapacity_boolean_T(naninfo_isNaN, i);
  loop_ub = x->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    naninfo_isNaN->data[i] = rtIsNaN(x->data[i]);
  }
  for (j = 0; j < 3; j++) {
    for (loop_ub = 0; loop_ub <= b_n; loop_ub++) {
      if (naninfo_isNaN->data[loop_ub + naninfo_isNaN->size[0] * j]) {
        naninfo_nNaNsInRow->data[loop_ub]++;
        nrows++;
      }
    }
  }
  emxFree_boolean_T(&naninfo_isNaN);
  for (loop_ub = 0; loop_ub <= b_n; loop_ub++) {
    if (naninfo_nNaNsInRow->data[loop_ub] > 0) {
      p++;
    }
  }
  noNaNs = (nrows <= 0);
  DOF = x->size[0] - p;
  if (DOF >= 1) {
    DOF--;
  }
  b_n = x->size[0] - 1;
  if (!noNaNs) {
    varargout_6_size[0] = 1;
    varargout_6_size[1] = 3;
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (loop_ub = 0; loop_ub <= b_n; loop_ub++) {
        d = x->data[loop_ub + x->size[0] * j];
        if (!rtIsNaN(d)) {
          wcol++;
          xcol += d;
        }
      }
      varargout_6_data[j] = xcol / wcol;
    }
  } else {
    varargout_6_size[0] = 1;
    varargout_6_size[1] = 3;
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (loop_ub = 0; loop_ub <= b_n; loop_ub++) {
        wcol++;
        xcol += x->data[loop_ub + x->size[0] * j];
      }
      varargout_6_data[j] = xcol / wcol;
    }
  }
  for (j = 0; j < 3; j++) {
    for (loop_ub = 0; loop_ub < n; loop_ub++) {
      b_x->data[loop_ub + b_x->size[0] * j] -= varargout_6_data[j];
    }
  }
  emxInit_real_T(&xNoNaNs, 2);
  emxInit_real_T(&score, 2);
  emxInit_real_T(&b_score, 2);
  if (noNaNs) {
    i = xNoNaNs->size[0] * xNoNaNs->size[1];
    xNoNaNs->size[0] = b_x->size[0];
    xNoNaNs->size[1] = 3;
    emxEnsureCapacity_real_T(xNoNaNs, i);
    loop_ub = b_x->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      xNoNaNs->data[i] = b_x->data[i];
    }
    nrows = b_x->size[0] - 1;
    xzsvdc(xNoNaNs, score, latent_data, &b_n, coeff_data, coeff_size);
    nsv = score->size[1];
    for (j = 0; j < nsv; j++) {
      for (loop_ub = 0; loop_ub <= nrows; loop_ub++) {
        score->data[loop_ub + score->size[0] * j] *= latent_data[j];
      }
      d = latent_data[j];
      d = d * d / (double)DOF;
      latent_data[j] = d;
    }
    localTSquared(score, latent_data, b_n, DOF, varargout_4);
    if (DOF < 3) {
      if (DOF < nsv) {
        nsv = DOF;
      }
      i = b_score->size[0] * b_score->size[1];
      b_score->size[0] = b_x->size[0];
      b_score->size[1] = nsv;
      emxEnsureCapacity_real_T(b_score, i);
      *varargout_3_size = nsv;
      for (j = 0; j < nsv; j++) {
        for (loop_ub = 0; loop_ub <= nrows; loop_ub++) {
          b_score->data[loop_ub + b_score->size[0] * j] =
              score->data[loop_ub + score->size[0] * j];
        }
        varargout_3_data[j] = latent_data[j];
        b_coeff_data[3 * j] = coeff_data[3 * j];
        b_n = 3 * j + 1;
        b_coeff_data[b_n] = coeff_data[b_n];
        b_n = 3 * j + 2;
        b_coeff_data[b_n] = coeff_data[b_n];
      }
    } else {
      i = b_score->size[0] * b_score->size[1];
      b_score->size[0] = score->size[0];
      b_score->size[1] = score->size[1];
      emxEnsureCapacity_real_T(b_score, i);
      loop_ub = score->size[0] * score->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_score->data[i] = score->data[i];
      }
      *varargout_3_size = b_n;
      if (0 <= b_n - 1) {
        memcpy(&varargout_3_data[0], &latent_data[0], b_n * sizeof(double));
      }
      nsv = coeff_size[1];
      loop_ub = 3 * coeff_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&b_coeff_data[0], &coeff_data[0], loop_ub * sizeof(double));
      }
    }
    if (*varargout_3_size == 0) {
      wcol = 0.0;
    } else {
      wcol = varargout_3_data[0];
      for (b_n = 2; b_n <= *varargout_3_size; b_n++) {
        wcol += varargout_3_data[b_n - 1];
      }
    }
    *varargout_5_size = *varargout_3_size;
    for (i = 0; i < *varargout_3_size; i++) {
      varargout_5_data[i] = 100.0 * varargout_3_data[i] / wcol;
    }
  } else {
    n = b_x->size[0];
    i = xNoNaNs->size[0] * xNoNaNs->size[1];
    xNoNaNs->size[0] = b_x->size[0] - p;
    xNoNaNs->size[1] = 3;
    emxEnsureCapacity_real_T(xNoNaNs, i);
    b_n = -1;
    for (loop_ub = 0; loop_ub < n; loop_ub++) {
      if (naninfo_nNaNsInRow->data[loop_ub] == 0) {
        b_n++;
        xNoNaNs->data[b_n] = b_x->data[loop_ub];
        xNoNaNs->data[b_n + xNoNaNs->size[0]] =
            b_x->data[loop_ub + b_x->size[0]];
        xNoNaNs->data[b_n + xNoNaNs->size[0] * 2] =
            b_x->data[loop_ub + b_x->size[0] * 2];
      }
    }
    nrows = xNoNaNs->size[0];
    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = xNoNaNs->size[0];
    b_x->size[1] = 3;
    emxEnsureCapacity_real_T(b_x, i);
    loop_ub = xNoNaNs->size[0] * xNoNaNs->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_x->data[i] = xNoNaNs->data[i];
    }
    xzsvdc(b_x, b_score, latent_data, &b_n, coeff_data, coeff_size);
    nsv = b_score->size[1];
    for (j = 0; j < nsv; j++) {
      for (loop_ub = 0; loop_ub < nrows; loop_ub++) {
        b_score->data[loop_ub + b_score->size[0] * j] *= latent_data[j];
      }
      d = latent_data[j];
      d = d * d / (double)DOF;
      latent_data[j] = d;
    }
    emxInit_real_T(&tsquared, 2);
    localTSquared(b_score, latent_data, b_n, DOF, tsquared);
    if (DOF < 3) {
      if (DOF < nsv) {
        nsv = DOF;
      }
      i = score->size[0] * score->size[1];
      score->size[0] = xNoNaNs->size[0];
      score->size[1] = nsv;
      emxEnsureCapacity_real_T(score, i);
      *varargout_3_size = nsv;
      for (j = 0; j < nsv; j++) {
        for (loop_ub = 0; loop_ub < nrows; loop_ub++) {
          score->data[loop_ub + score->size[0] * j] =
              b_score->data[loop_ub + b_score->size[0] * j];
        }
        varargout_3_data[j] = latent_data[j];
        b_coeff_data[3 * j] = coeff_data[3 * j];
        b_n = 3 * j + 1;
        b_coeff_data[b_n] = coeff_data[b_n];
        b_n = 3 * j + 2;
        b_coeff_data[b_n] = coeff_data[b_n];
      }
    } else {
      i = score->size[0] * score->size[1];
      score->size[0] = b_score->size[0];
      score->size[1] = b_score->size[1];
      emxEnsureCapacity_real_T(score, i);
      loop_ub = b_score->size[0] * b_score->size[1];
      for (i = 0; i < loop_ub; i++) {
        score->data[i] = b_score->data[i];
      }
      *varargout_3_size = b_n;
      if (0 <= b_n - 1) {
        memcpy(&varargout_3_data[0], &latent_data[0], b_n * sizeof(double));
      }
      nsv = coeff_size[1];
      loop_ub = 3 * coeff_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&b_coeff_data[0], &coeff_data[0], loop_ub * sizeof(double));
      }
    }
    if (*varargout_3_size == 0) {
      wcol = 0.0;
    } else {
      wcol = varargout_3_data[0];
      for (b_n = 2; b_n <= *varargout_3_size; b_n++) {
        wcol += varargout_3_data[b_n - 1];
      }
    }
    *varargout_5_size = *varargout_3_size;
    for (i = 0; i < *varargout_3_size; i++) {
      varargout_5_data[i] = 100.0 * varargout_3_data[i] / wcol;
    }
    n = naninfo_nNaNsInRow->size[0];
    p = score->size[1] - 1;
    i = b_score->size[0] * b_score->size[1];
    b_score->size[0] = naninfo_nNaNsInRow->size[0];
    b_score->size[1] = score->size[1];
    emxEnsureCapacity_real_T(b_score, i);
    b_n = -1;
    for (loop_ub = 0; loop_ub < n; loop_ub++) {
      if (naninfo_nNaNsInRow->data[loop_ub] > 0) {
        for (j = 0; j <= p; j++) {
          b_score->data[loop_ub + b_score->size[0] * j] = rtNaN;
        }
      } else {
        b_n++;
        for (j = 0; j <= p; j++) {
          b_score->data[loop_ub + b_score->size[0] * j] =
              score->data[b_n + score->size[0] * j];
        }
      }
    }
    n = naninfo_nNaNsInRow->size[0];
    p = tsquared->size[1] - 1;
    i = varargout_4->size[0] * varargout_4->size[1];
    varargout_4->size[0] = naninfo_nNaNsInRow->size[0];
    varargout_4->size[1] = tsquared->size[1];
    emxEnsureCapacity_real_T(varargout_4, i);
    b_n = -1;
    for (loop_ub = 0; loop_ub < n; loop_ub++) {
      if (naninfo_nNaNsInRow->data[loop_ub] > 0) {
        for (j = 0; j <= p; j++) {
          varargout_4->data[loop_ub + varargout_4->size[0] * j] = rtNaN;
        }
      } else {
        b_n++;
        for (j = 0; j <= p; j++) {
          varargout_4->data[loop_ub + varargout_4->size[0] * j] =
              tsquared->data[b_n + tsquared->size[0] * j];
        }
      }
    }
    emxFree_real_T(&tsquared);
  }
  emxFree_real_T(&score);
  emxFree_real_T(&xNoNaNs);
  emxFree_int32_T(&naninfo_nNaNsInRow);
  emxFree_real_T(&b_x);
  p = b_score->size[0] - 1;
  if (3 < DOF) {
    varargout_1_size[0] = 3;
    varargout_1_size[1] = 3;
    for (j = 0; j < 3; j++) {
      varargout_1_data[3 * j] = b_coeff_data[3 * j];
      i = 3 * j + 1;
      varargout_1_data[i] = b_coeff_data[i];
      i = 3 * j + 2;
      varargout_1_data[i] = b_coeff_data[i];
    }
    i = varargout_2->size[0] * varargout_2->size[1];
    varargout_2->size[0] = b_score->size[0];
    varargout_2->size[1] = 3;
    emxEnsureCapacity_real_T(varargout_2, i);
    for (j = 0; j < 3; j++) {
      for (loop_ub = 0; loop_ub <= p; loop_ub++) {
        varargout_2->data[loop_ub + varargout_2->size[0] * j] =
            b_score->data[loop_ub + b_score->size[0] * j];
      }
    }
  } else {
    varargout_1_size[0] = 3;
    varargout_1_size[1] = nsv;
    loop_ub = 3 * nsv;
    if (0 <= loop_ub - 1) {
      memcpy(&varargout_1_data[0], &b_coeff_data[0], loop_ub * sizeof(double));
    }
    i = varargout_2->size[0] * varargout_2->size[1];
    varargout_2->size[0] = b_score->size[0];
    varargout_2->size[1] = b_score->size[1];
    emxEnsureCapacity_real_T(varargout_2, i);
    loop_ub = b_score->size[0] * b_score->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargout_2->data[i] = b_score->data[i];
    }
  }
  emxFree_real_T(&b_score);
  nrows = varargout_1_size[1];
  for (j = 0; j < nrows; j++) {
    wcol = 0.0;
    xcol = 1.0;
    d = varargout_1_data[3 * j];
    absc = fabs(d);
    if (absc > 0.0) {
      wcol = absc;
      xcol = d;
      if (d < 0.0) {
        xcol = -1.0;
      } else if (d > 0.0) {
        xcol = 1.0;
      } else if (d == 0.0) {
        xcol = 0.0;
      }
    }
    i = 3 * j + 1;
    d1 = varargout_1_data[i];
    absc = fabs(d1);
    if (absc > wcol) {
      wcol = absc;
      xcol = d1;
      if (d1 < 0.0) {
        xcol = -1.0;
      } else if (d1 > 0.0) {
        xcol = 1.0;
      } else if (d1 == 0.0) {
        xcol = 0.0;
      }
    }
    b_n = 3 * j + 2;
    d1 = varargout_1_data[b_n];
    if (fabs(d1) > wcol) {
      xcol = d1;
      if (d1 < 0.0) {
        xcol = -1.0;
      } else if (d1 > 0.0) {
        xcol = 1.0;
      } else if (d1 == 0.0) {
        xcol = 0.0;
      }
    }
    if (xcol < 0.0) {
      varargout_1_data[3 * j] = -d;
      varargout_1_data[i] = -varargout_1_data[i];
      varargout_1_data[b_n] = -varargout_1_data[b_n];
      for (loop_ub = 0; loop_ub <= p; loop_ub++) {
        varargout_2->data[loop_ub + varargout_2->size[0] * j] =
            -varargout_2->data[loop_ub + varargout_2->size[0] * j];
      }
    }
  }
}

/*
 * File trailer for pca.c
 *
 * [EOF]
 */
