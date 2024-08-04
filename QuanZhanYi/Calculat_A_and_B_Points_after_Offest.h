/*
 * File: Calculat_A_and_B_Points_after_Offest.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 05-Aug-2024 00:10:26
 */

#ifndef CALCULAT_A_AND_B_POINTS_AFTER_OFFEST_H
#define CALCULAT_A_AND_B_POINTS_AFTER_OFFEST_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculat_A_and_B_Points_after_Offest(
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double Bottom_round_center1[3], const double Bottom_round_center2[3],
    const double testP[3], double numShengLu, double phi, double toff,
    double roff, emxArray_real_T *PointTable_A_off,
    emxArray_real_T *PointTable_B_off);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Calculat_A_and_B_Points_after_Offest.h
 *
 * [EOF]
 */
