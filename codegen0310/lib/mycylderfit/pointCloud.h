/*
 * File: pointCloud.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

/* Include Files */
#include "mycylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
pointCloud *pointCloud_pointCloud(pointCloud *this,
                                  const emxArray_real_T *varargin_1);

void pointCloud_surfaceNormalImpl(pointCloud *this, emxArray_real_T *normals);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pointCloud.h
 *
 * [EOF]
 */
