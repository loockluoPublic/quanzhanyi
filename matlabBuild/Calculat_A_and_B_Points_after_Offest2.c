/*
 * File: Calculat_A_and_B_Points_after_Offest2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 18:24:20
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
 *                emxArray_real_T *PointTable_A_off2
 *                emxArray_real_T *PointTable_B_off2
 *                emxArray_real_T *BianHao
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest2(
    const double Bottom_round_center1[3], const double Bottom_round_center2[3],
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, const emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    emxArray_real_T *PointTable_A_off2, emxArray_real_T *PointTable_B_off2,
    emxArray_real_T *BianHao)
{
  emxArray_real_T *AngR1;
  emxArray_real_T *PYallA;
  emxArray_real_T *PhiDian;
  emxArray_real_T *PointTable_B_off;
  emxArray_real_T *YuanZhouDian;
  emxArray_real_T *disPhiDian;
  double R_tmp[9];
  const double *Ang_data;
  const double *roff_data;
  const double *toff_data;
  double absxk;
  double absxk_tmp;
  double b;
  double b_absxk_tmp;
  double c_absxk_tmp;
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
  double *AngR1_data;
  double *BianHao_data;
  double *PYallA_data;
  double *PhiDian_data;
  double *PointTable_B_off_data;
  double *YuanZhouDian_data;
  int BianHao_tmp;
  int b_BianHao_tmp;
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
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
    b_loop_ub = loop_ub - (b_i << 1);
    b_BianHao_tmp = numShengLu + b_i;
    BianHao_data[2 * b_BianHao_tmp] = b_loop_ub;
    BianHao_data[2 * b_i + 1] = BianHao_tmp;
    BianHao_data[2 * b_BianHao_tmp + 1] = b_loop_ub;
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
  absxk_tmp = fabs(d_idx_0_tmp);
  if (absxk_tmp > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / 3.3121686421112381E-170;
    y = t * t;
  }
  b_absxk_tmp = fabs(d_idx_1_tmp);
  if (b_absxk_tmp > scale) {
    t = scale / b_absxk_tmp;
    y = y * t * t + 1.0;
    scale = b_absxk_tmp;
  } else {
    t = b_absxk_tmp / scale;
    y += t * t;
  }
  c_absxk_tmp = fabs(d_idx_2_tmp);
  if (c_absxk_tmp > scale) {
    t = scale / c_absxk_tmp;
    y = y * t * t + 1.0;
    scale = c_absxk_tmp;
  } else {
    t = c_absxk_tmp / scale;
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
    b_i = -1;
  } else {
    i = numShengLu - 1;
    i1 = -1;
    b_i = 0;
  }
  emxInit_real_T(&AngR1, 2);
  BianHao_tmp = AngR1->size[0] * AngR1->size[1];
  AngR1->size[0] = 1;
  b_loop_ub = div_s32(b_i - i, i1);
  AngR1->size[1] = (numShengLu + b_loop_ub) + 1;
  emxEnsureCapacity_real_T(AngR1, BianHao_tmp);
  AngR1_data = AngR1->data;
  for (b_i = 0; b_i < numShengLu; b_i++) {
    AngR1_data[b_i] = Ang_data[b_i];
  }
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    AngR1_data[b_i + numShengLu] = 3.1415926535897931 - Ang_data[i + i1 * b_i];
  }
  /*  % 角度偏移 */
  /*   */
  /*  rAng = roff(1:numShengLu)./Mradial; */
  /*  roffAng = [rAng,-rAng(end:-1:1)]; */
  /*  3、生成圆周点 */
  emxInit_real_T(&YuanZhouDian, 2);
  i = YuanZhouDian->size[0] * YuanZhouDian->size[1];
  YuanZhouDian->size[0] = 3;
  YuanZhouDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(YuanZhouDian, i);
  YuanZhouDian_data = YuanZhouDian->data;
  b_BianHao_tmp = 3 * loop_ub;
  for (i = 0; i < b_BianHao_tmp; i++) {
    YuanZhouDian_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = AngR1_data[b_i];
    b = sin(scale);
    scale = cos(scale);
    YuanZhouDian_data[3 * b_i] =
        (Bottom_round_center2[0] + u_idx_0 * Mradial * b) +
        e_idx_0 * Mradial * scale;
    YuanZhouDian_data[3 * b_i + 1] =
        (Bottom_round_center2[1] + u_idx_1 * Mradial * b) +
        e_idx_1 * Mradial * scale;
    YuanZhouDian_data[3 * b_i + 2] =
        (Bottom_round_center2[2] + u_idx_2 * Mradial * b) +
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
  b = (scale * d_idx_0_tmp + Bottom_round_center1[0]) - Bottom_round_center2[0];
  u_idx_0 = sqrt((t * t + y * y) + b * b);
  /*  phi角移动 */
  emxInit_real_T(&PhiDian, 2);
  i = PhiDian->size[0] * PhiDian->size[1];
  PhiDian->size[0] = 3;
  PhiDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PhiDian, i);
  PhiDian_data = PhiDian->data;
  for (i = 0; i < b_BianHao_tmp; i++) {
    PhiDian_data[i] = 0.0;
  }
  emxInit_real_T(&disPhiDian, 2);
  i = disPhiDian->size[0] * disPhiDian->size[1];
  disPhiDian->size[0] = 1;
  disPhiDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(disPhiDian, i);
  BianHao_data = disPhiDian->data;
  for (i = 0; i < loop_ub; i++) {
    BianHao_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    scale = cos(AngR1_data[b_i]);
    PhiDian_data[3 * b_i] = e_idx_0 * Mradial * scale;
    i = 3 * b_i + 1;
    PhiDian_data[i] = e_idx_1 * Mradial * scale;
    i1 = 3 * b_i + 2;
    PhiDian_data[i1] = e_idx_2 * Mradial * scale;
    if (b_i + 1 <= numShengLu) {
      scale = 3.3121686421112381E-170;
      absxk = fabs(PhiDian_data[3 * b_i]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      absxk = fabs(PhiDian_data[i]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      absxk = fabs(PhiDian_data[i1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      y = scale * sqrt(y);
      BianHao_data[b_i] = -y / tan(phi);
    } else {
      scale = 3.3121686421112381E-170;
      absxk = fabs(PhiDian_data[3 * b_i]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      absxk = fabs(PhiDian_data[i]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      absxk = fabs(PhiDian_data[i1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      y = scale * sqrt(y);
      BianHao_data[b_i] = y / tan(phi);
    }
  }
  /*  偏移移动 ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
  if (numShengLu < 1) {
    i = 0;
    i1 = 1;
    b_i = -1;
  } else {
    i = numShengLu - 1;
    i1 = -1;
    b_i = 0;
  }
  BianHao_tmp = AngR1->size[0] * AngR1->size[1];
  AngR1->size[0] = 1;
  b_loop_ub = div_s32(b_i - i, i1);
  AngR1->size[1] = (numShengLu + b_loop_ub) + 1;
  emxEnsureCapacity_real_T(AngR1, BianHao_tmp);
  AngR1_data = AngR1->data;
  for (b_i = 0; b_i < numShengLu; b_i++) {
    AngR1_data[b_i] = toff_data[b_i];
  }
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    AngR1_data[b_i + numShengLu] = -toff_data[i + i1 * b_i];
  }
  i = PhiDian->size[0] * PhiDian->size[1];
  PhiDian->size[0] = 3;
  PhiDian->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PhiDian, i);
  PhiDian_data = PhiDian->data;
  for (i = 0; i < b_BianHao_tmp; i++) {
    PhiDian_data[i] = 0.0;
  }
  emxInit_real_T(&PYallA, 2);
  if (disPhiDian->size[1] == AngR1->size[1]) {
    i = PYallA->size[0] * PYallA->size[1];
    PYallA->size[0] = 1;
    PYallA->size[1] = disPhiDian->size[1];
    emxEnsureCapacity_real_T(PYallA, i);
    PYallA_data = PYallA->data;
    b_loop_ub = disPhiDian->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      PYallA_data[i] = (u_idx_0 + BianHao_data[i]) + AngR1_data[i];
    }
  } else {
    binary_expand_op_1(PYallA, u_idx_0, disPhiDian, AngR1);
    PYallA_data = PYallA->data;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    t = PYallA_data[b_i];
    PhiDian_data[3 * b_i] = YuanZhouDian_data[3 * b_i] - d_idx_0 * t;
    i = 3 * b_i + 1;
    PhiDian_data[i] = YuanZhouDian_data[i] - d_idx_1 * t;
    i = 3 * b_i + 2;
    PhiDian_data[i] = YuanZhouDian_data[i] - d_idx_2 * t;
  }
  emxInit_real_T(&PointTable_B_off, 2);
  i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_B_off, i);
  PointTable_B_off_data = PointTable_B_off->data;
  for (i = 0; i < b_BianHao_tmp; i++) {
    PointTable_B_off_data[i] = 0.0;
  }
  if (disPhiDian->size[1] == AngR1->size[1]) {
    b_loop_ub = disPhiDian->size[1] - 1;
    i = disPhiDian->size[0] * disPhiDian->size[1];
    disPhiDian->size[0] = 1;
    emxEnsureCapacity_real_T(disPhiDian, i);
    BianHao_data = disPhiDian->data;
    for (i = 0; i <= b_loop_ub; i++) {
      BianHao_data[i] = (u_idx_0 - BianHao_data[i]) - AngR1_data[i];
    }
  } else {
    binary_expand_op(disPhiDian, u_idx_0, AngR1);
    BianHao_data = disPhiDian->data;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b = BianHao_data[b_i];
    PointTable_B_off_data[3 * b_i] = YuanZhouDian_data[3 * b_i] - d_idx_0 * b;
    i = 3 * b_i + 1;
    PointTable_B_off_data[i] = YuanZhouDian_data[i] - d_idx_1 * b;
    i = 3 * b_i + 2;
    PointTable_B_off_data[i] = YuanZhouDian_data[i] - d_idx_2 * b;
  }
  emxFree_real_T(&disPhiDian);
  /*  5、径向偏移 */
  /*  角度偏移 */
  i = AngR1->size[0] * AngR1->size[1];
  AngR1->size[0] = 1;
  AngR1->size[1] = numShengLu;
  emxEnsureCapacity_real_T(AngR1, i);
  AngR1_data = AngR1->data;
  for (i = 0; i < numShengLu; i++) {
    AngR1_data[i] = roff_data[i] / Mradial;
  }
  if (AngR1->size[1] < 1) {
    i = 0;
    i1 = 1;
    b_i = -1;
  } else {
    i = AngR1->size[1] - 1;
    i1 = -1;
    b_i = 0;
  }
  BianHao_tmp = PYallA->size[0] * PYallA->size[1];
  PYallA->size[0] = 1;
  b_loop_ub = div_s32(b_i - i, i1);
  PYallA->size[1] = (AngR1->size[1] + b_loop_ub) + 1;
  emxEnsureCapacity_real_T(PYallA, BianHao_tmp);
  PYallA_data = PYallA->data;
  BianHao_tmp = AngR1->size[1];
  for (b_i = 0; b_i < BianHao_tmp; b_i++) {
    PYallA_data[b_i] = AngR1_data[b_i];
  }
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    PYallA_data[b_i + AngR1->size[1]] = -AngR1_data[i + i1 * b_i];
  }
  emxFree_real_T(&AngR1);
  i = PointTable_A_off2->size[0] * PointTable_A_off2->size[1];
  PointTable_A_off2->size[0] = 3;
  PointTable_A_off2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_A_off2, i);
  BianHao_data = PointTable_A_off2->data;
  for (i = 0; i < b_BianHao_tmp; i++) {
    BianHao_data[i] = 0.0;
  }
  i = PhiDian->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    /*  旋转轴方向向量 */
    scale = 3.3121686421112381E-170;
    if (absxk_tmp > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk_tmp;
    } else {
      t = absxk_tmp / 3.3121686421112381E-170;
      y = t * t;
    }
    if (b_absxk_tmp > scale) {
      t = scale / b_absxk_tmp;
      y = y * t * t + 1.0;
      scale = b_absxk_tmp;
    } else {
      t = b_absxk_tmp / scale;
      y += t * t;
    }
    if (c_absxk_tmp > scale) {
      t = scale / c_absxk_tmp;
      y = y * t * t + 1.0;
      scale = c_absxk_tmp;
    } else {
      t = c_absxk_tmp / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    e_idx_0 = d_idx_0_tmp / y;
    e_idx_1 = d_idx_1_tmp / y;
    e_idx_2 = d_idx_2_tmp / y;
    /*  归一化为单位向量 */
    /*  旋转矩阵 */
    scale = PYallA_data[b_i];
    absxk = cos(scale);
    t = sin(scale);
    /*  计算旋转后的点 */
    R_tmp[0] = absxk + e_idx_0 * e_idx_0 * (1.0 - absxk);
    scale = e_idx_0 * e_idx_1 * (1.0 - absxk);
    b = e_idx_2 * t;
    R_tmp[3] = scale - b;
    y = e_idx_0 * e_idx_2 * (1.0 - absxk);
    u_idx_0 = e_idx_1 * t;
    R_tmp[6] = y + u_idx_0;
    R_tmp[1] = scale + b;
    R_tmp[4] = absxk + e_idx_1 * e_idx_1 * (1.0 - absxk);
    scale = e_idx_1 * e_idx_2 * (1.0 - absxk);
    b = e_idx_0 * t;
    R_tmp[7] = scale - b;
    R_tmp[2] = y - u_idx_0;
    R_tmp[5] = scale + b;
    R_tmp[8] = absxk + e_idx_2 * e_idx_2 * (1.0 - absxk);
    b = PhiDian_data[3 * b_i] - Bottom_round_center1[0];
    t = PhiDian_data[3 * b_i + 1] - Bottom_round_center1[1];
    scale = PhiDian_data[3 * b_i + 2] - Bottom_round_center1[2];
    for (i1 = 0; i1 < 3; i1++) {
      BianHao_data[i1 + 3 * b_i] =
          ((R_tmp[i1] * b + R_tmp[i1 + 3] * t) + R_tmp[i1 + 6] * scale) +
          Bottom_round_center1[i1];
    }
    /*  减去P1，然后旋转，再加回P1 */
  }
  emxFree_real_T(&PhiDian);
  i = PointTable_B_off2->size[0] * PointTable_B_off2->size[1];
  PointTable_B_off2->size[0] = 3;
  PointTable_B_off2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_B_off2, i);
  BianHao_data = PointTable_B_off2->data;
  for (i = 0; i < b_BianHao_tmp; i++) {
    BianHao_data[i] = 0.0;
  }
  i = PointTable_B_off->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    /*  旋转轴方向向量 */
    scale = 3.3121686421112381E-170;
    if (absxk_tmp > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk_tmp;
    } else {
      t = absxk_tmp / 3.3121686421112381E-170;
      y = t * t;
    }
    if (b_absxk_tmp > scale) {
      t = scale / b_absxk_tmp;
      y = y * t * t + 1.0;
      scale = b_absxk_tmp;
    } else {
      t = b_absxk_tmp / scale;
      y += t * t;
    }
    if (c_absxk_tmp > scale) {
      t = scale / c_absxk_tmp;
      y = y * t * t + 1.0;
      scale = c_absxk_tmp;
    } else {
      t = c_absxk_tmp / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    e_idx_0 = d_idx_0_tmp / y;
    e_idx_1 = d_idx_1_tmp / y;
    e_idx_2 = d_idx_2_tmp / y;
    /*  归一化为单位向量 */
    /*  旋转矩阵 */
    scale = PYallA_data[b_i];
    absxk = cos(scale);
    t = sin(scale);
    /*  计算旋转后的点 */
    R_tmp[0] = absxk + e_idx_0 * e_idx_0 * (1.0 - absxk);
    scale = e_idx_0 * e_idx_1 * (1.0 - absxk);
    b = e_idx_2 * t;
    R_tmp[3] = scale - b;
    y = e_idx_0 * e_idx_2 * (1.0 - absxk);
    u_idx_0 = e_idx_1 * t;
    R_tmp[6] = y + u_idx_0;
    R_tmp[1] = scale + b;
    R_tmp[4] = absxk + e_idx_1 * e_idx_1 * (1.0 - absxk);
    scale = e_idx_1 * e_idx_2 * (1.0 - absxk);
    b = e_idx_0 * t;
    R_tmp[7] = scale - b;
    R_tmp[2] = y - u_idx_0;
    R_tmp[5] = scale + b;
    R_tmp[8] = absxk + e_idx_2 * e_idx_2 * (1.0 - absxk);
    b = PointTable_B_off_data[3 * b_i] - Bottom_round_center1[0];
    t = PointTable_B_off_data[3 * b_i + 1] - Bottom_round_center1[1];
    scale = PointTable_B_off_data[3 * b_i + 2] - Bottom_round_center1[2];
    for (i1 = 0; i1 < 3; i1++) {
      BianHao_data[i1 + 3 * b_i] =
          ((R_tmp[i1] * b + R_tmp[i1 + 3] * t) + R_tmp[i1 + 6] * scale) +
          Bottom_round_center1[i1];
    }
    /*  减去P1，然后旋转，再加回P1 */
  }
  emxFree_real_T(&PointTable_B_off);
  emxFree_real_T(&PYallA);
  if (PointTable_B_off2->size[1] < 1) {
    i = 0;
    i1 = 1;
    b_i = -1;
  } else {
    i = PointTable_B_off2->size[1] - 1;
    i1 = -1;
    b_i = 0;
  }
  BianHao_tmp = YuanZhouDian->size[0] * YuanZhouDian->size[1];
  YuanZhouDian->size[0] = 3;
  loop_ub = div_s32(b_i - i, i1);
  YuanZhouDian->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(YuanZhouDian, BianHao_tmp);
  YuanZhouDian_data = YuanZhouDian->data;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    BianHao_tmp = i + i1 * b_i;
    YuanZhouDian_data[3 * b_i] = BianHao_data[3 * BianHao_tmp];
    YuanZhouDian_data[3 * b_i + 1] = BianHao_data[3 * BianHao_tmp + 1];
    YuanZhouDian_data[3 * b_i + 2] = BianHao_data[3 * BianHao_tmp + 2];
  }
  i = PointTable_B_off2->size[0] * PointTable_B_off2->size[1];
  PointTable_B_off2->size[0] = 3;
  PointTable_B_off2->size[1] = YuanZhouDian->size[1];
  emxEnsureCapacity_real_T(PointTable_B_off2, i);
  BianHao_data = PointTable_B_off2->data;
  loop_ub = 3 * YuanZhouDian->size[1];
  for (i = 0; i < loop_ub; i++) {
    BianHao_data[i] = YuanZhouDian_data[i];
  }
  emxFree_real_T(&YuanZhouDian);
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.c
 *
 * [EOF]
 */
