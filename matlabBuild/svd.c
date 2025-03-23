/*
 * File: svd.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

/* Include Files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[8]
 *                double U[4]
 *                double s[2]
 *                double V[16]
 * Return Type  : void
 */
void d_svd(const double A[8], double U[4], double s[2], double V[16])
{
  double b_A[8];
  double e[4];
  double b_s[3];
  double work[2];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int ii;
  int jj;
  int k;
  int m;
  int q;
  int qp1;
  int qp1jj;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  memcpy(&b_A[0], &A[0], 8U * sizeof(double));
  b_s[0] = 0.0;
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  e[3] = 0.0;
  work[0] = 0.0;
  U[0] = 0.0;
  U[1] = 0.0;
  memset(&V[0], 0, 16U * sizeof(double));
  for (q = 0; q < 2; q++) {
    qp1 = q + 2;
    qp1jj = q + (q << 1);
    qq = qp1jj + 1;
    apply_transform = false;
    if (q + 1 <= 1) {
      nrm = g_xnrm2(b_A, qp1jj + 1);
      if (nrm > 0.0) {
        apply_transform = true;
        if (b_A[qp1jj] < 0.0) {
          ztest = -nrm;
        } else {
          ztest = nrm;
        }
        if (fabs(ztest) >= 1.0020841800044864E-292) {
          nrm = 1.0 / ztest;
          jj = qp1jj + 2;
          for (k = qq; k <= jj; k++) {
            b_A[k - 1] *= nrm;
          }
        } else {
          jj = qp1jj + 2;
          for (k = qq; k <= jj; k++) {
            b_A[k - 1] /= ztest;
          }
        }
        b_A[qp1jj]++;
        b_s[0] = -ztest;
      } else {
        b_s[0] = 0.0;
      }
    }
    for (jj = qp1; jj < 5; jj++) {
      qq = q + ((jj - 1) << 1);
      if (apply_transform) {
        e_xaxpy(2 - q,
                -(c_xdotc(2 - q, b_A, qp1jj + 1, b_A, qq + 1) / b_A[qp1jj]),
                qp1jj + 1, b_A, qq + 1);
      }
      e[jj - 1] = b_A[qq];
    }
    if (q + 1 <= 1) {
      U[0] = b_A[0];
      U[1] = b_A[1];
    }
    nrm = c_xnrm2(3 - q, e, q + 2);
    if (nrm == 0.0) {
      e[q] = 0.0;
    } else {
      if (e[q + 1] < 0.0) {
        e[q] = -nrm;
      } else {
        e[q] = nrm;
      }
      nrm = e[q];
      if (fabs(e[q]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / e[q];
        for (k = qp1; k < 5; k++) {
          e[k - 1] *= nrm;
        }
      } else {
        for (k = qp1; k < 5; k++) {
          e[k - 1] /= nrm;
        }
      }
      e[q + 1]++;
      e[q] = -e[q];
      if (q + 2 <= 2) {
        work[1] = 0.0;
        g_xaxpy(1 - q, e[1], b_A, 4, work);
        g_xaxpy(1 - q, e[2], b_A, 6, work);
        g_xaxpy(1 - q, e[3], b_A, 8, work);
        h_xaxpy(1 - q, -e[1] / e[1], work, b_A, 4);
        h_xaxpy(1 - q, -e[2] / e[1], work, b_A, 6);
        h_xaxpy(1 - q, -e[3] / e[1], work, b_A, 8);
      }
    }
    for (ii = qp1; ii < 5; ii++) {
      V[(ii + (q << 2)) - 1] = e[ii - 1];
    }
  }
  m = 1;
  b_s[1] = b_A[3];
  b_s[2] = 0.0;
  e[2] = 0.0;
  U[2] = 0.0;
  U[3] = 1.0;
  if (b_s[0] != 0.0) {
    f_xaxpy(-(d_xdotc(U, U) / U[0]), U);
    U[0] = -U[0];
    U[1] = -U[1];
    U[0]++;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }
  for (q = 3; q >= 0; q--) {
    if ((q + 1 <= 2) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qq = (q + (q << 2)) + 2;
      for (jj = qp1; jj < 5; jj++) {
        qp1jj = (q + ((jj - 1) << 2)) + 2;
        d_xaxpy(3 - q, -(b_xdotc(3 - q, V, qq, V, qp1jj) / V[qq - 1]), qq, V,
                qp1jj);
      }
    }
    qq = q << 2;
    V[qq] = 0.0;
    V[qq + 1] = 0.0;
    V[qq + 2] = 0.0;
    V[qq + 3] = 0.0;
    V[q + qq] = 1.0;
  }
  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
      b_s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }
      if (q + 1 <= 2) {
        qq = q << 1;
        jj = qq + 2;
        for (k = qq + 1; k <= jj; k++) {
          U[k - 1] *= nrm;
        }
      }
    }
    if (q + 1 < 3) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        qq = (q + 1) << 2;
        jj = qq + 4;
        for (k = qq + 1; k <= jj; k++) {
          V[k - 1] *= nrm;
        }
      }
    }
    nrm = fabs(b_s[q]);
    ztest = fabs(e[q]);
    if ((nrm >= ztest) || rtIsNaN(ztest)) {
      ztest = nrm;
    }
    if ((!(snorm >= ztest)) && (!rtIsNaN(ztest))) {
      snorm = ztest;
    }
  }
  while ((m + 2 > 0) && (qp1 < 75)) {
    jj = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[ii - 1]);
      if ((nrm <=
           2.2204460492503131E-16 * (fabs(b_s[ii - 1]) + fabs(b_s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      qq = 4;
    } else {
      qp1jj = m + 2;
      qq = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qq >= ii)) {
        qp1jj = qq;
        if (qq == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (qq < m + 2) {
            nrm = fabs(e[qq - 1]);
          }
          if (qq > ii + 1) {
            nrm += fabs(e[qq - 2]);
          }
          ztest = fabs(b_s[qq - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) ||
              (ztest <= 1.0020841800044864E-292)) {
            b_s[qq - 1] = 0.0;
            exitg1 = true;
          } else {
            qq--;
          }
        }
      }
      if (qp1jj == ii) {
        qq = 3;
      } else if (qp1jj == m + 2) {
        qq = 1;
      } else {
        qq = 2;
        ii = qp1jj;
      }
    }
    switch (qq) {
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      for (k = jj; k >= ii + 1; k--) {
        sm = xrotg(&b_s[k - 1], &ztest, &sqds);
        if (k > ii + 1) {
          ztest = -sqds * e[0];
          e[0] *= sm;
        }
        b_xrot(V, ((k - 1) << 2) + 1, ((m + 1) << 2) + 1, sm, sqds);
      }
      break;
    case 2:
      ztest = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        sm = xrotg(&b_s[k - 1], &ztest, &sqds);
        rt = e[k - 1];
        ztest = -sqds * rt;
        e[k - 1] = rt * sm;
        c_xrot(U, ((k - 1) << 1) + 1, ((ii - 1) << 1) + 1, sm, sqds);
      }
      break;
    case 3:
      nrm = b_s[m + 1];
      scale = fabs(nrm);
      ztest = fabs(b_s[m]);
      if ((!(scale >= ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[m]);
      if ((!(scale >= ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(b_s[ii]);
      if ((!(scale >= ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[ii]);
      if ((!(scale >= ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      ztest = e[m] / scale;
      sqds = b_s[ii] / scale;
      rt = ((nrm + sm) * (nrm - sm) + ztest * ztest) / 2.0;
      nrm = sm * ztest;
      nrm *= nrm;
      if ((rt != 0.0) || (nrm != 0.0)) {
        ztest = sqrt(rt * rt + nrm);
        if (rt < 0.0) {
          ztest = -ztest;
        }
        ztest = nrm / (rt + ztest);
      } else {
        ztest = 0.0;
      }
      ztest += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= jj; k++) {
        sm = xrotg(&ztest, &nrm, &sqds);
        if (k > ii + 1) {
          e[0] = ztest;
        }
        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        b_xrot(V, ((k - 1) << 2) + 1, (k << 2) + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        sm = xrotg(&b_s[k - 1], &ztest, &sqds);
        rt = e[k - 1];
        ztest = sm * rt + sqds * b_s[k];
        b_s[k] = -sqds * rt + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        if (k < 2) {
          c_xrot(U, 1, 3, sm, sqds);
        }
      }
      e[m] = ztest;
      qp1++;
      break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        qq = ii << 2;
        jj = qq + 4;
        for (k = qq + 1; k <= jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        b_xswap(V, (ii << 2) + 1, ((ii + 1) << 2) + 1);
        if (ii + 1 < 2) {
          c_xswap(U);
        }
        ii = qp1;
        qp1++;
      }
      qp1 = 0;
      m--;
      break;
    }
  }
  s[0] = b_s[0];
  s[1] = b_s[1];
}

/*
 * Arguments    : const double A[9]
 *                double U[9]
 *                double s[3]
 *                double V[9]
 * Return Type  : void
 */
void svd(const double A[9], double U[9], double s[3], double V[9])
{
  double Vf[9];
  double b_A[9];
  double b_s[3];
  double e[3];
  double work[3];
  double b;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  int ii;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  int qq_tmp;
  boolean_T apply_transform;
  boolean_T exitg1;
  b_s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (qjj = 0; qjj < 9; qjj++) {
    b_A[qjj] = A[qjj];
    U[qjj] = 0.0;
    Vf[qjj] = 0.0;
  }
  for (q = 0; q < 2; q++) {
    qp1 = q + 2;
    qq_tmp = q + 3 * q;
    qq = qq_tmp + 1;
    apply_transform = false;
    nrm = xnrm2(3 - q, b_A, qq_tmp + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq_tmp] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qq_tmp - q) + 3;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq_tmp - q) + 3;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }
      b_A[qq_tmp]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + 3 * (kase - 1);
      if (apply_transform) {
        xaxpy(3 - q,
              -(xdotc(3 - q, b_A, qq_tmp + 1, b_A, qjj + 1) / b_A[qq_tmp]),
              qq_tmp + 1, b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      kase = (ii + 3 * q) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 1) {
      nrm = f_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (k = qp1; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          i_xaxpy(e[kase - 1], b_A, 3 * (kase - 1) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          j_xaxpy(-e[kase - 1] / e[1], work, b_A, 3 * (kase - 1) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        Vf[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  b_s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (b_s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + 3 * (kase - 1)) + 1;
        xaxpy(3 - q, -(xdotc(3 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }
      for (ii = q + 1; ii < 4; ii++) {
        kase = (ii + 3 * q) - 1;
        U[kase] = -U[kase];
      }
      U[qq]++;
      if (q - 1 >= 0) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      xaxpy(2, -(xdotc(2, Vf, 2, Vf, 5) / Vf[1]), 2, Vf, 5);
      xaxpy(2, -(xdotc(2, Vf, 2, Vf, 8) / Vf[1]), 2, Vf, 8);
    }
    Vf[3 * q] = 0.0;
    Vf[3 * q + 1] = 0.0;
    Vf[3 * q + 2] = 0.0;
    Vf[q + 3 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    nrm = b_s[q];
    if (nrm != 0.0) {
      rt = fabs(nrm);
      nrm /= rt;
      b_s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }
      kase = 3 * q;
      qjj = kase + 3;
      for (k = kase + 1; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 3) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }
    nrm = fabs(b_s[q]);
    rt = fabs(e[q]);
    if ((nrm >= rt) || rtIsNaN(rt)) {
      rt = nrm;
    }
    if ((!(snorm >= rt)) && (!rtIsNaN(rt))) {
      snorm = rt;
    }
  }
  while ((m + 2 > 0) && (qq < 75)) {
    qq_tmp = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[ii - 1]);
      if ((nrm <=
           2.2204460492503131E-16 * (fabs(b_s[ii - 1]) + fabs(b_s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= ii)) {
        qjj = kase;
        if (kase == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }
          if (kase > ii + 1) {
            nrm += fabs(e[kase - 2]);
          }
          rt = fabs(b_s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == ii) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        ii = qjj;
      }
    }
    switch (kase) {
    case 1:
      rt = e[m];
      e[m] = 0.0;
      for (k = qq_tmp; k >= ii + 1; k--) {
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        if (k > ii + 1) {
          rt = -sqds * e[0];
          e[0] *= sm;
        }
        xrot(Vf, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2:
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sm, sqds);
      }
      break;
    case 3:
      nrm = b_s[m + 1];
      scale = fabs(nrm);
      rt = fabs(b_s[m]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(e[m]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(b_s[ii]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(e[ii]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      rt = e[m] / scale;
      sqds = b_s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= qq_tmp; k++) {
        sm = xrotg(&rt, &nrm, &sqds);
        if (k > ii + 1) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        qjj = 3 * (k - 1) + 1;
        kase = 3 * k + 1;
        xrot(Vf, qjj, kase, sm, sqds);
        b_s[k - 1] = sm * b + sqds * nrm;
        sm = xrotg(&b_s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = sm * b + sqds * b_s[k];
        b_s[k] = -sqds * b + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, qjj, kase, sm, sqds);
      }
      e[m] = rt;
      qq++;
      break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        kase = 3 * ii;
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        qjj = 3 * ii + 1;
        kase = 3 * (ii + 1) + 1;
        xswap(Vf, qjj, kase);
        xswap(U, qjj, kase);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
  for (k = 0; k < 3; k++) {
    s[k] = b_s[k];
    V[3 * k] = Vf[3 * k];
    kase = 3 * k + 1;
    V[kase] = Vf[kase];
    kase = 3 * k + 2;
    V[kase] = Vf[kase];
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
