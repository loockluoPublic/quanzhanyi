/*
 * File: _coder_mycylderfit2_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

#ifndef _CODER_MYCYLDERFIT2_API_H
#define _CODER_MYCYLDERFIT2_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void mycylderfit2(real_T x[45], real_T y[45], real_T z[45], real_T *XXX1,
                  real_T *XXX2, real_T *XXX3, real_T *XXX4, real_T *XXX5,
                  real_T *XXX6, real_T *XXX7);

void mycylderfit2_api(const mxArray *const prhs[3], int32_T nlhs,
                      const mxArray *plhs[7]);

void mycylderfit2_atexit(void);

void mycylderfit2_initialize(void);

void mycylderfit2_terminate(void);

void mycylderfit2_xil_shutdown(void);

void mycylderfit2_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_mycylderfit2_api.h
 *
 * [EOF]
 */
