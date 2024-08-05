/*
 * File: Calculat_A_and_B_Points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 05-Aug-2024 16:15:51
 */

/* Include Files */
#include "Calculat_A_and_B_Points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
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
 *                emxArray_real_T *PointTable_A
 *                emxArray_real_T *PointTable_B
 * Return Type  : void
 */
void Calculat_A_and_B_Points(const double MTaon[3], const double Mcenter[3],
                             double Mradial,
                             const double Bottom_round_center1[3],
                             const double Bottom_round_center2[3],
                             const double testP[3], double numShengLu,
                             double phi, emxArray_real_T *PointTable_A,
                             emxArray_real_T *PointTable_B)
{
  emxArray_real_T *b;
  emxArray_real_T *b_C;
  emxArray_real_T *result;
  emxArray_real_T *varargin_2;
  double PointTable2DT_A_data[60];
  double b_PointTable2DT_A_data[60];
  double j_A2x[30];
  double i_A2x[27];
  double h_A2x[24];
  double g_A2x[21];
  double f_A2x[18];
  double P2D[15];
  double Prot[15];
  double e_A2x[15];
  double d_A2x[12];
  double b_b[9];
  double c_A2x[9];
  double rot1[9];
  double b_A2x[6];
  double r[4];
  double C[3];
  double D[3];
  double E[3];
  double b_c[3];
  double A10y;
  double A11x;
  double A1y;
  double A1z;
  double A2x;
  double A2y;
  double A3x;
  double A3y;
  double A4x;
  double A4y;
  double A5x;
  double A5y;
  double Ang1;
  double C_tmp;
  double K;
  double c;
  double dd;
  double norm_vec;
  double s;
  double xN1;
  double yN1;
  double zN1;
  double *C_data;
  double *PointTable_A_data;
  double *result_data;
  int PointTable2DT_A_size_idx_0;
  int boffset;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  计算45（phi）面的法向量D */
  c = 0.0 * MTaon[2] - MTaon[1];
  C[0] = c;
  s = MTaon[0] - 0.0 * MTaon[2];
  C[1] = s;
  C_tmp = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  C[2] = C_tmp;
  A1y = b_norm(C);
  norm_vec = tan(1.5707963267948966 - phi);
  A1z = c / A1y;
  C[0] = A1z;
  D[0] = MTaon[0] + norm_vec * A1z;
  A1z = s / A1y;
  C[1] = A1z;
  D[1] = MTaon[1] + norm_vec * A1z;
  A1z = C_tmp / A1y;
  D[2] = MTaon[2] + norm_vec * A1z;
  A1y = b_norm(D);
  D[0] /= A1y;
  D[1] /= A1y;
  D[2] /= A1y;
  b_c[0] = MTaon[1] * A1z - C[1] * MTaon[2];
  b_c[1] = C[0] * MTaon[2] - MTaon[0] * A1z;
  b_c[2] = MTaon[0] * C[1] - C[0] * MTaon[1];
  E[0] = b_c[1] * D[2] - D[1] * b_c[2];
  E[1] = D[0] * b_c[2] - b_c[0] * D[2];
  E[2] = b_c[0] * D[1] - D[0] * b_c[1];
  A1y = b_norm(E);
  /*  圆心点 */
  E[0] /= A1y;
  E[1] /= A1y;
  E[2] /= A1y;
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  A1y = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  A1z = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - testP[0]) * norm_vec + (Mcenter[1] - testP[1]) * A1y) +
        (Mcenter[2] - testP[2]) * A1z) /
      ((norm_vec * norm_vec + A1y * A1y) + A1z * A1z);
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * norm_vec + Mcenter[0];
  yN1 = K * A1y + Mcenter[1];
  zN1 = K * A1z + Mcenter[2];
  /*  面法向量第二个点（与圆心点构成45（phi）面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  b_c[0] = c;
  b_c[1] = s;
  b_c[2] = C_tmp;
  A1y = b_norm(b_c);
  C[0] = c;
  C[1] = s;
  C[2] = C_tmp;
  A1z = rt_atan2d_snf(b_norm(C), (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  r[0] = c / A1y;
  r[1] = s / A1y;
  r[2] = C_tmp / A1y;
  r[3] = A1z;
  s = sin(A1z);
  c = cos(A1z);
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
  A1y = norm_vec * C[1];
  A1z = s * C[2];
  rot1[3] = A1y - A1z;
  norm_vec *= C[2];
  K = s * C[1];
  rot1[6] = norm_vec + K;
  rot1[1] = A1y + A1z;
  A1y = (1.0 - c) * C[1];
  rot1[4] = A1y * C[1] + c;
  A1y *= C[2];
  A1z = s * C[0];
  rot1[7] = A1y - A1z;
  rot1[2] = norm_vec - K;
  rot1[5] = A1y + A1z;
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
  for (itilerow = 0; itilerow < 5; itilerow++) {
    A1y = Prot[3 * itilerow];
    A1z = Prot[3 * itilerow + 1];
    norm_vec = Prot[3 * itilerow + 2];
    for (ibmat = 0; ibmat < 3; ibmat++) {
      P2D[itilerow + 5 * ibmat] =
          (A1y * rot1[3 * ibmat] + A1z * rot1[3 * ibmat + 1]) +
          norm_vec * rot1[3 * ibmat + 2];
    }
  }
  /*  plotcylinder(P2D(3,:),P2D(4,:),'b',Mradial,0.2) */
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * 5;
    for (itilerow = 0; itilerow < 5; itilerow++) {
      Prot[ibmat + itilerow] = C[jcol];
    }
  }
  for (itilerow = 0; itilerow < 15; itilerow++) {
    Prot[itilerow] = P2D[itilerow] - Prot[itilerow];
  }
  /*  旋转、平移后 法向量 */
  C[0] = Prot[1] - Prot[0];
  C[1] = Prot[6] - Prot[5];
  C[2] = Prot[11] - Prot[10];
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  dd = -((C[0] * Prot[0] + C[1] * Prot[5]) + C[2] * Prot[10]);
  /*  起始角度 */
  Ang1 = atan(Prot[9] / Prot[4]);
  norm_vec = Mradial * cos(Ang1);
  A1y = Mradial * sin(Ang1);
  A1z = -((dd + C[0] * norm_vec) + C[1] * A1y) / C[2];
  jcol = 10;
  memset(&PointTable2DT_A_data[0], 0, 30U * sizeof(double));
  /*  根据声路数画出测点 */
  switch ((int)numShengLu) {
  case 1:
    jcol = 1;
    PointTable2DT_A_data[0] = norm_vec;
    PointTable2DT_A_data[1] = A1y;
    PointTable2DT_A_data[2] = A1z;
    break;
  case 2:
    A2x = Mradial * cos(Ang1 - 0.52359877559829882);
    A2y = Mradial * sin(Ang1 - 0.52359877559829882);
    A3x = Mradial * cos(Ang1 + 0.52359877559829882);
    A3y = Mradial * sin(Ang1 + 0.52359877559829882);
    b_A2x[0] = A2x;
    b_A2x[2] = A2y;
    b_A2x[4] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    b_A2x[1] = A3x;
    b_A2x[3] = A3y;
    b_A2x[5] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    jcol = 2;
    for (itilerow = 0; itilerow < 6; itilerow++) {
      PointTable2DT_A_data[itilerow] = b_A2x[itilerow];
    }
    break;
  case 3:
    A2x = Mradial * cos(Ang1 - 0.78539816339744828);
    A2y = Mradial * sin(Ang1 - 0.78539816339744828);
    A3x = Mradial * cos(Ang1 + 0.78539816339744828);
    A3y = Mradial * sin(Ang1 + 0.78539816339744828);
    c_A2x[0] = A2x;
    c_A2x[3] = A2y;
    c_A2x[6] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    c_A2x[1] = norm_vec;
    c_A2x[4] = A1y;
    c_A2x[7] = A1z;
    c_A2x[2] = A3x;
    c_A2x[5] = A3y;
    c_A2x[8] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    jcol = 3;
    memcpy(&PointTable2DT_A_data[0], &c_A2x[0], 9U * sizeof(double));
    break;
  case 4:
    A2x = Mradial * cos(Ang1 - 0.94247779607693793);
    A2y = Mradial * sin(Ang1 - 0.94247779607693793);
    A3x = Mradial * cos(Ang1 - 0.31415926535897931);
    A3y = Mradial * sin(Ang1 - 0.31415926535897931);
    A4x = Mradial * cos(Ang1 + 0.31415926535897931);
    A4y = Mradial * sin(Ang1 + 0.31415926535897931);
    A5x = Mradial * cos(Ang1 + 0.94247779607693793);
    A5y = Mradial * sin(Ang1 + 0.94247779607693793);
    d_A2x[0] = A2x;
    d_A2x[4] = A2y;
    d_A2x[8] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    d_A2x[1] = A3x;
    d_A2x[5] = A3y;
    d_A2x[9] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    d_A2x[2] = A4x;
    d_A2x[6] = A4y;
    d_A2x[10] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    d_A2x[3] = A5x;
    d_A2x[7] = A5y;
    d_A2x[11] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    jcol = 4;
    memcpy(&PointTable2DT_A_data[0], &d_A2x[0], 12U * sizeof(double));
    break;
  case 5:
    A2x = Mradial * cos(Ang1 - 1.0471975511965976);
    A2y = Mradial * sin(Ang1 - 1.0471975511965976);
    A3x = Mradial * cos(Ang1 - 0.52359877559829882);
    A3y = Mradial * sin(Ang1 - 0.52359877559829882);
    A4x = Mradial * cos(Ang1 + 0.52359877559829882);
    A4y = Mradial * sin(Ang1 + 0.52359877559829882);
    A5x = Mradial * cos(Ang1 + 1.0471975511965976);
    A5y = Mradial * sin(Ang1 + 1.0471975511965976);
    e_A2x[0] = A2x;
    e_A2x[5] = A2y;
    e_A2x[10] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    e_A2x[1] = A3x;
    e_A2x[6] = A3y;
    e_A2x[11] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    e_A2x[2] = norm_vec;
    e_A2x[7] = A1y;
    e_A2x[12] = A1z;
    e_A2x[3] = A4x;
    e_A2x[8] = A4y;
    e_A2x[13] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    e_A2x[4] = A5x;
    e_A2x[9] = A5y;
    e_A2x[14] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    jcol = 5;
    memcpy(&PointTable2DT_A_data[0], &e_A2x[0], 15U * sizeof(double));
    break;
  case 6:
    A2x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.44879895051282759);
    A2y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.44879895051282759);
    A3x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.89759790102565518);
    A3y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.89759790102565518);
    A4x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.3463968515384828);
    A4y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.3463968515384828);
    A5x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.7951958020513104);
    A5y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.7951958020513104);
    K = Mradial * cos((Ang1 - 1.5707963267948966) + 2.2439947525641379);
    c = Mradial * sin((Ang1 - 1.5707963267948966) + 2.2439947525641379);
    s = Mradial * cos((Ang1 - 1.5707963267948966) + 2.6927937030769655);
    C_tmp = Mradial * sin((Ang1 - 1.5707963267948966) + 2.6927937030769655);
    f_A2x[0] = A2x;
    f_A2x[6] = A2y;
    f_A2x[12] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    f_A2x[1] = A3x;
    f_A2x[7] = A3y;
    f_A2x[13] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    f_A2x[2] = A4x;
    f_A2x[8] = A4y;
    f_A2x[14] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    f_A2x[3] = A5x;
    f_A2x[9] = A5y;
    f_A2x[15] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    f_A2x[4] = K;
    f_A2x[10] = c;
    f_A2x[16] = -((dd + C[0] * K) + C[1] * c) / C[2];
    f_A2x[5] = s;
    f_A2x[11] = C_tmp;
    f_A2x[17] = -((dd + C[0] * s) + C[1] * C_tmp) / C[2];
    jcol = 6;
    memcpy(&PointTable2DT_A_data[0], &f_A2x[0], 18U * sizeof(double));
    break;
  case 7:
    A2x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.39269908169872414);
    A2y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.39269908169872414);
    A3x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.78539816339744828);
    A3y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.78539816339744828);
    A4x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.1780972450961724);
    A4y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.1780972450961724);
    A5x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.5707963267948966);
    A5y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.5707963267948966);
    K = Mradial * cos((Ang1 - 1.5707963267948966) + 1.9634954084936207);
    c = Mradial * sin((Ang1 - 1.5707963267948966) + 1.9634954084936207);
    s = Mradial * cos((Ang1 - 1.5707963267948966) + 2.3561944901923448);
    C_tmp = Mradial * sin((Ang1 - 1.5707963267948966) + 2.3561944901923448);
    A1y = Mradial * cos((Ang1 - 1.5707963267948966) + 2.748893571891069);
    A1z = Mradial * sin((Ang1 - 1.5707963267948966) + 2.748893571891069);
    g_A2x[0] = A2x;
    g_A2x[7] = A2y;
    g_A2x[14] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    g_A2x[1] = A3x;
    g_A2x[8] = A3y;
    g_A2x[15] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    g_A2x[2] = A4x;
    g_A2x[9] = A4y;
    g_A2x[16] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    g_A2x[3] = A5x;
    g_A2x[10] = A5y;
    g_A2x[17] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    g_A2x[4] = K;
    g_A2x[11] = c;
    g_A2x[18] = -((dd + C[0] * K) + C[1] * c) / C[2];
    g_A2x[5] = s;
    g_A2x[12] = C_tmp;
    g_A2x[19] = -((dd + C[0] * s) + C[1] * C_tmp) / C[2];
    g_A2x[6] = A1y;
    g_A2x[13] = A1z;
    g_A2x[20] = -((dd + C[0] * A1y) + C[1] * A1z) / C[2];
    jcol = 7;
    memcpy(&PointTable2DT_A_data[0], &g_A2x[0], 21U * sizeof(double));
    break;
  case 8:
    A2x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.3490658503988659);
    A2y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.3490658503988659);
    A3x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.69813170079773179);
    A3y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.69813170079773179);
    A4x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.0471975511965976);
    A4y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.0471975511965976);
    A5x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.3962634015954636);
    A5y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.3962634015954636);
    K = Mradial * cos((Ang1 - 1.5707963267948966) + 1.7453292519943295);
    c = Mradial * sin((Ang1 - 1.5707963267948966) + 1.7453292519943295);
    s = Mradial * cos((Ang1 - 1.5707963267948966) + 2.0943951023931953);
    C_tmp = Mradial * sin((Ang1 - 1.5707963267948966) + 2.0943951023931953);
    A1y = Mradial * cos((Ang1 - 1.5707963267948966) + 2.4434609527920612);
    A1z = Mradial * sin((Ang1 - 1.5707963267948966) + 2.4434609527920612);
    zN1 = Mradial * cos((Ang1 - 1.5707963267948966) + 2.7925268031909272);
    yN1 = Mradial * sin((Ang1 - 1.5707963267948966) + 2.7925268031909272);
    h_A2x[0] = A2x;
    h_A2x[8] = A2y;
    h_A2x[16] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    h_A2x[1] = A3x;
    h_A2x[9] = A3y;
    h_A2x[17] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    h_A2x[2] = A4x;
    h_A2x[10] = A4y;
    h_A2x[18] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    h_A2x[3] = A5x;
    h_A2x[11] = A5y;
    h_A2x[19] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    h_A2x[4] = K;
    h_A2x[12] = c;
    h_A2x[20] = -((dd + C[0] * K) + C[1] * c) / C[2];
    h_A2x[5] = s;
    h_A2x[13] = C_tmp;
    h_A2x[21] = -((dd + C[0] * s) + C[1] * C_tmp) / C[2];
    h_A2x[6] = A1y;
    h_A2x[14] = A1z;
    h_A2x[22] = -((dd + C[0] * A1y) + C[1] * A1z) / C[2];
    h_A2x[7] = zN1;
    h_A2x[15] = yN1;
    h_A2x[23] = -((dd + C[0] * zN1) + C[1] * yN1) / C[2];
    jcol = 8;
    memcpy(&PointTable2DT_A_data[0], &h_A2x[0], 24U * sizeof(double));
    break;
  case 9:
    A2x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.31415926535897931);
    A2y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.31415926535897931);
    A3x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.62831853071795862);
    A3y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.62831853071795862);
    A4x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.94247779607693793);
    A4y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.94247779607693793);
    A5x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.2566370614359172);
    A5y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.2566370614359172);
    K = Mradial * cos((Ang1 - 1.5707963267948966) + 1.5707963267948966);
    c = Mradial * sin((Ang1 - 1.5707963267948966) + 1.5707963267948966);
    s = Mradial * cos((Ang1 - 1.5707963267948966) + 1.8849555921538759);
    C_tmp = Mradial * sin((Ang1 - 1.5707963267948966) + 1.8849555921538759);
    A1y = Mradial * cos((Ang1 - 1.5707963267948966) + 2.1991148575128552);
    A1z = Mradial * sin((Ang1 - 1.5707963267948966) + 2.1991148575128552);
    zN1 = Mradial * cos((Ang1 - 1.5707963267948966) + 2.5132741228718345);
    yN1 = Mradial * sin((Ang1 - 1.5707963267948966) + 2.5132741228718345);
    xN1 = Mradial * cos((Ang1 - 1.5707963267948966) + 2.8274333882308138);
    A10y = Mradial * sin((Ang1 - 1.5707963267948966) + 2.8274333882308138);
    i_A2x[0] = A2x;
    i_A2x[9] = A2y;
    i_A2x[18] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    i_A2x[1] = A3x;
    i_A2x[10] = A3y;
    i_A2x[19] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    i_A2x[2] = A4x;
    i_A2x[11] = A4y;
    i_A2x[20] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    i_A2x[3] = A5x;
    i_A2x[12] = A5y;
    i_A2x[21] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    i_A2x[4] = K;
    i_A2x[13] = c;
    i_A2x[22] = -((dd + C[0] * K) + C[1] * c) / C[2];
    i_A2x[5] = s;
    i_A2x[14] = C_tmp;
    i_A2x[23] = -((dd + C[0] * s) + C[1] * C_tmp) / C[2];
    i_A2x[6] = A1y;
    i_A2x[15] = A1z;
    i_A2x[24] = -((dd + C[0] * A1y) + C[1] * A1z) / C[2];
    i_A2x[7] = zN1;
    i_A2x[16] = yN1;
    i_A2x[25] = -((dd + C[0] * zN1) + C[1] * yN1) / C[2];
    i_A2x[8] = xN1;
    i_A2x[17] = A10y;
    i_A2x[26] = -((dd + C[0] * xN1) + C[1] * A10y) / C[2];
    jcol = 9;
    memcpy(&PointTable2DT_A_data[0], &i_A2x[0], 27U * sizeof(double));
    break;
  case 10:
    A2x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.28559933214452665);
    A2y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.28559933214452665);
    A3x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.5711986642890533);
    A3y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.5711986642890533);
    A4x = Mradial * cos((Ang1 - 1.5707963267948966) + 0.8567979964335799);
    A4y = Mradial * sin((Ang1 - 1.5707963267948966) + 0.8567979964335799);
    A5x = Mradial * cos((Ang1 - 1.5707963267948966) + 1.1423973285781066);
    A5y = Mradial * sin((Ang1 - 1.5707963267948966) + 1.1423973285781066);
    K = Mradial * cos((Ang1 - 1.5707963267948966) + 1.4279966607226333);
    c = Mradial * sin((Ang1 - 1.5707963267948966) + 1.4279966607226333);
    s = Mradial * cos((Ang1 - 1.5707963267948966) + 1.7135959928671598);
    C_tmp = Mradial * sin((Ang1 - 1.5707963267948966) + 1.7135959928671598);
    A1y = Mradial * cos((Ang1 - 1.5707963267948966) + 1.9991953250116865);
    A1z = Mradial * sin((Ang1 - 1.5707963267948966) + 1.9991953250116865);
    zN1 = Mradial * cos((Ang1 - 1.5707963267948966) + 2.2847946571562132);
    yN1 = Mradial * sin((Ang1 - 1.5707963267948966) + 2.2847946571562132);
    xN1 = Mradial * cos((Ang1 - 1.5707963267948966) + 2.5703939893007397);
    A10y = Mradial * sin((Ang1 - 1.5707963267948966) + 2.5703939893007397);
    A11x = Mradial * cos((Ang1 - 1.5707963267948966) + 2.8559933214452666);
    norm_vec = Mradial * sin((Ang1 - 1.5707963267948966) + 2.8559933214452666);
    j_A2x[0] = A2x;
    j_A2x[10] = A2y;
    j_A2x[20] = -((dd + C[0] * A2x) + C[1] * A2y) / C[2];
    j_A2x[1] = A3x;
    j_A2x[11] = A3y;
    j_A2x[21] = -((dd + C[0] * A3x) + C[1] * A3y) / C[2];
    j_A2x[2] = A4x;
    j_A2x[12] = A4y;
    j_A2x[22] = -((dd + C[0] * A4x) + C[1] * A4y) / C[2];
    j_A2x[3] = A5x;
    j_A2x[13] = A5y;
    j_A2x[23] = -((dd + C[0] * A5x) + C[1] * A5y) / C[2];
    j_A2x[4] = K;
    j_A2x[14] = c;
    j_A2x[24] = -((dd + C[0] * K) + C[1] * c) / C[2];
    j_A2x[5] = s;
    j_A2x[15] = C_tmp;
    j_A2x[25] = -((dd + C[0] * s) + C[1] * C_tmp) / C[2];
    j_A2x[6] = A1y;
    j_A2x[16] = A1z;
    j_A2x[26] = -((dd + C[0] * A1y) + C[1] * A1z) / C[2];
    j_A2x[7] = zN1;
    j_A2x[17] = yN1;
    j_A2x[27] = -((dd + C[0] * zN1) + C[1] * yN1) / C[2];
    j_A2x[8] = xN1;
    j_A2x[18] = A10y;
    j_A2x[28] = -((dd + C[0] * xN1) + C[1] * A10y) / C[2];
    j_A2x[9] = A11x;
    j_A2x[19] = norm_vec;
    j_A2x[29] = -((dd + C[0] * A11x) + C[1] * norm_vec) / C[2];
    memcpy(&PointTable2DT_A_data[0], &j_A2x[0], 30U * sizeof(double));
    break;
  }
  /* 计算2D A面测点 */
  A1y = 2.0 * Prot[0];
  boffset = jcol - 1;
  A1z = 2.0 * Prot[5];
  norm_vec = 2.0 * Prot[10];
  PointTable2DT_A_size_idx_0 = jcol + jcol;
  for (itilerow = 0; itilerow < 3; itilerow++) {
    for (ibmat = 0; ibmat < jcol; ibmat++) {
      b_PointTable2DT_A_data[ibmat + PointTable2DT_A_size_idx_0 * itilerow] =
          PointTable2DT_A_data[ibmat + jcol * itilerow];
    }
  }
  for (itilerow = 0; itilerow <= boffset; itilerow++) {
    b_PointTable2DT_A_data[itilerow + jcol] =
        A1y - PointTable2DT_A_data[itilerow];
  }
  for (itilerow = 0; itilerow <= boffset; itilerow++) {
    ibmat = itilerow + jcol;
    b_PointTable2DT_A_data[ibmat + PointTable2DT_A_size_idx_0] =
        A1z - PointTable2DT_A_data[ibmat];
  }
  for (itilerow = 0; itilerow <= boffset; itilerow++) {
    b_PointTable2DT_A_data[(itilerow + jcol) + PointTable2DT_A_size_idx_0 * 2] =
        norm_vec - PointTable2DT_A_data[itilerow + jcol * 2];
  }
  ibmat = PointTable2DT_A_size_idx_0 * 3;
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         ibmat * sizeof(double));
  emxInit_real_T(&varargin_2, 1);
  itilerow = varargin_2->size[0];
  varargin_2->size[0] = PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(varargin_2, itilerow);
  PointTable_A_data = varargin_2->data;
  for (itilerow = 0; itilerow < PointTable2DT_A_size_idx_0; itilerow++) {
    PointTable_A_data[itilerow] = -PointTable2DT_A_data[itilerow];
  }
  emxInit_real_T(&result, 2);
  itilerow = result->size[0] * result->size[1];
  result->size[0] = PointTable2DT_A_size_idx_0;
  result->size[1] = 3;
  emxEnsureCapacity_real_T(result, itilerow);
  result_data = result->data;
  for (itilerow = 0; itilerow < PointTable2DT_A_size_idx_0; itilerow++) {
    result_data[itilerow] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0];
  }
  ibmat = varargin_2->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    result_data[itilerow + result->size[0]] = PointTable_A_data[itilerow];
  }
  for (itilerow = 0; itilerow < PointTable2DT_A_size_idx_0; itilerow++) {
    result_data[itilerow + result->size[0] * 2] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0 * 2];
  }
  ibmat = PointTable2DT_A_size_idx_0 - 1;
  boffset = PointTable2DT_A_size_idx_0 - 1;
  for (itilerow = 0; itilerow <= ibmat; itilerow++) {
    b_PointTable2DT_A_data[itilerow] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0];
  }
  ibmat = varargin_2->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    b_PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0] =
        PointTable_A_data[itilerow];
  }
  emxFree_real_T(&varargin_2);
  for (itilerow = 0; itilerow <= boffset; itilerow++) {
    b_PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0 * 2] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0 * 2];
  }
  ibmat = PointTable2DT_A_size_idx_0 * 3;
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         ibmat * sizeof(double));
  emxInit_real_T(&b, 2);
  /* 计算2D B面测点 */
  /* 2D AB面测点 转3D */
  pinv(rot1, c_A2x);
  pinv(rot1, b_b);
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_A_size_idx_0;
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  PointTable_A_data = b->data;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * PointTable2DT_A_size_idx_0;
    for (itilerow = 0; itilerow < PointTable2DT_A_size_idx_0; itilerow++) {
      PointTable_A_data[ibmat + itilerow] = C[jcol];
    }
  }
  ibmat = result->size[0] * 3;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = result->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  PointTable_A_data = b->data;
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    PointTable_A_data[itilerow] += result_data[itilerow];
  }
  emxInit_real_T(&b_C, 2);
  jcol = b->size[0];
  itilerow = b_C->size[0] * b_C->size[1];
  b_C->size[0] = b->size[0];
  b_C->size[1] = 3;
  emxEnsureCapacity_real_T(b_C, itilerow);
  C_data = b_C->data;
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * jcol;
    boffset = itilerow * 3;
    for (i = 0; i < jcol; i++) {
      C_data[ibmat + i] =
          (PointTable_A_data[i] * c_A2x[boffset] +
           PointTable_A_data[b->size[0] + i] * c_A2x[boffset + 1]) +
          PointTable_A_data[(b->size[0] << 1) + i] * c_A2x[boffset + 2];
    }
  }
  itilerow = PointTable_A->size[0] * PointTable_A->size[1];
  PointTable_A->size[0] = 3;
  PointTable_A->size[1] = b_C->size[0];
  emxEnsureCapacity_real_T(PointTable_A, itilerow);
  PointTable_A_data = PointTable_A->data;
  ibmat = b_C->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    PointTable_A_data[3 * itilerow] = C_data[itilerow];
    PointTable_A_data[3 * itilerow + 1] = C_data[itilerow + b_C->size[0]];
    PointTable_A_data[3 * itilerow + 2] = C_data[itilerow + b_C->size[0] * 2];
  }
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = result->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  PointTable_A_data = b->data;
  boffset = result->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * boffset;
    for (itilerow = 0; itilerow < boffset; itilerow++) {
      PointTable_A_data[ibmat + itilerow] = C[jcol];
    }
  }
  ibmat = result->size[0];
  memcpy(&b_PointTable2DT_A_data[0], &PointTable2DT_A_data[0],
         PointTable2DT_A_size_idx_0 * sizeof(double));
  for (itilerow = 0; itilerow < PointTable2DT_A_size_idx_0; itilerow++) {
    b_PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0];
  }
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    b_PointTable2DT_A_data[itilerow + PointTable2DT_A_size_idx_0 * 2] =
        norm_vec - result_data[itilerow + result->size[0] * 2];
  }
  itilerow = result->size[0] * result->size[1];
  result->size[0] = PointTable2DT_A_size_idx_0;
  result->size[1] = 3;
  emxEnsureCapacity_real_T(result, itilerow);
  result_data = result->data;
  ibmat = PointTable2DT_A_size_idx_0 * 3;
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    result_data[itilerow] =
        b_PointTable2DT_A_data[itilerow] + PointTable_A_data[itilerow];
  }
  emxFree_real_T(&b);
  jcol = result->size[0];
  itilerow = b_C->size[0] * b_C->size[1];
  b_C->size[0] = result->size[0];
  b_C->size[1] = 3;
  emxEnsureCapacity_real_T(b_C, itilerow);
  C_data = b_C->data;
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * jcol;
    boffset = itilerow * 3;
    for (i = 0; i < jcol; i++) {
      C_data[ibmat + i] =
          (result_data[i] * b_b[boffset] +
           result_data[result->size[0] + i] * b_b[boffset + 1]) +
          result_data[(result->size[0] << 1) + i] * b_b[boffset + 2];
    }
  }
  emxFree_real_T(&result);
  itilerow = PointTable_B->size[0] * PointTable_B->size[1];
  PointTable_B->size[0] = 3;
  PointTable_B->size[1] = b_C->size[0];
  emxEnsureCapacity_real_T(PointTable_B, itilerow);
  PointTable_A_data = PointTable_B->data;
  ibmat = b_C->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    PointTable_A_data[3 * itilerow] = C_data[itilerow];
    PointTable_A_data[3 * itilerow + 1] = C_data[itilerow + b_C->size[0]];
    PointTable_A_data[3 * itilerow + 2] = C_data[itilerow + b_C->size[0] * 2];
  }
  emxFree_real_T(&b_C);
}

/*
 * File trailer for Calculat_A_and_B_Points.c
 *
 * [EOF]
 */
