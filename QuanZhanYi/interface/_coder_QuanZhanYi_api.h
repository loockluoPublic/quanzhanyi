/*
 * File: _coder_QuanZhanYi_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Mar-2024 15:44:04
 */

#ifndef _CODER_QUANZHANYI_API_H
#define _CODER_QUANZHANYI_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Calculate_accurate_cylinders_from_multiple_measurement_points(
    emxArray_real_T *points, real_T P_bound1[3], real_T P_bound2[3],
    real_T Mcenter[3], real_T MTaon[3], real_T *Mradial,
    emxArray_real_T *Err_every, real_T Bottom_round_center1[3],
    real_T Bottom_round_center2[3]);

void Generate_multi_layered_measurement_points(emxArray_real_T *Point_out,
                                               real_T num, real_T laynum,
                                               real_T P3[3], real_T P4[3],
                                               emxArray_real_T *Point_test);

void QuanZhanYi_atexit(void);

void QuanZhanYi_initialize(void);

void QuanZhanYi_terminate(void);

void QuanZhanYi_xil_shutdown(void);

void QuanZhanYi_xil_terminate(void);

void c_Calculate_accurate_cylinders_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[6]);

void c_Generate_multi_layered_measur(const mxArray *const prhs[5],
                                     const mxArray **plhs);

void c_foot_of_perpendicular_from_a_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3]);

void c_generate_unit_circle_with_nor(const mxArray *const prhs[3],
                                     const mxArray **plhs);

void foot_of_perpendicular_from_a_point_to_a_line(real_T P_outer[3],
                                                  real_T P_lines1[3],
                                                  real_T P_lines2[3],
                                                  real_T *xN1, real_T *yN1,
                                                  real_T *zN1);

void generate_unit_circle_with_normal_vector(real_T azimuth, real_T elevation,
                                             real_T num,
                                             emxArray_real_T *Point_out);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_QuanZhanYi_api.h
 *
 * [EOF]
 */
