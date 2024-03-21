/*
 * File: _coder_generate_unit_circle_with_normal_vector_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 21-Mar-2024 21:48:40
 */

#ifndef _CODER_GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_API_H
#define _CODER_GENERATE_UNIT_CIRCLE_WITH_NORMAL_VECTOR_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_generate_unit_circle_with_nor(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3]);

void generate_unit_circle_with_normal_vector(real_T t1, real_T t2, real_T num,
                                             emxArray_real_T *x_circle,
                                             emxArray_real_T *y_circle,
                                             emxArray_real_T *z_circle);

void generate_unit_circle_with_normal_vector_atexit(void);

void generate_unit_circle_with_normal_vector_initialize(void);

void generate_unit_circle_with_normal_vector_terminate(void);

void generate_unit_circle_with_normal_vector_xil_shutdown(void);

void generate_unit_circle_with_normal_vector_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_generate_unit_circle_with_normal_vector_api.h
 *
 * [EOF]
 */
