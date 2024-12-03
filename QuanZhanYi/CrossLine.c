/*
 * File: CrossLine.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 02-Dec-2024 23:37:52
 */

/* Include Files */
#include "CrossLine.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * 定义平面1的系数
 *
 * Arguments    : const double PlanePara1[4]
 *                const double PlanePara2[4]
 *                double x_val
 *                double P0[3]
 *                double d[3]
 * Return Type  : void
 */
void CrossLine(const double PlanePara1[4], const double PlanePara2[4],
               double x_val, double P0[3], double d[3])
{
  double A[4];
  double B[2];
  double a21;
  double yz_idx_1_tmp;
  int r1;
  int r2;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  定义平面2的系数 */
  /*  计算法向量的叉乘得到交线的方向向量 */
  d[0] = PlanePara1[1] * PlanePara2[2] - PlanePara2[1] * PlanePara1[2];
  d[1] = PlanePara2[0] * PlanePara1[2] - PlanePara1[0] * PlanePara2[2];
  d[2] = PlanePara1[0] * PlanePara2[1] - PlanePara2[0] * PlanePara1[1];
  /*  确定一个交点 */
  /*  Create the system of equations */
  /*  Solve for y and z */
  A[0] = PlanePara1[1];
  A[2] = PlanePara1[2];
  A[1] = PlanePara2[1];
  A[3] = PlanePara2[2];
  B[0] = -PlanePara1[3] - PlanePara1[0] * x_val;
  B[1] = -PlanePara2[3] - PlanePara2[0] * x_val;
  if (fabs(PlanePara2[1]) > fabs(PlanePara1[1])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = A[r2] / A[r1];
  yz_idx_1_tmp = A[r1 + 2];
  a21 = (B[r2] - B[r1] * a21) / (A[r2 + 2] - a21 * yz_idx_1_tmp);
  /*  The point on the intersection line */
  P0[0] = x_val;
  P0[1] = (B[r1] - a21 * yz_idx_1_tmp) / A[r1];
  P0[2] = a21;
}

/*
 * File trailer for CrossLine.c
 *
 * [EOF]
 */
