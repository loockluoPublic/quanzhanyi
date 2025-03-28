/*
 * File: Calculate_rectangle_from_vertex.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

#ifndef CALCULATE_RECTANGLE_FROM_VERTEX_H
#define CALCULATE_RECTANGLE_FROM_VERTEX_H

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
Calculate_rectangle_from_vertex(const emxArray_real_T *TrianglePoints4,
                                double Pin[3], double Pout[3], double UPP[3],
                                double *b, double *h, double *w, double Tao[3],
                                double PP[24]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Calculate_rectangle_from_vertex.h
 *
 * [EOF]
 */
