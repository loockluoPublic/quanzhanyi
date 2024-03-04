/*
 * _coder_cylderfit_mex.c
 *
 * Code generation for function '_coder_cylderfit_mex'
 *
 */

/* Include files */
#include "_coder_cylderfit_mex.h"
#include "_coder_cylderfit_api.h"
#include "cylderfit_data.h"
#include "cylderfit_initialize.h"
#include "cylderfit_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void cylderfit_mexFunction(int32_T nlhs, mxArray *plhs[7], int32_T nrhs,
                           const mxArray *prhs[3])
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
                        9, "cylderfit");
  }
  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "cylderfit");
  }
  /* Call the function. */
  cylderfit_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&cylderfit_atexit);
  /* Module initialization. */
  cylderfit_initialize();
  /* Dispatch the entry-point. */
  cylderfit_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  cylderfit_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_cylderfit_mex.c) */
