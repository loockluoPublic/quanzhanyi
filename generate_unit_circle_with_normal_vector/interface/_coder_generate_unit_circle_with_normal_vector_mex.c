/*
 * File: _coder_generate_unit_circle_with_normal_vector_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 21-Mar-2024 21:48:40
 */

/* Include Files */
#include "_coder_generate_unit_circle_with_normal_vector_mex.h"
#include "_coder_generate_unit_circle_with_normal_vector_api.h"

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
  mexAtExit(&generate_unit_circle_with_normal_vector_atexit);
  /* Module initialization. */
  generate_unit_circle_with_normal_vector_initialize();
  /* Dispatch the entry-point. */
  unsafe_generate_unit_circle_with_normal_vector_mexFunction(nlhs, plhs, nrhs,
                                                             prhs);
  /* Module termination. */
  generate_unit_circle_with_normal_vector_terminate();
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
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_generate_unit_circle_with_normal_vector_mexFunction(
    int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        39, "generate_unit_circle_with_normal_vector");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 39,
                        "generate_unit_circle_with_normal_vector");
  }
  /* Call the function. */
  c_generate_unit_circle_with_nor(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_generate_unit_circle_with_normal_vector_mex.c
 *
 * [EOF]
 */
