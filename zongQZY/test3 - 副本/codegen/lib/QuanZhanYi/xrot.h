/*
 * File: xrot.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 29-Sep-2024 01:27:40
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
