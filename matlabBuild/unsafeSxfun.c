/*
 * File: unsafeSxfun.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Jan-2025 23:29:36
 */

/* Include Files */
#include "unsafeSxfun.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
void binary_expand_op_7(emxArray_real_T *in1, const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double varargin_1;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 2;
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[2 * i] = in1_data[2 * aux_0_1] - in3_data[2 * aux_1_1];
    b_in1_data[2 * i + 1] =
        in1_data[2 * aux_0_1 + 1] - in3_data[2 * aux_1_1 + 1];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 2;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[2 * i] = b_in1_data[2 * i];
    stride_0_1 = 2 * i + 1;
    in1_data[stride_0_1] = b_in1_data[stride_0_1];
  }
  emxFree_real_T(&b_in1);
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 2;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = in1_data[2 * i];
    in1_data[2 * i] = varargin_1 * varargin_1;
    stride_0_1 = 2 * i + 1;
    varargin_1 = in1_data[stride_0_1];
    in1_data[stride_0_1] = varargin_1 * varargin_1;
  }
}

/*
 * File trailer for unsafeSxfun.c
 *
 * [EOF]
 */
