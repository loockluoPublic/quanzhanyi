/*
 * File: fitcircle.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 15-Apr-2024 22:57:09
 */

/* Include Files */
#include "fitcircle.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "svd.h"
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
 * Arguments    : double in1[3]
 *                const double in2[3]
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                const emxArray_real_T *in5
 *                const int in6[2]
 *                const emxArray_real_T *in7
 * Return Type  : void
 */
void binary_expand_op(double in1[3], const double in2[3],
                      const emxArray_real_T *in3, const emxArray_real_T *in4,
                      const emxArray_real_T *in5, const int in6[2],
                      const emxArray_real_T *in7)
{
  emxArray_real_T *b_in2;
  emxArray_real_T *e_in2;
  emxArray_real_T *f_in2;
  const double *in3_data;
  const double *in4_data;
  const double *in5_data;
  const double *in7_data;
  double c_in2;
  double d_in2;
  double *b_in2_data;
  double *c_in2_data;
  double *in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in7_data = in7->data;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  emxInit_real_T(&b_in2, 1);
  c_in2 = in2[0];
  d_in2 = in2[1];
  i = b_in2->size[0];
  if (in4->size[0] == 1) {
    b_in2->size[0] = in3->size[0];
  } else {
    b_in2->size[0] = in4->size[0];
  }
  emxEnsureCapacity_real_T(b_in2, i);
  in2_data = b_in2->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] =
        -((c_in2 - in3_data[i * stride_0_0]) / in4_data[i * stride_1_0]);
  }
  emxInit_real_T(&e_in2, 1);
  i = e_in2->size[0];
  if (in4->size[0] == 1) {
    e_in2->size[0] = in5->size[0];
  } else {
    e_in2->size[0] = in4->size[0];
  }
  emxEnsureCapacity_real_T(e_in2, i);
  b_in2_data = e_in2->data;
  stride_0_0 = (in5->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  if (in4->size[0] == 1) {
    loop_ub = in5->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] =
        -((d_in2 - in5_data[i * stride_0_0]) / in4_data[i * stride_1_0]);
  }
  emxInit_real_T(&f_in2, 2);
  c_in2 = in2[2];
  i = f_in2->size[0] * f_in2->size[1];
  f_in2->size[0] = b_in2->size[0];
  f_in2->size[1] = 3;
  emxEnsureCapacity_real_T(f_in2, i);
  c_in2_data = f_in2->data;
  loop_ub = b_in2->size[0];
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
  i = b_in2->size[0];
  b_in2->size[0] = in7->size[1];
  emxEnsureCapacity_real_T(b_in2, i);
  in2_data = b_in2->data;
  loop_ub = in7->size[1];
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = in7_data[i] - c_in2;
  }
  mldivide(f_in2, b_in2, in1);
  emxFree_real_T(&f_in2);
  emxFree_real_T(&b_in2);
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
  double U[4];
  double y[2];
  const double *x_data;
  double absxk;
  double b_y;
  double d;
  double scale;
  double t;
  double u_idx_0;
  double u_idx_1;
  double *r1;
  int U_tmp;
  int i;
  int k;
  boolean_T exitg1;
  boolean_T p;
  x_data = x->data;
  /*  Form the coefficient matrix */
  d = x_data[0];
  absxk = x_data[1];
  B[0] = d * d + absxk * absxk;
  B[2] = d;
  B[4] = absxk;
  d = x_data[x->size[0]];
  absxk = x_data[x->size[0] + 1];
  B[1] = d * d + absxk * absxk;
  B[3] = d;
  B[5] = absxk;
  for (i = 0; i < 2; i++) {
    B[i + 6] = 1.0;
  }
  /*  Least squares estimate is right singular vector corresp. to smallest */
  /*  singular value of B */
  p = true;
  for (k = 0; k < 8; k++) {
    if ((!p) || (rtIsInf(B[k]) || rtIsNaN(B[k]))) {
      p = false;
    }
  }
  if (p) {
    c_svd(B, U, y, V);
  } else {
    for (i = 0; i < 16; i++) {
      V[i] = rtNaN;
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
  u_idx_0 = -V[13] / d;
  absxk = fabs(V[14]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  u_idx_1 = -V[14] / d;
  b_y = scale * sqrt(b_y);
  absxk = b_y / (2.0 * V[12]);
  *r = sqrt(absxk * absxk - V[15] / V[12]);
  /*  Delta is the norm of current step, scaled by the norm of u */
  k = 0;
  emxInit_real_T(&b_r, 2);
  exitg1 = false;
  while ((!exitg1) && (k < 100)) {
    double u[6];
    double h[3];
    /*  Find the function and Jacobian  */
    /* SYS   Nonlinear system to be minimised - the objective */
    /* function is the distance to each point from the fitted circle */
    /* contained in u */
    /*  Objective function */
    i = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 2;
    b_r->size[1] = 2;
    emxEnsureCapacity_real_T(b_r, i);
    r1 = b_r->data;
    r1[0] = u_idx_0;
    r1[1] = u_idx_1;
    r1[2] = u_idx_0;
    r1[3] = u_idx_1;
    if (x->size[0] == 2) {
      for (i = 0; i < 2; i++) {
        U_tmp = i << 1;
        U[U_tmp] = r1[2 * i] - x_data[x->size[0] * i];
        U[U_tmp + 1] = r1[2 * i + 1] - x_data[x->size[0] * i + 1];
      }
    } else {
      minus(U, b_r, x);
    }
    /*  Jacobian */
    /*  Solve for the step and update u */
    y[0] = sqrt(U[0] * U[0] + U[1] * U[1]);
    d = u_idx_0 - x_data[0];
    absxk = u_idx_1 - x_data[1];
    t = sqrt(d * d + absxk * absxk);
    u[0] = -(d / t);
    u[2] = -(absxk / t);
    y[1] = sqrt(U[2] * U[2] + U[3] * U[3]);
    d = u_idx_0 - x_data[x->size[0]];
    absxk = u_idx_1 - x_data[x->size[0] + 1];
    t = sqrt(d * d + absxk * absxk);
    u[1] = -(d / t);
    u[3] = -(absxk / t);
    for (i = 0; i < 2; i++) {
      u[i + 4] = 1.0;
    }
    y[0] -= *r;
    y[1] -= *r;
    b_mldivide(u, y, h);
    /*  Check for convergence */
    b_y = 0.0;
    absxk = 0.0;
    d = u_idx_0 + h[0];
    u_idx_0 = d;
    t = fabs(h[0]);
    if (rtIsNaN(t) || (t > 0.0)) {
      b_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > 0.0)) {
      absxk = t;
    }
    d = u_idx_1 + h[1];
    u_idx_1 = d;
    t = fabs(h[1]);
    if (rtIsNaN(t) || (t > b_y)) {
      b_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > absxk)) {
      absxk = t;
    }
    d = *r + h[2];
    *r = d;
    t = fabs(h[2]);
    if (rtIsNaN(t) || (t > b_y)) {
      b_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > absxk)) {
      absxk = t;
    }
    if (b_y / absxk < 1.0E-5) {
      exitg1 = true;
    } else {
      k++;
    }
  }
  /* SYS   Nonlinear system to be minimised - the objective */
  /* function is the distance to each point from the fitted circle */
  /* contained in u */
  /*  Objective function */
  i = b_r->size[0] * b_r->size[1];
  b_r->size[0] = 2;
  b_r->size[1] = 2;
  emxEnsureCapacity_real_T(b_r, i);
  r1 = b_r->data;
  z[0] = u_idx_0;
  r1[0] = u_idx_0;
  r1[1] = u_idx_1;
  z[1] = u_idx_1;
  r1[2] = u_idx_0;
  r1[3] = u_idx_1;
  if (x->size[0] == 2) {
    for (i = 0; i < 2; i++) {
      U_tmp = i << 1;
      U[U_tmp] = r1[2 * i] - x_data[x->size[0] * i];
      U[U_tmp + 1] = r1[2 * i + 1] - x_data[x->size[0] * i + 1];
    }
  } else {
    minus(U, b_r, x);
  }
  emxFree_real_T(&b_r);
  /*  Jacobian */
  scale = 3.3121686421112381E-170;
  absxk = fabs(sqrt(U[0] * U[0] + U[1] * U[1]) - *r);
  if (absxk > 3.3121686421112381E-170) {
    *residual = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    *residual = t * t;
  }
  absxk = fabs(sqrt(U[2] * U[2] + U[3] * U[3]) - *r);
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
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
void plus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 1);
  i = b_in1->size[0];
  if (in2->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2->size[0];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] + in2_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = b_in1->size[0];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * File trailer for fitcircle.c
 *
 * [EOF]
 */
