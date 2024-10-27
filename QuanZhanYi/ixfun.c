/*
 * File: ixfun.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:30:42
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
  int csz_idx_0;
  int u1;
  boolean_T b1;
  boolean_T b_b;
  b_data = b->data;
  a_data = a->data;
  csz_idx_0 = a->size[0];
  u1 = b->size[0];
  if (csz_idx_0 <= u1) {
    u1 = csz_idx_0;
  }
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else {
    csz_idx_0 = u1;
  }
  u1 = c->size[0];
  c->size[0] = csz_idx_0;
  emxEnsureCapacity_real_T(c, u1);
  c_data = c->data;
  if (csz_idx_0 != 0) {
    b_b = (a->size[0] != 1);
    b1 = (b->size[0] != 1);
    u1 = csz_idx_0 - 1;
    for (csz_idx_0 = 0; csz_idx_0 <= u1; csz_idx_0++) {
      c_data[csz_idx_0] =
          rt_hypotd_snf(a_data[b_b * csz_idx_0], b_data[b1 * csz_idx_0]);
    }
  }
}

/*
 * File trailer for ixfun.c
 *
 * [EOF]
 */
