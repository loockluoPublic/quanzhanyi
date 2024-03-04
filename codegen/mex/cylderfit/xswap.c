/*
 * xswap.c
 *
 * Code generation for function 'xswap'
 *
 */

/* Include files */
#include "xswap.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void xswap(real_T x[49], int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T i;
  int32_T k;
  int32_T temp_tmp;
  for (k = 0; k < 7; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    i = (iy0 + k) - 1;
    x[temp_tmp] = x[i];
    x[i] = temp;
  }
}

/* End of code generation (xswap.c) */
