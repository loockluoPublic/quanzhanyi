/*
 * File: planefit.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Nov-2024 20:42:34
 */

/* Include Files */
#include "planefit.h"
#include "CrossLine.h"
#include "GenerateTrianglePoints.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <math.h>

/* Function Definitions */
/*
 * Points 输入点 3*n
 *  PlaneParaIn 输入平面参数 4*n (n可为0)
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  TrianglePoints 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points
 *                const emxArray_real_T *PlaneParaIn
 *                const double BoundPoint1[3]
 *                const double BoundPoint2[3]
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 * Return Type  : void
 */
void planefit(const emxArray_real_T *Points, const emxArray_real_T *PlaneParaIn,
              const double BoundPoint1[3], const double BoundPoint2[3],
              emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints)
{
  static const signed char b_iv1[18] = {0, 1, 2, 1, 2, 3, 0, 2, 4,
                                        2, 4, 5, 4, 5, 6, 5, 6, 7};
  static const signed char iv2[12] = {0, 1, 2, 1, 2, 3, 0, 2, 4, 2, 4, 5};
  static const signed char b_iv[6] = {0, 1, 2, 0, 2, 3};
  emxArray_real_T *a__1;
  emxArray_real_T *b_Points;
  emxArray_real_T *b_pointss;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  emxArray_real_T *y;
  double f_xfit[72];
  double e_xfit[54];
  double g_xfit[36];
  double c_xfit[18];
  double V[9];
  double b_xfit[8];
  double b_yfit[8];
  double zfit[8];
  double PointTri[6];
  double b_zfit[6];
  double c_yfit[6];
  double d_xfit[6];
  double xfit[4];
  double yfit[4];
  double D[3];
  double coefficients[3];
  double bb[2];
  const double *PlaneParaIn_data;
  const double *Points_data;
  double a;
  double a21;
  double b;
  double d;
  double x_val;
  double yz_idx_1;
  double yz_idx_1_tmp;
  double *PlaneParaOut_data;
  double *pointss_data;
  double *x_data;
  double *y_data;
  int c;
  int i;
  int r1;
  int r2;
  signed char i1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  PlaneParaIn_data = PlaneParaIn->data;
  Points_data = Points->data;
  /*  平面拟合 */
  emxInit_real_T(&x, 1);
  r2 = x->size[0];
  x->size[0] = Points->size[1];
  emxEnsureCapacity_real_T(x, r2);
  x_data = x->data;
  r1 = Points->size[1];
  emxInit_real_T(&y, 1);
  r2 = y->size[0];
  y->size[0] = Points->size[1];
  emxEnsureCapacity_real_T(y, r2);
  y_data = y->data;
  for (r2 = 0; r2 < r1; r2++) {
    x_data[r2] = Points_data[3 * r2];
    y_data[r2] = Points_data[3 * r2 + 1];
  }
  emxInit_real_T(&pointss, 2);
  r2 = pointss->size[0] * pointss->size[1];
  pointss->size[0] = Points->size[1];
  pointss->size[1] = 3;
  emxEnsureCapacity_real_T(pointss, r2);
  pointss_data = pointss->data;
  r1 = Points->size[1];
  for (r2 = 0; r2 < 3; r2++) {
    for (i = 0; i < r1; i++) {
      pointss_data[i + pointss->size[0] * r2] = Points_data[r2 + 3 * i];
    }
  }
  /*  Fit a plane through the points */
  b_mean(pointss, coefficients);
  emxInit_real_T(&b_pointss, 2);
  r2 = b_pointss->size[0] * b_pointss->size[1];
  b_pointss->size[0] = pointss->size[0];
  b_pointss->size[1] = 3;
  emxEnsureCapacity_real_T(b_pointss, r2);
  PlaneParaOut_data = b_pointss->data;
  r1 = pointss->size[0];
  for (r2 = 0; r2 < 3; r2++) {
    for (i = 0; i < r1; i++) {
      PlaneParaOut_data[i + b_pointss->size[0] * r2] =
          pointss_data[i + pointss->size[0] * r2] - coefficients[r2];
    }
  }
  r2 = pointss->size[0] * pointss->size[1];
  pointss->size[0] = b_pointss->size[0];
  pointss->size[1] = 3;
  emxEnsureCapacity_real_T(pointss, r2);
  pointss_data = pointss->data;
  r1 = b_pointss->size[0];
  for (r2 = 0; r2 < 3; r2++) {
    for (i = 0; i < r1; i++) {
      pointss_data[i + pointss->size[0] * r2] =
          PlaneParaOut_data[i + b_pointss->size[0] * r2];
    }
  }
  emxInit_real_T(&a__1, 2);
  b_svd(pointss, a__1, b_pointss, V);
  emxFree_real_T(&b_pointss);
  emxFree_real_T(&a__1);
  /*  Normal vector of the plane */
  /*  Calculate angle between normal vector and z-axis */
  /*  Check if angle is below threshold */
  if (fabs(90.0 - 57.295779513082323 *
                      acos(fabs((V[6] * 0.0 + V[7] * 0.0) + V[8]))) < 0.5) {
    c = 0;
    polyfit(x, y, bb);
    /*  拟合，其实是线性回归，但可以用来拟合平面 */
    a = bb[0];
    b = -1.0;
    d = bb[1];
  } else {
    /*  构建矩阵 A 和向量 b */
    /*  使用最小二乘法拟合平面 */
    r2 = pointss->size[0] * pointss->size[1];
    pointss->size[0] = x->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, r2);
    pointss_data = pointss->data;
    r1 = x->size[0];
    emxInit_real_T(&b_Points, 1);
    r2 = b_Points->size[0];
    b_Points->size[0] = Points->size[1];
    emxEnsureCapacity_real_T(b_Points, r2);
    PlaneParaOut_data = b_Points->data;
    for (r2 = 0; r2 < r1; r2++) {
      pointss_data[r2] = x_data[r2];
      pointss_data[r2 + pointss->size[0]] = y_data[r2];
      pointss_data[r2 + pointss->size[0] * 2] = 1.0;
      PlaneParaOut_data[r2] = Points_data[3 * r2 + 2];
    }
    mldivide(pointss, b_Points, coefficients);
    emxFree_real_T(&b_Points);
    a = coefficients[0];
    b = coefficients[1];
    d = coefficients[2];
    c = -1;
  }
  emxFree_real_T(&pointss);
  r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 1;
  emxEnsureCapacity_real_T(PlaneParaOut, r2);
  PlaneParaOut_data = PlaneParaOut->data;
  PlaneParaOut_data[0] = 0.0;
  PlaneParaOut_data[1] = 0.0;
  PlaneParaOut_data[2] = 0.0;
  PlaneParaOut_data[3] = 0.0;
  r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 6;
  emxEnsureCapacity_real_T(TrianglePoints, r2);
  PlaneParaOut_data = TrianglePoints->data;
  for (r2 = 0; r2 < 18; r2++) {
    PlaneParaOut_data[r2] = 0.0;
  }
  if (PlaneParaIn->size[1] == 0) {
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 1;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    PlaneParaOut_data = PlaneParaOut->data;
    PlaneParaOut_data[0] = a;
    PlaneParaOut_data[1] = b;
    PlaneParaOut_data[2] = c;
    PlaneParaOut_data[3] = d;
    /*  找到边界，确定三角点 */
    a21 = minimum(x);
    yz_idx_1 = b_maximum(x);
    xfit[0] = a21;
    xfit[1] = a21;
    xfit[2] = yz_idx_1;
    xfit[3] = yz_idx_1;
    yz_idx_1 = b_maximum(y);
    a21 = minimum(y);
    yfit[0] = yz_idx_1;
    yfit[1] = a21;
    yfit[2] = a21;
    yfit[3] = yz_idx_1;
    for (r2 = 0; r2 < 6; r2++) {
      i1 = b_iv[r2];
      a21 = xfit[i1];
      c_xfit[3 * r2] = a21;
      yz_idx_1 = yfit[i1];
      c_xfit[3 * r2 + 1] = yz_idx_1;
      c_xfit[3 * r2 + 2] = -((d + a * a21) + b * yz_idx_1) / (double)c;
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 6;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    PlaneParaOut_data = TrianglePoints->data;
    for (r2 = 0; r2 < 18; r2++) {
      PlaneParaOut_data[r2] = c_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 1) {
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 2;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    PlaneParaOut_data = PlaneParaOut->data;
    PlaneParaOut_data[0] = PlaneParaIn_data[0];
    PlaneParaOut_data[1] = PlaneParaIn_data[1];
    PlaneParaOut_data[2] = PlaneParaIn_data[2];
    PlaneParaOut_data[3] = PlaneParaIn_data[3];
    PlaneParaOut_data[4] = a;
    PlaneParaOut_data[5] = b;
    PlaneParaOut_data[6] = c;
    PlaneParaOut_data[7] = d;
    /*  计算交线 */
    x_val = (b_maximum(x) + minimum(x)) / 2.0;
    /*  定义平面1的系数 */
    /*  定义平面2的系数 */
    /*  计算法向量的叉乘得到交线的方向向量 */
    D[0] = PlaneParaIn_data[1] * (double)c - b * PlaneParaIn_data[2];
    D[1] = a * PlaneParaIn_data[2] - PlaneParaIn_data[0] * (double)c;
    D[2] = PlaneParaIn_data[0] * b - a * PlaneParaIn_data[1];
    /*  确定一个交点 */
    /*  Create the system of equations */
    /*  Solve for y and z */
    a21 = PlaneParaIn_data[1];
    yfit[0] = PlaneParaIn_data[1];
    yfit[1] = b;
    yfit[2] = PlaneParaIn_data[2];
    yfit[3] = c;
    bb[0] = -PlaneParaIn_data[3] - PlaneParaIn_data[0] * x_val;
    bb[1] = -d - a * x_val;
    if (fabs(b) > fabs(a21)) {
      r1 = 1;
      r2 = 0;
    } else {
      r1 = 0;
      r2 = 1;
    }
    a21 = yfit[r2] / yfit[r1];
    yz_idx_1_tmp = yfit[r1 + 2];
    yz_idx_1 = (bb[r2] - bb[r1] * a21) / (yfit[r2 + 2] - a21 * yz_idx_1_tmp);
    /*  The point on the intersection line */
    coefficients[0] = x_val;
    coefficients[1] = (bb[r1] - yz_idx_1 * yz_idx_1_tmp) / yfit[r1];
    coefficients[2] = yz_idx_1;
    /*  找到边界，确定三角点 */
    c_GenerateTrianglePoints(PlaneParaIn, BoundPoint1, coefficients, D,
                             PointTri);
    d_xfit[0] = PointTri[0];
    c_yfit[0] = PointTri[1];
    b_zfit[0] = PointTri[2];
    d_xfit[1] = PointTri[3];
    c_yfit[1] = PointTri[4];
    b_zfit[1] = PointTri[5];
    c_GenerateTrianglePoints(PlaneParaIn, BoundPoint2, coefficients, D,
                             PointTri);
    d_xfit[2] = PointTri[0];
    c_yfit[2] = PointTri[1];
    b_zfit[2] = PointTri[2];
    d_xfit[3] = PointTri[3];
    c_yfit[3] = PointTri[4];
    b_zfit[3] = PointTri[5];
    xfit[0] = a;
    xfit[1] = b;
    xfit[2] = c;
    xfit[3] = d;
    d_GenerateTrianglePoints(xfit, BoundPoint1, coefficients, D, PointTri);
    d_xfit[4] = PointTri[3];
    c_yfit[4] = PointTri[4];
    b_zfit[4] = PointTri[5];
    xfit[0] = a;
    xfit[1] = b;
    xfit[2] = c;
    xfit[3] = d;
    d_GenerateTrianglePoints(xfit, BoundPoint2, coefficients, D, PointTri);
    d_xfit[5] = PointTri[3];
    c_yfit[5] = PointTri[4];
    b_zfit[5] = PointTri[5];
    for (r2 = 0; r2 < 12; r2++) {
      i1 = iv2[r2];
      g_xfit[3 * r2] = d_xfit[i1];
      g_xfit[3 * r2 + 1] = c_yfit[i1];
      g_xfit[3 * r2 + 2] = b_zfit[i1];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 12;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    PlaneParaOut_data = TrianglePoints->data;
    for (r2 = 0; r2 < 36; r2++) {
      PlaneParaOut_data[r2] = g_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 2) {
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 3;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    PlaneParaOut_data = PlaneParaOut->data;
    for (r2 = 0; r2 < 2; r2++) {
      PlaneParaOut_data[4 * r2] = PlaneParaIn_data[4 * r2];
      i = 4 * r2 + 1;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
      i = 4 * r2 + 2;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
      i = 4 * r2 + 3;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
    }
    PlaneParaOut_data[8] = a;
    PlaneParaOut_data[9] = b;
    PlaneParaOut_data[10] = c;
    PlaneParaOut_data[11] = d;
    /* %%%%% 前2个面的交点 %%%% */
    /*  计算交线 */
    x_val = (b_maximum(x) + minimum(x)) / 2.0;
    CrossLine(&PlaneParaIn_data[0], &PlaneParaIn_data[4], x_val, coefficients,
              D);
    /*  找到边界，确定三角点 */
    b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[0] = PointTri[0];
    b_yfit[0] = PointTri[1];
    zfit[0] = PointTri[2];
    b_xfit[1] = PointTri[3];
    b_yfit[1] = PointTri[4];
    zfit[1] = PointTri[5];
    b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[2] = PointTri[0];
    b_yfit[2] = PointTri[1];
    zfit[2] = PointTri[2];
    b_xfit[3] = PointTri[3];
    b_yfit[3] = PointTri[4];
    zfit[3] = PointTri[5];
    /* %%%%% 第2、3个面的交点 %%%% */
    CrossLine(&PlaneParaOut_data[4], &PlaneParaOut_data[8], x_val, coefficients,
              D);
    /*  找到边界，确定三角点 */
    b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[4] = PointTri[0];
    b_yfit[4] = PointTri[1];
    zfit[4] = PointTri[2];
    b_xfit[6] = PointTri[3];
    b_yfit[6] = PointTri[4];
    zfit[6] = PointTri[5];
    b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[5] = PointTri[0];
    b_yfit[5] = PointTri[1];
    zfit[5] = PointTri[2];
    b_xfit[7] = PointTri[3];
    b_yfit[7] = PointTri[4];
    zfit[7] = PointTri[5];
    for (r2 = 0; r2 < 18; r2++) {
      i1 = b_iv1[r2];
      e_xfit[3 * r2] = b_xfit[i1];
      e_xfit[3 * r2 + 1] = b_yfit[i1];
      e_xfit[3 * r2 + 2] = zfit[i1];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 18;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    PlaneParaOut_data = TrianglePoints->data;
    for (r2 = 0; r2 < 54; r2++) {
      PlaneParaOut_data[r2] = e_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 3) {
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 4;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    PlaneParaOut_data = PlaneParaOut->data;
    for (r2 = 0; r2 < 3; r2++) {
      PlaneParaOut_data[4 * r2] = PlaneParaIn_data[4 * r2];
      i = 4 * r2 + 1;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
      i = 4 * r2 + 2;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
      i = 4 * r2 + 3;
      PlaneParaOut_data[i] = PlaneParaIn_data[i];
    }
    PlaneParaOut_data[12] = a;
    PlaneParaOut_data[13] = b;
    PlaneParaOut_data[14] = c;
    PlaneParaOut_data[15] = d;
    /* %%%%% 前2个面的交点 %%%% */
    /*  计算交线 */
    x_val = (b_maximum(x) + minimum(x)) / 2.0;
    CrossLine(&PlaneParaIn_data[0], &PlaneParaIn_data[4], x_val, coefficients,
              D);
    /*  找到边界，确定三角点 */
    b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[0] = PointTri[0];
    b_yfit[0] = PointTri[1];
    zfit[0] = PointTri[2];
    b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[2] = PointTri[0];
    b_yfit[2] = PointTri[1];
    zfit[2] = PointTri[2];
    /* %%%%% 第2、3个面的交点 %%%% */
    CrossLine(&PlaneParaOut_data[4], &PlaneParaOut_data[8], x_val, coefficients,
              D);
    /*  找到边界，确定三角点 */
    b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[4] = PointTri[0];
    b_yfit[4] = PointTri[1];
    zfit[4] = PointTri[2];
    b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[5] = PointTri[0];
    b_yfit[5] = PointTri[1];
    zfit[5] = PointTri[2];
    /* %%%%% 第3、4个面的交点 %%%% */
    CrossLine(&PlaneParaOut_data[8], &PlaneParaOut_data[12], x_val,
              coefficients, D);
    b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[6] = PointTri[0];
    b_yfit[6] = PointTri[1];
    zfit[6] = PointTri[2];
    b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[7] = PointTri[0];
    b_yfit[7] = PointTri[1];
    zfit[7] = PointTri[2];
    /* %%%%% 第1、4个面的交点 %%%% */
    CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[12], x_val,
              coefficients, D);
    b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                             D, PointTri);
    b_xfit[1] = PointTri[0];
    b_yfit[1] = PointTri[1];
    zfit[1] = PointTri[2];
    b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                             D, PointTri);
    b_xfit[3] = PointTri[0];
    b_yfit[3] = PointTri[1];
    zfit[3] = PointTri[2];
    for (r2 = 0; r2 < 24; r2++) {
      i1 = iv1[r2];
      f_xfit[3 * r2] = b_xfit[i1];
      f_xfit[3 * r2 + 1] = b_yfit[i1];
      f_xfit[3 * r2 + 2] = zfit[i1];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 24;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    PlaneParaOut_data = TrianglePoints->data;
    for (r2 = 0; r2 < 72; r2++) {
      PlaneParaOut_data[r2] = f_xfit[r2];
    }
  }
  emxFree_real_T(&y);
  emxFree_real_T(&x);
}

/*
 * File trailer for planefit.c
 *
 * [EOF]
 */
