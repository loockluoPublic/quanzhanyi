/*
 * File: fitcircle.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

#ifndef FITCIRCLE_H
#define FITCIRCLE_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void fitcircle(const emxArray_real_T *x, double z[2], double *r,
                      double *residual);

void sys(const captured_var *m, const b_captured_var *x,
         const b_captured_var *x1, const b_captured_var *x2, const double u[3],
         emxArray_real_T *f, emxArray_real_T *J);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for fitcircle.h
 *
 * [EOF]
 */
