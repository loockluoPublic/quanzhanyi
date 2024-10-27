/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:09:52
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "combineVectorElements.h"
#include "fitcircle.h"
#include "ifWhileCond.h"
#include "ixfun.h"
#include "mldivide.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "xzsvdc.h"
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
  static const signed char b_V[16] = {1, 0, 0, 0, 0, 1, 0, 0,
                                      0, 0, 1, 0, 0, 0, 0, 1};
  emxArray_real_T *A;
  emxArray_real_T *OptAllErr;
  emxArray_real_T *P;
  emxArray_real_T *U;
  emxArray_real_T *b_A;
  emxArray_real_T *b_y;
  emxArray_real_T *denom;
  emxArray_real_T *err;
  emxArray_real_T *n;
  emxArray_real_T *x;
  emxArray_real_T *x2_contents;
  emxArray_real_T *x_contents;
  emxArray_real_T *y;
  double V[16];
  double b_dv[9];
  double b_x[9];
  double s_data[4];
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
  int b_i;
  int i;
  int j;
  int m_contents;
  int nIts;
  int npages;
  int nx;
  int xi;
  boolean_T c_n[3];
  boolean_T exitg1;
  boolean_T p;
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
  i = OptAllErr->size[0];
  OptAllErr->size[0] = points->size[1];
  emxEnsureCapacity_real_T(OptAllErr, i);
  OptAllErr_data = OptAllErr->data;
  nx = points->size[1];
  for (i = 0; i < nx; i++) {
    OptAllErr_data[i] = 0.0;
  }
  emxInit_real_T(&P, 2);
  emxInit_real_T(&err, 1);
  emxInit_real_T(&x_contents, 2);
  emxInit_real_T(&x2_contents, 1);
  emxInit_real_T(&U, 2);
  emxInit_real_T(&denom, 1);
  emxInit_real_T(&A, 2);
  emxInit_real_T(&y, 2);
  y_data = y->data;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&n, 2);
  emxInit_real_T(&b_y, 1);
  emxInit_real_T(&b_A, 2);
  for (b_i = 0; b_i < 180; b_i++) {
    d = 0.035101593894858021 * (double)b_i;
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
      b_dv[0] = r_idx_1 * b_n[0] + c;
      norm_vec = r_idx_1 * b_n[1];
      absxk = s * b_n[2];
      b_dv[3] = norm_vec - absxk;
      r_idx_1 *= b_n[2];
      rcoselev = s * b_n[1];
      b_dv[6] = r_idx_1 + rcoselev;
      b_dv[1] = norm_vec + absxk;
      norm_vec = (1.0 - c) * b_n[1];
      b_dv[4] = norm_vec * b_n[1] + c;
      norm_vec *= b_n[2];
      absxk = s * b_n[0];
      b_dv[7] = norm_vec - absxk;
      b_dv[2] = r_idx_1 - rcoselev;
      b_dv[5] = norm_vec + absxk;
      b_dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      mtimes(points, b_dv, P);
      P_data = P->data;
      i = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, i);
      x_contents_data = x_contents->data;
      nx = P->size[0];
      for (i = 0; i < nx; i++) {
        x_contents_data[2 * i] = P_data[i];
        x_contents_data[2 * i + 1] = P_data[i + P->size[0]];
      }
      m_contents = x_contents->size[1];
      i = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, i);
      err_data = err->data;
      nx = x_contents->size[1];
      i = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, i);
      x2_contents_data = x2_contents->data;
      for (i = 0; i < nx; i++) {
        err_data[i] = x_contents_data[2 * i];
        x2_contents_data[i] = x_contents_data[2 * i + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      if (err->size[0] == x2_contents->size[0]) {
        i = A->size[0] * A->size[1];
        A->size[0] = err->size[0];
        A->size[1] = 4;
        emxEnsureCapacity_real_T(A, i);
        Err_every_data = A->data;
        nx = err->size[0];
        for (i = 0; i < nx; i++) {
          absx = err_data[i];
          norm_vec = x2_contents_data[i];
          Err_every_data[i] = absx * absx + norm_vec * norm_vec;
          Err_every_data[i + A->size[0]] = x_contents_data[2 * i];
          Err_every_data[i + A->size[0] * 2] = x_contents_data[2 * i + 1];
          Err_every_data[i + A->size[0] * 3] = 1.0;
        }
      } else {
        binary_expand_op_8(A, err, x2_contents, x_contents);
        Err_every_data = A->data;
      }
      nx = A->size[0] << 2;
      p = true;
      for (npages = 0; npages < nx; npages++) {
        if ((!p) || (rtIsInf(Err_every_data[npages]) ||
                     rtIsNaN(Err_every_data[npages]))) {
          p = false;
        }
      }
      if (p) {
        if (A->size[0] == 0) {
          for (i = 0; i < 16; i++) {
            V[i] = b_V[i];
          }
        } else {
          i = b_A->size[0] * b_A->size[1];
          b_A->size[0] = A->size[0];
          b_A->size[1] = 4;
          emxEnsureCapacity_real_T(b_A, i);
          denom_data = b_A->data;
          nx = A->size[0] * A->size[1] - 1;
          for (i = 0; i <= nx; i++) {
            denom_data[i] = Err_every_data[i];
          }
          xzsvdc(b_A, U, s_data, V);
        }
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
      nIts = 0;
      exitg1 = false;
      while ((!exitg1) && (nIts < 100)) {
        /*  Find the function and Jacobian  */
        /* SYS   Nonlinear system to be minimised - the objective */
        /* function is the distance to each point from the fitted circle */
        /* contained in u */
        /*  Objective function */
        i = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = m_contents;
        emxEnsureCapacity_real_T(x, i);
        Err_every_data = x->data;
        for (npages = 0; npages < m_contents; npages++) {
          nx = npages << 1;
          Err_every_data[nx] = b_n[0];
          Err_every_data[nx + 1] = b_n[1];
        }
        /*  Jacobian */
        if (err->size[0] == x2_contents->size[0]) {
          i = denom->size[0];
          denom->size[0] = err->size[0];
          emxEnsureCapacity_real_T(denom, i);
          denom_data = denom->data;
          nx = err->size[0];
          for (i = 0; i < nx; i++) {
            absx = b_n[0] - err_data[i];
            norm_vec = b_n[1] - x2_contents_data[i];
            denom_data[i] = absx * absx + norm_vec * norm_vec;
          }
        } else {
          binary_expand_op_7(denom, b_n, err, x2_contents);
          denom_data = denom->data;
        }
        nx = denom->size[0];
        for (npages = 0; npages < nx; npages++) {
          denom_data[npages] = sqrt(denom_data[npages]);
        }
        outsize[0] = m_contents;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          nx = x->size[1] << 1;
          i = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, i);
          Err_every_data = x->data;
          for (i = 0; i < nx; i++) {
            absx = Err_every_data[i] - x_contents_data[i];
            Err_every_data[i] = absx * absx;
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
          i = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(y, i);
          y_data = y->data;
          for (xi = 0; xi < npages; xi++) {
            nx = xi << 1;
            y_data[xi] = Err_every_data[nx] + Err_every_data[nx + 1];
          }
        }
        nx = y->size[1];
        for (npages = 0; npages < nx; npages++) {
          y_data[npages] = sqrt(y_data[npages]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          i = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, i);
          Err_every_data = n->data;
          nx = err->size[0];
          for (i = 0; i < nx; i++) {
            Err_every_data[i] = -((b_n[0] - err_data[i]) / denom_data[i]);
          }
          nx = x2_contents->size[0];
          for (i = 0; i < nx; i++) {
            Err_every_data[i + n->size[0]] =
                -((b_n[1] - x2_contents_data[i]) / denom_data[i]);
          }
          for (i = 0; i < m_contents; i++) {
            Err_every_data[i + n->size[0] * 2] = 1.0;
          }
          i = b_y->size[0];
          b_y->size[0] = y->size[1];
          emxEnsureCapacity_real_T(b_y, i);
          Err_every_data = b_y->data;
          nx = y->size[1];
          for (i = 0; i < nx; i++) {
            Err_every_data[i] = y_data[i] - b_n[2];
          }
          mldivide(n, b_y, h);
        } else {
          binary_expand_op_5(b_n, err, denom, x2_contents, outsize, y, h);
        }
        /*  Check for convergence */
        rcoselev = 0.0;
        absxk = 0.0;
        for (npages = 0; npages < 3; npages++) {
          r_idx_1 = h[npages];
          norm_vec = b_n[npages] + r_idx_1;
          b_n[npages] = norm_vec;
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
          nIts++;
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
      nx = P->size[0];
      i = b_y->size[0];
      b_y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(b_y, i);
      Err_every_data = b_y->data;
      for (i = 0; i < nx; i++) {
        denom_data[i] = P_data[i] - b_n[0];
        Err_every_data[i] = P_data[i + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == b_y->size[0]) {
        i = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, i);
        err_data = err->data;
        nx = denom->size[0];
        for (i = 0; i < nx; i++) {
          absx = denom_data[i];
          r_idx_1 = Err_every_data[i];
          err_data[i] = rt_hypotd_snf(absx, r_idx_1);
        }
      } else {
        expand_hypot(denom, b_y, err);
        err_data = err->data;
      }
      nx = err->size[0];
      for (i = 0; i < nx; i++) {
        err_data[i] -= b_n[2];
      }
      i = b_y->size[0];
      b_y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(b_y, i);
      Err_every_data = b_y->data;
      nx = err->size[0];
      for (i = 0; i < nx; i++) {
        absx = err_data[i];
        Err_every_data[i] = absx * absx;
      }
      absxk = sqrt(combineVectorElements(b_y) / (double)b_y->size[0]);
      if (absxk < OptErr) {
        OptErr = absxk;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        i = OptAllErr->size[0];
        OptAllErr->size[0] = err->size[0];
        emxEnsureCapacity_real_T(OptAllErr, i);
        OptAllErr_data = OptAllErr->data;
        nx = err->size[0];
        for (i = 0; i < nx; i++) {
          OptAllErr_data[i] = err_data[i];
        }
        OptAngle_idx_0 = d;
        OptAngle_idx_1 = rcoselev_tmp;
      }
    }
  }
  emxFree_real_T(&b_A);
  emxFree_real_T(&b_y);
  emxFree_real_T(&n);
  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_real_T(&A);
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
  b_dv[0] = d1 * b_n[0] + c;
  d2 = d1 * b_n[1];
  r_idx_1 = s * b_n[2];
  b_dv[3] = d2 - r_idx_1;
  d1 *= b_n[2];
  norm_vec = s * b_n[1];
  b_dv[6] = d1 + norm_vec;
  b_dv[1] = d2 + r_idx_1;
  d2 = (1.0 - c) * b_n[1];
  b_dv[4] = d2 * b_n[1] + c;
  d2 *= b_n[2];
  r_idx_1 = s * b_n[0];
  b_dv[7] = d2 - r_idx_1;
  b_dv[2] = d1 - norm_vec;
  b_dv[5] = d2 + r_idx_1;
  b_dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(b_dv, b_x);
  d1 = P_bound2[0] - P_bound1[0];
  d2 = P_bound2[1] - P_bound1[1];
  r_idx_1 = P_bound2[2] - P_bound1[2];
  for (xi = 0; xi < 3; xi++) {
    i = 3 * xi + 1;
    nx = 3 * xi + 2;
    Mcenter[xi] =
        (OptPara_idx_0 * b_x[3 * xi] + OptPara_idx_1 * b_x[i]) + 0.0 * b_x[nx];
    norm_vec = MTaon[xi];
    absxk = norm_vec * d1;
    b_x[3 * xi] = absxk;
    rcoselev = norm_vec * d2;
    b_x[i] = rcoselev;
    norm_vec *= r_idx_1;
    b_x[nx] = norm_vec;
    c_n[xi] = ((absxk + rcoselev) + norm_vec > 0.0);
  }
  if (ifWhileCond(c_n)) {
    MTaon[0] = -MTaon[0];
    MTaon[1] = -MTaon[1];
    MTaon[2] = -d;
  }
  i = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = OptAllErr->size[0];
  emxEnsureCapacity_real_T(Err_every, i);
  Err_every_data = Err_every->data;
  nx = OptAllErr->size[0];
  for (i = 0; i < nx; i++) {
    Err_every_data[i] = OptAllErr_data[i];
  }
  emxFree_real_T(&OptAllErr);
  /*  三个点定义 */
  /*  斜率计算 */
  rcoselev = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  norm_vec = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  r_idx_1 = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  absxk = (rcoselev * rcoselev + norm_vec * norm_vec) + r_idx_1 * r_idx_1;
  absx = -(((Mcenter[0] - P_bound1[0]) * rcoselev +
            (Mcenter[1] - P_bound1[1]) * norm_vec) +
           (Mcenter[2] - P_bound1[2]) * r_idx_1) /
         absxk;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  absxk = -(((Mcenter[0] - P_bound2[0]) * rcoselev +
             (Mcenter[1] - P_bound2[1]) * norm_vec) +
            (Mcenter[2] - P_bound2[2]) * r_idx_1) /
          absxk;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = absx * rcoselev + Mcenter[0];
  Bottom_round_center1[1] = absx * norm_vec + Mcenter[1];
  Bottom_round_center1[2] = absx * r_idx_1 + Mcenter[2];
  Bottom_round_center2[0] = absxk * rcoselev + Mcenter[0];
  Bottom_round_center2[1] = absxk * norm_vec + Mcenter[1];
  Bottom_round_center2[2] = absxk * r_idx_1 + Mcenter[2];
  /*  ！  需求1  判断方向 ，改法向量方向 */
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
