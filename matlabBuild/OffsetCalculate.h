/*
 * File: OffsetCalculate.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

#ifndef OFFSETCALCULATE_H
#define OFFSETCALCULATE_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void OffsetCalculate(double Mradial, double phi,
                            const emxArray_real_T *Ang,
                            const emxArray_real_T *a,
                            emxArray_real_T *OffsetOut);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for OffsetCalculate.h
 *
 * [EOF]
 */
