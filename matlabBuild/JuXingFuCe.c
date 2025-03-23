/*
 * File: JuXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
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
 *                const double LenDaoJiao[8]
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
                const emxArray_real_T *PlaneParaOut4,
                const double LenDaoJiao[8], emxArray_real_T *Distance,
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
  double shengdao2[3];
  double x_intersect1[3];
  const double *PlaneParaOut4_data;
  const double *PointIn_data;
  double absxk;
  double b;
  double b_scale;
  double b_x_intersect1;
  double c;
  double d;
  double d1;
  double d2;
  double scale;
  double t;
  double y;
  double y_intersect1;
  double zN1;
  double z_intersect1;
  double *Distance_data;
  double *TiC_data;
  double *theta_data;
  double *w_data;
  int b_i;
  int b_loop_ub_tmp;
  int count_tk;
  int i;
  int loop_ub_tmp;
  int nx;
  (void)LenDaoJiao;
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
    count_tk = 3 * ((int)(d - 1.0) - 1);
    nx = 3 * ((int)d - 1);
    absxk = fabs(PointIn_data[count_tk] - PointIn_data[nx]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(PointIn_data[count_tk + 1] - PointIn_data[nx + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(PointIn_data[count_tk + 2] - PointIn_data[nx + 2]);
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
    count_tk = 3 * ((int)(d - 1.0) - 1);
    d = PointIn_data[i] - PointIn_data[count_tk];
    c = Tao[0] * d;
    absxk = fabs(Tao[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      b = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b = t * t;
    }
    d = PointIn_data[i + 1] - PointIn_data[count_tk + 1];
    c += Tao[1] * d;
    absxk = fabs(Tao[1]);
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
      b = b * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b += t * t;
    }
    d = PointIn_data[i + 2] - PointIn_data[count_tk + 2];
    c += Tao[2] * d;
    absxk = fabs(Tao[2]);
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
      b = b * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b += t * t;
    }
    y = scale * sqrt(y);
    b = b_scale * sqrt(b);
    theta_data[b_i] = acos(c / (y * b));
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
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    count_tk = 3 * ((int)d - 1);
    nx = 3 * ((int)(d - 1.0) - 1);
    shengdao2[0] = PointIn_data[count_tk] - PointIn_data[nx];
    shengdao2[1] = PointIn_data[count_tk + 1] - PointIn_data[nx + 1];
    shengdao2[2] = PointIn_data[count_tk + 2] - PointIn_data[nx + 2];
    /*  计算方向向量 */
    b_scale = PlaneParaOut4_data[0];
    b = PlaneParaOut4_data[1];
    c = PlaneParaOut4_data[2];
    /*  将直线方程代入平面方程，求解参数 t */
    i = ((b_i + 1) << 1) - 2;
    d = PointIn_data[3 * i];
    d1 = PointIn_data[3 * i + 1];
    d2 = PointIn_data[3 * i + 2];
    t = -(((b_scale * d + b * d1) + c * d2) + PlaneParaOut4_data[3]) /
        ((b_scale * shengdao2[0] + b * shengdao2[1]) + c * shengdao2[2]);
    /*  计算交点 */
    b_x_intersect1 = d + t * shengdao2[0];
    y_intersect1 = d1 + t * shengdao2[1];
    z_intersect1 = d2 + t * shengdao2[2];
    /*  计算方向向量 */
    b_scale = PlaneParaOut4_data[8];
    b = PlaneParaOut4_data[9];
    c = PlaneParaOut4_data[10];
    /*  将直线方程代入平面方程，求解参数 t */
    t = -(((b_scale * d + b * d1) + c * d2) + PlaneParaOut4_data[11]) /
        ((b_scale * shengdao2[0] + b * shengdao2[1]) + c * shengdao2[2]);
    /*  计算交点 */
    x_intersect1[0] = b_x_intersect1;
    x_intersect1[1] = y_intersect1;
    x_intersect1[2] = z_intersect1;
    scale = 3.3121686421112381E-170;
    absxk = fabs((d + t * shengdao2[0]) - b_x_intersect1);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / 3.3121686421112381E-170;
      y = b_scale * b_scale;
    }
    absxk = fabs((d1 + t * shengdao2[1]) - y_intersect1);
    if (absxk > scale) {
      b_scale = scale / absxk;
      y = y * b_scale * b_scale + 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / scale;
      y += b_scale * b_scale;
    }
    absxk = fabs((d2 + t * shengdao2[2]) - z_intersect1);
    if (absxk > scale) {
      b_scale = scale / absxk;
      y = y * b_scale * b_scale + 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / scale;
      y += b_scale * b_scale;
    }
    theta_data[b_i] = scale * sqrt(y);
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
  if ((int)shenglunum - 1 >= 0) {
    x_intersect1[0] = Pin[0] + Tao[0];
    x_intersect1[1] = Pin[1] + Tao[1];
    x_intersect1[2] = Pin[2] + Tao[2];
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    count_tk = 3 * ((int)(d - 1.0) - 1);
    nx = 3 * ((int)d - 1);
    shengdao2[0] = (PointIn_data[count_tk] + PointIn_data[nx]) / 2.0;
    shengdao2[1] = (PointIn_data[count_tk + 1] + PointIn_data[nx + 1]) / 2.0;
    shengdao2[2] = (PointIn_data[count_tk + 2] + PointIn_data[nx + 2]) / 2.0;
    foot_of_perpendicular_from_a_point_to_a_line(shengdao2, Pin, x_intersect1,
                                                 &z_intersect1, &c, &zN1);
    /* 法 */
    /*  平面法向量 */
    b_scale = -((Tao[0] * z_intersect1 + Tao[1] * c) + Tao[2] * zN1);
    /*  空间点坐标 */
    /*  计算投影点 */
    i = (b_i + 1) << 1;
    count_tk = 3 * (i - 2);
    d = PointIn_data[count_tk];
    d1 = PointIn_data[count_tk + 1];
    d2 = PointIn_data[count_tk + 2];
    b = (Tao[0] * Tao[0] + Tao[1] * Tao[1]) + Tao[2] * Tao[2];
    t = -(((Tao[0] * d + Tao[1] * d1) + Tao[2] * d2) + b_scale) / b;
    /*  返回投影点 */
    shengdao2[0] = d + Tao[0] * t;
    shengdao2[1] = d1 + Tao[1] * t;
    shengdao2[2] = d2 + Tao[2] * t;
    /*  空间点坐标 */
    /*  计算投影点 */
    i = 3 * (i - 1);
    d = PointIn_data[i];
    d1 = PointIn_data[i + 1];
    d2 = PointIn_data[i + 2];
    t = -(((Tao[0] * d + Tao[1] * d1) + Tao[2] * d2) + b_scale) / b;
    /*  返回投影点 */
    /*  三个点定义 */
    /*  斜率计算 */
    b_scale = (d + Tao[0] * t) - shengdao2[0];
    y_intersect1 = (d1 + Tao[1] * t) - shengdao2[1];
    b = (d2 + Tao[2] * t) - shengdao2[2];
    b_x_intersect1 =
        -(((shengdao2[0] - z_intersect1) * b_scale +
           (shengdao2[1] - c) * y_intersect1) +
          (shengdao2[2] - zN1) * b) /
        ((b_scale * b_scale + y_intersect1 * y_intersect1) + b * b);
    /*  P1点在轴线上的投影坐标 */
    scale = 3.3121686421112381E-170;
    absxk = fabs((b_x_intersect1 * b_scale + shengdao2[0]) - z_intersect1);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs((b_x_intersect1 * y_intersect1 + shengdao2[1]) - c);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs((b_x_intersect1 * b + shengdao2[2]) - zN1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    TiC_data[b_i] = 2.0 * y / h;
  }
  /*  alphaA = asin(TiC); */
  d = floor(shenglunum / 2.0);
  if (d < 1.0) {
    count_tk = 0;
  } else {
    count_tk = (int)d;
  }
  emxInit_real_T(&TiYiCe, 2);
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = count_tk;
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  for (i = 0; i < count_tk; i++) {
    theta_data[i] = -TiC_data[i];
  }
  count_tk = TiYiCe->size[1];
  for (i = 0; i < count_tk; i++) {
    TiC_data[i] = theta_data[i];
  }
  /*  计算权重 */
  /*  k1 = 0.5; */
  /*  k2 = 0.6; */
  /*  gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903]; */
  /*  gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959]; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  if (shenglunum < 1.0) {
    b_loop_ub_tmp = 0;
  } else {
    b_loop_ub_tmp = (int)shenglunum;
  }
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = b_loop_ub_tmp;
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    theta_data[i] = TiC_data[i];
  }
  if (shenglunum == 0.0) {
    d1 = 0.0;
  } else {
    d1 = fmod(shenglunum, 2.0);
  }
  if (d1 == 1.0) {
    /* 奇数 */
    theta_data[(int)(unsigned int)d] = 0.0;
  }
  emxInit_real_T(&t_k, 1);
  count_tk = (int)(shenglunum - 1.0);
  i = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i);
  Distance_data = t_k->data;
  for (i = 0; i < count_tk; i++) {
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
    count_tk = 0;
    for (nx = 0; nx < loop_ub_tmp; nx++) {
      if (nx + 1 != b_i + 1) {
        Distance_data[count_tk] = theta_data[nx];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (count_tk = 0; count_tk < i; count_tk++) {
      nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)count_tk + 1.0), r);
      prod(r, r1);
      w_data[b_i] += b_dv[count_tk] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (nx = 0; nx < loop_ub_tmp; nx++) {
      if (nx + 1 != b_i + 1) {
        b_scale *= theta_data[b_i] - theta_data[nx];
      }
    }
    d2 = theta_data[b_i];
    w_data[b_i] /= rt_powd_snf(1.0 - d2 * d2, 0.0) * b_scale;
  }
  nx = w->size[0];
  i = Wquanzhong3->size[0];
  Wquanzhong3->size[0] = w->size[0];
  emxEnsureCapacity_real_T(Wquanzhong3, i);
  theta_data = Wquanzhong3->data;
  for (count_tk = 0; count_tk < nx; count_tk++) {
    theta_data[count_tk] = fabs(w_data[count_tk]);
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  TiYiCe->size[1] = b_loop_ub_tmp;
  emxEnsureCapacity_real_T(TiYiCe, i);
  theta_data = TiYiCe->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    theta_data[i] = TiC_data[i];
  }
  if (d1 == 1.0) {
    /* 奇数 */
    theta_data[(int)(unsigned int)d] = 0.0;
  }
  i = t_k->size[0];
  t_k->size[0] = theta->size[1] - 1;
  emxEnsureCapacity_real_T(t_k, i);
  Distance_data = t_k->data;
  for (i = 0; i <= loop_ub_tmp - 2; i++) {
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
    count_tk = 0;
    for (nx = 0; nx < loop_ub_tmp; nx++) {
      if (nx + 1 != b_i + 1) {
        Distance_data[count_tk] = theta_data[nx];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (count_tk = 0; count_tk < i; count_tk++) {
      nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)count_tk + 1.0), r);
      prod(r, r1);
      w_data[b_i] += b_dv1[count_tk] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (nx = 0; nx < loop_ub_tmp; nx++) {
      if (nx + 1 != b_i + 1) {
        b_scale *= theta_data[b_i] - theta_data[nx];
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
  for (count_tk = 0; count_tk < nx; count_tk++) {
    theta_data[count_tk] = fabs(w_data[count_tk]);
  }
  emxFree_real_T(&w);
}

/*
 * File trailer for JuXingFuCe.c
 *
 * [EOF]
 */
