/*
 * File: _coder_foot_of_perpendicular_from_a_point_to_a_line_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 17:37:00
 */

#ifndef _CODER_FOOT_OF_PERPENDICULAR_FROM_A_POINT_TO_A_LINE_API_H
#define _CODER_FOOT_OF_PERPENDICULAR_FROM_A_POINT_TO_A_LINE_API_H

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
void Generate_multi_layered_measurement_points(
    emxArray_real_T *x, emxArray_real_T *y, emxArray_real_T *z, real_T num,
    real_T laynum, real_T P3[3], real_T P4[3], emxArray_real_T *Point_test);

void Three_Points_Initial_Rough_Cylindrical_Judgment(real_T x[3], real_T y[3],
                                                     real_T z[3], real_T S[3],
                                                     real_T *x0, real_T *b_y0,
                                                     real_T *z0);

void c_Generate_multi_layered_measur(const mxArray *const prhs[7],
                                     const mxArray **plhs);

void c_Three_Points_Initial_Rough_Cy(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[4]);

void c_foot_of_perpendicular_from_a_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3]);

void c_generate_unit_circle_with_nor(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3]);

void foot_of_perpendicular_from_a_point_to_a_line(real_T P_outer[3],
                                                  real_T P_lines1[3],
                                                  real_T P_lines2[3],
                                                  real_T *xN1, real_T *yN1,
                                                  real_T *zN1);

void foot_of_perpendicular_from_a_point_to_a_line_atexit(void);

void foot_of_perpendicular_from_a_point_to_a_line_initialize(void);

void foot_of_perpendicular_from_a_point_to_a_line_terminate(void);

void foot_of_perpendicular_from_a_point_to_a_line_xil_shutdown(void);

void foot_of_perpendicular_from_a_point_to_a_line_xil_terminate(void);

void generate_unit_circle_with_normal_vector(real_T t1, real_T t2, real_T num,
                                             emxArray_real_T *x_circle1,
                                             emxArray_real_T *y_circle1,
                                             emxArray_real_T *z_circle1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_foot_of_perpendicular_from_a_point_to_a_line_api.h
 *
 * [EOF]
 */
