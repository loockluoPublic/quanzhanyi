/*
 * File: OffsetCalculate.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 05-Jul-2024 14:54:53
 */

/* Include Files */
#include "OffsetCalculate.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "div.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2);

static void c_plus(emxArray_real_T *in1, const emxArray_real_T *in2,
                   const emxArray_real_T *in3);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] - in2_data[i * stride_1_1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void c_plus(emxArray_real_T *in1, const emxArray_real_T *in2,
                   const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  if (in3->size[1] == 1) {
    in1->size[1] = in2->size[1];
  } else {
    in1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] + in3_data[i * stride_1_1];
  }
}

/*
 * Arguments    : double Mradial
 *                double phi
 *                const emxArray_real_T *Ang
 *                const emxArray_real_T *a
 *                emxArray_real_T *OffsetOut
 * Return Type  : void
 */
void OffsetCalculate(double Mradial, double phi, const emxArray_real_T *Ang,
                     const emxArray_real_T *a, emxArray_real_T *OffsetOut)
{
  emxArray_boolean_T *r2;
  emxArray_int32_T *r4;
  emxArray_real_T *r;
  emxArray_real_T *temp;
  emxArray_real_T *x;
  emxArray_real_T *y_tmp;
  const double *Ang_data;
  const double *a_data;
  double b_a;
  double b_x;
  double *OffsetOut_data;
  double *r1;
  double *temp_data;
  double *x_data;
  double *y_tmp_data;
  int i;
  int k;
  int nx;
  int *r5;
  boolean_T *r3;
  a_data = a->data;
  Ang_data = Ang->data;
  emxInit_real_T(&temp, 2);
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(temp, i);
  temp_data = temp->data;
  nx = Ang->size[1];
  for (i = 0; i < nx; i++) {
    temp_data[i] = Ang_data[i];
  }
  nx = Ang->size[1];
  for (k = 0; k < nx; k++) {
    temp_data[k] = sin(temp_data[k]);
  }
  emxInit_real_T(&y_tmp, 2);
  i = y_tmp->size[0] * y_tmp->size[1];
  y_tmp->size[0] = 1;
  y_tmp->size[1] = a->size[1];
  emxEnsureCapacity_real_T(y_tmp, i);
  y_tmp_data = y_tmp->data;
  nx = a->size[1];
  for (i = 0; i < nx; i++) {
    y_tmp_data[i] = Mradial - a_data[i];
  }
  if (temp->size[1] == y_tmp->size[1]) {
    nx = temp->size[1] - 1;
    i = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(temp, i);
    temp_data = temp->data;
    for (i = 0; i <= nx; i++) {
      temp_data[i] = Mradial * temp_data[i] / y_tmp_data[i];
    }
  } else {
    l_binary_expand_op(temp, Mradial, y_tmp);
    temp_data = temp->data;
  }
  nx = temp->size[1];
  for (k = 0; k < nx; k++) {
    temp_data[k] = asin(temp_data[k]);
  }
  if (temp->size[1] == Ang->size[1]) {
    nx = temp->size[1] - 1;
    i = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(temp, i);
    temp_data = temp->data;
    for (i = 0; i <= nx; i++) {
      temp_data[i] -= Ang_data[i];
    }
  } else {
    b_minus(temp, Ang);
    temp_data = temp->data;
  }
  b_a = 6.2831853071795862 * Mradial / 360.0;
  emxInit_real_T(&r, 2);
  if (temp->size[1] == Ang->size[1]) {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = temp->size[1];
    emxEnsureCapacity_real_T(r, i);
    r1 = r->data;
    nx = temp->size[1];
    for (i = 0; i < nx; i++) {
      r1[i] = temp_data[i] + Ang_data[i];
    }
  } else {
    c_plus(r, temp, Ang);
    r1 = r->data;
  }
  nx = r->size[1];
  for (k = 0; k < nx; k++) {
    r1[k] = cos(r1[k]);
  }
  emxInit_real_T(&x, 2);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  nx = Ang->size[1];
  for (i = 0; i < nx; i++) {
    x_data[i] = Ang_data[i];
  }
  nx = Ang->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = cos(x_data[k]);
  }
  b_x = tan(phi);
  if (y_tmp->size[1] == 1) {
    nx = r->size[1];
  } else {
    nx = y_tmp->size[1];
  }
  if ((y_tmp->size[1] == r->size[1]) && (x->size[1] == nx)) {
    i = OffsetOut->size[0] * OffsetOut->size[1];
    OffsetOut->size[0] = 2;
    OffsetOut->size[1] = temp->size[1];
    emxEnsureCapacity_real_T(OffsetOut, i);
    OffsetOut_data = OffsetOut->data;
    nx = temp->size[1];
    for (i = 0; i < nx; i++) {
      OffsetOut_data[2 * i] = b_a * temp_data[i] / 3.1415926535897931 * 180.0;
    }
    nx = x->size[1];
    for (i = 0; i < nx; i++) {
      OffsetOut_data[2 * i + 1] =
          (Mradial * x_data[i] - y_tmp_data[i] * r1[i]) / b_x;
    }
  } else {
    k_binary_expand_op(OffsetOut, b_a, temp, Mradial, x, y_tmp, r, b_x);
    OffsetOut_data = OffsetOut->data;
  }
  emxFree_real_T(&y_tmp);
  emxFree_real_T(&x);
  emxFree_real_T(&r);
  emxFree_real_T(&temp);
  emxInit_boolean_T(&r2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 2;
  r2->size[1] = OffsetOut->size[1];
  emxEnsureCapacity_boolean_T(r2, i);
  r3 = r2->data;
  nx = 2 * OffsetOut->size[1];
  for (i = 0; i < nx; i++) {
    r3[i] = rtIsNaN(OffsetOut_data[i]);
  }
  k = (r2->size[1] << 1) - 1;
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (r3[i]) {
      nx++;
    }
  }
  emxInit_int32_T(&r4);
  i = r4->size[0];
  r4->size[0] = nx;
  emxEnsureCapacity_int32_T(r4, i);
  r5 = r4->data;
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (r3[i]) {
      r5[nx] = i + 1;
      nx++;
    }
  }
  emxFree_boolean_T(&r2);
  nx = r4->size[0] - 1;
  for (i = 0; i <= nx; i++) {
    OffsetOut_data[r5[i] - 1] = 0.0;
  }
  emxFree_int32_T(&r4);
}

/*
 * File trailer for OffsetCalculate.c
 *
 * [EOF]
 */
