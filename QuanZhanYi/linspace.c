/*
 * File: linspace.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 14:10:17
 */

/* Include Files */
#include "linspace.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double n
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_linspace(double n, emxArray_real_T *y)
{
  double *y_data;
  int k;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    double delta1;
    int i;
    delta1 = floor(n);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    if ((int)delta1 >= 1) {
      y_data[(int)delta1 - 1] = 5.2359877559829888;
      if (y->size[1] >= 2) {
        y_data[0] = 1.0471975511965976;
        if (y->size[1] >= 3) {
          delta1 = 4.1887902047863914 / ((double)y->size[1] - 1.0);
          i = y->size[1];
          for (k = 0; k <= i - 3; k++) {
            y_data[k + 1] = ((double)k + 1.0) * delta1 + 1.0471975511965976;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : double n
 *                emxArray_real_T *y
 * Return Type  : void
 */
void linspace(double n, emxArray_real_T *y)
{
  double *y_data;
  int k;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    double delta1;
    int y_tmp_tmp;
    delta1 = floor(n);
    y_tmp_tmp = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(y, y_tmp_tmp);
    y_data = y->data;
    if ((int)delta1 >= 1) {
      y_tmp_tmp = (int)delta1 - 1;
      y_data[(int)floor(n) - 1] = 2.0943951023931953;
      if (y->size[1] >= 2) {
        y_data[0] = -2.0943951023931953;
        if (y->size[1] >= 3) {
          if ((int)delta1 > 2) {
            double d2scaled;
            d2scaled = 2.0943951023931953 / ((double)(int)delta1 - 1.0);
            for (k = 2; k <= y_tmp_tmp; k++) {
              y_data[k - 1] = (double)(((k << 1) - (int)delta1) - 1) * d2scaled;
            }
            if (((int)delta1 & 1) == 1) {
              y_data[(int)delta1 >> 1] = 0.0;
            }
          } else {
            delta1 = 4.1887902047863905 / ((double)y->size[1] - 1.0);
            y_tmp_tmp = y->size[1];
            for (k = 0; k <= y_tmp_tmp - 3; k++) {
              y_data[k + 1] = ((double)k + 1.0) * delta1 + -2.0943951023931953;
            }
          }
        }
      }
    }
  }
}

/*
 * File trailer for linspace.c
 *
 * [EOF]
 */
