/*
 * File: G5P_types.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Mar-2024 19:53:49
 */

#ifndef G5P_TYPES_H
#define G5P_TYPES_H

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
 * File trailer for G5P_types.h
 *
 * [EOF]
 */
