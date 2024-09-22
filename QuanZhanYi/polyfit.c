/*
 * File: polyfit.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 22-Sep-2024 11:56:57
 */

/* Include Files */
#include "polyfit.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                double p[2]
 * Return Type  : void
 */
void polyfit(const emxArray_real_T *x, const emxArray_real_T *y, double p[2])
{
  emxArray_real_T *B;
  emxArray_real_T *V;
  double tau_data[2];
  double vn1[2];
  double vn2[2];
  double work[2];
  const double *x_data;
  const double *y_data;
  double atmp;
  double beta1;
  double temp;
  double *B_data;
  double *V_data;
  int b_i;
  int exitg1;
  int i;
  int iac;
  int ii;
  int ip1;
  int ix;
  int k;
  int knt;
  int lastv;
  int m;
  int ma;
  int mmi;
  int pvt;
  int u0;
  signed char jpvt[2];
  y_data = y->data;
  x_data = x->data;
  emxInit_real_T(&V, 2);
  i = V->size[0] * V->size[1];
  V->size[0] = x->size[0];
  V->size[1] = 2;
  emxEnsureCapacity_real_T(V, i);
  V_data = V->data;
  if (x->size[0] != 0) {
    i = x->size[0];
    for (k = 0; k < i; k++) {
      V_data[k + V->size[0]] = 1.0;
      V_data[k] = x_data[k];
    }
  }
  m = V->size[0];
  u0 = V->size[0];
  if (u0 > 2) {
    u0 = 2;
  }
  if (u0 - 1 >= 0) {
    memset(&tau_data[0], 0, (unsigned int)u0 * sizeof(double));
  }
  if (V->size[0] == 0) {
    jpvt[0] = 1;
    jpvt[1] = 2;
  } else {
    ma = V->size[0];
    jpvt[0] = 1;
    work[0] = 0.0;
    temp = b_xnrm2(V->size[0], V, 1);
    vn1[0] = temp;
    vn2[0] = temp;
    jpvt[1] = 2;
    work[1] = 0.0;
    temp = b_xnrm2(V->size[0], V, V->size[0] + 1);
    vn1[1] = temp;
    vn2[1] = temp;
    for (b_i = 0; b_i < u0; b_i++) {
      ip1 = b_i + 2;
      lastv = b_i * ma;
      ii = lastv + b_i;
      mmi = m - b_i;
      ix = 0;
      if ((2 - b_i > 1) && (fabs(vn1[b_i + 1]) > fabs(vn1[b_i]))) {
        ix = 1;
      }
      pvt = b_i + ix;
      if (pvt != b_i) {
        ix = pvt * ma;
        for (k = 0; k < m; k++) {
          knt = ix + k;
          temp = V_data[knt];
          i = lastv + k;
          V_data[knt] = V_data[i];
          V_data[i] = temp;
        }
        ix = jpvt[pvt];
        jpvt[pvt] = jpvt[b_i];
        jpvt[b_i] = (signed char)ix;
        vn1[pvt] = vn1[b_i];
        vn2[pvt] = vn2[b_i];
      }
      if (b_i + 1 < m) {
        atmp = V_data[ii];
        ix = ii + 2;
        tau_data[b_i] = 0.0;
        if (mmi > 0) {
          temp = b_xnrm2(mmi - 1, V, ii + 2);
          if (temp != 0.0) {
            beta1 = rt_hypotd_snf(V_data[ii], temp);
            if (V_data[ii] >= 0.0) {
              beta1 = -beta1;
            }
            if (fabs(beta1) < 1.0020841800044864E-292) {
              knt = 0;
              i = ii + mmi;
              do {
                knt++;
                for (k = ix; k <= i; k++) {
                  V_data[k - 1] *= 9.9792015476736E+291;
                }
                beta1 *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));
              beta1 = rt_hypotd_snf(atmp, b_xnrm2(mmi - 1, V, ii + 2));
              if (atmp >= 0.0) {
                beta1 = -beta1;
              }
              tau_data[b_i] = (beta1 - atmp) / beta1;
              temp = 1.0 / (atmp - beta1);
              for (k = ix; k <= i; k++) {
                V_data[k - 1] *= temp;
              }
              for (k = 0; k < knt; k++) {
                beta1 *= 1.0020841800044864E-292;
              }
              atmp = beta1;
            } else {
              tau_data[b_i] = (beta1 - V_data[ii]) / beta1;
              temp = 1.0 / (V_data[ii] - beta1);
              i = ii + mmi;
              for (k = ix; k <= i; k++) {
                V_data[k - 1] *= temp;
              }
              atmp = beta1;
            }
          }
        }
        V_data[ii] = atmp;
      } else {
        tau_data[b_i] = 0.0;
      }
      if (b_i + 1 < 2) {
        atmp = V_data[ii];
        V_data[ii] = 1.0;
        pvt = (ii + ma) + 1;
        if (tau_data[0] != 0.0) {
          lastv = mmi - 1;
          ix = (ii + mmi) - 1;
          while ((lastv + 1 > 0) && (V_data[ix] == 0.0)) {
            lastv--;
            ix--;
          }
          ix = 1;
          k = pvt;
          do {
            exitg1 = 0;
            if (k <= pvt + lastv) {
              if (V_data[k - 1] != 0.0) {
                exitg1 = 1;
              } else {
                k++;
              }
            } else {
              ix = 0;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          lastv = -1;
          ix = 0;
        }
        if (lastv + 1 > 0) {
          if (ix != 0) {
            work[0] = 0.0;
            knt = 0;
            for (iac = pvt; ma < 0 ? iac >= pvt : iac <= pvt; iac += ma) {
              temp = 0.0;
              i = iac + lastv;
              for (k = iac; k <= i; k++) {
                temp += V_data[k - 1] * V_data[(ii + k) - iac];
              }
              work[knt] += temp;
              knt++;
            }
          }
          if (!(-tau_data[0] == 0.0)) {
            for (iac = 0; iac < ix; iac++) {
              if (work[0] != 0.0) {
                temp = work[0] * -tau_data[0];
                i = lastv + pvt;
                for (knt = pvt; knt <= i; knt++) {
                  V_data[knt - 1] += V_data[(ii + knt) - pvt] * temp;
                }
              }
              pvt += ma;
            }
          }
        }
        V_data[ii] = atmp;
      }
      for (iac = ip1; iac < 3; iac++) {
        ix = b_i + ma;
        if (vn1[1] != 0.0) {
          temp = fabs(V_data[ix]) / vn1[1];
          temp = 1.0 - temp * temp;
          if (temp < 0.0) {
            temp = 0.0;
          }
          beta1 = vn1[1] / vn2[1];
          beta1 = temp * (beta1 * beta1);
          if (beta1 <= 1.4901161193847656E-8) {
            if (b_i + 1 < m) {
              temp = b_xnrm2(mmi - 1, V, ix + 2);
              vn1[1] = temp;
              vn2[1] = temp;
            } else {
              vn1[1] = 0.0;
              vn2[1] = 0.0;
            }
          } else {
            vn1[1] *= sqrt(temp);
          }
        }
      }
    }
  }
  knt = 0;
  if (u0 > 0) {
    for (k = 0; k < u0; k++) {
      if (V_data[k + V->size[0] * k] != 0.0) {
        knt++;
      }
    }
  }
  emxInit_real_T(&B, 1);
  i = B->size[0];
  B->size[0] = y->size[0];
  emxEnsureCapacity_real_T(B, i);
  B_data = B->data;
  ix = y->size[0];
  for (i = 0; i < ix; i++) {
    B_data[i] = y_data[i];
  }
  p[0] = 0.0;
  p[1] = 0.0;
  m = V->size[0];
  for (iac = 0; iac < u0; iac++) {
    if (tau_data[iac] != 0.0) {
      temp = B_data[iac];
      i = iac + 2;
      for (b_i = i; b_i <= m; b_i++) {
        temp += V_data[(b_i + V->size[0] * iac) - 1] * B_data[b_i - 1];
      }
      temp *= tau_data[iac];
      if (temp != 0.0) {
        B_data[iac] -= temp;
        for (b_i = i; b_i <= m; b_i++) {
          B_data[b_i - 1] -= V_data[(b_i + V->size[0] * iac) - 1] * temp;
        }
      }
    }
  }
  for (b_i = 0; b_i < knt; b_i++) {
    p[jpvt[b_i] - 1] = B_data[b_i];
  }
  emxFree_real_T(&B);
  for (iac = knt; iac >= 1; iac--) {
    ix = jpvt[iac - 1] - 1;
    p[ix] /= V_data[(iac + V->size[0] * (iac - 1)) - 1];
    for (b_i = 0; b_i <= iac - 2; b_i++) {
      p[jpvt[0] - 1] -= p[ix] * V_data[V->size[0] * (iac - 1)];
    }
  }
  emxFree_real_T(&V);
}

/*
 * File trailer for polyfit.c
 *
 * [EOF]
 */
