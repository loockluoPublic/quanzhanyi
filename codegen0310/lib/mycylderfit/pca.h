/*
 * File: pca.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

#ifndef PCA_H
#define PCA_H

/* Include Files */
#include "mycylderfit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void pca(const emxArray_real_T *x, double varargout_1_data[],
         int varargout_1_size[2], emxArray_real_T *varargout_2,
         double varargout_3_data[], int *varargout_3_size,
         emxArray_real_T *varargout_4, double varargout_5_data[],
         int *varargout_5_size, double varargout_6_data[],
         int varargout_6_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pca.h
 *
 * [EOF]
 */
