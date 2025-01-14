/*
 * File: Calculate_rectangle_from_vertex8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 14-Jan-2025 20:59:01
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex8.h"
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "dot.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "norm.h"
#include "planefit4.h"
#include "planefit8.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_10(emxArray_real_T *in1, int in2, double in4,
                                const emxArray_real_T *in5, int in6, int in7,
                                const emxArray_real_T *in8, int in9, int in10,
                                double in11);

static void binary_expand_op_12(emxArray_real_T *in1, int in2, double in4,
                                const emxArray_real_T *in5, int in6, int in7,
                                const emxArray_real_T *in8, int in9, int in10,
                                double in11);

static void binary_expand_op_13(emxArray_real_T *in1, const double in2[3],
                                const emxArray_real_T *in3);

static void binary_expand_op_14(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                int in2
 *                double in4
 *                const emxArray_real_T *in5
 *                int in6
 *                int in7
 *                const emxArray_real_T *in8
 *                int in9
 *                int in10
 *                double in11
 * Return Type  : void
 */
static void binary_expand_op_10(emxArray_real_T *in1, int in2, double in4,
                                const emxArray_real_T *in5, int in6, int in7,
                                const emxArray_real_T *in8, int in9, int in10,
                                double in11)
{
  const double *in5_data;
  const double *in8_data;
  double *in1_data;
  int stride_0_1;
  int stride_0_1_tmp;
  int stride_1_1;
  int stride_1_1_tmp;
  in8_data = in8->data;
  in5_data = in5->data;
  in1_data = in1->data;
  stride_0_1_tmp = (in7 - in6) + 1;
  stride_0_1 = (stride_0_1_tmp != 1);
  stride_1_1_tmp = (in10 - in9) + 1;
  stride_1_1 = (stride_1_1_tmp != 1);
  if (stride_1_1_tmp != 1) {
    stride_0_1_tmp = stride_1_1_tmp;
  }
  for (stride_1_1_tmp = 0; stride_1_1_tmp < stride_0_1_tmp; stride_1_1_tmp++) {
    in1_data[in2 + stride_1_1_tmp] =
        (in4 - in5_data[in6 + stride_1_1_tmp * stride_0_1]) +
        in8_data[in9 + stride_1_1_tmp * stride_1_1] / in11;
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                int in2
 *                double in4
 *                const emxArray_real_T *in5
 *                int in6
 *                int in7
 *                const emxArray_real_T *in8
 *                int in9
 *                int in10
 *                double in11
 * Return Type  : void
 */
static void binary_expand_op_12(emxArray_real_T *in1, int in2, double in4,
                                const emxArray_real_T *in5, int in6, int in7,
                                const emxArray_real_T *in8, int in9, int in10,
                                double in11)
{
  const double *in5_data;
  const double *in8_data;
  double *in1_data;
  int stride_0_1;
  int stride_0_1_tmp;
  int stride_1_1;
  int stride_1_1_tmp;
  in8_data = in8->data;
  in5_data = in5->data;
  in1_data = in1->data;
  stride_0_1_tmp = (in7 - in6) + 1;
  stride_0_1 = (stride_0_1_tmp != 1);
  stride_1_1_tmp = (in10 - in9) + 1;
  stride_1_1 = (stride_1_1_tmp != 1);
  if (stride_1_1_tmp != 1) {
    stride_0_1_tmp = stride_1_1_tmp;
  }
  for (stride_1_1_tmp = 0; stride_1_1_tmp < stride_0_1_tmp; stride_1_1_tmp++) {
    in1_data[in2 + stride_1_1_tmp] =
        (in4 + in5_data[in6 + stride_1_1_tmp * stride_0_1]) -
        in8_data[in9 + stride_1_1_tmp * stride_1_1] / in11;
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const double in2[3]
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void binary_expand_op_13(emxArray_real_T *in1, const double in2[3],
                                const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_2_1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_2_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 3;
  if (in3->size[1] == 1) {
    stride_0_1 = 1;
  } else {
    stride_0_1 = in3->size[1];
  }
  if (stride_0_1 == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = stride_0_1;
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_2_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[3 * i] = in1_data[3 * aux_0_1] - in2[0] * in3_data[aux_2_1];
    b_in1_data[3 * i + 1] =
        in1_data[3 * aux_0_1 + 1] - in2[1] * in3_data[aux_2_1];
    b_in1_data[3 * i + 2] =
        in1_data[3 * aux_0_1 + 2] - in2[2] * in3_data[aux_2_1];
    aux_2_1 += stride_2_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 3;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[3 * i] = b_in1_data[3 * i];
    stride_0_1 = 3 * i + 1;
    in1_data[stride_0_1] = b_in1_data[stride_0_1];
    stride_0_1 = 3 * i + 2;
    in1_data[stride_0_1] = b_in1_data[stride_0_1];
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const double in3[3]
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
static void binary_expand_op_14(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4)
{
  const double *in2_data;
  const double *in4_data;
  double *in1_data;
  int aux_0_1;
  int aux_2_1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_2_1;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 3;
  emxEnsureCapacity_real_T(in1, i);
  if (in4->size[1] == 1) {
    i = 1;
  } else {
    i = in4->size[1];
  }
  if (i == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = i;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_2_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    in1_data[3 * i] = in2_data[3 * aux_0_1] - in3[0] * in4_data[aux_2_1];
    in1_data[3 * i + 1] =
        in2_data[3 * aux_0_1 + 1] - in3[1] * in4_data[aux_2_1];
    in1_data[3 * i + 2] =
        in2_data[3 * aux_0_1 + 2] - in3[2] * in4_data[aux_2_1];
    aux_2_1 += stride_2_1;
    aux_0_1 += stride_0_1;
  }
}

/*
 * 1、生成基底
 * 调用矩形拟合
 *
 * Arguments    : const emxArray_real_T *side_faces_transformed1
 *                const emxArray_real_T *side_faces_transformed2
 *                const emxArray_real_T *side_faces_transformed3
 *                const emxArray_real_T *side_faces_transformed4
 *                const emxArray_real_T *side_faces_transformed5
 *                const emxArray_real_T *side_faces_transformed6
 *                const emxArray_real_T *side_faces_transformed7
 *                const emxArray_real_T *side_faces_transformed8
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                const double PAB[3]
 *                double phi
 *                double shenglunum
 *                const emxArray_real_T *Ti
 *                const emxArray_real_T *a
 *                double distanceThreshold
 *                emxArray_real_T *PointTable_A_off8
 *                emxArray_real_T *PointTable_B_off8
 *                emxArray_real_T *XieMianPianYi
 *                emxArray_real_T *BianHao
 * Return Type  : void
 */
void Calculate_rectangle_from_vertex8(
    const emxArray_real_T *side_faces_transformed1,
    const emxArray_real_T *side_faces_transformed2,
    const emxArray_real_T *side_faces_transformed3,
    const emxArray_real_T *side_faces_transformed4,
    const emxArray_real_T *side_faces_transformed5,
    const emxArray_real_T *side_faces_transformed6,
    const emxArray_real_T *side_faces_transformed7,
    const emxArray_real_T *side_faces_transformed8, const double P_bound1[3],
    const double P_bound2[3], const double PAB[3], double phi,
    double shenglunum, const emxArray_real_T *Ti, const emxArray_real_T *a,
    double distanceThreshold, emxArray_real_T *PointTable_A_off8,
    emxArray_real_T *PointTable_B_off8, emxArray_real_T *XieMianPianYi,
    emxArray_real_T *BianHao)
{
  static const signed char b_iv[16] = {6, 7, 13, 19, 25, 31, 37, 43,
                                       2, 8, 17, 23, 29, 35, 41, 47};
  emxArray_real_T *Ti2A;
  emxArray_real_T *TrianglePoints4;
  emxArray_real_T *XMFlagA;
  emxArray_real_T *a__1;
  emxArray_real_T *b_side_faces_transformed2;
  emxArray_real_T *b_side_faces_transformed4;
  emxArray_real_T *b_side_faces_transformed6;
  emxArray_real_T *b_side_faces_transformed8;
  emxArray_real_T *deltTib;
  double PP16[48];
  double a__7[24];
  double a__8[8];
  double a__2[4];
  double Pin[3];
  double Pout[3];
  double d[3];
  double e[3];
  double u[3];
  double v[3];
  const double *Ti_data;
  const double *a_data;
  const double *side_faces_transformed2_data;
  const double *side_faces_transformed4_data;
  const double *side_faces_transformed6_data;
  const double *side_faces_transformed8_data;
  double PP16_tmp;
  double TiYuZhi1;
  double TiYuZhi2;
  double TiYuZhi3;
  double ab1;
  double ab2;
  double ab4;
  double b;
  double b_PP16_tmp;
  double b_x;
  double c_PP16_tmp;
  double d_PP16_tmp;
  double e_PP16_tmp;
  double h;
  double temp;
  double theta1;
  double theta2;
  double theta3;
  double theta4;
  double x;
  double *PointTable_B_off8_data;
  double *Ti2A_data;
  double *XMFlagA_data;
  double *XieMianPianYi_data;
  double *deltTib_data;
  int b_i;
  int i;
  int i1;
  int i10;
  int i11;
  int i12;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int loop_ub;
  int nx;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  a_data = a->data;
  Ti_data = Ti->data;
  side_faces_transformed8_data = side_faces_transformed8->data;
  side_faces_transformed6_data = side_faces_transformed6->data;
  side_faces_transformed4_data = side_faces_transformed4->data;
  side_faces_transformed2_data = side_faces_transformed2->data;
  emxInit_real_T(&XMFlagA, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&TrianglePoints4, 2);
  b_planefit4(side_faces_transformed1, side_faces_transformed3,
              side_faces_transformed5, side_faces_transformed7, P_bound1,
              P_bound2, distanceThreshold, a__1, TrianglePoints4, a__2,
              XMFlagA);
  /* 调用矩形参数计算 */
  Calculate_rectangle_from_vertex(TrianglePoints4, Pin, Pout, e, &b, &h, &ab4,
                                  v, a__7);
  /*    u, v: 底面的两个正交基向量，其中 u 在竖直平面内 */
  /*  计算轴向向量并归一化 */
  d[0] = Pout[0] - Pin[0];
  d[1] = Pout[1] - Pin[1];
  d[2] = Pout[2] - Pin[2];
  ab2 = b_norm(d);
  d[0] /= ab2;
  d[1] /= ab2;
  d[2] /= ab2;
  /*  选择竖直平面内的向量 e */
  if (fabs(d[0]) > fabs(d[1])) {
    /*  如果轴向向量大致沿 X 轴 */
    e[0] = 0.0;
    e[1] = 1.0;
    /*  选择 y 方向的单位向量 */
  } else {
    /*  否则，如果轴向向量大致沿 Y 轴 */
    e[0] = 1.0;
    e[1] = 0.0;
    /*  选择 x 方向的单位向量 */
  }
  /*  计算第一个基向量 u，使其位于竖直面内 */
  u[0] = d[1] * 0.0 - e[1] * d[2];
  u[1] = e[0] * d[2] - d[0] * 0.0;
  u[2] = d[0] * e[1] - e[0] * d[1];
  /*  计算与 d 和 e 正交的向量 */
  ab2 = b_norm(u);
  u[0] /= ab2;
  u[1] /= ab2;
  u[2] /= ab2;
  /*  归一化 */
  /*  确保 u 的方向朝上 */
  if (u[2] <= 0.0) {
    u[0] = -u[0];
    u[1] = -u[1];
    u[2] = -u[2];
    /*  如果 u 的方向与轴方向相反，反转 u */
  }
  /*  计算第二个基向量 v，使其与 d 和 u 正交 */
  v[0] = d[1] * u[2] - u[1] * d[2];
  v[1] = u[0] * d[2] - d[0] * u[2];
  v[2] = d[0] * u[1] - u[0] * d[1];
  /*  计算第二个正交向量 */
  ab2 = b_norm(v);
  v[0] = -v[0] / ab2;
  v[1] = -v[1] / ab2;
  v[2] = -v[2] / ab2;
  /*  归一化 */
  /*  2、判断是否在斜面上 */
  /* 计算八面参数 */
  emxInit_real_T(&b_side_faces_transformed2, 2);
  i = b_side_faces_transformed2->size[0] * b_side_faces_transformed2->size[1];
  b_side_faces_transformed2->size[0] = 3;
  b_side_faces_transformed2->size[1] = side_faces_transformed2->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed2, i);
  XieMianPianYi_data = b_side_faces_transformed2->data;
  loop_ub =
      side_faces_transformed2->size[0] * side_faces_transformed2->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed2_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed4, 2);
  i = b_side_faces_transformed4->size[0] * b_side_faces_transformed4->size[1];
  b_side_faces_transformed4->size[0] = 3;
  b_side_faces_transformed4->size[1] = side_faces_transformed4->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed4, i);
  XieMianPianYi_data = b_side_faces_transformed4->data;
  loop_ub =
      side_faces_transformed4->size[0] * side_faces_transformed4->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed4_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed6, 2);
  i = b_side_faces_transformed6->size[0] * b_side_faces_transformed6->size[1];
  b_side_faces_transformed6->size[0] = 3;
  b_side_faces_transformed6->size[1] = side_faces_transformed6->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed6, i);
  XieMianPianYi_data = b_side_faces_transformed6->data;
  loop_ub =
      side_faces_transformed6->size[0] * side_faces_transformed6->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed6_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed8, 2);
  i = b_side_faces_transformed8->size[0] * b_side_faces_transformed8->size[1];
  b_side_faces_transformed8->size[0] = 3;
  b_side_faces_transformed8->size[1] = side_faces_transformed8->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed8, i);
  XieMianPianYi_data = b_side_faces_transformed8->data;
  loop_ub =
      side_faces_transformed8->size[0] * side_faces_transformed8->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed8_data[i];
  }
  b_planefit8(side_faces_transformed1, b_side_faces_transformed2,
              side_faces_transformed3, b_side_faces_transformed4,
              side_faces_transformed5, b_side_faces_transformed6,
              side_faces_transformed7, b_side_faces_transformed8, P_bound1,
              P_bound2, distanceThreshold, a__1, TrianglePoints4, a__8,
              XMFlagA);
  XieMianPianYi_data = TrianglePoints4->data;
  deltTib_data = a__1->data;
  emxFree_real_T(&b_side_faces_transformed8);
  emxFree_real_T(&b_side_faces_transformed6);
  emxFree_real_T(&b_side_faces_transformed4);
  /* 计算角度 */
  ab1 = b_norm(&deltTib_data[0]);
  theta1 = acos(dot(&deltTib_data[0], &deltTib_data[4]) / ab1 /
                b_norm(&deltTib_data[4]));
  ab4 = b_norm(&deltTib_data[16]);
  theta2 = acos(dot(&deltTib_data[12], &deltTib_data[16]) /
                b_norm(&deltTib_data[12]) / ab4);
  theta3 = acos(dot(&deltTib_data[16], &deltTib_data[20]) / ab4 /
                b_norm(&deltTib_data[20]));
  theta4 = acos(dot(&deltTib_data[0], &deltTib_data[28]) / ab1 /
                b_norm(&deltTib_data[28]));
  emxFree_real_T(&a__1);
  /* 计算阈值 */
  /*  承接16顶点 */
  for (i = 0; i < 16; i++) {
    nx = 3 * b_iv[i];
    PP16[3 * i] = XieMianPianYi_data[nx];
    PP16[3 * i + 1] = XieMianPianYi_data[nx + 1];
    PP16[3 * i + 2] = XieMianPianYi_data[nx + 2];
  }
  emxFree_real_T(&TrianglePoints4);
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[0], &PP16[3], &PP16[18],
                                               &temp, &ab4, &ab2);
  PP16_tmp = PP16[3] - PP16[18];
  e[0] = PP16_tmp;
  b_PP16_tmp = PP16[4] - PP16[19];
  e[1] = b_PP16_tmp;
  c_PP16_tmp = PP16[5] - PP16[20];
  e[2] = c_PP16_tmp;
  ab1 = b_norm(e) / 2.0;
  e[0] = PP16[3] - temp;
  e[1] = PP16[4] - ab4;
  e[2] = PP16[5] - ab2;
  TiYuZhi1 = (ab1 - b_norm(e)) / ab1;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[9], &PP16[6], &PP16[15],
                                               &ab1, &ab4, &temp);
  TiYuZhi3 = PP16[6] - PP16[15];
  e[0] = TiYuZhi3;
  d_PP16_tmp = PP16[7] - PP16[16];
  e[1] = d_PP16_tmp;
  e_PP16_tmp = PP16[8] - PP16[17];
  e[2] = e_PP16_tmp;
  ab2 = b_norm(e) / 2.0;
  e[0] = PP16[6] - ab1;
  e[1] = PP16[7] - ab4;
  e[2] = PP16[8] - temp;
  TiYuZhi2 = (ab2 - b_norm(e)) / ab2;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[12], &PP16[6], &PP16[15],
                                               &ab1, &ab4, &temp);
  e[0] = TiYuZhi3;
  e[1] = d_PP16_tmp;
  e[2] = e_PP16_tmp;
  ab2 = b_norm(e) / 2.0;
  e[0] = PP16[6] - ab1;
  e[1] = PP16[7] - ab4;
  e[2] = PP16[8] - temp;
  TiYuZhi3 = (ab2 - b_norm(e)) / ab2;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[21], &PP16[3], &PP16[18],
                                               &ab1, &temp, &ab2);
  e[0] = PP16_tmp;
  e[1] = b_PP16_tmp;
  e[2] = c_PP16_tmp;
  ab4 = b_norm(e) / 2.0;
  e[0] = PP16[3] - ab1;
  e[1] = PP16[4] - temp;
  e[2] = PP16[5] - ab2;
  ab1 = (ab4 - b_norm(e)) / ab4;
  /* 判断点是否在斜面上（利用阈值 */
  temp = shenglunum / 2.0;
  i = XMFlagA->size[0] * XMFlagA->size[1];
  XMFlagA->size[0] = 1;
  loop_ub = (int)(2.0 * shenglunum);
  XMFlagA->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlagA, i);
  XMFlagA_data = XMFlagA->data;
  for (i = 0; i < loop_ub; i++) {
    XMFlagA_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    ab4 = fabs(Ti_data[b_i]);
    if ((double)b_i + 1.0 <= temp) {
      XMFlagA_data[b_i] = !(ab4 < fabs(ab1));
    } else if ((double)b_i + 1.0 <= 2.0 * temp) {
      XMFlagA_data[b_i] = !(ab4 < fabs(TiYuZhi1));
    } else if ((double)b_i + 1.0 <= 3.0 * temp) {
      XMFlagA_data[b_i] = !(ab4 < fabs(TiYuZhi2));
    } else {
      XMFlagA_data[b_i] = !(ab4 < fabs(TiYuZhi3));
    }
  }
  /*  3、修正Ti */
  emxInit_real_T(&Ti2A, 2);
  i = Ti2A->size[0] * Ti2A->size[1];
  Ti2A->size[0] = 1;
  Ti2A->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ti2A, i);
  Ti2A_data = Ti2A->data;
  for (i = 0; i < loop_ub; i++) {
    Ti2A_data[i] = 0.0;
  }
  i = XieMianPianYi->size[0] * XieMianPianYi->size[1];
  XieMianPianYi->size[0] = 1;
  XieMianPianYi->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XieMianPianYi, i);
  XieMianPianYi_data = XieMianPianYi->data;
  for (i = 0; i < loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  /* %%%%%%%%%%%%%%%%%%%%%  对斜面上的点进行偏移（修正Ti）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (nx = 0; nx < loop_ub; nx++) {
    if ((double)nx + 1.0 <= temp) {
      if (XMFlagA_data[nx] == 1.0) {
        /* 斜面上 */
        ab2 = a_data[nx];
        Ti2A_data[nx] = Ti_data[nx] + ab2 * sin(theta4);
        XieMianPianYi_data[nx] = ab2 * tan(theta4);
      } else {
        Ti2A_data[nx] = Ti_data[nx];
        XieMianPianYi_data[nx] = 0.0;
      }
    } else if ((double)nx + 1.0 <= 2.0 * temp) {
      if (XMFlagA_data[nx] == 1.0) {
        /* 斜面上 */
        ab2 = a_data[nx];
        Ti2A_data[nx] = Ti_data[nx] - ab2 * sin(theta1);
        XieMianPianYi_data[nx] = ab2 * tan(theta1);
      } else {
        Ti2A_data[nx] = Ti_data[nx];
        XieMianPianYi_data[nx] = 0.0;
      }
    } else if ((double)nx + 1.0 <= 3.0 * temp) {
      if (XMFlagA_data[nx] == 1.0) {
        /* 斜面上 */
        ab2 = a_data[nx];
        Ti2A_data[nx] = Ti_data[nx] - ab2 * sin(theta2);
        XieMianPianYi_data[nx] = ab2 * tan(theta2);
      } else {
        Ti2A_data[nx] = Ti_data[nx];
        XieMianPianYi_data[nx] = 0.0;
      }
    } else if (XMFlagA_data[nx] == 1.0) {
      /* 斜面上 */
      ab2 = a_data[nx];
      Ti2A_data[nx] = Ti_data[nx] + ab2 * sin(theta3);
      XieMianPianYi_data[nx] = ab2 * tan(theta3);
    } else {
      Ti2A_data[nx] = Ti_data[nx];
      XieMianPianYi_data[nx] = 0.0;
    }
  }
  /*  4、径向移动 */
  emxInit_real_T(&deltTib, 2);
  i = deltTib->size[0] * deltTib->size[1];
  deltTib->size[0] = 1;
  deltTib->size[1] = loop_ub;
  emxEnsureCapacity_real_T(deltTib, i);
  deltTib_data = deltTib->data;
  for (i = 0; i < loop_ub; i++) {
    deltTib_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if ((double)b_i + 1.0 <= temp) {
      if (XMFlagA_data[b_i] == 1.0) {
        /* 斜面上 */
        deltTib_data[b_i] = fabs(Ti2A_data[b_i] - ab1) * h / 2.0 /
                            tan(1.5707963267948966 - theta4);
      }
    } else if ((double)b_i + 1.0 <= 2.0 * temp) {
      if (XMFlagA_data[b_i] == 1.0) {
        /* 斜面上 */
        deltTib_data[b_i] = fabs(Ti2A_data[b_i] - TiYuZhi1) * h / 2.0 /
                            tan(1.5707963267948966 - theta1);
      }
    } else if ((double)b_i + 1.0 <= 3.0 * temp) {
      if (XMFlagA_data[b_i] == 1.0) {
        /* 斜面上 */
        deltTib_data[b_i] = fabs(Ti2A_data[b_i] - TiYuZhi2) * h / 2.0 /
                            tan(1.5707963267948966 - theta2);
      }
    } else if (XMFlagA_data[b_i] == 1.0) {
      /* 斜面上 */
      deltTib_data[b_i] = fabs(Ti2A_data[b_i] - TiYuZhi3) * h / 2.0 /
                          tan(1.5707963267948966 - theta3);
    }
  }
  i = XMFlagA->size[0] * XMFlagA->size[1];
  XMFlagA->size[0] = 1;
  XMFlagA->size[1] = deltTib->size[1];
  emxEnsureCapacity_real_T(XMFlagA, i);
  XMFlagA_data = XMFlagA->data;
  nx = deltTib->size[1];
  for (i = 0; i < nx; i++) {
    XMFlagA_data[i] = deltTib_data[i];
  }
  nx = deltTib->size[1];
  i = deltTib->size[0] * deltTib->size[1];
  deltTib->size[0] = 1;
  deltTib->size[1] = XMFlagA->size[1];
  emxEnsureCapacity_real_T(deltTib, i);
  deltTib_data = deltTib->data;
  for (b_i = 0; b_i < nx; b_i++) {
    deltTib_data[b_i] = fabs(XMFlagA_data[b_i]);
  }
  /*  5、面上一周的点计算 */
  i = PointTable_B_off8->size[0] * PointTable_B_off8->size[1];
  PointTable_B_off8->size[0] = 3;
  PointTable_B_off8->size[1] = loop_ub;
  emxEnsureCapacity_real_T(PointTable_B_off8, i);
  PointTable_B_off8_data = PointTable_B_off8->data;
  nx = 3 * loop_ub;
  for (i = 0; i < nx; i++) {
    PointTable_B_off8_data[i] = 0.0;
  }
  i = (int)shenglunum;
  for (nx = 0; nx < i; nx++) {
    ab1 = Ti2A_data[nx];
    ab4 = b / 2.0 - deltTib_data[nx];
    PointTable_B_off8_data[3 * nx] =
        (Pout[0] + u[0] * ab1 * h / 2.0) - v[0] * ab4;
    PointTable_B_off8_data[3 * nx + 1] =
        (Pout[1] + u[1] * ab1 * h / 2.0) - v[1] * ab4;
    PointTable_B_off8_data[3 * nx + 2] =
        (Pout[2] + u[2] * ab1 * h / 2.0) - v[2] * ab4;
  }
  i1 = (int)(2.0 * shenglunum + (1.0 - (shenglunum + 1.0)));
  for (b_i = 0; b_i < i1; b_i++) {
    ab2 = (shenglunum + 1.0) + (double)b_i;
    ab1 = Ti2A_data[(int)ab2 - 1];
    ab4 = b / 2.0 - deltTib_data[(int)ab2 - 1];
    i2 = 3 * ((int)ab2 - 1);
    PointTable_B_off8_data[i2] = (Pout[0] + u[0] * ab1 * h / 2.0) + v[0] * ab4;
    PointTable_B_off8_data[i2 + 1] =
        (Pout[1] + u[1] * ab1 * h / 2.0) + v[1] * ab4;
    PointTable_B_off8_data[i2 + 2] =
        (Pout[2] + u[2] * ab1 * h / 2.0) + v[2] * ab4;
  }
  /*  6、计算轴线移动l */
  /* 整体移动 */
  foot_of_perpendicular_from_a_point_to_a_line(PAB, Pin, Pout, &temp, &ab4,
                                               &ab2);
  ab2 -= Pout[2];
  ab4 -= Pout[1];
  ab1 = temp - Pout[0];
  ab4 = sqrt((ab2 * ab2 + ab4 * ab4) + ab1 * ab1);
  /*  距离*cos(phi) 无正负 全为正 */
  i2 = Ti2A->size[0] * Ti2A->size[1];
  Ti2A->size[0] = 1;
  Ti2A->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ti2A, i2);
  Ti2A_data = Ti2A->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    Ti2A_data[i2] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    ab2 = deltTib_data[b_i];
    if (ab2 == 0.0) {
      Ti2A_data[b_i] = b / 2.0 / tan(phi);
    } else {
      Ti2A_data[b_i] = (b / 2.0 - ab2) / tan(phi);
    }
  }
  emxFree_real_T(&deltTib);
  /*  7、偏移 */
  /*  A测点 */
  i2 = XMFlagA->size[0] * XMFlagA->size[1];
  XMFlagA->size[0] = 1;
  XMFlagA->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlagA, i2);
  XMFlagA_data = XMFlagA->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    XMFlagA_data[i2] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    if (shenglunum < 1.0) {
      nx = 0;
    } else {
      nx = (int)shenglunum;
    }
    ab1 = tan(phi);
    for (i2 = 0; i2 < nx; i2++) {
      XMFlagA_data[i2] = (ab4 + Ti2A_data[i2]) - a_data[i2] / ab1;
    }
  }
  if (i1 - 1 >= 0) {
    if (shenglunum + 1.0 > 2.0 * shenglunum) {
      i3 = 0;
      i4 = 0;
      i5 = 0;
      i6 = 0;
    } else {
      i3 = (int)(shenglunum + 1.0) - 1;
      i4 = loop_ub;
      i5 = (int)(shenglunum + 1.0) - 1;
      i6 = loop_ub;
    }
    x = tan(phi);
    if (shenglunum + 1.0 > 2.0 * shenglunum) {
      i7 = 0;
    } else {
      i7 = (int)(shenglunum + 1.0) - 1;
    }
  }
  for (b_i = 0; b_i < i1; b_i++) {
    nx = i4 - i3;
    if (nx == i6 - i5) {
      for (i2 = 0; i2 < nx; i2++) {
        XMFlagA_data[i7 + i2] =
            (ab4 - Ti2A_data[i3 + i2]) + a_data[i5 + i2] / x;
      }
    } else {
      binary_expand_op_10(XMFlagA, i7, ab4, Ti2A, i3, i4 - 1, a, i5, i6 - 1, x);
      XMFlagA_data = XMFlagA->data;
    }
  }
  if (PointTable_B_off8->size[1] == XMFlagA->size[1]) {
    i2 = PointTable_A_off8->size[0] * PointTable_A_off8->size[1];
    PointTable_A_off8->size[0] = 3;
    PointTable_A_off8->size[1] = PointTable_B_off8->size[1];
    emxEnsureCapacity_real_T(PointTable_A_off8, i2);
    XieMianPianYi_data = PointTable_A_off8->data;
    nx = PointTable_B_off8->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      XieMianPianYi_data[3 * i2] =
          PointTable_B_off8_data[3 * i2] - d[0] * XMFlagA_data[i2];
      i3 = 3 * i2 + 1;
      XieMianPianYi_data[i3] =
          PointTable_B_off8_data[i3] - d[1] * XMFlagA_data[i2];
      i3 = 3 * i2 + 2;
      XieMianPianYi_data[i3] =
          PointTable_B_off8_data[i3] - d[2] * XMFlagA_data[i2];
    }
  } else {
    binary_expand_op_14(PointTable_A_off8, PointTable_B_off8, d, XMFlagA);
  }
  /*  B测点 */
  i2 = XMFlagA->size[0] * XMFlagA->size[1];
  XMFlagA->size[0] = 1;
  XMFlagA->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlagA, i2);
  XMFlagA_data = XMFlagA->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    XMFlagA_data[i2] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    if (shenglunum < 1.0) {
      nx = 0;
    } else {
      nx = (int)shenglunum;
    }
    ab1 = tan(phi);
    for (i2 = 0; i2 < nx; i2++) {
      XMFlagA_data[i2] = (ab4 - Ti2A_data[i2]) + a_data[i2] / ab1;
    }
  }
  if (i1 - 1 >= 0) {
    if (shenglunum + 1.0 > 2.0 * shenglunum) {
      i8 = 0;
      i9 = 0;
      i10 = 0;
      i11 = 0;
    } else {
      i8 = (int)(shenglunum + 1.0) - 1;
      i9 = loop_ub;
      i10 = (int)(shenglunum + 1.0) - 1;
      i11 = loop_ub;
    }
    b_x = tan(phi);
    if (shenglunum + 1.0 > 2.0 * shenglunum) {
      i12 = 0;
    } else {
      i12 = (int)(shenglunum + 1.0) - 1;
    }
  }
  for (b_i = 0; b_i < i1; b_i++) {
    nx = i9 - i8;
    if (nx == i11 - i10) {
      for (i2 = 0; i2 < nx; i2++) {
        XMFlagA_data[i12 + i2] =
            (ab4 + Ti2A_data[i8 + i2]) - a_data[i10 + i2] / b_x;
      }
    } else {
      binary_expand_op_12(XMFlagA, i12, ab4, Ti2A, i8, i9 - 1, a, i10, i11 - 1,
                          b_x);
      XMFlagA_data = XMFlagA->data;
    }
  }
  emxFree_real_T(&Ti2A);
  if (PointTable_B_off8->size[1] == XMFlagA->size[1]) {
    i2 =
        b_side_faces_transformed2->size[0] * b_side_faces_transformed2->size[1];
    b_side_faces_transformed2->size[0] = 3;
    b_side_faces_transformed2->size[1] = PointTable_B_off8->size[1];
    emxEnsureCapacity_real_T(b_side_faces_transformed2, i2);
    XieMianPianYi_data = b_side_faces_transformed2->data;
    nx = PointTable_B_off8->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      XieMianPianYi_data[3 * i2] =
          PointTable_B_off8_data[3 * i2] - d[0] * XMFlagA_data[i2];
      i3 = 3 * i2 + 1;
      XieMianPianYi_data[i3] =
          PointTable_B_off8_data[i3] - d[1] * XMFlagA_data[i2];
      i3 = 3 * i2 + 2;
      XieMianPianYi_data[i3] =
          PointTable_B_off8_data[i3] - d[2] * XMFlagA_data[i2];
    }
    i2 = PointTable_B_off8->size[0] * PointTable_B_off8->size[1];
    PointTable_B_off8->size[0] = 3;
    PointTable_B_off8->size[1] = b_side_faces_transformed2->size[1];
    emxEnsureCapacity_real_T(PointTable_B_off8, i2);
    PointTable_B_off8_data = PointTable_B_off8->data;
    nx = 3 * b_side_faces_transformed2->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      PointTable_B_off8_data[i2] = XieMianPianYi_data[i2];
    }
  } else {
    binary_expand_op_13(PointTable_B_off8, d, XMFlagA);
  }
  emxFree_real_T(&b_side_faces_transformed2);
  emxFree_real_T(&XMFlagA);
  /*  8、编号 */
  i2 = BianHao->size[0] * BianHao->size[1];
  BianHao->size[0] = 2;
  BianHao->size[1] = loop_ub;
  emxEnsureCapacity_real_T(BianHao, i2);
  XieMianPianYi_data = BianHao->data;
  loop_ub <<= 1;
  for (i2 = 0; i2 < loop_ub; i2++) {
    XieMianPianYi_data[i2] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    ab1 = 2.0 * ((double)b_i + 1.0);
    XieMianPianYi_data[2 * b_i] = ab1 - 1.0;
    XieMianPianYi_data[2 * b_i + 1] = ab1;
  }
  for (b_i = 0; b_i < i1; b_i++) {
    ab4 = (shenglunum + 1.0) + (double)b_i;
    ab1 = ((2.0 * shenglunum + 1.0) - ab4) * 2.0;
    i = 2 * ((int)ab4 - 1);
    XieMianPianYi_data[i] = ab1;
    XieMianPianYi_data[i + 1] = ab1 - 1.0;
  }
}

/*
 * File trailer for Calculate_rectangle_from_vertex8.c
 *
 * [EOF]
 */
