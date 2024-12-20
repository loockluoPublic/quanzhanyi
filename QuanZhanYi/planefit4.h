/*
 * File: planefit4.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Dec-2024 23:43:24
 */

#ifndef PLANEFIT4_H
#define PLANEFIT4_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, const emxArray_real_T *Points4,
                 const double BoundPoint1[3], const double BoundPoint2[3],
                 double distanceThreshold, emxArray_real_T *PlaneParaOut,
                 emxArray_real_T *TrianglePoints, double MaxDis[4],
                 emxArray_real_T *distancesFianal);

extern void planefit4(const emxArray_real_T *Points1,
                      const emxArray_real_T *Points2,
                      const emxArray_real_T *Points3,
                      const emxArray_real_T *Points4,
                      const double BoundPoint1[3], const double BoundPoint2[3],
                      double distanceThreshold, emxArray_real_T *PlaneParaOut,
                      emxArray_real_T *TrianglePoints, double MaxDis[4],
                      emxArray_real_T *distancesFianal);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit4.h
 *
 * [EOF]
 */
