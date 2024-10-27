/*
 * File: JuXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:51:24
 */

/* Include Files */
#include "JuXingFuCe.h"
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

/* Function Declarations */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  double *b_in2_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in2, 2);
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = 1;
  if (in1->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in1->size[1];
  }
  b_in2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in1->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_1] - in1_data[i * stride_1_1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in2->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in2->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(&b_in2);
}

/*
 * 计算距离
 *
 * Arguments    : const emxArray_real_T *PointIn
 *                double shenglunum
 *                const double Pin[3]
 *                const double Tao[3]
 *                double h
 *                const emxArray_real_T *PlaneParaOut4
 *                emxArray_real_T *Distance
 *                emxArray_real_T *theta
 *                emxArray_real_T *LTPY
 *                emxArray_real_T *TiC
 *                emxArray_real_T *Wquanzhong3
 *                emxArray_real_T *Wquanzhong4
 * Return Type  : void
 */
void JuXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                const double Pin[3], const double Tao[3], double h,
                const emxArray_real_T *PlaneParaOut4, emxArray_real_T *Distance,
                emxArray_real_T *theta, emxArray_real_T *LTPY,
                emxArray_real_T *TiC, emxArray_real_T *Wquanzhong3,
                emxArray_real_T *Wquanzhong4)
{
  static const double b_dv[5] = {2.0, 0.66666666666666663, 0.4,
                                 0.2857142857142857, 0.22222222222222221};
  static const double b_dv1[5] = {1.838286, 0.556753, 0.315143, 0.215852,
                                  0.162469};
  emxArray_real_T *TiYiCe;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *t_k;
  emxArray_real_T *w;
  double shengdao1[3];
  double shengdao2[3];
  const double *PlaneParaOut4_data;
  const double *PointIn_data;
  double a;
  double absxk;
  double b_scale;
  double c;
  double d;
  double scale;
  double t;
  double x_intersect1;
  double y;
  double y_intersect1;
  double z_intersect1;
  double *Distance_data;
  double *TiC_data;
  double *theta_data;
  double *w_data;
  int absxk_tmp;
  int b_i;
  int b_loop_ub_tmp;
  unsigned int count_tk;
  int i;
  int loop_ub_tmp;
  int nx;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  PlaneParaOut4_data = PlaneParaOut4->data;
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
    nx = 3 * ((int)(d - 1.0) - 1);
    absxk_tmp = 3 * ((int)d - 1);
    absxk = fabs(PointIn_data[nx] - PointIn_data[absxk_tmp]);
    if (absxk > 3.3121686421112381E-170) {
      x_intersect1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x_intersect1 = t * t;
    }
    absxk = fabs(PointIn_data[nx + 1] - PointIn_data[absxk_tmp + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    absxk = fabs(PointIn_data[nx + 2] - PointIn_data[absxk_tmp + 2]);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    Distance_data[b_i] = scale * sqrt(x_intersect1);
  }
  /*  计算声道角度 */
  i = theta->size[0] * theta->size[1];
  theta->size[0] = 1;
  theta->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(theta, i);
  theta_data = theta->data;
  if (loop_ub_tmp - 1 >= 0) {
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    i = 3 * ((int)d - 1);
    nx = 3 * ((int)(d - 1.0) - 1);
    d = PointIn_data[i] - PointIn_data[nx];
    c = Tao[0] * d;
    absxk = fabs(Tao[0]);
    if (absxk > 3.3121686421112381E-170) {
      x_intersect1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x_intersect1 = t * t;
    }
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    d = PointIn_data[i + 1] - PointIn_data[nx + 1];
    c += Tao[1] * d;
    absxk = fabs(Tao[1]);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    absxk = fabs(d);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      y = y * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      y += t * t;
    }
    d = PointIn_data[i + 2] - PointIn_data[nx + 2];
    c += Tao[2] * d;
    absxk = fabs(Tao[2]);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    absxk = fabs(d);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      y = y * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      y += t * t;
    }
    x_intersect1 = scale * sqrt(x_intersect1);
    y = b_scale * sqrt(y);
    theta_data[b_i] = acos(c / (x_intersect1 * y));
  }
  i = theta->size[0] * theta->size[1];
  theta->size[0] = 1;
  emxEnsureCapacity_real_T(theta, i);
  theta_data = theta->data;
  b_loop_ub_tmp = theta->size[1] - 1;
  for (i = 0; i <= b_loop_ub_tmp; i++) {
    theta_data[i] = 3.1415926535897931 - theta_data[i];
  }
  /*  degtheta = rad2deg(theta); */
  /*  计算LT */
  i = LTPY->size[0] * LTPY->size[1];
  LTPY->size[0] = 1;
  LTPY->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(LTPY, i);
  theta_data = LTPY->data;
  if (loop_ub_tmp - 1 >= 0) {
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    nx = 3 * ((int)d - 1);
    absxk_tmp = 3 * ((int)(d - 1.0) - 1);
    shengdao2[0] = PointIn_data[nx] - PointIn_data[absxk_tmp];
    shengdao2[1] = PointIn_data[nx + 1] - PointIn_data[absxk_tmp + 1];
    shengdao2[2] = PointIn_data[nx + 2] - PointIn_data[absxk_tmp + 2];
    /*  计算方向向量 */
    a = PlaneParaOut4_data[0];
    b_scale = PlaneParaOut4_data[1];
    c = PlaneParaOut4_data[2];
    /*  将直线方程代入平面方程，求解参数 t */
    i = ((b_i + 1) << 1) - 2;
    d = PointIn_data[3 * i];
    y = PointIn_data[3 * i + 1];
    absxk = PointIn_data[3 * i + 2];
    t = -(((a * d + b_scale * y) + c * absxk) + PlaneParaOut4_data[3]) /
        ((a * shengdao2[0] + b_scale * shengdao2[1]) + c * shengdao2[2]);
    /*  计算交点 */
    x_intersect1 = d + t * shengdao2[0];
    y_intersect1 = y + t * shengdao2[1];
    z_intersect1 = absxk + t * shengdao2[2];
    /*  计算方向向量 */
    a = PlaneParaOut4_data[8];
    b_scale = PlaneParaOut4_data[9];
    c = PlaneParaOut4_data[10];
    /*  将直线方程代入平面方程，求解参数 t */
    t = -(((a * d + b_scale * y) + c * absxk) + PlaneParaOut4_data[11]) /
        ((a * shengdao2[0] + b_scale * shengdao2[1]) + c * shengdao2[2]);
    /*  计算交点 */
    b_scale = d + t * shengdao2[0];
    a = y + t * shengdao2[1];
    y = absxk + t * shengdao2[2];
    scale = 3.3121686421112381E-170;
    absxk = fabs(b_scale - x_intersect1);
    if (absxk > 3.3121686421112381E-170) {
      x_intersect1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x_intersect1 = t * t;
    }
    absxk = fabs(a - y_intersect1);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    absxk = fabs(y - z_intersect1);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    theta_data[b_i] = scale * sqrt(x_intersect1);
  }
  if (Distance->size[1] == LTPY->size[1]) {
    i = LTPY->size[0] * LTPY->size[1];
    LTPY->size[0] = 1;
    LTPY->size[1] = Distance->size[1];
    emxEnsureCapacity_real_T(LTPY, i);
    theta_data = LTPY->data;
    for (i = 0; i <= b_loop_ub_tmp; i++) {
      theta_data[i] = Distance_data[i] - theta_data[i];
    }
  } else {
    b_minus(LTPY, Distance);
  }
  /*  相对高度计算 */
  i = TiC->size[0] * TiC->size[1];
  TiC->size[0] = 1;
  TiC->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(TiC, i);
  TiC_data = TiC->data;
  if (loop_ub_tmp - 1 >= 0) {
    shengdao2[0] = Pin[0] + Tao[0];
    shengdao2[1] = Pin[1] + Tao[1];
    shengdao2[2] = Pin[2] + Tao[2];
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    nx = 3 * ((int)(d - 1.0) - 1);
    absxk_tmp = 3 * ((int)d - 1);
    shengdao1[0] = (PointIn_data[nx] + PointIn_data[absxk_tmp]) / 2.0;
    shengdao1[1] = (PointIn_data[nx + 1] + PointIn_data[absxk_tmp + 1]) / 2.0;
    shengdao1[2] = (PointIn_data[nx + 2] + PointIn_data[absxk_tmp + 2]) / 2.0;
    foot_of_perpendicular_from_a_point_to_a_line(shengdao1, Pin, shengdao2,
                                                 &b_scale, &y, &a);
    scale = 3.3121686421112381E-170;
    absxk = fabs(shengdao1[0] - b_scale);
    if (absxk > 3.3121686421112381E-170) {
      x_intersect1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x_intersect1 = t * t;
    }
    absxk = fabs(shengdao1[1] - y);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    absxk = fabs(shengdao1[2] - a);
    if (absxk > scale) {
      t = scale / absxk;
      x_intersect1 = x_intersect1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x_intersect1 += t * t;
    }
    x_intersect1 = scale * sqrt(x_intersect1);
    TiC_data[b_i] = 2.0 * x_intersect1 / h;
  }
  /*  alphaA = asin(TiC); */
  d = floor(shenglunum / 2.0);
  if (d < 1.0) {
    nx = 0;
  } else {
    nx = (int)d;
  }
  emxInit_real_T(&TiYiCe, 2);
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = nx;
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  for (i = 0; i < nx; i++) {
    theta_data[i] = -TiC_data[i];
  }
  nx = TiYiCe->size[1];
  for (i = 0; i < nx; i++) {
    TiC_data[i] = theta_data[i];
  }
  /*  计算权重 */
  /*  k1 = 0.5; */
  /*  k2 = 0.6; */
  /*  gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903]; */
  /*  gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959]; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  nx = TiC->size[1];
  for (i = 0; i < nx; i++) {
    theta_data[i] = TiC_data[i];
  }
  if (rtIsInf(shenglunum)) {
    y = rtNaN;
  } else if (shenglunum == 0.0) {
    y = 0.0;
  } else {
    y = fmod(shenglunum, 2.0);
  }
  if (y == 1.0) {
    /* 奇数 */
    theta_data[(int)(unsigned int)d] = 0.0;
  }
  emxInit_real_T(&t_k, 1);
  b_loop_ub_tmp = (int)(shenglunum - 1.0);
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  Distance_data = t_k->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    Distance_data[i] = 0.0;
  }
  emxInit_real_T(&w, 1);
  i = w->size[0];
  w->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(w, i);
  w_data = w->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    w_data[i] = 0.0;
  }
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 1);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        Distance_data[(int)count_tk - 1] = theta_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      w_data[b_i] += b_dv[absxk_tmp] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        b_scale *= theta_data[b_i] - theta_data[absxk_tmp];
      }
    }
    absxk = theta_data[b_i];
    w_data[b_i] /= rt_powd_snf(1.0 - absxk * absxk, 0.0) * b_scale;
  }
  nx = w->size[0];
  i = Wquanzhong3->size[0];
  Wquanzhong3->size[0] = w->size[0];
  emxEnsureCapacity_real_T(Wquanzhong3, i);
  theta_data = Wquanzhong3->data;
  for (absxk_tmp = 0; absxk_tmp < nx; absxk_tmp++) {
    theta_data[absxk_tmp] = fabs(w_data[absxk_tmp]);
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = TiC->size[1];
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  nx = TiC->size[1];
  for (i = 0; i < nx; i++) {
    theta_data[i] = TiC_data[i];
  }
  if (y == 1.0) {
    /* 奇数 */
    theta_data[(int)(unsigned int)d] = 0.0;
  }
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  Distance_data = t_k->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    Distance_data[i] = 0.0;
  }
  i = w->size[0];
  w->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(w, i);
  w_data = w->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    w_data[i] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        Distance_data[(int)count_tk - 1] = theta_data[absxk_tmp];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (absxk_tmp = 0; absxk_tmp < i; absxk_tmp++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)absxk_tmp + 1.0), r);
      prod(r, r1);
      w_data[b_i] += b_dv1[absxk_tmp] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (absxk_tmp = 0; absxk_tmp < loop_ub_tmp; absxk_tmp++) {
      if ((unsigned int)absxk_tmp != (unsigned int)b_i) {
        b_scale *= theta_data[b_i] - theta_data[absxk_tmp];
      }
    }
    d = theta_data[b_i];
    w_data[b_i] /= rt_powd_snf(1.0 - d * d, 0.15) * b_scale;
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&t_k);
  emxFree_real_T(&TiYiCe);
  nx = w->size[0];
  i = Wquanzhong4->size[0];
  Wquanzhong4->size[0] = w->size[0];
  emxEnsureCapacity_real_T(Wquanzhong4, i);
  theta_data = Wquanzhong4->data;
  for (absxk_tmp = 0; absxk_tmp < nx; absxk_tmp++) {
    theta_data[absxk_tmp] = fabs(w_data[absxk_tmp]);
  }
  emxFree_real_T(&w);
}

/*
 * File trailer for JuXingFuCe.c
 *
 * [EOF]
 */
