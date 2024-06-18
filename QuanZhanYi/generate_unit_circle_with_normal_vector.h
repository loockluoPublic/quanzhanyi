/*
 * File: generate_unit_circle_with_normal_vector.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 18-Jun-2024 11:44:39
 */

#ifndef GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_H
#define GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void d_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                        const emxArray_real_T *in3, const double in4[3]);

void e_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                        const emxArray_real_T *in3, const double in4[3]);

void f_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                        const emxArray_real_T *in3, const double in4[3]);

extern void generate_unit_circle_with_normal_vector(double azimuth,
                                                    double elevation,
                                                    double num,
                                                    emxArray_real_T *Point_out);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for generate_unit_circle_with_normal_vector.h
 *
 * [EOF]
 */
