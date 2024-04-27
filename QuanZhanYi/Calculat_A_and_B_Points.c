/*
 * File: Calculat_A_and_B_Points.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Apr-2024 15:10:40
 */

/* Include Files */
#include "Calculat_A_and_B_Points.h"
#include "QuanZhanYi_emxutil.h"
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
                             const double Bottom_round_center1[3],
                             const double Bottom_round_center2[3],
                             const double testP[3], double numShengLu,
                             double phi, emxArray_real_T *PointTable_A,
                             emxArray_real_T *PointTable_B)
{
  double PointTable2DT_A_data[60];
  double b_PointTable2DT_A_data[60];
  double b_data[60];
  double A2x[30];
  double P2D[15];
  double Prot[15];
  double b[9];
  double b_b[9];
  double rot1[9];
  double C[3];
  double A10x;
  double A10y;
  double A10z;
  double A11x;
  double A11y;
  double A11z;
  double A4z;
  double A8z;
  double A9x;
  double A9y;
  double A9z;
  double Ang1;
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
  double c;
  double dd;
  double norm_vec;
  double s;
  double scale;
  double t;
  double xN1;
  double yN1;
  double zN1;
  double *PointTable_A_data;
  int coffset;
  int ibmat;
  int itilerow;
  /*  计算45（phi）面的法向量D */
  c = 0.0 * MTaon[2] - MTaon[1];
  C_tmp = MTaon[0] - 0.0 * MTaon[2];
  b_C_tmp = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  scale = 3.3121686421112381E-170;
  s = fabs(c);
  if (s > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = s;
  } else {
    t = s / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk_tmp = fabs(C_tmp);
  if (absxk_tmp > scale) {
    t = scale / absxk_tmp;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / scale;
    norm_vec += t * t;
  }
  t = b_C_tmp / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  Ang1 = tan(phi);
  scale = 3.3121686421112381E-170;
  A4z = c / norm_vec;
  C[0] = A4z;
  dd = MTaon[0] + Ang1 * A4z;
  D_idx_0 = dd;
  absxk = fabs(dd);
  if (absxk > 3.3121686421112381E-170) {
    K = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    K = t * t;
  }
  A4z = C_tmp / norm_vec;
  C[1] = A4z;
  dd = MTaon[1] + Ang1 * A4z;
  D_idx_1 = dd;
  absxk = fabs(dd);
  if (absxk > scale) {
    t = scale / absxk;
    K = K * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    K += t * t;
  }
  A4z = b_C_tmp / norm_vec;
  dd = MTaon[2] + Ang1 * A4z;
  absxk = fabs(dd);
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
  D_idx_2 = dd / K;
  dd = MTaon[1] * A4z - C[1] * MTaon[2];
  norm_vec = C[0] * MTaon[2] - MTaon[0] * A4z;
  Ang1 = MTaon[0] * C[1] - C[0] * MTaon[1];
  E_idx_0 = norm_vec * D_idx_2 - D_idx_1 * Ang1;
  E_idx_1 = D_idx_0 * Ang1 - dd * D_idx_2;
  E_idx_2 = dd * D_idx_1 - D_idx_0 * norm_vec;
  scale = 3.3121686421112381E-170;
  absxk = fabs(E_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk = fabs(E_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  absxk = fabs(E_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  norm_vec = scale * sqrt(norm_vec);
  /*  圆心点 */
  E_idx_0 /= norm_vec;
  E_idx_1 /= norm_vec;
  E_idx_2 /= norm_vec;
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  dd = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  Ang1 = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - testP[0]) * norm_vec + (Mcenter[1] - testP[1]) * dd) +
        (Mcenter[2] - testP[2]) * Ang1) /
      ((norm_vec * norm_vec + dd * dd) + Ang1 * Ang1);
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * norm_vec + Mcenter[0];
  yN1 = K * dd + Mcenter[1];
  zN1 = K * Ang1 + Mcenter[2];
  /*  面法向量第二个点（与圆心点构成45（phi）面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  scale = 3.3121686421112381E-170;
  if (s > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = s;
  } else {
    t = s / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  if (absxk_tmp > scale) {
    t = scale / absxk_tmp;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / scale;
    norm_vec += t * t;
  }
  t = b_C_tmp / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  scale = 3.3121686421112381E-170;
  if (s > 3.3121686421112381E-170) {
    K = 1.0;
    scale = s;
  } else {
    t = s / 3.3121686421112381E-170;
    K = t * t;
  }
  if (absxk_tmp > scale) {
    t = scale / absxk_tmp;
    K = K * t * t + 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / scale;
    K += t * t;
  }
  t = b_C_tmp / scale;
  K += t * t;
  K = scale * sqrt(K);
  A4z = rt_atan2d_snf(K, (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  K = c / norm_vec;
  Ang1 = C_tmp / norm_vec;
  dd = b_C_tmp / norm_vec;
  s = sin(A4z);
  c = cos(A4z);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  absxk = fabs(K);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk = fabs(Ang1);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  t = dd / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    C[0] = 0.0;
    C[1] = 0.0;
    C[2] = 0.0;
  } else {
    C[0] = K / norm_vec;
    C[1] = Ang1 / norm_vec;
    C[2] = dd / norm_vec;
  }
  norm_vec = (1.0 - c) * C[0];
  rot1[0] = norm_vec * C[0] + c;
  dd = norm_vec * C[1];
  Ang1 = s * C[2];
  rot1[3] = dd - Ang1;
  norm_vec *= C[2];
  K = s * C[1];
  rot1[6] = norm_vec + K;
  rot1[1] = dd + Ang1;
  dd = (1.0 - c) * C[1];
  rot1[4] = dd * C[1] + c;
  dd *= C[2];
  Ang1 = s * C[0];
  rot1[7] = dd - Ang1;
  rot1[2] = norm_vec - K;
  rot1[5] = dd + Ang1;
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
  for (ibmat = 0; ibmat < 5; ibmat++) {
    A4z = Prot[3 * ibmat];
    dd = Prot[3 * ibmat + 1];
    Ang1 = Prot[3 * ibmat + 2];
    for (coffset = 0; coffset < 3; coffset++) {
      P2D[ibmat + 5 * coffset] =
          (A4z * rot1[3 * coffset] + dd * rot1[3 * coffset + 1]) +
          Ang1 * rot1[3 * coffset + 2];
    }
  }
  /*  plotcylinder(P2D(3,:),P2D(4,:),'b',Mradial,0.2) */
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (coffset = 0; coffset < 3; coffset++) {
    ibmat = coffset * 5;
    for (itilerow = 0; itilerow < 5; itilerow++) {
      Prot[ibmat + itilerow] = C[coffset];
    }
  }
  for (ibmat = 0; ibmat < 15; ibmat++) {
    Prot[ibmat] = P2D[ibmat] - Prot[ibmat];
  }
  /*  旋转、平移后 法向量 */
  C[0] = Prot[1] - Prot[0];
  C[1] = Prot[6] - Prot[5];
  C[2] = Prot[11] - Prot[10];
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  dd = -((C[0] * Prot[0] + C[1] * Prot[5]) + C[2] * Prot[10]);
  /*  起始角度 */
  Ang1 = atan(Prot[9] / Prot[4]);
  memset(&PointTable2DT_A_data[0], 0, 30U * sizeof(double));
  /*  根据声路数画出测点 */
  switch ((int)numShengLu) {
  case 1:
    break;
  case 2:
    angle2point(Ang1 - 0.52359877559829882, C[0], C[1], C[2], dd, &K, &norm_vec,
                &c);
    angle2point(Ang1 + 0.52359877559829882, C[0], C[1], C[2], dd, &s, &scale,
                &t);
    break;
  case 3:
    angle2point(Ang1 - 0.78539816339744828, C[0], C[1], C[2], dd, &K, &norm_vec,
                &c);
    angle2point(Ang1 + 0.78539816339744828, C[0], C[1], C[2], dd, &s, &scale,
                &t);
    break;
  case 4:
    angle2point(Ang1 - 0.94247779607693793, C[0], C[1], C[2], dd, &K, &norm_vec,
                &c);
    angle2point(Ang1 - 0.31415926535897931, C[0], C[1], C[2], dd, &s, &scale,
                &t);
    angle2point(Ang1 + 0.31415926535897931, C[0], C[1], C[2], dd, &absxk,
                &absxk_tmp, &A4z);
    angle2point(Ang1 + 0.94247779607693793, C[0], C[1], C[2], dd, &C_tmp, &zN1,
                &b_C_tmp);
    break;
  case 5:
    angle2point(Ang1 - 1.0471975511965976, C[0], C[1], C[2], dd, &K, &norm_vec,
                &c);
    angle2point(Ang1 - 0.52359877559829882, C[0], C[1], C[2], dd, &s, &scale,
                &t);
    angle2point(Ang1 + 0.52359877559829882, C[0], C[1], C[2], dd, &absxk,
                &absxk_tmp, &A4z);
    angle2point(Ang1 + 1.0471975511965976, C[0], C[1], C[2], dd, &C_tmp, &zN1,
                &b_C_tmp);
    break;
  case 6:
    angle2point((Ang1 - 1.5707963267948966) + 0.44879895051282759, C[0], C[1],
                C[2], dd, &K, &norm_vec, &c);
    angle2point((Ang1 - 1.5707963267948966) + 0.89759790102565518, C[0], C[1],
                C[2], dd, &s, &scale, &t);
    angle2point((Ang1 - 1.5707963267948966) + 1.3463968515384828, C[0], C[1],
                C[2], dd, &absxk, &absxk_tmp, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.7951958020513104, C[0], C[1],
                C[2], dd, &C_tmp, &zN1, &b_C_tmp);
    angle2point((Ang1 - 1.5707963267948966) + 2.2439947525641379, C[0], C[1],
                C[2], dd, &yN1, &xN1, &E_idx_2);
    angle2point((Ang1 - 1.5707963267948966) + 2.6927937030769655, C[0], C[1],
                C[2], dd, &E_idx_1, &D_idx_2, &E_idx_0);
    break;
  case 7:
    angle2point((Ang1 - 1.5707963267948966) + 0.39269908169872414, C[0], C[1],
                C[2], dd, &K, &norm_vec, &c);
    angle2point((Ang1 - 1.5707963267948966) + 0.78539816339744828, C[0], C[1],
                C[2], dd, &s, &scale, &t);
    angle2point((Ang1 - 1.5707963267948966) + 1.1780972450961724, C[0], C[1],
                C[2], dd, &absxk, &absxk_tmp, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], dd, &C_tmp, &zN1, &b_C_tmp);
    angle2point((Ang1 - 1.5707963267948966) + 1.9634954084936207, C[0], C[1],
                C[2], dd, &yN1, &xN1, &E_idx_2);
    angle2point((Ang1 - 1.5707963267948966) + 2.3561944901923448, C[0], C[1],
                C[2], dd, &E_idx_1, &D_idx_2, &E_idx_0);
    angle2point((Ang1 - 1.5707963267948966) + 2.748893571891069, C[0], C[1],
                C[2], dd, &D_idx_0, &D_idx_1, &A8z);
    break;
  case 8:
    angle2point((Ang1 - 1.5707963267948966) + 0.3490658503988659, C[0], C[1],
                C[2], dd, &K, &norm_vec, &c);
    angle2point((Ang1 - 1.5707963267948966) + 0.69813170079773179, C[0], C[1],
                C[2], dd, &s, &scale, &t);
    angle2point((Ang1 - 1.5707963267948966) + 1.0471975511965976, C[0], C[1],
                C[2], dd, &absxk, &absxk_tmp, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.3962634015954636, C[0], C[1],
                C[2], dd, &C_tmp, &zN1, &b_C_tmp);
    angle2point((Ang1 - 1.5707963267948966) + 1.7453292519943295, C[0], C[1],
                C[2], dd, &yN1, &xN1, &E_idx_2);
    angle2point((Ang1 - 1.5707963267948966) + 2.0943951023931953, C[0], C[1],
                C[2], dd, &E_idx_1, &D_idx_2, &E_idx_0);
    angle2point((Ang1 - 1.5707963267948966) + 2.4434609527920612, C[0], C[1],
                C[2], dd, &D_idx_0, &D_idx_1, &A8z);
    angle2point((Ang1 - 1.5707963267948966) + 2.7925268031909272, C[0], C[1],
                C[2], dd, &A9x, &A9y, &A9z);
    break;
  case 9:
    angle2point((Ang1 - 1.5707963267948966) + 0.31415926535897931, C[0], C[1],
                C[2], dd, &K, &norm_vec, &c);
    angle2point((Ang1 - 1.5707963267948966) + 0.62831853071795862, C[0], C[1],
                C[2], dd, &s, &scale, &t);
    angle2point((Ang1 - 1.5707963267948966) + 0.94247779607693793, C[0], C[1],
                C[2], dd, &absxk, &absxk_tmp, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.2566370614359172, C[0], C[1],
                C[2], dd, &C_tmp, &zN1, &b_C_tmp);
    angle2point((Ang1 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], dd, &yN1, &xN1, &E_idx_2);
    angle2point((Ang1 - 1.5707963267948966) + 1.8849555921538759, C[0], C[1],
                C[2], dd, &E_idx_1, &D_idx_2, &E_idx_0);
    angle2point((Ang1 - 1.5707963267948966) + 2.1991148575128552, C[0], C[1],
                C[2], dd, &D_idx_0, &D_idx_1, &A8z);
    angle2point((Ang1 - 1.5707963267948966) + 2.5132741228718345, C[0], C[1],
                C[2], dd, &A9x, &A9y, &A9z);
    angle2point((Ang1 - 1.5707963267948966) + 2.8274333882308138, C[0], C[1],
                C[2], dd, &A10x, &A10y, &A10z);
    break;
  case 10:
    angle2point((Ang1 - 1.5707963267948966) + 0.31415926535897931, C[0], C[1],
                C[2], dd, &K, &norm_vec, &c);
    angle2point((Ang1 - 1.5707963267948966) + 0.62831853071795862, C[0], C[1],
                C[2], dd, &s, &scale, &t);
    angle2point((Ang1 - 1.5707963267948966) + 0.94247779607693793, C[0], C[1],
                C[2], dd, &absxk, &absxk_tmp, &A4z);
    angle2point((Ang1 - 1.5707963267948966) + 1.2566370614359172, C[0], C[1],
                C[2], dd, &C_tmp, &zN1, &b_C_tmp);
    angle2point((Ang1 - 1.5707963267948966) + 1.5707963267948966, C[0], C[1],
                C[2], dd, &yN1, &xN1, &E_idx_2);
    angle2point((Ang1 - 1.5707963267948966) + 1.8849555921538759, C[0], C[1],
                C[2], dd, &E_idx_1, &D_idx_2, &E_idx_0);
    angle2point((Ang1 - 1.5707963267948966) + 2.1991148575128552, C[0], C[1],
                C[2], dd, &D_idx_0, &D_idx_1, &A8z);
    angle2point((Ang1 - 1.5707963267948966) + 2.5132741228718345, C[0], C[1],
                C[2], dd, &A9x, &A9y, &A9z);
    angle2point((Ang1 - 1.5707963267948966) + 2.8274333882308138, C[0], C[1],
                C[2], dd, &A10x, &A10y, &A10z);
    angle2point((Ang1 - 1.5707963267948966) + 3.1415926535897931, C[0], C[1],
                C[2], dd, &A11x, &A11y, &A11z);
    A2x[0] = K;
    A2x[10] = norm_vec;
    A2x[20] = c;
    A2x[1] = s;
    A2x[11] = scale;
    A2x[21] = t;
    A2x[2] = absxk;
    A2x[12] = absxk_tmp;
    A2x[22] = A4z;
    A2x[3] = C_tmp;
    A2x[13] = zN1;
    A2x[23] = b_C_tmp;
    A2x[4] = yN1;
    A2x[14] = xN1;
    A2x[24] = E_idx_2;
    A2x[5] = E_idx_1;
    A2x[15] = D_idx_2;
    A2x[25] = E_idx_0;
    A2x[6] = D_idx_0;
    A2x[16] = D_idx_1;
    A2x[26] = A8z;
    A2x[7] = A9x;
    A2x[17] = A9y;
    A2x[27] = A9z;
    A2x[8] = A10x;
    A2x[18] = A10y;
    A2x[28] = A10z;
    A2x[9] = A11x;
    A2x[19] = A11y;
    A2x[29] = A11z;
    memcpy(&PointTable2DT_A_data[0], &A2x[0], 30U * sizeof(double));
    break;
  }
  /* 计算2D A面测点 */
  A4z = 2.0 * Prot[0];
  dd = 2.0 * Prot[5];
  Ang1 = 2.0 * Prot[10];
  for (ibmat = 0; ibmat < 3; ibmat++) {
    memcpy(&b_PointTable2DT_A_data[ibmat * 20],
           &PointTable2DT_A_data[ibmat * 10], 10U * sizeof(double));
  }
  for (ibmat = 0; ibmat < 10; ibmat++) {
    b_PointTable2DT_A_data[ibmat + 10] = A4z - PointTable2DT_A_data[ibmat];
    b_PointTable2DT_A_data[ibmat + 30] = dd - PointTable2DT_A_data[ibmat + 10];
    b_PointTable2DT_A_data[ibmat + 50] =
        Ang1 - PointTable2DT_A_data[ibmat + 20];
  }
  memcpy(&PointTable2DT_A_data[0], &b_PointTable2DT_A_data[0],
         60U * sizeof(double));
  /* 计算2D B面测点 */
  /* 2D AB面测点 转3D */
  pinv(rot1, b);
  pinv(rot1, b_b);
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (coffset = 0; coffset < 3; coffset++) {
    ibmat = coffset * 20;
    for (itilerow = 0; itilerow < 20; itilerow++) {
      b_data[ibmat + itilerow] = C[coffset];
    }
  }
  for (ibmat = 0; ibmat < 60; ibmat++) {
    b_data[ibmat] += PointTable2DT_A_data[ibmat];
  }
  for (itilerow = 0; itilerow < 3; itilerow++) {
    coffset = itilerow * 20;
    ibmat = itilerow * 3;
    A4z = b[ibmat];
    dd = b[ibmat + 1];
    norm_vec = b[ibmat + 2];
    for (ibmat = 0; ibmat < 20; ibmat++) {
      b_PointTable2DT_A_data[coffset + ibmat] =
          (b_data[ibmat] * A4z + b_data[ibmat + 20] * dd) +
          b_data[ibmat + 40] * norm_vec;
    }
  }
  ibmat = PointTable_A->size[0] * PointTable_A->size[1];
  PointTable_A->size[0] = 3;
  PointTable_A->size[1] = 20;
  emxEnsureCapacity_real_T(PointTable_A, ibmat);
  PointTable_A_data = PointTable_A->data;
  for (ibmat = 0; ibmat < 20; ibmat++) {
    PointTable_A_data[3 * ibmat] = b_PointTable2DT_A_data[ibmat];
    PointTable_A_data[3 * ibmat + 1] = b_PointTable2DT_A_data[ibmat + 20];
    PointTable_A_data[3 * ibmat + 2] = b_PointTable2DT_A_data[ibmat + 40];
  }
  C[0] = P2D[0];
  C[1] = P2D[5];
  C[2] = 0.0;
  for (coffset = 0; coffset < 3; coffset++) {
    ibmat = coffset * 20;
    for (itilerow = 0; itilerow < 20; itilerow++) {
      b_data[ibmat + itilerow] = C[coffset];
    }
  }
  for (ibmat = 0; ibmat < 20; ibmat++) {
    b_PointTable2DT_A_data[ibmat] = PointTable2DT_A_data[ibmat];
    b_PointTable2DT_A_data[ibmat + 20] = PointTable2DT_A_data[ibmat + 20];
    b_PointTable2DT_A_data[ibmat + 40] =
        Ang1 - PointTable2DT_A_data[ibmat + 40];
  }
  for (ibmat = 0; ibmat < 60; ibmat++) {
    PointTable2DT_A_data[ibmat] = b_PointTable2DT_A_data[ibmat] + b_data[ibmat];
  }
  for (itilerow = 0; itilerow < 3; itilerow++) {
    coffset = itilerow * 20;
    ibmat = itilerow * 3;
    A4z = b_b[ibmat];
    dd = b_b[ibmat + 1];
    Ang1 = b_b[ibmat + 2];
    for (ibmat = 0; ibmat < 20; ibmat++) {
      b_PointTable2DT_A_data[coffset + ibmat] =
          (PointTable2DT_A_data[ibmat] * A4z +
           PointTable2DT_A_data[ibmat + 20] * dd) +
          PointTable2DT_A_data[ibmat + 40] * Ang1;
    }
  }
  ibmat = PointTable_B->size[0] * PointTable_B->size[1];
  PointTable_B->size[0] = 3;
  PointTable_B->size[1] = 20;
  emxEnsureCapacity_real_T(PointTable_B, ibmat);
  PointTable_A_data = PointTable_B->data;
  for (ibmat = 0; ibmat < 20; ibmat++) {
    PointTable_A_data[3 * ibmat] = b_PointTable2DT_A_data[ibmat];
    PointTable_A_data[3 * ibmat + 1] = b_PointTable2DT_A_data[ibmat + 20];
    PointTable_A_data[3 * ibmat + 2] = b_PointTable2DT_A_data[ibmat + 40];
  }
}

/*
 * File trailer for Calculat_A_and_B_Points.c
 *
 * [EOF]
 */
