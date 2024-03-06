/*
 * File: mycylderfit.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

#ifndef MYCYLDERFIT_H
#define MYCYLDERFIT_H

/* Include Files */
#include "mycylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
extern int add200(int a, int b);
/* Function Declarations */
extern void mycylderfit(const emxArray_real_T *x, const emxArray_real_T *y,
                        const emxArray_real_T *z, double *xn1, double *xn2,
                        double *xn3, double *xn4, double *xn5, double *xn6,
                        double *xn7);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mycylderfit.h
 *
 * [EOF]
 */
