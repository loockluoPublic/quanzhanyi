/*
 * File: planefit8.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
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
extern void
planefit8(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
          const emxArray_real_T *Points3, const emxArray_real_T *Points4,
          const emxArray_real_T *Points5, const emxArray_real_T *Points6,
          const emxArray_real_T *Points7, const emxArray_real_T *Points8,
          const double P_bound1[3], const double P_bound2[3],
          emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit8.h
 *
 * [EOF]
 */
