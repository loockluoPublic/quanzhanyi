/*
 * vAllOrAny.c
 *
 * Code generation for function 'vAllOrAny'
 *
 */

/* Include files */
#include "vAllOrAny.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T flatVectorAllOrAny(const real_T x_data[], const int32_T x_size[2])
{
  int32_T k;
  int32_T nx;
  boolean_T p;
  nx = x_size[0] * x_size[1];
  p = true;
  for (k = 0; k < nx; k++) {
    if ((!p) ||
        (muDoubleScalarIsInf(x_data[k]) || muDoubleScalarIsNaN(x_data[k]))) {
      p = false;
    }
  }
  return p;
}

/* End of code generation (vAllOrAny.c) */
