/*
 * File: fitcircle.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 05-Jul-2024 14:54:53
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
void b_plus(emxArray_real_T *in1, const emxArray_real_T *in2);

void c_binary_expand_op(double in1[3], const double in2[3],
                        const emxArray_real_T *in3, const emxArray_real_T *in4,
                        const emxArray_real_T *in5, const int in6[2],
                        const emxArray_real_T *in7);

extern void fitcircle(const emxArray_real_T *x, double z[2], double *r,
                      double *residual);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for fitcircle.h
 *
 * [EOF]
 */
