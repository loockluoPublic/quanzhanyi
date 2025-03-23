/*
 * File: planefit8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

/* Include Files */
#include "planefit8.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "combineVectorElements.h"
#include "dot.h"
#include "find.h"
#include "mean.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "mtimes.h"
#include "norm.h"
#include "planefit4.h"
#include "polyfit.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "validate_print_arguments.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Variable Definitions */
static const double dv1[3] = {1.0, 0.0, 0.0};

static const double dv2[3] = {0.0, 0.0, 1.0};

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
 *                emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                emxArray_real_T *Points4
 *                const emxArray_real_T *Points5
 *                emxArray_real_T *Points6
 *                const emxArray_real_T *Points7
 *                emxArray_real_T *Points8
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[8]
 *                emxArray_real_T *tt1
 * Return Type  : void
 */
void b_planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, emxArray_real_T *Points4,
                 const emxArray_real_T *Points5, emxArray_real_T *Points6,
                 const emxArray_real_T *Points7, emxArray_real_T *Points8,
                 const double P_bound1[3], const double P_bound2[3],
                 double distanceThreshold, emxArray_real_T *PlaneParaOut,
                 emxArray_real_T *TrianglePoints, double MaxDis[8],
                 emxArray_real_T *tt1)
{
  static const signed char b_iv[8] = {0, 1, 2, 5, 8, 11, 14, 17};
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
  emxArray_real_T *Cnum;
  emxArray_real_T *TrianglePoints4;
  emxArray_real_T *a__1;
  emxArray_real_T *a__4;
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *c_pointss;
  emxArray_real_T *d_distancesFianal1;
  emxArray_real_T *distances;
  emxArray_real_T *e_distancesFianal1;
  emxArray_real_T *f_distancesFianal1;
  emxArray_real_T *g_distancesFianal1;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  double Tpoints[60];
  double PP[48];
  double PlaneParaOutP_data[32];
  double tempPP[24];
  double A[9];
  double Isempty[4];
  double PlaneParaOut2[4];
  double TPP10[3];
  double Tv1[3];
  double normaltao[3];
  double bb[2];
  const double *Points1_data;
  const double *Points3_data;
  const double *Points5_data;
  const double *Points7_data;
  double Tv_idx_0;
  double Tv_idx_1;
  double Tv_idx_2;
  double a;
  double b_a;
  double d;
  double d1;
  double d2;
  double d3;
  double d4;
  double tempPP_tmp;
  double *Points2_data;
  double *Points4_data;
  double *Points6_data;
  double *Points8_data;
  double *TrianglePoints4_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  int nx;
  int sizes_idx_1;
  int *r25;
  signed char i2;
  boolean_T empty_non_axis_sizes;
  boolean_T *distances_data;
  Points8_data = Points8->data;
  Points7_data = Points7->data;
  Points6_data = Points6->data;
  Points5_data = Points5->data;
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  /*   增加判断面的点是否完善 */
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&TrianglePoints4, 2);
  b_planefit4(Points1, Points3, Points5, Points7, P_bound1, P_bound2, a__1,
              TrianglePoints4, Isempty, Cnum);
  TrianglePoints4_data = TrianglePoints4->data;
  emxFree_real_T(&a__1);
  for (i = 0; i < 8; i++) {
    nx = 3 * b_iv[i];
    tempPP[3 * i] = TrianglePoints4_data[nx];
    tempPP[3 * i + 1] = TrianglePoints4_data[nx + 1];
    tempPP[3 * i + 2] = TrianglePoints4_data[nx + 2];
  }
  emxFree_real_T(&TrianglePoints4);
  validate_print_arguments(Points2->size[1], Points4->size[1], Points6->size[1],
                           Points8->size[1], PlaneParaOut2);
  printf("Isempty FACE2468: %f, %f, %f, %f\n", PlaneParaOut2[0],
         PlaneParaOut2[1], PlaneParaOut2[2], PlaneParaOut2[3]);
  fflush(stdout);
  if (Points2->size[1] == 0) {
    d = tempPP[0] + 0.0001 * (tempPP[12] - tempPP[0]);
    TPP10[0] = d;
    normaltao[0] =
        tempPP[0] - ((tempPP[0] + 0.0001 * (tempPP[3] - tempPP[0])) + d) / 2.0;
    d = tempPP[1] + 0.0001 * (tempPP[13] - tempPP[1]);
    TPP10[1] = d;
    normaltao[1] =
        tempPP[1] - ((tempPP[1] + 0.0001 * (tempPP[4] - tempPP[1])) + d) / 2.0;
    d = tempPP[2] + 0.0001 * (tempPP[14] - tempPP[2]);
    normaltao[2] =
        tempPP[2] - ((tempPP[2] + 0.0001 * (tempPP[5] - tempPP[2])) + d) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    d1 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= d1;
    Tv1[0] = 1.0;
    normaltao[1] /= d1;
    Tv1[1] = 0.0;
    normaltao[2] /= d1;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    a = dot(Tv1, normaltao);
    Tv1[0] -= a * normaltao[0];
    Tv1[1] -= a * normaltao[1];
    Tv1[2] = 0.0 - a * normaltao[2];
    /*  投影法向量到平面内 */
    d1 = b_norm(Tv1);
    Tv1[0] /= d1;
    Tv1[1] /= d1;
    Tv1[2] /= d1;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    d1 = TPP10[0];
    d2 = TPP10[1];
    d3 = Tv1[0];
    d4 = Tv1[1];
    tempPP_tmp = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      a = (b_rand() - 0.5) * 2.0;
      b_a = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (d1 + a * d3) + b_a * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (d2 + a * d4) + b_a * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (d + a * tempPP_tmp) + b_a * Tv_idx_2;
    }
    i = Points2->size[0] * Points2->size[1];
    Points2->size[0] = 3;
    Points2->size[1] = 20;
    emxEnsureCapacity_real_T(Points2, i);
    Points2_data = Points2->data;
    for (i = 0; i < 60; i++) {
      Points2_data[i] = Tpoints[i];
    }
  }
  if (Points4->size[1] == 0) {
    d = tempPP[12] + 0.0001 * (tempPP[0] - tempPP[12]);
    TPP10[0] = d;
    normaltao[0] =
        tempPP[12] -
        (d + (tempPP[12] + 0.0001 * (tempPP[18] - tempPP[12]))) / 2.0;
    d = tempPP[13] + 0.0001 * (tempPP[1] - tempPP[13]);
    TPP10[1] = d;
    normaltao[1] =
        tempPP[13] -
        (d + (tempPP[13] + 0.0001 * (tempPP[19] - tempPP[13]))) / 2.0;
    d = tempPP[14] + 0.0001 * (tempPP[2] - tempPP[14]);
    normaltao[2] =
        tempPP[14] -
        (d + (tempPP[14] + 0.0001 * (tempPP[20] - tempPP[14]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    d1 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= d1;
    Tv1[0] = 1.0;
    normaltao[1] /= d1;
    Tv1[1] = 0.0;
    normaltao[2] /= d1;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    a = dot(Tv1, normaltao);
    Tv1[0] -= a * normaltao[0];
    Tv1[1] -= a * normaltao[1];
    Tv1[2] = 0.0 - a * normaltao[2];
    /*  投影法向量到平面内 */
    d1 = b_norm(Tv1);
    Tv1[0] /= d1;
    Tv1[1] /= d1;
    Tv1[2] /= d1;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    d1 = TPP10[0];
    d2 = TPP10[1];
    d3 = Tv1[0];
    d4 = Tv1[1];
    tempPP_tmp = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      a = (b_rand() - 0.5) * 2.0;
      b_a = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (d1 + a * d3) + b_a * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (d2 + a * d4) + b_a * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (d + a * tempPP_tmp) + b_a * Tv_idx_2;
    }
    i = Points4->size[0] * Points4->size[1];
    Points4->size[0] = 3;
    Points4->size[1] = 20;
    emxEnsureCapacity_real_T(Points4, i);
    Points4_data = Points4->data;
    for (i = 0; i < 60; i++) {
      Points4_data[i] = Tpoints[i];
    }
  }
  if (Points6->size[1] == 0) {
    d = tempPP[18] + 0.0001 * (tempPP[12] - tempPP[18]);
    TPP10[0] = d;
    normaltao[0] = tempPP[18] -
                   (d + (tempPP[18] + 0.0001 * (tempPP[3] - tempPP[18]))) / 2.0;
    d = tempPP[19] + 0.0001 * (tempPP[13] - tempPP[19]);
    TPP10[1] = d;
    normaltao[1] = tempPP[19] -
                   (d + (tempPP[19] + 0.0001 * (tempPP[4] - tempPP[19]))) / 2.0;
    d = tempPP[20] + 0.0001 * (tempPP[14] - tempPP[20]);
    normaltao[2] = tempPP[20] -
                   (d + (tempPP[20] + 0.0001 * (tempPP[5] - tempPP[20]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    d1 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= d1;
    Tv1[0] = 1.0;
    normaltao[1] /= d1;
    Tv1[1] = 0.0;
    normaltao[2] /= d1;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    a = dot(Tv1, normaltao);
    Tv1[0] -= a * normaltao[0];
    Tv1[1] -= a * normaltao[1];
    Tv1[2] = 0.0 - a * normaltao[2];
    /*  投影法向量到平面内 */
    d1 = b_norm(Tv1);
    Tv1[0] /= d1;
    Tv1[1] /= d1;
    Tv1[2] /= d1;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    d1 = TPP10[0];
    d2 = TPP10[1];
    d3 = Tv1[0];
    d4 = Tv1[1];
    tempPP_tmp = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      a = (b_rand() - 0.5) * 2.0;
      b_a = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (d1 + a * d3) + b_a * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (d2 + a * d4) + b_a * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (d + a * tempPP_tmp) + b_a * Tv_idx_2;
    }
    i = Points6->size[0] * Points6->size[1];
    Points6->size[0] = 3;
    Points6->size[1] = 20;
    emxEnsureCapacity_real_T(Points6, i);
    Points6_data = Points6->data;
    for (i = 0; i < 60; i++) {
      Points6_data[i] = Tpoints[i];
    }
  }
  if (Points8->size[1] == 0) {
    d = tempPP[3] + 0.0001 * (tempPP[0] - tempPP[3]);
    TPP10[0] = d;
    normaltao[0] =
        tempPP[3] - (d + (tempPP[3] + 0.0001 * (tempPP[18] - tempPP[3]))) / 2.0;
    d = tempPP[4] + 0.0001 * (tempPP[1] - tempPP[4]);
    TPP10[1] = d;
    normaltao[1] =
        tempPP[4] - (d + (tempPP[4] + 0.0001 * (tempPP[19] - tempPP[4]))) / 2.0;
    d = tempPP[5] + 0.0001 * (tempPP[2] - tempPP[5]);
    normaltao[2] =
        tempPP[5] - (d + (tempPP[5] + 0.0001 * (tempPP[20] - tempPP[5]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    d1 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= d1;
    Tv1[0] = 1.0;
    normaltao[1] /= d1;
    Tv1[1] = 0.0;
    normaltao[2] /= d1;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    a = dot(Tv1, normaltao);
    Tv1[0] -= a * normaltao[0];
    Tv1[1] -= a * normaltao[1];
    Tv1[2] = 0.0 - a * normaltao[2];
    /*  投影法向量到平面内 */
    d1 = b_norm(Tv1);
    Tv1[0] /= d1;
    Tv1[1] /= d1;
    Tv1[2] /= d1;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    d1 = TPP10[0];
    d2 = TPP10[1];
    d3 = Tv1[0];
    d4 = Tv1[1];
    tempPP_tmp = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      a = (b_rand() - 0.5) * 2.0;
      b_a = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (d1 + a * d3) + b_a * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (d2 + a * d4) + b_a * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (d + a * tempPP_tmp) + b_a * Tv_idx_2;
    }
    i = Points8->size[0] * Points8->size[1];
    Points8->size[0] = 3;
    Points8->size[1] = 20;
    emxEnsureCapacity_real_T(Points8, i);
    Points8_data = Points8->data;
    for (i = 0; i < 60; i++) {
      Points8_data[i] = Tpoints[i];
    }
  }
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
  Points2_data = PlaneParaOut->data;
  for (i = 0; i < 32; i++) {
    Points2_data[i] = 0.0;
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
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&a__4, 2);
  emxInit_real_T(&B, 2);
  emxInit_int32_T(&r24);
  emxInit_real_T(&b_pointss, 2);
  emxInit_real_T(&c_pointss, 1);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_inlierPoints, 1);
  for (b_i = 0; b_i < 8; b_i++) {
    /*  平面拟合 */
    loop_ub = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points4_data[i1 + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * i1];
      }
    }
    /*  最优内点距离 */
    /*  随机选择三个点 */
    /*  samplePoints = pointss(sampleIdx, :); */
    /*  计算平面模型 */
    /*  A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)]; */
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    Points8_data = b_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i] = Points4_data[i];
      Points8_data[i + b_pointss->size[0]] = Points4_data[i + pointss->size[0]];
    }
    nx = pointss->size[0];
    if (nx < 3) {
      nx = 3;
    }
    if (pointss->size[0] == 0) {
      loop_ub = 0;
    } else {
      loop_ub = nx;
    }
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i + b_pointss->size[0] * 2] = 1.0;
    }
    i = c_pointss->size[0];
    c_pointss->size[0] = pointss->size[0];
    emxEnsureCapacity_real_T(c_pointss, i);
    Points8_data = c_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i] = Points4_data[i + pointss->size[0] * 2];
    }
    mldivide(b_pointss, c_pointss, TPP10);
    if (pointss->size[0] != 0) {
      nx = pointss->size[0];
    } else {
      nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
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
    Tv_idx_0 = sqrt((TPP10[0] * TPP10[0] + TPP10[1] * TPP10[1]) + 1.0);
    Isempty[0] = TPP10[0];
    Isempty[1] = TPP10[1];
    Isempty[3] = TPP10[2];
    i = B->size[0] * B->size[1];
    B->size[0] = nx;
    B->size[1] = i2 + sizes_idx_1;
    emxEnsureCapacity_real_T(B, i);
    Points8_data = B->data;
    loop_ub = i2;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        Points8_data[i1 + B->size[0] * i] = Points4_data[i1 + nx * i];
      }
    }
    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        Points8_data[i1 + B->size[0] * i2] = 1.0;
      }
    }
    nx = B->size[0];
    i = Cnum->size[0] * Cnum->size[1];
    Cnum->size[0] = 1;
    Cnum->size[1] = B->size[0];
    emxEnsureCapacity_real_T(Cnum, i);
    Points6_data = Cnum->data;
    for (sizes_idx_1 = 0; sizes_idx_1 < nx; sizes_idx_1++) {
      Points6_data[sizes_idx_1] =
          ((Isempty[0] * Points8_data[sizes_idx_1] +
            Isempty[1] * Points8_data[B->size[0] + sizes_idx_1]) -
           Points8_data[(B->size[0] << 1) + sizes_idx_1]) +
          Isempty[3] * Points8_data[3 * B->size[0] + sizes_idx_1];
    }
    nx = Cnum->size[1];
    i = distances->size[0] * distances->size[1];
    distances->size[0] = 1;
    distances->size[1] = Cnum->size[1];
    emxEnsureCapacity_real_T(distances, i);
    Points8_data = distances->data;
    for (sizes_idx_1 = 0; sizes_idx_1 < nx; sizes_idx_1++) {
      Points8_data[sizes_idx_1] = fabs(Points6_data[sizes_idx_1]);
    }
    i = distances->size[0] * distances->size[1];
    distances->size[0] = 1;
    emxEnsureCapacity_real_T(distances, i);
    Points8_data = distances->data;
    loop_ub = distances->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      Points8_data[i] /= Tv_idx_0;
    }
    /*  确定内点 */
    /*  更新最优平面模型 */
    if (b_combineVectorElements(distances) / (double)distances->size[1] <
        99999.0) {
      i = b_distances->size[0] * b_distances->size[1];
      b_distances->size[0] = 1;
      b_distances->size[1] = distances->size[1];
      emxEnsureCapacity_boolean_T(b_distances, i);
      distances_data = b_distances->data;
      loop_ub = distances->size[1];
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = (Points8_data[i] < distanceThreshold);
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
      i = distancesFianal1[b_i].f1->size[0] * distancesFianal1[b_i].f1->size[1];
      distancesFianal1[b_i].f1->size[0] = 1;
      distancesFianal1[b_i].f1->size[1] = distances->size[1];
      emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
      loop_ub = distances->size[1];
      for (i = 0; i < loop_ub; i++) {
        distancesFianal1[b_i].f1->data[i] = Points8_data[i];
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Points6_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points6_data[i1 + inlierPoints->size[0] * i] =
            Points4_data[((int)inlierIdxFinal[b_i].f1->data[i1] +
                          pointss->size[0] * i) -
                         1];
      }
    }
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i] = Points6_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i + pointss->size[0]] =
          Points6_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i + pointss->size[0] * 2] =
          Points6_data[i + inlierPoints->size[0] * 2];
    }
    /*  Fit a plane through the points */
    mean(pointss, TPP10);
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    Points8_data = b_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points8_data[i1 + b_pointss->size[0] * i] =
            Points4_data[i1 + pointss->size[0] * i] - TPP10[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    loop_ub = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points4_data[i1 + pointss->size[0] * i] =
            Points8_data[i1 + b_pointss->size[0] * i];
      }
    }
    c_svd(pointss, a__4, b_pointss, A);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 * acos(fabs(dot(&A[6], dv2)))) < 2.0) {
      nx = 0;
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_pointss->size[0];
      c_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_pointss, i);
      Points8_data = c_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      Points8_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i + inlierPoints->size[0]];
      }
      polyfit(c_pointss, b_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      a = bb[0];
      Tv_idx_0 = -1.0;
      Tv_idx_1 = bb[1];
    } else {
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_pointss->size[0] * b_pointss->size[1];
      b_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      b_pointss->size[1] = 3;
      emxEnsureCapacity_real_T(b_pointss, i);
      Points8_data = b_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i];
      }
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i + b_pointss->size[0]] =
            Points6_data[i + inlierPoints->size[0]];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i + b_pointss->size[0] * 2] = 1.0;
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_pointss->size[0];
      c_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_pointss, i);
      Points8_data = c_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(b_pointss, c_pointss, TPP10);
      a = TPP10[0];
      Tv_idx_0 = TPP10[1];
      Tv_idx_1 = TPP10[2];
      nx = -1;
    }
    Points2_data[4 * b_i] = a;
    Points2_data[4 * b_i + 1] = Tv_idx_0;
    Points2_data[4 * b_i + 2] = nx;
    Points2_data[4 * b_i + 3] = Tv_idx_1;
  }
  emxFree_real_T(&b_inlierPoints);
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&c_pointss);
  emxFree_real_T(&b_pointss);
  emxFree_int32_T(&r24);
  emxFree_real_T(&B);
  emxFreeMatrix_cell_wrap_4(PointAll);
  emxFree_real_T(&a__4);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&pointss);
  /* %%%%%%%% 测试 %%%%%%%%%%%% */
  Points2_data[8] = 0.0;
  Points2_data[9] = 0.0;
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points6_data = Cnum->data;
  loop_ub = Points3->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points6_data[i] = Points3_data[3 * i + 2];
  }
  Points2_data[11] = b_combineVectorElements(Cnum) / (double)Points3->size[1];
  Points2_data[24] = 0.0;
  Points2_data[25] = 0.0;
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = Points7->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points6_data = Cnum->data;
  loop_ub = Points7->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points6_data[i] = Points7_data[3 * i + 2];
  }
  Points2_data[27] = b_combineVectorElements(Cnum) / (double)Points7->size[1];
  d = (Points2_data[0] + Points2_data[16]) / 2.0;
  Points2_data[0] = d;
  Points2_data[16] = d;
  d = (Points2_data[1] + Points2_data[17]) / 2.0;
  Points2_data[1] = d;
  Points2_data[17] = d;
  /* %%%%%%%% 测试 %%%%%%%%%%%% */
  /*  %%%%%%%%% 约束 %%%%%%%%%%%% */
  /*   */
  /*  % 左、右面竖直 */
  /*  PlaneParaOut(3,1) = 0; */
  /*  PlaneParaOut(3,5) = 0; */
  /*  % 左右面平行 */
  /*  PlaneParaOut(1:2,1) = (PlaneParaOut(1:2,1)+PlaneParaOut(1:2,5))./2 ; */
  /*  PlaneParaOut(1:2,5) = PlaneParaOut(1:2,1) ; */
  /*   */
  /*  %%%%%%%% 约束只能前后倾斜  %%%%%%%%% */
  /*      t1 = PlaneParaOut(1,5); */
  /*      t2 = PlaneParaOut(2,5); */
  /*   */
  /*      % 输入: */
  /*      % points: n×3 矩阵，每行 (xi, yi, zi) */
  /*      % t1, t2: 约束参数 */
  /*   */
  /*      X = Points3(1,:)';  % 提取 x 坐标 */
  /*      Y = Points3(2,:)';  % 提取 y 坐标 */
  /*      Z = Points3(3,:)';  % 提取 z 坐标 */
  /*   */
  /*      % 构造设计矩阵 A 和观测向量 b */
  /*      A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z */
  /*      b = Z; % 目标值 */
  /*   */
  /*      % 约束矩阵 */
  /*      C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0 */
  /*   */
  /*      % 使用约束最小二乘求解 */
  /*      n = size(A, 2); */
  /*      M = [A'*A, C'; C, 0];  % 扩展矩阵 */
  /*      rhs = [A'*b; 0];  % 右端项 */
  /*      solution = M \ rhs; % 求解 */
  /*   */
  /*      % 提取参数 a, b, d */
  /*      a = solution(1); */
  /*      b = solution(2); */
  /*      d = solution(3); */
  /*   */
  /*      % 输出参数 */
  /*      params = [a, b, d]; */
  /*      PlaneParaOut(:,3) = [a; b;-1 ;d]; */
  /*   */
  /*    */
  /*      % 输入: */
  /*      % points: n×3 矩阵，每行 (xi, yi, zi) */
  /*      % t1, t2: 约束参数 */
  /*   */
  /*      X = Points7(1,:)';  % 提取 x 坐标 */
  /*      Y = Points7(2,:)';  % 提取 y 坐标 */
  /*      Z = Points7(3,:)';  % 提取 z 坐标 */
  /*   */
  /*      % 构造设计矩阵 A 和观测向量 b */
  /*      A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z */
  /*      b = Z; % 目标值 */
  /*   */
  /*      % 约束矩阵 */
  /*      C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0 */
  /*   */
  /*      % 使用约束最小二乘求解 */
  /*      n = size(A, 2); */
  /*      M = [A'*A, C'; C, 0];  % 扩展矩阵 */
  /*      rhs = [A'*b; 0];  % 右端项 */
  /*      solution = M \ rhs; % 求解 */
  /*   */
  /*      % 提取参数 a, b, d */
  /*      a = solution(1); */
  /*      b = solution(2); */
  /*      d = solution(3); */
  /*   */
  /*      % 输出参数 */
  /*      params = [a, b, d]; */
  /*      PlaneParaOut(:,7) = [a; b;-1 ;d]; */
  /*   */
  /*  PlaneParaOut(1:2,3) = (PlaneParaOut(1:2,3)+PlaneParaOut(1:2,7))./2 ; */
  /*  PlaneParaOut(1:2,7) = PlaneParaOut(1:2,3) ; */
  /*  %%%%%%%%%%% 约束只能前后倾斜  %%%%%%%%%%%% */
  i = tt1->size[0] * tt1->size[1];
  tt1->size[0] = 1;
  tt1->size[1] = distancesFianal1[0].f1->size[1];
  emxEnsureCapacity_real_T(tt1, i);
  Points8_data = tt1->data;
  loop_ub = distancesFianal1[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[0].f1->data[i];
  }
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points6_data = Cnum->data;
  loop_ub = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points6_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  Points8_data = distances->data;
  loop_ub = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  Points8_data = b_distancesFianal1->data;
  loop_ub = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  Points8_data = c_distancesFianal1->data;
  loop_ub = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxInit_real_T(&d_distancesFianal1, 2);
  i = d_distancesFianal1->size[0] * d_distancesFianal1->size[1];
  d_distancesFianal1->size[0] = 1;
  d_distancesFianal1->size[1] = inlierIdxFinal[4].f1->size[1];
  emxEnsureCapacity_real_T(d_distancesFianal1, i);
  Points8_data = d_distancesFianal1->data;
  loop_ub = inlierIdxFinal[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[4].f1->data[(int)inlierIdxFinal[4].f1->data[i] - 1];
  }
  emxInit_real_T(&e_distancesFianal1, 2);
  i = e_distancesFianal1->size[0] * e_distancesFianal1->size[1];
  e_distancesFianal1->size[0] = 1;
  e_distancesFianal1->size[1] = inlierIdxFinal[5].f1->size[1];
  emxEnsureCapacity_real_T(e_distancesFianal1, i);
  Points8_data = e_distancesFianal1->data;
  loop_ub = inlierIdxFinal[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[5].f1->data[(int)inlierIdxFinal[5].f1->data[i] - 1];
  }
  emxInit_real_T(&f_distancesFianal1, 2);
  i = f_distancesFianal1->size[0] * f_distancesFianal1->size[1];
  f_distancesFianal1->size[0] = 1;
  f_distancesFianal1->size[1] = inlierIdxFinal[6].f1->size[1];
  emxEnsureCapacity_real_T(f_distancesFianal1, i);
  Points8_data = f_distancesFianal1->data;
  loop_ub = inlierIdxFinal[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[6].f1->data[(int)inlierIdxFinal[6].f1->data[i] - 1];
  }
  emxInit_real_T(&g_distancesFianal1, 2);
  i = g_distancesFianal1->size[0] * g_distancesFianal1->size[1];
  g_distancesFianal1->size[0] = 1;
  g_distancesFianal1->size[1] = inlierIdxFinal[7].f1->size[1];
  emxEnsureCapacity_real_T(g_distancesFianal1, i);
  Points8_data = g_distancesFianal1->data;
  loop_ub = inlierIdxFinal[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[7].f1->data[(int)inlierIdxFinal[7].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_1(distancesFianal1);
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
  emxInit_real_T(&b_PlaneParaOut, 2);
  i = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 8;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, i);
  Points8_data = b_PlaneParaOut->data;
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      Points8_data[i1 + b_PlaneParaOut->size[0] * i] = Points2_data[i + 4 * i1];
    }
  }
  for (i = 0; i < 32; i++) {
    PlaneParaOutP_data[i] = Points8_data[i];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&tempPP[0], 0, 24U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (b_i = 0; b_i < 8; b_i++) {
    if (b_i + 1 < 8) {
      Tv_idx_0 = PlaneParaOutP_data[b_i + 17];
      Tv_idx_1 = PlaneParaOutP_data[b_i + 9];
      Tv_idx_2 = PlaneParaOutP_data[b_i + 16];
      tempPP_tmp = PlaneParaOutP_data[b_i + 8];
      tempPP[b_i] = tempPP_tmp * Tv_idx_0 - Tv_idx_1 * Tv_idx_2;
      b_a = PlaneParaOutP_data[b_i + 1];
      tempPP[b_i + 8] = b_a * Tv_idx_2 - PlaneParaOutP_data[b_i] * Tv_idx_0;
      tempPP[b_i + 16] = PlaneParaOutP_data[b_i] * Tv_idx_1 - b_a * tempPP_tmp;
    } else {
      tempPP[7] = PlaneParaOutP_data[15] * PlaneParaOutP_data[16] -
                  PlaneParaOutP_data[8] * PlaneParaOutP_data[23];
      tempPP[15] = PlaneParaOutP_data[0] * PlaneParaOutP_data[23] -
                   PlaneParaOutP_data[7] * PlaneParaOutP_data[16];
      tempPP[23] = PlaneParaOutP_data[7] * PlaneParaOutP_data[8] -
                   PlaneParaOutP_data[0] * PlaneParaOutP_data[15];
      /*  最后一个与第一个相邻 */
    }
    TPP10[0] = tempPP[b_i];
    TPP10[1] = tempPP[b_i + 8];
    TPP10[2] = tempPP[b_i + 16];
    d = b_norm(TPP10);
    tempPP[b_i] /= d;
    tempPP[b_i + 8] /= d;
    tempPP[b_i + 16] /= d;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  d = tempPP[0];
  d1 = tempPP[8];
  d2 = tempPP[16];
  for (b_i = 0; b_i < 7; b_i++) {
    Tv_idx_0 = tempPP[b_i + 1];
    d3 = tempPP[b_i + 9];
    d4 = tempPP[b_i + 17];
    if ((d * Tv_idx_0 + d1 * d3) + d2 * d4 < 0.0) {
      /*  如果方向相反 */
      tempPP[b_i + 1] = -Tv_idx_0;
      d3 = -d3;
      tempPP[b_i + 9] = d3;
      d4 = -d4;
      tempPP[b_i + 17] = d4;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  b_mean(tempPP, TPP10);
  /*  计算顶面方程的 d 值 */
  /*  计算底面方程的 d 值 */
  Tv_idx_0 = (TPP10[0] * P_bound1[0] + TPP10[1] * P_bound1[1]) +
             TPP10[2] * P_bound1[2];
  Tv_idx_1 = (TPP10[0] * P_bound2[0] + TPP10[1] * P_bound2[1]) +
             TPP10[2] * P_bound2[2];
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 48U * sizeof(double));
  /*  计算顶面和底面的8个顶点 */
  d = TPP10[0];
  d1 = TPP10[1];
  d2 = TPP10[2];
  A[2] = d;
  A[5] = d1;
  A[8] = d2;
  for (b_i = 0; b_i < 8; b_i++) {
    /*  顶面顶点 */
    if (b_i + 1 < 8) {
      Isempty[0] = PlaneParaOutP_data[b_i];
      PlaneParaOut2[0] = PlaneParaOutP_data[b_i + 1];
      Isempty[1] = PlaneParaOutP_data[b_i + 8];
      PlaneParaOut2[1] = PlaneParaOutP_data[b_i + 9];
      Isempty[2] = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut2[2] = PlaneParaOutP_data[b_i + 17];
      Isempty[3] = PlaneParaOutP_data[b_i + 24];
      PlaneParaOut2[3] = PlaneParaOutP_data[b_i + 25];
    } else {
      Isempty[0] = PlaneParaOutP_data[7];
      PlaneParaOut2[0] = PlaneParaOutP_data[0];
      Isempty[1] = PlaneParaOutP_data[15];
      PlaneParaOut2[1] = PlaneParaOutP_data[8];
      Isempty[2] = PlaneParaOutP_data[23];
      PlaneParaOut2[2] = PlaneParaOutP_data[16];
      Isempty[3] = PlaneParaOutP_data[31];
      PlaneParaOut2[3] = PlaneParaOutP_data[24];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = Isempty[0];
    A[1] = PlaneParaOut2[0];
    A[3] = Isempty[1];
    A[4] = PlaneParaOut2[1];
    A[6] = Isempty[2];
    A[7] = PlaneParaOut2[2];
    normaltao[0] = -Isempty[3];
    normaltao[1] = -PlaneParaOut2[3];
    normaltao[2] = Tv_idx_0;
    b_mldivide(A, normaltao, TPP10);
    PP[b_i] = TPP10[0];
    PP[b_i + 16] = TPP10[1];
    PP[b_i + 32] = TPP10[2];
    /*  求底面和两个相邻侧面的交线 */
    normaltao[0] = -Isempty[3];
    normaltao[1] = -PlaneParaOut2[3];
    normaltao[2] = Tv_idx_1;
    b_mldivide(A, normaltao, TPP10);
    PP[b_i + 8] = TPP10[0];
    PP[b_i + 24] = TPP10[1];
    PP[b_i + 40] = TPP10[2];
  }
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 48;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  Points8_data = TrianglePoints->data;
  for (i = 0; i < 48; i++) {
    i2 = iv[i];
    Points8_data[3 * i] = PP[i2];
    Points8_data[3 * i + 1] = PP[i2 + 16];
    Points8_data[3 * i + 2] = PP[i2 + 32];
  }
  /*  倒角计算 */
}

/*
 * Points 输入点 3*n
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  PP 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                emxArray_real_T *Points4
 *                const emxArray_real_T *Points5
 *                emxArray_real_T *Points6
 *                const emxArray_real_T *Points7
 *                emxArray_real_T *Points8
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[8]
 *                emxArray_real_T *tt1
 *                emxArray_real_T *tt2
 *                emxArray_real_T *tt3
 *                emxArray_real_T *tt4
 *                emxArray_real_T *tt5
 *                emxArray_real_T *tt6
 *                emxArray_real_T *tt7
 *                emxArray_real_T *tt8
 *                double LenDaoJiao[8]
 * Return Type  : void
 */
void planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
               const emxArray_real_T *Points3, emxArray_real_T *Points4,
               const emxArray_real_T *Points5, emxArray_real_T *Points6,
               const emxArray_real_T *Points7, emxArray_real_T *Points8,
               const double P_bound1[3], const double P_bound2[3],
               double distanceThreshold, emxArray_real_T *PlaneParaOut,
               emxArray_real_T *TrianglePoints, double MaxDis[8],
               emxArray_real_T *tt1, emxArray_real_T *tt2, emxArray_real_T *tt3,
               emxArray_real_T *tt4, emxArray_real_T *tt5, emxArray_real_T *tt6,
               emxArray_real_T *tt7, emxArray_real_T *tt8, double LenDaoJiao[8])
{
  static const signed char b_iv[8] = {0, 1, 2, 5, 8, 11, 14, 17};
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
  emxArray_real_T *Cnum;
  emxArray_real_T *TrianglePoints4;
  emxArray_real_T *a__1;
  emxArray_real_T *a__4;
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_distancesFianal1;
  emxArray_real_T *b_inlierPoints;
  emxArray_real_T *b_pointss;
  emxArray_real_T *c_distancesFianal1;
  emxArray_real_T *c_pointss;
  emxArray_real_T *d_distancesFianal1;
  emxArray_real_T *d_pointss;
  emxArray_real_T *distances;
  emxArray_real_T *e_distancesFianal1;
  emxArray_real_T *f_distancesFianal1;
  emxArray_real_T *g_distancesFianal1;
  emxArray_real_T *inlierPoints;
  emxArray_real_T *pointss;
  double Tpoints[60];
  double PP[48];
  double b_PP[48];
  double PlaneParaOutP_data[32];
  double tempPP[24];
  double A[9];
  double Isempty[4];
  double PlaneParaOut2[4];
  double TPP10[3];
  double TPP9[3];
  double Tv1[3];
  double normaltao[3];
  double bb[2];
  const double *Points1_data;
  const double *Points3_data;
  const double *Points5_data;
  const double *Points7_data;
  double L1;
  double L2;
  double L6;
  double L7;
  double L8;
  double RETL1;
  double RETL2;
  double RETL3;
  double RETL4;
  double Tv_idx_0;
  double Tv_idx_1;
  double Tv_idx_2;
  double *Points2_data;
  double *Points4_data;
  double *Points6_data;
  double *Points8_data;
  double *TrianglePoints4_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  int nx;
  int sizes_idx_1;
  int *r25;
  signed char i2;
  boolean_T empty_non_axis_sizes;
  boolean_T *distances_data;
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
  /*   增加判断面的点是否完善 */
  emxInit_real_T(&Cnum, 2);
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&TrianglePoints4, 2);
  planefit4(Points1, Points3, Points5, Points7, P_bound1, P_bound2,
            distanceThreshold, a__1, TrianglePoints4, Isempty, Cnum);
  TrianglePoints4_data = TrianglePoints4->data;
  emxFree_real_T(&a__1);
  for (i = 0; i < 8; i++) {
    nx = 3 * b_iv[i];
    tempPP[3 * i] = TrianglePoints4_data[nx];
    tempPP[3 * i + 1] = TrianglePoints4_data[nx + 1];
    tempPP[3 * i + 2] = TrianglePoints4_data[nx + 2];
  }
  validate_print_arguments(Points2->size[1], Points4->size[1], Points6->size[1],
                           Points8->size[1], PlaneParaOut2);
  printf("Isempty FACE2468: %f, %f, %f, %f\n", PlaneParaOut2[0],
         PlaneParaOut2[1], PlaneParaOut2[2], PlaneParaOut2[3]);
  fflush(stdout);
  if (Points2->size[1] == 0) {
    RETL2 = tempPP[0] + 0.0001 * (tempPP[12] - tempPP[0]);
    TPP10[0] = RETL2;
    normaltao[0] =
        tempPP[0] -
        ((tempPP[0] + 0.0001 * (tempPP[3] - tempPP[0])) + RETL2) / 2.0;
    RETL2 = tempPP[1] + 0.0001 * (tempPP[13] - tempPP[1]);
    TPP10[1] = RETL2;
    normaltao[1] =
        tempPP[1] -
        ((tempPP[1] + 0.0001 * (tempPP[4] - tempPP[1])) + RETL2) / 2.0;
    RETL2 = tempPP[2] + 0.0001 * (tempPP[14] - tempPP[2]);
    normaltao[2] =
        tempPP[2] -
        ((tempPP[2] + 0.0001 * (tempPP[5] - tempPP[2])) + RETL2) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    RETL3 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= RETL3;
    Tv1[0] = 1.0;
    normaltao[1] /= RETL3;
    Tv1[1] = 0.0;
    normaltao[2] /= RETL3;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    L8 = dot(Tv1, normaltao);
    Tv1[0] -= L8 * normaltao[0];
    Tv1[1] -= L8 * normaltao[1];
    Tv1[2] = 0.0 - L8 * normaltao[2];
    /*  投影法向量到平面内 */
    RETL3 = b_norm(Tv1);
    Tv1[0] /= RETL3;
    Tv1[1] /= RETL3;
    Tv1[2] /= RETL3;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    RETL3 = TPP10[0];
    RETL1 = TPP10[1];
    L1 = Tv1[0];
    L2 = Tv1[1];
    L6 = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      L8 = (b_rand() - 0.5) * 2.0;
      L7 = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (RETL3 + L8 * L1) + L7 * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (RETL1 + L8 * L2) + L7 * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (RETL2 + L8 * L6) + L7 * Tv_idx_2;
    }
    i = Points2->size[0] * Points2->size[1];
    Points2->size[0] = 3;
    Points2->size[1] = 20;
    emxEnsureCapacity_real_T(Points2, i);
    Points2_data = Points2->data;
    for (i = 0; i < 60; i++) {
      Points2_data[i] = Tpoints[i];
    }
  }
  if (Points4->size[1] == 0) {
    RETL2 = tempPP[12] + 0.0001 * (tempPP[0] - tempPP[12]);
    TPP9[0] = RETL2;
    normaltao[0] =
        tempPP[12] -
        (RETL2 + (tempPP[12] + 0.0001 * (tempPP[18] - tempPP[12]))) / 2.0;
    RETL2 = tempPP[13] + 0.0001 * (tempPP[1] - tempPP[13]);
    TPP9[1] = RETL2;
    normaltao[1] =
        tempPP[13] -
        (RETL2 + (tempPP[13] + 0.0001 * (tempPP[19] - tempPP[13]))) / 2.0;
    RETL2 = tempPP[14] + 0.0001 * (tempPP[2] - tempPP[14]);
    normaltao[2] =
        tempPP[14] -
        (RETL2 + (tempPP[14] + 0.0001 * (tempPP[20] - tempPP[14]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    RETL3 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= RETL3;
    Tv1[0] = 1.0;
    normaltao[1] /= RETL3;
    Tv1[1] = 0.0;
    normaltao[2] /= RETL3;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    L8 = dot(Tv1, normaltao);
    Tv1[0] -= L8 * normaltao[0];
    Tv1[1] -= L8 * normaltao[1];
    Tv1[2] = 0.0 - L8 * normaltao[2];
    /*  投影法向量到平面内 */
    RETL3 = b_norm(Tv1);
    Tv1[0] /= RETL3;
    Tv1[1] /= RETL3;
    Tv1[2] /= RETL3;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    RETL3 = TPP9[0];
    RETL1 = TPP9[1];
    L1 = Tv1[0];
    L2 = Tv1[1];
    L6 = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      L8 = (b_rand() - 0.5) * 2.0;
      L7 = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (RETL3 + L8 * L1) + L7 * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (RETL1 + L8 * L2) + L7 * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (RETL2 + L8 * L6) + L7 * Tv_idx_2;
    }
    i = Points4->size[0] * Points4->size[1];
    Points4->size[0] = 3;
    Points4->size[1] = 20;
    emxEnsureCapacity_real_T(Points4, i);
    Points4_data = Points4->data;
    for (i = 0; i < 60; i++) {
      Points4_data[i] = Tpoints[i];
    }
  }
  if (Points6->size[1] == 0) {
    RETL2 = tempPP[18] + 0.0001 * (tempPP[12] - tempPP[18]);
    TPP9[0] = RETL2;
    normaltao[0] =
        tempPP[18] -
        (RETL2 + (tempPP[18] + 0.0001 * (tempPP[3] - tempPP[18]))) / 2.0;
    RETL2 = tempPP[19] + 0.0001 * (tempPP[13] - tempPP[19]);
    TPP9[1] = RETL2;
    normaltao[1] =
        tempPP[19] -
        (RETL2 + (tempPP[19] + 0.0001 * (tempPP[4] - tempPP[19]))) / 2.0;
    RETL2 = tempPP[20] + 0.0001 * (tempPP[14] - tempPP[20]);
    normaltao[2] =
        tempPP[20] -
        (RETL2 + (tempPP[20] + 0.0001 * (tempPP[5] - tempPP[20]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    RETL3 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= RETL3;
    Tv1[0] = 1.0;
    normaltao[1] /= RETL3;
    Tv1[1] = 0.0;
    normaltao[2] /= RETL3;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    L8 = dot(Tv1, normaltao);
    Tv1[0] -= L8 * normaltao[0];
    Tv1[1] -= L8 * normaltao[1];
    Tv1[2] = 0.0 - L8 * normaltao[2];
    /*  投影法向量到平面内 */
    RETL3 = b_norm(Tv1);
    Tv1[0] /= RETL3;
    Tv1[1] /= RETL3;
    Tv1[2] /= RETL3;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    RETL3 = TPP9[0];
    RETL1 = TPP9[1];
    L1 = Tv1[0];
    L2 = Tv1[1];
    L6 = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      L8 = (b_rand() - 0.5) * 2.0;
      L7 = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (RETL3 + L8 * L1) + L7 * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (RETL1 + L8 * L2) + L7 * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (RETL2 + L8 * L6) + L7 * Tv_idx_2;
    }
    i = Points6->size[0] * Points6->size[1];
    Points6->size[0] = 3;
    Points6->size[1] = 20;
    emxEnsureCapacity_real_T(Points6, i);
    Points6_data = Points6->data;
    for (i = 0; i < 60; i++) {
      Points6_data[i] = Tpoints[i];
    }
  }
  if (Points8->size[1] == 0) {
    RETL2 = tempPP[3] + 0.0001 * (tempPP[0] - tempPP[3]);
    TPP9[0] = RETL2;
    normaltao[0] =
        tempPP[3] -
        (RETL2 + (tempPP[3] + 0.0001 * (tempPP[18] - tempPP[3]))) / 2.0;
    RETL2 = tempPP[4] + 0.0001 * (tempPP[1] - tempPP[4]);
    TPP9[1] = RETL2;
    normaltao[1] =
        tempPP[4] -
        (RETL2 + (tempPP[4] + 0.0001 * (tempPP[19] - tempPP[4]))) / 2.0;
    RETL2 = tempPP[5] + 0.0001 * (tempPP[2] - tempPP[5]);
    normaltao[2] =
        tempPP[5] -
        (RETL2 + (tempPP[5] + 0.0001 * (tempPP[20] - tempPP[5]))) / 2.0;
    /*  已知数据：平面法向量和平面上一点 */
    RETL3 = b_norm(normaltao);
    /*  归一化法向量 */
    /*  平面上一点 */
    /*  生成平面上的随机点参数 */
    /*  要生成的点数 */
    /*  点的分布范围 */
    /*  找到平面内的两个非平行向量作为基向量 */
    /*  随意选择一个非平行于法向量的向量 */
    normaltao[0] /= RETL3;
    Tv1[0] = 1.0;
    normaltao[1] /= RETL3;
    Tv1[1] = 0.0;
    normaltao[2] /= RETL3;
    Tv1[2] = 0.0;
    if (fabs(dot(normaltao, dv1)) > 1.0E-6) {
      /*  如果v1与法向量平行，则换一个向量 */
      Tv1[0] = 0.0;
      Tv1[1] = 1.0;
      Tv1[2] = 0.0;
    }
    /*  使用Gram-Schmidt正交化法找到两个平面内的正交向量 */
    L8 = dot(Tv1, normaltao);
    Tv1[0] -= L8 * normaltao[0];
    Tv1[1] -= L8 * normaltao[1];
    Tv1[2] = 0.0 - L8 * normaltao[2];
    /*  投影法向量到平面内 */
    RETL3 = b_norm(Tv1);
    Tv1[0] /= RETL3;
    Tv1[1] /= RETL3;
    Tv1[2] /= RETL3;
    /*  单位化 */
    Tv_idx_0 = normaltao[1] * Tv1[2] - Tv1[1] * normaltao[2];
    Tv_idx_1 = Tv1[0] * normaltao[2] - normaltao[0] * Tv1[2];
    Tv_idx_2 = normaltao[0] * Tv1[1] - Tv1[0] * normaltao[1];
    /*  第二个正交向量 */
    /*  生成平面上的点 */
    RETL3 = TPP9[0];
    RETL1 = TPP9[1];
    L1 = Tv1[0];
    L2 = Tv1[1];
    L6 = Tv1[2];
    for (b_i = 0; b_i < 20; b_i++) {
      /*  在范围内随机生成系数 */
      L8 = (b_rand() - 0.5) * 2.0;
      L7 = (b_rand() - 0.5) * 2.0;
      /*  计算平面上的点：p = p0 + a*u + b*v */
      Tpoints[3 * b_i] = (RETL3 + L8 * L1) + L7 * Tv_idx_0;
      Tpoints[3 * b_i + 1] = (RETL1 + L8 * L2) + L7 * Tv_idx_1;
      Tpoints[3 * b_i + 2] = (RETL2 + L8 * L6) + L7 * Tv_idx_2;
    }
    i = Points8->size[0] * Points8->size[1];
    Points8->size[0] = 3;
    Points8->size[1] = 20;
    emxEnsureCapacity_real_T(Points8, i);
    Points8_data = Points8->data;
    for (i = 0; i < 60; i++) {
      Points8_data[i] = Tpoints[i];
    }
  }
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
  Points2_data = PlaneParaOut->data;
  for (i = 0; i < 32; i++) {
    Points2_data[i] = 0.0;
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
  Isempty[2] = -1.0;
  emxInit_real_T(&pointss, 2);
  emxInit_real_T(&distances, 2);
  emxInit_real_T(&inlierPoints, 2);
  emxInit_real_T(&a__4, 2);
  emxInit_int32_T(&r24);
  emxInit_real_T(&b_pointss, 2);
  emxInit_real_T(&c_pointss, 1);
  emxInit_real_T(&d_pointss, 2);
  emxInit_boolean_T(&b_distances);
  emxInit_real_T(&b_inlierPoints, 1);
  for (b_i = 0; b_i < 8; b_i++) {
    /*  平面拟合 */
    loop_ub = PointAll[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = PointAll[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points4_data[i1 + pointss->size[0] * i] =
            PointAll[b_i].f1->data[i + 3 * i1];
      }
    }
    /*  最优内点距离 */
    /*  随机选择三个点 */
    /*  samplePoints = pointss(sampleIdx, :); */
    /*  计算平面模型 */
    /*  A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)]; */
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    Points8_data = b_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i] = Points4_data[i];
      Points8_data[i + b_pointss->size[0]] = Points4_data[i + pointss->size[0]];
    }
    nx = pointss->size[0];
    if (nx < 3) {
      nx = 3;
    }
    if (pointss->size[0] == 0) {
      loop_ub = 0;
    } else {
      loop_ub = nx;
    }
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i + b_pointss->size[0] * 2] = 1.0;
    }
    i = c_pointss->size[0];
    c_pointss->size[0] = pointss->size[0];
    emxEnsureCapacity_real_T(c_pointss, i);
    Points8_data = c_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < loop_ub; i++) {
      Points8_data[i] = Points4_data[i + pointss->size[0] * 2];
    }
    mldivide(b_pointss, c_pointss, TPP10);
    if (pointss->size[0] != 0) {
      nx = pointss->size[0];
    } else {
      nx = 0;
    }
    empty_non_axis_sizes = (nx == 0);
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
    Tv_idx_0 = sqrt((TPP10[0] * TPP10[0] + TPP10[1] * TPP10[1]) + 1.0);
    Isempty[0] = TPP10[0];
    Isempty[1] = TPP10[1];
    Isempty[3] = TPP10[2];
    i = d_pointss->size[0] * d_pointss->size[1];
    d_pointss->size[0] = nx;
    d_pointss->size[1] = i2 + sizes_idx_1;
    emxEnsureCapacity_real_T(d_pointss, i);
    Points8_data = d_pointss->data;
    loop_ub = i2;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        Points8_data[i1 + d_pointss->size[0] * i] = Points4_data[i1 + nx * i];
      }
    }
    for (i = 0; i < sizes_idx_1; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        Points8_data[i1 + d_pointss->size[0] * i2] = 1.0;
      }
    }
    b_mtimes(Isempty, d_pointss, Cnum);
    Points8_data = Cnum->data;
    nx = Cnum->size[1];
    i = distances->size[0] * distances->size[1];
    distances->size[0] = 1;
    distances->size[1] = Cnum->size[1];
    emxEnsureCapacity_real_T(distances, i);
    Points6_data = distances->data;
    for (sizes_idx_1 = 0; sizes_idx_1 < nx; sizes_idx_1++) {
      Points6_data[sizes_idx_1] = fabs(Points8_data[sizes_idx_1]);
    }
    i = distances->size[0] * distances->size[1];
    distances->size[0] = 1;
    emxEnsureCapacity_real_T(distances, i);
    Points6_data = distances->data;
    loop_ub = distances->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      Points6_data[i] /= Tv_idx_0;
    }
    /*  确定内点 */
    /*  更新最优平面模型 */
    if (b_combineVectorElements(distances) / (double)distances->size[1] <
        99999.0) {
      i = b_distances->size[0] * b_distances->size[1];
      b_distances->size[0] = 1;
      b_distances->size[1] = distances->size[1];
      emxEnsureCapacity_boolean_T(b_distances, i);
      distances_data = b_distances->data;
      loop_ub = distances->size[1];
      for (i = 0; i < loop_ub; i++) {
        distances_data[i] = (Points6_data[i] < distanceThreshold);
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
      i = distancesFianal1[b_i].f1->size[0] * distancesFianal1[b_i].f1->size[1];
      distancesFianal1[b_i].f1->size[0] = 1;
      distancesFianal1[b_i].f1->size[1] = distances->size[1];
      emxEnsureCapacity_real_T(distancesFianal1[b_i].f1, i);
      loop_ub = distances->size[1];
      for (i = 0; i < loop_ub; i++) {
        distancesFianal1[b_i].f1->data[i] = Points6_data[i];
      }
    }
    /*  重新计算最终平面模型，使用所有内点 */
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = inlierPoints->size[0] * inlierPoints->size[1];
    inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
    inlierPoints->size[1] = 3;
    emxEnsureCapacity_real_T(inlierPoints, i);
    Points6_data = inlierPoints->data;
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points6_data[i1 + inlierPoints->size[0] * i] =
            Points4_data[((int)inlierIdxFinal[b_i].f1->data[i1] +
                          pointss->size[0] * i) -
                         1];
      }
    }
    loop_ub = inlierIdxFinal[b_i].f1->size[1];
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i] = Points6_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i + pointss->size[0]] =
          Points6_data[i + inlierPoints->size[0]];
    }
    for (i = 0; i < loop_ub; i++) {
      Points4_data[i + pointss->size[0] * 2] =
          Points6_data[i + inlierPoints->size[0] * 2];
    }
    /*  Fit a plane through the points */
    mean(pointss, TPP10);
    i = b_pointss->size[0] * b_pointss->size[1];
    b_pointss->size[0] = pointss->size[0];
    b_pointss->size[1] = 3;
    emxEnsureCapacity_real_T(b_pointss, i);
    Points8_data = b_pointss->data;
    loop_ub = pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points8_data[i1 + b_pointss->size[0] * i] =
            Points4_data[i1 + pointss->size[0] * i] - TPP10[i];
      }
    }
    i = pointss->size[0] * pointss->size[1];
    pointss->size[0] = b_pointss->size[0];
    pointss->size[1] = 3;
    emxEnsureCapacity_real_T(pointss, i);
    Points4_data = pointss->data;
    loop_ub = b_pointss->size[0];
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        Points4_data[i1 + pointss->size[0] * i] =
            Points8_data[i1 + b_pointss->size[0] * i];
      }
    }
    c_svd(pointss, a__4, b_pointss, A);
    /*  Normal vector of the plane */
    /*  Calculate angle between normal vector and z-axis */
    /*  Check if angle is below threshold */
    if (fabs(90.0 - 57.295779513082323 * acos(fabs(dot(&A[6], dv2)))) < 2.0) {
      nx = 0;
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_pointss->size[0];
      c_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_pointss, i);
      Points8_data = c_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_inlierPoints->size[0];
      b_inlierPoints->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(b_inlierPoints, i);
      Points8_data = b_inlierPoints->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i + inlierPoints->size[0]];
      }
      polyfit(c_pointss, b_inlierPoints, bb);
      /*  拟合，其实是线性回归，但可以用来拟合平面 */
      L8 = bb[0];
      Tv_idx_0 = -1.0;
      Tv_idx_1 = bb[1];
    } else {
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = b_pointss->size[0] * b_pointss->size[1];
      b_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      b_pointss->size[1] = 3;
      emxEnsureCapacity_real_T(b_pointss, i);
      Points8_data = b_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i];
      }
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i + b_pointss->size[0]] =
            Points6_data[i + inlierPoints->size[0]];
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i + b_pointss->size[0] * 2] = 1.0;
      }
      loop_ub = inlierIdxFinal[b_i].f1->size[1];
      i = c_pointss->size[0];
      c_pointss->size[0] = inlierIdxFinal[b_i].f1->size[1];
      emxEnsureCapacity_real_T(c_pointss, i);
      Points8_data = c_pointss->data;
      for (i = 0; i < loop_ub; i++) {
        Points8_data[i] = Points6_data[i + inlierPoints->size[0] * 2];
      }
      mldivide(b_pointss, c_pointss, TPP10);
      L8 = TPP10[0];
      Tv_idx_0 = TPP10[1];
      Tv_idx_1 = TPP10[2];
      nx = -1;
    }
    Points2_data[4 * b_i] = L8;
    Points2_data[4 * b_i + 1] = Tv_idx_0;
    Points2_data[4 * b_i + 2] = nx;
    Points2_data[4 * b_i + 3] = Tv_idx_1;
  }
  emxFree_real_T(&b_inlierPoints);
  emxFree_boolean_T(&b_distances);
  emxFree_real_T(&d_pointss);
  emxFree_real_T(&c_pointss);
  emxFree_real_T(&b_pointss);
  emxFree_int32_T(&r24);
  emxFreeMatrix_cell_wrap_4(PointAll);
  emxFree_real_T(&a__4);
  emxFree_real_T(&inlierPoints);
  emxFree_real_T(&pointss);
  /* %%%%%%%% 测试 %%%%%%%%%%%% */
  Points2_data[8] = 0.0;
  Points2_data[9] = 0.0;
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = Points3->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points8_data = Cnum->data;
  loop_ub = Points3->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = Points3_data[3 * i + 2];
  }
  Points2_data[11] = b_combineVectorElements(Cnum) / (double)Points3->size[1];
  Points2_data[24] = 0.0;
  Points2_data[25] = 0.0;
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = Points7->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points8_data = Cnum->data;
  loop_ub = Points7->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = Points7_data[3 * i + 2];
  }
  Points2_data[27] = b_combineVectorElements(Cnum) / (double)Points7->size[1];
  RETL2 = (Points2_data[0] + Points2_data[16]) / 2.0;
  Points2_data[0] = RETL2;
  Points2_data[16] = RETL2;
  RETL2 = (Points2_data[1] + Points2_data[17]) / 2.0;
  Points2_data[1] = RETL2;
  Points2_data[17] = RETL2;
  /* %%%%%%%% 测试 %%%%%%%%%%%% */
  /*  %%%%%%%%% 约束 %%%%%%%%%%%% */
  /*   */
  /*  % 左、右面竖直 */
  /*  PlaneParaOut(3,1) = 0; */
  /*  PlaneParaOut(3,5) = 0; */
  /*  % 左右面平行 */
  /*  PlaneParaOut(1:2,1) = (PlaneParaOut(1:2,1)+PlaneParaOut(1:2,5))./2 ; */
  /*  PlaneParaOut(1:2,5) = PlaneParaOut(1:2,1) ; */
  /*   */
  /*  %%%%%%%% 约束只能前后倾斜  %%%%%%%%% */
  /*      t1 = PlaneParaOut(1,5); */
  /*      t2 = PlaneParaOut(2,5); */
  /*   */
  /*      % 输入: */
  /*      % points: n×3 矩阵，每行 (xi, yi, zi) */
  /*      % t1, t2: 约束参数 */
  /*   */
  /*      X = Points3(1,:)';  % 提取 x 坐标 */
  /*      Y = Points3(2,:)';  % 提取 y 坐标 */
  /*      Z = Points3(3,:)';  % 提取 z 坐标 */
  /*   */
  /*      % 构造设计矩阵 A 和观测向量 b */
  /*      A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z */
  /*      b = Z; % 目标值 */
  /*   */
  /*      % 约束矩阵 */
  /*      C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0 */
  /*   */
  /*      % 使用约束最小二乘求解 */
  /*      n = size(A, 2); */
  /*      M = [A'*A, C'; C, 0];  % 扩展矩阵 */
  /*      rhs = [A'*b; 0];  % 右端项 */
  /*      solution = M \ rhs; % 求解 */
  /*   */
  /*      % 提取参数 a, b, d */
  /*      a = solution(1); */
  /*      b = solution(2); */
  /*      d = solution(3); */
  /*   */
  /*      % 输出参数 */
  /*      params = [a, b, d]; */
  /*      PlaneParaOut(:,3) = [a; b;-1 ;d]; */
  /*   */
  /*    */
  /*      % 输入: */
  /*      % points: n×3 矩阵，每行 (xi, yi, zi) */
  /*      % t1, t2: 约束参数 */
  /*   */
  /*      X = Points7(1,:)';  % 提取 x 坐标 */
  /*      Y = Points7(2,:)';  % 提取 y 坐标 */
  /*      Z = Points7(3,:)';  % 提取 z 坐标 */
  /*   */
  /*      % 构造设计矩阵 A 和观测向量 b */
  /*      A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z */
  /*      b = Z; % 目标值 */
  /*   */
  /*      % 约束矩阵 */
  /*      C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0 */
  /*   */
  /*      % 使用约束最小二乘求解 */
  /*      n = size(A, 2); */
  /*      M = [A'*A, C'; C, 0];  % 扩展矩阵 */
  /*      rhs = [A'*b; 0];  % 右端项 */
  /*      solution = M \ rhs; % 求解 */
  /*   */
  /*      % 提取参数 a, b, d */
  /*      a = solution(1); */
  /*      b = solution(2); */
  /*      d = solution(3); */
  /*   */
  /*      % 输出参数 */
  /*      params = [a, b, d]; */
  /*      PlaneParaOut(:,7) = [a; b;-1 ;d]; */
  /*   */
  /*  PlaneParaOut(1:2,3) = (PlaneParaOut(1:2,3)+PlaneParaOut(1:2,7))./2 ; */
  /*  PlaneParaOut(1:2,7) = PlaneParaOut(1:2,3) ; */
  /*  %%%%%%%%%%% 约束只能前后倾斜  %%%%%%%%%%%% */
  i = tt1->size[0] * tt1->size[1];
  tt1->size[0] = 1;
  tt1->size[1] = distancesFianal1[0].f1->size[1];
  emxEnsureCapacity_real_T(tt1, i);
  Points8_data = tt1->data;
  loop_ub = distancesFianal1[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[0].f1->data[i];
  }
  i = tt2->size[0] * tt2->size[1];
  tt2->size[0] = 1;
  tt2->size[1] = distancesFianal1[1].f1->size[1];
  emxEnsureCapacity_real_T(tt2, i);
  Points8_data = tt2->data;
  loop_ub = distancesFianal1[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[1].f1->data[i];
  }
  i = tt3->size[0] * tt3->size[1];
  tt3->size[0] = 1;
  tt3->size[1] = distancesFianal1[2].f1->size[1];
  emxEnsureCapacity_real_T(tt3, i);
  Points8_data = tt3->data;
  loop_ub = distancesFianal1[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[2].f1->data[i];
  }
  i = tt4->size[0] * tt4->size[1];
  tt4->size[0] = 1;
  tt4->size[1] = distancesFianal1[3].f1->size[1];
  emxEnsureCapacity_real_T(tt4, i);
  Points8_data = tt4->data;
  loop_ub = distancesFianal1[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[3].f1->data[i];
  }
  i = tt5->size[0] * tt5->size[1];
  tt5->size[0] = 1;
  tt5->size[1] = distancesFianal1[4].f1->size[1];
  emxEnsureCapacity_real_T(tt5, i);
  Points8_data = tt5->data;
  loop_ub = distancesFianal1[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[4].f1->data[i];
  }
  i = tt6->size[0] * tt6->size[1];
  tt6->size[0] = 1;
  tt6->size[1] = distancesFianal1[5].f1->size[1];
  emxEnsureCapacity_real_T(tt6, i);
  Points8_data = tt6->data;
  loop_ub = distancesFianal1[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[5].f1->data[i];
  }
  i = tt7->size[0] * tt7->size[1];
  tt7->size[0] = 1;
  tt7->size[1] = distancesFianal1[6].f1->size[1];
  emxEnsureCapacity_real_T(tt7, i);
  Points8_data = tt7->data;
  loop_ub = distancesFianal1[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[6].f1->data[i];
  }
  i = tt8->size[0] * tt8->size[1];
  tt8->size[0] = 1;
  tt8->size[1] = distancesFianal1[7].f1->size[1];
  emxEnsureCapacity_real_T(tt8, i);
  Points8_data = tt8->data;
  loop_ub = distancesFianal1[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] = distancesFianal1[7].f1->data[i];
  }
  i = Cnum->size[0] * Cnum->size[1];
  Cnum->size[0] = 1;
  Cnum->size[1] = inlierIdxFinal[0].f1->size[1];
  emxEnsureCapacity_real_T(Cnum, i);
  Points8_data = Cnum->data;
  loop_ub = inlierIdxFinal[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[0].f1->data[(int)inlierIdxFinal[0].f1->data[i] - 1];
  }
  i = distances->size[0] * distances->size[1];
  distances->size[0] = 1;
  distances->size[1] = inlierIdxFinal[1].f1->size[1];
  emxEnsureCapacity_real_T(distances, i);
  Points6_data = distances->data;
  loop_ub = inlierIdxFinal[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points6_data[i] =
        distancesFianal1[1].f1->data[(int)inlierIdxFinal[1].f1->data[i] - 1];
  }
  emxInit_real_T(&b_distancesFianal1, 2);
  i = b_distancesFianal1->size[0] * b_distancesFianal1->size[1];
  b_distancesFianal1->size[0] = 1;
  b_distancesFianal1->size[1] = inlierIdxFinal[2].f1->size[1];
  emxEnsureCapacity_real_T(b_distancesFianal1, i);
  Points8_data = b_distancesFianal1->data;
  loop_ub = inlierIdxFinal[2].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[2].f1->data[(int)inlierIdxFinal[2].f1->data[i] - 1];
  }
  emxInit_real_T(&c_distancesFianal1, 2);
  i = c_distancesFianal1->size[0] * c_distancesFianal1->size[1];
  c_distancesFianal1->size[0] = 1;
  c_distancesFianal1->size[1] = inlierIdxFinal[3].f1->size[1];
  emxEnsureCapacity_real_T(c_distancesFianal1, i);
  Points8_data = c_distancesFianal1->data;
  loop_ub = inlierIdxFinal[3].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[3].f1->data[(int)inlierIdxFinal[3].f1->data[i] - 1];
  }
  emxInit_real_T(&d_distancesFianal1, 2);
  i = d_distancesFianal1->size[0] * d_distancesFianal1->size[1];
  d_distancesFianal1->size[0] = 1;
  d_distancesFianal1->size[1] = inlierIdxFinal[4].f1->size[1];
  emxEnsureCapacity_real_T(d_distancesFianal1, i);
  Points8_data = d_distancesFianal1->data;
  loop_ub = inlierIdxFinal[4].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[4].f1->data[(int)inlierIdxFinal[4].f1->data[i] - 1];
  }
  emxInit_real_T(&e_distancesFianal1, 2);
  i = e_distancesFianal1->size[0] * e_distancesFianal1->size[1];
  e_distancesFianal1->size[0] = 1;
  e_distancesFianal1->size[1] = inlierIdxFinal[5].f1->size[1];
  emxEnsureCapacity_real_T(e_distancesFianal1, i);
  Points8_data = e_distancesFianal1->data;
  loop_ub = inlierIdxFinal[5].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[5].f1->data[(int)inlierIdxFinal[5].f1->data[i] - 1];
  }
  emxInit_real_T(&f_distancesFianal1, 2);
  i = f_distancesFianal1->size[0] * f_distancesFianal1->size[1];
  f_distancesFianal1->size[0] = 1;
  f_distancesFianal1->size[1] = inlierIdxFinal[6].f1->size[1];
  emxEnsureCapacity_real_T(f_distancesFianal1, i);
  Points8_data = f_distancesFianal1->data;
  loop_ub = inlierIdxFinal[6].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[6].f1->data[(int)inlierIdxFinal[6].f1->data[i] - 1];
  }
  emxInit_real_T(&g_distancesFianal1, 2);
  i = g_distancesFianal1->size[0] * g_distancesFianal1->size[1];
  g_distancesFianal1->size[0] = 1;
  g_distancesFianal1->size[1] = inlierIdxFinal[7].f1->size[1];
  emxEnsureCapacity_real_T(g_distancesFianal1, i);
  Points8_data = g_distancesFianal1->data;
  loop_ub = inlierIdxFinal[7].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Points8_data[i] =
        distancesFianal1[7].f1->data[(int)inlierIdxFinal[7].f1->data[i] - 1];
  }
  emxFreeMatrix_cell_wrap_1(distancesFianal1);
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
  emxInit_real_T(&b_PlaneParaOut, 2);
  i = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 8;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, i);
  Points8_data = b_PlaneParaOut->data;
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 8; i1++) {
      Points8_data[i1 + b_PlaneParaOut->size[0] * i] = Points2_data[i + 4 * i1];
    }
  }
  for (i = 0; i < 32; i++) {
    PlaneParaOutP_data[i] = Points8_data[i];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&tempPP[0], 0, 24U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (b_i = 0; b_i < 8; b_i++) {
    if (b_i + 1 < 8) {
      L2 = PlaneParaOutP_data[b_i + 17];
      Tv_idx_0 = PlaneParaOutP_data[b_i + 9];
      Tv_idx_1 = PlaneParaOutP_data[b_i + 16];
      Tv_idx_2 = PlaneParaOutP_data[b_i + 8];
      tempPP[b_i] = Tv_idx_2 * L2 - Tv_idx_0 * Tv_idx_1;
      L1 = PlaneParaOutP_data[b_i + 1];
      tempPP[b_i + 8] = L1 * Tv_idx_1 - PlaneParaOutP_data[b_i] * L2;
      tempPP[b_i + 16] = PlaneParaOutP_data[b_i] * Tv_idx_0 - L1 * Tv_idx_2;
    } else {
      tempPP[7] = PlaneParaOutP_data[15] * PlaneParaOutP_data[16] -
                  PlaneParaOutP_data[8] * PlaneParaOutP_data[23];
      tempPP[15] = PlaneParaOutP_data[0] * PlaneParaOutP_data[23] -
                   PlaneParaOutP_data[7] * PlaneParaOutP_data[16];
      tempPP[23] = PlaneParaOutP_data[7] * PlaneParaOutP_data[8] -
                   PlaneParaOutP_data[0] * PlaneParaOutP_data[15];
      /*  最后一个与第一个相邻 */
    }
    TPP9[0] = tempPP[b_i];
    TPP9[1] = tempPP[b_i + 8];
    TPP9[2] = tempPP[b_i + 16];
    RETL2 = b_norm(TPP9);
    tempPP[b_i] /= RETL2;
    tempPP[b_i + 8] /= RETL2;
    tempPP[b_i + 16] /= RETL2;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  TPP10[0] = tempPP[0];
  TPP10[1] = tempPP[8];
  TPP10[2] = tempPP[16];
  /*  选择第一个向量作为参考 */
  for (b_i = 0; b_i < 7; b_i++) {
    L2 = tempPP[b_i + 1];
    TPP9[0] = L2;
    RETL2 = tempPP[b_i + 9];
    TPP9[1] = RETL2;
    RETL3 = tempPP[b_i + 17];
    TPP9[2] = RETL3;
    if (dot(TPP10, TPP9) < 0.0) {
      /*  如果方向相反 */
      tempPP[b_i + 1] = -L2;
      RETL2 = -RETL2;
      tempPP[b_i + 9] = RETL2;
      RETL3 = -RETL3;
      tempPP[b_i + 17] = RETL3;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  b_mean(tempPP, TPP9);
  /*  计算顶面方程的 d 值 */
  Tv_idx_0 = -dot(TPP9, P_bound1);
  /*  计算底面方程的 d 值 */
  Tv_idx_1 = -dot(TPP9, P_bound2);
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 48U * sizeof(double));
  /*  计算顶面和底面的8个顶点 */
  RETL2 = TPP9[0];
  RETL3 = TPP9[1];
  RETL1 = TPP9[2];
  A[2] = RETL2;
  A[5] = RETL3;
  A[8] = RETL1;
  for (b_i = 0; b_i < 8; b_i++) {
    /*  顶面顶点 */
    if (b_i + 1 < 8) {
      Isempty[0] = PlaneParaOutP_data[b_i];
      PlaneParaOut2[0] = PlaneParaOutP_data[b_i + 1];
      Isempty[1] = PlaneParaOutP_data[b_i + 8];
      PlaneParaOut2[1] = PlaneParaOutP_data[b_i + 9];
      Isempty[2] = PlaneParaOutP_data[b_i + 16];
      PlaneParaOut2[2] = PlaneParaOutP_data[b_i + 17];
      Isempty[3] = PlaneParaOutP_data[b_i + 24];
      PlaneParaOut2[3] = PlaneParaOutP_data[b_i + 25];
    } else {
      Isempty[0] = PlaneParaOutP_data[7];
      PlaneParaOut2[0] = PlaneParaOutP_data[0];
      Isempty[1] = PlaneParaOutP_data[15];
      PlaneParaOut2[1] = PlaneParaOutP_data[8];
      Isempty[2] = PlaneParaOutP_data[23];
      PlaneParaOut2[2] = PlaneParaOutP_data[16];
      Isempty[3] = PlaneParaOutP_data[31];
      PlaneParaOut2[3] = PlaneParaOutP_data[24];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = Isempty[0];
    A[1] = PlaneParaOut2[0];
    A[3] = Isempty[1];
    A[4] = PlaneParaOut2[1];
    A[6] = Isempty[2];
    A[7] = PlaneParaOut2[2];
    normaltao[0] = -Isempty[3];
    normaltao[1] = -PlaneParaOut2[3];
    normaltao[2] = -Tv_idx_0;
    b_mldivide(A, normaltao, TPP10);
    PP[b_i] = TPP10[0];
    PP[b_i + 16] = TPP10[1];
    PP[b_i + 32] = TPP10[2];
    /*  求底面和两个相邻侧面的交线 */
    normaltao[0] = -Isempty[3];
    normaltao[1] = -PlaneParaOut2[3];
    normaltao[2] = -Tv_idx_1;
    b_mldivide(A, normaltao, TPP10);
    PP[b_i + 8] = TPP10[0];
    PP[b_i + 24] = TPP10[1];
    PP[b_i + 40] = TPP10[2];
  }
  for (i = 0; i < 16; i++) {
    b_PP[3 * i] = PP[i];
    b_PP[3 * i + 1] = PP[i + 16];
    b_PP[3 * i + 2] = PP[i + 32];
  }
  i = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 48;
  emxEnsureCapacity_real_T(TrianglePoints, i);
  Points8_data = TrianglePoints->data;
  for (i = 0; i < 48; i++) {
    nx = 3 * iv[i];
    Points8_data[3 * i] = b_PP[nx];
    Points8_data[3 * i + 1] = b_PP[nx + 1];
    Points8_data[3 * i + 2] = b_PP[nx + 2];
  }
  /*  倒角计算 */
  for (i = 0; i < 8; i++) {
    nx = 3 * b_iv[i];
    tempPP[3 * i] = TrianglePoints4_data[nx];
    tempPP[3 * i + 1] = TrianglePoints4_data[nx + 1];
    tempPP[3 * i + 2] = TrianglePoints4_data[nx + 2];
  }
  emxFree_real_T(&TrianglePoints4);
  normaltao[0] = tempPP[0] - b_PP[0];
  normaltao[1] = tempPP[1] - b_PP[1];
  normaltao[2] = tempPP[2] - b_PP[2];
  L1 = b_norm(normaltao);
  normaltao[0] = tempPP[0] - b_PP[3];
  normaltao[1] = tempPP[1] - b_PP[4];
  normaltao[2] = tempPP[2] - b_PP[5];
  L2 = b_norm(normaltao);
  normaltao[0] = tempPP[12] - b_PP[6];
  normaltao[1] = tempPP[13] - b_PP[7];
  normaltao[2] = tempPP[14] - b_PP[8];
  Tv_idx_0 = b_norm(normaltao);
  normaltao[0] = tempPP[12] - b_PP[9];
  normaltao[1] = tempPP[13] - b_PP[10];
  normaltao[2] = tempPP[14] - b_PP[11];
  Tv_idx_1 = b_norm(normaltao);
  normaltao[0] = tempPP[18] - b_PP[12];
  normaltao[1] = tempPP[19] - b_PP[13];
  normaltao[2] = tempPP[20] - b_PP[14];
  Tv_idx_2 = b_norm(normaltao);
  normaltao[0] = tempPP[18] - b_PP[15];
  normaltao[1] = tempPP[19] - b_PP[16];
  normaltao[2] = tempPP[20] - b_PP[17];
  L6 = b_norm(normaltao);
  normaltao[0] = tempPP[3] - b_PP[18];
  normaltao[1] = tempPP[4] - b_PP[19];
  normaltao[2] = tempPP[5] - b_PP[20];
  L7 = b_norm(normaltao);
  normaltao[0] = tempPP[3] - b_PP[21];
  normaltao[1] = tempPP[4] - b_PP[22];
  normaltao[2] = tempPP[5] - b_PP[23];
  L8 = b_norm(normaltao);
  normaltao[0] = tempPP[0] - tempPP[3];
  normaltao[1] = tempPP[1] - tempPP[4];
  normaltao[2] = tempPP[2] - tempPP[5];
  RETL1 = b_norm(normaltao);
  normaltao[0] = tempPP[0] - tempPP[12];
  normaltao[1] = tempPP[1] - tempPP[13];
  normaltao[2] = tempPP[2] - tempPP[14];
  RETL2 = b_norm(normaltao);
  normaltao[0] = tempPP[12] - tempPP[18];
  normaltao[1] = tempPP[13] - tempPP[19];
  normaltao[2] = tempPP[14] - tempPP[20];
  RETL3 = b_norm(normaltao);
  normaltao[0] = tempPP[18] - tempPP[3];
  normaltao[1] = tempPP[19] - tempPP[4];
  normaltao[2] = tempPP[20] - tempPP[5];
  RETL4 = b_norm(normaltao);
  if (L1 < 0.05 * RETL1) {
    L1 = 0.0;
  }
  if (L2 < 0.05 * RETL2) {
    L2 = 0.0;
  }
  if (Tv_idx_0 < 0.05 * RETL2) {
    Tv_idx_0 = 0.0;
  }
  if (Tv_idx_1 < 0.05 * RETL3) {
    Tv_idx_1 = 0.0;
  }
  if (Tv_idx_2 < 0.05 * RETL3) {
    Tv_idx_2 = 0.0;
  }
  if (L6 < 0.05 * RETL4) {
    L6 = 0.0;
  }
  if (L7 < 0.05 * RETL4) {
    L7 = 0.0;
  }
  if (L8 < 0.05 * RETL1) {
    L8 = 0.0;
  }
  LenDaoJiao[0] = L1;
  LenDaoJiao[1] = L2;
  LenDaoJiao[2] = Tv_idx_0;
  LenDaoJiao[3] = Tv_idx_1;
  LenDaoJiao[4] = Tv_idx_2;
  LenDaoJiao[5] = L6;
  LenDaoJiao[6] = L7;
  LenDaoJiao[7] = L8;
}

/*
 * File trailer for planefit8.c
 *
 * [EOF]
 */
