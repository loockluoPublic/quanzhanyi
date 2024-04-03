/*
 * File: fitcircle.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "fitcircle.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "qrsolve.h"
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
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxArray_real_T *U;
  emxArray_real_T *a;
  emxArray_real_T *b_x;
  emxArray_real_T *b_y;
  emxArray_real_T *c_x;
  emxArray_real_T *d_y;
  emxArray_real_T *denom;
  emxArray_real_T *e_y;
  emxArray_real_T *f_y;
  emxArray_real_T *x1_contents;
  emxArray_real_T *x2_contents;
  emxArray_real_T *y;
  double V[16];
  double A_data[9];
  double s_data[4];
  double h[3];
  double absxk;
  double c_y;
  double d;
  double scale;
  double t;
  double u_idx_0;
  double u_idx_1;
  int ibtile;
  int m_contents;
  int nIts;
  int nx;
  int r3;
  int rtemp;
  boolean_T exitg1;
  boolean_T p;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInit_real_T(&x1_contents, 1);
  m_contents = x->size[1];
  nx = x->size[1];
  r3 = x1_contents->size[0];
  x1_contents->size[0] = x->size[1];
  emxEnsureCapacity_real_T(x1_contents, r3);
  for (r3 = 0; r3 < nx; r3++) {
    x1_contents->data[r3] = x->data[2 * r3];
  }
  emxInit_real_T(&x2_contents, 1);
  nx = x->size[1];
  r3 = x2_contents->size[0];
  x2_contents->size[0] = x->size[1];
  emxEnsureCapacity_real_T(x2_contents, r3);
  for (r3 = 0; r3 < nx; r3++) {
    x2_contents->data[r3] = x->data[2 * r3 + 1];
  }
  emxInit_real_T(&y, 1);
  /*  Form the coefficient matrix */
  r3 = y->size[0];
  y->size[0] = x1_contents->size[0];
  emxEnsureCapacity_real_T(y, r3);
  nx = x1_contents->size[0];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    y->data[ibtile] = x1_contents->data[ibtile] * x1_contents->data[ibtile];
  }
  emxInit_real_T(&b_y, 1);
  r3 = b_y->size[0];
  b_y->size[0] = x2_contents->size[0];
  emxEnsureCapacity_real_T(b_y, r3);
  nx = x2_contents->size[0];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    b_y->data[ibtile] = x2_contents->data[ibtile] * x2_contents->data[ibtile];
  }
  emxInit_real_T(&B, 2);
  r3 = B->size[0] * B->size[1];
  B->size[0] = y->size[0];
  B->size[1] = 4;
  emxEnsureCapacity_real_T(B, r3);
  nx = y->size[0];
  for (r3 = 0; r3 < nx; r3++) {
    B->data[r3] = y->data[r3] + b_y->data[r3];
  }
  nx = x1_contents->size[0];
  for (r3 = 0; r3 < nx; r3++) {
    B->data[r3 + B->size[0]] = x1_contents->data[r3];
  }
  nx = x2_contents->size[0];
  for (r3 = 0; r3 < nx; r3++) {
    B->data[r3 + B->size[0] * 2] = x2_contents->data[r3];
  }
  nx = x->size[1];
  for (r3 = 0; r3 < nx; r3++) {
    B->data[r3 + B->size[0] * 3] = 1.0;
  }
  /*  Least squares estimate is right singular vector corresp. to smallest */
  /*  singular value of B */
  nx = B->size[0] << 2;
  p = true;
  for (ibtile = 0; ibtile < nx; ibtile++) {
    if ((!p) || (rtIsInf(B->data[ibtile]) || rtIsNaN(B->data[ibtile]))) {
      p = false;
    }
  }
  if (p) {
    emxInit_real_T(&U, 2);
    c_svd(B, U, s_data, &nx, V);
    emxFree_real_T(&U);
  } else {
    for (r3 = 0; r3 < 16; r3++) {
      V[r3] = rtNaN;
    }
  }
  emxFree_real_T(&B);
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
    c_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    c_y = t * t;
  }
  u_idx_0 = -V[13] / d;
  absxk = fabs(V[14]);
  if (absxk > scale) {
    t = scale / absxk;
    c_y = c_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    c_y += t * t;
  }
  u_idx_1 = -V[14] / d;
  c_y = scale * sqrt(c_y);
  absxk = c_y / (2.0 * V[12]);
  *r = sqrt(absxk * absxk - V[15] / V[12]);
  /*  Delta is the norm of current step, scaled by the norm of u */
  nIts = 0;
  emxInit_real_T(&A, 2);
  emxInit_real_T(&denom, 1);
  emxInit_real_T(&d_y, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&b_x, 1);
  emxInit_real_T(&c_x, 1);
  emxInit_real_T(&e_y, 2);
  exitg1 = false;
  while ((!exitg1) && (nIts < 100)) {
    /*  Find the function and Jacobian  */
    /* SYS   Nonlinear system to be minimised - the objective */
    /* function is the distance to each point from the fitted circle */
    /* contained in u */
    /*  Objective function */
    r3 = a->size[0] * a->size[1];
    a->size[0] = 2;
    a->size[1] = m_contents;
    emxEnsureCapacity_real_T(a, r3);
    for (r3 = 0; r3 < m_contents; r3++) {
      ibtile = r3 << 1;
      a->data[ibtile] = u_idx_0;
      a->data[ibtile + 1] = u_idx_1;
    }
    nx = 2 * a->size[1];
    r3 = a->size[0] * a->size[1];
    a->size[0] = 2;
    emxEnsureCapacity_real_T(a, r3);
    for (r3 = 0; r3 < nx; r3++) {
      a->data[r3] -= x->data[r3];
    }
    r3 = d_y->size[0] * d_y->size[1];
    d_y->size[0] = 2;
    d_y->size[1] = a->size[1];
    emxEnsureCapacity_real_T(d_y, r3);
    nx = a->size[1] << 1;
    for (ibtile = 0; ibtile < nx; ibtile++) {
      d_y->data[ibtile] = a->data[ibtile] * a->data[ibtile];
    }
    if (d_y->size[1] == 0) {
      e_y->size[0] = 1;
      e_y->size[1] = 0;
    } else {
      ibtile = d_y->size[1];
      r3 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = d_y->size[1];
      emxEnsureCapacity_real_T(e_y, r3);
      for (r3 = 0; r3 < ibtile; r3++) {
        nx = r3 << 1;
        e_y->data[r3] = d_y->data[nx] + d_y->data[nx + 1];
      }
    }
    nx = e_y->size[1];
    for (ibtile = 0; ibtile < nx; ibtile++) {
      e_y->data[ibtile] = sqrt(e_y->data[ibtile]);
    }
    r3 = b_y->size[0];
    b_y->size[0] = e_y->size[1];
    emxEnsureCapacity_real_T(b_y, r3);
    nx = e_y->size[1];
    for (r3 = 0; r3 < nx; r3++) {
      b_y->data[r3] = e_y->data[r3] - *r;
    }
    /*  Jacobian */
    r3 = b_x->size[0];
    b_x->size[0] = x1_contents->size[0];
    emxEnsureCapacity_real_T(b_x, r3);
    nx = x1_contents->size[0];
    for (r3 = 0; r3 < nx; r3++) {
      b_x->data[r3] = u_idx_0 - x1_contents->data[r3];
    }
    r3 = c_x->size[0];
    c_x->size[0] = x2_contents->size[0];
    emxEnsureCapacity_real_T(c_x, r3);
    nx = x2_contents->size[0];
    for (r3 = 0; r3 < nx; r3++) {
      c_x->data[r3] = u_idx_1 - x2_contents->data[r3];
    }
    r3 = denom->size[0];
    denom->size[0] = b_x->size[0];
    emxEnsureCapacity_real_T(denom, r3);
    nx = b_x->size[0];
    for (ibtile = 0; ibtile < nx; ibtile++) {
      denom->data[ibtile] = b_x->data[ibtile] * b_x->data[ibtile];
    }
    r3 = y->size[0];
    y->size[0] = c_x->size[0];
    emxEnsureCapacity_real_T(y, r3);
    nx = c_x->size[0];
    for (ibtile = 0; ibtile < nx; ibtile++) {
      y->data[ibtile] = c_x->data[ibtile] * c_x->data[ibtile];
    }
    nx = denom->size[0];
    for (r3 = 0; r3 < nx; r3++) {
      denom->data[r3] += y->data[r3];
    }
    nx = denom->size[0];
    for (ibtile = 0; ibtile < nx; ibtile++) {
      denom->data[ibtile] = sqrt(denom->data[ibtile]);
    }
    /*  Solve for the step and update u */
    r3 = A->size[0] * A->size[1];
    A->size[0] = b_x->size[0];
    A->size[1] = 3;
    emxEnsureCapacity_real_T(A, r3);
    nx = b_x->size[0];
    for (r3 = 0; r3 < nx; r3++) {
      A->data[r3] = -(b_x->data[r3] / denom->data[r3]);
    }
    nx = c_x->size[0];
    for (r3 = 0; r3 < nx; r3++) {
      A->data[r3 + A->size[0]] = -(c_x->data[r3] / denom->data[r3]);
    }
    for (r3 = 0; r3 < m_contents; r3++) {
      A->data[r3 + A->size[0] * 2] = 1.0;
    }
    if ((A->size[0] == 0) || (b_y->size[0] == 0)) {
      h[0] = 0.0;
      h[1] = 0.0;
      h[2] = 0.0;
    } else if (A->size[0] == 3) {
      for (r3 = 0; r3 < 9; r3++) {
        A_data[r3] = A->data[r3];
      }
      nx = 0;
      ibtile = 1;
      r3 = 2;
      absxk = fabs(A->data[0]);
      t = fabs(A->data[1]);
      if (t > absxk) {
        absxk = t;
        nx = 1;
        ibtile = 0;
      }
      if (fabs(A->data[2]) > absxk) {
        nx = 2;
        ibtile = 1;
        r3 = 0;
      }
      A_data[ibtile] = A->data[ibtile] / A->data[nx];
      A_data[r3] /= A_data[nx];
      A_data[ibtile + 3] -= A_data[ibtile] * A_data[nx + 3];
      A_data[r3 + 3] -= A_data[r3] * A_data[nx + 3];
      A_data[ibtile + 6] -= A_data[ibtile] * A_data[nx + 6];
      A_data[r3 + 6] -= A_data[r3] * A_data[nx + 6];
      if (fabs(A_data[r3 + 3]) > fabs(A_data[ibtile + 3])) {
        rtemp = ibtile;
        ibtile = r3;
        r3 = rtemp;
      }
      A_data[r3 + 3] /= A_data[ibtile + 3];
      A_data[r3 + 6] -= A_data[r3 + 3] * A_data[ibtile + 6];
      h[1] = b_y->data[ibtile] - b_y->data[nx] * A_data[ibtile];
      h[2] =
          (b_y->data[r3] - b_y->data[nx] * A_data[r3]) - h[1] * A_data[r3 + 3];
      h[2] /= A_data[r3 + 6];
      h[0] = b_y->data[nx] - h[2] * A_data[nx + 6];
      h[1] -= h[2] * A_data[ibtile + 6];
      h[1] /= A_data[ibtile + 3];
      h[0] -= h[1] * A_data[nx + 3];
      h[0] /= A_data[nx];
    } else {
      qrsolve(A, b_y, h);
    }
    /*  Check for convergence */
    c_y = 0.0;
    absxk = 0.0;
    d = u_idx_0 + h[0];
    u_idx_0 = d;
    t = fabs(h[0]);
    if (rtIsNaN(t) || (t > 0.0)) {
      c_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > 0.0)) {
      absxk = t;
    }
    d = u_idx_1 + h[1];
    u_idx_1 = d;
    t = fabs(h[1]);
    if (rtIsNaN(t) || (t > c_y)) {
      c_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > absxk)) {
      absxk = t;
    }
    d = *r + h[2];
    *r = d;
    t = fabs(h[2]);
    if (rtIsNaN(t) || (t > c_y)) {
      c_y = t;
    }
    t = fabs(d);
    if (rtIsNaN(t) || (t > absxk)) {
      absxk = t;
    }
    if (c_y / absxk < 1.0E-5) {
      exitg1 = true;
    } else {
      nIts++;
    }
  }
  emxFree_real_T(&y);
  emxFree_real_T(&c_x);
  emxFree_real_T(&b_x);
  emxFree_real_T(&d_y);
  emxFree_real_T(&denom);
  emxFree_real_T(&A);
  emxFree_real_T(&x1_contents);
  emxFree_real_T(&x2_contents);
  z[0] = u_idx_0;
  z[1] = u_idx_1;
  /* SYS   Nonlinear system to be minimised - the objective */
  /* function is the distance to each point from the fitted circle */
  /* contained in u */
  /*  Objective function */
  r3 = a->size[0] * a->size[1];
  a->size[0] = 2;
  a->size[1] = x->size[1];
  emxEnsureCapacity_real_T(a, r3);
  nx = x->size[1];
  for (r3 = 0; r3 < nx; r3++) {
    ibtile = r3 << 1;
    a->data[ibtile] = u_idx_0;
    a->data[ibtile + 1] = u_idx_1;
  }
  nx = 2 * a->size[1];
  r3 = a->size[0] * a->size[1];
  a->size[0] = 2;
  emxEnsureCapacity_real_T(a, r3);
  for (r3 = 0; r3 < nx; r3++) {
    a->data[r3] -= x->data[r3];
  }
  emxInit_real_T(&f_y, 2);
  r3 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 2;
  f_y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(f_y, r3);
  nx = a->size[1] << 1;
  for (ibtile = 0; ibtile < nx; ibtile++) {
    f_y->data[ibtile] = a->data[ibtile] * a->data[ibtile];
  }
  emxFree_real_T(&a);
  if (f_y->size[1] == 0) {
    e_y->size[0] = 1;
    e_y->size[1] = 0;
  } else {
    ibtile = f_y->size[1];
    r3 = e_y->size[0] * e_y->size[1];
    e_y->size[0] = 1;
    e_y->size[1] = f_y->size[1];
    emxEnsureCapacity_real_T(e_y, r3);
    for (r3 = 0; r3 < ibtile; r3++) {
      nx = r3 << 1;
      e_y->data[r3] = f_y->data[nx] + f_y->data[nx + 1];
    }
  }
  emxFree_real_T(&f_y);
  nx = e_y->size[1];
  for (ibtile = 0; ibtile < nx; ibtile++) {
    e_y->data[ibtile] = sqrt(e_y->data[ibtile]);
  }
  r3 = b_y->size[0];
  b_y->size[0] = e_y->size[1];
  emxEnsureCapacity_real_T(b_y, r3);
  nx = e_y->size[1];
  for (r3 = 0; r3 < nx; r3++) {
    b_y->data[r3] = e_y->data[r3] - *r;
  }
  emxFree_real_T(&e_y);
  /*  Jacobian */
  if (b_y->size[0] == 0) {
    *residual = 0.0;
  } else {
    *residual = 0.0;
    if (b_y->size[0] == 1) {
      *residual = fabs(b_y->data[0]);
    } else {
      scale = 3.3121686421112381E-170;
      nx = b_y->size[0];
      for (ibtile = 0; ibtile < nx; ibtile++) {
        absxk = fabs(b_y->data[ibtile]);
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
  emxFree_real_T(&b_y);
  /*  sys */
  /*      end % fitcircle_geometric */
  /*  END NESTED FUNCTIONS */
}

/*
 * File trailer for fitcircle.c
 *
 * [EOF]
 */
