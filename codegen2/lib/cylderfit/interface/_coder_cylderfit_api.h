/*
 * File: _coder_cylderfit_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

#ifndef _CODER_CYLDERFIT_API_H
#define _CODER_CYLDERFIT_API_H

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
void cylderfit(real_T x[45], real_T y[45], real_T z[45],
               emxArray_real_T *retrn);

void cylderfit_api(const mxArray *const prhs[3], const mxArray **plhs);

void cylderfit_atexit(void);

void cylderfit_initialize(void);

void cylderfit_terminate(void);

void cylderfit_xil_shutdown(void);

void cylderfit_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_cylderfit_api.h
 *
 * [EOF]
 */
