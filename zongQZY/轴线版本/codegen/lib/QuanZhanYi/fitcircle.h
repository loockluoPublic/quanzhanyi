/*
 * File: fitcircle.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 22:37:07
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
void binary_expand_op_6(const double in2[3], const emxArray_real_T *in3,
                        const emxArray_real_T *in4, const emxArray_real_T *in5,
                        const int in6[2], const emxArray_real_T *in7,
                        double in1[3]);

void binary_expand_op_8(emxArray_real_T *in1, const double in3[3],
                        const emxArray_real_T *in4, const emxArray_real_T *in5);

void binary_expand_op_9(const emxArray_real_T *in2, const emxArray_real_T *in3,
                        const emxArray_real_T *in4, emxArray_real_T *in5,
                        emxArray_real_T *in6, double in7[16]);

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
