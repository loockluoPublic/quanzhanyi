/*
 * File: mean.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 22:01:39
 */

/* Include Files */
#include "mean.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                double y[3]
 * Return Type  : void
 */
void b_mean(const emxArray_real_T *x, double y[3])
{
  double bsum_idx_0;
  double bsum_idx_1;
  double bsum_idx_2;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  int xoffset;
  if (x->size[1] == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
    y[2] = 0.0;
  } else {
    if (x->size[1] <= 1024) {
      firstBlockLength = x->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x->size[1] / 1024;
      lastBlockLength = x->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y[0] = x->data[0];
    y[1] = x->data[1];
    y[2] = x->data[2];
    for (k = 2; k <= firstBlockLength; k++) {
      xoffset = (k - 1) * 3;
      y[0] += x->data[xoffset];
      y[1] += x->data[xoffset + 1];
      y[2] += x->data[xoffset + 2];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) * 3072;
      bsum_idx_0 = x->data[firstBlockLength];
      bsum_idx_1 = x->data[firstBlockLength + 1];
      bsum_idx_2 = x->data[firstBlockLength + 2];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        xoffset = firstBlockLength + (k - 1) * 3;
        bsum_idx_0 += x->data[xoffset];
        bsum_idx_1 += x->data[xoffset + 1];
        bsum_idx_2 += x->data[xoffset + 2];
      }
      y[0] += bsum_idx_0;
      y[1] += bsum_idx_1;
      y[2] += bsum_idx_2;
    }
  }
  y[0] /= (double)x->size[1];
  y[1] /= (double)x->size[1];
  y[2] /= (double)x->size[1];
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double mean(const emxArray_real_T *x)
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
  y /= (double)x->size[0];
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
