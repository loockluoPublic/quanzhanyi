/*
 * File: GenerateTrianglePoints.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 22:41:07
 */

#ifndef GENERATETRIANGLEPOINTS_H
#define GENERATETRIANGLEPOINTS_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void GenerateTrianglePoints(const double PlaneParaIn[4],
                                   const double BoundPoint1[3],
                                   const double P0[3],
                                   const double Direction[3],
                                   double PointTri[6]);

void b_GenerateTrianglePoints(const double PlaneParaIn[4],
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6]);

void c_GenerateTrianglePoints(const emxArray_real_T *PlaneParaIn,
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6]);

void d_GenerateTrianglePoints(const double PlaneParaIn[4],
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for GenerateTrianglePoints.h
 *
 * [EOF]
 */
