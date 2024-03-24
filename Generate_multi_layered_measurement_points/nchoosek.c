/*
 * File: nchoosek.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

/* Include Files */
#include "nchoosek.h"
#include "Generate_multi_layered_measurement_points_emxutil.h"
#include "Generate_multi_layered_measurement_points_types.h"
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
  double nmk;
  double y;
  int i;
  int j;
  if (!rtIsNaN(n)) {
    if (3.0 > n / 2.0) {
      k = n - 3.0;
    }
    if (k > 1000.0) {
      y = rtInf;
    } else {
      y = 1.0;
      nmk = n - k;
      i = (int)k;
      for (j = 0; j < i; j++) {
        y *= (((double)j + 1.0) + nmk) / ((double)j + 1.0);
      }
      y = rt_roundd_snf(y);
    }
  } else {
    y = rtNaN;
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
 *                emxArray_real_T *y
 * Return Type  : void
 */
void nchoosek(const emxArray_real_T *x, emxArray_real_T *y)
{
  int comb[3];
  int a;
  int combj;
  int icomb;
  int nmkpi;
  int nrows;
  int row;
  if (x->size[1] == 1) {
    if (!(3.0 > x->data[0])) {
      icomb = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, icomb);
      y->data[0] = nCk(x->data[0], 3.0);
    }
  } else if (3 > x->size[1]) {
    y->size[0] = 0;
    y->size[1] = 3;
  } else {
    nrows = (int)floor(nCk(x->size[1], 3.0));
    icomb = y->size[0] * y->size[1];
    y->size[0] = nrows;
    y->size[1] = 3;
    emxEnsureCapacity_real_T(y, icomb);
    comb[0] = 1;
    comb[1] = 2;
    comb[2] = 3;
    icomb = 2;
    nmkpi = x->size[1];
    for (row = 0; row < nrows; row++) {
      y->data[row] = x->data[comb[0] - 1];
      y->data[row + y->size[0]] = x->data[comb[1] - 1];
      y->data[row + y->size[0] * 2] = x->data[comb[2] - 1];
      if (icomb + 1 > 0) {
        a = comb[icomb];
        combj = comb[icomb] + 1;
        comb[icomb]++;
        if (a + 1 < nmkpi) {
          icomb += 2;
          for (nmkpi = icomb; nmkpi < 4; nmkpi++) {
            combj++;
            comb[nmkpi - 1] = combj;
          }
          icomb = 2;
          nmkpi = x->size[1];
        } else {
          icomb--;
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
