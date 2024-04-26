/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Apr-2024 00:13:24
 */

/* Include Files */
#include "svd.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
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
  const double *A_data;
  double f;
  double rt;
  double scale;
  double sqds;
  double *U_data;
  double *b_A_data;
  double *work_data;
  int i;
  int ii;
  int jj;
  int k;
  int minnp;
  int n;
  int nrt;
  int ns;
  int q;
  A_data = A->data;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 4;
  emxEnsureCapacity_real_T(b_A, i);
  b_A_data = b_A->data;
  ns = A->size[0] * 4;
  for (i = 0; i < ns; i++) {
    b_A_data[i] = A_data[i];
  }
  n = A->size[0];
  ns = A->size[0] + 1;
  if (ns > 4) {
    ns = 4;
  }
  minnp = A->size[0];
  if (minnp > 4) {
    minnp = 4;
  }
  if (ns - 1 >= 0) {
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
  work_data = work->data;
  ns = A->size[0];
  for (i = 0; i < ns; i++) {
    work_data[i] = 0.0;
  }
  i = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = A->size[0];
  emxEnsureCapacity_real_T(U, i);
  U_data = U->data;
  ns = A->size[0] * A->size[0];
  for (i = 0; i < ns; i++) {
    U_data[i] = 0.0;
  }
  memset(&V[0], 0, 16U * sizeof(double));
  if (A->size[0] == 0) {
    V[0] = 1.0;
    V[5] = 1.0;
    V[10] = 1.0;
    V[15] = 1.0;
  } else {
    double nrm;
    double snorm;
    int m;
    int nct;
    int nctp1;
    int nmq;
    int qjj;
    int qp1;
    int qq;
    if (A->size[0] >= 2) {
      nrt = 2;
    } else {
      nrt = 1;
    }
    nct = A->size[0] - 1;
    if (nct > 4) {
      nct = 4;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      i = nct;
    } else {
      i = nrt;
    }
    for (q = 0; q < i; q++) {
      boolean_T apply_transform;
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = b_xnrm2(nmq + 1, b_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (b_A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          b_s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            ns = qq + nmq;
            for (k = qq; k <= ns; k++) {
              b_A_data[k - 1] *= nrm;
            }
          } else {
            ns = qq + nmq;
            for (k = qq; k <= ns; k++) {
              b_A_data[k - 1] /= b_s_data[q];
            }
          }
          b_A_data[qq - 1]++;
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
              nrm += b_A_data[(qq + k) - 1] * b_A_data[qjj + k];
            }
          }
          nrm = -(nrm / b_A_data[q + b_A->size[0] * q]);
          b_xaxpy(nmq + 1, nrm, qq, b_A, qjj + 1);
          b_A_data = b_A->data;
        }
        e[jj - 1] = b_A_data[qjj];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U->size[0] * q) - 1] =
              b_A_data[(ii + b_A->size[0] * q) - 1];
        }
      }
      if (q + 1 <= nrt) {
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
          if (q + 2 <= n) {
            for (ii = qp1; ii <= n; ii++) {
              work_data[ii - 1] = 0.0;
            }
            for (jj = qp1; jj < 5; jj++) {
              c_xaxpy(nmq, e[jj - 1], b_A, (q + n * (jj - 1)) + 2, work, q + 2);
              work_data = work->data;
            }
            for (jj = qp1; jj < 5; jj++) {
              c_xaxpy(nmq, -e[jj - 1] / e[q + 1], work, q + 2, b_A,
                      (q + n * (jj - 1)) + 2);
              b_A_data = b_A->data;
            }
          }
        }
        for (ii = qp1; ii < 5; ii++) {
          V[(ii + (q << 2)) - 1] = e[ii - 1];
        }
      }
    }
    if (A->size[0] + 1 >= 4) {
      m = 3;
    } else {
      m = A->size[0];
    }
    if (nct < 4) {
      b_s_data[nct] = b_A_data[nct + b_A->size[0] * nct];
    }
    if (A->size[0] < m + 1) {
      b_s_data[m] = 0.0;
    }
    if (nrt + 1 < m + 1) {
      e[nrt] = b_A_data[nrt + b_A->size[0] * m];
    }
    e[m] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (jj = nctp1; jj <= n; jj++) {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U->size[0] * (jj - 1)] = 0.0;
        }
        U_data[(jj + U->size[0] * (jj - 1)) - 1] = 1.0;
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
              nrm += U_data[qq + k] * U_data[(qjj + k) - 1];
            }
          }
          nrm = -(nrm / U_data[qq]);
          b_xaxpy(ns + 1, nrm, qq + 1, U, qjj);
          U_data = U->data;
        }
        for (ii = q; ii <= n; ii++) {
          U_data[(ii + U->size[0] * (q - 1)) - 1] =
              -U_data[(ii + U->size[0] * (q - 1)) - 1];
        }
        U_data[qq]++;
        for (ii = 0; ii <= q - 2; ii++) {
          U_data[ii + U->size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U->size[0] * (q - 1)] = 0.0;
        }
        U_data[qq] = 1.0;
      }
    }
    for (q = 3; q >= 0; q--) {
      if ((q + 1 <= nrt) && (e[q] != 0.0)) {
        qp1 = q + 2;
        ns = (q + (q << 2)) + 2;
        for (jj = qp1; jj < 5; jj++) {
          nmq = (q + ((jj - 1) << 2)) + 2;
          d_xaxpy(3 - q, -(b_xdotc(3 - q, V, ns, V, nmq) / V[ns - 1]), ns, V,
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
      nrm = b_s_data[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm /= rt;
        b_s_data[q] = rt;
        if (q + 1 < m + 1) {
          e[q] /= nrm;
        }
        if (q + 1 <= n) {
          ns = n * q;
          i = ns + n;
          for (k = ns + 1; k <= i; k++) {
            U_data[k - 1] *= nrm;
          }
        }
      }
      if (q + 1 < m + 1) {
        nrm = e[q];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          nrm = rt / nrm;
          e[q] = rt;
          b_s_data[q + 1] *= nrm;
          ns = (q + 1) << 2;
          i = ns + 4;
          for (k = ns + 1; k <= i; k++) {
            V[k - 1] *= nrm;
          }
        }
      }
      snorm = fmax(snorm, fmax(fabs(b_s_data[q]), fabs(e[q])));
    }
    while ((m + 1 > 0) && (nct < 75)) {
      boolean_T exitg1;
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
            rt = fabs(b_s_data[ns - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
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
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          if (k > ii + 1) {
            double b;
            b = e[k - 2];
            f = -scale * b;
            e[k - 2] = b * sqds;
          }
          b_xrot(V, ((k - 1) << 2) + 1, (m << 2) + 1, sqds, scale);
        }
      } break;
      case 2: {
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 1; k++) {
          double b;
          xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          b = e[k - 1];
          f = -scale * b;
          e[k - 1] = b * sqds;
          if (n >= 1) {
            nmq = n * (k - 1);
            qjj = n * (ii - 1);
            for (nrt = 0; nrt < n; nrt++) {
              nctp1 = qjj + nrt;
              ns = nmq + nrt;
              nrm = sqds * U_data[ns] + scale * U_data[nctp1];
              U_data[nctp1] = sqds * U_data[nctp1] - scale * U_data[ns];
              U_data[ns] = nrm;
            }
          }
        }
      } break;
      case 3: {
        double b;
        nrm = b_s_data[m - 1];
        rt = e[m - 1];
        scale = fmax(fmax(fmax(fmax(fabs(b_s_data[m]), fabs(nrm)), fabs(rt)),
                          fabs(b_s_data[ii])),
                     fabs(e[ii]));
        f = b_s_data[m] / scale;
        nrm /= scale;
        rt /= scale;
        sqds = b_s_data[ii] / scale;
        b = ((nrm + f) * (nrm - f) + rt * rt) / 2.0;
        nrm = f * rt;
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
        f = (sqds + f) * (sqds - f) + rt;
        rt = sqds * (e[ii] / scale);
        for (k = ii + 1; k <= m; k++) {
          xrotg(&f, &rt, &sqds, &scale);
          if (k > ii + 1) {
            e[k - 2] = f;
          }
          nrm = e[k - 1];
          b = b_s_data[k - 1];
          e[k - 1] = sqds * nrm - scale * b;
          rt = scale * b_s_data[k];
          b_s_data[k] *= sqds;
          b_xrot(V, ((k - 1) << 2) + 1, (k << 2) + 1, sqds, scale);
          b_s_data[k - 1] = sqds * b + scale * nrm;
          xrotg(&b_s_data[k - 1], &rt, &sqds, &scale);
          f = sqds * e[k - 1] + scale * b_s_data[k];
          b_s_data[k] = -scale * e[k - 1] + sqds * b_s_data[k];
          rt = scale * e[k];
          e[k] *= sqds;
          if (k < n) {
            nmq = n * (k - 1);
            qjj = n * k;
            for (nrt = 0; nrt < n; nrt++) {
              nctp1 = qjj + nrt;
              ns = nmq + nrt;
              nrm = sqds * U_data[ns] + scale * U_data[nctp1];
              U_data[nctp1] = sqds * U_data[nctp1] - scale * U_data[ns];
              U_data[ns] = nrm;
            }
          }
        }
        e[m - 1] = f;
        nct++;
      } break;
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
          b_xswap(V, (ii << 2) + 1, ((ii + 1) << 2) + 1);
          if (ii + 1 < n) {
            nmq = n * ii;
            qjj = n * (ii + 1);
            for (k = 0; k < n; k++) {
              nctp1 = nmq + k;
              nrm = U_data[nctp1];
              i = qjj + k;
              U_data[nctp1] = U_data[i];
              U_data[i] = nrm;
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
  if (minnp - 1 >= 0) {
    memcpy(&s_data[0], &b_s_data[0], minnp * sizeof(double));
  }
}

/*
 * Arguments    : const double A[8]
 *                double U[4]
 *                double s[2]
 *                double V[16]
 * Return Type  : void
 */
void c_svd(const double A[8], double U[4], double s[2], double V[16])
{
  double b_A[8];
  double e[4];
  double b_s[3];
  double work[2];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int ii;
  int jj;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
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
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + (q << 1)) + 1;
    apply_transform = false;
    if (q + 1 <= 1) {
      nrm = e_xnrm2(b_A, qq);
      if (nrm > 0.0) {
        apply_transform = true;
        if (b_A[qq - 1] < 0.0) {
          ztest = -nrm;
        } else {
          ztest = nrm;
        }
        if (fabs(ztest) >= 1.0020841800044864E-292) {
          nrm = 1.0 / ztest;
          jj = qq + 1;
          for (k = qq; k <= jj; k++) {
            b_A[k - 1] *= nrm;
          }
        } else {
          jj = qq + 1;
          for (k = qq; k <= jj; k++) {
            b_A[k - 1] /= ztest;
          }
        }
        b_A[qq - 1]++;
        b_s[0] = -ztest;
      } else {
        b_s[0] = 0.0;
      }
    }
    for (jj = qp1; jj < 5; jj++) {
      qjj = q + ((jj - 1) << 1);
      if (apply_transform) {
        e_xaxpy(2 - q,
                -(c_xdotc(2 - q, b_A, qq, b_A, qjj + 1) / b_A[q + (q << 1)]),
                qq, b_A, qjj + 1);
      }
      e[jj - 1] = b_A[qjj];
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
      qjj = (q + (q << 2)) + 2;
      for (jj = qp1; jj < 5; jj++) {
        qq = (q + ((jj - 1) << 2)) + 2;
        d_xaxpy(3 - q, -(b_xdotc(3 - q, V, qjj, V, qq) / V[qjj - 1]), qjj, V,
                qq);
      }
    }
    qjj = q << 2;
    V[qjj] = 0.0;
    V[qjj + 1] = 0.0;
    V[qjj + 2] = 0.0;
    V[qjj + 3] = 0.0;
    V[q + (q << 2)] = 1.0;
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
        qjj = q << 1;
        jj = qjj + 2;
        for (k = qjj + 1; k <= jj; k++) {
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
        qjj = (q + 1) << 2;
        jj = qjj + 4;
        for (k = qjj + 1; k <= jj; k++) {
          V[k - 1] *= nrm;
        }
      }
    }
    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }
  while ((m + 2 > 0) && (qp1 < 75)) {
    boolean_T exitg1;
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
      qjj = 4;
    } else {
      qq = m + 2;
      qjj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qjj >= ii)) {
        qq = qjj;
        if (qjj == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }
          if (qjj > ii + 1) {
            nrm += fabs(e[qjj - 2]);
          }
          ztest = fabs(b_s[qjj - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) ||
              (ztest <= 1.0020841800044864E-292)) {
            b_s[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }
      if (qq == ii) {
        qjj = 3;
      } else if (qq == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        ii = qq;
      }
    }
    switch (qjj) {
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      for (k = jj; k >= ii + 1; k--) {
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
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
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = -sqds * rt;
        e[k - 1] = rt * sm;
        c_xrot(U, ((k - 1) << 1) + 1, ((ii - 1) << 1) + 1, sm, sqds);
      }
      break;
    case 3: {
      double scale;
      nrm = b_s[m + 1];
      scale = fmax(
          fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs(b_s[ii])),
          fabs(e[ii]));
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
        xrotg(&ztest, &nrm, &sm, &sqds);
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
        xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        if (k < 2) {
          c_xrot(U, 1, 3, sm, sqds);
        }
      }
      e[m] = ztest;
      qp1++;
    } break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        qjj = ii << 2;
        jj = qjj + 4;
        for (k = qjj + 1; k <= jj; k++) {
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
  double nrm;
  double rt;
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
  b_s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (kase = 0; kase < 9; kase++) {
    b_A[kase] = A[kase];
    U[kase] = 0.0;
    Vf[kase] = 0.0;
  }
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + 3 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(3 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        kase = (qq - q) + 2;
        for (k = qq; k <= kase; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        kase = (qq - q) + 2;
        for (k = qq; k <= kase; k++) {
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
        xaxpy(3 - q, -(xdotc(3 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 3 * q]),
              qq, b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      kase = (ii + 3 * q) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 1) {
      nrm = d_xnrm2(e);
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
      qjj = 3 * q;
      kase = qjj + 3;
      for (k = qjj + 1; k <= kase; k++) {
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
        qjj = 3 * (q + 1);
        kase = qjj + 3;
        for (k = qjj + 1; k <= kase; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }
    snorm = fmax(snorm, fmax(fabs(b_s[q]), fabs(e[q])));
  }
  while ((m + 2 > 0) && (qq < 75)) {
    boolean_T exitg1;
    qp1 = m + 1;
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
      for (k = qp1; k >= ii + 1; k--) {
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        if (k > ii + 1) {
          rt = -sqds * e[0];
          e[0] *= sm;
        }
        xrot(Vf, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2: {
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        double b;
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      nrm = b_s[m + 1];
      scale = fmax(
          fmax(fmax(fmax(fabs(nrm), fabs(b_s[m])), fabs(e[m])), fabs(b_s[ii])),
          fabs(e[ii]));
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
      for (k = ii + 1; k <= qp1; k++) {
        xrotg(&rt, &nrm, &sm, &sqds);
        if (k > ii + 1) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        xrot(Vf, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
        b_s[k - 1] = sm * b + sqds * nrm;
        xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        rt = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
      }
      e[m] = rt;
      qq++;
    } break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        qjj = 3 * ii;
        kase = qjj + 3;
        for (k = qjj + 1; k <= kase; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        xswap(Vf, 3 * ii + 1, 3 * (ii + 1) + 1);
        xswap(U, 3 * ii + 1, 3 * (ii + 1) + 1);
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
