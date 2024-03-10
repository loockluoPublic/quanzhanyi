/*
 * File: pointCloud.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "pointCloud.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"
#include "PCANormalCore_api.hpp"
#include "cvstCG_kdtree.h"

/* Function Definitions */
/*
 * Arguments    : pointCloud *this
 *                const emxArray_real_T *varargin_1
 * Return Type  : pointCloud *
 */
pointCloud *pointCloud_pointCloud(pointCloud *this,
                                  const emxArray_real_T *varargin_1)
{
  pointCloud *b_this;
  const double *varargin_1_data;
  int i;
  int loop_ub;
  varargin_1_data = varargin_1->data;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(b_this->Location, i);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1_data[i];
  }
  b_this->Color->size[0] = 0;
  b_this->Color->size[1] = 0;
  b_this->Normal->size[0] = 0;
  b_this->Normal->size[1] = 0;
  b_this->Intensity->size[0] = 0;
  b_this->Intensity->size[1] = 0;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  b_this->ZLimitsInternal->size[0] = 0;
  b_this->ZLimitsInternal->size[1] = 0;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

/*
 * Arguments    : pointCloud *this
 *                emxArray_real_T *normals
 * Return Type  : void
 */
void pointCloud_surfaceNormalImpl(pointCloud *this, emxArray_real_T *normals)
{
  void *locationPtr;
  emxArray_real_T *a__9;
  emxArray_real_T *b_normals;
  emxArray_real_T *loc;
  emxArray_real_T *location;
  emxArray_uint32_T *indices;
  emxArray_uint32_T *valid;
  double *a__9_data;
  double *loc_data;
  double *normals_data;
  int K;
  int i;
  int loop_ub;
  unsigned int unnamed_idx_0;
  unsigned int *indices_data;
  unsigned int *valid_data;
  boolean_T createIndex;
  K = this->Location->size[0];
  if (K >= 6) {
    K = 6;
  }
  if (this->Location->size[0] <= 2) {
    unnamed_idx_0 = (unsigned int)this->Location->size[0];
    i = normals->size[0] * normals->size[1];
    normals->size[0] = (int)unnamed_idx_0;
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(normals, i);
    normals_data = normals->data;
    loop_ub = (int)unnamed_idx_0 * 3;
    for (i = 0; i < loop_ub; i++) {
      normals_data[i] = rtNaN;
    }
  } else {
    emxInit_real_T(&loc, 2);
    i = loc->size[0] * loc->size[1];
    loc->size[0] = this->Location->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(loc, i);
    loc_data = loc->data;
    loop_ub = this->Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      loc_data[i] = this->Location->data[i];
    }
    emxInit_real_T(&location, 2);
    if (!this->HasLocationHandleAllocated) {
      i = location->size[0] * location->size[1];
      location->size[0] = this->Location->size[0];
      location->size[1] = 3;
      emxEnsureCapacity_real_T(location, i);
      normals_data = location->data;
      loop_ub = this->Location->size[0] * 3;
      for (i = 0; i < loop_ub; i++) {
        normals_data[i] = this->Location->data[i];
      }
      locationPtr = NULL;
      if (this->Location->size[0] != 0) {
        kdtreeGetLocationDataPointer_double(
            &normals_data[0], (unsigned int)this->Location->size[0], 3U,
            &locationPtr);
      }
      this->LocationHandle = locationPtr;
      this->HasLocationHandleAllocated = true;
    }
    if (!this->HasKdtreeConstructed) {
      this->Kdtree = NULL;
      kdtreeConstruct_double(&this->Kdtree);
      this->HasKdtreeConstructed = true;
      createIndex = true;
    } else {
      createIndex =
          kdtreeNeedsReindex_double(this->Kdtree, this->LocationHandle);
    }
    if (createIndex) {
      kdtreeIndex_double(this->Kdtree, this->LocationHandle,
                         (unsigned int)this->Location->size[0], 3U, 4.0, 1.0,
                         0.0);
    }
    i = location->size[0] * location->size[1];
    location->size[0] = loc->size[0];
    location->size[1] = 3;
    emxEnsureCapacity_real_T(location, i);
    normals_data = location->data;
    loop_ub = loc->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      normals_data[i] = loc_data[i];
    }
    emxInit_real_T(&a__9, 2);
    emxInit_uint32_T(&indices, 2);
    emxInit_uint32_T(&valid, 1);
    emxInit_real_T(&b_normals, 2);
    i = indices->size[0] * indices->size[1];
    indices->size[0] = K;
    indices->size[1] = loc->size[0];
    emxEnsureCapacity_uint32_T(indices, i);
    indices_data = indices->data;
    i = a__9->size[0] * a__9->size[1];
    a__9->size[0] = K;
    a__9->size[1] = loc->size[0];
    emxEnsureCapacity_real_T(a__9, i);
    a__9_data = a__9->data;
    i = valid->size[0];
    valid->size[0] = loc->size[0];
    emxEnsureCapacity_uint32_T(valid, i);
    valid_data = valid->data;
    kdtreeKNNSearch_double(this->Kdtree, &normals_data[0],
                           (unsigned int)loc->size[0], 3U, (unsigned int)K, 0.0,
                           0.0, &indices_data[0], &a__9_data[0], &valid_data[0],
                           2000, 500U);
    i = b_normals->size[0] * b_normals->size[1];
    b_normals->size[0] = loc->size[0];
    b_normals->size[1] = 3;
    emxEnsureCapacity_real_T(b_normals, i);
    a__9_data = b_normals->data;
    PCANormalImpl_double(&loc_data[0], &indices_data[0], &valid_data[0],
                         (unsigned int)loc->size[0],
                         (unsigned int)indices->size[0], &a__9_data[0]);
    i = normals->size[0] * normals->size[1];
    normals->size[0] = b_normals->size[0];
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(normals, i);
    normals_data = normals->data;
    loop_ub = b_normals->size[0] * 3;
    emxFree_real_T(&location);
    emxFree_uint32_T(&valid);
    emxFree_uint32_T(&indices);
    emxFree_real_T(&a__9);
    emxFree_real_T(&loc);
    for (i = 0; i < loop_ub; i++) {
      normals_data[i] = a__9_data[i];
    }
    emxFree_real_T(&b_normals);
  }
}

/*
 * File trailer for pointCloud.c
 *
 * [EOF]
 */
