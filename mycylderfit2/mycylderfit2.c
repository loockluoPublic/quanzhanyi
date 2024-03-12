/*
 * File: mycylderfit2.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

/* Include Files */
#include "mycylderfit2.h"
#include "minOrMax.h"
#include "mycylderfit2_data.h"
#include "mycylderfit2_emxutil.h"
#include "mycylderfit2_initialize.h"
#include "mycylderfit2_types.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <emscripten.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[45]
 *                const double y[45]
 *                const double z[45]
 *                double *XXX1
 *                double *XXX2
 *                double *XXX3
 *                double *XXX4
 *                double *XXX5
 *                double *XXX6
 *                double *XXX7
 * Return Type  : void
 */

EMSCRIPTEN_KEEPALIVE
int add(int a)
{
  printf("开始计算");
  return a + 1;
}

EMSCRIPTEN_KEEPALIVE
double mycylderfit2(const double x[45], const double y[45], const double z[45],
                    double *XXX1, double *XXX2, double *XXX3, double *XXX4,
                    double *XXX5, double *XXX6, double *XXX7)
{
  printf(" x %d \n");

  printf("Hello, World! %f \n", x[0]);

  EM_ASM_(
      {
        var number = $0;
        console.log("x: " + number);
      },
      x[0]);

  EM_ASM_(
      {
        var number = $0;
        console.log("XXX1: " + number);
      },
      *XXX1);

  printf("开始计算");
  emxArray_real_T *Xnn;
  emxArray_real_T *YuanDu;
  double Bn[315];
  double b_NBBn_tmp[315];
  double B[135];
  double b_B[135];
  double circleCloud[135];
  double ptCloud[135];
  double mm[90];
  double NBBn_tmp[49];
  double a[49];
  double L[45];
  double A[9];
  double rot1[9];
  double rot2[9];
  double Xn[7];
  double c_NBBn_tmp[7];
  double deltX[7];
  double angles[3];
  double ttt[3];
  double Bn_tmp;
  double a0;
  double a21;
  double absxk;
  double b0;
  double b_ii;
  double b_y1;
  double c0;
  double cang_idx_0;
  double cang_idx_1;
  double cang_idx_2;
  double d;
  double d1;
  double d2;
  double maxval;
  double r0;
  double t;
  double x1;
  int ii;
  int jj;
  int r1;
  int r2;
  int r3;
  int rtemp;
  boolean_T b;
  boolean_T exitg1;
  if (!isInitialized_mycylderfit2) {
    mycylderfit2_initialize();
  }
  for (rtemp = 0; rtemp < 45; rtemp++) {
    ptCloud[rtemp] = x[rtemp];
    ptCloud[rtemp + 45] = y[rtemp];
    ptCloud[rtemp + 90] = z[rtemp];
  }
  /* -----------------------------计算点云法向量----------------------------- */
  mm[89] = 6.2831853071795862;
  mm[0] = 0.0;
  for (r2 = 0; r2 < 88; r2++) {
    mm[r2 + 1] = ((double)r2 + 1.0) * 0.070597587721118946;
  }
  emxInit_real_T(&YuanDu, 2);
  emxInit_real_T(&Xnn, 2);
  YuanDu->size[0] = 1;
  YuanDu->size[1] = 0;
  Xnn->size[0] = 7;
  Xnn->size[1] = 0;
  b = rtIsNaN(ptCloud[90]);
  for (ii = 0; ii < 90; ii++) {
    b_ii = mm[ii];
    for (jj = 0; jj < 90; jj++) {
      /*          rot1 = angle2dcm(ii,jj,0, 'XYZ'); % 旋转矩阵 */
      d = mm[jj];
      cang_idx_0 = cos(b_ii);
      angles[0] = sin(b_ii);
      cang_idx_1 = cos(d);
      angles[1] = sin(d);
      rot1[0] = cang_idx_1;
      rot1[3] = angles[0] * angles[1] + cang_idx_0 * 0.0;
      rot1[6] = -cang_idx_0 * angles[1] + angles[0] * 0.0;
      rot1[1] = -cang_idx_1 * 0.0;
      rot1[4] = -angles[0] * angles[1] * 0.0 + cang_idx_0;
      rot1[7] = cang_idx_0 * angles[1] * 0.0 + angles[0];
      rot1[2] = angles[1];
      rot1[5] = -angles[0] * cang_idx_1;
      rot1[8] = cang_idx_0 * cang_idx_1;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        ttt[rtemp] = rot1[3 * rtemp + 2];
      }
      a0 = ttt[0];
      b0 = ttt[1];
      c0 = ttt[2];
      /*          rot2 = angle2dcm(-ii,-jj,0, 'XYZ'); */
      cang_idx_0 = cos(-b_ii);
      angles[0] = sin(-b_ii);
      cang_idx_1 = cos(-d);
      angles[1] = sin(-d);
      rot2[0] = cang_idx_1;
      rot2[3] = angles[0] * angles[1] + cang_idx_0 * 0.0;
      rot2[6] = -cang_idx_0 * angles[1] + angles[0] * 0.0;
      rot2[1] = -cang_idx_1 * 0.0;
      rot2[4] = -angles[0] * angles[1] * 0.0 + cang_idx_0;
      rot2[7] = cang_idx_0 * angles[1] * 0.0 + angles[0];
      rot2[2] = angles[1];
      rot2[5] = -angles[0] * cang_idx_1;
      rot2[8] = cang_idx_0 * cang_idx_1;
      for (rtemp = 0; rtemp < 45; rtemp++) {
        d = ptCloud[rtemp];
        d1 = ptCloud[rtemp + 45];
        d2 = ptCloud[rtemp + 90];
        for (r2 = 0; r2 < 3; r2++) {
          circleCloud[rtemp + 45 * r2] =
              (d * rot2[3 * r2] + d1 * rot2[3 * r2 + 1]) +
              d2 * rot2[3 * r2 + 2];
        }
      }
      /* --------------------------初始化矩阵系数--------------------------------
       */
      for (rtemp = 0; rtemp < 135; rtemp++) {
        B[rtemp] = 1.0;
      }
      /*  系数矩阵L */
      /*  赋值 */
      /*  间接平差求解 */
      for (r2 = 0; r2 < 45; r2++) {
        d = circleCloud[r2];
        d1 = d * 2.0;
        B[r2] = d1;
        maxval = circleCloud[r2 + 45];
        d2 = maxval * 2.0;
        B[r2 + 45] = d2;
        L[r2] = d * d + maxval * maxval;
        b_B[3 * r2] = d1;
        b_B[3 * r2 + 1] = d2;
        b_B[3 * r2 + 2] = B[r2 + 90];
      }
      memcpy(&circleCloud[0], &b_B[0], 135U * sizeof(double));
      /*  参数求解 */
      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (r2 = 0; r2 < 3; r2++) {
          d = 0.0;
          for (r3 = 0; r3 < 45; r3++) {
            d += circleCloud[rtemp + 3 * r3] * B[r3 + 45 * r2];
          }
          A[rtemp + 3 * r2] = d;
        }
        d = 0.0;
        for (r2 = 0; r2 < 45; r2++) {
          d += circleCloud[rtemp + 3 * r2] * L[r2];
        }
        angles[rtemp] = d;
      }
      r1 = 0;
      r2 = 1;
      r3 = 2;
      maxval = fabs(A[0]);
      a21 = fabs(A[1]);
      if (a21 > maxval) {
        maxval = a21;
        r1 = 1;
        r2 = 0;
      }
      if (fabs(A[2]) > maxval) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
      }
      A[r2] /= A[r1];
      A[r3] /= A[r1];
      A[r2 + 3] -= A[r2] * A[r1 + 3];
      A[r3 + 3] -= A[r3] * A[r1 + 3];
      A[r2 + 6] -= A[r2] * A[r1 + 6];
      A[r3 + 6] -= A[r3] * A[r1 + 6];
      if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
        rtemp = r2;
        r2 = r3;
        r3 = rtemp;
      }
      A[r3 + 3] /= A[r2 + 3];
      A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
      cang_idx_1 = angles[r2] - angles[r1] * A[r2];
      cang_idx_2 =
          ((angles[r3] - angles[r1] * A[r3]) - cang_idx_1 * A[r3 + 3]) /
          A[r3 + 6];
      cang_idx_1 -= cang_idx_2 * A[r2 + 6];
      cang_idx_1 /= A[r2 + 3];
      cang_idx_0 =
          ((angles[r1] - cang_idx_2 * A[r1 + 6]) - cang_idx_1 * A[r1 + 3]) /
          A[r1];
      r0 = sqrt((cang_idx_0 * cang_idx_0 + cang_idx_1 * cang_idx_1) +
                cang_idx_2);
      for (rtemp = 0; rtemp < 3; rtemp++) {
        angles[rtemp] =
            (cang_idx_0 * rot2[3 * rtemp] + cang_idx_1 * rot2[3 * rtemp + 1]) +
            0.0 * rot2[3 * rtemp + 2];
      }
      /*  旋转矩阵的逆与转置相等 */
      x1 = angles[0];
      b_y1 = angles[1];
      if (!b) {
        r1 = 1;
      } else {
        r1 = 0;
        r2 = 2;
        exitg1 = false;
        while ((!exitg1) && (r2 < 46)) {
          if (!rtIsNaN(ptCloud[r2 + 89])) {
            r1 = r2;
            exitg1 = true;
          } else {
            r2++;
          }
        }
      }
      if (r1 == 0) {
        maxval = ptCloud[90];
      } else {
        maxval = ptCloud[r1 + 89];
        rtemp = r1 + 1;
        for (r2 = rtemp; r2 < 46; r2++) {
          d = ptCloud[r2 + 89];
          if (maxval > d) {
            maxval = d;
          }
        }
      }
      if (!b) {
        r1 = 1;
      } else {
        r1 = 0;
        r2 = 2;
        exitg1 = false;
        while ((!exitg1) && (r2 < 46)) {
          if (!rtIsNaN(ptCloud[r2 + 89])) {
            r1 = r2;
            exitg1 = true;
          } else {
            r2++;
          }
        }
      }
      if (r1 == 0) {
        a21 = ptCloud[90];
      } else {
        a21 = ptCloud[r1 + 89];
        rtemp = r1 + 1;
        for (r2 = rtemp; r2 < 46; r2++) {
          d = ptCloud[r2 + 89];
          if (a21 < d) {
            a21 = d;
          }
        }
      }
      /*  计算点云z坐标最值 */
      maxval = (maxval + a21) * 0.5;
      /* ------------------------------最小二乘迭代---------------------------
       */
      for (rtemp = 0; rtemp < 315; rtemp++) {
        Bn[rtemp] = 1.0;
      }
      Xn[0] = angles[0];
      Xn[1] = angles[1];
      Xn[2] = maxval;
      Xn[3] = ttt[0];
      Xn[4] = ttt[1];
      Xn[5] = ttt[2];
      Xn[6] = r0;
      r1 = 1;
      exitg1 = false;
      while ((!exitg1) && (r0 > 0.0001)) {
        for (r2 = 0; r2 < 45; r2++) {
          d = y[r2];
          d1 = x[r2];
          a21 = d1 - x1;
          absxk = d - b_y1;
          d2 = z[r2];
          t = d2 - maxval;
          Bn_tmp = (a0 * a21 + b0 * absxk) + c0 * t;
          Bn[r2] = (2.0 * x1 - d1 * 2.0) + 2.0 * a0 * Bn_tmp;
          for (rtemp = 0; rtemp < 45; rtemp++) {
            Bn[rtemp + 45] = (2.0 * b_y1 - 2.0 * d) + 2.0 * b0 * Bn_tmp;
          }
          Bn[r2 + 90] = (2.0 * maxval - 2.0 * d2) + 2.0 * c0 * Bn_tmp;
          Bn[r2 + 135] = -2.0 * a21 * Bn_tmp;
          Bn[r2 + 180] = -2.0 * absxk * Bn_tmp;
          Bn[r2 + 225] = -2.0 * t * Bn_tmp;
          Bn[r2 + 270] = -2.0 * r0;
          L[r2] = -((((a21 * a21 + absxk * absxk) + t * t) - Bn_tmp * Bn_tmp) -
                    r0 * r0);
        }
        /*  间接平差求解 */
        for (rtemp = 0; rtemp < 45; rtemp++) {
          for (r2 = 0; r2 < 7; r2++) {
            b_NBBn_tmp[r2 + 7 * rtemp] = Bn[rtemp + 45 * r2];
          }
        }
        for (rtemp = 0; rtemp < 7; rtemp++) {
          for (r2 = 0; r2 < 7; r2++) {
            d = 0.0;
            for (r3 = 0; r3 < 45; r3++) {
              d += b_NBBn_tmp[rtemp + 7 * r3] * Bn[r3 + 45 * r2];
            }
            NBBn_tmp[rtemp + 7 * r2] = d;
          }
        }
        pinv(NBBn_tmp, a);
        for (rtemp = 0; rtemp < 7; rtemp++) {
          d = 0.0;
          for (r2 = 0; r2 < 45; r2++) {
            d += b_NBBn_tmp[rtemp + 7 * r2] * L[r2];
          }
          c_NBBn_tmp[rtemp] = d;
        }
        for (rtemp = 0; rtemp < 7; rtemp++) {
          d = 0.0;
          for (r2 = 0; r2 < 7; r2++) {
            d += a[rtemp + 7 * r2] * c_NBBn_tmp[r2];
          }
          deltX[rtemp] = d;
          Xn[rtemp] += d;
        }
        /*  获取迭代增量 */
        x1 = deltX[0];
        b_y1 = deltX[1];
        maxval = deltX[2];
        a0 = deltX[3];
        b0 = deltX[4];
        c0 = deltX[5];
        r0 = deltX[6];
        r1++;
        /* 迭代次数足够多，跳出迭代。 */
        if (r1 >= 100) {
          exitg1 = true;
        }
      }
      /*          disp("轴线一点坐标："); */
      /*          disp(Xn(1:3)); */
      /*          disp("轴线方向向量："); */
      /*          disp(Xn(4:6)); */
      /*          disp("圆柱体半径："); */
      /*          disp(Xn(7)); */
      /* ------------------------------可视化对比--------------------------- */
      /*  列出所有参数 */
      /* 圆心 */
      /* 法向量 */
      /* 半径 */
      /*  计算两个中心点u1、u2 */
      /* ------------------------------ 圆度计算 --------------------------- */
      /*  计算测点到轴线距离 */
      /*  比较与半径的差值（圆度） */
      /*  单个点误差 */
      d = Xn[0];
      d1 = (Xn[0] - 8.0 * Xn[3]) - Xn[0];
      d2 = Xn[1];
      b_y1 = (Xn[1] - 8.0 * Xn[4]) - Xn[1];
      r0 = Xn[2];
      a0 = (Xn[2] - 8.0 * Xn[5]) - Xn[2];
      b0 = Xn[6];
      for (r1 = 0; r1 < 45; r1++) {
        cang_idx_0 = x[r1] - d;
        cang_idx_1 = y[r1] - d2;
        cang_idx_2 = z[r1] - r0;
        maxval = 3.3121686421112381E-170;
        a21 = 3.3121686421112381E-170;
        absxk = fabs(cang_idx_1 * a0 - b_y1 * cang_idx_2);
        if (absxk > 3.3121686421112381E-170) {
          Bn_tmp = 1.0;
          maxval = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          Bn_tmp = t * t;
        }
        absxk = fabs(d1);
        if (absxk > 3.3121686421112381E-170) {
          x1 = 1.0;
          a21 = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          x1 = t * t;
        }
        absxk = fabs(d1 * cang_idx_2 - cang_idx_0 * a0);
        if (absxk > maxval) {
          t = maxval / absxk;
          Bn_tmp = Bn_tmp * t * t + 1.0;
          maxval = absxk;
        } else {
          t = absxk / maxval;
          Bn_tmp += t * t;
        }
        absxk = fabs(b_y1);
        if (absxk > a21) {
          t = a21 / absxk;
          x1 = x1 * t * t + 1.0;
          a21 = absxk;
        } else {
          t = absxk / a21;
          x1 += t * t;
        }
        absxk = fabs(cang_idx_0 * b_y1 - d1 * cang_idx_1);
        if (absxk > maxval) {
          t = maxval / absxk;
          Bn_tmp = Bn_tmp * t * t + 1.0;
          maxval = absxk;
        } else {
          t = absxk / maxval;
          Bn_tmp += t * t;
        }
        absxk = fabs(a0);
        if (absxk > a21) {
          t = a21 / absxk;
          x1 = x1 * t * t + 1.0;
          a21 = absxk;
        } else {
          t = absxk / a21;
          x1 += t * t;
        }
        Bn_tmp = maxval * sqrt(Bn_tmp);
        x1 = a21 * sqrt(x1);
        maxval = Bn_tmp / x1 - b0;
        L[r1] = maxval * maxval;
      }
      Bn_tmp = L[0];
      for (r2 = 0; r2 < 44; r2++) {
        Bn_tmp += L[r2 + 1];
      }
      rtemp = YuanDu->size[1];
      r2 = YuanDu->size[0] * YuanDu->size[1];
      YuanDu->size[1]++;
      emxEnsureCapacity_real_T(YuanDu, r2);
      YuanDu->data[rtemp] = Bn_tmp / 45.0;
      /*  总体圆度 */
      rtemp = Xnn->size[1];
      r2 = Xnn->size[0] * Xnn->size[1];
      Xnn->size[0] = 7;
      Xnn->size[1]++;
      emxEnsureCapacity_real_T(Xnn, r2);
      for (r2 = 0; r2 < 7; r2++) {
        Xnn->data[r2 + 7 * rtemp] = Xn[r2];
      }
    }
  }
  minimum(YuanDu, &maxval, &r1);
  /* ------------------------------可视化对比--------------------------- */
  /*  列出所有参数 */
  /* 圆心 */
  /* 法向量 */
  /* 半径 */
  r1 = 7 * (r1 - 1);
  *XXX1 = Xnn->data[r1];
  *XXX2 = Xnn->data[r1 + 1];
  *XXX3 = Xnn->data[r1 + 2];
  *XXX4 = Xnn->data[r1 + 3];
  *XXX5 = Xnn->data[r1 + 4];
  *XXX6 = Xnn->data[r1 + 5];
  *XXX7 = Xnn->data[r1 + 6];

  // printf('结束计算： %f %f %f %f %f %f %f %f ', XXX1, XXX2, XXX3, XXX4, XXX5,
  //        XXX6, XXX7);
  emxFree_real_T(&Xnn);
  emxFree_real_T(&YuanDu);

  EM_ASM_(
      {
        var number = $0;
        console.log("XXX1 end: " + number);
      },
      *XXX1);
  return *XXX1;
}

/*
 * File trailer for mycylderfit2.c
 *
 * [EOF]
 */
