/*
 * File: Calculat_A_and_B_Points_after_Offest2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:51:24
 */

/* Include Files */
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Declarations */
static void binary_expand_op_1(emxArray_real_T *in1, const emxArray_real_T *in2,
                               double in3);

static void plus(emxArray_real_T *in1, const emxArray_real_T *in2);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                double in3
 * Return Type  : void
 */
static void binary_expand_op_1(emxArray_real_T *in1, const emxArray_real_T *in2,
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
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void plus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  b_in1->size[1] = 3;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * i] +
          in2_data[i1 * stride_1_0 + in2->size[0] * i];
    }
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = 3;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[0];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : const double MTaon[3]
 *                const double Mcenter[3]
 *                double Mradial
 *                const double PAB[3]
 *                double phi
 *                emxArray_real_T *Ang
 *                const emxArray_real_T *toff
 *                const emxArray_real_T *roff
 *                emxArray_real_T *PointTable_A_off
 *                emxArray_real_T *PointTable_B_off
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest2(
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off)
{

  printf("CalculatOffset:  MTaon(%f,%f,%f) \n", MTaon[0], MTaon[1], MTaon[2]);
  printf("CalculatOffset:  Mcenter(%f,%f,%fc) \n", Mcenter[0], Mcenter[1],
         Mcenter[2]);
  printf("CalculatOffset:  PAB(%f,%f,%f)\n", PAB[0], PAB[1], PAB[2]);
  printf("CalculatOffset:  phi: %f\n", phi);
  printf("CalculatOffset:  toff: %f\n", toff->data[0]);
  printf("CalculatOffset:  roff: %f\n", roff->data[0]);
  emxArray_real_T *AngProcess;
  emxArray_real_T *PointTable2DT_A;
  emxArray_real_T *PointTable2DT_B;
  emxArray_real_T *b;
  emxArray_real_T *x;
  double P2D[9];
  double Prot[9];
  double rot1[9];
  double C[3];
  const double *roff_data;
  const double *toff_data;
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
  double c_idx_0;
  double d;
  double dd;
  double norm_vec;
  double numShengLu;
  double s;
  double scale;
  double t;
  double xN1;
  double yN1;
  double zN1;
  double *AngProcess_data;
  double *Ang_data;
  double *PointTable2DT_A_data;
  double *b_data;
  int i;
  int ibmat;
  int itilerow;
  int jcol;
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
  C_tmp = MTaon[0] - 0.0 * MTaon[2];
  b_C_tmp = 0.0 * MTaon[1] - 0.0 * MTaon[0];
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
  norm_vec = tan(1.5707963267948966 - phi);
  scale = 3.3121686421112381E-170;
  d = s / c;
  C[0] = d;
  c_idx_0 = MTaon[0] + norm_vec * d;
  D_idx_0 = c_idx_0;
  absxk = fabs(c_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    dd = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    dd = t * t;
  }
  d = C_tmp / c;
  C[1] = d;
  c_idx_0 = MTaon[1] + norm_vec * d;
  D_idx_1 = c_idx_0;
  absxk = fabs(c_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    dd = dd * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    dd += t * t;
  }
  d = b_C_tmp / c;
  c_idx_0 = MTaon[2] + norm_vec * d;
  absxk = fabs(c_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    dd = dd * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    dd += t * t;
  }
  dd = scale * sqrt(dd);
  D_idx_0 /= dd;
  D_idx_1 /= dd;
  D_idx_2 = c_idx_0 / dd;
  /*  计算0度线向量E */
  c_idx_0 = MTaon[1] * d - C[1] * MTaon[2];
  dd = C[0] * MTaon[2] - MTaon[0] * d;
  norm_vec = MTaon[0] * C[1] - C[0] * MTaon[1];
  E_idx_0 = dd * D_idx_2 - D_idx_1 * norm_vec;
  E_idx_1 = D_idx_0 * norm_vec - c_idx_0 * D_idx_2;
  E_idx_2 = c_idx_0 * D_idx_1 - D_idx_0 * dd;
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
  E_idx_0 /= c;
  E_idx_1 /= c;
  E_idx_2 /= c;
  printf("E xyz: %f, %f, %f\n", E_idx_0, E_idx_1, E_idx_2);
  fflush(stdout);
  /*  圆心点 */
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  dd = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  c_idx_0 = (Mcenter[2] + MTaon[2]) - Mcenter[2];
  K = -(((Mcenter[0] - PAB[0]) * norm_vec + (Mcenter[1] - PAB[1]) * dd) +
        (Mcenter[2] - PAB[2]) * c_idx_0) /
      ((norm_vec * norm_vec + dd * dd) + c_idx_0 * c_idx_0);
  /*  P1点在轴线上的投影坐标 */
  xN1 = K * norm_vec + Mcenter[0];
  yN1 = K * dd + Mcenter[1];
  zN1 = K * c_idx_0 + Mcenter[2];
  /*  面法向量第二个点（与圆心点构成phi面的法向量） */
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
    dd = 1.0;
    scale = absxk_tmp;
  } else {
    t = absxk_tmp / 3.3121686421112381E-170;
    dd = t * t;
  }
  if (b_absxk_tmp > scale) {
    t = scale / b_absxk_tmp;
    dd = dd * t * t + 1.0;
    scale = b_absxk_tmp;
  } else {
    t = b_absxk_tmp / scale;
    dd += t * t;
  }
  t = b_C_tmp / scale;
  dd += t * t;
  dd = scale * sqrt(dd);
  d = rt_atan2d_snf(dd, (0.0 * MTaon[0] + 0.0 * MTaon[1]) + MTaon[2]);
  K = s / c;
  c_idx_0 = C_tmp / c;
  dd = b_C_tmp / c;
  s = sin(d);
  c = cos(d);
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
  absxk = fabs(c_idx_0);
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
    C[1] = c_idx_0 / norm_vec;
    C[2] = dd / norm_vec;
  }
  norm_vec = (1.0 - c) * C[0];
  rot1[0] = norm_vec * C[0] + c;
  dd = norm_vec * C[1];
  c_idx_0 = s * C[2];
  rot1[3] = dd - c_idx_0;
  norm_vec *= C[2];
  K = s * C[1];
  rot1[6] = norm_vec + K;
  rot1[1] = dd + c_idx_0;
  dd = (1.0 - c) * C[1];
  rot1[4] = dd * C[1] + c;
  dd *= C[2];
  c_idx_0 = s * C[0];
  rot1[7] = dd - c_idx_0;
  rot1[2] = norm_vec - K;
  rot1[5] = dd + c_idx_0;
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
  Prot[6] = xN1 + E_idx_0;
  Prot[7] = yN1 + E_idx_1;
  Prot[8] = zN1 + E_idx_2;
  /*  起始点 （测点半圆的中点，0度线） */
  /*  旋转至【0，0，1】的点集合 */
  for (itilerow = 0; itilerow < 3; itilerow++) {
    d = Prot[3 * itilerow];
    c_idx_0 = Prot[3 * itilerow + 1];
    norm_vec = Prot[3 * itilerow + 2];
    for (jcol = 0; jcol < 3; jcol++) {
      P2D[itilerow + 3 * jcol] =
          (d * rot1[3 * jcol] + c_idx_0 * rot1[3 * jcol + 1]) +
          norm_vec * rot1[3 * jcol + 2];
    }
  }
  C[0] = P2D[0];
  C[1] = P2D[3];
  C[2] = 0.0;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * 3;
    d = C[jcol];
    Prot[ibmat] = d;
    Prot[ibmat + 1] = d;
    Prot[ibmat + 2] = d;
  }
  for (itilerow = 0; itilerow < 9; itilerow++) {
    Prot[itilerow] = P2D[itilerow] - Prot[itilerow];
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
    ibmat = Ang->size[1] - 1;
    itilerow = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    emxEnsureCapacity_real_T(Ang, itilerow);
    Ang_data = Ang->data;
    for (itilerow = 0; itilerow <= ibmat; itilerow++) {
      Ang_data[itilerow] += roff_data[itilerow] / Mradial;
    }
  } else {
    binary_expand_op_1(Ang, roff, Mradial);
  }
  itilerow = Ang->size[0] * Ang->size[1];
  Ang->size[0] = 1;
  emxEnsureCapacity_real_T(Ang, itilerow);
  Ang_data = Ang->data;
  loop_ub_tmp = Ang->size[1] - 1;
  for (itilerow = 0; itilerow <= loop_ub_tmp; itilerow++) {
    Ang_data[itilerow] += 3.1415926535897931;
  }
  /*  第二步处理 */
  emxInit_real_T(&AngProcess, 2);
  itilerow = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  AngProcess->size[1] = Ang->size[1];
  emxEnsureCapacity_real_T(AngProcess, itilerow);
  AngProcess_data = AngProcess->data;
  ibmat = Ang->size[1];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    AngProcess_data[itilerow] = 0.0;
  }
  if (numShengLu < 1.0) {
    ibmat = 0;
  } else {
    ibmat = (int)numShengLu;
  }
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    AngProcess_data[itilerow] = norm_vec - Ang_data[itilerow];
  }
  d = 2.0 * numShengLu;
  if (numShengLu + 1.0 > d) {
    itilerow = 0;
    jcol = 0;
  } else {
    itilerow = (int)(numShengLu + 1.0) - 1;
    jcol = (int)d;
  }
  if (numShengLu + 1.0 > 2.0 * numShengLu) {
    ntilerows = 1;
  } else {
    ntilerows = (int)(numShengLu + 1.0);
  }
  ibmat = jcol - itilerow;
  for (jcol = 0; jcol < ibmat; jcol++) {
    AngProcess_data[(ntilerows + jcol) - 1] =
        (norm_vec + 3.1415926535897931) + Ang_data[itilerow + jcol];
  }
  /*  调用计算坐标 */
  emxInit_real_T(&x, 2);
  itilerow = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = AngProcess->size[1];
  emxEnsureCapacity_real_T(x, itilerow);
  Ang_data = x->data;
  ibmat = AngProcess->size[1];
  for (ntilerows = 0; ntilerows < ibmat; ntilerows++) {
    Ang_data[ntilerows] = cos(AngProcess_data[ntilerows]);
  }
  itilerow = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_real_T(x, itilerow);
  Ang_data = x->data;
  for (itilerow = 0; itilerow <= loop_ub_tmp; itilerow++) {
    Ang_data[itilerow] *= Mradial;
  }
  ibmat = AngProcess->size[1];
  for (ntilerows = 0; ntilerows < ibmat; ntilerows++) {
    AngProcess_data[ntilerows] = sin(AngProcess_data[ntilerows]);
  }
  itilerow = AngProcess->size[0] * AngProcess->size[1];
  AngProcess->size[0] = 1;
  emxEnsureCapacity_real_T(AngProcess, itilerow);
  AngProcess_data = AngProcess->data;
  for (itilerow = 0; itilerow <= loop_ub_tmp; itilerow++) {
    AngProcess_data[itilerow] *= Mradial;
  }
  emxInit_real_T(&PointTable2DT_A, 2);
  if (x->size[1] == AngProcess->size[1]) {
    itilerow = PointTable2DT_A->size[0] * PointTable2DT_A->size[1];
    PointTable2DT_A->size[0] = x->size[1];
    PointTable2DT_A->size[1] = 3;
    emxEnsureCapacity_real_T(PointTable2DT_A, itilerow);
    PointTable2DT_A_data = PointTable2DT_A->data;
    ibmat = x->size[1];
    for (itilerow = 0; itilerow < ibmat; itilerow++) {
      d = Ang_data[itilerow];
      PointTable2DT_A_data[itilerow] = d;
      c_idx_0 = AngProcess_data[itilerow];
      PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0]] = c_idx_0;
      PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0] * 2] =
          -((dd + C[0] * d) + C[1] * c_idx_0) / C[2];
    }
  } else {
    binary_expand_op(PointTable2DT_A, x, AngProcess, dd, C);
    PointTable2DT_A_data = PointTable2DT_A->data;
  }
  emxFree_real_T(&x);
  emxFree_real_T(&AngProcess);
  itilerow = PointTable2DT_A->size[0];
  for (ibmat = 0; ibmat < itilerow; ibmat++) {
    d = PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2];
    if (d > Prot[6]) {
      d -= toff_data[ibmat];
      PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2] = d;
    } else {
      d += toff_data[ibmat];
      PointTable2DT_A_data[ibmat + PointTable2DT_A->size[0] * 2] = d;
    }
  }
  /*  2D A面点 */
  ibmat = PointTable2DT_A->size[0];
  ntilerows = PointTable2DT_A->size[0] - 1;
  emxInit_real_T(&PointTable2DT_B, 2);
  itilerow = PointTable2DT_B->size[0] * PointTable2DT_B->size[1];
  PointTable2DT_B->size[0] = PointTable2DT_A->size[0];
  PointTable2DT_B->size[1] = 3;
  emxEnsureCapacity_real_T(PointTable2DT_B, itilerow);
  Ang_data = PointTable2DT_B->data;
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    Ang_data[itilerow] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0]];
  }
  for (itilerow = 0; itilerow <= ntilerows; itilerow++) {
    Ang_data[itilerow + PointTable2DT_B->size[0]] =
        -PointTable2DT_A_data[itilerow];
  }
  for (itilerow = 0; itilerow <= ntilerows; itilerow++) {
    Ang_data[itilerow + PointTable2DT_B->size[0] * 2] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0] * 2];
  }
  itilerow = PointTable2DT_A->size[0] * PointTable2DT_A->size[1];
  PointTable2DT_A->size[0] = PointTable2DT_B->size[0];
  PointTable2DT_A->size[1] = 3;
  emxEnsureCapacity_real_T(PointTable2DT_A, itilerow);
  PointTable2DT_A_data = PointTable2DT_A->data;
  loop_ub_tmp = PointTable2DT_B->size[0] * 3;
  for (itilerow = 0; itilerow < loop_ub_tmp; itilerow++) {
    PointTable2DT_A_data[itilerow] = Ang_data[itilerow];
  }
  /* 2D B面点 */
  d = 2.0 * Prot[6];
  itilerow = PointTable2DT_B->size[0] * PointTable2DT_B->size[1];
  PointTable2DT_B->size[0] = PointTable2DT_A->size[0];
  PointTable2DT_B->size[1] = 3;
  emxEnsureCapacity_real_T(PointTable2DT_B, itilerow);
  Ang_data = PointTable2DT_B->data;
  ibmat = PointTable2DT_A->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    Ang_data[itilerow] = PointTable2DT_A_data[itilerow];
    Ang_data[itilerow + PointTable2DT_B->size[0]] =
        PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0]];
    Ang_data[itilerow + PointTable2DT_B->size[0] * 2] =
        d - PointTable2DT_A_data[itilerow + PointTable2DT_A->size[0] * 2];
  }
  /* 2D A面测点 转3D */
  pinv(rot1, Prot);
  C[0] = P2D[0];
  C[1] = P2D[3];
  C[2] = 0.0;
  emxInit_real_T(&b, 2);
  itilerow = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_A->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  b_data = b->data;
  ntilerows = PointTable2DT_A->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * PointTable2DT_A->size[0];
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = C[jcol];
    }
  }
  if (PointTable2DT_A->size[0] == b->size[0]) {
    itilerow = PointTable2DT_A->size[0] * PointTable2DT_A->size[1];
    PointTable2DT_A->size[1] = 3;
    emxEnsureCapacity_real_T(PointTable2DT_A, itilerow);
    PointTable2DT_A_data = PointTable2DT_A->data;
    for (itilerow = 0; itilerow < loop_ub_tmp; itilerow++) {
      PointTable2DT_A_data[itilerow] += b_data[itilerow];
    }
  } else {
    plus(PointTable2DT_A, b);
    PointTable2DT_A_data = PointTable2DT_A->data;
  }
  jcol = PointTable2DT_A->size[0];
  itilerow = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_A->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  b_data = b->data;
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * jcol;
    ntilerows = itilerow * 3;
    for (i = 0; i < jcol; i++) {
      b_data[ibmat + i] =
          (PointTable2DT_A_data[i] * Prot[ntilerows] +
           PointTable2DT_A_data[PointTable2DT_A->size[0] + i] *
               Prot[ntilerows + 1]) +
          PointTable2DT_A_data[(PointTable2DT_A->size[0] << 1) + i] *
              Prot[ntilerows + 2];
    }
  }
  emxFree_real_T(&PointTable2DT_A);
  itilerow = PointTable_A_off->size[0] * PointTable_A_off->size[1];
  PointTable_A_off->size[0] = 3;
  PointTable_A_off->size[1] = b->size[0];
  emxEnsureCapacity_real_T(PointTable_A_off, itilerow);
  AngProcess_data = PointTable_A_off->data;
  ibmat = b->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    AngProcess_data[3 * itilerow] = b_data[itilerow];
    AngProcess_data[3 * itilerow + 1] = b_data[itilerow + b->size[0]];
    AngProcess_data[3 * itilerow + 2] = b_data[itilerow + b->size[0] * 2];
  }
  C[0] = P2D[0];
  C[1] = P2D[3];
  C[2] = 0.0;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_B->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  b_data = b->data;
  ntilerows = PointTable2DT_B->size[0];
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * PointTable2DT_B->size[0];
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      b_data[ibmat + itilerow] = C[jcol];
    }
  }
  if (PointTable2DT_B->size[0] == b->size[0]) {
    itilerow = PointTable2DT_B->size[0] * PointTable2DT_B->size[1];
    PointTable2DT_B->size[1] = 3;
    emxEnsureCapacity_real_T(PointTable2DT_B, itilerow);
    Ang_data = PointTable2DT_B->data;
    for (itilerow = 0; itilerow < loop_ub_tmp; itilerow++) {
      Ang_data[itilerow] += b_data[itilerow];
    }
  } else {
    plus(PointTable2DT_B, b);
    Ang_data = PointTable2DT_B->data;
  }
  jcol = PointTable2DT_B->size[0];
  itilerow = b->size[0] * b->size[1];
  b->size[0] = PointTable2DT_B->size[0];
  b->size[1] = 3;
  emxEnsureCapacity_real_T(b, itilerow);
  b_data = b->data;
  for (itilerow = 0; itilerow < 3; itilerow++) {
    ibmat = itilerow * jcol;
    ntilerows = itilerow * 3;
    for (i = 0; i < jcol; i++) {
      b_data[ibmat + i] =
          (Ang_data[i] * Prot[ntilerows] +
           Ang_data[PointTable2DT_B->size[0] + i] * Prot[ntilerows + 1]) +
          Ang_data[(PointTable2DT_B->size[0] << 1) + i] * Prot[ntilerows + 2];
    }
  }
  emxFree_real_T(&PointTable2DT_B);
  itilerow = PointTable_B_off->size[0] * PointTable_B_off->size[1];
  PointTable_B_off->size[0] = 3;
  PointTable_B_off->size[1] = b->size[0];
  emxEnsureCapacity_real_T(PointTable_B_off, itilerow);
  Ang_data = PointTable_B_off->data;
  ibmat = b->size[0];
  for (itilerow = 0; itilerow < ibmat; itilerow++) {
    Ang_data[3 * itilerow] = b_data[itilerow];
    Ang_data[3 * itilerow + 1] = b_data[itilerow + b->size[0]];
    Ang_data[3 * itilerow + 2] = b_data[itilerow + b->size[0] * 2];
  }
  emxFree_real_T(&b);
  printf("A1 xyz: %f, %f, %f\n", AngProcess_data[0], AngProcess_data[1],
         AngProcess_data[2]);
  fflush(stdout);
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.c
 *
 * [EOF]
 */
