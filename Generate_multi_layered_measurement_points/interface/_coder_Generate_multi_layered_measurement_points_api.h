/*
 * File: _coder_Generate_multi_layered_measurement_points_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 24-Mar-2024 21:24:04
 */

#ifndef _CODER_GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_API_H
#define _CODER_GENERATE_MULTI_LAYERED_MEASUREMENT_POINTS_API_H

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

void Generate_multi_layered_measurement_points_atexit(void);

void Generate_multi_layered_measurement_points_initialize(void);

void Generate_multi_layered_measurement_points_terminate(void);

void Generate_multi_layered_measurement_points_xil_shutdown(void);

void Generate_multi_layered_measurement_points_xil_terminate(void);

void c_Generate_multi_layered_measur(const mxArray *const prhs[7],
                                     const mxArray **plhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Generate_multi_layered_measurement_points_api.h
 *
 * [EOF]
 */
