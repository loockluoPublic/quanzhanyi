/*
 * File: YuanXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Dec-2024 23:43:24
 */

/* Include Files */
#include "YuanXingFuCe.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "combineVectorElements.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
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
  double b_Mcenter[3];
  double shengdao1[3];
  const double *PointIn_data;
  double absxk;
  double b_scale;
  double b_y;
  double d;
  double mul;
  double scale;
  double t;
  double y;
  double *Distance_data;
  double *LTPY_data;
  double *TiC_data;
  double *TiYiCe_data;
  double *theta_data;
  int absxk_tmp;
  int b_absxk_tmp;
  int b_i;
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
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    absxk_tmp = 3 * ((int)(d - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)d - 1);
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
  theta_data = theta->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    i = 3 * ((int)d - 1);
    absxk_tmp = 3 * ((int)(d - 1.0) - 1);
    d = PointIn_data[i] - PointIn_data[absxk_tmp];
    mul = MTaon[0] * d;
    absxk = fabs(MTaon[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    d = PointIn_data[i + 1] - PointIn_data[absxk_tmp + 1];
    mul += MTaon[1] * d;
    absxk = fabs(MTaon[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(d);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y = b_y * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y += t * t;
    }
    d = PointIn_data[i + 2] - PointIn_data[absxk_tmp + 2];
    mul += MTaon[2] * d;
    absxk = fabs(MTaon[2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(d);
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
    theta_data[b_i] = acos(mul / (y * b_y));
  }
  absxk_tmp = theta->size[1] - 1;
  for (b_i = 0; b_i <= absxk_tmp; b_i++) {
    d = theta_data[b_i];
    if (d > 1.5707963267948966) {
      d = 3.1415926535897931 - d;
      theta_data[b_i] = d;
    }
  }
  /*  rad2deg(theta) */
  /*  相对高度计算 */
  i = TiC->size[0] * TiC->size[1];
  TiC->size[0] = 1;
  TiC->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(TiC, i);
  TiC_data = TiC->data;
  if (loop_ub_tmp - 1 >= 0) {
    b_Mcenter[0] = Mcenter[0] + MTaon[0];
    b_Mcenter[1] = Mcenter[1] + MTaon[1];
    b_Mcenter[2] = Mcenter[2] + MTaon[2];
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    absxk_tmp = 3 * ((int)(d - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)d - 1);
    shengdao1[0] = (PointIn_data[absxk_tmp] + PointIn_data[b_absxk_tmp]) / 2.0;
    shengdao1[1] =
        (PointIn_data[absxk_tmp + 1] + PointIn_data[b_absxk_tmp + 1]) / 2.0;
    shengdao1[2] =
        (PointIn_data[absxk_tmp + 2] + PointIn_data[b_absxk_tmp + 2]) / 2.0;
    foot_of_perpendicular_from_a_point_to_a_line(shengdao1, Mcenter, b_Mcenter,
                                                 &b_scale, &mul, &b_y);
    scale = 3.3121686421112381E-170;
    absxk = fabs(shengdao1[0] - b_scale);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(shengdao1[1] - mul);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(shengdao1[2] - b_y);
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
  d = floor(shenglunum / 2.0);
  if (d < 1.0) {
    absxk_tmp = 0;
  } else {
    absxk_tmp = (int)d;
  }
  emxInit_real_T(&TiYiCe, 2);
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = absxk_tmp;
  emxEnsureCapacity_real_T(TiYiCe, i);
  TiYiCe_data = TiYiCe->data;
  for (i = 0; i < absxk_tmp; i++) {
    TiYiCe_data[i] = -TiC_data[i];
  }
  absxk_tmp = TiYiCe->size[1];
  for (i = 0; i < absxk_tmp; i++) {
    TiC_data[i] = TiYiCe_data[i];
  }
  /*  计算LT */
  /*  % % LTPY = zeros(1,shenglunum); */
  /*  % % for i = 1:shenglunum */
  /*  % %     shengdao1 = PointIn(:,2*i-1); */
  /*  % %     shengdao2 = PointIn(:,2*i); */
  /*  % %     Cross_point =
   * YuanZhuJiaoDian(Mcenter,MTaon,Mradial,shengdao1',shengdao2'); */
  /*  % %  */
  /*  % %     LT1 = norm(shengdao1'-Cross_point(2,:)); */
  /*  % %     LT2 = norm(shengdao1'-Cross_point(1,:)); */
  /*  % %  */
  /*  % %     if LT1<LT2 */
  /*  % %         LTF = norm(shengdao1'-Cross_point(2,:)); */
  /*  % %         LTR = norm(shengdao2'-Cross_point(1,:)); */
  /*  % %         LThalf = min([LTF,LTR]); */
  /*  % %     else */
  /*  % %         LTF = norm(shengdao2'-Cross_point(2,:)); */
  /*  % %         LTR = norm(shengdao1'-Cross_point(1,:)); */
  /*  % %         LThalf = min([LTF,LTR]); */
  /*  % %     end */
  /*  % %     LTPY(i) = LThalf.*2; */
  /*  % %  */
  /*  % % end */
  i = LTPY->size[0] * LTPY->size[1];
  LTPY->size[0] = 1;
  LTPY->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(LTPY, i);
  LTPY_data = LTPY->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    LTPY_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    b_scale = TiC_data[b_i];
    LTPY_data[b_i] = (Distance_data[b_i] - 2.0 * sqrt(1.0 - b_scale * b_scale) *
                                               Mradial / sin(theta_data[b_i])) /
                     2.0;
  }
  /*  计算权重 1 */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  TiYiCe_data = TiYiCe->data;
  absxk_tmp = TiC->size[1];
  for (i = 0; i < absxk_tmp; i++) {
    TiYiCe_data[i] = TiC_data[i];
  }
  /*  fprintf('%f,%f,%f,%f',TiYiCe(1),TiYiCe(2),TiYiCe(3),TiYiCe(4)); */
  if (rtIsInf(shenglunum)) {
    b_scale = rtNaN;
  } else if (shenglunum == 0.0) {
    b_scale = 0.0;
  } else {
    b_scale = fmod(shenglunum, 2.0);
  }
  if (b_scale == 1.0) {
    /* 奇数 */
    TiYiCe_data[(int)(unsigned int)d] = 0.0;
  }
  emxInit_real_T(&t_k, 1);
  b_absxk_tmp = (int)(shenglunum - 1.0);
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  LTPY_data = t_k->data;
  for (i = 0; i < b_absxk_tmp; i++) {
    LTPY_data[i] = 0.0;
  }
  i = Wquanzhong2->size[0];
  Wquanzhong2->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(Wquanzhong2, i);
  Distance_data = Wquanzhong2->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Distance_data[i] = 0.0;
  }
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 1);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        LTPY_data[(int)count_tk - 1] = TiYiCe_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      Distance_data[b_i] += b_dv[absxk_tmp] * -combineVectorElements(r1);
    }
    mul = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        mul *= TiYiCe_data[b_i] - TiYiCe_data[absxk_tmp];
      }
    }
    b_y = TiYiCe_data[b_i];
    Distance_data[b_i] /= sqrt(1.0 - b_y * b_y) * mul;
  }
  i = Wquanzhong1->size[0];
  Wquanzhong1->size[0] = Wquanzhong2->size[0];
  emxEnsureCapacity_real_T(Wquanzhong1, i);
  LTPY_data = Wquanzhong1->data;
  absxk_tmp = Wquanzhong2->size[0];
  for (i = 0; i < absxk_tmp; i++) {
    LTPY_data[i] = Distance_data[i];
  }
  /*  计算权重 2 */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  TiYiCe_data = TiYiCe->data;
  absxk_tmp = TiC->size[1];
  for (i = 0; i < absxk_tmp; i++) {
    TiYiCe_data[i] = TiC_data[i];
  }
  if (b_scale == 1.0) {
    /* 奇数 */
    TiYiCe_data[(int)(unsigned int)d] = 0.0;
  }
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  LTPY_data = t_k->data;
  for (i = 0; i < b_absxk_tmp; i++) {
    LTPY_data[i] = 0.0;
  }
  i = Wquanzhong2->size[0];
  Wquanzhong2->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(Wquanzhong2, i);
  Distance_data = Wquanzhong2->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Distance_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        LTPY_data[(int)count_tk - 1] = TiYiCe_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      Distance_data[b_i] += b_dv1[absxk_tmp] * -combineVectorElements(r1);
    }
    mul = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        mul *= TiYiCe_data[b_i] - TiYiCe_data[absxk_tmp];
      }
    }
    d = TiYiCe_data[b_i];
    Distance_data[b_i] /= rt_powd_snf(1.0 - d * d, 0.6) * mul;
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
