/*
 * File: linspace.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

/* Include Files */
#include "linspace.h"
#include "Generate_multi_layered_measurement_points_emxutil.h"
#include "Generate_multi_layered_measurement_points_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double d1
 *                double d2
 *                double n
 *                emxArray_real_T *y
 * Return Type  : void
 */
void linspace(double d1, double d2, double n, emxArray_real_T *y)
{
  double d2scaled;
  double delta1;
  int k;
  int y_tmp_tmp;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    delta1 = floor(n);
    y_tmp_tmp = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(y, y_tmp_tmp);
    if ((int)delta1 >= 1) {
      y_tmp_tmp = (int)delta1 - 1;
      y->data[(int)floor(n) - 1] = d2;
      if (y->size[1] >= 2) {
        y->data[0] = d1;
        if (y->size[1] >= 3) {
          if ((d1 == -d2) && ((int)delta1 > 2)) {
            d2scaled = d2 / ((double)(int)delta1 - 1.0);
            for (k = 2; k <= y_tmp_tmp; k++) {
              y->data[k - 1] =
                  (double)(((k << 1) - (int)delta1) - 1) * d2scaled;
            }
            if (((int)delta1 & 1) == 1) {
              y->data[(int)delta1 >> 1] = 0.0;
            }
          } else {
            delta1 = (d2 - d1) / ((double)y->size[1] - 1.0);
            y_tmp_tmp = y->size[1];
            for (k = 0; k <= y_tmp_tmp - 3; k++) {
              y->data[k + 1] = d1 + ((double)k + 1.0) * delta1;
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
