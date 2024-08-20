/*
 * File: Calculate_rectangle_from_vertex.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 21-Aug-2024 00:46:56
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
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
 * Arguments    : const double TrianglePoints4[16]
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Pin[3]
 *                double Pout[3]
 *                double UPP[3]
 *                double *b
 *                double *h
 *                double *w
 *                double Tao[4]
 *                double PP[24]
 * Return Type  : void
 */
void Calculate_rectangle_from_vertex(const double TrianglePoints4[16],
                                     const double P_bound1[3],
                                     const double P_bound2[3], double Pin[3],
                                     double Pout[3], double UPP[3], double *b,
                                     double *h, double *w, double Tao[4],
                                     double PP[24])
{
  static const signed char b_iv[8] = {1, 2, 3, 6, 9, 16, 17, 18};
  double Pdd[32];
  double K;
  double PP1_idx_0;
  double PP1_idx_1;
  double PP1_idx_2;
  double PP4_idx_0;
  double PP4_idx_1;
  double PP4_idx_2;
  double PP6_idx_0;
  double PP6_idx_1;
  double PP7_idx_1;
  double PP7_idx_2;
  double Tao2_tmp_idx_1;
  double Tao2_tmp_idx_2;
  double Tao3_tmp_idx_0;
  double Tao3_tmp_idx_1;
  double Tao3_tmp_idx_2;
  double Tao_tmp;
  double a;
  double absxk;
  double b_Tao_tmp;
  double b_a;
  double b_scale;
  double c_a;
  double c_scale;
  double scale;
  double t;
  int Pdd_tmp;
  int b_Pdd_tmp;
  int i;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  取八个点 */
  for (i = 0; i < 8; i++) {
    Pdd_tmp = (b_iv[i] - 1) << 2;
    b_Pdd_tmp = i << 2;
    Pdd[b_Pdd_tmp] = TrianglePoints4[Pdd_tmp];
    Pdd[b_Pdd_tmp + 1] = TrianglePoints4[Pdd_tmp + 1];
    Pdd[b_Pdd_tmp + 2] = TrianglePoints4[Pdd_tmp + 2];
    Pdd[b_Pdd_tmp + 3] = TrianglePoints4[Pdd_tmp + 3];
  }
  /*  计算轴线 */
  scale = 3.3121686421112381E-170;
  b_scale = 3.3121686421112381E-170;
  c_scale = 3.3121686421112381E-170;
  a = Pdd[8] - Pdd[0];
  PP4_idx_1 = Pdd[12] - Pdd[4];
  Tao3_tmp_idx_0 = Pdd[20] - Pdd[16];
  absxk = fabs(Tao3_tmp_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    PP7_idx_1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    PP7_idx_1 = t * t;
  }
  absxk = fabs(a);
  if (absxk > 3.3121686421112381E-170) {
    PP7_idx_2 = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    PP7_idx_2 = t * t;
  }
  absxk = fabs(PP4_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    PP6_idx_1 = 1.0;
    c_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    PP6_idx_1 = t * t;
  }
  b_a = Pdd[9] - Pdd[1];
  Tao2_tmp_idx_1 = Pdd[13] - Pdd[5];
  Tao3_tmp_idx_1 = Pdd[21] - Pdd[17];
  absxk = fabs(Tao3_tmp_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    PP7_idx_1 = PP7_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    PP7_idx_1 += t * t;
  }
  absxk = fabs(b_a);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    PP7_idx_2 = PP7_idx_2 * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    PP7_idx_2 += t * t;
  }
  absxk = fabs(Tao2_tmp_idx_1);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    PP6_idx_1 = PP6_idx_1 * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    PP6_idx_1 += t * t;
  }
  c_a = Pdd[10] - Pdd[2];
  Tao2_tmp_idx_2 = Pdd[14] - Pdd[6];
  Tao3_tmp_idx_2 = Pdd[22] - Pdd[18];
  absxk = fabs(Tao3_tmp_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    PP7_idx_1 = PP7_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    PP7_idx_1 += t * t;
  }
  absxk = fabs(c_a);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    PP7_idx_2 = PP7_idx_2 * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    PP7_idx_2 += t * t;
  }
  absxk = fabs(Tao2_tmp_idx_2);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    PP6_idx_1 = PP6_idx_1 * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    PP6_idx_1 += t * t;
  }
  PP6_idx_0 = Pdd[11] - Pdd[3];
  K = Pdd[15] - Pdd[7];
  PP4_idx_2 = Pdd[23] - Pdd[19];
  absxk = fabs(PP4_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    PP7_idx_1 = PP7_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    PP7_idx_1 += t * t;
  }
  absxk = fabs(PP6_idx_0);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    PP7_idx_2 = PP7_idx_2 * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    PP7_idx_2 += t * t;
  }
  absxk = fabs(K);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    PP6_idx_1 = PP6_idx_1 * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    PP6_idx_1 += t * t;
  }
  PP7_idx_1 = scale * sqrt(PP7_idx_1);
  PP7_idx_2 = b_scale * sqrt(PP7_idx_2);
  PP6_idx_1 = c_scale * sqrt(PP6_idx_1);
  c_scale = Pdd[28] - Pdd[24];
  Tao[0] =
      (((a / PP7_idx_2 + PP4_idx_1 / PP6_idx_1) + Tao3_tmp_idx_0 / PP7_idx_1) +
       c_scale / PP7_idx_1) /
      4.0;
  Tao_tmp = Pdd[29] - Pdd[25];
  Tao[1] = (((b_a / PP7_idx_2 + Tao2_tmp_idx_1 / PP6_idx_1) +
             Tao3_tmp_idx_1 / PP7_idx_1) +
            Tao_tmp / PP7_idx_1) /
           4.0;
  b_Tao_tmp = Pdd[30] - Pdd[26];
  Tao[2] = (((c_a / PP7_idx_2 + Tao2_tmp_idx_2 / PP6_idx_1) +
             Tao3_tmp_idx_2 / PP7_idx_1) +
            b_Tao_tmp / PP7_idx_1) /
           4.0;
  Tao[3] = (((PP6_idx_0 / PP7_idx_2 + K / PP6_idx_1) + PP4_idx_2 / PP7_idx_1) +
            (Pdd[31] - Pdd[27]) / PP7_idx_1) /
           4.0;
  /*  计算投影点 */
  /*  三个点定义 */
  /*  斜率计算 */
  b_scale = (a * a + b_a * b_a) + c_a * c_a;
  K = -(((Pdd[0] - P_bound1[0]) * a + (Pdd[1] - P_bound1[1]) * b_a) +
        (Pdd[2] - P_bound1[2]) * c_a) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  PP1_idx_0 = K * a + Pdd[0];
  PP1_idx_1 = K * b_a + Pdd[1];
  PP1_idx_2 = K * c_a + Pdd[2];
  /*  三个点定义 */
  /*  斜率计算 */
  scale = (PP4_idx_1 * PP4_idx_1 + Tao2_tmp_idx_1 * Tao2_tmp_idx_1) +
          Tao2_tmp_idx_2 * Tao2_tmp_idx_2;
  K = -(((Pdd[4] - P_bound1[0]) * PP4_idx_1 +
         (Pdd[5] - P_bound1[1]) * Tao2_tmp_idx_1) +
        (Pdd[6] - P_bound1[2]) * Tao2_tmp_idx_2) /
      scale;
  /*  P1点在轴线上的投影坐标 */
  Pin[0] = K * PP4_idx_1 + Pdd[4];
  Pin[1] = K * Tao2_tmp_idx_1 + Pdd[5];
  Pin[2] = K * Tao2_tmp_idx_2 + Pdd[6];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[0] - P_bound2[0]) * a + (Pdd[1] - P_bound2[1]) * b_a) +
        (Pdd[2] - P_bound2[2]) * c_a) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  Pout[0] = K * a + Pdd[0];
  Pout[1] = K * b_a + Pdd[1];
  Pout[2] = K * c_a + Pdd[2];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[4] - P_bound2[0]) * PP4_idx_1 +
         (Pdd[5] - P_bound2[1]) * Tao2_tmp_idx_1) +
        (Pdd[6] - P_bound2[2]) * Tao2_tmp_idx_2) /
      scale;
  /*  P1点在轴线上的投影坐标 */
  PP4_idx_0 = K * PP4_idx_1 + Pdd[4];
  PP4_idx_1 = K * Tao2_tmp_idx_1 + Pdd[5];
  PP4_idx_2 = K * Tao2_tmp_idx_2 + Pdd[6];
  /*  三个点定义 */
  /*  斜率计算 */
  b_scale =
      (Tao3_tmp_idx_0 * Tao3_tmp_idx_0 + Tao3_tmp_idx_1 * Tao3_tmp_idx_1) +
      Tao3_tmp_idx_2 * Tao3_tmp_idx_2;
  K = -(((Pdd[16] - P_bound1[0]) * Tao3_tmp_idx_0 +
         (Pdd[17] - P_bound1[1]) * Tao3_tmp_idx_1) +
        (Pdd[18] - P_bound1[2]) * Tao3_tmp_idx_2) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  UPP[0] = K * Tao3_tmp_idx_0 + Pdd[16];
  UPP[1] = K * Tao3_tmp_idx_1 + Pdd[17];
  UPP[2] = K * Tao3_tmp_idx_2 + Pdd[18];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[16] - P_bound2[0]) * Tao3_tmp_idx_0 +
         (Pdd[17] - P_bound2[1]) * Tao3_tmp_idx_1) +
        (Pdd[18] - P_bound2[2]) * Tao3_tmp_idx_2) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  PP6_idx_0 = K * Tao3_tmp_idx_0 + Pdd[16];
  PP6_idx_1 = K * Tao3_tmp_idx_1 + Pdd[17];
  absxk = K * Tao3_tmp_idx_2 + Pdd[18];
  /*  三个点定义 */
  /*  斜率计算 */
  b_scale = (c_scale * c_scale + Tao_tmp * Tao_tmp) + b_Tao_tmp * b_Tao_tmp;
  K = -(((Pdd[24] - P_bound1[0]) * c_scale +
         (Pdd[25] - P_bound1[1]) * Tao_tmp) +
        (Pdd[26] - P_bound1[2]) * b_Tao_tmp) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  t = K * c_scale + Pdd[24];
  PP7_idx_1 = K * Tao_tmp + Pdd[25];
  PP7_idx_2 = K * b_Tao_tmp + Pdd[26];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[24] - P_bound2[0]) * c_scale +
         (Pdd[25] - P_bound2[1]) * Tao_tmp) +
        (Pdd[26] - P_bound2[2]) * b_Tao_tmp) /
      b_scale;
  /*  P1点在轴线上的投影坐标 */
  c_scale = K * c_scale + Pdd[24];
  b_scale = K * Tao_tmp + Pdd[25];
  scale = K * b_Tao_tmp + Pdd[26];
  /*  计算进口中心 */
  /*  计算出口中心 */
  /*  计算上顶点 */
  /*  计算长宽高 */
  a = PP1_idx_0 - UPP[0];
  b_a = PP1_idx_1 - UPP[1];
  c_a = PP1_idx_2 - UPP[2];
  *b = sqrt((a * a + b_a * b_a) + c_a * c_a);
  a = PP1_idx_0 - Pin[0];
  b_a = PP1_idx_1 - Pin[1];
  c_a = PP1_idx_2 - Pin[2];
  *h = sqrt((a * a + b_a * b_a) + c_a * c_a);
  a = PP1_idx_0 - Pout[0];
  b_a = PP1_idx_1 - Pout[1];
  c_a = PP1_idx_2 - Pout[2];
  *w = sqrt((a * a + b_a * b_a) + c_a * c_a);
  /*  8个顶点 */
  PP[0] = PP1_idx_0;
  PP[3] = Pin[0];
  PP[6] = Pout[0];
  PP[9] = PP4_idx_0;
  PP[12] = UPP[0];
  PP[15] = PP6_idx_0;
  PP[18] = t;
  PP[21] = c_scale;
  Pin[0] = ((Pin[0] + UPP[0]) / 2.0 + (PP1_idx_0 + t) / 2.0) / 2.0;
  Pout[0] = ((Pout[0] + c_scale) / 2.0 + (PP4_idx_0 + PP6_idx_0) / 2.0) / 2.0;
  UPP[0] = (UPP[0] + t) / 2.0;
  PP[1] = PP1_idx_1;
  PP[4] = Pin[1];
  PP[7] = Pout[1];
  PP[10] = PP4_idx_1;
  PP[13] = UPP[1];
  PP[16] = PP6_idx_1;
  PP[19] = PP7_idx_1;
  PP[22] = b_scale;
  Pin[1] = ((Pin[1] + UPP[1]) / 2.0 + (PP1_idx_1 + PP7_idx_1) / 2.0) / 2.0;
  Pout[1] = ((Pout[1] + b_scale) / 2.0 + (PP4_idx_1 + PP6_idx_1) / 2.0) / 2.0;
  UPP[1] = (UPP[1] + PP7_idx_1) / 2.0;
  PP[2] = PP1_idx_2;
  PP[5] = Pin[2];
  PP[8] = Pout[2];
  PP[11] = PP4_idx_2;
  PP[14] = UPP[2];
  PP[17] = absxk;
  PP[20] = PP7_idx_2;
  PP[23] = scale;
  Pin[2] = ((Pin[2] + UPP[2]) / 2.0 + (PP1_idx_2 + PP7_idx_2) / 2.0) / 2.0;
  Pout[2] = ((Pout[2] + scale) / 2.0 + (PP4_idx_2 + absxk) / 2.0) / 2.0;
  UPP[2] = (UPP[2] + PP7_idx_2) / 2.0;
}

/*
 * File trailer for Calculate_rectangle_from_vertex.c
 *
 * [EOF]
 */
