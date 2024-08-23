/*
 * File: ShengDaoGaoDu.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 21:29:19
 */

/* Include Files */
#include "ShengDaoGaoDu.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);

/* Function Definitions */
/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int tempAbsQuotient;
  unsigned int u;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      tempAbsQuotient = ~(unsigned int)numerator + 1U;
    } else {
      tempAbsQuotient = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u = ~(unsigned int)denominator + 1U;
    } else {
      u = (unsigned int)denominator;
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

/*
 * Arguments    : double numShengLu
 *                emxArray_real_T *Ti
 * Return Type  : void
 */
void ShengDaoGaoDu(double numShengLu, emxArray_real_T *Ti)
{
  static const double dv5[10] = {-0.973907, -0.865063, -0.67941, -0.433395,
                                 -0.148874, 0.148874,  0.433395, 0.67941,
                                 0.865063,  0.973907};
  static const double dv4[9] = {-0.96816, -0.836031, -0.613371, -0.324253, 0.0,
                                0.324253, 0.613371,  0.836031,  0.96816};
  static const double dv3[8] = {-0.96029, -0.796666, -0.525532, -0.183435,
                                0.183435, 0.525532,  0.796666,  0.96029};
  static const double dv2[7] = {-0.949108, -0.741531, -0.405845, 0.0,
                                0.405845,  0.741531,  0.949108};
  static const double dv1[6] = {-0.93247, -0.661209, -0.238619,
                                0.238619, 0.661209,  0.93247};
  static const double dv[5] = {-0.90618, -0.538469, 0.0, 0.538469, 0.90618};
  emxArray_real_T *Ti1;
  double *Ti1_data;
  double *Ti_data;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int loop_ub_tmp;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInit_real_T(&Ti1, 2);
  i = Ti1->size[0] * Ti1->size[1];
  Ti1->size[0] = 1;
  loop_ub_tmp = (int)numShengLu;
  Ti1->size[1] = (int)numShengLu;
  emxEnsureCapacity_real_T(Ti1, i);
  Ti1_data = Ti1->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Ti1_data[i] = 0.0;
  }
  switch ((int)numShengLu) {
  case 1:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 1;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    Ti1_data[0] = 0.0;
    break;
  case 2:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 2;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    Ti1_data[0] = -0.57735;
    Ti1_data[1] = 0.57735;
    break;
  case 3:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 3;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    Ti1_data[0] = -0.774597;
    Ti1_data[1] = 0.0;
    Ti1_data[2] = 0.774597;
    break;
  case 4:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 4;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    Ti1_data[0] = -0.861136;
    Ti1_data[1] = -0.339981;
    Ti1_data[2] = 0.339981;
    Ti1_data[3] = 0.861136;
    break;
  case 5:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 5;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 5; i++) {
      Ti1_data[i] = dv[i];
    }
    break;
  case 6:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 6;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 6; i++) {
      Ti1_data[i] = dv1[i];
    }
    break;
  case 7:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 7;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 7; i++) {
      Ti1_data[i] = dv2[i];
    }
    break;
  case 8:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 8;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 8; i++) {
      Ti1_data[i] = dv3[i];
    }
    break;
  case 9:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 9;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 9; i++) {
      Ti1_data[i] = dv4[i];
    }
    break;
  case 10:
    i = Ti1->size[0] * Ti1->size[1];
    Ti1->size[0] = 1;
    Ti1->size[1] = 10;
    emxEnsureCapacity_real_T(Ti1, i);
    Ti1_data = Ti1->data;
    for (i = 0; i < 10; i++) {
      Ti1_data[i] = dv5[i];
    }
    break;
  }
  if (Ti1->size[1] < 1) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = Ti1->size[1] - 1;
    i1 = -1;
    i2 = 0;
  }
  loop_ub_tmp = Ti->size[0] * Ti->size[1];
  Ti->size[0] = 1;
  loop_ub = div_s32(i2 - i, i1);
  Ti->size[1] = (Ti1->size[1] + loop_ub) + 1;
  emxEnsureCapacity_real_T(Ti, loop_ub_tmp);
  Ti_data = Ti->data;
  loop_ub_tmp = Ti1->size[1];
  for (i2 = 0; i2 < loop_ub_tmp; i2++) {
    Ti_data[i2] = Ti1_data[i2];
  }
  for (i2 = 0; i2 <= loop_ub; i2++) {
    Ti_data[i2 + Ti1->size[1]] = Ti1_data[i + i1 * i2];
  }
  emxFree_real_T(&Ti1);
}

/*
 * File trailer for ShengDaoGaoDu.c
 *
 * [EOF]
 */
