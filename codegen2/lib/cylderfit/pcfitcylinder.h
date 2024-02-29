/*
 * File: pcfitcylinder.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

#ifndef PCFITCYLINDER_H
#define PCFITCYLINDER_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void convertToFiniteCylinderModel(double modelParams_data[],
                                  const b_pointCloud *ptCloud,
                                  const emxArray_real_T *inlierIndices);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pcfitcylinder.h
 *
 * [EOF]
 */
