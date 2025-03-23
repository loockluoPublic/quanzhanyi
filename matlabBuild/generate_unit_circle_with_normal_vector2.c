/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 18:24:20
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_19(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4,
                                const double in5[3]);

static void binary_expand_op_20(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4,
                                const double in5[3]);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const double in3[3]
 *                const emxArray_real_T *in4
 *                const double in5[3]
 * Return Type  : void
 */
static void binary_expand_op_19(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4, const double in5[3])
{
  const double *in2_data;
  const double *in4_data;
  double b_in3;
  double b_in5;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_data = in4->data;
  in2_data = in2->data;
  b_in3 = in3[1];
  b_in5 = in5[1];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  if (in4->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in4->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        in2_data[i * stride_0_1] * b_in3 + in4_data[i * stride_1_1] * b_in5;
  }
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const double in3[3]
 *                const emxArray_real_T *in4
 *                const double in5[3]
 * Return Type  : void
 */
static void binary_expand_op_20(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4, const double in5[3])
{
  const double *in2_data;
  const double *in4_data;
  double b_in3;
  double b_in5;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_data = in4->data;
  in2_data = in2->data;
  b_in3 = in3[0];
  b_in5 = in5[0];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(in1, i);
  if (in4->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in4->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        in2_data[i * stride_0_1] * b_in3 + in4_data[i * stride_1_1] * b_in5;
  }
}

/*
 * Arguments    : const emxArray_real_T *PointIn
 *                double num
 *                double laynum
 *                const double PUp[3]
 *                const double PDown[3]
 *                emxArray_real_T *Point_out
 * Return Type  : void
 */
void generate_unit_circle_with_normal_vector2(const emxArray_real_T *PointIn,
                                              double num, double laynum,
                                              const double PUp[3],
                                              const double PDown[3],
                                              emxArray_real_T *Point_out)
{
  emxArray_real_T *deltx;
  emxArray_real_T *delty;
  emxArray_real_T *deltz;
  emxArray_real_T *theta;
  emxArray_real_T *x_circle;
  emxArray_real_T *y_circle;
  emxArray_real_T *z_circle;
  double b_n1[6];
  double n1[3];
  double v1[3];
  double b_dv[2];
  const double *PointIn_data;
  double M1_idx_0;
  double M1_idx_1;
  double M1_idx_2;
  double absxk;
  double d;
  double normal_idx_0;
  double normal_idx_1;
  double normal_idx_2;
  double r;
  double scale;
  double t;
  double v2_idx_0;
  double v2_idx_1;
  double v2_idx_2;
  double *deltx_data;
  double *delty_data;
  double *deltz_data;
  double *theta_data;
  double *x_circle_data;
  double *y_circle_data;
  double *z_circle_data;
  int b_i;
  int i;
  int i1;
  int j;
  int k;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  PointIn_data = PointIn->data;
  /*  1. 计算法向量 */
  d = PointIn_data[0];
  v1[0] = PointIn_data[3] - d;
  v2_idx_0 = PointIn_data[6] - d;
  d = PointIn_data[1];
  v1[1] = PointIn_data[4] - d;
  v2_idx_1 = PointIn_data[7] - d;
  d = PointIn_data[2];
  v1[2] = PointIn_data[5] - d;
  v2_idx_2 = PointIn_data[8] - d;
  normal_idx_0 = v1[1] * v2_idx_2 - v2_idx_1 * v1[2];
  normal_idx_1 = v2_idx_0 * v1[2] - v1[0] * v2_idx_2;
  normal_idx_2 = v1[0] * v2_idx_1 - v2_idx_0 * v1[1];
  /*  叉乘 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(normal_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    M1_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    M1_idx_2 = t * t;
  }
  absxk = fabs(normal_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  absxk = fabs(normal_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  M1_idx_2 = scale * sqrt(M1_idx_2);
  /*  单位化 */
  /*  2. 计算中点 */
  normal_idx_0 /= M1_idx_2;
  M1_idx_0 = (PointIn_data[0] + PointIn_data[3]) / 2.0;
  normal_idx_1 /= M1_idx_2;
  M1_idx_1 = (PointIn_data[1] + PointIn_data[4]) / 2.0;
  normal_idx_2 /= M1_idx_2;
  M1_idx_2 = (PointIn_data[2] + PointIn_data[5]) / 2.0;
  /*  3. 计算垂直向量 */
  n1[0] = v1[1] * normal_idx_2 - normal_idx_1 * v1[2];
  n1[1] = normal_idx_0 * v1[2] - v1[0] * normal_idx_2;
  n1[2] = v1[0] * normal_idx_1 - normal_idx_0 * v1[1];
  /*  4. 求解圆心 */
  b_n1[3] = -(v2_idx_1 * normal_idx_2 - normal_idx_1 * v2_idx_2);
  b_n1[4] = -(normal_idx_0 * v2_idx_2 - v2_idx_0 * normal_idx_2);
  b_n1[5] = -(v2_idx_0 * normal_idx_1 - normal_idx_0 * v2_idx_1);
  b_n1[0] = n1[0];
  v1[0] = (PointIn_data[0] + PointIn_data[6]) / 2.0 - M1_idx_0;
  b_n1[1] = n1[1];
  v1[1] = (PointIn_data[1] + PointIn_data[7]) / 2.0 - M1_idx_1;
  b_n1[2] = n1[2];
  v1[2] = (PointIn_data[2] + PointIn_data[8]) / 2.0 - M1_idx_2;
  d_mldivide(b_n1, v1, b_dv);
  /*  5. 计算半径 */
  scale = 3.3121686421112381E-170;
  d = M1_idx_0 + b_dv[0] * n1[0];
  M1_idx_0 = d;
  absxk = fabs(PointIn_data[0] - d);
  if (absxk > 3.3121686421112381E-170) {
    r = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    r = t * t;
  }
  d = M1_idx_1 + b_dv[0] * n1[1];
  M1_idx_1 = d;
  absxk = fabs(PointIn_data[1] - d);
  if (absxk > scale) {
    t = scale / absxk;
    r = r * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    r += t * t;
  }
  d = M1_idx_2 + b_dv[0] * n1[2];
  absxk = fabs(PointIn_data[2] - d);
  if (absxk > scale) {
    t = scale / absxk;
    r = r * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    r += t * t;
  }
  r = scale * sqrt(r);
  /*  三个点定义 */
  /*  斜率计算 */
  scale = (M1_idx_0 + normal_idx_0) - M1_idx_0;
  v2_idx_2 = (M1_idx_1 + normal_idx_1) - M1_idx_1;
  M1_idx_2 = (d + normal_idx_2) - d;
  normal_idx_0 = (scale * scale + v2_idx_2 * v2_idx_2) + M1_idx_2 * M1_idx_2;
  absxk = -(((M1_idx_0 - PUp[0]) * scale + (M1_idx_1 - PUp[1]) * v2_idx_2) +
            (d - PUp[2]) * M1_idx_2) /
          normal_idx_0;
  /*  P1点在轴线上的投影坐标 */
  t = absxk * scale + M1_idx_0;
  normal_idx_1 = absxk * v2_idx_2 + M1_idx_1;
  normal_idx_2 = absxk * M1_idx_2 + d;
  /*  三个点定义 */
  /*  斜率计算 */
  absxk = -(((M1_idx_0 - PDown[0]) * scale + (M1_idx_1 - PDown[1]) * v2_idx_2) +
            (d - PDown[2]) * M1_idx_2) /
          normal_idx_0;
  /*  P1点在轴线上的投影坐标 */
  scale = absxk * scale + M1_idx_0;
  normal_idx_0 = absxk * v2_idx_2 + M1_idx_1;
  v2_idx_2 = absxk * M1_idx_2 + d;
  emxInit_real_T(&deltx, 2);
  i = deltx->size[0] * deltx->size[1];
  deltx->size[0] = 1;
  i1 = (int)laynum;
  deltx->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(deltx, i);
  deltx_data = deltx->data;
  emxInit_real_T(&delty, 2);
  i = delty->size[0] * delty->size[1];
  delty->size[0] = 1;
  delty->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(delty, i);
  delty_data = delty->data;
  emxInit_real_T(&deltz, 2);
  i = deltz->size[0] * deltz->size[1];
  deltz->size[0] = 1;
  deltz->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(deltz, i);
  deltz_data = deltz->data;
  for (b_i = 0; b_i < i1; b_i++) {
    M1_idx_2 = ((double)b_i + 1.0) / ((laynum + 1.0) - ((double)b_i + 1.0));
    deltx_data[b_i] = (t + M1_idx_2 * scale) / (M1_idx_2 + 1.0);
    delty_data[b_i] =
        (normal_idx_1 + M1_idx_2 * normal_idx_0) / (M1_idx_2 + 1.0);
    deltz_data[b_i] = (normal_idx_2 + M1_idx_2 * v2_idx_2) / (M1_idx_2 + 1.0);
  }
  /*  计算轴向向量并归一化 */
  v2_idx_0 = scale - t;
  v2_idx_1 = normal_idx_0 - normal_idx_1;
  v2_idx_2 -= normal_idx_2;
  scale = 3.3121686421112381E-170;
  absxk = fabs(v2_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    M1_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    M1_idx_2 = t * t;
  }
  absxk = fabs(v2_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  absxk = fabs(v2_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  M1_idx_2 = scale * sqrt(M1_idx_2);
  v2_idx_0 /= M1_idx_2;
  v2_idx_1 /= M1_idx_2;
  v2_idx_2 /= M1_idx_2;
  /*  选择竖直平面内的向量 e */
  if (fabs(v2_idx_0) > fabs(v2_idx_1)) {
    /*  如果轴向向量大致沿 X 轴 */
    v1[0] = 0.0;
    v1[1] = 1.0;
    /*  选择 y 方向的单位向量 */
  } else {
    /*  否则，如果轴向向量大致沿 Y 轴 */
    v1[0] = 1.0;
    v1[1] = 0.0;
    /*  选择 x 方向的单位向量 */
  }
  /*  计算第一个基向量 u，使其位于竖直面内 */
  n1[0] = v2_idx_1 * 0.0 - v1[1] * v2_idx_2;
  n1[1] = v1[0] * v2_idx_2 - v2_idx_0 * 0.0;
  n1[2] = v2_idx_0 * v1[1] - v1[0] * v2_idx_1;
  /*  计算与 d 和 e 正交的向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(n1[0]);
  if (absxk > 3.3121686421112381E-170) {
    M1_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    M1_idx_2 = t * t;
  }
  absxk = fabs(n1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  absxk = fabs(n1[2]);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  M1_idx_2 = scale * sqrt(M1_idx_2);
  n1[0] /= M1_idx_2;
  n1[1] /= M1_idx_2;
  n1[2] /= M1_idx_2;
  /*  归一化 */
  /*  确保 u 的方向朝上 */
  if (n1[2] <= 0.0) {
    n1[0] = -n1[0];
    n1[1] = -n1[1];
    n1[2] = -n1[2];
    /*  如果 u 的方向与轴方向相反，反转 u */
  }
  /*  计算第二个基向量 v，使其与 d 和 u 正交 */
  v1[0] = v2_idx_1 * n1[2] - n1[1] * v2_idx_2;
  v1[1] = n1[0] * v2_idx_2 - v2_idx_0 * n1[2];
  v1[2] = v2_idx_0 * n1[1] - n1[0] * v2_idx_1;
  /*  计算第二个正交向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(v1[0]);
  if (absxk > 3.3121686421112381E-170) {
    M1_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    M1_idx_2 = t * t;
  }
  absxk = fabs(v1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  absxk = fabs(v1[2]);
  if (absxk > scale) {
    t = scale / absxk;
    M1_idx_2 = M1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    M1_idx_2 += t * t;
  }
  M1_idx_2 = scale * sqrt(M1_idx_2);
  /*  归一化 */
  n1[0] *= r;
  v1[0] = -v1[0] / M1_idx_2 * r;
  n1[1] *= r;
  v1[1] = -v1[1] / M1_idx_2 * r;
  n1[2] *= r;
  v1[2] = -v1[2] / M1_idx_2 * r;
  emxInit_real_T(&theta, 2);
  theta_data = theta->data;
  if (!(num >= 0.0)) {
    theta->size[0] = 1;
    theta->size[1] = 0;
  } else {
    d = floor(num);
    i = theta->size[0] * theta->size[1];
    theta->size[0] = 1;
    theta->size[1] = (int)d;
    emxEnsureCapacity_real_T(theta, i);
    theta_data = theta->data;
    if ((int)d >= 1) {
      theta_data[(int)d - 1] = 3.6651914291880923;
      if (theta->size[1] >= 2) {
        theta_data[0] = -0.52359877559829882;
        if (theta->size[1] >= 3) {
          M1_idx_2 = 4.1887902047863914 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta_data[k + 1] =
                ((double)k + 1.0) * M1_idx_2 - 0.52359877559829882;
          }
        }
      }
    }
  }
  /*  单位圆的参数方程 */
  emxInit_real_T(&z_circle, 2);
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, i);
  z_circle_data = z_circle->data;
  b_i = theta->size[1];
  for (k = 0; k < b_i; k++) {
    d = theta_data[k];
    z_circle_data[k] = cos(d);
    d = sin(d);
    theta_data[k] = d;
  }
  emxInit_real_T(&x_circle, 2);
  if (z_circle->size[1] == theta->size[1]) {
    i = x_circle->size[0] * x_circle->size[1];
    x_circle->size[0] = 1;
    x_circle->size[1] = z_circle->size[1];
    emxEnsureCapacity_real_T(x_circle, i);
    x_circle_data = x_circle->data;
    b_i = z_circle->size[1];
    for (i = 0; i < b_i; i++) {
      x_circle_data[i] = z_circle_data[i] * v1[0] + theta_data[i] * n1[0];
    }
  } else {
    binary_expand_op_20(x_circle, z_circle, v1, theta, n1);
    x_circle_data = x_circle->data;
  }
  emxInit_real_T(&y_circle, 2);
  if (z_circle->size[1] == theta->size[1]) {
    i = y_circle->size[0] * y_circle->size[1];
    y_circle->size[0] = 1;
    y_circle->size[1] = z_circle->size[1];
    emxEnsureCapacity_real_T(y_circle, i);
    y_circle_data = y_circle->data;
    b_i = z_circle->size[1];
    for (i = 0; i < b_i; i++) {
      y_circle_data[i] = z_circle_data[i] * v1[1] + theta_data[i] * n1[1];
    }
  } else {
    binary_expand_op_19(y_circle, z_circle, v1, theta, n1);
    y_circle_data = y_circle->data;
  }
  if (z_circle->size[1] == theta->size[1]) {
    b_i = z_circle->size[1] - 1;
    i = z_circle->size[0] * z_circle->size[1];
    z_circle->size[0] = 1;
    emxEnsureCapacity_real_T(z_circle, i);
    z_circle_data = z_circle->data;
    for (i = 0; i <= b_i; i++) {
      z_circle_data[i] = z_circle_data[i] * v1[2] + theta_data[i] * n1[2];
    }
  } else {
    binary_expand_op_15(z_circle, v1, theta, n1);
    z_circle_data = z_circle->data;
  }
  emxFree_real_T(&theta);
  i = Point_out->size[0] * Point_out->size[1];
  Point_out->size[0] = 3;
  k = (int)(num * laynum);
  Point_out->size[1] = k;
  emxEnsureCapacity_real_T(Point_out, i);
  theta_data = Point_out->data;
  b_i = 3 * k;
  for (i = 0; i < b_i; i++) {
    theta_data[i] = 0.0;
  }
  for (j = 0; j < i1; j++) {
    d = (((double)j + 1.0) - 1.0) * num + 1.0;
    if (d > ((double)j + 1.0) * num) {
      i = 0;
    } else {
      i = (int)d - 1;
    }
    M1_idx_2 = deltx_data[j];
    v2_idx_2 = delty_data[j];
    normal_idx_0 = deltz_data[j];
    b_i = x_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k)] = x_circle_data[k] + M1_idx_2;
    }
    b_i = y_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 1] = y_circle_data[k] + v2_idx_2;
    }
    b_i = z_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 2] = z_circle_data[k] + normal_idx_0;
    }
  }
  emxFree_real_T(&z_circle);
  emxFree_real_T(&y_circle);
  emxFree_real_T(&x_circle);
  emxFree_real_T(&deltz);
  emxFree_real_T(&delty);
  emxFree_real_T(&deltx);
}

/*
 * File trailer for generate_unit_circle_with_normal_vector2.c
 *
 * [EOF]
 */
