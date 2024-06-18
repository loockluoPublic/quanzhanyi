/*
 * File: planefit.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 18-Jun-2024 11:44:39
 */

#ifndef PLANEFIT_H
#define PLANEFIT_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void planefit(const emxArray_real_T *Points,
                     const emxArray_real_T *PlaneParaIn,
                     const double BoundPoint1[3], const double BoundPoint2[3],
                     emxArray_real_T *PlaneParaOut,
                     double TrianglePoints_data[], int TrianglePoints_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for planefit.h
 *
 * [EOF]
 */
