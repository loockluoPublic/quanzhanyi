/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
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
#include "mtimes.h"
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
  double dv1[9];
  double b_n[3];
  double h[3];
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
  double r_idx_1;
  double rcoselev;
  double rcoselev_tmp;
  double s;
  double scale;
  double t;
  double *Err_every_data;
  double *OptAllErr_data;
  double *P_data;
  double *denom_data;
  double *err_data;
  double *x2_contents_data;
  double *x_contents_data;
  double *y_data;
  int outsize[2];
  int i;
  int ibtile;
  int j;
  int k;
  int lastBlockLength;
  int nblocks;
  int npages;
  int xi;
  boolean_T exitg1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  OptErr = 99999.0;
  OptAngle_idx_0 = 0.0;
  OptAngle_idx_1 = 0.0;
  OptPara_idx_0 = 0.0;
  OptPara_idx_1 = 0.0;
  *Mradial = 0.0;
  emxInit_real_T(&OptAllErr, 1);
  xi = OptAllErr->size[0];
  OptAllErr->size[0] = points->size[1];
  emxEnsureCapacity_real_T(OptAllErr, xi);
  OptAllErr_data = OptAllErr->data;
  ibtile = points->size[1];
  for (xi = 0; xi < ibtile; xi++) {
    OptAllErr_data[xi] = 0.0;
  }
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
  for (i = 0; i < 180; i++) {
    d = 0.035101593894858021 * (double)i;
    d1 = cos(d);
    d2 = sin(d);
    for (j = 0; j < 180; j++) {
      rcoselev_tmp = 0.035101593894858021 * (double)j;
      rcoselev = cos(rcoselev_tmp);
      r_idx_1 = sin(rcoselev_tmp);
      b_n[0] = rcoselev * d1;
      b_n[1] = rcoselev * d2;
      h[0] = 0.0 * r_idx_1 - b_n[1];
      h[1] = b_n[0] - 0.0 * r_idx_1;
      scale = 3.3121686421112381E-170;
      absxk = fabs(h[0]);
      if (absxk > 3.3121686421112381E-170) {
        absx = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        absx = t * t;
      }
      absxk = fabs(h[1]);
      if (absxk > scale) {
        t = scale / absxk;
        absx = absx * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        absx += t * t;
      }
      absx = scale * sqrt(absx);
      r_idx_1 = rt_atan2d_snf(absx, r_idx_1);
      s = sin(r_idx_1);
      c = cos(r_idx_1);
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
      absxk = h[0] / absx;
      rcoselev = absxk;
      absxk = fabs(absxk);
      if (absxk > 3.3121686421112381E-170) {
        norm_vec = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        norm_vec = t * t;
      }
      absxk = h[1] / absx;
      r_idx_1 = absxk;
      absxk = fabs(absxk);
      if (absxk > scale) {
        t = scale / absxk;
        norm_vec = norm_vec * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        norm_vec += t * t;
      }
      absxk = (0.0 * b_n[1] - 0.0 * b_n[0]) / absx;
      t = absxk / scale;
      norm_vec += t * t;
      norm_vec = scale * sqrt(norm_vec);
      if (norm_vec <= 1.0E-12) {
        b_n[0] = 0.0;
        b_n[1] = 0.0;
        b_n[2] = 0.0;
      } else {
        b_n[0] = rcoselev / norm_vec;
        b_n[1] = r_idx_1 / norm_vec;
        b_n[2] = absxk / norm_vec;
      }
      r_idx_1 = (1.0 - c) * b_n[0];
      dv[0] = r_idx_1 * b_n[0] + c;
      norm_vec = r_idx_1 * b_n[1];
      absxk = s * b_n[2];
      dv[3] = norm_vec - absxk;
      r_idx_1 *= b_n[2];
      rcoselev = s * b_n[1];
      dv[6] = r_idx_1 + rcoselev;
      dv[1] = norm_vec + absxk;
      norm_vec = (1.0 - c) * b_n[1];
      dv[4] = norm_vec * b_n[1] + c;
      norm_vec *= b_n[2];
      absxk = s * b_n[0];
      dv[7] = norm_vec - absxk;
      dv[2] = r_idx_1 - rcoselev;
      dv[5] = norm_vec + absxk;
      dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      mtimes(points, dv, P);
      P_data = P->data;
      xi = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, xi);
      x_contents_data = x_contents->data;
      ibtile = P->size[0];
      for (xi = 0; xi < ibtile; xi++) {
        x_contents_data[2 * xi] = P_data[xi];
        x_contents_data[2 * xi + 1] = P_data[xi + P->size[0]];
      }
      nblocks = x_contents->size[1];
      xi = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, xi);
      err_data = err->data;
      ibtile = x_contents->size[1];
      xi = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, xi);
      x2_contents_data = x2_contents->data;
      for (xi = 0; xi < ibtile; xi++) {
        err_data[xi] = x_contents_data[2 * xi];
        x2_contents_data[xi] = x_contents_data[2 * xi + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      if (err->size[0] == x2_contents->size[0]) {
        xi = r->size[0] * r->size[1];
        r->size[0] = err->size[0];
        r->size[1] = 4;
        emxEnsureCapacity_real_T(r, xi);
        Err_every_data = r->data;
        ibtile = err->size[0];
        for (xi = 0; xi < ibtile; xi++) {
          r_idx_1 = err_data[xi];
          norm_vec = x2_contents_data[xi];
          Err_every_data[xi] = r_idx_1 * r_idx_1 + norm_vec * norm_vec;
          Err_every_data[xi + r->size[0]] = x_contents_data[2 * xi];
          Err_every_data[xi + r->size[0] * 2] = x_contents_data[2 * xi + 1];
          Err_every_data[xi + r->size[0] * 3] = 1.0;
        }
        b_svd(r, U, S, V);
      } else {
        binary_expand_op_8(err, x2_contents, x_contents, U, S, V);
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
      r_idx_1 = 2.0 * V[12];
      absxk = fabs(V[13]);
      if (absxk > 3.3121686421112381E-170) {
        rcoselev = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        rcoselev = t * t;
      }
      b_n[0] = -V[13] / r_idx_1;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        rcoselev = rcoselev * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        rcoselev += t * t;
      }
      b_n[1] = -V[14] / r_idx_1;
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
        xi = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = nblocks;
        emxEnsureCapacity_real_T(x, xi);
        Err_every_data = x->data;
        for (npages = 0; npages < nblocks; npages++) {
          ibtile = npages << 1;
          Err_every_data[ibtile] = b_n[0];
          Err_every_data[ibtile + 1] = b_n[1];
        }
        /*  Jacobian */
        if (err->size[0] == x2_contents->size[0]) {
          xi = denom->size[0];
          denom->size[0] = err->size[0];
          emxEnsureCapacity_real_T(denom, xi);
          denom_data = denom->data;
          ibtile = err->size[0];
          for (xi = 0; xi < ibtile; xi++) {
            r_idx_1 = b_n[0] - err_data[xi];
            norm_vec = b_n[1] - x2_contents_data[xi];
            denom_data[xi] = r_idx_1 * r_idx_1 + norm_vec * norm_vec;
          }
        } else {
          binary_expand_op_7(denom, b_n, err, x2_contents);
          denom_data = denom->data;
        }
        ibtile = denom->size[0];
        for (k = 0; k < ibtile; k++) {
          denom_data[k] = sqrt(denom_data[k]);
        }
        outsize[0] = nblocks;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          ibtile = x->size[1] << 1;
          xi = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, xi);
          Err_every_data = x->data;
          for (xi = 0; xi < ibtile; xi++) {
            r_idx_1 = Err_every_data[xi] - x_contents_data[xi];
            Err_every_data[xi] = r_idx_1 * r_idx_1;
          }
        } else {
          binary_expand_op_6(x, x_contents);
          Err_every_data = x->data;
        }
        if (x->size[1] == 0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          npages = x->size[1];
          xi = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(y, xi);
          y_data = y->data;
          for (xi = 0; xi < npages; xi++) {
            ibtile = xi << 1;
            y_data[xi] = Err_every_data[ibtile] + Err_every_data[ibtile + 1];
          }
        }
        ibtile = y->size[1];
        for (k = 0; k < ibtile; k++) {
          y_data[k] = sqrt(y_data[k]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          xi = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, xi);
          Err_every_data = n->data;
          ibtile = err->size[0];
          for (xi = 0; xi < ibtile; xi++) {
            Err_every_data[xi] = -((b_n[0] - err_data[xi]) / denom_data[xi]);
          }
          ibtile = x2_contents->size[0];
          for (xi = 0; xi < ibtile; xi++) {
            Err_every_data[xi + n->size[0]] =
                -((b_n[1] - x2_contents_data[xi]) / denom_data[xi]);
          }
          for (xi = 0; xi < nblocks; xi++) {
            Err_every_data[xi + n->size[0] * 2] = 1.0;
          }
          xi = b_y->size[0];
          b_y->size[0] = y->size[1];
          emxEnsureCapacity_real_T(b_y, xi);
          Err_every_data = b_y->data;
          ibtile = y->size[1];
          for (xi = 0; xi < ibtile; xi++) {
            Err_every_data[xi] = y_data[xi] - b_n[2];
          }
          mldivide(n, b_y, h);
        } else {
          binary_expand_op_5(b_n, err, denom, x2_contents, outsize, y, h);
        }
        /*  Check for convergence */
        rcoselev = 0.0;
        absxk = 0.0;
        for (k = 0; k < 3; k++) {
          r_idx_1 = h[k];
          norm_vec = b_n[k] + r_idx_1;
          b_n[k] = norm_vec;
          absx = fabs(r_idx_1);
          if (rtIsNaN(absx) || (absx > rcoselev)) {
            rcoselev = absx;
          }
          absx = fabs(norm_vec);
          if (rtIsNaN(absx) || (absx > absxk)) {
            absxk = absx;
          }
        }
        if (rcoselev / absxk < 1.0E-5) {
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
      xi = denom->size[0];
      denom->size[0] = P->size[0];
      emxEnsureCapacity_real_T(denom, xi);
      denom_data = denom->data;
      ibtile = P->size[0];
      xi = b_y->size[0];
      b_y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(b_y, xi);
      Err_every_data = b_y->data;
      for (xi = 0; xi < ibtile; xi++) {
        denom_data[xi] = P_data[xi] - b_n[0];
        Err_every_data[xi] = P_data[xi + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == b_y->size[0]) {
        xi = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, xi);
        err_data = err->data;
        ibtile = denom->size[0];
        for (xi = 0; xi < ibtile; xi++) {
          r_idx_1 = denom_data[xi];
          norm_vec = Err_every_data[xi];
          err_data[xi] = rt_hypotd_snf(r_idx_1, norm_vec);
        }
      } else {
        expand_hypot(denom, b_y, err);
        err_data = err->data;
      }
      ibtile = err->size[0];
      for (xi = 0; xi < ibtile; xi++) {
        err_data[xi] -= b_n[2];
      }
      xi = b_y->size[0];
      b_y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(b_y, xi);
      Err_every_data = b_y->data;
      ibtile = err->size[0];
      for (xi = 0; xi < ibtile; xi++) {
        r_idx_1 = err_data[xi];
        Err_every_data[xi] = r_idx_1 * r_idx_1;
      }
      if (b_y->size[0] == 0) {
        rcoselev = 0.0;
      } else {
        if (b_y->size[0] <= 1024) {
          ibtile = b_y->size[0];
          lastBlockLength = 0;
          nblocks = 1;
        } else {
          ibtile = 1024;
          nblocks = (int)((unsigned int)b_y->size[0] >> 10);
          lastBlockLength = b_y->size[0] - (nblocks << 10);
          if (lastBlockLength > 0) {
            nblocks++;
          } else {
            lastBlockLength = 1024;
          }
        }
        rcoselev = Err_every_data[0];
        for (k = 2; k <= ibtile; k++) {
          rcoselev += Err_every_data[k - 1];
        }
        for (xi = 2; xi <= nblocks; xi++) {
          ibtile = (xi - 1) << 10;
          norm_vec = Err_every_data[ibtile];
          if (xi == nblocks) {
            npages = lastBlockLength;
          } else {
            npages = 1024;
          }
          for (k = 2; k <= npages; k++) {
            norm_vec += Err_every_data[(ibtile + k) - 1];
          }
          rcoselev += norm_vec;
        }
      }
      absxk = sqrt(rcoselev / (double)b_y->size[0]);
      if (absxk < OptErr) {
        OptErr = absxk;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        xi = OptAllErr->size[0];
        OptAllErr->size[0] = err->size[0];
        emxEnsureCapacity_real_T(OptAllErr, xi);
        OptAllErr_data = OptAllErr->data;
        ibtile = err->size[0];
        for (xi = 0; xi < ibtile; xi++) {
          OptAllErr_data[xi] = err_data[xi];
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
    absx = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    absx = t * t;
  }
  absxk = fabs(h[1]);
  if (absxk > scale) {
    t = scale / absxk;
    absx = absx * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    absx += t * t;
  }
  absx = scale * sqrt(absx);
  d1 = rt_atan2d_snf(absx, d);
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
  absxk = h[0] / absx;
  rcoselev = absxk;
  absxk = fabs(absxk);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk = h[1] / absx;
  r_idx_1 = absxk;
  absxk = fabs(absxk);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  absxk = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / absx;
  t = absxk / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    b_n[0] = 0.0;
    b_n[1] = 0.0;
    b_n[2] = 0.0;
  } else {
    b_n[0] = rcoselev / norm_vec;
    b_n[1] = r_idx_1 / norm_vec;
    b_n[2] = absxk / norm_vec;
  }
  d1 = (1.0 - c) * b_n[0];
  dv[0] = d1 * b_n[0] + c;
  d2 = d1 * b_n[1];
  r_idx_1 = s * b_n[2];
  dv[3] = d2 - r_idx_1;
  d1 *= b_n[2];
  norm_vec = s * b_n[1];
  dv[6] = d1 + norm_vec;
  dv[1] = d2 + r_idx_1;
  d2 = (1.0 - c) * b_n[1];
  dv[4] = d2 * b_n[1] + c;
  d2 *= b_n[2];
  r_idx_1 = s * b_n[0];
  dv[7] = d2 - r_idx_1;
  dv[2] = d1 - norm_vec;
  dv[5] = d2 + r_idx_1;
  dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(dv, dv1);
  for (xi = 0; xi < 3; xi++) {
    Mcenter[xi] =
        (OptPara_idx_0 * dv1[3 * xi] + OptPara_idx_1 * dv1[3 * xi + 1]) +
        0.0 * dv1[3 * xi + 2];
  }
  xi = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = OptAllErr->size[0];
  emxEnsureCapacity_real_T(Err_every, xi);
  Err_every_data = Err_every->data;
  ibtile = OptAllErr->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    Err_every_data[xi] = OptAllErr_data[xi];
  }
  emxFree_real_T(&OptAllErr);
  /*  三个点定义 */
  /*  斜率计算 */
  r_idx_1 = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  absx = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  absxk = (r_idx_1 * r_idx_1 + absx * absx) + rcoselev * rcoselev;
  norm_vec = -(((Mcenter[0] - P_bound1[0]) * r_idx_1 +
                (Mcenter[1] - P_bound1[1]) * absx) +
               (Mcenter[2] - P_bound1[2]) * rcoselev) /
             absxk;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  absxk = -(((Mcenter[0] - P_bound2[0]) * r_idx_1 +
             (Mcenter[1] - P_bound2[1]) * absx) +
            (Mcenter[2] - P_bound2[2]) * rcoselev) /
          absxk;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = norm_vec * r_idx_1 + Mcenter[0];
  Bottom_round_center1[1] = norm_vec * absx + Mcenter[1];
  Bottom_round_center1[2] = norm_vec * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = absxk * r_idx_1 + Mcenter[0];
  Bottom_round_center2[1] = absxk * absx + Mcenter[1];
  Bottom_round_center2[2] = absxk * rcoselev + Mcenter[2];
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
