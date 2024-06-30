/*
 * File: ixfun.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 12:40:56
 */

/* Include Files */
#include "ixfun.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *a
 *                const emxArray_real_T *b
 *                emxArray_real_T *c
 * Return Type  : void
 */
void expand_hypot(const emxArray_real_T *a, const emxArray_real_T *b,
                  emxArray_real_T *c)
{
  const double *a_data;
  const double *b_data;
  double *c_data;
  int acoef;
  int bcoef;
  int csz_idx_0;
  int i;
  b_data = b->data;
  a_data = a->data;
  acoef = a->size[0];
  bcoef = b->size[0];
  if (acoef <= bcoef) {
    bcoef = acoef;
  }
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else {
    csz_idx_0 = bcoef;
  }
  i = c->size[0];
  acoef = a->size[0];
  bcoef = b->size[0];
  if (acoef <= bcoef) {
    bcoef = acoef;
  }
  if (b->size[0] == 1) {
    c->size[0] = a->size[0];
  } else if (a->size[0] == 1) {
    c->size[0] = b->size[0];
  } else {
    c->size[0] = bcoef;
  }
  emxEnsureCapacity_real_T(c, i);
  c_data = c->data;
  if (csz_idx_0 != 0) {
    acoef = (a->size[0] != 1);
    bcoef = (b->size[0] != 1);
    i = csz_idx_0 - 1;
    for (csz_idx_0 = 0; csz_idx_0 <= i; csz_idx_0++) {
      c_data[csz_idx_0] =
          rt_hypotd_snf(a_data[acoef * csz_idx_0], b_data[bcoef * csz_idx_0]);
    }
  }
}

/*
 * File trailer for ixfun.c
 *
 * [EOF]
 */
