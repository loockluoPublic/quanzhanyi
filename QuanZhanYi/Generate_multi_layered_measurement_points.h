/*
 * File: Generate_multi_layered_measurement_points.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 17-Oct-2024 10:45:45
 */

#ifndef GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_H
#define GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Generate_multi_layered_measurement_points(
    const emxArray_real_T *Point_out, double num, double laynum,
    const double P3[3], const double P4[3], emxArray_real_T *Point_test);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Generate_multi_layered_measurement_points.h
 *
 * [EOF]
 */
