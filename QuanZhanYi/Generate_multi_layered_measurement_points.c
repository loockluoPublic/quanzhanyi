/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 17:37:00
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_data.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_emxutil.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_initialize.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_types.h"
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
  double f_P12[3];
  double f_P23[3];
  const double *x_data;
  const double *y_data;
  const double *z_data;
  double XCenterMean;
  double YCenterMean;
  double absxk;
  double b_nmk;
  double b_y;
  double f_N12_idx_0;
  double f_N12_idx_1;
  double f_N12_idx_2;
  double f_N23_idx_0;
  double f_N23_idx_0_tmp;
  double f_N23_idx_1;
  double f_N23_idx_2;
  double f_S_idx_0;
  double f_S_idx_1;
  double f_S_idx_2;
  double f_d1;
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
  if (!isInitialized_foot_of_perpendicular_from_a_point_to_a_line) {
    foot_of_perpendicular_from_a_point_to_a_line_initialize();
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
    /*      [s,xcenter,ycenter,zcenter] =
     * Three_Points_Initial_Rough_Cylindrical_Judgment(xxx,yyy,zzz); */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    f_S_idx_1 = order_data[combj];
    f_d1 = order_data[combj + order->size[0]];
    b_nmk = order_data[combj + order->size[0] * 2];
    XCenterMean = x_data[(int)f_d1 - 1];
    scale = x_data[(int)f_S_idx_1 - 1];
    f_N12_idx_0 = XCenterMean - scale;
    YCenterMean = y_data[(int)f_d1 - 1];
    absxk = y_data[(int)f_S_idx_1 - 1];
    f_N12_idx_1 = YCenterMean - absxk;
    t = z_data[(int)f_d1 - 1];
    f_d1 = z_data[(int)f_S_idx_1 - 1];
    f_N12_idx_2 = t - f_d1;
    f_N23_idx_0_tmp = x_data[(int)b_nmk - 1];
    f_N23_idx_0 = f_N23_idx_0_tmp - XCenterMean;
    b_y = y_data[(int)b_nmk - 1];
    f_N23_idx_1 = b_y - YCenterMean;
    b_nmk = z_data[(int)b_nmk - 1];
    f_N23_idx_2 = b_nmk - t;
    f_S_idx_0 = f_N12_idx_1 * f_N23_idx_2 - f_N23_idx_1 * f_N12_idx_2;
    f_S_idx_1 = f_N23_idx_0 * f_N12_idx_2 - f_N12_idx_0 * f_N23_idx_2;
    f_S_idx_2 = f_N12_idx_0 * f_N23_idx_1 - f_N23_idx_0 * f_N12_idx_1;
    /* 方向向量 */
    /*     %% 计算交点 */
    f_d1 = -((f_N12_idx_0 * ((scale + XCenterMean) / 2.0) +
              f_N12_idx_1 * ((absxk + YCenterMean) / 2.0)) +
             f_N12_idx_2 * ((f_d1 + t) / 2.0));
    b_nmk = (f_d1 * f_N23_idx_1 -
             f_N12_idx_1 *
                 -((f_N23_idx_0 * ((XCenterMean + f_N23_idx_0_tmp) / 2.0) +
                    f_N23_idx_1 * ((YCenterMean + b_y) / 2.0)) +
                   f_N23_idx_2 * ((t + b_nmk) / 2.0))) /
            (f_N12_idx_1 * f_N23_idx_2 - f_N23_idx_1 * f_N12_idx_2);
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    scale = 3.3121686421112381E-170;
    absxk = fabs(f_S_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(f_S_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(f_S_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    b_y = scale * sqrt(b_y);
    nmkpi = S->size[1];
    nblocks = S->size[0] * S->size[1];
    S->size[0] = 3;
    S->size[1]++;
    emxEnsureCapacity_real_T(S, nblocks);
    S_data = S->data;
    S_data[3 * nmkpi] = f_S_idx_0 / b_y;
    S_data[3 * nmkpi + 1] = f_S_idx_1 / b_y;
    S_data[3 * nmkpi + 2] = f_S_idx_2 / b_y;
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
    YCenter_data[nmkpi] = -(f_N12_idx_2 * b_nmk + f_d1) / f_N12_idx_1;
    nmkpi = ZCenter->size[1];
    nblocks = ZCenter->size[0] * ZCenter->size[1];
    ZCenter->size[1]++;
    emxEnsureCapacity_real_T(ZCenter, nblocks);
    ZCenter_data = ZCenter->data;
    ZCenter_data[nmkpi] = b_nmk;
  }
  emxFree_real_T(&order);
  XCenterMean = mean(temp);
  YCenterMean = mean(YCenter);
  f_S_idx_0 = mean(ZCenter);
  if (S->size[1] == 0) {
    f_N12_idx_0 = 0.0;
    f_N12_idx_1 = 0.0;
    f_N12_idx_2 = 0.0;
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
    f_N12_idx_0 = S_data[0];
    f_N12_idx_1 = S_data[1];
    f_N12_idx_2 = S_data[2];
    for (k = 2; k <= nmk; k++) {
      combj = (k - 1) * 3;
      f_N12_idx_0 += S_data[combj];
      f_N12_idx_1 += S_data[combj + 1];
      f_N12_idx_2 += S_data[combj + 2];
    }
    for (row = 2; row <= nblocks; row++) {
      nmk = (row - 1) * 3072;
      f_P12[0] = S_data[nmk];
      f_P12[1] = S_data[nmk + 1];
      f_P12[2] = S_data[nmk + 2];
      if (row == nblocks) {
        nmkpi = lastBlockLength;
      } else {
        nmkpi = 1024;
      }
      for (k = 2; k <= nmkpi; k++) {
        combj = nmk + (k - 1) * 3;
        f_P12[0] += S_data[combj];
        f_P12[1] += S_data[combj + 1];
        f_P12[2] += S_data[combj + 2];
      }
      f_N12_idx_0 += f_P12[0];
      f_N12_idx_1 += f_P12[1];
      f_N12_idx_2 += f_P12[2];
    }
  }
  f_N12_idx_0 /= (double)S->size[1];
  f_N12_idx_1 /= (double)S->size[1];
  f_N12_idx_2 /= (double)S->size[1];
  /*  -----------------------------计算参数------------------------------- */
  temp->size[0] = 1;
  temp->size[1] = 0;
  i = x->size[0];
  emxFree_real_T(&S);
  for (combj = 0; combj < i; combj++) {
    b_nmk = x_data[combj] - XCenterMean;
    b_y = y_data[combj] - YCenterMean;
    f_d1 = z_data[combj] - f_S_idx_0;
    nmkpi = temp->size[1];
    nblocks = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1]++;
    emxEnsureCapacity_real_T(temp, nblocks);
    temp_data = temp->data;
    temp_data[nmkpi] = sqrt((b_nmk * b_nmk + b_y * b_y) + f_d1 * f_d1);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  f_N23_idx_1 = mean(temp);
  scale = 3.3121686421112381E-170;
  absxk = fabs(f_N12_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(f_N12_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(f_N12_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  f_P12[0] = XCenterMean;
  f_P12[1] = YCenterMean;
  f_P12[2] = f_S_idx_0;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  f_S_idx_1 = f_N12_idx_0 / b_y;
  f_N12_idx_0 = f_S_idx_1;
  f_P23[0] = XCenterMean + f_S_idx_1;
  f_S_idx_1 = f_N12_idx_1 / b_y;
  f_N12_idx_1 = f_S_idx_1;
  f_P23[1] = YCenterMean + f_S_idx_1;
  f_S_idx_1 = f_N12_idx_2 / b_y;
  f_P23[2] = f_S_idx_0 + f_S_idx_1;
  foot_of_perpendicular_from_a_point_to_a_line(P4, f_P12, f_P23, &f_N23_idx_2,
                                               &f_N23_idx_0_tmp, &f_N23_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, f_P12, f_P23, &b_nmk, &b_y,
                                               &f_d1);
  scale = 3.3121686421112381E-170;
  absxk = fabs(f_P23[0] - XCenterMean);
  if (absxk > 3.3121686421112381E-170) {
    b_nmk = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_nmk = t * t;
  }
  absxk = fabs(f_P23[1] - YCenterMean);
  if (absxk > scale) {
    t = scale / absxk;
    b_nmk = b_nmk * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_nmk += t * t;
  }
  absxk = fabs(f_P23[2] - f_S_idx_0);
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
      rt_atan2d_snf(f_S_idx_1, sqrt(f_N12_idx_0 * f_N12_idx_0 +
                                    f_N12_idx_1 * f_N12_idx_1)),
      rt_atan2d_snf(f_N12_idx_1, f_N12_idx_0), num, temp, YCenter, ZCenter);
  /*  ----------------------------移动到原点------------------------------- */
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, i);
  temp_data = temp->data;
  nmk = temp->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    temp_data[i] = temp_data[i] * f_N23_idx_1 + f_N23_idx_2;
  }
  i = YCenter->size[0] * YCenter->size[1];
  YCenter->size[0] = 1;
  emxEnsureCapacity_real_T(YCenter, i);
  YCenter_data = YCenter->data;
  nmk = YCenter->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    YCenter_data[i] = YCenter_data[i] * f_N23_idx_1 + f_N23_idx_0_tmp;
  }
  i = ZCenter->size[0] * ZCenter->size[1];
  ZCenter->size[0] = 1;
  emxEnsureCapacity_real_T(ZCenter, i);
  ZCenter_data = ZCenter->data;
  nmk = ZCenter->size[1] - 1;
  for (i = 0; i <= nmk; i++) {
    ZCenter_data[i] = ZCenter_data[i] * f_N23_idx_1 + f_N23_idx_0;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  b_y = 0.2 * b_nmk;
  b_nmk *= 0.8;
  emxInit_real_T(&Layer, 2);
  order_data = Layer->data;
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    f_d1 = floor(laynum);
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)f_d1;
    emxEnsureCapacity_real_T(Layer, i);
    order_data = Layer->data;
    if ((int)f_d1 >= 1) {
      nmk = (int)f_d1 - 1;
      order_data[(int)floor(laynum) - 1] = b_nmk;
      if (Layer->size[1] >= 2) {
        order_data[0] = b_y;
        if (Layer->size[1] >= 3) {
          if ((b_y == -b_nmk) && ((int)f_d1 > 2)) {
            b_nmk /= (double)(int)f_d1 - 1.0;
            for (k = 2; k <= nmk; k++) {
              order_data[k - 1] = (double)(((k << 1) - (int)f_d1) - 1) * b_nmk;
            }
            if (((int)f_d1 & 1) == 1) {
              order_data[(int)f_d1 >> 1] = 0.0;
            }
          } else {
            b_nmk = (b_nmk - b_y) / ((double)Layer->size[1] - 1.0);
            i = Layer->size[1];
            for (k = 0; k <= i - 3; k++) {
              order_data[k + 1] = b_y + ((double)k + 1.0) * b_nmk;
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
    b_nmk = order_data[combj] * f_N12_idx_0;
    for (nblocks = 0; nblocks < nmk; nblocks++) {
      S_data[nmkpi + nblocks] = temp_data[nblocks] - b_nmk;
    }
    nmkpi = Point_testy->size[1];
    nmk = YCenter->size[1];
    nblocks = Point_testy->size[0] * Point_testy->size[1];
    Point_testy->size[1] += YCenter->size[1];
    emxEnsureCapacity_real_T(Point_testy, nblocks);
    Point_testy_data = Point_testy->data;
    b_nmk = order_data[combj] * f_N12_idx_1;
    for (nblocks = 0; nblocks < nmk; nblocks++) {
      Point_testy_data[nmkpi + nblocks] = YCenter_data[nblocks] - b_nmk;
    }
    nmkpi = Point_testz->size[1];
    nmk = ZCenter->size[1];
    nblocks = Point_testz->size[0] * Point_testz->size[1];
    Point_testz->size[1] += ZCenter->size[1];
    emxEnsureCapacity_real_T(Point_testz, nblocks);
    Point_testz_data = Point_testz->data;
    b_nmk = order_data[combj] * f_S_idx_1;
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
