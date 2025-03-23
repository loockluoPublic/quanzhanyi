/*
 * File: fminsearch.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

/* Include Files */
#include "fminsearch.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double funfcn_workspace_aaa
 *                const emxArray_real_T *funfcn_workspace_Points1
 *                double funfcn_workspace_bbb
 *                double funfcn_workspace_ccc
 * Return Type  : double
 */
double fminsearch(double funfcn_workspace_aaa,
                  const emxArray_real_T *funfcn_workspace_Points1,
                  double funfcn_workspace_bbb, double funfcn_workspace_ccc)
{
  emxArray_real_T *b_x;
  emxArray_real_T *y;
  double fv[2];
  double v[2];
  const double *funfcn_workspace_Points1_data;
  double b_cfv_tmp_tmp;
  double cfv;
  double cfv_tmp_tmp;
  double fxr;
  double x;
  double xe;
  double xr;
  double *x_data;
  double *y_data;
  int b_exponent;
  int c_exponent;
  int exponent;
  int firstCol;
  int fun_evals;
  int itercount;
  int k;
  int lastCol;
  int nx;
  signed char idxb[2];
  signed char idx_idx_0;
  signed char idx_idx_1;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  funfcn_workspace_Points1_data = funfcn_workspace_Points1->data;
  emxInit_real_T(&b_x, 2);
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = funfcn_workspace_Points1->size[1];
  emxEnsureCapacity_real_T(b_x, k);
  x_data = b_x->data;
  nx = funfcn_workspace_Points1->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] =
        (funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
         funfcn_workspace_bbb * funfcn_workspace_Points1_data[3 * k + 1]) +
        funfcn_workspace_ccc * funfcn_workspace_Points1_data[3 * k + 2];
  }
  nx = b_x->size[1];
  emxInit_real_T(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  for (k = 0; k < nx; k++) {
    y_data[k] = fabs(x_data[k]);
  }
  xe = b_combineVectorElements(y);
  fv[0] = xe;
  v[0] = 0.0;
  v[1] = 0.00025;
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = funfcn_workspace_Points1->size[1];
  emxEnsureCapacity_real_T(b_x, k);
  x_data = b_x->data;
  nx = funfcn_workspace_Points1->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] =
        ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
          funfcn_workspace_bbb * funfcn_workspace_Points1_data[3 * k + 1]) +
         funfcn_workspace_ccc * funfcn_workspace_Points1_data[3 * k + 2]) +
        0.00025;
  }
  nx = b_x->size[1];
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  for (k = 0; k < nx; k++) {
    y_data[k] = fabs(x_data[k]);
  }
  cfv = b_combineVectorElements(y);
  fv[1] = cfv;
  if ((xe <= cfv) || rtIsNaN(cfv)) {
    idx_idx_0 = 1;
    idx_idx_1 = 2;
  } else {
    idx_idx_0 = 2;
    idx_idx_1 = 1;
  }
  itercount = 1;
  fun_evals = 2;
  lastCol = idx_idx_1 - 1;
  firstCol = idx_idx_0 - 1;
  exitg1 = false;
  while ((!exitg1) && ((fun_evals < 200) && (itercount < 200))) {
    xr = 0.0;
    cfv_tmp_tmp = fv[idx_idx_0 - 1];
    b_cfv_tmp_tmp = fv[idx_idx_1 - 1];
    cfv = fabs(cfv_tmp_tmp - b_cfv_tmp_tmp);
    if (cfv > 0.0) {
      xr = cfv;
    }
    xe = fabs(cfv_tmp_tmp);
    if (rtIsInf(xe) || rtIsNaN(xe)) {
      xe = rtNaN;
    } else if (xe < 4.4501477170144028E-308) {
      xe = 4.94065645841247E-324;
    } else {
      frexp(xe, &exponent);
      xe = ldexp(1.0, exponent - 53);
    }
    xe *= 10.0;
    if (rtIsNaN(xe)) {
      xe = rtNaN;
    } else if (xe < 4.4501477170144028E-308) {
      xe = 4.94065645841247E-324;
    } else {
      frexp(xe, &b_exponent);
      xe = ldexp(1.0, b_exponent - 53);
    }
    xe *= 10.0;
    if ((xe <= 0.0001) || rtIsNaN(xe)) {
      xe = 0.0001;
    }
    if (xr > xe) {
      p = false;
    } else {
      xr = 0.0;
      xe = v[idx_idx_0 - 1];
      cfv = fabs(xe - v[idx_idx_1 - 1]);
      if (cfv > 0.0) {
        xr = cfv;
      }
      xe = fabs(xe);
      if (rtIsInf(xe) || rtIsNaN(xe)) {
        xe = rtNaN;
      } else if (xe < 4.4501477170144028E-308) {
        xe = 4.94065645841247E-324;
      } else {
        frexp(xe, &c_exponent);
        xe = ldexp(1.0, c_exponent - 53);
      }
      xe *= 10.0;
      if ((xe <= 0.0001) || rtIsNaN(xe)) {
        xe = 0.0001;
      }
      p = (xr <= xe);
    }
    if (!p) {
      xr = 2.0 * v[firstCol] - v[lastCol];
      k = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = funfcn_workspace_Points1->size[1];
      emxEnsureCapacity_real_T(b_x, k);
      x_data = b_x->data;
      nx = funfcn_workspace_Points1->size[1];
      for (k = 0; k < nx; k++) {
        x_data[k] =
            ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
              funfcn_workspace_bbb * funfcn_workspace_Points1_data[3 * k + 1]) +
             funfcn_workspace_ccc * funfcn_workspace_Points1_data[3 * k + 2]) +
            xr;
      }
      nx = b_x->size[1];
      k = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = b_x->size[1];
      emxEnsureCapacity_real_T(y, k);
      y_data = y->data;
      for (k = 0; k < nx; k++) {
        y_data[k] = fabs(x_data[k]);
      }
      fxr = b_combineVectorElements(y);
      fun_evals++;
      guard1 = false;
      guard2 = false;
      if (fxr < cfv_tmp_tmp) {
        xe = 3.0 * v[firstCol] - 2.0 * v[lastCol];
        k = b_x->size[0] * b_x->size[1];
        b_x->size[0] = 1;
        b_x->size[1] = funfcn_workspace_Points1->size[1];
        emxEnsureCapacity_real_T(b_x, k);
        x_data = b_x->data;
        nx = funfcn_workspace_Points1->size[1];
        for (k = 0; k < nx; k++) {
          x_data[k] =
              ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
                funfcn_workspace_bbb *
                    funfcn_workspace_Points1_data[3 * k + 1]) +
               funfcn_workspace_ccc *
                   funfcn_workspace_Points1_data[3 * k + 2]) +
              xe;
        }
        nx = b_x->size[1];
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = b_x->size[1];
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        for (k = 0; k < nx; k++) {
          y_data[k] = fabs(x_data[k]);
        }
        cfv = b_combineVectorElements(y);
        fun_evals++;
        if (cfv < fxr) {
          v[lastCol] = xe;
          fv[idx_idx_1 - 1] = cfv;
        } else {
          v[lastCol] = xr;
          fv[idx_idx_1 - 1] = fxr;
        }
        guard1 = true;
      } else if (fxr < cfv_tmp_tmp) {
        v[lastCol] = xr;
        fv[idx_idx_1 - 1] = fxr;
        guard1 = true;
      } else if (fxr < b_cfv_tmp_tmp) {
        x = 1.5 * v[firstCol] - 0.5 * v[lastCol];
        k = b_x->size[0] * b_x->size[1];
        b_x->size[0] = 1;
        b_x->size[1] = funfcn_workspace_Points1->size[1];
        emxEnsureCapacity_real_T(b_x, k);
        x_data = b_x->data;
        nx = funfcn_workspace_Points1->size[1];
        for (k = 0; k < nx; k++) {
          x_data[k] =
              ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
                funfcn_workspace_bbb *
                    funfcn_workspace_Points1_data[3 * k + 1]) +
               funfcn_workspace_ccc *
                   funfcn_workspace_Points1_data[3 * k + 2]) +
              x;
        }
        nx = b_x->size[1];
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = b_x->size[1];
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        for (k = 0; k < nx; k++) {
          y_data[k] = fabs(x_data[k]);
        }
        xe = b_combineVectorElements(y);
        fun_evals++;
        if (xe <= fxr) {
          v[lastCol] = x;
          fv[idx_idx_1 - 1] = xe;
          guard1 = true;
        } else {
          guard2 = true;
        }
      } else {
        x = 0.5 * v[firstCol] + 0.5 * v[lastCol];
        k = b_x->size[0] * b_x->size[1];
        b_x->size[0] = 1;
        b_x->size[1] = funfcn_workspace_Points1->size[1];
        emxEnsureCapacity_real_T(b_x, k);
        x_data = b_x->data;
        nx = funfcn_workspace_Points1->size[1];
        for (k = 0; k < nx; k++) {
          x_data[k] =
              ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
                funfcn_workspace_bbb *
                    funfcn_workspace_Points1_data[3 * k + 1]) +
               funfcn_workspace_ccc *
                   funfcn_workspace_Points1_data[3 * k + 2]) +
              x;
        }
        nx = b_x->size[1];
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = b_x->size[1];
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        for (k = 0; k < nx; k++) {
          y_data[k] = fabs(x_data[k]);
        }
        xe = b_combineVectorElements(y);
        fun_evals++;
        if (xe < b_cfv_tmp_tmp) {
          v[lastCol] = x;
          fv[idx_idx_1 - 1] = xe;
          guard1 = true;
        } else {
          guard2 = true;
        }
      }
      if (guard2) {
        v[idx_idx_1 - 1] = v[firstCol] + 0.5 * (v[idx_idx_1 - 1] - v[firstCol]);
        k = b_x->size[0] * b_x->size[1];
        b_x->size[0] = 1;
        b_x->size[1] = funfcn_workspace_Points1->size[1];
        emxEnsureCapacity_real_T(b_x, k);
        x_data = b_x->data;
        nx = funfcn_workspace_Points1->size[1];
        for (k = 0; k < nx; k++) {
          x_data[k] =
              ((funfcn_workspace_aaa * funfcn_workspace_Points1_data[3 * k] +
                funfcn_workspace_bbb *
                    funfcn_workspace_Points1_data[3 * k + 1]) +
               funfcn_workspace_ccc *
                   funfcn_workspace_Points1_data[3 * k + 2]) +
              v[idx_idx_1 - 1];
        }
        nx = b_x->size[1];
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = b_x->size[1];
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        for (k = 0; k < nx; k++) {
          y_data[k] = fabs(x_data[k]);
        }
        fv[idx_idx_1 - 1] = b_combineVectorElements(y);
        fun_evals++;
        idxb[0] = idx_idx_0;
        xe = fv[idx_idx_1 - 1];
        idxb[1] = idx_idx_1;
        if ((fv[idx_idx_0 - 1] <= xe) || rtIsNaN(xe)) {
          idx_idx_0 = 1;
          idx_idx_1 = 2;
        } else {
          idx_idx_0 = 2;
          idx_idx_1 = 1;
        }
        idx_idx_0 = idxb[idx_idx_0 - 1];
        idx_idx_1 = idxb[idx_idx_1 - 1];
      }
      if (guard1 && (fv[idx_idx_1 - 1] < fv[idx_idx_0 - 1])) {
        nx = idx_idx_1;
        idx_idx_1 = idx_idx_0;
        idx_idx_0 = (signed char)nx;
      }
      itercount++;
      lastCol = idx_idx_1 - 1;
      firstCol = idx_idx_0 - 1;
    } else {
      exitg1 = true;
    }
  }
  emxFree_real_T(&b_x);
  emxFree_real_T(&y);
  return v[idx_idx_0 - 1];
}

/*
 * File trailer for fminsearch.c
 *
 * [EOF]
 */
