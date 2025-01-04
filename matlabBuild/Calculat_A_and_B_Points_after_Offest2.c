/*
 * File: Calculat_A_and_B_Points_after_Offest2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 23:51:41
 */

/* Include Files */
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_real_T *in1, double in2,
                             const emxArray_real_T *in3);

static void binary_expand_op_1(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4);

static void binary_expand_op_2(emxArray_real_T *in1, const emxArray_real_T *in2,
                               int in3, int in4, int in5, int in6,
                               const emxArray_real_T *in7, int in8, int in9,
                               int in10);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void binary_expand_op(emxArray_real_T *in1, double in2,
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
    in2_data[i] = (in2 - in1_data[i * stride_0_1]) - in3_data[i * stride_1_1];
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
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
static void binary_expand_op_1(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4)
{
  const double *in3_data;
  const double *in4_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_data = in4->data;
  in3_data = in3->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  if (in4->size[1] == 1) {
    loop_ub = in3->size[1];
  } else {
    loop_ub = in4->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in3->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2 + in3_data[i * stride_0_1]) + in4_data[i * stride_1_1];
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                int in3
 *                int in4
 *                int in5
 *                int in6
 *                const emxArray_real_T *in7
 *                int in8
 *                int in9
 *                int in10
 * Return Type  : void
 */
static void binary_expand_op_2(emxArray_real_T *in1, const emxArray_real_T *in2,
                               int in3, int in4, int in5, int in6,
                               const emxArray_real_T *in7, int in8, int in9,
                               int in10)
{
  emxArray_real_T *b_in1;
  emxArray_real_T *b_in7;
  const double *in2_data;
  const double *in7_data;
  double *b_in1_data;
  double *b_in7_data;
  double *in1_data;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_1_1;
  in7_data = in7->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  loop_ub = div_s32(in6 - in4, in5);
  i = in1->size[0] * in1->size[1];
  in1->size[1] = (in3 + loop_ub) + 1;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < in3; i++) {
    in1_data[i] = in2_data[i];
  }
  for (i = 0; i <= loop_ub; i++) {
    in1_data[i + in3] = 3.1415926535897931 - in2_data[in4 + in5 * i];
  }
  emxInit_real_T(&b_in7, 2);
  i = b_in7->size[0] * b_in7->size[1];
  b_in7->size[0] = 1;
  loop_ub = div_s32(in10 - in8, in9);
  b_in7->size[1] = (in7->size[1] + loop_ub) + 1;
  emxEnsureCapacity_real_T(b_in7, i);
  b_in7_data = b_in7->data;
  b_loop_ub = in7->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    b_in7_data[i] = in7_data[i];
  }
  for (i = 0; i <= loop_ub; i++) {
    b_in7_data[i + in7->size[1]] = -in7_data[in8 + in9 * i];
  }
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (b_in7->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = b_in7->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  b_loop_ub = (in1->size[1] != 1);
  stride_1_1 = (b_in7->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * b_loop_ub] + b_in7_data[i * stride_1_1];
  }
  emxFree_real_T(&b_in7);
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
 * 0、编号
 *
 * Arguments    : const double Bottom_round_center1[3]
 *                const double Bottom_round_center2[3]
 *                const double MTaon[3]
 *                const double Mcenter[3]
 *                double Mradial
 *                const double PAB[3]
 *                double phi
 *                const emxArray_real_T *Ang
 *                const emxArray_real_T *toff
 *                const emxArray_real_T *roff
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 *                emxArray_real_T *BianHao
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest2(
    const double Bottom_round_center1[3], const double Bottom_round_center2[3],
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, const emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off,
    emxArray_real_T *BianHao)
{
  emxArray_real_T *AngR;
  emxArray_real_T *PhiDian;
  emxArray_real_T *YuanZhouDian;
  emxArray_real_T *b_rAng;
  emxArray_real_T *disPhiDian;
  emxArray_real_T *rAng;
  const double *Ang_data;
  const double *roff_data;
  const double *toff_data;
  double absxk;
  double d_idx_0;
  double d_idx_0_tmp;
  double d_idx_1;
  double d_idx_1_tmp;
  double d_idx_2;
  double d_idx_2_tmp;
  double e_idx_0;
  double e_idx_1;
  double e_idx_2;
  double scale;
  double t;
  double u_idx_0;
  double u_idx_1;
  double u_idx_2;
  double y;
  double *AngR_data;
  double *BianHao_data;
  double *YuanZhouDian_data;
  double *disPhiDian_data;
  double *rAng_data;
  int BianHao_tmp;
  int b_BianHao_tmp;
  int b_i;
  int b_loop_ub;
  int c_BianHao_tmp;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  int numShengLu;
  (void)MTaon;
  (void)Mcenter;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  roff_data = roff->data;
  toff_data = toff->data;
  Ang_data = Ang->data;
  numShengLu = (int)floor((double)Ang->size[1] / 2.0);
  i = BianHao->size[0] * BianHao->size[1];
  BianHao->size[0] = 2;
  loop_ub = numShengLu << 1;
  BianHao->size[1] = loop_ub;
  emxEnsureCapacity_real_T(BianHao, i);
  BianHao_data = BianHao->data;
  b_loop_ub = numShengLu << 2;
  for (i = 0; i < b_loop_ub; i++) {
    BianHao_data[i] = 0.0;
  }
  for (b_i = 0; b_i < numShengLu; b_i++) {
    BianHao_tmp = 2 * (b_i + 1) - 1;
    BianHao_data[2 * b_i] = BianHao_tmp;
    b_BianHao_tmp = loop_ub - (b_i << 1);
    c_BianHao_tmp = numShengLu + b_i;
    BianHao_data[2 * c_BianHao_tmp] = b_BianHao_tmp;
    BianHao_data[2 * b_i + 1] = BianHao_tmp;
    BianHao_data[2 * c_BianHao_tmp + 1] = b_BianHao_tmp;
  }
  /*  1、基底建立 */
  /*  计算圆柱底面的基底向量，其中第一个基底向量在竖直面内且朝上 */
  /*  输入： */
  /*    x1, y1, z1: 圆柱底面圆心 */
  /*    x2, y2, z2: 圆柱顶面圆心 */
  /*  输出： */
  /*    u, v: 底面的两个正交基向量，其中 u 在竖直平面内 */
  /*  计算轴向向量并归一化 */
  d_idx_0_tmp = Bottom_round_center2[0] - Bottom_round_center1[0];
  d_idx_1_tmp = Bottom_round_center2[1] - Bottom_round_center1[1];
  d_idx_2_tmp = Bottom_round_center2[2] - Bottom_round_center1[2];
  scale = 3.3121686421112381E-170;
  absxk = fabs(d_idx_0_tmp);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(d_idx_1_tmp);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(d_idx_2_tmp);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  d_idx_0 = d_idx_0_tmp / y;
  d_idx_1 = d_idx_1_tmp / y;
  d_idx_2 = d_idx_2_tmp / y;
  /*  选择竖直平面内的向量 e */
  if (fabs(d_idx_0) > fabs(d_idx_1)) {
    /*  如果轴向向量大致沿 X 轴 */
    e_idx_0 = 0.0;
    e_idx_1 = 1.0;
    /*  选择 y 方向的单位向量 */
  } else {
    /*  否则，如果轴向向量大致沿 Y 轴 */
    e_idx_0 = 1.0;
    e_idx_1 = 0.0;
    /*  选择 x 方向的单位向量 */
  }
  /*  计算第一个基向量 u，使其位于竖直面内 */
  u_idx_0 = d_idx_1 * 0.0 - e_idx_1 * d_idx_2;
  u_idx_1 = e_idx_0 * d_idx_2 - d_idx_0 * 0.0;
  u_idx_2 = d_idx_0 * e_idx_1 - e_idx_0 * d_idx_1;
  /*  计算与 d 和 e 正交的向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(u_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(u_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(u_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  u_idx_0 /= y;
  u_idx_1 /= y;
  u_idx_2 /= y;
  /*  归一化 */
  /*  确保 u 的方向朝上 */
  if (u_idx_2 <= 0.0) {
    u_idx_0 = -u_idx_0;
    u_idx_1 = -u_idx_1;
    u_idx_2 = -u_idx_2;
    /*  如果 u 的方向与轴方向相反，反转 u */
  }
  /*  计算第二个基向量 v，使其与 d 和 u 正交 */
  e_idx_0 = d_idx_1 * u_idx_2 - u_idx_1 * d_idx_2;
  e_idx_1 = u_idx_0 * d_idx_2 - d_idx_0 * u_idx_2;
  e_idx_2 = d_idx_0 * u_idx_1 - u_idx_0 * d_idx_1;
  /*  计算第二个正交向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(e_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(e_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(e_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  e_idx_0 = -e_idx_0 / y;
  e_idx_1 = -e_idx_1 / y;
  e_idx_2 = -e_idx_2 / y;
  /*  归一化 */
  /*  2、计算角度 */
  /*  角度处理 */
  if (numShengLu < 1) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = numShengLu - 1;
    i1 = -1;
    i2 = 0;
  }
  /*  角度偏移 */
  emxInit_real_T(&rAng, 2);
  i3 = rAng->size[0] * rAng->size[1];
  rAng->size[0] = 1;
  rAng->size[1] = numShengLu;
  emxEnsureCapacity_real_T(rAng, i3);
  rAng_data = rAng->data;
  for (i3 = 0; i3 < numShengLu; i3++) {
    rAng_data[i3] = roff_data[i3] / Mradial;
  }
  if (rAng->size[1] < 1) {
    i3 = 0;
    BianHao_tmp = 1;
    b_BianHao_tmp = -1;
  } else {
    i3 = rAng->size[1] - 1;
    BianHao_tmp = -1;
    b_BianHao_tmp = 0;
  }
  b_loop_ub = div_s32(i2 - i, i1);
  c_BianHao_tmp = (numShengLu + b_loop_ub) + 1;
  b_i = div_s32(b_BianHao_tmp - i3, BianHao_tmp);
  i4 = (rAng->size[1] + b_i) + 1;
  emxInit_real_T(&AngR, 2);
  emxInit_real_T(&disPhiDian, 2);
  if (c_BianHao_tmp == i4) {
    i2 = disPhiDian->size[0] * disPhiDian->size[1];
    disPhiDian->size[0] = 1;
    disPhiDian->size[1] = c_BianHao_tmp;
    emxEnsureCapacity_real_T(disPhiDian, i2);
    disPhiDian_data = disPhiDian->data;
    for (i2 = 0; i2 < numShengLu; i2++) {
      disPhiDian_data[i2] = Ang_data[i2];
    }
    for (i2 = 0; i2 <= b_loop_ub; i2++) {
      disPhiDian_data[i2 + numShengLu] =
          3.1415926535897931 - Ang_data[i + i1 * i2];
    }
    emxInit_real_T(&b_rAng, 2);
    i = b_rAng->size[0] * b_rAng->size[1];
    b_rAng->size[0] = 1;
    b_rAng->size[1] = i4;
    emxEnsureCapacity_real_T(b_rAng, i);
    BianHao_data = b_rAng->data;
    b_loop_ub = rAng->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      BianHao_data[i] = rAng_data[i];
    }
    for (i = 0; i <= b_i; i++) {
      BianHao_data[i + rAng->size[1]] = -rAng_data[i3 + BianHao_tmp * i];
    }
    i = AngR->size[0] * AngR->size[1];
    AngR->size[0] = 1;
    AngR->size[1] = disPhiDian->size[1];
    emxEnsureCapacity_real_T(AngR, i);
    AngR_data = AngR->data;
    b_loop_ub = disPhiDian->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      AngR_data[i] = disPhiDian_data[i] + BianHao_data[i];
    }
    emxFree_real_T(&b_rAng);
  } else {
    binary_expand_op_2(AngR, Ang, numShengLu, i, i1, i2, rAng, i3, BianHao_tmp,
                       b_BianHao_tmp);
    AngR_data = AngR->data;
  }
  /*  3、生成圆周点 */
  emxInit_real_T(&YuanZhouDian, 2);
  i = YuanZhouDian->size[0] * YuanZhouDian->size[1];
  YuanZhouDian->size[0] = 3;
  YuanZhouDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(YuanZhouDian, i);
  YuanZhouDian_data = YuanZhouDian->data;
  BianHao_tmp = 3 * loop_ub;
  for (i = 0; i < BianHao_tmp; i++) {
    YuanZhouDian_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = AngR_data[b_i];
    y = sin(scale);
    scale = cos(scale);
    YuanZhouDian_data[3 * b_i] =
        (Bottom_round_center2[0] + u_idx_0 * Mradial * y) +
        e_idx_0 * Mradial * scale;
    YuanZhouDian_data[3 * b_i + 1] =
        (Bottom_round_center2[1] + u_idx_1 * Mradial * y) +
        e_idx_1 * Mradial * scale;
    YuanZhouDian_data[3 * b_i + 2] =
        (Bottom_round_center2[2] + u_idx_2 * Mradial * y) +
        e_idx_2 * Mradial * scale;
  }
  /*  4、计算轴向移动 */
  /*  总体移动 */
  /*  三个点定义 */
  /*  斜率计算 */
  scale = -(((Bottom_round_center1[0] - PAB[0]) * d_idx_0_tmp +
             (Bottom_round_center1[1] - PAB[1]) * d_idx_1_tmp) +
            (Bottom_round_center1[2] - PAB[2]) * d_idx_2_tmp) /
          ((d_idx_0_tmp * d_idx_0_tmp + d_idx_1_tmp * d_idx_1_tmp) +
           d_idx_2_tmp * d_idx_2_tmp);
  /*  P1点在轴线上的投影坐标 */
  t = (scale * d_idx_2_tmp + Bottom_round_center1[2]) - Bottom_round_center2[2];
  y = (scale * d_idx_1_tmp + Bottom_round_center1[1]) - Bottom_round_center2[1];
  scale =
      (scale * d_idx_0_tmp + Bottom_round_center1[0]) - Bottom_round_center2[0];
  absxk = sqrt((t * t + y * y) + scale * scale);
  /*  phi角移动 */
  emxInit_real_T(&PhiDian, 2);
  i = PhiDian->size[0] * PhiDian->size[1];
  PhiDian->size[0] = 3;
  PhiDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PhiDian, i);
  rAng_data = PhiDian->data;
  for (i = 0; i < BianHao_tmp; i++) {
    rAng_data[i] = 0.0;
  }
  i = disPhiDian->size[0] * disPhiDian->size[1];
  disPhiDian->size[0] = 1;
  disPhiDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(disPhiDian, i);
  disPhiDian_data = disPhiDian->data;
  for (i = 0; i < loop_ub; i++) {
    disPhiDian_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = cos(AngR_data[b_i]);
    rAng_data[3 * b_i] = e_idx_0 * Mradial * scale;
    i = 3 * b_i + 1;
    rAng_data[i] = e_idx_1 * Mradial * scale;
    i1 = 3 * b_i + 2;
    rAng_data[i1] = e_idx_2 * Mradial * scale;
    if (b_i + 1 <= numShengLu) {
      t = rAng_data[3 * b_i];
      y = rAng_data[i];
      scale = rAng_data[i1];
      disPhiDian_data[b_i] = -sqrt((t * t + y * y) + scale * scale) * cos(phi);
    } else {
      t = rAng_data[3 * b_i];
      y = rAng_data[i];
      scale = rAng_data[i1];
      disPhiDian_data[b_i] = sqrt((t * t + y * y) + scale * scale) * cos(phi);
    }
  }
  /*  偏移移动 ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
  if (numShengLu < 1) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = numShengLu - 1;
    i1 = -1;
    i2 = 0;
  }
  i3 = rAng->size[0] * rAng->size[1];
  rAng->size[0] = 1;
  b_loop_ub = div_s32(i2 - i, i1);
  rAng->size[1] = (numShengLu + b_loop_ub) + 1;
  emxEnsureCapacity_real_T(rAng, i3);
  rAng_data = rAng->data;
  for (i2 = 0; i2 < numShengLu; i2++) {
    rAng_data[i2] = toff_data[i2];
  }
  for (i2 = 0; i2 <= b_loop_ub; i2++) {
    rAng_data[i2 + numShengLu] = -toff_data[i + i1 * i2];
  }
  i = PointTable_A_off->size[0] * PointTable_A_off->size[1];
  PointTable_A_off->size[0] = 3;
  PointTable_A_off->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_A_off, i);
  BianHao_data = PointTable_A_off->data;
  for (i = 0; i < BianHao_tmp; i++) {
    BianHao_data[i] = 0.0;
  }
  if (disPhiDian->size[1] == rAng->size[1]) {
    i = AngR->size[0] * AngR->size[1];
    AngR->size[0] = 1;
    AngR->size[1] = disPhiDian->size[1];
    emxEnsureCapacity_real_T(AngR, i);
    AngR_data = AngR->data;
    b_loop_ub = disPhiDian->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      AngR_data[i] = (absxk + disPhiDian_data[i]) + rAng_data[i];
    }
  } else {
    binary_expand_op_1(AngR, absxk, disPhiDian, rAng);
    AngR_data = AngR->data;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = AngR_data[b_i];
    BianHao_data[3 * b_i] = YuanZhouDian_data[3 * b_i] - d_idx_0 * scale;
    i = 3 * b_i + 1;
    BianHao_data[i] = YuanZhouDian_data[i] - d_idx_1 * scale;
    i = 3 * b_i + 2;
    BianHao_data[i] = YuanZhouDian_data[i] - d_idx_2 * scale;
  }
  emxFree_real_T(&AngR);
  i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_B_off, i);
  BianHao_data = PointTable_B_off->data;
  for (i = 0; i < BianHao_tmp; i++) {
    BianHao_data[i] = 0.0;
  }
  if (disPhiDian->size[1] == rAng->size[1]) {
    b_loop_ub = disPhiDian->size[1] - 1;
    i = disPhiDian->size[0] * disPhiDian->size[1];
    disPhiDian->size[0] = 1;
    emxEnsureCapacity_real_T(disPhiDian, i);
    disPhiDian_data = disPhiDian->data;
    for (i = 0; i <= b_loop_ub; i++) {
      disPhiDian_data[i] = (absxk - disPhiDian_data[i]) - rAng_data[i];
    }
  } else {
    binary_expand_op(disPhiDian, absxk, rAng);
    disPhiDian_data = disPhiDian->data;
  }
  emxFree_real_T(&rAng);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = disPhiDian_data[b_i];
    BianHao_data[3 * b_i] = YuanZhouDian_data[3 * b_i] - d_idx_0 * scale;
    i = 3 * b_i + 1;
    BianHao_data[i] = YuanZhouDian_data[i] - d_idx_1 * scale;
    i = 3 * b_i + 2;
    BianHao_data[i] = YuanZhouDian_data[i] - d_idx_2 * scale;
  }
  emxFree_real_T(&disPhiDian);
  emxFree_real_T(&YuanZhouDian);
  if (PointTable_B_off->size[1] < 1) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = PointTable_B_off->size[1] - 1;
    i1 = -1;
    i2 = 0;
  }
  i3 = PhiDian->size[0] * PhiDian->size[1];
  PhiDian->size[0] = 3;
  loop_ub = div_s32(i2 - i, i1);
  PhiDian->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(PhiDian, i3);
  rAng_data = PhiDian->data;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    BianHao_tmp = i + i1 * i2;
    rAng_data[3 * i2] = BianHao_data[3 * BianHao_tmp];
    rAng_data[3 * i2 + 1] = BianHao_data[3 * BianHao_tmp + 1];
    rAng_data[3 * i2 + 2] = BianHao_data[3 * BianHao_tmp + 2];
  }
  i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = PhiDian->size[1];
  emxEnsureCapacity_real_T(PointTable_B_off, i);
  BianHao_data = PointTable_B_off->data;
  loop_ub = 3 * PhiDian->size[1];
  for (i = 0; i < loop_ub; i++) {
    BianHao_data[i] = rAng_data[i];
  }
  emxFree_real_T(&PhiDian);
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.c
 *
 * [EOF]
 */
