/*
 * File: Calculat_JuXing_A_and_B_Points_after_Offest.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 11:38:12
 */

#ifndef CALCULAT_JUXING_A_AND_B_POINTS_AFTER_OFFEST_H
#define CALCULAT_JUXING_A_AND_B_POINTS_AFTER_OFFEST_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Calculat_JuXing_A_and_B_Points_after_Offest(
    const double Tao[3], const double UPP[3], const double Pin[3], double b,
    double h, const double PAB[3], double phi, double shenglunum,
    const emxArray_real_T *Ti, const emxArray_real_T *toff,
    emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Calculat_JuXing_A_and_B_Points_after_Offest.h
 *
 * [EOF]
 */
