/*
 * File: xzsvdc.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 21-Aug-2024 00:46:56
 */

/* Include Files */
#include "xzsvdc.h"
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
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *U
 *                double S_data[]
 *                double V[9]
 * Return Type  : int
 */
int b_xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
             double V[9])
{
  emxArray_real_T *work;
  double e[3];
  double s_data[3];
  double b;
  double f;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double *A_data;
  double *U_data;
  double *work_data;
  int S_size;
  int i;
  int ii;
  int k;
  int m;
  int mm;
  int n;
  int nct;
  int nctp1;
  int ns;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  A_data = A->data;
  n = A->size[0];
  if (A->size[0] + 1 <= 3) {
    ns = A->size[0];
  } else {
    ns = 2;
  }
  S_size = A->size[0];
  if (S_size > 3) {
    S_size = 3;
  }
  memset(&s_data[0], 0, (unsigned int)(ns + 1) * sizeof(double));
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  emxInit_real_T(&work, 1);
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
  memset(&V[0], 0, 9U * sizeof(double));
  if (A->size[0] == 0) {
    V[0] = 1.0;
    V[4] = 1.0;
    V[8] = 1.0;
  } else {
    nct = A->size[0] - 1;
    if (nct > 3) {
      nct = 3;
    }
    nctp1 = nct + 1;
    if (nct >= 1) {
      i = nct;
    } else {
      i = 1;
    }
    for (q = 0; q < i; q++) {
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      ns = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = b_xnrm2(ns + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            qjj = qq + ns;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] *= nrm;
            }
          } else {
            qjj = qq + ns;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (mm = qp1; mm < 4; mm++) {
        qjj = q + n * (mm - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (ns + 1 >= 1) {
            for (k = 0; k <= ns; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[qjj + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          b_xaxpy(ns + 1, nrm, qq, A, qjj + 1);
          A_data = A->data;
        }
        e[mm - 1] = A_data[qjj];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U->size[0] * q) - 1] = A_data[(ii + A->size[0] * q) - 1];
        }
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
          if (n >= 2) {
            for (ii = qp1; ii <= n; ii++) {
              work_data[ii - 1] = 0.0;
            }
            for (mm = qp1; mm < 4; mm++) {
              k_xaxpy(ns, e[mm - 1], A, n * (mm - 1) + 2, work);
              work_data = work->data;
            }
            for (mm = qp1; mm < 4; mm++) {
              l_xaxpy(ns, -e[mm - 1] / e[1], work, A, n * (mm - 1) + 2);
              A_data = A->data;
            }
          }
        }
        for (ii = qp1; ii < 4; ii++) {
          V[ii - 1] = e[ii - 1];
        }
      }
    }
    if (A->size[0] + 1 >= 3) {
      m = 3;
    } else {
      m = A->size[0] + 1;
    }
    if (nct < 3) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (A->size[0] < m) {
      s_data[m - 1] = 0.0;
    }
    if (m > 2) {
      e[1] = A_data[A->size[0] * (m - 1) + 1];
    }
    e[m - 1] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (mm = nctp1; mm <= n; mm++) {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U->size[0] * (mm - 1)] = 0.0;
        }
        U_data[(mm + U->size[0] * (mm - 1)) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      ns = n - q;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        for (mm = qp1; mm <= n; mm++) {
          qjj = q + n * (mm - 1);
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
    for (q = 2; q >= 0; q--) {
      if ((q + 1 <= 1) && (e[0] != 0.0)) {
        xaxpy(2, -(xdotc(2, V, 2, V, 5) / V[1]), 2, V, 5);
        xaxpy(2, -(xdotc(2, V, 2, V, 8) / V[1]), 2, V, 8);
      }
      V[3 * q] = 0.0;
      V[3 * q + 1] = 0.0;
      V[3 * q + 2] = 0.0;
      V[q + 3 * q] = 1.0;
    }
    i = (unsigned char)m;
    for (q = 0; q < i; q++) {
      nrm = s_data[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm /= rt;
        s_data[q] = rt;
        if (q + 1 < m) {
          e[q] /= nrm;
        }
        if (q + 1 <= n) {
          ns = n * q;
          qjj = ns + n;
          for (k = ns + 1; k <= qjj; k++) {
            U_data[k - 1] *= nrm;
          }
        }
      }
      if (q + 1 < m) {
        nrm = e[q];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          nrm = rt / nrm;
          e[q] = rt;
          s_data[q + 1] *= nrm;
          ns = 3 * (q + 1);
          qjj = ns + 3;
          for (k = ns + 1; k <= qjj; k++) {
            V[k - 1] *= nrm;
          }
        }
      }
    }
    mm = m;
    qp1 = 0;
    snorm = 0.0;
    for (ii = 0; ii < i; ii++) {
      nrm = fabs(s_data[ii]);
      rt = fabs(e[ii]);
      if ((nrm >= rt) || rtIsNaN(rt)) {
        rt = nrm;
      }
      if ((!(snorm >= rt)) && (!rtIsNaN(rt))) {
        snorm = rt;
      }
    }
    while ((m > 0) && (qp1 < 75)) {
      nctp1 = m - 1;
      ii = m - 1;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[ii - 1]) + fabs(s_data[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((qp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }
      if (ii == m - 1) {
        ns = 4;
      } else {
        qjj = m;
        ns = m;
        exitg1 = false;
        while ((!exitg1) && (ns >= ii)) {
          qjj = ns;
          if (ns == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m) {
              nrm = fabs(e[ns - 1]);
            }
            if (ns > ii + 1) {
              nrm += fabs(e[ns - 2]);
            }
            rt = fabs(s_data[ns - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (qjj == ii) {
          ns = 3;
        } else if (qjj == m) {
          ns = 1;
        } else {
          ns = 2;
          ii = qjj;
        }
      }
      switch (ns) {
      case 1:
        f = e[m - 2];
        e[m - 2] = 0.0;
        for (k = nctp1; k >= ii + 1; k--) {
          sqds = xrotg(&s_data[k - 1], &f, &sm);
          if (k > ii + 1) {
            f = -sm * e[0];
            e[0] *= sqds;
          }
          xrot(V, 3 * (k - 1) + 1, 3 * (m - 1) + 1, sqds, sm);
        }
        break;
      case 2:
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        for (k = ii + 1; k <= m; k++) {
          sqds = xrotg(&s_data[k - 1], &f, &sm);
          b = e[k - 1];
          f = -sm * b;
          e[k - 1] = b * sqds;
          if (n >= 1) {
            nct = n * (k - 1);
            qq = n * (ii - 1);
            for (q = 0; q < n; q++) {
              ns = qq + q;
              nrm = U_data[ns];
              qjj = nct + q;
              rt = U_data[qjj];
              U_data[ns] = sqds * nrm - sm * rt;
              U_data[qjj] = sqds * rt + sm * nrm;
            }
          }
        }
        break;
      case 3:
        nrm = s_data[m - 1];
        scale = fabs(nrm);
        b = s_data[m - 2];
        rt = fabs(b);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        f = e[m - 2];
        rt = fabs(f);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(s_data[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(e[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        sm = nrm / scale;
        nrm = b / scale;
        rt = f / scale;
        sqds = s_data[ii] / scale;
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
        f = (sqds + sm) * (sqds - sm) + rt;
        b = sqds * (e[ii] / scale);
        for (k = ii + 1; k <= nctp1; k++) {
          sqds = xrotg(&f, &b, &sm);
          if (k > ii + 1) {
            e[0] = f;
          }
          nrm = e[k - 1];
          b = s_data[k - 1];
          e[k - 1] = sqds * nrm - sm * b;
          rt = sm * s_data[k];
          s_data[k] *= sqds;
          xrot(V, 3 * (k - 1) + 1, 3 * k + 1, sqds, sm);
          s_data[k - 1] = sqds * b + sm * nrm;
          sqds = xrotg(&s_data[k - 1], &rt, &sm);
          b = e[k - 1];
          f = sqds * b + sm * s_data[k];
          s_data[k] = -sm * b + sqds * s_data[k];
          b = sm * e[k];
          e[k] *= sqds;
          if (k < n) {
            nct = n * (k - 1);
            qq = n * k;
            for (q = 0; q < n; q++) {
              ns = qq + q;
              nrm = U_data[ns];
              qjj = nct + q;
              rt = U_data[qjj];
              U_data[ns] = sqds * nrm - sm * rt;
              U_data[qjj] = sqds * rt + sm * nrm;
            }
          }
        }
        e[m - 2] = f;
        qp1++;
        break;
      default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
          ns = 3 * ii;
          i = ns + 3;
          for (k = ns + 1; k <= i; k++) {
            V[k - 1] = -V[k - 1];
          }
        }
        qp1 = ii + 1;
        while ((ii + 1 < mm) && (s_data[ii] < s_data[qp1])) {
          rt = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = rt;
          xswap(V, 3 * ii + 1, 3 * (ii + 1) + 1);
          if (ii + 1 < n) {
            nct = n * ii;
            qq = n * (ii + 1);
            for (k = 0; k < n; k++) {
              ns = nct + k;
              nrm = U_data[ns];
              i = qq + k;
              U_data[ns] = U_data[i];
              U_data[i] = nrm;
            }
          }
          ii = qp1;
          qp1++;
        }
        qp1 = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  if (S_size - 1 >= 0) {
    memcpy(&S_data[0], &s_data[0], (unsigned int)S_size * sizeof(double));
  }
  return S_size;
}

/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *U
 *                double S_data[]
 *                double V[16]
 * Return Type  : int
 */
int xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
           double V[16])
{
  emxArray_real_T *work;
  double e[4];
  double s_data[4];
  double b;
  double f;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  double *A_data;
  double *U_data;
  double *work_data;
  int S_size;
  int i;
  int ii;
  int k;
  int m;
  int mm;
  int n;
  int nct;
  int nctp1;
  int nrt;
  int ns;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  A_data = A->data;
  n = A->size[0];
  if (A->size[0] + 1 <= 4) {
    ns = A->size[0];
  } else {
    ns = 3;
  }
  S_size = A->size[0];
  if (S_size > 4) {
    S_size = 4;
  }
  memset(&s_data[0], 0, (unsigned int)(ns + 1) * sizeof(double));
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  e[3] = 0.0;
  emxInit_real_T(&work, 1);
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
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      ns = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = b_xnrm2(ns + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            qjj = qq + ns;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] *= nrm;
            }
          } else {
            qjj = qq + ns;
            for (k = qq; k <= qjj; k++) {
              A_data[k - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (mm = qp1; mm < 5; mm++) {
        qjj = q + n * (mm - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (ns + 1 >= 1) {
            for (k = 0; k <= ns; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[qjj + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          b_xaxpy(ns + 1, nrm, qq, A, qjj + 1);
          A_data = A->data;
        }
        e[mm - 1] = A_data[qjj];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U->size[0] * q) - 1] = A_data[(ii + A->size[0] * q) - 1];
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
            for (mm = qp1; mm < 5; mm++) {
              c_xaxpy(ns, e[mm - 1], A, (q + n * (mm - 1)) + 2, work, q + 2);
              work_data = work->data;
            }
            for (mm = qp1; mm < 5; mm++) {
              c_xaxpy(ns, -e[mm - 1] / e[q + 1], work, q + 2, A,
                      (q + n * (mm - 1)) + 2);
              A_data = A->data;
            }
          }
        }
        for (ii = qp1; ii < 5; ii++) {
          V[(ii + (q << 2)) - 1] = e[ii - 1];
        }
      }
    }
    if (A->size[0] + 1 >= 4) {
      m = 4;
    } else {
      m = A->size[0] + 1;
    }
    if (nct < 4) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (A->size[0] < m) {
      s_data[m - 1] = 0.0;
    }
    if (nrt + 1 < m) {
      e[nrt] = A_data[nrt + A->size[0] * (m - 1)];
    }
    e[m - 1] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (mm = nctp1; mm <= n; mm++) {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U->size[0] * (mm - 1)] = 0.0;
        }
        U_data[(mm + U->size[0] * (mm - 1)) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      ns = n - q;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        for (mm = qp1; mm <= n; mm++) {
          qjj = q + n * (mm - 1);
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
        for (mm = qp1; mm < 5; mm++) {
          qjj = (q + ((mm - 1) << 2)) + 2;
          d_xaxpy(3 - q, -(b_xdotc(3 - q, V, ns, V, qjj) / V[ns - 1]), ns, V,
                  qjj);
        }
      }
      ns = q << 2;
      V[ns] = 0.0;
      V[ns + 1] = 0.0;
      V[ns + 2] = 0.0;
      V[ns + 3] = 0.0;
      V[q + ns] = 1.0;
    }
    i = (unsigned char)m;
    for (q = 0; q < i; q++) {
      nrm = s_data[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm /= rt;
        s_data[q] = rt;
        if (q + 1 < m) {
          e[q] /= nrm;
        }
        if (q + 1 <= n) {
          ns = n * q;
          qjj = ns + n;
          for (k = ns + 1; k <= qjj; k++) {
            U_data[k - 1] *= nrm;
          }
        }
      }
      if (q + 1 < m) {
        nrm = e[q];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          nrm = rt / nrm;
          e[q] = rt;
          s_data[q + 1] *= nrm;
          ns = (q + 1) << 2;
          qjj = ns + 4;
          for (k = ns + 1; k <= qjj; k++) {
            V[k - 1] *= nrm;
          }
        }
      }
    }
    mm = m;
    nrt = 0;
    snorm = 0.0;
    for (ii = 0; ii < i; ii++) {
      nrm = fabs(s_data[ii]);
      rt = fabs(e[ii]);
      if ((nrm >= rt) || rtIsNaN(rt)) {
        rt = nrm;
      }
      if ((!(snorm >= rt)) && (!rtIsNaN(rt))) {
        snorm = rt;
      }
    }
    while ((m > 0) && (nrt < 75)) {
      nctp1 = m - 1;
      ii = m - 1;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[ii - 1]) + fabs(s_data[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((nrt > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }
      if (ii == m - 1) {
        ns = 4;
      } else {
        qjj = m;
        ns = m;
        exitg1 = false;
        while ((!exitg1) && (ns >= ii)) {
          qjj = ns;
          if (ns == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m) {
              nrm = fabs(e[ns - 1]);
            }
            if (ns > ii + 1) {
              nrm += fabs(e[ns - 2]);
            }
            rt = fabs(s_data[ns - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (qjj == ii) {
          ns = 3;
        } else if (qjj == m) {
          ns = 1;
        } else {
          ns = 2;
          ii = qjj;
        }
      }
      switch (ns) {
      case 1:
        f = e[m - 2];
        e[m - 2] = 0.0;
        for (k = nctp1; k >= ii + 1; k--) {
          sqds = xrotg(&s_data[k - 1], &f, &sm);
          if (k > ii + 1) {
            b = e[k - 2];
            f = -sm * b;
            e[k - 2] = b * sqds;
          }
          b_xrot(V, ((k - 1) << 2) + 1, ((m - 1) << 2) + 1, sqds, sm);
        }
        break;
      case 2:
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        for (k = ii + 1; k <= m; k++) {
          sqds = xrotg(&s_data[k - 1], &f, &sm);
          b = e[k - 1];
          f = -sm * b;
          e[k - 1] = b * sqds;
          if (n >= 1) {
            nct = n * (k - 1);
            qq = n * (ii - 1);
            for (qp1 = 0; qp1 < n; qp1++) {
              ns = qq + qp1;
              nrm = U_data[ns];
              qjj = nct + qp1;
              rt = U_data[qjj];
              U_data[ns] = sqds * nrm - sm * rt;
              U_data[qjj] = sqds * rt + sm * nrm;
            }
          }
        }
        break;
      case 3:
        nrm = s_data[m - 1];
        scale = fabs(nrm);
        b = s_data[m - 2];
        rt = fabs(b);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        f = e[m - 2];
        rt = fabs(f);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(s_data[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(e[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        sm = nrm / scale;
        nrm = b / scale;
        rt = f / scale;
        sqds = s_data[ii] / scale;
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
        f = (sqds + sm) * (sqds - sm) + rt;
        b = sqds * (e[ii] / scale);
        for (k = ii + 1; k <= nctp1; k++) {
          sqds = xrotg(&f, &b, &sm);
          if (k > ii + 1) {
            e[k - 2] = f;
          }
          nrm = e[k - 1];
          b = s_data[k - 1];
          e[k - 1] = sqds * nrm - sm * b;
          rt = sm * s_data[k];
          s_data[k] *= sqds;
          b_xrot(V, ((k - 1) << 2) + 1, (k << 2) + 1, sqds, sm);
          s_data[k - 1] = sqds * b + sm * nrm;
          sqds = xrotg(&s_data[k - 1], &rt, &sm);
          b = e[k - 1];
          f = sqds * b + sm * s_data[k];
          s_data[k] = -sm * b + sqds * s_data[k];
          b = sm * e[k];
          e[k] *= sqds;
          if (k < n) {
            nct = n * (k - 1);
            qq = n * k;
            for (qp1 = 0; qp1 < n; qp1++) {
              ns = qq + qp1;
              nrm = U_data[ns];
              qjj = nct + qp1;
              rt = U_data[qjj];
              U_data[ns] = sqds * nrm - sm * rt;
              U_data[qjj] = sqds * rt + sm * nrm;
            }
          }
        }
        e[m - 2] = f;
        nrt++;
        break;
      default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
          ns = ii << 2;
          i = ns + 4;
          for (k = ns + 1; k <= i; k++) {
            V[k - 1] = -V[k - 1];
          }
        }
        qp1 = ii + 1;
        while ((ii + 1 < mm) && (s_data[ii] < s_data[qp1])) {
          rt = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = rt;
          b_xswap(V, (ii << 2) + 1, ((ii + 1) << 2) + 1);
          if (ii + 1 < n) {
            nct = n * ii;
            qq = n * (ii + 1);
            for (k = 0; k < n; k++) {
              ns = nct + k;
              nrm = U_data[ns];
              i = qq + k;
              U_data[ns] = U_data[i];
              U_data[i] = nrm;
            }
          }
          ii = qp1;
          qp1++;
        }
        nrt = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  if (S_size - 1 >= 0) {
    memcpy(&S_data[0], &s_data[0], (unsigned int)S_size * sizeof(double));
  }
  return S_size;
}

/*
 * File trailer for xzsvdc.c
 *
 * [EOF]
 */
