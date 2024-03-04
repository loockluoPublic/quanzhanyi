/*
 * File: xnrm2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

/* Include Files */
#include "xnrm2.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                int ix0
 * Return Type  : double
 */
double b_xnrm2(const double x_data[], int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = ix0 + 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x_data[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 * Return Type  : double
 */
double c_xnrm2(int n, const double x[9], int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[3]
 *                int ix0
 * Return Type  : double
 */
double d_xnrm2(const double x[3], int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = ix0 + 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : int n
 *                const double x[49]
 *                int ix0
 * Return Type  : double
 */
double e_xnrm2(int n, const double x[49], int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : int n
 *                const double x[7]
 *                int ix0
 * Return Type  : double
 */
double f_xnrm2(int n, const double x[7], int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
double xnrm2(int n, const emxArray_real_T *x, int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x->data[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x->data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * sqrt(y);
    }
  }
  return y;
}

/*
 * File trailer for xnrm2.c
 *
 * [EOF]
 */
