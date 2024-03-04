/*
 * File: pctransform.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

#ifndef PCTRANSFORM_H
#define PCTRANSFORM_H

/* Include Files */
#include "cylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
pointCloud *pctransform(const pointCloud *ptCloudIn,
                        const double tform_AffineTform_T[16],
                        pointCloud *iobj_0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pctransform.h
 *
 * [EOF]
 */
