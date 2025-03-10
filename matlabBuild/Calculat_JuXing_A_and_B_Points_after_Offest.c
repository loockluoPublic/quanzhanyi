/*
 * File: Calculat_JuXing_A_and_B_Points_after_Offest.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 20:27:52
 */

/* Include Files */
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
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
  const double *in6_data;
  double *b_in1_data;
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
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in6->size[1] == 1) {
    loop_ub_tmp = in1->size[1];
  } else {
    loop_ub_tmp = in6->size[1];
  }
  b_in1->size[1] = loop_ub_tmp;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in6->size[1] != 1);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in6_data[i * stride_1_1];
  }
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
 *                const emxArray_real_T *Ti
 *                const emxArray_real_T *toff
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 * Return Type  : void
 */
void Calculat_JuXing_A_and_B_Points_after_Offest(
    const double Tao[3], const double UPP[3], const double Pin[3], double b,
    double h, const double PAB[3], double phi, double shenglunum,
    const emxArray_real_T *Ti, const emxArray_real_T *toff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off)
{
  emxArray_real_T *Axoff;
  emxArray_real_T *Ay;
  emxArray_real_T *Az;
  emxArray_real_T *b_Axoff;
  emxArray_real_T *b_b;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  double ROT[9];
  double b_dv[9];
  double rot1[9];
  double UPPmove[3];
  double theta1_tmp[3];
  const double *Ti_data;
  const double *toff_data;
  double absxk;
  double b_theta1_tmp;
  double c;
  double norm_vec;
  double r_idx_0;
  double r_idx_1;
  double r_idx_2;
  double s;
  double scale;
  double t;
  double *Axoff_data;
  double *Ay_data;
  double *Az_data;
  double *PointTable_A_off_data;
  double *r1;
  double *r3;
  int i;
  int ibmat;
  int itilerow;
  int loop_ub;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  toff_data = toff->data;
  Ti_data = Ti->data;
  /*  平移 Pin */
  UPPmove[0] = UPP[0] - Pin[0];
  UPPmove[1] = UPP[1] - Pin[1];
  UPPmove[2] = UPP[2] - Pin[2];
  /*  构建旋转矩阵1,pt6转到z轴 */
  theta1_tmp[0] = 0.0 * UPPmove[2] - UPPmove[1];
  theta1_tmp[1] = UPPmove[0] - 0.0 * UPPmove[2];
  theta1_tmp[2] = 0.0 * UPPmove[1] - 0.0 * UPPmove[0];
  scale = 3.3121686421112381E-170;
  absxk = fabs(theta1_tmp[0]);
  if (absxk > 3.3121686421112381E-170) {
    b_theta1_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_theta1_tmp = t * t;
  }
  absxk = fabs(theta1_tmp[1]);
  if (absxk > scale) {
    t = scale / absxk;
    b_theta1_tmp = b_theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_theta1_tmp += t * t;
  }
  t = theta1_tmp[2] / scale;
  b_theta1_tmp += t * t;
  b_theta1_tmp = scale * sqrt(b_theta1_tmp);
  r_idx_2 = rt_atan2d_snf(b_theta1_tmp,
                          (0.0 * UPPmove[0] + 0.0 * UPPmove[1]) + UPPmove[2]);
  s = sin(r_idx_2);
  c = cos(r_idx_2);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  r_idx_2 = theta1_tmp[0] / b_theta1_tmp;
  r_idx_0 = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  r_idx_2 = theta1_tmp[1] / b_theta1_tmp;
  r_idx_1 = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  r_idx_2 = theta1_tmp[2] / b_theta1_tmp;
  t = r_idx_2 / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    UPPmove[0] = 0.0;
    UPPmove[1] = 0.0;
    UPPmove[2] = 0.0;
  } else {
    UPPmove[0] = r_idx_0 / norm_vec;
    UPPmove[1] = r_idx_1 / norm_vec;
    UPPmove[2] = r_idx_2 / norm_vec;
  }
  scale = (1.0 - c) * UPPmove[0];
  rot1[0] = scale * UPPmove[0] + c;
  absxk = scale * UPPmove[1];
  t = s * UPPmove[2];
  rot1[3] = absxk - t;
  scale *= UPPmove[2];
  r_idx_2 = s * UPPmove[1];
  rot1[6] = scale + r_idx_2;
  rot1[1] = absxk + t;
  absxk = (1.0 - c) * UPPmove[1];
  rot1[4] = absxk * UPPmove[1] + c;
  absxk *= UPPmove[2];
  t = s * UPPmove[0];
  rot1[7] = absxk - t;
  rot1[2] = scale - r_idx_2;
  rot1[5] = absxk + t;
  rot1[8] = (1.0 - c) * UPPmove[2] * UPPmove[2] + c;
  /*  Tao旋转rot1 */
  r_idx_2 = Tao[0];
  scale = Tao[1];
  absxk = Tao[2];
  for (i = 0; i < 3; i++) {
    UPPmove[i] = (r_idx_2 * rot1[3 * i] + scale * rot1[3 * i + 1]) +
                 absxk * rot1[3 * i + 2];
  }
  /*  构建旋转矩阵2,taorot1转到x轴 */
  theta1_tmp[0] = 0.0 * UPPmove[2] - 0.0 * UPPmove[1];
  theta1_tmp[1] = 0.0 * UPPmove[0] - UPPmove[2];
  theta1_tmp[2] = UPPmove[1] - 0.0 * UPPmove[0];
  scale = 3.3121686421112381E-170;
  t = theta1_tmp[0] / 3.3121686421112381E-170;
  b_theta1_tmp = t * t;
  absxk = fabs(theta1_tmp[1]);
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / absxk;
    b_theta1_tmp = b_theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_theta1_tmp += t * t;
  }
  absxk = fabs(theta1_tmp[2]);
  if (absxk > scale) {
    t = scale / absxk;
    b_theta1_tmp = b_theta1_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_theta1_tmp += t * t;
  }
  b_theta1_tmp = scale * sqrt(b_theta1_tmp);
  /*  总的旋转矩阵 ROT */
  r_idx_2 = rt_atan2d_snf(b_theta1_tmp,
                          (UPPmove[0] + 0.0 * UPPmove[1]) + 0.0 * UPPmove[2]);
  s = sin(r_idx_2);
  c = cos(r_idx_2);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  r_idx_2 = theta1_tmp[0] / b_theta1_tmp;
  r_idx_0 = r_idx_2;
  t = r_idx_2 / 3.3121686421112381E-170;
  norm_vec = t * t;
  r_idx_2 = theta1_tmp[1] / b_theta1_tmp;
  r_idx_1 = r_idx_2;
  absxk = fabs(r_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec += t * t;
  }
  r_idx_2 = theta1_tmp[2] / b_theta1_tmp;
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
    UPPmove[1] = r_idx_1 / norm_vec;
    UPPmove[2] = r_idx_2 / norm_vec;
  }
  r_idx_2 = (1.0 - c) * UPPmove[0];
  b_dv[0] = r_idx_2 * UPPmove[0] + c;
  scale = r_idx_2 * UPPmove[1];
  absxk = s * UPPmove[2];
  b_dv[3] = scale - absxk;
  r_idx_2 *= UPPmove[2];
  t = s * UPPmove[1];
  b_dv[6] = r_idx_2 + t;
  b_dv[1] = scale + absxk;
  scale = (1.0 - c) * UPPmove[1];
  b_dv[4] = scale * UPPmove[1] + c;
  scale *= UPPmove[2];
  absxk = s * UPPmove[0];
  b_dv[7] = scale - absxk;
  b_dv[2] = r_idx_2 - t;
  b_dv[5] = scale + absxk;
  b_dv[8] = (1.0 - c) * UPPmove[2] * UPPmove[2] + c;
  /*  计算A点 */
  /*  在PABrot的基础上增量xyz */
  /*  x为b*tan(phi) */
  /*  y为b */
  /*  z为Ti*h */
  for (i = 0; i < 3; i++) {
    r_idx_2 = rot1[i];
    scale = rot1[i + 3];
    absxk = rot1[i + 6];
    for (itilerow = 0; itilerow < 3; itilerow++) {
      ROT[i + 3 * itilerow] =
          (r_idx_2 * b_dv[3 * itilerow] + scale * b_dv[3 * itilerow + 1]) +
          absxk * b_dv[3 * itilerow + 2];
    }
    UPPmove[i] = PAB[i] - Pin[i];
  }
  r_idx_2 = UPPmove[0];
  scale = UPPmove[1];
  absxk = UPPmove[2];
  for (i = 0; i < 3; i++) {
    theta1_tmp[i] = (r_idx_2 * ROT[3 * i] + scale * ROT[3 * i + 1]) +
                    absxk * ROT[3 * i + 2];
  }
  scale = theta1_tmp[0];
  absxk = tan(phi);
  emxInit_real_T(&Ay, 2);
  i = Ay->size[0] * Ay->size[1];
  Ay->size[0] = 1;
  itilerow = (int)shenglunum + (int)shenglunum;
  Ay->size[1] = itilerow;
  emxEnsureCapacity_real_T(Ay, i);
  Ay_data = Ay->data;
  ibmat = (int)shenglunum;
  for (i = 0; i < ibmat; i++) {
    Ay_data[i] = b / 2.0;
  }
  for (i = 0; i < ibmat; i++) {
    Ay_data[i + (int)shenglunum] = -b / 2.0;
  }
  emxInit_real_T(&Az, 2);
  i = Az->size[0] * Az->size[1];
  Az->size[0] = 1;
  Az->size[1] = Ti->size[1];
  emxEnsureCapacity_real_T(Az, i);
  Az_data = Az->data;
  loop_ub = Ti->size[1];
  for (i = 0; i < loop_ub; i++) {
    Az_data[i] = Ti_data[i] * h / 2.0;
  }
  /*  计算并偏移 */
  emxInit_real_T(&Axoff, 2);
  if (itilerow == toff->size[1]) {
    emxInit_real_T(&b_b, 2);
    i = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = itilerow;
    emxEnsureCapacity_real_T(b_b, i);
    PointTable_A_off_data = b_b->data;
    for (i = 0; i < ibmat; i++) {
      PointTable_A_off_data[i] = b / 2.0 * absxk + scale;
    }
    for (i = 0; i < ibmat; i++) {
      PointTable_A_off_data[i + (int)shenglunum] = -b / 2.0 * absxk + scale;
    }
    i = Axoff->size[0] * Axoff->size[1];
    Axoff->size[0] = 1;
    Axoff->size[1] = b_b->size[1];
    emxEnsureCapacity_real_T(Axoff, i);
    Axoff_data = Axoff->data;
    loop_ub = b_b->size[1];
    for (i = 0; i < loop_ub; i++) {
      Axoff_data[i] = PointTable_A_off_data[i] + toff_data[i];
    }
    emxFree_real_T(&b_b);
  } else {
    binary_expand_op_4(Axoff, b, absxk, theta1_tmp[0], shenglunum, toff);
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
  for (loop_ub = 0; loop_ub < 3; loop_ub++) {
    ibmat = loop_ub * i;
    for (itilerow = 0; itilerow < i; itilerow++) {
      r1[ibmat + itilerow] = Pin[loop_ub];
    }
  }
  emxInit_real_T(&b_Axoff, 2);
  i = b_Axoff->size[0] * b_Axoff->size[1];
  b_Axoff->size[0] = 3;
  b_Axoff->size[1] = Axoff->size[1];
  emxEnsureCapacity_real_T(b_Axoff, i);
  PointTable_A_off_data = b_Axoff->data;
  loop_ub = Axoff->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i] = Axoff_data[i];
  }
  loop_ub = Ay->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i + 1] = Ay_data[i];
  }
  loop_ub = Az->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i + 2] = Az_data[i];
  }
  emxInit_real_T(&r2, 2);
  mtimes(b_Axoff, rot1, r2);
  r3 = r2->data;
  if (r2->size[0] == r->size[0]) {
    i = PointTable_A_off->size[0] * PointTable_A_off->size[1];
    PointTable_A_off->size[0] = 3;
    PointTable_A_off->size[1] = r2->size[0];
    emxEnsureCapacity_real_T(PointTable_A_off, i);
    PointTable_A_off_data = PointTable_A_off->data;
    loop_ub = r2->size[0];
    for (i = 0; i < loop_ub; i++) {
      PointTable_A_off_data[3 * i] = r3[i] + r1[i];
      PointTable_A_off_data[3 * i + 1] =
          r3[i + r2->size[0]] + r1[i + r->size[0]];
      PointTable_A_off_data[3 * i + 2] =
          r3[i + r2->size[0] * 2] + r1[i + r->size[0] * 2];
    }
  } else {
    binary_expand_op_2(PointTable_A_off, r2, r);
  }
  i = b_Axoff->size[0] * b_Axoff->size[1];
  b_Axoff->size[0] = 3;
  b_Axoff->size[1] = Axoff->size[1];
  emxEnsureCapacity_real_T(b_Axoff, i);
  PointTable_A_off_data = b_Axoff->data;
  loop_ub = Axoff->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i] = Axoff_data[i];
  }
  emxFree_real_T(&Axoff);
  loop_ub = Ay->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i + 1] = -Ay_data[i];
  }
  emxFree_real_T(&Ay);
  loop_ub = Az->size[1];
  for (i = 0; i < loop_ub; i++) {
    PointTable_A_off_data[3 * i + 2] = Az_data[i];
  }
  emxFree_real_T(&Az);
  mtimes(b_Axoff, rot1, r2);
  r3 = r2->data;
  emxFree_real_T(&b_Axoff);
  if (r2->size[0] == r->size[0]) {
    i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
    PointTable_B_off->size[0] = 3;
    PointTable_B_off->size[1] = r2->size[0];
    emxEnsureCapacity_real_T(PointTable_B_off, i);
    PointTable_A_off_data = PointTable_B_off->data;
    loop_ub = r2->size[0];
    for (i = 0; i < loop_ub; i++) {
      PointTable_A_off_data[3 * i] = r3[i] + r1[i];
      PointTable_A_off_data[3 * i + 1] =
          r3[i + r2->size[0]] + r1[i + r->size[0]];
      PointTable_A_off_data[3 * i + 2] =
          r3[i + r2->size[0] * 2] + r1[i + r->size[0] * 2];
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
