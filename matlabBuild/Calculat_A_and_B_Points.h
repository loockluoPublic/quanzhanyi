/*
 * File: Calculat_A_and_B_Points.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 20:27:52
 */

#ifndef CALCULAT_A_AND_B_POINTS_H
#define CALCULAT_A_AND_B_POINTS_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculat_A_and_B_Points(const double MTaon[3],
                                    const double Mcenter[3], double Mradial,
                                    const double Bottom_round_center1[3],
                                    const double Bottom_round_center2[3],
                                    const double testP[3], double numShengLu,
                                    double phi, emxArray_real_T *PointTable_A,
                                    emxArray_real_T *PointTable_B);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Calculat_A_and_B_Points.h
 *
 * [EOF]
 */
