/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "mldivide.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * points = points';
 *
 * Arguments    : const double points[3]
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Mcenter[3]
 *                double MTaon[3]
 *                double *Mradial
 *                double *Err_every
 *                double Bottom_round_center1[3]
 *                double Bottom_round_center2[3]
 * Return Type  : void
 */
void Calculate_accurate_cylinders_from_multiple_measurement_points2(
    const double points[3], const double P_bound1[3], const double P_bound2[3],
    double Mcenter[3], double MTaon[3], double *Mradial, double *Err_every,
    double Bottom_round_center1[3], double Bottom_round_center2[3])
{
  double V[16];
  double dv[9];
  double rot2[9];
  double B[4];
  double P[3];
  double dv1[3];
  double n[3];
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
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double rcoselev;
  double rcoselev_tmp;
  double s;
  double scale;
  double t;
  double u_idx_0;
  double u_idx_1;
  double x_contents_idx_0;
  double x_contents_idx_1;
  int i;
  int j;
  int nIts;
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
  *Err_every = 0.0;
  d = points[0];
  d1 = points[1];
  d2 = points[2];
  for (i = 0; i < 180; i++) {
    d3 = 0.035101593894858021 * (double)i;
    d4 = cos(d3);
    d5 = sin(d3);
    for (j = 0; j < 180; j++) {
      rcoselev_tmp = 0.035101593894858021 * (double)j;
      rcoselev = cos(rcoselev_tmp);
      d6 = sin(rcoselev_tmp);
      n[0] = rcoselev * d4;
      n[1] = rcoselev * d5;
      u_idx_0 = 0.0 * d6 - n[1];
      u_idx_1 = n[0] - 0.0 * d6;
      scale = 3.3121686421112381E-170;
      absxk = fabs(u_idx_0);
      if (absxk > 3.3121686421112381E-170) {
        absx = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        absx = t * t;
      }
      absxk = fabs(u_idx_1);
      if (absxk > scale) {
        t = scale / absxk;
        absx = absx * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        absx += t * t;
      }
      absx = scale * sqrt(absx);
      d6 = rt_atan2d_snf(absx, d6);
      s = sin(d6);
      c = cos(d6);
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
      d6 = u_idx_0 / absx;
      B[0] = d6;
      absxk = fabs(d6);
      if (absxk > 3.3121686421112381E-170) {
        rcoselev = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        rcoselev = t * t;
      }
      d6 = u_idx_1 / absx;
      B[1] = d6;
      absxk = fabs(d6);
      if (absxk > scale) {
        t = scale / absxk;
        rcoselev = rcoselev * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        rcoselev += t * t;
      }
      d6 = (0.0 * n[1] - 0.0 * n[0]) / absx;
      t = d6 / scale;
      rcoselev += t * t;
      rcoselev = scale * sqrt(rcoselev);
      if (rcoselev <= 1.0E-12) {
        n[0] = 0.0;
        n[1] = 0.0;
        n[2] = 0.0;
      } else {
        n[0] = B[0] / rcoselev;
        n[1] = B[1] / rcoselev;
        n[2] = d6 / rcoselev;
      }
      d6 = (1.0 - c) * n[0];
      dv[0] = d6 * n[0] + c;
      d7 = d6 * n[1];
      d8 = s * n[2];
      dv[3] = d7 - d8;
      d6 *= n[2];
      rcoselev = s * n[1];
      dv[6] = d6 + rcoselev;
      dv[1] = d7 + d8;
      d7 = (1.0 - c) * n[1];
      dv[4] = d7 * n[1] + c;
      d7 *= n[2];
      d8 = s * n[0];
      dv[7] = d7 - d8;
      dv[2] = d6 - rcoselev;
      dv[5] = d7 + d8;
      dv[8] = (1.0 - c) * n[2] * n[2] + c;
      for (nIts = 0; nIts < 3; nIts++) {
        P[nIts] =
            (d * dv[3 * nIts] + d1 * dv[3 * nIts + 1]) + d2 * dv[3 * nIts + 2];
      }
      x_contents_idx_0 = P[0];
      x_contents_idx_1 = P[1];
      d6 = P[0];
      d7 = P[1];
      /*  Form the coefficient matrix */
      B[0] = P[0] * P[0] + P[1] * P[1];
      B[1] = P[0];
      B[2] = P[1];
      B[3] = 1.0;
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      p = ((!rtIsInf(B[0])) && (!rtIsNaN(B[0])));
      if ((!p) || (rtIsInf(P[0]) || rtIsNaN(P[0]))) {
        p = false;
      }
      if ((!p) || (rtIsInf(P[1]) || rtIsNaN(P[1]))) {
        p = false;
      }
      if (p) {
        svd(B, &rcoselev, &s, V);
      } else {
        for (nIts = 0; nIts < 16; nIts++) {
          V[nIts] = rtNaN;
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
      d8 = 2.0 * V[12];
      absxk = fabs(V[13]);
      if (absxk > 3.3121686421112381E-170) {
        c = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        c = t * t;
      }
      u_idx_0 = -V[13] / d8;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        c = c * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        c += t * t;
      }
      u_idx_1 = -V[14] / d8;
      c = scale * sqrt(c);
      rcoselev = c / (2.0 * V[12]);
      t = sqrt(rcoselev * rcoselev - V[15] / V[12]);
      /*  Delta is the norm of current step, scaled by the norm of u */
      nIts = 0;
      exitg1 = false;
      while ((!exitg1) && (nIts < 100)) {
        /*  Find the function and Jacobian  */
        /* SYS   Nonlinear system to be minimised - the objective */
        /* function is the distance to each point from the fitted circle */
        /* contained in u */
        /*  Objective function */
        d8 = u_idx_0 - x_contents_idx_0;
        rcoselev = d8 * d8;
        d8 = u_idx_1 - x_contents_idx_1;
        /*  Jacobian */
        scale = u_idx_0 - d6;
        absxk = u_idx_1 - d7;
        c = sqrt(scale * scale + absxk * absxk);
        /*  Solve for the step and update u */
        n[0] = -(scale / c);
        n[1] = -(absxk / c);
        n[2] = 1.0;
        mldivide(n, sqrt(rcoselev + d8 * d8) - t, dv1);
        /*  Check for convergence */
        c = 0.0;
        rcoselev = 0.0;
        d8 = u_idx_0 + dv1[0];
        u_idx_0 = d8;
        absx = fabs(dv1[0]);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          c = absx;
        }
        absx = fabs(d8);
        if (rtIsNaN(absx) || (absx > 0.0)) {
          rcoselev = absx;
        }
        d8 = u_idx_1 + dv1[1];
        u_idx_1 = d8;
        absx = fabs(dv1[1]);
        if (rtIsNaN(absx) || (absx > c)) {
          c = absx;
        }
        absx = fabs(d8);
        if (rtIsNaN(absx) || (absx > rcoselev)) {
          rcoselev = absx;
        }
        d8 = t + dv1[2];
        t = d8;
        absx = fabs(dv1[2]);
        if (rtIsNaN(absx) || (absx > c)) {
          c = absx;
        }
        absx = fabs(d8);
        if (rtIsNaN(absx) || (absx > rcoselev)) {
          rcoselev = absx;
        }
        if (c / rcoselev < 1.0E-5) {
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
      absx = rt_hypotd_snf(P[0] - u_idx_0, P[1] - u_idx_1) - t;
      c = sqrt(absx * absx);
      if (c < OptErr) {
        OptErr = c;
        OptPara_idx_0 = u_idx_0;
        OptPara_idx_1 = u_idx_1;
        *Mradial = t;
        *Err_every = absx;
        OptAngle_idx_0 = d3;
        OptAngle_idx_1 = rcoselev_tmp;
      }
    }
  }
  rcoselev = cos(OptAngle_idx_1);
  d = sin(OptAngle_idx_1);
  MTaon[0] = rcoselev * cos(OptAngle_idx_0);
  MTaon[1] = rcoselev * sin(OptAngle_idx_0);
  MTaon[2] = d;
  u_idx_0 = 0.0 * d - MTaon[1];
  u_idx_1 = MTaon[0] - 0.0 * d;
  scale = 3.3121686421112381E-170;
  absxk = fabs(u_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    absx = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    absx = t * t;
  }
  absxk = fabs(u_idx_1);
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
  d1 = u_idx_0 / absx;
  B[0] = d1;
  absxk = fabs(d1);
  if (absxk > 3.3121686421112381E-170) {
    rcoselev = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    rcoselev = t * t;
  }
  d1 = u_idx_1 / absx;
  B[1] = d1;
  absxk = fabs(d1);
  if (absxk > scale) {
    t = scale / absxk;
    rcoselev = rcoselev * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    rcoselev += t * t;
  }
  d1 = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / absx;
  t = d1 / scale;
  rcoselev += t * t;
  rcoselev = scale * sqrt(rcoselev);
  if (rcoselev <= 1.0E-12) {
    n[0] = 0.0;
    n[1] = 0.0;
    n[2] = 0.0;
  } else {
    n[0] = B[0] / rcoselev;
    n[1] = B[1] / rcoselev;
    n[2] = d1 / rcoselev;
  }
  d1 = (1.0 - c) * n[0];
  dv[0] = d1 * n[0] + c;
  d2 = d1 * n[1];
  d3 = s * n[2];
  dv[3] = d2 - d3;
  d1 *= n[2];
  d4 = s * n[1];
  dv[6] = d1 + d4;
  dv[1] = d2 + d3;
  d2 = (1.0 - c) * n[1];
  dv[4] = d2 * n[1] + c;
  d2 *= n[2];
  d3 = s * n[0];
  dv[7] = d2 - d3;
  dv[2] = d1 - d4;
  dv[5] = d2 + d3;
  dv[8] = (1.0 - c) * n[2] * n[2] + c;
  pinv(dv, rot2);
  for (nIts = 0; nIts < 3; nIts++) {
    Mcenter[nIts] =
        (OptPara_idx_0 * rot2[3 * nIts] + OptPara_idx_1 * rot2[3 * nIts + 1]) +
        0.0 * rot2[3 * nIts + 2];
  }
  /*  三个点定义 */
  /*  斜率计算 */
  scale = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  absxk = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  absx = (Mcenter[2] + d) - Mcenter[2];
  rcoselev = (scale * scale + absxk * absxk) + absx * absx;
  c = -(((Mcenter[0] - P_bound1[0]) * scale +
         (Mcenter[1] - P_bound1[1]) * absxk) +
        (Mcenter[2] - P_bound1[2]) * absx) /
      rcoselev;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  rcoselev = -(((Mcenter[0] - P_bound2[0]) * scale +
                (Mcenter[1] - P_bound2[1]) * absxk) +
               (Mcenter[2] - P_bound2[2]) * absx) /
             rcoselev;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = c * scale + Mcenter[0];
  Bottom_round_center1[1] = c * absxk + Mcenter[1];
  Bottom_round_center1[2] = c * absx + Mcenter[2];
  Bottom_round_center2[0] = rcoselev * scale + Mcenter[0];
  Bottom_round_center2[1] = rcoselev * absxk + Mcenter[1];
  Bottom_round_center2[2] = rcoselev * absx + Mcenter[2];
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
