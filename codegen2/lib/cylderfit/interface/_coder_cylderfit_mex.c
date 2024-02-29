/*
 * File: _coder_cylderfit_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "_coder_cylderfit_mex.h"
#include "_coder_cylderfit_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&cylderfit_atexit);
  /* Module initialization. */
  cylderfit_initialize();
  /* Dispatch the entry-point. */
  unsafe_cylderfit_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  cylderfit_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_cylderfit_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        9, "cylderfit");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "cylderfit");
  }
  /* Call the function. */
  cylderfit_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * File trailer for _coder_cylderfit_mex.c
 *
 * [EOF]
 */
