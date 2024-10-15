/*
 * File: nchoosek.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 16-Oct-2024 02:36:46
 */

/* Include Files */
#include "nchoosek.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double nCk(double n, double k);

static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : double n
 *                double k
 * Return Type  : double
 */
static double nCk(double n, double k)
{
  double maxRelErr;
  double y;
  unsigned long long b_i;
  unsigned long long b_k;
  unsigned long long b_n;
  unsigned long long u;
  unsigned long long u1;
  unsigned long long yint;
  int i;
  int j;
  boolean_T exitg1;
  if (rtIsInf(n) || rtIsNaN(n) || (rtIsInf(k) || rtIsNaN(k))) {
    y = rtNaN;
  } else if (k > 1000.0) {
    y = rtInf;
  } else {
    maxRelErr = 0.0;
    y = n;
    i = (int)(k - 1.0);
    for (j = 0; j < i; j++) {
      y *= ((n - ((double)j + 2.0)) + 1.0) / ((double)j + 2.0);
      if (!(y < 1.125899906842624E+15)) {
        maxRelErr += 4.4408920985006262E-16;
      }
      y = rt_roundd_snf(y);
    }
    if ((maxRelErr != 0.0) && (y <= 3.6893488147419103E+19)) {
      maxRelErr = rt_roundd_snf(n);
      if (maxRelErr < 1.8446744073709552E+19) {
        if (maxRelErr >= 0.0) {
          b_n = (unsigned long long)maxRelErr;
        } else {
          b_n = 0ULL;
        }
      } else if (maxRelErr >= 1.8446744073709552E+19) {
        b_n = MAX_uint64_T;
      } else {
        b_n = 0ULL;
      }
      maxRelErr = rt_roundd_snf(k);
      if (maxRelErr < 1.8446744073709552E+19) {
        if (maxRelErr >= 0.0) {
          b_k = (unsigned long long)maxRelErr;
        } else {
          b_k = 0ULL;
        }
      } else {
        b_k = 0ULL;
      }
      yint = 1ULL;
      b_i = 1ULL;
      exitg1 = false;
      while ((!exitg1) && (b_i <= b_k)) {
        if (b_i == 0ULL) {
          u = MAX_uint64_T;
        } else {
          u = yint / b_i;
        }
        if (b_n == 0ULL) {
          u1 = MAX_uint64_T;
        } else {
          u1 = MAX_uint64_T / b_n;
        }
        if (u >= u1) {
          yint = MAX_uint64_T;
          exitg1 = true;
        } else {
          if (b_i == 0ULL) {
            u1 = MAX_uint64_T;
          } else {
            if (b_i == 0ULL) {
              u1 = MAX_uint64_T;
            } else {
              u1 = yint / b_i;
            }
            u1 = (yint - u1 * b_i) * b_n / b_i;
          }
          yint = u * b_n + u1;
          b_n--;
          b_i++;
        }
      }
      y = (double)yint;
    }
  }
  return y;
}

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double k
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_nchoosek(const emxArray_real_T *x, double k, emxArray_real_T *y)
{
  emxArray_int32_T *comb;
  const double *x_data;
  double r;
  double *y_data;
  int combj;
  int kint;
  int n;
  int nmkpi;
  int nrows;
  int row;
  int yk;
  int *comb_data;
  x_data = x->data;
  if (x->size[0] == 1) {
    r = k;
    if (k > x_data[0] - k) {
      r = x_data[0] - k;
    }
    if (r == 0.0) {
      yk = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, yk);
      y_data = y->data;
      y_data[0] = 1.0;
    } else if (r == 1.0) {
      yk = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, yk);
      y_data = y->data;
      y_data[0] = x_data[0];
    } else {
      yk = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, yk);
      y_data = y->data;
      y_data[0] = nCk(x_data[0], r);
    }
  } else if (k > x->size[0]) {
    y->size[0] = 0;
    y->size[1] = (int)k;
  } else {
    kint = (int)floor(k);
    r = k;
    if (k > (double)x->size[0] - k) {
      r = (double)x->size[0] - k;
    }
    if (r == 0.0) {
      r = 1.0;
    } else if (r == 1.0) {
      r = x->size[0];
    } else {
      r = nCk(x->size[0], r);
    }
    nrows = (int)floor(r);
    yk = y->size[0] * y->size[1];
    y->size[0] = nrows;
    y->size[1] = kint;
    emxEnsureCapacity_real_T(y, yk);
    y_data = y->data;
    if (kint < 1) {
      n = 0;
    } else {
      n = kint;
    }
    emxInit_int32_T(&comb);
    yk = comb->size[0] * comb->size[1];
    comb->size[0] = 1;
    comb->size[1] = n;
    emxEnsureCapacity_int32_T(comb, yk);
    comb_data = comb->data;
    if (n > 0) {
      comb_data[0] = 1;
      yk = 1;
      for (nmkpi = 2; nmkpi <= n; nmkpi++) {
        yk++;
        comb_data[nmkpi - 1] = yk;
      }
    }
    n = kint - 1;
    nmkpi = x->size[0];
    for (row = 0; row < nrows; row++) {
      for (yk = 0; yk < kint; yk++) {
        y_data[row + y->size[0] * yk] = x_data[comb_data[yk] - 1];
      }
      if (n + 1 > 0) {
        yk = comb_data[n];
        combj = comb_data[n] + 1;
        comb_data[n]++;
        if (yk + 1 < nmkpi) {
          yk = n + 2;
          for (n = yk; n <= kint; n++) {
            combj++;
            comb_data[n - 1] = combj;
          }
          n = kint - 1;
          nmkpi = x->size[0];
        } else {
          n--;
          nmkpi--;
        }
      }
    }
    emxFree_int32_T(&comb);
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void nchoosek(const emxArray_real_T *x, emxArray_real_T *y)
{
  const double *x_data;
  double r;
  double *y_data;
  int comb[3];
  int a;
  int b_r;
  int combj;
  int nmkpi;
  int nrows;
  int row;
  x_data = x->data;
  if (x->size[1] == 1) {
    r = 3.0;
    if (x_data[0] - 3.0 < 3.0) {
      r = x_data[0] - 3.0;
    }
    if (r == 0.0) {
      b_r = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, b_r);
      y_data = y->data;
      y_data[0] = 1.0;
    } else if (r == 1.0) {
      b_r = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, b_r);
      y_data = y->data;
      y_data[0] = x_data[0];
    } else {
      b_r = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, b_r);
      y_data = y->data;
      y_data[0] = nCk(x_data[0], r);
    }
  } else if (x->size[1] < 3) {
    y->size[0] = 0;
    y->size[1] = 3;
  } else {
    b_r = 3;
    if (x->size[1] - 3 < 3) {
      b_r = x->size[1] - 3;
    }
    if (b_r == 0) {
      r = 1.0;
    } else if (b_r == 1) {
      r = x->size[1];
    } else {
      r = nCk(x->size[1], b_r);
    }
    nrows = (int)floor(r);
    b_r = y->size[0] * y->size[1];
    y->size[0] = nrows;
    y->size[1] = 3;
    emxEnsureCapacity_real_T(y, b_r);
    y_data = y->data;
    comb[0] = 1;
    comb[1] = 2;
    comb[2] = 3;
    b_r = 2;
    nmkpi = x->size[1];
    for (row = 0; row < nrows; row++) {
      y_data[row] = x_data[comb[0] - 1];
      y_data[row + y->size[0]] = x_data[comb[1] - 1];
      y_data[row + y->size[0] * 2] = x_data[comb[2] - 1];
      if (b_r + 1 > 0) {
        a = comb[b_r];
        combj = comb[b_r] + 1;
        comb[b_r]++;
        if (a + 1 < nmkpi) {
          b_r += 2;
          for (nmkpi = b_r; nmkpi < 4; nmkpi++) {
            combj++;
            comb[nmkpi - 1] = combj;
          }
          b_r = 2;
          nmkpi = x->size[1];
        } else {
          b_r--;
          nmkpi--;
        }
      }
    }
  }
}

/*
 * File trailer for nchoosek.c
 *
 * [EOF]
 */
