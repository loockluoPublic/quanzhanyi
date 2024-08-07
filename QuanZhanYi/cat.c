/*
 * File: cat.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Aug-2024 19:00:37
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
 *                double in4
 *                const double in5[3]
 * Return Type  : void
 */
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                      const emxArray_real_T *in3, double in4,
                      const double in5[3])
{
  emxArray_real_T *b_in4;
  const double *in2_data;
  const double *in3_data;
  double b_in5;
  double c_in5;
  double d_in5;
  double *in1_data;
  double *in4_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  b_in5 = in5[0];
  c_in5 = in5[1];
  d_in5 = in5[2];
  emxInit_real_T(&b_in4, 1);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  i = b_in4->size[0];
  b_in4->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in4, i);
  in4_data = b_in4->data;
  stride_0_0 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in4_data[i] = -((in4 + b_in5 * in2_data[i * stride_0_0]) +
                    c_in5 * in3_data[i * stride_1_0]) /
                  d_in5;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = in2->size[1];
  in1->size[1] = 3;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = in2->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i];
  }
  loop_ub = in3->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + in1->size[0]] = in3_data[i];
  }
  loop_ub = b_in4->size[0];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + in1->size[0] * 2] = in4_data[i];
  }
  emxFree_real_T(&b_in4);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 *                double in4
 *                const emxArray_real_T *in5
 *                const emxArray_real_T *in6
 *                const emxArray_real_T *in7
 *                double in8
 * Return Type  : void
 */
void binary_expand_op_12(emxArray_real_T *in1, double in2,
                         const emxArray_real_T *in3, double in4,
                         const emxArray_real_T *in5, const emxArray_real_T *in6,
                         const emxArray_real_T *in7, double in8)
{
  emxArray_real_T *b_in4;
  const double *in3_data;
  const double *in5_data;
  const double *in6_data;
  const double *in7_data;
  double *in1_data;
  double *in4_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  in7_data = in7->data;
  in6_data = in6->data;
  in5_data = in5->data;
  in3_data = in3->data;
  emxInit_real_T(&b_in4, 2);
  i = b_in4->size[0] * b_in4->size[1];
  b_in4->size[0] = 1;
  if (in7->size[1] == 1) {
    loop_ub = in6->size[1];
  } else {
    loop_ub = in7->size[1];
  }
  if (loop_ub == 1) {
    loop_ub = in5->size[1];
  }
  b_in4->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in4, i);
  in4_data = b_in4->data;
  stride_0_1 = (in5->size[1] != 1);
  stride_1_1 = (in6->size[1] != 1);
  stride_2_1 = (in7->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in4_data[i] = (in4 * in5_data[i * stride_0_1] -
                   in6_data[i * stride_1_1] * in7_data[i * stride_2_1]) /
                  in8;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 2;
  in1->size[1] = in3->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = in3->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[2 * i] = in2 * in3_data[i] / 3.1415926535897931 * 180.0;
  }
  loop_ub = b_in4->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[2 * i + 1] = in4_data[i];
  }
  emxFree_real_T(&b_in4);
}

/*
 * File trailer for cat.c
 *
 * [EOF]
 */
