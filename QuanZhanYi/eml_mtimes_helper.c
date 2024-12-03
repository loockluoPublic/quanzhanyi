/*
 * File: eml_mtimes_helper.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 23:50:47
 */

/* Include Files */
#include "eml_mtimes_helper.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const double in4[9]
 * Return Type  : void
 */
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                      const emxArray_real_T *in3, const double in4[9])
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  double *b_in2_data;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  emxInit_real_T(&b_in2, 2);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  b_in2->size[1] = 3;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + b_in2->size[0] * i] =
          in2_data[i1 * stride_0_0 + in2->size[0] * i] +
          in3_data[i1 * stride_1_0 + in3->size[0] * i];
    }
  }
  mtimes(b_in2, in4, in1);
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const double in3[9]
 * Return Type  : void
 */
void binary_expand_op_1(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const double in3[9])
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 3;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * i] +
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
  }
  mtimes(b_in1, in3, in1);
  emxFree_real_T(&b_in1);
}

/*
 * File trailer for eml_mtimes_helper.c
 *
 * [EOF]
 */
