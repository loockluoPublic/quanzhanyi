/*
 * File: xnrm2.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-May-2024 23:50:53
 */

/* Include Files */
#include "xnrm2.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
double b_xnrm2(int n, const emxArray_real_T *x, int ix0)
{
  const double *x_data;
  double y;
  int k;
  x_data = x->data;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x_data[ix0 - 1]);
    } else {
      double scale;
      int kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        double absxk;
        absxk = fabs(x_data[k - 1]);
        if (absxk > scale) {
          double t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          double t;
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
 * Arguments    : int n
 *                const double x[4]
 *                int ix0
 * Return Type  : double
 */
double c_xnrm2(int n, const double x[4], int ix0)
{
  double scale;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    double absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      double t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      double t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[3]
 * Return Type  : double
 */
double d_xnrm2(const double x[3])
{
  double scale;
  double y;
  int k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 2; k < 4; k++) {
    double absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      double t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      double t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[8]
 *                int ix0
 * Return Type  : double
 */
double e_xnrm2(const double x[8], int ix0)
{
  double scale;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = ix0 + 1;
  for (k = ix0; k <= kend; k++) {
    double absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      double t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      double t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[6]
 *                int ix0
 * Return Type  : double
 */
double f_xnrm2(const double x[6], int ix0)
{
  return fabs(x[ix0 - 1]);
}

/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 * Return Type  : double
 */
double xnrm2(int n, const double x[9], int ix0)
{
  double scale;
  double y;
  int k;
  int kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    double absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      double t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      double t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * sqrt(y);
}

/*
 * File trailer for xnrm2.c
 *
 * [EOF]
 */
