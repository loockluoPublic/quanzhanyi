/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 14:10:17
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector2.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void g_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const double in3[3], const emxArray_real_T *in4,
                               const double in5[3]);

static void h_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const double in3[3], const emxArray_real_T *in4,
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
static void g_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const double in3[3], const emxArray_real_T *in4,
                               const double in5[3])
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
  if (in4->size[1] == 1) {
    in1->size[1] = in2->size[1];
  } else {
    in1->size[1] = in4->size[1];
  }
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  if (in4->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in4->size[1];
  }
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
static void h_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const double in3[3], const emxArray_real_T *in4,
                               const double in5[3])
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
  if (in4->size[1] == 1) {
    in1->size[1] = in2->size[1];
  } else {
    in1->size[1] = in4->size[1];
  }
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  if (in4->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in4->size[1];
  }
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
  double lamuda;
  double t;
  double x0_tmp;
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
  int i;
  int i1;
  int j;
  int k;
  int nx;
  emxInit_real_T(&deltx, 2);
  emxInit_real_T(&delty, 2);
  emxInit_real_T(&deltz, 2);
  x0_tmp = cos(azimuth);
  Pl2_idx_2 = sin(azimuth);
  Pl2_idx_0 = x0_tmp * cos(elevation);
  Pl2_idx_1 = x0_tmp * sin(elevation);
  /*  三个点定义 */
  /*  斜率计算 */
  x0_tmp =
      (Pl2_idx_0 * Pl2_idx_0 + Pl2_idx_1 * Pl2_idx_1) + Pl2_idx_2 * Pl2_idx_2;
  K = -(((0.0 - P1[0]) * Pl2_idx_0 + (0.0 - P1[1]) * Pl2_idx_1) +
        (0.0 - P1[2]) * Pl2_idx_2) /
      x0_tmp;
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * Pl2_idx_0;
  yN1 = K * Pl2_idx_1;
  zN1 = K * Pl2_idx_2;
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((0.0 - P2[0]) * Pl2_idx_0 + (0.0 - P2[1]) * Pl2_idx_1) +
        (0.0 - P2[2]) * Pl2_idx_2) /
      x0_tmp;
  /*  P1点在轴线上的投影坐标 */
  t = K * Pl2_idx_0;
  yN2 = K * Pl2_idx_1;
  x0_tmp = K * Pl2_idx_2;
  k = deltx->size[0] * deltx->size[1];
  deltx->size[0] = 1;
  i = (int)laynum;
  deltx->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(deltx, k);
  deltx_data = deltx->data;
  k = delty->size[0] * delty->size[1];
  delty->size[0] = 1;
  delty->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(delty, k);
  delty_data = delty->data;
  k = deltz->size[0] * deltz->size[1];
  deltz->size[0] = 1;
  deltz->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(deltz, k);
  deltz_data = deltz->data;
  for (nx = 0; nx < i; nx++) {
    lamuda = ((double)nx + 1.0) / ((laynum + 1.0) - ((double)nx + 1.0));
    deltx_data[nx] = (xN1 + lamuda * t) / (lamuda + 1.0);
    delty_data[nx] = (yN1 + lamuda * yN2) / (lamuda + 1.0);
    deltz_data[nx] = (zN1 + lamuda * x0_tmp) / (lamuda + 1.0);
  }
  /*  定义法向量 */
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  K = 3.3121686421112381E-170;
  lamuda = fabs(Pl2_idx_0);
  if (lamuda > 3.3121686421112381E-170) {
    x0_tmp = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    x0_tmp = t * t;
  }
  lamuda = fabs(Pl2_idx_1);
  if (lamuda > K) {
    t = K / lamuda;
    x0_tmp = x0_tmp * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    x0_tmp += t * t;
  }
  lamuda = fabs(Pl2_idx_2);
  if (lamuda > K) {
    t = K / lamuda;
    x0_tmp = x0_tmp * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    x0_tmp += t * t;
  }
  x0_tmp = K * sqrt(x0_tmp);
  if (x0_tmp != 1.0) {
    Pl2_idx_0 /= x0_tmp;
    Pl2_idx_1 /= x0_tmp;
    Pl2_idx_2 /= x0_tmp;
  }
  /*  使用参数方程生成单位圆上的点 */
  emxInit_real_T(&theta, 2);
  if (azimuth > 3.1415926535897931) {
    if (elevation < 3.1415926535897931) {
      linspace(num, theta);
      theta_data = theta->data;
    } else {
      b_linspace(num, theta);
      theta_data = theta->data;
    }
  } else if (elevation < 3.1415926535897931) {
    b_linspace(num, theta);
    theta_data = theta->data;
  } else {
    linspace(num, theta);
    theta_data = theta->data;
  }
  v[0] = Pl2_idx_1 - Pl2_idx_2 * 0.0;
  v[1] = Pl2_idx_2 * 0.0 - Pl2_idx_0;
  v[2] = Pl2_idx_0 * 0.0 - Pl2_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  K = 3.3121686421112381E-170;
  lamuda = fabs(v[0]);
  if (lamuda > 3.3121686421112381E-170) {
    x0_tmp = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    x0_tmp = t * t;
  }
  lamuda = fabs(v[1]);
  if (lamuda > K) {
    t = K / lamuda;
    x0_tmp = x0_tmp * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    x0_tmp += t * t;
  }
  t = v[2] / K;
  x0_tmp += t * t;
  x0_tmp = K * sqrt(x0_tmp);
  if (x0_tmp < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v[0] = Pl2_idx_1 * 0.0 - Pl2_idx_2;
    v[1] = Pl2_idx_2 * 0.0 - Pl2_idx_0 * 0.0;
    v[2] = Pl2_idx_0 - Pl2_idx_1 * 0.0;
  }
  K = 3.3121686421112381E-170;
  lamuda = fabs(v[0]);
  if (lamuda > 3.3121686421112381E-170) {
    x0_tmp = 1.0;
    K = lamuda;
  } else {
    t = lamuda / 3.3121686421112381E-170;
    x0_tmp = t * t;
  }
  lamuda = fabs(v[1]);
  if (lamuda > K) {
    t = K / lamuda;
    x0_tmp = x0_tmp * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    x0_tmp += t * t;
  }
  lamuda = fabs(v[2]);
  if (lamuda > K) {
    t = K / lamuda;
    x0_tmp = x0_tmp * t * t + 1.0;
    K = lamuda;
  } else {
    t = lamuda / K;
    x0_tmp += t * t;
  }
  emxInit_real_T(&z_circle, 2);
  x0_tmp = K * sqrt(x0_tmp);
  v[0] /= x0_tmp;
  v[1] /= x0_tmp;
  v[2] /= x0_tmp;
  /*  归一化向量 */
  u[0] = v[1] * Pl2_idx_2 - Pl2_idx_1 * v[2];
  u[1] = Pl2_idx_0 * v[2] - v[0] * Pl2_idx_2;
  u[2] = v[0] * Pl2_idx_1 - Pl2_idx_0 * v[1];
  /*  创建另一个垂直向量 */
  /*  单位圆的参数方程 */
  k = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, k);
  z_circle_data = z_circle->data;
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    z_circle_data[k] = theta_data[k];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    z_circle_data[k] = cos(z_circle_data[k]);
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    theta_data[k] = sin(theta_data[k]);
  }
  emxInit_real_T(&x_circle, 2);
  if (z_circle->size[1] == theta->size[1]) {
    k = x_circle->size[0] * x_circle->size[1];
    x_circle->size[0] = 1;
    x_circle->size[1] = z_circle->size[1];
    emxEnsureCapacity_real_T(x_circle, k);
    x_circle_data = x_circle->data;
    nx = z_circle->size[1];
    for (k = 0; k < nx; k++) {
      x_circle_data[k] = z_circle_data[k] * v[0] + theta_data[k] * u[0];
    }
  } else {
    h_binary_expand_op(x_circle, z_circle, v, theta, u);
    x_circle_data = x_circle->data;
  }
  emxInit_real_T(&y_circle, 2);
  if (z_circle->size[1] == theta->size[1]) {
    k = y_circle->size[0] * y_circle->size[1];
    y_circle->size[0] = 1;
    y_circle->size[1] = z_circle->size[1];
    emxEnsureCapacity_real_T(y_circle, k);
    y_circle_data = y_circle->data;
    nx = z_circle->size[1];
    for (k = 0; k < nx; k++) {
      y_circle_data[k] = z_circle_data[k] * v[1] + theta_data[k] * u[1];
    }
  } else {
    g_binary_expand_op(y_circle, z_circle, v, theta, u);
    y_circle_data = y_circle->data;
  }
  if (z_circle->size[1] == theta->size[1]) {
    nx = z_circle->size[1] - 1;
    k = z_circle->size[0] * z_circle->size[1];
    z_circle->size[0] = 1;
    emxEnsureCapacity_real_T(z_circle, k);
    z_circle_data = z_circle->data;
    for (k = 0; k <= nx; k++) {
      z_circle_data[k] = z_circle_data[k] * v[2] + theta_data[k] * u[2];
    }
  } else {
    d_binary_expand_op(z_circle, v, theta, u);
    z_circle_data = z_circle->data;
  }
  emxFree_real_T(&theta);
  k = Point_out->size[0] * Point_out->size[1];
  Point_out->size[0] = 3;
  i1 = (int)(num * laynum);
  Point_out->size[1] = i1;
  emxEnsureCapacity_real_T(Point_out, k);
  theta_data = Point_out->data;
  nx = 3 * i1;
  for (k = 0; k < nx; k++) {
    theta_data[k] = 0.0;
  }
  for (j = 0; j < i; j++) {
    x0_tmp = (((double)j + 1.0) - 1.0) * num + 1.0;
    if (x0_tmp > ((double)j + 1.0) * num) {
      k = 0;
    } else {
      k = (int)x0_tmp - 1;
    }
    x0_tmp = deltx_data[j];
    K = delty_data[j];
    lamuda = deltz_data[j];
    nx = x_circle->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      theta_data[3 * (k + i1)] = x_circle_data[i1] + x0_tmp;
    }
    nx = y_circle->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      theta_data[3 * (k + i1) + 1] = y_circle_data[i1] + K;
    }
    nx = z_circle->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      theta_data[3 * (k + i1) + 2] = z_circle_data[i1] + lamuda;
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
