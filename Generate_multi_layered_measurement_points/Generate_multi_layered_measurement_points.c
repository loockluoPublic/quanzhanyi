/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "Generate_multi_layered_measurement_points_data.h"
#include "Generate_multi_layered_measurement_points_emxutil.h"
#include "Generate_multi_layered_measurement_points_initialize.h"
#include "Generate_multi_layered_measurement_points_types.h"
#include "linspace.h"
#include "mean.h"
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>

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
 * --------------------------3点组合抽样------------------------------
 *
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const emxArray_real_T *z
 *                double num
 *                double laynum
 *                const double P3[3]
 *                const double P4[3]
 *                emxArray_real_T *Point_test
 * Return Type  : void
 */
void Generate_multi_layered_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double num, double laynum, const double P3[3],
    const double P4[3], emxArray_real_T *Point_test)
{
  emxArray_real_T *S;
  emxArray_real_T *Xlay0;
  emxArray_real_T *YCenter;
  emxArray_real_T *Ylay0;
  emxArray_real_T *ZCenter;
  emxArray_real_T *Zlay0;
  emxArray_real_T *order;
  emxArray_real_T *temp;
  emxArray_real_T *y_circle;
  double dv[3];
  double K;
  double N12_idx_0;
  double N12_idx_0_tmp;
  double N12_idx_1;
  double N12_idx_1_tmp;
  double N12_idx_2;
  double N12_idx_2_tmp;
  double N23_idx_0;
  double N23_idx_1;
  double N23_idx_2;
  double P12_idx_2;
  double P23_idx_1;
  double Radius;
  double S_idx_0_tmp;
  double S_idx_1;
  double S_idx_2;
  double YCenterMean;
  double ZCenterMean;
  double absxk;
  double b_y;
  double d;
  double d1;
  double scale;
  double t;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  int nx;
  (void)P3;
  if (!isInitialized_Generate_multi_layered_measurement_points) {
    Generate_multi_layered_measurement_points_initialize();
  }
  emxInit_real_T(&temp, 2);
  if (x->size[0] < 1) {
    temp->size[0] = 1;
    temp->size[1] = 0;
  } else {
    i = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = x->size[0];
    emxEnsureCapacity_real_T(temp, i);
    loop_ub = x->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      temp->data[i] = (double)i + 1.0;
    }
  }
  emxInit_real_T(&order, 2);
  emxInit_real_T(&YCenter, 2);
  emxInit_real_T(&ZCenter, 2);
  emxInit_real_T(&S, 2);
  nchoosek(temp, order);
  /*  -----------------------平均轴向量、圆心----------------------- */
  temp->size[0] = 1;
  temp->size[1] = 0;
  YCenter->size[0] = 1;
  YCenter->size[1] = 0;
  ZCenter->size[0] = 1;
  ZCenter->size[1] = 0;
  S->size[0] = 3;
  S->size[1] = 0;
  i = order->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    d = order->data[b_i];
    K = order->data[b_i + order->size[0]];
    P12_idx_2 = order->data[b_i + order->size[0] * 2];
    N12_idx_0_tmp = x->data[(int)K - 1];
    d1 = x->data[(int)d - 1];
    N12_idx_0 = N12_idx_0_tmp - d1;
    N12_idx_1_tmp = y->data[(int)K - 1];
    Radius = y->data[(int)d - 1];
    N12_idx_1 = N12_idx_1_tmp - Radius;
    N12_idx_2_tmp = z->data[(int)K - 1];
    K = z->data[(int)d - 1];
    N12_idx_2 = N12_idx_2_tmp - K;
    YCenterMean = x->data[(int)P12_idx_2 - 1];
    N23_idx_0 = YCenterMean - N12_idx_0_tmp;
    ZCenterMean = y->data[(int)P12_idx_2 - 1];
    N23_idx_1 = ZCenterMean - N12_idx_1_tmp;
    P23_idx_1 = z->data[(int)P12_idx_2 - 1];
    N23_idx_2 = P23_idx_1 - N12_idx_2_tmp;
    S_idx_0_tmp = N12_idx_1 * N23_idx_2 - N23_idx_1 * N12_idx_2;
    S_idx_1 = N23_idx_0 * N12_idx_2 - N12_idx_0 * N23_idx_2;
    S_idx_2 = N12_idx_0 * N23_idx_1 - N23_idx_0 * N12_idx_1;
    /* 方向向量 */
    scale = 3.3121686421112381E-170;
    absxk = fabs(S_idx_0_tmp);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(S_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(S_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    b_y = scale * sqrt(b_y);
    S_idx_1 /= b_y;
    S_idx_2 /= b_y;
    /*     %% 计算交点 */
    d1 = -((N12_idx_0 * ((d1 + N12_idx_0_tmp) / 2.0) +
            N12_idx_1 * ((Radius + N12_idx_1_tmp) / 2.0)) +
           N12_idx_2 * ((K + N12_idx_2_tmp) / 2.0));
    P12_idx_2 =
        (d1 * N23_idx_1 -
         N12_idx_1 * -((N23_idx_0 * ((N12_idx_0_tmp + YCenterMean) / 2.0) +
                        N23_idx_1 * ((N12_idx_1_tmp + ZCenterMean) / 2.0)) +
                       N23_idx_2 * ((N12_idx_2_tmp + P23_idx_1) / 2.0))) /
        S_idx_0_tmp;
    /*      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*      f_P12 = [(xxx(1)+xxx(2))./2,(yyy(1)+yyy(2))./2,(zzz(1)+zzz(2))./2];
     */
    /*      f_P23 = [(xxx(3)+xxx(2))./2,(yyy(3)+yyy(2))./2,(zzz(3)+zzz(2))./2];
     */
    /*      f_N12 = [xxx(2)-xxx(1),yyy(2)-yyy(1),zzz(2)-zzz(1)]; */
    /*      f_N23 = [xxx(3)-xxx(2),yyy(3)-yyy(2),zzz(3)-zzz(2)]; */
    /*         */
    /*      f_S = cross(f_N12,f_N23);  %方向向量 */
    /*      s = f_S./norm(f_S); */
    /*       */
    /*      %% 计算交点 */
    /*      f_a1 = f_N12(1); */
    /*      f_b1 = f_N12(2); */
    /*      f_c1 = f_N12(3); */
    /*      f_d1 = -(f_a1*f_P12(1)+f_b1*f_P12(2)+f_c1*f_P12(3)); */
    /*       */
    /*       */
    /*      f_a2 = f_N23(1); */
    /*      f_b2 = f_N23(2); */
    /*      f_c2 = f_N23(3); */
    /*      f_d2 = -(f_a2*f_P23(1)+f_b2*f_P23(2)+f_c2*f_P23(3)); */
    /*       */
    /*      xcenter = 0; */
    /*      zcenter = (f_d1*f_b2-f_b1*f_d2)/(f_b1*f_c2-f_c1*f_b2); */
    /*      ycenter = -(f_c1*zcenter+f_d1)/f_b1; */
    /*   */
    /*      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    nx = S->size[1];
    i1 = S->size[0] * S->size[1];
    S->size[0] = 3;
    S->size[1]++;
    emxEnsureCapacity_real_T(S, i1);
    S->data[3 * nx] = S_idx_0_tmp / b_y;
    S->data[3 * nx + 1] = S_idx_1;
    S->data[3 * nx + 2] = S_idx_2;
    nx = temp->size[1];
    i1 = temp->size[0] * temp->size[1];
    temp->size[1]++;
    emxEnsureCapacity_real_T(temp, i1);
    temp->data[nx] = 0.0;
    nx = YCenter->size[1];
    i1 = YCenter->size[0] * YCenter->size[1];
    YCenter->size[1]++;
    emxEnsureCapacity_real_T(YCenter, i1);
    YCenter->data[nx] = -(N12_idx_2 * P12_idx_2 + d1) / N12_idx_1;
    nx = ZCenter->size[1];
    i1 = ZCenter->size[0] * ZCenter->size[1];
    ZCenter->size[1]++;
    emxEnsureCapacity_real_T(ZCenter, i1);
    ZCenter->data[nx] = P12_idx_2;
  }
  emxFree_real_T(&order);
  N23_idx_2 = mean(temp);
  YCenterMean = mean(YCenter);
  ZCenterMean = mean(ZCenter);
  b_mean(S, dv);
  /*  -----------------------------计算参数------------------------------- */
  temp->size[0] = 1;
  temp->size[1] = 0;
  i = x->size[0];
  emxFree_real_T(&S);
  for (b_i = 0; b_i < i; b_i++) {
    P12_idx_2 = x->data[b_i] - N23_idx_2;
    d1 = y->data[b_i] - YCenterMean;
    K = z->data[b_i] - ZCenterMean;
    nx = temp->size[1];
    i1 = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1]++;
    emxEnsureCapacity_real_T(temp, i1);
    temp->data[nx] = sqrt((P12_idx_2 * P12_idx_2 + d1 * d1) + K * K);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  Radius = mean(temp);
  scale = 3.3121686421112381E-170;
  absxk = fabs(dv[0]);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(dv[1]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(dv[2]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  d = dv[0] / b_y;
  N23_idx_0 = d;
  d1 = N23_idx_2 + d;
  d = dv[1] / b_y;
  N23_idx_1 = d;
  P23_idx_1 = YCenterMean + d;
  d = dv[2] / b_y;
  /*  三个点定义 */
  /*  斜率计算 */
  P12_idx_2 = d1 - N23_idx_2;
  d1 = P23_idx_1 - YCenterMean;
  P23_idx_1 = (ZCenterMean + d) - ZCenterMean;
  K = -(((N23_idx_2 - P4[0]) * P12_idx_2 + (YCenterMean - P4[1]) * d1) +
        (ZCenterMean - P4[2]) * P23_idx_1) /
      ((P12_idx_2 * P12_idx_2 + d1 * d1) + P23_idx_1 * P23_idx_1);
  /*  P1点在轴线上的投影坐标 */
  S_idx_2 = K * P12_idx_2 + N23_idx_2;
  S_idx_1 = K * d1 + YCenterMean;
  S_idx_0_tmp = K * P23_idx_1 + ZCenterMean;
  scale = 3.3121686421112381E-170;
  absxk = fabs(P12_idx_2);
  if (absxk > 3.3121686421112381E-170) {
    N23_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    N23_idx_2 = t * t;
  }
  absxk = fabs(d1);
  if (absxk > scale) {
    t = scale / absxk;
    N23_idx_2 = N23_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    N23_idx_2 += t * t;
  }
  absxk = fabs(P23_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    N23_idx_2 = N23_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    N23_idx_2 += t * t;
  }
  N23_idx_2 = scale * sqrt(N23_idx_2);
  /*  -----------------------------生成抽样点------------------------------- */
  P12_idx_2 =
      rt_atan2d_snf(d, sqrt(N23_idx_0 * N23_idx_0 + N23_idx_1 * N23_idx_1));
  d1 = rt_atan2d_snf(N23_idx_1, N23_idx_0);
  K = cos(P12_idx_2);
  /*  定义法向量 */
  ZCenterMean = K * cos(d1);
  YCenterMean = K * sin(d1);
  P12_idx_2 = sin(P12_idx_2);
  /*  检查法向量是否是单位向量，如果不是则归一化 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(ZCenterMean);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  absxk = fabs(YCenterMean);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  absxk = fabs(P12_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  K = scale * sqrt(K);
  if (K != 1.0) {
    ZCenterMean /= K;
    YCenterMean /= K;
    P12_idx_2 /= K;
  }
  /*  使用参数方程生成单位圆上的点 */
  if (!(num + 1.0 >= 0.0)) {
    YCenter->size[0] = 1;
    YCenter->size[1] = 0;
  } else {
    K = floor(num + 1.0);
    i = YCenter->size[0] * YCenter->size[1];
    YCenter->size[0] = 1;
    YCenter->size[1] = (int)K;
    emxEnsureCapacity_real_T(YCenter, i);
    if ((int)K >= 1) {
      YCenter->data[(int)K - 1] = 6.2831853071795862;
      if (YCenter->size[1] >= 2) {
        YCenter->data[0] = 0.0;
        if (YCenter->size[1] >= 3) {
          d1 = 6.2831853071795862 / ((double)YCenter->size[1] - 1.0);
          i = YCenter->size[1];
          for (b_i = 0; b_i <= i - 3; b_i++) {
            YCenter->data[b_i + 1] = ((double)b_i + 1.0) * d1;
          }
        }
      }
    }
  }
  d1 = YCenterMean - P12_idx_2 * 0.0;
  P23_idx_1 = P12_idx_2 * 0.0 - ZCenterMean;
  K = ZCenterMean * 0.0 - YCenterMean * 0.0;
  /*  找到与法向量垂直的一个向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(d1);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(P23_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  t = K / scale;
  b_y += t * t;
  b_y = scale * sqrt(b_y);
  if (b_y < 2.2204460492503131E-16) {
    /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
    d1 = YCenterMean * 0.0 - P12_idx_2;
    P23_idx_1 = P12_idx_2 * 0.0 - ZCenterMean * 0.0;
    K = ZCenterMean - YCenterMean * 0.0;
  }
  scale = 3.3121686421112381E-170;
  absxk = fabs(d1);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(P23_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(K);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  d1 /= b_y;
  P23_idx_1 /= b_y;
  K /= b_y;
  /*  归一化向量 */
  N12_idx_0 = P23_idx_1 * P12_idx_2 - YCenterMean * K;
  N12_idx_1 = ZCenterMean * K - d1 * P12_idx_2;
  N12_idx_2 = d1 * YCenterMean - ZCenterMean * P23_idx_1;
  /*  创建另一个垂直向量 */
  /*  单位圆的参数方程 */
  i = ZCenter->size[0] * ZCenter->size[1];
  ZCenter->size[0] = 1;
  ZCenter->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(ZCenter, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    ZCenter->data[i] = YCenter->data[i];
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    ZCenter->data[b_i] = cos(ZCenter->data[b_i]);
  }
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(temp, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    temp->data[i] = YCenter->data[i];
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    temp->data[b_i] = sin(temp->data[b_i]);
  }
  i = ZCenter->size[0] * ZCenter->size[1];
  ZCenter->size[0] = 1;
  emxEnsureCapacity_real_T(ZCenter, i);
  loop_ub = ZCenter->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    ZCenter->data[i] = ZCenter->data[i] * d1 + temp->data[i] * N12_idx_0;
  }
  emxInit_real_T(&y_circle, 2);
  i = y_circle->size[0] * y_circle->size[1];
  y_circle->size[0] = 1;
  y_circle->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(y_circle, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_circle->data[i] = YCenter->data[i];
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    y_circle->data[b_i] = cos(y_circle->data[b_i]);
  }
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(temp, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    temp->data[i] = YCenter->data[i];
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    temp->data[b_i] = sin(temp->data[b_i]);
  }
  i = y_circle->size[0] * y_circle->size[1];
  y_circle->size[0] = 1;
  emxEnsureCapacity_real_T(y_circle, i);
  loop_ub = y_circle->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    y_circle->data[i] =
        y_circle->data[i] * P23_idx_1 + temp->data[i] * N12_idx_1;
  }
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(temp, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    temp->data[i] = YCenter->data[i];
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    temp->data[b_i] = cos(temp->data[b_i]);
  }
  nx = YCenter->size[1];
  for (b_i = 0; b_i < nx; b_i++) {
    YCenter->data[b_i] = sin(YCenter->data[b_i]);
  }
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, i);
  loop_ub = temp->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    temp->data[i] = temp->data[i] * K + YCenter->data[i] * N12_idx_2;
  }
  emxInit_real_T(&Xlay0, 2);
  if (1 > ZCenter->size[1] - 1) {
    loop_ub = 0;
  } else {
    loop_ub = ZCenter->size[1] - 1;
  }
  if (1 > y_circle->size[1] - 1) {
    nx = 0;
  } else {
    nx = y_circle->size[1] - 1;
  }
  if (1 > temp->size[1] - 1) {
    b_i = 0;
  } else {
    b_i = temp->size[1] - 1;
  }
  /*  ----------------------------移动到原点------------------------------- */
  i = Xlay0->size[0] * Xlay0->size[1];
  Xlay0->size[0] = 1;
  Xlay0->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Xlay0, i);
  for (i = 0; i < loop_ub; i++) {
    Xlay0->data[i] = ZCenter->data[i] * Radius + S_idx_2;
  }
  emxInit_real_T(&Ylay0, 2);
  i = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  Ylay0->size[1] = nx;
  emxEnsureCapacity_real_T(Ylay0, i);
  for (i = 0; i < nx; i++) {
    Ylay0->data[i] = y_circle->data[i] * Radius + S_idx_1;
  }
  emxInit_real_T(&Zlay0, 2);
  i = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  Zlay0->size[1] = b_i;
  emxEnsureCapacity_real_T(Zlay0, i);
  for (i = 0; i < b_i; i++) {
    Zlay0->data[i] = temp->data[i] * Radius + S_idx_0_tmp;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  linspace(0.2 * N23_idx_2, 0.8 * N23_idx_2, laynum, temp);
  YCenter->size[0] = 1;
  YCenter->size[1] = 0;
  ZCenter->size[0] = 1;
  ZCenter->size[1] = 0;
  y_circle->size[0] = 1;
  y_circle->size[1] = 0;
  i = (int)laynum;
  for (b_i = 0; b_i < i; b_i++) {
    nx = YCenter->size[1];
    loop_ub = Xlay0->size[1];
    i1 = YCenter->size[0] * YCenter->size[1];
    YCenter->size[1] += Xlay0->size[1];
    emxEnsureCapacity_real_T(YCenter, i1);
    P12_idx_2 = temp->data[b_i] * N23_idx_0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      YCenter->data[nx + i1] = Xlay0->data[i1] - P12_idx_2;
    }
    nx = ZCenter->size[1];
    loop_ub = Ylay0->size[1];
    i1 = ZCenter->size[0] * ZCenter->size[1];
    ZCenter->size[1] += Ylay0->size[1];
    emxEnsureCapacity_real_T(ZCenter, i1);
    P12_idx_2 = temp->data[b_i] * N23_idx_1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      ZCenter->data[nx + i1] = Ylay0->data[i1] - P12_idx_2;
    }
    nx = y_circle->size[1];
    loop_ub = Zlay0->size[1];
    i1 = y_circle->size[0] * y_circle->size[1];
    y_circle->size[1] += Zlay0->size[1];
    emxEnsureCapacity_real_T(y_circle, i1);
    P12_idx_2 = temp->data[b_i] * d;
    for (i1 = 0; i1 < loop_ub; i1++) {
      y_circle->data[nx + i1] = Zlay0->data[i1] - P12_idx_2;
    }
  }
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&Xlay0);
  emxFree_real_T(&temp);
  i = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = YCenter->size[1];
  emxEnsureCapacity_real_T(Point_test, i);
  loop_ub = YCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    Point_test->data[3 * i] = YCenter->data[i];
  }
  emxFree_real_T(&YCenter);
  loop_ub = ZCenter->size[1];
  for (i = 0; i < loop_ub; i++) {
    Point_test->data[3 * i + 1] = ZCenter->data[i];
  }
  emxFree_real_T(&ZCenter);
  loop_ub = y_circle->size[1];
  for (i = 0; i < loop_ub; i++) {
    Point_test->data[3 * i + 2] = y_circle->data[i];
  }
  emxFree_real_T(&y_circle);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
