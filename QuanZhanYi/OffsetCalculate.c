/*
 * File: OffsetCalculate.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 21:47:53
 */

/* Include Files */
#include "OffsetCalculate.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "div.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void c_minus(emxArray_real_T *in1, const emxArray_real_T *in2);

static void plus(emxArray_real_T *in1, const emxArray_real_T *in2,
                 const emxArray_real_T *in3);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void c_minus(emxArray_real_T *in1, const emxArray_real_T *in2)
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
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
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
static void plus(emxArray_real_T *in1, const emxArray_real_T *in2,
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
  emxEnsureCapacity_real_T(in1, i);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
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
  int k;
  int nx;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  a_data = a->data;
  Ang_data = Ang->data;
  emxInit_real_T(&temp, 2);
  k = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(temp, k);
  temp_data = temp->data;
  nx = Ang->size[1];
  for (k = 0; k < nx; k++) {
    temp_data[k] = sin(Ang_data[k]);
  }
  emxInit_real_T(&y_tmp, 2);
  k = y_tmp->size[0] * y_tmp->size[1];
  y_tmp->size[0] = 1;
  y_tmp->size[1] = a->size[1];
  emxEnsureCapacity_real_T(y_tmp, k);
  y_tmp_data = y_tmp->data;
  nx = a->size[1];
  for (k = 0; k < nx; k++) {
    y_tmp_data[k] = Mradial - a_data[k];
  }
  if (temp->size[1] == y_tmp->size[1]) {
    nx = temp->size[1] - 1;
    k = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(temp, k);
    temp_data = temp->data;
    for (k = 0; k <= nx; k++) {
      temp_data[k] = Mradial * temp_data[k] / y_tmp_data[k];
    }
  } else {
    binary_expand_op_18(temp, Mradial, y_tmp);
    temp_data = temp->data;
  }
  nx = temp->size[1];
  for (k = 0; k < nx; k++) {
    temp_data[k] = asin(temp_data[k]);
  }
  if (temp->size[1] == Ang->size[1]) {
    nx = temp->size[1] - 1;
    k = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    emxEnsureCapacity_real_T(temp, k);
    temp_data = temp->data;
    for (k = 0; k <= nx; k++) {
      temp_data[k] -= Ang_data[k];
    }
  } else {
    c_minus(temp, Ang);
    temp_data = temp->data;
  }
  b_a = 6.2831853071795862 * Mradial / 360.0;
  emxInit_real_T(&r, 2);
  if (temp->size[1] == Ang->size[1]) {
    k = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = temp->size[1];
    emxEnsureCapacity_real_T(r, k);
    r1 = r->data;
    nx = temp->size[1];
    for (k = 0; k < nx; k++) {
      r1[k] = temp_data[k] + Ang_data[k];
    }
  } else {
    plus(r, temp, Ang);
    r1 = r->data;
  }
  nx = r->size[1];
  for (k = 0; k < nx; k++) {
    r1[k] = cos(r1[k]);
  }
  emxInit_real_T(&x, 2);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  nx = Ang->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = cos(Ang_data[k]);
  }
  b_x = tan(phi);
  if (y_tmp->size[1] == 1) {
    nx = r->size[1];
  } else {
    nx = y_tmp->size[1];
  }
  if ((y_tmp->size[1] == r->size[1]) && (x->size[1] == nx)) {
    k = OffsetOut->size[0] * OffsetOut->size[1];
    OffsetOut->size[0] = 2;
    OffsetOut->size[1] = temp->size[1];
    emxEnsureCapacity_real_T(OffsetOut, k);
    OffsetOut_data = OffsetOut->data;
    nx = temp->size[1];
    for (k = 0; k < nx; k++) {
      OffsetOut_data[2 * k] = b_a * temp_data[k] / 3.1415926535897931 * 180.0;
    }
    nx = x->size[1];
    for (k = 0; k < nx; k++) {
      OffsetOut_data[2 * k + 1] =
          (Mradial * x_data[k] - y_tmp_data[k] * r1[k]) / b_x;
    }
  } else {
    binary_expand_op_17(OffsetOut, b_a, temp, Mradial, x, y_tmp, r, b_x);
    OffsetOut_data = OffsetOut->data;
  }
  emxFree_real_T(&y_tmp);
  emxFree_real_T(&x);
  emxFree_real_T(&r);
  emxFree_real_T(&temp);
  nx = (OffsetOut->size[1] << 1) - 1;
  for (k = 0; k <= nx; k++) {
    if (rtIsNaN(OffsetOut_data[k])) {
      OffsetOut_data[k] = 0.0;
    }
  }
}

/*
 * File trailer for OffsetCalculate.c
 *
 * [EOF]
 */
