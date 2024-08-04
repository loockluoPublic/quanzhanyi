/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 05-Aug-2024 00:57:42
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "fitcircle.h"
#include "ixfun.h"
#include "mldivide.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd1.h"
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
  emxArray_real_T *OptAllErr;
  emxArray_real_T *P;
  emxArray_real_T *S;
  emxArray_real_T *U;
  emxArray_real_T *b_y;
  emxArray_real_T *denom;
  emxArray_real_T *err;
  emxArray_real_T *n;
  emxArray_real_T *r;
  emxArray_real_T *x;
  emxArray_real_T *x2_contents;
  emxArray_real_T *x_contents;
  emxArray_real_T *y;
  double V[16];
  double dv[9];
  double m[9];
  double b_n[3];
  double h[3];
  const double *points_data;
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
  double norm_vec;
  double rcoselev;
  double rcoselev_tmp;
  double s;
  double scale;
  double t;
  double theta_tmp;
  double *Err_every_data;
  double *OptAllErr_data;
  double *P_data;
  double *denom_data;
  double *err_data;
  double *x2_contents_data;
  double *x_contents_data;
  double *y_data;
  int outsize[2];
  int aoffset;
  int b_i;
  int b_m;
  int boffset;
  int coffset;
  int i;
  int j;
  int k;
  int lastBlockLength;
  boolean_T exitg1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  points_data = points->data;
  OptErr = 99999.0;
  OptAngle_idx_0 = 0.0;
  OptAngle_idx_1 = 0.0;
  OptPara_idx_0 = 0.0;
  OptPara_idx_1 = 0.0;
  *Mradial = 0.0;
  emxInit_real_T(&OptAllErr, 1);
  i = OptAllErr->size[0];
  OptAllErr->size[0] = points->size[1];
  emxEnsureCapacity_real_T(OptAllErr, i);
  OptAllErr_data = OptAllErr->data;
  coffset = points->size[1];
  for (i = 0; i < coffset; i++) {
    OptAllErr_data[i] = 0.0;
  }
  b_m = points->size[1];
  emxInit_real_T(&P, 2);
  emxInit_real_T(&err, 1);
  emxInit_real_T(&x_contents, 2);
  emxInit_real_T(&x2_contents, 1);
  emxInit_real_T(&U, 2);
  emxInit_real_T(&S, 2);
  emxInit_real_T(&denom, 1);
  emxInit_real_T(&y, 2);
  y_data = y->data;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&r, 2);
  emxInit_real_T(&n, 2);
  emxInit_real_T(&b_y, 1);
  for (b_i = 0; b_i < 180; b_i++) {
    d = 0.035101593894858021 * (double)b_i;
    d1 = cos(d);
    d2 = sin(d);
    for (j = 0; j < 180; j++) {
      rcoselev_tmp = 0.035101593894858021 * (double)j;
      rcoselev = cos(rcoselev_tmp);
      absx = sin(rcoselev_tmp);
      b_n[0] = rcoselev * d1;
      b_n[1] = rcoselev * d2;
      h[0] = 0.0 * absx - b_n[1];
      h[1] = b_n[0] - 0.0 * absx;
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
      absx = rt_atan2d_snf(theta_tmp, absx);
      s = sin(absx);
      c = cos(absx);
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
      rcoselev = absxk;
      absxk = fabs(absxk);
      if (absxk > 3.3121686421112381E-170) {
        norm_vec = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        norm_vec = t * t;
      }
      absxk = h[1] / theta_tmp;
      absx = absxk;
      absxk = fabs(absxk);
      if (absxk > scale) {
        t = scale / absxk;
        norm_vec = norm_vec * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        norm_vec += t * t;
      }
      absxk = (0.0 * b_n[1] - 0.0 * b_n[0]) / theta_tmp;
      t = absxk / scale;
      norm_vec += t * t;
      norm_vec = scale * sqrt(norm_vec);
      if (norm_vec <= 1.0E-12) {
        b_n[0] = 0.0;
        b_n[1] = 0.0;
        b_n[2] = 0.0;
      } else {
        b_n[0] = rcoselev / norm_vec;
        b_n[1] = absx / norm_vec;
        b_n[2] = absxk / norm_vec;
      }
      absxk = (1.0 - c) * b_n[0];
      m[0] = absxk * b_n[0] + c;
      rcoselev = absxk * b_n[1];
      norm_vec = s * b_n[2];
      m[3] = rcoselev - norm_vec;
      absxk *= b_n[2];
      theta_tmp = s * b_n[1];
      m[6] = absxk + theta_tmp;
      m[1] = rcoselev + norm_vec;
      rcoselev = (1.0 - c) * b_n[1];
      m[4] = rcoselev * b_n[1] + c;
      rcoselev *= b_n[2];
      norm_vec = s * b_n[0];
      m[7] = rcoselev - norm_vec;
      m[2] = absxk - theta_tmp;
      m[5] = rcoselev + norm_vec;
      m[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      i = P->size[0] * P->size[1];
      P->size[0] = points->size[1];
      P->size[1] = 3;
      emxEnsureCapacity_real_T(P, i);
      P_data = P->data;
      for (lastBlockLength = 0; lastBlockLength < 3; lastBlockLength++) {
        coffset = lastBlockLength * b_m;
        boffset = lastBlockLength * 3;
        for (i = 0; i < b_m; i++) {
          aoffset = i * 3;
          P_data[coffset + i] = (points_data[aoffset] * m[boffset] +
                                 points_data[aoffset + 1] * m[boffset + 1]) +
                                points_data[aoffset + 2] * m[boffset + 2];
        }
      }
      i = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, i);
      x_contents_data = x_contents->data;
      coffset = P->size[0];
      for (i = 0; i < coffset; i++) {
        x_contents_data[2 * i] = P_data[i];
        x_contents_data[2 * i + 1] = P_data[i + P->size[0]];
      }
      aoffset = x_contents->size[1];
      i = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, i);
      err_data = err->data;
      coffset = x_contents->size[1];
      i = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, i);
      x2_contents_data = x2_contents->data;
      for (i = 0; i < coffset; i++) {
        err_data[i] = x_contents_data[2 * i];
        x2_contents_data[i] = x_contents_data[2 * i + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      if (err->size[0] == x2_contents->size[0]) {
        i = r->size[0] * r->size[1];
        r->size[0] = err->size[0];
        r->size[1] = 4;
        emxEnsureCapacity_real_T(r, i);
        Err_every_data = r->data;
        coffset = err->size[0];
        for (i = 0; i < coffset; i++) {
          theta_tmp = err_data[i];
          norm_vec = x2_contents_data[i];
          Err_every_data[i] = theta_tmp * theta_tmp + norm_vec * norm_vec;
          Err_every_data[i + r->size[0]] = x_contents_data[2 * i];
          Err_every_data[i + r->size[0] * 2] = x_contents_data[2 * i + 1];
          Err_every_data[i + r->size[0] * 3] = 1.0;
        }
        b_svd(r, U, S, V);
      } else {
        binary_expand_op_3(err, x2_contents, x_contents, U, S, V);
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
      absx = 2.0 * V[12];
      absxk = fabs(V[13]);
      if (absxk > 3.3121686421112381E-170) {
        theta_tmp = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        theta_tmp = t * t;
      }
      b_n[0] = -V[13] / absx;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        theta_tmp = theta_tmp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        theta_tmp += t * t;
      }
      b_n[1] = -V[14] / absx;
      theta_tmp = scale * sqrt(theta_tmp);
      absxk = theta_tmp / (2.0 * V[12]);
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
        i = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = aoffset;
        emxEnsureCapacity_real_T(x, i);
        Err_every_data = x->data;
        for (boffset = 0; boffset < aoffset; boffset++) {
          coffset = boffset << 1;
          Err_every_data[coffset] = b_n[0];
          Err_every_data[coffset + 1] = b_n[1];
        }
        /*  Jacobian */
        if (err->size[0] == x2_contents->size[0]) {
          i = denom->size[0];
          denom->size[0] = err->size[0];
          emxEnsureCapacity_real_T(denom, i);
          denom_data = denom->data;
          coffset = err->size[0];
          for (i = 0; i < coffset; i++) {
            theta_tmp = b_n[0] - err_data[i];
            norm_vec = b_n[1] - x2_contents_data[i];
            denom_data[i] = theta_tmp * theta_tmp + norm_vec * norm_vec;
          }
        } else {
          binary_expand_op_2(denom, b_n, err, x2_contents);
          denom_data = denom->data;
        }
        coffset = denom->size[0];
        for (k = 0; k < coffset; k++) {
          denom_data[k] = sqrt(denom_data[k]);
        }
        outsize[0] = aoffset;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          coffset = x->size[1] << 1;
          i = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, i);
          Err_every_data = x->data;
          for (i = 0; i < coffset; i++) {
            theta_tmp = Err_every_data[i] - x_contents_data[i];
            Err_every_data[i] = theta_tmp * theta_tmp;
          }
        } else {
          binary_expand_op_1(x, x_contents);
          Err_every_data = x->data;
        }
        if (x->size[1] == 0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          boffset = x->size[1];
          i = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(y, i);
          y_data = y->data;
          for (i = 0; i < boffset; i++) {
            coffset = i << 1;
            y_data[i] = Err_every_data[coffset] + Err_every_data[coffset + 1];
          }
        }
        coffset = y->size[1];
        for (k = 0; k < coffset; k++) {
          y_data[k] = sqrt(y_data[k]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          i = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, i);
          Err_every_data = n->data;
          coffset = err->size[0];
          for (i = 0; i < coffset; i++) {
            Err_every_data[i] = -((b_n[0] - err_data[i]) / denom_data[i]);
          }
          coffset = x2_contents->size[0];
          for (i = 0; i < coffset; i++) {
            Err_every_data[i + n->size[0]] =
                -((b_n[1] - x2_contents_data[i]) / denom_data[i]);
          }
          for (i = 0; i < aoffset; i++) {
            Err_every_data[i + n->size[0] * 2] = 1.0;
          }
          i = b_y->size[0];
          b_y->size[0] = y->size[1];
          emxEnsureCapacity_real_T(b_y, i);
          Err_every_data = b_y->data;
          coffset = y->size[1];
          for (i = 0; i < coffset; i++) {
            Err_every_data[i] = y_data[i] - b_n[2];
          }
          mldivide(n, b_y, h);
        } else {
          binary_expand_op(b_n, err, denom, x2_contents, outsize, y, h);
        }
        /*  Check for convergence */
        theta_tmp = 0.0;
        absxk = 0.0;
        for (k = 0; k < 3; k++) {
          absx = h[k];
          rcoselev = b_n[k] + absx;
          b_n[k] = rcoselev;
          absx = fabs(absx);
          if (rtIsNaN(absx) || (absx > theta_tmp)) {
            theta_tmp = absx;
          }
          absx = fabs(rcoselev);
          if (rtIsNaN(absx) || (absx > absxk)) {
            absxk = absx;
          }
        }
        if (theta_tmp / absxk < 1.0E-5) {
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
      i = denom->size[0];
      denom->size[0] = P->size[0];
      emxEnsureCapacity_real_T(denom, i);
      denom_data = denom->data;
      coffset = P->size[0];
      i = b_y->size[0];
      b_y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(b_y, i);
      Err_every_data = b_y->data;
      for (i = 0; i < coffset; i++) {
        denom_data[i] = P_data[i] - b_n[0];
        Err_every_data[i] = P_data[i + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == b_y->size[0]) {
        i = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, i);
        err_data = err->data;
        coffset = denom->size[0];
        for (i = 0; i < coffset; i++) {
          theta_tmp = denom_data[i];
          norm_vec = Err_every_data[i];
          err_data[i] = rt_hypotd_snf(theta_tmp, norm_vec);
        }
      } else {
        expand_hypot(denom, b_y, err);
        err_data = err->data;
      }
      coffset = err->size[0];
      for (i = 0; i < coffset; i++) {
        err_data[i] -= b_n[2];
      }
      i = b_y->size[0];
      b_y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(b_y, i);
      Err_every_data = b_y->data;
      coffset = err->size[0];
      for (i = 0; i < coffset; i++) {
        theta_tmp = err_data[i];
        Err_every_data[i] = theta_tmp * theta_tmp;
      }
      if (b_y->size[0] == 0) {
        theta_tmp = 0.0;
      } else {
        if (b_y->size[0] <= 1024) {
          coffset = b_y->size[0];
          lastBlockLength = 0;
          aoffset = 1;
        } else {
          coffset = 1024;
          aoffset = (int)((unsigned int)b_y->size[0] >> 10);
          lastBlockLength = b_y->size[0] - (aoffset << 10);
          if (lastBlockLength > 0) {
            aoffset++;
          } else {
            lastBlockLength = 1024;
          }
        }
        theta_tmp = Err_every_data[0];
        for (k = 2; k <= coffset; k++) {
          theta_tmp += Err_every_data[k - 1];
        }
        for (i = 2; i <= aoffset; i++) {
          coffset = (i - 1) << 10;
          norm_vec = Err_every_data[coffset];
          if (i == aoffset) {
            boffset = lastBlockLength;
          } else {
            boffset = 1024;
          }
          for (k = 2; k <= boffset; k++) {
            norm_vec += Err_every_data[(coffset + k) - 1];
          }
          theta_tmp += norm_vec;
        }
      }
      absxk = sqrt(theta_tmp / (double)b_y->size[0]);
      if (absxk < OptErr) {
        OptErr = absxk;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        i = OptAllErr->size[0];
        OptAllErr->size[0] = err->size[0];
        emxEnsureCapacity_real_T(OptAllErr, i);
        OptAllErr_data = OptAllErr->data;
        coffset = err->size[0];
        for (i = 0; i < coffset; i++) {
          OptAllErr_data[i] = err_data[i];
        }
        OptAngle_idx_0 = d;
        OptAngle_idx_1 = rcoselev_tmp;
      }
    }
  }
  emxFree_real_T(&b_y);
  emxFree_real_T(&n);
  emxFree_real_T(&r);
  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_real_T(&denom);
  emxFree_real_T(&S);
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
  rcoselev = absxk;
  absxk = fabs(absxk);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk = h[1] / theta_tmp;
  absx = absxk;
  absxk = fabs(absxk);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  absxk = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / theta_tmp;
  t = absxk / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    b_n[0] = 0.0;
    b_n[1] = 0.0;
    b_n[2] = 0.0;
  } else {
    b_n[0] = rcoselev / norm_vec;
    b_n[1] = absx / norm_vec;
    b_n[2] = absxk / norm_vec;
  }
  d1 = (1.0 - c) * b_n[0];
  dv[0] = d1 * b_n[0] + c;
  d2 = d1 * b_n[1];
  absx = s * b_n[2];
  dv[3] = d2 - absx;
  d1 *= b_n[2];
  rcoselev = s * b_n[1];
  dv[6] = d1 + rcoselev;
  dv[1] = d2 + absx;
  d2 = (1.0 - c) * b_n[1];
  dv[4] = d2 * b_n[1] + c;
  d2 *= b_n[2];
  absx = s * b_n[0];
  dv[7] = d2 - absx;
  dv[2] = d1 - rcoselev;
  dv[5] = d2 + absx;
  dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(dv, m);
  for (i = 0; i < 3; i++) {
    Mcenter[i] = (OptPara_idx_0 * m[3 * i] + OptPara_idx_1 * m[3 * i + 1]) +
                 0.0 * m[3 * i + 2];
  }
  i = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = OptAllErr->size[0];
  emxEnsureCapacity_real_T(Err_every, i);
  Err_every_data = Err_every->data;
  coffset = OptAllErr->size[0];
  for (i = 0; i < coffset; i++) {
    Err_every_data[i] = OptAllErr_data[i];
  }
  emxFree_real_T(&OptAllErr);
  /*  三个点定义 */
  /*  斜率计算 */
  theta_tmp = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  absx = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  absxk = (theta_tmp * theta_tmp + absx * absx) + rcoselev * rcoselev;
  norm_vec = -(((Mcenter[0] - P_bound1[0]) * theta_tmp +
                (Mcenter[1] - P_bound1[1]) * absx) +
               (Mcenter[2] - P_bound1[2]) * rcoselev) /
             absxk;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  absxk = -(((Mcenter[0] - P_bound2[0]) * theta_tmp +
             (Mcenter[1] - P_bound2[1]) * absx) +
            (Mcenter[2] - P_bound2[2]) * rcoselev) /
          absxk;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = norm_vec * theta_tmp + Mcenter[0];
  Bottom_round_center1[1] = norm_vec * absx + Mcenter[1];
  Bottom_round_center1[2] = norm_vec * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = absxk * theta_tmp + Mcenter[0];
  Bottom_round_center2[1] = absxk * absx + Mcenter[1];
  Bottom_round_center2[2] = absxk * rcoselev + Mcenter[2];
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
