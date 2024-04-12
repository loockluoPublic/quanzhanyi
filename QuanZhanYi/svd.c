/*
 * File: svd.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

/* Include Files */
#include "svd.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 *                emxArray_real_T *S
 *                double V[16]
 * Return Type  : void
 */
void svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
         double V[16])
{
  emxArray_real_T *U1;
  emxArray_real_T *r;
  double V1[16];
  double s_data[4];
  int i;
  int k;
  int nx;
  boolean_T p;
  nx = A->size[0] << 2;
  p = true;
  for (k = 0; k < nx; k++) {
    if ((!p) || (rtIsInf(A->data[k]) || rtIsNaN(A->data[k]))) {
      p = false;
    }
  }
  if (p) {
    b_svd(A, U, s_data, &k, V);
  } else {
    emxInit_real_T(&r, 2);
    i = r->size[0] * r->size[1];
    r->size[0] = A->size[0];
    r->size[1] = 4;
    emxEnsureCapacity_real_T(r, i);
    nx = A->size[0] << 2;
    for (i = 0; i < nx; i++) {
      r->data[i] = 0.0;
    }
    emxInit_real_T(&U1, 2);
    b_svd(r, U1, s_data, &k, V1);
    i = U->size[0] * U->size[1];
    U->size[0] = U1->size[0];
    U->size[1] = U1->size[1];
    emxEnsureCapacity_real_T(U, i);
    nx = U1->size[0] * U1->size[1];
    emxFree_real_T(&r);
    emxFree_real_T(&U1);
    for (i = 0; i < nx; i++) {
      U->data[i] = rtNaN;
    }
    for (i = 0; i < k; i++) {
      s_data[i] = rtNaN;
    }
    for (i = 0; i < 16; i++) {
      V[i] = rtNaN;
    }
  }
  i = S->size[0] * S->size[1];
  S->size[0] = U->size[1];
  S->size[1] = 4;
  emxEnsureCapacity_real_T(S, i);
  nx = U->size[1] << 2;
  for (i = 0; i < nx; i++) {
    S->data[i] = 0.0;
  }
  i = k - 1;
  for (k = 0; k <= i; k++) {
    S->data[k + S->size[0] * k] = s_data[k];
  }
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
