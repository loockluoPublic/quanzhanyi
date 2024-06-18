/*
 * File: cat.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 18-Jun-2024 11:44:39
 */

/* Include Files */
#include "cat.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
void c_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3, const emxArray_real_T *in4)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  const double *in4_data;
  double *b_in2_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  emxInit_real_T(&b_in2, 1);
  i = b_in2->size[0];
  if (in3->size[0] == 1) {
    b_in2->size[0] = in2->size[0];
  } else {
    b_in2->size[0] = in3->size[0];
  }
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] + in3_data[i * stride_1_0];
  }
  loop_ub = in4->size[1];
  stride_0_0 = in4->size[1];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in2->size[0];
  in1->size[1] = 4;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_1_0 = b_in2->size[0];
  for (i = 0; i < stride_1_0; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(&b_in2);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + in1->size[0]] = in4_data[2 * i];
  }
  for (i = 0; i < stride_0_0; i++) {
    in1_data[i + in1->size[0] * 2] = in4_data[2 * i + 1];
  }
  loop_ub = in4->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + in1->size[0] * 3] = 1.0;
  }
}

/*
 * File trailer for cat.c
 *
 * [EOF]
 */
