/*
 * File: YuanXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 09-Oct-2024 15:40:33
 */

/* Include Files */
#include "YuanXingFuCe.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "YuanZhuJiaoDian.h"
#include "combineVectorElements.h"
#include "nchoosek.h"
#include "norm.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Definitions */
/*
 * 距离计算
 *
 * Arguments    : const emxArray_real_T *PointIn
 *                double shenglunum
 *                const double Mcenter[3]
 *                const double MTaon[3]
 *                double Mradial
 *                double phi
 *                emxArray_real_T *Distance
 *                emxArray_real_T *theta
 *                emxArray_real_T *LTPY
 *                emxArray_real_T *TiC
 *                emxArray_real_T *Wquanzhong1
 *                emxArray_real_T *Wquanzhong2
 * Return Type  : void
 */
void YuanXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                  const double Mcenter[3], const double MTaon[3],
                  double Mradial, double phi, emxArray_real_T *Distance,
                  emxArray_real_T *theta, emxArray_real_T *LTPY,
                  emxArray_real_T *TiC, emxArray_real_T *Wquanzhong1,
                  emxArray_real_T *Wquanzhong2)
{
  static const double dv[5] = {1.570796, 0.392699, 0.19635, 0.122718, 0.085903};
  static const double dv1[5] = {1.513365, 0.360325, 0.174351, 0.106311,
                                0.072959};
  emxArray_real_T *TiYiCe;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *t_k;
  double Cross_point_data[6];
  double b_shengdao1[3];
  double shengdao1[3];
  double shengdao2[3];
  const double *PointIn_data;
  double K;
  double LT2_tmp;
  double a_tmp;
  double absxk;
  double b_a_tmp;
  double c_a_tmp;
  double scale;
  double shengdao1_tmp;
  double t;
  double y;
  double *Distance_data;
  double *TiC_data;
  double *Wquanzhong2_data;
  double *t_k_data;
  int Cross_point_size[2];
  int absxk_tmp;
  int b_absxk_tmp;
  int b_i;
  int b_loop_ub_tmp;
  unsigned int count_tk;
  int i;
  int loop_ub_tmp;
  (void)phi;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  PointIn_data = PointIn->data;
  i = Distance->size[0] * Distance->size[1];
  Distance->size[0] = 1;
  loop_ub_tmp = (int)shenglunum;
  Distance->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(Distance, i);
  Distance_data = Distance->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    shengdao1_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    absxk_tmp = 3 * ((int)(shengdao1_tmp - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)shengdao1_tmp - 1);
    absxk = fabs(PointIn_data[absxk_tmp] - PointIn_data[b_absxk_tmp]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(PointIn_data[absxk_tmp + 1] - PointIn_data[b_absxk_tmp + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(PointIn_data[absxk_tmp + 2] - PointIn_data[b_absxk_tmp + 2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    Distance_data[b_i] = scale * sqrt(y);
  }
  /*  计算声道角度 */
  /*  计算水平方向向量 */
  i = theta->size[0] * theta->size[1];
  theta->size[0] = 1;
  theta->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(theta, i);
  Distance_data = theta->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    shengdao1_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    i = 3 * ((int)shengdao1_tmp - 1);
    absxk_tmp = 3 * ((int)(shengdao1_tmp - 1.0) - 1);
    shengdao1_tmp = PointIn_data[i] - PointIn_data[absxk_tmp];
    K = MTaon[0] * shengdao1_tmp;
    absxk = fabs(shengdao1_tmp);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    shengdao1_tmp = PointIn_data[i + 1] - PointIn_data[absxk_tmp + 1];
    K += MTaon[1] * shengdao1_tmp;
    absxk = fabs(shengdao1_tmp);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    shengdao1_tmp = PointIn_data[i + 2] - PointIn_data[absxk_tmp + 2];
    K += MTaon[2] * shengdao1_tmp;
    absxk = fabs(shengdao1_tmp);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    Distance_data[b_i] = acos(K / (b_norm(MTaon) * y));
  }
  absxk_tmp = theta->size[1] - 1;
  for (b_i = 0; b_i <= absxk_tmp; b_i++) {
    shengdao1_tmp = Distance_data[b_i];
    if (shengdao1_tmp > 1.5707963267948966) {
      shengdao1_tmp = 3.1415926535897931 - shengdao1_tmp;
      Distance_data[b_i] = shengdao1_tmp;
    }
  }
  /*  rad2deg(theta) */
  /*  计算LT */
  i = LTPY->size[0] * LTPY->size[1];
  LTPY->size[0] = 1;
  LTPY->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(LTPY, i);
  Distance_data = LTPY->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    shengdao1_tmp = 2.0 * ((double)b_i + 1.0);
    b_absxk_tmp = 3 * ((int)(shengdao1_tmp - 1.0) - 1);
    shengdao1[0] = PointIn_data[b_absxk_tmp];
    absxk_tmp = 3 * ((int)shengdao1_tmp - 1);
    shengdao2[0] = PointIn_data[absxk_tmp];
    shengdao1[1] = PointIn_data[b_absxk_tmp + 1];
    shengdao2[1] = PointIn_data[absxk_tmp + 1];
    shengdao1[2] = PointIn_data[b_absxk_tmp + 2];
    shengdao2[2] = PointIn_data[absxk_tmp + 2];
    YuanZhuJiaoDian(Mcenter, MTaon, Mradial, shengdao1, shengdao2,
                    Cross_point_data, Cross_point_size);
    b_shengdao1[0] = shengdao1[0] - Cross_point_data[0];
    b_shengdao1[1] = shengdao1[1] - Cross_point_data[Cross_point_size[0]];
    K = Cross_point_data[Cross_point_size[0] * 2];
    b_shengdao1[2] = shengdao1[2] - K;
    LT2_tmp = b_norm(b_shengdao1);
    absxk = shengdao1[0] - Cross_point_data[1];
    b_shengdao1[0] = absxk;
    t = Cross_point_data[Cross_point_size[0] + 1];
    scale = shengdao1[1] - t;
    b_shengdao1[1] = scale;
    y = Cross_point_data[Cross_point_size[0] * 2 + 1];
    shengdao1_tmp = shengdao1[2] - y;
    b_shengdao1[2] = shengdao1_tmp;
    if (b_norm(b_shengdao1) < LT2_tmp) {
      b_shengdao1[0] = absxk;
      shengdao1[0] = shengdao2[0] - Cross_point_data[0];
      b_shengdao1[1] = scale;
      shengdao1[1] = shengdao2[1] - Cross_point_data[Cross_point_size[0]];
      b_shengdao1[2] = shengdao1_tmp;
      shengdao1[2] = shengdao2[2] - K;
      t = b_norm(b_shengdao1);
      shengdao1_tmp = b_norm(shengdao1);
      if ((t > shengdao1_tmp) || (rtIsNaN(t) && (!rtIsNaN(shengdao1_tmp)))) {
        t = shengdao1_tmp;
      }
    } else {
      shengdao1[0] = shengdao2[0] - Cross_point_data[1];
      shengdao1[1] = shengdao2[1] - t;
      shengdao1[2] = shengdao2[2] - y;
      t = b_norm(shengdao1);
      if ((t > LT2_tmp) || (rtIsNaN(t) && (!rtIsNaN(LT2_tmp)))) {
        t = LT2_tmp;
      }
    }
    Distance_data[b_i] = t * 2.0;
  }
  /*  相对高度计算 */
  i = TiC->size[0] * TiC->size[1];
  TiC->size[0] = 1;
  TiC->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(TiC, i);
  TiC_data = TiC->data;
  if (loop_ub_tmp - 1 >= 0) {
    a_tmp = (Mcenter[0] + MTaon[0]) - Mcenter[0];
    b_a_tmp = (Mcenter[1] + MTaon[1]) - Mcenter[1];
    c_a_tmp = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    shengdao1_tmp = 2.0 * ((double)b_i + 1.0);
    b_absxk_tmp = 3 * ((int)(shengdao1_tmp - 1.0) - 1);
    absxk_tmp = 3 * ((int)shengdao1_tmp - 1);
    shengdao1[0] = (PointIn_data[b_absxk_tmp] + PointIn_data[absxk_tmp]) / 2.0;
    shengdao1[1] =
        (PointIn_data[b_absxk_tmp + 1] + PointIn_data[absxk_tmp + 1]) / 2.0;
    shengdao1[2] =
        (PointIn_data[b_absxk_tmp + 2] + PointIn_data[absxk_tmp + 2]) / 2.0;
    /*  三个点定义 */
    /*  斜率计算 */
    K = -(((Mcenter[0] - shengdao1[0]) * a_tmp +
           (Mcenter[1] - shengdao1[1]) * b_a_tmp) +
          (Mcenter[2] - shengdao1[2]) * c_a_tmp) /
        ((a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp);
    /*  P1点在轴线上的投影坐标 */
    scale = 3.3121686421112381E-170;
    absxk = fabs(shengdao1[0] - (K * a_tmp + Mcenter[0]));
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(shengdao1[1] - (K * b_a_tmp + Mcenter[1]));
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(shengdao1[2] - (K * c_a_tmp + Mcenter[2]));
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    TiC_data[b_i] = y / Mradial;
  }
  /*  计算权重 1 */
  emxInit_real_T(&TiYiCe, 2);
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  Distance_data = TiYiCe->data;
  absxk_tmp = TiC->size[1];
  for (i = 0; i < absxk_tmp; i++) {
    Distance_data[i] = TiC_data[i];
  }
  shengdao1_tmp = floor(shenglunum / 2.0);
  if (shengdao1_tmp < 1.0) {
    b_absxk_tmp = 0;
  } else {
    b_absxk_tmp = (int)shengdao1_tmp;
  }
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = -TiC_data[i];
  }
  printf("%f,%f,%f,%f", Distance_data[0], Distance_data[1], Distance_data[2],
         Distance_data[3]);
  fflush(stdout);
  if (rtIsInf(shenglunum)) {
    t = rtNaN;
  } else if (shenglunum == 0.0) {
    t = 0.0;
  } else {
    t = fmod(shenglunum, 2.0);
  }
  if (t == 1.0) {
    /* 奇数 */
    Distance_data[(int)(unsigned int)shengdao1_tmp] = 0.0;
  }
  emxInit_real_T(&t_k, 1);
  b_loop_ub_tmp = (int)(shenglunum - 1.0);
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  t_k_data = t_k->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    t_k_data[i] = 0.0;
  }
  i = Wquanzhong2->size[0];
  Wquanzhong2->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(Wquanzhong2, i);
  Wquanzhong2_data = Wquanzhong2->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Wquanzhong2_data[i] = 0.0;
  }
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 1);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      Wquanzhong2_data[b_i] += dv[absxk_tmp] * -combineVectorElements(r1);
    }
    K = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        K *= Distance_data[b_i] - Distance_data[absxk_tmp];
      }
    }
    absxk = Distance_data[b_i];
    Wquanzhong2_data[b_i] /= sqrt(1.0 - absxk * absxk) * K;
  }
  i = Wquanzhong1->size[0];
  Wquanzhong1->size[0] = Wquanzhong2->size[0];
  emxEnsureCapacity_real_T(Wquanzhong1, i);
  Distance_data = Wquanzhong1->data;
  absxk_tmp = Wquanzhong2->size[0];
  for (i = 0; i < absxk_tmp; i++) {
    Distance_data[i] = Wquanzhong2_data[i];
  }
  /*  计算权重 2 */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  Distance_data = TiYiCe->data;
  absxk_tmp = TiC->size[1];
  for (i = 0; i < absxk_tmp; i++) {
    Distance_data[i] = TiC_data[i];
  }
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = -TiC_data[i];
  }
  if (t == 1.0) {
    /* 奇数 */
    Distance_data[(int)(unsigned int)shengdao1_tmp] = 0.0;
  }
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  t_k_data = t_k->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    t_k_data[i] = 0.0;
  }
  i = Wquanzhong2->size[0];
  Wquanzhong2->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(Wquanzhong2, i);
  Wquanzhong2_data = Wquanzhong2->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Wquanzhong2_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      Wquanzhong2_data[b_i] += dv1[absxk_tmp] * -combineVectorElements(r1);
    }
    K = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        K *= Distance_data[b_i] - Distance_data[absxk_tmp];
      }
    }
    shengdao1_tmp = Distance_data[b_i];
    Wquanzhong2_data[b_i] /=
        rt_powd_snf(1.0 - shengdao1_tmp * shengdao1_tmp, 0.6) * K;
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&t_k);
  emxFree_real_T(&TiYiCe);
}

/*
 * File trailer for YuanXingFuCe.c
 *
 * [EOF]
 */
