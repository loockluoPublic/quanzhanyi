/*
 * File: cat.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
 */

#ifndef CAT_H
#define CAT_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                      const emxArray_real_T *in3, double in4,
                      const double in5[3]);

void g_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3, const emxArray_real_T *in4);

void m_binary_expand_op(emxArray_real_T *in1, double in2,
                        const emxArray_real_T *in3, double in4,
                        const emxArray_real_T *in5, const emxArray_real_T *in6,
                        const emxArray_real_T *in7, double in8);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for cat.h
 *
 * [EOF]
 */
