/*
 * File: Calculate_rectangle_from_vertex.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 22-Aug-2024 17:04:17
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * TrianglePoints4 前一个函数的输出三角点坐标
 *  P_bound1 边界点1
 *  P_bound2 边界点2
 *  Pin  边界点1的中心
 *  Pout 边界点2的中心
 *  UPP  边界1上中点
 *  b    进口面宽
 *  h    进口面高
 *  w    管道长度
 *  Tao  单位轴线
 *  PP   8个顶点
 *
 * Arguments    : const emxArray_real_T *TrianglePoints4
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Pin[3]
 *                double Pout[3]
 *                double UPP[3]
 *                double *b
 *                double *h
 *                double *w
 *                double Tao[3]
 *                emxArray_real_T *PP
 * Return Type  : void
 */
void Calculate_rectangle_from_vertex(const emxArray_real_T *TrianglePoints4,
                                     const double P_bound1[3],
                                     const double P_bound2[3], double Pin[3],
                                     double Pout[3], double UPP[3], double *b,
                                     double *h, double *w, double Tao[3],
                                     emxArray_real_T *PP)
{
  static const signed char b_iv[8] = {1, 2, 3, 6, 9, 16, 17, 18};
  double Pdd[24];
  const double *TrianglePoints4_data;
  double PP1_idx_0;
  double PP1_idx_1;
  double PP4_idx_0;
  double PP4_idx_1;
  double Tao3_tmp;
  double a;
  double absxk;
  double b_a;
  double b_scale;
  double b_y;
  double c_a;
  double c_scale;
  double d_a;
  double e_a;
  double f_a;
  double g_a;
  double h_a;
  double i_a;
  double scale;
  double t;
  double xN2;
  double xN3;
  double xN6;
  double xN7;
  double xN8;
  double y;
  double yN2;
  double yN6;
  double yN7;
  double yN8;
  double zN6;
  double zN7;
  double zN8;
  double *PP_data;
  int Pdd_tmp;
  int i;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  TrianglePoints4_data = TrianglePoints4->data;
  /*  取八个点 */
  for (i = 0; i < 8; i++) {
    Pdd_tmp = b_iv[i] - 1;
    Pdd[3 * i] = TrianglePoints4_data[3 * Pdd_tmp];
    Pdd[3 * i + 1] = TrianglePoints4_data[3 * Pdd_tmp + 1];
    Pdd[3 * i + 2] = TrianglePoints4_data[3 * Pdd_tmp + 2];
  }
  /*  计算轴线 */
  scale = 3.3121686421112381E-170;
  b_scale = 3.3121686421112381E-170;
  c_scale = 3.3121686421112381E-170;
  xN2 = Pdd[6] - Pdd[0];
  Tao[0] = xN2;
  yN2 = Pdd[9] - Pdd[3];
  PP1_idx_0 = yN2;
  xN3 = Pdd[15] - Pdd[12];
  PP4_idx_0 = xN3;
  absxk = fabs(xN3);
  if (absxk > 3.3121686421112381E-170) {
    Tao3_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    Tao3_tmp = t * t;
  }
  absxk = fabs(xN2);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(yN2);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    c_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  xN2 = Pdd[7] - Pdd[1];
  Tao[1] = xN2;
  yN2 = Pdd[10] - Pdd[4];
  PP1_idx_1 = yN2;
  xN3 = Pdd[16] - Pdd[13];
  PP4_idx_1 = xN3;
  absxk = fabs(xN3);
  if (absxk > scale) {
    t = scale / absxk;
    Tao3_tmp = Tao3_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    Tao3_tmp += t * t;
  }
  absxk = fabs(xN2);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  absxk = fabs(yN2);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    b_y = b_y * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    b_y += t * t;
  }
  xN2 = Pdd[8] - Pdd[2];
  yN2 = Pdd[11] - Pdd[5];
  xN3 = Pdd[17] - Pdd[14];
  absxk = fabs(xN3);
  if (absxk > scale) {
    t = scale / absxk;
    Tao3_tmp = Tao3_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    Tao3_tmp += t * t;
  }
  absxk = fabs(xN2);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  absxk = fabs(yN2);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    b_y = b_y * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    b_y += t * t;
  }
  Tao3_tmp = scale * sqrt(Tao3_tmp);
  y = b_scale * sqrt(y);
  b_y = c_scale * sqrt(b_y);
  Tao[0] = (((Tao[0] / y + PP1_idx_0 / b_y) + PP4_idx_0 / Tao3_tmp) +
            (Pdd[21] - Pdd[18]) / Tao3_tmp) /
           4.0;
  Tao[1] = (((Tao[1] / y + PP1_idx_1 / b_y) + PP4_idx_1 / Tao3_tmp) +
            (Pdd[22] - Pdd[19]) / Tao3_tmp) /
           4.0;
  Tao[2] = (((xN2 / y + yN2 / b_y) + xN3 / Tao3_tmp) +
            (Pdd[23] - Pdd[20]) / Tao3_tmp) /
           4.0;
  /*  计算投影点 */
  foot_of_perpendicular_from_a_point_to_a_line(P_bound1, &Pdd[0], &Pdd[6],
                                               &scale, &b_scale, &c_scale);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound1, &Pdd[3], &Pdd[9], &xN2,
                                               &yN2, &PP1_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound2, &Pdd[0], &Pdd[6], &xN3,
                                               &PP4_idx_0, &absxk);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound2, &Pdd[3], &Pdd[9], &t,
                                               &Tao3_tmp, &y);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound1, &Pdd[12], &Pdd[15],
                                               &b_y, &PP1_idx_1, &PP4_idx_1);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound2, &Pdd[12], &Pdd[15],
                                               &xN6, &yN6, &zN6);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound1, &Pdd[18], &Pdd[21],
                                               &xN7, &yN7, &zN7);
  foot_of_perpendicular_from_a_point_to_a_line(P_bound2, &Pdd[18], &Pdd[21],
                                               &xN8, &yN8, &zN8);
  /*  计算进口中心 */
  /*  计算出口中心 */
  /*  计算上顶点 */
  /*  计算长宽高 */
  a = scale - b_y;
  b_a = b_scale - PP1_idx_1;
  c_a = c_scale - PP4_idx_1;
  d_a = scale - xN2;
  e_a = b_scale - yN2;
  f_a = c_scale - PP1_idx_0;
  g_a = scale - xN3;
  h_a = b_scale - PP4_idx_0;
  i_a = c_scale - absxk;
  Pdd[0] = scale;
  Pdd[3] = xN2;
  Pdd[6] = xN3;
  Pdd[9] = t;
  Pdd[12] = b_y;
  Pdd[15] = xN6;
  Pdd[18] = xN7;
  Pdd[21] = xN8;
  Pdd[1] = b_scale;
  Pdd[4] = yN2;
  Pdd[7] = PP4_idx_0;
  Pdd[10] = Tao3_tmp;
  Pdd[13] = PP1_idx_1;
  Pdd[16] = yN6;
  Pdd[19] = yN7;
  Pdd[22] = yN8;
  Pdd[2] = c_scale;
  Pdd[5] = PP1_idx_0;
  Pdd[8] = absxk;
  Pdd[11] = y;
  Pdd[14] = PP4_idx_1;
  Pdd[17] = zN6;
  Pdd[20] = zN7;
  Pdd[23] = zN8;
  i = PP->size[0] * PP->size[1];
  PP->size[0] = 3;
  PP->size[1] = 8;
  emxEnsureCapacity_real_T(PP, i);
  PP_data = PP->data;
  for (i = 0; i < 24; i++) {
    PP_data[i] = Pdd[i];
  }
  /*  8个顶点 */
  Pin[0] = ((xN2 + b_y) / 2.0 + (scale + xN7) / 2.0) / 2.0;
  Pout[0] = ((xN3 + xN8) / 2.0 + (t + xN6) / 2.0) / 2.0;
  UPP[0] = (b_y + xN7) / 2.0;
  Pin[1] = ((yN2 + PP1_idx_1) / 2.0 + (b_scale + yN7) / 2.0) / 2.0;
  Pout[1] = ((PP4_idx_0 + yN8) / 2.0 + (Tao3_tmp + yN6) / 2.0) / 2.0;
  UPP[1] = (PP1_idx_1 + yN7) / 2.0;
  Pin[2] = ((PP1_idx_0 + PP4_idx_1) / 2.0 + (c_scale + zN7) / 2.0) / 2.0;
  Pout[2] = ((absxk + zN8) / 2.0 + (y + zN6) / 2.0) / 2.0;
  UPP[2] = (PP4_idx_1 + zN7) / 2.0;
  *b = sqrt((a * a + b_a * b_a) + c_a * c_a);
  *h = sqrt((d_a * d_a + e_a * e_a) + f_a * f_a);
  *w = sqrt((g_a * g_a + h_a * h_a) + i_a * i_a);
}

/*
 * File trailer for Calculate_rectangle_from_vertex.c
 *
 * [EOF]
 */
