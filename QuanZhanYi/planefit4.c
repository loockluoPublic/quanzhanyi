/*
 * File: planefit4.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:51:24
 */

/* Include Files */
#include "planefit4.h"
#include "CrossLine.h"
#include "GenerateTrianglePoints.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "find.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "nchoosek.h"
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
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[4]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void b_planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, const emxArray_real_T *Points4,
                 const double BoundPoint1[3], const double BoundPoint2[3],
                 double distanceThreshold, emxArray_real_T *PlaneParaOut,
                 emxArray_real_T *TrianglePoints, double MaxDis[4],
                 emxArray_real_T *distancesFianal)
{
  static const signed char b_iv[8] = {0, 1, 2, 5, 8, 15, 16, 17};
  cell_wrap_1 distancesFianal1[4];
  cell_wrap_1 inlierIdxFinal[4];
  cell_wrap_1 r10;
  cell_wrap_1 r11;
  cell_wrap_1 r4;
  cell_wrap_1 r5;
  cell_wrap_1 r6;
  cell_wrap_1 r7;
  cell_wrap_1 r8;
  cell_wrap_1 r9;
  cell_wrap_4 PointAll[4];
  cell_wrap_4 r;
  cell_wrap_4 r1;
  cell_wrap_4 r2;
  cell_wrap_4 r3;
  emxArray_boolean_T *b_distances;
  emxArray_int32_T *r12;
  emxArray_real_T *B;
  emxArray_real_T *C;
  emxArray_real_T *Cnum;
  emxArray_real_T *a__1;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *distances;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  double b_xfit[72];
  double Pdd[24];
  double samplePoints[9];
  double samplePoints_data[9];
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
  double K;
  double K_tmp;
  double PP3_idx_0;
  double PP3_idx_1;
  double PP3_idx_2;
  double PP4_idx_0;
  double PP4_idx_1;
  double PP4_idx_2;
  double PP5_idx_1;
  double PP5_idx_2;
  double PP6_idx_0;
  double PP6_idx_1;
  double PP6_idx_2;
  double PP7_idx_0;
  double PP7_idx_1;
  double PP7_idx_2;
  double a;
  double a_tmp;
  double b;
  double b_a_tmp;
  double bestDist;
  double c_a_tmp;
  double d;
  double *C_data;
  double *Cnum_data;
  double *PlaneParaOut_data;
  double *distances_data;
  double *pointss_data;
  int b_i;
  int b_j;
  int b_loop_ub;
  int b_result_idx_1;
  int c;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i;
  int j;
  int loop_ub;
  int nx;
  int result;
  int result_idx_1;
  int *r13;
  signed char i1;
  signed char sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T *b_distances_data;
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_4(&r);
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, i);
  nx = 3 * Points1->size[1];
  for (i = 0; i < nx; i++) {
    r.f1->data[i] = Points1_data[i];
  }
  emxInitStruct_cell_wrap_4(&r1);
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, i);
  nx = 3 * Points2->size[1];
  for (i = 0; i < nx; i++) {
    r1.f1->data[i] = Points2_data[i];
  }
  emxInitStruct_cell_wrap_4(&r2);
  i = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, i);
  nx = 3 * Points3->size[1];
  for (i = 0; i < nx; i++) {
    r2.f1->data[i] = Points3_data[i];
  }
  emxInitStruct_cell_wrap_4(&r3);
  i = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, i);
  nx = 3 * Points4->size[1];
  for (i = 0; i < nx; i++) {
    r3.f1->data[i] = Points4_data[i];
  }
  emxInitMatrix_cell_wrap_41(PointAll);
  emxCopyStruct_cell_wrap_4(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_4(&r);
  emxCopyStruct_cell_wrap_4(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_4(&r1);
  emxCopyStruct_cell_wrap_4(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_4(&r2);
  emxCopyStruct_cell_wrap_4(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_4(&r3);
  i = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(PlaneParaOut, i);
  PlaneParaOut_data = PlaneParaOut->data;
  for (i = 0; i < 16; i++) {
    PlaneParaOut_data[i] = 0.0;
  }
  emxInitStruct_cell_wrap_1(&r4);
  i = r4.f1->size[0] * r4.f1->size[1];
  r4.f1->size[0] = 1;
  r4.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r4.f1, i);
  r4.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r5);
  i = r5.f1->size[0] * r5.f1->size[1];
  r5.f1->size[0] = 1;
  r5.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r5.f1, i);
  r5.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r6);
  i = r6.f1->size[0] * r6.f1->size[1];
  r6.f1->size[0] = 1;
  r6.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r6.f1, i);
  r6.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r7);
  i = r7.f1->size[0] * r7.f1->size[1];
  r7.f1->size[0] = 1;
  r7.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r7.f1, i);
  r7.f1->data[0] = 4.0;
  emxInitMatrix_cell_wrap_11(inlierIdxFinal);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[0], &r4);
  emxFreeStruct_cell_wrap_1(&r4);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[1], &r5);
  emxFreeStruct_cell_wrap_1(&r5);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[2], &r6);
  emxFreeStruct_cell_wrap_1(&r6);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[3], &r7);
  emxFreeStruct_cell_wrap_1(&r7);
  emxInitStruct_cell_wrap_1(&r8);
  i = r8.f1->size[0] * r8.f1->size[1];
  r8.f1->size[0] = 1;
  r8.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r8.f1, i);
  r8.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r9);
  i = r9.f1->size[0] * r9.f1->size[1];
  r9.f1->size[0] = 1;
  r9.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r9.f1, i);
  r9.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r10);
  i = r10.f1->size[0] * r10.f1->size[1];
  r10.f1->size[0] = 1;
  r10.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r10.f1, i);
  r10.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r11);
  i = r11.f1->size[0] * r11.f1->size[1];
  r11.f1->size[0] = 1;
  r11.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r11.f1, i);
  r11.f1->data[0] = 4.0;
  emxInitMatrix_cell_wrap_11(distancesFianal1);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[0], &r8);
  emxFreeStruct_cell_wrap_1(&r8);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[1], &r9);
  emxFreeStruct_cell_wrap_1(&r9);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[2], &r10);
  emxFreeStruct_cell_wrap_1(&r10);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[3], &r11);
  emxFreeStruct_cell_wrap_1(&r11);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&x, 1);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&B, 2);
  emxInit_int32_T(&r12);
  emxInit_real_T(&b_inlierPoints, 1);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_pointss, 2);
  for (b_i = 0; b_i < 4; b_i++) {
    /*  平面拟合 */
    nx = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        pointss_data[j + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * j];
      }
    }
    c = pointss->size[0];
    if (c < 3) {
      c = 3;
    }
    if (pointss->size[0] == 0) {
      c = 0;
    }
    if (c < 1) {
      Cnum->size[0] = 1;
      Cnum->size[1] = 0;
    } else {
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = c;
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      nx = c - 1;
      for (i = 0; i <= nx; i++) {
        Cnum_data[i] = (double)i + 1.0;
      }
    }
    bestDist = 99999.0;
    /*  最优内点距离 */
    nchoosek(Cnum, C);
    C_data = C->data;
    c = C->size[0];
    nx = C->size[1];
    if (c >= nx) {
      nx = c;
    }
    if (C->size[0] == 0) {
      c = 0;
    } else {
      c = nx;
    }
    if (c - 1 >= 0) {
      loop_ub = C->size[1];
      b_loop_ub = C->size[1];
      c_loop_ub = C->size[1];
      if (pointss->size[0] != 0) {
        result = pointss->size[0];
      } else {
        result = 0;
      }
      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        i1 = 3;
      } else {
        i1 = 0;
      }
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        sizes_idx_1 = 1;
      } else {
        sizes_idx_1 = 0;
      }
      result_idx_1 = i1;
      b_result_idx_1 = sizes_idx_1;
      d_loop_ub = i1;
      e_loop_ub = sizes_idx_1;
    }
    for (b_j = 0; b_j < c; b_j++) {
      /*  随机选择三个点 */
      nx = C->size[1];
      for (i = 0; i < 3; i++) {
        for (j = 0; j < loop_ub; j++) {
          samplePoints_data[j + nx * i] = pointss_data
              [((int)C_data[b_j + C->size[0] * j] + pointss->size[0] * i) - 1];
        }
      }
      /*  计算平面模型 */
      for (i = 0; i < b_loop_ub; i++) {
        samplePoints[i] = samplePoints_data[i];
        samplePoints[i + 3] = samplePoints_data[i + nx];
      }
      samplePoints[6] = 1.0;
      samplePoints[7] = 1.0;
      samplePoints[8] = 1.0;
      for (i = 0; i < c_loop_ub; i++) {
        PP2[i] = samplePoints_data[i + nx * 2];
      }
      b_mldivide(samplePoints, PP2, coefficients);
      a = sqrt((coefficients[0] * coefficients[0] +
                coefficients[1] * coefficients[1]) +
               1.0);
      b = coefficients[0];
      d = coefficients[1];
      PP4_idx_2 = coefficients[2];
      i = B->size[0] * B->size[1];
      B->size[0] = result;
      B->size[1] = result_idx_1 + b_result_idx_1;
      emxEnsureCapacity_real_T(B, i);
      distances_data = B->data;
      for (i = 0; i < d_loop_ub; i++) {
        for (j = 0; j < result; j++) {
          distances_data[j + B->size[0] * i] = pointss_data[j + result * i];
        }
      }
      for (i = 0; i < e_loop_ub; i++) {
        for (j = 0; j < result; j++) {
          distances_data[j + B->size[0] * result_idx_1] = 1.0;
        }
      }
      nx = B->size[0];
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = B->size[0];
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      for (j = 0; j < nx; j++) {
        Cnum_data[j] =
            ((b * distances_data[j] + d * distances_data[B->size[0] + j]) -
             distances_data[(B->size[0] << 1) + j]) +
            PP4_idx_2 * distances_data[3 * B->size[0] + j];
      }
      nx = Cnum->size[1];
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      distances->size[1] = Cnum->size[1];
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      for (j = 0; j < nx; j++) {
        distances_data[j] = fabs(Cnum_data[j]);
      }
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      nx = distances->size[1] - 1;
      for (i = 0; i <= nx; i++) {
        distances_data[i] /= a;
      }
      /*  确定内点 */
      /*  更新最优平面模型 */
      a = mean(distances);
      if (a < bestDist) {
        bestDist = a;
        i = b_distances->size[0] * b_distances->size[1];
        b_distances->size[0] = 1;
        b_distances->size[1] = distances->size[1];
        emxEnsureCapacity_boolean_T(b_distances, i);
        b_distances_data = b_distances->data;
        nx = distances->size[1];
        for (i = 0; i < nx; i++) {
          b_distances_data[i] = (distances_data[i] < distanceThreshold);
        }
        eml_find(b_distances, r12);
        r13 = r12->data;
        i = inlierIdxFinal[b_i].f1->size[0] * inlierIdxFinal[b_i].f1->size[1];
        inlierIdxFinal[b_i].f1->size[0] = 1;
        inlierIdxFinal[b_i].f1->size[1] = r12->size[1];
        emxEnsureCapacity_real_T(inlierIdxFinal[b_i].f1, i);
        nx = r12->size[1];
        for (i = 0; i < nx; i++) {
          inlierIdxFinal[b_i].f1->data[i] = r13[i];
        }
        i = distancesFianal1[b_i].f1->size[0] *
            distancesFianal1[b_i].f1->size[1];
        distancesFianal1[b_i].f1->size[0] = 1;
        distancesFianal1[b_i].f1->size[1] = distances->size[1];
        emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
        nx = distances->size[1];
        for (i = 0; i < nx; i++) {
          distancesFianal1[b_i].f1->data[i] = distances_data[i];
        }
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Cnum_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        Cnum_data[j + inlierPoints->size[0] * i] = pointss_data
            [((int)inlierIdxFinal[b_i].f1->data[j] + pointss->size[0] * i) - 1];
      }
    }
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = x->size[0];
    x->size[0] = inlierIdxFinal[b_i].f1->size[1];
    emxEnsureCapacity_real_T(x, i);
    distances_data = x->data;
    for (i = 0; i < nx; i++) {
      distances_data[i] = Cnum_data[i];
    }
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < nx; i++) {
      pointss_data[i] = Cnum_data[i];
    }
    for (i = 0; i < nx; i++) {
      pointss_data[i + pointss->size[0]] = Cnum_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < nx; i++) {
      pointss_data[i + pointss->size[0] * 2] =
          Cnum_data[i + inlierPoints->size[0] * 2];
    }
    /*  Fit a plane through the points */
    b_mean(pointss, coefficients);
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    distances_data = b_pointss->data;
    nx = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        distances_data[j + b_pointss->size[0] * i] =
            pointss_data[j + pointss->size[0] * i] - coefficients[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    nx = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        pointss_data[j + pointss->size[0] * i] =
            distances_data[j + b_pointss->size[0] * i];
      }
    }
    b_svd(pointss, a__1, b_pointss, samplePoints);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 * acos(fabs((samplePoints[6] * 0.0 +
                                                    samplePoints[7] * 0.0) +
                                                   samplePoints[8]))) < 0.5) {
      c = 0;
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < nx; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0]];
      }
      polyfit(x, b_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      b = -1.0;
      d = bb[1];
    } else {
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = pointss->size[0] * pointss->size[1];
      pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, i);
      pointss_data = pointss->data;
      for (i = 0; i < nx; i++) {
        pointss_data[i] = Cnum_data[i];
      }
      for (i = 0; i < nx; i++) {
        pointss_data[i + pointss->size[0]] =
            Cnum_data[i + inlierPoints->size[0]];
      }
      nx = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < nx; i++) {
        pointss_data[i + pointss->size[0] * 2] = 1.0;
      }
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < nx; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(pointss, b_inlierPoints, coefficients);
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
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&b_inlierPoints);
  emxFree_int32_T(&r12);
  emxFree_real_T(&B);
  emxFreeMatrix_cell_wrap_41(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&C);
  emxFree_real_T(&pointss);
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Cnum_data = Cnum->data;
  nx = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < nx; i++) {
    Cnum_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  distances_data = distances->data;
  nx = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  distances_data = b_distancesFianal1->data;
  nx = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  distances_data = c_distancesFianal1->data;
  nx = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_11(inlierIdxFinal);
  MaxDis[0] = maximum(Cnum);
  emxFree_real_T(&Cnum);
  MaxDis[1] = maximum(distances);
  emxFree_real_T(&distances);
  MaxDis[2] = maximum(b_distancesFianal1);
  emxFree_real_T(&b_distancesFianal1);
  MaxDis[3] = maximum(c_distancesFianal1);
  emxFree_real_T(&c_distancesFianal1);
  i = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  distancesFianal->size[1] =
      ((distancesFianal1[0].f1->size[1] + distancesFianal1[1].f1->size[1]) +
       distancesFianal1[2].f1->size[1]) +
      distancesFianal1[3].f1->size[1];
  emxEnsureCapacity_real_T(distancesFianal, i);
  distances_data = distancesFianal->data;
  nx = distancesFianal1[0].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] = distancesFianal1[0].f1->data[i];
  }
  nx = distancesFianal1[1].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i + distancesFianal1[0].f1->size[1]] =
        distancesFianal1[1].f1->data[i];
  }
  nx = distancesFianal1[2].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[(i + distancesFianal1[0].f1->size[1]) +
                   distancesFianal1[1].f1->size[1]] =
        distancesFianal1[2].f1->data[i];
  }
  nx = distancesFianal1[3].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[((i + distancesFianal1[0].f1->size[1]) +
                    distancesFianal1[1].f1->size[1]) +
                   distancesFianal1[2].f1->size[1]] =
        distancesFianal1[3].f1->data[i];
  }
  emxFreeMatrix_cell_wrap_11(distancesFianal1);
  /*  平面方程的系数输出 */
  /* %%%%% 前2个面的交点 %%%% */
  /*  计算交线 */
  a = (b_maximum(x) + minimum(x)) / 2.0;
  emxFree_real_T(&x);
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[4], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[0] = PointTri[0];
  yfit[0] = PointTri[1];
  zfit[0] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[2] = PointTri[0];
  yfit[2] = PointTri[1];
  zfit[2] = PointTri[2];
  /* %%%%% 第2、3个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[4], &PlaneParaOut_data[8], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[4] = PointTri[0];
  yfit[4] = PointTri[1];
  zfit[4] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[5] = PointTri[0];
  yfit[5] = PointTri[1];
  zfit[5] = PointTri[2];
  /* %%%%% 第3、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[8], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[6] = PointTri[0];
  yfit[6] = PointTri[1];
  zfit[6] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[7] = PointTri[0];
  yfit[7] = PointTri[1];
  zfit[7] = PointTri[2];
  /* %%%%% 第1、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[1] = PointTri[0];
  yfit[1] = PointTri[1];
  zfit[1] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[3] = PointTri[0];
  yfit[3] = PointTri[1];
  zfit[3] = PointTri[2];
  /*  取八个点 */
  for (i = 0; i < 24; i++) {
    i1 = iv1[i];
    b_xfit[3 * i] = xfit[i1];
    b_xfit[3 * i + 1] = yfit[i1];
    b_xfit[3 * i + 2] = zfit[i1];
  }
  for (i = 0; i < 8; i++) {
    c = 3 * b_iv[i];
    Pdd[3 * i] = b_xfit[c];
    Pdd[3 * i + 1] = b_xfit[c + 1];
    Pdd[3 * i + 2] = b_xfit[c + 2];
  }
  /*  计算投影点 */
  /*  三个点定义 */
  /*  斜率计算 */
  a_tmp = Pdd[6] - Pdd[0];
  b_a_tmp = Pdd[7] - Pdd[1];
  c_a_tmp = Pdd[8] - Pdd[2];
  K_tmp = (a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp;
  K = -(((Pdd[0] - BoundPoint1[0]) * a_tmp +
         (Pdd[1] - BoundPoint1[1]) * b_a_tmp) +
        (Pdd[2] - BoundPoint1[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  coefficients[0] = K * a_tmp + Pdd[0];
  coefficients[1] = K * b_a_tmp + Pdd[1];
  coefficients[2] = K * c_a_tmp + Pdd[2];
  /*  三个点定义 */
  /*  斜率计算 */
  a = Pdd[9] - Pdd[3];
  d = Pdd[10] - Pdd[4];
  PP4_idx_2 = Pdd[11] - Pdd[5];
  b = (a * a + d * d) + PP4_idx_2 * PP4_idx_2;
  K = -(((Pdd[3] - BoundPoint1[0]) * a + (Pdd[4] - BoundPoint1[1]) * d) +
        (Pdd[5] - BoundPoint1[2]) * PP4_idx_2) /
      b;
  /*  P1点在轴线上的投影坐标 */
  PP2[0] = K * a + Pdd[3];
  PP2[1] = K * d + Pdd[4];
  PP2[2] = K * PP4_idx_2 + Pdd[5];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[0] - BoundPoint2[0]) * a_tmp +
         (Pdd[1] - BoundPoint2[1]) * b_a_tmp) +
        (Pdd[2] - BoundPoint2[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  PP3_idx_0 = K * a_tmp + Pdd[0];
  PP3_idx_1 = K * b_a_tmp + Pdd[1];
  PP3_idx_2 = K * c_a_tmp + Pdd[2];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[3] - BoundPoint2[0]) * a + (Pdd[4] - BoundPoint2[1]) * d) +
        (Pdd[5] - BoundPoint2[2]) * PP4_idx_2) /
      b;
  /*  P1点在轴线上的投影坐标 */
  PP4_idx_0 = K * a + Pdd[3];
  PP4_idx_1 = K * d + Pdd[4];
  PP4_idx_2 = K * PP4_idx_2 + Pdd[5];
  /*  三个点定义 */
  /*  斜率计算 */
  a_tmp = Pdd[15] - Pdd[12];
  b_a_tmp = Pdd[16] - Pdd[13];
  c_a_tmp = Pdd[17] - Pdd[14];
  K_tmp = (a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp;
  K = -(((Pdd[12] - BoundPoint1[0]) * a_tmp +
         (Pdd[13] - BoundPoint1[1]) * b_a_tmp) +
        (Pdd[14] - BoundPoint1[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  bestDist = K * a_tmp + Pdd[12];
  PP5_idx_1 = K * b_a_tmp + Pdd[13];
  PP5_idx_2 = K * c_a_tmp + Pdd[14];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[12] - BoundPoint2[0]) * a_tmp +
         (Pdd[13] - BoundPoint2[1]) * b_a_tmp) +
        (Pdd[14] - BoundPoint2[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  PP6_idx_0 = K * a_tmp + Pdd[12];
  PP6_idx_1 = K * b_a_tmp + Pdd[13];
  PP6_idx_2 = K * c_a_tmp + Pdd[14];
  /*  三个点定义 */
  /*  斜率计算 */
  a_tmp = Pdd[21] - Pdd[18];
  b_a_tmp = Pdd[22] - Pdd[19];
  c_a_tmp = Pdd[23] - Pdd[20];
  K_tmp = (a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp;
  K = -(((Pdd[18] - BoundPoint1[0]) * a_tmp +
         (Pdd[19] - BoundPoint1[1]) * b_a_tmp) +
        (Pdd[20] - BoundPoint1[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  PP7_idx_0 = K * a_tmp + Pdd[18];
  PP7_idx_1 = K * b_a_tmp + Pdd[19];
  PP7_idx_2 = K * c_a_tmp + Pdd[20];
  /*  三个点定义 */
  /*  斜率计算 */
  K = -(((Pdd[18] - BoundPoint2[0]) * a_tmp +
         (Pdd[19] - BoundPoint2[1]) * b_a_tmp) +
        (Pdd[20] - BoundPoint2[2]) * c_a_tmp) /
      K_tmp;
  /*  P1点在轴线上的投影坐标 */
  d = K * a_tmp + Pdd[18];
  b = K * b_a_tmp + Pdd[19];
  a = K * c_a_tmp + Pdd[20];
  b_xfit[0] = coefficients[0];
  b_xfit[3] = PP2[0];
  b_xfit[6] = PP3_idx_0;
  b_xfit[9] = PP2[0];
  b_xfit[12] = PP3_idx_0;
  b_xfit[15] = PP4_idx_0;
  b_xfit[18] = coefficients[0];
  b_xfit[21] = PP3_idx_0;
  b_xfit[24] = bestDist;
  b_xfit[27] = PP3_idx_0;
  b_xfit[30] = bestDist;
  b_xfit[33] = PP6_idx_0;
  b_xfit[36] = bestDist;
  b_xfit[39] = PP6_idx_0;
  b_xfit[42] = PP7_idx_0;
  b_xfit[45] = PP6_idx_0;
  b_xfit[48] = PP7_idx_0;
  b_xfit[51] = d;
  b_xfit[54] = PP2[0];
  b_xfit[57] = PP4_idx_0;
  b_xfit[60] = PP7_idx_0;
  b_xfit[63] = PP4_idx_0;
  b_xfit[66] = PP7_idx_0;
  b_xfit[69] = d;
  b_xfit[1] = coefficients[1];
  b_xfit[4] = PP2[1];
  b_xfit[7] = PP3_idx_1;
  b_xfit[10] = PP2[1];
  b_xfit[13] = PP3_idx_1;
  b_xfit[16] = PP4_idx_1;
  b_xfit[19] = coefficients[1];
  b_xfit[22] = PP3_idx_1;
  b_xfit[25] = PP5_idx_1;
  b_xfit[28] = PP3_idx_1;
  b_xfit[31] = PP5_idx_1;
  b_xfit[34] = PP6_idx_1;
  b_xfit[37] = PP5_idx_1;
  b_xfit[40] = PP6_idx_1;
  b_xfit[43] = PP7_idx_1;
  b_xfit[46] = PP6_idx_1;
  b_xfit[49] = PP7_idx_1;
  b_xfit[52] = b;
  b_xfit[55] = PP2[1];
  b_xfit[58] = PP4_idx_1;
  b_xfit[61] = PP7_idx_1;
  b_xfit[64] = PP4_idx_1;
  b_xfit[67] = PP7_idx_1;
  b_xfit[70] = b;
  b_xfit[2] = coefficients[2];
  b_xfit[5] = PP2[2];
  b_xfit[8] = PP3_idx_2;
  b_xfit[11] = PP2[2];
  b_xfit[14] = PP3_idx_2;
  b_xfit[17] = PP4_idx_2;
  b_xfit[20] = coefficients[2];
  b_xfit[23] = PP3_idx_2;
  b_xfit[26] = PP5_idx_2;
  b_xfit[29] = PP3_idx_2;
  b_xfit[32] = PP5_idx_2;
  b_xfit[35] = PP6_idx_2;
  b_xfit[38] = PP5_idx_2;
  b_xfit[41] = PP6_idx_2;
  b_xfit[44] = PP7_idx_2;
  b_xfit[47] = PP6_idx_2;
  b_xfit[50] = PP7_idx_2;
  b_xfit[53] = a;
  b_xfit[56] = PP2[2];
  b_xfit[59] = PP4_idx_2;
  b_xfit[62] = PP7_idx_2;
  b_xfit[65] = PP4_idx_2;
  b_xfit[68] = PP7_idx_2;
  b_xfit[71] = a;
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 24;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  distances_data = TrianglePoints->data;
  for (i = 0; i < 72; i++) {
    distances_data[i] = b_xfit[i];
  }
}

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
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[4]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const double BoundPoint1[3], const double BoundPoint2[3],
               double distanceThreshold, emxArray_real_T *PlaneParaOut,
               emxArray_real_T *TrianglePoints, double MaxDis[4],
               emxArray_real_T *distancesFianal)
{
  static const signed char b_iv[8] = {0, 1, 2, 5, 8, 15, 16, 17};
  cell_wrap_1 distancesFianal1[4];
  cell_wrap_1 inlierIdxFinal[4];
  cell_wrap_1 r10;
  cell_wrap_1 r11;
  cell_wrap_1 r4;
  cell_wrap_1 r5;
  cell_wrap_1 r6;
  cell_wrap_1 r7;
  cell_wrap_1 r8;
  cell_wrap_1 r9;
  cell_wrap_4 PointAll[4];
  cell_wrap_4 r;
  cell_wrap_4 r1;
  cell_wrap_4 r2;
  cell_wrap_4 r3;
  emxArray_boolean_T *b_distances;
  emxArray_int32_T *r12;
  emxArray_real_T *B;
  emxArray_real_T *C;
  emxArray_real_T *Cnum;
  emxArray_real_T *a__1;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *distances;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  emxArray_real_T *x;
  double b_xfit[72];
  double Pdd[24];
  double samplePoints[9];
  double samplePoints_data[9];
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
  double A_idx_3;
  double a;
  double b;
  double bestDist;
  double d;
  double xN3;
  double xN4;
  double xN5;
  double xN6;
  double xN7;
  double xN8;
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
  double *C_data;
  double *Cnum_data;
  double *PlaneParaOut_data;
  double *distances_data;
  double *pointss_data;
  int b_i;
  int b_j;
  int b_loop_ub;
  int b_result_idx_1;
  int c;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i;
  int j;
  int loop_ub;
  int nx;
  int result;
  int result_idx_1;
  int *r13;
  signed char i1;
  signed char sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T *b_distances_data;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_4(&r);
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, i);
  nx = 3 * Points1->size[1];
  for (i = 0; i < nx; i++) {
    r.f1->data[i] = Points1_data[i];
  }
  emxInitStruct_cell_wrap_4(&r1);
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, i);
  nx = 3 * Points2->size[1];
  for (i = 0; i < nx; i++) {
    r1.f1->data[i] = Points2_data[i];
  }
  emxInitStruct_cell_wrap_4(&r2);
  i = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, i);
  nx = 3 * Points3->size[1];
  for (i = 0; i < nx; i++) {
    r2.f1->data[i] = Points3_data[i];
  }
  emxInitStruct_cell_wrap_4(&r3);
  i = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, i);
  nx = 3 * Points4->size[1];
  for (i = 0; i < nx; i++) {
    r3.f1->data[i] = Points4_data[i];
  }
  emxInitMatrix_cell_wrap_41(PointAll);
  emxCopyStruct_cell_wrap_4(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_4(&r);
  emxCopyStruct_cell_wrap_4(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_4(&r1);
  emxCopyStruct_cell_wrap_4(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_4(&r2);
  emxCopyStruct_cell_wrap_4(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_4(&r3);
  i = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(PlaneParaOut, i);
  PlaneParaOut_data = PlaneParaOut->data;
  for (i = 0; i < 16; i++) {
    PlaneParaOut_data[i] = 0.0;
  }
  emxInitStruct_cell_wrap_1(&r4);
  i = r4.f1->size[0] * r4.f1->size[1];
  r4.f1->size[0] = 1;
  r4.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r4.f1, i);
  r4.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r5);
  i = r5.f1->size[0] * r5.f1->size[1];
  r5.f1->size[0] = 1;
  r5.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r5.f1, i);
  r5.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r6);
  i = r6.f1->size[0] * r6.f1->size[1];
  r6.f1->size[0] = 1;
  r6.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r6.f1, i);
  r6.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r7);
  i = r7.f1->size[0] * r7.f1->size[1];
  r7.f1->size[0] = 1;
  r7.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r7.f1, i);
  r7.f1->data[0] = 4.0;
  emxInitMatrix_cell_wrap_11(inlierIdxFinal);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[0], &r4);
  emxFreeStruct_cell_wrap_1(&r4);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[1], &r5);
  emxFreeStruct_cell_wrap_1(&r5);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[2], &r6);
  emxFreeStruct_cell_wrap_1(&r6);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[3], &r7);
  emxFreeStruct_cell_wrap_1(&r7);
  emxInitStruct_cell_wrap_1(&r8);
  i = r8.f1->size[0] * r8.f1->size[1];
  r8.f1->size[0] = 1;
  r8.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r8.f1, i);
  r8.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r9);
  i = r9.f1->size[0] * r9.f1->size[1];
  r9.f1->size[0] = 1;
  r9.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r9.f1, i);
  r9.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r10);
  i = r10.f1->size[0] * r10.f1->size[1];
  r10.f1->size[0] = 1;
  r10.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r10.f1, i);
  r10.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r11);
  i = r11.f1->size[0] * r11.f1->size[1];
  r11.f1->size[0] = 1;
  r11.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r11.f1, i);
  r11.f1->data[0] = 4.0;
  emxInitMatrix_cell_wrap_11(distancesFianal1);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[0], &r8);
  emxFreeStruct_cell_wrap_1(&r8);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[1], &r9);
  emxFreeStruct_cell_wrap_1(&r9);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[2], &r10);
  emxFreeStruct_cell_wrap_1(&r10);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[3], &r11);
  emxFreeStruct_cell_wrap_1(&r11);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&x, 1);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&B, 2);
  emxInit_int32_T(&r12);
  emxInit_real_T(&b_inlierPoints, 1);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_pointss, 2);
  for (b_i = 0; b_i < 4; b_i++) {
    /*  平面拟合 */
    nx = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        pointss_data[j + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * j];
      }
    }
    c = pointss->size[0];
    if (c < 3) {
      c = 3;
    }
    if (pointss->size[0] == 0) {
      c = 0;
    }
    if (c < 1) {
      Cnum->size[0] = 1;
      Cnum->size[1] = 0;
    } else {
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = c;
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      nx = c - 1;
      for (i = 0; i <= nx; i++) {
        Cnum_data[i] = (double)i + 1.0;
      }
    }
    bestDist = 99999.0;
    /*  最优内点距离 */
    nchoosek(Cnum, C);
    C_data = C->data;
    c = C->size[0];
    nx = C->size[1];
    if (c >= nx) {
      nx = c;
    }
    if (C->size[0] == 0) {
      c = 0;
    } else {
      c = nx;
    }
    if (c - 1 >= 0) {
      loop_ub = C->size[1];
      b_loop_ub = C->size[1];
      c_loop_ub = C->size[1];
      if (pointss->size[0] != 0) {
        result = pointss->size[0];
      } else {
        result = 0;
      }
      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        i1 = 3;
      } else {
        i1 = 0;
      }
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        sizes_idx_1 = 1;
      } else {
        sizes_idx_1 = 0;
      }
      result_idx_1 = i1;
      b_result_idx_1 = sizes_idx_1;
      d_loop_ub = i1;
      e_loop_ub = sizes_idx_1;
    }
    for (b_j = 0; b_j < c; b_j++) {
      /*  随机选择三个点 */
      nx = C->size[1];
      for (i = 0; i < 3; i++) {
        for (j = 0; j < loop_ub; j++) {
          samplePoints_data[j + nx * i] = pointss_data
              [((int)C_data[b_j + C->size[0] * j] + pointss->size[0] * i) - 1];
        }
      }
      /*  计算平面模型 */
      for (i = 0; i < b_loop_ub; i++) {
        samplePoints[i] = samplePoints_data[i];
        samplePoints[i + 3] = samplePoints_data[i + nx];
      }
      samplePoints[6] = 1.0;
      samplePoints[7] = 1.0;
      samplePoints[8] = 1.0;
      for (i = 0; i < c_loop_ub; i++) {
        PP2[i] = samplePoints_data[i + nx * 2];
      }
      b_mldivide(samplePoints, PP2, coefficients);
      a = sqrt((coefficients[0] * coefficients[0] +
                coefficients[1] * coefficients[1]) +
               1.0);
      b = coefficients[0];
      d = coefficients[1];
      A_idx_3 = coefficients[2];
      i = B->size[0] * B->size[1];
      B->size[0] = result;
      B->size[1] = result_idx_1 + b_result_idx_1;
      emxEnsureCapacity_real_T(B, i);
      distances_data = B->data;
      for (i = 0; i < d_loop_ub; i++) {
        for (j = 0; j < result; j++) {
          distances_data[j + B->size[0] * i] = pointss_data[j + result * i];
        }
      }
      for (i = 0; i < e_loop_ub; i++) {
        for (j = 0; j < result; j++) {
          distances_data[j + B->size[0] * result_idx_1] = 1.0;
        }
      }
      nx = B->size[0];
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = B->size[0];
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      for (j = 0; j < nx; j++) {
        Cnum_data[j] =
            ((b * distances_data[j] + d * distances_data[B->size[0] + j]) -
             distances_data[(B->size[0] << 1) + j]) +
            A_idx_3 * distances_data[3 * B->size[0] + j];
      }
      nx = Cnum->size[1];
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      distances->size[1] = Cnum->size[1];
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      for (j = 0; j < nx; j++) {
        distances_data[j] = fabs(Cnum_data[j]);
      }
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      nx = distances->size[1] - 1;
      for (i = 0; i <= nx; i++) {
        distances_data[i] /= a;
      }
      /*  确定内点 */
      /*  更新最优平面模型 */
      a = mean(distances);
      if (a < bestDist) {
        bestDist = a;
        i = b_distances->size[0] * b_distances->size[1];
        b_distances->size[0] = 1;
        b_distances->size[1] = distances->size[1];
        emxEnsureCapacity_boolean_T(b_distances, i);
        b_distances_data = b_distances->data;
        nx = distances->size[1];
        for (i = 0; i < nx; i++) {
          b_distances_data[i] = (distances_data[i] < distanceThreshold);
        }
        eml_find(b_distances, r12);
        r13 = r12->data;
        i = inlierIdxFinal[b_i].f1->size[0] * inlierIdxFinal[b_i].f1->size[1];
        inlierIdxFinal[b_i].f1->size[0] = 1;
        inlierIdxFinal[b_i].f1->size[1] = r12->size[1];
        emxEnsureCapacity_real_T(inlierIdxFinal[b_i].f1, i);
        nx = r12->size[1];
        for (i = 0; i < nx; i++) {
          inlierIdxFinal[b_i].f1->data[i] = r13[i];
        }
        i = distancesFianal1[b_i].f1->size[0] *
            distancesFianal1[b_i].f1->size[1];
        distancesFianal1[b_i].f1->size[0] = 1;
        distancesFianal1[b_i].f1->size[1] = distances->size[1];
        emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
        nx = distances->size[1];
        for (i = 0; i < nx; i++) {
          distancesFianal1[b_i].f1->data[i] = distances_data[i];
        }
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Cnum_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        Cnum_data[j + inlierPoints->size[0] * i] = pointss_data
            [((int)inlierIdxFinal[b_i].f1->data[j] + pointss->size[0] * i) - 1];
      }
    }
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = x->size[0];
    x->size[0] = inlierIdxFinal[b_i].f1->size[1];
    emxEnsureCapacity_real_T(x, i);
    distances_data = x->data;
    for (i = 0; i < nx; i++) {
      distances_data[i] = Cnum_data[i];
    }
    nx = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < nx; i++) {
      pointss_data[i] = Cnum_data[i];
    }
    for (i = 0; i < nx; i++) {
      pointss_data[i + pointss->size[0]] = Cnum_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < nx; i++) {
      pointss_data[i + pointss->size[0] * 2] =
          Cnum_data[i + inlierPoints->size[0] * 2];
    }
    /*  Fit a plane through the points */
    b_mean(pointss, coefficients);
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    distances_data = b_pointss->data;
    nx = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        distances_data[j + b_pointss->size[0] * i] =
            pointss_data[j + pointss->size[0] * i] - coefficients[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    nx = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (j = 0; j < nx; j++) {
        pointss_data[j + pointss->size[0] * i] =
            distances_data[j + b_pointss->size[0] * i];
      }
    }
    b_svd(pointss, a__1, b_pointss, samplePoints);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 * acos(fabs((samplePoints[6] * 0.0 +
                                                    samplePoints[7] * 0.0) +
                                                   samplePoints[8]))) < 0.5) {
      c = 0;
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < nx; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0]];
      }
      polyfit(x, b_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      b = -1.0;
      d = bb[1];
    } else {
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = pointss->size[0] * pointss->size[1];
      pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, i);
      pointss_data = pointss->data;
      for (i = 0; i < nx; i++) {
        pointss_data[i] = Cnum_data[i];
      }
      for (i = 0; i < nx; i++) {
        pointss_data[i + pointss->size[0]] =
            Cnum_data[i + inlierPoints->size[0]];
      }
      nx = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < nx; i++) {
        pointss_data[i + pointss->size[0] * 2] = 1.0;
      }
      nx = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < nx; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(pointss, b_inlierPoints, coefficients);
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
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&b_inlierPoints);
  emxFree_int32_T(&r12);
  emxFree_real_T(&B);
  emxFreeMatrix_cell_wrap_41(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&C);
  emxFree_real_T(&pointss);
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Cnum_data = Cnum->data;
  nx = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < nx; i++) {
    Cnum_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  distances_data = distances->data;
  nx = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  distances_data = b_distancesFianal1->data;
  nx = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  distances_data = c_distancesFianal1->data;
  nx = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_11(inlierIdxFinal);
  MaxDis[0] = maximum(Cnum);
  emxFree_real_T(&Cnum);
  MaxDis[1] = maximum(distances);
  emxFree_real_T(&distances);
  MaxDis[2] = maximum(b_distancesFianal1);
  emxFree_real_T(&b_distancesFianal1);
  MaxDis[3] = maximum(c_distancesFianal1);
  emxFree_real_T(&c_distancesFianal1);
  i = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  distancesFianal->size[1] =
      ((distancesFianal1[0].f1->size[1] + distancesFianal1[1].f1->size[1]) +
       distancesFianal1[2].f1->size[1]) +
      distancesFianal1[3].f1->size[1];
  emxEnsureCapacity_real_T(distancesFianal, i);
  distances_data = distancesFianal->data;
  nx = distancesFianal1[0].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i] = distancesFianal1[0].f1->data[i];
  }
  nx = distancesFianal1[1].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[i + distancesFianal1[0].f1->size[1]] =
        distancesFianal1[1].f1->data[i];
  }
  nx = distancesFianal1[2].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[(i + distancesFianal1[0].f1->size[1]) +
                   distancesFianal1[1].f1->size[1]] =
        distancesFianal1[2].f1->data[i];
  }
  nx = distancesFianal1[3].f1->size[1];
  for (i = 0; i < nx; i++) {
    distances_data[((i + distancesFianal1[0].f1->size[1]) +
                    distancesFianal1[1].f1->size[1]) +
                   distancesFianal1[2].f1->size[1]] =
        distancesFianal1[3].f1->data[i];
  }
  emxFreeMatrix_cell_wrap_11(distancesFianal1);
  /*  平面方程的系数输出 */
  /* %%%%% 前2个面的交点 %%%% */
  /*  计算交线 */
  a = (b_maximum(x) + minimum(x)) / 2.0;
  emxFree_real_T(&x);
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[4], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[0] = PointTri[0];
  yfit[0] = PointTri[1];
  zfit[0] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[0], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[2] = PointTri[0];
  yfit[2] = PointTri[1];
  zfit[2] = PointTri[2];
  /* %%%%% 第2、3个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[4], &PlaneParaOut_data[8], a, coefficients, PP2);
  /*  找到边界，确定三角点 */
  b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[4] = PointTri[0];
  yfit[4] = PointTri[1];
  zfit[4] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[8], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[5] = PointTri[0];
  yfit[5] = PointTri[1];
  zfit[5] = PointTri[2];
  /* %%%%% 第3、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[8], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[6] = PointTri[0];
  yfit[6] = PointTri[1];
  zfit[6] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[7] = PointTri[0];
  yfit[7] = PointTri[1];
  zfit[7] = PointTri[2];
  /* %%%%% 第1、4个面的交点 %%%% */
  CrossLine(&PlaneParaOut_data[0], &PlaneParaOut_data[12], a, coefficients,
            PP2);
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint1, coefficients,
                           PP2, PointTri);
  xfit[1] = PointTri[0];
  yfit[1] = PointTri[1];
  zfit[1] = PointTri[2];
  b_GenerateTrianglePoints(&PlaneParaOut_data[12], BoundPoint2, coefficients,
                           PP2, PointTri);
  xfit[3] = PointTri[0];
  yfit[3] = PointTri[1];
  zfit[3] = PointTri[2];
  /*  取八个点 */
  for (i = 0; i < 24; i++) {
    i1 = iv1[i];
    b_xfit[3 * i] = xfit[i1];
    b_xfit[3 * i + 1] = yfit[i1];
    b_xfit[3 * i + 2] = zfit[i1];
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
                                               &A_idx_3, &bestDist, &zN2);
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
  b_xfit[3] = A_idx_3;
  b_xfit[6] = xN3;
  b_xfit[9] = A_idx_3;
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
  b_xfit[54] = A_idx_3;
  b_xfit[57] = xN4;
  b_xfit[60] = xN7;
  b_xfit[63] = xN4;
  b_xfit[66] = xN7;
  b_xfit[69] = xN8;
  b_xfit[1] = b;
  b_xfit[4] = bestDist;
  b_xfit[7] = yN3;
  b_xfit[10] = bestDist;
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
  b_xfit[55] = bestDist;
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
  distances_data = TrianglePoints->data;
  for (i = 0; i < 72; i++) {
    distances_data[i] = b_xfit[i];
  }
}

/*
 * File trailer for planefit4.c
 *
 * [EOF]
 */
