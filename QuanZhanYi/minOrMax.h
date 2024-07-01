/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 01-Jul-2024 15:27:46
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_maximum(const emxArray_real_T *x);

double b_minimum(const emxArray_real_T *x);

void maximum(const emxArray_real_T *x, double *ex, int *idx);

void minimum(const emxArray_real_T *x, double *ex, int *idx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
