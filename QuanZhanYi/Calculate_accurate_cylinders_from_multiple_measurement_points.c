/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 20:09:07
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "linspace.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "norm.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in3,
                             const emxArray_real_T *in4);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in3,
                             const emxArray_real_T *in4)
{
  const double *in3_data;
  const double *in4_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in3_data = in3->data;
  in1_data = in1->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in3_data[i * stride_0_0] + in4_data[i * stride_1_0];
  }
}

/*
 * Arguments    : const emxArray_real_T *Point_in
 *                double azimuth
 *                double elevation
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
    const emxArray_real_T *Point_in, double azimuth, double elevation,
    const double P_bound1[3], const double P_bound2[3], double Mcenter[3],
    double MTaon[3], double *Mradial, emxArray_real_T *Err_every,
    double Bottom_round_center1[3], double Bottom_round_center2[3])
{
  emxArray_real_T *B;
  emxArray_real_T *Bn;
  emxArray_real_T *L;
  emxArray_real_T *Xnn;
  emxArray_real_T *YuanDu;
  emxArray_real_T *b_ptCloud;
  emxArray_real_T *circleCloud;
  emxArray_real_T *dis;
  emxArray_real_T *ptCloud;
  emxArray_real_T *r;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  double mm[180];
  double nn[180];
  double dv[90];
  double dv1[90];
  double a[49];
  double b_C[49];
  double C[9];
  double rot1[9];
  double rot2[9];
  double Xn[7];
  double c_C[7];
  double deltX[7];
  double angles[3];
  double cang[3];
  double ttt[3];
  const double *Point_in_data;
  double a0;
  double absxk;
  double b0;
  double b_ii;
  double b_scale;
  double b_y1;
  double bkj;
  double c0;
  double cang_idx_0;
  double cang_idx_1;
  double r0;
  double scale;
  double t;
  double x1;
  double *B_data;
  double *L_data;
  double *Xnn_data;
  double *b_ptCloud_data;
  double *ptCloud_data;
  double *r1;
  double *x_data;
  double *y_data;
  double *z_data;
  int b_loop_ub;
  int boffset;
  int c_loop_ub;
  int coffset;
  int count;
  int d_loop_ub;
  int e_loop_ub;
  int i;
  int ii;
  int iindx;
  int inner;
  int j;
  int jj;
  int k;
  int loop_ub;
  int m;
  int n;
  boolean_T exitg1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Point_in_data = Point_in->data;
  emxInit_real_T(&x, 1);
  loop_ub = Point_in->size[1];
  coffset = x->size[0];
  x->size[0] = Point_in->size[1];
  emxEnsureCapacity_real_T(x, coffset);
  x_data = x->data;
  for (coffset = 0; coffset < loop_ub; coffset++) {
    x_data[coffset] = Point_in_data[3 * coffset];
  }
  emxInit_real_T(&y, 1);
  loop_ub = Point_in->size[1];
  coffset = y->size[0];
  y->size[0] = Point_in->size[1];
  emxEnsureCapacity_real_T(y, coffset);
  y_data = y->data;
  for (coffset = 0; coffset < loop_ub; coffset++) {
    y_data[coffset] = Point_in_data[3 * coffset + 1];
  }
  emxInit_real_T(&z, 1);
  loop_ub = Point_in->size[1];
  coffset = z->size[0];
  z->size[0] = Point_in->size[1];
  emxEnsureCapacity_real_T(z, coffset);
  z_data = z->data;
  for (coffset = 0; coffset < loop_ub; coffset++) {
    z_data[coffset] = Point_in_data[3 * coffset + 2];
  }
  emxInit_real_T(&ptCloud, 2);
  coffset = ptCloud->size[0] * ptCloud->size[1];
  ptCloud->size[0] = x->size[0];
  ptCloud->size[1] = 3;
  emxEnsureCapacity_real_T(ptCloud, coffset);
  ptCloud_data = ptCloud->data;
  loop_ub = x->size[0];
  for (coffset = 0; coffset < loop_ub; coffset++) {
    ptCloud_data[coffset] = x_data[coffset];
  }
  loop_ub = y->size[0];
  for (coffset = 0; coffset < loop_ub; coffset++) {
    ptCloud_data[coffset + ptCloud->size[0]] = y_data[coffset];
  }
  loop_ub = z->size[0];
  for (coffset = 0; coffset < loop_ub; coffset++) {
    ptCloud_data[coffset + ptCloud->size[0] * 2] = z_data[coffset];
  }
  n = x->size[0];
  /* -----------------------------计算点云法向量----------------------------- */
  linspace(elevation - 0.17453292519943295, elevation + 0.17453292519943295,
           dv);
  linspace(-elevation - 0.17453292519943295, -elevation + 0.17453292519943295,
           dv1);
  for (coffset = 0; coffset < 90; coffset++) {
    mm[coffset] = dv[coffset];
    mm[coffset + 90] = dv1[coffset];
  }
  linspace(azimuth - 0.17453292519943295, azimuth + 0.17453292519943295, dv);
  linspace(-azimuth - 0.17453292519943295, -azimuth + 0.17453292519943295, dv1);
  for (coffset = 0; coffset < 90; coffset++) {
    nn[coffset] = dv[coffset];
    nn[coffset + 90] = dv1[coffset];
  }
  emxInit_real_T(&YuanDu, 2);
  emxInit_real_T(&Xnn, 2);
  Xnn_data = Xnn->data;
  /*  mm = linspace(0,2*pi,240); */
  /*  nn = linspace(0,2*pi,240); */
  YuanDu->size[0] = 1;
  YuanDu->size[1] = 0;
  Xnn->size[0] = 7;
  Xnn->size[1] = 0;
  m = ptCloud->size[0];
  loop_ub = x->size[0] * 3;
  b_loop_ub = ptCloud->size[0];
  c_loop_ub = x->size[0] * 7;
  d_loop_ub = x->size[0];
  emxInit_real_T(&circleCloud, 2);
  emxInit_real_T(&B, 2);
  emxInit_real_T(&L, 1);
  emxInit_real_T(&Bn, 2);
  emxInit_real_T(&dis, 2);
  emxInit_real_T(&r, 1);
  emxInit_real_T(&b_ptCloud, 1);
  for (ii = 0; ii < 180; ii++) {
    b_ii = mm[ii];
    for (jj = 0; jj < 180; jj++) {
      /*  rot1旋转矩阵 */
      t = nn[jj];
      cang[0] = cos(b_ii);
      angles[0] = sin(b_ii);
      cang[1] = cos(t);
      angles[1] = sin(t);
      rot1[0] = cang[1];
      rot1[3] = angles[0] * angles[1] + cang[0] * 0.0;
      rot1[6] = -cang[0] * angles[1] + angles[0] * 0.0;
      rot1[1] = -cang[1] * 0.0;
      rot1[4] = -angles[0] * angles[1] * 0.0 + cang[0];
      rot1[7] = cang[0] * angles[1] * 0.0 + angles[0];
      rot1[2] = angles[1];
      rot1[5] = -angles[0] * cang[1];
      rot1[8] = cang[0] * cang[1];
      for (coffset = 0; coffset < 3; coffset++) {
        ttt[coffset] = (0.0 * rot1[3 * coffset] + 0.0 * rot1[3 * coffset + 1]) +
                       rot1[3 * coffset + 2];
      }
      a0 = ttt[0];
      b0 = ttt[1];
      c0 = ttt[2];
      /*  rot2 旋转矩阵 */
      cang[0] = cos(-b_ii);
      angles[0] = sin(-b_ii);
      cang[1] = cos(-t);
      angles[1] = sin(-t);
      rot2[0] = cang[1];
      rot2[3] = angles[0] * angles[1] + cang[0] * 0.0;
      rot2[6] = -cang[0] * angles[1] + angles[0] * 0.0;
      rot2[1] = -cang[1] * 0.0;
      rot2[4] = -angles[0] * angles[1] * 0.0 + cang[0];
      rot2[7] = cang[0] * angles[1] * 0.0 + angles[0];
      rot2[2] = angles[1];
      rot2[5] = -angles[0] * cang[1];
      rot2[8] = cang[0] * cang[1];
      coffset = circleCloud->size[0] * circleCloud->size[1];
      circleCloud->size[0] = ptCloud->size[0];
      circleCloud->size[1] = 3;
      emxEnsureCapacity_real_T(circleCloud, coffset);
      Xnn_data = circleCloud->data;
      for (j = 0; j < 3; j++) {
        coffset = j * m;
        boffset = j * 3;
        for (i = 0; i < m; i++) {
          Xnn_data[coffset + i] =
              (ptCloud_data[i] * rot2[boffset] +
               ptCloud_data[ptCloud->size[0] + i] * rot2[boffset + 1]) +
              ptCloud_data[(ptCloud->size[0] << 1) + i] * rot2[boffset + 2];
        }
      }
      /* --------------------------初始化矩阵系数--------------------------------
       */
      coffset = B->size[0] * B->size[1];
      B->size[0] = n;
      B->size[1] = 3;
      emxEnsureCapacity_real_T(B, coffset);
      B_data = B->data;
      for (coffset = 0; coffset < loop_ub; coffset++) {
        B_data[coffset] = 1.0;
      }
      coffset = L->size[0];
      L->size[0] = n;
      emxEnsureCapacity_real_T(L, coffset);
      L_data = L->data;
      for (coffset = 0; coffset < n; coffset++) {
        L_data[coffset] = 0.0;
      }
      /*  系数矩阵L */
      /*  赋值 */
      e_loop_ub = circleCloud->size[0];
      for (coffset = 0; coffset < e_loop_ub; coffset++) {
        B_data[coffset] = Xnn_data[coffset] * 2.0;
      }
      e_loop_ub = circleCloud->size[0];
      for (coffset = 0; coffset < e_loop_ub; coffset++) {
        B_data[coffset + B->size[0]] =
            Xnn_data[coffset + circleCloud->size[0]] * 2.0;
      }
      e_loop_ub = circleCloud->size[0];
      coffset = b_ptCloud->size[0];
      b_ptCloud->size[0] = circleCloud->size[0];
      emxEnsureCapacity_real_T(b_ptCloud, coffset);
      b_ptCloud_data = b_ptCloud->data;
      for (coffset = 0; coffset < e_loop_ub; coffset++) {
        bkj = Xnn_data[coffset];
        b_ptCloud_data[coffset] = bkj * bkj;
      }
      e_loop_ub = circleCloud->size[0];
      coffset = r->size[0];
      r->size[0] = circleCloud->size[0];
      emxEnsureCapacity_real_T(r, coffset);
      r1 = r->data;
      for (coffset = 0; coffset < e_loop_ub; coffset++) {
        bkj = Xnn_data[coffset + circleCloud->size[0]];
        r1[coffset] = bkj * bkj;
      }
      if (b_ptCloud->size[0] == r->size[0]) {
        e_loop_ub = b_ptCloud->size[0];
        for (coffset = 0; coffset < e_loop_ub; coffset++) {
          L_data[coffset] = b_ptCloud_data[coffset] + r1[coffset];
        }
      } else {
        binary_expand_op(L, b_ptCloud, r);
        L_data = L->data;
      }
      /*  间接平差求解 */
      /*  参数求解 */
      inner = B->size[0];
      e_loop_ub = B->size[0];
      for (j = 0; j < 3; j++) {
        coffset = j * 3;
        boffset = j * B->size[0];
        C[coffset] = 0.0;
        C[coffset + 1] = 0.0;
        C[coffset + 2] = 0.0;
        for (k = 0; k < inner; k++) {
          bkj = B_data[boffset + k];
          C[coffset] += B_data[k] * bkj;
          C[coffset + 1] += B_data[B->size[0] + k] * bkj;
          C[coffset + 2] += B_data[(B->size[0] << 1) + k] * bkj;
        }
        angles[j] = 0.0;
      }
      for (k = 0; k < e_loop_ub; k++) {
        angles[0] += B_data[k] * L_data[k];
        angles[1] += B_data[B->size[0] + k] * L_data[k];
        angles[2] += B_data[(B->size[0] << 1) + k] * L_data[k];
      }
      mldivide(C, angles, cang);
      r0 = sqrt((cang[0] * cang[0] + cang[1] * cang[1]) + cang[2]);
      cang_idx_0 = cang[0];
      cang_idx_1 = cang[1];
      for (coffset = 0; coffset < 3; coffset++) {
        angles[coffset] = (cang_idx_0 * rot2[3 * coffset] +
                           cang_idx_1 * rot2[3 * coffset + 1]) +
                          0.0 * rot2[3 * coffset + 2];
      }
      /*  旋转矩阵的逆与转置相等 */
      x1 = angles[0];
      b_y1 = angles[1];
      coffset = L->size[0];
      L->size[0] = b_loop_ub;
      emxEnsureCapacity_real_T(L, coffset);
      L_data = L->data;
      coffset = b_ptCloud->size[0];
      b_ptCloud->size[0] = ptCloud->size[0];
      emxEnsureCapacity_real_T(b_ptCloud, coffset);
      b_ptCloud_data = b_ptCloud->data;
      for (coffset = 0; coffset < b_loop_ub; coffset++) {
        t = ptCloud_data[coffset + ptCloud->size[0] * 2];
        L_data[coffset] = t;
        b_ptCloud_data[coffset] = t;
      }
      /*  计算点云z坐标最值 */
      bkj = (minimum(L) + maximum(b_ptCloud)) * 0.5;
      /* ------------------------------最小二乘迭代---------------------------
       */
      coffset = Bn->size[0] * Bn->size[1];
      Bn->size[0] = n;
      Bn->size[1] = 7;
      emxEnsureCapacity_real_T(Bn, coffset);
      B_data = Bn->data;
      for (coffset = 0; coffset < c_loop_ub; coffset++) {
        B_data[coffset] = 1.0;
      }
      coffset = L->size[0];
      L->size[0] = n;
      emxEnsureCapacity_real_T(L, coffset);
      L_data = L->data;
      for (coffset = 0; coffset < n; coffset++) {
        L_data[coffset] = 1.0;
      }
      Xn[0] = angles[0];
      Xn[1] = angles[1];
      Xn[2] = bkj;
      Xn[3] = ttt[0];
      Xn[4] = ttt[1];
      Xn[5] = ttt[2];
      Xn[6] = r0;
      count = 1;
      exitg1 = false;
      while ((!exitg1) && (r0 > 0.0001)) {
        for (i = 0; i < n; i++) {
          scale = x_data[i] - x1;
          b_scale = y_data[i] - b_y1;
          absxk = z_data[i] - bkj;
          t = (a0 * scale + b0 * b_scale) + c0 * absxk;
          B_data[i] = (2.0 * x1 - x_data[i] * 2.0) + 2.0 * a0 * t;
          e_loop_ub = Bn->size[0];
          for (coffset = 0; coffset < e_loop_ub; coffset++) {
            B_data[coffset + Bn->size[0]] =
                (2.0 * b_y1 - 2.0 * y_data[i]) + 2.0 * b0 * t;
          }
          B_data[i + Bn->size[0] * 2] =
              (2.0 * bkj - 2.0 * z_data[i]) + 2.0 * c0 * t;
          B_data[i + Bn->size[0] * 3] = -2.0 * scale * t;
          B_data[i + Bn->size[0] * 4] = -2.0 * b_scale * t;
          B_data[i + Bn->size[0] * 5] = -2.0 * absxk * t;
          B_data[i + Bn->size[0] * 6] = -2.0 * r0;
          L_data[i] = -(
              (((scale * scale + b_scale * b_scale) + absxk * absxk) - t * t) -
              r0 * r0);
        }
        /*  间接平差求解 */
        inner = Bn->size[0];
        for (j = 0; j < 7; j++) {
          coffset = j * 7;
          boffset = j * Bn->size[0];
          for (i = 0; i < 7; i++) {
            b_C[coffset + i] = 0.0;
          }
          for (k = 0; k < inner; k++) {
            bkj = B_data[boffset + k];
            for (i = 0; i < 7; i++) {
              e_loop_ub = coffset + i;
              b_C[e_loop_ub] += B_data[i * Bn->size[0] + k] * bkj;
            }
          }
        }
        pinv(b_C, a);
        inner = Bn->size[0];
        for (i = 0; i < 7; i++) {
          c_C[i] = 0.0;
        }
        for (k = 0; k < inner; k++) {
          for (i = 0; i < 7; i++) {
            c_C[i] += B_data[i * Bn->size[0] + k] * L_data[k];
          }
        }
        for (coffset = 0; coffset < 7; coffset++) {
          t = 0.0;
          for (e_loop_ub = 0; e_loop_ub < 7; e_loop_ub++) {
            t += a[coffset + 7 * e_loop_ub] * c_C[e_loop_ub];
          }
          deltX[coffset] = t;
          Xn[coffset] += t;
        }
        /*  获取迭代增量 */
        x1 = deltX[0];
        b_y1 = deltX[1];
        bkj = deltX[2];
        a0 = deltX[3];
        b0 = deltX[4];
        c0 = deltX[5];
        r0 = deltX[6];
        count++;
        /* 迭代次数足够多，跳出迭代。 */
        if (count >= 100) {
          exitg1 = true;
        }
      }
      /*  列出所有参数 */
      /* 圆心 */
      /* 法向量 */
      /* 半径 */
      /*  计算两个中心点u1、u2 */
      /* ------------------------------ 圆度计算 --------------------------- */
      /*  计算测点到轴线距离 */
      coffset = dis->size[0] * dis->size[1];
      dis->size[0] = 1;
      dis->size[1] = x->size[0];
      emxEnsureCapacity_real_T(dis, coffset);
      B_data = dis->data;
      if (d_loop_ub - 1 >= 0) {
        cang[0] = (Xn[0] - 2.0 * Xn[3]) - Xn[0];
        cang[1] = (Xn[1] - 2.0 * Xn[4]) - Xn[1];
        cang[2] = (Xn[2] - 2.0 * Xn[5]) - Xn[2];
      }
      for (j = 0; j < d_loop_ub; j++) {
        cang_idx_0 = x_data[j] - Xn[0];
        cang_idx_1 = y_data[j] - Xn[1];
        bkj = z_data[j] - Xn[2];
        scale = 3.3121686421112381E-170;
        b_scale = 3.3121686421112381E-170;
        absxk = fabs(cang_idx_1 * cang[2] - cang[1] * bkj);
        if (absxk > 3.3121686421112381E-170) {
          x1 = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          x1 = t * t;
        }
        absxk = fabs(cang[0]);
        if (absxk > 3.3121686421112381E-170) {
          b_y1 = 1.0;
          b_scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          b_y1 = t * t;
        }
        absxk = fabs(cang[0] * bkj - cang_idx_0 * cang[2]);
        if (absxk > scale) {
          t = scale / absxk;
          x1 = x1 * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          x1 += t * t;
        }
        absxk = fabs(cang[1]);
        if (absxk > b_scale) {
          t = b_scale / absxk;
          b_y1 = b_y1 * t * t + 1.0;
          b_scale = absxk;
        } else {
          t = absxk / b_scale;
          b_y1 += t * t;
        }
        absxk = fabs(cang_idx_0 * cang[1] - cang[0] * cang_idx_1);
        if (absxk > scale) {
          t = scale / absxk;
          x1 = x1 * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          x1 += t * t;
        }
        absxk = fabs(cang[2]);
        if (absxk > b_scale) {
          t = b_scale / absxk;
          b_y1 = b_y1 * t * t + 1.0;
          b_scale = absxk;
        } else {
          t = absxk / b_scale;
          b_y1 += t * t;
        }
        x1 = scale * sqrt(x1);
        b_y1 = b_scale * sqrt(b_y1);
        B_data[j] = x1 / b_y1;
      }
      /*  比较与半径的差值（圆度） */
      /*  单个点误差 */
      coffset = dis->size[0] * dis->size[1];
      dis->size[0] = 1;
      emxEnsureCapacity_real_T(dis, coffset);
      B_data = dis->data;
      e_loop_ub = dis->size[1] - 1;
      for (coffset = 0; coffset <= e_loop_ub; coffset++) {
        bkj = B_data[coffset] - Xn[6];
        B_data[coffset] = bkj * bkj;
      }
      coffset = YuanDu->size[1];
      e_loop_ub = YuanDu->size[0] * YuanDu->size[1];
      YuanDu->size[0] = 1;
      YuanDu->size[1]++;
      emxEnsureCapacity_real_T(YuanDu, e_loop_ub);
      B_data = YuanDu->data;
      B_data[coffset] = mean(dis);
      /*  总体圆度 */
      coffset = Xnn->size[1];
      e_loop_ub = Xnn->size[0] * Xnn->size[1];
      Xnn->size[0] = 7;
      Xnn->size[1]++;
      emxEnsureCapacity_real_T(Xnn, e_loop_ub);
      Xnn_data = Xnn->data;
      for (e_loop_ub = 0; e_loop_ub < 7; e_loop_ub++) {
        Xnn_data[e_loop_ub + 7 * coffset] = Xn[e_loop_ub];
      }
    }
  }
  emxFree_real_T(&b_ptCloud);
  emxFree_real_T(&r);
  emxFree_real_T(&dis);
  emxFree_real_T(&Bn);
  emxFree_real_T(&L);
  emxFree_real_T(&B);
  emxFree_real_T(&circleCloud);
  emxFree_real_T(&ptCloud);
  b_minimum(YuanDu, &bkj, &e_loop_ub);
  /*  列出所有参数 */
  /* 圆心 */
  /* 法向量 */
  coffset = 7 * (e_loop_ub - 1);
  t = b_norm(*(double(*)[3]) & (*(double(*)[7]) & Xnn_data[coffset])[3]);
  r0 = Xnn_data[coffset + 6];
  /* 半径 */
  bkj = Xnn_data[coffset];
  Mcenter[0] = bkj;
  absxk = Xnn_data[coffset + 3] / t;
  MTaon[0] = absxk;
  angles[0] = bkj - 2.0 * absxk;
  scale = Xnn_data[coffset + 1];
  Mcenter[1] = scale;
  absxk = Xnn_data[coffset + 4] / t;
  MTaon[1] = absxk;
  angles[1] = scale - 2.0 * absxk;
  b_scale = Xnn_data[coffset + 2];
  Mcenter[2] = b_scale;
  absxk = Xnn_data[coffset + 5] / t;
  MTaon[2] = absxk;
  angles[2] = b_scale - 2.0 * absxk;
  coffset = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = x->size[0];
  emxEnsureCapacity_real_T(Err_every, coffset);
  B_data = Err_every->data;
  loop_ub = x->size[0];
  emxFree_real_T(&YuanDu);
  for (coffset = 0; coffset < loop_ub; coffset++) {
    B_data[coffset] = 0.0;
  }
  coffset = x->size[0];
  if (x->size[0] - 1 >= 0) {
    cang[0] = angles[0] - bkj;
    cang[1] = angles[1] - scale;
    cang[2] = angles[2] - b_scale;
    iindx = e_loop_ub;
  }
  for (j = 0; j < coffset; j++) {
    cang_idx_0 = x_data[j] - Xnn_data[7 * (iindx - 1)];
    cang_idx_1 = y_data[j] - Xnn_data[7 * (iindx - 1) + 1];
    bkj = z_data[j] - Xnn_data[7 * (iindx - 1) + 2];
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    absxk = fabs(cang_idx_1 * cang[2] - cang[1] * bkj);
    if (absxk > 3.3121686421112381E-170) {
      x1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x1 = t * t;
    }
    absxk = fabs(cang[0]);
    if (absxk > 3.3121686421112381E-170) {
      b_y1 = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y1 = t * t;
    }
    absxk = fabs(cang[0] * bkj - cang_idx_0 * cang[2]);
    if (absxk > scale) {
      t = scale / absxk;
      x1 = x1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x1 += t * t;
    }
    absxk = fabs(cang[1]);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y1 = b_y1 * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y1 += t * t;
    }
    absxk = fabs(cang_idx_0 * cang[1] - cang[0] * cang_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      x1 = x1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x1 += t * t;
    }
    absxk = fabs(cang[2]);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y1 = b_y1 * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y1 += t * t;
    }
    x1 = scale * sqrt(x1);
    b_y1 = b_scale * sqrt(b_y1);
    B_data[j] = x1 / b_y1;
  }
  emxFree_real_T(&z);
  emxFree_real_T(&y);
  emxFree_real_T(&x);
  /*  比较与半径的差值（圆度） */
  coffset = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  emxEnsureCapacity_real_T(Err_every, coffset);
  B_data = Err_every->data;
  loop_ub = Err_every->size[1] - 1;
  for (coffset = 0; coffset <= loop_ub; coffset++) {
    B_data[coffset] -= r0;
  }
  /*  单个点误差 */
  foot_of_perpendicular_from_a_point_to_a_line(
      P_bound1,
      *(double(*)[3]) & (*(double(*)[7]) & Xnn_data[7 * (e_loop_ub - 1)])[0],
      angles, &bkj, &absxk, &scale);
  foot_of_perpendicular_from_a_point_to_a_line(
      P_bound2,
      *(double(*)[3]) & (*(double(*)[7]) & Xnn_data[7 * (e_loop_ub - 1)])[0],
      angles, &b_scale, &t, &x1);
  Bottom_round_center1[0] = bkj;
  Bottom_round_center1[1] = absxk;
  Bottom_round_center1[2] = scale;
  Bottom_round_center2[0] = b_scale;
  Bottom_round_center2[1] = t;
  Bottom_round_center2[2] = x1;
  *Mradial = r0;
  emxFree_real_T(&Xnn);
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * [EOF]
 */
