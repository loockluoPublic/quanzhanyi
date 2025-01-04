/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 23:51:41
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
static void binary_expand_op_14(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4,
                                const double in5[3]);

static void binary_expand_op_15(emxArray_real_T *in1,
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
static void binary_expand_op_14(emxArray_real_T *in1,
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
static void binary_expand_op_15(emxArray_real_T *in1,
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
  double n1[6];
  double n2[3];
  double v1[3];
  double c[2];
  const double *PointIn_data;
  double M1_idx_0;
  double M1_idx_1;
  double M2_idx_0;
  double M2_idx_1;
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
  double y;
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
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(normal_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(normal_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  /*  单位化 */
  /*  2. 计算中点 */
  normal_idx_0 /= y;
  d = PointIn_data[0];
  M1_idx_0 = (d + PointIn_data[3]) / 2.0;
  M2_idx_0 = (d + PointIn_data[6]) / 2.0;
  normal_idx_1 /= y;
  d = PointIn_data[1];
  M1_idx_1 = (d + PointIn_data[4]) / 2.0;
  M2_idx_1 = (d + PointIn_data[7]) / 2.0;
  normal_idx_2 /= y;
  d = PointIn_data[2];
  /*  3. 计算垂直向量 */
  scale = v1[1] * normal_idx_2 - normal_idx_1 * v1[2];
  absxk = normal_idx_0 * v1[2] - v1[0] * normal_idx_2;
  t = v1[0] * normal_idx_1 - normal_idx_0 * v1[1];
  n2[0] = v2_idx_1 * normal_idx_2 - normal_idx_1 * v2_idx_2;
  n2[1] = normal_idx_0 * v2_idx_2 - v2_idx_0 * normal_idx_2;
  n2[2] = v2_idx_0 * normal_idx_1 - normal_idx_0 * v2_idx_1;
  /*  4. 求解圆心 */
  /*  5. 计算半径 */
  n1[0] = scale;
  n1[1] = -n2[0];
  n1[2] = absxk;
  n1[3] = -n2[1];
  n1[4] = t;
  n1[5] = -n2[2];
  c[0] =
      (scale * M1_idx_0 + absxk * M1_idx_1) + t * ((d + PointIn_data[5]) / 2.0);
  c[1] = (n2[0] * M2_idx_0 + n2[1] * M2_idx_1) +
         n2[2] * ((d + PointIn_data[8]) / 2.0);
  d_mldivide(n1, c, v1);
  scale = 3.3121686421112381E-170;
  absxk = fabs(PointIn_data[0] - v1[0]);
  if (absxk > 3.3121686421112381E-170) {
    r = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    r = t * t;
  }
  absxk = fabs(PointIn_data[1] - v1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    r = r * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    r += t * t;
  }
  absxk = fabs(PointIn_data[2] - v1[2]);
  if (absxk > scale) {
    t = scale / absxk;
    r = r * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    r += t * t;
  }
  r = scale * sqrt(r);
  v2_idx_0 = normal_idx_0;
  v2_idx_1 = normal_idx_1;
  v2_idx_2 = normal_idx_2;
  /*  三个点定义 */
  /*  斜率计算 */
  scale = (normal_idx_0 * normal_idx_0 + normal_idx_1 * normal_idx_1) +
          normal_idx_2 * normal_idx_2;
  absxk = -(((0.0 - PUp[0]) * normal_idx_0 + (0.0 - PUp[1]) * normal_idx_1) +
            (0.0 - PUp[2]) * normal_idx_2) /
          scale;
  /*  P1点在轴线上的投影坐标 */
  M2_idx_0 = absxk * normal_idx_0;
  M1_idx_1 = absxk * normal_idx_1;
  M2_idx_1 = absxk * normal_idx_2;
  /*  三个点定义 */
  /*  斜率计算 */
  absxk =
      -(((0.0 - PDown[0]) * normal_idx_0 + (0.0 - PDown[1]) * normal_idx_1) +
        (0.0 - PDown[2]) * normal_idx_2) /
      scale;
  /*  P1点在轴线上的投影坐标 */
  t = absxk * normal_idx_0;
  M1_idx_0 = absxk * normal_idx_1;
  scale = absxk * normal_idx_2;
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
    absxk = ((double)b_i + 1.0) / ((laynum + 1.0) - ((double)b_i + 1.0));
    deltx_data[b_i] = (M2_idx_0 + absxk * t) / (absxk + 1.0);
    delty_data[b_i] = (M1_idx_1 + absxk * M1_idx_0) / (absxk + 1.0);
    deltz_data[b_i] = (M2_idx_1 + absxk * scale) / (absxk + 1.0);
  }
  /*  定义法向量 */
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(normal_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    d = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    d = t * t;
  }
  absxk = fabs(normal_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    d = d * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d += t * t;
  }
  absxk = fabs(normal_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    d = d * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d += t * t;
  }
  d = scale * sqrt(d);
  if (d != 1.0) {
    v2_idx_0 = normal_idx_0 / d;
    v2_idx_1 = normal_idx_1 / d;
    v2_idx_2 = normal_idx_2 / d;
  }
  v1[0] = v2_idx_1 - v2_idx_2 * 0.0;
  v1[1] = v2_idx_2 * 0.0 - v2_idx_0;
  v1[2] = v2_idx_0 * 0.0 - v2_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(v1[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(v1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  t = v1[2] / scale;
  y += t * t;
  y = scale * sqrt(y);
  if (y < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v1[0] = v2_idx_1 * 0.0 - v2_idx_2;
    v1[1] = v2_idx_2 * 0.0 - v2_idx_0 * 0.0;
    v1[2] = v2_idx_0 - v2_idx_1 * 0.0;
  }
  scale = 3.3121686421112381E-170;
  absxk = fabs(v1[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(v1[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(v1[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  v1[0] /= y;
  v1[1] /= y;
  v1[2] /= y;
  /*  归一化向量 */
  /*  创建另一个垂直向量 */
  n2[0] = (v1[1] * v2_idx_2 - v2_idx_1 * v1[2]) * r;
  n2[1] = (v2_idx_0 * v1[2] - v1[0] * v2_idx_2) * r;
  n2[2] = (v1[0] * v2_idx_1 - v2_idx_0 * v1[1]) * r;
  v1[0] *= r;
  v1[1] *= r;
  v1[2] *= r;
  /*  使用参数方程生成单位圆上的点 */
  emxInit_real_T(&theta, 2);
  theta_data = theta->data;
  if (v1[0] > 0.0) {
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
        b_i = (int)d - 1;
        theta_data[(int)floor(num) - 1] = 2.0943951023931953;
        if (theta->size[1] >= 2) {
          theta_data[0] = -2.0943951023931953;
          if (theta->size[1] >= 3) {
            scale = 2.0943951023931953 / ((double)theta->size[1] - 1.0);
            for (k = 2; k <= b_i; k++) {
              theta_data[k - 1] =
                  (double)(((k << 1) - theta->size[1]) - 1) * scale;
            }
            if ((theta->size[1] & 1) == 1) {
              theta_data[theta->size[1] >> 1] = 0.0;
            }
          }
        }
      }
    }
  } else if (!(num >= 0.0)) {
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
      theta_data[(int)d - 1] = 5.2359877559829888;
      if (theta->size[1] >= 2) {
        theta_data[0] = 1.0471975511965976;
        if (theta->size[1] >= 3) {
          scale = 4.1887902047863914 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta_data[k + 1] = ((double)k + 1.0) * scale + 1.0471975511965976;
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
      x_circle_data[i] = z_circle_data[i] * v1[0] + theta_data[i] * n2[0];
    }
  } else {
    binary_expand_op_15(x_circle, z_circle, v1, theta, n2);
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
      y_circle_data[i] = z_circle_data[i] * v1[1] + theta_data[i] * n2[1];
    }
  } else {
    binary_expand_op_14(y_circle, z_circle, v1, theta, n2);
    y_circle_data = y_circle->data;
  }
  if (z_circle->size[1] == theta->size[1]) {
    b_i = z_circle->size[1] - 1;
    i = z_circle->size[0] * z_circle->size[1];
    z_circle->size[0] = 1;
    emxEnsureCapacity_real_T(z_circle, i);
    z_circle_data = z_circle->data;
    for (i = 0; i <= b_i; i++) {
      z_circle_data[i] = z_circle_data[i] * v1[2] + theta_data[i] * n2[2];
    }
  } else {
    binary_expand_op_10(z_circle, v1, theta, n2);
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
    scale = deltx_data[j];
    absxk = delty_data[j];
    t = deltz_data[j];
    b_i = x_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k)] = x_circle_data[k] + scale;
    }
    b_i = y_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 1] = y_circle_data[k] + absxk;
    }
    b_i = z_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 2] = z_circle_data[k] + t;
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
