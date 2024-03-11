/*
 * File: _coder_mycylderfit2_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

/* Include Files */
#include "_coder_mycylderfit2_mex.h"
#include "_coder_mycylderfit2_api.h"

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
  mexAtExit(&mycylderfit2_atexit);
  /* Module initialization. */
  mycylderfit2_initialize();
  /* Dispatch the entry-point. */
  unsafe_mycylderfit2_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  mycylderfit2_terminate();
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
 *                mxArray *plhs[7]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_mycylderfit2_mexFunction(int32_T nlhs, mxArray *plhs[7],
                                     int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[7];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        12, "mycylderfit2");
  }
  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "mycylderfit2");
  }
  /* Call the function. */
  mycylderfit2_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_mycylderfit2_mex.c
 *
 * [EOF]
 */
