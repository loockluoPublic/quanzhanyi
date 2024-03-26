/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 20:09:07
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
void b_minimum(const emxArray_real_T *x, double *ex, int *idx);

double maximum(const emxArray_real_T *x);

double minimum(const emxArray_real_T *x);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
