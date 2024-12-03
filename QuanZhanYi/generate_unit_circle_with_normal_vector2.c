/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 02-Dec-2024 23:37:52
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_15(emxArray_real_T *in1,
                                const emxArray_real_T *in2, const double in3[3],
                                const emxArray_real_T *in4,
                                const double in5[3]);

static void binary_expand_op_16(emxArray_real_T *in1,
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
static void binary_expand_op_16(emxArray_real_T *in1,
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
 * Arguments    : double azimuth
 *                double elevation
 *                double num
 *                double laynum
 *                const double P1[3]
 *                const double P2[3]
 *                emxArray_real_T *Point_out
 * Return Type  : void
 */
void generate_unit_circle_with_normal_vector2(double azimuth, double elevation,
                                              double num, double laynum,
                                              const double P1[3],
                                              const double P2[3],
                                              emxArray_real_T *Point_out)
{

  emxArray_real_T *deltx;
  emxArray_real_T *delty;
  emxArray_real_T *deltz;
  emxArray_real_T *theta;
  emxArray_real_T *x_circle;
  emxArray_real_T *y_circle;
  emxArray_real_T *z_circle;
  double u[3];
  double v[3];
  double K;
  double Pl2_idx_0;
  double Pl2_idx_1;
  double Pl2_idx_2;
  double delta1;
  double lamuda;
  double t;
  double xN1;
  double yN1;
  double yN2;
  double zN1;
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
  delta1 = cos(azimuth);
  Pl2_idx_2 = sin(azimuth);
  Pl2_idx_0 = delta1 * cos(elevation);
  Pl2_idx_1 = delta1 * sin(elevation);
  /*  三个点定义 */
  /*  斜率计算 */
  delta1 =
      (Pl2_idx_0 * Pl2_idx_0 + Pl2_idx_1 * Pl2_idx_1) + Pl2_idx_2 * Pl2_idx_2;
  K = -(((0.0 - P1[0]) * Pl2_idx_0 + (0.0 - P1[1]) * Pl2_idx_1) +
        (0.0 - P1[2]) * Pl2_idx_2) /
      delta1;
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * Pl2_idx_0;
  yN1 = K * Pl2_idx_1;
  zN1 = K * Pl2_idx_2;
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((0.0 - P2[0]) * Pl2_idx_0 + (0.0 - P2[1]) * Pl2_idx_1) +
        (0.0 - P2[2]) * Pl2_idx_2) /
      delta1;
  /*  P1点在轴线上的投影坐标 */
  t = K * Pl2_idx_0;
  yN2 = K * Pl2_idx_1;
  delta1 = K * Pl2_idx_2;
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
    lamuda = ((double)b_i + 1.0) / ((laynum + 1.0) - ((double)b_i + 1.0));
    deltx_data[b_i] = (xN1 + lamuda * t) / (lamuda + 1.0);
    delty_data[b_i] = (yN1 + lamuda * yN2) / (lamuda + 1.0);
    deltz_data[b_i] = (zN1 + lamuda * delta1) / (lamuda + 1.0);
  }
  /*  定义法向量 */
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  K = 3.3121686421112381E-170;
  lamuda = fabs(Pl2_idx_0);
  if (lamuda > 3.3121686421112381E-170) {
    delta1 = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  lamuda = fabs(Pl2_idx_1);
  if (lamuda > K) {
    t = K / lamuda;
    delta1 = delta1 * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    delta1 += t * t;
  }
  lamuda = fabs(Pl2_idx_2);
  if (lamuda > K) {
    t = K / lamuda;
    delta1 = delta1 * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    delta1 += t * t;
  }
  delta1 = K * sqrt(delta1);
  if (delta1 != 1.0) {
    Pl2_idx_0 /= delta1;
    Pl2_idx_1 /= delta1;
    Pl2_idx_2 /= delta1;
  }
  v[0] = Pl2_idx_1 - Pl2_idx_2 * 0.0;
  v[1] = Pl2_idx_2 * 0.0 - Pl2_idx_0;
  v[2] = Pl2_idx_0 * 0.0 - Pl2_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  K = 3.3121686421112381E-170;
  lamuda = fabs(v[0]);
  if (lamuda > 3.3121686421112381E-170) {
    delta1 = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  lamuda = fabs(v[1]);
  if (lamuda > K) {
    t = K / lamuda;
    delta1 = delta1 * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    delta1 += t * t;
  }
  t = v[2] / K;
  delta1 += t * t;
  delta1 = K * sqrt(delta1);
  if (delta1 < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v[0] = Pl2_idx_1 * 0.0 - Pl2_idx_2;
    v[1] = Pl2_idx_2 * 0.0 - Pl2_idx_0 * 0.0;
    v[2] = Pl2_idx_0 - Pl2_idx_1 * 0.0;
  }
  K = 3.3121686421112381E-170;
  lamuda = fabs(v[0]);
  if (lamuda > 3.3121686421112381E-170) {
    delta1 = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  lamuda = fabs(v[1]);
  if (lamuda > K) {
    t = K / lamuda;
    delta1 = delta1 * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    delta1 += t * t;
  }
  lamuda = fabs(v[2]);
  if (lamuda > K) {
    t = K / lamuda;
    delta1 = delta1 * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    delta1 += t * t;
  }
  delta1 = K * sqrt(delta1);
  v[0] /= delta1;
  v[1] /= delta1;
  v[2] /= delta1;
  /*  归一化向量 */
  u[0] = v[1] * Pl2_idx_2 - Pl2_idx_1 * v[2];
  u[1] = Pl2_idx_0 * v[2] - v[0] * Pl2_idx_2;
  u[2] = v[0] * Pl2_idx_1 - Pl2_idx_0 * v[1];
  /*  创建另一个垂直向量 */
  /*  使用参数方程生成单位圆上的点 */
  emxInit_real_T(&theta, 2);
  theta_data = theta->data;
  if (v[0] > 0.0) {
    if (!(num >= 0.0)) {
      theta->size[0] = 1;
      theta->size[1] = 0;
    } else {
      delta1 = floor(num);
      i = theta->size[0] * theta->size[1];
      theta->size[0] = 1;
      theta->size[1] = (int)delta1;
      emxEnsureCapacity_real_T(theta, i);
      theta_data = theta->data;
      if ((int)delta1 >= 1) {
        b_i = (int)delta1 - 1;
        theta_data[(int)floor(num) - 1] = 2.0943951023931953;
        if (theta->size[1] >= 2) {
          theta_data[0] = -2.0943951023931953;
          if (theta->size[1] >= 3) {
            delta1 = 2.0943951023931953 / ((double)theta->size[1] - 1.0);
            for (k = 2; k <= b_i; k++) {
              theta_data[k - 1] =
                  (double)(((k << 1) - theta->size[1]) - 1) * delta1;
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
    delta1 = floor(num);
    i = theta->size[0] * theta->size[1];
    theta->size[0] = 1;
    theta->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(theta, i);
    theta_data = theta->data;
    if ((int)delta1 >= 1) {
      theta_data[(int)delta1 - 1] = 5.2359877559829888;
      if (theta->size[1] >= 2) {
        theta_data[0] = 1.0471975511965976;
        if (theta->size[1] >= 3) {
          delta1 = 4.1887902047863914 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta_data[k + 1] = ((double)k + 1.0) * delta1 + 1.0471975511965976;
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
    delta1 = theta_data[k];
    z_circle_data[k] = cos(delta1);
    delta1 = sin(delta1);
    theta_data[k] = delta1;
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
      x_circle_data[i] = z_circle_data[i] * v[0] + theta_data[i] * u[0];
    }
  } else {
    binary_expand_op_16(x_circle, z_circle, v, theta, u);
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
      y_circle_data[i] = z_circle_data[i] * v[1] + theta_data[i] * u[1];
    }
  } else {
    binary_expand_op_15(y_circle, z_circle, v, theta, u);
    y_circle_data = y_circle->data;
  }
  if (z_circle->size[1] == theta->size[1]) {
    b_i = z_circle->size[1] - 1;
    i = z_circle->size[0] * z_circle->size[1];
    z_circle->size[0] = 1;
    emxEnsureCapacity_real_T(z_circle, i);
    z_circle_data = z_circle->data;
    for (i = 0; i <= b_i; i++) {
      z_circle_data[i] = z_circle_data[i] * v[2] + theta_data[i] * u[2];
    }
  } else {
    binary_expand_op_11(z_circle, v, theta, u);
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
    delta1 = (((double)j + 1.0) - 1.0) * num + 1.0;
    if (delta1 > ((double)j + 1.0) * num) {
      i = 0;
    } else {
      i = (int)delta1 - 1;
    }
    delta1 = deltx_data[j];
    K = delty_data[j];
    lamuda = deltz_data[j];
    b_i = x_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k)] = x_circle_data[k] + delta1;
    }
    b_i = y_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 1] = y_circle_data[k] + K;
    }
    b_i = z_circle->size[1];
    for (k = 0; k < b_i; k++) {
      theta_data[3 * (i + k) + 2] = z_circle_data[k] + lamuda;
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
