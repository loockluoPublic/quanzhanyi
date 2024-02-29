/*
 * File: pcfitcylinder.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "pcfitcylinder.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double modelParams_data[]
 *                const b_pointCloud *ptCloud
 *                const emxArray_real_T *inlierIndices
 * Return Type  : void
 */
void convertToFiniteCylinderModel(double modelParams_data[],
                                  const b_pointCloud *ptCloud,
                                  const emxArray_real_T *inlierIndices)
{
  emxArray_real_T *k;
  emxArray_real_T *r;
  emxArray_real_T *x;
  double b_p0[3];
  double dp[3];
  double dp_tmp;
  double ex;
  double p0;
  int ibmat;
  int itilerow;
  int jcol;
  int ntilerows;
  boolean_T exitg1;
  emxInit_real_T(&r, 2);
  jcol = r->size[0] * r->size[1];
  r->size[0] = inlierIndices->size[0];
  r->size[1] = 3;
  emxEnsureCapacity_real_T(r, jcol);
  ntilerows = inlierIndices->size[0];
  p0 = 0.0;
  for (jcol = 0; jcol < 3; jcol++) {
    dp_tmp = modelParams_data[jcol + 3];
    dp[jcol] = dp_tmp;
    b_p0[jcol] = modelParams_data[jcol];
    ibmat = jcol * ntilerows;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      r->data[ibmat + itilerow] = dp_tmp;
    }
    p0 += b_p0[jcol] * dp[jcol];
  }
  emxInit_real_T(&k, 1);
  emxInit_real_T(&x, 2);
  jcol = x->size[0] * x->size[1];
  x->size[0] = inlierIndices->size[0];
  x->size[1] = 3;
  emxEnsureCapacity_real_T(x, jcol);
  ntilerows = inlierIndices->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    for (ibmat = 0; ibmat < ntilerows; ibmat++) {
      x->data[ibmat + x->size[0] * jcol] =
          ptCloud->Location[((int)inlierIndices->data[ibmat] + 45 * jcol) - 1] *
          r->data[ibmat + r->size[0] * jcol];
    }
  }
  emxFree_real_T(&r);
  if (x->size[0] == 0) {
    k->size[0] = 0;
  } else {
    ibmat = x->size[0];
    jcol = k->size[0];
    k->size[0] = x->size[0];
    emxEnsureCapacity_real_T(k, jcol);
    for (jcol = 0; jcol < ibmat; jcol++) {
      k->data[jcol] = x->data[jcol];
    }
    for (itilerow = 0; itilerow < 2; itilerow++) {
      ntilerows = (itilerow + 1) * ibmat;
      for (jcol = 0; jcol < ibmat; jcol++) {
        k->data[jcol] += x->data[ntilerows + jcol];
      }
    }
  }
  emxFree_real_T(&x);
  ntilerows = k->size[0];
  for (jcol = 0; jcol < ntilerows; jcol++) {
    k->data[jcol] -= p0;
  }
  ibmat = k->size[0];
  if (k->size[0] <= 2) {
    if (k->size[0] == 1) {
      p0 = k->data[0];
    } else if ((k->data[0] > k->data[k->size[0] - 1]) ||
               (rtIsNaN(k->data[0]) && (!rtIsNaN(k->data[k->size[0] - 1])))) {
      p0 = k->data[k->size[0] - 1];
    } else {
      p0 = k->data[0];
    }
  } else {
    if (!rtIsNaN(k->data[0])) {
      ntilerows = 1;
    } else {
      ntilerows = 0;
      itilerow = 2;
      exitg1 = false;
      while ((!exitg1) && (itilerow <= ibmat)) {
        if (!rtIsNaN(k->data[itilerow - 1])) {
          ntilerows = itilerow;
          exitg1 = true;
        } else {
          itilerow++;
        }
      }
    }
    if (ntilerows == 0) {
      p0 = k->data[0];
    } else {
      p0 = k->data[ntilerows - 1];
      jcol = ntilerows + 1;
      for (itilerow = jcol; itilerow <= ibmat; itilerow++) {
        dp_tmp = k->data[itilerow - 1];
        if (p0 > dp_tmp) {
          p0 = dp_tmp;
        }
      }
    }
  }
  ibmat = k->size[0];
  if (k->size[0] <= 2) {
    if (k->size[0] == 1) {
      ex = k->data[0];
    } else if ((k->data[0] < k->data[k->size[0] - 1]) ||
               (rtIsNaN(k->data[0]) && (!rtIsNaN(k->data[k->size[0] - 1])))) {
      ex = k->data[k->size[0] - 1];
    } else {
      ex = k->data[0];
    }
  } else {
    if (!rtIsNaN(k->data[0])) {
      ntilerows = 1;
    } else {
      ntilerows = 0;
      itilerow = 2;
      exitg1 = false;
      while ((!exitg1) && (itilerow <= ibmat)) {
        if (!rtIsNaN(k->data[itilerow - 1])) {
          ntilerows = itilerow;
          exitg1 = true;
        } else {
          itilerow++;
        }
      }
    }
    if (ntilerows == 0) {
      ex = k->data[0];
    } else {
      ex = k->data[ntilerows - 1];
      jcol = ntilerows + 1;
      for (itilerow = jcol; itilerow <= ibmat; itilerow++) {
        dp_tmp = k->data[itilerow - 1];
        if (ex < dp_tmp) {
          ex = dp_tmp;
        }
      }
    }
  }
  emxFree_real_T(&k);
  modelParams_data[0] = b_p0[0] + p0 * dp[0];
  modelParams_data[3] = b_p0[0] + ex * dp[0];
  modelParams_data[1] = b_p0[1] + p0 * dp[1];
  modelParams_data[4] = b_p0[1] + ex * dp[1];
  modelParams_data[2] = b_p0[2] + p0 * dp[2];
  modelParams_data[5] = b_p0[2] + ex * dp[2];
}

/*
 * File trailer for pcfitcylinder.c
 *
 * [EOF]
 */
