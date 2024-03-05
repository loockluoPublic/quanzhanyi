/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
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
void b_svd(const double A[49], double U[49], double s[7], double V[49])
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
    nrm = e_xnrm2(7 - q, b_A, qq);
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
        d_xaxpy(7 - q, -(xdotc(7 - q, b_A, qq, b_A, i + 1) / b_A[q + 7 * q]),
                qq, b_A, i + 1);
      }
      e[k - 1] = b_A[i];
    }
    for (k = q + 1; k < 8; k++) {
      i = (k + 7 * q) - 1;
      U[i] = b_A[i];
    }
    if (q + 1 <= 5) {
      nrm = f_xnrm2(6 - q, e, q + 2);
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
          e_xaxpy(6 - q, e[k - 1], b_A, (q + 7 * (k - 1)) + 2, work, q + 2);
        }
        for (k = qp1; k < 8; k++) {
          f_xaxpy(6 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A,
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
        d_xaxpy(7 - q, -(xdotc(7 - q, U, qq + 1, U, i) / U[qq]), qq + 1, U, i);
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
        d_xaxpy(6 - q, -(xdotc(6 - q, Vf, i, Vf, qp1jj) / Vf[i - 1]), i, Vf,
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
 * Arguments    : const double A[9]
 *                double U[3]
 * Return Type  : void
 */
void svd(const double A[9], double U[3])
{
  double b_A[9];
  double e[3];
  double s[3];
  double work[3];
  double b;
  double nrm;
  double r;
  double scale;
  double sm;
  double snorm;
  double sqds;
  int A_tmp;
  int exitg1;
  int iter;
  int k;
  int m;
  int q;
  int qp1;
  int qq;
  int qs;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 9U * sizeof(double));
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (q = 0; q < 2; q++) {
    qp1 = q + 2;
    iter = q + 3 * q;
    qq = iter + 1;
    m = 2 - q;
    apply_transform = false;
    nrm = c_xnrm2(3 - q, b_A, iter + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[iter] < 0.0) {
        b = -nrm;
        s[q] = -nrm;
      } else {
        b = nrm;
        s[q] = nrm;
      }
      if (fabs(b) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b;
        qs = (iter - q) + 3;
        for (k = qq; k <= qs; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qs = (iter - q) + 3;
        for (k = qq; k <= qs; k++) {
          b_A[k - 1] /= s[q];
        }
      }
      b_A[iter]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (qs = qp1; qs < 4; qs++) {
      qq = q + 3 * (qs - 1);
      if (apply_transform) {
        nrm = 0.0;
        for (k = 0; k <= m; k++) {
          nrm += b_A[iter + k] * b_A[qq + k];
        }
        nrm = -(nrm / b_A[iter]);
        if (!(nrm == 0.0)) {
          for (k = 0; k <= m; k++) {
            A_tmp = qq + k;
            b_A[A_tmp] += nrm * b_A[iter + k];
          }
        }
      }
      e[qs - 1] = b_A[qq];
    }
    if (q + 1 <= 1) {
      nrm = d_xnrm2(e, 2);
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
        for (A_tmp = qp1; A_tmp < 4; A_tmp++) {
          work[A_tmp - 1] = 0.0;
        }
        for (qs = qp1; qs < 4; qs++) {
          b = e[qs - 1];
          if (!(b == 0.0)) {
            qq = 3 * (qs - 1) + 1;
            work[1] += b * b_A[qq];
            work[2] += b * b_A[qq + 1];
          }
        }
        for (qs = qp1; qs < 4; qs++) {
          c_xaxpy(2, -e[qs - 1] / e[1], work, 2, b_A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  iter = 0;
  snorm = 0.0;
  b = s[0];
  if (s[0] != 0.0) {
    nrm = fabs(s[0]);
    r = s[0] / nrm;
    b = nrm;
    s[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = fabs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    s[1] *= r;
  }
  nrm = fabs(b);
  if ((!(nrm > e[0])) && (!rtIsNaN(e[0]))) {
    nrm = e[0];
  }
  if (!rtIsNaN(nrm)) {
    snorm = nrm;
  }
  b = s[1];
  if (s[1] != 0.0) {
    nrm = fabs(s[1]);
    r = s[1] / nrm;
    b = nrm;
    s[1] = nrm;
    e[1] = b_A[7] / r;
  }
  if (e[1] != 0.0) {
    nrm = fabs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    s[2] = b_A[8] * r;
  }
  nrm = fabs(b);
  if ((!(nrm > e[1])) && (!rtIsNaN(e[1]))) {
    nrm = e[1];
  }
  if ((!(snorm > nrm)) && (!rtIsNaN(nrm))) {
    snorm = nrm;
  }
  b = s[2];
  if (s[2] != 0.0) {
    nrm = fabs(s[2]);
    b = nrm;
    s[2] = nrm;
  }
  nrm = fabs(b);
  if (!(nrm > 0.0)) {
    nrm = 0.0;
  }
  if ((!(snorm > nrm)) && (!rtIsNaN(nrm))) {
    snorm = nrm;
  }
  while ((m + 2 > 0) && (iter < 75)) {
    A_tmp = m;
    do {
      exitg1 = 0;
      q = A_tmp + 1;
      if (A_tmp + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[A_tmp]);
        if ((nrm <=
             2.2204460492503131E-16 * (fabs(s[A_tmp]) + fabs(s[A_tmp + 1]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[A_tmp] = 0.0;
          exitg1 = 1;
        } else {
          A_tmp--;
        }
      }
    } while (exitg1 == 0);
    if (A_tmp + 1 == m + 1) {
      qq = 4;
    } else {
      qs = m + 2;
      qq = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qq >= A_tmp + 1)) {
        qs = qq;
        if (qq == A_tmp + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qq < m + 2) {
            nrm = fabs(e[qq - 1]);
          }
          if (qq > A_tmp + 2) {
            nrm += fabs(e[qq - 2]);
          }
          r = fabs(s[qq - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) ||
              (r <= 1.0020841800044864E-292)) {
            s[qq - 1] = 0.0;
            exitg2 = true;
          } else {
            qq--;
          }
        }
      }
      if (qs == A_tmp + 1) {
        qq = 3;
      } else if (qs == m + 2) {
        qq = 1;
      } else {
        qq = 2;
        q = qs;
      }
    }
    switch (qq) {
    case 1:
      r = e[m];
      e[m] = 0.0;
      qs = m + 1;
      for (k = qs; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          r = -sqds * e[0];
          e[0] *= sm;
        }
      }
      break;
    case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
      }
      break;
    case 3:
      qq = m + 1;
      r = s[m + 1];
      scale = fabs(r);
      nrm = fabs(s[m]);
      if ((!(scale > nrm)) && (!rtIsNaN(nrm))) {
        scale = nrm;
      }
      nrm = fabs(e[m]);
      if ((!(scale > nrm)) && (!rtIsNaN(nrm))) {
        scale = nrm;
      }
      nrm = fabs(s[q]);
      if ((!(scale > nrm)) && (!rtIsNaN(nrm))) {
        scale = nrm;
      }
      nrm = fabs(e[q]);
      if ((!(scale > nrm)) && (!rtIsNaN(nrm))) {
        scale = nrm;
      }
      sm = r / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = sqrt(b * b + nrm);
        if (b < 0.0) {
          r = -r;
        }
        r = nrm / (b + r);
      } else {
        r = 0.0;
      }
      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qq; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[0] = r;
        }
        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        r = sqds * s[k];
        s[k] *= sm;
        s[k - 1] = sm * b + sqds * nrm;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        r = sm * e[k - 1] + sqds * s[k];
        s[k] = -sqds * e[k - 1] + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
      }
      e[m] = r;
      iter++;
      break;
    default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
      }
      qp1 = q + 1;
      while ((q + 1 < 3) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        q = qp1;
        qp1++;
      }
      iter = 0;
      m--;
      break;
    }
  }
  U[0] = s[0];
  U[1] = s[1];
  U[2] = s[2];
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
