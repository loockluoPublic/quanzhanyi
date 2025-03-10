/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 22:41:07
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * -----------------------平均轴向量、圆心-----------------------
 *
 * Arguments    : const emxArray_real_T *Point_out
 *                double num
 *                double laynum
 *                const double P3[3]
 *                const double P4[3]
 *                double r
 *                emxArray_real_T *Point_test
 * Return Type  : void
 */
void Generate_multi_layered_measurement_points(const emxArray_real_T *Point_out,
                                               double num, double laynum,
                                               const double P3[3],
                                               const double P4[3], double r,
                                               emxArray_real_T *Point_test)
{
  emxArray_real_T *Dist;
  emxArray_real_T *Layer;
  emxArray_real_T *Point_out1;
  emxArray_real_T *Ylay0;
  emxArray_real_T *Zlay0;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  double p23f[3];
  double p3[3];
  const double *Point_out_data;
  double Radius;
  double S_idx_0;
  double absxk;
  double ds;
  double p12f_idx_0;
  double p12f_idx_1;
  double p23_idx_0;
  double p23_idx_1;
  double p2_idx_0;
  double p2_idx_1;
  double p2_idx_2;
  double pf_idx_0;
  double pf_idx_1;
  double pf_idx_2;
  double scale;
  double t;
  double *Dist_data;
  double *Point_out1_data;
  double *Ylay0_data;
  double *Zlay0_data;
  double *x_data;
  double *y_data;
  double *z_data;
  int b_i;
  int i;
  int i1;
  int k;
  int loop_ub;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Point_out_data = Point_out->data;
  emxInit_real_T(&x, 1);
  i = x->size[0];
  x->size[0] = Point_out->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  loop_ub = Point_out->size[1];
  emxInit_real_T(&y, 1);
  i = y->size[0];
  y->size[0] = Point_out->size[1];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  emxInit_real_T(&z, 1);
  i = z->size[0];
  z->size[0] = Point_out->size[1];
  emxEnsureCapacity_real_T(z, i);
  z_data = z->data;
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = Point_out_data[3 * i];
    y_data[i] = Point_out_data[3 * i + 1];
    z_data[i] = Point_out_data[3 * i + 2];
  }
  /*  [s1,s2,s3,xcenter,ycenter,zcenter] =
   * Three_Points_Initial_Rough_Cylindrical_Judgment(xxx,yyy,zzz); */
  /* %%%%%%%%%%%%%%%%%%%% */
  /*  两条线段的重点，之后需要求中垂线 */
  p2_idx_2 = x_data[0] - x_data[1];
  p23f[0] = x_data[0] - x_data[2];
  p12f_idx_1 = y_data[0] - y_data[1];
  p23f[1] = y_data[0] - y_data[2];
  ds = z_data[0] - z_data[1];
  p23f[2] = z_data[0] - z_data[2];
  pf_idx_0 = p12f_idx_1 * p23f[2] - p23f[1] * ds;
  pf_idx_1 = p23f[0] * ds - p2_idx_2 * p23f[2];
  pf_idx_2 = p2_idx_2 * p23f[1] - p23f[0] * p12f_idx_1;
  /*  求两条线的中垂线 */
  p12f_idx_0 = pf_idx_1 * ds - p12f_idx_1 * pf_idx_2;
  p12f_idx_1 = p2_idx_2 * pf_idx_2 - pf_idx_0 * ds;
  p23_idx_0 = (x_data[1] + x_data[2]) / 2.0;
  p2_idx_0 = x_data[1] - x_data[2];
  p23_idx_1 = (y_data[1] + y_data[2]) / 2.0;
  p2_idx_1 = y_data[1] - y_data[2];
  p2_idx_2 = z_data[1] - z_data[2];
  p23f[0] = pf_idx_1 * p2_idx_2 - p2_idx_1 * pf_idx_2;
  p23f[1] = p2_idx_0 * pf_idx_2 - pf_idx_0 * p2_idx_2;
  /*  求在中垂线上投影的大小 */
  ds = (((y_data[0] + y_data[1]) / 2.0 - p23_idx_1) * p12f_idx_0 -
        ((x_data[0] + x_data[1]) / 2.0 - p23_idx_0) * p12f_idx_1) /
       (p12f_idx_0 * p23f[1] - p23f[0] * p12f_idx_1);
  /*  得出距离 */
  /*  radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2); */
  scale = 3.3121686421112381E-170;
  p23_idx_0 += p23f[0] * ds;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    p12f_idx_1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p12f_idx_1 = t * t;
  }
  p23_idx_1 += p23f[1] * ds;
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_1 = p12f_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_1 += t * t;
  }
  p12f_idx_0 = (z_data[1] + z_data[2]) / 2.0 +
               (pf_idx_0 * p2_idx_1 - p2_idx_0 * pf_idx_1) * ds;
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_1 = p12f_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_1 += t * t;
  }
  p12f_idx_1 = scale * sqrt(p12f_idx_1);
  pf_idx_0 /= p12f_idx_1;
  pf_idx_1 /= p12f_idx_1;
  pf_idx_2 /= p12f_idx_1;
  /* %%%%%%%%%%%%%%%%%%% */
  /*  -----------------------------计算参数------------------------------- */
  emxInit_real_T(&Dist, 2);
  i = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  Dist->size[1] = x->size[0];
  emxEnsureCapacity_real_T(Dist, i);
  Dist_data = Dist->data;
  loop_ub = x->size[0];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    p12f_idx_1 = x_data[b_i] - p23_idx_0;
    p2_idx_2 = y_data[b_i] - p23_idx_1;
    ds = z_data[b_i] - p12f_idx_0;
    Dist_data[b_i] =
        sqrt((p12f_idx_1 * p12f_idx_1 + p2_idx_2 * p2_idx_2) + ds * ds);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  Radius = mean(Dist);
  scale = 3.3121686421112381E-170;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    p12f_idx_1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p12f_idx_1 = t * t;
  }
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_1 = p12f_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_1 += t * t;
  }
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_1 = p12f_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_1 += t * t;
  }
  p12f_idx_1 = scale * sqrt(p12f_idx_1);
  p3[0] = p23_idx_0;
  p3[1] = p23_idx_1;
  p3[2] = p12f_idx_0;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  pf_idx_0 /= p12f_idx_1;
  S_idx_0 = pf_idx_0;
  p23f[0] = p23_idx_0 + pf_idx_0;
  pf_idx_0 = pf_idx_1 / p12f_idx_1;
  p23_idx_0 = pf_idx_0;
  p23f[1] = p23_idx_1 + pf_idx_0;
  pf_idx_0 = pf_idx_2 / p12f_idx_1;
  p23f[2] = p12f_idx_0 + pf_idx_0;
  foot_of_perpendicular_from_a_point_to_a_line(P4, p3, p23f, &p12f_idx_1,
                                               &p2_idx_2, &p12f_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, p3, p23f, &ds, &p2_idx_0,
                                               &p2_idx_1);
  scale = 3.3121686421112381E-170;
  absxk = fabs(ds - p12f_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    ds = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    ds = t * t;
  }
  absxk = fabs(p2_idx_0 - p2_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    ds = ds * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    ds += t * t;
  }
  absxk = fabs(p2_idx_1 - p12f_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    ds = ds * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    ds += t * t;
  }
  ds = scale * sqrt(ds);
  /*  -----------------------------生成抽样点------------------------------- */
  emxInit_real_T(&Point_out1, 2);
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(pf_idx_0, sqrt(S_idx_0 * S_idx_0 + p23_idx_0 * p23_idx_0)),
      rt_atan2d_snf(p23_idx_0, S_idx_0), num, r, Point_out1);
  Point_out1_data = Point_out1->data;
  /*  ----------------------------移动到原点------------------------------- */
  i = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  Dist->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Dist, i);
  Dist_data = Dist->data;
  loop_ub = Point_out1->size[1];
  emxInit_real_T(&Ylay0, 2);
  i = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  Ylay0->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Ylay0, i);
  Ylay0_data = Ylay0->data;
  emxInit_real_T(&Zlay0, 2);
  i = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  Zlay0->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Zlay0, i);
  Zlay0_data = Zlay0->data;
  for (i = 0; i < loop_ub; i++) {
    Dist_data[i] = Point_out1_data[3 * i] * Radius + p12f_idx_1;
    Ylay0_data[i] = Point_out1_data[3 * i + 1] * Radius + p2_idx_2;
    Zlay0_data[i] = Point_out1_data[3 * i + 2] * Radius + p12f_idx_0;
  }
  emxFree_real_T(&Point_out1);
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  p2_idx_2 = 0.2 * ds;
  p12f_idx_1 = 0.8 * ds;
  emxInit_real_T(&Layer, 2);
  Point_out1_data = Layer->data;
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    ds = floor(laynum);
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)ds;
    emxEnsureCapacity_real_T(Layer, i);
    Point_out1_data = Layer->data;
    if ((int)ds >= 1) {
      loop_ub = (int)ds - 1;
      Point_out1_data[(int)floor(laynum) - 1] = p12f_idx_1;
      if (Layer->size[1] >= 2) {
        Point_out1_data[0] = p2_idx_2;
        if (Layer->size[1] >= 3) {
          if (p2_idx_2 == -p12f_idx_1) {
            p12f_idx_1 /= (double)Layer->size[1] - 1.0;
            for (k = 2; k <= loop_ub; k++) {
              Point_out1_data[k - 1] =
                  (double)(((k << 1) - Layer->size[1]) - 1) * p12f_idx_1;
            }
            if ((Layer->size[1] & 1) == 1) {
              Point_out1_data[Layer->size[1] >> 1] = 0.0;
            }
          } else {
            p12f_idx_1 =
                (p12f_idx_1 - p2_idx_2) / ((double)Layer->size[1] - 1.0);
            i = Layer->size[1];
            for (k = 0; k <= i - 3; k++) {
              Point_out1_data[k + 1] =
                  p2_idx_2 + ((double)k + 1.0) * p12f_idx_1;
            }
          }
        }
      }
    }
  }
  loop_ub = (int)(laynum * num);
  i = x->size[0];
  x->size[0] = loop_ub;
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = 0.0;
  }
  i = y->size[0];
  y->size[0] = loop_ub;
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = 0.0;
  }
  i = z->size[0];
  z->size[0] = loop_ub;
  emxEnsureCapacity_real_T(z, i);
  z_data = z->data;
  for (i = 0; i < loop_ub; i++) {
    z_data[i] = 0.0;
  }
  i = (int)laynum;
  for (b_i = 0; b_i < i; b_i++) {
    ds = (((double)b_i + 1.0) - 1.0) * num + 1.0;
    p12f_idx_1 = ((double)b_i + 1.0) * num;
    if (ds > p12f_idx_1) {
      k = 1;
    } else {
      k = (int)ds;
    }
    p2_idx_2 = Point_out1_data[b_i] * S_idx_0;
    loop_ub = Dist->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      x_data[(k + i1) - 1] = Dist_data[i1] - p2_idx_2;
    }
    if (ds > p12f_idx_1) {
      k = 1;
    } else {
      k = (int)ds;
    }
    p2_idx_2 = Point_out1_data[b_i] * p23_idx_0;
    loop_ub = Ylay0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      y_data[(k + i1) - 1] = Ylay0_data[i1] - p2_idx_2;
    }
    if (ds > p12f_idx_1) {
      k = 1;
    } else {
      k = (int)ds;
    }
    p2_idx_2 = Point_out1_data[b_i] * pf_idx_0;
    loop_ub = Zlay0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      z_data[(k + i1) - 1] = Zlay0_data[i1] - p2_idx_2;
    }
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&Dist);
  i = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = x->size[0];
  emxEnsureCapacity_real_T(Point_test, i);
  Point_out1_data = Point_test->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i] = x_data[i];
  }
  emxFree_real_T(&x);
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i + 1] = y_data[i];
  }
  emxFree_real_T(&y);
  loop_ub = z->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i + 2] = z_data[i];
  }
  emxFree_real_T(&z);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
