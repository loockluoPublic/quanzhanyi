/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "fitcircle.h"
#include "mldivide.h"
#include "norm.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd.h"
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
  b_captured_var x;
  b_captured_var x1;
  b_captured_var x2;
  captured_var b_m;
  emxArray_real_T *J;
  emxArray_real_T *P;
  emxArray_real_T *S;
  emxArray_real_T *U;
  emxArray_real_T *b_J;
  emxArray_real_T *b_x;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *err;
  emxArray_real_T *y;
  double V[16];
  double dv[9];
  double rot1[9];
  double r[4];
  double h[3];
  double n[3];
  double OptAngle_idx_0;
  double OptAngle_idx_1;
  double OptErr;
  double OptPara_idx_0;
  double OptPara_idx_1;
  double absx;
  double c;
  double d;
  double d1;
  double d2;
  double d3;
  double norm_vec;
  double rcoselev;
  double rcoselev_tmp;
  double rot1_tmp;
  double s;
  int aoffset;
  int b_i;
  int boffset;
  int coffset;
  int i;
  int j;
  int k;
  int lastBlockLength;
  int m;
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
  aoffset = Err_every->size[0];
  Err_every->size[0] = points->size[1];
  emxEnsureCapacity_real_T(Err_every, aoffset);
  boffset = points->size[1];
  for (aoffset = 0; aoffset < boffset; aoffset++) {
    Err_every->data[aoffset] = 0.0;
  }
  m = points->size[1];
  emxInit_real_T(&P, 2);
  emxInit_real_T(&err, 1);
  emxInitStruct_captured_var(&x);
  emxInitStruct_captured_var1(&x2);
  emxInitStruct_captured_var1(&x1);
  emxInit_real_T(&U, 2);
  emxInit_real_T(&S, 2);
  emxInit_real_T(&J, 2);
  emxInit_real_T(&b_x, 1);
  emxInit_real_T(&y, 1);
  emxInit_real_T(&b_y, 1);
  emxInit_real_T(&c_y, 2);
  emxInit_real_T(&b_J, 2);
  for (i = 0; i < 180; i++) {
    d = 0.035101593894858021 * (double)i;
    d1 = cos(d);
    d2 = sin(d);
    for (j = 0; j < 180; j++) {
      rcoselev_tmp = 0.035101593894858021 * (double)j;
      rcoselev = cos(rcoselev_tmp);
      d3 = sin(rcoselev_tmp);
      n[0] = rcoselev * d1;
      n[1] = rcoselev * d2;
      h[0] = 0.0 * d3 - n[1];
      h[1] = n[0] - 0.0 * d3;
      h[2] = 0.0 * n[1] - 0.0 * n[0];
      s = b_norm(h);
      d3 = rt_atan2d_snf(s, d3);
      r[0] = h[0] / s;
      r[1] = h[1] / s;
      r[2] = h[2] / s;
      r[3] = d3;
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
      norm_vec = b_norm(*(double(*)[3]) & r[0]);
      if (norm_vec <= 1.0E-12) {
        n[0] = 0.0;
        n[1] = 0.0;
        n[2] = 0.0;
      } else {
        n[0] = r[0] / norm_vec;
        n[1] = r[1] / norm_vec;
        n[2] = r[2] / norm_vec;
      }
      rcoselev = (1.0 - c) * n[0];
      rot1[0] = rcoselev * n[0] + c;
      norm_vec = rcoselev * n[1];
      rot1_tmp = s * n[2];
      rot1[3] = norm_vec - rot1_tmp;
      rcoselev *= n[2];
      absx = s * n[1];
      rot1[6] = rcoselev + absx;
      rot1[1] = norm_vec + rot1_tmp;
      norm_vec = (1.0 - c) * n[1];
      rot1[4] = norm_vec * n[1] + c;
      norm_vec *= n[2];
      rot1_tmp = s * n[0];
      rot1[7] = norm_vec - rot1_tmp;
      rot1[2] = rcoselev - absx;
      rot1[5] = norm_vec + rot1_tmp;
      rot1[8] = (1.0 - c) * n[2] * n[2] + c;
      aoffset = P->size[0] * P->size[1];
      P->size[0] = points->size[1];
      P->size[1] = 3;
      emxEnsureCapacity_real_T(P, aoffset);
      for (lastBlockLength = 0; lastBlockLength < 3; lastBlockLength++) {
        coffset = lastBlockLength * m;
        boffset = lastBlockLength * 3;
        for (b_i = 0; b_i < m; b_i++) {
          aoffset = b_i * 3;
          P->data[coffset + b_i] =
              (points->data[aoffset] * rot1[boffset] +
               points->data[aoffset + 1] * rot1[boffset + 1]) +
              points->data[aoffset + 2] * rot1[boffset + 2];
        }
      }
      boffset = P->size[0];
      coffset = P->size[0];
      aoffset = x.contents->size[0] * x.contents->size[1];
      x.contents->size[0] = 2;
      x.contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x.contents, aoffset);
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        x.contents->data[2 * aoffset] = P->data[aoffset];
      }
      for (aoffset = 0; aoffset < coffset; aoffset++) {
        x.contents->data[2 * aoffset + 1] = P->data[aoffset + P->size[0]];
      }
      boffset = x.contents->size[1];
      b_m.contents = x.contents->size[1];
      aoffset = x1.contents->size[0];
      x1.contents->size[0] = x.contents->size[1];
      emxEnsureCapacity_real_T(x1.contents, aoffset);
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        x1.contents->data[aoffset] = x.contents->data[2 * aoffset];
      }
      boffset = x.contents->size[1];
      aoffset = x2.contents->size[0];
      x2.contents->size[0] = x.contents->size[1];
      emxEnsureCapacity_real_T(x2.contents, aoffset);
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        x2.contents->data[aoffset] = x.contents->data[2 * aoffset + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      aoffset = y->size[0];
      y->size[0] = x1.contents->size[0];
      emxEnsureCapacity_real_T(y, aoffset);
      coffset = x1.contents->size[0];
      for (k = 0; k < coffset; k++) {
        y->data[k] = x1.contents->data[k] * x1.contents->data[k];
      }
      aoffset = b_y->size[0];
      b_y->size[0] = x2.contents->size[0];
      emxEnsureCapacity_real_T(b_y, aoffset);
      coffset = x2.contents->size[0];
      for (k = 0; k < coffset; k++) {
        b_y->data[k] = x2.contents->data[k] * x2.contents->data[k];
      }
      aoffset = c_y->size[0] * c_y->size[1];
      c_y->size[0] = y->size[0];
      c_y->size[1] = 4;
      emxEnsureCapacity_real_T(c_y, aoffset);
      boffset = y->size[0];
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        c_y->data[aoffset] = y->data[aoffset] + b_y->data[aoffset];
      }
      boffset = x1.contents->size[0];
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        c_y->data[aoffset + c_y->size[0]] = x1.contents->data[aoffset];
      }
      boffset = x2.contents->size[0];
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        c_y->data[aoffset + c_y->size[0] * 2] = x2.contents->data[aoffset];
      }
      boffset = x.contents->size[1];
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        c_y->data[aoffset + c_y->size[0] * 3] = 1.0;
      }
      svd(c_y, U, S, V);
      /*  For clarity, set the quadratic form variables */
      /*  Convert to centre/radius */
      rcoselev = 3.3121686421112381E-170;
      /*  2) Nonlinear refinement to miminise geometric error, and compute
       * residual */
      /*  [z, r, residual] = fitcircle_geometric(x, z, r); */
      /*  NESTED FUNCTIONS */
      /*      function [z, r, residual] = fitcircle_geometric(x, z0, r0) */
      /*  Use a simple Gauss Newton method to minimize the geometric error */
      /*  Set initial u */
      d3 = 2.0 * V[12];
      s = fabs(V[13]);
      if (s > 3.3121686421112381E-170) {
        c = 1.0;
        rcoselev = s;
      } else {
        norm_vec = s / 3.3121686421112381E-170;
        c = norm_vec * norm_vec;
      }
      n[0] = -V[13] / d3;
      s = fabs(V[14]);
      if (s > rcoselev) {
        norm_vec = rcoselev / s;
        c = c * norm_vec * norm_vec + 1.0;
        rcoselev = s;
      } else {
        norm_vec = s / rcoselev;
        c += norm_vec * norm_vec;
      }
      n[1] = -V[14] / d3;
      c = rcoselev * sqrt(c);
      absx = c / (2.0 * V[12]);
      n[2] = sqrt(absx * absx - V[15] / V[12]);
      /*  Delta is the norm of current step, scaled by the norm of u */
      coffset = 0;
      exitg1 = false;
      while ((!exitg1) && (coffset < 100)) {
        /*  Find the function and Jacobian  */
        sys(&b_m, &x, &x1, &x2, n, b_y, J);
        /*  Solve for the step and update u */
        aoffset = b_J->size[0] * b_J->size[1];
        b_J->size[0] = J->size[0];
        b_J->size[1] = 3;
        emxEnsureCapacity_real_T(b_J, aoffset);
        boffset = J->size[0] * 3;
        for (aoffset = 0; aoffset < boffset; aoffset++) {
          b_J->data[aoffset] = -J->data[aoffset];
        }
        mldivide(b_J, b_y, h);
        /*  Check for convergence */
        c = 0.0;
        rot1_tmp = 0.0;
        d3 = n[0] + h[0];
        n[0] = d3;
        absx = fabs(h[0]);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          c = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          rot1_tmp = absx;
        }
        d3 = n[1] + h[1];
        n[1] = d3;
        absx = fabs(h[1]);
        if (rtIsNaN(absx) || (absx > c)) {
          c = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > rot1_tmp)) {
          rot1_tmp = absx;
        }
        d3 = n[2] + h[2];
        n[2] = d3;
        absx = fabs(h[2]);
        if (rtIsNaN(absx) || (absx > c)) {
          c = absx;
        }
        absx = fabs(d3);
        if (rtIsNaN(absx) || (absx > rot1_tmp)) {
          rot1_tmp = absx;
        }
        if (c / rot1_tmp < 1.0E-5) {
          exitg1 = true;
        } else {
          coffset++;
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
      boffset = P->size[0];
      aoffset = b_y->size[0];
      b_y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(b_y, aoffset);
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        b_y->data[aoffset] = P->data[aoffset] - n[0];
      }
      boffset = P->size[0];
      aoffset = y->size[0];
      y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(y, aoffset);
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        y->data[aoffset] = P->data[aoffset + P->size[0]] - n[1];
      }
      if (b_y->size[0] <= y->size[0]) {
        aoffset = b_y->size[0];
      } else {
        aoffset = y->size[0];
      }
      coffset = err->size[0];
      err->size[0] = aoffset;
      emxEnsureCapacity_real_T(err, coffset);
      for (k = 0; k < aoffset; k++) {
        err->data[k] = rt_hypotd_snf(b_y->data[k], y->data[k]);
      }
      boffset = err->size[0];
      for (aoffset = 0; aoffset < boffset; aoffset++) {
        err->data[aoffset] -= n[2];
      }
      aoffset = err->size[0];
      coffset = b_x->size[0];
      b_x->size[0] = err->size[0];
      emxEnsureCapacity_real_T(b_x, coffset);
      for (k = 0; k < aoffset; k++) {
        b_x->data[k] = err->data[k] * err->data[k];
      }
      if (b_x->size[0] == 0) {
        c = 0.0;
      } else {
        if (b_x->size[0] <= 1024) {
          coffset = b_x->size[0];
          lastBlockLength = 0;
          aoffset = 1;
        } else {
          coffset = 1024;
          aoffset = b_x->size[0] / 1024;
          lastBlockLength = b_x->size[0] - (aoffset << 10);
          if (lastBlockLength > 0) {
            aoffset++;
          } else {
            lastBlockLength = 1024;
          }
        }
        c = b_x->data[0];
        for (k = 2; k <= coffset; k++) {
          c += b_x->data[k - 1];
        }
        for (b_i = 2; b_i <= aoffset; b_i++) {
          coffset = (b_i - 1) << 10;
          s = b_x->data[coffset];
          if (b_i == aoffset) {
            boffset = lastBlockLength;
          } else {
            boffset = 1024;
          }
          for (k = 2; k <= boffset; k++) {
            s += b_x->data[(coffset + k) - 1];
          }
          c += s;
        }
      }
      absx = sqrt(c / (double)b_x->size[0]);
      if (absx < OptErr) {
        OptErr = absx;
        OptPara_idx_0 = n[0];
        OptPara_idx_1 = n[1];
        *Mradial = n[2];
        aoffset = Err_every->size[0];
        Err_every->size[0] = err->size[0];
        emxEnsureCapacity_real_T(Err_every, aoffset);
        boffset = err->size[0];
        for (aoffset = 0; aoffset < boffset; aoffset++) {
          Err_every->data[aoffset] = err->data[aoffset];
        }
        OptAngle_idx_0 = d;
        OptAngle_idx_1 = rcoselev_tmp;
      }
    }
  }
  emxFree_real_T(&b_J);
  emxFree_real_T(&c_y);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxFree_real_T(&b_x);
  emxFree_real_T(&J);
  emxFree_real_T(&S);
  emxFree_real_T(&U);
  emxFreeStruct_captured_var(&x1);
  emxFreeStruct_captured_var(&x2);
  emxFreeStruct_captured_var(&x);
  emxFree_real_T(&err);
  emxFree_real_T(&P);
  rcoselev = cos(OptAngle_idx_1);
  d = sin(OptAngle_idx_1);
  MTaon[0] = rcoselev * cos(OptAngle_idx_0);
  MTaon[1] = rcoselev * sin(OptAngle_idx_0);
  MTaon[2] = d;
  h[0] = 0.0 * d - MTaon[1];
  h[1] = MTaon[0] - 0.0 * d;
  h[2] = 0.0 * MTaon[1] - 0.0 * MTaon[0];
  s = b_norm(h);
  d1 = rt_atan2d_snf(s, d);
  r[0] = h[0] / s;
  r[1] = h[1] / s;
  r[2] = h[2] / s;
  r[3] = d1;
  s = sin(d1);
  c = cos(d1);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  norm_vec = b_norm(*(double(*)[3]) & r[0]);
  if (norm_vec <= 1.0E-12) {
    n[0] = 0.0;
    n[1] = 0.0;
    n[2] = 0.0;
  } else {
    n[0] = r[0] / norm_vec;
    n[1] = r[1] / norm_vec;
    n[2] = r[2] / norm_vec;
  }
  d1 = (1.0 - c) * n[0];
  dv[0] = d1 * n[0] + c;
  d2 = d1 * n[1];
  d3 = s * n[2];
  dv[3] = d2 - d3;
  d1 *= n[2];
  absx = s * n[1];
  dv[6] = d1 + absx;
  dv[1] = d2 + d3;
  d2 = (1.0 - c) * n[1];
  dv[4] = d2 * n[1] + c;
  d2 *= n[2];
  d3 = s * n[0];
  dv[7] = d2 - d3;
  dv[2] = d1 - absx;
  dv[5] = d2 + d3;
  dv[8] = (1.0 - c) * n[2] * n[2] + c;
  pinv(dv, rot1);
  for (aoffset = 0; aoffset < 3; aoffset++) {
    Mcenter[aoffset] = (OptPara_idx_0 * rot1[3 * aoffset] +
                        OptPara_idx_1 * rot1[3 * aoffset + 1]) +
                       0.0 * rot1[3 * aoffset + 2];
  }
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  rot1_tmp = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  absx = (norm_vec * norm_vec + rot1_tmp * rot1_tmp) + rcoselev * rcoselev;
  s = -(((Mcenter[0] - P_bound1[0]) * norm_vec +
         (Mcenter[1] - P_bound1[1]) * rot1_tmp) +
        (Mcenter[2] - P_bound1[2]) * rcoselev) /
      absx;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  absx = -(((Mcenter[0] - P_bound2[0]) * norm_vec +
            (Mcenter[1] - P_bound2[1]) * rot1_tmp) +
           (Mcenter[2] - P_bound2[2]) * rcoselev) /
         absx;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = s * norm_vec + Mcenter[0];
  Bottom_round_center1[1] = s * rot1_tmp + Mcenter[1];
  Bottom_round_center1[2] = s * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = absx * norm_vec + Mcenter[0];
  Bottom_round_center2[1] = absx * rot1_tmp + Mcenter[1];
  Bottom_round_center2[2] = absx * rcoselev + Mcenter[2];
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
