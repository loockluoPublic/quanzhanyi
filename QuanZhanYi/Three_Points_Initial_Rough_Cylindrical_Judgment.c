/*
 * File: Three_Points_Initial_Rough_Cylindrical_Judgment.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 23:35:55
 */

/* Include Files */
#include "Three_Points_Initial_Rough_Cylindrical_Judgment.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double x[3]
 *                const double y[3]
 *                const double z[3]
 *                double *S1
 *                double *S2
 *                double *S3
 *                double *x0
 *                double *b_y0
 *                double *z0
 * Return Type  : void
 */
void Three_Points_Initial_Rough_Cylindrical_Judgment(
    const double x[3], const double y[3], const double z[3], double *S1,
    double *S2, double *S3, double *x0, double *b_y0, double *z0)
{
  double p12f_idx_0;
  double p12f_idx_1;
  double p23f_idx_0;
  double p23f_idx_1;
  double p23f_idx_2;
  double p2_idx_0;
  double p2_idx_1;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  /*  if any(pf == 0) */
  /*      error('三个点不能共线！！'); */
  /*  end */
  /*  两条线段的重点，之后需要求中垂线 */
  p2_idx_0 = x[0] - x[1];
  p23f_idx_0 = x[0] - x[2];
  p12f_idx_1 = y[0] - y[1];
  p23f_idx_1 = y[0] - y[2];
  p2_idx_1 = z[0] - z[1];
  p23f_idx_2 = z[0] - z[2];
  *S1 = p12f_idx_1 * p23f_idx_2 - p23f_idx_1 * p2_idx_1;
  *S2 = p23f_idx_0 * p2_idx_1 - p2_idx_0 * p23f_idx_2;
  *S3 = p2_idx_0 * p23f_idx_1 - p23f_idx_0 * p12f_idx_1;
  /*  求两条线的中垂线 */
  p12f_idx_0 = *S2 * p2_idx_1 - p12f_idx_1 * *S3;
  p12f_idx_1 = p2_idx_0 * *S3 - *S1 * p2_idx_1;
  *x0 = (x[1] + x[2]) / 2.0;
  p2_idx_0 = x[1] - x[2];
  *b_y0 = (y[1] + y[2]) / 2.0;
  p2_idx_1 = y[1] - y[2];
  p23f_idx_2 = z[1] - z[2];
  p23f_idx_0 = *S2 * p23f_idx_2 - p2_idx_1 * *S3;
  p23f_idx_1 = p2_idx_0 * *S3 - *S1 * p23f_idx_2;
  /*  求在中垂线上投影的大小 */
  p23f_idx_2 = (((y[0] + y[1]) / 2.0 - *b_y0) * p12f_idx_0 -
                ((x[0] + x[1]) / 2.0 - *x0) * p12f_idx_1) /
               (p12f_idx_0 * p23f_idx_1 - p23f_idx_0 * p12f_idx_1);
  /*  得出距离 */
  *x0 += p23f_idx_0 * p23f_idx_2;
  *b_y0 += p23f_idx_1 * p23f_idx_2;
  /*  radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2); */
  *z0 = (z[1] + z[2]) / 2.0 + (*S1 * p2_idx_1 - p2_idx_0 * *S2) * p23f_idx_2;
}

/*
 * File trailer for Three_Points_Initial_Rough_Cylindrical_Judgment.c
 *
 * [EOF]
 */
