/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2024 00:13:40
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
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int i;
  int k;
  int m;
  int q;
  int qp1;
  int qp1jj;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
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
        ztest = -nrm;
        b_s[q] = -nrm;
      } else {
        ztest = nrm;
        b_s[q] = nrm;
      }
      if (fabs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
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
    for (k = qp1; k < 8; k++) {
      i = q + 7 * (k - 1);
      if (apply_transform) {
        xaxpy(7 - q, -(xdotc(7 - q, b_A, qq, b_A, i + 1) / b_A[q + 7 * q]), qq,
              b_A, i + 1);
      }
      e[k - 1] = b_A[i];
    }
    for (k = q + 1; k < 8; k++) {
      i = (k + 7 * q) - 1;
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
        for (k = qp1; k < 8; k++) {
          work[k - 1] = 0.0;
        }
        for (k = qp1; k < 8; k++) {
          b_xaxpy(6 - q, e[k - 1], b_A, (q + 7 * (k - 1)) + 2, work, q + 2);
        }
        for (k = qp1; k < 8; k++) {
          c_xaxpy(6 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A,
                  (q + 7 * (k - 1)) + 2);
        }
      }
      for (k = qp1; k < 8; k++) {
        Vf[(k + 7 * q) - 1] = e[k - 1];
      }
    }
  }
  m = 5;
  b_s[6] = b_A[48];
  e[5] = b_A[47];
  e[6] = 0.0;
  for (k = 0; k < 7; k++) {
    U[k + 42] = 0.0;
  }
  U[48] = 1.0;
  for (q = 5; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 7 * q;
    if (b_s[q] != 0.0) {
      for (k = qp1; k < 8; k++) {
        i = (q + 7 * (k - 1)) + 1;
        xaxpy(7 - q, -(xdotc(7 - q, U, qq + 1, U, i) / U[qq]), qq + 1, U, i);
      }
      for (k = q + 1; k < 8; k++) {
        i = (k + 7 * q) - 1;
        U[i] = -U[i];
      }
      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + 7 * q] = 0.0;
      }
    } else {
      for (k = 0; k < 7; k++) {
        U[k + 7 * q] = 0.0;
      }
      U[qq] = 1.0;
    }
  }
  for (q = 6; q >= 0; q--) {
    if ((q + 1 <= 5) && (e[q] != 0.0)) {
      qp1 = q + 2;
      i = (q + 7 * q) + 2;
      for (k = qp1; k < 8; k++) {
        qp1jj = (q + 7 * (k - 1)) + 2;
        xaxpy(6 - q, -(xdotc(6 - q, Vf, i, Vf, qp1jj) / Vf[i - 1]), i, Vf,
              qp1jj);
      }
    }
    for (k = 0; k < 7; k++) {
      Vf[k + 7 * q] = 0.0;
    }
    Vf[q + 7 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 7; q++) {
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = fabs(ztest);
      nrm = ztest / rt;
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
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
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
    ztest = fabs(e[q]);
    if ((nrm > ztest) || rtIsNaN(ztest)) {
      ztest = nrm;
    }
    if ((!(snorm > ztest)) && (!rtIsNaN(ztest))) {
      snorm = ztest;
    }
  }
  while ((m + 2 > 0) && (qq < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <=
             2.2204460492503131E-16 * (fabs(b_s[k]) + fabs(b_s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);
    if (k + 1 == m + 1) {
      i = 4;
    } else {
      qp1jj = m + 2;
      i = m + 2;
      exitg2 = false;
      while ((!exitg2) && (i >= k + 1)) {
        qp1jj = i;
        if (i == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (i < m + 2) {
            nrm = fabs(e[i - 1]);
          }
          if (i > k + 2) {
            nrm += fabs(e[i - 2]);
          }
          ztest = fabs(b_s[i - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) ||
              (ztest <= 1.0020841800044864E-292)) {
            b_s[i - 1] = 0.0;
            exitg2 = true;
          } else {
            i--;
          }
        }
      }
      if (qp1jj == k + 1) {
        i = 3;
      } else if (qp1jj == m + 2) {
        i = 1;
      } else {
        i = 2;
        q = qp1jj;
      }
    }
    switch (i) {
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        if (k > q + 1) {
          rt = e[k - 2];
          ztest = -sqds * rt;
          e[k - 2] = rt * sm;
        }
        xrot(Vf, 7 * (k - 1) + 1, 7 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = -sqds * rt;
        e[k - 1] = rt * sm;
        xrot(U, 7 * (k - 1) + 1, 7 * (q - 1) + 1, sm, sqds);
      }
      break;
    case 3:
      i = m + 1;
      nrm = b_s[m + 1];
      scale = fabs(nrm);
      ztest = fabs(b_s[m]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[m]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(b_s[q]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      ztest = fabs(e[q]);
      if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
        scale = ztest;
      }
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      ztest = e[m] / scale;
      sqds = b_s[q] / scale;
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
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= i; k++) {
        xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = ztest;
        }
        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 7 * (k - 1) + 1, 7 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 7 * (k - 1) + 1, 7 * k + 1, sm, sqds);
      }
      e[m] = ztest;
      qq++;
      break;
    default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        i = 7 * q;
        qp1jj = i + 7;
        for (k = i + 1; k <= qp1jj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = q + 1;
      while ((q + 1 < 7) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, 7 * q + 1, 7 * (q + 1) + 1);
        xswap(U, 7 * q + 1, 7 * (q + 1) + 1);
        q = qp1;
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
