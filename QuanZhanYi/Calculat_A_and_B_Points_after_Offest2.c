/*
 * File: Calculat_A_and_B_Points_after_Offest2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 05-Aug-2024 00:10:26
 */

/* Include Files */
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double MTaon[3]
 *                const double Mcenter[3]
 *                double Mradial
 *                const double PAB[3]
 *                double phi
 *                const emxArray_real_T *Ang
 *                const emxArray_real_T *toff
 *                const emxArray_real_T *roff
 *                const int PointTable_A_off_size[2]
 * Return Type  : void
 */
void Calculat_A_and_B_Points_after_Offest2(
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, const emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    const int PointTable_A_off_size[2])
{
  (void)MTaon;
  (void)Mcenter;
  (void)Mradial;
  (void)PAB;
  (void)phi;
  (void)Ang;
  (void)toff;
  (void)roff;
  (void)PointTable_A_off_size;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  计算phi面的法向量D */
  /*  计算0度线向量E */
  /*  圆心点 */
  /*  三个点定义 */
  /*  斜率计算 */
  /*  P1点在轴线上的投影坐标 */
  /*  面法向量第二个点（与圆心点构成phi面的法向量） */
  /*  起始点 （测点半圆的中点） */
  /*  构建旋转矩阵 */
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  /*  选择旋转点集合 */
  /*  圆心点 */
  /*  面法向量第二个点 */
  /*  起始点 （测点半圆的中点，0度线） */
  /*  旋转至【0，0，1】的点集合 */
  /*  旋转、平移后 法向量 */
  /*  法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3 */
  /*  起始角度 */
  /*  !!!!!!!后面的点以这个为基础 */
  /*  第一步修正 */
  /*  第二步处理 */
  /*  调用计算坐标 */
  /* A check that is always false is detected at compile-time. Eliminating code
   * that follows. */
}

/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.c
 *
 * [EOF]
 */
