/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "fitcircle.h"
#include "ixfun.h"
#include "mldivide.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * points = points';
 *
 * Arguments    : const emxArray_real_T *points
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Mcenter[3]
 *                double MTaon[3]
 *                double *Mradial
 *                emxArray_real_T *Err_every
 *                double Bottom_round_center1[3]
 *                double Bottom_round_center2[3]
 * Return Type  : void
 */
void Calculate_accurate_cylinders_from_multiple_measurement_points2(
    const emxArray_real_T *points, const double P_bound1[3],
    const double P_bound2[3], double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every, double Bottom_round_center1[3],
    double Bottom_round_center2[3])
{
  emxArray_real_T *A;
  emxArray_real_T *OptAllErr;
  emxArray_real_T *P;
  emxArray_real_T *U;
  emxArray_real_T *b_y;
  emxArray_real_T *denom;
  emxArray_real_T *err;
  emxArray_real_T *n;
  emxArray_real_T *x;
  emxArray_real_T *x2_contents;
  emxArray_real_T *x_contents;
  emxArray_real_T *y;
  double V[16];
  double dv[9];
  double rot2[9];
  double s_data[4];
  double b_n[3];
  double h[3];
  double OptAngle_idx_0;
  double OptAngle_idx_1;
  double OptErr;
  double OptPara_idx_0;
  double OptPara_idx_1;
  double absxk;
  double c;
  double d;
  double d1;
  double d2;
  double d3;
  double norm_vec;
  double r_idx_0;
  double r_idx_1;
  double rcoselev;
  double rcoselev_tmp;
  double s;
  double scale;
  double t;
  double theta_tmp;
  double *A_data;
  double *Err_every_data;
  double *OptAllErr_data;
  double *P_data;
  double *denom_data;
  double *err_data;
  double *x2_contents_data;
  double *x_contents_data;
  double *y_data;
  int outsize[2];
  int hi;
  int i;
  int j;
  int k;
  int lastBlockLength;
  int m_contents;
  int npages;
  int nx;
  boolean_T exitg1;
  boolean_T p;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInit_real_T(&OptAllErr, 1);
  OptErr = 99999.0;
  OptAngle_idx_0 = 0.0;
  OptAngle_idx_1 = 0.0;
  OptPara_idx_0 = 0.0;
  OptPara_idx_1 = 0.0;
  *Mradial = 0.0;
  k = OptAllErr->size[0];
  OptAllErr->size[0] = points->size[1];
  emxEnsureCapacity_real_T(OptAllErr, k);
  OptAllErr_data = OptAllErr->data;
  hi = points->size[1];
  for (k = 0; k < hi; k++) {
    OptAllErr_data[k] = 0.0;
  }
  emxInit_real_T(&P, 2);
  emxInit_real_T(&err, 1);
  emxInit_real_T(&x_contents, 2);
  emxInit_real_T(&x2_contents, 1);
  emxInit_real_T(&U, 2);
  emxInit_real_T(&denom, 1);
  emxInit_real_T(&y, 1);
  emxInit_real_T(&A, 2);
  emxInit_real_T(&b_y, 2);
  y_data = b_y->data;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&n, 2);
  for (i = 0; i < 180; i++) {
    d = 0.035101593894858021 * (double)i;
    d1 = cos(d);
    d2 = sin(d);
    for (j = 0; j < 180; j++) {
      rcoselev_tmp = 0.035101593894858021 * (double)j;
      rcoselev = cos(rcoselev_tmp);
      d3 = sin(rcoselev_tmp);
      b_n[0] = rcoselev * d1;
      b_n[1] = rcoselev * d2;
      h[0] = 0.0 * d3 - b_n[1];
      h[1] = b_n[0] - 0.0 * d3;
      h[2] = 0.0 * b_n[1] - 0.0 * b_n[0];
      scale = 3.3121686421112381E-170;
      absxk = fabs(h[0]);
      if (absxk > 3.3121686421112381E-170) {
        theta_tmp = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        theta_tmp = t * t;
      }
      absxk = fabs(h[1]);
      if (absxk > scale) {
        t = scale / absxk;
        theta_tmp = theta_tmp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        theta_tmp += t * t;
      }
      theta_tmp = scale * sqrt(theta_tmp);
      d3 = rt_atan2d_snf(theta_tmp, d3);
      s = sin(d3);
      c = cos(d3);
      /* SL3DNORMALIZE Normalize a vector. */
      /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the
       */
      /*    input vector X. Input X can be vector of any size. If the modulus of
       */
      /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)).
       */
      /*  */
      /*    Not to be called directly. */
      /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
      scale = 3.3121686421112381E-170;
      rcoselev = h[0] / theta_tmp;
      r_idx_0 = rcoselev;
      absxk = fabs(rcoselev);
      if (absxk > 3.3121686421112381E-170) {
        norm_vec = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        norm_vec = t * t;
      }
      rcoselev = h[1] / theta_tmp;
      r_idx_1 = rcoselev;
      absxk = fabs(rcoselev);
      if (absxk > scale) {
        t = scale / absxk;
        norm_vec = norm_vec * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        norm_vec += t * t;
      }
      rcoselev = h[2] / theta_tmp;
      t = rcoselev / scale;
      norm_vec += t * t;
      norm_vec = scale * sqrt(norm_vec);
      if (norm_vec <= 1.0E-12) {
        b_n[0] = 0.0;
        b_n[1] = 0.0;
        b_n[2] = 0.0;
      } else {
        b_n[0] = r_idx_0 / norm_vec;
        b_n[1] = r_idx_1 / norm_vec;
        b_n[2] = rcoselev / norm_vec;
      }
      d3 = (1.0 - c) * b_n[0];
      dv[0] = d3 * b_n[0] + c;
      rcoselev = d3 * b_n[1];
      r_idx_0 = s * b_n[2];
      dv[3] = rcoselev - r_idx_0;
      d3 *= b_n[2];
      norm_vec = s * b_n[1];
      dv[6] = d3 + norm_vec;
      dv[1] = rcoselev + r_idx_0;
      rcoselev = (1.0 - c) * b_n[1];
      dv[4] = rcoselev * b_n[1] + c;
      rcoselev *= b_n[2];
      r_idx_0 = s * b_n[0];
      dv[7] = rcoselev - r_idx_0;
      dv[2] = d3 - norm_vec;
      dv[5] = rcoselev + r_idx_0;
      dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      mtimes(points, dv, P);
      P_data = P->data;
      hi = P->size[0];
      k = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, k);
      x_contents_data = x_contents->data;
      for (k = 0; k < hi; k++) {
        x_contents_data[2 * k] = P_data[k];
        x_contents_data[2 * k + 1] = P_data[k + P->size[0]];
      }
      m_contents = x_contents->size[1];
      hi = x_contents->size[1];
      k = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, k);
      err_data = err->data;
      for (k = 0; k < hi; k++) {
        err_data[k] = x_contents_data[2 * k];
      }
      hi = x_contents->size[1];
      k = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, k);
      x2_contents_data = x2_contents->data;
      for (k = 0; k < hi; k++) {
        x2_contents_data[k] = x_contents_data[2 * k + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      k = y->size[0];
      y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(y, k);
      Err_every_data = y->data;
      hi = err->size[0];
      for (k = 0; k < hi; k++) {
        norm_vec = err_data[k];
        Err_every_data[k] = norm_vec * norm_vec;
      }
      k = denom->size[0];
      denom->size[0] = x2_contents->size[0];
      emxEnsureCapacity_real_T(denom, k);
      denom_data = denom->data;
      hi = x2_contents->size[0];
      for (k = 0; k < hi; k++) {
        norm_vec = x2_contents_data[k];
        denom_data[k] = norm_vec * norm_vec;
      }
      if (y->size[0] == denom->size[0]) {
        hi = x_contents->size[1];
        nx = x_contents->size[1];
        k = A->size[0] * A->size[1];
        A->size[0] = y->size[0];
        A->size[1] = 4;
        emxEnsureCapacity_real_T(A, k);
        A_data = A->data;
        npages = y->size[0];
        for (k = 0; k < npages; k++) {
          A_data[k] = Err_every_data[k] + denom_data[k];
        }
        for (k = 0; k < hi; k++) {
          A_data[k + A->size[0]] = x_contents_data[2 * k];
        }
        for (k = 0; k < nx; k++) {
          A_data[k + A->size[0] * 2] = x_contents_data[2 * k + 1];
        }
        hi = x_contents->size[1];
        for (k = 0; k < hi; k++) {
          A_data[k + A->size[0] * 3] = 1.0;
        }
      } else {
        g_binary_expand_op(A, y, denom, x_contents);
        A_data = A->data;
      }
      nx = A->size[0] << 2;
      p = true;
      for (k = 0; k < nx; k++) {
        if ((!p) || (rtIsInf(A_data[k]) || rtIsNaN(A_data[k]))) {
          p = false;
        }
      }
      if (p) {
        b_svd(A, U, s_data, &nx, V);
      } else {
        for (k = 0; k < 16; k++) {
          V[k] = rtNaN;
        }
      }
      /*  For clarity, set the quadratic form variables */
      /*  Convert to centre/radius */
      scale = 3.3121686421112381E-170;
      /*  2) Nonlinear refinement to miminise geometric error, and compute
       * residual */
      /*  [z, r, residual] = fitcircle_geometric(x, z, r); */
      /*  NESTED FUNCTIONS */
      /*      function [z, r, residual] = fitcircle_geometric(x, z0, r0) */
      /*  Use a simple Gauss Newton method to minimize the geometric error */
      /*  Set initial u */
      d3 = 2.0 * V[12];
      absxk = fabs(V[13]);
      if (absxk > 3.3121686421112381E-170) {
        rcoselev = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        rcoselev = t * t;
      }
      b_n[0] = -V[13] / d3;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        rcoselev = rcoselev * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        rcoselev += t * t;
      }
      b_n[1] = -V[14] / d3;
      rcoselev = scale * sqrt(rcoselev);
      absxk = rcoselev / (2.0 * V[12]);
      b_n[2] = sqrt(absxk * absxk - V[15] / V[12]);
      /*  Delta is the norm of current step, scaled by the norm of u */
      lastBlockLength = 0;
      exitg1 = false;
      while ((!exitg1) && (lastBlockLength < 100)) {
        /*  Find the function and Jacobian  */
        /* SYS   Nonlinear system to be minimised - the objective */
        /* function is the distance to each point from the fitted circle */
        /* contained in u */
        /*  Objective function */
        k = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = m_contents;
        emxEnsureCapacity_real_T(x, k);
        Err_every_data = x->data;
        for (npages = 0; npages < m_contents; npages++) {
          nx = npages << 1;
          Err_every_data[nx] = b_n[0];
          Err_every_data[nx + 1] = b_n[1];
        }
        /*  Jacobian */
        k = denom->size[0];
        denom->size[0] = err->size[0];
        emxEnsureCapacity_real_T(denom, k);
        denom_data = denom->data;
        hi = err->size[0];
        for (k = 0; k < hi; k++) {
          norm_vec = b_n[0] - err_data[k];
          denom_data[k] = norm_vec * norm_vec;
        }
        k = y->size[0];
        y->size[0] = x2_contents->size[0];
        emxEnsureCapacity_real_T(y, k);
        Err_every_data = y->data;
        hi = x2_contents->size[0];
        for (k = 0; k < hi; k++) {
          norm_vec = b_n[1] - x2_contents_data[k];
          Err_every_data[k] = norm_vec * norm_vec;
        }
        if (denom->size[0] == y->size[0]) {
          hi = denom->size[0];
          for (k = 0; k < hi; k++) {
            denom_data[k] += Err_every_data[k];
          }
        } else {
          b_plus(denom, y);
          denom_data = denom->data;
        }
        nx = denom->size[0];
        for (k = 0; k < nx; k++) {
          denom_data[k] = sqrt(denom_data[k]);
        }
        outsize[0] = m_contents;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          hi = 2 * x->size[1];
          k = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, k);
          Err_every_data = x->data;
          for (k = 0; k < hi; k++) {
            norm_vec = Err_every_data[k] - x_contents_data[k];
            Err_every_data[k] = norm_vec * norm_vec;
          }
        } else {
          f_binary_expand_op(x, x_contents);
          Err_every_data = x->data;
        }
        if (x->size[1] == 0) {
          b_y->size[0] = 1;
          b_y->size[1] = 0;
        } else {
          npages = x->size[1];
          k = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          b_y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(b_y, k);
          y_data = b_y->data;
          for (hi = 0; hi < npages; hi++) {
            nx = hi << 1;
            y_data[hi] = Err_every_data[nx] + Err_every_data[nx + 1];
          }
        }
        nx = b_y->size[1];
        for (k = 0; k < nx; k++) {
          y_data[k] = sqrt(y_data[k]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          k = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, k);
          Err_every_data = n->data;
          hi = err->size[0];
          for (k = 0; k < hi; k++) {
            Err_every_data[k] = -((b_n[0] - err_data[k]) / denom_data[k]);
          }
          hi = x2_contents->size[0];
          for (k = 0; k < hi; k++) {
            Err_every_data[k + n->size[0]] =
                -((b_n[1] - x2_contents_data[k]) / denom_data[k]);
          }
          for (k = 0; k < m_contents; k++) {
            Err_every_data[k + n->size[0] * 2] = 1.0;
          }
          k = y->size[0];
          y->size[0] = b_y->size[1];
          emxEnsureCapacity_real_T(y, k);
          Err_every_data = y->data;
          hi = b_y->size[1];
          for (k = 0; k < hi; k++) {
            Err_every_data[k] = y_data[k] - b_n[2];
          }
          mldivide(n, y, h);
        } else {
          e_binary_expand_op(h, b_n, err, denom, x2_contents, outsize, b_y);
        }
        /*  Check for convergence */
        rcoselev = 0.0;
        r_idx_1 = 0.0;
        d3 = b_n[0] + h[0];
        b_n[0] = d3;
        absxk = fabs(h[0]);
        if (rtIsNaN(absxk) || (absxk > 0.0)) {
          rcoselev = absxk;
        }
        absxk = fabs(d3);
        if (rtIsNaN(absxk) || (absxk > 0.0)) {
          r_idx_1 = absxk;
        }
        d3 = b_n[1] + h[1];
        b_n[1] = d3;
        absxk = fabs(h[1]);
        if (rtIsNaN(absxk) || (absxk > rcoselev)) {
          rcoselev = absxk;
        }
        absxk = fabs(d3);
        if (rtIsNaN(absxk) || (absxk > r_idx_1)) {
          r_idx_1 = absxk;
        }
        d3 = b_n[2] + h[2];
        b_n[2] = d3;
        absxk = fabs(h[2]);
        if (rtIsNaN(absxk) || (absxk > rcoselev)) {
          rcoselev = absxk;
        }
        absxk = fabs(d3);
        if (rtIsNaN(absxk) || (absxk > r_idx_1)) {
          r_idx_1 = absxk;
        }
        if (rcoselev / r_idx_1 < 1.0E-5) {
          exitg1 = true;
        } else {
          lastBlockLength++;
        }
      }
      /* SYS   Nonlinear system to be minimised - the objective */
      /* function is the distance to each point from the fitted circle */
      /* contained in u */
      /*  Objective function */
      /*  Jacobian */
      /*  sys */
      /*      end % fitcircle_geometric */
      /*  END NESTED FUNCTIONS */
      hi = P->size[0];
      k = denom->size[0];
      denom->size[0] = P->size[0];
      emxEnsureCapacity_real_T(denom, k);
      denom_data = denom->data;
      k = y->size[0];
      y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(y, k);
      Err_every_data = y->data;
      for (k = 0; k < hi; k++) {
        denom_data[k] = P_data[k] - b_n[0];
        Err_every_data[k] = P_data[k + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == y->size[0]) {
        k = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, k);
        err_data = err->data;
        hi = denom->size[0];
        for (k = 0; k < hi; k++) {
          norm_vec = denom_data[k];
          r_idx_0 = Err_every_data[k];
          err_data[k] = rt_hypotd_snf(norm_vec, r_idx_0);
        }
      } else {
        expand_hypot(denom, y, err);
        err_data = err->data;
      }
      hi = err->size[0];
      for (k = 0; k < hi; k++) {
        err_data[k] -= b_n[2];
      }
      k = y->size[0];
      y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(y, k);
      Err_every_data = y->data;
      hi = err->size[0];
      for (k = 0; k < hi; k++) {
        norm_vec = err_data[k];
        Err_every_data[k] = norm_vec * norm_vec;
      }
      if (y->size[0] == 0) {
        rcoselev = 0.0;
      } else {
        if (y->size[0] <= 1024) {
          nx = y->size[0];
          lastBlockLength = 0;
          npages = 1;
        } else {
          nx = 1024;
          npages = y->size[0] / 1024;
          lastBlockLength = y->size[0] - (npages << 10);
          if (lastBlockLength > 0) {
            npages++;
          } else {
            lastBlockLength = 1024;
          }
        }
        rcoselev = Err_every_data[0];
        for (k = 2; k <= nx; k++) {
          rcoselev += Err_every_data[k - 1];
        }
        for (m_contents = 2; m_contents <= npages; m_contents++) {
          nx = (m_contents - 1) << 10;
          norm_vec = Err_every_data[nx];
          if (m_contents == npages) {
            hi = lastBlockLength;
          } else {
            hi = 1024;
          }
          for (k = 2; k <= hi; k++) {
            norm_vec += Err_every_data[(nx + k) - 1];
          }
          rcoselev += norm_vec;
        }
      }
      absxk = sqrt(rcoselev / (double)y->size[0]);
      if (absxk < OptErr) {
        OptErr = absxk;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        k = OptAllErr->size[0];
        OptAllErr->size[0] = err->size[0];
        emxEnsureCapacity_real_T(OptAllErr, k);
        OptAllErr_data = OptAllErr->data;
        hi = err->size[0];
        for (k = 0; k < hi; k++) {
          OptAllErr_data[k] = err_data[k];
        }
        OptAngle_idx_0 = d;
        OptAngle_idx_1 = rcoselev_tmp;
      }
    }
  }
  emxFree_real_T(&n);
  emxFree_real_T(&x);
  emxFree_real_T(&b_y);
  emxFree_real_T(&A);
  emxFree_real_T(&y);
  emxFree_real_T(&denom);
  emxFree_real_T(&U);
  emxFree_real_T(&x2_contents);
  emxFree_real_T(&x_contents);
  emxFree_real_T(&err);
  emxFree_real_T(&P);
  rcoselev = cos(OptAngle_idx_1);
  d = sin(OptAngle_idx_1);
  MTaon[0] = rcoselev * cos(OptAngle_idx_0);
  MTaon[1] = rcoselev * sin(OptAngle_idx_0);
  MTaon[2] = d;
  h[0] = 0.0 * d - MTaon[1];
  h[1] = MTaon[0] - 0.0 * d;
  scale = 3.3121686421112381E-170;
  absxk = fabs(h[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta_tmp = t * t;
  }
  absxk = fabs(h[1]);
  if (absxk > scale) {
    t = scale / absxk;
    theta_tmp = theta_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta_tmp += t * t;
  }
  theta_tmp = scale * sqrt(theta_tmp);
  d1 = rt_atan2d_snf(theta_tmp, d);
  s = sin(d1);
  c = cos(d1);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  rcoselev = h[0] / theta_tmp;
  r_idx_0 = rcoselev;
  absxk = fabs(rcoselev);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  rcoselev = h[1] / theta_tmp;
  r_idx_1 = rcoselev;
  absxk = fabs(rcoselev);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  rcoselev = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / theta_tmp;
  t = rcoselev / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    b_n[0] = 0.0;
    b_n[1] = 0.0;
    b_n[2] = 0.0;
  } else {
    b_n[0] = r_idx_0 / norm_vec;
    b_n[1] = r_idx_1 / norm_vec;
    b_n[2] = rcoselev / norm_vec;
  }
  d1 = (1.0 - c) * b_n[0];
  dv[0] = d1 * b_n[0] + c;
  d2 = d1 * b_n[1];
  d3 = s * b_n[2];
  dv[3] = d2 - d3;
  d1 *= b_n[2];
  rcoselev = s * b_n[1];
  dv[6] = d1 + rcoselev;
  dv[1] = d2 + d3;
  d2 = (1.0 - c) * b_n[1];
  dv[4] = d2 * b_n[1] + c;
  d2 *= b_n[2];
  d3 = s * b_n[0];
  dv[7] = d2 - d3;
  dv[2] = d1 - rcoselev;
  dv[5] = d2 + d3;
  dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(dv, rot2);
  for (k = 0; k < 3; k++) {
    Mcenter[k] =
        (OptPara_idx_0 * rot2[3 * k] + OptPara_idx_1 * rot2[3 * k + 1]) +
        0.0 * rot2[3 * k + 2];
  }
  k = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = OptAllErr->size[0];
  emxEnsureCapacity_real_T(Err_every, k);
  Err_every_data = Err_every->data;
  hi = OptAllErr->size[0];
  for (k = 0; k < hi; k++) {
    Err_every_data[k] = OptAllErr_data[k];
  }
  emxFree_real_T(&OptAllErr);
  /*  三个点定义 */
  /*  斜率计算 */
  r_idx_0 = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  r_idx_1 = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  absxk = (r_idx_0 * r_idx_0 + r_idx_1 * r_idx_1) + rcoselev * rcoselev;
  norm_vec = -(((Mcenter[0] - P_bound1[0]) * r_idx_0 +
                (Mcenter[1] - P_bound1[1]) * r_idx_1) +
               (Mcenter[2] - P_bound1[2]) * rcoselev) /
             absxk;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  absxk = -(((Mcenter[0] - P_bound2[0]) * r_idx_0 +
             (Mcenter[1] - P_bound2[1]) * r_idx_1) +
            (Mcenter[2] - P_bound2[2]) * rcoselev) /
          absxk;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = norm_vec * r_idx_0 + Mcenter[0];
  Bottom_round_center1[1] = norm_vec * r_idx_1 + Mcenter[1];
  Bottom_round_center1[2] = norm_vec * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = absxk * r_idx_0 + Mcenter[0];
  Bottom_round_center2[1] = absxk * r_idx_1 + Mcenter[1];
  Bottom_round_center2[2] = absxk * rcoselev + Mcenter[2];
  /*  ！  需求1  判断方向 ，改法向量方向 */
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
