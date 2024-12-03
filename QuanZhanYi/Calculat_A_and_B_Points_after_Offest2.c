/*
 * File: Calculat_A_and_B_Points_after_Offest2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 21:15:29
 */

/* Include Files */
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "eml_mtimes_helper.h"
#include "mtimes.h"
#include "norm.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include <math.h>
#include <stdio.h>

/* Function Declarations */
static void binary_expand_op_3(emxArray_real_T *in1, const emxArray_real_T *in2,
                               double in3);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                double in3
 * Return Type  : void
 */
static void binary_expand_op_3(emxArray_real_T *in1, const emxArray_real_T *in2,
                               double in3)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1] / in3;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : const double Bottom_round_center1[3]
 *                const double Bottom_round_center2[3]
 *                const double MTaon[3]
 *                const double Mcenter[3]
 *                double Mradial
 *                const double PAB[3]
 *                double phi
 *                emxArray_real_T *Ang
 *                const emxArray_real_T *toff
 *                const emxArray_real_T *roff
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 *                emxArray_real_T *BianHao
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest2(
    const double Bottom_round_center1[3], const double Bottom_round_center2[3],
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off,
    emxArray_real_T *BianHao)
{

  printf("CalculatOffset:  MTaon(%f,%f,%f) \n", MTaon[0], MTaon[1], MTaon[2]);
  printf("CalculatOffset:  Mcenter(%f,%f,%fc) \n", Mcenter[0], Mcenter[1],
         Mcenter[2]);
  printf("CalculatOffset:  PAB(%f,%f,%f)\n", PAB[0], PAB[1], PAB[2]);
  printf("CalculatOffset:  phi: %f\n", phi);
  printf("CalculatOffset:  toff: %f\n", toff->data[0]);
  printf("CalculatOffset:  roff: %f\n", roff->data[0]);
  emxArray_real_T *AngProcess;
  emxArray_real_T *BianHao1;
  emxArray_real_T *BianHaoTemp;
  emxArray_real_T *LeftPoint;
  emxArray_real_T *PointTable2DT_A;
  emxArray_real_T *PointTable2DT_B;
  emxArray_real_T *RightPoint;
  emxArray_real_T *TTTemp;
  emxArray_real_T *b;
  emxArray_real_T *b_LeftPoint;
  emxArray_real_T *b_PointTable2DT_A;
  emxArray_real_T *x;
  double P2D[9];
  double Prot[9];
  double rot1[9];
  double r[4];
  double C[3];
  double D[3];
  double E[3];
  double c[3];
  const double *roff_data;
  const double *toff_data;
  double C_tmp;
  double K;
  double a;
  double a_tmp;
  double b_C_tmp;
  double b_a;
  double c_a;
  double d_a;
  double dd;
  double e_a;
  double f_a;
  double norm_vec;
  double numShengLu;
  double s;
  double t;
  double xN1;
  double yN1;
  double zN1;
  double *AngProcess_data;
  double *Ang_data;
  double *PointTable2DT_A_data;
  double *PointTable2DT_B_data;
  double *PointTable_A_off_data;
  double *PointTable_B_off_data;
  double *RightPoint_data;
  double *x_data;
  int b_b;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
  int loop_ub;
  int loop_ub_tmp;
  int ntilerows;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  roff_data = roff->data;
  toff_data = toff->data;
  numShengLu = (double)Ang->size[1] / 2.0;
  /*  计算phi面的法向量D */
  s = 0.0 * MTaon[2] - MTaon[1];
  C[0] = s;
  C_tmp = MTaon[0] - 0.0 * MTaon[2];
  C[1] = C_tmp;
  b_C_tmp = 0.0 * MTaon[1] - MTaon[0] * 0.0;
  C[2] = b_C_tmp;
  t = b_norm(C);
  norm_vec = tan(1.5707963267948966 - phi);
  a_tmp = s / t;
  C[0] = a_tmp;
  D[0] = MTaon[0] + norm_vec * a_tmp;
  a_tmp = C_tmp / t;
  C[1] = a_tmp;
  D[1] = MTaon[1] + norm_vec * a_tmp;
  a_tmp = b_C_tmp / t;
  D[2] = MTaon[2] + norm_vec * a_tmp;
  t = b_norm(D);
  D[0] /= t;
  D[1] /= t;
  D[2] /= t;
  /*  计算0度线向量E */
  c[0] = MTaon[1] * a_tmp - C[1] * MTaon[2];
  c[1] = C[0] * MTaon[2] - MTaon[0] * a_tmp;
  c[2] = MTaon[0] * C[1] - C[0] * MTaon[1];
  E[0] = c[1] * D[2] - D[1] * c[2];
  E[1] = D[0] * c[2] - c[0] * D[2];
  E[2] = c[0] * D[1] - D[0] * c[1];
  t = b_norm(E);
  E[0] /= t;
  E[1] /= t;
  E[2] /= t;
  printf("E xyz: %f, %f, %f\n", E[0], E[1], E[2]);
  fflush(stdout);
  /*  圆心点 */
  /*  三个点定义 */
  /*  斜率计算 */
  /*  P1点在轴线上的投影坐标 */
  /*  面法向量第二个点（与圆心点构成phi面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  c[0] = s;
  c[1] = C_tmp;
  c[2] = b_C_tmp;
  dd = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  t = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  a_tmp = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - PAB[0]) * dd + (Mcenter[1] - PAB[1]) * t) +
        (Mcenter[2] - PAB[2]) * a_tmp) /
      ((dd * dd + t * t) + a_tmp * a_tmp);
  xN1 = K * dd + Mcenter[0];
  yN1 = K * t + Mcenter[1];
  zN1 = K * a_tmp + Mcenter[2];
  t = b_norm(c);
  C[0] = s;
  C[1] = C_tmp;
  C[2] = b_C_tmp;
  a_tmp =
      rt_atan2d_snf(b_norm(C), (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  r[0] = s / t;
  r[1] = C_tmp / t;
  r[2] = b_C_tmp / t;
  r[3] = a_tmp;
  s = sin(a_tmp);
  K = cos(a_tmp);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  norm_vec = b_norm(&r[0]);
  if (norm_vec <= 1.0E-12) {
    C[0] = 0.0;
    C[1] = 0.0;
    C[2] = 0.0;
  } else {
    C[0] = r[0] / norm_vec;
    C[1] = r[1] / norm_vec;
    C[2] = r[2] / norm_vec;
  }
  dd = (1.0 - K) * C[0];
  rot1[0] = dd * C[0] + K;
  t = dd * C[1];
  norm_vec = s * C[2];
  rot1[3] = t - norm_vec;
  dd *= C[2];
  a_tmp = s * C[1];
  rot1[6] = dd + a_tmp;
  rot1[1] = t + norm_vec;
  t = (1.0 - K) * C[1];
  rot1[4] = t * C[1] + K;
  t *= C[2];
  norm_vec = s * C[0];
  rot1[7] = t - norm_vec;
  rot1[2] = dd - a_tmp;
  rot1[5] = t + norm_vec;
  rot1[8] = (1.0 - K) * C[2] * C[2] + K;
  /*  选择旋转点集合 */
  Prot[0] = xN1;
  Prot[1] = yN1;
  Prot[2] = zN1;
  /*  圆心点 */
  Prot[3] = xN1 + D[0];
  Prot[4] = yN1 + D[1];
  Prot[5] = zN1 + D[2];
  /*  面法向量第二个点 */
  Prot[6] = xN1 + E[0];
  Prot[7] = yN1 + E[1];
  Prot[8] = zN1 + E[2];
  /*  起始点 （测点半圆的中点，0度线） */
  /*  旋转至【0，0，1】的点集合 */
  for (i = 0; i < 3; i++) {
    t = Prot[3 * i];
    a_tmp = Prot[3 * i + 1];
    norm_vec = Prot[3 * i + 2];
    for (itilerow = 0; itilerow < 3; itilerow++) {
      P2D[i + 3 * itilerow] =
          (t * rot1[3 * itilerow] + a_tmp * rot1[3 * itilerow + 1]) +
          norm_vec * rot1[3 * itilerow + 2];
    }
  }
  D[0] = P2D[0];
  D[1] = P2D[3];
  D[2] = 0.0;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * 3;
    t = D[jcol];
    Prot[ibmat] = t;
    Prot[ibmat + 1] = t;
    Prot[ibmat + 2] = t;
  }
  for (i = 0; i < 9; i++) {
    Prot[i] = P2D[i] - Prot[i];
  }
  /*  旋转、平移后 法向量 */
  C[0] = Prot[1] - Prot[0];
  C[1] = Prot[4] - Prot[3];
  C[2] = Prot[7] - Prot[6];
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  dd = -((C[0] * Prot[0] + C[1] * Prot[3]) + C[2] * Prot[6]);
  /*  起始角度 */
  norm_vec = atan(Prot[5] / Prot[2]);
  /*  !!!!!!!后面的点以这个为基础 */
  printf("AngOring: %f\n", norm_vec);
  fflush(stdout);
  /*  第一步修正 */
  if (Ang->size[1] == roff->size[1]) {
    jcol = Ang->size[1] - 1;
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i <= jcol; i++) {
      Ang_data[i] += roff_data[i] / Mradial;
    }
  } else {
    binary_expand_op_3(Ang, roff, Mradial);
    Ang_data = Ang->data;
  }
  if (E[2] < 0.0) {
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    jcol = Ang->size[1] - 1;
    for (i = 0; i <= jcol; i++) {
      Ang_data[i] += 3.1415926535897931;
    }
  }
  /*  第二步处理 */
  emxInit_real_T(&AngProcess, 2);
  i = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  AngProcess->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(AngProcess, i);
  AngProcess_data = AngProcess->data;
  jcol = Ang->size[1];
  for (i = 0; i < jcol; i++) {
    AngProcess_data[i] = 0.0;
  }
  if (numShengLu < 1.0) {
    jcol = 0;
  } else {
    jcol = (int)numShengLu;
  }
  for (i = 0; i < jcol; i++) {
    AngProcess_data[i] = norm_vec - Ang_data[i];
  }
  t = 2.0 * numShengLu;
  if (numShengLu + 1.0 > t) {
    i = 0;
    itilerow = 0;
  } else {
    i = (int)(numShengLu + 1.0) - 1;
    itilerow = (int)t;
  }
  if (numShengLu + 1.0 > 2.0 * numShengLu) {
    ibmat = 1;
  } else {
    ibmat = (int)(numShengLu + 1.0);
  }
  jcol = itilerow - i;
  for (itilerow = 0; itilerow < jcol; itilerow++) {
    AngProcess_data[(ibmat + itilerow) - 1] =
        (norm_vec + 3.1415926535897931) + Ang_data[i + itilerow];
  }
  /*  调用计算坐标 */
  emxInit_real_T(&x, 2);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = AngProcess->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  jcol = AngProcess->size[1];
  for (ntilerows = 0; ntilerows < jcol; ntilerows++) {
    x_data[ntilerows] = cos(AngProcess_data[ntilerows]);
  }
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  loop_ub_tmp = x->size[1] - 1;
  for (i = 0; i <= loop_ub_tmp; i++) {
    x_data[i] *= Mradial;
  }
  ibmat = AngProcess->size[1];
  for (ntilerows = 0; ntilerows < ibmat; ntilerows++) {
    AngProcess_data[ntilerows] = sin(AngProcess_data[ntilerows]);
  }
  i = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  emxEnsureCapacity_real_T(AngProcess, i);
  AngProcess_data = AngProcess->data;
  for (i = 0; i <= loop_ub_tmp; i++) {
    AngProcess_data[i] *= Mradial;
  }
  emxInit_real_T(&PointTable2DT_A, 2);
  if (x->size[1] == AngProcess->size[1]) {
    i = PointTable2DT_A->size[0] * PointTable2DT_A->size[1];
    PointTable2DT_A->size[0] = x->size[1];
    PointTable2DT_A->size[1] = 3;
    emxEnsureCapacity_real_T(PointTable2DT_A, i);
    PointTable2DT_A_data = PointTable2DT_A->data;
    jcol = x->size[1];
    for (i = 0; i < jcol; i++) {
      t = x_data[i];
      PointTable2DT_A_data[i] = t;
      a_tmp = AngProcess_data[i];
      PointTable2DT_A_data[i + PointTable2DT_A->size[0]] = a_tmp;
      PointTable2DT_A_data[i + PointTable2DT_A->size[0] * 2] =
          -((dd + C[0] * t) + C[1] * a_tmp) / C[2];
    }
  } else {
    binary_expand_op_2(PointTable2DT_A, x, AngProcess, dd, C);
    PointTable2DT_A_data = PointTable2DT_A->data;
  }
  i = PointTable2DT_A->size[0];
  for (ibmat = 0; ibmat < i; ibmat++) {
    t = PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2];
    if (t > Prot[6]) {
      t -= toff_data[ibmat];
      PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2] = t;
    } else {
      t += toff_data[ibmat];
      PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2] = t;
    }
  }
  /*  2D A面点 */
  ibmat = PointTable2DT_A->size[0];
  ntilerows = PointTable2DT_A->size[0] - 1;
  emxInit_real_T(&b_PointTable2DT_A, 2);
  i = b_PointTable2DT_A->size[0] * b_PointTable2DT_A->size[1];
  b_PointTable2DT_A->size[0] = PointTable2DT_A->size[0];
  b_PointTable2DT_A->size[1] = 3;
  emxEnsureCapacity_real_T(b_PointTable2DT_A, i);
  Ang_data = b_PointTable2DT_A->data;
  for (i = 0; i < ibmat; i++) {
    Ang_data[i] = PointTable2DT_A_data[i + PointTable2DT_A->size[0]];
  }
  for (i = 0; i <= ntilerows; i++) {
    Ang_data[i + b_PointTable2DT_A->size[0]] = -PointTable2DT_A_data[i];
  }
  for (i = 0; i <= ntilerows; i++) {
    Ang_data[i + b_PointTable2DT_A->size[0] * 2] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0] * 2];
  }
  i = PointTable2DT_A->size[0] * PointTable2DT_A->size[1];
  PointTable2DT_A->size[0] = b_PointTable2DT_A->size[0];
  PointTable2DT_A->size[1] = 3;
  emxEnsureCapacity_real_T(PointTable2DT_A, i);
  PointTable2DT_A_data = PointTable2DT_A->data;
  loop_ub_tmp = b_PointTable2DT_A->size[0] * 3;
  for (i = 0; i < loop_ub_tmp; i++) {
    PointTable2DT_A_data[i] = Ang_data[i];
  }
  /* 2D B面点 */
  t = 2.0 * Prot[6];
  emxInit_real_T(&PointTable2DT_B, 2);
  i = PointTable2DT_B->size[0] * PointTable2DT_B->size[1];
  PointTable2DT_B->size[0] = PointTable2DT_A->size[0];
  PointTable2DT_B->size[1] = 3;
  emxEnsureCapacity_real_T(PointTable2DT_B, i);
  PointTable2DT_B_data = PointTable2DT_B->data;
  jcol = PointTable2DT_A->size[0];
  for (i = 0; i < jcol; i++) {
    PointTable2DT_B_data[i] = PointTable2DT_A_data[i];
    PointTable2DT_B_data[i + PointTable2DT_B->size[0]] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0]];
    PointTable2DT_B_data[i + PointTable2DT_B->size[0] * 2] =
        t - PointTable2DT_A_data[i + PointTable2DT_A->size[0] * 2];
  }
  /* 2D A面测点 转3D */
  pinv(rot1, Prot);
  D[0] = P2D[0];
  D[1] = P2D[3];
  D[2] = 0.0;
  emxInit_real_T(&b, 2);
  i = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_A->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, i);
  RightPoint_data = b->data;
  ntilerows = PointTable2DT_A->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * PointTable2DT_A->size[0];
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      RightPoint_data[ibmat + itilerow] = D[jcol];
    }
  }
  if (PointTable2DT_A->size[0] == b->size[0]) {
    i = b_PointTable2DT_A->size[0] * b_PointTable2DT_A->size[1];
    b_PointTable2DT_A->size[0] = PointTable2DT_A->size[0];
    b_PointTable2DT_A->size[1] = 3;
    emxEnsureCapacity_real_T(b_PointTable2DT_A, i);
    Ang_data = b_PointTable2DT_A->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      Ang_data[i] = PointTable2DT_A_data[i] + RightPoint_data[i];
    }
    mtimes(b_PointTable2DT_A, Prot, PointTable2DT_A);
    PointTable2DT_A_data = PointTable2DT_A->data;
  } else {
    binary_expand_op_1(PointTable2DT_A, b, Prot);
    PointTable2DT_A_data = PointTable2DT_A->data;
  }
  i = PointTable_A_off->size[0] * PointTable_A_off->size[1];
  PointTable_A_off->size[0] = 3;
  PointTable_A_off->size[1] = PointTable2DT_A->size[0];
  emxEnsureCapacity_real_T(PointTable_A_off, i);
  PointTable_A_off_data = PointTable_A_off->data;
  jcol = PointTable2DT_A->size[0];
  for (i = 0; i < jcol; i++) {
    PointTable_A_off_data[3 * i] = PointTable2DT_A_data[i];
    PointTable_A_off_data[3 * i + 1] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0]];
    PointTable_A_off_data[3 * i + 2] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0] * 2];
  }
  D[0] = P2D[0];
  D[1] = P2D[3];
  D[2] = 0.0;
  i = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_B->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, i);
  RightPoint_data = b->data;
  ntilerows = PointTable2DT_B->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * PointTable2DT_B->size[0];
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      RightPoint_data[ibmat + itilerow] = D[jcol];
    }
  }
  if (PointTable2DT_B->size[0] == b->size[0]) {
    i = b_PointTable2DT_A->size[0] * b_PointTable2DT_A->size[1];
    b_PointTable2DT_A->size[0] = PointTable2DT_B->size[0];
    b_PointTable2DT_A->size[1] = 3;
    emxEnsureCapacity_real_T(b_PointTable2DT_A, i);
    Ang_data = b_PointTable2DT_A->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      Ang_data[i] = PointTable2DT_B_data[i] + RightPoint_data[i];
    }
    mtimes(b_PointTable2DT_A, Prot, PointTable2DT_A);
    PointTable2DT_A_data = PointTable2DT_A->data;
  } else {
    binary_expand_op(PointTable2DT_A, PointTable2DT_B, b, Prot);
    PointTable2DT_A_data = PointTable2DT_A->data;
  }
  emxFree_real_T(&b_PointTable2DT_A);
  emxFree_real_T(&b);
  emxFree_real_T(&PointTable2DT_B);
  i = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = PointTable2DT_A->size[0];
  emxEnsureCapacity_real_T(PointTable_B_off, i);
  PointTable_B_off_data = PointTable_B_off->data;
  jcol = PointTable2DT_A->size[0];
  for (i = 0; i < jcol; i++) {
    PointTable_B_off_data[3 * i] = PointTable2DT_A_data[i];
    PointTable_B_off_data[3 * i + 1] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0]];
    PointTable_B_off_data[3 * i + 2] =
        PointTable2DT_A_data[i + PointTable2DT_A->size[0] * 2];
  }
  emxFree_real_T(&PointTable2DT_A);
  E[0] = Bottom_round_center1[0] - Bottom_round_center2[0];
  E[1] = Bottom_round_center1[1] - Bottom_round_center2[1];
  E[2] = Bottom_round_center1[2] - Bottom_round_center2[2];
  /*  向上游 */
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  loop_ub_tmp = (int)numShengLu;
  x->size[1] = (int)numShengLu;
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    x_data[i] = 1.0;
  }
  i = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  jcol = (int)numShengLu << 1;
  AngProcess->size[1] = jcol;
  emxEnsureCapacity_real_T(AngProcess, i);
  AngProcess_data = AngProcess->data;
  for (i = 0; i < jcol; i++) {
    AngProcess_data[i] = -1.0;
  }
  if (jcol - 1 >= 0) {
    a = Bottom_round_center2[0] - Bottom_round_center1[0];
    b_a = Bottom_round_center2[1] - Bottom_round_center1[1];
    c_a = Bottom_round_center2[2] - Bottom_round_center1[2];
    c[0] = E[1] * 0.0 - E[2] * 0.0;
    c[1] = E[2] - E[0] * 0.0;
    c[2] = E[0] * 0.0 - E[1];
  }
  for (itilerow = 0; itilerow < jcol; itilerow++) {
    /*  计算方向 */
    /*  右侧 */
    /*  三个点定义 */
    /*  斜率计算 */
    norm_vec = Bottom_round_center2[0] - Bottom_round_center1[0];
    dd = Bottom_round_center2[1] - Bottom_round_center1[1];
    t = Bottom_round_center2[2] - Bottom_round_center1[2];
    ibmat = 3 * itilerow + 1;
    ntilerows = 3 * itilerow + 2;
    K = -(((Bottom_round_center1[0] - PointTable_A_off_data[3 * itilerow]) *
               norm_vec +
           (Bottom_round_center1[1] - PointTable_A_off_data[ibmat]) * dd) +
          (Bottom_round_center1[2] - PointTable_A_off_data[ntilerows]) * t) /
        ((a * a + b_a * b_a) + c_a * c_a);
    /*  P1点在轴线上的投影坐标 */
    /*  指向垂足 */
    /*  计算夹角 */
    D[0] = (K * norm_vec + Bottom_round_center1[0]) -
           PointTable_A_off_data[3 * itilerow];
    D[1] = (K * dd + Bottom_round_center1[1]) - PointTable_A_off_data[ibmat];
    D[2] = (K * t + Bottom_round_center1[2]) - PointTable_A_off_data[ntilerows];
    C[0] = D[1] * 0.0 - 0.0 * D[2];
    C[1] = D[2] - D[0] * 0.0;
    C[2] = D[0] * 0.0 - D[1];
    /*  夹角（弧度） */
    /*  判断左右 */
    norm_vec = 3.3121686421112381E-170;
    dd = fabs(E[0]);
    if (dd > 3.3121686421112381E-170) {
      a_tmp = 1.0;
      norm_vec = dd;
    } else {
      t = dd / 3.3121686421112381E-170;
      a_tmp = t * t;
    }
    dd = fabs(E[1]);
    if (dd > norm_vec) {
      t = norm_vec / dd;
      a_tmp = a_tmp * t * t + 1.0;
      norm_vec = dd;
    } else {
      t = dd / norm_vec;
      a_tmp += t * t;
    }
    dd = fabs(E[2]);
    if (dd > norm_vec) {
      t = norm_vec / dd;
      a_tmp = a_tmp * t * t + 1.0;
      norm_vec = dd;
    } else {
      t = dd / norm_vec;
      a_tmp += t * t;
    }
    a_tmp = norm_vec * sqrt(a_tmp);
    AngProcess_data[itilerow] = !(
        57.295779513082323 * acos(((E[0] * C[0] + E[1] * C[1]) + E[2] * C[2]) /
                                  (a_tmp * b_norm(C))) >
        90.0);
    /*  计算平面方程 */
    /* A1-4一侧，右侧向量 */
    C[0] = c[1] * E[2] - E[1] * c[2];
    C[1] = E[0] * c[2] - c[0] * E[2];
    C[2] = c[0] * E[1] - E[0] * c[1];
    t = b_norm(C);
    C[0] /= t;
    C[1] /= t;
    C[2] /= t;
    /*  平面法向量 */
    /*  计算点到平面的距离 */
    /*  平面方程左侧的值 */
    /*  法向量的模长 */
    x_data[itilerow] =
        (((C[0] * PointTable_A_off_data[3 * itilerow] +
           C[1] * PointTable_A_off_data[ibmat]) +
          C[2] * PointTable_A_off_data[ntilerows]) -
         ((C[0] * Bottom_round_center1[0] + C[1] * Bottom_round_center1[1]) +
          C[2] * Bottom_round_center1[2])) /
        sqrt((C[0] * C[0] + C[1] * C[1]) + C[2] * C[2]);
    /*  距离公式 */
  }
  emxInit_real_T(&RightPoint, 2);
  RightPoint_data = RightPoint->data;
  RightPoint->size[0] = 0;
  RightPoint->size[1] = 5;
  /*  编号、点（x，y，z）、距离 */
  emxInit_real_T(&LeftPoint, 2);
  PointTable2DT_A_data = LeftPoint->data;
  LeftPoint->size[0] = 0;
  LeftPoint->size[1] = 5;
  emxInit_real_T(&b_LeftPoint, 2);
  for (ntilerows = 0; ntilerows < jcol; ntilerows++) {
    if (AngProcess_data[ntilerows] == 1.0) {
      ibmat = RightPoint->size[0];
      i = b_LeftPoint->size[0] * b_LeftPoint->size[1];
      b_LeftPoint->size[0] = RightPoint->size[0] + 1;
      b_LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(b_LeftPoint, i);
      Ang_data = b_LeftPoint->data;
      for (i = 0; i < 5; i++) {
        for (itilerow = 0; itilerow < ibmat; itilerow++) {
          Ang_data[itilerow + b_LeftPoint->size[0] * i] =
              RightPoint_data[itilerow + RightPoint->size[0] * i];
        }
      }
      Ang_data[RightPoint->size[0]] = (double)ntilerows + 1.0;
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0]] =
          PointTable_A_off_data[3 * ntilerows];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 2] =
          PointTable_A_off_data[3 * ntilerows + 1];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 3] =
          PointTable_A_off_data[3 * ntilerows + 2];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 4] =
          x_data[ntilerows];
      i = RightPoint->size[0] * RightPoint->size[1];
      RightPoint->size[0] = b_LeftPoint->size[0];
      RightPoint->size[1] = 5;
      emxEnsureCapacity_real_T(RightPoint, i);
      RightPoint_data = RightPoint->data;
      ibmat = b_LeftPoint->size[0] * 5;
      for (i = 0; i < ibmat; i++) {
        RightPoint_data[i] = Ang_data[i];
      }
    } else {
      ibmat = LeftPoint->size[0];
      i = b_LeftPoint->size[0] * b_LeftPoint->size[1];
      b_LeftPoint->size[0] = LeftPoint->size[0] + 1;
      b_LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(b_LeftPoint, i);
      Ang_data = b_LeftPoint->data;
      for (i = 0; i < 5; i++) {
        for (itilerow = 0; itilerow < ibmat; itilerow++) {
          Ang_data[itilerow + b_LeftPoint->size[0] * i] =
              PointTable2DT_A_data[itilerow + LeftPoint->size[0] * i];
        }
      }
      Ang_data[LeftPoint->size[0]] = (double)ntilerows + 1.0;
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0]] =
          PointTable_A_off_data[3 * ntilerows];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 2] =
          PointTable_A_off_data[3 * ntilerows + 1];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 3] =
          PointTable_A_off_data[3 * ntilerows + 2];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 4] =
          x_data[ntilerows];
      i = LeftPoint->size[0] * LeftPoint->size[1];
      LeftPoint->size[0] = b_LeftPoint->size[0];
      LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(LeftPoint, i);
      PointTable2DT_A_data = LeftPoint->data;
      ibmat = b_LeftPoint->size[0] * 5;
      for (i = 0; i < ibmat; i++) {
        PointTable2DT_A_data[i] = Ang_data[i];
      }
    }
  }
  sortrows(RightPoint);
  RightPoint_data = RightPoint->data;
  sortrows(LeftPoint);
  PointTable2DT_A_data = LeftPoint->data;
  emxInit_real_T(&BianHaoTemp, 1);
  i = BianHaoTemp->size[0];
  BianHaoTemp->size[0] = jcol;
  emxEnsureCapacity_real_T(BianHaoTemp, i);
  Ang_data = BianHaoTemp->data;
  for (i = 0; i < jcol; i++) {
    Ang_data[i] = 0.0;
  }
  emxInit_real_T(&BianHao1, 2);
  i = BianHao1->size[0] * BianHao1->size[1];
  BianHao1->size[0] = 1;
  BianHao1->size[1] = jcol;
  emxEnsureCapacity_real_T(BianHao1, i);
  PointTable_A_off_data = BianHao1->data;
  for (i = 0; i < jcol; i++) {
    PointTable_A_off_data[i] = 0.0;
  }
  if ((int)numShengLu - 1 >= 0) {
    if (jcol < 1) {
      AngProcess->size[0] = 1;
      AngProcess->size[1] = 0;
    } else {
      i = AngProcess->size[0] * AngProcess->size[1];
      AngProcess->size[0] = 1;
      AngProcess->size[1] = jcol;
      emxEnsureCapacity_real_T(AngProcess, i);
      AngProcess_data = AngProcess->data;
      ibmat = jcol - 1;
      for (i = 0; i <= ibmat; i++) {
        AngProcess_data[i] = (double)i + 1.0;
      }
    }
    loop_ub = AngProcess->size[1];
  }
  emxInit_real_T(&TTTemp, 2);
  for (ntilerows = 0; ntilerows < loop_ub_tmp; ntilerows++) {
    ibmat = ((ntilerows + 1) << 1) - 1;
    Ang_data[ibmat - 1] = RightPoint_data[ntilerows];
    Ang_data[ibmat] = PointTable2DT_A_data[ntilerows];
    i = TTTemp->size[0] * TTTemp->size[1];
    TTTemp->size[0] = BianHaoTemp->size[0];
    TTTemp->size[1] = 2;
    emxEnsureCapacity_real_T(TTTemp, i);
    PointTable2DT_B_data = TTTemp->data;
    ibmat = BianHaoTemp->size[0];
    for (i = 0; i < ibmat; i++) {
      PointTable2DT_B_data[i] = Ang_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      PointTable2DT_B_data[i + TTTemp->size[0]] = AngProcess_data[i];
    }
    b_sortrows(TTTemp);
    PointTable2DT_B_data = TTTemp->data;
    i = BianHao1->size[0] * BianHao1->size[1];
    BianHao1->size[0] = 1;
    BianHao1->size[1] = TTTemp->size[0];
    emxEnsureCapacity_real_T(BianHao1, i);
    PointTable_A_off_data = BianHao1->data;
    ibmat = TTTemp->size[0];
    for (i = 0; i < ibmat; i++) {
      PointTable_A_off_data[i] = PointTable2DT_B_data[i + TTTemp->size[0]];
    }
  }
  i = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  AngProcess->size[1] = jcol;
  emxEnsureCapacity_real_T(AngProcess, i);
  AngProcess_data = AngProcess->data;
  for (i = 0; i < jcol; i++) {
    AngProcess_data[i] = -1.0;
  }
  if (jcol - 1 >= 0) {
    d_a = Bottom_round_center2[0] - Bottom_round_center1[0];
    e_a = Bottom_round_center2[1] - Bottom_round_center1[1];
    f_a = Bottom_round_center2[2] - Bottom_round_center1[2];
    c[0] = E[1] * 0.0 - E[2] * 0.0;
    c[1] = E[2] - E[0] * 0.0;
    c[2] = E[0] * 0.0 - E[1];
  }
  for (itilerow = 0; itilerow < jcol; itilerow++) {
    /*  计算方向 */
    /*  三个点定义 */
    /*  斜率计算 */
    norm_vec = Bottom_round_center2[0] - Bottom_round_center1[0];
    dd = Bottom_round_center2[1] - Bottom_round_center1[1];
    t = Bottom_round_center2[2] - Bottom_round_center1[2];
    ibmat = 3 * itilerow + 1;
    ntilerows = 3 * itilerow + 2;
    K = -(((Bottom_round_center1[0] - PointTable_B_off_data[3 * itilerow]) *
               norm_vec +
           (Bottom_round_center1[1] - PointTable_B_off_data[ibmat]) * dd) +
          (Bottom_round_center1[2] - PointTable_B_off_data[ntilerows]) * t) /
        ((d_a * d_a + e_a * e_a) + f_a * f_a);
    /*  P1点在轴线上的投影坐标 */
    /*  指向垂足 */
    /*  计算夹角 */
    D[0] = (K * norm_vec + Bottom_round_center1[0]) -
           PointTable_B_off_data[3 * itilerow];
    D[1] = (K * dd + Bottom_round_center1[1]) - PointTable_B_off_data[ibmat];
    D[2] = (K * t + Bottom_round_center1[2]) - PointTable_B_off_data[ntilerows];
    C[0] = D[1] * 0.0 - 0.0 * D[2];
    C[1] = D[2] - D[0] * 0.0;
    C[2] = D[0] * 0.0 - D[1];
    /*  夹角（弧度） */
    /*  判断左右 */
    norm_vec = 3.3121686421112381E-170;
    dd = fabs(E[0]);
    if (dd > 3.3121686421112381E-170) {
      a_tmp = 1.0;
      norm_vec = dd;
    } else {
      t = dd / 3.3121686421112381E-170;
      a_tmp = t * t;
    }
    dd = fabs(E[1]);
    if (dd > norm_vec) {
      t = norm_vec / dd;
      a_tmp = a_tmp * t * t + 1.0;
      norm_vec = dd;
    } else {
      t = dd / norm_vec;
      a_tmp += t * t;
    }
    dd = fabs(E[2]);
    if (dd > norm_vec) {
      t = norm_vec / dd;
      a_tmp = a_tmp * t * t + 1.0;
      norm_vec = dd;
    } else {
      t = dd / norm_vec;
      a_tmp += t * t;
    }
    a_tmp = norm_vec * sqrt(a_tmp);
    AngProcess_data[itilerow] = !(
        57.295779513082323 * acos(((E[0] * C[0] + E[1] * C[1]) + E[2] * C[2]) /
                                  (a_tmp * b_norm(C))) >
        90.0);
    /*  计算平面方程 */
    /* A1-4一侧，右侧向量 */
    C[0] = c[1] * E[2] - E[1] * c[2];
    C[1] = E[0] * c[2] - c[0] * E[2];
    C[2] = c[0] * E[1] - E[0] * c[1];
    t = b_norm(C);
    C[0] /= t;
    C[1] /= t;
    C[2] /= t;
    /*  平面法向量 */
    /*  计算点到平面的距离 */
    /*  平面方程左侧的值 */
    /*  法向量的模长 */
    x_data[itilerow] =
        (((C[0] * PointTable_B_off_data[3 * itilerow] +
           C[1] * PointTable_B_off_data[ibmat]) +
          C[2] * PointTable_B_off_data[ntilerows]) -
         ((C[0] * Bottom_round_center1[0] + C[1] * Bottom_round_center1[1]) +
          C[2] * Bottom_round_center1[2])) /
        sqrt((C[0] * C[0] + C[1] * C[1]) + C[2] * C[2]);
    /*  距离公式 */
  }
  RightPoint->size[0] = 0;
  RightPoint->size[1] = 5;
  /*  编号、点（x，y，z）、距离 */
  LeftPoint->size[0] = 0;
  LeftPoint->size[1] = 5;
  for (ntilerows = 0; ntilerows < jcol; ntilerows++) {
    if (AngProcess_data[ntilerows] == 1.0) {
      ibmat = RightPoint->size[0];
      i = b_LeftPoint->size[0] * b_LeftPoint->size[1];
      b_LeftPoint->size[0] = RightPoint->size[0] + 1;
      b_LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(b_LeftPoint, i);
      Ang_data = b_LeftPoint->data;
      for (i = 0; i < 5; i++) {
        for (itilerow = 0; itilerow < ibmat; itilerow++) {
          Ang_data[itilerow + b_LeftPoint->size[0] * i] =
              RightPoint_data[itilerow + RightPoint->size[0] * i];
        }
      }
      Ang_data[RightPoint->size[0]] = (double)ntilerows + 1.0;
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0]] =
          PointTable_B_off_data[3 * ntilerows];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 2] =
          PointTable_B_off_data[3 * ntilerows + 1];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 3] =
          PointTable_B_off_data[3 * ntilerows + 2];
      Ang_data[RightPoint->size[0] + b_LeftPoint->size[0] * 4] =
          x_data[ntilerows];
      i = RightPoint->size[0] * RightPoint->size[1];
      RightPoint->size[0] = b_LeftPoint->size[0];
      RightPoint->size[1] = 5;
      emxEnsureCapacity_real_T(RightPoint, i);
      RightPoint_data = RightPoint->data;
      ibmat = b_LeftPoint->size[0] * 5;
      for (i = 0; i < ibmat; i++) {
        RightPoint_data[i] = Ang_data[i];
      }
    } else {
      ibmat = LeftPoint->size[0];
      i = b_LeftPoint->size[0] * b_LeftPoint->size[1];
      b_LeftPoint->size[0] = LeftPoint->size[0] + 1;
      b_LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(b_LeftPoint, i);
      Ang_data = b_LeftPoint->data;
      for (i = 0; i < 5; i++) {
        for (itilerow = 0; itilerow < ibmat; itilerow++) {
          Ang_data[itilerow + b_LeftPoint->size[0] * i] =
              PointTable2DT_A_data[itilerow + LeftPoint->size[0] * i];
        }
      }
      Ang_data[LeftPoint->size[0]] = (double)ntilerows + 1.0;
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0]] =
          PointTable_B_off_data[3 * ntilerows];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 2] =
          PointTable_B_off_data[3 * ntilerows + 1];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 3] =
          PointTable_B_off_data[3 * ntilerows + 2];
      Ang_data[LeftPoint->size[0] + b_LeftPoint->size[0] * 4] =
          x_data[ntilerows];
      i = LeftPoint->size[0] * LeftPoint->size[1];
      LeftPoint->size[0] = b_LeftPoint->size[0];
      LeftPoint->size[1] = 5;
      emxEnsureCapacity_real_T(LeftPoint, i);
      PointTable2DT_A_data = LeftPoint->data;
      ibmat = b_LeftPoint->size[0] * 5;
      for (i = 0; i < ibmat; i++) {
        PointTable2DT_A_data[i] = Ang_data[i];
      }
    }
  }
  emxFree_real_T(&b_LeftPoint);
  emxFree_real_T(&x);
  sortrows(RightPoint);
  RightPoint_data = RightPoint->data;
  sortrows(LeftPoint);
  PointTable2DT_A_data = LeftPoint->data;
  i = BianHaoTemp->size[0];
  BianHaoTemp->size[0] = jcol;
  emxEnsureCapacity_real_T(BianHaoTemp, i);
  Ang_data = BianHaoTemp->data;
  for (i = 0; i < jcol; i++) {
    Ang_data[i] = 0.0;
  }
  i = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  AngProcess->size[1] = jcol;
  emxEnsureCapacity_real_T(AngProcess, i);
  AngProcess_data = AngProcess->data;
  for (i = 0; i < jcol; i++) {
    AngProcess_data[i] = 0.0;
  }
  if ((int)numShengLu - 1 >= 0) {
    b_b = jcol;
  }
  for (ntilerows = 0; ntilerows < loop_ub_tmp; ntilerows++) {
    ibmat = ((ntilerows + 1) << 1) - 1;
    Ang_data[ibmat - 1] = PointTable2DT_A_data[ntilerows];
    Ang_data[ibmat] = RightPoint_data[ntilerows];
    if (b_b < 1) {
      AngProcess->size[0] = 1;
      AngProcess->size[1] = 0;
    } else {
      i = AngProcess->size[0] * AngProcess->size[1];
      AngProcess->size[0] = 1;
      AngProcess->size[1] = b_b;
      emxEnsureCapacity_real_T(AngProcess, i);
      AngProcess_data = AngProcess->data;
      jcol = b_b - 1;
      for (i = 0; i <= jcol; i++) {
        AngProcess_data[i] = (double)i + 1.0;
      }
    }
    i = TTTemp->size[0] * TTTemp->size[1];
    TTTemp->size[0] = BianHaoTemp->size[0];
    TTTemp->size[1] = 2;
    emxEnsureCapacity_real_T(TTTemp, i);
    PointTable2DT_B_data = TTTemp->data;
    jcol = BianHaoTemp->size[0];
    for (i = 0; i < jcol; i++) {
      PointTable2DT_B_data[i] = Ang_data[i];
    }
    jcol = AngProcess->size[1];
    for (i = 0; i < jcol; i++) {
      PointTable2DT_B_data[i + TTTemp->size[0]] = AngProcess_data[i];
    }
    b_sortrows(TTTemp);
    PointTable2DT_B_data = TTTemp->data;
    i = AngProcess->size[0] * AngProcess->size[1];
    AngProcess->size[0] = 1;
    AngProcess->size[1] = TTTemp->size[0];
    emxEnsureCapacity_real_T(AngProcess, i);
    AngProcess_data = AngProcess->data;
    jcol = TTTemp->size[0];
    for (i = 0; i < jcol; i++) {
      AngProcess_data[i] = PointTable2DT_B_data[i + TTTemp->size[0]];
    }
  }
  emxFree_real_T(&TTTemp);
  emxFree_real_T(&BianHaoTemp);
  emxFree_real_T(&LeftPoint);
  emxFree_real_T(&RightPoint);
  i = BianHao->size[0] * BianHao->size[1];
  BianHao->size[0] = 2;
  BianHao->size[1] = BianHao1->size[1];
  emxEnsureCapacity_real_T(BianHao, i);
  Ang_data = BianHao->data;
  jcol = BianHao1->size[1];
  for (i = 0; i < jcol; i++) {
    Ang_data[2 * i] = PointTable_A_off_data[i];
  }
  emxFree_real_T(&BianHao1);
  jcol = AngProcess->size[1];
  for (i = 0; i < jcol; i++) {
    Ang_data[2 * i + 1] = AngProcess_data[i];
  }
  emxFree_real_T(&AngProcess);
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.c
 *
 * [EOF]
 */
