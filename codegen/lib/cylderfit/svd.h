/*
 * File: svd.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

#ifndef SVD_H
#define SVD_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_svd(const double A[49], double U[49], double s[7], double V[49]);

void svd(const double A[9], double U[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for svd.h
 *
 * [EOF]
 */
