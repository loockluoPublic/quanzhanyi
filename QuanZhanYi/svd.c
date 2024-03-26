/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 15:14:21
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
 * Arguments    : const double A[49]
 *                double U[49]
 *                double s[7]
 *                double V[49]
 * Return Type  : void
 */
void svd(const double A[49], double U[49], double s[7], double V[49])
{
  double Vf[49];
  double b_A[49];
  double b_s[7];
  double e[7];
  double work[7];
  double b;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  int i;
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
  memcpy(&b_A[0], &A[0], 49U * sizeof(double));
  for (i = 0; i < 7; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }
  memset(&U[0], 0, 49U * sizeof(double));
  memset(&Vf[0], 0, 49U * sizeof(double));
  for (q = 0; q < 6; q++) {
    qp1 = q + 2;
    qq = (q + 7 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(7 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 6;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 6;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }
      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (jj = qp1; jj < 8; jj++) {
      i = q + 7 * (jj - 1);
      if (apply_transform) {
        xaxpy(7 - q, -(xdotc(7 - q, b_A, qq, b_A, i + 1) / b_A[q + 7 * q]), qq,
              b_A, i + 1);
      }
      e[jj - 1] = b_A[i];
    }
    for (ii = q + 1; ii < 8; ii++) {
      i = (ii + 7 * q) - 1;
      U[i] = b_A[i];
    }
    if (q + 1 <= 5) {
      nrm = b_xnrm2(6 - q, e, q + 2);
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
          for (k = qp1; k < 8; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 8; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (ii = qp1; ii < 8; ii++) {
          work[ii - 1] = 0.0;
        }
        for (jj = qp1; jj < 8; jj++) {
          b_xaxpy(6 - q, e[jj - 1], b_A, (q + 7 * (jj - 1)) + 2, work, q + 2);
        }
        for (jj = qp1; jj < 8; jj++) {
          c_xaxpy(6 - q, -e[jj - 1] / e[q + 1], work, q + 2, b_A,
                  (q + 7 * (jj - 1)) + 2);
        }
      }
      for (ii = qp1; ii < 8; ii++) {
        Vf[(ii + 7 * q) - 1] = e[ii - 1];
      }
    }
  }
  m = 5;
  b_s[6] = b_A[48];
  e[5] = b_A[47];
  e[6] = 0.0;
  for (ii = 0; ii < 7; ii++) {
    U[ii + 42] = 0.0;
  }
  U[48] = 1.0;
  for (q = 5; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 7 * q;
    if (b_s[q] != 0.0) {
      for (jj = qp1; jj < 8; jj++) {
        i = (q + 7 * (jj - 1)) + 1;
        xaxpy(7 - q, -(xdotc(7 - q, U, qq + 1, U, i) / U[qq]), qq + 1, U, i);
      }
      for (ii = q + 1; ii < 8; ii++) {
        i = (ii + 7 * q) - 1;
        U[i] = -U[i];
      }
      U[qq]++;
      for (ii = 0; ii < q; ii++) {
        U[ii + 7 * q] = 0.0;
      }
    } else {
      for (ii = 0; ii < 7; ii++) {
        U[ii + 7 * q] = 0.0;
      }
      U[qq] = 1.0;
    }
  }
  for (q = 6; q >= 0; q--) {
    if ((q + 1 <= 5) && (e[q] != 0.0)) {
      qp1 = q + 2;
      i = (q + 7 * q) + 2;
      for (jj = qp1; jj < 8; jj++) {
        qp1jj = (q + 7 * (jj - 1)) + 2;
        xaxpy(6 - q, -(xdotc(6 - q, Vf, i, Vf, qp1jj) / Vf[i - 1]), i, Vf,
              qp1jj);
      }
    }
    for (ii = 0; ii < 7; ii++) {
      Vf[ii + 7 * q] = 0.0;
    }
    Vf[q + 7 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 7; q++) {
    nrm = b_s[q];
    if (nrm != 0.0) {
      rt = fabs(nrm);
      nrm /= rt;
      b_s[q] = rt;
      if (q + 1 < 7) {
        e[q] /= nrm;
      }
      i = 7 * q;
      qp1jj = i + 7;
      for (k = i + 1; k <= qp1jj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 7) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        i = 7 * (q + 1);
        qp1jj = i + 7;
        for (k = i + 1; k <= qp1jj; k++) {
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
    jj = m + 1;
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
      i = 4;
    } else {
      qp1jj = m + 2;
      i = m + 2;
      exitg1 = false;
      while ((!exitg1) && (i >= ii)) {
        qp1jj = i;
        if (i == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (i < m + 2) {
            nrm = fabs(e[i - 1]);
          }
          if (i > ii + 1) {
            nrm += fabs(e[i - 2]);
          }
          rt = fabs(b_s[i - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            b_s[i - 1] = 0.0;
            exitg1 = true;
          } else {
            i--;
          }
        }
      }
      if (qp1jj == ii) {
        i = 3;
      } else if (qp1jj == m + 2) {
        i = 1;
      } else {
        i = 2;
        ii = qp1jj;
      }
    }
    switch (i) {
    case 1:
      rt = e[m];
      e[m] = 0.0;
      for (k = jj; k >= ii + 1; k--) {
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        if (k > ii + 1) {
          b = e[k - 2];
          rt = -sqds * b;
          e[k - 2] = b * sm;
        }
        xrot(Vf, 7 * (k - 1) + 1, 7 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2:
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 7 * (k - 1) + 1, 7 * (ii - 1) + 1, sm, sqds);
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
      for (k = ii + 1; k <= jj; k++) {
        xrotg(&rt, &nrm, &sm, &sqds);
        if (k > ii + 1) {
          e[k - 2] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 7 * (k - 1) + 1, 7 * k + 1, sm, sqds);
        b_s[k - 1] = sm * b + sqds * nrm;
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        rt = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 7 * (k - 1) + 1, 7 * k + 1, sm, sqds);
      }
      e[m] = rt;
      qq++;
      break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        i = 7 * ii;
        qp1jj = i + 7;
        for (k = i + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 7) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, 7 * ii + 1, 7 * (ii + 1) + 1);
        xswap(U, 7 * ii + 1, 7 * (ii + 1) + 1);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
  for (k = 0; k < 7; k++) {
    s[k] = b_s[k];
    for (i = 0; i < 7; i++) {
      qp1jj = i + 7 * k;
      V[qp1jj] = Vf[qp1jj];
    }
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
