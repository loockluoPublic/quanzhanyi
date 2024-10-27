/*
 * File: YuanXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:51:24
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
#include "prod.h"
#include "rt_nonfinite.h"
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
  static const double b_dv[5] = {1.570796, 0.392699, 0.19635, 0.122718,
                                 0.085903};
  static const double b_dv1[5] = {1.513365, 0.360325, 0.174351, 0.106311,
                                  0.072959};
  emxArray_real_T *TiYiCe;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *t_k;
  double Cross_point_data[6];
  double shengdao1[3];
  double shengdao2[3];
  const double *PointIn_data;
  double K;
  double LThalf;
  double a_tmp;
  double absxk;
  double absxk_tmp;
  double absxk_tmp_tmp;
  double b_a_tmp;
  double b_scale;
  double b_y;
  double c_a_tmp;
  double d_absxk_tmp;
  double e_absxk_tmp;
  double mul;
  double scale;
  double t;
  double y;
  double *Distance_data;
  double *TiC_data;
  double *Wquanzhong2_data;
  double *t_k_data;
  int Cross_point_size[2];
  int b_absxk_tmp;
  int b_i;
  int c_absxk_tmp;
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
    absxk_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_absxk_tmp = 3 * ((int)(absxk_tmp - 1.0) - 1);
    c_absxk_tmp = 3 * ((int)absxk_tmp - 1);
    absxk = fabs(PointIn_data[b_absxk_tmp] - PointIn_data[c_absxk_tmp]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(PointIn_data[b_absxk_tmp + 1] - PointIn_data[c_absxk_tmp + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(PointIn_data[b_absxk_tmp + 2] - PointIn_data[c_absxk_tmp + 2]);
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
    absxk_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    i = 3 * ((int)absxk_tmp - 1);
    b_absxk_tmp = 3 * ((int)(absxk_tmp - 1.0) - 1);
    absxk_tmp = PointIn_data[i] - PointIn_data[b_absxk_tmp];
    mul = MTaon[0] * absxk_tmp;
    absxk = fabs(MTaon[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(absxk_tmp);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk_tmp = PointIn_data[i + 1] - PointIn_data[b_absxk_tmp + 1];
    mul += MTaon[1] * absxk_tmp;
    absxk = fabs(MTaon[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(absxk_tmp);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y = b_y * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y += t * t;
    }
    absxk_tmp = PointIn_data[i + 2] - PointIn_data[b_absxk_tmp + 2];
    mul += MTaon[2] * absxk_tmp;
    absxk = fabs(MTaon[2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(absxk_tmp);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y = b_y * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y += t * t;
    }
    y = scale * sqrt(y);
    b_y = b_scale * sqrt(b_y);
    Distance_data[b_i] = acos(mul / (y * b_y));
  }
  b_absxk_tmp = theta->size[1] - 1;
  for (b_i = 0; b_i <= b_absxk_tmp; b_i++) {
    absxk_tmp = Distance_data[b_i];
    if (absxk_tmp > 1.5707963267948966) {
      absxk_tmp = 3.1415926535897931 - absxk_tmp;
      Distance_data[b_i] = absxk_tmp;
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
    absxk_tmp = 2.0 * ((double)b_i + 1.0);
    c_absxk_tmp = 3 * ((int)(absxk_tmp - 1.0) - 1);
    shengdao1[0] = PointIn_data[c_absxk_tmp];
    b_absxk_tmp = 3 * ((int)absxk_tmp - 1);
    shengdao2[0] = PointIn_data[b_absxk_tmp];
    shengdao1[1] = PointIn_data[c_absxk_tmp + 1];
    shengdao2[1] = PointIn_data[b_absxk_tmp + 1];
    shengdao1[2] = PointIn_data[c_absxk_tmp + 2];
    shengdao2[2] = PointIn_data[b_absxk_tmp + 2];
    YuanZhuJiaoDian(Mcenter, MTaon, Mradial, shengdao1, shengdao2,
                    Cross_point_data, Cross_point_size);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    absxk = fabs(shengdao1[0] - Cross_point_data[0]);
    if (absxk > 3.3121686421112381E-170) {
      mul = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      mul = t * t;
    }
    K = fabs(shengdao1[0] - Cross_point_data[1]);
    if (K > 3.3121686421112381E-170) {
      y = 1.0;
      b_scale = K;
    } else {
      t = K / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(shengdao1[1] - Cross_point_data[Cross_point_size[0]]);
    if (absxk > scale) {
      t = scale / absxk;
      mul = mul * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      mul += t * t;
    }
    b_y = Cross_point_data[Cross_point_size[0] + 1];
    absxk_tmp = fabs(shengdao1[1] - b_y);
    if (absxk_tmp > b_scale) {
      t = b_scale / absxk_tmp;
      y = y * t * t + 1.0;
      b_scale = absxk_tmp;
    } else {
      t = absxk_tmp / b_scale;
      y += t * t;
    }
    d_absxk_tmp = Cross_point_data[Cross_point_size[0] * 2];
    absxk = fabs(shengdao1[2] - d_absxk_tmp);
    if (absxk > scale) {
      t = scale / absxk;
      mul = mul * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      mul += t * t;
    }
    absxk_tmp_tmp = Cross_point_data[Cross_point_size[0] * 2 + 1];
    e_absxk_tmp = fabs(shengdao1[2] - absxk_tmp_tmp);
    if (e_absxk_tmp > b_scale) {
      t = b_scale / e_absxk_tmp;
      y = y * t * t + 1.0;
      b_scale = e_absxk_tmp;
    } else {
      t = e_absxk_tmp / b_scale;
      y += t * t;
    }
    mul = scale * sqrt(mul);
    y = b_scale * sqrt(y);
    if (y < mul) {
      scale = 3.3121686421112381E-170;
      b_scale = 3.3121686421112381E-170;
      if (K > 3.3121686421112381E-170) {
        LThalf = 1.0;
        scale = K;
      } else {
        t = K / 3.3121686421112381E-170;
        LThalf = t * t;
      }
      absxk = fabs(shengdao2[0] - Cross_point_data[0]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        b_scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      if (absxk_tmp > scale) {
        t = scale / absxk_tmp;
        LThalf = LThalf * t * t + 1.0;
        scale = absxk_tmp;
      } else {
        t = absxk_tmp / scale;
        LThalf += t * t;
      }
      absxk = fabs(shengdao2[1] - Cross_point_data[Cross_point_size[0]]);
      if (absxk > b_scale) {
        t = b_scale / absxk;
        y = y * t * t + 1.0;
        b_scale = absxk;
      } else {
        t = absxk / b_scale;
        y += t * t;
      }
      if (e_absxk_tmp > scale) {
        t = scale / e_absxk_tmp;
        LThalf = LThalf * t * t + 1.0;
        scale = e_absxk_tmp;
      } else {
        t = e_absxk_tmp / scale;
        LThalf += t * t;
      }
      absxk = fabs(shengdao2[2] - d_absxk_tmp);
      if (absxk > b_scale) {
        t = b_scale / absxk;
        y = y * t * t + 1.0;
        b_scale = absxk;
      } else {
        t = absxk / b_scale;
        y += t * t;
      }
      LThalf = scale * sqrt(LThalf);
      y = b_scale * sqrt(y);
      if ((LThalf > y) || (rtIsNaN(LThalf) && (!rtIsNaN(y)))) {
        LThalf = y;
      }
    } else {
      scale = 3.3121686421112381E-170;
      absxk = fabs(shengdao2[0] - Cross_point_data[1]);
      if (absxk > 3.3121686421112381E-170) {
        LThalf = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        LThalf = t * t;
      }
      absxk = fabs(shengdao2[1] - b_y);
      if (absxk > scale) {
        t = scale / absxk;
        LThalf = LThalf * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        LThalf += t * t;
      }
      absxk = fabs(shengdao2[2] - absxk_tmp_tmp);
      if (absxk > scale) {
        t = scale / absxk;
        LThalf = LThalf * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        LThalf += t * t;
      }
      LThalf = scale * sqrt(LThalf);
      if ((LThalf > mul) || (rtIsNaN(LThalf) && (!rtIsNaN(mul)))) {
        LThalf = mul;
      }
    }
    Distance_data[b_i] = LThalf * 2.0;
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
    absxk_tmp = 2.0 * ((double)b_i + 1.0);
    c_absxk_tmp = 3 * ((int)(absxk_tmp - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)absxk_tmp - 1);
    shengdao1[0] =
        (PointIn_data[c_absxk_tmp] + PointIn_data[b_absxk_tmp]) / 2.0;
    shengdao1[1] =
        (PointIn_data[c_absxk_tmp + 1] + PointIn_data[b_absxk_tmp + 1]) / 2.0;
    shengdao1[2] =
        (PointIn_data[c_absxk_tmp + 2] + PointIn_data[b_absxk_tmp + 2]) / 2.0;
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
  /*  alphaA = asin(TiC); */
  absxk_tmp = floor(shenglunum / 2.0);
  if (absxk_tmp < 1.0) {
    b_absxk_tmp = 0;
  } else {
    b_absxk_tmp = (int)absxk_tmp;
  }
  emxInit_real_T(&TiYiCe, 2);
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = b_absxk_tmp;
  emxEnsureCapacity_real_T(TiYiCe, i);
  Distance_data = TiYiCe->data;
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = -TiC_data[i];
  }
  b_absxk_tmp = TiYiCe->size[1];
  for (i = 0; i < b_absxk_tmp; i++) {
    TiC_data[i] = Distance_data[i];
  }
  /*  计算权重 1 */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  Distance_data = TiYiCe->data;
  b_absxk_tmp = TiC->size[1];
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = TiC_data[i];
  }
  /*  fprintf('%f,%f,%f,%f',TiYiCe(1),TiYiCe(2),TiYiCe(3),TiYiCe(4)); */
  if (rtIsInf(shenglunum)) {
    K = rtNaN;
  } else if (shenglunum == 0.0) {
    K = 0.0;
  } else {
    K = fmod(shenglunum, 2.0);
  }
  if (K == 1.0) {
    /* 奇数 */
    Distance_data[(int)(unsigned int)absxk_tmp] = 0.0;
  }
  emxInit_real_T(&t_k, 1);
  c_absxk_tmp = (int)(shenglunum - 1.0);
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  t_k_data = t_k->data;
  for (i = 0; i < c_absxk_tmp; i++) {
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
    for (b_absxk_tmp = 0; b_absxk_tmp < loop_ub_tmp; b_absxk_tmp++) {
      if ((unsigned int)b_absxk_tmp != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[b_absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (b_absxk_tmp = 0; b_absxk_tmp < i; b_absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)b_absxk_tmp + 1.0),
                 r);
      prod(r, r1);
      Wquanzhong2_data[b_i] += b_dv[b_absxk_tmp] * -combineVectorElements(r1);
    }
    mul = 1.0;
    for (b_absxk_tmp = 0; b_absxk_tmp < loop_ub_tmp; b_absxk_tmp++) {
      if ((unsigned int)b_absxk_tmp != (unsigned int)b_i) {
        mul *= Distance_data[b_i] - Distance_data[b_absxk_tmp];
      }
    }
    b_y = Distance_data[b_i];
    Wquanzhong2_data[b_i] /= sqrt(1.0 - b_y * b_y) * mul;
  }
  i = Wquanzhong1->size[0];
  Wquanzhong1->size[0] = Wquanzhong2->size[0];
  emxEnsureCapacity_real_T(Wquanzhong1, i);
  Distance_data = Wquanzhong1->data;
  b_absxk_tmp = Wquanzhong2->size[0];
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = Wquanzhong2_data[i];
  }
  /*  计算权重 2 */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  Distance_data = TiYiCe->data;
  b_absxk_tmp = TiC->size[1];
  for (i = 0; i < b_absxk_tmp; i++) {
    Distance_data[i] = TiC_data[i];
  }
  if (K == 1.0) {
    /* 奇数 */
    Distance_data[(int)(unsigned int)absxk_tmp] = 0.0;
  }
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  t_k_data = t_k->data;
  for (i = 0; i < c_absxk_tmp; i++) {
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
    for (b_absxk_tmp = 0; b_absxk_tmp < loop_ub_tmp; b_absxk_tmp++) {
      if ((unsigned int)b_absxk_tmp != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = Distance_data[b_absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (b_absxk_tmp = 0; b_absxk_tmp < i; b_absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)b_absxk_tmp + 1.0),
                 r);
      prod(r, r1);
      Wquanzhong2_data[b_i] += b_dv1[b_absxk_tmp] * -combineVectorElements(r1);
    }
    mul = 1.0;
    for (b_absxk_tmp = 0; b_absxk_tmp < loop_ub_tmp; b_absxk_tmp++) {
      if ((unsigned int)b_absxk_tmp != (unsigned int)b_i) {
        mul *= Distance_data[b_i] - Distance_data[b_absxk_tmp];
      }
    }
    absxk_tmp = Distance_data[b_i];
    Wquanzhong2_data[b_i] /=
        rt_powd_snf(1.0 - absxk_tmp * absxk_tmp, 0.6) * mul;
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
