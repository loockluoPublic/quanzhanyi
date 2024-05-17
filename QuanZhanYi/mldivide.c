/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 17-May-2024 11:16:59
 */

/* Include Files */
#include "mldivide.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[6]
 *                const double B[2]
 *                double Y[3]
 * Return Type  : void
 */
void b_mldivide(const double A[6], const double B[2], double Y[3])
{
  double b_A[6];
  double vn1[3];
  double vn2[3];
  double work[3];
  double b_B[2];
  double tau[2];
  double absxk;
  double scale;
  double smax;
  double t;
  int b_i;
  int i;
  int j;
  int k;
  int kend;
  int pvt;
  int rankA;
  signed char jpvt[3];
  for (i = 0; i < 6; i++) {
    b_A[i] = A[i];
  }
  jpvt[0] = 1;
  jpvt[1] = 2;
  jpvt[2] = 3;
  tau[0] = 0.0;
  tau[1] = 0.0;
  for (j = 0; j < 3; j++) {
    work[j] = 0.0;
    pvt = j << 1;
    smax = 0.0;
    scale = 3.3121686421112381E-170;
    kend = pvt + 2;
    for (k = pvt + 1; k <= kend; k++) {
      absxk = fabs(A[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        smax = smax * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        smax += t * t;
      }
    }
    absxk = scale * sqrt(smax);
    vn1[j] = absxk;
    vn2[j] = absxk;
  }
  for (b_i = 0; b_i < 2; b_i++) {
    int ii;
    int ip1;
    int lastc;
    int lastv;
    ip1 = b_i + 2;
    rankA = b_i << 1;
    ii = rankA + b_i;
    kend = 3 - b_i;
    pvt = 0;
    smax = fabs(vn1[b_i]);
    for (k = 2; k <= kend; k++) {
      scale = fabs(vn1[(b_i + k) - 1]);
      if (scale > smax) {
        pvt = k - 1;
        smax = scale;
      }
    }
    pvt += b_i;
    if (pvt != b_i) {
      kend = pvt << 1;
      smax = b_A[kend];
      b_A[kend] = b_A[rankA];
      b_A[rankA] = smax;
      smax = b_A[kend + 1];
      b_A[kend + 1] = b_A[rankA + 1];
      b_A[rankA + 1] = smax;
      kend = jpvt[pvt];
      jpvt[pvt] = jpvt[b_i];
      jpvt[b_i] = (signed char)kend;
      vn1[pvt] = vn1[b_i];
      vn2[pvt] = vn2[b_i];
    }
    if (b_i + 1 < 2) {
      t = b_A[ii];
      kend = ii + 2;
      tau[0] = 0.0;
      smax = f_xnrm2(b_A, ii + 2);
      if (smax != 0.0) {
        scale = rt_hypotd_snf(b_A[ii], smax);
        if (b_A[ii] >= 0.0) {
          scale = -scale;
        }
        if (fabs(scale) < 1.0020841800044864E-292) {
          pvt = 0;
          do {
            pvt++;
            for (k = kend; k <= kend; k++) {
              b_A[k - 1] *= 9.9792015476736E+291;
            }
            scale *= 9.9792015476736E+291;
            t *= 9.9792015476736E+291;
          } while ((fabs(scale) < 1.0020841800044864E-292) && (pvt < 20));
          scale = rt_hypotd_snf(t, f_xnrm2(b_A, ii + 2));
          if (t >= 0.0) {
            scale = -scale;
          }
          tau[0] = (scale - t) / scale;
          smax = 1.0 / (t - scale);
          for (k = kend; k <= kend; k++) {
            b_A[k - 1] *= smax;
          }
          for (k = 0; k < pvt; k++) {
            scale *= 1.0020841800044864E-292;
          }
          t = scale;
        } else {
          tau[0] = (scale - b_A[ii]) / scale;
          smax = 1.0 / (b_A[ii] - scale);
          for (k = kend; k <= kend; k++) {
            b_A[k - 1] *= smax;
          }
          t = scale;
        }
      }
      b_A[ii] = t;
    } else {
      tau[1] = 0.0;
    }
    t = b_A[ii];
    b_A[ii] = 1.0;
    k = ii + 3;
    if (tau[b_i] != 0.0) {
      boolean_T exitg2;
      lastv = 2 - b_i;
      kend = (ii - b_i) + 1;
      while ((lastv > 0) && (b_A[kend] == 0.0)) {
        lastv--;
        kend--;
      }
      lastc = 1 - b_i;
      exitg2 = false;
      while ((!exitg2) && (lastc + 1 > 0)) {
        int exitg1;
        kend = (ii + (lastc << 1)) + 2;
        rankA = kend;
        do {
          exitg1 = 0;
          if (rankA + 1 <= kend + lastv) {
            if (b_A[rankA] != 0.0) {
              exitg1 = 1;
            } else {
              rankA++;
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
      lastv = 0;
      lastc = -1;
    }
    if (lastv > 0) {
      int i1;
      if (lastc + 1 != 0) {
        memset(&work[0], 0, (lastc + 1) * sizeof(double));
        i = (ii + (lastc << 1)) + 3;
        for (pvt = k; pvt <= i; pvt += 2) {
          smax = 0.0;
          i1 = (pvt + lastv) - 1;
          for (rankA = pvt; rankA <= i1; rankA++) {
            smax += b_A[rankA - 1] * b_A[(ii + rankA) - pvt];
          }
          kend = ((pvt - ii) - 3) >> 1;
          work[kend] += smax;
        }
      }
      if (!(-tau[b_i] == 0.0)) {
        kend = ii;
        for (j = 0; j <= lastc; j++) {
          absxk = work[j];
          if (absxk != 0.0) {
            smax = absxk * -tau[b_i];
            i = kend + 3;
            i1 = lastv + kend;
            for (rankA = i; rankA <= i1 + 2; rankA++) {
              b_A[rankA - 1] += b_A[((ii + rankA) - kend) - 3] * smax;
            }
          }
          kend += 2;
        }
      }
    }
    b_A[ii] = t;
    for (j = ip1; j < 4; j++) {
      pvt = b_i + ((j - 1) << 1);
      absxk = vn1[j - 1];
      if (absxk != 0.0) {
        smax = fabs(b_A[pvt]) / absxk;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }
        scale = absxk / vn2[j - 1];
        scale = smax * (scale * scale);
        if (scale <= 1.4901161193847656E-8) {
          if (b_i + 1 < 2) {
            absxk = f_xnrm2(b_A, pvt + 2);
            vn1[j - 1] = absxk;
            vn2[j - 1] = absxk;
          } else {
            vn1[j - 1] = 0.0;
            vn2[j - 1] = 0.0;
          }
        } else {
          vn1[j - 1] = absxk * sqrt(smax);
        }
      }
    }
  }
  rankA = 0;
  smax = 6.6613381477509392E-15 * fabs(b_A[0]);
  while ((rankA < 2) && (!(fabs(b_A[rankA + (rankA << 1)]) <= smax))) {
    rankA++;
  }
  b_B[0] = B[0];
  b_B[1] = B[1];
  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  for (j = 0; j < 2; j++) {
    if (tau[j] != 0.0) {
      smax = b_B[j];
      i = j + 2;
      for (b_i = i; b_i < 3; b_i++) {
        smax += b_A[(j << 1) + 1] * b_B[1];
      }
      smax *= tau[j];
      if (smax != 0.0) {
        b_B[j] -= smax;
        for (b_i = i; b_i < 3; b_i++) {
          b_B[1] -= b_A[(j << 1) + 1] * smax;
        }
      }
    }
  }
  for (b_i = 0; b_i < rankA; b_i++) {
    Y[jpvt[b_i] - 1] = b_B[b_i];
  }
  for (j = rankA; j >= 1; j--) {
    kend = jpvt[j - 1] - 1;
    pvt = (j - 1) << 1;
    Y[kend] /= b_A[(j + pvt) - 1];
    for (b_i = 0; b_i <= j - 2; b_i++) {
      Y[jpvt[0] - 1] -= Y[kend] * b_A[pvt];
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double Y[3]
 * Return Type  : void
 */
void mldivide(const emxArray_real_T *A, const emxArray_real_T *B, double Y[3])
{
  const double *A_data;
  const double *B_data;
  int r1;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (B->size[0] == 0)) {
    Y[0] = 0.0;
    Y[1] = 0.0;
    Y[2] = 0.0;
  } else if (A->size[0] == 3) {
    double b_A_data[9];
    double a21;
    double maxval;
    int r2;
    int r3;
    for (r1 = 0; r1 < 9; r1++) {
      b_A_data[r1] = A_data[r1];
    }
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = fabs(A_data[0]);
    a21 = fabs(A_data[1]);
    if (a21 > maxval) {
      maxval = a21;
      r1 = 1;
      r2 = 0;
    }
    if (fabs(A_data[2]) > maxval) {
      r1 = 2;
      r2 = 1;
      r3 = 0;
    }
    b_A_data[r2] = A_data[r2] / A_data[r1];
    b_A_data[r3] /= b_A_data[r1];
    b_A_data[r2 + 3] -= b_A_data[r2] * b_A_data[r1 + 3];
    b_A_data[r3 + 3] -= b_A_data[r3] * b_A_data[r1 + 3];
    b_A_data[r2 + 6] -= b_A_data[r2] * b_A_data[r1 + 6];
    b_A_data[r3 + 6] -= b_A_data[r3] * b_A_data[r1 + 6];
    if (fabs(b_A_data[r3 + 3]) > fabs(b_A_data[r2 + 3])) {
      int rtemp;
      rtemp = r2;
      r2 = r3;
      r3 = rtemp;
    }
    b_A_data[r3 + 3] /= b_A_data[r2 + 3];
    b_A_data[r3 + 6] -= b_A_data[r3 + 3] * b_A_data[r2 + 6];
    Y[1] = B_data[r2] - B_data[r1] * b_A_data[r2];
    Y[2] = (B_data[r3] - B_data[r1] * b_A_data[r3]) - Y[1] * b_A_data[r3 + 3];
    Y[2] /= b_A_data[r3 + 6];
    Y[0] = B_data[r1] - Y[2] * b_A_data[r1 + 6];
    Y[1] -= Y[2] * b_A_data[r2 + 6];
    Y[1] /= b_A_data[r2 + 3];
    Y[0] -= Y[1] * b_A_data[r1 + 3];
    Y[0] /= b_A_data[r1];
  } else {
    qrsolve(A, B, Y);
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
