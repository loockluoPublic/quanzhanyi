/*
 * File: planefit4.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Aug-2024 16:15:12
 */

/* Include Files */
#include "planefit4.h"
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
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  TrianglePoints 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                const emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                const emxArray_real_T *Points4
 *                const double BoundPoint1[3]
 *                const double BoundPoint2[3]
 *                double PlaneParaOut[16]
 *                double TrianglePoints[72]
 * Return Type  : void
 */
void planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const double BoundPoint1[3], const double BoundPoint2[3],
               double PlaneParaOut[16], double TrianglePoints[72])
{
  cell_wrap_6 PointAll[4];
  cell_wrap_6 r;
  cell_wrap_6 r1;
  cell_wrap_6 r2;
  cell_wrap_6 r3;
  emxArray_real_T *a__1;
  emxArray_real_T *b_pointss;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  emxArray_real_T *y;
  double V[9];
  double xfit[8];
  double yfit[8];
  double zfit[8];
  double PointTri[6];
  double D[3];
  double coefficients[3];
  double bb[2];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  double a;
  double b;
  double d;
  double *b_pointss_data;
  double *pointss_data;
  double *x_data;
  double *y_data;
  int PlaneParaOut_tmp;
  int b_i;
  int c;
  int i;
  signed char i1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_6(&r);
  PlaneParaOut_tmp = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, PlaneParaOut_tmp);
  c = 3 * Points1->size[1];
  for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
    r.f1->data[PlaneParaOut_tmp] = Points1_data[PlaneParaOut_tmp];
  }
  emxInitStruct_cell_wrap_6(&r1);
  PlaneParaOut_tmp = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, PlaneParaOut_tmp);
  c = 3 * Points2->size[1];
  for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
    r1.f1->data[PlaneParaOut_tmp] = Points2_data[PlaneParaOut_tmp];
  }
  emxInitStruct_cell_wrap_6(&r2);
  PlaneParaOut_tmp = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, PlaneParaOut_tmp);
  c = 3 * Points3->size[1];
  for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
    r2.f1->data[PlaneParaOut_tmp] = Points3_data[PlaneParaOut_tmp];
  }
  emxInitStruct_cell_wrap_6(&r3);
  PlaneParaOut_tmp = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, PlaneParaOut_tmp);
  c = 3 * Points4->size[1];
  for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
    r3.f1->data[PlaneParaOut_tmp] = Points4_data[PlaneParaOut_tmp];
  }
  emxInitMatrix_cell_wrap_6(PointAll);
  emxCopyStruct_cell_wrap_6(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_6(&r);
  emxCopyStruct_cell_wrap_6(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_6(&r1);
  emxCopyStruct_cell_wrap_6(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_6(&r2);
  emxCopyStruct_cell_wrap_6(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_6(&r3);
  emxInit_real_T(&x, 1);
  emxInit_real_T(&y, 1);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&b_pointss, 2);
  for (i = 0; i < 4; i++) {
    /*  平面拟合 */
    c = PointAll[i].f1->size[1];
    PlaneParaOut_tmp = x->size[0];
    x->size[0] = PointAll[i].f1->size[1];
    emxEnsureCapacity_real_T(x, PlaneParaOut_tmp);
    x_data = x->data;
    PlaneParaOut_tmp = y->size[0];
    y->size[0] = PointAll[i].f1->size[1];
    emxEnsureCapacity_real_T(y, PlaneParaOut_tmp);
    y_data = y->data;
    for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
      x_data[PlaneParaOut_tmp] = PointAll[i].f1->data[3 * PlaneParaOut_tmp];
      y_data[PlaneParaOut_tmp] = PointAll[i].f1->data[3 * PlaneParaOut_tmp + 1];
    }
    c = PointAll[i].f1->size[1];
    PlaneParaOut_tmp = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, PlaneParaOut_tmp);
    pointss_data = pointss->data;
    for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < 3; PlaneParaOut_tmp++) {
      for (b_i = 0; b_i < c; b_i++) {
        pointss_data[b_i + pointss->size[0] * PlaneParaOut_tmp] =
            PointAll[i].f1->data[PlaneParaOut_tmp + 3 * b_i];
      }
    }
    /*  Fit a plane through the points */
    mean(pointss, coefficients);
    PlaneParaOut_tmp = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, PlaneParaOut_tmp);
    b_pointss_data = b_pointss->data;
    c = pointss->size[0];
    for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < 3; PlaneParaOut_tmp++) {
      for (b_i = 0; b_i < c; b_i++) {
        b_pointss_data[b_i + b_pointss->size[0] * PlaneParaOut_tmp] =
            pointss_data[b_i + pointss->size[0] * PlaneParaOut_tmp] -
            coefficients[PlaneParaOut_tmp];
      }
    }
    PlaneParaOut_tmp = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, PlaneParaOut_tmp);
    pointss_data = pointss->data;
    c = b_pointss->size[0];
    for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < 3; PlaneParaOut_tmp++) {
      for (b_i = 0; b_i < c; b_i++) {
        pointss_data[b_i + pointss->size[0] * PlaneParaOut_tmp] =
            b_pointss_data[b_i + b_pointss->size[0] * PlaneParaOut_tmp];
      }
    }
    d_svd(pointss, a__1, b_pointss, V);
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
      PlaneParaOut_tmp = pointss->size[0] * pointss->size[1];
      pointss->size[0] = x->size[0];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, PlaneParaOut_tmp);
      pointss_data = pointss->data;
      c = x->size[0];
      for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
        pointss_data[PlaneParaOut_tmp] = x_data[PlaneParaOut_tmp];
      }
      c = y->size[0];
      for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
        pointss_data[PlaneParaOut_tmp + pointss->size[0]] =
            y_data[PlaneParaOut_tmp];
      }
      c = x->size[0];
      for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
        pointss_data[PlaneParaOut_tmp + pointss->size[0] * 2] = 1.0;
      }
      c = PointAll[i].f1->size[1];
      PlaneParaOut_tmp = y->size[0];
      y->size[0] = PointAll[i].f1->size[1];
      emxEnsureCapacity_real_T(y, PlaneParaOut_tmp);
      y_data = y->data;
      for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < c; PlaneParaOut_tmp++) {
        y_data[PlaneParaOut_tmp] =
            PointAll[i].f1->data[3 * PlaneParaOut_tmp + 2];
      }
      mldivide(pointss, y, coefficients);
      a = coefficients[0];
      b = coefficients[1];
      d = coefficients[2];
      c = -1;
    }
    PlaneParaOut_tmp = i << 2;
    PlaneParaOut[PlaneParaOut_tmp] = a;
    PlaneParaOut[PlaneParaOut_tmp + 1] = b;
    PlaneParaOut[PlaneParaOut_tmp + 2] = c;
    PlaneParaOut[PlaneParaOut_tmp + 3] = d;
  }
  emxFree_real_T(&b_pointss);
  emxFreeMatrix_cell_wrap_6(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&pointss);
  emxFree_real_T(&y);
  /*  平面方程的系数输出 */
  /* %%%%% 前2个面的交点 %%%% */
  /*  计算交线 */
  a = (maximum(x) + minimum(x)) / 2.0;
  emxFree_real_T(&x);
  CrossLine(&PlaneParaOut[0], &PlaneParaOut[4], a, coefficients, D);
  /*  找到边界，确定三角点 */
  d_GenerateTrianglePoints(&PlaneParaOut[0], BoundPoint1, coefficients, D,
                           PointTri);
  xfit[0] = PointTri[0];
  yfit[0] = PointTri[1];
  zfit[0] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut[0], BoundPoint2, coefficients, D,
                           PointTri);
  xfit[2] = PointTri[0];
  yfit[2] = PointTri[1];
  zfit[2] = PointTri[2];
  /* %%%%% 第2、3个面的交点 %%%% */
  CrossLine(&PlaneParaOut[4], &PlaneParaOut[8], a, coefficients, D);
  /*  找到边界，确定三角点 */
  d_GenerateTrianglePoints(&PlaneParaOut[8], BoundPoint1, coefficients, D,
                           PointTri);
  xfit[4] = PointTri[0];
  yfit[4] = PointTri[1];
  zfit[4] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut[8], BoundPoint2, coefficients, D,
                           PointTri);
  xfit[5] = PointTri[0];
  yfit[5] = PointTri[1];
  zfit[5] = PointTri[2];
  /* %%%%% 第3、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut[8], &PlaneParaOut[12], a, coefficients, D);
  d_GenerateTrianglePoints(&PlaneParaOut[12], BoundPoint1, coefficients, D,
                           PointTri);
  xfit[6] = PointTri[0];
  yfit[6] = PointTri[1];
  zfit[6] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut[12], BoundPoint2, coefficients, D,
                           PointTri);
  xfit[7] = PointTri[0];
  yfit[7] = PointTri[1];
  zfit[7] = PointTri[2];
  /* %%%%% 第1、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut[0], &PlaneParaOut[12], a, coefficients, D);
  d_GenerateTrianglePoints(&PlaneParaOut[12], BoundPoint1, coefficients, D,
                           PointTri);
  xfit[1] = PointTri[0];
  yfit[1] = PointTri[1];
  zfit[1] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut[12], BoundPoint2, coefficients, D,
                           PointTri);
  xfit[3] = PointTri[0];
  yfit[3] = PointTri[1];
  zfit[3] = PointTri[2];
  for (PlaneParaOut_tmp = 0; PlaneParaOut_tmp < 24; PlaneParaOut_tmp++) {
    i1 = iv[PlaneParaOut_tmp];
    TrianglePoints[3 * PlaneParaOut_tmp] = xfit[i1];
    TrianglePoints[3 * PlaneParaOut_tmp + 1] = yfit[i1];
    TrianglePoints[3 * PlaneParaOut_tmp + 2] = zfit[i1];
  }
}

/*
 * File trailer for planefit4.c
 *
 * [EOF]
 */
