/*
 * File: Calculate_rectangle_from_vertex8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Sep-2024 21:13:02
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex8.h"
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "dot.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "norm.h"
#include "planefit4.h"
#include "planefit8.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Definitions */
/*
 * %%%%%%%%%%%%%%%%%%%%%  计算八面参数  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : const emxArray_real_T *side_faces_transformed1
 *                const emxArray_real_T *side_faces_transformed2
 *                const emxArray_real_T *side_faces_transformed3
 *                const emxArray_real_T *side_faces_transformed4
 *                const emxArray_real_T *side_faces_transformed5
 *                const emxArray_real_T *side_faces_transformed6
 *                const emxArray_real_T *side_faces_transformed7
 *                const emxArray_real_T *side_faces_transformed8
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                const double PAB[3]
 *                double phi
 *                double shenglunum
 *                const emxArray_real_T *Ti
 *                const emxArray_real_T *a
 *                double distanceThreshold
 *                emxArray_real_T *PointTable_A_off8
 *                emxArray_real_T *PointTable_B_off8
 *                emxArray_real_T *XieMianPianYi
 * Return Type  : void
 */
void Calculate_rectangle_from_vertex8(
    const emxArray_real_T *side_faces_transformed1,
    const emxArray_real_T *side_faces_transformed2,
    const emxArray_real_T *side_faces_transformed3,
    const emxArray_real_T *side_faces_transformed4,
    const emxArray_real_T *side_faces_transformed5,
    const emxArray_real_T *side_faces_transformed6,
    const emxArray_real_T *side_faces_transformed7,
    const emxArray_real_T *side_faces_transformed8, const double P_bound1[3],
    const double P_bound2[3], const double PAB[3], double phi,
    double shenglunum, const emxArray_real_T *Ti, const emxArray_real_T *a,
    double distanceThreshold, emxArray_real_T *PointTable_A_off8,
    emxArray_real_T *PointTable_B_off8, emxArray_real_T *XieMianPianYi)
{
  static const signed char b_iv[16] = {6, 7, 13, 19, 25, 31, 37, 43,
                                       2, 8, 17, 23, 29, 35, 41, 47};
  emxArray_real_T *PlaneParaOut8;
  emxArray_real_T *PointTable_A_off4;
  emxArray_real_T *PointTable_B_off4;
  emxArray_real_T *Ti2;
  emxArray_real_T *TrianglePoints8;
  emxArray_real_T *XMFlag;
  emxArray_real_T *a__3;
  emxArray_real_T *toff;
  double PP16[48];
  double a__7[24];
  double a__1[8];
  double a__4[4];
  double PabLine[3];
  double Pin2Pup[3];
  double b_PP16[3];
  double dir_vec[3];
  const double *Ti_data;
  const double *a_data;
  double TiYuZhi1;
  double TiYuZhi2;
  double TiYuZhi3;
  double ab1;
  double ab2;
  double ab3;
  double ab4;
  double b_PP16_tmp;
  double c_PP16_tmp;
  double d_PP16_tmp;
  double e_PP16_tmp;
  double temp;
  double theta1;
  double theta2;
  double theta3;
  double theta4;
  double zN1;
  double *PlaneParaOut8_data;
  double *PointTable_A_off4_data;
  double *PointTable_B_off4_data;
  double *Ti2_data;
  double *XMFlag_data;
  double *XieMianPianYi_data;
  int PP16_tmp;
  int b_loop_ub;
  int i;
  int k;
  int loop_ub;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  a_data = a->data;
  Ti_data = Ti->data;
  emxInit_real_T(&toff, 2);
  emxInit_real_T(&PlaneParaOut8, 2);
  emxInit_real_T(&TrianglePoints8, 2);
  b_planefit8(
      side_faces_transformed1, side_faces_transformed2, side_faces_transformed3,
      side_faces_transformed4, side_faces_transformed5, side_faces_transformed6,
      side_faces_transformed7, side_faces_transformed8, P_bound1, P_bound2,
      distanceThreshold, PlaneParaOut8, TrianglePoints8, a__1, toff);
  XieMianPianYi_data = TrianglePoints8->data;
  PlaneParaOut8_data = PlaneParaOut8->data;
  printf("%0.5f\n", PlaneParaOut8_data[0]);
  fflush(stdout);
  printf("%0.5f\n", PlaneParaOut8_data[12]);
  fflush(stdout);
  printf("%0.5f\n", PlaneParaOut8_data[28]);
  fflush(stdout);
  /* %%%%%%%%%%%%%%%%%%%%%  计算角度  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  ab4 = b_norm(&PlaneParaOut8_data[0]);
  theta1 = acos(dot(&PlaneParaOut8_data[0], &PlaneParaOut8_data[4]) / ab4 /
                b_norm(&PlaneParaOut8_data[4]));
  ab3 = b_norm(&PlaneParaOut8_data[16]);
  theta2 = acos(dot(&PlaneParaOut8_data[12], &PlaneParaOut8_data[16]) /
                b_norm(&PlaneParaOut8_data[12]) / ab3);
  theta3 = acos(dot(&PlaneParaOut8_data[16], &PlaneParaOut8_data[20]) / ab3 /
                b_norm(&PlaneParaOut8_data[20]));
  theta4 = acos(dot(&PlaneParaOut8_data[0], &PlaneParaOut8_data[28]) / ab4 /
                b_norm(&PlaneParaOut8_data[28]));
  printf("%0.5f\n", theta1);
  fflush(stdout);
  printf("%0.5f\n", theta3);
  fflush(stdout);
  /* %%%%%%%%%%%%%%%%%%%%%  计算阈值  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  承接16顶点 */
  for (i = 0; i < 16; i++) {
    PP16_tmp = 3 * b_iv[i];
    PP16[3 * i] = XieMianPianYi_data[PP16_tmp];
    PP16[3 * i + 1] = XieMianPianYi_data[PP16_tmp + 1];
    PP16[3 * i + 2] = XieMianPianYi_data[PP16_tmp + 2];
  }
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[3], &PP16[0], &PP16[9],
                                               &ab4, &ab3, &zN1);
  b_PP16_tmp = PP16[0] - PP16[9];
  b_PP16[0] = b_PP16_tmp;
  temp = PP16[1] - PP16[10];
  b_PP16[1] = temp;
  c_PP16_tmp = PP16[2] - PP16[11];
  b_PP16[2] = c_PP16_tmp;
  ab1 = b_norm(b_PP16) / 2.0;
  b_PP16[0] = PP16[0] - ab4;
  b_PP16[1] = PP16[1] - ab3;
  b_PP16[2] = PP16[2] - zN1;
  TiYuZhi1 = (ab1 - b_norm(b_PP16)) / ab1;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[18], &PP16[21], &PP16[12],
                                               &zN1, &ab1, &ab4);
  ab3 = PP16[21] - PP16[12];
  b_PP16[0] = ab3;
  d_PP16_tmp = PP16[22] - PP16[13];
  b_PP16[1] = d_PP16_tmp;
  e_PP16_tmp = PP16[23] - PP16[14];
  b_PP16[2] = e_PP16_tmp;
  ab2 = b_norm(b_PP16) / 2.0;
  b_PP16[0] = PP16[21] - zN1;
  b_PP16[1] = PP16[22] - ab1;
  b_PP16[2] = PP16[23] - ab4;
  TiYuZhi2 = (ab2 - b_norm(b_PP16)) / ab2;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[15], &PP16[21], &PP16[12],
                                               &zN1, &ab1, &ab4);
  b_PP16[0] = ab3;
  b_PP16[1] = d_PP16_tmp;
  b_PP16[2] = e_PP16_tmp;
  ab3 = b_norm(b_PP16) / 2.0;
  b_PP16[0] = PP16[21] - zN1;
  b_PP16[1] = PP16[22] - ab1;
  b_PP16[2] = PP16[23] - ab4;
  TiYuZhi3 = (ab3 - b_norm(b_PP16)) / ab3;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[6], &PP16[0], &PP16[9],
                                               &zN1, &ab1, &ab2);
  b_PP16[0] = b_PP16_tmp;
  b_PP16[1] = temp;
  b_PP16[2] = c_PP16_tmp;
  ab4 = b_norm(b_PP16) / 2.0;
  b_PP16[0] = PP16[0] - zN1;
  b_PP16[1] = PP16[1] - ab1;
  b_PP16[2] = PP16[2] - ab2;
  ab4 = (ab4 - b_norm(b_PP16)) / ab4;
  /* %%%%%%%%%%%%%%%%%%%%%  判断点是否在斜面上（利用阈值）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  temp = shenglunum / 2.0;
  emxInit_real_T(&XMFlag, 2);
  i = XMFlag->size[0] * XMFlag->size[1];
  XMFlag->size[0] = 1;
  loop_ub = (int)(2.0 * shenglunum);
  XMFlag->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlag, i);
  XMFlag_data = XMFlag->data;
  for (i = 0; i < loop_ub; i++) {
    XMFlag_data[i] = 0.0;
  }
  for (PP16_tmp = 0; PP16_tmp < loop_ub; PP16_tmp++) {
    ab3 = fabs(Ti_data[PP16_tmp]);
    if ((double)PP16_tmp + 1.0 <= temp) {
      XMFlag_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi3));
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      XMFlag_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi2));
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      XMFlag_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi1));
    } else {
      XMFlag_data[PP16_tmp] = !(ab3 < fabs(ab4));
    }
  }
  emxInit_real_T(&Ti2, 2);
  i = Ti2->size[0] * Ti2->size[1];
  Ti2->size[0] = 1;
  Ti2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ti2, i);
  Ti2_data = Ti2->data;
  for (i = 0; i < loop_ub; i++) {
    Ti2_data[i] = 0.0;
  }
  i = XieMianPianYi->size[0] * XieMianPianYi->size[1];
  XieMianPianYi->size[0] = 1;
  XieMianPianYi->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XieMianPianYi, i);
  XieMianPianYi_data = XieMianPianYi->data;
  for (i = 0; i < loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  /* %%%%%%%%%%%%%%%%%%%%%  对斜面上的点进行偏移（修正Ti）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (PP16_tmp = 0; PP16_tmp < loop_ub; PP16_tmp++) {
    if ((double)PP16_tmp + 1.0 <= temp) {
      if (XMFlag_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] + TiYuZhi2 * sin(theta3);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta3);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] - TiYuZhi2 * sin(theta2);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta2);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] - TiYuZhi2 * sin(theta1);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta1);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if (XMFlag_data[PP16_tmp] == 1.0) {
      /* 斜面上 */
      TiYuZhi2 = a_data[PP16_tmp];
      Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] + TiYuZhi2 * sin(theta4);
      XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta4);
    } else {
      Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
      XieMianPianYi_data[PP16_tmp] = 0.0;
    }
  }
  printf("%0.5f\n", Ti2_data[1]);
  fflush(stdout);
  printf("%0.5f\n", Ti2_data[3]);
  fflush(stdout);
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形拟合  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  emxInit_real_T(&a__3, 2);
  b_planefit4(side_faces_transformed1, side_faces_transformed3,
              side_faces_transformed5, side_faces_transformed7, P_bound1,
              P_bound2, distanceThreshold, a__3, TrianglePoints8, a__4, toff);
  emxFree_real_T(&a__3);
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形参数计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  Calculate_rectangle_from_vertex(TrianglePoints8, b_PP16, PabLine, Pin2Pup,
                                  &ab4, &b_PP16_tmp, &ab3, dir_vec, a__7);
  emxFree_real_T(&TrianglePoints8);
  /* %%%%%%%%%%%%%%%%%%%%%  矩形安装点计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  if (shenglunum < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)shenglunum;
  }
  if (shenglunum + 1.0 > 2.0 * shenglunum) {
    i = 0;
    k = 0;
  } else {
    i = (int)(shenglunum + 1.0) - 1;
    k = loop_ub;
  }
  ab3 = tan(phi);
  PP16_tmp = toff->size[0] * toff->size[1];
  toff->size[0] = 1;
  toff->size[1] = (b_loop_ub + k) - i;
  emxEnsureCapacity_real_T(toff, PP16_tmp);
  XieMianPianYi_data = toff->data;
  for (PP16_tmp = 0; PP16_tmp < b_loop_ub; PP16_tmp++) {
    XieMianPianYi_data[PP16_tmp] = -a_data[PP16_tmp] / ab3;
  }
  PP16_tmp = k - i;
  for (k = 0; k < PP16_tmp; k++) {
    XieMianPianYi_data[k + b_loop_ub] = a_data[i + k] / ab3;
  }
  emxInit_real_T(&PointTable_A_off4, 2);
  emxInit_real_T(&PointTable_B_off4, 2);
  Calculat_JuXing_A_and_B_Points_after_Offest(
      dir_vec, Pin2Pup, b_PP16, ab4, b_PP16_tmp, PAB, phi, shenglunum, Ti2,
      toff, PointTable_A_off4, PointTable_B_off4);
  PointTable_B_off4_data = PointTable_B_off4->data;
  PointTable_A_off4_data = PointTable_A_off4->data;
  /* %%%%%%%%%%%%%%%%%%%%%  计算交点  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  Pin2Pup[0] -= b_PP16[0];
  Pin2Pup[1] -= b_PP16[1];
  Pin2Pup[2] -= b_PP16[2];
  TiYuZhi2 = b_norm(Pin2Pup);
  Pin2Pup[0] /= TiYuZhi2;
  Pin2Pup[1] /= TiYuZhi2;
  Pin2Pup[2] /= TiYuZhi2;
  /*   单位上方向 */
  foot_of_perpendicular_from_a_point_to_a_line(PAB, b_PP16, PabLine, &TiYuZhi3,
                                               &d_PP16_tmp, &e_PP16_tmp);
  printf("%0.5f\n", ab4);
  fflush(stdout);
  printf("%0.5f\n", b_PP16_tmp);
  fflush(stdout);
  printf("%0.5f\n", XieMianPianYi_data[1]);
  fflush(stdout);
  printf("%0.5f\n", XieMianPianYi_data[3]);
  emxFree_real_T(&toff);
  fflush(stdout);
  printf("%0.5f\n", b_PP16[0]);
  fflush(stdout);
  printf("%0.5f\n", b_PP16[1]);
  fflush(stdout);
  printf("%0.5f\n", b_PP16[2]);
  fflush(stdout);
  i = PointTable_A_off8->size[0] * PointTable_A_off8->size[1];
  PointTable_A_off8->size[0] = 3;
  PointTable_A_off8->size[1] = PointTable_A_off4->size[1];
  emxEnsureCapacity_real_T(PointTable_A_off8, i);
  XieMianPianYi_data = PointTable_A_off8->data;
  b_loop_ub = 3 * PointTable_A_off4->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_A_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_A_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_A_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_A_off4_data[3 * k];
        ab4 = PointTable_A_off4_data[PP16_tmp];
        ab2 = PointTable_A_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[20];
        ab3 = PlaneParaOut8_data[21];
        zN1 = PlaneParaOut8_data[22];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[23]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_A_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_A_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_A_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_A_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_A_off4_data[3 * k];
        ab4 = PointTable_A_off4_data[PP16_tmp];
        ab2 = PointTable_A_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[12];
        ab3 = PlaneParaOut8_data[13];
        zN1 = PlaneParaOut8_data[14];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[15]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_A_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_A_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_A_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_A_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_A_off4_data[3 * k];
        ab4 = PointTable_A_off4_data[PP16_tmp];
        ab2 = PointTable_A_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[4];
        ab3 = PlaneParaOut8_data[5];
        zN1 = PlaneParaOut8_data[6];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[7]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_A_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_A_off4_data[i];
      }
    } else if (XMFlag_data[k] == 1.0) {
      /* 斜面上 */
      ab3 = Ti2_data[k];
      dir_vec[0] = PointTable_A_off4_data[3 * k] -
                   (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
      PP16_tmp = 3 * k + 1;
      dir_vec[1] = PointTable_A_off4_data[PP16_tmp] -
                   (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
      b_loop_ub = 3 * k + 2;
      dir_vec[2] = PointTable_A_off4_data[b_loop_ub] -
                   (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab1 = PointTable_A_off4_data[3 * k];
      ab4 = PointTable_A_off4_data[PP16_tmp];
      ab2 = PointTable_A_off4_data[b_loop_ub];
      TiYuZhi2 = PlaneParaOut8_data[28];
      ab3 = PlaneParaOut8_data[29];
      zN1 = PlaneParaOut8_data[30];
      ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
              PlaneParaOut8_data[31]) /
            ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
      XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
      XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
    } else {
      XieMianPianYi_data[3 * k] = PointTable_A_off4_data[3 * k];
      i = 3 * k + 1;
      XieMianPianYi_data[i] = PointTable_A_off4_data[i];
      i = 3 * k + 2;
      XieMianPianYi_data[i] = PointTable_A_off4_data[i];
    }
  }
  emxFree_real_T(&PointTable_A_off4);
  i = PointTable_B_off8->size[0] * PointTable_B_off8->size[1];
  PointTable_B_off8->size[0] = 3;
  PointTable_B_off8->size[1] = PointTable_B_off4->size[1];
  emxEnsureCapacity_real_T(PointTable_B_off8, i);
  XieMianPianYi_data = PointTable_B_off8->data;
  b_loop_ub = 3 * PointTable_B_off4->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_B_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_B_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_B_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_B_off4_data[3 * k];
        ab4 = PointTable_B_off4_data[PP16_tmp];
        ab2 = PointTable_B_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[28];
        ab3 = PlaneParaOut8_data[29];
        zN1 = PlaneParaOut8_data[30];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[31]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_B_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_B_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_B_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_B_off4_data[3 * k];
        ab4 = PointTable_B_off4_data[PP16_tmp];
        ab2 = PointTable_B_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[4];
        ab3 = PlaneParaOut8_data[5];
        zN1 = PlaneParaOut8_data[6];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[7]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2_data[k];
        dir_vec[0] = PointTable_B_off4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = PointTable_B_off4_data[PP16_tmp] -
                     (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = PointTable_B_off4_data[b_loop_ub] -
                     (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab1 = PointTable_B_off4_data[3 * k];
        ab4 = PointTable_B_off4_data[PP16_tmp];
        ab2 = PointTable_B_off4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[12];
        ab3 = PlaneParaOut8_data[13];
        zN1 = PlaneParaOut8_data[14];
        ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
                PlaneParaOut8_data[15]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = PointTable_B_off4_data[i];
      }
    } else if (XMFlag_data[k] == 1.0) {
      /* 斜面上 */
      ab3 = Ti2_data[k];
      dir_vec[0] = PointTable_B_off4_data[3 * k] -
                   (TiYuZhi3 + Pin2Pup[0] * b_PP16_tmp * ab3 / 2.0);
      PP16_tmp = 3 * k + 1;
      dir_vec[1] = PointTable_B_off4_data[PP16_tmp] -
                   (d_PP16_tmp + Pin2Pup[1] * b_PP16_tmp * ab3 / 2.0);
      b_loop_ub = 3 * k + 2;
      dir_vec[2] = PointTable_B_off4_data[b_loop_ub] -
                   (e_PP16_tmp + Pin2Pup[2] * b_PP16_tmp * ab3 / 2.0);
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab1 = PointTable_B_off4_data[3 * k];
      ab4 = PointTable_B_off4_data[PP16_tmp];
      ab2 = PointTable_B_off4_data[b_loop_ub];
      TiYuZhi2 = PlaneParaOut8_data[20];
      ab3 = PlaneParaOut8_data[21];
      zN1 = PlaneParaOut8_data[22];
      ab3 = -(((TiYuZhi2 * ab1 + ab3 * ab4) + zN1 * ab2) +
              PlaneParaOut8_data[23]) /
            ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + zN1 * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      XieMianPianYi_data[3 * k] = ab1 + ab3 * dir_vec[0];
      XieMianPianYi_data[PP16_tmp] = ab4 + ab3 * dir_vec[1];
      XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
    } else {
      XieMianPianYi_data[3 * k] = PointTable_B_off4_data[3 * k];
      i = 3 * k + 1;
      XieMianPianYi_data[i] = PointTable_B_off4_data[i];
      i = 3 * k + 2;
      XieMianPianYi_data[i] = PointTable_B_off4_data[i];
    }
  }
  emxFree_real_T(&PlaneParaOut8);
  emxFree_real_T(&PointTable_B_off4);
  emxFree_real_T(&Ti2);
  emxFree_real_T(&XMFlag);
}

/*
 * File trailer for Calculate_rectangle_from_vertex8.c
 *
 * [EOF]
 */
