/*
 * File: generate_unit_circle_with_normal_vector.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
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
extern void generate_unit_circle_with_normal_vector(double azimuth,
                                                    double elevation,
                                                    double num,
                                                    emxArray_real_T *Point_out);

void h_binary_expand_op(emxArray_real_T *in1, const double in2[3],
                        const emxArray_real_T *in3, const double in4[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for generate_unit_circle_with_normal_vector.h
 *
 * [EOF]
 */
