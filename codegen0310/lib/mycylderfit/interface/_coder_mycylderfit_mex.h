/*
 * File: _coder_mycylderfit_mex.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef _CODER_MYCYLDERFIT_MEX_H
#define _CODER_MYCYLDERFIT_MEX_H

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

void unsafe_mycylderfit_mexFunction(int32_T nlhs, mxArray *plhs[7],
                                    int32_T nrhs, const mxArray *prhs[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_mycylderfit_mex.h
 *
 * [EOF]
 */
