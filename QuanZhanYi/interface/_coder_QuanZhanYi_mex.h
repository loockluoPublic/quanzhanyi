/*
 * File: _coder_QuanZhanYi_mex.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 15:14:21
 */

#ifndef _CODER_QUANZHANYI_MEX_H
#define _CODER_QUANZHANYI_MEX_H

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

void unsafe_Calculate_accurate_cylinders_from_multiple_measurement_points_mexFunction(
    int32_T nlhs, mxArray *plhs[6], int32_T nrhs, const mxArray *prhs[5]);

void unsafe_Generate_multi_layered_measurement_points_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[5]);

void unsafe_foot_of_perpendicular_from_a_point_to_a_line_mexFunction(
    int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[3]);

void unsafe_generate_unit_circle_with_normal_vector_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_QuanZhanYi_mex.h
 *
 * [EOF]
 */
