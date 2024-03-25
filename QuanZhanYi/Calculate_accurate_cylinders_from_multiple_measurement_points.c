/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2024 00:13:40
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const emxArray_real_T *z
 *                double Mcenter[3]
 *                double MTaon[3]
 *                double *Mradial
 *                emxArray_real_T *Err_every
 * Return Type  : void
 */
void Calculate_accurate_cylinders_from_multiple_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every)
{
  emxArray_real_T *B;
  emxArray_real_T *Bn;
  emxArray_real_T *L;
  emxArray_real_T *Xnn;
  emxArray_real_T *YuanDu;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *circleCloud;
  emxArray_real_T *d_y;
  emxArray_real_T *dis;
  emxArray_real_T *ptCloud;
  double mm[180];
  double a[49];
  double b_C[49];
  double C[9];
  double rot1[9];
  double rot2[9];
  double Xn[7];
  double c_C[7];
  double deltX[7];
  double angles[3];
  double dv[3];
  double ttt[3];
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
  int b_loop_ub;
  int boffset;
  int c_loop_ub;
  int coffset;
  int count;
  int d_loop_ub;
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
  int nx;
  boolean_T exitg1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInit_real_T(&ptCloud, 2);
  boffset = ptCloud->size[0] * ptCloud->size[1];
  ptCloud->size[0] = x->size[0];
  ptCloud->size[1] = 3;
  emxEnsureCapacity_real_T(ptCloud, boffset);
  loop_ub = x->size[0];
  for (boffset = 0; boffset < loop_ub; boffset++) {
    ptCloud->data[boffset] = x->data[boffset];
  }
  loop_ub = y->size[0];
  for (boffset = 0; boffset < loop_ub; boffset++) {
    ptCloud->data[boffset + ptCloud->size[0]] = y->data[boffset];
  }
  loop_ub = z->size[0];
  for (boffset = 0; boffset < loop_ub; boffset++) {
    ptCloud->data[boffset + ptCloud->size[0] * 2] = z->data[boffset];
  }
  n = x->size[0];
  /* -----------------------------计算点云法向量----------------------------- */
  mm[179] = 6.2831853071795862;
  mm[0] = 0.0;
  for (k = 0; k < 178; k++) {
    mm[k + 1] = ((double)k + 1.0) * 0.035101593894858021;
  }
  emxInit_real_T(&YuanDu, 2);
  emxInit_real_T(&Xnn, 2);
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
  emxInit_real_T(&b_y, 1);
  emxInit_real_T(&c_y, 1);
  emxInit_real_T(&d_y, 2);
  for (ii = 0; ii < 180; ii++) {
    b_ii = mm[ii];
    for (jj = 0; jj < 180; jj++) {
      /*  rot1旋转矩阵 */
      bkj = mm[jj];
      cang_idx_0 = cos(b_ii);
      angles[0] = sin(b_ii);
      cang_idx_1 = cos(bkj);
      angles[1] = sin(bkj);
      rot1[0] = cang_idx_1;
      rot1[3] = angles[0] * angles[1] + cang_idx_0 * 0.0;
      rot1[6] = -cang_idx_0 * angles[1] + angles[0] * 0.0;
      rot1[1] = -cang_idx_1 * 0.0;
      rot1[4] = -angles[0] * angles[1] * 0.0 + cang_idx_0;
      rot1[7] = cang_idx_0 * angles[1] * 0.0 + angles[0];
      rot1[2] = angles[1];
      rot1[5] = -angles[0] * cang_idx_1;
      rot1[8] = cang_idx_0 * cang_idx_1;
      for (boffset = 0; boffset < 3; boffset++) {
        ttt[boffset] = rot1[3 * boffset + 2];
      }
      a0 = ttt[0];
      b0 = ttt[1];
      c0 = ttt[2];
      /*  rot2 旋转矩阵 */
      cang_idx_0 = cos(-b_ii);
      angles[0] = sin(-b_ii);
      cang_idx_1 = cos(-bkj);
      angles[1] = sin(-bkj);
      rot2[0] = cang_idx_1;
      rot2[3] = angles[0] * angles[1] + cang_idx_0 * 0.0;
      rot2[6] = -cang_idx_0 * angles[1] + angles[0] * 0.0;
      rot2[1] = -cang_idx_1 * 0.0;
      rot2[4] = -angles[0] * angles[1] * 0.0 + cang_idx_0;
      rot2[7] = cang_idx_0 * angles[1] * 0.0 + angles[0];
      rot2[2] = angles[1];
      rot2[5] = -angles[0] * cang_idx_1;
      rot2[8] = cang_idx_0 * cang_idx_1;
      boffset = circleCloud->size[0] * circleCloud->size[1];
      circleCloud->size[0] = ptCloud->size[0];
      circleCloud->size[1] = 3;
      emxEnsureCapacity_real_T(circleCloud, boffset);
      for (j = 0; j < 3; j++) {
        coffset = j * m;
        boffset = j * 3;
        for (i = 0; i < m; i++) {
          circleCloud->data[coffset + i] =
              (ptCloud->data[i] * rot2[boffset] +
               ptCloud->data[ptCloud->size[0] + i] * rot2[boffset + 1]) +
              ptCloud->data[(ptCloud->size[0] << 1) + i] * rot2[boffset + 2];
        }
      }
      /* --------------------------初始化矩阵系数--------------------------------
       */
      boffset = B->size[0] * B->size[1];
      B->size[0] = n;
      B->size[1] = 3;
      emxEnsureCapacity_real_T(B, boffset);
      for (boffset = 0; boffset < loop_ub; boffset++) {
        B->data[boffset] = 1.0;
      }
      boffset = L->size[0];
      L->size[0] = n;
      emxEnsureCapacity_real_T(L, boffset);
      for (boffset = 0; boffset < n; boffset++) {
        L->data[boffset] = 0.0;
      }
      /*  系数矩阵L */
      /*  赋值 */
      coffset = circleCloud->size[0];
      for (boffset = 0; boffset < coffset; boffset++) {
        B->data[boffset] = circleCloud->data[boffset] * 2.0;
      }
      coffset = circleCloud->size[0];
      for (boffset = 0; boffset < coffset; boffset++) {
        B->data[boffset + B->size[0]] =
            circleCloud->data[boffset + circleCloud->size[0]] * 2.0;
      }
      boffset = b_y->size[0];
      b_y->size[0] = circleCloud->size[0];
      emxEnsureCapacity_real_T(b_y, boffset);
      nx = circleCloud->size[0];
      for (k = 0; k < nx; k++) {
        bkj = circleCloud->data[k];
        b_y->data[k] = bkj * bkj;
      }
      boffset = c_y->size[0];
      c_y->size[0] = circleCloud->size[0];
      emxEnsureCapacity_real_T(c_y, boffset);
      nx = circleCloud->size[0];
      for (k = 0; k < nx; k++) {
        bkj = circleCloud->data[k + circleCloud->size[0]];
        c_y->data[k] = bkj * bkj;
      }
      coffset = b_y->size[0];
      for (boffset = 0; boffset < coffset; boffset++) {
        L->data[boffset] = b_y->data[boffset] + c_y->data[boffset];
      }
      /*  间接平差求解 */
      /*  参数求解 */
      inner = B->size[0];
      nx = B->size[0];
      for (j = 0; j < 3; j++) {
        coffset = j * 3;
        boffset = j * B->size[0];
        C[coffset] = 0.0;
        C[coffset + 1] = 0.0;
        C[coffset + 2] = 0.0;
        for (k = 0; k < inner; k++) {
          bkj = B->data[boffset + k];
          C[coffset] += B->data[k] * bkj;
          C[coffset + 1] += B->data[B->size[0] + k] * bkj;
          C[coffset + 2] += B->data[(B->size[0] << 1) + k] * bkj;
        }
        angles[j] = 0.0;
      }
      for (k = 0; k < nx; k++) {
        angles[0] += B->data[k] * L->data[k];
        angles[1] += B->data[B->size[0] + k] * L->data[k];
        angles[2] += B->data[(B->size[0] << 1) + k] * L->data[k];
      }
      mldivide(C, angles, dv);
      cang_idx_0 = dv[0];
      cang_idx_1 = dv[1];
      r0 = sqrt((dv[0] * dv[0] + dv[1] * dv[1]) + dv[2]);
      for (boffset = 0; boffset < 3; boffset++) {
        angles[boffset] = (cang_idx_0 * rot2[3 * boffset] +
                           cang_idx_1 * rot2[3 * boffset + 1]) +
                          0.0 * rot2[3 * boffset + 2];
      }
      /*  旋转矩阵的逆与转置相等 */
      x1 = angles[0];
      b_y1 = angles[1];
      boffset = L->size[0];
      L->size[0] = b_loop_ub;
      emxEnsureCapacity_real_T(L, boffset);
      boffset = b_y->size[0];
      b_y->size[0] = ptCloud->size[0];
      emxEnsureCapacity_real_T(b_y, boffset);
      for (boffset = 0; boffset < b_loop_ub; boffset++) {
        bkj = ptCloud->data[boffset + ptCloud->size[0] * 2];
        L->data[boffset] = bkj;
        b_y->data[boffset] = bkj;
      }
      /*  计算点云z坐标最值 */
      bkj = (minimum(L) + maximum(b_y)) * 0.5;
      /* ------------------------------最小二乘迭代---------------------------
       */
      boffset = Bn->size[0] * Bn->size[1];
      Bn->size[0] = n;
      Bn->size[1] = 7;
      emxEnsureCapacity_real_T(Bn, boffset);
      for (boffset = 0; boffset < c_loop_ub; boffset++) {
        Bn->data[boffset] = 1.0;
      }
      boffset = L->size[0];
      L->size[0] = n;
      emxEnsureCapacity_real_T(L, boffset);
      for (boffset = 0; boffset < n; boffset++) {
        L->data[boffset] = 1.0;
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
          scale = x->data[i] - x1;
          b_scale = y->data[i] - b_y1;
          absxk = z->data[i] - bkj;
          t = (a0 * scale + b0 * b_scale) + c0 * absxk;
          Bn->data[i] = (2.0 * x1 - x->data[i] * 2.0) + 2.0 * a0 * t;
          coffset = Bn->size[0];
          for (boffset = 0; boffset < coffset; boffset++) {
            Bn->data[boffset + Bn->size[0]] =
                (2.0 * b_y1 - 2.0 * y->data[i]) + 2.0 * b0 * t;
          }
          Bn->data[i + Bn->size[0] * 2] =
              (2.0 * bkj - 2.0 * z->data[i]) + 2.0 * c0 * t;
          Bn->data[i + Bn->size[0] * 3] = -2.0 * scale * t;
          Bn->data[i + Bn->size[0] * 4] = -2.0 * b_scale * t;
          Bn->data[i + Bn->size[0] * 5] = -2.0 * absxk * t;
          Bn->data[i + Bn->size[0] * 6] = -2.0 * r0;
          L->data[i] = -(
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
            bkj = Bn->data[boffset + k];
            for (i = 0; i < 7; i++) {
              nx = coffset + i;
              b_C[nx] += Bn->data[i * Bn->size[0] + k] * bkj;
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
            c_C[i] += Bn->data[i * Bn->size[0] + k] * L->data[k];
          }
        }
        for (boffset = 0; boffset < 7; boffset++) {
          bkj = 0.0;
          for (nx = 0; nx < 7; nx++) {
            bkj += a[boffset + 7 * nx] * c_C[nx];
          }
          deltX[boffset] = bkj;
          Xn[boffset] += bkj;
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
      /* ------------------------------可视化对比--------------------------- */
      /*  列出所有参数 */
      /* 圆心 */
      /* 法向量 */
      /* 半径 */
      /*  计算两个中心点u1、u2 */
      /* ------------------------------ 圆度计算 --------------------------- */
      /*  计算测点到轴线距离 */
      boffset = dis->size[0] * dis->size[1];
      dis->size[0] = 1;
      dis->size[1] = x->size[0];
      emxEnsureCapacity_real_T(dis, boffset);
      if (0 <= d_loop_ub - 1) {
        ttt[0] = (Xn[0] - 2.0 * Xn[3]) - Xn[0];
        ttt[1] = (Xn[1] - 2.0 * Xn[4]) - Xn[1];
        ttt[2] = (Xn[2] - 2.0 * Xn[5]) - Xn[2];
      }
      for (j = 0; j < d_loop_ub; j++) {
        cang_idx_0 = x->data[j] - Xn[0];
        cang_idx_1 = y->data[j] - Xn[1];
        bkj = z->data[j] - Xn[2];
        scale = 3.3121686421112381E-170;
        b_scale = 3.3121686421112381E-170;
        absxk = fabs(cang_idx_1 * ttt[2] - ttt[1] * bkj);
        if (absxk > 3.3121686421112381E-170) {
          x1 = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          x1 = t * t;
        }
        absxk = fabs(ttt[0]);
        if (absxk > 3.3121686421112381E-170) {
          b_y1 = 1.0;
          b_scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          b_y1 = t * t;
        }
        absxk = fabs(ttt[0] * bkj - cang_idx_0 * ttt[2]);
        if (absxk > scale) {
          t = scale / absxk;
          x1 = x1 * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          x1 += t * t;
        }
        absxk = fabs(ttt[1]);
        if (absxk > b_scale) {
          t = b_scale / absxk;
          b_y1 = b_y1 * t * t + 1.0;
          b_scale = absxk;
        } else {
          t = absxk / b_scale;
          b_y1 += t * t;
        }
        absxk = fabs(cang_idx_0 * ttt[1] - ttt[0] * cang_idx_1);
        if (absxk > scale) {
          t = scale / absxk;
          x1 = x1 * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          x1 += t * t;
        }
        absxk = fabs(ttt[2]);
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
        dis->data[j] = x1 / b_y1;
      }
      /*  比较与半径的差值（圆度） */
      /*  单个点误差 */
      boffset = dis->size[0] * dis->size[1];
      dis->size[0] = 1;
      emxEnsureCapacity_real_T(dis, boffset);
      coffset = dis->size[1] - 1;
      for (boffset = 0; boffset <= coffset; boffset++) {
        dis->data[boffset] -= Xn[6];
      }
      boffset = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = dis->size[1];
      emxEnsureCapacity_real_T(d_y, boffset);
      nx = dis->size[1];
      for (k = 0; k < nx; k++) {
        bkj = dis->data[k];
        d_y->data[k] = bkj * bkj;
      }
      boffset = YuanDu->size[1];
      nx = YuanDu->size[0] * YuanDu->size[1];
      YuanDu->size[0] = 1;
      YuanDu->size[1]++;
      emxEnsureCapacity_real_T(YuanDu, nx);
      YuanDu->data[boffset] = mean(d_y);
      /*  总体圆度 */
      boffset = Xnn->size[1];
      nx = Xnn->size[0] * Xnn->size[1];
      Xnn->size[0] = 7;
      Xnn->size[1]++;
      emxEnsureCapacity_real_T(Xnn, nx);
      for (nx = 0; nx < 7; nx++) {
        Xnn->data[nx + 7 * boffset] = Xn[nx];
      }
    }
  }
  emxFree_real_T(&d_y);
  emxFree_real_T(&c_y);
  emxFree_real_T(&b_y);
  emxFree_real_T(&dis);
  emxFree_real_T(&Bn);
  emxFree_real_T(&L);
  emxFree_real_T(&B);
  emxFree_real_T(&circleCloud);
  emxFree_real_T(&ptCloud);
  b_minimum(YuanDu, &bkj, &coffset);
  /* ------------------------------可视化对比--------------------------- */
  /*  列出所有参数 */
  /* 圆心 */
  /* 法向量 */
  nx = 7 * (coffset - 1);
  r0 = Xnn->data[nx + 6];
  /* 半径 */
  bkj = Xnn->data[nx];
  Mcenter[0] = bkj;
  scale = Xnn->data[nx + 3];
  MTaon[0] = scale;
  b_scale = Xnn->data[nx + 1];
  Mcenter[1] = b_scale;
  absxk = Xnn->data[nx + 4];
  MTaon[1] = absxk;
  t = Xnn->data[nx + 2];
  Mcenter[2] = t;
  x1 = Xnn->data[nx + 5];
  MTaon[2] = x1;
  boffset = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = x->size[0];
  emxEnsureCapacity_real_T(Err_every, boffset);
  loop_ub = x->size[0];
  emxFree_real_T(&YuanDu);
  for (boffset = 0; boffset < loop_ub; boffset++) {
    Err_every->data[boffset] = 0.0;
  }
  boffset = x->size[0];
  if (0 <= x->size[0] - 1) {
    iindx = coffset;
    ttt[0] = (bkj - 2.0 * scale) - bkj;
    ttt[1] = (b_scale - 2.0 * absxk) - b_scale;
    ttt[2] = (t - 2.0 * x1) - t;
  }
  for (j = 0; j < boffset; j++) {
    cang_idx_0 = x->data[j] - Xnn->data[7 * (iindx - 1)];
    cang_idx_1 = y->data[j] - Xnn->data[7 * (iindx - 1) + 1];
    bkj = z->data[j] - Xnn->data[7 * (iindx - 1) + 2];
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    absxk = fabs(cang_idx_1 * ttt[2] - ttt[1] * bkj);
    if (absxk > 3.3121686421112381E-170) {
      x1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      x1 = t * t;
    }
    absxk = fabs(ttt[0]);
    if (absxk > 3.3121686421112381E-170) {
      b_y1 = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y1 = t * t;
    }
    absxk = fabs(ttt[0] * bkj - cang_idx_0 * ttt[2]);
    if (absxk > scale) {
      t = scale / absxk;
      x1 = x1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x1 += t * t;
    }
    absxk = fabs(ttt[1]);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      b_y1 = b_y1 * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      b_y1 += t * t;
    }
    absxk = fabs(cang_idx_0 * ttt[1] - ttt[0] * cang_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      x1 = x1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      x1 += t * t;
    }
    absxk = fabs(ttt[2]);
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
    Err_every->data[j] = x1 / b_y1;
  }
  emxFree_real_T(&Xnn);
  /*  比较与半径的差值（圆度） */
  boffset = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  emxEnsureCapacity_real_T(Err_every, boffset);
  loop_ub = Err_every->size[1] - 1;
  for (boffset = 0; boffset <= loop_ub; boffset++) {
    Err_every->data[boffset] -= r0;
  }
  /*  单个点误差 */
  *Mradial = r0;
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points.c
 *
 * [EOF]
 */
