/*
 * File: YuanXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Mar-2025 21:42:51
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
  double K;
  double P_projected1_idx_0;
  double P_projected1_idx_1;
  double P_projected1_idx_2;
  double a_tmp;
  double absxk;
  double b_scale;
  double c;
  double scale;
  double t;
  double t_tmp;
  double yN1;
  double zN1;
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
    a_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    absxk_tmp = 3 * ((int)(a_tmp - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)a_tmp - 1);
    absxk = fabs(PointIn_data[absxk_tmp] - PointIn_data[b_absxk_tmp]);
    if (absxk > 3.3121686421112381E-170) {
      P_projected1_idx_0 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      P_projected1_idx_0 = t * t;
    }
    absxk = fabs(PointIn_data[absxk_tmp + 1] - PointIn_data[b_absxk_tmp + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    absxk = fabs(PointIn_data[absxk_tmp + 2] - PointIn_data[b_absxk_tmp + 2]);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    Distance_data[b_i] = scale * sqrt(P_projected1_idx_0);
  }
  /*  计算声道角度 */
  /*  计算水平方向向量 */
  i = theta->size[0] * theta->size[1];
  theta->size[0] = 1;
  theta->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(theta, i);
  theta_data = theta->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    a_tmp = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    i = 3 * ((int)a_tmp - 1);
    absxk_tmp = 3 * ((int)(a_tmp - 1.0) - 1);
    a_tmp = PointIn_data[i] - PointIn_data[absxk_tmp];
    c = MTaon[0] * a_tmp;
    absxk = fabs(MTaon[0]);
    if (absxk > 3.3121686421112381E-170) {
      P_projected1_idx_0 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      P_projected1_idx_0 = t * t;
    }
    absxk = fabs(a_tmp);
    if (absxk > 3.3121686421112381E-170) {
      K = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      K = t * t;
    }
    a_tmp = PointIn_data[i + 1] - PointIn_data[absxk_tmp + 1];
    c += MTaon[1] * a_tmp;
    absxk = fabs(MTaon[1]);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    absxk = fabs(a_tmp);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      K = K * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      K += t * t;
    }
    a_tmp = PointIn_data[i + 2] - PointIn_data[absxk_tmp + 2];
    c += MTaon[2] * a_tmp;
    absxk = fabs(MTaon[2]);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    absxk = fabs(a_tmp);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      K = K * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      K += t * t;
    }
    P_projected1_idx_0 = scale * sqrt(P_projected1_idx_0);
    K = b_scale * sqrt(K);
    theta_data[b_i] = acos(c / (P_projected1_idx_0 * K));
  }
  absxk_tmp = theta->size[1] - 1;
  for (b_i = 0; b_i <= absxk_tmp; b_i++) {
    a_tmp = theta_data[b_i];
    if (a_tmp > 1.5707963267948966) {
      a_tmp = 3.1415926535897931 - a_tmp;
      theta_data[b_i] = a_tmp;
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
    t_tmp = (MTaon[0] * MTaon[0] + MTaon[1] * MTaon[1]) + MTaon[2] * MTaon[2];
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    a_tmp = 2.0 * ((double)b_i + 1.0);
    absxk_tmp = 3 * ((int)(a_tmp - 1.0) - 1);
    b_absxk_tmp = 3 * ((int)a_tmp - 1);
    shengdao1[0] = (PointIn_data[absxk_tmp] + PointIn_data[b_absxk_tmp]) / 2.0;
    shengdao1[1] =
        (PointIn_data[absxk_tmp + 1] + PointIn_data[b_absxk_tmp + 1]) / 2.0;
    shengdao1[2] =
        (PointIn_data[absxk_tmp + 2] + PointIn_data[b_absxk_tmp + 2]) / 2.0;
    foot_of_perpendicular_from_a_point_to_a_line(shengdao1, Mcenter, b_Mcenter,
                                                 &absxk, &yN1, &zN1);
    /* 法 */
    /*  平面法向量 */
    b_scale = -((MTaon[0] * absxk + MTaon[1] * yN1) + MTaon[2] * zN1);
    /*  空间点坐标 */
    /*  计算投影点 */
    i = (b_i + 1) << 1;
    absxk_tmp = 3 * (i - 2);
    a_tmp = PointIn_data[absxk_tmp];
    c = PointIn_data[absxk_tmp + 1];
    K = PointIn_data[absxk_tmp + 2];
    t = -(((MTaon[0] * a_tmp + MTaon[1] * c) + MTaon[2] * K) + b_scale) / t_tmp;
    /*  返回投影点 */
    P_projected1_idx_0 = a_tmp + MTaon[0] * t;
    P_projected1_idx_1 = c + MTaon[1] * t;
    P_projected1_idx_2 = K + MTaon[2] * t;
    /*  空间点坐标 */
    /*  计算投影点 */
    i = 3 * (i - 1);
    a_tmp = PointIn_data[i];
    c = PointIn_data[i + 1];
    K = PointIn_data[i + 2];
    t = -(((MTaon[0] * a_tmp + MTaon[1] * c) + MTaon[2] * K) + b_scale) / t_tmp;
    /*  返回投影点 */
    /*  三个点定义 */
    /*  斜率计算 */
    b_scale = (a_tmp + MTaon[0] * t) - P_projected1_idx_0;
    a_tmp = (c + MTaon[1] * t) - P_projected1_idx_1;
    c = (K + MTaon[2] * t) - P_projected1_idx_2;
    K = -(((P_projected1_idx_0 - absxk) * b_scale +
           (P_projected1_idx_1 - yN1) * a_tmp) +
          (P_projected1_idx_2 - zN1) * c) /
        ((b_scale * b_scale + a_tmp * a_tmp) + c * c);
    /*  P1点在轴线上的投影坐标 */
    scale = 3.3121686421112381E-170;
    absxk = fabs((K * b_scale + P_projected1_idx_0) - absxk);
    if (absxk > 3.3121686421112381E-170) {
      P_projected1_idx_0 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      P_projected1_idx_0 = t * t;
    }
    absxk = fabs((K * a_tmp + P_projected1_idx_1) - yN1);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    absxk = fabs((K * c + P_projected1_idx_2) - zN1);
    if (absxk > scale) {
      t = scale / absxk;
      P_projected1_idx_0 = P_projected1_idx_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      P_projected1_idx_0 += t * t;
    }
    P_projected1_idx_0 = scale * sqrt(P_projected1_idx_0);
    TiC_data[b_i] = P_projected1_idx_0 / Mradial;
  }
  /*  alphaA = asin(TiC); */
  a_tmp = floor(shenglunum / 2.0);
  if (a_tmp < 1.0) {
    absxk_tmp = 0;
  } else {
    absxk_tmp = (int)a_tmp;
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
    c = TiC_data[b_i];
    LTPY_data[b_i] = Distance_data[b_i] -
                     2.0 * sqrt(1.0 - c * c) * Mradial / sin(theta_data[b_i]);
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
    c = rtNaN;
  } else if (shenglunum == 0.0) {
    c = 0.0;
  } else {
    c = fmod(shenglunum, 2.0);
  }
  if (c == 1.0) {
    /* 奇数 */
    TiYiCe_data[(int)(unsigned int)a_tmp] = 0.0;
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
    b_scale = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        b_scale *= TiYiCe_data[b_i] - TiYiCe_data[absxk_tmp];
      }
    }
    K = TiYiCe_data[b_i];
    Distance_data[b_i] /= sqrt(1.0 - K * K) * b_scale;
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
  if (c == 1.0) {
    /* 奇数 */
    TiYiCe_data[(int)(unsigned int)a_tmp] = 0.0;
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
    b_scale = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        b_scale *= TiYiCe_data[b_i] - TiYiCe_data[absxk_tmp];
      }
    }
    a_tmp = TiYiCe_data[b_i];
    Distance_data[b_i] /= rt_powd_snf(1.0 - a_tmp * a_tmp, 0.6) * b_scale;
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
