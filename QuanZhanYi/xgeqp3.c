/*
 * File: xgeqp3.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 17-Oct-2024 10:45:45
 */

/* Include Files */
#include "xgeqp3.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *A
 *                double tau_data[]
 *                int jpvt[3]
 * Return Type  : int
 */
int xgeqp3(emxArray_real_T *A, double tau_data[], int jpvt[3])
{
  double vn1[3];
  double vn2[3];
  double work[3];
  double atmp;
  double d;
  double s;
  double smax;
  double *A_data;
  int b_i;
  int exitg1;
  int i;
  int ii;
  int ip1;
  int ix;
  int jA;
  int k;
  int knt;
  int lastc;
  int lastv;
  int m;
  int ma;
  int mmi;
  int pvt;
  int tau_size;
  boolean_T exitg2;
  A_data = A->data;
  m = A->size[0];
  tau_size = A->size[0];
  if (tau_size > 3) {
    tau_size = 3;
  }
  if (tau_size - 1 >= 0) {
    memset(&tau_data[0], 0, (unsigned int)tau_size * sizeof(double));
  }
  if ((A->size[0] == 0) || (tau_size < 1)) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  } else {
    ma = A->size[0];
    jpvt[0] = 1;
    work[0] = 0.0;
    d = b_xnrm2(m, A, 1);
    vn1[0] = d;
    vn2[0] = d;
    jpvt[1] = 2;
    work[1] = 0.0;
    d = b_xnrm2(m, A, ma + 1);
    vn1[1] = d;
    vn2[1] = d;
    jpvt[2] = 3;
    work[2] = 0.0;
    d = b_xnrm2(m, A, (ma << 1) + 1);
    vn1[2] = d;
    vn2[2] = d;
    for (i = 0; i < tau_size; i++) {
      ip1 = i + 2;
      lastc = i * ma;
      ii = lastc + i;
      mmi = m - i;
      ix = 3 - i;
      knt = 0;
      if (3 - i > 1) {
        smax = fabs(vn1[i]);
        for (k = 2; k <= ix; k++) {
          s = fabs(vn1[(i + k) - 1]);
          if (s > smax) {
            knt = k - 1;
            smax = s;
          }
        }
      }
      pvt = i + knt;
      if (pvt != i) {
        ix = pvt * ma;
        for (k = 0; k < m; k++) {
          knt = ix + k;
          smax = A_data[knt];
          b_i = lastc + k;
          A_data[knt] = A_data[b_i];
          A_data[b_i] = smax;
        }
        ix = jpvt[pvt];
        jpvt[pvt] = jpvt[i];
        jpvt[i] = ix;
        vn1[pvt] = vn1[i];
        vn2[pvt] = vn2[i];
      }
      if (i + 1 < m) {
        atmp = A_data[ii];
        ix = ii + 2;
        tau_data[i] = 0.0;
        if (mmi > 0) {
          smax = b_xnrm2(mmi - 1, A, ii + 2);
          if (smax != 0.0) {
            s = rt_hypotd_snf(A_data[ii], smax);
            if (A_data[ii] >= 0.0) {
              s = -s;
            }
            if (fabs(s) < 1.0020841800044864E-292) {
              knt = 0;
              b_i = ii + mmi;
              do {
                knt++;
                for (k = ix; k <= b_i; k++) {
                  A_data[k - 1] *= 9.9792015476736E+291;
                }
                s *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while ((fabs(s) < 1.0020841800044864E-292) && (knt < 20));
              s = rt_hypotd_snf(atmp, b_xnrm2(mmi - 1, A, ii + 2));
              if (atmp >= 0.0) {
                s = -s;
              }
              tau_data[i] = (s - atmp) / s;
              smax = 1.0 / (atmp - s);
              for (k = ix; k <= b_i; k++) {
                A_data[k - 1] *= smax;
              }
              for (k = 0; k < knt; k++) {
                s *= 1.0020841800044864E-292;
              }
              atmp = s;
            } else {
              tau_data[i] = (s - A_data[ii]) / s;
              smax = 1.0 / (A_data[ii] - s);
              b_i = ii + mmi;
              for (k = ix; k <= b_i; k++) {
                A_data[k - 1] *= smax;
              }
              atmp = s;
            }
          }
        }
        A_data[ii] = atmp;
      } else {
        tau_data[i] = 0.0;
      }
      if (i + 1 < 3) {
        atmp = A_data[ii];
        A_data[ii] = 1.0;
        jA = (ii + ma) + 1;
        if (tau_data[i] != 0.0) {
          lastv = mmi - 1;
          ix = (ii + mmi) - 1;
          while ((lastv + 1 > 0) && (A_data[ix] == 0.0)) {
            lastv--;
            ix--;
          }
          lastc = 1 - i;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            ix = jA + lastc * ma;
            k = ix;
            do {
              exitg1 = 0;
              if (k <= ix + lastv) {
                if (A_data[k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  k++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = -1;
        }
        if (lastv + 1 > 0) {
          if (lastc + 1 != 0) {
            memset(&work[0], 0, (unsigned int)(lastc + 1) * sizeof(double));
            knt = 0;
            b_i = jA + ma * lastc;
            for (pvt = jA; ma < 0 ? pvt >= b_i : pvt <= b_i; pvt += ma) {
              smax = 0.0;
              ix = pvt + lastv;
              for (k = pvt; k <= ix; k++) {
                smax += A_data[k - 1] * A_data[(ii + k) - pvt];
              }
              work[knt] += smax;
              knt++;
            }
          }
          if (!(-tau_data[i] == 0.0)) {
            for (pvt = 0; pvt <= lastc; pvt++) {
              d = work[pvt];
              if (d != 0.0) {
                smax = d * -tau_data[i];
                b_i = lastv + jA;
                for (knt = jA; knt <= b_i; knt++) {
                  A_data[knt - 1] += A_data[(ii + knt) - jA] * smax;
                }
              }
              jA += ma;
            }
          }
        }
        A_data[ii] = atmp;
      }
      for (pvt = ip1; pvt < 4; pvt++) {
        ix = i + (pvt - 1) * ma;
        d = vn1[pvt - 1];
        if (d != 0.0) {
          smax = fabs(A_data[ix]) / d;
          smax = 1.0 - smax * smax;
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[pvt - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if (i + 1 < m) {
              d = b_xnrm2(mmi - 1, A, ix + 2);
              vn1[pvt - 1] = d;
              vn2[pvt - 1] = d;
            } else {
              vn1[pvt - 1] = 0.0;
              vn2[pvt - 1] = 0.0;
            }
          } else {
            vn1[pvt - 1] = d * sqrt(smax);
          }
        }
      }
    }
  }
  return tau_size;
}

/*
 * File trailer for xgeqp3.c
 *
 * [EOF]
 */
