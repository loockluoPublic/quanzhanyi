/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 20:09:07
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xaxpy(int n, double a, const double x[49], int ix0, double y[7],
             int iy0);

void c_xaxpy(int n, double a, const double x[7], int ix0, double y[49],
             int iy0);

void xaxpy(int n, double a, int ix0, double y[49], int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
