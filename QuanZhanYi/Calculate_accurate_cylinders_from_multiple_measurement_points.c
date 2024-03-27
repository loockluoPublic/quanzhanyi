/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Mar-2024 15:44:04
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *points
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Mcenter[3]
 *                double MTaon[3]
 *                double *Mradial
 *                emxArray_real_T *Err_every
 *                double Bottom_round_center1[3]
 *                double Bottom_round_center2[3]
 * Return Type  : void
 */
void Calculate_accurate_cylinders_from_multiple_measurement_points(
    const emxArray_real_T *points, const double P_bound1[3],
    const double P_bound2[3], double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every, double Bottom_round_center1[3],
    double Bottom_round_center2[3])
{
  emxArray_real_T *b_points;
  emxArray_real_T *distances;
  emxArray_real_T *y;
  const double *points_data;
  double absxk;
  double axis_direction_idx_0;
  double axis_direction_idx_1;
  double axis_direction_idx_2;
  double b_y;
  double best_radius;
  double d;
  double m1_idx_0;
  double m1_idx_1;
  double min_residual;
  double residual;
  double scale;
  double t;
  double v1_idx_0;
  double v1_idx_1;
  double v1_idx_1_tmp;
  double v1_idx_2;
  double v1_idx_2_tmp;
  double v2_idx_0;
  double v2_idx_1;
  double v2_idx_2;
  double v3_idx_0;
  double v3_idx_1;
  double v3_idx_2;
  double v4_idx_0;
  double v4_idx_1;
  double v4_idx_2;
  double *b_points_data;
  double *distances_data;
  double *y_data;
  int b_i;
  unsigned int b_j;
  int b_k;
  int firstBlockLength;
  int i;
  int i1;
  int i2;
  int ib;
  int j;
  int k;
  int lastBlockLength;
  int nblocks;
  int num_points;
  int xblockoffset;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  points_data = points->data;
  emxInit_real_T(&b_points, 2);
  i = b_points->size[0] * b_points->size[1];
  b_points->size[0] = points->size[1];
  b_points->size[1] = 3;
  emxEnsureCapacity_real_T(b_points, i);
  b_points_data = b_points->data;
  firstBlockLength = points->size[1];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < firstBlockLength; i1++) {
      b_points_data[i1 + b_points->size[0] * i] = points_data[i + 3 * i1];
    }
  }
  num_points = b_points->size[0];
  min_residual = rtInf;
  Mcenter[0] = 0.0;
  MTaon[0] = 0.0;
  Mcenter[1] = 0.0;
  MTaon[1] = 0.0;
  Mcenter[2] = 0.0;
  MTaon[2] = 0.0;
  best_radius = 0.0;
  /*  尝试所有可能的圆柱面参数组合 */
  i = b_points->size[0];
  emxInit_real_T(&distances, 1);
  emxInit_real_T(&y, 1);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = num_points - b_i;
    for (j = 0; j <= i1 - 2; j++) {
      b_j = ((unsigned int)b_i + j) + 2U;
      i2 = (int)((double)num_points + (1.0 - ((double)b_j + 1.0)));
      for (k = 0; k < i2; k++) {
        /*  通过三个点确定圆柱面的轴线和半径 */
        firstBlockLength = (int)(b_j + k);
        xblockoffset = (int)b_j + k;
        residual = b_points_data[(int)b_j - 1];
        v1_idx_0 = residual - b_points_data[b_i];
        v2_idx_0 = b_points_data[xblockoffset] - b_points_data[b_i];
        v1_idx_1_tmp = b_points_data[((int)b_j + b_points->size[0]) - 1];
        v1_idx_1 = v1_idx_1_tmp - b_points_data[b_i + b_points->size[0]];
        v2_idx_1 = b_points_data[xblockoffset + b_points->size[0]] -
                   b_points_data[b_i + b_points->size[0]];
        v1_idx_2_tmp = b_points_data[((int)b_j + b_points->size[0] * 2) - 1];
        v1_idx_2 = v1_idx_2_tmp - b_points_data[b_i + b_points->size[0] * 2];
        v2_idx_2 = b_points_data[xblockoffset + b_points->size[0] * 2] -
                   b_points_data[b_i + b_points->size[0] * 2];
        axis_direction_idx_0 = v1_idx_1 * v2_idx_2 - v2_idx_1 * v1_idx_2;
        axis_direction_idx_1 = v2_idx_0 * v1_idx_2 - v1_idx_0 * v2_idx_2;
        axis_direction_idx_2 = v1_idx_0 * v2_idx_1 - v2_idx_0 * v1_idx_1;
        scale = 3.3121686421112381E-170;
        absxk = fabs(axis_direction_idx_0);
        if (absxk > 3.3121686421112381E-170) {
          b_y = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          b_y = t * t;
        }
        absxk = fabs(axis_direction_idx_1);
        if (absxk > scale) {
          t = scale / absxk;
          b_y = b_y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_y += t * t;
        }
        absxk = fabs(axis_direction_idx_2);
        if (absxk > scale) {
          t = scale / absxk;
          b_y = b_y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_y += t * t;
        }
        b_y = scale * sqrt(b_y);
        axis_direction_idx_0 /= b_y;
        axis_direction_idx_1 /= b_y;
        axis_direction_idx_2 /= b_y;
        v3_idx_0 =
            axis_direction_idx_1 * v1_idx_2 - v1_idx_1 * axis_direction_idx_2;
        v3_idx_1 =
            v1_idx_0 * axis_direction_idx_2 - axis_direction_idx_0 * v1_idx_2;
        v3_idx_2 =
            axis_direction_idx_0 * v1_idx_1 - v1_idx_0 * axis_direction_idx_1;
        v4_idx_0 =
            axis_direction_idx_1 * v2_idx_2 - v2_idx_1 * axis_direction_idx_2;
        v4_idx_1 =
            v2_idx_0 * axis_direction_idx_2 - axis_direction_idx_0 * v2_idx_2;
        v4_idx_2 =
            axis_direction_idx_0 * v2_idx_1 - v2_idx_0 * axis_direction_idx_1;
        d = (b_points_data[b_i] + residual) / 2.0;
        m1_idx_0 = d;
        residual =
            v4_idx_0 *
            (d - (b_points_data[b_i] + b_points_data[firstBlockLength]) / 2.0);
        d = (b_points_data[b_i + b_points->size[0]] + v1_idx_1_tmp) / 2.0;
        m1_idx_1 = d;
        residual += v4_idx_1 *
                    (d - (b_points_data[b_i + b_points->size[0]] +
                          b_points_data[firstBlockLength + b_points->size[0]]) /
                             2.0);
        d = (b_points_data[b_i + b_points->size[0] * 2] + v1_idx_2_tmp) / 2.0;
        v1_idx_2_tmp =
            (v4_idx_0 * v1_idx_0 + v4_idx_1 * v1_idx_1) + v4_idx_2 * v1_idx_2;
        residual +=
            v4_idx_2 *
            (d - (b_points_data[b_i + b_points->size[0] * 2] +
                  b_points_data[firstBlockLength + b_points->size[0] * 2]) /
                     2.0);
        residual = residual / v1_idx_2_tmp /
                   (((v3_idx_0 * v2_idx_0 + v3_idx_1 * v2_idx_1) +
                     v3_idx_2 * v2_idx_2) /
                        ((v3_idx_0 * v1_idx_0 + v3_idx_1 * v1_idx_1) +
                         v3_idx_2 * v1_idx_2) -
                    ((v4_idx_0 * v2_idx_0 + v4_idx_1 * v2_idx_1) +
                     v4_idx_2 * v2_idx_2) /
                        v1_idx_2_tmp);
        scale = 3.3121686421112381E-170;
        v1_idx_1_tmp = m1_idx_0 + residual * v3_idx_0;
        m1_idx_0 = v1_idx_1_tmp;
        absxk = fabs(v1_idx_1_tmp - b_points_data[b_i]);
        if (absxk > 3.3121686421112381E-170) {
          v1_idx_2_tmp = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          v1_idx_2_tmp = t * t;
        }
        v1_idx_1_tmp = m1_idx_1 + residual * v3_idx_1;
        m1_idx_1 = v1_idx_1_tmp;
        absxk = fabs(v1_idx_1_tmp - b_points_data[b_i + b_points->size[0]]);
        if (absxk > scale) {
          t = scale / absxk;
          v1_idx_2_tmp = v1_idx_2_tmp * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          v1_idx_2_tmp += t * t;
        }
        v1_idx_1_tmp = d + residual * v3_idx_2;
        absxk = fabs(v1_idx_1_tmp - b_points_data[b_i + b_points->size[0] * 2]);
        if (absxk > scale) {
          t = scale / absxk;
          v1_idx_2_tmp = v1_idx_2_tmp * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          v1_idx_2_tmp += t * t;
        }
        v1_idx_2_tmp = scale * sqrt(v1_idx_2_tmp);
        /*  计算拟合误差 */
        xblockoffset = b_points->size[0];
        firstBlockLength = distances->size[0];
        distances->size[0] = b_points->size[0];
        emxEnsureCapacity_real_T(distances, firstBlockLength);
        distances_data = distances->data;
        for (firstBlockLength = 0; firstBlockLength < xblockoffset;
             firstBlockLength++) {
          /*  计算每个点到圆柱面的距离 */
          d = b_points_data[firstBlockLength] - m1_idx_0;
          v4_idx_0 = d;
          residual = d * axis_direction_idx_0;
          d = b_points_data[firstBlockLength + b_points->size[0]] - m1_idx_1;
          v2_idx_0 = d;
          residual += d * axis_direction_idx_1;
          d = b_points_data[firstBlockLength + b_points->size[0] * 2] -
              v1_idx_1_tmp;
          residual += d * axis_direction_idx_2;
          scale = 3.3121686421112381E-170;
          absxk = fabs(v4_idx_0 - residual * axis_direction_idx_0);
          if (absxk > 3.3121686421112381E-170) {
            b_y = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            b_y = t * t;
          }
          absxk = fabs(v2_idx_0 - residual * axis_direction_idx_1);
          if (absxk > scale) {
            t = scale / absxk;
            b_y = b_y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            b_y += t * t;
          }
          absxk = fabs(d - residual * axis_direction_idx_2);
          if (absxk > scale) {
            t = scale / absxk;
            b_y = b_y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            b_y += t * t;
          }
          b_y = scale * sqrt(b_y);
          distances_data[firstBlockLength] = b_y - v1_idx_2_tmp;
        }
        /*  拟合误差为距离的平方和 */
        firstBlockLength = distances->size[0];
        xblockoffset = y->size[0];
        y->size[0] = distances->size[0];
        emxEnsureCapacity_real_T(y, xblockoffset);
        y_data = y->data;
        for (xblockoffset = 0; xblockoffset < firstBlockLength;
             xblockoffset++) {
          residual = distances_data[xblockoffset];
          y_data[xblockoffset] = residual * residual;
        }
        if (y->size[0] == 0) {
          residual = 0.0;
        } else {
          if (y->size[0] <= 1024) {
            firstBlockLength = y->size[0];
            lastBlockLength = 0;
            nblocks = 1;
          } else {
            firstBlockLength = 1024;
            nblocks = y->size[0] / 1024;
            lastBlockLength = y->size[0] - (nblocks << 10);
            if (lastBlockLength > 0) {
              nblocks++;
            } else {
              lastBlockLength = 1024;
            }
          }
          residual = y_data[0];
          for (b_k = 2; b_k <= firstBlockLength; b_k++) {
            residual += y_data[b_k - 1];
          }
          for (ib = 2; ib <= nblocks; ib++) {
            xblockoffset = (ib - 1) << 10;
            v4_idx_0 = y_data[xblockoffset];
            if (ib == nblocks) {
              firstBlockLength = lastBlockLength;
            } else {
              firstBlockLength = 1024;
            }
            for (b_k = 2; b_k <= firstBlockLength; b_k++) {
              v4_idx_0 += y_data[(xblockoffset + b_k) - 1];
            }
            residual += v4_idx_0;
          }
        }
        /*  更新最佳拟合参数 */
        if (residual < min_residual) {
          min_residual = residual;
          Mcenter[0] = m1_idx_0;
          MTaon[0] = axis_direction_idx_0;
          Mcenter[1] = m1_idx_1;
          MTaon[1] = axis_direction_idx_1;
          Mcenter[2] = v1_idx_1_tmp;
          MTaon[2] = axis_direction_idx_2;
          best_radius = v1_idx_2_tmp;
        }
      }
    }
  }
  emxFree_real_T(&y);
  emxFree_real_T(&distances);
  /* 圆心 */
  /* 法向量 */
  scale = 3.3121686421112381E-170;
  absxk = fabs(MTaon[0]);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(MTaon[1]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(MTaon[2]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  /* 半径 */
  d = MTaon[0] / b_y;
  MTaon[0] = d;
  v3_idx_0 = Mcenter[0] - 2.0 * d;
  d = MTaon[1] / b_y;
  MTaon[1] = d;
  v3_idx_1 = Mcenter[1] - 2.0 * d;
  d = MTaon[2] / b_y;
  MTaon[2] = d;
  v3_idx_2 = Mcenter[2] - 2.0 * d;
  firstBlockLength = b_points->size[0];
  i = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = b_points->size[0];
  emxEnsureCapacity_real_T(Err_every, i);
  distances_data = Err_every->data;
  for (i = 0; i < firstBlockLength; i++) {
    distances_data[i] = 0.0;
  }
  i = b_points->size[0] - 1;
  if (b_points->size[0] - 1 >= 0) {
    v1_idx_0 = v3_idx_0 - Mcenter[0];
    v1_idx_1 = v3_idx_1 - Mcenter[1];
    v1_idx_2 = v3_idx_2 - Mcenter[2];
  }
  for (firstBlockLength = 0; firstBlockLength <= i; firstBlockLength++) {
    v4_idx_0 = b_points_data[firstBlockLength] - Mcenter[0];
    v2_idx_0 = b_points_data[firstBlockLength + b_points->size[0]] - Mcenter[1];
    v4_idx_1 =
        b_points_data[firstBlockLength + b_points->size[0] * 2] - Mcenter[2];
    scale = 3.3121686421112381E-170;
    v4_idx_2 = 3.3121686421112381E-170;
    absxk = fabs(v2_idx_0 * v1_idx_2 - v1_idx_1 * v4_idx_1);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      v1_idx_1_tmp = 1.0;
      v4_idx_2 = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      v1_idx_1_tmp = t * t;
    }
    absxk = fabs(v1_idx_0 * v4_idx_1 - v4_idx_0 * v1_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > v4_idx_2) {
      t = v4_idx_2 / absxk;
      v1_idx_1_tmp = v1_idx_1_tmp * t * t + 1.0;
      v4_idx_2 = absxk;
    } else {
      t = absxk / v4_idx_2;
      v1_idx_1_tmp += t * t;
    }
    absxk = fabs(v4_idx_0 * v1_idx_1 - v1_idx_0 * v2_idx_0);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(v1_idx_2);
    if (absxk > v4_idx_2) {
      t = v4_idx_2 / absxk;
      v1_idx_1_tmp = v1_idx_1_tmp * t * t + 1.0;
      v4_idx_2 = absxk;
    } else {
      t = absxk / v4_idx_2;
      v1_idx_1_tmp += t * t;
    }
    b_y = scale * sqrt(b_y);
    v1_idx_1_tmp = v4_idx_2 * sqrt(v1_idx_1_tmp);
    distances_data[firstBlockLength] = b_y / v1_idx_1_tmp;
  }
  emxFree_real_T(&b_points);
  /*  比较与半径的差值（圆度） */
  i = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  emxEnsureCapacity_real_T(Err_every, i);
  distances_data = Err_every->data;
  firstBlockLength = Err_every->size[1] - 1;
  for (i = 0; i <= firstBlockLength; i++) {
    distances_data[i] -= best_radius;
  }
  /*  单个点误差 */
  v1_idx_2_tmp = mean(Err_every);
  i = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  emxEnsureCapacity_real_T(Err_every, i);
  distances_data = Err_every->data;
  firstBlockLength = Err_every->size[1] - 1;
  for (i = 0; i <= firstBlockLength; i++) {
    distances_data[i] -= v1_idx_2_tmp;
  }
  /*  三个点定义 */
  /*  斜率计算 */
  v1_idx_1_tmp = v3_idx_0 - Mcenter[0];
  v4_idx_2 = v3_idx_1 - Mcenter[1];
  v4_idx_0 = v3_idx_2 - Mcenter[2];
  residual =
      (v1_idx_1_tmp * v1_idx_1_tmp + v4_idx_2 * v4_idx_2) + v4_idx_0 * v4_idx_0;
  v4_idx_1 = -(((Mcenter[0] - P_bound1[0]) * v1_idx_1_tmp +
                (Mcenter[1] - P_bound1[1]) * v4_idx_2) +
               (Mcenter[2] - P_bound1[2]) * v4_idx_0) /
             residual;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  residual = -(((Mcenter[0] - P_bound2[0]) * v1_idx_1_tmp +
                (Mcenter[1] - P_bound2[1]) * v4_idx_2) +
               (Mcenter[2] - P_bound2[2]) * v4_idx_0) /
             residual;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = v4_idx_1 * v1_idx_1_tmp + Mcenter[0];
  Bottom_round_center1[1] = v4_idx_1 * v4_idx_2 + Mcenter[1];
  Bottom_round_center1[2] = v4_idx_1 * v4_idx_0 + Mcenter[2];
  Bottom_round_center2[0] = residual * v1_idx_1_tmp + Mcenter[0];
  Bottom_round_center2[1] = residual * v4_idx_2 + Mcenter[1];
  Bottom_round_center2[2] = residual * v4_idx_0 + Mcenter[2];
  *Mradial = v1_idx_2_tmp + best_radius;
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * [EOF]
 */
