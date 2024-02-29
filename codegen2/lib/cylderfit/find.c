/*
 * File: find.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "find.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[45]
 *                int i_data[]
 *                int *i_size
 * Return Type  : void
 */
void eml_find(const boolean_T x[45], int i_data[], int *i_size)
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 45)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 45) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (1 > idx) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
