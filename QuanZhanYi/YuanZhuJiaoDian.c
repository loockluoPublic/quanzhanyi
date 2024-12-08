/*
 * File: YuanZhuJiaoDian.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Dec-2024 19:01:03
 */

/* Include Files */
#include "YuanZhuJiaoDian.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"
#include "xgeev.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * 定义圆柱参数
 *  p0 = [x0, y0, z0];  % 圆柱轴线上的一点
 *  v = [vx, vy, vz];   % 圆柱的轴线方向向量，必须为单位向量
 *  r = radius;         % 圆柱的半径
 *
 *  % 定义直线上两点
 *  P1 = [x1, y1, z1];
 *  P2 = [x2, y2, z2];
 *
 * Arguments    : const double Mcenter[3]
 *                const double MTaon[3]
 *                double Mradial
 *                const double Pin1[3]
 *                const double Pin2[3]
 *                double Cross_point_data[]
 *                int Cross_point_size[2]
 * Return Type  : void
 */
void YuanZhuJiaoDian(const double Mcenter[3], const double MTaon[3],
                     double Mradial, const double Pin1[3], const double Pin2[3],
                     double Cross_point_data[], int Cross_point_size[2])
{
  creal_T eiga_data[2];
  creal_T t_vals_data[2];
  double a_data[4];
  double B_tmp_tmp[3];
  double ctmp[3];
  double a_tmp;
  double b_c;
  double c;
  double c_c;
  double c_tmp;
  double d;
  double d1;
  double dP_idx_0;
  double dP_idx_1;
  int a_size[2];
  int companDim;
  int j;
  int k1;
  int k2;
  int loop_ub;
  int nTrailingZeros;
  signed char tmp_data[2];
  boolean_T exitg1;
  boolean_T exitg2;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  计算向量差 */
  /*  计算系数 A, B, C */
  d = Pin2[0] - Pin1[0];
  dP_idx_0 = d;
  a_tmp = d * MTaon[0];
  c = d * d;
  d1 = Pin1[0] - Mcenter[0];
  b_c = d * d1;
  c_tmp = d1 * MTaon[0];
  c_c = d1 * d1;
  d = Pin2[1] - Pin1[1];
  dP_idx_1 = d;
  a_tmp += d * MTaon[1];
  c += d * d;
  d1 = Pin1[1] - Mcenter[1];
  b_c += d * d1;
  c_tmp += d1 * MTaon[1];
  c_c += d1 * d1;
  d = Pin2[2] - Pin1[2];
  a_tmp += d * MTaon[2];
  c += d * d;
  d1 = Pin1[2] - Mcenter[2];
  b_c += d * d1;
  c_tmp += d1 * MTaon[2];
  c_c += d1 * d1;
  /*  解二次方程 At^2 + Bt + C = 0 */
  B_tmp_tmp[0] = c - a_tmp * a_tmp;
  B_tmp_tmp[1] = 2.0 * (b_c - a_tmp * c_tmp);
  B_tmp_tmp[2] = (c_c - c_tmp * c_tmp) - Mradial * Mradial;
  t_vals_data[0].re = 0.0;
  t_vals_data[0].im = 0.0;
  t_vals_data[1].re = 0.0;
  t_vals_data[1].im = 0.0;
  k1 = 1;
  while ((k1 <= 3) && (!(B_tmp_tmp[k1 - 1] != 0.0))) {
    k1++;
  }
  k2 = 3;
  while ((k2 >= k1) && (!(B_tmp_tmp[k2 - 1] != 0.0))) {
    k2--;
  }
  nTrailingZeros = 2 - k2;
  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        ctmp[j] = B_tmp_tmp[k1 + j] / B_tmp_tmp[k1 - 1];
        if (rtIsInf(fabs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }
      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }
    if (companDim < 1) {
      k1 = 3 - k2;
    } else {
      a_size[0] = companDim;
      a_size[1] = companDim;
      loop_ub = companDim * companDim;
      memset(&a_data[0], 0, (unsigned int)loop_ub * sizeof(double));
      if (companDim - 2 >= 0) {
        a_data[0] = -ctmp[0];
        a_data[1] = 1.0;
      }
      a_data[companDim * (companDim - 1)] = -ctmp[companDim - 1];
      if (nTrailingZeros >= 0) {
        memset(&t_vals_data[0], 0,
               (unsigned int)(nTrailingZeros + 1) * sizeof(creal_T));
      }
      if (companDim == 1) {
        for (k1 = 0; k1 < companDim; k1++) {
          eiga_data[k1].re = a_data[k1];
          eiga_data[k1].im = 0.0;
        }
      } else {
        xgeev(a_data, a_size, eiga_data, &j);
      }
      for (k1 = 0; k1 < companDim; k1++) {
        t_vals_data[(k1 - k2) + 3] = eiga_data[k1];
      }
      k1 = (companDim - k2) + 3;
    }
  } else {
    k1 = 3 - k2;
  }
  /*  判断是否有实数解 */
  k1--;
  nTrailingZeros = 0;
  j = 0;
  for (loop_ub = 0; loop_ub <= k1; loop_ub++) {
    if (t_vals_data[loop_ub].im == 0.0) {
      nTrailingZeros++;
      tmp_data[j] = (signed char)loop_ub;
      j++;
    }
  }
  Cross_point_size[0] = nTrailingZeros;
  Cross_point_size[1] = 3;
  loop_ub = nTrailingZeros * 3;
  if (loop_ub - 1 >= 0) {
    memset(&Cross_point_data[0], 0, (unsigned int)loop_ub * sizeof(double));
  }
  if (nTrailingZeros != 0) {
    /*  计算交点 */
    for (loop_ub = 0; loop_ub < nTrailingZeros; loop_ub++) {
      a_tmp = t_vals_data[tmp_data[loop_ub]].re;
      Cross_point_data[loop_ub] = Pin1[0] + a_tmp * dP_idx_0;
      Cross_point_data[loop_ub + nTrailingZeros] = Pin1[1] + a_tmp * dP_idx_1;
      Cross_point_data[loop_ub + nTrailingZeros * 2] = Pin1[2] + a_tmp * d;
      /*              disp(['Intersection Point ', num2str(i), ':']); */
      /*              disp(intersection_point); */
    }
  }
}

/*
 * File trailer for YuanZhuJiaoDian.c
 *
 * [EOF]
 */
