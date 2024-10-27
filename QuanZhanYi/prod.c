/*
 * File: prod.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 09:05:44
 */

/* Include Files */
#include "prod.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void prod(const emxArray_real_T *x, emxArray_real_T *y)
{
  const double *x_data;
  double *y_data;
  int j;
  int k;
  int vlen;
  int vstride;
  int xoffset;
  x_data = x->data;
  vlen = x->size[1];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    j = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(y, j);
    y_data = y->data;
    xoffset = x->size[0];
    for (j = 0; j < xoffset; j++) {
      y_data[j] = 1.0;
    }
  } else {
    vstride = x->size[0];
    j = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(y, j);
    y_data = y->data;
    for (j = 0; j < vstride; j++) {
      y_data[j] = x_data[j];
    }
    for (k = 2; k <= vlen; k++) {
      xoffset = (k - 1) * vstride;
      for (j = 0; j < vstride; j++) {
        y_data[j] *= x_data[xoffset + j];
      }
    }
  }
}

/*
 * File trailer for prod.c
 *
 * [EOF]
 */
