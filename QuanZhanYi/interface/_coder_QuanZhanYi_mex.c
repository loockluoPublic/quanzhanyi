/*
 * File: _coder_QuanZhanYi_mex.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Jun-2024 16:40:59
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
  static const char_T *emlrtEntryPoints[14] = {
      "angle2point",
      "Calculat_A_and_B_Points",
      "Calculat_A_and_B_Points_after_Offest",
      "Calculate_accurate_cylinders_from_multiple_measurement_points2",
      "CrossLine",
      "fitcircle",
      "foot_of_perpendicular_from_a_point_to_a_line",
      "Generate_multi_layered_measurement_points",
      "generate_unit_circle_with_normal_vector",
      "generate_unit_circle_with_normal_vector2",
      "GenerateTrianglePoints",
      "myvrrotvec2mat",
      "planefit",
      "RepeatSurvey"};
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
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 14)) {
  case 0:
    unsafe_angle2point_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    unsafe_Calculat_A_and_B_Points_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 2:
    unsafe_Calculat_A_and_B_Points_after_Offest_mexFunction(nlhs, plhs,
                                                            nrhs - 1, &prhs[1]);
    break;
  case 3:
    unsafe_Calculate_accurate_cylinders_from_multiple_measurement_points2_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 4:
    unsafe_CrossLine_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 5:
    unsafe_fitcircle_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 6:
    unsafe_foot_of_perpendicular_from_a_point_to_a_line_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 7:
    unsafe_Generate_multi_layered_measurement_points_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 8:
    unsafe_generate_unit_circle_with_normal_vector_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 9:
    unsafe_generate_unit_circle_with_normal_vector2_mexFunction(
        nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 10:
    unsafe_GenerateTrianglePoints_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 11:
    unsafe_myvrrotvec2mat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 12:
    unsafe_planefit_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 13:
    unsafe_RepeatSurvey_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
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
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, (const char_T *)"GBK", true);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[10]
 * Return Type  : void
 */
void unsafe_Calculat_A_and_B_Points_after_Offest_mexFunction(
    int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[10])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 10) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 10, 4,
                        36, "Calculat_A_and_B_Points_after_Offest");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 36,
                        "Calculat_A_and_B_Points_after_Offest");
  }
  /* Call the function. */
  c_Calculat_A_and_B_Points_after(prhs, nlhs, outputs);
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
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[8]
 * Return Type  : void
 */
void unsafe_Calculat_A_and_B_Points_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                                int32_T nrhs,
                                                const mxArray *prhs[8])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        23, "Calculat_A_and_B_Points");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "Calculat_A_and_B_Points");
  }
  /* Call the function. */
  Calculat_A_and_B_Points_api(prhs, nlhs, outputs);
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
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_CrossLine_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                  const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        9, "CrossLine");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "CrossLine");
  }
  /* Call the function. */
  CrossLine_api(prhs, nlhs, outputs);
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
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void unsafe_GenerateTrianglePoints_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                               int32_T nrhs,
                                               const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        22, "GenerateTrianglePoints");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "GenerateTrianglePoints");
  }
  /* Call the function. */
  GenerateTrianglePoints_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
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
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void unsafe_RepeatSurvey_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                     int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        12, "RepeatSurvey");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "RepeatSurvey");
  }
  /* Call the function. */
  RepeatSurvey_api(prhs, nlhs, outputs);
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
 *                const mxArray *prhs[6]
 * Return Type  : void
 */
void unsafe_angle2point_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                    int32_T nrhs, const mxArray *prhs[6])
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
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        11, "angle2point");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "angle2point");
  }
  /* Call the function. */
  angle2point_api(prhs, nlhs, outputs);
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
 *                const mxArray *prhs[6]
 * Return Type  : void
 */
void unsafe_generate_unit_circle_with_normal_vector2_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
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
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void unsafe_planefit_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                 const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        8, "planefit");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "planefit");
  }
  /* Call the function. */
  planefit_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_QuanZhanYi_mex.c
 *
 * [EOF]
 */
