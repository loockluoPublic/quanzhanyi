/*
 * File: generate_unit_circle_with_normal_vector2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
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
  emxArray_real_T *a;
  emxArray_real_T *b_a;
  emxArray_real_T *c_a;
  emxArray_real_T *d_a;
  emxArray_real_T *e_a;
  emxArray_real_T *theta;
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
  /*  使用参数方程生成单位圆上的点 */
  emxInit_real_T(&theta, 2);
  if (!(num >= 0.0)) {
    theta->size[0] = 1;
    theta->size[1] = 0;
  } else {
    K = floor(num);
    i = theta->size[0] * theta->size[1];
    theta->size[0] = 1;
    theta->size[1] = (int)K;
    emxEnsureCapacity_real_T(theta, i);
    if ((int)K >= 1) {
      theta->data[(int)K - 1] = 5.7595865315812871;
      if (theta->size[1] >= 2) {
        theta->data[0] = 0.52359877559829882;
        if (theta->size[1] >= 3) {
          K = 5.2359877559829879 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta->data[k + 1] = ((double)k + 1.0) * K + 0.52359877559829882;
          }
        }
      }
    }
  }
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
  emxInit_real_T(&a, 2);
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
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(a, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    a->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    a->data[k] = cos(a->data[k]);
  }
  emxInit_real_T(&b_a, 2);
  i = b_a->size[0] * b_a->size[1];
  b_a->size[0] = 1;
  b_a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(b_a, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    b_a->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    b_a->data[k] = sin(b_a->data[k]);
  }
  emxInit_real_T(&c_a, 2);
  i = c_a->size[0] * c_a->size[1];
  c_a->size[0] = 1;
  c_a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(c_a, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    c_a->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    c_a->data[k] = cos(c_a->data[k]);
  }
  emxInit_real_T(&d_a, 2);
  i = d_a->size[0] * d_a->size[1];
  d_a->size[0] = 1;
  d_a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(d_a, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    d_a->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    d_a->data[k] = sin(d_a->data[k]);
  }
  emxInit_real_T(&e_a, 2);
  i = e_a->size[0] * e_a->size[1];
  e_a->size[0] = 1;
  e_a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(e_a, i);
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    e_a->data[i] = theta->data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    e_a->data[k] = cos(e_a->data[k]);
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    theta->data[k] = sin(theta->data[k]);
  }
  i = Point_out->size[0] * Point_out->size[1];
  Point_out->size[0] = 3;
  Point_out->size[1] = a->size[1];
  emxEnsureCapacity_real_T(Point_out, i);
  nx = a->size[1];
  for (i = 0; i < nx; i++) {
    Point_out->data[3 * i] =
        0.6 * (a->data[i] * v_idx_0 + b_a->data[i] * absxk) + midx;
  }
  emxFree_real_T(&b_a);
  emxFree_real_T(&a);
  nx = c_a->size[1];
  for (i = 0; i < nx; i++) {
    Point_out->data[3 * i + 1] =
        0.6 * (c_a->data[i] * v_idx_1 + d_a->data[i] * b_K) + midy;
  }
  emxFree_real_T(&d_a);
  emxFree_real_T(&c_a);
  nx = e_a->size[1];
  for (i = 0; i < nx; i++) {
    Point_out->data[3 * i + 2] =
        0.6 * (e_a->data[i] * v_idx_2 + theta->data[i] * K) + midz;
  }
  emxFree_real_T(&e_a);
  emxFree_real_T(&theta);
}

/*
 * File trailer for generate_unit_circle_with_normal_vector2.c
 *
 * [EOF]
 */
