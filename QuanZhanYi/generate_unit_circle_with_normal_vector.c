/*
 * File: generate_unit_circle_with_normal_vector.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 13:55:20
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

/* Function Declarations */
static void b_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                               const emxArray_real_T *in3, const double in4[3]);

static void binary_expand_op(emxArray_real_T *in1, const double in2[3],
                             const emxArray_real_T *in3, const double in4[3]);

static void c_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                               const emxArray_real_T *in3, const double in4[3]);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const double in2[3]
 *                const emxArray_real_T *in3
 *                const double in4[3]
 * Return Type  : void
 */
static void b_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                               const emxArray_real_T *in3, const double in4[3])
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double b_in2;
  double b_in4;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  b_in2 = in2[1];
  b_in4 = in4[1];
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in3->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] =
        in1_data[i * stride_0_1] * b_in2 + in3_data[i * stride_1_1] * b_in4;
  }
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
 * Arguments    : emxArray_real_T *in1
 *                const double in2[3]
 *                const emxArray_real_T *in3
 *                const double in4[3]
 * Return Type  : void
 */
static void binary_expand_op(emxArray_real_T *in1, const double in2[3],
                             const emxArray_real_T *in3, const double in4[3])
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double b_in2;
  double b_in4;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  b_in2 = in2[2];
  b_in4 = in4[2];
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in3->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] =
        in1_data[i * stride_0_1] * b_in2 + in3_data[i * stride_1_1] * b_in4;
  }
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
 * Arguments    : emxArray_real_T *in1
 *                const double in2[3]
 *                const emxArray_real_T *in3
 *                const double in4[3]
 * Return Type  : void
 */
EMSCRIPTEN_KEEPALIVE
static void c_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                               const emxArray_real_T *in3, const double in4[3])
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double b_in2;
  double b_in4;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  b_in2 = in2[0];
  b_in4 = in4[0];
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in3->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] =
        in1_data[i * stride_0_1] * b_in2 + in3_data[i * stride_1_1] * b_in4;
  }
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
 * Arguments    : double t1
 *                double t2
 *                double num
 *                emxArray_real_T *x_circle
 *                emxArray_real_T *y_circle
 *                emxArray_real_T *z_circle
 * Return Type  : void
 */
EMSCRIPTEN_KEEPALIVE
void generate_unit_circle_with_normal_vector(double t1, double t2, double num,
                                             emxArray_real_T *x_circle,
                                             emxArray_real_T *y_circle,
                                             emxArray_real_T *z_circle)
{
  emxArray_real_T *a;
  emxArray_real_T *theta;
  double u[3];
  double v[3];
  double absxk;
  double delta1;
  double normal_vector_idx_0;
  double normal_vector_idx_1;
  double normal_vector_idx_2;
  double scale;
  double t;
  double *a_data;
  double *theta_data;
  double *x_circle_data;
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
  theta_data = theta->data;
  if (!(num + 1.0 >= 0.0)) {
    theta->size[0] = 1;
    theta->size[1] = 0;
  } else {
    delta1 = floor(num + 1.0);
    i = theta->size[0] * theta->size[1];
    theta->size[0] = 1;
    theta->size[1] = (int)delta1;
    emxEnsureCapacity_real_T(theta, i);
    theta_data = theta->data;
    if ((int)delta1 >= 1) {
      theta_data[(int)delta1 - 1] = 6.2831853071795862;
      if (theta->size[1] >= 2) {
        theta_data[0] = 0.0;
        if (theta->size[1] >= 3) {
          delta1 = 6.2831853071795862 / ((double)theta->size[1] - 1.0);
          i = theta->size[1];
          for (k = 0; k <= i - 3; k++) {
            theta_data[k + 1] = ((double)k + 1.0) * delta1;
          }
        }
      }
    }
  }
  v[0] = normal_vector_idx_1 - normal_vector_idx_2 * 0.0;
  v[1] = normal_vector_idx_2 * 0.0 - normal_vector_idx_0;
  v[2] = normal_vector_idx_0 * 0.0 - normal_vector_idx_1 * 0.0;
  /*  找到与法向量垂直的一个向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(v[0]);
  if (absxk > 3.3121686421112381E-170) {
    delta1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  absxk = fabs(v[1]);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  t = v[2] / scale;
  delta1 += t * t;
  delta1 = scale * sqrt(delta1);
  if (delta1 < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    v[0] = normal_vector_idx_1 * 0.0 - normal_vector_idx_2;
    v[1] = normal_vector_idx_2 * 0.0 - normal_vector_idx_0 * 0.0;
    v[2] = normal_vector_idx_0 - normal_vector_idx_1 * 0.0;
  }
  scale = 3.3121686421112381E-170;
  absxk = fabs(v[0]);
  if (absxk > 3.3121686421112381E-170) {
    delta1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    delta1 = t * t;
  }
  absxk = fabs(v[1]);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  absxk = fabs(v[2]);
  if (absxk > scale) {
    t = scale / absxk;
    delta1 = delta1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    delta1 += t * t;
  }
  delta1 = scale * sqrt(delta1);
  v[0] /= delta1;
  v[1] /= delta1;
  v[2] /= delta1;
  /*  归一化向量 */
  u[0] = v[1] * normal_vector_idx_2 - normal_vector_idx_1 * v[2];
  u[1] = normal_vector_idx_0 * v[2] - v[0] * normal_vector_idx_2;
  u[2] = v[0] * normal_vector_idx_1 - normal_vector_idx_0 * v[1];
  /*  创建另一个垂直向量 */
  /*  单位圆的参数方程 */
  i = x_circle->size[0] * x_circle->size[1];
  x_circle->size[0] = 1;
  x_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(x_circle, i);
  x_circle_data = x_circle->data;
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    x_circle_data[i] = theta_data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    x_circle_data[k] = cos(x_circle_data[k]);
  }
  emxInit_real_T(&a, 2);
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(a, i);
  a_data = a->data;
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    a_data[i] = theta_data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    a_data[k] = sin(a_data[k]);
  }
  if (x_circle->size[1] == a->size[1]) {
    nx = x_circle->size[1] - 1;
    i = x_circle->size[0] * x_circle->size[1];
    x_circle->size[0] = 1;
    emxEnsureCapacity_real_T(x_circle, i);
    x_circle_data = x_circle->data;
    for (i = 0; i <= nx; i++) {
      x_circle_data[i] = x_circle_data[i] * v[0] + a_data[i] * u[0];
    }
  } else {
    c_binary_expand_op(x_circle, v, a, u);
  }
  i = y_circle->size[0] * y_circle->size[1];
  y_circle->size[0] = 1;
  y_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(y_circle, i);
  x_circle_data = y_circle->data;
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    x_circle_data[i] = theta_data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    x_circle_data[k] = cos(x_circle_data[k]);
  }
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(a, i);
  a_data = a->data;
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    a_data[i] = theta_data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    a_data[k] = sin(a_data[k]);
  }
  if (y_circle->size[1] == a->size[1]) {
    nx = y_circle->size[1] - 1;
    i = y_circle->size[0] * y_circle->size[1];
    y_circle->size[0] = 1;
    emxEnsureCapacity_real_T(y_circle, i);
    x_circle_data = y_circle->data;
    for (i = 0; i <= nx; i++) {
      x_circle_data[i] = x_circle_data[i] * v[1] + a_data[i] * u[1];
    }
  } else {
    b_binary_expand_op(y_circle, v, a, u);
  }
  emxFree_real_T(&a);
  i = z_circle->size[0] * z_circle->size[1];
  z_circle->size[0] = 1;
  z_circle->size[1] = theta->size[1];
  emxEnsureCapacity_real_T(z_circle, i);
  x_circle_data = z_circle->data;
  nx = theta->size[1];
  for (i = 0; i < nx; i++) {
    x_circle_data[i] = theta_data[i];
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    x_circle_data[k] = cos(x_circle_data[k]);
  }
  nx = theta->size[1];
  for (k = 0; k < nx; k++) {
    theta_data[k] = sin(theta_data[k]);
  }
  if (z_circle->size[1] == theta->size[1]) {
    nx = z_circle->size[1] - 1;
    i = z_circle->size[0] * z_circle->size[1];
    z_circle->size[0] = 1;
    emxEnsureCapacity_real_T(z_circle, i);
    x_circle_data = z_circle->data;
    for (i = 0; i <= nx; i++) {
      x_circle_data[i] = x_circle_data[i] * v[2] + theta_data[i] * u[2];
    }
  } else {
    binary_expand_op(z_circle, v, theta, u);
  }
  emxFree_real_T(&theta);
  i = x_circle->size[0] * x_circle->size[1];
  if (x_circle->size[1] - 1 < 1) {
    x_circle->size[1] = 0;
  } else {
    x_circle->size[1]--;
  }
  emxEnsureCapacity_real_T(x_circle, i);
  i = y_circle->size[0] * y_circle->size[1];
  if (y_circle->size[1] - 1 < 1) {
    y_circle->size[1] = 0;
  } else {
    y_circle->size[1]--;
  }
  emxEnsureCapacity_real_T(y_circle, i);
  i = z_circle->size[0] * z_circle->size[1];
  if (z_circle->size[1] - 1 < 1) {
    z_circle->size[1] = 0;
  } else {
    z_circle->size[1]--;
  }
  emxEnsureCapacity_real_T(z_circle, i);
}

/*
 * File trailer for generate_unit_circle_with_normal_vector.c
 *
 * [EOF]
 */
