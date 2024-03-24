/*
 * File: Three_Points_Initial_Rough_Cylindrical_Judgment.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 00:17:09
 */

/* Include Files */
#include "Three_Points_Initial_Rough_Cylindrical_Judgment.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"
#include <emscripten.h>
/* Function Definitions */
/*
 * Arguments    : const double x[3]
 *                const double y[3]
 *                const double z[3]
 *                double S[3]
 *                double *x0
 *                double *b_y0
 *                double *z0
 * Return Type  : void
 */
EMSCRIPTEN_KEEPALIVE
void Three_Points_Initial_Rough_Cylindrical_Judgment(const double x[3],
                                                     const double y[3],
                                                     const double z[3],
                                                     double S[3], double *x0,
                                                     double *b_y0, double *z0)
{
  double N12_idx_0;
  double N12_idx_1;
  double N12_idx_2;
  double N23_idx_0;
  double N23_idx_1;
  double N23_idx_2;
  double S_tmp;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  N12_idx_0 = x[1] - x[0];
  N12_idx_1 = y[1] - y[0];
  N12_idx_2 = z[1] - z[0];
  N23_idx_0 = x[2] - x[1];
  N23_idx_1 = y[2] - y[1];
  N23_idx_2 = z[2] - z[1];
  S_tmp = N12_idx_1 * N23_idx_2 - N23_idx_1 * N12_idx_2;
  S[0] = S_tmp;
  S[1] = N23_idx_0 * N12_idx_2 - N12_idx_0 * N23_idx_2;
  S[2] = N12_idx_0 * N23_idx_1 - N23_idx_0 * N12_idx_1;
  /* 方向向量 */
  /*     %% 计算交点 */
  N12_idx_0 = -(
      (N12_idx_0 * ((x[0] + x[1]) / 2.0) + N12_idx_1 * ((y[0] + y[1]) / 2.0)) +
      N12_idx_2 * ((z[0] + z[1]) / 2.0));
  *x0 = 0.0;
  *z0 = (N12_idx_0 * N23_idx_1 -
         N12_idx_1 * -((N23_idx_0 * ((x[1] + x[2]) / 2.0) +
                        N23_idx_1 * ((y[1] + y[2]) / 2.0)) +
                       N23_idx_2 * ((z[1] + z[2]) / 2.0))) /
        S_tmp;
  *b_y0 = -(N12_idx_2 * *z0 + N12_idx_0) / N12_idx_1;
}

/*
 * File trailer for Three_Points_Initial_Rough_Cylindrical_Judgment.c
 *
 * [EOF]
 */
