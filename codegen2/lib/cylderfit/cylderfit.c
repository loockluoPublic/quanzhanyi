/*
 * File: cylderfit.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "cylderfit.h"
#include "PCANormalCore_api.hpp"
#include "cvstCG_kdtree.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_initialize.h"
#include "cylderfit_types.h"
#include "initializeRansacModel.h"
#include "msac.h"
#include "pcfitcylinder.h"
#include "rt_nonfinite.h"
#include <emscripten.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[45]
 *                const double y[45]
 *                const double z[45]
 *                emxArray_real_T *retrn
 * Return Type  : void
 */
EMSCRIPTEN_KEEPALIVE
void cylderfit(const double x[45], const double y[45], const double z[45],
               emxArray_real_T *retrn)
{
  void *locationPtr;
  b_pointCloud ptCloud_in;
  emxArray_real_T *b_y;
  emxArray_real_T *c_pc;
  emxArray_real_T *distances;
  emxArray_real_T *inlier_Idx;
  emxArray_real_T *p1p0;
  pointCloud pc;
  pointCloud *b_pc;
  double a__8_data[270];
  double loc[135];
  double queryPoints[135];
  double validPtCloudIndices_data[45];
  double modelParams_data[7];
  double d;
  unsigned int indices_data[270];
  unsigned int valid_data[45];
  int modelParams_size[2];
  int i;
  int k;
  int loop_ub;
  int sizes_idx_1;
  int vstride;
  signed char input_sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  if (!isInitialized_cylderfit) {
    cylderfit_initialize();
  }
  emxInitStruct_pointCloud(&ptCloud_in);
  emxInitStruct_pointCloud1(&pc);
  ptCloud_in.HasKdtreeConstructed = false;
  ptCloud_in.HasLocationHandleAllocated = false;
  for (i = 0; i < 45; i++) {
    ptCloud_in.Location[i] = x[i];
    ptCloud_in.Location[i + 45] = y[i];
    ptCloud_in.Location[i + 90] = z[i];
  }
  ptCloud_in.Color->size[0] = 0;
  ptCloud_in.Color->size[1] = 0;
  ptCloud_in.Normal->size[0] = 0;
  ptCloud_in.Normal->size[1] = 0;
  ptCloud_in.Intensity->size[0] = 0;
  ptCloud_in.Intensity->size[1] = 0;
  ptCloud_in.RangeData->size[0] = 0;
  ptCloud_in.RangeData->size[1] = 0;
  ptCloud_in.PointCloudArrayData->size[0] = 1;
  ptCloud_in.PointCloudArrayData->size[1] = 1;
  ptCloud_in.Kdtree = NULL;
  ptCloud_in.matlabCodegenIsDeleted = false;
  pc.matlabCodegenIsDeleted = true;
  memcpy(&loc[0], &ptCloud_in.Location[0], 135U * sizeof(double));
  ptCloud_in.LocationHandle = NULL;
  kdtreeGetLocationDataPointer_double(&loc[0], 45U, 3U,
                                      &ptCloud_in.LocationHandle);
  ptCloud_in.HasLocationHandleAllocated = true;
  ptCloud_in.Kdtree = NULL;
  kdtreeConstruct_double(&ptCloud_in.Kdtree);
  ptCloud_in.HasKdtreeConstructed = true;
  kdtreeIndex_double(ptCloud_in.Kdtree, ptCloud_in.LocationHandle, 45U, 3U, 4.0,
                     1.0, 0.0);
  for (i = 0; i < 135; i++) {
    d = ptCloud_in.Location[i];
    loc[i] = d;
    queryPoints[i] = d;
  }
  kdtreeKNNSearch_double(ptCloud_in.Kdtree, &queryPoints[0], 45U, 3U, 6U, 0.0,
                         0.0, &indices_data[0], &a__8_data[0], &valid_data[0],
                         2000, 500U);
  PCANormalImpl_double(&loc[0], &indices_data[0], &valid_data[0], 45U, 6U,
                       &queryPoints[0]);
  i = ptCloud_in.Normal->size[0] * ptCloud_in.Normal->size[1];
  ptCloud_in.Normal->size[0] = 45;
  ptCloud_in.Normal->size[1] = 3;
  emxEnsureCapacity_real_T(ptCloud_in.Normal, i);
  for (i = 0; i < 135; i++) {
    ptCloud_in.Normal->data[i] = queryPoints[i];
  }
  initializeRansacModel(&ptCloud_in, &pc, &sizes_idx_1, &b_pc,
                        validPtCloudIndices_data, &vstride);
  modelParams_size[0] = 1;
  modelParams_size[1] = 7;
  for (i = 0; i < 7; i++) {
    modelParams_data[i] = 0.0;
  }
  emxInit_real_T(&inlier_Idx, 2);
  if (sizes_idx_1 == 0) {
    if (pc.Location->size[0] != 0) {
      vstride = pc.Location->size[0];
    } else if ((pc.Normal->size[0] != 0) && (pc.Normal->size[1] != 0)) {
      vstride = pc.Normal->size[0];
    } else {
      vstride = 0;
      if (pc.Normal->size[0] > 0) {
        vstride = pc.Normal->size[0];
      }
    }
    empty_non_axis_sizes = (vstride == 0);
    if (empty_non_axis_sizes || (pc.Location->size[0] != 0)) {
      input_sizes_idx_1 = 3;
    } else {
      input_sizes_idx_1 = 0;
    }
    if (empty_non_axis_sizes ||
        ((pc.Normal->size[0] != 0) && (pc.Normal->size[1] != 0))) {
      sizes_idx_1 = pc.Normal->size[1];
    } else {
      sizes_idx_1 = 0;
    }
    emxInit_real_T(&c_pc, 2);
    i = c_pc->size[0] * c_pc->size[1];
    c_pc->size[0] = vstride;
    c_pc->size[1] = input_sizes_idx_1 + sizes_idx_1;
    emxEnsureCapacity_real_T(c_pc, i);
    loop_ub = input_sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (k = 0; k < vstride; k++) {
        c_pc->data[k + c_pc->size[0] * i] =
            pc.Location->data[k + pc.Location->size[0] * i];
      }
    }
    for (i = 0; i < sizes_idx_1; i++) {
      for (k = 0; k < vstride; k++) {
        c_pc->data[k + c_pc->size[0] * (i + input_sizes_idx_1)] =
            pc.Normal->data[k + vstride * i];
      }
    }
    msac(c_pc, &empty_non_axis_sizes, modelParams_data, modelParams_size);
    emxFree_real_T(&c_pc);
    if (empty_non_axis_sizes) {
      emxInit_real_T(&p1p0, 2);
      loop_ub = pc.Location->size[0];
      sizes_idx_1 = pc.Location->size[0];
      vstride = pc.Location->size[0];
      i = p1p0->size[0] * p1p0->size[1];
      p1p0->size[0] = loop_ub;
      p1p0->size[1] = 3;
      emxEnsureCapacity_real_T(p1p0, i);
      for (i = 0; i < loop_ub; i++) {
        p1p0->data[i] = pc.Location->data[i] - modelParams_data[0];
      }
      for (i = 0; i < sizes_idx_1; i++) {
        p1p0->data[i + p1p0->size[0]] =
            pc.Location->data[i + pc.Location->size[0]] - modelParams_data[1];
      }
      for (i = 0; i < vstride; i++) {
        p1p0->data[i + p1p0->size[0] * 2] =
            pc.Location->data[i + pc.Location->size[0] * 2] -
            modelParams_data[2];
      }
      loop_ub = p1p0->size[0];
      sizes_idx_1 = p1p0->size[0];
      vstride = p1p0->size[0];
      i = pc.Location->size[0] * pc.Location->size[1];
      pc.Location->size[0] = p1p0->size[0];
      pc.Location->size[1] = 3;
      emxEnsureCapacity_real_T(pc.Location, i);
      for (i = 0; i < loop_ub; i++) {
        pc.Location->data[i] =
            p1p0->data[i + p1p0->size[0]] * modelParams_data[5] -
            p1p0->data[i + p1p0->size[0] * 2] * modelParams_data[4];
      }
      for (i = 0; i < sizes_idx_1; i++) {
        pc.Location->data[i + pc.Location->size[0]] =
            p1p0->data[i + p1p0->size[0] * 2] * modelParams_data[3] -
            p1p0->data[i] * modelParams_data[5];
      }
      for (i = 0; i < vstride; i++) {
        pc.Location->data[i + pc.Location->size[0] * 2] =
            p1p0->data[i] * modelParams_data[4] -
            p1p0->data[i + p1p0->size[0]] * modelParams_data[3];
      }
      emxFree_real_T(&p1p0);
      emxInit_real_T(&b_y, 1);
      loop_ub = pc.Location->size[0] * 3;
      i = pc.Location->size[0] * pc.Location->size[1];
      pc.Location->size[1] = 3;
      emxEnsureCapacity_real_T(pc.Location, i);
      for (i = 0; i < loop_ub; i++) {
        pc.Location->data[i] *= pc.Location->data[i];
      }
      if (pc.Location->size[0] == 0) {
        b_y->size[0] = 0;
      } else {
        vstride = pc.Location->size[0];
        i = b_y->size[0];
        b_y->size[0] = pc.Location->size[0];
        emxEnsureCapacity_real_T(b_y, i);
        for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
          b_y->data[loop_ub] = pc.Location->data[loop_ub];
        }
        for (k = 0; k < 2; k++) {
          sizes_idx_1 = (k + 1) * vstride;
          for (loop_ub = 0; loop_ub < vstride; loop_ub++) {
            b_y->data[loop_ub] += pc.Location->data[sizes_idx_1 + loop_ub];
          }
        }
      }
      vstride = b_y->size[0];
      for (k = 0; k < vstride; k++) {
        b_y->data[k] = sqrt(b_y->data[k]);
      }
      loop_ub = b_y->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_y->data[i] -= modelParams_data[6];
      }
      emxInit_real_T(&distances, 1);
      vstride = b_y->size[0];
      i = distances->size[0];
      distances->size[0] = b_y->size[0];
      emxEnsureCapacity_real_T(distances, i);
      for (k = 0; k < vstride; k++) {
        distances->data[k] = fabs(b_y->data[k]);
      }
      emxFree_real_T(&b_y);
      loop_ub = distances->size[0] - 1;
      vstride = 0;
      for (k = 0; k <= loop_ub; k++) {
        if (distances->data[k] < 0.0005) {
          vstride++;
        }
      }
      i = inlier_Idx->size[0] * inlier_Idx->size[1];
      inlier_Idx->size[0] = vstride;
      inlier_Idx->size[1] = 1;
      emxEnsureCapacity_real_T(inlier_Idx, i);
      sizes_idx_1 = 0;
      for (k = 0; k <= loop_ub; k++) {
        if (distances->data[k] < 0.0005) {
          inlier_Idx->data[sizes_idx_1] = validPtCloudIndices_data[k];
          sizes_idx_1++;
        }
      }
      emxFree_real_T(&distances);
      convertToFiniteCylinderModel(modelParams_data, &ptCloud_in, inlier_Idx);
    }
  }
  emxFree_real_T(&inlier_Idx);
  if ((modelParams_size[0] == 0) || (modelParams_size[1] == 0)) {
    modelParams_size[1] = 7;
    for (i = 0; i < 7; i++) {
      modelParams_data[i] = 0.0;
    }
  }
  if (!pc.matlabCodegenIsDeleted) {
    pc.matlabCodegenIsDeleted = true;
    if (pc.HasLocationHandleAllocated) {
      locationPtr = pc.LocationHandle;
      kdtreeDeleteLocationDataPointer_double(locationPtr);
      pc.HasLocationHandleAllocated = false;
    }
    if (pc.HasKdtreeConstructed) {
      locationPtr = pc.Kdtree;
      kdtreeDeleteObj_double(locationPtr);
      pc.HasKdtreeConstructed = false;
    }
  }
  i = retrn->size[0] * retrn->size[1];
  retrn->size[0] = 1;
  retrn->size[1] = modelParams_size[1];
  emxEnsureCapacity_real_T(retrn, i);
  loop_ub = modelParams_size[1];
  for (i = 0; i < loop_ub; i++) {
    retrn->data[i] = modelParams_data[i];
  }
  if (!ptCloud_in.matlabCodegenIsDeleted) {
    if (ptCloud_in.HasLocationHandleAllocated) {
      kdtreeDeleteLocationDataPointer_double(ptCloud_in.LocationHandle);
    }
    kdtreeDeleteObj_double(ptCloud_in.Kdtree);
  }
  emxFreeStruct_pointCloud(&ptCloud_in);
  emxFreeStruct_pointCloud1(&pc);
}

/*
 * File trailer for cylderfit.c
 *
 * [EOF]
 */
