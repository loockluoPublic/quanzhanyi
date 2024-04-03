/*
 * File: qrsolve.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
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
  double vn1[3];
  double vn2[3];
  double work[3];
  double atmp;
  double d;
  double s;
  double smax;
  int b_i;
  int exitg1;
  int i;
  int ia;
  int ii;
  int ip1;
  int jA;
  int k;
  int knt;
  int lastv;
  int m;
  int ma;
  int minmana;
  int minmn;
  int mmi;
  int pvt;
  signed char jpvt[3];
  boolean_T exitg2;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 3;
  emxEnsureCapacity_real_T(b_A, i);
  minmana = A->size[0] * 3;
  for (i = 0; i < minmana; i++) {
    b_A->data[i] = A->data[i];
  }
  m = A->size[0];
  minmana = A->size[0];
  if (minmana >= 3) {
    minmana = 3;
  }
  if (0 <= minmana - 1) {
    memset(&tau_data[0], 0, minmana * sizeof(double));
  }
  if (A->size[0] == 0) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  } else {
    ma = A->size[0];
    minmn = A->size[0];
    if (minmn >= 3) {
      minmn = 3;
    }
    jpvt[0] = 1;
    work[0] = 0.0;
    d = c_xnrm2(A->size[0], A, 1);
    vn1[0] = d;
    vn2[0] = d;
    jpvt[1] = 2;
    work[1] = 0.0;
    d = c_xnrm2(A->size[0], A, A->size[0] + 1);
    vn1[1] = d;
    vn2[1] = d;
    jpvt[2] = 3;
    work[2] = 0.0;
    d = c_xnrm2(A->size[0], A, (A->size[0] << 1) + 1);
    vn1[2] = d;
    vn2[2] = d;
    for (b_i = 0; b_i < minmn; b_i++) {
      ip1 = b_i + 2;
      lastv = b_i * ma;
      ii = lastv + b_i;
      mmi = m - b_i;
      minmana = 3 - b_i;
      knt = 0;
      if (3 - b_i > 1) {
        smax = fabs(vn1[b_i]);
        for (k = 2; k <= minmana; k++) {
          s = fabs(vn1[(b_i + k) - 1]);
          if (s > smax) {
            knt = k - 1;
            smax = s;
          }
        }
      }
      pvt = b_i + knt;
      if (pvt != b_i) {
        minmana = pvt * ma;
        for (k = 0; k < m; k++) {
          knt = minmana + k;
          smax = b_A->data[knt];
          i = lastv + k;
          b_A->data[knt] = b_A->data[i];
          b_A->data[i] = smax;
        }
        minmana = jpvt[pvt];
        jpvt[pvt] = jpvt[b_i];
        jpvt[b_i] = (signed char)minmana;
        vn1[pvt] = vn1[b_i];
        vn2[pvt] = vn2[b_i];
      }
      if (b_i + 1 < m) {
        atmp = b_A->data[ii];
        minmana = ii + 2;
        tau_data[b_i] = 0.0;
        if (mmi > 0) {
          smax = c_xnrm2(mmi - 1, b_A, ii + 2);
          if (smax != 0.0) {
            s = rt_hypotd_snf(b_A->data[ii], smax);
            if (b_A->data[ii] >= 0.0) {
              s = -s;
            }
            if (fabs(s) < 1.0020841800044864E-292) {
              knt = -1;
              i = ii + mmi;
              do {
                knt++;
                for (k = minmana; k <= i; k++) {
                  b_A->data[k - 1] *= 9.9792015476736E+291;
                }
                s *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while (!(fabs(s) >= 1.0020841800044864E-292));
              s = rt_hypotd_snf(atmp, c_xnrm2(mmi - 1, b_A, ii + 2));
              if (atmp >= 0.0) {
                s = -s;
              }
              tau_data[b_i] = (s - atmp) / s;
              smax = 1.0 / (atmp - s);
              for (k = minmana; k <= i; k++) {
                b_A->data[k - 1] *= smax;
              }
              for (k = 0; k <= knt; k++) {
                s *= 1.0020841800044864E-292;
              }
              atmp = s;
            } else {
              tau_data[b_i] = (s - b_A->data[ii]) / s;
              smax = 1.0 / (b_A->data[ii] - s);
              i = ii + mmi;
              for (k = minmana; k <= i; k++) {
                b_A->data[k - 1] *= smax;
              }
              atmp = s;
            }
          }
        }
        b_A->data[ii] = atmp;
      } else {
        tau_data[b_i] = 0.0;
      }
      if (b_i + 1 < 3) {
        atmp = b_A->data[ii];
        b_A->data[ii] = 1.0;
        jA = (ii + ma) + 1;
        if (tau_data[b_i] != 0.0) {
          lastv = mmi - 1;
          minmana = (ii + mmi) - 1;
          while ((lastv + 1 > 0) && (b_A->data[minmana] == 0.0)) {
            lastv--;
            minmana--;
          }
          pvt = 1 - b_i;
          exitg2 = false;
          while ((!exitg2) && (pvt + 1 > 0)) {
            minmana = jA + pvt * ma;
            ia = minmana;
            do {
              exitg1 = 0;
              if (ia <= minmana + lastv) {
                if (b_A->data[ia - 1] != 0.0) {
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
            if (0 <= pvt) {
              memset(&work[0], 0, (pvt + 1) * sizeof(double));
            }
            minmana = 0;
            i = jA + ma * pvt;
            for (k = jA; ma < 0 ? k >= i : k <= i; k += ma) {
              smax = 0.0;
              knt = k + lastv;
              for (ia = k; ia <= knt; ia++) {
                smax += b_A->data[ia - 1] * b_A->data[(ii + ia) - k];
              }
              work[minmana] += smax;
              minmana++;
            }
          }
          if (!(-tau_data[b_i] == 0.0)) {
            for (ia = 0; ia <= pvt; ia++) {
              d = work[ia];
              if (d != 0.0) {
                smax = d * -tau_data[b_i];
                i = lastv + jA;
                for (minmana = jA; minmana <= i; minmana++) {
                  b_A->data[minmana - 1] +=
                      b_A->data[(ii + minmana) - jA] * smax;
                }
              }
              jA += ma;
            }
          }
        }
        b_A->data[ii] = atmp;
      }
      for (ia = ip1; ia < 4; ia++) {
        minmana = b_i + (ia - 1) * ma;
        d = vn1[ia - 1];
        if (d != 0.0) {
          smax = fabs(b_A->data[minmana]) / d;
          smax = 1.0 - smax * smax;
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[ia - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if (b_i + 1 < m) {
              d = c_xnrm2(mmi - 1, b_A, minmana + 2);
              vn1[ia - 1] = d;
              vn2[ia - 1] = d;
            } else {
              vn1[ia - 1] = 0.0;
              vn2[ia - 1] = 0.0;
            }
          } else {
            vn1[ia - 1] = d * sqrt(smax);
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
    smax = 2.2204460492503131E-15 * (double)minmana;
    if (1.4901161193847656E-8 < smax) {
      smax = 1.4901161193847656E-8;
    }
    smax *= fabs(b_A->data[0]);
    while ((pvt < minmn) &&
           (!(fabs(b_A->data[pvt + b_A->size[0] * pvt]) <= smax))) {
      pvt++;
    }
  }
  emxInit_real_T(&b_B, 1);
  i = b_B->size[0];
  b_B->size[0] = B->size[0];
  emxEnsureCapacity_real_T(b_B, i);
  minmana = B->size[0];
  for (i = 0; i < minmana; i++) {
    b_B->data[i] = B->data[i];
  }
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  m = b_A->size[0];
  minmana = b_A->size[0];
  if (minmana >= 3) {
    minmana = 3;
  }
  for (ia = 0; ia < minmana; ia++) {
    if (tau_data[ia] != 0.0) {
      smax = b_B->data[ia];
      i = ia + 2;
      for (b_i = i; b_i <= m; b_i++) {
        smax += b_A->data[(b_i + b_A->size[0] * ia) - 1] * b_B->data[b_i - 1];
      }
      smax *= tau_data[ia];
      if (smax != 0.0) {
        b_B->data[ia] -= smax;
        for (b_i = i; b_i <= m; b_i++) {
          b_B->data[b_i - 1] -= b_A->data[(b_i + b_A->size[0] * ia) - 1] * smax;
        }
      }
    }
  }
  for (b_i = 0; b_i < pvt; b_i++) {
    Y[jpvt[b_i] - 1] = b_B->data[b_i];
  }
  emxFree_real_T(&b_B);
  for (ia = pvt; ia >= 1; ia--) {
    minmana = jpvt[ia - 1] - 1;
    Y[minmana] /= b_A->data[(ia + b_A->size[0] * (ia - 1)) - 1];
    for (b_i = 0; b_i <= ia - 2; b_i++) {
      knt = jpvt[b_i] - 1;
      Y[knt] -= Y[minmana] * b_A->data[b_i + b_A->size[0] * (ia - 1)];
    }
  }
  emxFree_real_T(&b_A);
}

/*
 * File trailer for qrsolve.c
 *
 * [EOF]
 */
