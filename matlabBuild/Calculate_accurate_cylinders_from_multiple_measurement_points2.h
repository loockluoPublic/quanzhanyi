/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

#ifndef CALCULATE_ACCURATE_CYLINDERS_FROM_MULTIPLE_MEASUREMENT_POINTS2_H
#define CALCULATE_ACCURATE_CYLINDERS_FROM_MULTIPLE_MEASUREMENT_POINTS2_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculate_accurate_cylinders_from_multiple_measurement_points2(
    const emxArray_real_T *points, const double P_bound1[3],
    const double P_bound2[3], double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every, double Bottom_round_center1[3],
    double Bottom_round_center2[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.h
 *
 * [EOF]
 */
