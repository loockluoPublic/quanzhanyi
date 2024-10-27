/*
 * File: Calculate_rectangle_from_vertex.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 12:33:43
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
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
 *                double Pin[3]
 *                double Pout[3]
 *                double UPP[3]
 *                double *b
 *                double *h
 *                double *w
 *                double Tao[3]
 *                double PP[24]
 * Return Type  : void
 */
void Calculate_rectangle_from_vertex(const emxArray_real_T *TrianglePoints4,
                                     double Pin[3], double Pout[3],
                                     double UPP[3], double *b, double *h,
                                     double *w, double Tao[3], double PP[24])
{
  static const signed char b_iv[8] = {1, 2, 3, 6, 9, 12, 17, 18};
  double Pdd[24];
  const double *TrianglePoints4_data;
  double Tao2_tmp_idx_0;
  double Tao2_tmp_idx_1;
  double Tao2_tmp_idx_2;
  double Tao3_tmp;
  double Tao3_tmp_idx_0;
  double Tao3_tmp_idx_1;
  double Tao3_tmp_idx_2;
  double absxk;
  double b_scale;
  double b_y;
  double c_scale;
  double d;
  double scale;
  double t;
  double y;
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
  d = Pdd[6] - Pdd[0];
  Tao[0] = d;
  Tao2_tmp_idx_2 = Pdd[9] - Pdd[3];
  Tao2_tmp_idx_0 = Tao2_tmp_idx_2;
  Tao3_tmp_idx_2 = Pdd[15] - Pdd[12];
  Tao3_tmp_idx_0 = Tao3_tmp_idx_2;
  absxk = fabs(Tao3_tmp_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    Tao3_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    Tao3_tmp = t * t;
  }
  absxk = fabs(d);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(Tao2_tmp_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    c_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  d = Pdd[7] - Pdd[1];
  Tao[1] = d;
  Tao2_tmp_idx_2 = Pdd[10] - Pdd[4];
  Tao2_tmp_idx_1 = Tao2_tmp_idx_2;
  Tao3_tmp_idx_2 = Pdd[16] - Pdd[13];
  Tao3_tmp_idx_1 = Tao3_tmp_idx_2;
  absxk = fabs(Tao3_tmp_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    Tao3_tmp = Tao3_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    Tao3_tmp += t * t;
  }
  absxk = fabs(d);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  absxk = fabs(Tao2_tmp_idx_2);
  if (absxk > c_scale) {
    t = c_scale / absxk;
    b_y = b_y * t * t + 1.0;
    c_scale = absxk;
  } else {
    t = absxk / c_scale;
    b_y += t * t;
  }
  d = Pdd[8] - Pdd[2];
  Tao2_tmp_idx_2 = Pdd[11] - Pdd[5];
  Tao3_tmp_idx_2 = Pdd[17] - Pdd[14];
  absxk = fabs(Tao3_tmp_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    Tao3_tmp = Tao3_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    Tao3_tmp += t * t;
  }
  absxk = fabs(d);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  absxk = fabs(Tao2_tmp_idx_2);
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
  /*  计算进口中心 */
  /*  计算出口中心 */
  /*  计算上顶点 */
  /*  计算长宽高 */
  scale = Pdd[0] - Pdd[12];
  b_scale = Pdd[1] - Pdd[13];
  c_scale = Pdd[2] - Pdd[14];
  *b = sqrt((scale * scale + b_scale * b_scale) + c_scale * c_scale);
  scale = Pdd[0] - Pdd[3];
  b_scale = Pdd[1] - Pdd[4];
  c_scale = Pdd[2] - Pdd[5];
  *h = sqrt((scale * scale + b_scale * b_scale) + c_scale * c_scale);
  scale = Pdd[0] - Pdd[6];
  b_scale = Pdd[1] - Pdd[7];
  c_scale = Pdd[2] - Pdd[8];
  *w = sqrt((scale * scale + b_scale * b_scale) + c_scale * c_scale);
  Tao[0] = (((Tao[0] / y + Tao2_tmp_idx_0 / b_y) + Tao3_tmp_idx_0 / Tao3_tmp) +
            (Pdd[21] - Pdd[18]) / Tao3_tmp) /
           4.0;
  Pin[0] = ((Pdd[3] + Pdd[12]) / 2.0 + (Pdd[0] + Pdd[18]) / 2.0) / 2.0;
  Pout[0] = ((Pdd[6] + Pdd[21]) / 2.0 + (Pdd[9] + Pdd[15]) / 2.0) / 2.0;
  UPP[0] = (Pdd[0] + Pdd[12]) / 2.0;
  PP[0] = Pdd[0];
  PP[1] = Pdd[3];
  PP[2] = Pdd[6];
  PP[3] = Pdd[9];
  PP[4] = Pdd[12];
  PP[5] = Pdd[15];
  PP[6] = Pdd[18];
  PP[7] = Pdd[21];
  Tao[1] = (((Tao[1] / y + Tao2_tmp_idx_1 / b_y) + Tao3_tmp_idx_1 / Tao3_tmp) +
            (Pdd[22] - Pdd[19]) / Tao3_tmp) /
           4.0;
  Pin[1] = ((Pdd[4] + Pdd[13]) / 2.0 + (Pdd[1] + Pdd[19]) / 2.0) / 2.0;
  Pout[1] = ((Pdd[7] + Pdd[22]) / 2.0 + (Pdd[10] + Pdd[16]) / 2.0) / 2.0;
  UPP[1] = (Pdd[1] + Pdd[13]) / 2.0;
  PP[8] = Pdd[1];
  PP[9] = Pdd[4];
  PP[10] = Pdd[7];
  PP[11] = Pdd[10];
  PP[12] = Pdd[13];
  PP[13] = Pdd[16];
  PP[14] = Pdd[19];
  PP[15] = Pdd[22];
  Tao[2] = (((d / y + Tao2_tmp_idx_2 / b_y) + Tao3_tmp_idx_2 / Tao3_tmp) +
            (Pdd[23] - Pdd[20]) / Tao3_tmp) /
           4.0;
  Pin[2] = ((Pdd[5] + Pdd[14]) / 2.0 + (Pdd[2] + Pdd[20]) / 2.0) / 2.0;
  Pout[2] = ((Pdd[8] + Pdd[23]) / 2.0 + (Pdd[11] + Pdd[17]) / 2.0) / 2.0;
  UPP[2] = (Pdd[2] + Pdd[14]) / 2.0;
  PP[16] = Pdd[2];
  PP[17] = Pdd[5];
  PP[18] = Pdd[8];
  PP[19] = Pdd[11];
  PP[20] = Pdd[14];
  PP[21] = Pdd[17];
  PP[22] = Pdd[20];
  PP[23] = Pdd[23];
  /*  8个顶点 */
}

/*
 * File trailer for Calculate_rectangle_from_vertex.c
 *
 * [EOF]
 */
