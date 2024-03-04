/*
 * xrot.c
 *
 * Code generation for function 'xrot'
 *
 */

/* Include files */
#include "xrot.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void xrot(real_T x[49], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  real_T b_temp_tmp;
  real_T d_temp_tmp;
  int32_T c_temp_tmp;
  int32_T k;
  int32_T temp_tmp;
  for (k = 0; k < 7; k++) {
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = x[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = x[c_temp_tmp];
    x[temp_tmp] = c * b_temp_tmp - s * d_temp_tmp;
    x[c_temp_tmp] = c * d_temp_tmp + s * b_temp_tmp;
  }
}

/* End of code generation (xrot.c) */
