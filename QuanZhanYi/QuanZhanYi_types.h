/*
 * File: QuanZhanYi_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 12-Apr-2024 14:11:28
 */

#ifndef QUANZHANYI_TYPES_H
#define QUANZHANYI_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_captured_var
#define typedef_captured_var
typedef struct {
  double contents;
} captured_var;
#endif /* typedef_captured_var */

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

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  emxArray_real_T *contents;
} b_captured_var;
#endif /* typedef_b_captured_var */

#endif
/*
 * File trailer for QuanZhanYi_types.h
 *
 * [EOF]
 */
