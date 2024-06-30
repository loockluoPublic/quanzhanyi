/*
 * File: qrsolve.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 12:40:56
 */

/* Include Files */
#include "qrsolve.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double Y[3]
 * Return Type  : void
 */
void qrsolve(const emxArray_real_T *A, const emxArray_real_T *B, double Y[3])
{
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  double tau_data[3];
  double work[3];
  const double *A_data;
  const double *B_data;
  double smax;
  double *b_A_data;
  double *b_B_data;
  int b_i;
  int i;
  int ia;
  int iac;
  int jA;
  int knt;
  int m;
  int minmana;
  int minmn;
  int pvt;
  signed char jpvt[3];
  B_data = B->data;
  A_data = A->data;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 3;
  emxEnsureCapacity_real_T(b_A, i);
  b_A_data = b_A->data;
  minmana = A->size[0] * 3;
  for (i = 0; i < minmana; i++) {
    b_A_data[i] = A_data[i];
  }
  m = A->size[0];
  minmana = A->size[0];
  if (minmana > 3) {
    minmana = 3;
  }
  if (minmana - 1 >= 0) {
    memset(&tau_data[0], 0, minmana * sizeof(double));
  }
  if (A->size[0] == 0) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  } else {
    double vn1[3];
    double vn2[3];
    double d;
    int ma;
    ma = A->size[0];
    minmn = A->size[0];
    if (minmn > 3) {
      minmn = 3;
    }
    jpvt[0] = 1;
    work[0] = 0.0;
    d = b_xnrm2(A->size[0], A, 1);
    vn1[0] = d;
    vn2[0] = d;
    jpvt[1] = 2;
    work[1] = 0.0;
    d = b_xnrm2(A->size[0], A, A->size[0] + 1);
    vn1[1] = d;
    vn2[1] = d;
    jpvt[2] = 3;
    work[2] = 0.0;
    d = b_xnrm2(A->size[0], A, (A->size[0] << 1) + 1);
    vn1[2] = d;
    vn2[2] = d;
    for (b_i = 0; b_i < minmn; b_i++) {
      double atmp;
      double s;
      int ii;
      int ip1;
      int lastv;
      int mmi;
      ip1 = b_i + 2;
      lastv = b_i * ma;
      ii = lastv + b_i;
      mmi = m - b_i;
      minmana = 3 - b_i;
      knt = 0;
      if (3 - b_i > 1) {
        smax = fabs(vn1[b_i]);
        for (jA = 2; jA <= minmana; jA++) {
          s = fabs(vn1[(b_i + jA) - 1]);
          if (s > smax) {
            knt = jA - 1;
            smax = s;
          }
        }
      }
      pvt = b_i + knt;
      if (pvt != b_i) {
        minmana = pvt * ma;
        for (jA = 0; jA < m; jA++) {
          knt = minmana + jA;
          smax = b_A_data[knt];
          i = lastv + jA;
          b_A_data[knt] = b_A_data[i];
          b_A_data[i] = smax;
        }
        minmana = jpvt[pvt];
        jpvt[pvt] = jpvt[b_i];
        jpvt[b_i] = (signed char)minmana;
        vn1[pvt] = vn1[b_i];
        vn2[pvt] = vn2[b_i];
      }
      if (b_i + 1 < m) {
        atmp = b_A_data[ii];
        minmana = ii + 2;
        tau_data[b_i] = 0.0;
        if (mmi > 0) {
          smax = b_xnrm2(mmi - 1, b_A, ii + 2);
          if (smax != 0.0) {
            s = rt_hypotd_snf(b_A_data[ii], smax);
            if (b_A_data[ii] >= 0.0) {
              s = -s;
            }
            if (fabs(s) < 1.0020841800044864E-292) {
              knt = 0;
              i = ii + mmi;
              do {
                knt++;
                for (jA = minmana; jA <= i; jA++) {
                  b_A_data[jA - 1] *= 9.9792015476736E+291;
                }
                s *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while ((fabs(s) < 1.0020841800044864E-292) && (knt < 20));
              s = rt_hypotd_snf(atmp, b_xnrm2(mmi - 1, b_A, ii + 2));
              if (atmp >= 0.0) {
                s = -s;
              }
              tau_data[b_i] = (s - atmp) / s;
              smax = 1.0 / (atmp - s);
              for (jA = minmana; jA <= i; jA++) {
                b_A_data[jA - 1] *= smax;
              }
              for (jA = 0; jA < knt; jA++) {
                s *= 1.0020841800044864E-292;
              }
              atmp = s;
            } else {
              tau_data[b_i] = (s - b_A_data[ii]) / s;
              smax = 1.0 / (b_A_data[ii] - s);
              i = ii + mmi;
              for (jA = minmana; jA <= i; jA++) {
                b_A_data[jA - 1] *= smax;
              }
              atmp = s;
            }
          }
        }
        b_A_data[ii] = atmp;
      } else {
        tau_data[b_i] = 0.0;
      }
      if (b_i + 1 < 3) {
        atmp = b_A_data[ii];
        b_A_data[ii] = 1.0;
        jA = (ii + ma) + 1;
        if (tau_data[b_i] != 0.0) {
          boolean_T exitg2;
          lastv = mmi - 1;
          minmana = (ii + mmi) - 1;
          while ((lastv + 1 > 0) && (b_A_data[minmana] == 0.0)) {
            lastv--;
            minmana--;
          }
          pvt = 1 - b_i;
          exitg2 = false;
          while ((!exitg2) && (pvt + 1 > 0)) {
            int exitg1;
            minmana = jA + pvt * ma;
            ia = minmana;
            do {
              exitg1 = 0;
              if (ia <= minmana + lastv) {
                if (b_A_data[ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  ia++;
                }
              } else {
                pvt--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          pvt = -1;
        }
        if (lastv + 1 > 0) {
          if (pvt + 1 != 0) {
            memset(&work[0], 0, (pvt + 1) * sizeof(double));
            minmana = 0;
            i = jA + ma * pvt;
            for (iac = jA; ma < 0 ? iac >= i : iac <= i; iac += ma) {
              smax = 0.0;
              knt = iac + lastv;
              for (ia = iac; ia <= knt; ia++) {
                smax += b_A_data[ia - 1] * b_A_data[(ii + ia) - iac];
              }
              work[minmana] += smax;
              minmana++;
            }
          }
          if (!(-tau_data[b_i] == 0.0)) {
            for (iac = 0; iac <= pvt; iac++) {
              d = work[iac];
              if (d != 0.0) {
                smax = d * -tau_data[b_i];
                i = lastv + jA;
                for (minmana = jA; minmana <= i; minmana++) {
                  b_A_data[minmana - 1] += b_A_data[(ii + minmana) - jA] * smax;
                }
              }
              jA += ma;
            }
          }
        }
        b_A_data[ii] = atmp;
      }
      for (iac = ip1; iac < 4; iac++) {
        minmana = b_i + (iac - 1) * ma;
        d = vn1[iac - 1];
        if (d != 0.0) {
          smax = fabs(b_A_data[minmana]) / d;
          smax = 1.0 - smax * smax;
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[iac - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if (b_i + 1 < m) {
              d = b_xnrm2(mmi - 1, b_A, minmana + 2);
              vn1[iac - 1] = d;
              vn2[iac - 1] = d;
            } else {
              vn1[iac - 1] = 0.0;
              vn2[iac - 1] = 0.0;
            }
          } else {
            vn1[iac - 1] = d * sqrt(smax);
          }
        }
      }
    }
  }
  pvt = 0;
  if (b_A->size[0] < 3) {
    minmn = b_A->size[0];
    minmana = 3;
  } else {
    minmn = 3;
    minmana = b_A->size[0];
  }
  if (minmn > 0) {
    smax =
        fmin(1.4901161193847656E-8, 2.2204460492503131E-15 * (double)minmana) *
        fabs(b_A_data[0]);
    while ((pvt < minmn) &&
           (!(fabs(b_A_data[pvt + b_A->size[0] * pvt]) <= smax))) {
      pvt++;
    }
  }
  emxInit_real_T(&b_B, 1);
  i = b_B->size[0];
  b_B->size[0] = B->size[0];
  emxEnsureCapacity_real_T(b_B, i);
  b_B_data = b_B->data;
  minmana = B->size[0];
  for (i = 0; i < minmana; i++) {
    b_B_data[i] = B_data[i];
  }
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  m = b_A->size[0];
  minmana = b_A->size[0];
  if (minmana > 3) {
    minmana = 3;
  }
  for (iac = 0; iac < minmana; iac++) {
    if (tau_data[iac] != 0.0) {
      smax = b_B_data[iac];
      i = iac + 2;
      for (b_i = i; b_i <= m; b_i++) {
        smax += b_A_data[(b_i + b_A->size[0] * iac) - 1] * b_B_data[b_i - 1];
      }
      smax *= tau_data[iac];
      if (smax != 0.0) {
        b_B_data[iac] -= smax;
        for (b_i = i; b_i <= m; b_i++) {
          b_B_data[b_i - 1] -= b_A_data[(b_i + b_A->size[0] * iac) - 1] * smax;
        }
      }
    }
  }
  for (b_i = 0; b_i < pvt; b_i++) {
    Y[jpvt[b_i] - 1] = b_B_data[b_i];
  }
  emxFree_real_T(&b_B);
  for (iac = pvt; iac >= 1; iac--) {
    minmana = jpvt[iac - 1] - 1;
    Y[minmana] /= b_A_data[(iac + b_A->size[0] * (iac - 1)) - 1];
    for (b_i = 0; b_i <= iac - 2; b_i++) {
      knt = jpvt[b_i] - 1;
      Y[knt] -= Y[minmana] * b_A_data[b_i + b_A->size[0] * (iac - 1)];
    }
  }
  emxFree_real_T(&b_A);
}

/*
 * File trailer for qrsolve.c
 *
 * [EOF]
 */
