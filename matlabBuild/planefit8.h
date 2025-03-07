/*
 * File: planefit8.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Mar-2025 21:42:51
 */

#ifndef PLANEFIT8_H
#define PLANEFIT8_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, emxArray_real_T *Points4,
                 const emxArray_real_T *Points5, emxArray_real_T *Points6,
                 const emxArray_real_T *Points7, emxArray_real_T *Points8,
                 const double P_bound1[3], const double P_bound2[3],
                 double distanceThreshold, emxArray_real_T *PlaneParaOut,
                 emxArray_real_T *TrianglePoints, double MaxDis[8],
                 emxArray_real_T *tt1);

extern void planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
                      const emxArray_real_T *Points3, emxArray_real_T *Points4,
                      const emxArray_real_T *Points5, emxArray_real_T *Points6,
                      const emxArray_real_T *Points7, emxArray_real_T *Points8,
                      const double P_bound1[3], const double P_bound2[3],
                      double distanceThreshold, emxArray_real_T *PlaneParaOut,
                      emxArray_real_T *TrianglePoints, double MaxDis[8],
                      emxArray_real_T *tt1, emxArray_real_T *tt2,
                      emxArray_real_T *tt3, emxArray_real_T *tt4,
                      emxArray_real_T *tt5, emxArray_real_T *tt6,
                      emxArray_real_T *tt7, emxArray_real_T *tt8,
                      double LenDaoJiao[8]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit8.h
 *
 * [EOF]
 */
