/*
 * File: Calculate_rectangle_from_vertex8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 00:38:09
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

/* Function Definitions */
/*
 * 打印第一、八个平面xyz、P1、P2、PAB、phi、shenglushu、Ti,a,distanceThreshold
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
  emxArray_real_T *Ti2A;
  emxArray_real_T *Ti2B;
  emxArray_real_T *TrianglePoints8;
  emxArray_real_T *XMFlagA;
  emxArray_real_T *XMFlagB;
  emxArray_real_T *a__3;
  emxArray_real_T *a__5;
  emxArray_real_T *b_side_faces_transformed2;
  emxArray_real_T *b_side_faces_transformed4;
  emxArray_real_T *b_side_faces_transformed6;
  emxArray_real_T *b_side_faces_transformed8;
  double PP16[48];
  double a__7[24];
  double a__1[8];
  double a__4[4];
  double PabLine[3];
  double Pin2Pup[3];
  double Pout[3];
  double dir_vec[3];
  const double *Ti_data;
  const double *a_data;
  const double *side_faces_transformed2_data;
  const double *side_faces_transformed4_data;
  const double *side_faces_transformed6_data;
  const double *side_faces_transformed8_data;
  double TiYuZhi1;
  double TiYuZhi2;
  double TiYuZhi3;
  double TiYuZhi4;
  double ab1;
  double ab2;
  double ab3;
  double ab4;
  double b_dir_vec_tmp;
  double c_dir_vec_tmp;
  double d_dir_vec_tmp;
  double dir_vec_tmp;
  double temp;
  double theta1;
  double theta2;
  double theta3;
  double theta4;
  double *PlaneParaOut8_data;
  double *Ti2A_data;
  double *Ti2B_data;
  double *XMFlagA_data;
  double *XMFlagB_data;
  double *XieMianPianYi_data;
  double *b_side_faces_transformed2_data;
  double *b_side_faces_transformed4_data;
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
  side_faces_transformed8_data = side_faces_transformed8->data;
  side_faces_transformed6_data = side_faces_transformed6->data;
  side_faces_transformed4_data = side_faces_transformed4->data;
  side_faces_transformed2_data = side_faces_transformed2->data;
  /*  fprintf('first face xyz: %f, %f,
   * %f\n',side_faces_transformed1(1,1),side_faces_transformed1(2,1),side_faces_transformed1(3,1));
   */
  /*  fprintf('second face xyz: %f, %f,
   * %f\n',side_faces_transformed2(1,1),side_faces_transformed2(2,1),side_faces_transformed2(3,1));
   */
  /*  fprintf('third face xyz: %f, %f,
   * %f\n',side_faces_transformed3(1,1),side_faces_transformed3(2,1),side_faces_transformed3(3,1));
   */
  /*  fprintf('fourth face xyz: %f, %f,
   * %f\n',side_faces_transformed4(1,1),side_faces_transformed4(2,1),side_faces_transformed4(3,1));
   */
  /*  fprintf('fifth face xyz: %f, %f,
   * %f\n',side_faces_transformed5(1,1),side_faces_transformed5(2,1),side_faces_transformed5(3,1));
   */
  /*  fprintf('sixth face xyz: %f, %f,
   * %f\n',side_faces_transformed6(1,1),side_faces_transformed6(2,1),side_faces_transformed6(3,1));
   */
  /*  fprintf('seventh face xyz: %f, %f,
   * %f\n',side_faces_transformed7(1,1),side_faces_transformed7(2,1),side_faces_transformed7(3,1));
   */
  /*  fprintf('eighth face xyz: %f, %f,
   * %f\n',side_faces_transformed8(1,1),side_faces_transformed8(2,1),side_faces_transformed8(3,1));
   */
  /*   */
  /*  fprintf('P_bound1 xyz: %f, %f, %f\n',P_bound1(1),P_bound1(2),P_bound1(3));
   */
  /*  fprintf('P_bound2 xyz: %f, %f, %f\n',P_bound2(1),P_bound2(2),P_bound2(3));
   */
  /*  fprintf('PAB xyz: %f, %f, %f\n',PAB(1),PAB(2),PAB(3)); */
  /*   */
  /*  fprintf('phi: %f\n',phi); */
  /*   */
  /*  fprintf('shenglushu: %f\n',shenglunum); */
  /*  fprintf('Ti: %f, %f, %f, %f\n',Ti(1),Ti(2),Ti(3),Ti(4)); */
  /*  fprintf('a: %f, %f, %f, %f\n',a(1),a(2),a(3),a(4)); */
  /*  fprintf('distanceThreshold: %f\n',distanceThreshold); */
  /* %%%%%%%%%%%%%%%%%%%%%  计算八面参数  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  emxInit_real_T(&b_side_faces_transformed2, 2);
  i = b_side_faces_transformed2->size[0] * b_side_faces_transformed2->size[1];
  b_side_faces_transformed2->size[0] = 3;
  b_side_faces_transformed2->size[1] = side_faces_transformed2->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed2, i);
  b_side_faces_transformed2_data = b_side_faces_transformed2->data;
  loop_ub =
      side_faces_transformed2->size[0] * side_faces_transformed2->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_side_faces_transformed2_data[i] = side_faces_transformed2_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed4, 2);
  i = b_side_faces_transformed4->size[0] * b_side_faces_transformed4->size[1];
  b_side_faces_transformed4->size[0] = 3;
  b_side_faces_transformed4->size[1] = side_faces_transformed4->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed4, i);
  b_side_faces_transformed4_data = b_side_faces_transformed4->data;
  loop_ub =
      side_faces_transformed4->size[0] * side_faces_transformed4->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_side_faces_transformed4_data[i] = side_faces_transformed4_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed6, 2);
  i = b_side_faces_transformed6->size[0] * b_side_faces_transformed6->size[1];
  b_side_faces_transformed6->size[0] = 3;
  b_side_faces_transformed6->size[1] = side_faces_transformed6->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed6, i);
  XieMianPianYi_data = b_side_faces_transformed6->data;
  loop_ub =
      side_faces_transformed6->size[0] * side_faces_transformed6->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed6_data[i];
  }
  emxInit_real_T(&b_side_faces_transformed8, 2);
  i = b_side_faces_transformed8->size[0] * b_side_faces_transformed8->size[1];
  b_side_faces_transformed8->size[0] = 3;
  b_side_faces_transformed8->size[1] = side_faces_transformed8->size[1];
  emxEnsureCapacity_real_T(b_side_faces_transformed8, i);
  XieMianPianYi_data = b_side_faces_transformed8->data;
  loop_ub =
      side_faces_transformed8->size[0] * side_faces_transformed8->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    XieMianPianYi_data[i] = side_faces_transformed8_data[i];
  }
  emxInit_real_T(&XMFlagA, 2);
  emxInit_real_T(&PlaneParaOut8, 2);
  emxInit_real_T(&TrianglePoints8, 2);
  b_planefit8(side_faces_transformed1, b_side_faces_transformed2,
              side_faces_transformed3, b_side_faces_transformed4,
              side_faces_transformed5, b_side_faces_transformed6,
              side_faces_transformed7, b_side_faces_transformed8, P_bound1,
              P_bound2, distanceThreshold, PlaneParaOut8, TrianglePoints8, a__1,
              XMFlagA);
  XieMianPianYi_data = TrianglePoints8->data;
  PlaneParaOut8_data = PlaneParaOut8->data;
  emxFree_real_T(&b_side_faces_transformed8);
  emxFree_real_T(&b_side_faces_transformed6);
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
  /* %%%%%%%%%%%%%%%%%%%%%  计算阈值  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  承接16顶点 */
  for (i = 0; i < 16; i++) {
    PP16_tmp = 3 * b_iv[i];
    PP16[3 * i] = XieMianPianYi_data[PP16_tmp];
    PP16[3 * i + 1] = XieMianPianYi_data[PP16_tmp + 1];
    PP16[3 * i + 2] = XieMianPianYi_data[PP16_tmp + 2];
  }
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[0], &PP16[3], &PP16[18],
                                               &ab4, &ab3, &TiYuZhi4);
  dir_vec_tmp = PP16[3] - PP16[18];
  dir_vec[0] = dir_vec_tmp;
  temp = PP16[4] - PP16[19];
  dir_vec[1] = temp;
  b_dir_vec_tmp = PP16[5] - PP16[20];
  dir_vec[2] = b_dir_vec_tmp;
  ab1 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[3] - ab4;
  dir_vec[1] = PP16[4] - ab3;
  dir_vec[2] = PP16[5] - TiYuZhi4;
  TiYuZhi1 = (ab1 - b_norm(dir_vec)) / ab1;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[9], &PP16[6], &PP16[15],
                                               &ab1, &ab4, &TiYuZhi4);
  ab3 = PP16[6] - PP16[15];
  dir_vec[0] = ab3;
  c_dir_vec_tmp = PP16[7] - PP16[16];
  dir_vec[1] = c_dir_vec_tmp;
  d_dir_vec_tmp = PP16[8] - PP16[17];
  dir_vec[2] = d_dir_vec_tmp;
  ab2 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[6] - ab1;
  dir_vec[1] = PP16[7] - ab4;
  dir_vec[2] = PP16[8] - TiYuZhi4;
  TiYuZhi2 = (ab2 - b_norm(dir_vec)) / ab2;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[12], &PP16[6], &PP16[15],
                                               &ab1, &ab4, &TiYuZhi4);
  dir_vec[0] = ab3;
  dir_vec[1] = c_dir_vec_tmp;
  dir_vec[2] = d_dir_vec_tmp;
  ab3 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[6] - ab1;
  dir_vec[1] = PP16[7] - ab4;
  dir_vec[2] = PP16[8] - TiYuZhi4;
  TiYuZhi3 = (ab3 - b_norm(dir_vec)) / ab3;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[21], &PP16[3], &PP16[18],
                                               &ab1, &TiYuZhi4, &ab2);
  dir_vec[0] = dir_vec_tmp;
  dir_vec[1] = temp;
  dir_vec[2] = b_dir_vec_tmp;
  ab4 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[3] - ab1;
  dir_vec[1] = PP16[4] - TiYuZhi4;
  dir_vec[2] = PP16[5] - ab2;
  TiYuZhi4 = (ab4 - b_norm(dir_vec)) / ab4;
  /*  a1 = PP16(:,1); */
  /*  b1 = PP16(:,8); */
  /*  c1 = PP16(:,2); */
  /*  d1 = PP16(:,7); */
  /*  TiYuZhi1 = norm(a1-b1)./norm(c1-d1); */
  /*  TiYuZhi4 = norm(a1-b1)./norm(c1-d1); */
  /*   */
  /*  a1 = PP16(:,4); */
  /*  b1 = PP16(:,5); */
  /*  c1 = PP16(:,3); */
  /*  d1 = PP16(:,6); */
  /*  TiYuZhi2 = norm(a1-b1)./norm(c1-d1); */
  /*  TiYuZhi3 = norm(a1-b1)./norm(c1-d1); */
  /* %%%%%%%%%%%%%%%%%%%%%  判断点是否在斜面上（利用阈值）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  temp = shenglunum / 2.0;
  i = XMFlagA->size[0] * XMFlagA->size[1];
  XMFlagA->size[0] = 1;
  loop_ub = (int)(2.0 * shenglunum);
  XMFlagA->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlagA, i);
  XMFlagA_data = XMFlagA->data;
  for (i = 0; i < loop_ub; i++) {
    XMFlagA_data[i] = 0.0;
  }
  for (PP16_tmp = 0; PP16_tmp < loop_ub; PP16_tmp++) {
    ab4 = fabs(Ti_data[PP16_tmp]);
    if ((double)PP16_tmp + 1.0 <= temp) {
      XMFlagA_data[PP16_tmp] = !(ab4 < fabs(TiYuZhi4));
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      XMFlagA_data[PP16_tmp] = !(ab4 < fabs(TiYuZhi1));
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      XMFlagA_data[PP16_tmp] = !(ab4 < fabs(TiYuZhi2));
    } else {
      XMFlagA_data[PP16_tmp] = !(ab4 < fabs(TiYuZhi3));
    }
  }
  emxInit_real_T(&Ti2A, 2);
  i = Ti2A->size[0] * Ti2A->size[1];
  Ti2A->size[0] = 1;
  Ti2A->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ti2A, i);
  Ti2A_data = Ti2A->data;
  for (i = 0; i < loop_ub; i++) {
    Ti2A_data[i] = 0.0;
  }
  /* %%%%%%%%%%%%%%%%%%%%%  对斜面上的点进行偏移（修正Ti）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (PP16_tmp = 0; PP16_tmp < loop_ub; PP16_tmp++) {
    if ((double)PP16_tmp + 1.0 <= temp) {
      if (XMFlagA_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        Ti2A_data[PP16_tmp] =
            Ti_data[PP16_tmp] + a_data[PP16_tmp] * sin(theta4);
      } else {
        Ti2A_data[PP16_tmp] = Ti_data[PP16_tmp];
      }
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      if (XMFlagA_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        Ti2A_data[PP16_tmp] =
            Ti_data[PP16_tmp] - a_data[PP16_tmp] * sin(theta1);
      } else {
        Ti2A_data[PP16_tmp] = Ti_data[PP16_tmp];
      }
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      if (XMFlagA_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        Ti2A_data[PP16_tmp] =
            Ti_data[PP16_tmp] - a_data[PP16_tmp] * sin(theta2);
      } else {
        Ti2A_data[PP16_tmp] = Ti_data[PP16_tmp];
      }
    } else if (XMFlagA_data[PP16_tmp] == 1.0) {
      /* 斜面上 */
      Ti2A_data[PP16_tmp] = Ti_data[PP16_tmp] + a_data[PP16_tmp] * sin(theta3);
    } else {
      Ti2A_data[PP16_tmp] = Ti_data[PP16_tmp];
    }
  }
  /* %%%%%%%%%%%%%%%%%%%%%  判断点是否在斜面上（利用阈值）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  emxInit_real_T(&XMFlagB, 2);
  i = XMFlagB->size[0] * XMFlagB->size[1];
  XMFlagB->size[0] = 1;
  XMFlagB->size[1] = loop_ub;
  emxEnsureCapacity_real_T(XMFlagB, i);
  XMFlagB_data = XMFlagB->data;
  for (i = 0; i < loop_ub; i++) {
    XMFlagB_data[i] = 0.0;
  }
  for (PP16_tmp = 0; PP16_tmp < loop_ub; PP16_tmp++) {
    ab3 = fabs(Ti_data[PP16_tmp]);
    if ((double)PP16_tmp + 1.0 <= temp) {
      XMFlagB_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi3));
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      XMFlagB_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi2));
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      XMFlagB_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi1));
    } else {
      XMFlagB_data[PP16_tmp] = !(ab3 < fabs(TiYuZhi4));
    }
  }
  emxInit_real_T(&Ti2B, 2);
  i = Ti2B->size[0] * Ti2B->size[1];
  Ti2B->size[0] = 1;
  Ti2B->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ti2B, i);
  Ti2B_data = Ti2B->data;
  for (i = 0; i < loop_ub; i++) {
    Ti2B_data[i] = 0.0;
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
      if (XMFlagB_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp] + TiYuZhi2 * sin(theta3);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta3);
      } else {
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      if (XMFlagB_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp] - TiYuZhi2 * sin(theta2);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta2);
      } else {
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      if (XMFlagB_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        TiYuZhi2 = a_data[PP16_tmp];
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp] - TiYuZhi2 * sin(theta1);
        XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta1);
      } else {
        Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if (XMFlagB_data[PP16_tmp] == 1.0) {
      /* 斜面上 */
      TiYuZhi2 = a_data[PP16_tmp];
      Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp] + TiYuZhi2 * sin(theta4);
      XieMianPianYi_data[PP16_tmp] = TiYuZhi2 * tan(theta4);
    } else {
      Ti2B_data[PP16_tmp] = Ti_data[PP16_tmp];
      XieMianPianYi_data[PP16_tmp] = 0.0;
    }
  }
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形拟合  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  emxInit_real_T(&a__5, 2);
  emxInit_real_T(&a__3, 2);
  b_planefit4(side_faces_transformed1, side_faces_transformed3,
              side_faces_transformed5, side_faces_transformed7, P_bound1,
              P_bound2, distanceThreshold, a__3, TrianglePoints8, a__4, a__5);
  emxFree_real_T(&a__3);
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形参数计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  Calculate_rectangle_from_vertex(TrianglePoints8, dir_vec, Pout, Pin2Pup, &ab4,
                                  &dir_vec_tmp, &ab3, PabLine, a__7);
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
  PP16_tmp = a__5->size[0] * a__5->size[1];
  a__5->size[0] = 1;
  a__5->size[1] = (b_loop_ub + k) - i;
  emxEnsureCapacity_real_T(a__5, PP16_tmp);
  XieMianPianYi_data = a__5->data;
  for (PP16_tmp = 0; PP16_tmp < b_loop_ub; PP16_tmp++) {
    XieMianPianYi_data[PP16_tmp] = -a_data[PP16_tmp] / ab3;
  }
  PP16_tmp = k - i;
  for (k = 0; k < PP16_tmp; k++) {
    XieMianPianYi_data[k + b_loop_ub] = a_data[i + k] / ab3;
  }
  Calculat_JuXing_A_and_B_Points_after_Offest(
      PabLine, Pin2Pup, dir_vec, ab4, dir_vec_tmp, PAB, phi, shenglunum, Ti2A,
      a__5, b_side_faces_transformed2, b_side_faces_transformed4);
  b_side_faces_transformed4_data = b_side_faces_transformed4->data;
  b_side_faces_transformed2_data = b_side_faces_transformed2->data;
  emxFree_real_T(&a__5);
  /* %%%%%%%%%%%%%%%%%%%%%  计算交点  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  Pin2Pup[0] -= dir_vec[0];
  Pin2Pup[1] -= dir_vec[1];
  Pin2Pup[2] -= dir_vec[2];
  TiYuZhi2 = b_norm(Pin2Pup);
  Pin2Pup[0] /= TiYuZhi2;
  Pin2Pup[1] /= TiYuZhi2;
  Pin2Pup[2] /= TiYuZhi2;
  /*   单位上方向 */
  foot_of_perpendicular_from_a_point_to_a_line(PAB, dir_vec, Pout, &TiYuZhi3,
                                               &c_dir_vec_tmp, &d_dir_vec_tmp);
  i = PointTable_A_off8->size[0] * PointTable_A_off8->size[1];
  PointTable_A_off8->size[0] = 3;
  PointTable_A_off8->size[1] = b_side_faces_transformed2->size[1];
  emxEnsureCapacity_real_T(PointTable_A_off8, i);
  XieMianPianYi_data = PointTable_A_off8->data;
  b_loop_ub = 3 * b_side_faces_transformed2->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlagA_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2A_data[k];
        dir_vec[0] = b_side_faces_transformed2_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed2_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed2_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed2_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed2_data[PP16_tmp];
        ab2 = b_side_faces_transformed2_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[28];
        ab3 = PlaneParaOut8_data[29];
        ab1 = PlaneParaOut8_data[30];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[31]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed2_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlagA_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2A_data[k];
        dir_vec[0] = b_side_faces_transformed2_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed2_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed2_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed2_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed2_data[PP16_tmp];
        ab2 = b_side_faces_transformed2_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[4];
        ab3 = PlaneParaOut8_data[5];
        ab1 = PlaneParaOut8_data[6];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[7]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed2_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlagA_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2A_data[k];
        dir_vec[0] = b_side_faces_transformed2_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed2_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed2_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed2_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed2_data[PP16_tmp];
        ab2 = b_side_faces_transformed2_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[12];
        ab3 = PlaneParaOut8_data[13];
        ab1 = PlaneParaOut8_data[14];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[15]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed2_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
      }
    } else if (XMFlagA_data[k] == 1.0) {
      /* 斜面上 */
      ab3 = Ti2A_data[k];
      dir_vec[0] = b_side_faces_transformed2_data[3 * k] -
                   (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
      PP16_tmp = 3 * k + 1;
      dir_vec[1] = b_side_faces_transformed2_data[PP16_tmp] -
                   (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
      b_loop_ub = 3 * k + 2;
      dir_vec[2] = b_side_faces_transformed2_data[b_loop_ub] -
                   (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab4 = b_side_faces_transformed2_data[3 * k];
      TiYuZhi4 = b_side_faces_transformed2_data[PP16_tmp];
      ab2 = b_side_faces_transformed2_data[b_loop_ub];
      TiYuZhi2 = PlaneParaOut8_data[20];
      ab3 = PlaneParaOut8_data[21];
      ab1 = PlaneParaOut8_data[22];
      ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
              PlaneParaOut8_data[23]) /
            ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
      XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
      XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
    } else {
      XieMianPianYi_data[3 * k] = b_side_faces_transformed2_data[3 * k];
      i = 3 * k + 1;
      XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
      i = 3 * k + 2;
      XieMianPianYi_data[i] = b_side_faces_transformed2_data[i];
    }
  }
  emxFree_real_T(&b_side_faces_transformed2);
  emxFree_real_T(&Ti2A);
  emxFree_real_T(&XMFlagA);
  i = PointTable_B_off8->size[0] * PointTable_B_off8->size[1];
  PointTable_B_off8->size[0] = 3;
  PointTable_B_off8->size[1] = b_side_faces_transformed4->size[1];
  emxEnsureCapacity_real_T(PointTable_B_off8, i);
  XieMianPianYi_data = PointTable_B_off8->data;
  b_loop_ub = 3 * b_side_faces_transformed4->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    XieMianPianYi_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlagB_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2B_data[k];
        dir_vec[0] = b_side_faces_transformed4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed4_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed4_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed4_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed4_data[PP16_tmp];
        ab2 = b_side_faces_transformed4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[20];
        ab3 = PlaneParaOut8_data[21];
        ab1 = PlaneParaOut8_data[22];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[23]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlagB_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2B_data[k];
        dir_vec[0] = b_side_faces_transformed4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed4_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed4_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed4_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed4_data[PP16_tmp];
        ab2 = b_side_faces_transformed4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[12];
        ab3 = PlaneParaOut8_data[13];
        ab1 = PlaneParaOut8_data[14];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[15]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlagB_data[k] == 1.0) {
        /* 斜面上 */
        ab3 = Ti2B_data[k];
        dir_vec[0] = b_side_faces_transformed4_data[3 * k] -
                     (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
        PP16_tmp = 3 * k + 1;
        dir_vec[1] = b_side_faces_transformed4_data[PP16_tmp] -
                     (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
        b_loop_ub = 3 * k + 2;
        dir_vec[2] = b_side_faces_transformed4_data[b_loop_ub] -
                     (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = b_side_faces_transformed4_data[3 * k];
        TiYuZhi4 = b_side_faces_transformed4_data[PP16_tmp];
        ab2 = b_side_faces_transformed4_data[b_loop_ub];
        TiYuZhi2 = PlaneParaOut8_data[4];
        ab3 = PlaneParaOut8_data[5];
        ab1 = PlaneParaOut8_data[6];
        ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
                PlaneParaOut8_data[7]) /
              ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
        XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
        XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
      } else {
        XieMianPianYi_data[3 * k] = b_side_faces_transformed4_data[3 * k];
        i = 3 * k + 1;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
        i = 3 * k + 2;
        XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
      }
    } else if (XMFlagB_data[k] == 1.0) {
      /* 斜面上 */
      ab3 = Ti2B_data[k];
      dir_vec[0] = b_side_faces_transformed4_data[3 * k] -
                   (TiYuZhi3 + Pin2Pup[0] * dir_vec_tmp * ab3 / 2.0);
      PP16_tmp = 3 * k + 1;
      dir_vec[1] = b_side_faces_transformed4_data[PP16_tmp] -
                   (c_dir_vec_tmp + Pin2Pup[1] * dir_vec_tmp * ab3 / 2.0);
      b_loop_ub = 3 * k + 2;
      dir_vec[2] = b_side_faces_transformed4_data[b_loop_ub] -
                   (d_dir_vec_tmp + Pin2Pup[2] * dir_vec_tmp * ab3 / 2.0);
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab4 = b_side_faces_transformed4_data[3 * k];
      TiYuZhi4 = b_side_faces_transformed4_data[PP16_tmp];
      ab2 = b_side_faces_transformed4_data[b_loop_ub];
      TiYuZhi2 = PlaneParaOut8_data[28];
      ab3 = PlaneParaOut8_data[29];
      ab1 = PlaneParaOut8_data[30];
      ab3 = -(((TiYuZhi2 * ab4 + ab3 * TiYuZhi4) + ab1 * ab2) +
              PlaneParaOut8_data[31]) /
            ((TiYuZhi2 * dir_vec[0] + ab3 * dir_vec[1]) + ab1 * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      XieMianPianYi_data[3 * k] = ab4 + ab3 * dir_vec[0];
      XieMianPianYi_data[PP16_tmp] = TiYuZhi4 + ab3 * dir_vec[1];
      XieMianPianYi_data[b_loop_ub] = ab2 + ab3 * dir_vec[2];
    } else {
      XieMianPianYi_data[3 * k] = b_side_faces_transformed4_data[3 * k];
      i = 3 * k + 1;
      XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
      i = 3 * k + 2;
      XieMianPianYi_data[i] = b_side_faces_transformed4_data[i];
    }
  }
  emxFree_real_T(&b_side_faces_transformed4);
  emxFree_real_T(&PlaneParaOut8);
  emxFree_real_T(&Ti2B);
  emxFree_real_T(&XMFlagB);
}

/*
 * File trailer for Calculate_rectangle_from_vertex8.c
 *
 * [EOF]
 */
