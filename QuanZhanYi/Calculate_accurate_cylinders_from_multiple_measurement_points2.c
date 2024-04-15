/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 15-Apr-2024 22:57:09
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "fitcircle.h"
#include "ixfun.h"
#include "mean.h"
#include "mldivide.h"
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
  const double *points_data;
  double Merr;
  double OptAngle_idx_0;
  double OptAngle_idx_1;
  double OptErr;
  double OptPara_idx_0;
  double OptPara_idx_1;
  double absx;
  double absxk;
  double c;
  double d;
  double d1;
  double d2;
  double d3;
  double rcoselev;
  double s;
  double scale;
  double t;
  double theta_tmp;
  double *A_data;
  double *Err_every_data;
  double *P_data;
  double *denom_data;
  double *err_data;
  double *x2_contents_data;
  double *x_contents_data;
  double *y_data;
  int outsize[2];
  int aoffset;
  int b_i;
  int b_j;
  int boffset;
  int c_i;
  int coffset;
  int i;
  int j;
  int m;
  points_data = points->data;
  OptErr = 99999.0;
  OptAngle_idx_0 = 0.0;
  OptAngle_idx_1 = 0.0;
  OptPara_idx_0 = 0.0;
  OptPara_idx_1 = 0.0;
  *Mradial = 0.0;
  i = Err_every->size[0];
  Err_every->size[0] = points->size[1];
  emxEnsureCapacity_real_T(Err_every, i);
  Err_every_data = Err_every->data;
  aoffset = points->size[1];
  for (i = 0; i < aoffset; i++) {
    Err_every_data[i] = 0.0;
  }
  m = points->size[1];
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
  for (b_i = 0; b_i < 180; b_i++) {
    d = 0.035101593894858021 * (double)b_i;
    d1 = cos(d);
    d2 = sin(d);
    for (j = 0; j < 180; j++) {
      double rcoselev_tmp;
      boolean_T exitg1;
      boolean_T p;
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
      absxk = h[0] / theta_tmp;
      Merr = absxk;
      absxk = fabs(absxk);
      if (absxk > 3.3121686421112381E-170) {
        rcoselev = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        rcoselev = t * t;
      }
      absxk = h[1] / theta_tmp;
      absx = absxk;
      absxk = fabs(absxk);
      if (absxk > scale) {
        t = scale / absxk;
        rcoselev = rcoselev * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        rcoselev += t * t;
      }
      absxk = h[2] / theta_tmp;
      t = absxk / scale;
      rcoselev += t * t;
      rcoselev = scale * sqrt(rcoselev);
      if (rcoselev <= 1.0E-12) {
        b_n[0] = 0.0;
        b_n[1] = 0.0;
        b_n[2] = 0.0;
      } else {
        b_n[0] = Merr / rcoselev;
        b_n[1] = absx / rcoselev;
        b_n[2] = absxk / rcoselev;
      }
      absxk = (1.0 - c) * b_n[0];
      rot2[0] = absxk * b_n[0] + c;
      Merr = absxk * b_n[1];
      rcoselev = s * b_n[2];
      rot2[3] = Merr - rcoselev;
      absxk *= b_n[2];
      theta_tmp = s * b_n[1];
      rot2[6] = absxk + theta_tmp;
      rot2[1] = Merr + rcoselev;
      Merr = (1.0 - c) * b_n[1];
      rot2[4] = Merr * b_n[1] + c;
      Merr *= b_n[2];
      rcoselev = s * b_n[0];
      rot2[7] = Merr - rcoselev;
      rot2[2] = absxk - theta_tmp;
      rot2[5] = Merr + rcoselev;
      rot2[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      i = P->size[0] * P->size[1];
      P->size[0] = points->size[1];
      P->size[1] = 3;
      emxEnsureCapacity_real_T(P, i);
      P_data = P->data;
      for (b_j = 0; b_j < 3; b_j++) {
        coffset = b_j * m;
        boffset = b_j * 3;
        for (c_i = 0; c_i < m; c_i++) {
          aoffset = c_i * 3;
          P_data[coffset + c_i] =
              (points_data[aoffset] * rot2[boffset] +
               points_data[aoffset + 1] * rot2[boffset + 1]) +
              points_data[aoffset + 2] * rot2[boffset + 2];
        }
      }
      aoffset = P->size[0];
      coffset = P->size[0];
      i = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, i);
      x_contents_data = x_contents->data;
      for (i = 0; i < aoffset; i++) {
        x_contents_data[2 * i] = P_data[i];
      }
      for (i = 0; i < coffset; i++) {
        x_contents_data[2 * i + 1] = P_data[i + P->size[0]];
      }
      c_i = x_contents->size[1];
      aoffset = x_contents->size[1];
      i = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, i);
      err_data = err->data;
      for (i = 0; i < aoffset; i++) {
        err_data[i] = x_contents_data[2 * i];
      }
      aoffset = x_contents->size[1];
      i = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, i);
      x2_contents_data = x2_contents->data;
      for (i = 0; i < aoffset; i++) {
        x2_contents_data[i] = x_contents_data[2 * i + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      i = y->size[0];
      y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(y, i);
      Err_every_data = y->data;
      aoffset = err->size[0];
      for (i = 0; i < aoffset; i++) {
        absxk = err_data[i];
        Err_every_data[i] = absxk * absxk;
      }
      i = denom->size[0];
      denom->size[0] = x2_contents->size[0];
      emxEnsureCapacity_real_T(denom, i);
      denom_data = denom->data;
      aoffset = x2_contents->size[0];
      for (i = 0; i < aoffset; i++) {
        absxk = x2_contents_data[i];
        denom_data[i] = absxk * absxk;
      }
      if (y->size[0] == denom->size[0]) {
        aoffset = x_contents->size[1];
        coffset = x_contents->size[1];
        i = A->size[0] * A->size[1];
        A->size[0] = y->size[0];
        A->size[1] = 4;
        emxEnsureCapacity_real_T(A, i);
        A_data = A->data;
        boffset = y->size[0];
        for (i = 0; i < boffset; i++) {
          A_data[i] = Err_every_data[i] + denom_data[i];
        }
        for (i = 0; i < aoffset; i++) {
          A_data[i + A->size[0]] = x_contents_data[2 * i];
        }
        for (i = 0; i < coffset; i++) {
          A_data[i + A->size[0] * 2] = x_contents_data[2 * i + 1];
        }
        aoffset = x_contents->size[1];
        for (i = 0; i < aoffset; i++) {
          A_data[i + A->size[0] * 3] = 1.0;
        }
      } else {
        c_binary_expand_op(A, y, denom, x_contents);
        A_data = A->data;
      }
      coffset = A->size[0] << 2;
      p = true;
      for (boffset = 0; boffset < coffset; boffset++) {
        if ((!p) || (rtIsInf(A_data[boffset]) || rtIsNaN(A_data[boffset]))) {
          p = false;
        }
      }
      if (p) {
        svd(A, U, s_data, &coffset, V);
      } else {
        for (i = 0; i < 16; i++) {
          V[i] = rtNaN;
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
        Merr = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        Merr = t * t;
      }
      b_n[0] = -V[13] / d3;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        Merr = Merr * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        Merr += t * t;
      }
      b_n[1] = -V[14] / d3;
      Merr = scale * sqrt(Merr);
      Merr /= 2.0 * V[12];
      b_n[2] = sqrt(Merr * Merr - V[15] / V[12]);
      /*  Delta is the norm of current step, scaled by the norm of u */
      b_j = 0;
      exitg1 = false;
      while ((!exitg1) && (b_j < 100)) {
        /*  Find the function and Jacobian  */
        /* SYS   Nonlinear system to be minimised - the objective */
        /* function is the distance to each point from the fitted circle */
        /* contained in u */
        /*  Objective function */
        i = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = c_i;
        emxEnsureCapacity_real_T(x, i);
        Err_every_data = x->data;
        for (boffset = 0; boffset < c_i; boffset++) {
          coffset = boffset << 1;
          Err_every_data[coffset] = b_n[0];
          Err_every_data[coffset + 1] = b_n[1];
        }
        /*  Jacobian */
        i = denom->size[0];
        denom->size[0] = err->size[0];
        emxEnsureCapacity_real_T(denom, i);
        denom_data = denom->data;
        aoffset = err->size[0];
        for (i = 0; i < aoffset; i++) {
          absxk = b_n[0] - err_data[i];
          denom_data[i] = absxk * absxk;
        }
        i = y->size[0];
        y->size[0] = x2_contents->size[0];
        emxEnsureCapacity_real_T(y, i);
        Err_every_data = y->data;
        aoffset = x2_contents->size[0];
        for (i = 0; i < aoffset; i++) {
          absxk = b_n[1] - x2_contents_data[i];
          Err_every_data[i] = absxk * absxk;
        }
        if (denom->size[0] == y->size[0]) {
          aoffset = denom->size[0];
          for (i = 0; i < aoffset; i++) {
            denom_data[i] += Err_every_data[i];
          }
        } else {
          plus(denom, y);
          denom_data = denom->data;
        }
        coffset = denom->size[0];
        for (boffset = 0; boffset < coffset; boffset++) {
          denom_data[boffset] = sqrt(denom_data[boffset]);
        }
        outsize[0] = c_i;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          aoffset = 2 * x->size[1];
          i = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, i);
          Err_every_data = x->data;
          for (i = 0; i < aoffset; i++) {
            absxk = Err_every_data[i] - x_contents_data[i];
            Err_every_data[i] = absxk * absxk;
          }
        } else {
          b_binary_expand_op(x, x_contents);
          Err_every_data = x->data;
        }
        if (x->size[1] == 0) {
          b_y->size[0] = 1;
          b_y->size[1] = 0;
        } else {
          boffset = x->size[1];
          i = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          b_y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(b_y, i);
          y_data = b_y->data;
          for (aoffset = 0; aoffset < boffset; aoffset++) {
            coffset = aoffset << 1;
            y_data[aoffset] =
                Err_every_data[coffset] + Err_every_data[coffset + 1];
          }
        }
        coffset = b_y->size[1];
        for (boffset = 0; boffset < coffset; boffset++) {
          y_data[boffset] = sqrt(y_data[boffset]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          i = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, i);
          Err_every_data = n->data;
          aoffset = err->size[0];
          for (i = 0; i < aoffset; i++) {
            Err_every_data[i] = -((b_n[0] - err_data[i]) / denom_data[i]);
          }
          aoffset = x2_contents->size[0];
          for (i = 0; i < aoffset; i++) {
            Err_every_data[i + n->size[0]] =
                -((b_n[1] - x2_contents_data[i]) / denom_data[i]);
          }
          for (i = 0; i < c_i; i++) {
            Err_every_data[i + n->size[0] * 2] = 1.0;
          }
          i = y->size[0];
          y->size[0] = b_y->size[1];
          emxEnsureCapacity_real_T(y, i);
          Err_every_data = y->data;
          aoffset = b_y->size[1];
          for (i = 0; i < aoffset; i++) {
            Err_every_data[i] = y_data[i] - b_n[2];
          }
          mldivide(n, y, h);
        } else {
          binary_expand_op(h, b_n, err, denom, x2_contents, outsize, b_y);
        }
        /*  Check for convergence */
        Merr = 0.0;
        absxk = 0.0;
        d3 = b_n[0] + h[0];
        b_n[0] = d3;
        absx = fabs(h[0]);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          Merr = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          absxk = absx;
        }
        d3 = b_n[1] + h[1];
        b_n[1] = d3;
        absx = fabs(h[1]);
        if (rtIsNaN(absx) || (absx > Merr)) {
          Merr = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > absxk)) {
          absxk = absx;
        }
        d3 = b_n[2] + h[2];
        b_n[2] = d3;
        absx = fabs(h[2]);
        if (rtIsNaN(absx) || (absx > Merr)) {
          Merr = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > absxk)) {
          absxk = absx;
        }
        if (Merr / absxk < 1.0E-5) {
          exitg1 = true;
        } else {
          b_j++;
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
      aoffset = P->size[0];
      i = denom->size[0];
      denom->size[0] = P->size[0];
      emxEnsureCapacity_real_T(denom, i);
      denom_data = denom->data;
      for (i = 0; i < aoffset; i++) {
        denom_data[i] = P_data[i] - b_n[0];
      }
      aoffset = P->size[0];
      i = y->size[0];
      y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(y, i);
      Err_every_data = y->data;
      for (i = 0; i < aoffset; i++) {
        Err_every_data[i] = P_data[i + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == y->size[0]) {
        i = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, i);
        err_data = err->data;
        aoffset = denom->size[0];
        for (i = 0; i < aoffset; i++) {
          absxk = denom_data[i];
          theta_tmp = Err_every_data[i];
          err_data[i] = rt_hypotd_snf(absxk, theta_tmp);
        }
      } else {
        expand_hypot(denom, y, err);
        err_data = err->data;
      }
      aoffset = err->size[0];
      for (i = 0; i < aoffset; i++) {
        err_data[i] -= b_n[2];
      }
      i = y->size[0];
      y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(y, i);
      Err_every_data = y->data;
      aoffset = err->size[0];
      for (i = 0; i < aoffset; i++) {
        absxk = err_data[i];
        Err_every_data[i] = absxk * absxk;
      }
      Merr = sqrt(mean(y));
      if (Merr < OptErr) {
        OptErr = Merr;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        i = Err_every->size[0];
        Err_every->size[0] = err->size[0];
        emxEnsureCapacity_real_T(Err_every, i);
        Err_every_data = Err_every->data;
        aoffset = err->size[0];
        for (i = 0; i < aoffset; i++) {
          Err_every_data[i] = err_data[i];
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
  absxk = h[0] / theta_tmp;
  Merr = absxk;
  absxk = fabs(absxk);
  if (absxk > 3.3121686421112381E-170) {
    rcoselev = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    rcoselev = t * t;
  }
  absxk = h[1] / theta_tmp;
  absx = absxk;
  absxk = fabs(absxk);
  if (absxk > scale) {
    t = scale / absxk;
    rcoselev = rcoselev * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    rcoselev += t * t;
  }
  absxk = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / theta_tmp;
  t = absxk / scale;
  rcoselev += t * t;
  rcoselev = scale * sqrt(rcoselev);
  if (rcoselev <= 1.0E-12) {
    b_n[0] = 0.0;
    b_n[1] = 0.0;
    b_n[2] = 0.0;
  } else {
    b_n[0] = Merr / rcoselev;
    b_n[1] = absx / rcoselev;
    b_n[2] = absxk / rcoselev;
  }
  d1 = (1.0 - c) * b_n[0];
  dv[0] = d1 * b_n[0] + c;
  d2 = d1 * b_n[1];
  d3 = s * b_n[2];
  dv[3] = d2 - d3;
  d1 *= b_n[2];
  Merr = s * b_n[1];
  dv[6] = d1 + Merr;
  dv[1] = d2 + d3;
  d2 = (1.0 - c) * b_n[1];
  dv[4] = d2 * b_n[1] + c;
  d2 *= b_n[2];
  d3 = s * b_n[0];
  dv[7] = d2 - d3;
  dv[2] = d1 - Merr;
  dv[5] = d2 + d3;
  dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(dv, rot2);
  for (i = 0; i < 3; i++) {
    Mcenter[i] =
        (OptPara_idx_0 * rot2[3 * i] + OptPara_idx_1 * rot2[3 * i + 1]) +
        0.0 * rot2[3 * i + 2];
  }
  /*  三个点定义 */
  /*  斜率计算 */
  theta_tmp = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  absx = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  Merr = (theta_tmp * theta_tmp + absx * absx) + rcoselev * rcoselev;
  absxk = -(((Mcenter[0] - P_bound1[0]) * theta_tmp +
             (Mcenter[1] - P_bound1[1]) * absx) +
            (Mcenter[2] - P_bound1[2]) * rcoselev) /
          Merr;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  Merr = -(((Mcenter[0] - P_bound2[0]) * theta_tmp +
            (Mcenter[1] - P_bound2[1]) * absx) +
           (Mcenter[2] - P_bound2[2]) * rcoselev) /
         Merr;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = absxk * theta_tmp + Mcenter[0];
  Bottom_round_center1[1] = absxk * absx + Mcenter[1];
  Bottom_round_center1[2] = absxk * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = Merr * theta_tmp + Mcenter[0];
  Bottom_round_center2[1] = Merr * absx + Mcenter[1];
  Bottom_round_center2[2] = Merr * rcoselev + Mcenter[2];
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
