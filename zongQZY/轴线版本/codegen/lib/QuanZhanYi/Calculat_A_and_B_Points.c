/*
 * File: Calculat_A_and_B_Points.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 22:37:07
 */

/* Include Files */
#include "Calculat_A_and_B_Points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "angle2point.h"
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
  emxArray_real_T *result;
  emxArray_real_T *varargin_2;
  double PointTable2DT_A_data[60];
  double b_PointTable2DT_A_data[60];
  double b_data[60];
  double i_A2x[30];
  double h_A2x[27];
  double g_A2x[24];
  double f_A2x[21];
  double e_A2x[18];
  double P2D[15];
  double Prot[15];
  double d_A2x[15];
  double c_A2x[12];
  double b_A2x[9];
  double rot1[9];
  double A2x[6];
  double C[3];
  double A1x;
  double A1y;
  double A1z;
  double A3x;
  double A3y;
  double A3z;
  double A4x;
  double A4y;
  double A4z;
  double A5x;
  double A5y;
  double A5z;
  double A8z;
  double C_tmp;
  double D_idx_0;
  double D_idx_1;
  double D_idx_2;
  double E_idx_0;
  double E_idx_1;
  double E_idx_2;
  double K;
  double absxk;
  double absxk_tmp;
  double b_C_tmp;
  double b_absxk_tmp;
  double c;
  double s;
  double scale;
  double t;
  double xN1;
  double yN1;
  double zN1;
  double *PointTable_A_data;
  double *result_data;
  int PointTable2DT_A_size_idx_0;
  int b_PointTable2DT_A_size_idx_0;
  int ibmat;
  int itilerow;
  int jcol;
  int loop_ub_tmp;
  int ntilerows;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  计算45（phi）面的法向量D */
  s = 0.0 * MTaon[2] - MTaon[1];
  C_tmp = MTaon[0] - 0.0 * MTaon[2];
  b_C_tmp = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  scale = 3.3121686421112381E-170;
  absxk_tmp = fabs(s);
  if (absxk_tmp > 3.3121686421112381E-170) {
    c = 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / 3.3121686421112381E-170;
    c = t * t;
  }
  b_absxk_tmp = fabs(C_tmp);
  if (b_absxk_tmp > scale) {
    t = scale / b_absxk_tmp;
    c = c * t * t + 1.0;
    scale = b_absxk_tmp;
  } else {
    t = b_absxk_tmp / scale;
    c += t * t;
  }
  t = b_C_tmp / scale;
  c += t * t;
  c = scale * sqrt(c);
  A1z = tan(1.5707963267948966 - phi);
  scale = 3.3121686421112381E-170;
  A8z = s / c;
  C[0] = A8z;
  A1x = MTaon[0] + A1z * A8z;
  D_idx_0 = A1x;
  absxk = fabs(A1x);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  A8z = C_tmp / c;
  C[1] = A8z;
  A1x = MTaon[1] + A1z * A8z;
  D_idx_1 = A1x;
  absxk = fabs(A1x);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  A8z = b_C_tmp / c;
  A1x = MTaon[2] + A1z * A8z;
  absxk = fabs(A1x);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  K = scale * sqrt(K);
  D_idx_0 /= K;
  D_idx_1 /= K;
  D_idx_2 = A1x / K;
  A1y = MTaon[1] * A8z - C[1] * MTaon[2];
  A1x = C[0] * MTaon[2] - MTaon[0] * A8z;
  A1z = MTaon[0] * C[1] - C[0] * MTaon[1];
  E_idx_0 = A1x * D_idx_2 - D_idx_1 * A1z;
  E_idx_1 = D_idx_0 * A1z - A1y * D_idx_2;
  E_idx_2 = A1y * D_idx_1 - D_idx_0 * A1x;
  scale = 3.3121686421112381E-170;
  absxk = fabs(E_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    c = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    c = t * t;
  }
  absxk = fabs(E_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    c = c * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    c += t * t;
  }
  absxk = fabs(E_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    c = c * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    c += t * t;
  }
  c = scale * sqrt(c);
  /*  圆心点 */
  E_idx_0 /= c;
  E_idx_1 /= c;
  E_idx_2 /= c;
  /*  三个点定义 */
  /*  斜率计算 */
  A1x = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  A1y = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  A1z = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - testP[0]) * A1x + (Mcenter[1] - testP[1]) * A1y) +
        (Mcenter[2] - testP[2]) * A1z) /
      ((A1x * A1x + A1y * A1y) + A1z * A1z);
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * A1x + Mcenter[0];
  yN1 = K * A1y + Mcenter[1];
  zN1 = K * A1z + Mcenter[2];
  /*  面法向量第二个点（与圆心点构成45（phi）面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  scale = 3.3121686421112381E-170;
  if (absxk_tmp > 3.3121686421112381E-170) {
    c = 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / 3.3121686421112381E-170;
    c = t * t;
  }
  if (b_absxk_tmp > scale) {
    t = scale / b_absxk_tmp;
    c = c * t * t + 1.0;
    scale = b_absxk_tmp;
  } else {
    t = b_absxk_tmp / scale;
    c += t * t;
  }
  t = b_C_tmp / scale;
  c += t * t;
  c = scale * sqrt(c);
  scale = 3.3121686421112381E-170;
  if (absxk_tmp > 3.3121686421112381E-170) {
    K = 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / 3.3121686421112381E-170;
    K = t * t;
  }
  if (b_absxk_tmp > scale) {
    t = scale / b_absxk_tmp;
    K = K * t * t + 1.0;
    scale = b_absxk_tmp;
  } else {
    t = b_absxk_tmp / scale;
    K += t * t;
  }
  t = b_C_tmp / scale;
  K += t * t;
  K = scale * sqrt(K);
  A8z = rt_atan2d_snf(K, (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  A1z = s / c;
  A1y = C_tmp / c;
  A1x = b_C_tmp / c;
  s = sin(A8z);
  c = cos(A8z);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  absxk = fabs(A1z);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  absxk = fabs(A1y);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  t = A1x / scale;
  K += t * t;
  K = scale * sqrt(K);
  if (K <= 1.0E-12) {
    C[0] = 0.0;
    C[1] = 0.0;
    C[2] = 0.0;
  } else {
    C[0] = A1z / K;
    C[1] = A1y / K;
    C[2] = A1x / K;
  }
  A1x = (1.0 - c) * C[0];
  rot1[0] = A1x * C[0] + c;
  A1y = A1x * C[1];
  A1z = s * C[2];
  rot1[3] = A1y - A1z;
  A1x *= C[2];
  K = s * C[1];
  rot1[6] = A1x + K;
  rot1[1] = A1y + A1z;
  A1y = (1.0 - c) * C[1];
  rot1[4] = A1y * C[1] + c;
  A1y *= C[2];
  A1z = s * C[0];
  rot1[7] = A1y - A1z;
  rot1[2] = A1x - K;
  rot1[5] = A1y + A1z;
  rot1[8] = (1.0 - c) * C[2] * C[2] + c;
  /*  选择旋转点集合 */
  Prot[0] = xN1;
  Prot[1] = yN1;
  Prot[2] = zN1;
  /*  圆心点 */
  Prot[3] = xN1 + D_idx_0;
  Prot[4] = yN1 + D_idx_1;
  Prot[5] = zN1 + D_idx_2;
  /*  面法向量第二个点 */
  /*  圆底面点1 */
  Prot[6] = Bottom_round_center1[0];
  Prot[9] = Bottom_round_center2[0];
  Prot[7] = Bottom_round_center1[1];
  Prot[10] = Bottom_round_center2[1];
  Prot[8] = Bottom_round_center1[2];
  Prot[11] = Bottom_round_center2[2];
  /*  圆底面点2 */
  Prot[12] = xN1 + E_idx_0;
  Prot[13] = yN1 + E_idx_1;
  Prot[14] = zN1 + E_idx_2;
  /*  起始点 （测点半圆的中点） */
  /*  旋转至【0，0，1】的点集合 */
  for (jcol = 0; jcol < 5; jcol++) {
    A8z = Prot[3 * jcol];
    A1x = Prot[3 * jcol + 1];
    A1z = Prot[3 * jcol + 2];
    for (ibmat = 0; ibmat < 3; ibmat++) {
      P2D[jcol + 5 * ibmat] =
          (A8z * rot1[3 * ibmat] + A1x * rot1[3 * ibmat + 1]) +
          A1z * rot1[3 * ibmat + 2];
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
  for (jcol = 0; jcol < 15; jcol++) {
    Prot[jcol] = P2D[jcol] - Prot[jcol];
  }
  /*  旋转、平移后 法向量 */
  C[0] = Prot[1] - Prot[0];
  C[1] = Prot[6] - Prot[5];
  C[2] = Prot[11] - Prot[10];
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  E_idx_1 = -((C[0] * Prot[0] + C[1] * Prot[5]) + C[2] * Prot[10]);
  /*  起始角度 */
  D_idx_2 = atan(Prot[9] / Prot[4]);
  A1x = Mradial * cos(D_idx_2);
  A1y = Mradial * sin(D_idx_2);
  A1z = -((E_idx_1 + C[0] * A1x) + C[1] * A1y) / C[2];
  PointTable2DT_A_size_idx_0 = 10;
  memset(&PointTable2DT_A_data[0], 0, 30U * sizeof(double));
  /*  根据声路数画出测点 */
  switch ((int)numShengLu) {
  case 1:
    PointTable2DT_A_size_idx_0 = 1;
    PointTable2DT_A_data[0] = A1x;
    PointTable2DT_A_data[1] = A1y;
    PointTable2DT_A_data[2] = A1z;
    break;
  case 2:
    angle2point(D_idx_2 - 0.52359877559829882, C[0], C[1], C[2], E_idx_1,
                Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point(D_idx_2 + 0.52359877559829882, C[0], C[1], C[2], E_idx_1,
                Mradial, &A3x, &A3y, &A3z);
    A2x[0] = E_idx_0;
    A2x[2] = D_idx_0;
    A2x[4] = D_idx_1;
    A2x[1] = A3x;
    A2x[3] = A3y;
    A2x[5] = A3z;
    PointTable2DT_A_size_idx_0 = 2;
    for (jcol = 0; jcol < 6; jcol++) {
      PointTable2DT_A_data[jcol] = A2x[jcol];
    }
    break;
  case 3:
    angle2point(D_idx_2 - 0.78539816339744828, C[0], C[1], C[2], E_idx_1,
                Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point(D_idx_2 + 0.78539816339744828, C[0], C[1], C[2], E_idx_1,
                Mradial, &A3x, &A3y, &A3z);
    b_A2x[0] = E_idx_0;
    b_A2x[3] = D_idx_0;
    b_A2x[6] = D_idx_1;
    b_A2x[1] = A1x;
    b_A2x[4] = A1y;
    b_A2x[7] = A1z;
    b_A2x[2] = A3x;
    b_A2x[5] = A3y;
    b_A2x[8] = A3z;
    PointTable2DT_A_size_idx_0 = 3;
    memcpy(&PointTable2DT_A_data[0], &b_A2x[0], 9U * sizeof(double));
    break;
  case 4:
    angle2point(D_idx_2 - 0.94247779607693793, C[0], C[1], C[2], E_idx_1,
                Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point(D_idx_2 - 0.31415926535897931, C[0], C[1], C[2], E_idx_1,
                Mradial, &A3x, &A3y, &A3z);
    angle2point(D_idx_2 + 0.31415926535897931, C[0], C[1], C[2], E_idx_1,
                Mradial, &A4x, &A4y, &A4z);
    angle2point(D_idx_2 + 0.94247779607693793, C[0], C[1], C[2], E_idx_1,
                Mradial, &A5x, &A5y, &A5z);
    c_A2x[0] = E_idx_0;
    c_A2x[4] = D_idx_0;
    c_A2x[8] = D_idx_1;
    c_A2x[1] = A3x;
    c_A2x[5] = A3y;
    c_A2x[9] = A3z;
    c_A2x[2] = A4x;
    c_A2x[6] = A4y;
    c_A2x[10] = A4z;
    c_A2x[3] = A5x;
    c_A2x[7] = A5y;
    c_A2x[11] = A5z;
    PointTable2DT_A_size_idx_0 = 4;
    memcpy(&PointTable2DT_A_data[0], &c_A2x[0], 12U * sizeof(double));
    break;
  case 5:
    angle2point(D_idx_2 - 1.0471975511965976, C[0], C[1], C[2], E_idx_1,
                Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point(D_idx_2 - 0.52359877559829882, C[0], C[1], C[2], E_idx_1,
                Mradial, &A3x, &A3y, &A3z);
    angle2point(D_idx_2 + 0.52359877559829882, C[0], C[1], C[2], E_idx_1,
                Mradial, &A4x, &A4y, &A4z);
    angle2point(D_idx_2 + 1.0471975511965976, C[0], C[1], C[2], E_idx_1,
                Mradial, &A5x, &A5y, &A5z);
    d_A2x[0] = E_idx_0;
    d_A2x[5] = D_idx_0;
    d_A2x[10] = D_idx_1;
    d_A2x[1] = A3x;
    d_A2x[6] = A3y;
    d_A2x[11] = A3z;
    d_A2x[2] = A1x;
    d_A2x[7] = A1y;
    d_A2x[12] = A1z;
    d_A2x[3] = A4x;
    d_A2x[8] = A4y;
    d_A2x[13] = A4z;
    d_A2x[4] = A5x;
    d_A2x[9] = A5y;
    d_A2x[14] = A5z;
    PointTable2DT_A_size_idx_0 = 5;
    memcpy(&PointTable2DT_A_data[0], &d_A2x[0], 15U * sizeof(double));
    break;
  case 6:
    angle2point((D_idx_2 - 1.5707963267948966) + 0.44879895051282759, C[0],
                C[1], C[2], E_idx_1, Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.89759790102565518, C[0],
                C[1], C[2], E_idx_1, Mradial, &A3x, &A3y, &A3z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.3463968515384828, C[0], C[1],
                C[2], E_idx_1, Mradial, &A4x, &A4y, &A4z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.7951958020513104, C[0], C[1],
                C[2], E_idx_1, Mradial, &A5x, &A5y, &A5z);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.2439947525641379, C[0], C[1],
                C[2], E_idx_1, Mradial, &K, &A1x, &A1y);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.6927937030769655, C[0], C[1],
                C[2], E_idx_1, Mradial, &A1z, &c, &s);
    e_A2x[0] = E_idx_0;
    e_A2x[6] = D_idx_0;
    e_A2x[12] = D_idx_1;
    e_A2x[1] = A3x;
    e_A2x[7] = A3y;
    e_A2x[13] = A3z;
    e_A2x[2] = A4x;
    e_A2x[8] = A4y;
    e_A2x[14] = A4z;
    e_A2x[3] = A5x;
    e_A2x[9] = A5y;
    e_A2x[15] = A5z;
    e_A2x[4] = K;
    e_A2x[10] = A1x;
    e_A2x[16] = A1y;
    e_A2x[5] = A1z;
    e_A2x[11] = c;
    e_A2x[17] = s;
    PointTable2DT_A_size_idx_0 = 6;
    memcpy(&PointTable2DT_A_data[0], &e_A2x[0], 18U * sizeof(double));
    break;
  case 7:
    angle2point((D_idx_2 - 1.5707963267948966) + 0.39269908169872414, C[0],
                C[1], C[2], E_idx_1, Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.78539816339744828, C[0],
                C[1], C[2], E_idx_1, Mradial, &A3x, &A3y, &A3z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.1780972450961724, C[0], C[1],
                C[2], E_idx_1, Mradial, &A4x, &A4y, &A4z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], E_idx_1, Mradial, &A5x, &A5y, &A5z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.9634954084936207, C[0], C[1],
                C[2], E_idx_1, Mradial, &K, &A1x, &A1y);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.3561944901923448, C[0], C[1],
                C[2], E_idx_1, Mradial, &A1z, &c, &s);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.748893571891069, C[0], C[1],
                C[2], E_idx_1, Mradial, &scale, &t, &A8z);
    f_A2x[0] = E_idx_0;
    f_A2x[7] = D_idx_0;
    f_A2x[14] = D_idx_1;
    f_A2x[1] = A3x;
    f_A2x[8] = A3y;
    f_A2x[15] = A3z;
    f_A2x[2] = A4x;
    f_A2x[9] = A4y;
    f_A2x[16] = A4z;
    f_A2x[3] = A5x;
    f_A2x[10] = A5y;
    f_A2x[17] = A5z;
    f_A2x[4] = K;
    f_A2x[11] = A1x;
    f_A2x[18] = A1y;
    f_A2x[5] = A1z;
    f_A2x[12] = c;
    f_A2x[19] = s;
    f_A2x[6] = scale;
    f_A2x[13] = t;
    f_A2x[20] = A8z;
    PointTable2DT_A_size_idx_0 = 7;
    memcpy(&PointTable2DT_A_data[0], &f_A2x[0], 21U * sizeof(double));
    break;
  case 8:
    angle2point((D_idx_2 - 1.5707963267948966) + 0.3490658503988659, C[0], C[1],
                C[2], E_idx_1, Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.69813170079773179, C[0],
                C[1], C[2], E_idx_1, Mradial, &A3x, &A3y, &A3z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.0471975511965976, C[0], C[1],
                C[2], E_idx_1, Mradial, &A4x, &A4y, &A4z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.3962634015954636, C[0], C[1],
                C[2], E_idx_1, Mradial, &A5x, &A5y, &A5z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.7453292519943295, C[0], C[1],
                C[2], E_idx_1, Mradial, &K, &A1x, &A1y);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.0943951023931953, C[0], C[1],
                C[2], E_idx_1, Mradial, &A1z, &c, &s);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.4434609527920612, C[0], C[1],
                C[2], E_idx_1, Mradial, &scale, &t, &A8z);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.7925268031909272, C[0], C[1],
                C[2], E_idx_1, Mradial, &absxk, &absxk_tmp, &b_absxk_tmp);
    g_A2x[0] = E_idx_0;
    g_A2x[8] = D_idx_0;
    g_A2x[16] = D_idx_1;
    g_A2x[1] = A3x;
    g_A2x[9] = A3y;
    g_A2x[17] = A3z;
    g_A2x[2] = A4x;
    g_A2x[10] = A4y;
    g_A2x[18] = A4z;
    g_A2x[3] = A5x;
    g_A2x[11] = A5y;
    g_A2x[19] = A5z;
    g_A2x[4] = K;
    g_A2x[12] = A1x;
    g_A2x[20] = A1y;
    g_A2x[5] = A1z;
    g_A2x[13] = c;
    g_A2x[21] = s;
    g_A2x[6] = scale;
    g_A2x[14] = t;
    g_A2x[22] = A8z;
    g_A2x[7] = absxk;
    g_A2x[15] = absxk_tmp;
    g_A2x[23] = b_absxk_tmp;
    PointTable2DT_A_size_idx_0 = 8;
    memcpy(&PointTable2DT_A_data[0], &g_A2x[0], 24U * sizeof(double));
    break;
  case 9:
    angle2point((D_idx_2 - 1.5707963267948966) + 0.31415926535897931, C[0],
                C[1], C[2], E_idx_1, Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.62831853071795862, C[0],
                C[1], C[2], E_idx_1, Mradial, &A3x, &A3y, &A3z);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.94247779607693793, C[0],
                C[1], C[2], E_idx_1, Mradial, &A4x, &A4y, &A4z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.2566370614359172, C[0], C[1],
                C[2], E_idx_1, Mradial, &A5x, &A5y, &A5z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], E_idx_1, Mradial, &K, &A1x, &A1y);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.8849555921538759, C[0], C[1],
                C[2], E_idx_1, Mradial, &A1z, &c, &s);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.1991148575128552, C[0], C[1],
                C[2], E_idx_1, Mradial, &scale, &t, &A8z);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.5132741228718345, C[0], C[1],
                C[2], E_idx_1, Mradial, &absxk, &absxk_tmp, &b_absxk_tmp);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.8274333882308138, C[0], C[1],
                C[2], E_idx_1, Mradial, &C_tmp, &zN1, &b_C_tmp);
    h_A2x[0] = E_idx_0;
    h_A2x[9] = D_idx_0;
    h_A2x[18] = D_idx_1;
    h_A2x[1] = A3x;
    h_A2x[10] = A3y;
    h_A2x[19] = A3z;
    h_A2x[2] = A4x;
    h_A2x[11] = A4y;
    h_A2x[20] = A4z;
    h_A2x[3] = A5x;
    h_A2x[12] = A5y;
    h_A2x[21] = A5z;
    h_A2x[4] = K;
    h_A2x[13] = A1x;
    h_A2x[22] = A1y;
    h_A2x[5] = A1z;
    h_A2x[14] = c;
    h_A2x[23] = s;
    h_A2x[6] = scale;
    h_A2x[15] = t;
    h_A2x[24] = A8z;
    h_A2x[7] = absxk;
    h_A2x[16] = absxk_tmp;
    h_A2x[25] = b_absxk_tmp;
    h_A2x[8] = C_tmp;
    h_A2x[17] = zN1;
    h_A2x[26] = b_C_tmp;
    PointTable2DT_A_size_idx_0 = 9;
    memcpy(&PointTable2DT_A_data[0], &h_A2x[0], 27U * sizeof(double));
    break;
  case 10:
    angle2point((D_idx_2 - 1.5707963267948966) + 0.28559933214452665, C[0],
                C[1], C[2], E_idx_1, Mradial, &E_idx_0, &D_idx_0, &D_idx_1);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.5711986642890533, C[0], C[1],
                C[2], E_idx_1, Mradial, &A3x, &A3y, &A3z);
    angle2point((D_idx_2 - 1.5707963267948966) + 0.8567979964335799, C[0], C[1],
                C[2], E_idx_1, Mradial, &A4x, &A4y, &A4z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.1423973285781066, C[0], C[1],
                C[2], E_idx_1, Mradial, &A5x, &A5y, &A5z);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.4279966607226333, C[0], C[1],
                C[2], E_idx_1, Mradial, &K, &A1x, &A1y);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.7135959928671598, C[0], C[1],
                C[2], E_idx_1, Mradial, &A1z, &c, &s);
    angle2point((D_idx_2 - 1.5707963267948966) + 1.9991953250116865, C[0], C[1],
                C[2], E_idx_1, Mradial, &scale, &t, &A8z);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.2847946571562132, C[0], C[1],
                C[2], E_idx_1, Mradial, &absxk, &absxk_tmp, &b_absxk_tmp);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.5703939893007397, C[0], C[1],
                C[2], E_idx_1, Mradial, &C_tmp, &zN1, &b_C_tmp);
    angle2point((D_idx_2 - 1.5707963267948966) + 2.8559933214452666, C[0], C[1],
                C[2], E_idx_1, Mradial, &yN1, &xN1, &E_idx_2);
    i_A2x[0] = E_idx_0;
    i_A2x[10] = D_idx_0;
    i_A2x[20] = D_idx_1;
    i_A2x[1] = A3x;
    i_A2x[11] = A3y;
    i_A2x[21] = A3z;
    i_A2x[2] = A4x;
    i_A2x[12] = A4y;
    i_A2x[22] = A4z;
    i_A2x[3] = A5x;
    i_A2x[13] = A5y;
    i_A2x[23] = A5z;
    i_A2x[4] = K;
    i_A2x[14] = A1x;
    i_A2x[24] = A1y;
    i_A2x[5] = A1z;
    i_A2x[15] = c;
    i_A2x[25] = s;
    i_A2x[6] = scale;
    i_A2x[16] = t;
    i_A2x[26] = A8z;
    i_A2x[7] = absxk;
    i_A2x[17] = absxk_tmp;
    i_A2x[27] = b_absxk_tmp;
    i_A2x[8] = C_tmp;
    i_A2x[18] = zN1;
    i_A2x[28] = b_C_tmp;
    i_A2x[9] = yN1;
    i_A2x[19] = xN1;
    i_A2x[29] = E_idx_2;
    memcpy(&PointTable2DT_A_data[0], &i_A2x[0], 30U * sizeof(double));
    break;
  }
  /* 计算2D A面测点 */
  A8z = 2.0 * Prot[0];
  A1x = 2.0 * Prot[5];
  ntilerows = PointTable2DT_A_size_idx_0 - 1;
  A1z = 2.0 * Prot[10];
  b_PointTable2DT_A_size_idx_0 =
      PointTable2DT_A_size_idx_0 + PointTable2DT_A_size_idx_0;
  for (jcol = 0; jcol < 3; jcol++) {
    for (ibmat = 0; ibmat < PointTable2DT_A_size_idx_0; ibmat++) {
      b_PointTable2DT_A_data[ibmat + b_PointTable2DT_A_size_idx_0 * jcol] =
          PointTable2DT_A_data[ibmat + PointTable2DT_A_size_idx_0 * jcol];
    }
  }
  for (jcol = 0; jcol < PointTable2DT_A_size_idx_0; jcol++) {
    b_PointTable2DT_A_data[jcol + PointTable2DT_A_size_idx_0] =
        A8z - PointTable2DT_A_data[jcol];
  }
  for (jcol = 0; jcol <= ntilerows; jcol++) {
    ibmat = jcol + PointTable2DT_A_size_idx_0;
    b_PointTable2DT_A_data[ibmat + b_PointTable2DT_A_size_idx_0] =
        A1x - PointTable2DT_A_data[ibmat];
  }
  for (jcol = 0; jcol <= ntilerows; jcol++) {
    b_PointTable2DT_A_data[(jcol + PointTable2DT_A_size_idx_0) +
                           b_PointTable2DT_A_size_idx_0 * 2] =
        A1z - PointTable2DT_A_data[jcol + PointTable2DT_A_size_idx_0 * 2];
  }
  PointTable2DT_A_size_idx_0 = b_PointTable2DT_A_size_idx_0;
  loop_ub_tmp = b_PointTable2DT_A_size_idx_0 * 3;
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         (unsigned int)loop_ub_tmp * sizeof(double));
  emxInit_real_T(&varargin_2, 1);
  jcol = varargin_2->size[0];
  varargin_2->size[0] = b_PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(varargin_2, jcol);
  PointTable_A_data = varargin_2->data;
  emxInit_real_T(&result, 2);
  jcol = result->size[0] * result->size[1];
  result->size[0] = b_PointTable2DT_A_size_idx_0;
  result->size[1] = 3;
  emxEnsureCapacity_real_T(result, jcol);
  result_data = result->data;
  for (jcol = 0; jcol < b_PointTable2DT_A_size_idx_0; jcol++) {
    PointTable_A_data[jcol] = -PointTable2DT_A_data[jcol];
    result_data[jcol] =
        PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0];
  }
  ibmat = varargin_2->size[0];
  ntilerows = b_PointTable2DT_A_size_idx_0 - 1;
  for (jcol = 0; jcol < ibmat; jcol++) {
    result_data[jcol + result->size[0]] = PointTable_A_data[jcol];
    result_data[jcol + result->size[0] * 2] =
        PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2];
    b_PointTable2DT_A_data[jcol] =
        PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0];
    b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0] =
        PointTable_A_data[jcol];
  }
  emxFree_real_T(&varargin_2);
  for (jcol = 0; jcol <= ntilerows; jcol++) {
    b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2] =
        PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2];
  }
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         (unsigned int)loop_ub_tmp * sizeof(double));
  /* 计算2D B面测点 */
  /* 2D AB面测点 转3D */
  pinv(rot1, b_A2x);
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  ntilerows = result->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * result->size[0];
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = C[jcol];
    }
  }
  for (jcol = 0; jcol < loop_ub_tmp; jcol++) {
    b_data[jcol] += PointTable2DT_A_data[jcol];
  }
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * b_PointTable2DT_A_size_idx_0;
    ntilerows = jcol * 3;
    for (itilerow = 0; itilerow < b_PointTable2DT_A_size_idx_0; itilerow++) {
      b_PointTable2DT_A_data[ibmat + itilerow] =
          (b_data[itilerow] * b_A2x[ntilerows] +
           b_data[b_PointTable2DT_A_size_idx_0 + itilerow] *
               b_A2x[ntilerows + 1]) +
          b_data[(b_PointTable2DT_A_size_idx_0 << 1) + itilerow] *
              b_A2x[ntilerows + 2];
    }
  }
  jcol = PointTable_A->size[0] * PointTable_A->size[1];
  PointTable_A->size[0] = 3;
  PointTable_A->size[1] = b_PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(PointTable_A, jcol);
  PointTable_A_data = PointTable_A->data;
  for (jcol = 0; jcol < b_PointTable2DT_A_size_idx_0; jcol++) {
    PointTable_A_data[3 * jcol] = b_PointTable2DT_A_data[jcol];
    PointTable_A_data[3 * jcol + 1] =
        b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0];
    PointTable_A_data[3 * jcol + 2] =
        b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2];
  }
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * b_PointTable2DT_A_size_idx_0;
    for (itilerow = 0; itilerow < b_PointTable2DT_A_size_idx_0; itilerow++) {
      b_data[ibmat + itilerow] = C[jcol];
    }
  }
  b_PointTable2DT_A_size_idx_0 = result->size[0];
  ibmat = result->size[0];
  for (jcol = 0; jcol < ibmat; jcol++) {
    b_PointTable2DT_A_data[jcol] = result_data[jcol];
    b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0] =
        result_data[jcol + result->size[0]];
    b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2] =
        A1z - PointTable2DT_A_data[jcol + PointTable2DT_A_size_idx_0 * 2];
  }
  emxFree_real_T(&result);
  for (jcol = 0; jcol < loop_ub_tmp; jcol++) {
    PointTable2DT_A_data[jcol] = b_PointTable2DT_A_data[jcol] + b_data[jcol];
  }
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * b_PointTable2DT_A_size_idx_0;
    ntilerows = jcol * 3;
    for (itilerow = 0; itilerow < b_PointTable2DT_A_size_idx_0; itilerow++) {
      b_PointTable2DT_A_data[ibmat + itilerow] =
          (PointTable2DT_A_data[itilerow] * b_A2x[ntilerows] +
           PointTable2DT_A_data[b_PointTable2DT_A_size_idx_0 + itilerow] *
               b_A2x[ntilerows + 1]) +
          PointTable2DT_A_data[(b_PointTable2DT_A_size_idx_0 << 1) + itilerow] *
              b_A2x[ntilerows + 2];
    }
  }
  jcol = PointTable_B->size[0] * PointTable_B->size[1];
  PointTable_B->size[0] = 3;
  PointTable_B->size[1] = b_PointTable2DT_A_size_idx_0;
  emxEnsureCapacity_real_T(PointTable_B, jcol);
  PointTable_A_data = PointTable_B->data;
  for (jcol = 0; jcol < b_PointTable2DT_A_size_idx_0; jcol++) {
    PointTable_A_data[3 * jcol] = b_PointTable2DT_A_data[jcol];
    PointTable_A_data[3 * jcol + 1] =
        b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0];
    PointTable_A_data[3 * jcol + 2] =
        b_PointTable2DT_A_data[jcol + b_PointTable2DT_A_size_idx_0 * 2];
  }
}

/*
 * File trailer for Calculat_A_and_B_Points.c
 *
 * [EOF]
 */
