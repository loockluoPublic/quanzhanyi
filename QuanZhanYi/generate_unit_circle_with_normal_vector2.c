/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double azimuth
 *                double elevation
 *                double num
 *                const double P1[3]
 *                const double P2[3]
 *                emxArray_real_T *Point_out
 * Return Type  : void
 */
void generate_unit_circle_with_normal_vector2(double azimuth, double elevation,
                                              double num, const double P1[3],
                                              const double P2[3],
                                              emxArray_real_T *Point_out)
{
  emxArray_real_T *theta;
  emxArray_real_T *x_circle;
  emxArray_real_T *y_circle;
  emxArray_real_T *z_circle;
  double K;
  double Pl2_idx_0;
  double Pl2_idx_1;
  double Pl2_idx_2;
  double absxk;
  double b_K;
  double midx;
  double midy;
  double midz;
  double t;
  double v_idx_0;
  double v_idx_1;
  double v_idx_2;
  int i;
  int k;
  int loop_ub;
  int nx;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  K = cos(azimuth);
  Pl2_idx_2 = sin(azimuth);
  Pl2_idx_0 = K * cos(elevation);
  Pl2_idx_1 = K * sin(elevation);
  /*  三个点定义 */
  /*  斜率计算 */
  K = (Pl2_idx_0 * Pl2_idx_0 + Pl2_idx_1 * Pl2_idx_1) + Pl2_idx_2 * Pl2_idx_2;
  b_K = -(((0.0 - P1[0]) * Pl2_idx_0 + (0.0 - P1[1]) * Pl2_idx_1) +
          (0.0 - P1[2]) * Pl2_idx_2) /
        K;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((0.0 - P2[0]) * Pl2_idx_0 + (0.0 - P2[1]) * Pl2_idx_1) +
        (0.0 - P2[2]) * Pl2_idx_2) /
      K;
  /*  P1点在轴线上的投影坐标 */
  midx = (b_K * Pl2_idx_0 + K * Pl2_idx_0) / 2.0;
  midy = (b_K * Pl2_idx_1 + K * Pl2_idx_1) / 2.0;
  midz = (b_K * Pl2_idx_2 + K * Pl2_idx_2) / 2.0;
  /*  定义法向量 */
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  b_K = 3.3121686421112381E-170;
  absxk = fabs(Pl2_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    b_K = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  absxk = fabs(Pl2_idx_1);
  if (absxk > b_K) {
    t = b_K / absxk;
    K = K * t * t + 1.0;
    b_K = absxk;
  } else {
    t = absxk / b_K;
    K += t * t;
  }
  absxk = fabs(Pl2_idx_2);
  if (absxk > b_K) {
    t = b_K / absxk;
    K = K * t * t + 1.0;
    b_K = absxk;
  } else {
    t = absxk / b_K;
    K += t * t;
  }
  K = b_K * sqrt(K);
  if (K != 1.0) {
    Pl2_idx_0 /= K;
    Pl2_idx_1 /= K;
    Pl2_idx_2 /= K;
  }
  emxInit_real_T(&theta, 2);
  /*  使用参数方程生成单位圆上的点 */
  linspace(num + 1.0, theta);
  v_idx_0 = Pl2_idx_1 - Pl2_idx_2 * 0.0;
  v_idx_1 = Pl2_idx_2 * 0.0 - Pl2_idx_0;
  v_idx_2 = Pl2_idx_0 * 0.0 - Pl2_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  b_K = 3.3121686421112381E-170;
  absxk = fabs(v_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    b_K = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  absxk = fabs(v_idx_1);
  if (absxk > b_K) {
    t = b_K / absxk;
    K = K * t * t + 1.0;
    b_K = absxk;
  } else {
    t = absxk / b_K;
    K += t * t;
  }
  t = v_idx_2 / b_K;
  K += t * t;
  K = b_K * sqrt(K);
  if (K < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v_idx_0 = Pl2_idx_1 * 0.0 - Pl2_idx_2;
    v_idx_1 = Pl2_idx_2 * 0.0 - Pl2_idx_0 * 0.0;
    v_idx_2 = Pl2_idx_0 - Pl2_idx_1 * 0.0;
  }
  b_K = 3.3121686421112381E-170;
  absxk = fabs(v_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    b_K = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  absxk = fabs(v_idx_1);
  if (absxk > b_K) {
    t = b_K / absxk;
    K = K * t * t + 1.0;
    b_K = absxk;
  } else {
    t = absxk / b_K;
    K += t * t;
  }
  absxk = fabs(v_idx_2);
  if (absxk > b_K) {
    t = b_K / absxk;
    K = K * t * t + 1.0;
    b_K = absxk;
  } else {
    t = absxk / b_K;
    K += t * t;
  }
  emxInit_real_T(&x_circle, 2);
  K = b_K * sqrt(K);
  v_idx_0 /= K;
  v_idx_1 /= K;
  v_idx_2 /= K;
  /*  归一化向量 */
  absxk = v_idx_1 * Pl2_idx_2 - Pl2_idx_1 * v_idx_2;
  b_K = Pl2_idx_0 * v_idx_2 - v_idx_0 * Pl2_idx_2;
  K = v_idx_0 * Pl2_idx_1 - Pl2_idx_0 * v_idx_1;
  /*  创建另一个垂直向量 */
  /*  单位圆的参数方程 */
  i = x_circle->size[0] * x_circle->size[1];
  x_circle->size[0] = 1;
  x_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(x_circle, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    x_circle->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    x_circle->data[k] = cos(x_circle->data[k]);
  }
  emxInit_real_T(&z_circle, 2);
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    z_circle->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    z_circle->data[k] = sin(z_circle->data[k]);
  }
  i = x_circle->size[0] * x_circle->size[1];
  x_circle->size[0] = 1;
  emxEnsureCapacity_real_T(x_circle, i);
  nx = x_circle->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    x_circle->data[i] = x_circle->data[i] * v_idx_0 + z_circle->data[i] * absxk;
  }
  emxInit_real_T(&y_circle, 2);
  i = y_circle->size[0] * y_circle->size[1];
  y_circle->size[0] = 1;
  y_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(y_circle, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    y_circle->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    y_circle->data[k] = cos(y_circle->data[k]);
  }
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    z_circle->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    z_circle->data[k] = sin(z_circle->data[k]);
  }
  i = y_circle->size[0] * y_circle->size[1];
  y_circle->size[0] = 1;
  emxEnsureCapacity_real_T(y_circle, i);
  nx = y_circle->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    y_circle->data[i] = y_circle->data[i] * v_idx_1 + z_circle->data[i] * b_K;
  }
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    z_circle->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    z_circle->data[k] = cos(z_circle->data[k]);
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    theta->data[k] = sin(theta->data[k]);
  }
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  emxEnsureCapacity_real_T(z_circle, i);
  nx = z_circle->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    z_circle->data[i] = z_circle->data[i] * v_idx_2 + theta->data[i] * K;
  }
  emxFree_real_T(&theta);
  if (1 > x_circle->size[1] - 1) {
    nx = 0;
  } else {
    nx = x_circle->size[1] - 1;
  }
  if (1 > y_circle->size[1] - 1) {
    k = 1;
  } else {
    k = y_circle->size[1];
  }
  if (1 > z_circle->size[1] - 1) {
    loop_ub = 1;
  } else {
    loop_ub = z_circle->size[1];
  }
  i = Point_out->size[0] * Point_out->size[1];
  Point_out->size[0] = 3;
  Point_out->size[1] = nx;
  emxEnsureCapacity_real_T(Point_out, i);
  for (i = 0; i < nx; i++) {
    Point_out->data[3 * i] = x_circle->data[i] + midx;
  }
  emxFree_real_T(&x_circle);
  for (i = 0; i <= k - 2; i++) {
    Point_out->data[3 * i + 1] = y_circle->data[i] + midy;
  }
  emxFree_real_T(&y_circle);
  for (i = 0; i <= loop_ub - 2; i++) {
    Point_out->data[3 * i + 2] = z_circle->data[i] + midz;
  }
  emxFree_real_T(&z_circle);
}

/*
 * File trailer for generate_unit_circle_with_normal_vector2.c
 *
 * [EOF]
 */
