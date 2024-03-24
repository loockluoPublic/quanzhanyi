/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:46:36
 */

/* Include Files */
#include "Generate_multi_layered_measurement_points.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "mean.h"
#include "nchoosek.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <emscripten.h>
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
 * --------------------------3点组合抽样------------------------------
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
EMSCRIPTEN_KEEPALIVE
void Generate_multi_layered_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double num, double laynum, const double P3[3],
    const double P4[3], emxArray_real_T *Point_test)
{
  emxArray_real_T *Layer;
  emxArray_real_T *Point_testx;
  emxArray_real_T *Point_testy;
  emxArray_real_T *Point_testz;
  emxArray_real_T *S;
  emxArray_real_T *XCenter;
  emxArray_real_T *YCenter;
  emxArray_real_T *Ylay0;
  emxArray_real_T *ZCenter;
  emxArray_real_T *Zlay0;
  emxArray_real_T *order;
  emxArray_real_T *temp;
  double N12[3];
  double P23[3];
  double dv[3];
  double N12_tmp;
  double N23_idx_0;
  double N23_idx_1;
  double N23_idx_2;
  double N23_idx_2_tmp;
  double P12_idx_1;
  double Radius;
  double S_idx_1;
  double S_idx_2;
  double XCenterMean;
  double ZCenterMean;
  double absxk;
  double b_N12_tmp;
  double b_y;
  double c_N12_tmp;
  double d;
  double d1;
  double d_N12_tmp;
  double scale;
  double t;
  int comb[3];
  int combj;
  int icomb;
  int nblocks;
  int nmkpi;
  int nrows;
  int row;
  unsigned int u;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  emxInit_real_T(&temp, 2);
  if (x->size[0] < 1) {
    temp->size[0] = 1;
    temp->size[1] = 0;
  } else {
    nblocks = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = x->size[0];
    emxEnsureCapacity_real_T(temp, nblocks);
    icomb = x->size[0] - 1;
    for (nblocks = 0; nblocks <= icomb; nblocks++) {
      temp->data[nblocks] = (double)nblocks + 1.0;
    }
  }
  emxInit_real_T(&order, 2);
  if (temp->size[1] == 1) {
    u = (unsigned int)temp->data[0];
    if (3U <= u) {
      nblocks = order->size[0] * order->size[1];
      order->size[0] = 1;
      order->size[1] = 1;
      emxEnsureCapacity_real_T(order, nblocks);
      order->data[0] = nCk(u, 3.0);
    }
  } else if (3 > temp->size[1]) {
    order->size[0] = 0;
    order->size[1] = 3;
  } else {
    nrows = (int)floor(nCk(temp->size[1], 3.0));
    nblocks = order->size[0] * order->size[1];
    order->size[0] = nrows;
    order->size[1] = 3;
    emxEnsureCapacity_real_T(order, nblocks);
    comb[0] = 1;
    comb[1] = 2;
    comb[2] = 3;
    icomb = 2;
    nmkpi = temp->size[1];
    for (row = 0; row < nrows; row++) {
      order->data[row] = (unsigned int)temp->data[comb[0] - 1];
      order->data[row + order->size[0]] = (unsigned int)temp->data[comb[1] - 1];
      order->data[row + order->size[0] * 2] =
          (unsigned int)temp->data[comb[2] - 1];
      if (icomb + 1 > 0) {
        nblocks = comb[icomb];
        combj = comb[icomb] + 1;
        comb[icomb]++;
        if (nblocks + 1 < nmkpi) {
          nblocks = icomb + 2;
          for (icomb = nblocks; icomb < 4; icomb++) {
            combj++;
            comb[icomb - 1] = combj;
          }
          icomb = 2;
          nmkpi = temp->size[1];
        } else {
          icomb--;
          nmkpi--;
        }
      }
    }
  }
  emxInit_real_T(&S, 2);
  /*  -----------------------平均轴向量、圆心----------------------- */
  nblocks = S->size[0] * S->size[1];
  S->size[0] = 3;
  S->size[1] = order->size[0];
  emxEnsureCapacity_real_T(S, nblocks);
  icomb = 3 * order->size[0];
  for (nblocks = 0; nblocks < icomb; nblocks++) {
    S->data[nblocks] = 0.0;
  }
  emxInit_real_T(&XCenter, 1);
  emxInit_real_T(&YCenter, 1);
  emxInit_real_T(&ZCenter, 1);
  nblocks = order->size[0];
  icomb = XCenter->size[0];
  XCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(XCenter, icomb);
  icomb = YCenter->size[0];
  YCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(YCenter, icomb);
  icomb = ZCenter->size[0];
  ZCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(ZCenter, icomb);
  for (nmkpi = 0; nmkpi < nblocks; nmkpi++) {
    d = order->data[nmkpi];
    S_idx_2 = order->data[nmkpi + order->size[0]];
    S_idx_1 = order->data[nmkpi + order->size[0] * 2];
    N12_tmp = x->data[(int)S_idx_2 - 1];
    d1 = x->data[(int)d - 1];
    N12[0] = N12_tmp - d1;
    b_N12_tmp = y->data[(int)S_idx_2 - 1];
    P12_idx_1 = y->data[(int)d - 1];
    N12[1] = b_N12_tmp - P12_idx_1;
    c_N12_tmp = z->data[(int)S_idx_2 - 1];
    d_N12_tmp = z->data[(int)d - 1];
    N12[2] = c_N12_tmp - d_N12_tmp;
    XCenterMean = x->data[(int)S_idx_1 - 1];
    N23_idx_0 = XCenterMean - N12_tmp;
    ZCenterMean = y->data[(int)S_idx_1 - 1];
    N23_idx_1 = ZCenterMean - b_N12_tmp;
    N23_idx_2_tmp = z->data[(int)S_idx_1 - 1];
    N23_idx_2 = N23_idx_2_tmp - c_N12_tmp;
    Radius = N12[1] * N23_idx_2 - N23_idx_1 * N12[2];
    S_idx_1 = N23_idx_0 * N12[2] - N12[0] * N23_idx_2;
    S_idx_2 = N12[0] * N23_idx_1 - N23_idx_0 * N12[1];
    /* 方向向量 */
    scale = 3.3121686421112381E-170;
    absxk = fabs(Radius);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(S_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = fabs(S_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    b_y = scale * sqrt(b_y);
    S_idx_1 /= b_y;
    S_idx_2 /= b_y;
    S->data[3 * nmkpi] = Radius / b_y;
    S->data[3 * nmkpi + 1] = S_idx_1;
    S->data[3 * nmkpi + 2] = S_idx_2;
    /*     %% 计算交点 */
    d1 = -((N12[0] * ((d1 + N12_tmp) / 2.0) +
            N12[1] * ((P12_idx_1 + b_N12_tmp) / 2.0)) +
           N12[2] * ((d_N12_tmp + c_N12_tmp) / 2.0));
    S_idx_1 = (d1 * N23_idx_1 -
               N12[1] * -((N23_idx_0 * ((N12_tmp + XCenterMean) / 2.0) +
                           N23_idx_1 * ((b_N12_tmp + ZCenterMean) / 2.0)) +
                          N23_idx_2 * ((c_N12_tmp + N23_idx_2_tmp) / 2.0))) /
              Radius;
    YCenter->data[nmkpi] = -(N12[2] * S_idx_1 + d1) / N12[1];
    XCenter->data[nmkpi] = 0.0;
    ZCenter->data[nmkpi] = S_idx_1;
  }
  emxFree_real_T(&order);
  XCenterMean = mean(XCenter);
  N23_idx_0 = mean(YCenter);
  ZCenterMean = mean(ZCenter);
  b_mean(S, dv);
  /*  -----------------------------计算参数------------------------------- */
  nblocks = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = x->size[0];
  emxEnsureCapacity_real_T(temp, nblocks);
  icomb = x->size[0];
  emxFree_real_T(&S);
  emxFree_real_T(&ZCenter);
  emxFree_real_T(&YCenter);
  emxFree_real_T(&XCenter);
  for (nblocks = 0; nblocks < icomb; nblocks++) {
    temp->data[nblocks] = 0.0;
  }
  nblocks = x->size[0];
  for (nmkpi = 0; nmkpi < nblocks; nmkpi++) {
    S_idx_1 = x->data[nmkpi] - XCenterMean;
    S_idx_2 = y->data[nmkpi] - N23_idx_0;
    d1 = z->data[nmkpi] - ZCenterMean;
    temp->data[nmkpi] = sqrt((S_idx_1 * S_idx_1 + S_idx_2 * S_idx_2) + d1 * d1);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  if (temp->size[1] == 0) {
    b_y = 0.0;
  } else {
    if (temp->size[1] <= 1024) {
      icomb = temp->size[1];
      nrows = 0;
      nblocks = 1;
    } else {
      icomb = 1024;
      nblocks = temp->size[1] / 1024;
      nrows = temp->size[1] - (nblocks << 10);
      if (nrows > 0) {
        nblocks++;
      } else {
        nrows = 1024;
      }
    }
    b_y = temp->data[0];
    for (row = 2; row <= icomb; row++) {
      b_y += temp->data[row - 1];
    }
    for (combj = 2; combj <= nblocks; combj++) {
      icomb = (combj - 1) << 10;
      S_idx_1 = temp->data[icomb];
      if (combj == nblocks) {
        nmkpi = nrows;
      } else {
        nmkpi = 1024;
      }
      for (row = 2; row <= nmkpi; row++) {
        S_idx_1 += temp->data[(icomb + row) - 1];
      }
      b_y += S_idx_1;
    }
  }
  Radius = b_y / (double)temp->size[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dv[0]);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    b_y = t * t;
  }
  absxk = fabs(dv[1]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  absxk = fabs(dv[2]);
  if (absxk > scale) {
    t = scale / absxk;
    b_y = b_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    b_y += t * t;
  }
  b_y = scale * sqrt(b_y);
  P23[0] = XCenterMean;
  P23[1] = N23_idx_0;
  P23[2] = ZCenterMean;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  d = dv[0] / b_y;
  N23_idx_1 = d;
  N12[0] = XCenterMean + d;
  d = dv[1] / b_y;
  P12_idx_1 = d;
  N12[1] = N23_idx_0 + d;
  d = dv[2] / b_y;
  N12[2] = ZCenterMean + d;
  foot_of_perpendicular_from_a_point_to_a_line(P4, P23, N12, &d_N12_tmp,
                                               &N23_idx_2_tmp, &N23_idx_2);
  foot_of_perpendicular_from_a_point_to_a_line(P3, P23, N12, &S_idx_1, &S_idx_2,
                                               &d1);
  scale = 3.3121686421112381E-170;
  absxk = fabs(N12[0] - XCenterMean);
  if (absxk > 3.3121686421112381E-170) {
    S_idx_1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    S_idx_1 = t * t;
  }
  absxk = fabs(N12[1] - N23_idx_0);
  if (absxk > scale) {
    t = scale / absxk;
    S_idx_1 = S_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    S_idx_1 += t * t;
  }
  absxk = fabs(N12[2] - ZCenterMean);
  if (absxk > scale) {
    t = scale / absxk;
    S_idx_1 = S_idx_1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    S_idx_1 += t * t;
  }
  emxInit_real_T(&Ylay0, 2);
  emxInit_real_T(&Zlay0, 2);
  S_idx_1 = scale * sqrt(S_idx_1);
  /*  -----------------------------生成抽样点------------------------------- */
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(d, sqrt(N23_idx_1 * N23_idx_1 + P12_idx_1 * P12_idx_1)),
      rt_atan2d_snf(P12_idx_1, N23_idx_1), num, temp, Ylay0, Zlay0);
  /*  ----------------------------移动到原点------------------------------- */
  nblocks = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, nblocks);
  icomb = temp->size[1] - 1;
  for (nblocks = 0; nblocks <= icomb; nblocks++) {
    temp->data[nblocks] = temp->data[nblocks] * Radius + d_N12_tmp;
  }
  nblocks = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  emxEnsureCapacity_real_T(Ylay0, nblocks);
  icomb = Ylay0->size[1] - 1;
  for (nblocks = 0; nblocks <= icomb; nblocks++) {
    Ylay0->data[nblocks] = Ylay0->data[nblocks] * Radius + N23_idx_2_tmp;
  }
  nblocks = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  emxEnsureCapacity_real_T(Zlay0, nblocks);
  icomb = Zlay0->size[1] - 1;
  for (nblocks = 0; nblocks <= icomb; nblocks++) {
    Zlay0->data[nblocks] = Zlay0->data[nblocks] * Radius + N23_idx_2;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  d1 = 0.2 * S_idx_1;
  S_idx_1 *= 0.8;
  emxInit_real_T(&Layer, 2);
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    S_idx_2 = floor(laynum);
    nblocks = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)S_idx_2;
    emxEnsureCapacity_real_T(Layer, nblocks);
    if ((int)S_idx_2 >= 1) {
      icomb = (int)S_idx_2 - 1;
      Layer->data[(int)floor(laynum) - 1] = S_idx_1;
      if (Layer->size[1] >= 2) {
        Layer->data[0] = d1;
        if (Layer->size[1] >= 3) {
          if ((d1 == -S_idx_1) && ((int)S_idx_2 > 2)) {
            S_idx_1 /= (double)(int)S_idx_2 - 1.0;
            for (row = 2; row <= icomb; row++) {
              Layer->data[row - 1] =
                  (double)(((row << 1) - (int)S_idx_2) - 1) * S_idx_1;
            }
            if (((int)S_idx_2 & 1) == 1) {
              Layer->data[(int)S_idx_2 >> 1] = 0.0;
            }
          } else {
            S_idx_1 = (S_idx_1 - d1) / ((double)Layer->size[1] - 1.0);
            nblocks = Layer->size[1];
            for (row = 0; row <= nblocks - 3; row++) {
              Layer->data[row + 1] = d1 + ((double)row + 1.0) * S_idx_1;
            }
          }
        }
      }
    }
  }
  emxInit_real_T(&Point_testx, 2);
  emxInit_real_T(&Point_testy, 2);
  emxInit_real_T(&Point_testz, 2);
  nblocks = Point_testx->size[0] * Point_testx->size[1];
  Point_testx->size[0] = 1;
  icomb = (int)laynum;
  Point_testx->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(Point_testx, nblocks);
  nblocks = Point_testy->size[0] * Point_testy->size[1];
  Point_testy->size[0] = 1;
  Point_testy->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(Point_testy, nblocks);
  nblocks = Point_testz->size[0] * Point_testz->size[1];
  Point_testz->size[0] = 1;
  Point_testz->size[1] = (int)laynum;
  emxEnsureCapacity_real_T(Point_testz, nblocks);
  for (nmkpi = 0; nmkpi < icomb; nmkpi++) {
    S_idx_2 = Layer->data[nmkpi];
    Point_testx->data[nmkpi] = temp->data[0] - S_idx_2 * N23_idx_1;
    Point_testy->data[nmkpi] = Ylay0->data[0] - S_idx_2 * P12_idx_1;
    Point_testz->data[nmkpi] = Zlay0->data[0] - S_idx_2 * d;
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&temp);
  nblocks = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = 3;
  Point_test->size[1] = Point_testx->size[1];
  emxEnsureCapacity_real_T(Point_test, nblocks);
  icomb = Point_testx->size[1];
  for (nblocks = 0; nblocks < icomb; nblocks++) {
    Point_test->data[3 * nblocks] = Point_testx->data[nblocks];
  }
  emxFree_real_T(&Point_testx);
  icomb = Point_testy->size[1];
  for (nblocks = 0; nblocks < icomb; nblocks++) {
    Point_test->data[3 * nblocks + 1] = Point_testy->data[nblocks];
  }
  emxFree_real_T(&Point_testy);
  icomb = Point_testz->size[1];
  for (nblocks = 0; nblocks < icomb; nblocks++) {
    Point_test->data[3 * nblocks + 2] = Point_testz->data[nblocks];
  }
  emxFree_real_T(&Point_testz);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
