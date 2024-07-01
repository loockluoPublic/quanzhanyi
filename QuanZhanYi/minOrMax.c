/*
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 01-Jul-2024 15:27:46
 */

/* Include Files */
#include "minOrMax.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double b_maximum(const emxArray_real_T *x)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else if ((x_data[0] < x_data[x->size[0] - 1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[x->size[0] - 1])))) {
      ex = x_data[x->size[0] - 1];
    } else {
      ex = x_data[0];
    }
  } else {
    int idx;
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double b_minimum(const emxArray_real_T *x)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
    } else if ((x_data[0] > x_data[x->size[0] - 1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[x->size[0] - 1])))) {
      ex = x_data[x->size[0] - 1];
    } else {
      ex = x_data[0];
    }
  } else {
    int idx;
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double *ex
 *                int *idx
 * Return Type  : void
 */
void maximum(const emxArray_real_T *x, double *ex, int *idx)
{
  const double *x_data;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      *ex = x_data[0];
      *idx = 1;
    } else if ((x_data[0] < x_data[x->size[0] - 1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[x->size[0] - 1])))) {
      *ex = x_data[x->size[0] - 1];
      *idx = x->size[0];
    } else {
      *ex = x_data[0];
      *idx = 1;
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x_data[0];
      *idx = 1;
    } else {
      int i;
      *ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (*ex < d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double *ex
 *                int *idx
 * Return Type  : void
 */
void minimum(const emxArray_real_T *x, double *ex, int *idx)
{
  const double *x_data;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      *ex = x_data[0];
      *idx = 1;
    } else if ((x_data[0] > x_data[x->size[0] - 1]) ||
               (rtIsNaN(x_data[0]) && (!rtIsNaN(x_data[x->size[0] - 1])))) {
      *ex = x_data[x->size[0] - 1];
      *idx = x->size[0];
    } else {
      *ex = x_data[0];
      *idx = 1;
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x_data[0];
      *idx = 1;
    } else {
      int i;
      *ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        double d;
        d = x_data[k - 1];
        if (*ex > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
