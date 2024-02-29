/*
 * File: _coder_apb_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 22:51:50
 */

#ifndef _CODER_APB_API_H
#define _CODER_APB_API_H

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
real_T apb(real_T u, real_T v);

void apb_api(const mxArray *const prhs[2], const mxArray **plhs);

void apb_atexit(void);

void apb_initialize(void);

void apb_terminate(void);

void apb_xil_shutdown(void);

void apb_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_apb_api.h
 *
 * [EOF]
 */
