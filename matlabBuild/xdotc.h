/*
 * File: xdotc.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 23:51:41
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_xdotc(int n, const double x[16], int ix0, const double y[16], int iy0);

double c_xdotc(int n, const double x[8], int ix0, const double y[8], int iy0);

double d_xdotc(const double x[4], const double y[4]);

double xdotc(int n, const double x[9], int ix0, const double y[9], int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xdotc.h
 *
 * [EOF]
 */
