/*
 * File: xnrm2.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

#ifndef XNRM2_H
#define XNRM2_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_xnrm2(const double x_data[], int ix0);

double c_xnrm2(int n, const double x[9], int ix0);

double d_xnrm2(const double x[3], int ix0);

double e_xnrm2(int n, const double x[49], int ix0);

double f_xnrm2(int n, const double x[7], int ix0);

double xnrm2(int n, const emxArray_real_T *x, int ix0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xnrm2.h
 *
 * [EOF]
 */
