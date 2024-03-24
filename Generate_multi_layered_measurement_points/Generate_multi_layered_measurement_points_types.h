/*
 * File: Generate_multi_layered_measurement_points_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

#ifndef GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_TYPES_H
#define GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_TYPES_H

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

#endif
/*
 * File trailer for Generate_multi_layered_measurement_points_types.h
 *
 * [EOF]
 */
