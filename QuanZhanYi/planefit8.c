/*
 * File: planefit8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
 */

/* Include Files */
#include "planefit8.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "mean.h"
#include "mldivide.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Points 输入点 3*n
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  PP 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                const emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                const emxArray_real_T *Points4
 *                const emxArray_real_T *Points5
 *                const emxArray_real_T *Points6
 *                const emxArray_real_T *Points7
 *                const emxArray_real_T *Points8
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 * Return Type  : void
 */
void planefit8(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const emxArray_real_T *Points5, const emxArray_real_T *Points6,
               const emxArray_real_T *Points7, const emxArray_real_T *Points8,
               const double P_bound1[3], const double P_bound2[3],
               emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints)
{
  static const signed char b_iv[48] = {
      0,  7,  8,  7,  8,  15, 0,  1,  9,  0,  8,  9, 1,  2,  9,  2,
      9,  10, 2,  3,  10, 3,  10, 11, 3,  4,  11, 4, 11, 12, 4,  5,
      12, 5,  12, 13, 5,  6,  13, 6,  13, 14, 6,  7, 14, 7,  14, 15};
  cell_wrap_6 PointAll[8];
  cell_wrap_6 r;
  cell_wrap_6 r1;
  cell_wrap_6 r2;
  cell_wrap_6 r3;
  cell_wrap_6 r4;
  cell_wrap_6 r5;
  cell_wrap_6 r6;
  cell_wrap_6 r7;
  emxArray_real_T *a__1;
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_pointss;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  emxArray_real_T *y;
  double PP[48];
  double PlaneParaOutP_data[32];
  double cross_vectors[24];
  double A[9];
  double PlaneParaOut1[3];
  double coefficients[3];
  double bb[2];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  const double *Points5_data;
  const double *Points6_data;
  const double *Points7_data;
  const double *Points8_data;
  double PlaneParaOut1_idx_2;
  double PlaneParaOut1_idx_3;
  double PlaneParaOut2_idx_1;
  double PlaneParaOut2_idx_2;
  double PlaneParaOut2_idx_3;
  double a;
  double b;
  double b_c;
  double c_c;
  double d;
  double *PlaneParaOut_data;
  double *b_pointss_data;
  double *pointss_data;
  double *x_data;
  double *y_data;
  int c;
  int i;
  int k;
  int xi;
  signed char b_i;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Points8_data = Points8->data;
  Points7_data = Points7->data;
  Points6_data = Points6->data;
  Points5_data = Points5->data;
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_6(&r);
  xi = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, xi);
  c = 3 * Points1->size[1];
  for (xi = 0; xi < c; xi++) {
    r.f1->data[xi] = Points1_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r1);
  xi = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, xi);
  c = 3 * Points2->size[1];
  for (xi = 0; xi < c; xi++) {
    r1.f1->data[xi] = Points2_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r2);
  xi = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, xi);
  c = 3 * Points3->size[1];
  for (xi = 0; xi < c; xi++) {
    r2.f1->data[xi] = Points3_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r3);
  xi = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, xi);
  c = 3 * Points4->size[1];
  for (xi = 0; xi < c; xi++) {
    r3.f1->data[xi] = Points4_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r4);
  xi = r4.f1->size[0] * r4.f1->size[1];
  r4.f1->size[0] = 3;
  r4.f1->size[1] = Points5->size[1];
  emxEnsureCapacity_real_T(r4.f1, xi);
  c = 3 * Points5->size[1];
  for (xi = 0; xi < c; xi++) {
    r4.f1->data[xi] = Points5_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r5);
  xi = r5.f1->size[0] * r5.f1->size[1];
  r5.f1->size[0] = 3;
  r5.f1->size[1] = Points6->size[1];
  emxEnsureCapacity_real_T(r5.f1, xi);
  c = 3 * Points6->size[1];
  for (xi = 0; xi < c; xi++) {
    r5.f1->data[xi] = Points6_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r6);
  xi = r6.f1->size[0] * r6.f1->size[1];
  r6.f1->size[0] = 3;
  r6.f1->size[1] = Points7->size[1];
  emxEnsureCapacity_real_T(r6.f1, xi);
  c = 3 * Points7->size[1];
  for (xi = 0; xi < c; xi++) {
    r6.f1->data[xi] = Points7_data[xi];
  }
  emxInitStruct_cell_wrap_6(&r7);
  xi = r7.f1->size[0] * r7.f1->size[1];
  r7.f1->size[0] = 3;
  r7.f1->size[1] = Points8->size[1];
  emxEnsureCapacity_real_T(r7.f1, xi);
  c = 3 * Points8->size[1];
  for (xi = 0; xi < c; xi++) {
    r7.f1->data[xi] = Points8_data[xi];
  }
  emxInitMatrix_cell_wrap_61(PointAll);
  emxCopyStruct_cell_wrap_6(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_6(&r);
  emxCopyStruct_cell_wrap_6(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_6(&r1);
  emxCopyStruct_cell_wrap_6(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_6(&r2);
  emxCopyStruct_cell_wrap_6(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_6(&r3);
  emxCopyStruct_cell_wrap_6(&PointAll[4], &r4);
  emxFreeStruct_cell_wrap_6(&r4);
  emxCopyStruct_cell_wrap_6(&PointAll[5], &r5);
  emxFreeStruct_cell_wrap_6(&r5);
  emxCopyStruct_cell_wrap_6(&PointAll[6], &r6);
  emxFreeStruct_cell_wrap_6(&r6);
  emxCopyStruct_cell_wrap_6(&PointAll[7], &r7);
  emxFreeStruct_cell_wrap_6(&r7);
  xi = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 8;
  emxEnsureCapacity_real_T(PlaneParaOut, xi);
  PlaneParaOut_data = PlaneParaOut->data;
  for (xi = 0; xi < 32; xi++) {
    PlaneParaOut_data[xi] = 0.0;
  }
  emxInit_real_T(&x, 1);
  emxInit_real_T(&y, 1);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&b_pointss, 2);
  for (i = 0; i < 8; i++) {
    /*  平面拟合 */
    c = PointAll[i].f1->size[1];
    xi = x->size[0];
    x->size[0] = PointAll[i].f1->size[1];
    emxEnsureCapacity_real_T(x, xi);
    x_data = x->data;
    xi = y->size[0];
    y->size[0] = PointAll[i].f1->size[1];
    emxEnsureCapacity_real_T(y, xi);
    y_data = y->data;
    for (xi = 0; xi < c; xi++) {
      x_data[xi] = PointAll[i].f1->data[3 * xi];
      y_data[xi] = PointAll[i].f1->data[3 * xi + 1];
    }
    c = PointAll[i].f1->size[1];
    xi = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, xi);
    pointss_data = pointss->data;
    for (xi = 0; xi < 3; xi++) {
      for (k = 0; k < c; k++) {
        pointss_data[k + pointss->size[0] * xi] =
            PointAll[i].f1->data[xi + 3 * k];
      }
    }
    /*  Fit a plane through the points */
    mean(pointss, coefficients);
    xi = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, xi);
    b_pointss_data = b_pointss->data;
    c = pointss->size[0];
    for (xi = 0; xi < 3; xi++) {
      for (k = 0; k < c; k++) {
        b_pointss_data[k + b_pointss->size[0] * xi] =
            pointss_data[k + pointss->size[0] * xi] - coefficients[xi];
      }
    }
    xi = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, xi);
    pointss_data = pointss->data;
    c = b_pointss->size[0];
    for (xi = 0; xi < 3; xi++) {
      for (k = 0; k < c; k++) {
        pointss_data[k + pointss->size[0] * xi] =
            b_pointss_data[k + b_pointss->size[0] * xi];
      }
    }
    d_svd(pointss, a__1, b_pointss, A);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 *
                        acos(fabs((A[6] * 0.0 + A[7] * 0.0) + A[8]))) < 0.5) {
      c = 0;
      polyfit(x, y, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      b = -1.0;
      d = bb[1];
    } else {
      /*  构建矩阵 A 和向量 b */
      /*  使用最小二乘法拟合平面 */
      xi = pointss->size[0] * pointss->size[1];
      pointss->size[0] = x->size[0];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, xi);
      pointss_data = pointss->data;
      c = x->size[0];
      for (xi = 0; xi < c; xi++) {
        pointss_data[xi] = x_data[xi];
      }
      c = y->size[0];
      for (xi = 0; xi < c; xi++) {
        pointss_data[xi + pointss->size[0]] = y_data[xi];
      }
      c = x->size[0];
      for (xi = 0; xi < c; xi++) {
        pointss_data[xi + pointss->size[0] * 2] = 1.0;
      }
      c = PointAll[i].f1->size[1];
      xi = x->size[0];
      x->size[0] = PointAll[i].f1->size[1];
      emxEnsureCapacity_real_T(x, xi);
      x_data = x->data;
      for (xi = 0; xi < c; xi++) {
        x_data[xi] = PointAll[i].f1->data[3 * xi + 2];
      }
      mldivide(pointss, x, coefficients);
      a = coefficients[0];
      b = coefficients[1];
      d = coefficients[2];
      c = -1;
    }
    PlaneParaOut_data[4 * i] = a;
    PlaneParaOut_data[4 * i + 1] = b;
    PlaneParaOut_data[4 * i + 2] = c;
    PlaneParaOut_data[4 * i + 3] = d;
  }
  emxFree_real_T(&b_pointss);
  emxFreeMatrix_cell_wrap_61(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&pointss);
  emxFree_real_T(&y);
  emxFree_real_T(&x);
  emxInit_real_T(&b_PlaneParaOut, 2);
  xi = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 8;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, xi);
  x_data = b_PlaneParaOut->data;
  for (xi = 0; xi < 4; xi++) {
    for (k = 0; k < 8; k++) {
      x_data[k + b_PlaneParaOut->size[0] * xi] = PlaneParaOut_data[xi + 4 * k];
    }
  }
  for (xi = 0; xi < 32; xi++) {
    PlaneParaOutP_data[xi] = x_data[xi];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&cross_vectors[0], 0, 24U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (i = 0; i < 8; i++) {
    if (i + 1 < 8) {
      a = PlaneParaOutP_data[i + 17];
      b = PlaneParaOutP_data[i + 9];
      d = PlaneParaOutP_data[i + 16];
      PlaneParaOut2_idx_1 = PlaneParaOutP_data[i + 8];
      cross_vectors[i] = PlaneParaOut2_idx_1 * a - b * d;
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[i + 1];
      cross_vectors[i + 8] =
          PlaneParaOut1_idx_2 * d - PlaneParaOutP_data[i] * a;
      cross_vectors[i + 16] =
          PlaneParaOutP_data[i] * b - PlaneParaOut1_idx_2 * PlaneParaOut2_idx_1;
    } else {
      cross_vectors[7] = PlaneParaOutP_data[15] * PlaneParaOutP_data[16] -
                         PlaneParaOutP_data[8] * PlaneParaOutP_data[23];
      cross_vectors[15] = PlaneParaOutP_data[0] * PlaneParaOutP_data[23] -
                          PlaneParaOutP_data[7] * PlaneParaOutP_data[16];
      cross_vectors[23] = PlaneParaOutP_data[7] * PlaneParaOutP_data[8] -
                          PlaneParaOutP_data[0] * PlaneParaOutP_data[15];
      /*  最后一个与第一个相邻 */
    }
    a = 3.3121686421112381E-170;
    b = fabs(cross_vectors[i]);
    if (b > 3.3121686421112381E-170) {
      PlaneParaOut2_idx_1 = 1.0;
      a = b;
    } else {
      d = b / 3.3121686421112381E-170;
      PlaneParaOut2_idx_1 = d * d;
    }
    b = fabs(cross_vectors[i + 8]);
    if (b > a) {
      d = a / b;
      PlaneParaOut2_idx_1 = PlaneParaOut2_idx_1 * d * d + 1.0;
      a = b;
    } else {
      d = b / a;
      PlaneParaOut2_idx_1 += d * d;
    }
    b = fabs(cross_vectors[i + 16]);
    if (b > a) {
      d = a / b;
      PlaneParaOut2_idx_1 = PlaneParaOut2_idx_1 * d * d + 1.0;
      a = b;
    } else {
      d = b / a;
      PlaneParaOut2_idx_1 += d * d;
    }
    PlaneParaOut2_idx_1 = a * sqrt(PlaneParaOut2_idx_1);
    cross_vectors[i] /= PlaneParaOut2_idx_1;
    cross_vectors[i + 8] /= PlaneParaOut2_idx_1;
    cross_vectors[i + 16] /= PlaneParaOut2_idx_1;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  PlaneParaOut2_idx_1 = cross_vectors[0];
  PlaneParaOut1_idx_2 = cross_vectors[8];
  PlaneParaOut2_idx_2 = cross_vectors[16];
  for (i = 0; i < 7; i++) {
    a = cross_vectors[i + 1];
    b = cross_vectors[i + 9];
    d = cross_vectors[i + 17];
    if ((PlaneParaOut2_idx_1 * a + PlaneParaOut1_idx_2 * b) +
            PlaneParaOut2_idx_2 * d <
        0.0) {
      /*  如果方向相反 */
      cross_vectors[i + 1] = -a;
      b = -b;
      cross_vectors[i + 9] = b;
      d = -d;
      cross_vectors[i + 17] = d;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  /*  计算顶面方程的 d 值 */
  b_c = 0.0;
  /*  计算底面方程的 d 值 */
  c_c = 0.0;
  for (xi = 0; xi < 3; xi++) {
    c = xi << 3;
    PlaneParaOut2_idx_1 = cross_vectors[c];
    for (k = 0; k < 7; k++) {
      PlaneParaOut2_idx_1 += cross_vectors[(c + k) + 1];
    }
    PlaneParaOut2_idx_1 /= 8.0;
    coefficients[xi] = PlaneParaOut2_idx_1;
    b_c += PlaneParaOut2_idx_1 * P_bound1[xi];
    c_c += PlaneParaOut2_idx_1 * P_bound2[xi];
  }
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 48U * sizeof(double));
  /*  计算顶面和底面的8个顶点 */
  PlaneParaOut2_idx_1 = coefficients[0];
  PlaneParaOut1_idx_2 = coefficients[1];
  PlaneParaOut2_idx_2 = coefficients[2];
  A[2] = PlaneParaOut2_idx_1;
  A[5] = PlaneParaOut1_idx_2;
  A[8] = PlaneParaOut2_idx_2;
  for (i = 0; i < 8; i++) {
    /*  顶面顶点 */
    if (i + 1 < 8) {
      a = PlaneParaOutP_data[i];
      b = PlaneParaOutP_data[i + 1];
      d = PlaneParaOutP_data[i + 8];
      PlaneParaOut2_idx_1 = PlaneParaOutP_data[i + 9];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[i + 16];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[i + 17];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[i + 24];
      PlaneParaOut2_idx_3 = PlaneParaOutP_data[i + 25];
    } else {
      a = PlaneParaOutP_data[7];
      b = PlaneParaOutP_data[0];
      d = PlaneParaOutP_data[15];
      PlaneParaOut2_idx_1 = PlaneParaOutP_data[8];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[23];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[16];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[31];
      PlaneParaOut2_idx_3 = PlaneParaOutP_data[24];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = a;
    A[1] = b;
    A[3] = d;
    A[4] = PlaneParaOut2_idx_1;
    A[6] = PlaneParaOut1_idx_2;
    A[7] = PlaneParaOut2_idx_2;
    PlaneParaOut1[0] = -PlaneParaOut1_idx_3;
    PlaneParaOut1[1] = -PlaneParaOut2_idx_3;
    PlaneParaOut1[2] = b_c;
    c_mldivide(A, PlaneParaOut1, coefficients);
    PP[i] = coefficients[0];
    PP[i + 16] = coefficients[1];
    PP[i + 32] = coefficients[2];
    /*  求底面和两个相邻侧面的交线 */
    PlaneParaOut1[0] = -PlaneParaOut1_idx_3;
    PlaneParaOut1[1] = -PlaneParaOut2_idx_3;
    PlaneParaOut1[2] = c_c;
    c_mldivide(A, PlaneParaOut1, coefficients);
    PP[i + 8] = coefficients[0];
    PP[i + 24] = coefficients[1];
    PP[i + 40] = coefficients[2];
  }
  xi = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 48;
  emxEnsureCapacity_real_T(TrianglePoints, xi);
  x_data = TrianglePoints->data;
  for (xi = 0; xi < 48; xi++) {
    b_i = b_iv[xi];
    x_data[3 * xi] = PP[b_i];
    x_data[3 * xi + 1] = PP[b_i + 16];
    x_data[3 * xi + 2] = PP[b_i + 32];
  }
}

/*
 * File trailer for planefit8.c
 *
 * [EOF]
 */
