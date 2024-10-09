/*
 * File: svd1.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Oct-2024 00:11:45
 */

/* Include Files */
#include "svd1.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 *                emxArray_real_T *S
 *                double V[9]
 * Return Type  : void
 */
void b_svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
           double V[9])
{
  static const signed char b_V[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  emxArray_real_T *U1;
  emxArray_real_T *b_A;
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
  emxInit_real_T(&b_A, 2);
  if (p) {
    if (A->size[0] == 0) {
      U->size[0] = 0;
      U->size[1] = 0;
      k = 0;
      for (i = 0; i < 9; i++) {
        V[i] = b_V[i];
      }
    } else {
      i = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = 3;
      emxEnsureCapacity_real_T(b_A, i);
      U_data = b_A->data;
      nx = A->size[0] * A->size[1] - 1;
      for (i = 0; i <= nx; i++) {
        U_data[i] = A_data[i];
      }
      k = b_xzsvdc(b_A, U, s_data, V);
    }
  } else {
    emxInit_real_T(&U1, 2);
    if (A->size[0] == 0) {
      i = U1->size[0] * U1->size[1];
      U1->size[0] = A->size[0];
      U1->size[1] = A->size[0];
      emxEnsureCapacity_real_T(U1, i);
      U_data = U1->data;
      nx = A->size[0] * A->size[0];
      for (i = 0; i < nx; i++) {
        U_data[i] = 0.0;
      }
      i = A->size[0];
      for (nx = 0; nx < i; nx++) {
        U_data[nx + U1->size[0] * nx] = 1.0;
      }
      k = 0;
    } else {
      i = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = 3;
      emxEnsureCapacity_real_T(b_A, i);
      U_data = b_A->data;
      nx = A->size[0] * 3;
      for (i = 0; i < nx; i++) {
        U_data[i] = 0.0;
      }
      k = b_xzsvdc(b_A, U1, s_data, V1);
    }
    i = U->size[0] * U->size[1];
    U->size[0] = U1->size[0];
    U->size[1] = U1->size[1];
    emxEnsureCapacity_real_T(U, i);
    U_data = U->data;
    nx = U1->size[0] * U1->size[1];
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
  emxFree_real_T(&b_A);
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
