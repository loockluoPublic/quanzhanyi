/*
 * File: Calculat_JuXing_A_and_B_Points_after_Offest.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Aug-2024 16:15:12
 */

/* Include Files */
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "ShengDaoGaoDu.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_2(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static void binary_expand_op_4(emxArray_real_T *in1, double in2, double in3,
                               double in4, double in5,
                               const emxArray_real_T *in6);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void binary_expand_op_2(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 3;
  emxEnsureCapacity_real_T(in1, i);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[0] != 1);
  stride_1_1 = (in3->size[0] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    in1_data[3 * i] = in2_data[aux_0_1] + in3_data[aux_1_1];
    in1_data[3 * i + 1] =
        in2_data[aux_0_1 + in2->size[0]] + in3_data[aux_1_1 + in3->size[0]];
    in1_data[3 * i + 2] = in2_data[aux_0_1 + in2->size[0] * 2] +
                          in3_data[aux_1_1 + in3->size[0] * 2];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                double in3
 *                double in4
 *                double in5
 *                const emxArray_real_T *in6
 * Return Type  : void
 */
static void binary_expand_op_4(emxArray_real_T *in1, double in2, double in3,
                               double in4, double in5,
                               const emxArray_real_T *in6)
{
  emxArray_real_T *b_in1;
  emxArray_real_T *b_in6;
  const double *in6_data;
  double *b_in1_data;
  double *b_in6_data;
  double *in1_data;
  int i;
  int loop_ub_tmp;
  int stride_0_1;
  int stride_1_1;
  in6_data = in6->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = (int)in5 + (int)in5;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub_tmp = (int)in5;
  for (i = 0; i < loop_ub_tmp; i++) {
    in1_data[i] = in2 / 2.0 * in3 + in4;
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    in1_data[i + (int)in5] = -in2 / 2.0 * in3 + in4;
  }
  emxInit_real_T(&b_in6, 2);
  i = b_in6->size[0] * b_in6->size[1];
  b_in6->size[0] = 1;
  b_in6->size[1] = in6->size[1] + in6->size[1];
  emxEnsureCapacity_real_T(b_in6, i);
  b_in6_data = b_in6->data;
  loop_ub_tmp = in6->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    b_in6_data[i] = -in6_data[i] / in3;
  }
  loop_ub_tmp = in6->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    b_in6_data[i + in6->size[1]] = in6_data[i] / in3;
  }
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (b_in6->size[1] == 1) {
    loop_ub_tmp = in1->size[1];
  } else {
    loop_ub_tmp = b_in6->size[1];
  }
  b_in1->size[1] = loop_ub_tmp;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (b_in6->size[1] != 1);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + b_in6_data[i * stride_1_1];
  }
  emxFree_real_T(&b_in6);
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub_tmp = b_in1->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * 平移以及计算旋转矩阵
 *
 * Arguments    : const double Tao[3]
 *                const double UPP[3]
 *                const double Pin[3]
 *                double b
 *                double h
 *                const double PAB[3]
 *                double phi
 *                double shenglunum
 *                const emxArray_real_T *a
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 * Return Type  : void
 */
void Calculat_JuXing_A_and_B_Points_after_Offest(
    const double Tao[3], const double UPP[3], const double Pin[3], double b,
    double h, const double PAB[3], double phi, double shenglunum,
    const emxArray_real_T *a, emxArray_real_T *PointTable_A_off,
    emxArray_real_T *PointTable_B_off)
{
  emxArray_real_T *Axoff;
  emxArray_real_T *Ay;
  emxArray_real_T *Ti;
  emxArray_real_T *b_Axoff;
  emxArray_real_T *b_a;
  emxArray_real_T *b_b;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  double ROT[9];
  double b_PAB[9];
  double rot1[9];
  double UPPmove[3];
  const double *a_data;
  double absxk;
  double c;
  double norm_vec;
  double r_idx_0;
  double r_idx_2;
  double s;
  double scale;
  double t;
  double theta1_tmp;
  double theta1_tmp_idx_1;
  double theta1_tmp_idx_2;
  double xbase;
  double *Axoff_data;
  double *Ay_data;
  double *PointTable_A_off_data;
  double *Ti_data;
  double *b_a_data;
  double *r1;
  int i;
  int ibmat;
  int itilerow;
  int loop_ub_tmp;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  a_data = a->data;
  /*  平移 Pin */
  UPPmove[0] = UPP[0] - Pin[0];
  UPPmove[1] = UPP[1] - Pin[1];
  UPPmove[2] = UPP[2] - Pin[2];
  /*  构建旋转矩阵1,pt6转到z轴 */
  xbase = 0.0 * UPPmove[2] - UPPmove[1];
  theta1_tmp_idx_1 = UPPmove[0] - 0.0 * UPPmove[2];
  theta1_tmp_idx_2 = 0.0 * UPPmove[1] - 0.0 * UPPmove[0];
  scale = 3.3121686421112381E-170;
  absxk = fabs(xbase);
  if (absxk > 3.3121686421112381E-170) {
    theta1_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta1_tmp = t * t;
  }
  absxk = fabs(theta1_tmp_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    theta1_tmp = theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta1_tmp += t * t;
  }
  t = theta1_tmp_idx_2 / scale;
  theta1_tmp += t * t;
  theta1_tmp = scale * sqrt(theta1_tmp);
  norm_vec = rt_atan2d_snf(theta1_tmp,
                           (0.0 * UPPmove[0] + 0.0 * UPPmove[1]) + UPPmove[2]);
  s = sin(norm_vec);
  c = cos(norm_vec);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  r_idx_2 = xbase / theta1_tmp;
  r_idx_0 = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  r_idx_2 = theta1_tmp_idx_1 / theta1_tmp;
  xbase = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  r_idx_2 = theta1_tmp_idx_2 / theta1_tmp;
  t = r_idx_2 / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    UPPmove[0] = 0.0;
    UPPmove[1] = 0.0;
    UPPmove[2] = 0.0;
  } else {
    UPPmove[0] = r_idx_0 / norm_vec;
    UPPmove[1] = xbase / norm_vec;
    UPPmove[2] = r_idx_2 / norm_vec;
  }
  xbase = (1.0 - c) * UPPmove[0];
  rot1[0] = xbase * UPPmove[0] + c;
  r_idx_2 = xbase * UPPmove[1];
  r_idx_0 = s * UPPmove[2];
  rot1[3] = r_idx_2 - r_idx_0;
  xbase *= UPPmove[2];
  norm_vec = s * UPPmove[1];
  rot1[6] = xbase + norm_vec;
  rot1[1] = r_idx_2 + r_idx_0;
  r_idx_2 = (1.0 - c) * UPPmove[1];
  rot1[4] = r_idx_2 * UPPmove[1] + c;
  r_idx_2 *= UPPmove[2];
  r_idx_0 = s * UPPmove[0];
  rot1[7] = r_idx_2 - r_idx_0;
  rot1[2] = xbase - norm_vec;
  rot1[5] = r_idx_2 + r_idx_0;
  rot1[8] = (1.0 - c) * UPPmove[2] * UPPmove[2] + c;
  /*  Tao旋转rot1 */
  norm_vec = Tao[0];
  xbase = Tao[1];
  r_idx_2 = Tao[2];
  for (i = 0; i < 3; i++) {
    UPPmove[i] = (norm_vec * rot1[3 * i] + xbase * rot1[3 * i + 1]) +
                 r_idx_2 * rot1[3 * i + 2];
  }
  /*  构建旋转矩阵2,taorot1转到x轴 */
  xbase = 0.0 * UPPmove[2] - 0.0 * UPPmove[1];
  theta1_tmp_idx_1 = 0.0 * UPPmove[0] - UPPmove[2];
  theta1_tmp_idx_2 = UPPmove[1] - 0.0 * UPPmove[0];
  scale = 3.3121686421112381E-170;
  t = xbase / 3.3121686421112381E-170;
  theta1_tmp = t * t;
  absxk = fabs(theta1_tmp_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / absxk;
    theta1_tmp = theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta1_tmp += t * t;
  }
  absxk = fabs(theta1_tmp_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    theta1_tmp = theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta1_tmp += t * t;
  }
  theta1_tmp = scale * sqrt(theta1_tmp);
  /*  总的旋转矩阵 ROT */
  norm_vec = rt_atan2d_snf(theta1_tmp,
                           (UPPmove[0] + 0.0 * UPPmove[1]) + 0.0 * UPPmove[2]);
  s = sin(norm_vec);
  c = cos(norm_vec);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  r_idx_2 = xbase / theta1_tmp;
  r_idx_0 = r_idx_2;
  t = r_idx_2 / 3.3121686421112381E-170;
  norm_vec = t * t;
  r_idx_2 = theta1_tmp_idx_1 / theta1_tmp;
  xbase = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec += t * t;
  }
  r_idx_2 = theta1_tmp_idx_2 / theta1_tmp;
  absxk = fabs(r_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    UPPmove[0] = 0.0;
    UPPmove[1] = 0.0;
    UPPmove[2] = 0.0;
  } else {
    UPPmove[0] = r_idx_0 / norm_vec;
    UPPmove[1] = xbase / norm_vec;
    UPPmove[2] = r_idx_2 / norm_vec;
  }
  xbase = (1.0 - c) * UPPmove[0];
  b_PAB[0] = xbase * UPPmove[0] + c;
  r_idx_2 = xbase * UPPmove[1];
  r_idx_0 = s * UPPmove[2];
  b_PAB[3] = r_idx_2 - r_idx_0;
  xbase *= UPPmove[2];
  norm_vec = s * UPPmove[1];
  b_PAB[6] = xbase + norm_vec;
  b_PAB[1] = r_idx_2 + r_idx_0;
  r_idx_2 = (1.0 - c) * UPPmove[1];
  b_PAB[4] = r_idx_2 * UPPmove[1] + c;
  r_idx_2 *= UPPmove[2];
  r_idx_0 = s * UPPmove[0];
  b_PAB[7] = r_idx_2 - r_idx_0;
  b_PAB[2] = xbase - norm_vec;
  b_PAB[5] = r_idx_2 + r_idx_0;
  b_PAB[8] = (1.0 - c) * UPPmove[2] * UPPmove[2] + c;
  for (i = 0; i < 3; i++) {
    norm_vec = rot1[i];
    xbase = rot1[i + 3];
    r_idx_2 = rot1[i + 6];
    for (itilerow = 0; itilerow < 3; itilerow++) {
      ROT[i + 3 * itilerow] =
          (norm_vec * b_PAB[3 * itilerow] + xbase * b_PAB[3 * itilerow + 1]) +
          r_idx_2 * b_PAB[3 * itilerow + 2];
    }
  }
  /*  计算A点 */
  emxInit_real_T(&Ti, 2);
  ShengDaoGaoDu(shenglunum, Ti);
  /*  在PABrot的基础上增量xyz */
  /*  x为b*tan(phi) */
  /*  y为b */
  /*  z为Ti*h */
  norm_vec = PAB[0];
  xbase = PAB[1];
  r_idx_2 = PAB[2];
  for (i = 0; i < 3; i++) {
    r_idx_0 = Pin[i];
    rot1[3 * i] = norm_vec - r_idx_0;
    rot1[3 * i + 1] = xbase - r_idx_0;
    rot1[3 * i + 2] = r_idx_2 - r_idx_0;
  }
  for (i = 0; i < 3; i++) {
    norm_vec = rot1[i];
    xbase = rot1[i + 3];
    r_idx_2 = rot1[i + 6];
    for (itilerow = 0; itilerow < 3; itilerow++) {
      b_PAB[i + 3 * itilerow] =
          (norm_vec * ROT[3 * itilerow] + xbase * ROT[3 * itilerow + 1]) +
          r_idx_2 * ROT[3 * itilerow + 2];
    }
  }
  xbase = b_PAB[0];
  r_idx_2 = tan(phi);
  emxInit_real_T(&Ay, 2);
  i = Ay->size[0] * Ay->size[1];
  Ay->size[0] = 1;
  itilerow = (int)shenglunum + (int)shenglunum;
  Ay->size[1] = itilerow;
  emxEnsureCapacity_real_T(Ay, i);
  Ay_data = Ay->data;
  loop_ub_tmp = (int)shenglunum;
  for (i = 0; i < loop_ub_tmp; i++) {
    Ay_data[i] = b / 2.0;
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    Ay_data[i + (int)shenglunum] = -b / 2.0;
  }
  i = Ti->size[0] * Ti->size[1];
  Ti->size[0] = 1;
  emxEnsureCapacity_real_T(Ti, i);
  Ti_data = Ti->data;
  ibmat = Ti->size[1] - 1;
  for (i = 0; i <= ibmat; i++) {
    Ti_data[i] = Ti_data[i] * h / 2.0;
  }
  /*  计算并偏移 */
  i = a->size[1] + a->size[1];
  emxInit_real_T(&Axoff, 2);
  if (itilerow == i) {
    emxInit_real_T(&b_b, 2);
    ibmat = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = itilerow;
    emxEnsureCapacity_real_T(b_b, ibmat);
    PointTable_A_off_data = b_b->data;
    for (itilerow = 0; itilerow < loop_ub_tmp; itilerow++) {
      PointTable_A_off_data[itilerow] = b / 2.0 * r_idx_2 + xbase;
    }
    for (itilerow = 0; itilerow < loop_ub_tmp; itilerow++) {
      PointTable_A_off_data[itilerow + (int)shenglunum] =
          -b / 2.0 * r_idx_2 + xbase;
    }
    emxInit_real_T(&b_a, 2);
    itilerow = b_a->size[0] * b_a->size[1];
    b_a->size[0] = 1;
    b_a->size[1] = i;
    emxEnsureCapacity_real_T(b_a, itilerow);
    b_a_data = b_a->data;
    ibmat = a->size[1];
    for (i = 0; i < ibmat; i++) {
      b_a_data[i] = -a_data[i] / r_idx_2;
    }
    ibmat = a->size[1];
    for (i = 0; i < ibmat; i++) {
      b_a_data[i + a->size[1]] = a_data[i] / r_idx_2;
    }
    i = Axoff->size[0] * Axoff->size[1];
    Axoff->size[0] = 1;
    Axoff->size[1] = b_b->size[1];
    emxEnsureCapacity_real_T(Axoff, i);
    Axoff_data = Axoff->data;
    ibmat = b_b->size[1];
    for (i = 0; i < ibmat; i++) {
      Axoff_data[i] = PointTable_A_off_data[i] + b_a_data[i];
    }
    emxFree_real_T(&b_a);
    emxFree_real_T(&b_b);
  } else {
    binary_expand_op_4(Axoff, b, r_idx_2, b_PAB[0], shenglunum, a);
    Axoff_data = Axoff->data;
  }
  /*  旋转平移回去 */
  pinv(ROT, rot1);
  emxInit_real_T(&r, 2);
  i = (int)(2.0 * shenglunum);
  itilerow = r->size[0] * r->size[1];
  r->size[0] = i;
  r->size[1] = 3;
  emxEnsureCapacity_real_T(r, itilerow);
  r1 = r->data;
  for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
    ibmat = loop_ub_tmp * i;
    for (itilerow = 0; itilerow < i; itilerow++) {
      r1[ibmat + itilerow] = Pin[loop_ub_tmp];
    }
  }
  emxInit_real_T(&b_Axoff, 2);
  i = b_Axoff->size[0] * b_Axoff->size[1];
  b_Axoff->size[0] = 3;
  b_Axoff->size[1] = Axoff->size[1];
  emxEnsureCapacity_real_T(b_Axoff, i);
  PointTable_A_off_data = b_Axoff->data;
  ibmat = Axoff->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i] = Axoff_data[i];
  }
  ibmat = Ay->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i + 1] = Ay_data[i];
  }
  ibmat = Ti->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i + 2] = Ti_data[i];
  }
  emxInit_real_T(&r2, 2);
  mtimes(b_Axoff, rot1, r2);
  b_a_data = r2->data;
  if (r2->size[0] == r->size[0]) {
    i = PointTable_A_off->size[0] * PointTable_A_off->size[1];
    PointTable_A_off->size[0] = 3;
    PointTable_A_off->size[1] = r2->size[0];
    emxEnsureCapacity_real_T(PointTable_A_off, i);
    PointTable_A_off_data = PointTable_A_off->data;
    ibmat = r2->size[0];
    for (i = 0; i < ibmat; i++) {
      PointTable_A_off_data[3 * i] = b_a_data[i] + r1[i];
      PointTable_A_off_data[3 * i + 1] =
          b_a_data[i + r2->size[0]] + r1[i + r->size[0]];
      PointTable_A_off_data[3 * i + 2] =
          b_a_data[i + r2->size[0] * 2] + r1[i + r->size[0] * 2];
    }
  } else {
    binary_expand_op_2(PointTable_A_off, r2, r);
  }
  i = b_Axoff->size[0] * b_Axoff->size[1];
  b_Axoff->size[0] = 3;
  b_Axoff->size[1] = Axoff->size[1];
  emxEnsureCapacity_real_T(b_Axoff, i);
  PointTable_A_off_data = b_Axoff->data;
  ibmat = Axoff->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i] = Axoff_data[i];
  }
  emxFree_real_T(&Axoff);
  ibmat = Ay->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i + 1] = -Ay_data[i];
  }
  emxFree_real_T(&Ay);
  ibmat = Ti->size[1];
  for (i = 0; i < ibmat; i++) {
    PointTable_A_off_data[3 * i + 2] = Ti_data[i];
  }
  emxFree_real_T(&Ti);
  mtimes(b_Axoff, rot1, r2);
  b_a_data = r2->data;
  emxFree_real_T(&b_Axoff);
  if (r2->size[0] == r->size[0]) {
    i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
    PointTable_B_off->size[0] = 3;
    PointTable_B_off->size[1] = r2->size[0];
    emxEnsureCapacity_real_T(PointTable_B_off, i);
    PointTable_A_off_data = PointTable_B_off->data;
    ibmat = r2->size[0];
    for (i = 0; i < ibmat; i++) {
      PointTable_A_off_data[3 * i] = b_a_data[i] + r1[i];
      PointTable_A_off_data[3 * i + 1] =
          b_a_data[i + r2->size[0]] + r1[i + r->size[0]];
      PointTable_A_off_data[3 * i + 2] =
          b_a_data[i + r2->size[0] * 2] + r1[i + r->size[0] * 2];
    }
  } else {
    binary_expand_op_2(PointTable_B_off, r2, r);
  }
  emxFree_real_T(&r2);
  emxFree_real_T(&r);
}

/*
 * File trailer for Calculat_JuXing_A_and_B_Points_after_Offest.c
 *
 * [EOF]
 */
