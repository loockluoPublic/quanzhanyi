/*
 * File: Generate_multi_layered_measurement_points.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 23:35:55
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
#include <math.h>
#include <stdio.h>

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
void Generate_multi_layered_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double num, double laynum, const double P3[3],
    const double P4[3], emxArray_real_T *Point_test)
{

  printf("收到的 num %f", num);
  printf("收到的 num %f \n", num);
  emxArray_real_T *Layer;
  emxArray_real_T *S;
  emxArray_real_T *XCenter;
  emxArray_real_T *YCenter;
  emxArray_real_T *Ylay0;
  emxArray_real_T *ZCenter;
  emxArray_real_T *Zlay0;
  emxArray_real_T *order;
  emxArray_real_T *temp;
  double P2[3];
  double p3[3];
  double d;
  double p12f_idx_1;
  double p1_idx_0;
  double p1_idx_1;
  double p1_idx_2;
  double p23_idx_0;
  double p23_idx_2;
  double p23f_idx_0;
  double p23f_idx_1;
  double p23f_idx_2;
  double p2_idx_0;
  double p2_idx_1;
  double p2_idx_2;
  double pf_idx_0;
  double pf_idx_1;
  double pf_idx_2;
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
    p1_idx_0 = x->data[(int)d - 1];
    p1_idx_1 = y->data[(int)d - 1];
    p1_idx_2 = z->data[(int)d - 1];
    d = order->data[nmkpi + order->size[0]];
    p2_idx_0 = x->data[(int)d - 1];
    p2_idx_1 = y->data[(int)d - 1];
    p2_idx_2 = z->data[(int)d - 1];
    d = order->data[nmkpi + order->size[0] * 2];
    p3[0] = x->data[(int)d - 1];
    p3[1] = y->data[(int)d - 1];
    p3[2] = z->data[(int)d - 1];
    /*  if any(pf == 0) */
    /*      error('三个点不能共线！！'); */
    /*  end */
    /*  两条线段的重点，之后需要求中垂线 */
    P2[0] = p1_idx_0 - p2_idx_0;
    p23f_idx_0 = p1_idx_0 - p3[0];
    p1_idx_0 = (p1_idx_0 + p2_idx_0) / 2.0;
    P2[1] = p1_idx_1 - p2_idx_1;
    p23f_idx_1 = p1_idx_1 - p3[1];
    p1_idx_1 = (p1_idx_1 + p2_idx_1) / 2.0;
    P2[2] = p1_idx_2 - p2_idx_2;
    p23f_idx_2 = p1_idx_2 - p3[2];
    pf_idx_0 = P2[1] * p23f_idx_2 - p23f_idx_1 * P2[2];
    pf_idx_1 = p23f_idx_0 * P2[2] - P2[0] * p23f_idx_2;
    pf_idx_2 = P2[0] * p23f_idx_1 - p23f_idx_0 * P2[1];
    /*  求两条线的中垂线 */
    p1_idx_2 = pf_idx_1 * P2[2] - P2[1] * pf_idx_2;
    p12f_idx_1 = P2[0] * pf_idx_2 - pf_idx_0 * P2[2];
    p23_idx_0 = (p2_idx_0 + p3[0]) / 2.0;
    p2_idx_0 -= p3[0];
    p23f_idx_2 = (p2_idx_1 + p3[1]) / 2.0;
    p2_idx_1 -= p3[1];
    p23_idx_2 = (p2_idx_2 + p3[2]) / 2.0;
    p2_idx_2 -= p3[2];
    p23f_idx_0 = pf_idx_1 * p2_idx_2 - p2_idx_1 * pf_idx_2;
    p23f_idx_1 = p2_idx_0 * pf_idx_2 - pf_idx_0 * p2_idx_2;
    /*  求在中垂线上投影的大小 */
    p1_idx_2 = ((p1_idx_1 - p23f_idx_2) * p1_idx_2 -
                (p1_idx_0 - p23_idx_0) * p12f_idx_1) /
               (p1_idx_2 * p23f_idx_1 - p23f_idx_0 * p12f_idx_1);
    /*  得出距离 */
    p23_idx_0 += p23f_idx_0 * p1_idx_2;
    p23f_idx_2 += p23f_idx_1 * p1_idx_2;
    p23_idx_2 += (pf_idx_0 * p2_idx_1 - p2_idx_0 * pf_idx_1) * p1_idx_2;
    /*  radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2); */
    XCenter->data[nmkpi] = p23_idx_0;
    YCenter->data[nmkpi] = p23f_idx_2;
    ZCenter->data[nmkpi] = p23_idx_2;
    S->data[3 * nmkpi] = pf_idx_0;
    S->data[3 * nmkpi + 1] = pf_idx_1;
    S->data[3 * nmkpi + 2] = pf_idx_2;
  }
  emxFree_real_T(&order);
  p1_idx_1 = mean(XCenter);
  p2_idx_2 = mean(YCenter);
  p2_idx_0 = mean(ZCenter);
  b_mean(S, P2);
  p23f_idx_0 = P2[0];
  p23f_idx_1 = P2[1];
  p23f_idx_2 = P2[2];
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
    p12f_idx_1 = x->data[nmkpi] - p1_idx_1;
    p1_idx_2 = y->data[nmkpi] - p2_idx_2;
    pf_idx_1 = z->data[nmkpi] - p2_idx_0;
    temp->data[nmkpi] = sqrt((p12f_idx_1 * p12f_idx_1 + p1_idx_2 * p1_idx_2) +
                             pf_idx_1 * pf_idx_1);
  }
  /* %%%%%%%           圆柱参数          %%%%%%%%%%% */
  if (temp->size[1] == 0) {
    p12f_idx_1 = 0.0;
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
    p12f_idx_1 = temp->data[0];
    for (row = 2; row <= icomb; row++) {
      p12f_idx_1 += temp->data[row - 1];
    }
    for (combj = 2; combj <= nblocks; combj++) {
      icomb = (combj - 1) << 10;
      p1_idx_2 = temp->data[icomb];
      if (combj == nblocks) {
        nmkpi = nrows;
      } else {
        nmkpi = 1024;
      }
      for (row = 2; row <= nmkpi; row++) {
        p1_idx_2 += temp->data[(icomb + row) - 1];
      }
      p12f_idx_1 += p1_idx_2;
    }
  }
  p1_idx_0 = p12f_idx_1 / (double)temp->size[1];
  pf_idx_1 = 3.3121686421112381E-170;
  pf_idx_2 = fabs(P2[0]);
  if (pf_idx_2 > 3.3121686421112381E-170) {
    p12f_idx_1 = 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / 3.3121686421112381E-170;
    p12f_idx_1 = p23_idx_0 * p23_idx_0;
  }
  pf_idx_2 = fabs(P2[1]);
  if (pf_idx_2 > pf_idx_1) {
    p23_idx_0 = pf_idx_1 / pf_idx_2;
    p12f_idx_1 = p12f_idx_1 * p23_idx_0 * p23_idx_0 + 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / pf_idx_1;
    p12f_idx_1 += p23_idx_0 * p23_idx_0;
  }
  pf_idx_2 = fabs(P2[2]);
  if (pf_idx_2 > pf_idx_1) {
    p23_idx_0 = pf_idx_1 / pf_idx_2;
    p12f_idx_1 = p12f_idx_1 * p23_idx_0 * p23_idx_0 + 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / pf_idx_1;
    p12f_idx_1 += p23_idx_0 * p23_idx_0;
  }
  p12f_idx_1 = pf_idx_1 * sqrt(p12f_idx_1);
  p3[0] = p1_idx_1;
  p3[1] = p2_idx_2;
  p3[2] = p2_idx_0;
  /* -------------------------管路确定范围（轴线端点）---------------------- */
  d = p23f_idx_0 / p12f_idx_1;
  p23f_idx_0 = d;
  P2[0] = p1_idx_1 + d;
  d = p23f_idx_1 / p12f_idx_1;
  p23f_idx_1 = d;
  P2[1] = p2_idx_2 + d;
  d = p23f_idx_2 / p12f_idx_1;
  P2[2] = p2_idx_0 + d;
  foot_of_perpendicular_from_a_point_to_a_line(P4, p3, P2, &p23f_idx_2,
                                               &p23_idx_2, &pf_idx_0);
  foot_of_perpendicular_from_a_point_to_a_line(P3, p3, P2, &p1_idx_2,
                                               &p12f_idx_1, &pf_idx_1);
  pf_idx_1 = 3.3121686421112381E-170;
  pf_idx_2 = fabs(P2[0] - p1_idx_1);
  if (pf_idx_2 > 3.3121686421112381E-170) {
    p1_idx_2 = 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / 3.3121686421112381E-170;
    p1_idx_2 = p23_idx_0 * p23_idx_0;
  }
  pf_idx_2 = fabs(P2[1] - p2_idx_2);
  if (pf_idx_2 > pf_idx_1) {
    p23_idx_0 = pf_idx_1 / pf_idx_2;
    p1_idx_2 = p1_idx_2 * p23_idx_0 * p23_idx_0 + 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / pf_idx_1;
    p1_idx_2 += p23_idx_0 * p23_idx_0;
  }
  pf_idx_2 = fabs(P2[2] - p2_idx_0);
  if (pf_idx_2 > pf_idx_1) {
    p23_idx_0 = pf_idx_1 / pf_idx_2;
    p1_idx_2 = p1_idx_2 * p23_idx_0 * p23_idx_0 + 1.0;
    pf_idx_1 = pf_idx_2;
  } else {
    p23_idx_0 = pf_idx_2 / pf_idx_1;
    p1_idx_2 += p23_idx_0 * p23_idx_0;
  }
  emxInit_real_T(&Ylay0, 2);
  emxInit_real_T(&Zlay0, 2);
  p1_idx_2 = pf_idx_1 * sqrt(p1_idx_2);
  /*  -----------------------------生成抽样点------------------------------- */
  generate_unit_circle_with_normal_vector(
      rt_atan2d_snf(d, sqrt(p23f_idx_0 * p23f_idx_0 + p23f_idx_1 * p23f_idx_1)),
      rt_atan2d_snf(p23f_idx_1, p23f_idx_0), num, temp, Ylay0, Zlay0);
  /*  ----------------------------移动到原点------------------------------- */
  i = temp->size[0] * temp->size[1];
  temp->size[0] = 1;
  emxEnsureCapacity_real_T(temp, i);
  icomb = temp->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    temp->data[i] = temp->data[i] * p1_idx_0 + p23f_idx_2;
  }
  i = Ylay0->size[0] * Ylay0->size[1];
  Ylay0->size[0] = 1;
  emxEnsureCapacity_real_T(Ylay0, i);
  icomb = Ylay0->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    Ylay0->data[i] = Ylay0->data[i] * p1_idx_0 + p23_idx_2;
  }
  i = Zlay0->size[0] * Zlay0->size[1];
  Zlay0->size[0] = 1;
  emxEnsureCapacity_real_T(Zlay0, i);
  icomb = Zlay0->size[1] - 1;
  for (i = 0; i <= icomb; i++) {
    Zlay0->data[i] = Zlay0->data[i] * p1_idx_0 + pf_idx_0;
  }
  /*  -----------------------------生成多层测点-------------------------------
   */
  /*  阈值  */
  p12f_idx_1 = 0.2 * p1_idx_2;
  p1_idx_2 *= 0.8;
  emxInit_real_T(&Layer, 2);
  if (!(laynum >= 0.0)) {
    Layer->size[0] = 1;
    Layer->size[1] = 0;
  } else {
    pf_idx_1 = floor(laynum);
    i = Layer->size[0] * Layer->size[1];
    Layer->size[0] = 1;
    Layer->size[1] = (int)pf_idx_1;
    emxEnsureCapacity_real_T(Layer, i);
    if ((int)pf_idx_1 >= 1) {
      icomb = (int)pf_idx_1 - 1;
      Layer->data[(int)floor(laynum) - 1] = p1_idx_2;
      if (Layer->size[1] >= 2) {
        Layer->data[0] = p12f_idx_1;
        if (Layer->size[1] >= 3) {
          if ((p12f_idx_1 == -p1_idx_2) && ((int)pf_idx_1 > 2)) {
            p1_idx_2 /= (double)(int)pf_idx_1 - 1.0;
            for (row = 2; row <= icomb; row++) {
              Layer->data[row - 1] =
                  (double)(((row << 1) - (int)pf_idx_1) - 1) * p1_idx_2;
            }
            if (((int)pf_idx_1 & 1) == 1) {
              Layer->data[(int)pf_idx_1 >> 1] = 0.0;
            }
          } else {
            p1_idx_2 = (p1_idx_2 - p12f_idx_1) / ((double)Layer->size[1] - 1.0);
            i = Layer->size[1];
            for (row = 0; row <= i - 3; row++) {
              Layer->data[row + 1] =
                  p12f_idx_1 + ((double)row + 1.0) * p1_idx_2;
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
    pf_idx_1 = (((double)nmkpi + 1.0) - 1.0) * num + 1.0;
    p1_idx_2 = ((double)nmkpi + 1.0) * num;
    if (pf_idx_1 > p1_idx_2) {
      icomb = 1;
    } else {
      icomb = (int)pf_idx_1;
    }
    p12f_idx_1 = Layer->data[nmkpi] * p23f_idx_0;
    for (nblocks = 0; nblocks < loop_ub; nblocks++) {
      XCenter->data[(icomb + nblocks) - 1] = temp->data[nblocks] - p12f_idx_1;
    }
    if (pf_idx_1 > p1_idx_2) {
      icomb = 1;
    } else {
      icomb = (int)pf_idx_1;
    }
    p12f_idx_1 = Layer->data[nmkpi] * p23f_idx_1;
    for (nblocks = 0; nblocks < b_loop_ub; nblocks++) {
      YCenter->data[(icomb + nblocks) - 1] = Ylay0->data[nblocks] - p12f_idx_1;
    }
    if (pf_idx_1 > p1_idx_2) {
      icomb = 1;
    } else {
      icomb = (int)pf_idx_1;
    }
    p12f_idx_1 = Layer->data[nmkpi] * d;
    for (nblocks = 0; nblocks < c_loop_ub; nblocks++) {
      ZCenter->data[(icomb + nblocks) - 1] = Zlay0->data[nblocks] - p12f_idx_1;
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
