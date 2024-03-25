/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 25-Mar-2024 17:49:36
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

/*
 * -----------------------平均轴向量、圆心-----------------------
 *  xxx = x(1:3);
 *  yyy = y(1:3);
 *  zzz = z(1:3);
 *
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const emxArray_real_T *z
 *                double num
 *                double laynum
 *                const double P3[3]
 *                const double P4[3]
 *                emxArray_real_T *Point_test
 * Return Type  : void
 */
void Generate_multi_layered_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double num, double laynum, const double P3[3],
    const double P4[3], emxArray_real_T *Point_test)
{
  emxArray_real_T *Dist;
  emxArray_real_T *Layer;
  emxArray_real_T *Point_testx;
  emxArray_real_T *Point_testy;
  emxArray_real_T *Point_testz;
  emxArray_real_T *Ylay0;
  emxArray_real_T *Zlay0;
  double p23f[3];
  double p3[3];
  double Radius;
  double S_idx_0;
  double absxk;
  double p12f_idx_0;
  double p12f_idx_1;
  double p23_idx_0;
  double p23_idx_1;
  double p23_idx_2;
  double p2_idx_0;
  double p2_idx_1;
  double p2_idx_2;
  double pf_idx_0;
  double pf_idx_1;
  double pf_idx_2;
  double scale;
  double t;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  [s1,s2,s3,xcenter,ycenter,zcenter] =
   * Three_Points_Initial_Rough_Cylindrical_Judgment(xxx,yyy,zzz); */
  /* %%%%%%%%%%%%%%%%%%%% */
  /*  两条线段的重点，之后需要求中垂线 */
  p12f_idx_1 = x->data[0] - x->data[1];
  p23f[0] = x->data[0] - x->data[2];
  p12f_idx_0 = y->data[0] - y->data[1];
  p23f[1] = y->data[0] - y->data[2];
  p2_idx_2 = z->data[0] - z->data[1];
  p23f[2] = z->data[0] - z->data[2];
  pf_idx_0 = p12f_idx_0 * p23f[2] - p23f[1] * p2_idx_2;
  pf_idx_1 = p23f[0] * p2_idx_2 - p12f_idx_1 * p23f[2];
  pf_idx_2 = p12f_idx_1 * p23f[1] - p23f[0] * p12f_idx_0;
  /*  求两条线的中垂线 */
  p12f_idx_0 = pf_idx_1 * p2_idx_2 - p12f_idx_0 * pf_idx_2;
  p12f_idx_1 = p12f_idx_1 * pf_idx_2 - pf_idx_0 * p2_idx_2;
  p23_idx_0 = (x->data[1] + x->data[2]) / 2.0;
  p2_idx_0 = x->data[1] - x->data[2];
  p23_idx_1 = (y->data[1] + y->data[2]) / 2.0;
  p2_idx_1 = y->data[1] - y->data[2];
  p2_idx_2 = z->data[1] - z->data[2];
  p23f[0] = pf_idx_1 * p2_idx_2 - p2_idx_1 * pf_idx_2;
  p23f[1] = p2_idx_0 * pf_idx_2 - pf_idx_0 * p2_idx_2;
  /*  求在中垂线上投影的大小 */
  p12f_idx_1 = (((y->data[0] + y->data[1]) / 2.0 - p23_idx_1) * p12f_idx_0 -
                ((x->data[0] + x->data[1]) / 2.0 - p23_idx_0) * p12f_idx_1) /
               (p12f_idx_0 * p23f[1] - p23f[0] * p12f_idx_1);
  /*  得出距离 */
  /*  radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2); */
  scale = 3.3121686421112381E-170;
  p23_idx_0 += p23f[0] * p12f_idx_1;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    p2_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p2_idx_2 = t * t;
  }
  p23_idx_1 += p23f[1] * p12f_idx_1;
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    p2_idx_2 = p2_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p2_idx_2 += t * t;
  }
  p23_idx_2 = (z->data[1] + z->data[2]) / 2.0 +
              (pf_idx_0 * p2_idx_1 - p2_idx_0 * pf_idx_1) * p12f_idx_1;
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    p2_idx_2 = p2_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p2_idx_2 += t * t;
  }
  emxInit_real_T(&Dist, 2);
  p2_idx_2 = scale * sqrt(p2_idx_2);
  pf_idx_0 /= p2_idx_2;
  pf_idx_1 /= p2_idx_2;
  pf_idx_2 /= p2_idx_2;
  /* %%%%%%%%%%%%%%%%%%% */
  /*  -----------------------------计算参数------------------------------- */
  ib = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  Dist->size[1] = x->size[0];
  emxEnsureCapacity_real_T(Dist, ib);
  firstBlockLength = x->size[0];
  for (ib = 0; ib < firstBlockLength; ib++) {
    Dist->data[ib] = 0.0;
  }
  ib = x->size[0];
  for (nblocks = 0; nblocks < ib; nblocks++) {
    p12f_idx_1 = x->data[nblocks] - p23_idx_0;
    p2_idx_2 = y->data[nblocks] - p23_idx_1;
    p12f_idx_0 = z->data[nblocks] - p23_idx_2;
    Dist->data[nblocks] = sqrt((p12f_idx_1 * p12f_idx_1 + p2_idx_2 * p2_idx_2) +
                               p12f_idx_0 * p12f_idx_0);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  if (Dist->size[1] == 0) {
    p2_idx_2 = 0.0;
  } else {
    if (Dist->size[1] <= 1024) {
      firstBlockLength = Dist->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = Dist->size[1] / 1024;
      lastBlockLength = Dist->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    p2_idx_2 = Dist->data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      p2_idx_2 += Dist->data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) << 10;
      p12f_idx_0 = Dist->data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        p12f_idx_0 += Dist->data[(firstBlockLength + k) - 1];
      }
      p2_idx_2 += p12f_idx_0;
    }
  }
  Radius = p2_idx_2 / (double)Dist->size[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(pf_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    p2_idx_2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p2_idx_2 = t * t;
  }
  absxk = fabs(pf_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    p2_idx_2 = p2_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p2_idx_2 += t * t;
  }
  absxk = fabs(pf_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    p2_idx_2 = p2_idx_2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p2_idx_2 += t * t;
  }
  p2_idx_2 = scale * sqrt(p2_idx_2);
  p3[0] = p23_idx_0;
  p3[1] = p23_idx_1;
  p3[2] = p23_idx_2;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  pf_idx_0 /= p2_idx_2;
  S_idx_0 = pf_idx_0;
  p23f[0] = p23_idx_0 + pf_idx_0;
  pf_idx_0 = pf_idx_1 / p2_idx_2;
  p23_idx_0 = pf_idx_0;
  p23f[1] = p23_idx_1 + pf_idx_0;
  pf_idx_0 = pf_idx_2 / p2_idx_2;
  p23f[2] = p23_idx_2 + pf_idx_0;
  foot_of_perpendicular_from_a_point_to_a_line(P4, p3, p23f, &p12f_idx_1,
                                               &p2_idx_2, &p2_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, p3, p23f, &p12f_idx_0,
                                               &p2_idx_1, &p23_idx_2);
  scale = 3.3121686421112381E-170;
  absxk = fabs(p12f_idx_0 - p12f_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    p12f_idx_0 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    p12f_idx_0 = t * t;
  }
  absxk = fabs(p2_idx_1 - p2_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_0 = p12f_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_0 += t * t;
  }
  absxk = fabs(p23_idx_2 - p2_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    p12f_idx_0 = p12f_idx_0 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    p12f_idx_0 += t * t;
  }
  emxInit_real_T(&Ylay0, 2);
  emxInit_real_T(&Zlay0, 2);
  p12f_idx_0 = scale * sqrt(p12f_idx_0);
  /*  -----------------------------生成抽样点------------------------------- */
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(pf_idx_0, sqrt(S_idx_0 * S_idx_0 + p23_idx_0 * p23_idx_0)),
      rt_atan2d_snf(p23_idx_0, S_idx_0), num, Dist, Ylay0, Zlay0);
  /*  ----------------------------移动到原点------------------------------- */
  ib = Dist->size[0] * Dist->size[1];
  Dist->size[0] = 1;
  emxEnsureCapacity_real_T(Dist, ib);
  firstBlockLength = Dist->size[1] - 1;
  for (ib = 0; ib <= firstBlockLength; ib++) {
    Dist->data[ib] = Dist->data[ib] * Radius + p12f_idx_1;
  }
  ib = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  emxEnsureCapacity_real_T(Ylay0, ib);
  firstBlockLength = Ylay0->size[1] - 1;
  for (ib = 0; ib <= firstBlockLength; ib++) {
    Ylay0->data[ib] = Ylay0->data[ib] * Radius + p2_idx_2;
  }
  ib = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  emxEnsureCapacity_real_T(Zlay0, ib);
  firstBlockLength = Zlay0->size[1] - 1;
  for (ib = 0; ib <= firstBlockLength; ib++) {
    Zlay0->data[ib] = Zlay0->data[ib] * Radius + p2_idx_0;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  p12f_idx_1 = 0.2 * p12f_idx_0;
  p12f_idx_0 *= 0.8;
  emxInit_real_T(&Layer, 2);
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    p2_idx_2 = floor(laynum);
    ib = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)p2_idx_2;
    emxEnsureCapacity_real_T(Layer, ib);
    if ((int)p2_idx_2 >= 1) {
      firstBlockLength = (int)p2_idx_2 - 1;
      Layer->data[(int)floor(laynum) - 1] = p12f_idx_0;
      if (Layer->size[1] >= 2) {
        Layer->data[0] = p12f_idx_1;
        if (Layer->size[1] >= 3) {
          if ((p12f_idx_1 == -p12f_idx_0) && ((int)p2_idx_2 > 2)) {
            p12f_idx_0 /= (double)(int)p2_idx_2 - 1.0;
            for (k = 2; k <= firstBlockLength; k++) {
              Layer->data[k - 1] =
                  (double)(((k << 1) - (int)p2_idx_2) - 1) * p12f_idx_0;
            }
            if (((int)p2_idx_2 & 1) == 1) {
              Layer->data[(int)p2_idx_2 >> 1] = 0.0;
            }
          } else {
            p12f_idx_0 =
                (p12f_idx_0 - p12f_idx_1) / ((double)Layer->size[1] - 1.0);
            ib = Layer->size[1];
            for (k = 0; k <= ib - 3; k++) {
              Layer->data[k + 1] = p12f_idx_1 + ((double)k + 1.0) * p12f_idx_0;
            }
          }
        }
      }
    }
  }
  emxInit_real_T(&Point_testx, 1);
  firstBlockLength = (int)(laynum * num);
  ib = Point_testx->size[0];
  Point_testx->size[0] = firstBlockLength;
  emxEnsureCapacity_real_T(Point_testx, ib);
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_testx->data[ib] = 0.0;
  }
  emxInit_real_T(&Point_testy, 1);
  ib = Point_testy->size[0];
  Point_testy->size[0] = firstBlockLength;
  emxEnsureCapacity_real_T(Point_testy, ib);
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_testy->data[ib] = 0.0;
  }
  emxInit_real_T(&Point_testz, 1);
  ib = Point_testz->size[0];
  Point_testz->size[0] = firstBlockLength;
  emxEnsureCapacity_real_T(Point_testz, ib);
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_testz->data[ib] = 0.0;
  }
  ib = (int)laynum;
  for (nblocks = 0; nblocks < ib; nblocks++) {
    p2_idx_2 = (((double)nblocks + 1.0) - 1.0) * num + 1.0;
    p12f_idx_0 = ((double)nblocks + 1.0) * num;
    if (p2_idx_2 > p12f_idx_0) {
      hi = 1;
    } else {
      hi = (int)p2_idx_2;
    }
    p12f_idx_1 = Layer->data[nblocks] * S_idx_0;
    firstBlockLength = Dist->size[1];
    for (lastBlockLength = 0; lastBlockLength < firstBlockLength;
         lastBlockLength++) {
      Point_testx->data[(hi + lastBlockLength) - 1] =
          Dist->data[lastBlockLength] - p12f_idx_1;
    }
    if (p2_idx_2 > p12f_idx_0) {
      hi = 1;
    } else {
      hi = (int)p2_idx_2;
    }
    p12f_idx_1 = Layer->data[nblocks] * p23_idx_0;
    firstBlockLength = Ylay0->size[1];
    for (lastBlockLength = 0; lastBlockLength < firstBlockLength;
         lastBlockLength++) {
      Point_testy->data[(hi + lastBlockLength) - 1] =
          Ylay0->data[lastBlockLength] - p12f_idx_1;
    }
    if (p2_idx_2 > p12f_idx_0) {
      hi = 1;
    } else {
      hi = (int)p2_idx_2;
    }
    p12f_idx_1 = Layer->data[nblocks] * pf_idx_0;
    firstBlockLength = Zlay0->size[1];
    for (lastBlockLength = 0; lastBlockLength < firstBlockLength;
         lastBlockLength++) {
      Point_testz->data[(hi + lastBlockLength) - 1] =
          Zlay0->data[lastBlockLength] - p12f_idx_1;
    }
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&Dist);
  ib = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = Point_testx->size[0];
  emxEnsureCapacity_real_T(Point_test, ib);
  firstBlockLength = Point_testx->size[0];
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_test->data[3 * ib] = Point_testx->data[ib];
  }
  emxFree_real_T(&Point_testx);
  firstBlockLength = Point_testy->size[0];
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_test->data[3 * ib + 1] = Point_testy->data[ib];
  }
  emxFree_real_T(&Point_testy);
  firstBlockLength = Point_testz->size[0];
  for (ib = 0; ib < firstBlockLength; ib++) {
    Point_test->data[3 * ib + 2] = Point_testz->data[ib];
  }
  emxFree_real_T(&Point_testz);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
