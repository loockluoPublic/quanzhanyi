/*
 * File: svd1.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

/* Include Files */
#include "svd1.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
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
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 *                double s_data[]
 *                int *s_size
 *                double V[16]
 * Return Type  : void
 */
void b_svd(const emxArray_real_T *A, emxArray_real_T *U, double s_data[],
           int *s_size, double V[16])
{
  emxArray_real_T *b_A;
  emxArray_real_T *work;
  double b_s_data[4];
  double e[4];
  double f;
  double nrm;
  double rt;
  double scale;
  double snorm;
  double sqds;
  double ztest;
  int i;
  int ii;
  int jj;
  int k;
  int m;
  int minnp;
  int n;
  int nct;
  int nctp1;
  int nmq;
  int nrt;
  int ns;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 4;
  emxEnsureCapacity_real_T(b_A, i);
  ns = A->size[0] * 4;
  for (i = 0; i < ns; i++) {
    b_A->data[i] = A->data[i];
  }
  n = A->size[0];
  ns = A->size[0] + 1;
  if (ns >= 4) {
    ns = 4;
  }
  minnp = A->size[0];
  if (minnp >= 4) {
    minnp = 4;
  }
  if (0 <= ns - 1) {
    memset(&b_s_data[0], 0, ns * sizeof(double));
  }
  emxInit_real_T(&work, 1);
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  e[3] = 0.0;
  i = work->size[0];
  work->size[0] = A->size[0];
  emxEnsureCapacity_real_T(work, i);
  ns = A->size[0];
  for (i = 0; i < ns; i++) {
    work->data[i] = 0.0;
  }
  i = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = A->size[0];
  emxEnsureCapacity_real_T(U, i);
  ns = A->size[0] * A->size[0];
  for (i = 0; i < ns; i++) {
    U->data[i] = 0.0;
  }
  memset(&V[0], 0, 16U * sizeof(double));
  if (A->size[0] == 0) {
    V[0] = 1.0;
    V[5] = 1.0;
    V[10] = 1.0;
    V[15] = 1.0;
  } else {
    nrt = A->size[0];
    if (2 < nrt) {
      nrt = 2;
    }
    if (A->size[0] > 1) {
      nct = A->size[0] - 1;
    } else {
      nct = 0;
    }
    if (nct >= 4) {
      nct = 4;
    }
    nctp1 = nct + 1;
    if (nct > nrt) {
      i = nct;
    } else {
      i = nrt;
    }
    for (q = 0; q < i; q++) {
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = xnrm2(nmq + 1, b_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (b_A->data[qq - 1] < 0.0) {
            ztest = -nrm;
            b_s_data[q] = -nrm;
          } else {
            ztest = nrm;
            b_s_data[q] = nrm;
          }
          if (fabs(ztest) >= 1.0020841800044864E-292) {
            nrm = 1.0 / ztest;
            ns = qq + nmq;
            for (k = qq; k <= ns; k++) {
              b_A->data[k - 1] *= nrm;
            }
          } else {
            ns = qq + nmq;
            for (k = qq; k <= ns; k++) {
              b_A->data[k - 1] /= b_s_data[q];
            }
          }
          b_A->data[qq - 1]++;
          b_s_data[q] = -b_s_data[q];
        } else {
          b_s_data[q] = 0.0;
        }
      }
      for (jj = qp1; jj < 5; jj++) {
        qjj = q + n * (jj - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (nmq + 1 >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += b_A->data[(qq + k) - 1] * b_A->data[qjj + k];
            }
          }
          nrm = -(nrm / b_A->data[q + b_A->size[0] * q]);
          xaxpy(nmq + 1, nrm, qq, b_A, qjj + 1);
        }
        e[jj - 1] = b_A->data[qjj];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U->data[(ii + U->size[0] * q) - 1] =
              b_A->data[(ii + b_A->size[0] * q) - 1];
        }
      }
      if (q + 1 <= nrt) {
        nrm = b_xnrm2(3 - q, e, q + 2);
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
          if (q + 2 <= n) {
            for (ii = qp1; ii <= n; ii++) {
              work->data[ii - 1] = 0.0;
            }
            for (jj = qp1; jj < 5; jj++) {
              b_xaxpy(nmq, e[jj - 1], b_A, (q + n * (jj - 1)) + 2, work, q + 2);
            }
            for (jj = qp1; jj < 5; jj++) {
              b_xaxpy(nmq, -e[jj - 1] / e[q + 1], work, q + 2, b_A,
                      (q + n * (jj - 1)) + 2);
            }
          }
        }
        for (ii = qp1; ii < 5; ii++) {
          V[(ii + (q << 2)) - 1] = e[ii - 1];
        }
      }
    }
    if (4 < A->size[0] + 1) {
      m = 3;
    } else {
      m = A->size[0];
    }
    if (nct < 4) {
      b_s_data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }
    if (A->size[0] < m + 1) {
      b_s_data[m] = 0.0;
    }
    if (nrt + 1 < m + 1) {
      e[nrt] = b_A->data[nrt + b_A->size[0] * m];
    }
    e[m] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (jj = nctp1; jj <= n; jj++) {
        for (ii = 0; ii < n; ii++) {
          U->data[ii + U->size[0] * (jj - 1)] = 0.0;
        }
        U->data[(jj + U->size[0] * (jj - 1)) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      ns = n - q;
      qq = (q + n * (q - 1)) - 1;
      if (b_s_data[q - 1] != 0.0) {
        for (jj = qp1; jj <= n; jj++) {
          qjj = q + n * (jj - 1);
          nrm = 0.0;
          if (ns + 1 >= 1) {
            for (k = 0; k <= ns; k++) {
              nrm += U->data[qq + k] * U->data[(qjj + k) - 1];
            }
          }
          nrm = -(nrm / U->data[qq]);
          xaxpy(ns + 1, nrm, qq + 1, U, qjj);
        }
        for (ii = q; ii <= n; ii++) {
          U->data[(ii + U->size[0] * (q - 1)) - 1] =
              -U->data[(ii + U->size[0] * (q - 1)) - 1];
        }
        U->data[qq]++;
        for (ii = 0; ii <= q - 2; ii++) {
          U->data[ii + U->size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (ii = 0; ii < n; ii++) {
          U->data[ii + U->size[0] * (q - 1)] = 0.0;
        }
        U->data[qq] = 1.0;
      }
    }
    for (q = 3; q >= 0; q--) {
      if ((q + 1 <= nrt) && (e[q] != 0.0)) {
        qp1 = q + 2;
        ns = (q + (q << 2)) + 2;
        for (jj = qp1; jj < 5; jj++) {
          nmq = (q + ((jj - 1) << 2)) + 2;
          c_xaxpy(3 - q, -(xdotc(3 - q, V, ns, V, nmq) / V[ns - 1]), ns, V,
                  nmq);
        }
      }
      ns = q << 2;
      V[ns] = 0.0;
      V[ns + 1] = 0.0;
      V[ns + 2] = 0.0;
      V[ns + 3] = 0.0;
      V[q + (q << 2)] = 1.0;
    }
    qq = m;
    nct = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      ztest = b_s_data[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = ztest / rt;
        b_s_data[q] = rt;
        if (q + 1 < m + 1) {
          e[q] /= nrm;
        }
        if (q + 1 <= n) {
          ns = n * q;
          i = ns + n;
          for (k = ns + 1; k <= i; k++) {
            U->data[k - 1] *= nrm;
          }
        }
      }
      if (q + 1 < m + 1) {
        ztest = e[q];
        if (ztest != 0.0) {
          rt = fabs(ztest);
          nrm = rt / ztest;
          e[q] = rt;
          b_s_data[q + 1] *= nrm;
          ns = (q + 1) << 2;
          i = ns + 4;
          for (k = ns + 1; k <= i; k++) {
            V[k - 1] *= nrm;
          }
        }
      }
      nrm = fabs(b_s_data[q]);
      ztest = fabs(e[q]);
      if ((nrm > ztest) || rtIsNaN(ztest)) {
        ztest = nrm;
      }
      if ((!(snorm > ztest)) && (!rtIsNaN(ztest))) {
        snorm = ztest;
      }
    }
    while ((m + 1 > 0) && (nct < 75)) {
      ii = m;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(b_s_data[ii - 1]) + fabs(b_s_data[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((nct > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }
      if (ii == m) {
        ns = 4;
      } else {
        nmq = m + 1;
        ns = m + 1;
        exitg1 = false;
        while ((!exitg1) && (ns >= ii)) {
          nmq = ns;
          if (ns == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m + 1) {
              nrm = fabs(e[ns - 1]);
            }
            if (ns > ii + 1) {
              nrm += fabs(e[ns - 2]);
            }
            ztest = fabs(b_s_data[ns - 1]);
            if ((ztest <= 2.2204460492503131E-16 * nrm) ||
                (ztest <= 1.0020841800044864E-292)) {
              b_s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (nmq == ii) {
          ns = 3;
        } else if (nmq == m + 1) {
          ns = 1;
        } else {
          ns = 2;
          ii = nmq;
        }
      }
      switch (ns) {
      case 1:
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          if (k > ii + 1) {
            rt = e[k - 2];
            f = -scale * rt;
            e[k - 2] = rt * sqds;
          }
          xrot(V, ((k - 1) << 2) + 1, (m << 2) + 1, sqds, scale);
        }
        break;
      case 2:
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 1; k++) {
          xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          rt = e[k - 1];
          f = -scale * rt;
          e[k - 1] = rt * sqds;
          if (n >= 1) {
            nmq = n * (k - 1);
            qjj = n * (ii - 1);
            for (nrt = 0; nrt < n; nrt++) {
              nctp1 = qjj + nrt;
              ns = nmq + nrt;
              nrm = sqds * U->data[ns] + scale * U->data[nctp1];
              U->data[nctp1] = sqds * U->data[nctp1] - scale * U->data[ns];
              U->data[ns] = nrm;
            }
          }
        }
        break;
      case 3:
        scale = fabs(b_s_data[m]);
        nrm = b_s_data[m - 1];
        ztest = fabs(nrm);
        if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
          scale = ztest;
        }
        rt = e[m - 1];
        ztest = fabs(rt);
        if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
          scale = ztest;
        }
        ztest = fabs(b_s_data[ii]);
        if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
          scale = ztest;
        }
        ztest = fabs(e[ii]);
        if ((!(scale > ztest)) && (!rtIsNaN(ztest))) {
          scale = ztest;
        }
        f = b_s_data[m] / scale;
        nrm /= scale;
        ztest = rt / scale;
        sqds = b_s_data[ii] / scale;
        rt = ((nrm + f) * (nrm - f) + ztest * ztest) / 2.0;
        nrm = f * ztest;
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
        f = (sqds + f) * (sqds - f) + ztest;
        ztest = sqds * (e[ii] / scale);
        for (k = ii + 1; k <= m; k++) {
          xrotg(&f, &ztest, &sqds, &scale);
          if (k > ii + 1) {
            e[k - 2] = f;
          }
          nrm = e[k - 1];
          rt = b_s_data[k - 1];
          e[k - 1] = sqds * nrm - scale * rt;
          ztest = scale * b_s_data[k];
          b_s_data[k] *= sqds;
          xrot(V, ((k - 1) << 2) + 1, (k << 2) + 1, sqds, scale);
          b_s_data[k - 1] = sqds * rt + scale * nrm;
          xrotg(&b_s_data[k - 1], &ztest, &sqds, &scale);
          f = sqds * e[k - 1] + scale * b_s_data[k];
          b_s_data[k] = -scale * e[k - 1] + sqds * b_s_data[k];
          ztest = scale * e[k];
          e[k] *= sqds;
          if ((k < n) && (n >= 1)) {
            nmq = n * (k - 1);
            qjj = n * k;
            for (nrt = 0; nrt < n; nrt++) {
              nctp1 = qjj + nrt;
              ns = nmq + nrt;
              nrm = sqds * U->data[ns] + scale * U->data[nctp1];
              U->data[nctp1] = sqds * U->data[nctp1] - scale * U->data[ns];
              U->data[ns] = nrm;
            }
          }
        }
        e[m - 1] = f;
        nct++;
        break;
      default:
        if (b_s_data[ii] < 0.0) {
          b_s_data[ii] = -b_s_data[ii];
          ns = ii << 2;
          i = ns + 4;
          for (k = ns + 1; k <= i; k++) {
            V[k - 1] = -V[k - 1];
          }
        }
        qp1 = ii + 1;
        while ((ii + 1 < qq + 1) && (b_s_data[ii] < b_s_data[qp1])) {
          rt = b_s_data[ii];
          b_s_data[ii] = b_s_data[qp1];
          b_s_data[qp1] = rt;
          xswap(V, (ii << 2) + 1, ((ii + 1) << 2) + 1);
          if (ii + 1 < n) {
            nmq = n * ii;
            qjj = n * (ii + 1);
            for (k = 0; k < n; k++) {
              nctp1 = nmq + k;
              nrm = U->data[nctp1];
              i = qjj + k;
              U->data[nctp1] = U->data[i];
              U->data[i] = nrm;
            }
          }
          ii = qp1;
          qp1++;
        }
        nct = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  emxFree_real_T(&b_A);
  *s_size = minnp;
  if (0 <= minnp - 1) {
    memcpy(&s_data[0], &b_s_data[0], minnp * sizeof(double));
  }
}

/*
 * Arguments    : const double A[9]
 *                double U[9]
 *                double s[3]
 *                double V[9]
 * Return Type  : void
 */
void c_svd(const double A[9], double U[9], double s[3], double V[9])
{
  double Vf[9];
  double b_A[9];
  double b_s[3];
  double e[3];
  double work[3];
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int exitg1;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg2;
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
    qq = (q + 3 * q) + 1;
    apply_transform = false;
    nrm = c_xnrm2(3 - q, b_A, qq);
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
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }
      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + 3 * (kase - 1);
      if (apply_transform) {
        d_xaxpy(3 - q,
                -(b_xdotc(3 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 3 * q]), qq,
                b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (k = q + 1; k < 4; k++) {
      kase = (k + 3 * q) - 1;
      U[kase] = b_A[kase];
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
        for (k = qp1; k < 4; k++) {
          work[k - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          e_xaxpy(2, e[kase - 1], b_A, 3 * (kase - 1) + 2, work, 2);
        }
        for (kase = qp1; kase < 4; kase++) {
          f_xaxpy(2, -e[kase - 1] / e[1], work, 2, b_A, 3 * (kase - 1) + 2);
        }
      }
      for (k = qp1; k < 4; k++) {
        Vf[k - 1] = e[k - 1];
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
        d_xaxpy(3 - q, -(b_xdotc(3 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
                qjj);
      }
      for (k = q + 1; k < 4; k++) {
        kase = (k + 3 * q) - 1;
        U[kase] = -U[kase];
      }
      U[qq]++;
      if (0 <= q - 1) {
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
      d_xaxpy(2, -(b_xdotc(2, Vf, 2, Vf, 5) / Vf[1]), 2, Vf, 5);
      d_xaxpy(2, -(b_xdotc(2, Vf, 2, Vf, 8) / Vf[1]), 2, Vf, 8);
    }
    Vf[3 * q] = 0.0;
    Vf[3 * q + 1] = 0.0;
    Vf[3 * q + 2] = 0.0;
    Vf[q + 3 * q] = 1.0;
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
      kase = 3 * q;
      qjj = kase + 3;
      for (k = kase + 1; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 3) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = fabs(ztest);
        nrm = rt / ztest;
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
    ztest = fabs(e[q]);
    if ((nrm > ztest) || rtIsNaN(ztest)) {
      ztest = nrm;
    }
    if ((!(snorm > ztest)) && (!rtIsNaN(ztest))) {
      snorm = ztest;
    }
  }
  while ((m + 2 > 0) && (qp1 < 75)) {
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
            ((qp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);
    if (k + 1 == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg2 = false;
      while ((!exitg2) && (kase >= k + 1)) {
        qjj = kase;
        if (kase == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }
          if (kase > k + 2) {
            nrm += fabs(e[kase - 2]);
          }
          ztest = fabs(b_s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) ||
              (ztest <= 1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg2 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == k + 1) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        q = qjj;
      }
    }
    switch (kase) {
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      qjj = m + 1;
      for (k = qjj; k >= q + 1; k--) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        if (k > q + 1) {
          ztest = -sqds * e[0];
          e[0] *= sm;
        }
        b_xrot(Vf, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
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
        b_xrot(U, 3 * (k - 1) + 1, 3 * (q - 1) + 1, sm, sqds);
      }
      break;
    case 3:
      kase = m + 1;
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
      for (k = q + 1; k <= kase; k++) {
        xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[0] = ztest;
        }
        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * rt;
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        b_xrot(Vf, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
        b_s[k - 1] = sm * rt + sqds * nrm;
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        b_xrot(U, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
      }
      e[m] = ztest;
      qp1++;
      break;
    default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        kase = 3 * q;
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = q + 1;
      while ((q + 1 < 3) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        b_xswap(Vf, 3 * q + 1, 3 * (q + 1) + 1);
        b_xswap(U, 3 * q + 1, 3 * (q + 1) + 1);
        q = qp1;
        qp1++;
      }
      qp1 = 0;
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
 * File trailer for svd1.c
 *
 * [EOF]
 */
