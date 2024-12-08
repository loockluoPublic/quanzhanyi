/*
 * File: planefit8.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Dec-2024 19:01:03
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
                 emxArray_real_T *distancesFianal);

extern void planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
                      const emxArray_real_T *Points3, emxArray_real_T *Points4,
                      const emxArray_real_T *Points5, emxArray_real_T *Points6,
                      const emxArray_real_T *Points7, emxArray_real_T *Points8,
                      const double P_bound1[3], const double P_bound2[3],
                      double distanceThreshold, emxArray_real_T *PlaneParaOut,
                      emxArray_real_T *TrianglePoints, double MaxDis[8],
                      emxArray_real_T *distancesFianal, double LenDaoJiao[8]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit8.h
 *
 * [EOF]
 */
