/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 15:14:21
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "mean.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

/*
 * -----------------------平均轴向量、圆心-----------------------
 *
 * Arguments    : const emxArray_real_T *Point_out
 *                double num
 *                double laynum
 *                const double P3[3]
 *                const double P4[3]
 *                emxArray_real_T *Point_test
 * Return Type  : void
 */
void Generate_multi_layered_measurement_points(const emxArray_real_T *Point_out,
                                               double num, double laynum,
                                               const double P3[3],
                                               const double P4[3],
                                               emxArray_real_T *Point_test)
{
  printf("num = %f \n laynum = %f \n P3 = %f \n P4 = %f \n ", num, laynum,
         P3[0], P4[0]);
  printf(" Point_out->size[1] = %d \n", Point_out->size[1]);
  emxArray_real_T *Dist;
  emxArray_real_T *Layer;
  emxArray_real_T *Point_out1;
  emxArray_real_T *Point_testx;
  emxArray_real_T *Point_testy;
  emxArray_real_T *Point_testz;
  emxArray_real_T *Ylay0;
  emxArray_real_T *Zlay0;
  double p23f[3];
  double p3[3];
  const double *Point_out_data;
  double absxk;
  double p12f_idx_0;
  double p1_idx_0;
  double p1_idx_1;
  double p1_idx_2;
  double p23_idx_0;
  double p23_idx_1;
  double p23_idx_2;
  double p2_idx_0;
  double p2_idx_1;
  double p2_idx_2;
  double pf_idx_0;
  double pf_idx_1;
  double pf_idx_2;
  double pf_tmp_idx_0;
  double scale;
  double t;
  double *Dist_data;
  double *Point_out1_data;
  double *Point_testx_data;
  double *Point_testy_data;
  double *Point_testz_data;
  double *Ylay0_data;
  double *Zlay0_data;
  int b_i;
  int i;
  int i1;
  int k;
  int loop_ub;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Point_out_data = Point_out->data;
  /*  [s1,s2,s3,xcenter,ycenter,zcenter] =
   * Three_Points_Initial_Rough_Cylindrical_Judgment(xxx,yyy,zzz); */
  /* %%%%%%%%%%%%%%%%%%%% */
  p1_idx_0 = Point_out_data[0];
  p1_idx_1 = Point_out_data[1];
  p1_idx_2 = Point_out_data[2];
  p2_idx_0 = Point_out_data[3];
  p2_idx_1 = Point_out_data[4];
  p2_idx_2 = Point_out_data[5];
  p3[0] = Point_out_data[6];
  p3[1] = Point_out_data[7];
  p3[2] = Point_out_data[8];
  /*  两条线段的重点，之后需要求中垂线 */
  pf_tmp_idx_0 = p1_idx_0 - p2_idx_0;
  p23f[0] = p1_idx_0 - p3[0];
  p1_idx_0 = (p1_idx_0 + p2_idx_0) / 2.0;
  p12f_idx_0 = p1_idx_1 - p2_idx_1;
  p23f[1] = p1_idx_1 - p3[1];
  p1_idx_1 = (p1_idx_1 + p2_idx_1) / 2.0;
  p23_idx_0 = p1_idx_2 - p2_idx_2;
  p23f[2] = p1_idx_2 - p3[2];
  pf_idx_0 = p12f_idx_0 * p23f[2] - p23f[1] * p23_idx_0;
  pf_idx_1 = p23f[0] * p23_idx_0 - pf_tmp_idx_0 * p23f[2];
  pf_idx_2 = pf_tmp_idx_0 * p23f[1] - p23f[0] * p12f_idx_0;
  /*  求两条线的中垂线 */
  p12f_idx_0 = pf_idx_1 * p23_idx_0 - p12f_idx_0 * pf_idx_2;
  p1_idx_2 = pf_tmp_idx_0 * pf_idx_2 - pf_idx_0 * p23_idx_0;
  p23_idx_0 = (p2_idx_0 + p3[0]) / 2.0;
  p2_idx_0 -= p3[0];
  p23_idx_1 = (p2_idx_1 + p3[1]) / 2.0;
  p2_idx_1 -= p3[1];
  p23_idx_2 = (p2_idx_2 + p3[2]) / 2.0;
  p2_idx_2 -= p3[2];
  p23f[0] = pf_idx_1 * p2_idx_2 - p2_idx_1 * pf_idx_2;
  p23f[1] = p2_idx_0 * pf_idx_2 - pf_idx_0 * p2_idx_2;
  /*  求在中垂线上投影的大小 */
  p1_idx_2 = ((p1_idx_1 - p23_idx_1) * p12f_idx_0 -
              (p1_idx_0 - p23_idx_0) * p1_idx_2) /
             (p12f_idx_0 * p23f[1] - p23f[0] * p1_idx_2);
  /*  得出距离 */
  /*  radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2); */
  scale = 3.3121686421112381E-170;
  p23_idx_0 += p23f[0] * p1_idx_2;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    pf_tmp_idx_0 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    pf_tmp_idx_0 = t * t;
  }
  p23_idx_1 += p23f[1] * p1_idx_2;
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    pf_tmp_idx_0 = pf_tmp_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    pf_tmp_idx_0 += t * t;
  }
  p23_idx_2 += (pf_idx_0 * p2_idx_1 - p2_idx_0 * pf_idx_1) * p1_idx_2;
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    pf_tmp_idx_0 = pf_tmp_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    pf_tmp_idx_0 += t * t;
  }
  emxInit_real_T(&Dist, 2);
  pf_tmp_idx_0 = scale * sqrt(pf_tmp_idx_0);
  pf_idx_0 /= pf_tmp_idx_0;
  pf_idx_1 /= pf_tmp_idx_0;
  pf_idx_2 /= pf_tmp_idx_0;
  /* %%%%%%%%%%%%%%%%%%% */
  /*  -----------------------------计算参数------------------------------- */
  loop_ub = Point_out->size[1];
  i = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  Dist->size[1] = Point_out->size[1];
  emxEnsureCapacity_real_T(Dist, i);
  Dist_data = Dist->data;
  for (i = 0; i < loop_ub; i++) {
    Dist_data[i] = 0.0;
  }
  i = Point_out->size[1] - 1;
  for (b_i = 0; b_i <= i; b_i++) {
    printf("i=%d,b_i = %d, Point_out_data[3 * b_i] = %f, p23_idx_0 = %f \n", i,
           b_i, Point_out_data[3 * b_i], p23_idx_0);
    p12f_idx_0 = Point_out_data[3 * b_i] - p23_idx_0;
    p1_idx_2 = Point_out_data[3 * b_i + 1] - p23_idx_1;
    pf_tmp_idx_0 = Point_out_data[3 * b_i + 2] - p23_idx_2;
    Dist_data[b_i] = sqrt((p12f_idx_0 * p12f_idx_0 + p1_idx_2 * p1_idx_2) +
                          pf_tmp_idx_0 * pf_tmp_idx_0);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  p2_idx_2 = mean(Dist);
  scale = 3.3121686421112381E-170;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    pf_tmp_idx_0 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    pf_tmp_idx_0 = t * t;
  }
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    pf_tmp_idx_0 = pf_tmp_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    pf_tmp_idx_0 += t * t;
  }
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    pf_tmp_idx_0 = pf_tmp_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    pf_tmp_idx_0 += t * t;
  }
  pf_tmp_idx_0 = scale * sqrt(pf_tmp_idx_0);
  p3[0] = p23_idx_0;
  p3[1] = p23_idx_1;
  p3[2] = p23_idx_2;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  p2_idx_1 = pf_idx_0 / pf_tmp_idx_0;
  pf_idx_0 = p2_idx_1;
  p23f[0] = p23_idx_0 + p2_idx_1;
  p2_idx_1 = pf_idx_1 / pf_tmp_idx_0;
  p2_idx_0 = p2_idx_1;
  p23f[1] = p23_idx_1 + p2_idx_1;
  p2_idx_1 = pf_idx_2 / pf_tmp_idx_0;
  p23f[2] = p23_idx_2 + p2_idx_1;
  foot_of_perpendicular_from_a_point_to_a_line(P4, p3, p23f, &p12f_idx_0,
                                               &pf_tmp_idx_0, &p23_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, p3, p23f, &p1_idx_2,
                                               &p1_idx_0, &p1_idx_1);
  scale = 3.3121686421112381E-170;
  absxk = fabs(p1_idx_2 - p12f_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    p1_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p1_idx_2 = t * t;
  }
  absxk = fabs(p1_idx_0 - pf_tmp_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    p1_idx_2 = p1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p1_idx_2 += t * t;
  }
  absxk = fabs(p1_idx_1 - p23_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    p1_idx_2 = p1_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p1_idx_2 += t * t;
  }
  emxInit_real_T(&Point_out1, 2);
  p1_idx_2 = scale * sqrt(p1_idx_2);
  /*  -----------------------------生成抽样点------------------------------- */
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(p2_idx_1, sqrt(pf_idx_0 * pf_idx_0 + p2_idx_0 * p2_idx_0)),
      rt_atan2d_snf(p2_idx_0, pf_idx_0), num, Point_out1);
  Point_out1_data = Point_out1->data;
  /*  ----------------------------移动到原点------------------------------- */
  loop_ub = Point_out1->size[1];
  i = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  Dist->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Dist, i);
  Dist_data = Dist->data;
  for (i = 0; i < loop_ub; i++) {
    Dist_data[i] = Point_out1_data[3 * i] * p2_idx_2 + p12f_idx_0;
  }
  emxInit_real_T(&Ylay0, 2);
  loop_ub = Point_out1->size[1];
  i = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  Ylay0->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Ylay0, i);
  Ylay0_data = Ylay0->data;
  for (i = 0; i < loop_ub; i++) {
    Ylay0_data[i] = Point_out1_data[3 * i + 1] * p2_idx_2 + pf_tmp_idx_0;
  }
  emxInit_real_T(&Zlay0, 2);
  loop_ub = Point_out1->size[1];
  i = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  Zlay0->size[1] = Point_out1->size[1];
  emxEnsureCapacity_real_T(Zlay0, i);
  Zlay0_data = Zlay0->data;
  for (i = 0; i < loop_ub; i++) {
    Zlay0_data[i] = Point_out1_data[3 * i + 2] * p2_idx_2 + p23_idx_0;
  }
  emxFree_real_T(&Point_out1);
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  p12f_idx_0 = 0.2 * p1_idx_2;
  p1_idx_2 *= 0.8;
  emxInit_real_T(&Layer, 2);
  Point_out1_data = Layer->data;
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    pf_tmp_idx_0 = floor(laynum);
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)pf_tmp_idx_0;
    emxEnsureCapacity_real_T(Layer, i);
    Point_out1_data = Layer->data;
    if ((int)pf_tmp_idx_0 >= 1) {
      loop_ub = (int)pf_tmp_idx_0 - 1;
      Point_out1_data[(int)floor(laynum) - 1] = p1_idx_2;
      if (Layer->size[1] >= 2) {
        Point_out1_data[0] = p12f_idx_0;
        if (Layer->size[1] >= 3) {
          if ((p12f_idx_0 == -p1_idx_2) && ((int)pf_tmp_idx_0 > 2)) {
            p1_idx_2 /= (double)(int)pf_tmp_idx_0 - 1.0;
            for (k = 2; k <= loop_ub; k++) {
              Point_out1_data[k - 1] =
                  (double)(((k << 1) - (int)pf_tmp_idx_0) - 1) * p1_idx_2;
            }
            if (((int)pf_tmp_idx_0 & 1) == 1) {
              Point_out1_data[(int)pf_tmp_idx_0 >> 1] = 0.0;
            }
          } else {
            p1_idx_2 = (p1_idx_2 - p12f_idx_0) / ((double)Layer->size[1] - 1.0);
            i = Layer->size[1];
            for (k = 0; k <= i - 3; k++) {
              Point_out1_data[k + 1] =
                  p12f_idx_0 + ((double)k + 1.0) * p1_idx_2;
            }
          }
        }
      }
    }
  }
  emxInit_real_T(&Point_testx, 1);
  loop_ub = (int)(laynum * num);
  i = Point_testx->size[0];
  Point_testx->size[0] = loop_ub;
  emxEnsureCapacity_real_T(Point_testx, i);
  Point_testx_data = Point_testx->data;
  for (i = 0; i < loop_ub; i++) {
    Point_testx_data[i] = 0.0;
  }
  emxInit_real_T(&Point_testy, 1);
  i = Point_testy->size[0];
  Point_testy->size[0] = loop_ub;
  emxEnsureCapacity_real_T(Point_testy, i);
  Point_testy_data = Point_testy->data;
  for (i = 0; i < loop_ub; i++) {
    Point_testy_data[i] = 0.0;
  }
  emxInit_real_T(&Point_testz, 1);
  i = Point_testz->size[0];
  Point_testz->size[0] = loop_ub;
  emxEnsureCapacity_real_T(Point_testz, i);
  Point_testz_data = Point_testz->data;
  for (i = 0; i < loop_ub; i++) {
    Point_testz_data[i] = 0.0;
  }
  i = (int)laynum;
  for (b_i = 0; b_i < i; b_i++) {
    pf_tmp_idx_0 = (((double)b_i + 1.0) - 1.0) * num + 1.0;
    p1_idx_2 = ((double)b_i + 1.0) * num;
    if (pf_tmp_idx_0 > p1_idx_2) {
      k = 1;
    } else {
      k = (int)pf_tmp_idx_0;
    }
    p12f_idx_0 = Point_out1_data[b_i] * pf_idx_0;
    loop_ub = Dist->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      Point_testx_data[(k + i1) - 1] = Dist_data[i1] - p12f_idx_0;
    }
    if (pf_tmp_idx_0 > p1_idx_2) {
      k = 1;
    } else {
      k = (int)pf_tmp_idx_0;
    }
    p12f_idx_0 = Point_out1_data[b_i] * p2_idx_0;
    loop_ub = Ylay0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      Point_testy_data[(k + i1) - 1] = Ylay0_data[i1] - p12f_idx_0;
    }
    if (pf_tmp_idx_0 > p1_idx_2) {
      k = 1;
    } else {
      k = (int)pf_tmp_idx_0;
    }
    p12f_idx_0 = Point_out1_data[b_i] * p2_idx_1;
    loop_ub = Zlay0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      Point_testz_data[(k + i1) - 1] = Zlay0_data[i1] - p12f_idx_0;
    }
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&Dist);
  i = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = Point_testx->size[0];
  emxEnsureCapacity_real_T(Point_test, i);
  Point_out1_data = Point_test->data;
  loop_ub = Point_testx->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i] = Point_testx_data[i];
  }
  emxFree_real_T(&Point_testx);
  loop_ub = Point_testy->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i + 1] = Point_testy_data[i];
  }
  emxFree_real_T(&Point_testy);
  loop_ub = Point_testz->size[0];
  for (i = 0; i < loop_ub; i++) {
    Point_out1_data[3 * i + 2] = Point_testz_data[i];
  }
  emxFree_real_T(&Point_testz);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
