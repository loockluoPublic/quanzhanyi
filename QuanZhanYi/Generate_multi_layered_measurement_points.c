/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 13:55:20
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
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

static double rt_roundd_snf(double u);

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
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
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
  emxArray_real_T *Layer;
  emxArray_real_T *Point_testx;
  emxArray_real_T *Point_testy;
  emxArray_real_T *Point_testz;
  emxArray_real_T *S;
  emxArray_real_T *YCenter;
  emxArray_real_T *ZCenter;
  emxArray_real_T *order;
  emxArray_real_T *temp;
  double P12[3];
  double P23[3];
  const double *x_data;
  const double *y_data;
  const double *z_data;
  double N12_idx_0;
  double N12_idx_0_tmp;
  double N12_idx_1;
  double N12_idx_1_tmp;
  double N12_idx_2;
  double N12_idx_2_tmp;
  double N23_idx_0;
  double N23_idx_0_tmp;
  double N23_idx_1;
  double N23_idx_2;
  double Radius;
  double YCenterMean;
  double ZCenterMean;
  double absxk;
  double b_N12_idx_1_tmp;
  double b_N12_idx_2_tmp;
  double b_nmk;
  double b_y;
  double d1;
  double s_idx_2;
  double scale;
  double t;
  double *Point_testy_data;
  double *Point_testz_data;
  double *S_data;
  double *YCenter_data;
  double *ZCenter_data;
  double *order_data;
  double *temp_data;
  int comb[3];
  int combj;
  int i;
  int k;
  int lastBlockLength;
  int nblocks;
  int nmk;
  int nmkpi;
  int row;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  z_data = z->data;
  y_data = y->data;
  x_data = x->data;
  emxInit_real_T(&temp, 2);
  temp_data = temp->data;
  if (x->size[0] < 1) {
    temp->size[0] = 1;
    temp->size[1] = 0;
  } else {
    i = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = x->size[0];
    emxEnsureCapacity_real_T(temp, i);
    temp_data = temp->data;
    nmk = x->size[0] - 1;
    for (i = 0; i <= nmk; i++) {
      temp_data[i] = (double)i + 1.0;
    }
  }
  emxInit_real_T(&order, 2);
  order_data = order->data;
  if (temp->size[1] == 1) {
    if (!(temp_data[0] < 3.0)) {
      k = 3;
      if (temp_data[0] / 2.0 < 3.0) {
        k = (int)temp_data[0] - 3;
      }
      if (k > 1000) {
        b_y = rtInf;
      } else {
        b_y = 1.0;
        b_nmk = temp_data[0] - (double)k;
        for (nmkpi = 0; nmkpi < k; nmkpi++) {
          b_y *= (((double)nmkpi + 1.0) + b_nmk) / ((double)nmkpi + 1.0);
        }
        b_y = rt_roundd_snf(b_y);
      }
      i = order->size[0] * order->size[1];
      order->size[0] = 1;
      order->size[1] = 1;
      emxEnsureCapacity_real_T(order, i);
      order_data = order->data;
      order_data[0] = b_y;
    }
  } else if (temp->size[1] < 3) {
    order->size[0] = 0;
    order->size[1] = 3;
  } else {
    k = 3;
    if ((double)temp->size[1] / 2.0 < 3.0) {
      k = temp->size[1] - 3;
    }
    if (k > 1000) {
      b_y = rtInf;
    } else {
      b_y = 1.0;
      nmk = temp->size[1] - k;
      for (nmkpi = 0; nmkpi < k; nmkpi++) {
        b_y *= (((double)nmkpi + 1.0) + (double)nmk) / ((double)nmkpi + 1.0);
      }
      b_y = rt_roundd_snf(b_y);
    }
    lastBlockLength = (int)b_y;
    i = order->size[0] * order->size[1];
    order->size[0] = (int)b_y;
    order->size[1] = 3;
    emxEnsureCapacity_real_T(order, i);
    order_data = order->data;
    comb[0] = 1;
    comb[1] = 2;
    comb[2] = 3;
    nmk = 2;
    nmkpi = temp->size[1];
    for (row = 0; row < lastBlockLength; row++) {
      order_data[row] = temp_data[comb[0] - 1];
      order_data[row + order->size[0]] = temp_data[comb[1] - 1];
      order_data[row + order->size[0] * 2] = temp_data[comb[2] - 1];
      if (nmk + 1 > 0) {
        nblocks = comb[nmk];
        combj = comb[nmk] + 1;
        comb[nmk]++;
        if (nblocks + 1 < nmkpi) {
          i = nmk + 2;
          for (nmkpi = i; nmkpi < 4; nmkpi++) {
            combj++;
            comb[nmkpi - 1] = combj;
          }
          nmk = 2;
          nmkpi = temp->size[1];
        } else {
          nmk--;
          nmkpi--;
        }
      }
    }
  }
  emxInit_real_T(&YCenter, 2);
  emxInit_real_T(&ZCenter, 2);
  emxInit_real_T(&S, 2);
  S_data = S->data;
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
  for (combj = 0; combj < i; combj++) {
    s_idx_2 = order_data[combj];
    N12_idx_2_tmp = order_data[combj + order->size[0]];
    b_nmk = order_data[combj + order->size[0] * 2];
    N12_idx_0_tmp = x_data[(int)N12_idx_2_tmp - 1];
    d1 = x_data[(int)s_idx_2 - 1];
    N12_idx_0 = N12_idx_0_tmp - d1;
    N12_idx_1_tmp = y_data[(int)N12_idx_2_tmp - 1];
    b_N12_idx_1_tmp = y_data[(int)s_idx_2 - 1];
    N12_idx_1 = N12_idx_1_tmp - b_N12_idx_1_tmp;
    b_N12_idx_2_tmp = z_data[(int)N12_idx_2_tmp - 1];
    N12_idx_2_tmp = z_data[(int)s_idx_2 - 1];
    N12_idx_2 = b_N12_idx_2_tmp - N12_idx_2_tmp;
    N23_idx_0_tmp = x_data[(int)b_nmk - 1];
    N23_idx_0 = N23_idx_0_tmp - N12_idx_0_tmp;
    Radius = y_data[(int)b_nmk - 1];
    N23_idx_1 = Radius - N12_idx_1_tmp;
    b_nmk = z_data[(int)b_nmk - 1];
    N23_idx_2 = b_nmk - b_N12_idx_2_tmp;
    YCenterMean = N12_idx_1 * N23_idx_2 - N23_idx_1 * N12_idx_2;
    ZCenterMean = N23_idx_0 * N12_idx_2 - N12_idx_0 * N23_idx_2;
    s_idx_2 = N12_idx_0 * N23_idx_1 - N23_idx_0 * N12_idx_1;
    /* 方向向量 */
    scale = 3.3121686421112381E-170;
    absxk = fabs(YCenterMean);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(ZCenterMean);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(s_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    b_y = scale * sqrt(b_y);
    /*     %% 计算交点 */
    d1 = -((N12_idx_0 * ((d1 + N12_idx_0_tmp) / 2.0) +
            N12_idx_1 * ((b_N12_idx_1_tmp + N12_idx_1_tmp) / 2.0)) +
           N12_idx_2 * ((N12_idx_2_tmp + b_N12_idx_2_tmp) / 2.0));
    b_nmk =
        (d1 * N23_idx_1 -
         N12_idx_1 * -((N23_idx_0 * ((N12_idx_0_tmp + N23_idx_0_tmp) / 2.0) +
                        N23_idx_1 * ((N12_idx_1_tmp + Radius) / 2.0)) +
                       N23_idx_2 * ((b_N12_idx_2_tmp + b_nmk) / 2.0))) /
        (N12_idx_1 * N23_idx_2 - N23_idx_1 * N12_idx_2);
    nmkpi = S->size[1];
    nblocks = S->size[0] * S->size[1];
    S->size[0] = 3;
    S->size[1]++;
    emxEnsureCapacity_real_T(S, nblocks);
    S_data = S->data;
    S_data[3 * nmkpi] = YCenterMean / b_y;
    S_data[3 * nmkpi + 1] = ZCenterMean / b_y;
    S_data[3 * nmkpi + 2] = s_idx_2 / b_y;
    nmkpi = temp->size[1];
    nblocks = temp->size[0] * temp->size[1];
    temp->size[1]++;
    emxEnsureCapacity_real_T(temp, nblocks);
    temp_data = temp->data;
    temp_data[nmkpi] = 0.0;
    nmkpi = YCenter->size[1];
    nblocks = YCenter->size[0] * YCenter->size[1];
    YCenter->size[1]++;
    emxEnsureCapacity_real_T(YCenter, nblocks);
    YCenter_data = YCenter->data;
    YCenter_data[nmkpi] = -(N12_idx_2 * b_nmk + d1) / N12_idx_1;
    nmkpi = ZCenter->size[1];
    nblocks = ZCenter->size[0] * ZCenter->size[1];
    ZCenter->size[1]++;
    emxEnsureCapacity_real_T(ZCenter, nblocks);
    ZCenter_data = ZCenter->data;
    ZCenter_data[nmkpi] = b_nmk;
  }
  emxFree_real_T(&order);
  N23_idx_1 = mean(temp);
  YCenterMean = mean(YCenter);
  ZCenterMean = mean(ZCenter);
  if (S->size[1] == 0) {
    N12_idx_0 = 0.0;
    N12_idx_1 = 0.0;
    N12_idx_2 = 0.0;
  } else {
    if (S->size[1] <= 1024) {
      nmk = S->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      nmk = 1024;
      nblocks = S->size[1] / 1024;
      lastBlockLength = S->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    N12_idx_0 = S_data[0];
    N12_idx_1 = S_data[1];
    N12_idx_2 = S_data[2];
    for (k = 2; k <= nmk; k++) {
      combj = (k - 1) * 3;
      N12_idx_0 += S_data[combj];
      N12_idx_1 += S_data[combj + 1];
      N12_idx_2 += S_data[combj + 2];
    }
    for (row = 2; row <= nblocks; row++) {
      nmk = (row - 1) * 3072;
      P12[0] = S_data[nmk];
      P12[1] = S_data[nmk + 1];
      P12[2] = S_data[nmk + 2];
      if (row == nblocks) {
        nmkpi = lastBlockLength;
      } else {
        nmkpi = 1024;
      }
      for (k = 2; k <= nmkpi; k++) {
        combj = nmk + (k - 1) * 3;
        P12[0] += S_data[combj];
        P12[1] += S_data[combj + 1];
        P12[2] += S_data[combj + 2];
      }
      N12_idx_0 += P12[0];
      N12_idx_1 += P12[1];
      N12_idx_2 += P12[2];
    }
  }
  N12_idx_0 /= (double)S->size[1];
  N12_idx_1 /= (double)S->size[1];
  N12_idx_2 /= (double)S->size[1];
  /*  -----------------------------计算参数------------------------------- */
  temp->size[0] = 1;
  temp->size[1] = 0;
  i = x->size[0];
  emxFree_real_T(&S);
  for (combj = 0; combj < i; combj++) {
    b_nmk = x_data[combj] - N23_idx_1;
    N12_idx_2_tmp = y_data[combj] - YCenterMean;
    N23_idx_2 = z_data[combj] - ZCenterMean;
    nmkpi = temp->size[1];
    nblocks = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1]++;
    emxEnsureCapacity_real_T(temp, nblocks);
    temp_data = temp->data;
    temp_data[nmkpi] = sqrt((b_nmk * b_nmk + N12_idx_2_tmp * N12_idx_2_tmp) +
                            N23_idx_2 * N23_idx_2);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  Radius = mean(temp);
  scale = 3.3121686421112381E-170;
  absxk = fabs(N12_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(N12_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(N12_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  P12[0] = N23_idx_1;
  P12[1] = YCenterMean;
  P12[2] = ZCenterMean;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  s_idx_2 = N12_idx_0 / b_y;
  N12_idx_0 = s_idx_2;
  P23[0] = N23_idx_1 + s_idx_2;
  s_idx_2 = N12_idx_1 / b_y;
  N12_idx_1 = s_idx_2;
  P23[1] = YCenterMean + s_idx_2;
  s_idx_2 = N12_idx_2 / b_y;
  P23[2] = ZCenterMean + s_idx_2;
  foot_of_perpendicular_from_a_point_to_a_line(P4, P12, P23, &d1,
                                               &N23_idx_0_tmp, &N23_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, P12, P23, &b_nmk,
                                               &N12_idx_2_tmp, &N23_idx_2);
  scale = 3.3121686421112381E-170;
  absxk = fabs(P23[0] - N23_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    b_nmk = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_nmk = t * t;
  }
  absxk = fabs(P23[1] - YCenterMean);
  if (absxk > scale) {
    t = scale / absxk;
    b_nmk = b_nmk * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_nmk += t * t;
  }
  absxk = fabs(P23[2] - ZCenterMean);
  if (absxk > scale) {
    t = scale / absxk;
    b_nmk = b_nmk * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_nmk += t * t;
  }
  b_nmk = scale * sqrt(b_nmk);
  /*  -----------------------------生成抽样点------------------------------- */
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(s_idx_2,
                    sqrt(N12_idx_0 * N12_idx_0 + N12_idx_1 * N12_idx_1)),
      rt_atan2d_snf(N12_idx_1, N12_idx_0), num, temp, YCenter, ZCenter);
  /*  ----------------------------移动到原点------------------------------- */
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, i);
  temp_data = temp->data;
  nmk = temp->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    temp_data[i] = temp_data[i] * Radius + d1;
  }
  i = YCenter->size[0] * YCenter->size[1];
  YCenter->size[0] = 1;
  emxEnsureCapacity_real_T(YCenter, i);
  YCenter_data = YCenter->data;
  nmk = YCenter->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    YCenter_data[i] = YCenter_data[i] * Radius + N23_idx_0_tmp;
  }
  i = ZCenter->size[0] * ZCenter->size[1];
  ZCenter->size[0] = 1;
  emxEnsureCapacity_real_T(ZCenter, i);
  ZCenter_data = ZCenter->data;
  nmk = ZCenter->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    ZCenter_data[i] = ZCenter_data[i] * Radius + N23_idx_0;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  d1 = 0.2 * b_nmk;
  b_nmk *= 0.8;
  emxInit_real_T(&Layer, 2);
  order_data = Layer->data;
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    N12_idx_2_tmp = floor(laynum);
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)N12_idx_2_tmp;
    emxEnsureCapacity_real_T(Layer, i);
    order_data = Layer->data;
    if ((int)N12_idx_2_tmp >= 1) {
      nmk = (int)N12_idx_2_tmp - 1;
      order_data[(int)floor(laynum) - 1] = b_nmk;
      if (Layer->size[1] >= 2) {
        order_data[0] = d1;
        if (Layer->size[1] >= 3) {
          if ((d1 == -b_nmk) && ((int)N12_idx_2_tmp > 2)) {
            b_nmk /= (double)(int)N12_idx_2_tmp - 1.0;
            for (k = 2; k <= nmk; k++) {
              order_data[k - 1] =
                  (double)(((k << 1) - (int)N12_idx_2_tmp) - 1) * b_nmk;
            }
            if (((int)N12_idx_2_tmp & 1) == 1) {
              order_data[(int)N12_idx_2_tmp >> 1] = 0.0;
            }
          } else {
            b_nmk = (b_nmk - d1) / ((double)Layer->size[1] - 1.0);
            i = Layer->size[1];
            for (k = 0; k <= i - 3; k++) {
              order_data[k + 1] = d1 + ((double)k + 1.0) * b_nmk;
            }
          }
        }
      }
    }
  }
  emxInit_real_T(&Point_testx, 2);
  S_data = Point_testx->data;
  emxInit_real_T(&Point_testy, 2);
  Point_testy_data = Point_testy->data;
  emxInit_real_T(&Point_testz, 2);
  Point_testz_data = Point_testz->data;
  Point_testx->size[0] = 1;
  Point_testx->size[1] = 0;
  Point_testy->size[0] = 1;
  Point_testy->size[1] = 0;
  Point_testz->size[0] = 1;
  Point_testz->size[1] = 0;
  i = (int)laynum;
  for (combj = 0; combj < i; combj++) {
    nmkpi = Point_testx->size[1];
    nmk = temp->size[1];
    nblocks = Point_testx->size[0] * Point_testx->size[1];
    Point_testx->size[1] += temp->size[1];
    emxEnsureCapacity_real_T(Point_testx, nblocks);
    S_data = Point_testx->data;
    b_nmk = order_data[combj] * N12_idx_0;
    for (nblocks = 0; nblocks < nmk; nblocks++) {
      S_data[nmkpi + nblocks] = temp_data[nblocks] - b_nmk;
    }
    nmkpi = Point_testy->size[1];
    nmk = YCenter->size[1];
    nblocks = Point_testy->size[0] * Point_testy->size[1];
    Point_testy->size[1] += YCenter->size[1];
    emxEnsureCapacity_real_T(Point_testy, nblocks);
    Point_testy_data = Point_testy->data;
    b_nmk = order_data[combj] * N12_idx_1;
    for (nblocks = 0; nblocks < nmk; nblocks++) {
      Point_testy_data[nmkpi + nblocks] = YCenter_data[nblocks] - b_nmk;
    }
    nmkpi = Point_testz->size[1];
    nmk = ZCenter->size[1];
    nblocks = Point_testz->size[0] * Point_testz->size[1];
    Point_testz->size[1] += ZCenter->size[1];
    emxEnsureCapacity_real_T(Point_testz, nblocks);
    Point_testz_data = Point_testz->data;
    b_nmk = order_data[combj] * s_idx_2;
    for (nblocks = 0; nblocks < nmk; nblocks++) {
      Point_testz_data[nmkpi + nblocks] = ZCenter_data[nblocks] - b_nmk;
    }
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&ZCenter);
  emxFree_real_T(&YCenter);
  emxFree_real_T(&temp);
  i = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = Point_testx->size[1];
  emxEnsureCapacity_real_T(Point_test, i);
  order_data = Point_test->data;
  nmk = Point_testx->size[1];
  for (i = 0; i < nmk; i++) {
    order_data[3 * i] = S_data[i];
  }
  emxFree_real_T(&Point_testx);
  nmk = Point_testy->size[1];
  for (i = 0; i < nmk; i++) {
    order_data[3 * i + 1] = Point_testy_data[i];
  }
  emxFree_real_T(&Point_testy);
  nmk = Point_testz->size[1];
  for (i = 0; i < nmk; i++) {
    order_data[3 * i + 2] = Point_testz_data[i];
  }
  emxFree_real_T(&Point_testz);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
