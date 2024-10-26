/*
 * File: xzsvdc.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 00:22:21
 */

#ifndef XZSVDC_H
#define XZSVDC_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int b_xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
             double V[9]);

int xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
           double V[16]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xzsvdc.h
 *
 * [EOF]
 */
