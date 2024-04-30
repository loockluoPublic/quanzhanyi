/*
 * File: xrot.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Apr-2024 00:52:42
 */

#ifndef XROT_H
#define XROT_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xrot(double x[16], int ix0, int iy0, double c, double s);

void c_xrot(double x[4], int ix0, int iy0, double c, double s);

void xrot(double x[9], int ix0, int iy0, double c, double s);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xrot.h
 *
 * [EOF]
 */
