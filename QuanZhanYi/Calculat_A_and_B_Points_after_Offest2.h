/*
 * File: Calculat_A_and_B_Points_after_Offest2.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Sep-2024 15:15:59
 */

#ifndef CALCULAT_A_AND_B_POINTS_AFTER_OFFEST2_H
#define CALCULAT_A_AND_B_POINTS_AFTER_OFFEST2_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculat_A_and_B_Points_after_Offest2(
    const double MTaon[3], const double Mcenter[3], double Mradial,
    const double PAB[3], double phi, emxArray_real_T *Ang,
    const emxArray_real_T *toff, const emxArray_real_T *roff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Calculat_A_and_B_Points_after_Offest2.h
 *
 * [EOF]
 */
