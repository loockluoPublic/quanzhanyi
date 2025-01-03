/*
 * File: mean.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 21:37:33
 */

#ifndef MEAN_H
#define MEAN_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_mean(const emxArray_real_T *x, double y[3]);

void c_mean(const double x[24], double y[3]);

double mean(const emxArray_real_T *x);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mean.h
 *
 * [EOF]
 */
