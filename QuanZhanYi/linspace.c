/*
 * File: linspace.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
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
void linspace(double n, emxArray_real_T *y)
{
  double delta1;
  int i;
  int k;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    delta1 = floor(n);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(y, i);
    if ((int)delta1 >= 1) {
      y->data[(int)delta1 - 1] = 6.2831853071795862;
      if (y->size[1] >= 2) {
        y->data[0] = 0.0;
        if (y->size[1] >= 3) {
          delta1 = 6.2831853071795862 / ((double)y->size[1] - 1.0);
          i = y->size[1];
          for (k = 0; k <= i - 3; k++) {
            y->data[k + 1] = ((double)k + 1.0) * delta1;
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
