/*
 * File: _coder_G5P_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Mar-2024 19:53:49
 */

#ifndef _CODER_G5P_API_H
#define _CODER_G5P_API_H

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
void G5P(real_T t1, real_T t2, real_T num, emxArray_real_T *Point);

void G5P_api(const mxArray *const prhs[3], const mxArray **plhs);

void G5P_atexit(void);

void G5P_initialize(void);

void G5P_terminate(void);

void G5P_xil_shutdown(void);

void G5P_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_G5P_api.h
 *
 * [EOF]
 */
