/*
 * File: combineVectorElements.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "combineVectorElements.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double combineVectorElements(const emxArray_real_T *x)
{
  double bsum;
  double y;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    if (x->size[0] <= 1024) {
      firstBlockLength = x->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x->size[0] / 1024;
      lastBlockLength = x->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x->data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      y += x->data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) << 10;
      bsum = x->data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += x->data[(firstBlockLength + k) - 1];
      }
      y += bsum;
    }
  }
  return y;
}

/*
 * File trailer for combineVectorElements.c
 *
 * [EOF]
 */
