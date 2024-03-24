/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 22:01:39
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
  double c_N12_tmp;
  double d;
  double d1;
  double d_N12_tmp;
  double e_N12_tmp;
  double scale;
  double t;
  int comb[3];
  int b_loop_ub;
  int c_loop_ub;
  int combj;
  int i;
  int icomb;
  int loop_ub;
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
    i = temp->size[0] * temp->size[1];
    temp->size[0] = 1;
    temp->size[1] = x->size[0];
    emxEnsureCapacity_real_T(temp, i);
    icomb = x->size[0] - 1;
    for (i = 0; i <= icomb; i++) {
      temp->data[i] = (double)i + 1.0;
    }
  }
  emxInit_real_T(&order, 2);
  if (temp->size[1] == 1) {
    u = (unsigned int)temp->data[0];
    if (3U <= u) {
      i = order->size[0] * order->size[1];
      order->size[0] = 1;
      order->size[1] = 1;
      emxEnsureCapacity_real_T(order, i);
      order->data[0] = nCk(u, 3.0);
    }
  } else if (3 > temp->size[1]) {
    order->size[0] = 0;
    order->size[1] = 3;
  } else {
    nrows = (int)floor(nCk(temp->size[1], 3.0));
    i = order->size[0] * order->size[1];
    order->size[0] = nrows;
    order->size[1] = 3;
    emxEnsureCapacity_real_T(order, i);
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
          i = icomb + 2;
          for (icomb = i; icomb < 4; icomb++) {
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
  i = S->size[0] * S->size[1];
  S->size[0] = 3;
  S->size[1] = order->size[0];
  emxEnsureCapacity_real_T(S, i);
  icomb = 3 * order->size[0];
  for (i = 0; i < icomb; i++) {
    S->data[i] = 0.0;
  }
  emxInit_real_T(&XCenter, 1);
  emxInit_real_T(&YCenter, 1);
  emxInit_real_T(&ZCenter, 1);
  i = order->size[0];
  icomb = XCenter->size[0];
  XCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(XCenter, icomb);
  icomb = YCenter->size[0];
  YCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(YCenter, icomb);
  icomb = ZCenter->size[0];
  ZCenter->size[0] = order->size[0];
  emxEnsureCapacity_real_T(ZCenter, icomb);
  for (nmkpi = 0; nmkpi < i; nmkpi++) {
    d = order->data[nmkpi];
    S_idx_2 = order->data[nmkpi + order->size[0]];
    d1 = order->data[nmkpi + order->size[0] * 2];
    N12_tmp = x->data[(int)S_idx_2 - 1];
    P12_idx_1 = x->data[(int)d - 1];
    N12[0] = N12_tmp - P12_idx_1;
    b_N12_tmp = y->data[(int)S_idx_2 - 1];
    c_N12_tmp = y->data[(int)d - 1];
    N12[1] = b_N12_tmp - c_N12_tmp;
    d_N12_tmp = z->data[(int)S_idx_2 - 1];
    e_N12_tmp = z->data[(int)d - 1];
    N12[2] = d_N12_tmp - e_N12_tmp;
    XCenterMean = x->data[(int)d1 - 1];
    N23_idx_0 = XCenterMean - N12_tmp;
    ZCenterMean = y->data[(int)d1 - 1];
    N23_idx_1 = ZCenterMean - b_N12_tmp;
    N23_idx_2_tmp = z->data[(int)d1 - 1];
    N23_idx_2 = N23_idx_2_tmp - d_N12_tmp;
    Radius = N12[1] * N23_idx_2 - N23_idx_1 * N12[2];
    S_idx_1 = N23_idx_0 * N12[2] - N12[0] * N23_idx_2;
    S_idx_2 = N12[0] * N23_idx_1 - N23_idx_0 * N12[1];
    /* 方向向量 */
    scale = 3.3121686421112381E-170;
    absxk = fabs(Radius);
    if (absxk > 3.3121686421112381E-170) {
      d1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      d1 = t * t;
    }
    absxk = fabs(S_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      d1 = d1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      d1 += t * t;
    }
    absxk = fabs(S_idx_2);
    if (absxk > scale) {
      t = scale / absxk;
      d1 = d1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      d1 += t * t;
    }
    d1 = scale * sqrt(d1);
    S_idx_1 /= d1;
    S_idx_2 /= d1;
    S->data[3 * nmkpi] = Radius / d1;
    S->data[3 * nmkpi + 1] = S_idx_1;
    S->data[3 * nmkpi + 2] = S_idx_2;
    /*     %% 计算交点 */
    d1 = -((N12[0] * ((P12_idx_1 + N12_tmp) / 2.0) +
            N12[1] * ((c_N12_tmp + b_N12_tmp) / 2.0)) +
           N12[2] * ((e_N12_tmp + d_N12_tmp) / 2.0));
    S_idx_1 = (d1 * N23_idx_1 -
               N12[1] * -((N23_idx_0 * ((N12_tmp + XCenterMean) / 2.0) +
                           N23_idx_1 * ((b_N12_tmp + ZCenterMean) / 2.0)) +
                          N23_idx_2 * ((d_N12_tmp + N23_idx_2_tmp) / 2.0))) /
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
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  temp->size[1] = x->size[0];
  emxEnsureCapacity_real_T(temp, i);
  icomb = x->size[0];
  emxFree_real_T(&S);
  for (i = 0; i < icomb; i++) {
    temp->data[i] = 0.0;
  }
  i = x->size[0];
  for (nmkpi = 0; nmkpi < i; nmkpi++) {
    S_idx_1 = x->data[nmkpi] - XCenterMean;
    S_idx_2 = y->data[nmkpi] - N23_idx_0;
    d1 = z->data[nmkpi] - ZCenterMean;
    temp->data[nmkpi] = sqrt((S_idx_1 * S_idx_1 + S_idx_2 * S_idx_2) + d1 * d1);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  if (temp->size[1] == 0) {
    d1 = 0.0;
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
    d1 = temp->data[0];
    for (row = 2; row <= icomb; row++) {
      d1 += temp->data[row - 1];
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
      d1 += S_idx_1;
    }
  }
  Radius = d1 / (double)temp->size[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dv[0]);
  if (absxk > 3.3121686421112381E-170) {
    d1 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    d1 = t * t;
  }
  absxk = fabs(dv[1]);
  if (absxk > scale) {
    t = scale / absxk;
    d1 = d1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d1 += t * t;
  }
  absxk = fabs(dv[2]);
  if (absxk > scale) {
    t = scale / absxk;
    d1 = d1 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d1 += t * t;
  }
  d1 = scale * sqrt(d1);
  P23[0] = XCenterMean;
  P23[1] = N23_idx_0;
  P23[2] = ZCenterMean;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  d = dv[0] / d1;
  N23_idx_1 = d;
  N12[0] = XCenterMean + d;
  d = dv[1] / d1;
  P12_idx_1 = d;
  N12[1] = N23_idx_0 + d;
  d = dv[2] / d1;
  N12[2] = ZCenterMean + d;
  foot_of_perpendicular_from_a_point_to_a_line(P4, P23, N12, &e_N12_tmp,
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
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, i);
  icomb = temp->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    temp->data[i] = temp->data[i] * Radius + e_N12_tmp;
  }
  i = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  emxEnsureCapacity_real_T(Ylay0, i);
  icomb = Ylay0->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    Ylay0->data[i] = Ylay0->data[i] * Radius + N23_idx_2_tmp;
  }
  i = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  emxEnsureCapacity_real_T(Zlay0, i);
  icomb = Zlay0->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    Zlay0->data[i] = Zlay0->data[i] * Radius + N23_idx_2;
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
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)S_idx_2;
    emxEnsureCapacity_real_T(Layer, i);
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
            i = Layer->size[1];
            for (row = 0; row <= i - 3; row++) {
              Layer->data[row + 1] = d1 + ((double)row + 1.0) * S_idx_1;
            }
          }
        }
      }
    }
  }
  icomb = (int)(laynum * num);
  i = XCenter->size[0];
  XCenter->size[0] = icomb;
  emxEnsureCapacity_real_T(XCenter, i);
  for (i = 0; i < icomb; i++) {
    XCenter->data[i] = 0.0;
  }
  i = YCenter->size[0];
  YCenter->size[0] = icomb;
  emxEnsureCapacity_real_T(YCenter, i);
  for (i = 0; i < icomb; i++) {
    YCenter->data[i] = 0.0;
  }
  i = ZCenter->size[0];
  ZCenter->size[0] = icomb;
  emxEnsureCapacity_real_T(ZCenter, i);
  for (i = 0; i < icomb; i++) {
    ZCenter->data[i] = 0.0;
  }
  i = (int)laynum;
  if (0 <= (int)laynum - 1) {
    loop_ub = temp->size[1];
    b_loop_ub = Ylay0->size[1];
    c_loop_ub = Zlay0->size[1];
  }
  for (nmkpi = 0; nmkpi < i; nmkpi++) {
    S_idx_2 = (((double)nmkpi + 1.0) - 1.0) * num + 1.0;
    d1 = ((double)nmkpi + 1.0) * num;
    if (S_idx_2 > d1) {
      icomb = 1;
    } else {
      icomb = (int)S_idx_2;
    }
    S_idx_1 = Layer->data[nmkpi] * N23_idx_1;
    for (nblocks = 0; nblocks < loop_ub; nblocks++) {
      XCenter->data[(icomb + nblocks) - 1] = temp->data[nblocks] - S_idx_1;
    }
    if (S_idx_2 > d1) {
      icomb = 1;
    } else {
      icomb = (int)S_idx_2;
    }
    S_idx_1 = Layer->data[nmkpi] * P12_idx_1;
    for (nblocks = 0; nblocks < b_loop_ub; nblocks++) {
      YCenter->data[(icomb + nblocks) - 1] = Ylay0->data[nblocks] - S_idx_1;
    }
    if (S_idx_2 > d1) {
      icomb = 1;
    } else {
      icomb = (int)S_idx_2;
    }
    S_idx_1 = Layer->data[nmkpi] * d;
    for (nblocks = 0; nblocks < c_loop_ub; nblocks++) {
      ZCenter->data[(icomb + nblocks) - 1] = Zlay0->data[nblocks] - S_idx_1;
    }
  }
  emxFree_real_T(&Layer);
  emxFree_real_T(&Zlay0);
  emxFree_real_T(&Ylay0);
  emxFree_real_T(&temp);
  i = Point_test->size[0] * Point_test->size[1];
  Point_test->size[0] = XCenter->size[0];
  Point_test->size[1] = 3;
  emxEnsureCapacity_real_T(Point_test, i);
  icomb = XCenter->size[0];
  for (i = 0; i < icomb; i++) {
    Point_test->data[i] = XCenter->data[i];
  }
  emxFree_real_T(&XCenter);
  icomb = YCenter->size[0];
  for (i = 0; i < icomb; i++) {
    Point_test->data[i + Point_test->size[0]] = YCenter->data[i];
  }
  emxFree_real_T(&YCenter);
  icomb = ZCenter->size[0];
  for (i = 0; i < icomb; i++) {
    Point_test->data[i + Point_test->size[0] * 2] = ZCenter->data[i];
  }
  emxFree_real_T(&ZCenter);
}

/*
 * File trailer for Generate_multi_layered_measurement_points.c
 *
 * [EOF]
 */
