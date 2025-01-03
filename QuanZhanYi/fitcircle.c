/*
 * File: fitcircle.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 11:27:52
 */

/* Include Files */
#include "fitcircle.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "svd1.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void minus(double in1[4], const emxArray_real_T *in2,
                  const emxArray_real_T *in3);

/* Function Definitions */
/*
 * Arguments    : double in1[4]
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void minus(double in1[4], const emxArray_real_T *in2,
                  const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  int stride_0_1;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  in1[0] = in2_data[0] - in3_data[0];
  in1[1] = in2_data[1] - in3_data[stride_1_0];
  in1[2] = in2_data[2 * stride_0_1] - in3_data[in3->size[0]];
  in1[3] = in2_data[2 * stride_0_1 + 1] - in3_data[stride_1_0 + in3->size[0]];
}

/*
 * Arguments    : const double in2[3]
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 *                const int in6[2]
 *                const emxArray_real_T *in7
 *                double in1[3]
 * Return Type  : void
 */
void binary_expand_op_6(const double in2[3], const emxArray_real_T *in3,
                        const emxArray_real_T *in4, const emxArray_real_T *in5,
                        const int in6[2], const emxArray_real_T *in7,
                        double in1[3])
{
  emxArray_real_T *d_in2;
  emxArray_real_T *e_in2;
  emxArray_real_T *f_in2;
  const double *in3_data;
  const double *in4_data;
  const double *in5_data;
  const double *in7_data;
  double b_in2;
  double c_in2;
  double *b_in2_data;
  double *c_in2_data;
  double *in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0_tmp;
  in7_data = in7->data;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  b_in2 = in2[0];
  c_in2 = in2[1];
  emxInit_real_T(&d_in2, 1);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = d_in2->size[0];
  d_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(d_in2, i);
  in2_data = d_in2->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0_tmp = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] =
        -((b_in2 - in3_data[i * stride_0_0]) / in4_data[i * stride_1_0_tmp]);
  }
  emxInit_real_T(&e_in2, 1);
  if (in4->size[0] == 1) {
    loop_ub = in5->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = e_in2->size[0];
  e_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(e_in2, i);
  b_in2_data = e_in2->data;
  stride_0_0 = (in5->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] =
        -((c_in2 - in5_data[i * stride_0_0]) / in4_data[i * stride_1_0_tmp]);
  }
  b_in2 = in2[2];
  emxInit_real_T(&f_in2, 2);
  i = f_in2->size[0] * f_in2->size[1];
  f_in2->size[0] = d_in2->size[0];
  f_in2->size[1] = 3;
  emxEnsureCapacity_real_T(f_in2, i);
  c_in2_data = f_in2->data;
  loop_ub = d_in2->size[0];
  for (i = 0; i < loop_ub; i++) {
    c_in2_data[i] = in2_data[i];
  }
  loop_ub = e_in2->size[0];
  for (i = 0; i < loop_ub; i++) {
    c_in2_data[i + f_in2->size[0]] = b_in2_data[i];
  }
  emxFree_real_T(&e_in2);
  loop_ub = in6[0];
  for (i = 0; i < loop_ub; i++) {
    c_in2_data[i + f_in2->size[0] * 2] = 1.0;
  }
  i = d_in2->size[0];
  d_in2->size[0] = in7->size[1];
  emxEnsureCapacity_real_T(d_in2, i);
  in2_data = d_in2->data;
  loop_ub = in7->size[1];
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = in7_data[i] - b_in2;
  }
  mldivide(f_in2, d_in2, in1);
  emxFree_real_T(&f_in2);
  emxFree_real_T(&d_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const double in3[3]
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 * Return Type  : void
 */
void binary_expand_op_8(emxArray_real_T *in1, const double in3[3],
                        const emxArray_real_T *in4, const emxArray_real_T *in5)
{
  const double *in4_data;
  const double *in5_data;
  double b_in3;
  double b_varargin_1;
  double c_in3;
  double varargin_1;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in5_data = in5->data;
  in4_data = in4->data;
  b_in3 = in3[0];
  c_in3 = in3[1];
  if (in5->size[0] == 1) {
    loop_ub = in4->size[0];
  } else {
    loop_ub = in5->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in4->size[0] != 1);
  stride_1_0 = (in5->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = b_in3 - in4_data[i * stride_0_0];
    b_varargin_1 = c_in3 - in5_data[i * stride_1_0];
    in1_data[i] = varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1;
  }
}

/*
 * Arguments    : const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                emxArray_real_T *in5
 *                emxArray_real_T *in6
 *                double in7[16]
 * Return Type  : void
 */
void binary_expand_op_9(const emxArray_real_T *in2, const emxArray_real_T *in3,
                        const emxArray_real_T *in4, emxArray_real_T *in5,
                        emxArray_real_T *in6, double in7[16])
{
  emxArray_real_T *r;
  emxArray_real_T *r2;
  const double *in2_data;
  const double *in3_data;
  const double *in4_data;
  double b_varargin_1;
  double varargin_1;
  double *r1;
  double *r3;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  emxInit_real_T(&r, 1);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = r->size[0];
  r->size[0] = loop_ub;
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = in2_data[i * stride_0_0];
    b_varargin_1 = in3_data[i * stride_1_0];
    r1[i] = varargin_1 * varargin_1 + b_varargin_1 * b_varargin_1;
  }
  emxInit_real_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = r->size[0];
  r2->size[1] = 4;
  emxEnsureCapacity_real_T(r2, i);
  r3 = r2->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    r3[i] = r1[i];
  }
  emxFree_real_T(&r);
  loop_ub = in4->size[1];
  for (i = 0; i < loop_ub; i++) {
    r3[i + r2->size[0]] = in4_data[2 * i];
    r3[i + r2->size[0] * 2] = in4_data[2 * i + 1];
    r3[i + r2->size[0] * 3] = 1.0;
  }
  b_svd(r2, in5, in6, in7);
  emxFree_real_T(&r2);
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double z[2]
 *                double *r
 *                double *residual
 * Return Type  : void
 */
void fitcircle(const emxArray_real_T *x, double z[2], double *r,
               double *residual)
{
  emxArray_real_T *b_r;
  double V[16];
  double B[8];
  double b_u[6];
  double U[4];
  double h[3];
  double u[3];
  double y[2];
  const double *x_data;
  double absxk;
  double b_y;
  double d;
  double scale;
  double t;
  double *r1;
  int k;
  int nIts;
  boolean_T exitg1;
  boolean_T p;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  x_data = x->data;
  /*  Form the coefficient matrix */
  d = x_data[0];
  t = x_data[1];
  B[0] = d * d + t * t;
  B[2] = d;
  B[4] = t;
  d = x_data[x->size[0]];
  t = x_data[x->size[0] + 1];
  B[1] = d * d + t * t;
  B[3] = d;
  B[5] = t;
  for (k = 0; k < 2; k++) {
    B[k + 6] = 1.0;
  }
  /*  Least squares estimate is right singular vector corresp. to smallest */
  /*  singular value of B */
  p = true;
  for (k = 0; k < 8; k++) {
    if (p) {
      d = B[k];
      if (rtIsInf(d) || rtIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    d_svd(B, U, y, V);
  } else {
    for (k = 0; k < 16; k++) {
      V[k] = rtNaN;
    }
  }
  /*  For clarity, set the quadratic form variables */
  /*  Convert to centre/radius */
  scale = 3.3121686421112381E-170;
  /*  2) Nonlinear refinement to miminise geometric error, and compute residual
   */
  /*  [z, r, residual] = fitcircle_geometric(x, z, r); */
  /*  NESTED FUNCTIONS */
  /*      function [z, r, residual] = fitcircle_geometric(x, z0, r0) */
  /*  Use a simple Gauss Newton method to minimize the geometric error */
  /*  Set initial u */
  d = 2.0 * V[12];
  absxk = fabs(V[13]);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  u[0] = -V[13] / d;
  absxk = fabs(V[14]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  u[1] = -V[14] / d;
  b_y = scale * sqrt(b_y);
  scale = b_y / (2.0 * V[12]);
  u[2] = sqrt(scale * scale - V[15] / V[12]);
  /*  Delta is the norm of current step, scaled by the norm of u */
  nIts = 0;
  emxInit_real_T(&b_r, 2);
  exitg1 = false;
  while ((!exitg1) && (nIts < 100)) {
    /*  Find the function and Jacobian  */
    /* SYS   Nonlinear system to be minimised - the objective */
    /* function is the distance to each point from the fitted circle */
    /* contained in u */
    /*  Objective function */
    k = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 2;
    b_r->size[1] = 2;
    emxEnsureCapacity_real_T(b_r, k);
    r1 = b_r->data;
    r1[0] = u[0];
    r1[1] = u[1];
    r1[2] = u[0];
    r1[3] = u[1];
    if (x->size[0] == 2) {
      for (k = 0; k < 4; k++) {
        U[k] = r1[k] - x_data[k];
      }
    } else {
      minus(U, b_r, x);
    }
    /*  Jacobian */
    /*  Solve for the step and update u */
    y[0] = sqrt(U[0] * U[0] + U[1] * U[1]);
    d = u[0] - x_data[0];
    t = u[1] - x_data[1];
    scale = sqrt(d * d + t * t);
    b_u[0] = -(d / scale);
    b_u[2] = -(t / scale);
    y[1] = sqrt(U[2] * U[2] + U[3] * U[3]);
    d = u[0] - x_data[x->size[0]];
    t = u[1] - x_data[x->size[0] + 1];
    scale = sqrt(d * d + t * t);
    b_u[1] = -(d / scale);
    b_u[3] = -(t / scale);
    for (k = 0; k < 2; k++) {
      b_u[k + 4] = 1.0;
    }
    y[0] -= u[2];
    y[1] -= u[2];
    d_mldivide(b_u, y, h);
    /*  Check for convergence */
    b_y = 0.0;
    absxk = 0.0;
    for (k = 0; k < 3; k++) {
      d = h[k];
      t = u[k] + d;
      u[k] = t;
      scale = fabs(d);
      if (rtIsNaN(scale) || (scale > b_y)) {
        b_y = scale;
      }
      scale = fabs(t);
      if (rtIsNaN(scale) || (scale > absxk)) {
        absxk = scale;
      }
    }
    if (b_y / absxk < 1.0E-5) {
      exitg1 = true;
    } else {
      nIts++;
    }
  }
  *r = u[2];
  /* SYS   Nonlinear system to be minimised - the objective */
  /* function is the distance to each point from the fitted circle */
  /* contained in u */
  /*  Objective function */
  k = b_r->size[0] * b_r->size[1];
  b_r->size[0] = 2;
  b_r->size[1] = 2;
  emxEnsureCapacity_real_T(b_r, k);
  r1 = b_r->data;
  z[0] = u[0];
  r1[0] = u[0];
  r1[1] = u[1];
  z[1] = u[1];
  r1[2] = u[0];
  r1[3] = u[1];
  if (x->size[0] == 2) {
    for (k = 0; k < 4; k++) {
      U[k] = r1[k] - x_data[k];
    }
  } else {
    minus(U, b_r, x);
  }
  emxFree_real_T(&b_r);
  /*  Jacobian */
  scale = 3.3121686421112381E-170;
  absxk = fabs(sqrt(U[0] * U[0] + U[1] * U[1]) - u[2]);
  if (absxk > 3.3121686421112381E-170) {
    *residual = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    *residual = t * t;
  }
  absxk = fabs(sqrt(U[2] * U[2] + U[3] * U[3]) - u[2]);
  if (absxk > scale) {
    t = scale / absxk;
    *residual = *residual * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    *residual += t * t;
  }
  *residual = scale * sqrt(*residual);
  /*  sys */
  /*      end % fitcircle_geometric */
  /*  END NESTED FUNCTIONS */
}

/*
 * File trailer for fitcircle.c
 *
 * [EOF]
 */
