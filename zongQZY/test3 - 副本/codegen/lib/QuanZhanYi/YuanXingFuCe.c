/*
 * File: YuanXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 29-Sep-2024 01:27:40
 */

/* Include Files */
#include "YuanXingFuCe.h"
#include "JuXingFuCe.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "YuanZhuJiaoDian.h"
#include "combineVectorElements.h"
#include "mod.h"
#include "nchoosek.h"
#include "norm.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include <math.h>

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
  emxArray_real_T *alphaA;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *t_k;
  emxArray_real_T *w;
  double Cross_point_data[6];
  double E[3];
  double QiShi[3];
  double shengdao1[3];
  double shengdao2[3];
  const double *PointIn_data;
  double K;
  double a;
  double a_tmp;
  double absxk;
  double b_a;
  double b_a_tmp;
  double c_a;
  double c_a_tmp;
  double d;
  double dirP_data_idx_0;
  double dirP_data_idx_1;
  double scale;
  double t;
  double y;
  double *Distance_data;
  double *TiC_data;
  double *t_k_data;
  double *theta_data;
  int Cross_point_size[2];
  int b_i;
  int b_loop_ub_tmp;
  unsigned int count_tk;
  int i;
  int idx;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int na;
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
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    idx = 3 * ((int)(d - 1.0) - 1);
    na = 3 * ((int)d - 1);
    absxk = fabs(PointIn_data[idx] - PointIn_data[na]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(PointIn_data[idx + 1] - PointIn_data[na + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(PointIn_data[idx + 2] - PointIn_data[na + 2]);
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
  theta_data = theta->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    i = 3 * ((int)d - 1);
    k = 3 * ((int)(d - 1.0) - 1);
    d = PointIn_data[i] - PointIn_data[k];
    K = MTaon[0] * d;
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    d = PointIn_data[i + 1] - PointIn_data[k + 1];
    K += MTaon[1] * d;
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    d = PointIn_data[i + 2] - PointIn_data[k + 2];
    K += MTaon[2] * d;
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    theta_data[b_i] = acos(K / (b_norm(MTaon) * y));
  }
  /*  rad2deg(theta) */
  /*  计算LT */
  i = LTPY->size[0] * LTPY->size[1];
  LTPY->size[0] = 1;
  LTPY->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(LTPY, i);
  theta_data = LTPY->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    idx = 3 * ((int)(d - 1.0) - 1);
    shengdao1[0] = PointIn_data[idx];
    na = 3 * ((int)d - 1);
    shengdao2[0] = PointIn_data[na];
    shengdao1[1] = PointIn_data[idx + 1];
    shengdao2[1] = PointIn_data[na + 1];
    shengdao1[2] = PointIn_data[idx + 2];
    shengdao2[2] = PointIn_data[na + 2];
    YuanZhuJiaoDian(Mcenter, MTaon, Mradial, shengdao1, shengdao2,
                    Cross_point_data, Cross_point_size);
    QiShi[0] = Cross_point_data[0] - Cross_point_data[1];
    QiShi[1] = Cross_point_data[Cross_point_size[0]] -
               Cross_point_data[Cross_point_size[0] + 1];
    QiShi[2] = Cross_point_data[Cross_point_size[0] * 2] -
               Cross_point_data[Cross_point_size[0] * 2 + 1];
    theta_data[b_i] = b_norm(QiShi);
  }
  if (Distance->size[1] == LTPY->size[1]) {
    loop_ub = Distance->size[1] - 1;
    i = LTPY->size[0] * LTPY->size[1];
    LTPY->size[0] = 1;
    LTPY->size[1] = Distance->size[1];
    emxEnsureCapacity_real_T(LTPY, i);
    theta_data = LTPY->data;
    for (i = 0; i <= loop_ub; i++) {
      theta_data[i] = Distance_data[i] - theta_data[i];
    }
  } else {
    b_minus(LTPY, Distance);
  }
  /*  相对高度计算 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%水平方向计算%%%%%%%%%%%%%%%%%% */
  /*  起始点 */
  shengdao1[0] = 0.0 * MTaon[2] - MTaon[1];
  shengdao1[1] = MTaon[0] - 0.0 * MTaon[2];
  shengdao1[2] = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  d = b_norm(shengdao1);
  dirP_data_idx_0 = tan(phi);
  absxk = shengdao1[0] / d;
  shengdao1[0] = absxk;
  shengdao2[0] = MTaon[0] + dirP_data_idx_0 * absxk;
  absxk = shengdao1[1] / d;
  shengdao1[1] = absxk;
  shengdao2[1] = MTaon[1] + dirP_data_idx_0 * absxk;
  absxk = shengdao1[2] / d;
  shengdao2[2] = MTaon[2] + dirP_data_idx_0 * absxk;
  d = b_norm(shengdao2);
  shengdao2[0] /= d;
  shengdao2[1] /= d;
  shengdao2[2] /= d;
  QiShi[0] = MTaon[1] * absxk - shengdao1[1] * MTaon[2];
  QiShi[1] = shengdao1[0] * MTaon[2] - MTaon[0] * absxk;
  QiShi[2] = MTaon[0] * shengdao1[1] - shengdao1[0] * MTaon[1];
  E[0] = QiShi[1] * shengdao2[2] - shengdao2[1] * QiShi[2];
  E[1] = shengdao2[0] * QiShi[2] - QiShi[0] * shengdao2[2];
  E[2] = QiShi[0] * shengdao2[1] - shengdao2[0] * QiShi[1];
  d = b_norm(E);
  /*  圆心点 */
  E[0] /= d;
  E[1] /= d;
  E[2] /= d;
  /*  三个点定义 */
  /*  斜率计算 */
  a_tmp = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  b_a_tmp = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  c_a_tmp = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  dirP_data_idx_0 = (a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp;
  K = -(((Mcenter[0] - MTaon[0]) * a_tmp + (Mcenter[1] - MTaon[1]) * b_a_tmp) +
        (Mcenter[2] - MTaon[2]) * c_a_tmp) /
      dirP_data_idx_0;
  /*  P1点在轴线上的投影坐标 */
  /*  起始点 （测点半圆的中点） */
  shengdao1[0] = (K * a_tmp + Mcenter[0]) + E[0];
  shengdao1[1] = (K * b_a_tmp + Mcenter[1]) + E[1];
  shengdao1[2] = (K * c_a_tmp + Mcenter[2]) + E[2];
  QiShi[0] = shengdao1[1] * MTaon[2] - MTaon[1] * shengdao1[2];
  QiShi[1] = MTaon[0] * shengdao1[2] - shengdao1[0] * MTaon[2];
  QiShi[2] = shengdao1[0] * MTaon[1] - MTaon[0] * shengdao1[1];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Mcenter[0] - QiShi[0]) * a_tmp + (Mcenter[1] - QiShi[1]) * b_a_tmp) +
        (Mcenter[2] - QiShi[2]) * c_a_tmp) /
      dirP_data_idx_0;
  /*  P1点在轴线上的投影坐标 */
  shengdao2[0] = QiShi[0] - (K * a_tmp + Mcenter[0]);
  shengdao2[1] = QiShi[1] - (K * b_a_tmp + Mcenter[1]);
  shengdao2[2] = QiShi[2] - (K * c_a_tmp + Mcenter[2]);
  d = b_norm(shengdao2);
  shengdao2[0] /= d;
  shengdao2[1] /= d;
  shengdao2[2] /= d;
  emxInit_real_T(&alphaA, 2);
  i = alphaA->size[0] * alphaA->size[1];
  alphaA->size[0] = 1;
  loop_ub = (int)(2.0 * shenglunum);
  alphaA->size[1] = loop_ub;
  emxEnsureCapacity_real_T(alphaA, i);
  Distance_data = alphaA->data;
  for (i = 0; i < loop_ub; i++) {
    Distance_data[i] = 0.0;
  }
  if (loop_ub - 1 >= 0) {
    a = a_tmp;
    b_a = b_a_tmp;
    c_a = c_a_tmp;
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    /*  三个点定义 */
    /*  斜率计算 */
    idx = 3 * b_i + 1;
    na = 3 * b_i + 2;
    K = -(((Mcenter[0] - PointIn_data[3 * b_i]) * a_tmp +
           (Mcenter[1] - PointIn_data[idx]) * b_a_tmp) +
          (Mcenter[2] - PointIn_data[na]) * c_a_tmp) /
        ((a * a + b_a * b_a) + c_a * c_a);
    /*  P1点在轴线上的投影坐标 */
    scale = 3.3121686421112381E-170;
    d = PointIn_data[3 * b_i] - (K * a_tmp + Mcenter[0]);
    dirP_data_idx_0 = d;
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    d = PointIn_data[idx] - (K * b_a_tmp + Mcenter[1]);
    dirP_data_idx_1 = d;
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    d = PointIn_data[na] - (K * c_a_tmp + Mcenter[2]);
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    scale = 3.3121686421112381E-170;
    absxk = dirP_data_idx_0 / y;
    K = absxk * shengdao2[0];
    absxk = fabs(absxk);
    if (absxk > 3.3121686421112381E-170) {
      dirP_data_idx_0 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      dirP_data_idx_0 = t * t;
    }
    absxk = dirP_data_idx_1 / y;
    K += absxk * shengdao2[1];
    absxk = fabs(absxk);
    if (absxk > scale) {
      t = scale / absxk;
      dirP_data_idx_0 = dirP_data_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      dirP_data_idx_0 += t * t;
    }
    absxk = d / y;
    K += absxk * shengdao2[2];
    absxk = fabs(absxk);
    if (absxk > scale) {
      t = scale / absxk;
      dirP_data_idx_0 = dirP_data_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      dirP_data_idx_0 += t * t;
    }
    dirP_data_idx_0 = scale * sqrt(dirP_data_idx_0);
    Distance_data[b_i] = acos(K / (dirP_data_idx_0 * b_norm(shengdao2)));
  }
  i = TiC->size[0] * TiC->size[1];
  TiC->size[0] = 1;
  TiC->size[1] = alphaA->size[1];
  emxEnsureCapacity_real_T(TiC, i);
  TiC_data = TiC->data;
  loop_ub = alphaA->size[1];
  for (k = 0; k < loop_ub; k++) {
    TiC_data[k] = sin(Distance_data[k]);
  }
  d = b_mod(shenglunum);
  if (d == 1.0) {
    /* 奇数 */
    absxk = 2.0 * floor(shenglunum / 2.0);
    if (absxk < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)absxk;
    }
    i = alphaA->size[0] * alphaA->size[1];
    alphaA->size[0] = 1;
    alphaA->size[1] = loop_ub;
    emxEnsureCapacity_real_T(alphaA, i);
    Distance_data = alphaA->data;
    for (i = 0; i < loop_ub; i++) {
      Distance_data[i] = -TiC_data[i];
    }
    loop_ub = alphaA->size[1];
    for (i = 0; i < loop_ub; i++) {
      TiC_data[i] = Distance_data[i];
    }
  } else {
    /* 偶数 */
    absxk = 2.0 * (shenglunum / 2.0);
    if (absxk < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)absxk;
    }
    i = alphaA->size[0] * alphaA->size[1];
    alphaA->size[0] = 1;
    alphaA->size[1] = loop_ub;
    emxEnsureCapacity_real_T(alphaA, i);
    Distance_data = alphaA->data;
    for (i = 0; i < loop_ub; i++) {
      Distance_data[i] = -TiC_data[i];
    }
    loop_ub = alphaA->size[1];
    for (i = 0; i < loop_ub; i++) {
      TiC_data[i] = Distance_data[i];
    }
  }
  /*  计算权重 1 */
  absxk = 2.0 * shenglunum;
  if (absxk < 1.0) {
    i = 1;
    k = -1;
  } else {
    i = 2;
    k = (int)absxk - 1;
  }
  na = alphaA->size[0] * alphaA->size[1];
  alphaA->size[0] = 1;
  loop_ub = div_s32(k, i);
  alphaA->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(alphaA, na);
  Distance_data = alphaA->data;
  for (k = 0; k <= loop_ub; k++) {
    Distance_data[k] = TiC_data[i * k];
  }
  if (d == 1.0) {
    /* 奇数 */
    Distance_data[(int)(floor(shenglunum / 2.0) + 1.0) - 1] = 0.0;
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
  emxInit_real_T(&w, 1);
  i = w->size[0];
  w->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(w, i);
  theta_data = w->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    theta_data[i] = 0.0;
  }
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 1);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[idx];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (idx = 0; idx < i; idx++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)idx + 1.0), r);
      prod(r, r1);
      theta_data[b_i] += dv[idx] * -combineVectorElements(r1);
    }
    dirP_data_idx_0 = 1.0;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        dirP_data_idx_0 *= Distance_data[b_i] - Distance_data[idx];
      }
    }
    K = Distance_data[b_i];
    theta_data[b_i] /= sqrt(1.0 - K * K) * dirP_data_idx_0;
  }
  na = w->size[0];
  i = w->size[0] << 1;
  k = t_k->size[0];
  t_k->size[0] = i;
  emxEnsureCapacity_real_T(t_k, k);
  t_k_data = t_k->data;
  idx = -1;
  for (k = 0; k < na; k++) {
    t_k_data[idx + 1] = theta_data[k];
    t_k_data[idx + 2] = theta_data[k];
    idx += 2;
  }
  na = t_k->size[0];
  k = Wquanzhong1->size[0];
  Wquanzhong1->size[0] = t_k->size[0];
  emxEnsureCapacity_real_T(Wquanzhong1, k);
  theta_data = Wquanzhong1->data;
  for (k = 0; k < na; k++) {
    theta_data[k] = fabs(t_k_data[k]);
  }
  /*  计算权重 2 */
  if (absxk < 1.0) {
    k = 1;
    na = -1;
  } else {
    k = 2;
    na = (int)absxk - 1;
  }
  idx = alphaA->size[0] * alphaA->size[1];
  alphaA->size[0] = 1;
  loop_ub = div_s32(na, k);
  alphaA->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(alphaA, idx);
  Distance_data = alphaA->data;
  for (na = 0; na <= loop_ub; na++) {
    Distance_data[na] = TiC_data[k * na];
  }
  if (d == 1.0) {
    /* 奇数 */
    Distance_data[(int)(floor(shenglunum / 2.0) + 1.0) - 1] = 0.0;
  }
  k = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, k);
  t_k_data = t_k->data;
  for (k = 0; k < b_loop_ub_tmp; k++) {
    t_k_data[k] = 0.0;
  }
  k = w->size[0];
  w->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(w, k);
  theta_data = w->data;
  for (k = 0; k < loop_ub_tmp; k++) {
    theta_data[k] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[idx];
        count_tk++;
      }
    }
    k = (int)((shenglunum + 1.0) / 2.0);
    for (idx = 0; idx < k; idx++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)idx + 1.0), r);
      prod(r, r1);
      theta_data[b_i] += dv1[idx] * -combineVectorElements(r1);
    }
    dirP_data_idx_0 = 1.0;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        dirP_data_idx_0 *= Distance_data[b_i] - Distance_data[idx];
      }
    }
    d = Distance_data[b_i];
    theta_data[b_i] /= rt_powd_snf(1.0 - d * d, 0.6) * dirP_data_idx_0;
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&alphaA);
  na = w->size[0];
  k = t_k->size[0];
  t_k->size[0] = i;
  emxEnsureCapacity_real_T(t_k, k);
  t_k_data = t_k->data;
  idx = -1;
  for (k = 0; k < na; k++) {
    t_k_data[idx + 1] = theta_data[k];
    t_k_data[idx + 2] = theta_data[k];
    idx += 2;
  }
  emxFree_real_T(&w);
  na = t_k->size[0];
  i = Wquanzhong2->size[0];
  Wquanzhong2->size[0] = t_k->size[0];
  emxEnsureCapacity_real_T(Wquanzhong2, i);
  theta_data = Wquanzhong2->data;
  for (k = 0; k < na; k++) {
    theta_data[k] = fabs(t_k_data[k]);
  }
  emxFree_real_T(&t_k);
}

/*
 * File trailer for YuanXingFuCe.c
 *
 * [EOF]
 */
