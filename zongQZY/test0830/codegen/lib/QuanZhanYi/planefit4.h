/*
 * File: planefit4.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
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
extern void
planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
          const emxArray_real_T *Points3, const emxArray_real_T *Points4,
          const double BoundPoint1[3], const double BoundPoint2[3],
          emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit4.h
 *
 * [EOF]
 */
