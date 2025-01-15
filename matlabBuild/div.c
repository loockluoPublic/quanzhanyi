/*
 * File: div.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 15-Jan-2025 14:19:16
 */

/* Include Files */
#include "div.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
void binary_expand_op_22(emxArray_real_T *in1, double in2,
                         const emxArray_real_T *in3)
{
  emxArray_real_T *b_in2;
  const double *in3_data;
  double *in1_data;
  double *in2_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in2, 2);
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = 1;
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  b_in2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  in2_data = b_in2->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = in2 * in1_data[i * stride_0_1] / in3_data[i * stride_1_1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in2->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in2->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i];
  }
  emxFree_real_T(&b_in2);
}

/*
 * File trailer for div.c
 *
 * [EOF]
 */
