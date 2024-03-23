/*
 * File: _coder_G5P_mex.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Mar-2024 19:53:49
 */

#ifndef _CODER_G5P_MEX_H
#define _CODER_G5P_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_G5P_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_G5P_mex.h
 *
 * [EOF]
 */
