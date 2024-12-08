/*
 * File: foot_of_perpendicular_from_a_point_to_a_line.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Dec-2024 19:01:03
 */

/* Include Files */
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * 三个点定义
 *
 * Arguments    : const double P_outer[3]
 *                const double P_lines1[3]
 *                const double P_lines2[3]
 *                double *xN1
 *                double *yN1
 *                double *zN1
 * Return Type  : void
 */
void foot_of_perpendicular_from_a_point_to_a_line(const double P_outer[3],
                                                  const double P_lines1[3],
                                                  const double P_lines2[3],
                                                  double *xN1, double *yN1,
                                                  double *zN1)
{
  double K;
  double a_tmp;
  double b_a_tmp;
  double c_a_tmp;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  斜率计算 */
  a_tmp = P_lines2[0] - P_lines1[0];
  b_a_tmp = P_lines2[1] - P_lines1[1];
  c_a_tmp = P_lines2[2] - P_lines1[2];
  K = -(((P_lines1[0] - P_outer[0]) * a_tmp +
         (P_lines1[1] - P_outer[1]) * b_a_tmp) +
        (P_lines1[2] - P_outer[2]) * c_a_tmp) /
      ((a_tmp * a_tmp + b_a_tmp * b_a_tmp) + c_a_tmp * c_a_tmp);
  /*  P1点在轴线上的投影坐标 */
  *xN1 = K * a_tmp + P_lines1[0];
  *yN1 = K * b_a_tmp + P_lines1[1];
  *zN1 = K * c_a_tmp + P_lines1[2];
}

/*
 * File trailer for foot_of_perpendicular_from_a_point_to_a_line.c
 *
 * [EOF]
 */
