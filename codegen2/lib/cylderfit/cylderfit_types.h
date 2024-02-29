/*
 * File: cylderfit_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

#ifndef CYLDERFIT_TYPES_H
#define CYLDERFIT_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

#ifndef typedef_pointCloud
#define typedef_pointCloud
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  emxArray_real_T *Location;
  emxArray_uint8_T *Color;
  emxArray_real_T *Normal;
  emxArray_real_T *Intensity;
  void *Kdtree;
  void *LocationHandle;
  boolean_T HasKdtreeConstructed;
  boolean_T HasLocationHandleAllocated;
} pointCloud;
#endif /* typedef_pointCloud */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_c_emxArray_pointclouds_internal
#define typedef_c_emxArray_pointclouds_internal
typedef struct {
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_pointclouds_internal;
#endif /* typedef_c_emxArray_pointclouds_internal */

#ifndef typedef_b_pointCloud
#define typedef_b_pointCloud
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  double Location[135];
  emxArray_uint8_T *Color;
  emxArray_real_T *Normal;
  emxArray_real_T *Intensity;
  emxArray_real_T *RangeData;
  void *Kdtree;
  void *LocationHandle;
  boolean_T HasKdtreeConstructed;
  boolean_T HasLocationHandleAllocated;
  c_emxArray_pointclouds_internal *PointCloudArrayData;
} b_pointCloud;
#endif /* typedef_b_pointCloud */

#endif
/*
 * File trailer for cylderfit_types.h
 *
 * [EOF]
 */
