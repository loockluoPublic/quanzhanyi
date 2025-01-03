/*
 * File: svd1.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

/* Include Files */
#include "svd1.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 *                emxArray_real_T *S
 *                double V[9]
 * Return Type  : void
 */
void c_svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
           double V[9])
{
  emxArray_real_T *U1;
  emxArray_real_T *r;
  double V1[9];
  double s_data[3];
  const double *A_data;
  double *U_data;
  int i;
  int k;
  int nx;
  boolean_T p;
  A_data = A->data;
  nx = A->size[0] * 3;
  p = true;
  for (k = 0; k < nx; k++) {
    if ((!p) || (rtIsInf(A_data[k]) || rtIsNaN(A_data[k]))) {
      p = false;
    }
  }
  if (p) {
    d_svd(A, U, s_data, &k, V);
  } else {
    emxInit_real_T(&r, 2);
    i = r->size[0] * r->size[1];
    r->size[0] = A->size[0];
    r->size[1] = 3;
    emxEnsureCapacity_real_T(r, i);
    U_data = r->data;
    nx = A->size[0] * 3;
    for (i = 0; i < nx; i++) {
      U_data[i] = 0.0;
    }
    emxInit_real_T(&U1, 2);
    d_svd(r, U1, s_data, &k, V1);
    i = U->size[0] * U->size[1];
    U->size[0] = U1->size[0];
    U->size[1] = U1->size[1];
    emxEnsureCapacity_real_T(U, i);
    U_data = U->data;
    nx = U1->size[0] * U1->size[1];
    emxFree_real_T(&r);
    emxFree_real_T(&U1);
    for (i = 0; i < nx; i++) {
      U_data[i] = rtNaN;
    }
    for (i = 0; i < k; i++) {
      s_data[i] = rtNaN;
    }
    for (i = 0; i < 9; i++) {
      V[i] = rtNaN;
    }
  }
  i = S->size[0] * S->size[1];
  S->size[0] = U->size[1];
  S->size[1] = 3;
  emxEnsureCapacity_real_T(S, i);
  U_data = S->data;
  nx = U->size[1] * 3;
  for (i = 0; i < nx; i++) {
    U_data[i] = 0.0;
  }
  i = k - 1;
  for (k = 0; k <= i; k++) {
    U_data[k + S->size[0] * k] = s_data[k];
  }
}

/*
 * File trailer for svd1.c
 *
 * [EOF]
 */
