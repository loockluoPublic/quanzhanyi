/*
 * File: _coder_mycylderfit_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef _CODER_MYCYLDERFIT_API_H
#define _CODER_MYCYLDERFIT_API_H

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
void mycylderfit(emxArray_real_T *x, emxArray_real_T *y, emxArray_real_T *z,
                 real_T *xn1, real_T *xn2, real_T *xn3, real_T *xn4,
                 real_T *xn5, real_T *xn6, real_T *xn7);

void mycylderfit_api(const mxArray *const prhs[3], int32_T nlhs,
                     const mxArray *plhs[7]);

void mycylderfit_atexit(void);

void mycylderfit_initialize(void);

void mycylderfit_terminate(void);

void mycylderfit_xil_shutdown(void);

void mycylderfit_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_mycylderfit_api.h
 *
 * [EOF]
 */
