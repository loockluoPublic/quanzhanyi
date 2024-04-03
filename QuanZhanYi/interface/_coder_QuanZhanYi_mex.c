/*
 * File: _coder_QuanZhanYi_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Apr-2024 21:38:53
 */

/* Include Files */
#include "_coder_QuanZhanYi_mex.h"
#include "_coder_QuanZhanYi_api.h"

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
  static const char_T *emlrtEntryPoints[7] = {
      "Calculate_accurate_cylinders_from_multiple_measurement_points2",
      "fitcircle",
      "foot_of_perpendicular_from_a_point_to_a_line",
      "Generate_multi_layered_measurement_points",
      "generate_unit_circle_with_normal_vector",
      "generate_unit_circle_with_normal_vector2",
      "myvrrotvec2mat"};
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexAtExit(&QuanZhanYi_atexit);
  /* Module initialization. */
  QuanZhanYi_initialize();
  st.tls = emlrtRootTLSGlobal;
  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 7)) {
  case 0:
    unsafe_Calculate_accurate_cylinders_from_multiple_measurement_points2_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    unsafe_fitcircle_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 2:
    unsafe_foot_of_perpendicular_from_a_point_to_a_line_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 3:
    unsafe_Generate_multi_layered_measurement_points_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 4:
    unsafe_generate_unit_circle_with_normal_vector_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 5:
    unsafe_generate_unit_circle_with_normal_vector2_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 6:
    unsafe_myvrrotvec2mat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  }
  /* Module termination. */
  QuanZhanYi_terminate();
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
 *                mxArray *plhs[6]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_Calculate_accurate_cylinders_from_multiple_measurement_points2_mexFunction(
    int32_T nlhs, mxArray *plhs[6], int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[6];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(
        &st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 62,
        "Calculate_accurate_cylinders_from_multiple_measurement_points2");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(
        &st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 62,
        "Calculate_accurate_cylinders_from_multiple_measurement_points2");
  }
  /* Call the function. */
  c_Calculate_accurate_cylinders_(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
void unsafe_Generate_multi_layered_measurement_points_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        41, "Generate_multi_layered_measurement_points");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 41,
                        "Generate_multi_layered_measurement_points");
  }
  /* Call the function. */
  c_Generate_multi_layered_measur(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[1]
 * Return Type  : void
 */
void unsafe_fitcircle_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                  const mxArray *prhs[1])
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
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        9, "fitcircle");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "fitcircle");
  }
  /* Call the function. */
  fitcircle_api(prhs[0], nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_foot_of_perpendicular_from_a_point_to_a_line_mexFunction(
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
                        44, "foot_of_perpendicular_from_a_point_to_a_line");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 44,
                        "foot_of_perpendicular_from_a_point_to_a_line");
  }
  /* Call the function. */
  c_foot_of_perpendicular_from_a_(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
void unsafe_generate_unit_circle_with_normal_vector2_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        40, "generate_unit_circle_with_normal_vector2");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 40,
                        "generate_unit_circle_with_normal_vector2");
  }
  /* Call the function. */
  d_generate_unit_circle_with_nor(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_generate_unit_circle_with_normal_vector_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[3])
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
                        39, "generate_unit_circle_with_normal_vector");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 39,
                        "generate_unit_circle_with_normal_vector");
  }
  /* Call the function. */
  c_generate_unit_circle_with_nor(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[1]
 * Return Type  : void
 */
void unsafe_myvrrotvec2mat_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                       int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        14, "myvrrotvec2mat");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "myvrrotvec2mat");
  }
  /* Call the function. */
  myvrrotvec2mat_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * File trailer for _coder_QuanZhanYi_mex.c
 *
 * [EOF]
 */
