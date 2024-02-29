/*
 * File: msac.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "msac.h"
#include "combineVectorElements.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double d;
  double d1;
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

/*
 * Arguments    : const emxArray_real_T *allPoints
 *                boolean_T *isFound
 *                double bestModelParams_data[]
 *                int bestModelParams_size[2]
 * Return Type  : void
 */
void msac(const emxArray_real_T *allPoints, boolean_T *isFound,
          double bestModelParams_data[], int bestModelParams_size[2])
{
  emxArray_boolean_T *bestInliers;
  emxArray_boolean_T *x;
  emxArray_real_T *c;
  emxArray_real_T *dis;
  emxArray_real_T *p1p0;
  emxArray_real_T *samplePoints;
  emxArray_real_T *y;
  double modelParams[7];
  double indices_data[2];
  double a;
  double b;
  double b_a;
  double b_c;
  double b_d;
  double bestDis;
  double d;
  double d1;
  double d2;
  double d3;
  double j;
  double loc_data_idx_0;
  double n1_idx_0;
  double n1_idx_1;
  double n2_idx_0;
  double n2_idx_1;
  double n2_idx_2;
  double p0_idx_0;
  double p0_idx_1;
  double p1_idx_0;
  double p1_idx_1;
  double p2_idx_0;
  double p2_idx_1;
  double selectedLoc;
  double t;
  double w_idx_1;
  int idxTrial;
  int k;
  int loop_ub;
  int numPts;
  int numTrials;
  int nz;
  int skipTrials;
  int vlen;
  signed char hashTbl_data[2];
  boolean_T tmp_data[7];
  boolean_T x_data[7];
  boolean_T exitg1;
  boolean_T isValidModel;
  emxInit_boolean_T(&bestInliers, 1);
  numPts = allPoints->size[0];
  idxTrial = 1;
  numTrials = 1000;
  bestDis = 0.0005 * (double)allPoints->size[0];
  bestModelParams_size[0] = 0;
  bestModelParams_size[1] = 0;
  skipTrials = 0;
  k = bestInliers->size[0];
  bestInliers->size[0] = allPoints->size[0];
  emxEnsureCapacity_boolean_T(bestInliers, k);
  vlen = allPoints->size[0];
  for (k = 0; k < vlen; k++) {
    bestInliers->data[k] = false;
  }
  emxInit_real_T(&samplePoints, 2);
  emxInit_real_T(&dis, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_real_T(&p1p0, 2);
  emxInit_real_T(&c, 2);
  emxInit_real_T(&y, 1);
  while ((idxTrial <= numTrials) && (skipTrials < 10000)) {
    indices_data[1] = 0.0;
    if (2 >= numPts) {
      indices_data[0] = 1.0;
      j = b_rand() * 2.0;
      j = floor(j);
      indices_data[1] = indices_data[(int)(j + 1.0) - 1];
      indices_data[(int)(j + 1.0) - 1] = 2.0;
    } else if (2.0 >= (double)numPts / 4.0) {
      t = 0.0;
      selectedLoc = numPts;
      loc_data_idx_0 = 2.0 / (double)numPts;
      j = b_rand();
      while (j > loc_data_idx_0) {
        t++;
        selectedLoc--;
        loc_data_idx_0 += (1.0 - loc_data_idx_0) * (2.0 / selectedLoc);
      }
      t++;
      j = b_rand();
      j = floor(j);
      indices_data[0] = 0.0;
      indices_data[(int)(j + 1.0) - 1] = t;
      selectedLoc = (double)numPts - t;
      loc_data_idx_0 = 1.0 / selectedLoc;
      j = b_rand();
      while (j > loc_data_idx_0) {
        t++;
        selectedLoc--;
        loc_data_idx_0 += (1.0 - loc_data_idx_0) * (1.0 / selectedLoc);
      }
      t++;
      j = b_rand() * 2.0;
      j = floor(j);
      indices_data[1] = indices_data[(int)(j + 1.0) - 1];
      indices_data[(int)(j + 1.0) - 1] = t;
    } else {
      hashTbl_data[0] = 0;
      hashTbl_data[1] = 0;
      selectedLoc = b_rand() * (((double)numPts - 1.0) + 1.0);
      selectedLoc = floor(selectedLoc);
      if (selectedLoc == 0.0) {
        j = 0.0;
      } else {
        j = fmod(selectedLoc, 2.0);
        if (j == 0.0) {
          j = 0.0;
        }
      }
      indices_data[0] = selectedLoc + 1.0;
      loc_data_idx_0 = selectedLoc;
      hashTbl_data[(int)(j + 1.0) - 1] = 1;
      vlen = hashTbl_data[(int)fmod((double)numPts - 1.0, 2.0)];
      while ((vlen > 0) && (selectedLoc != (double)numPts - 1.0)) {
        vlen = 0;
      }
      if (vlen > 0) {
        nz = 0;
      } else {
        nz = numPts - 1;
      }
      selectedLoc = b_rand() * (((double)numPts - 2.0) + 1.0);
      selectedLoc = floor(selectedLoc);
      if (selectedLoc == 0.0) {
        j = 0.0;
      } else {
        j = fmod(selectedLoc, 2.0);
        if (j == 0.0) {
          j = 0.0;
        }
      }
      j = hashTbl_data[(int)(j + 1.0) - 1];
      while ((j > 0.0) && (loc_data_idx_0 != selectedLoc)) {
        j = 0.0;
      }
      if (j > 0.0) {
        indices_data[1] = (double)nz + 1.0;
      } else {
        indices_data[1] = selectedLoc + 1.0;
      }
    }
    vlen = allPoints->size[1];
    k = samplePoints->size[0] * samplePoints->size[1];
    samplePoints->size[0] = 2;
    samplePoints->size[1] = allPoints->size[1];
    emxEnsureCapacity_real_T(samplePoints, k);
    for (k = 0; k < vlen; k++) {
      samplePoints->data[2 * k] =
          allPoints->data[((int)indices_data[0] + allPoints->size[0] * k) - 1];
      samplePoints->data[2 * k + 1] =
          allPoints->data[((int)indices_data[1] + allPoints->size[0] * k) - 1];
    }
    d = samplePoints->data[0];
    p1_idx_0 = d;
    d1 = samplePoints->data[6];
    n1_idx_0 = d1;
    d2 = samplePoints->data[1];
    p2_idx_0 = d2;
    n2_idx_0 = samplePoints->data[7];
    d3 = d + d1;
    p0_idx_0 = d3;
    j = d3 - d2;
    selectedLoc = d1 * d1;
    d = samplePoints->data[2];
    p1_idx_1 = d;
    d1 = samplePoints->data[8];
    n1_idx_1 = d1;
    d2 = samplePoints->data[3];
    p2_idx_1 = d2;
    n2_idx_1 = samplePoints->data[9];
    d3 = d + d1;
    p0_idx_1 = d3;
    w_idx_1 = d3 - d2;
    loc_data_idx_0 = d1 * d1;
    d = samplePoints->data[4];
    d1 = samplePoints->data[10];
    d2 = samplePoints->data[5];
    n2_idx_2 = samplePoints->data[11];
    d3 = d + d1;
    t = d3 - d2;
    a = (selectedLoc + loc_data_idx_0) + d1 * d1;
    b = (n1_idx_0 * n2_idx_0 + n1_idx_1 * n2_idx_1) + d1 * n2_idx_2;
    b_c = (n2_idx_0 * n2_idx_0 + n2_idx_1 * n2_idx_1) + n2_idx_2 * n2_idx_2;
    b_d = (n1_idx_0 * j + n1_idx_1 * w_idx_1) + d1 * t;
    j *= n2_idx_0;
    w_idx_1 *= n2_idx_1;
    t *= n2_idx_2;
    selectedLoc = (j + w_idx_1) + t;
    loc_data_idx_0 = a * b_c - b * b;
    if (fabs(loc_data_idx_0) < 1.0E-5) {
      b_a = 0.0;
      if (b > b_c) {
        a = b_d / b;
      } else {
        a = selectedLoc / b_c;
      }
    } else {
      b_a = (b * selectedLoc - b_c * b_d) / loc_data_idx_0;
      a = (a * selectedLoc - b * b_d) / loc_data_idx_0;
    }
    w_idx_1 = 3.3121686421112381E-170;
    b = p0_idx_0 + b_a * n1_idx_0;
    p0_idx_0 = b;
    selectedLoc = (p2_idx_0 + a * n2_idx_0) - b;
    p2_idx_0 = selectedLoc;
    loc_data_idx_0 = fabs(selectedLoc);
    if (loc_data_idx_0 > 3.3121686421112381E-170) {
      j = 1.0;
      w_idx_1 = loc_data_idx_0;
    } else {
      t = loc_data_idx_0 / 3.3121686421112381E-170;
      j = t * t;
    }
    b = p0_idx_1 + b_a * n1_idx_1;
    p0_idx_1 = b;
    selectedLoc = (p2_idx_1 + a * n2_idx_1) - b;
    p2_idx_1 = selectedLoc;
    loc_data_idx_0 = fabs(selectedLoc);
    if (loc_data_idx_0 > w_idx_1) {
      t = w_idx_1 / loc_data_idx_0;
      j = j * t * t + 1.0;
      w_idx_1 = loc_data_idx_0;
    } else {
      t = loc_data_idx_0 / w_idx_1;
      j += t * t;
    }
    b = d3 + b_a * d1;
    selectedLoc = (d2 + a * n2_idx_2) - b;
    loc_data_idx_0 = fabs(selectedLoc);
    if (loc_data_idx_0 > w_idx_1) {
      t = w_idx_1 / loc_data_idx_0;
      j = j * t * t + 1.0;
      w_idx_1 = loc_data_idx_0;
    } else {
      t = loc_data_idx_0 / w_idx_1;
      j += t * t;
    }
    j = w_idx_1 * sqrt(j);
    p2_idx_0 /= j;
    p1_idx_0 -= p0_idx_0;
    p2_idx_1 /= j;
    p1_idx_1 -= p0_idx_1;
    loc_data_idx_0 = selectedLoc / j;
    selectedLoc = d - b;
    n1_idx_0 = p1_idx_1 * loc_data_idx_0 - p2_idx_1 * selectedLoc;
    n1_idx_1 = p2_idx_0 * selectedLoc - p1_idx_0 * loc_data_idx_0;
    selectedLoc = p1_idx_0 * p2_idx_1 - p2_idx_0 * p1_idx_1;
    n1_idx_0 *= n1_idx_0;
    n1_idx_1 *= n1_idx_1;
    selectedLoc *= selectedLoc;
    modelParams[0] = p0_idx_0;
    modelParams[3] = p2_idx_0;
    modelParams[1] = p0_idx_1;
    modelParams[4] = p2_idx_1;
    modelParams[2] = b;
    modelParams[5] = loc_data_idx_0;
    modelParams[6] = sqrt((n1_idx_0 + n1_idx_1) + selectedLoc);
    for (k = 0; k < 7; k++) {
      d = modelParams[k];
      x_data[k] = rtIsInf(d);
      tmp_data[k] = rtIsNaN(d);
    }
    isValidModel = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (x_data[k] || tmp_data[k]) {
        isValidModel = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (isValidModel) {
      vlen = allPoints->size[0];
      k = p1p0->size[0] * p1p0->size[1];
      p1p0->size[0] = allPoints->size[0];
      p1p0->size[1] = 3;
      emxEnsureCapacity_real_T(p1p0, k);
      for (k = 0; k < vlen; k++) {
        p1p0->data[k] = allPoints->data[k] - p0_idx_0;
        p1p0->data[k + p1p0->size[0]] =
            allPoints->data[k + allPoints->size[0]] - p0_idx_1;
        p1p0->data[k + p1p0->size[0] * 2] =
            allPoints->data[k + allPoints->size[0] * 2] - b;
      }
      vlen = p1p0->size[0];
      nz = p1p0->size[0];
      loop_ub = p1p0->size[0];
      k = c->size[0] * c->size[1];
      c->size[0] = p1p0->size[0];
      c->size[1] = 3;
      emxEnsureCapacity_real_T(c, k);
      for (k = 0; k < vlen; k++) {
        c->data[k] = p1p0->data[k + p1p0->size[0]] * loc_data_idx_0 -
                     p1p0->data[k + p1p0->size[0] * 2] * p2_idx_1;
      }
      for (k = 0; k < nz; k++) {
        c->data[k + c->size[0]] = p1p0->data[k + p1p0->size[0] * 2] * p2_idx_0 -
                                  p1p0->data[k] * loc_data_idx_0;
      }
      for (k = 0; k < loop_ub; k++) {
        c->data[k + c->size[0] * 2] =
            p1p0->data[k] * p2_idx_1 - p1p0->data[k + p1p0->size[0]] * p2_idx_0;
      }
      vlen = c->size[0] * 3;
      k = c->size[0] * c->size[1];
      c->size[1] = 3;
      emxEnsureCapacity_real_T(c, k);
      for (k = 0; k < vlen; k++) {
        c->data[k] *= c->data[k];
      }
      if (c->size[0] == 0) {
        y->size[0] = 0;
      } else {
        nz = c->size[0];
        k = y->size[0];
        y->size[0] = c->size[0];
        emxEnsureCapacity_real_T(y, k);
        for (loop_ub = 0; loop_ub < nz; loop_ub++) {
          y->data[loop_ub] = c->data[loop_ub];
        }
        for (k = 0; k < 2; k++) {
          vlen = (k + 1) * nz;
          for (loop_ub = 0; loop_ub < nz; loop_ub++) {
            y->data[loop_ub] += c->data[vlen + loop_ub];
          }
        }
      }
      vlen = y->size[0];
      for (k = 0; k < vlen; k++) {
        y->data[k] = sqrt(y->data[k]);
      }
      vlen = y->size[0];
      for (k = 0; k < vlen; k++) {
        y->data[k] -= modelParams[6];
      }
      vlen = y->size[0];
      k = dis->size[0];
      dis->size[0] = y->size[0];
      emxEnsureCapacity_real_T(dis, k);
      for (k = 0; k < vlen; k++) {
        dis->data[k] = fabs(y->data[k]);
      }
      vlen = dis->size[0];
      for (nz = 0; nz < vlen; nz++) {
        if (dis->data[nz] > 0.0005) {
          dis->data[nz] = 0.0005;
        }
      }
      j = combineVectorElements(dis);
      if (j < bestDis) {
        bestDis = j;
        k = bestInliers->size[0];
        bestInliers->size[0] = dis->size[0];
        emxEnsureCapacity_boolean_T(bestInliers, k);
        vlen = dis->size[0];
        for (k = 0; k < vlen; k++) {
          bestInliers->data[k] = (dis->data[k] < 0.0005);
        }
        bestModelParams_size[0] = 1;
        bestModelParams_size[1] = 7;
        for (k = 0; k < 7; k++) {
          bestModelParams_data[k] = modelParams[k];
        }
        k = x->size[0];
        x->size[0] = dis->size[0];
        emxEnsureCapacity_boolean_T(x, k);
        vlen = dis->size[0];
        for (k = 0; k < vlen; k++) {
          x->data[k] = (dis->data[k] < 0.0005);
        }
        vlen = x->size[0];
        if (x->size[0] == 0) {
          nz = 0;
        } else {
          nz = x->data[0];
          for (k = 2; k <= vlen; k++) {
            nz += x->data[k - 1];
          }
        }
        j = rt_powd_snf((double)nz / (double)numPts, 2.0);
        if (j < 2.2204460492503131E-16) {
          vlen = MAX_int32_T;
        } else {
          d = ceil(-1.9999999999999996 / log10(1.0 - j));
          if (d < 2.147483648E+9) {
            vlen = (int)d;
          } else if (d >= 2.147483648E+9) {
            vlen = MAX_int32_T;
          } else {
            vlen = 0;
          }
        }
        if (numTrials >= vlen) {
          numTrials = vlen;
        }
      }
      idxTrial++;
    } else {
      skipTrials++;
    }
  }
  emxFree_real_T(&y);
  emxFree_real_T(&c);
  emxFree_real_T(&p1p0);
  emxFree_boolean_T(&x);
  emxFree_real_T(&dis);
  emxFree_real_T(&samplePoints);
  nz = bestModelParams_size[0] * bestModelParams_size[1];
  for (k = 0; k < nz; k++) {
    x_data[k] = rtIsInf(bestModelParams_data[k]);
  }
  for (k = 0; k < nz; k++) {
    tmp_data[k] = rtIsNaN(bestModelParams_data[k]);
  }
  for (k = 0; k < nz; k++) {
    x_data[k] = ((!x_data[k]) && (!tmp_data[k]));
  }
  isValidModel = true;
  vlen = 1;
  exitg1 = false;
  while ((!exitg1) && (vlen <= nz)) {
    if (!x_data[vlen - 1]) {
      isValidModel = false;
      exitg1 = true;
    } else {
      vlen++;
    }
  }
  if ((nz == 7) && isValidModel && (bestInliers->size[0] != 0)) {
    vlen = bestInliers->size[0];
    nz = bestInliers->data[0];
    for (k = 2; k <= vlen; k++) {
      nz += bestInliers->data[k - 1];
    }
    if (nz >= 2) {
      *isFound = true;
    } else {
      *isFound = false;
    }
  } else {
    *isFound = false;
  }
  emxFree_boolean_T(&bestInliers);
}

/*
 * File trailer for msac.c
 *
 * [EOF]
 */
