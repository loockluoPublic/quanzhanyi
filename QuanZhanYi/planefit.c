/*
 * File: planefit.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 14:10:17
 */

/* Include Files */
#include "planefit.h"
#include "CrossLine.h"
#include "GenerateTrianglePoints.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"
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
  static const signed char iv2[24] = {0, 1, 2, 1, 2, 3, 0, 2, 4, 2, 4, 5,
                                      4, 5, 6, 5, 6, 7, 1, 3, 6, 3, 6, 7};
  static const signed char iv1[18] = {0, 1, 2, 1, 2, 3, 0, 2, 4,
                                      2, 4, 5, 4, 5, 6, 5, 6, 7};
  static const signed char iv3[12] = {0, 1, 2, 1, 2, 3, 0, 2, 4, 2, 4, 5};
  static const signed char iv[6] = {0, 1, 2, 0, 2, 3};
  emxArray_real_T *a__1;
  emxArray_real_T *b_pointss;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  double V[9];
  double b_xfit[8];
  double b_yfit[8];
  double zfit[8];
  double c_yfit[6];
  double c_zfit[6];
  double d_xfit[6];
  double coefficients[3];
  double s_data[3];
  double bb[2];
  const double *PlaneParaIn_data;
  const double *Points_data;
  double a;
  double angle;
  double b;
  double d;
  double yz_idx_1;
  double *pointss_data;
  double *x_data;
  double *y_data;
  double *z_data;
  int c;
  int nx;
  int r2;
  int xfit_tmp_tmp;
  boolean_T p;
  PlaneParaIn_data = PlaneParaIn->data;
  Points_data = Points->data;
  emxInit_real_T(&x, 1);
  /*  平面拟合 */
  nx = Points->size[1];
  r2 = x->size[0];
  x->size[0] = Points->size[1];
  emxEnsureCapacity_real_T(x, r2);
  x_data = x->data;
  for (r2 = 0; r2 < nx; r2++) {
    x_data[r2] = Points_data[3 * r2];
  }
  emxInit_real_T(&y, 1);
  nx = Points->size[1];
  r2 = y->size[0];
  y->size[0] = Points->size[1];
  emxEnsureCapacity_real_T(y, r2);
  y_data = y->data;
  for (r2 = 0; r2 < nx; r2++) {
    y_data[r2] = Points_data[3 * r2 + 1];
  }
  emxInit_real_T(&z, 1);
  nx = Points->size[1];
  r2 = z->size[0];
  z->size[0] = Points->size[1];
  emxEnsureCapacity_real_T(z, r2);
  z_data = z->data;
  for (r2 = 0; r2 < nx; r2++) {
    z_data[r2] = Points_data[3 * r2 + 2];
  }
  emxInit_real_T(&pointss, 2);
  r2 = pointss->size[0] * pointss->size[1];
  pointss->size[0] = Points->size[1];
  pointss->size[1] = 3;
  emxEnsureCapacity_real_T(pointss, r2);
  z_data = pointss->data;
  nx = Points->size[1];
  for (r2 = 0; r2 < 3; r2++) {
    for (xfit_tmp_tmp = 0; xfit_tmp_tmp < nx; xfit_tmp_tmp++) {
      z_data[xfit_tmp_tmp + pointss->size[0] * r2] =
          Points_data[r2 + 3 * xfit_tmp_tmp];
    }
  }
  emxInit_real_T(&b_pointss, 2);
  /*  Fit a plane through the points */
  b_mean(pointss, coefficients);
  r2 = b_pointss->size[0] * b_pointss->size[1];
  b_pointss->size[0] = pointss->size[0];
  b_pointss->size[1] = 3;
  emxEnsureCapacity_real_T(b_pointss, r2);
  pointss_data = b_pointss->data;
  nx = pointss->size[0];
  for (r2 = 0; r2 < 3; r2++) {
    for (xfit_tmp_tmp = 0; xfit_tmp_tmp < nx; xfit_tmp_tmp++) {
      pointss_data[xfit_tmp_tmp + b_pointss->size[0] * r2] =
          z_data[xfit_tmp_tmp + pointss->size[0] * r2] - coefficients[r2];
    }
  }
  r2 = pointss->size[0] * pointss->size[1];
  pointss->size[0] = b_pointss->size[0];
  pointss->size[1] = 3;
  emxEnsureCapacity_real_T(pointss, r2);
  z_data = pointss->data;
  nx = b_pointss->size[0] * 3;
  for (r2 = 0; r2 < nx; r2++) {
    z_data[r2] = pointss_data[r2];
  }
  emxFree_real_T(&b_pointss);
  nx = pointss->size[0] * 3;
  p = true;
  for (r2 = 0; r2 < nx; r2++) {
    if ((!p) || (rtIsInf(z_data[r2]) || rtIsNaN(z_data[r2]))) {
      p = false;
    }
  }
  if (p) {
    emxInit_real_T(&a__1, 2);
    d_svd(pointss, a__1, s_data, &nx, V);
    emxFree_real_T(&a__1);
  } else {
    for (r2 = 0; r2 < 9; r2++) {
      V[r2] = rtNaN;
    }
  }
  /*  Normal vector of the plane */
  /*  Calculate angle between normal vector and z-axis */
  angle = fabs(90.0 - 57.295779513082323 *
                          acos(fabs((V[6] * 0.0 + V[7] * 0.0) + V[8])));
  /*  Check if angle is below threshold */
  if (angle < 0.5) {
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
    z_data = pointss->data;
    nx = x->size[0];
    for (r2 = 0; r2 < nx; r2++) {
      z_data[r2] = x_data[r2];
    }
    nx = y->size[0];
    for (r2 = 0; r2 < nx; r2++) {
      z_data[r2 + pointss->size[0]] = y_data[r2];
    }
    nx = x->size[0];
    for (r2 = 0; r2 < nx; r2++) {
      z_data[r2 + pointss->size[0] * 2] = 1.0;
    }
    mldivide(pointss, z, coefficients);
    a = coefficients[0];
    b = coefficients[1];
    d = coefficients[2];
    c = -1;
  }
  emxFree_real_T(&pointss);
  emxFree_real_T(&y);
  r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 1;
  emxEnsureCapacity_real_T(PlaneParaOut, r2);
  z_data = PlaneParaOut->data;
  z_data[0] = 0.0;
  z_data[1] = 0.0;
  z_data[2] = 0.0;
  z_data[3] = 0.0;
  r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 6;
  emxEnsureCapacity_real_T(TrianglePoints, r2);
  z_data = TrianglePoints->data;
  for (r2 = 0; r2 < 18; r2++) {
    z_data[r2] = 0.0;
  }
  if (PlaneParaIn->size[1] == 0) {
    double c_xfit[18];
    double b_zfit[4];
    double xfit[4];
    double yfit[4];
    double a21;
    double x_val;
    double yfit_tmp;
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 1;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    z_data = PlaneParaOut->data;
    z_data[0] = a;
    z_data[1] = b;
    z_data[2] = c;
    z_data[3] = d;
    /*  找到边界，确定三角点 */
    minimum(x, &yz_idx_1, &nx);
    maximum(x, &yz_idx_1, &r2);
    xfit_tmp_tmp = 3 * (nx - 1);
    a21 = Points_data[xfit_tmp_tmp];
    xfit[0] = a21;
    xfit[1] = a21;
    nx = 3 * (r2 - 1);
    x_val = Points_data[nx];
    xfit[2] = x_val;
    xfit[3] = x_val;
    yz_idx_1 = Points_data[xfit_tmp_tmp + 1];
    yfit[0] = yz_idx_1;
    yfit[1] = yz_idx_1;
    yfit_tmp = Points_data[nx + 1];
    yfit[2] = yfit_tmp;
    yfit[3] = yfit_tmp;
    if (angle < 0.5) {
      a21 = b_maximum(z);
      yz_idx_1 = b_minimum(z);
      b_zfit[0] = a21;
      b_zfit[1] = yz_idx_1;
      b_zfit[2] = yz_idx_1;
      b_zfit[3] = a21;
    } else {
      a21 = -((d + a * a21) + b * yz_idx_1) / (double)c;
      b_zfit[0] = a21;
      b_zfit[1] = a21;
      a21 = -((d + a * x_val) + b * yfit_tmp) / (double)c;
      b_zfit[2] = a21;
      b_zfit[3] = a21;
    }
    for (r2 = 0; r2 < 6; r2++) {
      signed char i;
      i = iv[r2];
      c_xfit[3 * r2] = xfit[i];
      c_xfit[3 * r2 + 1] = yfit[i];
      c_xfit[3 * r2 + 2] = b_zfit[i];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 6;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    z_data = TrianglePoints->data;
    for (r2 = 0; r2 < 18; r2++) {
      z_data[r2] = c_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 1) {
    double g_xfit[36];
    double PointTri[6];
    double xfit[4];
    double yfit[4];
    double a21;
    double x_val;
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 2;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    z_data = PlaneParaOut->data;
    z_data[0] = PlaneParaIn_data[0];
    z_data[1] = PlaneParaIn_data[1];
    z_data[2] = PlaneParaIn_data[2];
    z_data[3] = PlaneParaIn_data[3];
    z_data[4] = a;
    z_data[5] = b;
    z_data[6] = c;
    z_data[7] = d;
    /*  计算交线 */
    x_val = (b_maximum(x) + b_minimum(x)) / 2.0;
    /*  定义平面1的系数 */
    /*  定义平面2的系数 */
    /*  计算法向量的叉乘得到交线的方向向量 */
    s_data[0] = PlaneParaIn_data[1] * (double)c - b * PlaneParaIn_data[2];
    s_data[1] = a * PlaneParaIn_data[2] - PlaneParaIn_data[0] * (double)c;
    s_data[2] = PlaneParaIn_data[0] * b - a * PlaneParaIn_data[1];
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
      nx = 1;
      r2 = 0;
    } else {
      nx = 0;
      r2 = 1;
    }
    a21 = yfit[r2] / yfit[nx];
    angle = yfit[nx + 2];
    yz_idx_1 = (bb[r2] - bb[nx] * a21) / (yfit[r2 + 2] - a21 * angle);
    /*  The point on the intersection line */
    coefficients[0] = x_val;
    coefficients[1] = (bb[nx] - yz_idx_1 * angle) / yfit[nx];
    coefficients[2] = yz_idx_1;
    /*  找到边界，确定三角点 */
    b_GenerateTrianglePoints(PlaneParaIn, BoundPoint1, coefficients, s_data,
                             PointTri);
    d_xfit[0] = PointTri[0];
    c_yfit[0] = PointTri[1];
    c_zfit[0] = PointTri[2];
    d_xfit[1] = PointTri[3];
    c_yfit[1] = PointTri[4];
    c_zfit[1] = PointTri[5];
    b_GenerateTrianglePoints(PlaneParaIn, BoundPoint2, coefficients, s_data,
                             PointTri);
    d_xfit[2] = PointTri[0];
    c_yfit[2] = PointTri[1];
    c_zfit[2] = PointTri[2];
    d_xfit[3] = PointTri[3];
    c_yfit[3] = PointTri[4];
    c_zfit[3] = PointTri[5];
    xfit[0] = a;
    xfit[1] = b;
    xfit[2] = c;
    xfit[3] = d;
    c_GenerateTrianglePoints(xfit, BoundPoint1, coefficients, s_data, PointTri);
    d_xfit[4] = PointTri[3];
    c_yfit[4] = PointTri[4];
    c_zfit[4] = PointTri[5];
    xfit[0] = a;
    xfit[1] = b;
    xfit[2] = c;
    xfit[3] = d;
    c_GenerateTrianglePoints(xfit, BoundPoint2, coefficients, s_data, PointTri);
    d_xfit[5] = PointTri[3];
    c_yfit[5] = PointTri[4];
    c_zfit[5] = PointTri[5];
    for (r2 = 0; r2 < 12; r2++) {
      signed char i;
      i = iv3[r2];
      g_xfit[3 * r2] = d_xfit[i];
      g_xfit[3 * r2 + 1] = c_yfit[i];
      g_xfit[3 * r2 + 2] = c_zfit[i];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 12;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    z_data = TrianglePoints->data;
    for (r2 = 0; r2 < 36; r2++) {
      z_data[r2] = g_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 2) {
    double e_xfit[54];
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 3;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    z_data = PlaneParaOut->data;
    for (r2 = 0; r2 < 2; r2++) {
      z_data[4 * r2] = PlaneParaIn_data[4 * r2];
      xfit_tmp_tmp = 4 * r2 + 1;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
      xfit_tmp_tmp = 4 * r2 + 2;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
      xfit_tmp_tmp = 4 * r2 + 3;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
    }
    double PointTri[6];
    double x_val;
    z_data[8] = a;
    z_data[9] = b;
    z_data[10] = c;
    z_data[11] = d;
    /* %%%%% 前2个面的交点 %%%% */
    /*  计算交线 */
    x_val = (b_maximum(x) + b_minimum(x)) / 2.0;
    CrossLine(*(double(*)[4]) & PlaneParaIn_data[0],
              *(double(*)[4]) & PlaneParaIn_data[4], x_val, coefficients,
              s_data);
    /*  找到边界，确定三角点 */
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[0], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[0] = PointTri[0];
    b_yfit[0] = PointTri[1];
    zfit[0] = PointTri[2];
    b_xfit[1] = PointTri[3];
    b_yfit[1] = PointTri[4];
    zfit[1] = PointTri[5];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[0], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[2] = PointTri[0];
    b_yfit[2] = PointTri[1];
    zfit[2] = PointTri[2];
    b_xfit[3] = PointTri[3];
    b_yfit[3] = PointTri[4];
    zfit[3] = PointTri[5];
    /* %%%%% 第2、3个面的交点 %%%% */
    CrossLine(*(double(*)[4]) & z_data[4], *(double(*)[4]) & z_data[8], x_val,
              coefficients, s_data);
    /*  找到边界，确定三角点 */
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[8], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[4] = PointTri[0];
    b_yfit[4] = PointTri[1];
    zfit[4] = PointTri[2];
    b_xfit[6] = PointTri[3];
    b_yfit[6] = PointTri[4];
    zfit[6] = PointTri[5];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[8], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[5] = PointTri[0];
    b_yfit[5] = PointTri[1];
    zfit[5] = PointTri[2];
    b_xfit[7] = PointTri[3];
    b_yfit[7] = PointTri[4];
    zfit[7] = PointTri[5];
    for (r2 = 0; r2 < 18; r2++) {
      signed char i;
      i = iv1[r2];
      e_xfit[3 * r2] = b_xfit[i];
      e_xfit[3 * r2 + 1] = b_yfit[i];
      e_xfit[3 * r2 + 2] = zfit[i];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 18;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    z_data = TrianglePoints->data;
    for (r2 = 0; r2 < 54; r2++) {
      z_data[r2] = e_xfit[r2];
    }
  } else if (PlaneParaIn->size[1] == 3) {
    double f_xfit[72];
    /*  平面方程的系数输出 */
    r2 = PlaneParaOut->size[0] * PlaneParaOut->size[1];
    PlaneParaOut->size[0] = 4;
    PlaneParaOut->size[1] = 4;
    emxEnsureCapacity_real_T(PlaneParaOut, r2);
    z_data = PlaneParaOut->data;
    for (r2 = 0; r2 < 3; r2++) {
      z_data[4 * r2] = PlaneParaIn_data[4 * r2];
      xfit_tmp_tmp = 4 * r2 + 1;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
      xfit_tmp_tmp = 4 * r2 + 2;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
      xfit_tmp_tmp = 4 * r2 + 3;
      z_data[xfit_tmp_tmp] = PlaneParaIn_data[xfit_tmp_tmp];
    }
    double PointTri[6];
    double x_val;
    z_data[12] = a;
    z_data[13] = b;
    z_data[14] = c;
    z_data[15] = d;
    /* %%%%% 前2个面的交点 %%%% */
    /*  计算交线 */
    x_val = (b_maximum(x) + b_minimum(x)) / 2.0;
    CrossLine(*(double(*)[4]) & PlaneParaIn_data[0],
              *(double(*)[4]) & PlaneParaIn_data[4], x_val, coefficients,
              s_data);
    /*  找到边界，确定三角点 */
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[0], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[0] = PointTri[0];
    b_yfit[0] = PointTri[1];
    zfit[0] = PointTri[2];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[0], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[2] = PointTri[0];
    b_yfit[2] = PointTri[1];
    zfit[2] = PointTri[2];
    /* %%%%% 第2、3个面的交点 %%%% */
    CrossLine(*(double(*)[4]) & z_data[4], *(double(*)[4]) & z_data[8], x_val,
              coefficients, s_data);
    /*  找到边界，确定三角点 */
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[8], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[4] = PointTri[0];
    b_yfit[4] = PointTri[1];
    zfit[4] = PointTri[2];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[8], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[5] = PointTri[0];
    b_yfit[5] = PointTri[1];
    zfit[5] = PointTri[2];
    /* %%%%% 第3、4个面的交点 %%%% */
    CrossLine(*(double(*)[4]) & z_data[8], *(double(*)[4]) & z_data[12], x_val,
              coefficients, s_data);
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[12], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[6] = PointTri[0];
    b_yfit[6] = PointTri[1];
    zfit[6] = PointTri[2];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[12], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[7] = PointTri[0];
    b_yfit[7] = PointTri[1];
    zfit[7] = PointTri[2];
    /* %%%%% 第1、4个面的交点 %%%% */
    CrossLine(*(double(*)[4]) & z_data[0], *(double(*)[4]) & z_data[12], x_val,
              coefficients, s_data);
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[12], BoundPoint1,
                             coefficients, s_data, PointTri);
    b_xfit[1] = PointTri[0];
    b_yfit[1] = PointTri[1];
    zfit[1] = PointTri[2];
    d_GenerateTrianglePoints(*(double(*)[4]) & z_data[12], BoundPoint2,
                             coefficients, s_data, PointTri);
    b_xfit[3] = PointTri[0];
    b_yfit[3] = PointTri[1];
    zfit[3] = PointTri[2];
    for (r2 = 0; r2 < 24; r2++) {
      signed char i;
      i = iv2[r2];
      f_xfit[3 * r2] = b_xfit[i];
      f_xfit[3 * r2 + 1] = b_yfit[i];
      f_xfit[3 * r2 + 2] = zfit[i];
    }
    r2 = TrianglePoints->size[0] * TrianglePoints->size[1];
    TrianglePoints->size[0] = 3;
    TrianglePoints->size[1] = 24;
    emxEnsureCapacity_real_T(TrianglePoints, r2);
    z_data = TrianglePoints->data;
    for (r2 = 0; r2 < 72; r2++) {
      z_data[r2] = f_xfit[r2];
    }
  }
  emxFree_real_T(&z);
  emxFree_real_T(&x);
}

/*
 * File trailer for planefit.c
 *
 * [EOF]
 */
