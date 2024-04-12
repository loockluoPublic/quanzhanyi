/*
 * File: fitcircle.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
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
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
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
  b_captured_var b_x;
  b_captured_var x1;
  b_captured_var x2;
  captured_var m;
  emxArray_real_T *J;
  emxArray_real_T *S;
  emxArray_real_T *U;
  emxArray_real_T *a;
  emxArray_real_T *b_J;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *e_y;
  emxArray_real_T *f_y;
  emxArray_real_T *y;
  double V[16];
  double h[3];
  double u[3];
  double absxk;
  double d;
  double d_y;
  double scale;
  double t;
  int ibtile;
  int jtilecol;
  int nx;
  boolean_T exitg1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInitStruct_captured_var(&b_x);
  jtilecol = b_x.contents->size[0] * b_x.contents->size[1];
  b_x.contents->size[0] = 2;
  b_x.contents->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b_x.contents, jtilecol);
  nx = 2 * x->size[1];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    b_x.contents->data[jtilecol] = x->data[jtilecol];
  }
  emxInitStruct_captured_var1(&x1);
  m.contents = x->size[1];
  nx = x->size[1];
  jtilecol = x1.contents->size[0];
  x1.contents->size[0] = x->size[1];
  emxEnsureCapacity_real_T(x1.contents, jtilecol);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    x1.contents->data[jtilecol] = x->data[2 * jtilecol];
  }
  emxInitStruct_captured_var1(&x2);
  nx = x->size[1];
  jtilecol = x2.contents->size[0];
  x2.contents->size[0] = x->size[1];
  emxEnsureCapacity_real_T(x2.contents, jtilecol);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    x2.contents->data[jtilecol] = x->data[2 * jtilecol + 1];
  }
  emxInit_real_T(&y, 1);
  /*  Form the coefficient matrix */
  /*  Least squares estimate is right singular vector corresp. to smallest */
  /*  singular value of B */
  jtilecol = y->size[0];
  y->size[0] = x1.contents->size[0];
  emxEnsureCapacity_real_T(y, jtilecol);
  nx = x1.contents->size[0];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    y->data[ibtile] = x1.contents->data[ibtile] * x1.contents->data[ibtile];
  }
  emxInit_real_T(&b_y, 1);
  jtilecol = b_y->size[0];
  b_y->size[0] = x2.contents->size[0];
  emxEnsureCapacity_real_T(b_y, jtilecol);
  nx = x2.contents->size[0];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    b_y->data[ibtile] = x2.contents->data[ibtile] * x2.contents->data[ibtile];
  }
  emxInit_real_T(&c_y, 2);
  jtilecol = c_y->size[0] * c_y->size[1];
  c_y->size[0] = y->size[0];
  c_y->size[1] = 4;
  emxEnsureCapacity_real_T(c_y, jtilecol);
  nx = y->size[0];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    c_y->data[jtilecol] = y->data[jtilecol] + b_y->data[jtilecol];
  }
  emxFree_real_T(&b_y);
  nx = x1.contents->size[0];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    c_y->data[jtilecol + c_y->size[0]] = x1.contents->data[jtilecol];
  }
  nx = x2.contents->size[0];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    c_y->data[jtilecol + c_y->size[0] * 2] = x2.contents->data[jtilecol];
  }
  nx = x->size[1];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    c_y->data[jtilecol + c_y->size[0] * 3] = 1.0;
  }
  emxInit_real_T(&U, 2);
  emxInit_real_T(&S, 2);
  svd(c_y, U, S, V);
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
  emxFree_real_T(&c_y);
  emxFree_real_T(&S);
  emxFree_real_T(&U);
  if (absxk > 3.3121686421112381E-170) {
    d_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    d_y = t * t;
  }
  u[0] = -V[13] / d;
  absxk = fabs(V[14]);
  if (absxk > scale) {
    t = scale / absxk;
    d_y = d_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d_y += t * t;
  }
  u[1] = -V[14] / d;
  d_y = scale * sqrt(d_y);
  scale = d_y / (2.0 * V[12]);
  u[2] = sqrt(scale * scale - V[15] / V[12]);
  /*  Delta is the norm of current step, scaled by the norm of u */
  ibtile = 0;
  emxInit_real_T(&J, 2);
  emxInit_real_T(&b_J, 2);
  exitg1 = false;
  while ((!exitg1) && (ibtile < 100)) {
    /*  Find the function and Jacobian  */
    sys(&m, &b_x, &x1, &x2, u, y, J);
    /*  Solve for the step and update u */
    jtilecol = b_J->size[0] * b_J->size[1];
    b_J->size[0] = J->size[0];
    b_J->size[1] = 3;
    emxEnsureCapacity_real_T(b_J, jtilecol);
    nx = J->size[0] * 3;
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_J->data[jtilecol] = -J->data[jtilecol];
    }
    mldivide(b_J, y, h);
    /*  Check for convergence */
    d_y = 0.0;
    scale = 0.0;
    d = u[0] + h[0];
    u[0] = d;
    absxk = fabs(h[0]);
    if (rtIsNaN(absxk) || (absxk > 0.0)) {
      d_y = absxk;
    }
    absxk = fabs(d);
    if (rtIsNaN(absxk) || (absxk > 0.0)) {
      scale = absxk;
    }
    d = u[1] + h[1];
    u[1] = d;
    absxk = fabs(h[1]);
    if (rtIsNaN(absxk) || (absxk > d_y)) {
      d_y = absxk;
    }
    absxk = fabs(d);
    if (rtIsNaN(absxk) || (absxk > scale)) {
      scale = absxk;
    }
    d = u[2] + h[2];
    u[2] = d;
    absxk = fabs(h[2]);
    if (rtIsNaN(absxk) || (absxk > d_y)) {
      d_y = absxk;
    }
    absxk = fabs(d);
    if (rtIsNaN(absxk) || (absxk > scale)) {
      scale = absxk;
    }
    if (d_y / scale < 1.0E-5) {
      exitg1 = true;
    } else {
      ibtile++;
    }
  }
  emxFree_real_T(&b_J);
  emxFree_real_T(&J);
  emxFreeStruct_captured_var(&x1);
  emxFreeStruct_captured_var(&x2);
  emxInit_real_T(&a, 2);
  z[0] = u[0];
  z[1] = u[1];
  *r = u[2];
  /* SYS   Nonlinear system to be minimised - the objective */
  /* function is the distance to each point from the fitted circle */
  /* contained in u */
  /*  Objective function */
  jtilecol = a->size[0] * a->size[1];
  a->size[0] = 2;
  a->size[1] = x->size[1];
  emxEnsureCapacity_real_T(a, jtilecol);
  nx = x->size[1];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    ibtile = jtilecol << 1;
    a->data[ibtile] = u[0];
    a->data[ibtile + 1] = u[1];
  }
  nx = 2 * a->size[1];
  jtilecol = a->size[0] * a->size[1];
  a->size[0] = 2;
  emxEnsureCapacity_real_T(a, jtilecol);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    a->data[jtilecol] -= b_x.contents->data[jtilecol];
  }
  emxFreeStruct_captured_var(&b_x);
  emxInit_real_T(&e_y, 2);
  jtilecol = e_y->size[0] * e_y->size[1];
  e_y->size[0] = 2;
  e_y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(e_y, jtilecol);
  nx = a->size[1] << 1;
  for (ibtile = 0; ibtile < nx; ibtile++) {
    e_y->data[ibtile] = a->data[ibtile] * a->data[ibtile];
  }
  emxFree_real_T(&a);
  emxInit_real_T(&f_y, 2);
  if (e_y->size[1] == 0) {
    f_y->size[0] = 1;
    f_y->size[1] = 0;
  } else {
    ibtile = e_y->size[1];
    jtilecol = f_y->size[0] * f_y->size[1];
    f_y->size[0] = 1;
    f_y->size[1] = e_y->size[1];
    emxEnsureCapacity_real_T(f_y, jtilecol);
    for (jtilecol = 0; jtilecol < ibtile; jtilecol++) {
      nx = jtilecol << 1;
      f_y->data[jtilecol] = e_y->data[nx] + e_y->data[nx + 1];
    }
  }
  emxFree_real_T(&e_y);
  nx = f_y->size[1];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    f_y->data[ibtile] = sqrt(f_y->data[ibtile]);
  }
  jtilecol = y->size[0];
  y->size[0] = f_y->size[1];
  emxEnsureCapacity_real_T(y, jtilecol);
  nx = f_y->size[1];
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    y->data[jtilecol] = f_y->data[jtilecol] - u[2];
  }
  emxFree_real_T(&f_y);
  /*  Jacobian */
  if (y->size[0] == 0) {
    *residual = 0.0;
  } else {
    *residual = 0.0;
    if (y->size[0] == 1) {
      *residual = fabs(y->data[0]);
    } else {
      scale = 3.3121686421112381E-170;
      nx = y->size[0];
      for (ibtile = 0; ibtile < nx; ibtile++) {
        absxk = fabs(y->data[ibtile]);
        if (absxk > scale) {
          t = scale / absxk;
          *residual = *residual * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          *residual += t * t;
        }
      }
      *residual = scale * sqrt(*residual);
    }
  }
  emxFree_real_T(&y);
  /*  sys */
  /*      end % fitcircle_geometric */
  /*  END NESTED FUNCTIONS */
}

/*
 * SYS   Nonlinear system to be minimised - the objective
 * function is the distance to each point from the fitted circle
 * contained in u
 *
 * Arguments    : const captured_var *m
 *                const b_captured_var *x
 *                const b_captured_var *x1
 *                const b_captured_var *x2
 *                const double u[3]
 *                emxArray_real_T *f
 *                emxArray_real_T *J
 * Return Type  : void
 */
void sys(const captured_var *m, const b_captured_var *x,
         const b_captured_var *x1, const b_captured_var *x2, const double u[3],
         emxArray_real_T *f, emxArray_real_T *J)
{
  emxArray_real_T *a;
  emxArray_real_T *b_x;
  emxArray_real_T *b_y;
  emxArray_real_T *c_x;
  emxArray_real_T *c_y;
  emxArray_real_T *denom;
  emxArray_real_T *y;
  int ibtile;
  int loop_ub;
  int npages;
  int xi;
  emxInit_real_T(&a, 2);
  /*  Objective function */
  xi = a->size[0] * a->size[1];
  a->size[0] = 2;
  loop_ub = (int)m->contents;
  a->size[1] = loop_ub;
  emxEnsureCapacity_real_T(a, xi);
  for (npages = 0; npages < loop_ub; npages++) {
    ibtile = npages << 1;
    a->data[ibtile] = u[0];
    a->data[ibtile + 1] = u[1];
  }
  ibtile = 2 * a->size[1];
  xi = a->size[0] * a->size[1];
  a->size[0] = 2;
  emxEnsureCapacity_real_T(a, xi);
  for (xi = 0; xi < ibtile; xi++) {
    a->data[xi] -= x->contents->data[xi];
  }
  emxInit_real_T(&y, 2);
  xi = y->size[0] * y->size[1];
  y->size[0] = 2;
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(y, xi);
  ibtile = a->size[1] << 1;
  for (npages = 0; npages < ibtile; npages++) {
    y->data[npages] = a->data[npages] * a->data[npages];
  }
  emxFree_real_T(&a);
  emxInit_real_T(&b_y, 2);
  if (y->size[1] == 0) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else {
    npages = y->size[1];
    xi = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->size[1];
    emxEnsureCapacity_real_T(b_y, xi);
    for (xi = 0; xi < npages; xi++) {
      ibtile = xi << 1;
      b_y->data[xi] = y->data[ibtile] + y->data[ibtile + 1];
    }
  }
  emxFree_real_T(&y);
  ibtile = b_y->size[1];
  for (npages = 0; npages < ibtile; npages++) {
    b_y->data[npages] = sqrt(b_y->data[npages]);
  }
  xi = f->size[0];
  f->size[0] = b_y->size[1];
  emxEnsureCapacity_real_T(f, xi);
  ibtile = b_y->size[1];
  for (xi = 0; xi < ibtile; xi++) {
    f->data[xi] = b_y->data[xi] - u[2];
  }
  emxFree_real_T(&b_y);
  emxInit_real_T(&b_x, 1);
  /*  Jacobian */
  xi = b_x->size[0];
  b_x->size[0] = x1->contents->size[0];
  emxEnsureCapacity_real_T(b_x, xi);
  ibtile = x1->contents->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    b_x->data[xi] = u[0] - x1->contents->data[xi];
  }
  emxInit_real_T(&c_x, 1);
  xi = c_x->size[0];
  c_x->size[0] = x2->contents->size[0];
  emxEnsureCapacity_real_T(c_x, xi);
  ibtile = x2->contents->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    c_x->data[xi] = u[1] - x2->contents->data[xi];
  }
  emxInit_real_T(&denom, 1);
  xi = denom->size[0];
  denom->size[0] = b_x->size[0];
  emxEnsureCapacity_real_T(denom, xi);
  ibtile = b_x->size[0];
  for (npages = 0; npages < ibtile; npages++) {
    denom->data[npages] = b_x->data[npages] * b_x->data[npages];
  }
  emxInit_real_T(&c_y, 1);
  xi = c_y->size[0];
  c_y->size[0] = c_x->size[0];
  emxEnsureCapacity_real_T(c_y, xi);
  ibtile = c_x->size[0];
  for (npages = 0; npages < ibtile; npages++) {
    c_y->data[npages] = c_x->data[npages] * c_x->data[npages];
  }
  ibtile = denom->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    denom->data[xi] += c_y->data[xi];
  }
  emxFree_real_T(&c_y);
  ibtile = denom->size[0];
  for (npages = 0; npages < ibtile; npages++) {
    denom->data[npages] = sqrt(denom->data[npages]);
  }
  xi = J->size[0] * J->size[1];
  J->size[0] = b_x->size[0];
  J->size[1] = 3;
  emxEnsureCapacity_real_T(J, xi);
  ibtile = b_x->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    J->data[xi] = b_x->data[xi] / denom->data[xi];
  }
  emxFree_real_T(&b_x);
  ibtile = c_x->size[0];
  for (xi = 0; xi < ibtile; xi++) {
    J->data[xi + J->size[0]] = c_x->data[xi] / denom->data[xi];
  }
  emxFree_real_T(&c_x);
  emxFree_real_T(&denom);
  for (xi = 0; xi < loop_ub; xi++) {
    J->data[xi + J->size[0] * 2] = -1.0;
  }
}

/*
 * File trailer for fitcircle.c
 *
 * [EOF]
 */
