/*
 * File: Calculat_A_and_B_Points_after_Offest.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 17-May-2024 11:16:59
 */

/* Include Files */
#include "Calculat_A_and_B_Points_after_Offest.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "angle2point.h"
#include "norm.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double MTaon[3]
 *                const double Mcenter[3]
 *                double Mradial
 *                const double Bottom_round_center1[3]
 *                const double Bottom_round_center2[3]
 *                const double testP[3]
 *                double numShengLu
 *                double phi
 *                double toff
 *                double roff
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest(
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double Bottom_round_center1[3], const double Bottom_round_center2[3],
    const double testP[3], double numShengLu, double phi, double toff,
    double roff, emxArray_real_T *PointTable_A_off,
    emxArray_real_T *PointTable_B_off)
{
  double PointTable2DT_A_data[60];
  double b_PointTable2DT_A_data[60];
  double b_data[60];
  double h_PointTable2DT_A[30];
  double m_PointTable2DT_A[27];
  double f_PointTable2DT_A[24];
  double k_PointTable2DT_A[21];
  double d_PointTable2DT_A[18];
  double P2D[15];
  double Prot[15];
  double j_PointTable2DT_A[15];
  double b_PointTable2DT_A[12];
  double rot1[9];
  double rotz1[9];
  double rotz2[9];
  double r[4];
  double C[3];
  double D[3];
  double E[3];
  double b_c[3];
  double A10x;
  double A10y;
  double A10z;
  double A11x;
  double A11y;
  double A11z;
  double A1z;
  double A2x;
  double A2y;
  double A2z;
  double A3x;
  double A3y;
  double A3z;
  double A4x;
  double A4y;
  double A4z;
  double A5x;
  double A5y;
  double A5z;
  double A8x;
  double A8y;
  double Ang1;
  double K;
  double a_tmp;
  double c;
  double dd;
  double deltAngP;
  double norm_vec;
  double s;
  double xN1;
  double yN1;
  double zN1;
  double *PointTable_A_off_data;
  int PointTable2DT_A_size_idx_0;
  int b_PointTable2DT_A_size_idx_0;
  int b_i;
  int boffset;
  int i;
  int ibmat;
  int itilerow;
  /*  计算45（phi）面的法向量D */
  c = 0.0 * MTaon[2] - MTaon[1];
  C[0] = c;
  s = MTaon[0] - 0.0 * MTaon[2];
  C[1] = s;
  A1z = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  C[2] = A1z;
  A8x = b_norm(C);
  norm_vec = tan(1.5707963267948966 - phi);
  A8y = c / A8x;
  C[0] = A8y;
  D[0] = MTaon[0] + norm_vec * A8y;
  A8y = s / A8x;
  C[1] = A8y;
  D[1] = MTaon[1] + norm_vec * A8y;
  A8y = A1z / A8x;
  D[2] = MTaon[2] + norm_vec * A8y;
  A8x = b_norm(D);
  D[0] /= A8x;
  D[1] /= A8x;
  D[2] /= A8x;
  b_c[0] = MTaon[1] * A8y - C[1] * MTaon[2];
  b_c[1] = C[0] * MTaon[2] - MTaon[0] * A8y;
  b_c[2] = MTaon[0] * C[1] - C[0] * MTaon[1];
  E[0] = b_c[1] * D[2] - D[1] * b_c[2];
  E[1] = D[0] * b_c[2] - b_c[0] * D[2];
  E[2] = b_c[0] * D[1] - D[0] * b_c[1];
  A8x = b_norm(E);
  /*  圆心点 */
  E[0] /= A8x;
  E[1] /= A8x;
  E[2] /= A8x;
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  deltAngP = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  a_tmp = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - testP[0]) * norm_vec +
         (Mcenter[1] - testP[1]) * deltAngP) +
        (Mcenter[2] - testP[2]) * a_tmp) /
      ((norm_vec * norm_vec + deltAngP * deltAngP) + a_tmp * a_tmp);
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * norm_vec + Mcenter[0];
  yN1 = K * deltAngP + Mcenter[1];
  zN1 = K * a_tmp + Mcenter[2];
  /*  面法向量第二个点（与圆心点构成45（phi）面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  b_c[0] = c;
  b_c[1] = s;
  b_c[2] = A1z;
  A8x = b_norm(b_c);
  C[0] = c;
  C[1] = s;
  C[2] = A1z;
  A8y = rt_atan2d_snf(b_norm(C), (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  r[0] = c / A8x;
  r[1] = s / A8x;
  r[2] = A1z / A8x;
  r[3] = A8y;
  s = sin(A8y);
  c = cos(A8y);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  norm_vec = b_norm(*(double(*)[3]) & r[0]);
  if (norm_vec <= 1.0E-12) {
    C[0] = 0.0;
    C[1] = 0.0;
    C[2] = 0.0;
  } else {
    C[0] = r[0] / norm_vec;
    C[1] = r[1] / norm_vec;
    C[2] = r[2] / norm_vec;
  }
  norm_vec = (1.0 - c) * C[0];
  rot1[0] = norm_vec * C[0] + c;
  deltAngP = norm_vec * C[1];
  a_tmp = s * C[2];
  rot1[3] = deltAngP - a_tmp;
  norm_vec *= C[2];
  K = s * C[1];
  rot1[6] = norm_vec + K;
  rot1[1] = deltAngP + a_tmp;
  deltAngP = (1.0 - c) * C[1];
  rot1[4] = deltAngP * C[1] + c;
  deltAngP *= C[2];
  a_tmp = s * C[0];
  rot1[7] = deltAngP - a_tmp;
  rot1[2] = norm_vec - K;
  rot1[5] = deltAngP + a_tmp;
  rot1[8] = (1.0 - c) * C[2] * C[2] + c;
  /*  选择旋转点集合 */
  Prot[0] = xN1;
  Prot[1] = yN1;
  Prot[2] = zN1;
  /*  圆心点 */
  Prot[3] = xN1 + D[0];
  Prot[4] = yN1 + D[1];
  Prot[5] = zN1 + D[2];
  /*  面法向量第二个点 */
  /*  圆底面点1 */
  Prot[6] = Bottom_round_center1[0];
  Prot[9] = Bottom_round_center2[0];
  Prot[7] = Bottom_round_center1[1];
  Prot[10] = Bottom_round_center2[1];
  Prot[8] = Bottom_round_center1[2];
  Prot[11] = Bottom_round_center2[2];
  /*  圆底面点2 */
  Prot[12] = xN1 + E[0];
  Prot[13] = yN1 + E[1];
  Prot[14] = zN1 + E[2];
  /*  起始点 （测点半圆的中点） */
  /*  旋转至【0，0，1】的点集合 */
  for (i = 0; i < 5; i++) {
    A8x = Prot[3 * i];
    A8y = Prot[3 * i + 1];
    norm_vec = Prot[3 * i + 2];
    for (b_i = 0; b_i < 3; b_i++) {
      P2D[i + 5 * b_i] = (A8x * rot1[3 * b_i] + A8y * rot1[3 * b_i + 1]) +
                         norm_vec * rot1[3 * b_i + 2];
    }
  }
  /*  plotcylinder(P2D(3,:),P2D(4,:),'b',Mradial,0.2) */
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (boffset = 0; boffset < 3; boffset++) {
    ibmat = boffset * 5;
    for (itilerow = 0; itilerow < 5; itilerow++) {
      Prot[ibmat + itilerow] = C[boffset];
    }
  }
  for (i = 0; i < 15; i++) {
    Prot[i] = P2D[i] - Prot[i];
  }
  /*  旋转、平移后 法向量 */
  C[0] = Prot[1] - Prot[0];
  C[1] = Prot[6] - Prot[5];
  C[2] = Prot[11] - Prot[10];
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  dd = -((C[0] * Prot[0] + C[1] * Prot[5]) + C[2] * Prot[10]);
  /*  起始角度 */
  Ang1 = atan(Prot[9] / Prot[4]);
  c = Mradial * cos(Ang1);
  s = Mradial * sin(Ang1);
  A1z = -((dd + C[0] * c) + C[1] * s) / C[2];
  /*  偏移角 */
  deltAngP = roff / Mradial;
  norm_vec = sin(deltAngP);
  a_tmp = cos(deltAngP);
  rotz1[0] = a_tmp;
  rotz1[3] = norm_vec;
  rotz1[6] = 0.0;
  rotz1[1] = -norm_vec;
  rotz1[4] = a_tmp;
  rotz1[7] = 0.0;
  K = sin(-deltAngP);
  norm_vec = cos(-deltAngP);
  rotz2[0] = norm_vec;
  rotz2[3] = K;
  rotz2[6] = 0.0;
  rotz2[1] = -K;
  rotz2[4] = norm_vec;
  rotz2[7] = 0.0;
  rotz1[2] = 0.0;
  rotz2[2] = 0.0;
  rotz1[5] = 0.0;
  rotz2[5] = 0.0;
  rotz1[8] = 1.0;
  rotz2[8] = 1.0;
  PointTable2DT_A_size_idx_0 = 10;
  memset(&PointTable2DT_A_data[0], 0, 30U * sizeof(double));
  /*  根据声路数画出测点 */
  switch ((int)numShengLu) {
  case 1:
    PointTable2DT_A_size_idx_0 = 1;
    PointTable2DT_A_data[0] = c;
    PointTable2DT_A_data[1] = s;
    PointTable2DT_A_data[2] = A1z;
    break;
  case 2: {
    double b_A2x[6];
    angle2point(Ang1 - 0.52359877559829882, C[0], C[1], C[2], dd, Mradial, &A2x,
                &A2y, &A2z);
    angle2point(Ang1 + 0.52359877559829882, C[0], C[1], C[2], dd, Mradial, &A3x,
                &A3y, &A3z);
    b_A2x[0] = A2x;
    b_A2x[2] = A2y;
    b_A2x[4] = A2z;
    b_A2x[1] = A3x;
    b_A2x[3] = A3y;
    b_A2x[5] = A3z;
    PointTable2DT_A_size_idx_0 = 2;
    for (i = 0; i < 6; i++) {
      PointTable2DT_A_data[i] = b_A2x[i];
    }
    for (i = 0; i < 3; i++) {
      b_i = 3 * i + 1;
      boffset = 3 * i + 2;
      ibmat = i << 1;
      b_A2x[ibmat] = (PointTable2DT_A_data[0] * rotz2[3 * i] +
                      PointTable2DT_A_data[2] * rotz2[b_i]) +
                     PointTable2DT_A_data[4] * rotz2[boffset];
      b_A2x[ibmat + 1] = (PointTable2DT_A_data[1] * rotz1[3 * i] +
                          PointTable2DT_A_data[3] * rotz1[b_i]) +
                         PointTable2DT_A_data[5] * rotz1[boffset];
    }
    for (i = 0; i < 6; i++) {
      PointTable2DT_A_data[i] = b_A2x[i];
    }
    A8x = PointTable2DT_A_data[4];
    if (PointTable2DT_A_data[4] > Prot[10]) {
      A8x = PointTable2DT_A_data[4] - toff;
      PointTable2DT_A_data[4] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[4] = A8x;
    }
    A8x = PointTable2DT_A_data[5];
    if (PointTable2DT_A_data[5] > Prot[10]) {
      A8x = PointTable2DT_A_data[5] - toff;
      PointTable2DT_A_data[5] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[5] = A8x;
    }
  } break;
  case 3: {
    double PointTable2DT_A[9];
    angle2point(Ang1 - 0.78539816339744828, C[0], C[1], C[2], dd, Mradial, &A2x,
                &A2y, &A2z);
    angle2point(Ang1 + 0.78539816339744828, C[0], C[1], C[2], dd, Mradial, &A3x,
                &A3y, &A3z);
    PointTable2DT_A[0] = A2x;
    PointTable2DT_A[3] = A2y;
    PointTable2DT_A[6] = A2z;
    PointTable2DT_A[1] = c;
    PointTable2DT_A[4] = s;
    PointTable2DT_A[7] = A1z;
    PointTable2DT_A[2] = A3x;
    PointTable2DT_A[5] = A3y;
    PointTable2DT_A[8] = A3z;
    for (i = 0; i < 3; i++) {
      b_i = 3 * i + 1;
      boffset = 3 * i + 2;
      rotz2[3 * i] =
          (A2x * rotz2[3 * i] + A2y * rotz2[b_i]) + A2z * rotz2[boffset];
      rotz2[b_i] = PointTable2DT_A[b_i];
      rotz2[boffset] =
          (A3x * rotz1[3 * i] + A3y * rotz1[b_i]) + A3z * rotz1[boffset];
    }
    PointTable2DT_A_size_idx_0 = 3;
    memcpy(&PointTable2DT_A_data[0], &rotz2[0], 9U * sizeof(double));
    A8x = PointTable2DT_A_data[6];
    if (PointTable2DT_A_data[6] > Prot[10]) {
      A8x = PointTable2DT_A_data[6] - toff;
      PointTable2DT_A_data[6] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[6] = A8x;
    }
    A8x = PointTable2DT_A_data[7];
    if (PointTable2DT_A_data[7] > Prot[10]) {
      A8x = PointTable2DT_A_data[7] - toff;
      PointTable2DT_A_data[7] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[7] = A8x;
    }
    A8x = PointTable2DT_A_data[8];
    if (PointTable2DT_A_data[8] > Prot[10]) {
      A8x = PointTable2DT_A_data[8] - toff;
      PointTable2DT_A_data[8] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[8] = A8x;
    }
  } break;
  case 4: {
    double b_A2x[6];
    double i_PointTable2DT_A[6];
    angle2point(Ang1 - 0.94247779607693793, C[0], C[1], C[2], dd, Mradial, &A2x,
                &A2y, &A2z);
    angle2point(Ang1 - 0.31415926535897931, C[0], C[1], C[2], dd, Mradial, &A3x,
                &A3y, &A3z);
    angle2point(Ang1 + 0.31415926535897931, C[0], C[1], C[2], dd, Mradial, &A4x,
                &A4y, &A4z);
    angle2point(Ang1 + 0.94247779607693793, C[0], C[1], C[2], dd, Mradial, &A5x,
                &A5y, &A5z);
    b_PointTable2DT_A[0] = A2x;
    b_PointTable2DT_A[4] = A2y;
    b_PointTable2DT_A[8] = A2z;
    b_PointTable2DT_A[1] = A3x;
    b_PointTable2DT_A[5] = A3y;
    b_PointTable2DT_A[9] = A3z;
    b_PointTable2DT_A[2] = A4x;
    b_PointTable2DT_A[6] = A4y;
    b_PointTable2DT_A[10] = A4z;
    b_PointTable2DT_A[3] = A5x;
    b_PointTable2DT_A[7] = A5y;
    b_PointTable2DT_A[11] = A5z;
    for (i = 0; i < 2; i++) {
      A8x = b_PointTable2DT_A[i + 2];
      A8y = b_PointTable2DT_A[i + 6];
      norm_vec = b_PointTable2DT_A[i + 10];
      deltAngP = b_PointTable2DT_A[i];
      a_tmp = b_PointTable2DT_A[i + 4];
      K = b_PointTable2DT_A[i + 8];
      for (b_i = 0; b_i < 3; b_i++) {
        boffset = 3 * b_i + 1;
        ibmat = 3 * b_i + 2;
        itilerow = i + (b_i << 1);
        i_PointTable2DT_A[itilerow] =
            (A8x * rotz1[3 * b_i] + A8y * rotz1[boffset]) +
            norm_vec * rotz1[ibmat];
        b_A2x[itilerow] = (deltAngP * rotz2[3 * b_i] + a_tmp * rotz2[boffset]) +
                          K * rotz2[ibmat];
      }
    }
    for (i = 0; i < 3; i++) {
      itilerow = i << 1;
      ibmat = i << 2;
      b_PointTable2DT_A[ibmat] = b_A2x[itilerow];
      b_PointTable2DT_A[ibmat + 2] = i_PointTable2DT_A[itilerow];
      b_PointTable2DT_A[ibmat + 1] = b_A2x[itilerow + 1];
      b_PointTable2DT_A[ibmat + 3] = i_PointTable2DT_A[itilerow + 1];
    }
    PointTable2DT_A_size_idx_0 = 4;
    memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A[0],
           12U * sizeof(double));
    A8x = PointTable2DT_A_data[8];
    if (PointTable2DT_A_data[8] > Prot[10]) {
      A8x = PointTable2DT_A_data[8] - toff;
      PointTable2DT_A_data[8] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[8] = A8x;
    }
    A8x = PointTable2DT_A_data[9];
    if (PointTable2DT_A_data[9] > Prot[10]) {
      A8x = PointTable2DT_A_data[9] - toff;
      PointTable2DT_A_data[9] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[9] = A8x;
    }
    A8x = PointTable2DT_A_data[10];
    if (PointTable2DT_A_data[10] > Prot[10]) {
      A8x = PointTable2DT_A_data[10] - toff;
      PointTable2DT_A_data[10] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[10] = A8x;
    }
    A8x = PointTable2DT_A_data[11];
    if (PointTable2DT_A_data[11] > Prot[10]) {
      A8x = PointTable2DT_A_data[11] - toff;
      PointTable2DT_A_data[11] = A8x;
    }
    if (A8x < Prot[10]) {
      A8x += toff;
      PointTable2DT_A_data[11] = A8x;
    }
  } break;
  case 5: {
    double c_PointTable2DT_A[15];
    double b_A2x[6];
    double i_PointTable2DT_A[6];
    angle2point(Ang1 - 1.0471975511965976, C[0], C[1], C[2], dd, Mradial, &A2x,
                &A2y, &A2z);
    angle2point(Ang1 - 0.52359877559829882, C[0], C[1], C[2], dd, Mradial, &A3x,
                &A3y, &A3z);
    angle2point(Ang1 + 0.52359877559829882, C[0], C[1], C[2], dd, Mradial, &A4x,
                &A4y, &A4z);
    angle2point(Ang1 + 1.0471975511965976, C[0], C[1], C[2], dd, Mradial, &A5x,
                &A5y, &A5z);
    c_PointTable2DT_A[0] = A2x;
    c_PointTable2DT_A[5] = A2y;
    c_PointTable2DT_A[10] = A2z;
    c_PointTable2DT_A[1] = A3x;
    c_PointTable2DT_A[6] = A3y;
    c_PointTable2DT_A[11] = A3z;
    c_PointTable2DT_A[2] = c;
    c_PointTable2DT_A[7] = s;
    c_PointTable2DT_A[12] = A1z;
    c_PointTable2DT_A[3] = A4x;
    c_PointTable2DT_A[8] = A4y;
    c_PointTable2DT_A[13] = A4z;
    c_PointTable2DT_A[4] = A5x;
    c_PointTable2DT_A[9] = A5y;
    c_PointTable2DT_A[14] = A5z;
    for (i = 0; i < 2; i++) {
      A8x = c_PointTable2DT_A[i + 3];
      A8y = c_PointTable2DT_A[i + 8];
      norm_vec = c_PointTable2DT_A[i + 13];
      deltAngP = c_PointTable2DT_A[i];
      a_tmp = c_PointTable2DT_A[i + 5];
      K = c_PointTable2DT_A[i + 10];
      for (b_i = 0; b_i < 3; b_i++) {
        boffset = 3 * b_i + 1;
        ibmat = 3 * b_i + 2;
        itilerow = i + (b_i << 1);
        i_PointTable2DT_A[itilerow] =
            (A8x * rotz1[3 * b_i] + A8y * rotz1[boffset]) +
            norm_vec * rotz1[ibmat];
        b_A2x[itilerow] = (deltAngP * rotz2[3 * b_i] + a_tmp * rotz2[boffset]) +
                          K * rotz2[ibmat];
      }
    }
    for (i = 0; i < 3; i++) {
      itilerow = 5 * i + 2;
      j_PointTable2DT_A[itilerow] = c_PointTable2DT_A[itilerow];
      itilerow = i << 1;
      j_PointTable2DT_A[5 * i] = b_A2x[itilerow];
      j_PointTable2DT_A[5 * i + 3] = i_PointTable2DT_A[itilerow];
      j_PointTable2DT_A[5 * i + 1] = b_A2x[itilerow + 1];
      j_PointTable2DT_A[5 * i + 4] = i_PointTable2DT_A[itilerow + 1];
    }
    PointTable2DT_A_size_idx_0 = 5;
    memcpy(&PointTable2DT_A_data[0], &j_PointTable2DT_A[0],
           15U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 5; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 10];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 10] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 10] = A8y;
      }
    }
  } break;
  case 6: {
    double PointTable2DT_A[9];
    angle2point((Ang1 - 1.5707963267948966) + 0.44879895051282759, C[0], C[1],
                C[2], dd, Mradial, &A2x, &A2y, &A2z);
    angle2point((Ang1 - 1.5707963267948966) + 0.89759790102565518, C[0], C[1],
                C[2], dd, Mradial, &A3x, &A3y, &A3z);
    angle2point((Ang1 - 1.5707963267948966) + 1.3463968515384828, C[0], C[1],
                C[2], dd, Mradial, &A4x, &A4y, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.7951958020513104, C[0], C[1],
                C[2], dd, Mradial, &A5x, &A5y, &A5z);
    angle2point((Ang1 - 1.5707963267948966) + 2.2439947525641379, C[0], C[1],
                C[2], dd, Mradial, &norm_vec, &a_tmp, &K);
    angle2point((Ang1 - 1.5707963267948966) + 2.6927937030769655, C[0], C[1],
                C[2], dd, Mradial, &deltAngP, &c, &s);
    d_PointTable2DT_A[0] = A2x;
    d_PointTable2DT_A[6] = A2y;
    d_PointTable2DT_A[12] = A2z;
    d_PointTable2DT_A[1] = A3x;
    d_PointTable2DT_A[7] = A3y;
    d_PointTable2DT_A[13] = A3z;
    d_PointTable2DT_A[2] = A4x;
    d_PointTable2DT_A[8] = A4y;
    d_PointTable2DT_A[14] = A4z;
    d_PointTable2DT_A[3] = A5x;
    d_PointTable2DT_A[9] = A5y;
    d_PointTable2DT_A[15] = A5z;
    d_PointTable2DT_A[4] = norm_vec;
    d_PointTable2DT_A[10] = a_tmp;
    d_PointTable2DT_A[16] = K;
    d_PointTable2DT_A[5] = deltAngP;
    d_PointTable2DT_A[11] = c;
    d_PointTable2DT_A[17] = s;
    for (i = 0; i < 3; i++) {
      A8x = d_PointTable2DT_A[i];
      A8y = d_PointTable2DT_A[i + 6];
      norm_vec = d_PointTable2DT_A[i + 12];
      for (b_i = 0; b_i < 3; b_i++) {
        PointTable2DT_A[i + 3 * b_i] =
            (A8x * rotz2[3 * b_i] + A8y * rotz2[3 * b_i + 1]) +
            norm_vec * rotz2[3 * b_i + 2];
      }
    }
    for (i = 0; i < 3; i++) {
      A8x = d_PointTable2DT_A[i + 3];
      A8y = d_PointTable2DT_A[i + 9];
      norm_vec = d_PointTable2DT_A[i + 15];
      for (b_i = 0; b_i < 3; b_i++) {
        rotz2[i + 3 * b_i] = (A8x * rotz1[3 * b_i] + A8y * rotz1[3 * b_i + 1]) +
                             norm_vec * rotz1[3 * b_i + 2];
      }
    }
    for (i = 0; i < 3; i++) {
      d_PointTable2DT_A[6 * i] = PointTable2DT_A[3 * i];
      d_PointTable2DT_A[6 * i + 3] = rotz2[3 * i];
      itilerow = 3 * i + 1;
      d_PointTable2DT_A[6 * i + 1] = PointTable2DT_A[itilerow];
      d_PointTable2DT_A[6 * i + 4] = rotz2[itilerow];
      itilerow = 3 * i + 2;
      d_PointTable2DT_A[6 * i + 2] = PointTable2DT_A[itilerow];
      d_PointTable2DT_A[6 * i + 5] = rotz2[itilerow];
    }
    PointTable2DT_A_size_idx_0 = 6;
    memcpy(&PointTable2DT_A_data[0], &d_PointTable2DT_A[0],
           18U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 6; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 12];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 12] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 12] = A8y;
      }
    }
  } break;
  case 7: {
    double e_PointTable2DT_A[21];
    double PointTable2DT_A[9];
    angle2point((Ang1 - 1.5707963267948966) + 0.39269908169872414, C[0], C[1],
                C[2], dd, Mradial, &A2x, &A2y, &A2z);
    angle2point((Ang1 - 1.5707963267948966) + 0.78539816339744828, C[0], C[1],
                C[2], dd, Mradial, &A3x, &A3y, &A3z);
    angle2point((Ang1 - 1.5707963267948966) + 1.1780972450961724, C[0], C[1],
                C[2], dd, Mradial, &A4x, &A4y, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], dd, Mradial, &A5x, &A5y, &A5z);
    angle2point((Ang1 - 1.5707963267948966) + 1.9634954084936207, C[0], C[1],
                C[2], dd, Mradial, &norm_vec, &a_tmp, &K);
    angle2point((Ang1 - 1.5707963267948966) + 2.3561944901923448, C[0], C[1],
                C[2], dd, Mradial, &deltAngP, &c, &s);
    angle2point((Ang1 - 1.5707963267948966) + 2.748893571891069, C[0], C[1],
                C[2], dd, Mradial, &A8x, &A8y, &zN1);
    e_PointTable2DT_A[0] = A2x;
    e_PointTable2DT_A[7] = A2y;
    e_PointTable2DT_A[14] = A2z;
    e_PointTable2DT_A[1] = A3x;
    e_PointTable2DT_A[8] = A3y;
    e_PointTable2DT_A[15] = A3z;
    e_PointTable2DT_A[2] = A4x;
    e_PointTable2DT_A[9] = A4y;
    e_PointTable2DT_A[16] = A4z;
    e_PointTable2DT_A[3] = A5x;
    e_PointTable2DT_A[10] = A5y;
    e_PointTable2DT_A[17] = A5z;
    e_PointTable2DT_A[4] = norm_vec;
    e_PointTable2DT_A[11] = a_tmp;
    e_PointTable2DT_A[18] = K;
    e_PointTable2DT_A[5] = deltAngP;
    e_PointTable2DT_A[12] = c;
    e_PointTable2DT_A[19] = s;
    e_PointTable2DT_A[6] = A8x;
    e_PointTable2DT_A[13] = A8y;
    e_PointTable2DT_A[20] = zN1;
    for (i = 0; i < 3; i++) {
      A8x = e_PointTable2DT_A[i];
      A8y = e_PointTable2DT_A[i + 7];
      norm_vec = e_PointTable2DT_A[i + 14];
      for (b_i = 0; b_i < 3; b_i++) {
        PointTable2DT_A[i + 3 * b_i] =
            (A8x * rotz2[3 * b_i] + A8y * rotz2[3 * b_i + 1]) +
            norm_vec * rotz2[3 * b_i + 2];
      }
    }
    for (i = 0; i < 3; i++) {
      A8x = e_PointTable2DT_A[i + 4];
      A8y = e_PointTable2DT_A[i + 11];
      norm_vec = e_PointTable2DT_A[i + 18];
      for (b_i = 0; b_i < 3; b_i++) {
        rotz2[i + 3 * b_i] = (A8x * rotz1[3 * b_i] + A8y * rotz1[3 * b_i + 1]) +
                             norm_vec * rotz1[3 * b_i + 2];
        k_PointTable2DT_A[b_i + 7 * i] = PointTable2DT_A[b_i + 3 * i];
      }
      itilerow = 7 * i + 3;
      k_PointTable2DT_A[itilerow] = e_PointTable2DT_A[itilerow];
    }
    for (i = 0; i < 3; i++) {
      k_PointTable2DT_A[7 * i + 4] = rotz2[3 * i];
      k_PointTable2DT_A[7 * i + 5] = rotz2[3 * i + 1];
      k_PointTable2DT_A[7 * i + 6] = rotz2[3 * i + 2];
    }
    PointTable2DT_A_size_idx_0 = 7;
    memcpy(&PointTable2DT_A_data[0], &k_PointTable2DT_A[0],
           21U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 7; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 14];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 14] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 14] = A8y;
      }
    }
  } break;
  case 8: {
    double l_PointTable2DT_A[12];
    angle2point((Ang1 - 1.5707963267948966) + 0.3490658503988659, C[0], C[1],
                C[2], dd, Mradial, &A2x, &A2y, &A2z);
    angle2point((Ang1 - 1.5707963267948966) + 0.69813170079773179, C[0], C[1],
                C[2], dd, Mradial, &A3x, &A3y, &A3z);
    angle2point((Ang1 - 1.5707963267948966) + 1.0471975511965976, C[0], C[1],
                C[2], dd, Mradial, &A4x, &A4y, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.3962634015954636, C[0], C[1],
                C[2], dd, Mradial, &A5x, &A5y, &A5z);
    angle2point((Ang1 - 1.5707963267948966) + 1.7453292519943295, C[0], C[1],
                C[2], dd, Mradial, &norm_vec, &a_tmp, &K);
    angle2point((Ang1 - 1.5707963267948966) + 2.0943951023931953, C[0], C[1],
                C[2], dd, Mradial, &deltAngP, &c, &s);
    angle2point((Ang1 - 1.5707963267948966) + 2.4434609527920612, C[0], C[1],
                C[2], dd, Mradial, &A8x, &A8y, &zN1);
    angle2point((Ang1 - 1.5707963267948966) + 2.7925268031909272, C[0], C[1],
                C[2], dd, Mradial, &yN1, &xN1, &A1z);
    f_PointTable2DT_A[0] = A2x;
    f_PointTable2DT_A[8] = A2y;
    f_PointTable2DT_A[16] = A2z;
    f_PointTable2DT_A[1] = A3x;
    f_PointTable2DT_A[9] = A3y;
    f_PointTable2DT_A[17] = A3z;
    f_PointTable2DT_A[2] = A4x;
    f_PointTable2DT_A[10] = A4y;
    f_PointTable2DT_A[18] = A4z;
    f_PointTable2DT_A[3] = A5x;
    f_PointTable2DT_A[11] = A5y;
    f_PointTable2DT_A[19] = A5z;
    f_PointTable2DT_A[4] = norm_vec;
    f_PointTable2DT_A[12] = a_tmp;
    f_PointTable2DT_A[20] = K;
    f_PointTable2DT_A[5] = deltAngP;
    f_PointTable2DT_A[13] = c;
    f_PointTable2DT_A[21] = s;
    f_PointTable2DT_A[6] = A8x;
    f_PointTable2DT_A[14] = A8y;
    f_PointTable2DT_A[22] = zN1;
    f_PointTable2DT_A[7] = yN1;
    f_PointTable2DT_A[15] = xN1;
    f_PointTable2DT_A[23] = A1z;
    for (i = 0; i < 4; i++) {
      A8x = f_PointTable2DT_A[i + 4];
      A8y = f_PointTable2DT_A[i + 12];
      norm_vec = f_PointTable2DT_A[i + 20];
      deltAngP = f_PointTable2DT_A[i];
      a_tmp = f_PointTable2DT_A[i + 8];
      K = f_PointTable2DT_A[i + 16];
      for (b_i = 0; b_i < 3; b_i++) {
        boffset = 3 * b_i + 1;
        ibmat = 3 * b_i + 2;
        itilerow = i + (b_i << 2);
        l_PointTable2DT_A[itilerow] =
            (A8x * rotz1[3 * b_i] + A8y * rotz1[boffset]) +
            norm_vec * rotz1[ibmat];
        b_PointTable2DT_A[itilerow] =
            (deltAngP * rotz2[3 * b_i] + a_tmp * rotz2[boffset]) +
            K * rotz2[ibmat];
      }
    }
    for (i = 0; i < 3; i++) {
      itilerow = i << 2;
      ibmat = i << 3;
      f_PointTable2DT_A[ibmat] = b_PointTable2DT_A[itilerow];
      f_PointTable2DT_A[ibmat + 4] = l_PointTable2DT_A[itilerow];
      f_PointTable2DT_A[ibmat + 1] = b_PointTable2DT_A[itilerow + 1];
      f_PointTable2DT_A[ibmat + 5] = l_PointTable2DT_A[itilerow + 1];
      f_PointTable2DT_A[ibmat + 2] = b_PointTable2DT_A[itilerow + 2];
      f_PointTable2DT_A[ibmat + 6] = l_PointTable2DT_A[itilerow + 2];
      f_PointTable2DT_A[ibmat + 3] = b_PointTable2DT_A[itilerow + 3];
      f_PointTable2DT_A[ibmat + 7] = l_PointTable2DT_A[itilerow + 3];
    }
    PointTable2DT_A_size_idx_0 = 8;
    memcpy(&PointTable2DT_A_data[0], &f_PointTable2DT_A[0],
           24U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 8; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 16];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 16] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 16] = A8y;
      }
    }
  } break;
  case 9: {
    double g_PointTable2DT_A[27];
    double l_PointTable2DT_A[12];
    angle2point((Ang1 - 1.5707963267948966) + 0.31415926535897931, C[0], C[1],
                C[2], dd, Mradial, &A2x, &A2y, &A2z);
    angle2point((Ang1 - 1.5707963267948966) + 0.62831853071795862, C[0], C[1],
                C[2], dd, Mradial, &A3x, &A3y, &A3z);
    angle2point((Ang1 - 1.5707963267948966) + 0.94247779607693793, C[0], C[1],
                C[2], dd, Mradial, &A4x, &A4y, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.2566370614359172, C[0], C[1],
                C[2], dd, Mradial, &A5x, &A5y, &A5z);
    angle2point((Ang1 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], dd, Mradial, &norm_vec, &a_tmp, &K);
    angle2point((Ang1 - 1.5707963267948966) + 1.8849555921538759, C[0], C[1],
                C[2], dd, Mradial, &deltAngP, &c, &s);
    angle2point((Ang1 - 1.5707963267948966) + 2.1991148575128552, C[0], C[1],
                C[2], dd, Mradial, &A8x, &A8y, &zN1);
    angle2point((Ang1 - 1.5707963267948966) + 2.5132741228718345, C[0], C[1],
                C[2], dd, Mradial, &yN1, &xN1, &A1z);
    angle2point((Ang1 - 1.5707963267948966) + 2.8274333882308138, C[0], C[1],
                C[2], dd, Mradial, &A10x, &A10y, &A10z);
    g_PointTable2DT_A[0] = A2x;
    g_PointTable2DT_A[9] = A2y;
    g_PointTable2DT_A[18] = A2z;
    g_PointTable2DT_A[1] = A3x;
    g_PointTable2DT_A[10] = A3y;
    g_PointTable2DT_A[19] = A3z;
    g_PointTable2DT_A[2] = A4x;
    g_PointTable2DT_A[11] = A4y;
    g_PointTable2DT_A[20] = A4z;
    g_PointTable2DT_A[3] = A5x;
    g_PointTable2DT_A[12] = A5y;
    g_PointTable2DT_A[21] = A5z;
    g_PointTable2DT_A[4] = norm_vec;
    g_PointTable2DT_A[13] = a_tmp;
    g_PointTable2DT_A[22] = K;
    g_PointTable2DT_A[5] = deltAngP;
    g_PointTable2DT_A[14] = c;
    g_PointTable2DT_A[23] = s;
    g_PointTable2DT_A[6] = A8x;
    g_PointTable2DT_A[15] = A8y;
    g_PointTable2DT_A[24] = zN1;
    g_PointTable2DT_A[7] = yN1;
    g_PointTable2DT_A[16] = xN1;
    g_PointTable2DT_A[25] = A1z;
    g_PointTable2DT_A[8] = A10x;
    g_PointTable2DT_A[17] = A10y;
    g_PointTable2DT_A[26] = A10z;
    for (i = 0; i < 4; i++) {
      A8x = g_PointTable2DT_A[i + 5];
      A8y = g_PointTable2DT_A[i + 14];
      norm_vec = g_PointTable2DT_A[i + 23];
      deltAngP = g_PointTable2DT_A[i];
      a_tmp = g_PointTable2DT_A[i + 9];
      K = g_PointTable2DT_A[i + 18];
      for (b_i = 0; b_i < 3; b_i++) {
        boffset = 3 * b_i + 1;
        ibmat = 3 * b_i + 2;
        itilerow = i + (b_i << 2);
        l_PointTable2DT_A[itilerow] =
            (A8x * rotz1[3 * b_i] + A8y * rotz1[boffset]) +
            norm_vec * rotz1[ibmat];
        b_PointTable2DT_A[itilerow] =
            (deltAngP * rotz2[3 * b_i] + a_tmp * rotz2[boffset]) +
            K * rotz2[ibmat];
      }
    }
    for (i = 0; i < 3; i++) {
      itilerow = 9 * i + 4;
      m_PointTable2DT_A[itilerow] = g_PointTable2DT_A[itilerow];
      itilerow = i << 2;
      m_PointTable2DT_A[9 * i] = b_PointTable2DT_A[itilerow];
      m_PointTable2DT_A[9 * i + 5] = l_PointTable2DT_A[itilerow];
      m_PointTable2DT_A[9 * i + 1] = b_PointTable2DT_A[itilerow + 1];
      m_PointTable2DT_A[9 * i + 6] = l_PointTable2DT_A[itilerow + 1];
      m_PointTable2DT_A[9 * i + 2] = b_PointTable2DT_A[itilerow + 2];
      m_PointTable2DT_A[9 * i + 7] = l_PointTable2DT_A[itilerow + 2];
      m_PointTable2DT_A[9 * i + 3] = b_PointTable2DT_A[itilerow + 3];
      m_PointTable2DT_A[9 * i + 8] = l_PointTable2DT_A[itilerow + 3];
    }
    PointTable2DT_A_size_idx_0 = 9;
    memcpy(&PointTable2DT_A_data[0], &m_PointTable2DT_A[0],
           27U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 9; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 18];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 18] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 18] = A8y;
      }
    }
  } break;
  case 10: {
    double c_PointTable2DT_A[15];
    angle2point((Ang1 - 1.5707963267948966) + 0.28559933214452665, C[0], C[1],
                C[2], dd, Mradial, &A2x, &A2y, &A2z);
    angle2point((Ang1 - 1.5707963267948966) + 0.5711986642890533, C[0], C[1],
                C[2], dd, Mradial, &A3x, &A3y, &A3z);
    angle2point((Ang1 - 1.5707963267948966) + 0.8567979964335799, C[0], C[1],
                C[2], dd, Mradial, &A4x, &A4y, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.1423973285781066, C[0], C[1],
                C[2], dd, Mradial, &A5x, &A5y, &A5z);
    angle2point((Ang1 - 1.5707963267948966) + 1.4279966607226333, C[0], C[1],
                C[2], dd, Mradial, &norm_vec, &a_tmp, &K);
    angle2point((Ang1 - 1.5707963267948966) + 1.7135959928671598, C[0], C[1],
                C[2], dd, Mradial, &deltAngP, &c, &s);
    angle2point((Ang1 - 1.5707963267948966) + 1.9991953250116865, C[0], C[1],
                C[2], dd, Mradial, &A8x, &A8y, &zN1);
    angle2point((Ang1 - 1.5707963267948966) + 2.2847946571562132, C[0], C[1],
                C[2], dd, Mradial, &yN1, &xN1, &A1z);
    angle2point((Ang1 - 1.5707963267948966) + 2.5703939893007397, C[0], C[1],
                C[2], dd, Mradial, &A10x, &A10y, &A10z);
    angle2point((Ang1 - 1.5707963267948966) + 2.8559933214452666, C[0], C[1],
                C[2], dd, Mradial, &A11x, &A11y, &A11z);
    h_PointTable2DT_A[0] = A2x;
    h_PointTable2DT_A[10] = A2y;
    h_PointTable2DT_A[20] = A2z;
    h_PointTable2DT_A[1] = A3x;
    h_PointTable2DT_A[11] = A3y;
    h_PointTable2DT_A[21] = A3z;
    h_PointTable2DT_A[2] = A4x;
    h_PointTable2DT_A[12] = A4y;
    h_PointTable2DT_A[22] = A4z;
    h_PointTable2DT_A[3] = A5x;
    h_PointTable2DT_A[13] = A5y;
    h_PointTable2DT_A[23] = A5z;
    h_PointTable2DT_A[4] = norm_vec;
    h_PointTable2DT_A[14] = a_tmp;
    h_PointTable2DT_A[24] = K;
    h_PointTable2DT_A[5] = deltAngP;
    h_PointTable2DT_A[15] = c;
    h_PointTable2DT_A[25] = s;
    h_PointTable2DT_A[6] = A8x;
    h_PointTable2DT_A[16] = A8y;
    h_PointTable2DT_A[26] = zN1;
    h_PointTable2DT_A[7] = yN1;
    h_PointTable2DT_A[17] = xN1;
    h_PointTable2DT_A[27] = A1z;
    h_PointTable2DT_A[8] = A10x;
    h_PointTable2DT_A[18] = A10y;
    h_PointTable2DT_A[28] = A10z;
    h_PointTable2DT_A[9] = A11x;
    h_PointTable2DT_A[19] = A11y;
    h_PointTable2DT_A[29] = A11z;
    for (i = 0; i < 5; i++) {
      A8x = h_PointTable2DT_A[i + 5];
      A8y = h_PointTable2DT_A[i + 15];
      norm_vec = h_PointTable2DT_A[i + 25];
      deltAngP = h_PointTable2DT_A[i];
      a_tmp = h_PointTable2DT_A[i + 10];
      K = h_PointTable2DT_A[i + 20];
      for (b_i = 0; b_i < 3; b_i++) {
        boffset = 3 * b_i + 1;
        ibmat = 3 * b_i + 2;
        itilerow = i + 5 * b_i;
        j_PointTable2DT_A[itilerow] =
            (A8x * rotz1[3 * b_i] + A8y * rotz1[boffset]) +
            norm_vec * rotz1[ibmat];
        c_PointTable2DT_A[itilerow] =
            (deltAngP * rotz2[3 * b_i] + a_tmp * rotz2[boffset]) +
            K * rotz2[ibmat];
      }
    }
    for (i = 0; i < 3; i++) {
      for (b_i = 0; b_i < 5; b_i++) {
        itilerow = b_i + 5 * i;
        ibmat = b_i + 10 * i;
        h_PointTable2DT_A[ibmat] = c_PointTable2DT_A[itilerow];
        h_PointTable2DT_A[ibmat + 5] = j_PointTable2DT_A[itilerow];
      }
    }
    memcpy(&PointTable2DT_A_data[0], &h_PointTable2DT_A[0],
           30U * sizeof(double));
    A8x = Prot[10];
    for (ibmat = 0; ibmat < 10; ibmat++) {
      A8y = PointTable2DT_A_data[ibmat + 20];
      if (A8y > A8x) {
        A8y -= toff;
        PointTable2DT_A_data[ibmat + 20] = A8y;
      }
      if (A8y < A8x) {
        A8y += toff;
        PointTable2DT_A_data[ibmat + 20] = A8y;
      }
    }
  } break;
  }
  /* 计算2D A面测点 */
  A8x = 2.0 * Prot[0];
  itilerow = PointTable2DT_A_size_idx_0 - 1;
  A8y = 2.0 * Prot[5];
  norm_vec = 2.0 * Prot[10];
  b_PointTable2DT_A_size_idx_0 =
      PointTable2DT_A_size_idx_0 + PointTable2DT_A_size_idx_0;
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < PointTable2DT_A_size_idx_0; b_i++) {
      b_PointTable2DT_A_data[b_i + b_PointTable2DT_A_size_idx_0 * i] =
          PointTable2DT_A_data[b_i + PointTable2DT_A_size_idx_0 * i];
    }
  }
  for (i = 0; i <= itilerow; i++) {
    b_PointTable2DT_A_data[i + PointTable2DT_A_size_idx_0] =
        A8x - PointTable2DT_A_data[i];
  }
  for (i = 0; i <= itilerow; i++) {
    ibmat = i + PointTable2DT_A_size_idx_0;
    b_PointTable2DT_A_data[ibmat + b_PointTable2DT_A_size_idx_0] =
        A8y - PointTable2DT_A_data[ibmat];
  }
  for (i = 0; i <= itilerow; i++) {
    b_PointTable2DT_A_data[(i + PointTable2DT_A_size_idx_0) +
                           b_PointTable2DT_A_size_idx_0 * 2] =
        norm_vec - PointTable2DT_A_data[i + PointTable2DT_A_size_idx_0 * 2];
  }
  ibmat = b_PointTable2DT_A_size_idx_0 * 3;
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         ibmat * sizeof(double));
  /* 计算2D B面测点 */
  /* 2D AB面测点 转3D */
  pinv(rot1, rotz1);
  pinv(rot1, rotz2);
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (boffset = 0; boffset < 3; boffset++) {
    ibmat = boffset * b_PointTable2DT_A_size_idx_0;
    for (itilerow = 0; itilerow < b_PointTable2DT_A_size_idx_0; itilerow++) {
      b_data[ibmat + itilerow] = C[boffset];
    }
  }
  ibmat = b_PointTable2DT_A_size_idx_0 * 3;
  for (i = 0; i < ibmat; i++) {
    b_data[i] += PointTable2DT_A_data[i];
  }
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * b_PointTable2DT_A_size_idx_0;
    boffset = itilerow * 3;
    for (b_i = 0; b_i < b_PointTable2DT_A_size_idx_0; b_i++) {
      b_PointTable2DT_A_data[ibmat + b_i] =
          (b_data[b_i] * rotz1[boffset] +
           b_data[b_PointTable2DT_A_size_idx_0 + b_i] * rotz1[boffset + 1]) +
          b_data[(b_PointTable2DT_A_size_idx_0 << 1) + b_i] *
              rotz1[boffset + 2];
    }
  }
  i = PointTable_A_off->size[0] * PointTable_A_off->size[1];
  PointTable_A_off->size[0] = 3;
  PointTable_A_off->size[1] = b_PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(PointTable_A_off, i);
  PointTable_A_off_data = PointTable_A_off->data;
  for (i = 0; i < b_PointTable2DT_A_size_idx_0; i++) {
    PointTable_A_off_data[3 * i] = b_PointTable2DT_A_data[i];
    PointTable_A_off_data[3 * i + 1] =
        b_PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0];
    PointTable_A_off_data[3 * i + 2] =
        b_PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0 * 2];
  }
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (boffset = 0; boffset < 3; boffset++) {
    ibmat = boffset * b_PointTable2DT_A_size_idx_0;
    for (itilerow = 0; itilerow < b_PointTable2DT_A_size_idx_0; itilerow++) {
      b_data[ibmat + itilerow] = C[boffset];
    }
  }
  memcpy(&b_PointTable2DT_A_data[0], &PointTable2DT_A_data[0],
         b_PointTable2DT_A_size_idx_0 * sizeof(double));
  memcpy(&b_PointTable2DT_A_data[b_PointTable2DT_A_size_idx_0],
         &PointTable2DT_A_data[b_PointTable2DT_A_size_idx_0],
         ((b_PointTable2DT_A_size_idx_0 + b_PointTable2DT_A_size_idx_0) -
          b_PointTable2DT_A_size_idx_0) *
             sizeof(double));
  for (i = 0; i < b_PointTable2DT_A_size_idx_0; i++) {
    b_PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0 * 2] =
        norm_vec - PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0 * 2];
  }
  ibmat = b_PointTable2DT_A_size_idx_0 * 3;
  for (i = 0; i < ibmat; i++) {
    PointTable2DT_A_data[i] = b_PointTable2DT_A_data[i] + b_data[i];
  }
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * b_PointTable2DT_A_size_idx_0;
    boffset = itilerow * 3;
    for (b_i = 0; b_i < b_PointTable2DT_A_size_idx_0; b_i++) {
      b_PointTable2DT_A_data[ibmat + b_i] =
          (PointTable2DT_A_data[b_i] * rotz2[boffset] +
           PointTable2DT_A_data[b_PointTable2DT_A_size_idx_0 + b_i] *
               rotz2[boffset + 1]) +
          PointTable2DT_A_data[(b_PointTable2DT_A_size_idx_0 << 1) + b_i] *
              rotz2[boffset + 2];
    }
  }
  i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = b_PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(PointTable_B_off, i);
  PointTable_A_off_data = PointTable_B_off->data;
  for (i = 0; i < b_PointTable2DT_A_size_idx_0; i++) {
    PointTable_A_off_data[3 * i] = b_PointTable2DT_A_data[i];
    PointTable_A_off_data[3 * i + 1] =
        b_PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0];
    PointTable_A_off_data[3 * i + 2] =
        b_PointTable2DT_A_data[i + b_PointTable2DT_A_size_idx_0 * 2];
  }
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest.c
 *
 * [EOF]
 */
