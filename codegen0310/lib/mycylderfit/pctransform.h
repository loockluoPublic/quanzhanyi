/*
 * File: pctransform.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef PCTRANSFORM_H
#define PCTRANSFORM_H

/* Include Files */
#include "mycylderfit_types.h"
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
