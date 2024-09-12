/*
 * File: Calculate_rectangle_from_vertex8.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 12-Sep-2024 22:50:43
 */

/* Include Files */
#include "Calculate_rectangle_from_vertex8.h"
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "Calculate_rectangle_from_vertex.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "norm.h"
#include "planefit4.h"
#include "planefit8.h"
#include "rt_nonfinite.h"
#include <math.h>

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
  emxArray_real_T *a__5;
  double PP16[48];
  double a__7[24];
  double a__1[8];
  double a__4[4];
  double Pout[3];
  double Tao[3];
  double UPP[3];
  double dir_vec[3];
  const double *Ti_data;
  const double *a_data;
  double TiYuZhi1;
  double TiYuZhi2;
  double TiYuZhi3;
  double Tii;
  double ab1;
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
  double zN5;
  double *PlaneParaOut8_data;
  double *PointTable_B_off4_data;
  double *Ti2_data;
  double *TrianglePoints8_data;
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
  emxInit_real_T(&XMFlag, 2);
  emxInit_real_T(&PlaneParaOut8, 2);
  emxInit_real_T(&TrianglePoints8, 2);
  b_planefit8(
      side_faces_transformed1, side_faces_transformed2, side_faces_transformed3,
      side_faces_transformed4, side_faces_transformed5, side_faces_transformed6,
      side_faces_transformed7, side_faces_transformed8, P_bound1, P_bound2,
      distanceThreshold, PlaneParaOut8, TrianglePoints8, a__1, XMFlag);
  TrianglePoints8_data = TrianglePoints8->data;
  PlaneParaOut8_data = PlaneParaOut8->data;
  /* %%%%%%%%%%%%%%%%%%%%%  计算角度  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  zN5 = b_norm(&PlaneParaOut8_data[0]);
  ab4 = b_norm(&PlaneParaOut8_data[16]);
  dir_vec_tmp = PlaneParaOut8_data[0];
  Tii = dir_vec_tmp * PlaneParaOut8_data[4];
  TiYuZhi3 = PlaneParaOut8_data[16];
  ab1 = PlaneParaOut8_data[12] * TiYuZhi3;
  ab3 = TiYuZhi3 * PlaneParaOut8_data[20];
  temp = dir_vec_tmp * PlaneParaOut8_data[28];
  dir_vec_tmp = PlaneParaOut8_data[1];
  Tii += dir_vec_tmp * PlaneParaOut8_data[5];
  TiYuZhi3 = PlaneParaOut8_data[17];
  ab1 += PlaneParaOut8_data[13] * TiYuZhi3;
  ab3 += TiYuZhi3 * PlaneParaOut8_data[21];
  temp += dir_vec_tmp * PlaneParaOut8_data[29];
  dir_vec_tmp = PlaneParaOut8_data[2];
  Tii += dir_vec_tmp * PlaneParaOut8_data[6];
  TiYuZhi3 = PlaneParaOut8_data[18];
  ab1 += PlaneParaOut8_data[14] * TiYuZhi3;
  ab3 += TiYuZhi3 * PlaneParaOut8_data[22];
  temp += dir_vec_tmp * PlaneParaOut8_data[30];
  theta1 = acos(Tii / zN5 / b_norm(&PlaneParaOut8_data[4]));
  theta2 = acos(ab1 / b_norm(&PlaneParaOut8_data[12]) / ab4);
  theta3 = acos(ab3 / ab4 / b_norm(&PlaneParaOut8_data[20]));
  theta4 = acos(temp / zN5 / b_norm(&PlaneParaOut8_data[28]));
  /* %%%%%%%%%%%%%%%%%%%%%  计算阈值  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  承接16顶点 */
  for (i = 0; i < 16; i++) {
    PP16_tmp = 3 * b_iv[i];
    PP16[3 * i] = TrianglePoints8_data[PP16_tmp];
    PP16[3 * i + 1] = TrianglePoints8_data[PP16_tmp + 1];
    PP16[3 * i + 2] = TrianglePoints8_data[PP16_tmp + 2];
  }
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[3], &PP16[0], &PP16[9],
                                               &ab4, &ab3, &zN5);
  b_dir_vec_tmp = PP16[0] - PP16[9];
  dir_vec[0] = b_dir_vec_tmp;
  c_dir_vec_tmp = PP16[1] - PP16[10];
  dir_vec[1] = c_dir_vec_tmp;
  d_dir_vec_tmp = PP16[2] - PP16[11];
  dir_vec[2] = d_dir_vec_tmp;
  ab1 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[0] - ab4;
  dir_vec[1] = PP16[1] - ab3;
  dir_vec[2] = PP16[2] - zN5;
  TiYuZhi1 = (ab1 - b_norm(dir_vec)) / ab1;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[18], &PP16[21], &PP16[12],
                                               &zN5, &Tii, &temp);
  ab4 = PP16[21] - PP16[12];
  dir_vec[0] = ab4;
  ab3 = PP16[22] - PP16[13];
  dir_vec[1] = ab3;
  dir_vec_tmp = PP16[23] - PP16[14];
  dir_vec[2] = dir_vec_tmp;
  ab1 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[21] - zN5;
  dir_vec[1] = PP16[22] - Tii;
  dir_vec[2] = PP16[23] - temp;
  TiYuZhi2 = (ab1 - b_norm(dir_vec)) / ab1;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[15], &PP16[21], &PP16[12],
                                               &zN5, &Tii, &temp);
  dir_vec[0] = ab4;
  dir_vec[1] = ab3;
  dir_vec[2] = dir_vec_tmp;
  ab3 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[21] - zN5;
  dir_vec[1] = PP16[22] - Tii;
  dir_vec[2] = PP16[23] - temp;
  TiYuZhi3 = (ab3 - b_norm(dir_vec)) / ab3;
  foot_of_perpendicular_from_a_point_to_a_line(&PP16[6], &PP16[0], &PP16[9],
                                               &zN5, &Tii, &temp);
  dir_vec[0] = b_dir_vec_tmp;
  dir_vec[1] = c_dir_vec_tmp;
  dir_vec[2] = d_dir_vec_tmp;
  ab4 = b_norm(dir_vec) / 2.0;
  dir_vec[0] = PP16[0] - zN5;
  dir_vec[1] = PP16[1] - Tii;
  dir_vec[2] = PP16[2] - temp;
  ab1 = (ab4 - b_norm(dir_vec)) / ab4;
  /* %%%%%%%%%%%%%%%%%%%%%  判断点是否在斜面上（利用阈值）
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  temp = shenglunum / 2.0;
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
    Tii = fabs(Ti_data[PP16_tmp]);
    if ((double)PP16_tmp + 1.0 <= temp) {
      XMFlag_data[PP16_tmp] = !(Tii < fabs(TiYuZhi3));
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      XMFlag_data[PP16_tmp] = !(Tii < fabs(TiYuZhi2));
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      XMFlag_data[PP16_tmp] = !(Tii < fabs(TiYuZhi1));
    } else {
      XMFlag_data[PP16_tmp] = !(Tii < fabs(ab1));
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
        dir_vec_tmp = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] + dir_vec_tmp * sin(theta3);
        XieMianPianYi_data[PP16_tmp] = dir_vec_tmp * tan(theta3);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        dir_vec_tmp = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] - dir_vec_tmp * sin(theta2);
        XieMianPianYi_data[PP16_tmp] = dir_vec_tmp * tan(theta2);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if ((double)PP16_tmp + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[PP16_tmp] == 1.0) {
        /* 斜面上 */
        dir_vec_tmp = a_data[PP16_tmp];
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] - dir_vec_tmp * sin(theta1);
        XieMianPianYi_data[PP16_tmp] = dir_vec_tmp * tan(theta1);
      } else {
        Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
        XieMianPianYi_data[PP16_tmp] = 0.0;
      }
    } else if (XMFlag_data[PP16_tmp] == 1.0) {
      /* 斜面上 */
      dir_vec_tmp = a_data[PP16_tmp];
      Ti2_data[PP16_tmp] = Ti_data[PP16_tmp] + dir_vec_tmp * sin(theta4);
      XieMianPianYi_data[PP16_tmp] = dir_vec_tmp * tan(theta4);
    } else {
      Ti2_data[PP16_tmp] = Ti_data[PP16_tmp];
      XieMianPianYi_data[PP16_tmp] = 0.0;
    }
  }
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形拟合  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  emxInit_real_T(&a__5, 2);
  emxInit_real_T(&a__3, 2);
  b_planefit4(side_faces_transformed1, side_faces_transformed3,
              side_faces_transformed5, side_faces_transformed7, P_bound1,
              P_bound2, distanceThreshold, a__3, TrianglePoints8, a__4, a__5);
  TrianglePoints8_data = TrianglePoints8->data;
  emxFree_real_T(&a__3);
  /* %%%%%%%%%%%%%%%%%%%%%  调用矩形参数计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  Calculate_rectangle_from_vertex(TrianglePoints8, dir_vec, Pout, UPP, &Tii,
                                  &ab4, &ab1, Tao, a__7);
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
  ab1 = tan(phi);
  PP16_tmp = a__5->size[0] * a__5->size[1];
  a__5->size[0] = 1;
  a__5->size[1] = (b_loop_ub + k) - i;
  emxEnsureCapacity_real_T(a__5, PP16_tmp);
  Ti2_data = a__5->data;
  for (PP16_tmp = 0; PP16_tmp < b_loop_ub; PP16_tmp++) {
    Ti2_data[PP16_tmp] = -a_data[PP16_tmp] / ab1;
  }
  PP16_tmp = k - i;
  for (k = 0; k < PP16_tmp; k++) {
    Ti2_data[k + b_loop_ub] = a_data[i + k] / ab1;
  }
  emxInit_real_T(&PointTable_A_off4, 2);
  emxInit_real_T(&PointTable_B_off4, 2);
  Calculat_JuXing_A_and_B_Points_after_Offest(
      Tao, UPP, dir_vec, Tii, ab4, PAB, phi, shenglunum, Ti2, a__5,
      PointTable_A_off4, PointTable_B_off4);
  PointTable_B_off4_data = PointTable_B_off4->data;
  XieMianPianYi_data = PointTable_A_off4->data;
  emxFree_real_T(&a__5);
  emxFree_real_T(&Ti2);
  /* %%%%%%%%%%%%%%%%%%%%%  计算交点  %%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  dir_vec[0] = TrianglePoints8_data[0] - TrianglePoints8_data[24];
  dir_vec[1] = TrianglePoints8_data[1] - TrianglePoints8_data[25];
  dir_vec[2] = TrianglePoints8_data[2] - TrianglePoints8_data[26];
  emxFree_real_T(&TrianglePoints8);
  i = PointTable_A_off8->size[0] * PointTable_A_off8->size[1];
  PointTable_A_off8->size[0] = 3;
  PointTable_A_off8->size[1] = PointTable_A_off4->size[1];
  emxEnsureCapacity_real_T(PointTable_A_off8, i);
  Ti2_data = PointTable_A_off8->data;
  b_loop_ub = 3 * PointTable_A_off4->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    Ti2_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = XieMianPianYi_data[3 * k] + dir_vec[0];
        PP16_tmp = 3 * k + 1;
        ab3 = XieMianPianYi_data[PP16_tmp] + dir_vec[1];
        b_loop_ub = 3 * k + 2;
        zN5 = XieMianPianYi_data[b_loop_ub] + dir_vec[2];
        dir_vec_tmp = PlaneParaOut8_data[20];
        TiYuZhi3 = PlaneParaOut8_data[21];
        Tii = PlaneParaOut8_data[22];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[23]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = XieMianPianYi_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = XieMianPianYi_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = XieMianPianYi_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = XieMianPianYi_data[3 * k] + dir_vec[0];
        PP16_tmp = 3 * k + 1;
        ab3 = XieMianPianYi_data[PP16_tmp] + dir_vec[1];
        b_loop_ub = 3 * k + 2;
        zN5 = XieMianPianYi_data[b_loop_ub] + dir_vec[2];
        dir_vec_tmp = PlaneParaOut8_data[12];
        TiYuZhi3 = PlaneParaOut8_data[13];
        Tii = PlaneParaOut8_data[14];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[15]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = XieMianPianYi_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = XieMianPianYi_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = XieMianPianYi_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = XieMianPianYi_data[3 * k] + dir_vec[0];
        PP16_tmp = 3 * k + 1;
        ab3 = XieMianPianYi_data[PP16_tmp] + dir_vec[1];
        b_loop_ub = 3 * k + 2;
        zN5 = XieMianPianYi_data[b_loop_ub] + dir_vec[2];
        dir_vec_tmp = PlaneParaOut8_data[4];
        TiYuZhi3 = PlaneParaOut8_data[5];
        Tii = PlaneParaOut8_data[6];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[7]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = XieMianPianYi_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = XieMianPianYi_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = XieMianPianYi_data[i];
      }
    } else if (XMFlag_data[k] == 1.0) {
      /* 斜面上 */
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab4 = XieMianPianYi_data[3 * k] + dir_vec[0];
      PP16_tmp = 3 * k + 1;
      ab3 = XieMianPianYi_data[PP16_tmp] + dir_vec[1];
      b_loop_ub = 3 * k + 2;
      zN5 = XieMianPianYi_data[b_loop_ub] + dir_vec[2];
      dir_vec_tmp = PlaneParaOut8_data[28];
      TiYuZhi3 = PlaneParaOut8_data[29];
      Tii = PlaneParaOut8_data[30];
      ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
              PlaneParaOut8_data[31]) /
            ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
             Tii * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
      Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
      Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
    } else {
      Ti2_data[3 * k] = XieMianPianYi_data[3 * k];
      i = 3 * k + 1;
      Ti2_data[i] = XieMianPianYi_data[i];
      i = 3 * k + 2;
      Ti2_data[i] = XieMianPianYi_data[i];
    }
  }
  emxFree_real_T(&PointTable_A_off4);
  i = PointTable_B_off8->size[0] * PointTable_B_off8->size[1];
  PointTable_B_off8->size[0] = 3;
  PointTable_B_off8->size[1] = PointTable_B_off4->size[1];
  emxEnsureCapacity_real_T(PointTable_B_off8, i);
  Ti2_data = PointTable_B_off8->data;
  b_loop_ub = 3 * PointTable_B_off4->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    Ti2_data[i] = 0.0;
  }
  for (k = 0; k < loop_ub; k++) {
    if ((double)k + 1.0 <= temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = PointTable_B_off4_data[3 * k];
        PP16_tmp = 3 * k + 1;
        ab3 = PointTable_B_off4_data[PP16_tmp];
        b_loop_ub = 3 * k + 2;
        zN5 = PointTable_B_off4_data[b_loop_ub];
        dir_vec_tmp = PlaneParaOut8_data[28];
        TiYuZhi3 = PlaneParaOut8_data[29];
        Tii = PlaneParaOut8_data[30];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[31]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = PointTable_B_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 2.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = PointTable_B_off4_data[3 * k];
        PP16_tmp = 3 * k + 1;
        ab3 = PointTable_B_off4_data[PP16_tmp];
        b_loop_ub = 3 * k + 2;
        zN5 = PointTable_B_off4_data[b_loop_ub];
        dir_vec_tmp = PlaneParaOut8_data[4];
        TiYuZhi3 = PlaneParaOut8_data[5];
        Tii = PlaneParaOut8_data[6];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[7]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = PointTable_B_off4_data[i];
      }
    } else if ((double)k + 1.0 <= 3.0 * temp) {
      if (XMFlag_data[k] == 1.0) {
        /* 斜面上 */
        /*  计算方向向量 */
        /*  将直线方程代入平面方程，求解参数 t */
        ab4 = PointTable_B_off4_data[3 * k];
        PP16_tmp = 3 * k + 1;
        ab3 = PointTable_B_off4_data[PP16_tmp];
        b_loop_ub = 3 * k + 2;
        zN5 = PointTable_B_off4_data[b_loop_ub];
        dir_vec_tmp = PlaneParaOut8_data[12];
        TiYuZhi3 = PlaneParaOut8_data[13];
        Tii = PlaneParaOut8_data[14];
        ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
                PlaneParaOut8_data[15]) /
              ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
               Tii * dir_vec[2]);
        /*  计算交点 */
        /*  输出交点 */
        Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
        Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
        Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
      } else {
        Ti2_data[3 * k] = PointTable_B_off4_data[3 * k];
        i = 3 * k + 1;
        Ti2_data[i] = PointTable_B_off4_data[i];
        i = 3 * k + 2;
        Ti2_data[i] = PointTable_B_off4_data[i];
      }
    } else if (XMFlag_data[k] == 1.0) {
      /* 斜面上 */
      /*  计算方向向量 */
      /*  将直线方程代入平面方程，求解参数 t */
      ab4 = PointTable_B_off4_data[3 * k];
      PP16_tmp = 3 * k + 1;
      ab3 = PointTable_B_off4_data[PP16_tmp];
      b_loop_ub = 3 * k + 2;
      zN5 = PointTable_B_off4_data[b_loop_ub];
      dir_vec_tmp = PlaneParaOut8_data[20];
      TiYuZhi3 = PlaneParaOut8_data[21];
      Tii = PlaneParaOut8_data[22];
      ab1 = -(((dir_vec_tmp * ab4 + TiYuZhi3 * ab3) + Tii * zN5) +
              PlaneParaOut8_data[23]) /
            ((dir_vec_tmp * dir_vec[0] + TiYuZhi3 * dir_vec[1]) +
             Tii * dir_vec[2]);
      /*  计算交点 */
      /*  输出交点 */
      Ti2_data[3 * k] = ab4 + ab1 * dir_vec[0];
      Ti2_data[PP16_tmp] = ab3 + ab1 * dir_vec[1];
      Ti2_data[b_loop_ub] = zN5 + ab1 * dir_vec[2];
    } else {
      Ti2_data[3 * k] = PointTable_B_off4_data[3 * k];
      i = 3 * k + 1;
      Ti2_data[i] = PointTable_B_off4_data[i];
      i = 3 * k + 2;
      Ti2_data[i] = PointTable_B_off4_data[i];
    }
  }
  emxFree_real_T(&PlaneParaOut8);
  emxFree_real_T(&PointTable_B_off4);
  emxFree_real_T(&XMFlag);
}

/*
 * File trailer for Calculate_rectangle_from_vertex8.c
 *
 * [EOF]
 */
