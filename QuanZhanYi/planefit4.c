/*
 * File: planefit4.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 21:29:19
 */

/* Include Files */
#include "planefit4.h"
#include "CrossLine.h"
#include "GenerateTrianglePoints.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
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
 *  BJD 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                const emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                const emxArray_real_T *Points4
 *                const double BoundPoint1[3]
 *                const double BoundPoint2[3]
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 * Return Type  : void
 */
void planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const double BoundPoint1[3], const double BoundPoint2[3],
               emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints)
{
  static const signed char b_iv[8] = {0, 1, 2, 5, 8, 15, 16, 17};
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
  double b_xfit[72];
  double Pdd[24];
  double V[9];
  double xfit[8];
  double yfit[8];
  double zfit[8];
  double PointTri[6];
  double PP2[3];
  double coefficients[3];
  double bb[2];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  double a;
  double b;
  double d;
  double xN2;
  double xN3;
  double xN4;
  double xN5;
  double xN6;
  double xN7;
  double xN8;
  double yN2;
  double yN3;
  double yN4;
  double yN5;
  double yN6;
  double yN7;
  double yN8;
  double zN2;
  double zN3;
  double zN4;
  double zN5;
  double zN6;
  double zN7;
  double zN8;
  double *PlaneParaOut_data;
  double *b_pointss_data;
  double *pointss_data;
  double *x_data;
  double *y_data;
  int b_i;
  int c;
  int i;
  int i1;
  signed char i2;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_6(&r);
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, i);
  c = 3 * Points1->size[1];
  for (i = 0; i < c; i++) {
    r.f1->data[i] = Points1_data[i];
  }
  emxInitStruct_cell_wrap_6(&r1);
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, i);
  c = 3 * Points2->size[1];
  for (i = 0; i < c; i++) {
    r1.f1->data[i] = Points2_data[i];
  }
  emxInitStruct_cell_wrap_6(&r2);
  i = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, i);
  c = 3 * Points3->size[1];
  for (i = 0; i < c; i++) {
    r2.f1->data[i] = Points3_data[i];
  }
  emxInitStruct_cell_wrap_6(&r3);
  i = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, i);
  c = 3 * Points4->size[1];
  for (i = 0; i < c; i++) {
    r3.f1->data[i] = Points4_data[i];
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
  i = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(PlaneParaOut, i);
  PlaneParaOut_data = PlaneParaOut->data;
  for (i = 0; i < 16; i++) {
    PlaneParaOut_data[i] = 0.0;
  }
  emxInit_real_T(&x, 1);
  emxInit_real_T(&y, 1);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&b_pointss, 2);
  for (b_i = 0; b_i < 4; b_i++) {
    /*  平面拟合 */
    c = PointAll[b_i].f1->size[1];
    i = x->size[0];
    x->size[0] = PointAll[b_i].f1->size[1];
    emxEnsureCapacity_real_T(x, i);
    x_data = x->data;
    i = y->size[0];
    y->size[0] = PointAll[b_i].f1->size[1];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    for (i = 0; i < c; i++) {
      x_data[i] = PointAll[b_i].f1->data[3 * i];
      y_data[i] = PointAll[b_i].f1->data[3 * i + 1];
    }
    c = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < c; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * i1];
      }
    }
    /*  Fit a plane through the points */
    mean(pointss, coefficients);
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    b_pointss_data = b_pointss->data;
    c = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < c; i1++) {
        b_pointss_data[i1 + b_pointss->size[0] * i] =
            pointss_data[i1 + pointss->size[0] * i] - coefficients[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    c = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < c; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            b_pointss_data[i1 + b_pointss->size[0] * i];
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
      i = pointss->size[0] * pointss->size[1];
      pointss->size[0] = x->size[0];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, i);
      pointss_data = pointss->data;
      c = x->size[0];
      for (i = 0; i < c; i++) {
        pointss_data[i] = x_data[i];
      }
      c = y->size[0];
      for (i = 0; i < c; i++) {
        pointss_data[i + pointss->size[0]] = y_data[i];
      }
      c = x->size[0];
      for (i = 0; i < c; i++) {
        pointss_data[i + pointss->size[0] * 2] = 1.0;
      }
      c = PointAll[b_i].f1->size[1];
      i = y->size[0];
      y->size[0] = PointAll[b_i].f1->size[1];
      emxEnsureCapacity_real_T(y, i);
      y_data = y->data;
      for (i = 0; i < c; i++) {
        y_data[i] = PointAll[b_i].f1->data[3 * i + 2];
      }
      mldivide(pointss, y, coefficients);
      a = coefficients[0];
      b = coefficients[1];
      d = coefficients[2];
      c = -1;
    }
    PlaneParaOut_data[4 * b_i] = a;
    PlaneParaOut_data[4 * b_i + 1] = b;
    PlaneParaOut_data[4 * b_i + 2] = c;
    PlaneParaOut_data[4 * b_i + 3] = d;
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
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[4], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  d_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[0] = PointTri[0];
  yfit[0] = PointTri[1];
  zfit[0] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[2] = PointTri[0];
  yfit[2] = PointTri[1];
  zfit[2] = PointTri[2];
  /* %%%%% 第2、3个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[4], &PlaneParaOut_data[8], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  d_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[4] = PointTri[0];
  yfit[4] = PointTri[1];
  zfit[4] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[5] = PointTri[0];
  yfit[5] = PointTri[1];
  zfit[5] = PointTri[2];
  /* %%%%% 第3、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[8], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  d_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[6] = PointTri[0];
  yfit[6] = PointTri[1];
  zfit[6] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[7] = PointTri[0];
  yfit[7] = PointTri[1];
  zfit[7] = PointTri[2];
  /* %%%%% 第1、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  d_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[1] = PointTri[0];
  yfit[1] = PointTri[1];
  zfit[1] = PointTri[2];
  d_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[3] = PointTri[0];
  yfit[3] = PointTri[1];
  zfit[3] = PointTri[2];
  /*  取八个点 */
  for (i = 0; i < 24; i++) {
    i2 = iv[i];
    b_xfit[3 * i] = xfit[i2];
    b_xfit[3 * i + 1] = yfit[i2];
    b_xfit[3 * i + 2] = zfit[i2];
  }
  for (i = 0; i < 8; i++) {
    c = 3 * b_iv[i];
    Pdd[3 * i] = b_xfit[c];
    Pdd[3 * i + 1] = b_xfit[c + 1];
    Pdd[3 * i + 2] = b_xfit[c + 2];
  }
  /*  计算投影点 */
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1, &Pdd[0], &Pdd[6],
                                               &a, &b, &d);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1, &Pdd[3], &Pdd[9],
                                               &xN2, &yN2, &zN2);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2, &Pdd[0], &Pdd[6],
                                               &xN3, &yN3, &zN3);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2, &Pdd[3], &Pdd[9],
                                               &xN4, &yN4, &zN4);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1, &Pdd[12], &Pdd[15],
                                               &xN5, &yN5, &zN5);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2, &Pdd[12], &Pdd[15],
                                               &xN6, &yN6, &zN6);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1, &Pdd[18], &Pdd[21],
                                               &xN7, &yN7, &zN7);
  foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2, &Pdd[18], &Pdd[21],
                                               &xN8, &yN8, &zN8);
  b_xfit[0] = a;
  b_xfit[3] = xN2;
  b_xfit[6] = xN3;
  b_xfit[9] = xN2;
  b_xfit[12] = xN3;
  b_xfit[15] = xN4;
  b_xfit[18] = a;
  b_xfit[21] = xN3;
  b_xfit[24] = xN5;
  b_xfit[27] = xN3;
  b_xfit[30] = xN5;
  b_xfit[33] = xN6;
  b_xfit[36] = xN5;
  b_xfit[39] = xN6;
  b_xfit[42] = xN7;
  b_xfit[45] = xN6;
  b_xfit[48] = xN7;
  b_xfit[51] = xN8;
  b_xfit[54] = xN2;
  b_xfit[57] = xN4;
  b_xfit[60] = xN7;
  b_xfit[63] = xN4;
  b_xfit[66] = xN7;
  b_xfit[69] = xN8;
  b_xfit[1] = b;
  b_xfit[4] = yN2;
  b_xfit[7] = yN3;
  b_xfit[10] = yN2;
  b_xfit[13] = yN3;
  b_xfit[16] = yN4;
  b_xfit[19] = b;
  b_xfit[22] = yN3;
  b_xfit[25] = yN5;
  b_xfit[28] = yN3;
  b_xfit[31] = yN5;
  b_xfit[34] = yN6;
  b_xfit[37] = yN5;
  b_xfit[40] = yN6;
  b_xfit[43] = yN7;
  b_xfit[46] = yN6;
  b_xfit[49] = yN7;
  b_xfit[52] = yN8;
  b_xfit[55] = yN2;
  b_xfit[58] = yN4;
  b_xfit[61] = yN7;
  b_xfit[64] = yN4;
  b_xfit[67] = yN7;
  b_xfit[70] = yN8;
  b_xfit[2] = d;
  b_xfit[5] = zN2;
  b_xfit[8] = zN3;
  b_xfit[11] = zN2;
  b_xfit[14] = zN3;
  b_xfit[17] = zN4;
  b_xfit[20] = d;
  b_xfit[23] = zN3;
  b_xfit[26] = zN5;
  b_xfit[29] = zN3;
  b_xfit[32] = zN5;
  b_xfit[35] = zN6;
  b_xfit[38] = zN5;
  b_xfit[41] = zN6;
  b_xfit[44] = zN7;
  b_xfit[47] = zN6;
  b_xfit[50] = zN7;
  b_xfit[53] = zN8;
  b_xfit[56] = zN2;
  b_xfit[59] = zN4;
  b_xfit[62] = zN7;
  b_xfit[65] = zN4;
  b_xfit[68] = zN7;
  b_xfit[71] = zN8;
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 24;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  PlaneParaOut_data = TrianglePoints->data;
  for (i = 0; i < 72; i++) {
    PlaneParaOut_data[i] = b_xfit[i];
  }
}

/*
 * File trailer for planefit4.c
 *
 * [EOF]
 */
