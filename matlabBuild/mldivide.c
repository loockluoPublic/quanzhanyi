/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

/* Include Files */
#include "mldivide.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static int div_nde_s32_floor(int numerator);

/* Function Definitions */
/*
 * Arguments    : int numerator
 * Return Type  : int
 */
static int div_nde_s32_floor(int numerator)
{
  int i;
  if ((numerator < 0) && (numerator % 3 != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / 3 + i;
}

/*
 * Arguments    : const double A[9]
 *                const double B[3]
 *                double Y[3]
 * Return Type  : void
 */
void b_mldivide(const double A[9], const double B[3], double Y[3])
{
  double b_A[9];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  int rtemp;
  memcpy(&b_A[0], &A[0], 9U * sizeof(double));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(A[0]);
  a21 = fabs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (fabs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  b_A[r2] = A[r2] / A[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (fabs(b_A[r3 + 3]) > fabs(b_A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  Y[1] = B[r2] - B[r1] * b_A[r2];
  Y[2] = (B[r3] - B[r1] * b_A[r3]) - Y[1] * b_A[r3 + 3];
  Y[2] /= b_A[r3 + 6];
  Y[0] = B[r1] - Y[2] * b_A[r1 + 6];
  Y[1] -= Y[2] * b_A[r2 + 6];
  Y[1] /= b_A[r2 + 3];
  Y[0] -= Y[1] * b_A[r1 + 3];
  Y[0] /= b_A[r1];
}

/*
 * Arguments    : const double A[6]
 *                const double B[2]
 *                double Y[3]
 * Return Type  : void
 */
void c_mldivide(const double A[6], const double B[2], double Y[3])
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
  int exitg1;
  int i;
  int i1;
  int ii;
  int ip1;
  int j;
  int k;
  int kend;
  int lastc;
  int lastv;
  int pvt;
  int rankA;
  signed char jpvt[3];
  boolean_T exitg2;
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
      smax = h_xnrm2(b_A, ii + 2);
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
          scale = rt_hypotd_snf(t, h_xnrm2(b_A, ii + 2));
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
      lastv = 2 - b_i;
      kend = (ii - b_i) + 1;
      while ((lastv > 0) && (b_A[kend] == 0.0)) {
        lastv--;
        kend--;
      }
      lastc = 1 - b_i;
      exitg2 = false;
      while ((!exitg2) && (lastc + 1 > 0)) {
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
      if (lastc + 1 != 0) {
        memset(&work[0], 0, (unsigned int)(lastc + 1) * sizeof(double));
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
            absxk = h_xnrm2(b_A, pvt + 2);
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
 * Arguments    : const double A[6]
 *                const double B[3]
 *                double Y[2]
 * Return Type  : void
 */
void d_mldivide(const double A[6], const double B[3], double Y[2])
{
  double b_A[6];
  double b_B[3];
  double tau[2];
  double vn1[2];
  double vn2[2];
  double work[2];
  double absxk;
  double scale;
  double t;
  double temp;
  int b_i;
  int exitg1;
  int i;
  int ii;
  int ip1;
  int ix0;
  int iy;
  int kend;
  int lastc;
  int lastv;
  int pvt;
  signed char jpvt[2];
  for (i = 0; i < 6; i++) {
    b_A[i] = A[i];
  }
  for (pvt = 0; pvt < 2; pvt++) {
    jpvt[pvt] = (signed char)(pvt + 1);
    tau[pvt] = 0.0;
    work[pvt] = 0.0;
    ix0 = pvt * 3;
    temp = 0.0;
    scale = 3.3121686421112381E-170;
    kend = ix0 + 3;
    for (iy = ix0 + 1; iy <= kend; iy++) {
      absxk = fabs(A[iy - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        temp = temp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        temp += t * t;
      }
    }
    temp = scale * sqrt(temp);
    vn1[pvt] = temp;
    vn2[pvt] = temp;
  }
  for (b_i = 0; b_i < 2; b_i++) {
    ip1 = b_i + 2;
    ii = b_i * 3 + b_i;
    kend = 0;
    if ((2 - b_i > 1) && (fabs(vn1[b_i + 1]) > fabs(vn1[b_i]))) {
      kend = 1;
    }
    pvt = b_i + kend;
    if (pvt != b_i) {
      kend = pvt * 3;
      iy = b_i * 3;
      temp = b_A[kend];
      b_A[kend] = b_A[iy];
      b_A[iy] = temp;
      temp = b_A[kend + 1];
      b_A[kend + 1] = b_A[iy + 1];
      b_A[iy + 1] = temp;
      temp = b_A[kend + 2];
      b_A[kend + 2] = b_A[iy + 2];
      b_A[iy + 2] = temp;
      kend = jpvt[pvt];
      jpvt[pvt] = jpvt[b_i];
      jpvt[b_i] = (signed char)kend;
      vn1[pvt] = vn1[b_i];
      vn2[pvt] = vn2[b_i];
    }
    absxk = b_A[ii];
    ix0 = ii + 2;
    tau[b_i] = 0.0;
    temp = d_xnrm2(2 - b_i, b_A, ii + 2);
    if (temp != 0.0) {
      scale = rt_hypotd_snf(b_A[ii], temp);
      if (b_A[ii] >= 0.0) {
        scale = -scale;
      }
      if (fabs(scale) < 1.0020841800044864E-292) {
        kend = 0;
        i = (ii - b_i) + 3;
        do {
          kend++;
          for (pvt = ix0; pvt <= i; pvt++) {
            b_A[pvt - 1] *= 9.9792015476736E+291;
          }
          scale *= 9.9792015476736E+291;
          absxk *= 9.9792015476736E+291;
        } while ((fabs(scale) < 1.0020841800044864E-292) && (kend < 20));
        scale = rt_hypotd_snf(absxk, d_xnrm2(2 - b_i, b_A, ii + 2));
        if (absxk >= 0.0) {
          scale = -scale;
        }
        tau[b_i] = (scale - absxk) / scale;
        temp = 1.0 / (absxk - scale);
        for (pvt = ix0; pvt <= i; pvt++) {
          b_A[pvt - 1] *= temp;
        }
        for (pvt = 0; pvt < kend; pvt++) {
          scale *= 1.0020841800044864E-292;
        }
        absxk = scale;
      } else {
        tau[b_i] = (scale - b_A[ii]) / scale;
        temp = 1.0 / (b_A[ii] - scale);
        i = (ii - b_i) + 3;
        for (pvt = ix0; pvt <= i; pvt++) {
          b_A[pvt - 1] *= temp;
        }
        absxk = scale;
      }
    }
    b_A[ii] = absxk;
    if (b_i + 1 < 2) {
      b_A[ii] = 1.0;
      pvt = ii + 4;
      if (tau[0] != 0.0) {
        lastv = 3;
        kend = ii + 2;
        while ((lastv > 0) && (b_A[kend] == 0.0)) {
          lastv--;
          kend--;
        }
        lastc = 1;
        kend = ii + 3;
        do {
          exitg1 = 0;
          if (kend + 1 <= (ii + lastv) + 3) {
            if (b_A[kend] != 0.0) {
              exitg1 = 1;
            } else {
              kend++;
            }
          } else {
            lastc = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        if (lastc != 0) {
          work[0] = 0.0;
          for (iy = pvt; iy <= pvt; iy += 3) {
            temp = 0.0;
            i = (iy + lastv) - 1;
            for (kend = iy; kend <= i; kend++) {
              temp += b_A[kend - 1] * b_A[(ii + kend) - iy];
            }
            kend = div_nde_s32_floor((iy - ii) - 4);
            work[kend] += temp;
          }
        }
        if (!(-tau[0] == 0.0)) {
          kend = ii;
          for (ix0 = 0; ix0 < lastc; ix0++) {
            if (work[0] != 0.0) {
              temp = work[0] * -tau[0];
              i = kend + 4;
              iy = lastv + kend;
              for (pvt = i; pvt <= iy + 3; pvt++) {
                b_A[pvt - 1] += b_A[((ii + pvt) - kend) - 4] * temp;
              }
            }
            kend += 3;
          }
        }
      }
      b_A[ii] = absxk;
    }
    for (ix0 = ip1; ix0 < 3; ix0++) {
      if (vn1[1] != 0.0) {
        temp = fabs(b_A[b_i + 3]) / vn1[1];
        temp = 1.0 - temp * temp;
        if (temp < 0.0) {
          temp = 0.0;
        }
        scale = vn1[1] / vn2[1];
        scale = temp * (scale * scale);
        if (scale <= 1.4901161193847656E-8) {
          temp = d_xnrm2(2 - b_i, b_A, b_i + 5);
          vn1[1] = temp;
          vn2[1] = temp;
        } else {
          vn1[1] *= sqrt(temp);
        }
      }
    }
  }
  pvt = 0;
  temp = 6.6613381477509392E-15 * fabs(b_A[0]);
  while ((pvt < 2) && (!(fabs(b_A[pvt + 3 * pvt]) <= temp))) {
    pvt++;
  }
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  for (ix0 = 0; ix0 < 2; ix0++) {
    Y[ix0] = 0.0;
    if (tau[ix0] != 0.0) {
      temp = b_B[ix0];
      i = ix0 + 2;
      for (b_i = i; b_i < 4; b_i++) {
        temp += b_A[(b_i + 3 * ix0) - 1] * b_B[b_i - 1];
      }
      temp *= tau[ix0];
      if (temp != 0.0) {
        b_B[ix0] -= temp;
        for (b_i = i; b_i < 4; b_i++) {
          b_B[b_i - 1] -= b_A[(b_i + 3 * ix0) - 1] * temp;
        }
      }
    }
  }
  for (b_i = 0; b_i < pvt; b_i++) {
    Y[jpvt[b_i] - 1] = b_B[b_i];
  }
  for (ix0 = pvt; ix0 >= 1; ix0--) {
    kend = jpvt[ix0 - 1] - 1;
    iy = 3 * (ix0 - 1);
    Y[kend] /= b_A[(ix0 + iy) - 1];
    for (b_i = 0; b_i <= ix0 - 2; b_i++) {
      Y[jpvt[0] - 1] -= Y[kend] * b_A[iy];
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
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  double b_A_data[9];
  double tau_data[3];
  const double *A_data;
  const double *B_data;
  double a21;
  double tol;
  double *b_B_data;
  double *c_A_data;
  int jpvt[3];
  int b_i;
  int i;
  int maxmn;
  int minmn;
  int rankA;
  int rtemp;
  B_data = B->data;
  A_data = A->data;
  emxInit_real_T(&b_A, 2);
  emxInit_real_T(&b_B, 1);
  if ((A->size[0] == 0) || (B->size[0] == 0)) {
    Y[0] = 0.0;
    Y[1] = 0.0;
    Y[2] = 0.0;
  } else if (A->size[0] == 3) {
    for (i = 0; i < 9; i++) {
      b_A_data[i] = A_data[i];
    }
    minmn = 0;
    maxmn = 1;
    rankA = 2;
    tol = fabs(A_data[0]);
    a21 = fabs(A_data[1]);
    if (a21 > tol) {
      tol = a21;
      minmn = 1;
      maxmn = 0;
    }
    if (fabs(A_data[2]) > tol) {
      minmn = 2;
      maxmn = 1;
      rankA = 0;
    }
    b_A_data[maxmn] = A_data[maxmn] / A_data[minmn];
    b_A_data[rankA] /= b_A_data[minmn];
    b_A_data[maxmn + 3] -= b_A_data[maxmn] * b_A_data[minmn + 3];
    b_A_data[rankA + 3] -= b_A_data[rankA] * b_A_data[minmn + 3];
    b_A_data[maxmn + 6] -= b_A_data[maxmn] * b_A_data[minmn + 6];
    b_A_data[rankA + 6] -= b_A_data[rankA] * b_A_data[minmn + 6];
    if (fabs(b_A_data[rankA + 3]) > fabs(b_A_data[maxmn + 3])) {
      rtemp = maxmn;
      maxmn = rankA;
      rankA = rtemp;
    }
    b_A_data[rankA + 3] /= b_A_data[maxmn + 3];
    b_A_data[rankA + 6] -= b_A_data[rankA + 3] * b_A_data[maxmn + 6];
    Y[1] = B_data[maxmn] - B_data[minmn] * b_A_data[maxmn];
    Y[2] = (B_data[rankA] - B_data[minmn] * b_A_data[rankA]) -
           Y[1] * b_A_data[rankA + 3];
    Y[2] /= b_A_data[rankA + 6];
    Y[0] = B_data[minmn] - Y[2] * b_A_data[minmn + 6];
    Y[1] -= Y[2] * b_A_data[maxmn + 6];
    Y[1] /= b_A_data[maxmn + 3];
    Y[0] -= Y[1] * b_A_data[minmn + 3];
    Y[0] /= b_A_data[minmn];
  } else {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = 3;
    emxEnsureCapacity_real_T(b_A, i);
    c_A_data = b_A->data;
    minmn = A->size[0] * 3;
    for (i = 0; i < minmn; i++) {
      c_A_data[i] = A_data[i];
    }
    xgeqp3(b_A, tau_data, jpvt);
    c_A_data = b_A->data;
    rankA = 0;
    if (b_A->size[0] < 3) {
      minmn = b_A->size[0];
      maxmn = 3;
    } else {
      minmn = 3;
      maxmn = b_A->size[0];
    }
    if (minmn > 0) {
      tol = 2.2204460492503131E-15 * (double)maxmn;
      if (tol >= 1.4901161193847656E-8) {
        tol = 1.4901161193847656E-8;
      }
      tol *= fabs(c_A_data[0]);
      while ((rankA < minmn) &&
             (!(fabs(c_A_data[rankA + b_A->size[0] * rankA]) <= tol))) {
        rankA++;
      }
    }
    i = b_B->size[0];
    b_B->size[0] = B->size[0];
    emxEnsureCapacity_real_T(b_B, i);
    b_B_data = b_B->data;
    minmn = B->size[0];
    for (i = 0; i < minmn; i++) {
      b_B_data[i] = B_data[i];
    }
    Y[0] = 0.0;
    Y[1] = 0.0;
    Y[2] = 0.0;
    minmn = b_A->size[0];
    maxmn = b_A->size[0];
    if (maxmn > 3) {
      maxmn = 3;
    }
    for (rtemp = 0; rtemp < maxmn; rtemp++) {
      if (tau_data[rtemp] != 0.0) {
        tol = b_B_data[rtemp];
        i = rtemp + 2;
        for (b_i = i; b_i <= minmn; b_i++) {
          tol += c_A_data[(b_i + b_A->size[0] * rtemp) - 1] * b_B_data[b_i - 1];
        }
        tol *= tau_data[rtemp];
        if (tol != 0.0) {
          b_B_data[rtemp] -= tol;
          for (b_i = i; b_i <= minmn; b_i++) {
            b_B_data[b_i - 1] -=
                c_A_data[(b_i + b_A->size[0] * rtemp) - 1] * tol;
          }
        }
      }
    }
    for (b_i = 0; b_i < rankA; b_i++) {
      Y[jpvt[b_i] - 1] = b_B_data[b_i];
    }
    for (rtemp = rankA; rtemp >= 1; rtemp--) {
      minmn = jpvt[rtemp - 1] - 1;
      Y[minmn] /= c_A_data[(rtemp + b_A->size[0] * (rtemp - 1)) - 1];
      for (b_i = 0; b_i <= rtemp - 2; b_i++) {
        i = jpvt[b_i];
        Y[i - 1] -= Y[minmn] * c_A_data[b_i + b_A->size[0] * (rtemp - 1)];
      }
    }
  }
  emxFree_real_T(&b_B);
  emxFree_real_T(&b_A);
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
