/*
 * File: generate_unit_circle_with_normal_vector.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:46:36
 */

/* Include Files */
#include "generate_unit_circle_with_normal_vector.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <emscripten.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double t1
 *                double t2
 *                double num
 *                emxArray_real_T *x_circle1
 *                emxArray_real_T *y_circle1
 *                emxArray_real_T *z_circle1
 * Return Type  : void
 */
EMSCRIPTEN_KEEPALIVE
void generate_unit_circle_with_normal_vector(double t1, double t2, double num,
                                             emxArray_real_T *x_circle1,
                                             emxArray_real_T *y_circle1,
                                             emxArray_real_T *z_circle1)
{
  emxArray_real_T *theta;
  emxArray_real_T *x_circle;
  emxArray_real_T *y_circle;
  emxArray_real_T *z_circle;
  double absxk;
  double delta1;
  double normal_vector_idx_0;
  double normal_vector_idx_1;
  double normal_vector_idx_2;
  double scale;
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
  delta1 = cos(t1);
  /*  定义法向量 */
  normal_vector_idx_0 = delta1 * cos(t2);
  normal_vector_idx_1 = delta1 * sin(t2);
  normal_vector_idx_2 = sin(t1);
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(normal_vector_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    delta1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  absxk = fabs(normal_vector_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  absxk = fabs(normal_vector_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  delta1 = scale * sqrt(delta1);
  if (delta1 != 1.0) {
    normal_vector_idx_0 /= delta1;
    normal_vector_idx_1 /= delta1;
    normal_vector_idx_2 /= delta1;
  }
  /*  使用参数方程生成单位圆上的点 */
  emxInit_real_T(&theta, 2);
  if (!(num + 1.0 >= 0.0)) {
    theta->size[0] = 1;
    theta->size[1] = 0;
  } else {
    delta1 = floor(num + 1.0);
    i = theta->size[0] * theta->size[1];
    theta->size[0] = 1;
    theta->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(theta, i);
    if ((int)delta1 >= 1) {
      theta->data[(int)delta1 - 1] = 6.2831853071795862;
      if (theta->size[1] >= 2) {
        theta->data[0] = 0.0;
        if (theta->size[1] >= 3) {
          delta1 = 6.2831853071795862 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta->data[k + 1] = ((double)k + 1.0) * delta1;
          }
        }
      }
    }
  }
  v_idx_0 = normal_vector_idx_1 - normal_vector_idx_2 * 0.0;
  v_idx_1 = normal_vector_idx_2 * 0.0 - normal_vector_idx_0;
  v_idx_2 = normal_vector_idx_0 * 0.0 - normal_vector_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(v_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    delta1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  absxk = fabs(v_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  t = v_idx_2 / scale;
  delta1 += t * t;
  delta1 = scale * sqrt(delta1);
  if (delta1 < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v_idx_0 = normal_vector_idx_1 * 0.0 - normal_vector_idx_2;
    v_idx_1 = normal_vector_idx_2 * 0.0 - normal_vector_idx_0 * 0.0;
    v_idx_2 = normal_vector_idx_0 - normal_vector_idx_1 * 0.0;
  }
  scale = 3.3121686421112381E-170;
  absxk = fabs(v_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    delta1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  absxk = fabs(v_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  absxk = fabs(v_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  emxInit_real_T(&x_circle, 2);
  delta1 = scale * sqrt(delta1);
  v_idx_0 /= delta1;
  v_idx_1 /= delta1;
  v_idx_2 /= delta1;
  /*  归一化向量 */
  absxk = v_idx_1 * normal_vector_idx_2 - normal_vector_idx_1 * v_idx_2;
  scale = normal_vector_idx_0 * v_idx_2 - v_idx_0 * normal_vector_idx_2;
  delta1 = v_idx_0 * normal_vector_idx_1 - normal_vector_idx_0 * v_idx_1;
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
    y_circle->data[i] = y_circle->data[i] * v_idx_1 + z_circle->data[i] * scale;
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
    z_circle->data[i] = z_circle->data[i] * v_idx_2 + theta->data[i] * delta1;
  }
  emxFree_real_T(&theta);
  if (1 > x_circle->size[1] - 1) {
    nx = 0;
  } else {
    nx = x_circle->size[1] - 1;
  }
  i = x_circle1->size[0] * x_circle1->size[1];
  x_circle1->size[0] = 1;
  x_circle1->size[1] = nx;
  emxEnsureCapacity_real_T(x_circle1, i);
  for (i = 0; i < nx; i++) {
    x_circle1->data[i] = x_circle->data[i];
  }
  emxFree_real_T(&x_circle);
  if (1 > y_circle->size[1] - 1) {
    nx = 0;
  } else {
    nx = y_circle->size[1] - 1;
  }
  i = y_circle1->size[0] * y_circle1->size[1];
  y_circle1->size[0] = 1;
  y_circle1->size[1] = nx;
  emxEnsureCapacity_real_T(y_circle1, i);
  for (i = 0; i < nx; i++) {
    y_circle1->data[i] = y_circle->data[i];
  }
  emxFree_real_T(&y_circle);
  if (1 > z_circle->size[1] - 1) {
    nx = 0;
  } else {
    nx = z_circle->size[1] - 1;
  }
  i = z_circle1->size[0] * z_circle1->size[1];
  z_circle1->size[0] = 1;
  z_circle1->size[1] = nx;
  emxEnsureCapacity_real_T(z_circle1, i);
  for (i = 0; i < nx; i++) {
    z_circle1->data[i] = z_circle->data[i];
  }
  emxFree_real_T(&z_circle);
}

/*
 * File trailer for generate_unit_circle_with_normal_vector.c
 *
 * [EOF]
 */
