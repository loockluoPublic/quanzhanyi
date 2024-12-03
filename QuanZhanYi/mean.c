/*
 * File: mean.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 23:50:47
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
  const double *x_data;
  double bsum;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  int xblockoffset;
  int xi;
  int xpageoffset;
  x_data = x->data;
  if (x->size[0] == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
    y[2] = 0.0;
  } else {
    if (x->size[0] <= 1024) {
      firstBlockLength = x->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)x->size[0] >> 10);
      lastBlockLength = x->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (xi = 0; xi < 3; xi++) {
      xpageoffset = xi * x->size[0];
      y[xi] = x_data[xpageoffset];
      for (k = 2; k <= firstBlockLength; k++) {
        y[xi] += x_data[(xpageoffset + k) - 1];
      }
      for (ib = 2; ib <= nblocks; ib++) {
        xblockoffset = xpageoffset + ((ib - 1) << 10);
        bsum = x_data[xblockoffset];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (k = 2; k <= hi; k++) {
          bsum += x_data[(xblockoffset + k) - 1];
        }
        y[xi] += bsum;
      }
    }
  }
  y[0] /= (double)x->size[0];
  y[1] /= (double)x->size[0];
  y[2] /= (double)x->size[0];
}

/*
 * Arguments    : const double x[24]
 *                double y[3]
 * Return Type  : void
 */
void c_mean(const double x[24], double y[3])
{
  double d;
  int k;
  int xi;
  int xpageoffset;
  for (xi = 0; xi < 3; xi++) {
    xpageoffset = xi << 3;
    d = x[xpageoffset];
    for (k = 0; k < 7; k++) {
      d += x[(xpageoffset + k) + 1];
    }
    y[xi] = d / 8.0;
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double mean(const emxArray_real_T *x)
{
  const double *x_data;
  double bsum;
  double y;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  x_data = x->data;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    if (x->size[1] <= 1024) {
      firstBlockLength = x->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)x->size[1] >> 10);
      lastBlockLength = x->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      y += x_data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) << 10;
      bsum = x_data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += x_data[(firstBlockLength + k) - 1];
      }
      y += bsum;
    }
  }
  y /= (double)x->size[1];
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
