/*
 * File: svd.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Jan-2025 23:39:18
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
void d_svd(const double A[8], double U[4], double s[2], double V[16]);

void svd(const double A[9], double U[9], double s[3], double V[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for svd.h
 *
 * [EOF]
 */
