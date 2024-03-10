/*
 * File: xzsvdc.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "xzsvdc.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xnrm2.h"
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *U
 *                double S_data[]
 *                int *S_size
 *                double V_data[]
 *                int V_size[2]
 * Return Type  : void
 */
void xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
            int *S_size, double V_data[], int V_size[2])
{
  emxArray_real_T *work;
  emxArray_real_T *x;
  double Vf_data[9];
  double e_data[3];
  double s_data[3];
  double f;
  double nrm;
  double rt;
  double scale;
  double sm;
  double sn;
  double snorm;
  double sqds;
  double *A_data;
  double *U_data;
  double *work_data;
  double *x_data;
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
  int ns;
  int q;
  int qjj;
  int qp1;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  A_data = A->data;
  n = A->size[0];
  ns = A->size[0] + 1;
  if (ns > 3) {
    ns = 3;
  }
  minnp = A->size[0];
  if (minnp > 3) {
    minnp = 3;
  }
  if (ns - 1 >= 0) {
    memset(&s_data[0], 0, ns * sizeof(double));
  }
  emxInit_real_T(&work, 1);
  e_data[0] = 0.0;
  e_data[1] = 0.0;
  e_data[2] = 0.0;
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
  U->size[1] = minnp;
  emxEnsureCapacity_real_T(U, i);
  U_data = U->data;
  ns = A->size[0] * minnp;
  for (i = 0; i < ns; i++) {
    U_data[i] = 0.0;
  }
  memset(&Vf_data[0], 0, 9U * sizeof(double));
  if (A->size[0] == 0) {
    Vf_data[0] = 1.0;
    Vf_data[4] = 1.0;
    Vf_data[8] = 1.0;
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
    emxInit_real_T(&x, 2);
    for (q = 0; q < i; q++) {
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = xnrm2(nmq + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            m = x->size[0] * x->size[1];
            x->size[0] = A->size[0];
            x->size[1] = 3;
            emxEnsureCapacity_real_T(x, m);
            x_data = x->data;
            ns = A->size[0] * 3;
            for (m = 0; m < ns; m++) {
              x_data[m] = A_data[m];
            }
            m = qq + nmq;
            for (k = qq; k <= m; k++) {
              x_data[k - 1] *= nrm;
            }
            m = A->size[0] * A->size[1];
            A->size[0] = x->size[0];
            A->size[1] = 3;
            emxEnsureCapacity_real_T(A, m);
            A_data = A->data;
            ns = x->size[0] * 3;
            for (m = 0; m < ns; m++) {
              A_data[m] = x_data[m];
            }
          } else {
            m = qq + nmq;
            for (k = qq; k <= m; k++) {
              A_data[k - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (jj = qp1; jj < 4; jj++) {
        qjj = q + n * (jj - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (nmq + 1 >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[qjj + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          m = x->size[0] * x->size[1];
          x->size[0] = A->size[0];
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, m);
          x_data = x->data;
          ns = A->size[0] * 3;
          for (m = 0; m < ns; m++) {
            x_data[m] = A_data[m];
          }
          xaxpy(nmq + 1, nrm, qq, x, qjj + 1);
          x_data = x->data;
          m = A->size[0] * A->size[1];
          A->size[0] = x->size[0];
          A->size[1] = x->size[1];
          emxEnsureCapacity_real_T(A, m);
          A_data = A->data;
          ns = x->size[0] * x->size[1];
          for (m = 0; m < ns; m++) {
            A_data[m] = x_data[m];
          }
        }
        e_data[jj - 1] = A_data[qjj];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U->size[0] * q) - 1] = A_data[(ii + A->size[0] * q) - 1];
        }
      }
      if (q + 1 <= 1) {
        nrm = e_xnrm2(e_data);
        if (nrm == 0.0) {
          e_data[0] = 0.0;
        } else {
          if (e_data[1] < 0.0) {
            e_data[0] = -nrm;
          } else {
            e_data[0] = nrm;
          }
          nrm = e_data[0];
          if (fabs(e_data[0]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e_data[0];
            for (k = qp1; k < 4; k++) {
              e_data[k - 1] *= nrm;
            }
          } else {
            for (k = qp1; k < 4; k++) {
              e_data[k - 1] /= nrm;
            }
          }
          e_data[1]++;
          e_data[0] = -e_data[0];
          if (n >= 2) {
            for (ii = qp1; ii <= n; ii++) {
              work_data[ii - 1] = 0.0;
            }
            for (jj = qp1; jj < 4; jj++) {
              e_xaxpy(nmq, e_data[jj - 1], A, n * (jj - 1) + 2, work);
              work_data = work->data;
            }
            for (jj = qp1; jj < 4; jj++) {
              f_xaxpy(nmq, -e_data[jj - 1] / e_data[1], work, A,
                      n * (jj - 1) + 2);
              A_data = A->data;
            }
          }
        }
        for (ii = qp1; ii < 4; ii++) {
          Vf_data[ii - 1] = e_data[ii - 1];
        }
      }
    }
    if (n + 1 >= 3) {
      m = 2;
    } else {
      m = n;
    }
    if (nct < 3) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (n < m + 1) {
      s_data[m] = 0.0;
    }
    if (m + 1 > 2) {
      e_data[1] = A_data[A->size[0] * m + 1];
    }
    e_data[m] = 0.0;
    if (nct + 1 <= minnp) {
      for (jj = nctp1; jj <= minnp; jj++) {
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
      if (s_data[q - 1] != 0.0) {
        for (jj = qp1; jj <= minnp; jj++) {
          qjj = q + n * (jj - 1);
          nrm = 0.0;
          if (ns + 1 >= 1) {
            for (k = 0; k <= ns; k++) {
              nrm += U_data[qq + k] * U_data[(qjj + k) - 1];
            }
          }
          nrm = -(nrm / U_data[qq]);
          xaxpy(ns + 1, nrm, qq + 1, U, qjj);
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
      if ((q + 1 <= 1) && (e_data[0] != 0.0)) {
        for (jj = 0; jj < 2; jj++) {
          ns = 3 * (jj + 1);
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          xaxpy(
              2,
              -((Vf_data[1] * Vf_data[ns + 1] + Vf_data[2] * Vf_data[ns + 2]) /
                Vf_data[1]),
              2, x, ns + 2);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
        }
      }
      Vf_data[3 * q] = 0.0;
      Vf_data[3 * q + 1] = 0.0;
      Vf_data[3 * q + 2] = 0.0;
      Vf_data[q + 3 * q] = 1.0;
    }
    qq = m;
    nct = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      nrm = s_data[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm /= rt;
        s_data[q] = rt;
        if (q + 1 < m + 1) {
          e_data[q] /= nrm;
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
        nrm = e_data[q];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          nrm = rt / nrm;
          e_data[q] = rt;
          s_data[q + 1] *= nrm;
          ns = 3 * (q + 1);
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          i = ns + 3;
          for (k = ns + 1; k <= i; k++) {
            x_data[k - 1] *= nrm;
          }
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
        }
      }
      nrm = fabs(s_data[q]);
      rt = fabs(e_data[q]);
      if ((nrm >= rt) || rtIsNaN(rt)) {
        rt = nrm;
      }
      if ((!(snorm >= rt)) && (!rtIsNaN(rt))) {
        snorm = rt;
      }
    }
    while ((m + 1 > 0) && (nct < 75)) {
      ii = m;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e_data[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[ii - 1]) + fabs(s_data[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((nct > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e_data[ii - 1] = 0.0;
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
              nrm = fabs(e_data[ns - 1]);
            }
            if (ns > ii + 1) {
              nrm += fabs(e_data[ns - 2]);
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
        f = e_data[m - 1];
        e_data[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&s_data[k - 1], &f, &scale, &sn);
          if (k > ii + 1) {
            f = -sn * e_data[0];
            e_data[0] *= scale;
          }
          nmq = 3 * (k - 1);
          nctp1 = 3 * m;
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          rt = scale * x_data[nmq] + sn * x_data[nctp1];
          x_data[nctp1] = scale * x_data[nctp1] - sn * x_data[nmq];
          x_data[nmq] = rt;
          nrm = x_data[nctp1 + 1];
          rt = x_data[nmq + 1];
          x_data[nctp1 + 1] = scale * nrm - sn * rt;
          x_data[nmq + 1] = scale * rt + sn * nrm;
          nrm = x_data[nctp1 + 2];
          rt = x_data[nmq + 2];
          x_data[nctp1 + 2] = scale * nrm - sn * rt;
          x_data[nmq + 2] = scale * rt + sn * nrm;
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
        }
        break;
      case 2:
        f = e_data[ii - 1];
        e_data[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 1; k++) {
          xrotg(&s_data[k - 1], &f, &scale, &sn);
          sm = e_data[k - 1];
          f = -sn * sm;
          e_data[k - 1] = sm * scale;
          if (n >= 1) {
            nmq = n * (k - 1);
            nctp1 = n * (ii - 1);
            for (qp1 = 0; qp1 < n; qp1++) {
              qjj = nctp1 + qp1;
              ns = nmq + qp1;
              rt = scale * U_data[ns] + sn * U_data[qjj];
              U_data[qjj] = scale * U_data[qjj] - sn * U_data[ns];
              U_data[ns] = rt;
            }
          }
        }
        break;
      case 3:
        scale = fabs(s_data[m]);
        nrm = s_data[m - 1];
        rt = fabs(nrm);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        f = e_data[m - 1];
        rt = fabs(f);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(s_data[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        rt = fabs(e_data[ii]);
        if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }
        sm = s_data[m] / scale;
        nrm /= scale;
        rt = f / scale;
        sqds = s_data[ii] / scale;
        f = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((f != 0.0) || (nrm != 0.0)) {
          rt = sqrt(f * f + nrm);
          if (f < 0.0) {
            rt = -rt;
          }
          rt = nrm / (f + rt);
        } else {
          rt = 0.0;
        }
        f = (sqds + sm) * (sqds - sm) + rt;
        nrm = sqds * (e_data[ii] / scale);
        for (k = ii + 1; k <= m; k++) {
          xrotg(&f, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e_data[0] = f;
          }
          f = e_data[k - 1];
          sm = s_data[k - 1];
          e_data[k - 1] = scale * f - sn * sm;
          sqds = sn * s_data[k];
          s_data[k] *= scale;
          nmq = 3 * (k - 1);
          nctp1 = 3 * k;
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          rt = scale * x_data[nmq] + sn * x_data[nctp1];
          x_data[nctp1] = scale * x_data[nctp1] - sn * x_data[nmq];
          x_data[nmq] = rt;
          nrm = x_data[nctp1 + 1];
          rt = x_data[nmq + 1];
          x_data[nctp1 + 1] = scale * nrm - sn * rt;
          x_data[nmq + 1] = scale * rt + sn * nrm;
          nrm = x_data[nctp1 + 2];
          rt = x_data[nmq + 2];
          x_data[nctp1 + 2] = scale * nrm - sn * rt;
          x_data[nmq + 2] = scale * rt + sn * nrm;
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
          s_data[k - 1] = scale * sm + sn * f;
          xrotg(&s_data[k - 1], &sqds, &scale, &sn);
          f = scale * e_data[k - 1] + sn * s_data[k];
          s_data[k] = -sn * e_data[k - 1] + scale * s_data[k];
          nrm = sn * e_data[k];
          e_data[k] *= scale;
          if (k < n) {
            nmq = n * (k - 1);
            nctp1 = n * k;
            for (qp1 = 0; qp1 < n; qp1++) {
              qjj = nctp1 + qp1;
              ns = nmq + qp1;
              rt = scale * U_data[ns] + sn * U_data[qjj];
              U_data[qjj] = scale * U_data[qjj] - sn * U_data[ns];
              U_data[ns] = rt;
            }
          }
        }
        e_data[m - 1] = f;
        nct++;
        break;
      default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
          ns = 3 * ii;
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          i = ns + 3;
          for (k = ns + 1; k <= i; k++) {
            x_data[k - 1] = -x_data[k - 1];
          }
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
        }
        qp1 = ii + 1;
        while ((ii + 1 < qq + 1) && (s_data[ii] < s_data[qp1])) {
          rt = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = rt;
          nmq = 3 * ii;
          nctp1 = 3 * (ii + 1);
          i = x->size[0] * x->size[1];
          x->size[0] = 3;
          x->size[1] = 3;
          emxEnsureCapacity_real_T(x, i);
          x_data = x->data;
          for (i = 0; i < 9; i++) {
            x_data[i] = Vf_data[i];
          }
          rt = x_data[nmq];
          x_data[nmq] = x_data[nctp1];
          x_data[nctp1] = rt;
          rt = x_data[nmq + 1];
          x_data[nmq + 1] = x_data[nctp1 + 1];
          x_data[nctp1 + 1] = rt;
          rt = x_data[nmq + 2];
          x_data[nmq + 2] = x_data[nctp1 + 2];
          x_data[nctp1 + 2] = rt;
          for (i = 0; i < 9; i++) {
            Vf_data[i] = x_data[i];
          }
          if (ii + 1 < n) {
            nmq = n * ii;
            nctp1 = n * (ii + 1);
            for (k = 0; k < n; k++) {
              qjj = nmq + k;
              rt = U_data[qjj];
              i = nctp1 + k;
              U_data[qjj] = U_data[i];
              U_data[i] = rt;
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
    emxFree_real_T(&x);
  }
  emxFree_real_T(&work);
  *S_size = minnp;
  V_size[0] = 3;
  V_size[1] = minnp;
  for (k = 0; k < minnp; k++) {
    S_data[k] = s_data[k];
    V_data[3 * k] = Vf_data[3 * k];
    i = 3 * k + 1;
    V_data[i] = Vf_data[i];
    i = 3 * k + 2;
    V_data[i] = Vf_data[i];
  }
}

/*
 * File trailer for xzsvdc.c
 *
 * [EOF]
 */
