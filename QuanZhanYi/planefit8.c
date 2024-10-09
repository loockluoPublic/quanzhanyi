/*
 * File: planefit8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Oct-2024 00:11:45
 */

/* Include Files */
#include "planefit8.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "find.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "nchoosek.h"
#include "polyfit.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static const signed char iv[48] = {0, 7, 8,  7, 8,  15, 0, 1, 9,  0, 8,  9,
                                   1, 2, 9,  2, 9,  10, 2, 3, 10, 3, 10, 11,
                                   3, 4, 11, 4, 11, 12, 4, 5, 12, 5, 12, 13,
                                   5, 6, 13, 6, 13, 14, 6, 7, 14, 7, 14, 15};

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
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[8]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void b_planefit8(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, const emxArray_real_T *Points4,
                 const emxArray_real_T *Points5, const emxArray_real_T *Points6,
                 const emxArray_real_T *Points7, const emxArray_real_T *Points8,
                 const double P_bound1[3], const double P_bound2[3],
                 double distanceThreshold, emxArray_real_T *PlaneParaOut,
                 emxArray_real_T *TrianglePoints, double MaxDis[8],
                 emxArray_real_T *distancesFianal)
{
  cell_wrap_1 distancesFianal1[8];
  cell_wrap_1 inlierIdxFinal[8];
  cell_wrap_1 r10;
  cell_wrap_1 r11;
  cell_wrap_1 r12;
  cell_wrap_1 r13;
  cell_wrap_1 r14;
  cell_wrap_1 r15;
  cell_wrap_1 r16;
  cell_wrap_1 r17;
  cell_wrap_1 r18;
  cell_wrap_1 r19;
  cell_wrap_1 r20;
  cell_wrap_1 r21;
  cell_wrap_1 r22;
  cell_wrap_1 r23;
  cell_wrap_1 r8;
  cell_wrap_1 r9;
  cell_wrap_4 PointAll[8];
  cell_wrap_4 r;
  cell_wrap_4 r1;
  cell_wrap_4 r2;
  cell_wrap_4 r3;
  cell_wrap_4 r4;
  cell_wrap_4 r5;
  cell_wrap_4 r6;
  cell_wrap_4 r7;
  emxArray_boolean_T *b_distances;
  emxArray_int32_T *r24;
  emxArray_real_T *B;
  emxArray_real_T *C;
  emxArray_real_T *Cnum;
  emxArray_real_T *a__1;
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *c_inlierPoints;
  emxArray_real_T *d_distancesFianal1;
  emxArray_real_T *distances;
  emxArray_real_T *e_distancesFianal1;
  emxArray_real_T *f_distancesFianal1;
  emxArray_real_T *g_distancesFianal1;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  double PP[48];
  double PlaneParaOutP_data[32];
  double cross_vectors[24];
  double A[9];
  double samplePoints_data[9];
  double coefficients[3];
  double n[3];
  double bb[2];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  const double *Points5_data;
  const double *Points6_data;
  const double *Points7_data;
  const double *Points8_data;
  double PlaneParaOut1_idx_0;
  double PlaneParaOut1_idx_1;
  double PlaneParaOut1_idx_2;
  double PlaneParaOut1_idx_3;
  double PlaneParaOut2_idx_2;
  double a;
  double b_c;
  double bestDist;
  double c_c;
  double d;
  double *C_data;
  double *Cnum_data;
  double *PlaneParaOut_data;
  double *distances_data;
  double *pointss_data;
  int b_i;
  int b_loop_ub;
  int b_result_idx_1;
  int c;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i;
  int i1;
  int j;
  int loop_ub;
  int nx;
  int result;
  int result_idx_1;
  int *r25;
  signed char i2;
  signed char sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T *b_distances_data;
  Points8_data = Points8->data;
  Points7_data = Points7->data;
  Points6_data = Points6->data;
  Points5_data = Points5->data;
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  emxInitStruct_cell_wrap_4(&r);
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, i);
  loop_ub = 3 * Points1->size[1];
  for (i = 0; i < loop_ub; i++) {
    r.f1->data[i] = Points1_data[i];
  }
  emxInitStruct_cell_wrap_4(&r1);
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, i);
  loop_ub = 3 * Points2->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1.f1->data[i] = Points2_data[i];
  }
  emxInitStruct_cell_wrap_4(&r2);
  i = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, i);
  loop_ub = 3 * Points3->size[1];
  for (i = 0; i < loop_ub; i++) {
    r2.f1->data[i] = Points3_data[i];
  }
  emxInitStruct_cell_wrap_4(&r3);
  i = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, i);
  loop_ub = 3 * Points4->size[1];
  for (i = 0; i < loop_ub; i++) {
    r3.f1->data[i] = Points4_data[i];
  }
  emxInitStruct_cell_wrap_4(&r4);
  i = r4.f1->size[0] * r4.f1->size[1];
  r4.f1->size[0] = 3;
  r4.f1->size[1] = Points5->size[1];
  emxEnsureCapacity_real_T(r4.f1, i);
  loop_ub = 3 * Points5->size[1];
  for (i = 0; i < loop_ub; i++) {
    r4.f1->data[i] = Points5_data[i];
  }
  emxInitStruct_cell_wrap_4(&r5);
  i = r5.f1->size[0] * r5.f1->size[1];
  r5.f1->size[0] = 3;
  r5.f1->size[1] = Points6->size[1];
  emxEnsureCapacity_real_T(r5.f1, i);
  loop_ub = 3 * Points6->size[1];
  for (i = 0; i < loop_ub; i++) {
    r5.f1->data[i] = Points6_data[i];
  }
  emxInitStruct_cell_wrap_4(&r6);
  i = r6.f1->size[0] * r6.f1->size[1];
  r6.f1->size[0] = 3;
  r6.f1->size[1] = Points7->size[1];
  emxEnsureCapacity_real_T(r6.f1, i);
  loop_ub = 3 * Points7->size[1];
  for (i = 0; i < loop_ub; i++) {
    r6.f1->data[i] = Points7_data[i];
  }
  emxInitStruct_cell_wrap_4(&r7);
  i = r7.f1->size[0] * r7.f1->size[1];
  r7.f1->size[0] = 3;
  r7.f1->size[1] = Points8->size[1];
  emxEnsureCapacity_real_T(r7.f1, i);
  loop_ub = 3 * Points8->size[1];
  for (i = 0; i < loop_ub; i++) {
    r7.f1->data[i] = Points8_data[i];
  }
  emxInitMatrix_cell_wrap_4(PointAll);
  emxCopyStruct_cell_wrap_4(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_4(&r);
  emxCopyStruct_cell_wrap_4(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_4(&r1);
  emxCopyStruct_cell_wrap_4(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_4(&r2);
  emxCopyStruct_cell_wrap_4(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_4(&r3);
  emxCopyStruct_cell_wrap_4(&PointAll[4], &r4);
  emxFreeStruct_cell_wrap_4(&r4);
  emxCopyStruct_cell_wrap_4(&PointAll[5], &r5);
  emxFreeStruct_cell_wrap_4(&r5);
  emxCopyStruct_cell_wrap_4(&PointAll[6], &r6);
  emxFreeStruct_cell_wrap_4(&r6);
  emxCopyStruct_cell_wrap_4(&PointAll[7], &r7);
  emxFreeStruct_cell_wrap_4(&r7);
  i = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 8;
  emxEnsureCapacity_real_T(PlaneParaOut, i);
  PlaneParaOut_data = PlaneParaOut->data;
  for (i = 0; i < 32; i++) {
    PlaneParaOut_data[i] = 0.0;
  }
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
  emxInitStruct_cell_wrap_1(&r12);
  i = r12.f1->size[0] * r12.f1->size[1];
  r12.f1->size[0] = 1;
  r12.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r12.f1, i);
  r12.f1->data[0] = 5.0;
  emxInitStruct_cell_wrap_1(&r13);
  i = r13.f1->size[0] * r13.f1->size[1];
  r13.f1->size[0] = 1;
  r13.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r13.f1, i);
  r13.f1->data[0] = 6.0;
  emxInitStruct_cell_wrap_1(&r14);
  i = r14.f1->size[0] * r14.f1->size[1];
  r14.f1->size[0] = 1;
  r14.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r14.f1, i);
  r14.f1->data[0] = 7.0;
  emxInitStruct_cell_wrap_1(&r15);
  i = r15.f1->size[0] * r15.f1->size[1];
  r15.f1->size[0] = 1;
  r15.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r15.f1, i);
  r15.f1->data[0] = 8.0;
  emxInitMatrix_cell_wrap_1(inlierIdxFinal);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[0], &r8);
  emxFreeStruct_cell_wrap_1(&r8);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[1], &r9);
  emxFreeStruct_cell_wrap_1(&r9);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[2], &r10);
  emxFreeStruct_cell_wrap_1(&r10);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[3], &r11);
  emxFreeStruct_cell_wrap_1(&r11);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[4], &r12);
  emxFreeStruct_cell_wrap_1(&r12);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[5], &r13);
  emxFreeStruct_cell_wrap_1(&r13);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[6], &r14);
  emxFreeStruct_cell_wrap_1(&r14);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[7], &r15);
  emxFreeStruct_cell_wrap_1(&r15);
  emxInitStruct_cell_wrap_1(&r16);
  i = r16.f1->size[0] * r16.f1->size[1];
  r16.f1->size[0] = 1;
  r16.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r16.f1, i);
  r16.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r17);
  i = r17.f1->size[0] * r17.f1->size[1];
  r17.f1->size[0] = 1;
  r17.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r17.f1, i);
  r17.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r18);
  i = r18.f1->size[0] * r18.f1->size[1];
  r18.f1->size[0] = 1;
  r18.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r18.f1, i);
  r18.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r19);
  i = r19.f1->size[0] * r19.f1->size[1];
  r19.f1->size[0] = 1;
  r19.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r19.f1, i);
  r19.f1->data[0] = 4.0;
  emxInitStruct_cell_wrap_1(&r20);
  i = r20.f1->size[0] * r20.f1->size[1];
  r20.f1->size[0] = 1;
  r20.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r20.f1, i);
  r20.f1->data[0] = 5.0;
  emxInitStruct_cell_wrap_1(&r21);
  i = r21.f1->size[0] * r21.f1->size[1];
  r21.f1->size[0] = 1;
  r21.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r21.f1, i);
  r21.f1->data[0] = 6.0;
  emxInitStruct_cell_wrap_1(&r22);
  i = r22.f1->size[0] * r22.f1->size[1];
  r22.f1->size[0] = 1;
  r22.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r22.f1, i);
  r22.f1->data[0] = 7.0;
  emxInitStruct_cell_wrap_1(&r23);
  i = r23.f1->size[0] * r23.f1->size[1];
  r23.f1->size[0] = 1;
  r23.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r23.f1, i);
  r23.f1->data[0] = 8.0;
  emxInitMatrix_cell_wrap_1(distancesFianal1);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[0], &r16);
  emxFreeStruct_cell_wrap_1(&r16);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[1], &r17);
  emxFreeStruct_cell_wrap_1(&r17);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[2], &r18);
  emxFreeStruct_cell_wrap_1(&r18);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[3], &r19);
  emxFreeStruct_cell_wrap_1(&r19);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[4], &r20);
  emxFreeStruct_cell_wrap_1(&r20);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[5], &r21);
  emxFreeStruct_cell_wrap_1(&r21);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[6], &r22);
  emxFreeStruct_cell_wrap_1(&r22);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[7], &r23);
  emxFreeStruct_cell_wrap_1(&r23);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&B, 2);
  emxInit_int32_T(&r24);
  emxInit_real_T(&b_inlierPoints, 1);
  emxInit_real_T(&c_inlierPoints, 1);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_pointss, 2);
  for (b_i = 0; b_i < 8; b_i++) {
    /*  平面拟合 */
    loop_ub = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * i1];
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
      loop_ub = c - 1;
      for (i = 0; i <= loop_ub; i++) {
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
      b_loop_ub = C->size[1];
      c_loop_ub = C->size[1];
      d_loop_ub = C->size[1];
      if (pointss->size[0] != 0) {
        result = pointss->size[0];
      } else {
        result = 0;
      }
      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        i2 = 3;
      } else {
        i2 = 0;
      }
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        sizes_idx_1 = 1;
      } else {
        sizes_idx_1 = 0;
      }
      result_idx_1 = i2;
      b_result_idx_1 = sizes_idx_1;
      e_loop_ub = i2;
      f_loop_ub = sizes_idx_1;
    }
    for (j = 0; j < c; j++) {
      /*  随机选择三个点 */
      nx = C->size[1];
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          samplePoints_data[i1 + nx * i] = pointss_data
              [((int)C_data[j + C->size[0] * i1] + pointss->size[0] * i) - 1];
        }
      }
      /*  计算平面模型 */
      for (i = 0; i < c_loop_ub; i++) {
        A[i] = samplePoints_data[i];
        A[i + 3] = samplePoints_data[i + nx];
      }
      A[6] = 1.0;
      A[7] = 1.0;
      A[8] = 1.0;
      for (i = 0; i < d_loop_ub; i++) {
        n[i] = samplePoints_data[i + nx * 2];
      }
      b_mldivide(A, n, coefficients);
      a = sqrt((coefficients[0] * coefficients[0] +
                coefficients[1] * coefficients[1]) +
               1.0);
      PlaneParaOut1_idx_0 = coefficients[0];
      PlaneParaOut1_idx_1 = coefficients[1];
      PlaneParaOut1_idx_3 = coefficients[2];
      i = B->size[0] * B->size[1];
      B->size[0] = result;
      B->size[1] = result_idx_1 + b_result_idx_1;
      emxEnsureCapacity_real_T(B, i);
      distances_data = B->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          distances_data[i1 + B->size[0] * i] = pointss_data[i1 + result * i];
        }
      }
      for (i = 0; i < f_loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          distances_data[i1 + B->size[0] * result_idx_1] = 1.0;
        }
      }
      nx = B->size[0];
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = B->size[0];
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        Cnum_data[loop_ub] =
            ((PlaneParaOut1_idx_0 * distances_data[loop_ub] +
              PlaneParaOut1_idx_1 * distances_data[B->size[0] + loop_ub]) -
             distances_data[(B->size[0] << 1) + loop_ub]) +
            PlaneParaOut1_idx_3 * distances_data[3 * B->size[0] + loop_ub];
      }
      nx = Cnum->size[1];
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      distances->size[1] = Cnum->size[1];
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        distances_data[loop_ub] = fabs(Cnum_data[loop_ub]);
      }
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      loop_ub = distances->size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        distances_data[i] /= a;
      }
      /*  确定内点 */
      /*  更新最优平面模型 */
      PlaneParaOut1_idx_0 = mean(distances);
      if (PlaneParaOut1_idx_0 < bestDist) {
        bestDist = PlaneParaOut1_idx_0;
        i = b_distances->size[0] * b_distances->size[1];
        b_distances->size[0] = 1;
        b_distances->size[1] = distances->size[1];
        emxEnsureCapacity_boolean_T(b_distances, i);
        b_distances_data = b_distances->data;
        loop_ub = distances->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_distances_data[i] = (distances_data[i] < distanceThreshold);
        }
        eml_find(b_distances, r24);
        r25 = r24->data;
        i = inlierIdxFinal[b_i].f1->size[0] * inlierIdxFinal[b_i].f1->size[1];
        inlierIdxFinal[b_i].f1->size[0] = 1;
        inlierIdxFinal[b_i].f1->size[1] = r24->size[1];
        emxEnsureCapacity_real_T(inlierIdxFinal[b_i].f1, i);
        loop_ub = r24->size[1];
        for (i = 0; i < loop_ub; i++) {
          inlierIdxFinal[b_i].f1->data[i] = r25[i];
        }
        i = distancesFianal1[b_i].f1->size[0] *
            distancesFianal1[b_i].f1->size[1];
        distancesFianal1[b_i].f1->size[0] = 1;
        distancesFianal1[b_i].f1->size[1] = distances->size[1];
        emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
        loop_ub = distances->size[1];
        for (i = 0; i < loop_ub; i++) {
          distancesFianal1[b_i].f1->data[i] = distances_data[i];
        }
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Cnum_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Cnum_data[i1 + inlierPoints->size[0] * i] =
            pointss_data[((int)inlierIdxFinal[b_i].f1->data[i1] +
                          pointss->size[0] * i) -
                         1];
      }
    }
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < loop_ub; i++) {
      pointss_data[i] = Cnum_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      pointss_data[i + pointss->size[0]] = Cnum_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < loop_ub; i++) {
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
    loop_ub = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        distances_data[i1 + b_pointss->size[0] * i] =
            pointss_data[i1 + pointss->size[0] * i] - coefficients[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    loop_ub = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            distances_data[i1 + b_pointss->size[0] * i];
      }
    }
    b_svd(pointss, a__1, b_pointss, A);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 *
                        acos(fabs((A[6] * 0.0 + A[7] * 0.0) + A[8]))) < 0.5) {
      c = 0;
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_inlierPoints->size[0];
      c_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_inlierPoints, i);
      distances_data = c_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0]];
      }
      polyfit(b_inlierPoints, c_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      bestDist = -1.0;
      d = bb[1];
    } else {
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = pointss->size[0] * pointss->size[1];
      pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, i);
      pointss_data = pointss->data;
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i] = Cnum_data[i];
      }
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i + pointss->size[0]] =
            Cnum_data[i + inlierPoints->size[0]];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i + pointss->size[0] * 2] = 1.0;
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(pointss, b_inlierPoints, coefficients);
      a = coefficients[0];
      bestDist = coefficients[1];
      d = coefficients[2];
      c = -1;
    }
    PlaneParaOut_data[4 * b_i] = a;
    PlaneParaOut_data[4 * b_i + 1] = bestDist;
    PlaneParaOut_data[4 * b_i + 2] = c;
    PlaneParaOut_data[4 * b_i + 3] = d;
  }
  emxFree_real_T(&b_pointss);
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&c_inlierPoints);
  emxFree_real_T(&b_inlierPoints);
  emxFree_int32_T(&r24);
  emxFree_real_T(&B);
  emxFreeMatrix_cell_wrap_4(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&C);
  emxFree_real_T(&pointss);
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Cnum_data = Cnum->data;
  loop_ub = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Cnum_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  distances_data = distances->data;
  loop_ub = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  distances_data = b_distancesFianal1->data;
  loop_ub = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  distances_data = c_distancesFianal1->data;
  loop_ub = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxInit_real_T(&d_distancesFianal1, 2);
  i = d_distancesFianal1->size[0] * d_distancesFianal1->size[1];
  d_distancesFianal1->size[0] = 1;
  d_distancesFianal1->size[1] = inlierIdxFinal[4].f1->size[1];
  emxEnsureCapacity_real_T(d_distancesFianal1, i);
  distances_data = d_distancesFianal1->data;
  loop_ub = inlierIdxFinal[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[4].f1->data[(int)inlierIdxFinal[4].f1->data[i] - 1];
  }
  emxInit_real_T(&e_distancesFianal1, 2);
  i = e_distancesFianal1->size[0] * e_distancesFianal1->size[1];
  e_distancesFianal1->size[0] = 1;
  e_distancesFianal1->size[1] = inlierIdxFinal[5].f1->size[1];
  emxEnsureCapacity_real_T(e_distancesFianal1, i);
  distances_data = e_distancesFianal1->data;
  loop_ub = inlierIdxFinal[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[5].f1->data[(int)inlierIdxFinal[5].f1->data[i] - 1];
  }
  emxInit_real_T(&f_distancesFianal1, 2);
  i = f_distancesFianal1->size[0] * f_distancesFianal1->size[1];
  f_distancesFianal1->size[0] = 1;
  f_distancesFianal1->size[1] = inlierIdxFinal[6].f1->size[1];
  emxEnsureCapacity_real_T(f_distancesFianal1, i);
  distances_data = f_distancesFianal1->data;
  loop_ub = inlierIdxFinal[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[6].f1->data[(int)inlierIdxFinal[6].f1->data[i] - 1];
  }
  emxInit_real_T(&g_distancesFianal1, 2);
  i = g_distancesFianal1->size[0] * g_distancesFianal1->size[1];
  g_distancesFianal1->size[0] = 1;
  g_distancesFianal1->size[1] = inlierIdxFinal[7].f1->size[1];
  emxEnsureCapacity_real_T(g_distancesFianal1, i);
  distances_data = g_distancesFianal1->data;
  loop_ub = inlierIdxFinal[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[7].f1->data[(int)inlierIdxFinal[7].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_1(inlierIdxFinal);
  MaxDis[0] = maximum(Cnum);
  emxFree_real_T(&Cnum);
  MaxDis[1] = maximum(distances);
  emxFree_real_T(&distances);
  MaxDis[2] = maximum(b_distancesFianal1);
  emxFree_real_T(&b_distancesFianal1);
  MaxDis[3] = maximum(c_distancesFianal1);
  emxFree_real_T(&c_distancesFianal1);
  MaxDis[4] = maximum(d_distancesFianal1);
  emxFree_real_T(&d_distancesFianal1);
  MaxDis[5] = maximum(e_distancesFianal1);
  emxFree_real_T(&e_distancesFianal1);
  MaxDis[6] = maximum(f_distancesFianal1);
  emxFree_real_T(&f_distancesFianal1);
  MaxDis[7] = maximum(g_distancesFianal1);
  emxFree_real_T(&g_distancesFianal1);
  i = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  i1 = distancesFianal1[0].f1->size[1] + distancesFianal1[1].f1->size[1];
  c = i1 + distancesFianal1[2].f1->size[1];
  nx = c + distancesFianal1[3].f1->size[1];
  distancesFianal->size[1] = (((nx + distancesFianal1[4].f1->size[1]) +
                               distancesFianal1[5].f1->size[1]) +
                              distancesFianal1[6].f1->size[1]) +
                             distancesFianal1[7].f1->size[1];
  emxEnsureCapacity_real_T(distancesFianal, i);
  distances_data = distancesFianal->data;
  loop_ub = distancesFianal1[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] = distancesFianal1[0].f1->data[i];
  }
  loop_ub = distancesFianal1[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i + distancesFianal1[0].f1->size[1]] =
        distancesFianal1[1].f1->data[i];
  }
  loop_ub = distancesFianal1[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(i + distancesFianal1[0].f1->size[1]) +
                   distancesFianal1[1].f1->size[1]] =
        distancesFianal1[2].f1->data[i];
  }
  loop_ub = distancesFianal1[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[((i + distancesFianal1[0].f1->size[1]) +
                    distancesFianal1[1].f1->size[1]) +
                   distancesFianal1[2].f1->size[1]] =
        distancesFianal1[3].f1->data[i];
  }
  loop_ub = distancesFianal1[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + distancesFianal1[0].f1->size[1]) +
                     distancesFianal1[1].f1->size[1]) +
                    distancesFianal1[2].f1->size[1]) +
                   distancesFianal1[3].f1->size[1]] =
        distancesFianal1[4].f1->data[i];
  }
  loop_ub = distancesFianal1[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + i1) + distancesFianal1[2].f1->size[1]) +
                    distancesFianal1[3].f1->size[1]) +
                   distancesFianal1[4].f1->size[1]] =
        distancesFianal1[5].f1->data[i];
  }
  loop_ub = distancesFianal1[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + c) + distancesFianal1[3].f1->size[1]) +
                    distancesFianal1[4].f1->size[1]) +
                   distancesFianal1[5].f1->size[1]] =
        distancesFianal1[6].f1->data[i];
  }
  loop_ub = distancesFianal1[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + nx) + distancesFianal1[4].f1->size[1]) +
                    distancesFianal1[5].f1->size[1]) +
                   distancesFianal1[6].f1->size[1]] =
        distancesFianal1[7].f1->data[i];
  }
  emxFreeMatrix_cell_wrap_1(distancesFianal1);
  emxInit_real_T(&b_PlaneParaOut, 2);
  i = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 8;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, i);
  distances_data = b_PlaneParaOut->data;
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      distances_data[i1 + b_PlaneParaOut->size[0] * i] =
          PlaneParaOut_data[i + 4 * i1];
    }
  }
  for (i = 0; i < 32; i++) {
    PlaneParaOutP_data[i] = distances_data[i];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&cross_vectors[0], 0, 24U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (b_i = 0; b_i < 8; b_i++) {
    if (b_i + 1 < 8) {
      a = PlaneParaOutP_data[b_i + 17];
      bestDist = PlaneParaOutP_data[b_i + 9];
      d = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[b_i + 8];
      cross_vectors[b_i] = PlaneParaOut1_idx_2 * a - bestDist * d;
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[b_i + 1];
      cross_vectors[b_i + 8] =
          PlaneParaOut2_idx_2 * d - PlaneParaOutP_data[b_i] * a;
      cross_vectors[b_i + 16] = PlaneParaOutP_data[b_i] * bestDist -
                                PlaneParaOut2_idx_2 * PlaneParaOut1_idx_2;
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
    bestDist = fabs(cross_vectors[b_i]);
    if (bestDist > 3.3121686421112381E-170) {
      PlaneParaOut1_idx_2 = 1.0;
      a = bestDist;
    } else {
      d = bestDist / 3.3121686421112381E-170;
      PlaneParaOut1_idx_2 = d * d;
    }
    bestDist = fabs(cross_vectors[b_i + 8]);
    if (bestDist > a) {
      d = a / bestDist;
      PlaneParaOut1_idx_2 = PlaneParaOut1_idx_2 * d * d + 1.0;
      a = bestDist;
    } else {
      d = bestDist / a;
      PlaneParaOut1_idx_2 += d * d;
    }
    bestDist = fabs(cross_vectors[b_i + 16]);
    if (bestDist > a) {
      d = a / bestDist;
      PlaneParaOut1_idx_2 = PlaneParaOut1_idx_2 * d * d + 1.0;
      a = bestDist;
    } else {
      d = bestDist / a;
      PlaneParaOut1_idx_2 += d * d;
    }
    PlaneParaOut1_idx_2 = a * sqrt(PlaneParaOut1_idx_2);
    cross_vectors[b_i] /= PlaneParaOut1_idx_2;
    cross_vectors[b_i + 8] /= PlaneParaOut1_idx_2;
    cross_vectors[b_i + 16] /= PlaneParaOut1_idx_2;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  PlaneParaOut1_idx_0 = cross_vectors[0];
  PlaneParaOut2_idx_2 = cross_vectors[8];
  bestDist = cross_vectors[16];
  for (b_i = 0; b_i < 7; b_i++) {
    a = cross_vectors[b_i + 1];
    d = cross_vectors[b_i + 9];
    PlaneParaOut1_idx_2 = cross_vectors[b_i + 17];
    if ((PlaneParaOut1_idx_0 * a + PlaneParaOut2_idx_2 * d) +
            bestDist * PlaneParaOut1_idx_2 <
        0.0) {
      /*  如果方向相反 */
      cross_vectors[b_i + 1] = -a;
      d = -d;
      cross_vectors[b_i + 9] = d;
      PlaneParaOut1_idx_2 = -PlaneParaOut1_idx_2;
      cross_vectors[b_i + 17] = PlaneParaOut1_idx_2;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  /*  计算顶面方程的 d 值 */
  b_c = 0.0;
  /*  计算底面方程的 d 值 */
  c_c = 0.0;
  for (nx = 0; nx < 3; nx++) {
    c = nx << 3;
    PlaneParaOut1_idx_0 = cross_vectors[c];
    for (loop_ub = 0; loop_ub < 7; loop_ub++) {
      PlaneParaOut1_idx_0 += cross_vectors[(c + loop_ub) + 1];
    }
    PlaneParaOut1_idx_0 /= 8.0;
    n[nx] = PlaneParaOut1_idx_0;
    b_c += PlaneParaOut1_idx_0 * P_bound1[nx];
    c_c += PlaneParaOut1_idx_0 * P_bound2[nx];
  }
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 48U * sizeof(double));
  /*  计算顶面和底面的8个顶点 */
  PlaneParaOut1_idx_0 = n[0];
  PlaneParaOut2_idx_2 = n[1];
  bestDist = n[2];
  A[2] = PlaneParaOut1_idx_0;
  A[5] = PlaneParaOut2_idx_2;
  A[8] = bestDist;
  for (b_i = 0; b_i < 8; b_i++) {
    /*  顶面顶点 */
    if (b_i + 1 < 8) {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[b_i];
      a = PlaneParaOutP_data[b_i + 1];
      PlaneParaOut1_idx_1 = PlaneParaOutP_data[b_i + 8];
      d = PlaneParaOutP_data[b_i + 9];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[b_i + 17];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[b_i + 24];
      bestDist = PlaneParaOutP_data[b_i + 25];
    } else {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[7];
      a = PlaneParaOutP_data[0];
      PlaneParaOut1_idx_1 = PlaneParaOutP_data[15];
      d = PlaneParaOutP_data[8];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[23];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[16];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[31];
      bestDist = PlaneParaOutP_data[24];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = PlaneParaOut1_idx_0;
    A[1] = a;
    A[3] = PlaneParaOut1_idx_1;
    A[4] = d;
    A[6] = PlaneParaOut1_idx_2;
    A[7] = PlaneParaOut2_idx_2;
    n[0] = -PlaneParaOut1_idx_3;
    n[1] = -bestDist;
    n[2] = b_c;
    c_mldivide(A, n, coefficients);
    PP[b_i] = coefficients[0];
    PP[b_i + 16] = coefficients[1];
    PP[b_i + 32] = coefficients[2];
    /*  求底面和两个相邻侧面的交线 */
    n[0] = -PlaneParaOut1_idx_3;
    n[1] = -bestDist;
    n[2] = c_c;
    c_mldivide(A, n, coefficients);
    PP[b_i + 8] = coefficients[0];
    PP[b_i + 24] = coefficients[1];
    PP[b_i + 40] = coefficients[2];
  }
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 48;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  distances_data = TrianglePoints->data;
  for (i = 0; i < 48; i++) {
    i2 = iv[i];
    distances_data[3 * i] = PP[i2];
    distances_data[3 * i + 1] = PP[i2 + 16];
    distances_data[3 * i + 2] = PP[i2 + 32];
  }
}

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
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[8]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void planefit8(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const emxArray_real_T *Points5, const emxArray_real_T *Points6,
               const emxArray_real_T *Points7, const emxArray_real_T *Points8,
               const double P_bound1[3], const double P_bound2[3],
               double distanceThreshold, emxArray_real_T *PlaneParaOut,
               emxArray_real_T *TrianglePoints, double MaxDis[8],
               emxArray_real_T *distancesFianal)
{
  cell_wrap_1 distancesFianal1[8];
  cell_wrap_1 inlierIdxFinal[8];
  cell_wrap_1 r10;
  cell_wrap_1 r11;
  cell_wrap_1 r12;
  cell_wrap_1 r13;
  cell_wrap_1 r14;
  cell_wrap_1 r15;
  cell_wrap_1 r16;
  cell_wrap_1 r17;
  cell_wrap_1 r18;
  cell_wrap_1 r19;
  cell_wrap_1 r20;
  cell_wrap_1 r21;
  cell_wrap_1 r22;
  cell_wrap_1 r23;
  cell_wrap_1 r8;
  cell_wrap_1 r9;
  cell_wrap_4 PointAll[8];
  cell_wrap_4 r;
  cell_wrap_4 r1;
  cell_wrap_4 r2;
  cell_wrap_4 r3;
  cell_wrap_4 r4;
  cell_wrap_4 r5;
  cell_wrap_4 r6;
  cell_wrap_4 r7;
  emxArray_boolean_T *b_distances;
  emxArray_int32_T *r24;
  emxArray_real_T *B;
  emxArray_real_T *C;
  emxArray_real_T *Cnum;
  emxArray_real_T *a__1;
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *c_inlierPoints;
  emxArray_real_T *d_distancesFianal1;
  emxArray_real_T *distances;
  emxArray_real_T *e_distancesFianal1;
  emxArray_real_T *f_distancesFianal1;
  emxArray_real_T *g_distancesFianal1;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  double PP[48];
  double PlaneParaOutP_data[32];
  double cross_vectors[24];
  double A[9];
  double samplePoints_data[9];
  double coefficients[3];
  double n[3];
  double bb[2];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  const double *Points5_data;
  const double *Points6_data;
  const double *Points7_data;
  const double *Points8_data;
  double PlaneParaOut1_idx_0;
  double PlaneParaOut1_idx_1;
  double PlaneParaOut1_idx_2;
  double PlaneParaOut1_idx_3;
  double PlaneParaOut2_idx_2;
  double a;
  double b_c;
  double bestDist;
  double c_c;
  double d;
  double *C_data;
  double *Cnum_data;
  double *PlaneParaOut_data;
  double *distances_data;
  double *pointss_data;
  int b_i;
  int b_loop_ub;
  int b_result_idx_1;
  int c;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i;
  int i1;
  int j;
  int loop_ub;
  int nx;
  int result;
  int result_idx_1;
  int *r25;
  signed char i2;
  signed char sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T *b_distances_data;
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
  emxInitStruct_cell_wrap_4(&r);
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 3;
  r.f1->size[1] = Points1->size[1];
  emxEnsureCapacity_real_T(r.f1, i);
  loop_ub = 3 * Points1->size[1];
  for (i = 0; i < loop_ub; i++) {
    r.f1->data[i] = Points1_data[i];
  }
  emxInitStruct_cell_wrap_4(&r1);
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 3;
  r1.f1->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(r1.f1, i);
  loop_ub = 3 * Points2->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1.f1->data[i] = Points2_data[i];
  }
  emxInitStruct_cell_wrap_4(&r2);
  i = r2.f1->size[0] * r2.f1->size[1];
  r2.f1->size[0] = 3;
  r2.f1->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(r2.f1, i);
  loop_ub = 3 * Points3->size[1];
  for (i = 0; i < loop_ub; i++) {
    r2.f1->data[i] = Points3_data[i];
  }
  emxInitStruct_cell_wrap_4(&r3);
  i = r3.f1->size[0] * r3.f1->size[1];
  r3.f1->size[0] = 3;
  r3.f1->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(r3.f1, i);
  loop_ub = 3 * Points4->size[1];
  for (i = 0; i < loop_ub; i++) {
    r3.f1->data[i] = Points4_data[i];
  }
  emxInitStruct_cell_wrap_4(&r4);
  i = r4.f1->size[0] * r4.f1->size[1];
  r4.f1->size[0] = 3;
  r4.f1->size[1] = Points5->size[1];
  emxEnsureCapacity_real_T(r4.f1, i);
  loop_ub = 3 * Points5->size[1];
  for (i = 0; i < loop_ub; i++) {
    r4.f1->data[i] = Points5_data[i];
  }
  emxInitStruct_cell_wrap_4(&r5);
  i = r5.f1->size[0] * r5.f1->size[1];
  r5.f1->size[0] = 3;
  r5.f1->size[1] = Points6->size[1];
  emxEnsureCapacity_real_T(r5.f1, i);
  loop_ub = 3 * Points6->size[1];
  for (i = 0; i < loop_ub; i++) {
    r5.f1->data[i] = Points6_data[i];
  }
  emxInitStruct_cell_wrap_4(&r6);
  i = r6.f1->size[0] * r6.f1->size[1];
  r6.f1->size[0] = 3;
  r6.f1->size[1] = Points7->size[1];
  emxEnsureCapacity_real_T(r6.f1, i);
  loop_ub = 3 * Points7->size[1];
  for (i = 0; i < loop_ub; i++) {
    r6.f1->data[i] = Points7_data[i];
  }
  emxInitStruct_cell_wrap_4(&r7);
  i = r7.f1->size[0] * r7.f1->size[1];
  r7.f1->size[0] = 3;
  r7.f1->size[1] = Points8->size[1];
  emxEnsureCapacity_real_T(r7.f1, i);
  loop_ub = 3 * Points8->size[1];
  for (i = 0; i < loop_ub; i++) {
    r7.f1->data[i] = Points8_data[i];
  }
  emxInitMatrix_cell_wrap_4(PointAll);
  emxCopyStruct_cell_wrap_4(&PointAll[0], &r);
  emxFreeStruct_cell_wrap_4(&r);
  emxCopyStruct_cell_wrap_4(&PointAll[1], &r1);
  emxFreeStruct_cell_wrap_4(&r1);
  emxCopyStruct_cell_wrap_4(&PointAll[2], &r2);
  emxFreeStruct_cell_wrap_4(&r2);
  emxCopyStruct_cell_wrap_4(&PointAll[3], &r3);
  emxFreeStruct_cell_wrap_4(&r3);
  emxCopyStruct_cell_wrap_4(&PointAll[4], &r4);
  emxFreeStruct_cell_wrap_4(&r4);
  emxCopyStruct_cell_wrap_4(&PointAll[5], &r5);
  emxFreeStruct_cell_wrap_4(&r5);
  emxCopyStruct_cell_wrap_4(&PointAll[6], &r6);
  emxFreeStruct_cell_wrap_4(&r6);
  emxCopyStruct_cell_wrap_4(&PointAll[7], &r7);
  emxFreeStruct_cell_wrap_4(&r7);
  i = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 8;
  emxEnsureCapacity_real_T(PlaneParaOut, i);
  PlaneParaOut_data = PlaneParaOut->data;
  for (i = 0; i < 32; i++) {
    PlaneParaOut_data[i] = 0.0;
  }
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
  emxInitStruct_cell_wrap_1(&r12);
  i = r12.f1->size[0] * r12.f1->size[1];
  r12.f1->size[0] = 1;
  r12.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r12.f1, i);
  r12.f1->data[0] = 5.0;
  emxInitStruct_cell_wrap_1(&r13);
  i = r13.f1->size[0] * r13.f1->size[1];
  r13.f1->size[0] = 1;
  r13.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r13.f1, i);
  r13.f1->data[0] = 6.0;
  emxInitStruct_cell_wrap_1(&r14);
  i = r14.f1->size[0] * r14.f1->size[1];
  r14.f1->size[0] = 1;
  r14.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r14.f1, i);
  r14.f1->data[0] = 7.0;
  emxInitStruct_cell_wrap_1(&r15);
  i = r15.f1->size[0] * r15.f1->size[1];
  r15.f1->size[0] = 1;
  r15.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r15.f1, i);
  r15.f1->data[0] = 8.0;
  emxInitMatrix_cell_wrap_1(inlierIdxFinal);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[0], &r8);
  emxFreeStruct_cell_wrap_1(&r8);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[1], &r9);
  emxFreeStruct_cell_wrap_1(&r9);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[2], &r10);
  emxFreeStruct_cell_wrap_1(&r10);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[3], &r11);
  emxFreeStruct_cell_wrap_1(&r11);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[4], &r12);
  emxFreeStruct_cell_wrap_1(&r12);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[5], &r13);
  emxFreeStruct_cell_wrap_1(&r13);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[6], &r14);
  emxFreeStruct_cell_wrap_1(&r14);
  emxCopyStruct_cell_wrap_1(&inlierIdxFinal[7], &r15);
  emxFreeStruct_cell_wrap_1(&r15);
  emxInitStruct_cell_wrap_1(&r16);
  i = r16.f1->size[0] * r16.f1->size[1];
  r16.f1->size[0] = 1;
  r16.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r16.f1, i);
  r16.f1->data[0] = 1.0;
  emxInitStruct_cell_wrap_1(&r17);
  i = r17.f1->size[0] * r17.f1->size[1];
  r17.f1->size[0] = 1;
  r17.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r17.f1, i);
  r17.f1->data[0] = 2.0;
  emxInitStruct_cell_wrap_1(&r18);
  i = r18.f1->size[0] * r18.f1->size[1];
  r18.f1->size[0] = 1;
  r18.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r18.f1, i);
  r18.f1->data[0] = 3.0;
  emxInitStruct_cell_wrap_1(&r19);
  i = r19.f1->size[0] * r19.f1->size[1];
  r19.f1->size[0] = 1;
  r19.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r19.f1, i);
  r19.f1->data[0] = 4.0;
  emxInitStruct_cell_wrap_1(&r20);
  i = r20.f1->size[0] * r20.f1->size[1];
  r20.f1->size[0] = 1;
  r20.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r20.f1, i);
  r20.f1->data[0] = 5.0;
  emxInitStruct_cell_wrap_1(&r21);
  i = r21.f1->size[0] * r21.f1->size[1];
  r21.f1->size[0] = 1;
  r21.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r21.f1, i);
  r21.f1->data[0] = 6.0;
  emxInitStruct_cell_wrap_1(&r22);
  i = r22.f1->size[0] * r22.f1->size[1];
  r22.f1->size[0] = 1;
  r22.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r22.f1, i);
  r22.f1->data[0] = 7.0;
  emxInitStruct_cell_wrap_1(&r23);
  i = r23.f1->size[0] * r23.f1->size[1];
  r23.f1->size[0] = 1;
  r23.f1->size[1] = 1;
  emxEnsureCapacity_real_T(r23.f1, i);
  r23.f1->data[0] = 8.0;
  emxInitMatrix_cell_wrap_1(distancesFianal1);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[0], &r16);
  emxFreeStruct_cell_wrap_1(&r16);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[1], &r17);
  emxFreeStruct_cell_wrap_1(&r17);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[2], &r18);
  emxFreeStruct_cell_wrap_1(&r18);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[3], &r19);
  emxFreeStruct_cell_wrap_1(&r19);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[4], &r20);
  emxFreeStruct_cell_wrap_1(&r20);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[5], &r21);
  emxFreeStruct_cell_wrap_1(&r21);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[6], &r22);
  emxFreeStruct_cell_wrap_1(&r22);
  emxCopyStruct_cell_wrap_1(&distancesFianal1[7], &r23);
  emxFreeStruct_cell_wrap_1(&r23);
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&B, 2);
  emxInit_int32_T(&r24);
  emxInit_real_T(&b_inlierPoints, 1);
  emxInit_real_T(&c_inlierPoints, 1);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_pointss, 2);
  for (b_i = 0; b_i < 8; b_i++) {
    /*  平面拟合 */
    loop_ub = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * i1];
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
      loop_ub = c - 1;
      for (i = 0; i <= loop_ub; i++) {
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
      b_loop_ub = C->size[1];
      c_loop_ub = C->size[1];
      d_loop_ub = C->size[1];
      if (pointss->size[0] != 0) {
        result = pointss->size[0];
      } else {
        result = 0;
      }
      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        i2 = 3;
      } else {
        i2 = 0;
      }
      if (empty_non_axis_sizes || (pointss->size[0] != 0)) {
        sizes_idx_1 = 1;
      } else {
        sizes_idx_1 = 0;
      }
      result_idx_1 = i2;
      b_result_idx_1 = sizes_idx_1;
      e_loop_ub = i2;
      f_loop_ub = sizes_idx_1;
    }
    for (j = 0; j < c; j++) {
      /*  随机选择三个点 */
      nx = C->size[1];
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          samplePoints_data[i1 + nx * i] = pointss_data
              [((int)C_data[j + C->size[0] * i1] + pointss->size[0] * i) - 1];
        }
      }
      /*  计算平面模型 */
      for (i = 0; i < c_loop_ub; i++) {
        A[i] = samplePoints_data[i];
        A[i + 3] = samplePoints_data[i + nx];
      }
      A[6] = 1.0;
      A[7] = 1.0;
      A[8] = 1.0;
      for (i = 0; i < d_loop_ub; i++) {
        n[i] = samplePoints_data[i + nx * 2];
      }
      b_mldivide(A, n, coefficients);
      a = sqrt((coefficients[0] * coefficients[0] +
                coefficients[1] * coefficients[1]) +
               1.0);
      PlaneParaOut1_idx_0 = coefficients[0];
      PlaneParaOut1_idx_1 = coefficients[1];
      PlaneParaOut1_idx_3 = coefficients[2];
      i = B->size[0] * B->size[1];
      B->size[0] = result;
      B->size[1] = result_idx_1 + b_result_idx_1;
      emxEnsureCapacity_real_T(B, i);
      distances_data = B->data;
      for (i = 0; i < e_loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          distances_data[i1 + B->size[0] * i] = pointss_data[i1 + result * i];
        }
      }
      for (i = 0; i < f_loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          distances_data[i1 + B->size[0] * result_idx_1] = 1.0;
        }
      }
      nx = B->size[0];
      i = Cnum->size[0] * Cnum->size[1];
      Cnum->size[0] = 1;
      Cnum->size[1] = B->size[0];
      emxEnsureCapacity_real_T(Cnum, i);
      Cnum_data = Cnum->data;
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        Cnum_data[loop_ub] =
            ((PlaneParaOut1_idx_0 * distances_data[loop_ub] +
              PlaneParaOut1_idx_1 * distances_data[B->size[0] + loop_ub]) -
             distances_data[(B->size[0] << 1) + loop_ub]) +
            PlaneParaOut1_idx_3 * distances_data[3 * B->size[0] + loop_ub];
      }
      nx = Cnum->size[1];
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      distances->size[1] = Cnum->size[1];
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        distances_data[loop_ub] = fabs(Cnum_data[loop_ub]);
      }
      i = distances->size[0] * distances->size[1];
      distances->size[0] = 1;
      emxEnsureCapacity_real_T(distances, i);
      distances_data = distances->data;
      loop_ub = distances->size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        distances_data[i] /= a;
      }
      /*  确定内点 */
      /*  更新最优平面模型 */
      PlaneParaOut1_idx_0 = mean(distances);
      if (PlaneParaOut1_idx_0 < bestDist) {
        bestDist = PlaneParaOut1_idx_0;
        i = b_distances->size[0] * b_distances->size[1];
        b_distances->size[0] = 1;
        b_distances->size[1] = distances->size[1];
        emxEnsureCapacity_boolean_T(b_distances, i);
        b_distances_data = b_distances->data;
        loop_ub = distances->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_distances_data[i] = (distances_data[i] < distanceThreshold);
        }
        eml_find(b_distances, r24);
        r25 = r24->data;
        i = inlierIdxFinal[b_i].f1->size[0] * inlierIdxFinal[b_i].f1->size[1];
        inlierIdxFinal[b_i].f1->size[0] = 1;
        inlierIdxFinal[b_i].f1->size[1] = r24->size[1];
        emxEnsureCapacity_real_T(inlierIdxFinal[b_i].f1, i);
        loop_ub = r24->size[1];
        for (i = 0; i < loop_ub; i++) {
          inlierIdxFinal[b_i].f1->data[i] = r25[i];
        }
        i = distancesFianal1[b_i].f1->size[0] *
            distancesFianal1[b_i].f1->size[1];
        distancesFianal1[b_i].f1->size[0] = 1;
        distancesFianal1[b_i].f1->size[1] = distances->size[1];
        emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
        loop_ub = distances->size[1];
        for (i = 0; i < loop_ub; i++) {
          distancesFianal1[b_i].f1->data[i] = distances_data[i];
        }
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Cnum_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Cnum_data[i1 + inlierPoints->size[0] * i] =
            pointss_data[((int)inlierIdxFinal[b_i].f1->data[i1] +
                          pointss->size[0] * i) -
                         1];
      }
    }
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    for (i = 0; i < loop_ub; i++) {
      pointss_data[i] = Cnum_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      pointss_data[i + pointss->size[0]] = Cnum_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < loop_ub; i++) {
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
    loop_ub = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        distances_data[i1 + b_pointss->size[0] * i] =
            pointss_data[i1 + pointss->size[0] * i] - coefficients[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    pointss_data = pointss->data;
    loop_ub = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        pointss_data[i1 + pointss->size[0] * i] =
            distances_data[i1 + b_pointss->size[0] * i];
      }
    }
    b_svd(pointss, a__1, b_pointss, A);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 *
                        acos(fabs((A[6] * 0.0 + A[7] * 0.0) + A[8]))) < 0.5) {
      c = 0;
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_inlierPoints->size[0];
      c_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_inlierPoints, i);
      distances_data = c_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0]];
      }
      polyfit(b_inlierPoints, c_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      bestDist = -1.0;
      d = bb[1];
    } else {
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = pointss->size[0] * pointss->size[1];
      pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      pointss->size[1] = 3;
      emxEnsureCapacity_real_T(pointss, i);
      pointss_data = pointss->data;
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i] = Cnum_data[i];
      }
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i + pointss->size[0]] =
            Cnum_data[i + inlierPoints->size[0]];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < loop_ub; i++) {
        pointss_data[i + pointss->size[0] * 2] = 1.0;
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      distances_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = Cnum_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(pointss, b_inlierPoints, coefficients);
      a = coefficients[0];
      bestDist = coefficients[1];
      d = coefficients[2];
      c = -1;
    }
    PlaneParaOut_data[4 * b_i] = a;
    PlaneParaOut_data[4 * b_i + 1] = bestDist;
    PlaneParaOut_data[4 * b_i + 2] = c;
    PlaneParaOut_data[4 * b_i + 3] = d;
  }
  emxFree_real_T(&b_pointss);
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&c_inlierPoints);
  emxFree_real_T(&b_inlierPoints);
  emxFree_int32_T(&r24);
  emxFree_real_T(&B);
  emxFreeMatrix_cell_wrap_4(PointAll);
  emxFree_real_T(&a__1);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&C);
  emxFree_real_T(&pointss);
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Cnum_data = Cnum->data;
  loop_ub = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Cnum_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  distances_data = distances->data;
  loop_ub = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  distances_data = b_distancesFianal1->data;
  loop_ub = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  distances_data = c_distancesFianal1->data;
  loop_ub = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxInit_real_T(&d_distancesFianal1, 2);
  i = d_distancesFianal1->size[0] * d_distancesFianal1->size[1];
  d_distancesFianal1->size[0] = 1;
  d_distancesFianal1->size[1] = inlierIdxFinal[4].f1->size[1];
  emxEnsureCapacity_real_T(d_distancesFianal1, i);
  distances_data = d_distancesFianal1->data;
  loop_ub = inlierIdxFinal[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[4].f1->data[(int)inlierIdxFinal[4].f1->data[i] - 1];
  }
  emxInit_real_T(&e_distancesFianal1, 2);
  i = e_distancesFianal1->size[0] * e_distancesFianal1->size[1];
  e_distancesFianal1->size[0] = 1;
  e_distancesFianal1->size[1] = inlierIdxFinal[5].f1->size[1];
  emxEnsureCapacity_real_T(e_distancesFianal1, i);
  distances_data = e_distancesFianal1->data;
  loop_ub = inlierIdxFinal[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[5].f1->data[(int)inlierIdxFinal[5].f1->data[i] - 1];
  }
  emxInit_real_T(&f_distancesFianal1, 2);
  i = f_distancesFianal1->size[0] * f_distancesFianal1->size[1];
  f_distancesFianal1->size[0] = 1;
  f_distancesFianal1->size[1] = inlierIdxFinal[6].f1->size[1];
  emxEnsureCapacity_real_T(f_distancesFianal1, i);
  distances_data = f_distancesFianal1->data;
  loop_ub = inlierIdxFinal[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[6].f1->data[(int)inlierIdxFinal[6].f1->data[i] - 1];
  }
  emxInit_real_T(&g_distancesFianal1, 2);
  i = g_distancesFianal1->size[0] * g_distancesFianal1->size[1];
  g_distancesFianal1->size[0] = 1;
  g_distancesFianal1->size[1] = inlierIdxFinal[7].f1->size[1];
  emxEnsureCapacity_real_T(g_distancesFianal1, i);
  distances_data = g_distancesFianal1->data;
  loop_ub = inlierIdxFinal[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] =
        distancesFianal1[7].f1->data[(int)inlierIdxFinal[7].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_1(inlierIdxFinal);
  MaxDis[0] = maximum(Cnum);
  emxFree_real_T(&Cnum);
  MaxDis[1] = maximum(distances);
  emxFree_real_T(&distances);
  MaxDis[2] = maximum(b_distancesFianal1);
  emxFree_real_T(&b_distancesFianal1);
  MaxDis[3] = maximum(c_distancesFianal1);
  emxFree_real_T(&c_distancesFianal1);
  MaxDis[4] = maximum(d_distancesFianal1);
  emxFree_real_T(&d_distancesFianal1);
  MaxDis[5] = maximum(e_distancesFianal1);
  emxFree_real_T(&e_distancesFianal1);
  MaxDis[6] = maximum(f_distancesFianal1);
  emxFree_real_T(&f_distancesFianal1);
  MaxDis[7] = maximum(g_distancesFianal1);
  emxFree_real_T(&g_distancesFianal1);
  i = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  i1 = distancesFianal1[0].f1->size[1] + distancesFianal1[1].f1->size[1];
  c = i1 + distancesFianal1[2].f1->size[1];
  nx = c + distancesFianal1[3].f1->size[1];
  distancesFianal->size[1] = (((nx + distancesFianal1[4].f1->size[1]) +
                               distancesFianal1[5].f1->size[1]) +
                              distancesFianal1[6].f1->size[1]) +
                             distancesFianal1[7].f1->size[1];
  emxEnsureCapacity_real_T(distancesFianal, i);
  distances_data = distancesFianal->data;
  loop_ub = distancesFianal1[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i] = distancesFianal1[0].f1->data[i];
  }
  loop_ub = distancesFianal1[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[i + distancesFianal1[0].f1->size[1]] =
        distancesFianal1[1].f1->data[i];
  }
  loop_ub = distancesFianal1[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(i + distancesFianal1[0].f1->size[1]) +
                   distancesFianal1[1].f1->size[1]] =
        distancesFianal1[2].f1->data[i];
  }
  loop_ub = distancesFianal1[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[((i + distancesFianal1[0].f1->size[1]) +
                    distancesFianal1[1].f1->size[1]) +
                   distancesFianal1[2].f1->size[1]] =
        distancesFianal1[3].f1->data[i];
  }
  loop_ub = distancesFianal1[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + distancesFianal1[0].f1->size[1]) +
                     distancesFianal1[1].f1->size[1]) +
                    distancesFianal1[2].f1->size[1]) +
                   distancesFianal1[3].f1->size[1]] =
        distancesFianal1[4].f1->data[i];
  }
  loop_ub = distancesFianal1[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + i1) + distancesFianal1[2].f1->size[1]) +
                    distancesFianal1[3].f1->size[1]) +
                   distancesFianal1[4].f1->size[1]] =
        distancesFianal1[5].f1->data[i];
  }
  loop_ub = distancesFianal1[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + c) + distancesFianal1[3].f1->size[1]) +
                    distancesFianal1[4].f1->size[1]) +
                   distancesFianal1[5].f1->size[1]] =
        distancesFianal1[6].f1->data[i];
  }
  loop_ub = distancesFianal1[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    distances_data[(((i + nx) + distancesFianal1[4].f1->size[1]) +
                    distancesFianal1[5].f1->size[1]) +
                   distancesFianal1[6].f1->size[1]] =
        distancesFianal1[7].f1->data[i];
  }
  emxFreeMatrix_cell_wrap_1(distancesFianal1);
  emxInit_real_T(&b_PlaneParaOut, 2);
  i = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 8;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, i);
  distances_data = b_PlaneParaOut->data;
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      distances_data[i1 + b_PlaneParaOut->size[0] * i] =
          PlaneParaOut_data[i + 4 * i1];
    }
  }
  for (i = 0; i < 32; i++) {
    PlaneParaOutP_data[i] = distances_data[i];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&cross_vectors[0], 0, 24U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (b_i = 0; b_i < 8; b_i++) {
    if (b_i + 1 < 8) {
      a = PlaneParaOutP_data[b_i + 17];
      bestDist = PlaneParaOutP_data[b_i + 9];
      d = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[b_i + 8];
      cross_vectors[b_i] = PlaneParaOut1_idx_2 * a - bestDist * d;
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[b_i + 1];
      cross_vectors[b_i + 8] =
          PlaneParaOut2_idx_2 * d - PlaneParaOutP_data[b_i] * a;
      cross_vectors[b_i + 16] = PlaneParaOutP_data[b_i] * bestDist -
                                PlaneParaOut2_idx_2 * PlaneParaOut1_idx_2;
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
    bestDist = fabs(cross_vectors[b_i]);
    if (bestDist > 3.3121686421112381E-170) {
      PlaneParaOut1_idx_2 = 1.0;
      a = bestDist;
    } else {
      d = bestDist / 3.3121686421112381E-170;
      PlaneParaOut1_idx_2 = d * d;
    }
    bestDist = fabs(cross_vectors[b_i + 8]);
    if (bestDist > a) {
      d = a / bestDist;
      PlaneParaOut1_idx_2 = PlaneParaOut1_idx_2 * d * d + 1.0;
      a = bestDist;
    } else {
      d = bestDist / a;
      PlaneParaOut1_idx_2 += d * d;
    }
    bestDist = fabs(cross_vectors[b_i + 16]);
    if (bestDist > a) {
      d = a / bestDist;
      PlaneParaOut1_idx_2 = PlaneParaOut1_idx_2 * d * d + 1.0;
      a = bestDist;
    } else {
      d = bestDist / a;
      PlaneParaOut1_idx_2 += d * d;
    }
    PlaneParaOut1_idx_2 = a * sqrt(PlaneParaOut1_idx_2);
    cross_vectors[b_i] /= PlaneParaOut1_idx_2;
    cross_vectors[b_i + 8] /= PlaneParaOut1_idx_2;
    cross_vectors[b_i + 16] /= PlaneParaOut1_idx_2;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  PlaneParaOut1_idx_0 = cross_vectors[0];
  PlaneParaOut2_idx_2 = cross_vectors[8];
  bestDist = cross_vectors[16];
  for (b_i = 0; b_i < 7; b_i++) {
    a = cross_vectors[b_i + 1];
    d = cross_vectors[b_i + 9];
    PlaneParaOut1_idx_2 = cross_vectors[b_i + 17];
    if ((PlaneParaOut1_idx_0 * a + PlaneParaOut2_idx_2 * d) +
            bestDist * PlaneParaOut1_idx_2 <
        0.0) {
      /*  如果方向相反 */
      cross_vectors[b_i + 1] = -a;
      d = -d;
      cross_vectors[b_i + 9] = d;
      PlaneParaOut1_idx_2 = -PlaneParaOut1_idx_2;
      cross_vectors[b_i + 17] = PlaneParaOut1_idx_2;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  /*  计算顶面方程的 d 值 */
  b_c = 0.0;
  /*  计算底面方程的 d 值 */
  c_c = 0.0;
  for (nx = 0; nx < 3; nx++) {
    c = nx << 3;
    PlaneParaOut1_idx_0 = cross_vectors[c];
    for (loop_ub = 0; loop_ub < 7; loop_ub++) {
      PlaneParaOut1_idx_0 += cross_vectors[(c + loop_ub) + 1];
    }
    PlaneParaOut1_idx_0 /= 8.0;
    n[nx] = PlaneParaOut1_idx_0;
    b_c += PlaneParaOut1_idx_0 * P_bound1[nx];
    c_c += PlaneParaOut1_idx_0 * P_bound2[nx];
  }
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 48U * sizeof(double));
  /*  计算顶面和底面的8个顶点 */
  PlaneParaOut1_idx_0 = n[0];
  PlaneParaOut2_idx_2 = n[1];
  bestDist = n[2];
  A[2] = PlaneParaOut1_idx_0;
  A[5] = PlaneParaOut2_idx_2;
  A[8] = bestDist;
  for (b_i = 0; b_i < 8; b_i++) {
    /*  顶面顶点 */
    if (b_i + 1 < 8) {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[b_i];
      a = PlaneParaOutP_data[b_i + 1];
      PlaneParaOut1_idx_1 = PlaneParaOutP_data[b_i + 8];
      d = PlaneParaOutP_data[b_i + 9];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[b_i + 17];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[b_i + 24];
      bestDist = PlaneParaOutP_data[b_i + 25];
    } else {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[7];
      a = PlaneParaOutP_data[0];
      PlaneParaOut1_idx_1 = PlaneParaOutP_data[15];
      d = PlaneParaOutP_data[8];
      PlaneParaOut1_idx_2 = PlaneParaOutP_data[23];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[16];
      PlaneParaOut1_idx_3 = PlaneParaOutP_data[31];
      bestDist = PlaneParaOutP_data[24];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = PlaneParaOut1_idx_0;
    A[1] = a;
    A[3] = PlaneParaOut1_idx_1;
    A[4] = d;
    A[6] = PlaneParaOut1_idx_2;
    A[7] = PlaneParaOut2_idx_2;
    n[0] = -PlaneParaOut1_idx_3;
    n[1] = -bestDist;
    n[2] = b_c;
    c_mldivide(A, n, coefficients);
    PP[b_i] = coefficients[0];
    PP[b_i + 16] = coefficients[1];
    PP[b_i + 32] = coefficients[2];
    /*  求底面和两个相邻侧面的交线 */
    n[0] = -PlaneParaOut1_idx_3;
    n[1] = -bestDist;
    n[2] = c_c;
    c_mldivide(A, n, coefficients);
    PP[b_i + 8] = coefficients[0];
    PP[b_i + 24] = coefficients[1];
    PP[b_i + 40] = coefficients[2];
  }
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 48;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  distances_data = TrianglePoints->data;
  for (i = 0; i < 48; i++) {
    i2 = iv[i];
    distances_data[3 * i] = PP[i2];
    distances_data[3 * i + 1] = PP[i2 + 16];
    distances_data[3 * i + 2] = PP[i2 + 32];
  }
}

/*
 * File trailer for planefit8.c
 *
 * [EOF]
 */
