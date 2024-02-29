/*
 * File: msac.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

#ifndef MSAC_H
#define MSAC_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void msac(const emxArray_real_T *allPoints, boolean_T *isFound,
          double bestModelParams_data[], int bestModelParams_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for msac.h
 *
 * [EOF]
 */
