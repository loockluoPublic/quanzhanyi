/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2024 00:13:40
 */

#ifndef CALCULATE_ACCURATE_CYLINDERS_FROM_MULTIPLE_MEASUREMENT_POINTS_H
#define CALCULATE_ACCURATE_CYLINDERS_FROM_MULTIPLE_MEASUREMENT_POINTS_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculate_accurate_cylinders_from_multiple_measurement_points(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points.h
 *
 * [EOF]
 */
