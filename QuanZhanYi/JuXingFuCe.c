/*
 * File: JuXingFuCe.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Sep-2024 15:15:59
 */

/* Include Files */
#include "JuXingFuCe.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "combineVectorElements.h"
#include "mod.h"
#include "nchoosek.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2);

static double rt_powd_snf(double u0, double u1);

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
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double d;
  double d1;
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

/*
 * 计算距离
 *
 * Arguments    : const emxArray_real_T *PointIn
 *                double shenglunum
 *                const double Pin[3]
 *                const double Tao[3]
 *                double h
 *                const emxArray_real_T *PlaneParaOut8
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
                const emxArray_real_T *PlaneParaOut8, emxArray_real_T *Distance,
                emxArray_real_T *theta, emxArray_real_T *LTPY,
                emxArray_real_T *TiC, emxArray_real_T *Wquanzhong3,
                emxArray_real_T *Wquanzhong4)
{
  static const double dv[5] = {2.0, 0.66666666666666663, 0.4,
                               0.2857142857142857, 0.22222222222222221};
  static const double dv1[5] = {1.838286, 0.556753, 0.315143, 0.215852,
                                0.162469};
  emxArray_real_T *TiYiCe;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *t_k;
  emxArray_real_T *w;
  const double *PlaneParaOut8_data;
  const double *PointIn_data;
  double a;
  double absxk;
  double b;
  double b_scale;
  double c;
  double d;
  double d1;
  double d2;
  double scale;
  double shengdao1_idx_0;
  double shengdao1_idx_1;
  double shengdao1_idx_2;
  double shengdao2_idx_1;
  double shengdao2_idx_2;
  double t;
  double x_intersect1;
  double y;
  double y_intersect1;
  double z_intersect1;
  double *Distance_data;
  double *TiC_data;
  double *t_k_data;
  double *theta_data;
  int b_i;
  int b_loop_ub_tmp;
  unsigned int count_tk;
  int i;
  int i1;
  int idx;
  int loop_ub_tmp;
  int na;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  PlaneParaOut8_data = PlaneParaOut8->data;
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
  i = theta->size[0] * theta->size[1];
  theta->size[0] = 1;
  theta->size[1] = (int)shenglunum;
  emxEnsureCapacity_real_T(theta, i);
  theta_data = theta->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    d = 2.0 * ((double)b_i + 1.0);
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    i = 3 * ((int)(d - 1.0) - 1);
    shengdao1_idx_2 = PointIn_data[i];
    shengdao1_idx_0 = shengdao1_idx_2;
    i1 = 3 * ((int)d - 1);
    d = PointIn_data[i1] - shengdao1_idx_2;
    x_intersect1 = Tao[0] * d;
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
      shengdao2_idx_1 = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      shengdao2_idx_1 = t * t;
    }
    shengdao1_idx_2 = PointIn_data[i + 1];
    shengdao1_idx_1 = shengdao1_idx_2;
    d = PointIn_data[i1 + 1] - shengdao1_idx_2;
    x_intersect1 += Tao[1] * d;
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
      shengdao2_idx_1 = shengdao2_idx_1 * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      shengdao2_idx_1 += t * t;
    }
    shengdao1_idx_2 = PointIn_data[i + 2];
    d = PointIn_data[i1 + 2] - shengdao1_idx_2;
    x_intersect1 += Tao[2] * d;
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
      shengdao2_idx_1 = shengdao2_idx_1 * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      shengdao2_idx_1 += t * t;
    }
    y = scale * sqrt(y);
    shengdao2_idx_1 = b_scale * sqrt(shengdao2_idx_1);
    theta_data[b_i] = acos(x_intersect1 / (y * shengdao2_idx_1));
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
    i = 3 * ((int)(d - 1.0) - 1);
    shengdao1_idx_2 = PointIn_data[i];
    shengdao1_idx_0 = shengdao1_idx_2;
    idx = 3 * ((int)d - 1);
    b_scale = PointIn_data[idx] - shengdao1_idx_2;
    shengdao1_idx_2 = PointIn_data[i + 1];
    shengdao1_idx_1 = shengdao1_idx_2;
    shengdao2_idx_1 = PointIn_data[idx + 1] - shengdao1_idx_2;
    shengdao1_idx_2 = PointIn_data[i + 2];
    shengdao2_idx_2 = PointIn_data[idx + 2] - shengdao1_idx_2;
    /*  计算方向向量 */
    a = PlaneParaOut8_data[0];
    b = PlaneParaOut8_data[1];
    c = PlaneParaOut8_data[2];
    /*  将直线方程代入平面方程，求解参数 t */
    i = ((b_i + 1) << 1) - 2;
    d = PointIn_data[3 * i];
    d1 = PointIn_data[3 * i + 1];
    d2 = PointIn_data[3 * i + 2];
    t = -(((a * d + b * d1) + c * d2) + PlaneParaOut8_data[3]) /
        ((a * b_scale + b * shengdao2_idx_1) + c * shengdao2_idx_2);
    /*  计算交点 */
    x_intersect1 = d + t * b_scale;
    y_intersect1 = d1 + t * shengdao2_idx_1;
    z_intersect1 = d2 + t * shengdao2_idx_2;
    /*  计算方向向量 */
    a = PlaneParaOut8_data[16];
    b = PlaneParaOut8_data[17];
    c = PlaneParaOut8_data[18];
    /*  将直线方程代入平面方程，求解参数 t */
    t = -(((a * d + b * d1) + c * d2) + PlaneParaOut8_data[19]) /
        ((a * b_scale + b * shengdao2_idx_1) + c * shengdao2_idx_2);
    /*  计算交点 */
    scale = 3.3121686421112381E-170;
    absxk = fabs((d + t * b_scale) - x_intersect1);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / 3.3121686421112381E-170;
      y = b_scale * b_scale;
    }
    absxk = fabs((d1 + t * shengdao2_idx_1) - y_intersect1);
    if (absxk > scale) {
      b_scale = scale / absxk;
      y = y * b_scale * b_scale + 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / scale;
      y += b_scale * b_scale;
    }
    absxk = fabs((d2 + t * shengdao2_idx_2) - z_intersect1);
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
  na = (int)(2.0 * shenglunum);
  TiC->size[1] = na;
  emxEnsureCapacity_real_T(TiC, i);
  TiC_data = TiC->data;
  for (i = 0; i < na; i++) {
    TiC_data[i] = 0.0;
  }
  if (na - 1 >= 0) {
    a = PlaneParaOut8_data[8];
    b = PlaneParaOut8_data[9];
    c = PlaneParaOut8_data[10];
    shengdao1_idx_0 = a;
    shengdao1_idx_1 = b;
    shengdao1_idx_2 = c;
  }
  for (b_i = 0; b_i < na; b_i++) {
    /*  计算交点 */
    d = PointIn_data[3 * b_i];
    d1 = PointIn_data[3 * b_i + 1];
    d2 = PointIn_data[3 * b_i + 2];
    t = -(((a * d + b * d1) + c * d2) -
          ((a * Pin[0] + b * Pin[1]) + c * Pin[2])) /
        ((a * shengdao1_idx_0 + b * shengdao1_idx_1) + c * shengdao1_idx_2);
    /*  计算高度 */
    scale = 3.3121686421112381E-170;
    absxk = fabs((d + t * shengdao1_idx_0) - d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / 3.3121686421112381E-170;
      y = b_scale * b_scale;
    }
    absxk = fabs((d1 + t * shengdao1_idx_1) - d1);
    if (absxk > scale) {
      b_scale = scale / absxk;
      y = y * b_scale * b_scale + 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / scale;
      y += b_scale * b_scale;
    }
    absxk = fabs((d2 + t * shengdao1_idx_2) - d2);
    if (absxk > scale) {
      b_scale = scale / absxk;
      y = y * b_scale * b_scale + 1.0;
      scale = absxk;
    } else {
      b_scale = absxk / scale;
      y += b_scale * b_scale;
    }
    y = scale * sqrt(y);
    TiC_data[b_i] = 2.0 * y / h;
  }
  d = b_mod(shenglunum);
  emxInit_real_T(&TiYiCe, 2);
  if (d == 1.0) {
    /* 奇数 */
    d1 = 2.0 * floor(shenglunum / 2.0);
    if (d1 < 1.0) {
      na = 0;
    } else {
      na = (int)d1;
    }
    i = TiYiCe->size[0] * TiYiCe->size[1];
    TiYiCe->size[0] = 1;
    TiYiCe->size[1] = na;
    emxEnsureCapacity_real_T(TiYiCe, i);
    theta_data = TiYiCe->data;
    for (i = 0; i < na; i++) {
      theta_data[i] = -TiC_data[i];
    }
    na = TiYiCe->size[1];
    for (i = 0; i < na; i++) {
      TiC_data[i] = theta_data[i];
    }
  } else {
    /* 偶数 */
    d1 = 2.0 * (shenglunum / 2.0);
    if (d1 < 1.0) {
      na = 0;
    } else {
      na = (int)d1;
    }
    i = TiYiCe->size[0] * TiYiCe->size[1];
    TiYiCe->size[0] = 1;
    TiYiCe->size[1] = na;
    emxEnsureCapacity_real_T(TiYiCe, i);
    theta_data = TiYiCe->data;
    for (i = 0; i < na; i++) {
      theta_data[i] = -TiC_data[i];
    }
    na = TiYiCe->size[1];
    for (i = 0; i < na; i++) {
      TiC_data[i] = theta_data[i];
    }
  }
  /*  计算权重 */
  /*  k1 = 0.5; */
  /*  k2 = 0.6; */
  /*  gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903]; */
  /*  gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959]; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  d1 = 2.0 * shenglunum;
  if (d1 < 1.0) {
    i = 1;
    i1 = -1;
  } else {
    i = 2;
    i1 = (int)d1 - 1;
  }
  b_i = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  na = div_s32(i1, i);
  TiYiCe->size[1] = na + 1;
  emxEnsureCapacity_real_T(TiYiCe, b_i);
  theta_data = TiYiCe->data;
  for (i1 = 0; i1 <= na; i1++) {
    theta_data[i1] = TiC_data[i * i1];
  }
  if (d == 1.0) {
    /* 奇数 */
    theta_data[(int)(floor(shenglunum / 2.0) + 1.0) - 1] = 0.0;
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
  Distance_data = w->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    Distance_data[i] = 0.0;
  }
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 1);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = theta_data[idx];
        count_tk++;
      }
    }
    i = (int)((shenglunum + 1.0) / 2.0);
    for (idx = 0; idx < i; idx++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)idx + 1.0), r);
      prod(r, r1);
      Distance_data[b_i] += dv[idx] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        b_scale *= theta_data[b_i] - theta_data[idx];
      }
    }
    d2 = theta_data[b_i];
    Distance_data[b_i] /= rt_powd_snf(1.0 - d2 * d2, 0.0) * b_scale;
  }
  na = w->size[0];
  i = w->size[0] << 1;
  i1 = t_k->size[0];
  t_k->size[0] = i;
  emxEnsureCapacity_real_T(t_k, i1);
  t_k_data = t_k->data;
  idx = -1;
  for (b_i = 0; b_i < na; b_i++) {
    t_k_data[idx + 1] = Distance_data[b_i];
    t_k_data[idx + 2] = Distance_data[b_i];
    idx += 2;
  }
  na = t_k->size[0];
  i1 = Wquanzhong3->size[0];
  Wquanzhong3->size[0] = t_k->size[0];
  emxEnsureCapacity_real_T(Wquanzhong3, i1);
  theta_data = Wquanzhong3->data;
  for (b_i = 0; b_i < na; b_i++) {
    theta_data[b_i] = fabs(t_k_data[b_i]);
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  if (d1 < 1.0) {
    i1 = 1;
    b_i = -1;
  } else {
    i1 = 2;
    b_i = (int)d1 - 1;
  }
  idx = TiYiCe->size[0] * TiYiCe->size[1];
  TiYiCe->size[0] = 1;
  na = div_s32(b_i, i1);
  TiYiCe->size[1] = na + 1;
  emxEnsureCapacity_real_T(TiYiCe, idx);
  theta_data = TiYiCe->data;
  for (b_i = 0; b_i <= na; b_i++) {
    theta_data[b_i] = TiC_data[i1 * b_i];
  }
  if (d == 1.0) {
    /* 奇数 */
    theta_data[(int)(floor(shenglunum / 2.0) + 1.0) - 1] = 0.0;
  }
  i1 = t_k->size[0];
  t_k->size[0] = (int)(shenglunum - 1.0);
  emxEnsureCapacity_real_T(t_k, i1);
  t_k_data = t_k->data;
  for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
    t_k_data[i1] = 0.0;
  }
  i1 = w->size[0];
  w->size[0] = (int)shenglunum;
  emxEnsureCapacity_real_T(w, i1);
  Distance_data = w->data;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    Distance_data[i1] = 0.0;
  }
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    count_tk = 1U;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        t_k_data[(int)count_tk - 1] = theta_data[idx];
        count_tk++;
      }
    }
    i1 = (int)((shenglunum + 1.0) / 2.0);
    for (idx = 0; idx < i1; idx++) {
      b_nchoosek(t_k, (shenglunum + 1.0) - 2.0 * ((double)idx + 1.0), r);
      prod(r, r1);
      Distance_data[b_i] += dv1[idx] * -combineVectorElements(r1);
    }
    b_scale = 1.0;
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      if ((unsigned int)idx != (unsigned int)b_i) {
        b_scale *= theta_data[b_i] - theta_data[idx];
      }
    }
    d = theta_data[b_i];
    Distance_data[b_i] /= rt_powd_snf(1.0 - d * d, 0.15) * b_scale;
  }
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&TiYiCe);
  na = w->size[0];
  i1 = t_k->size[0];
  t_k->size[0] = i;
  emxEnsureCapacity_real_T(t_k, i1);
  t_k_data = t_k->data;
  idx = -1;
  for (b_i = 0; b_i < na; b_i++) {
    t_k_data[idx + 1] = Distance_data[b_i];
    t_k_data[idx + 2] = Distance_data[b_i];
    idx += 2;
  }
  emxFree_real_T(&w);
  na = t_k->size[0];
  i = Wquanzhong4->size[0];
  Wquanzhong4->size[0] = t_k->size[0];
  emxEnsureCapacity_real_T(Wquanzhong4, i);
  theta_data = Wquanzhong4->data;
  for (b_i = 0; b_i < na; b_i++) {
    theta_data[b_i] = fabs(t_k_data[b_i]);
  }
  emxFree_real_T(&t_k);
}

/*
 * File trailer for JuXingFuCe.c
 *
 * [EOF]
 */
