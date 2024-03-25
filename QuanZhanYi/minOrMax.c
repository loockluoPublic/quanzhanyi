/*
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2024 00:13:40
 */

/* Include Files */
#include "minOrMax.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                double *ex
 *                int *idx
 * Return Type  : void
 */
void b_minimum(const emxArray_real_T *x, double *ex, int *idx)
{
  double d;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  last = x->size[1];
  if (x->size[1] <= 2) {
    if (x->size[1] == 1) {
      *ex = x->data[0];
      *idx = 1;
    } else if ((x->data[0] > x->data[x->size[1] - 1]) ||
               (rtIsNaN(x->data[0]) && (!rtIsNaN(x->data[x->size[1] - 1])))) {
      *ex = x->data[x->size[1] - 1];
      *idx = x->size[1];
    } else {
      *ex = x->data[0];
      *idx = 1;
    }
  } else {
    if (!rtIsNaN(x->data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x->data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x->data[0];
      *idx = 1;
    } else {
      *ex = x->data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        d = x->data[k - 1];
        if (*ex > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double maximum(const emxArray_real_T *x)
{
  double d;
  double ex;
  int idx;
  int k;
  int last;
  boolean_T exitg1;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x->data[0];
    } else if ((x->data[0] < x->data[x->size[0] - 1]) ||
               (rtIsNaN(x->data[0]) && (!rtIsNaN(x->data[x->size[0] - 1])))) {
      ex = x->data[x->size[0] - 1];
    } else {
      ex = x->data[0];
    }
  } else {
    if (!rtIsNaN(x->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x->data[0];
    } else {
      ex = x->data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        d = x->data[k - 1];
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
double minimum(const emxArray_real_T *x)
{
  double d;
  double ex;
  int idx;
  int k;
  int last;
  boolean_T exitg1;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x->data[0];
    } else if ((x->data[0] > x->data[x->size[0] - 1]) ||
               (rtIsNaN(x->data[0]) && (!rtIsNaN(x->data[x->size[0] - 1])))) {
      ex = x->data[x->size[0] - 1];
    } else {
      ex = x->data[0];
    }
  } else {
    if (!rtIsNaN(x->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x->data[0];
    } else {
      ex = x->data[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        d = x->data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
