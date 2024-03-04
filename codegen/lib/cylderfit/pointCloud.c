/*
 * File: pointCloud.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

/* Include Files */
#include "pointCloud.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
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
  int i;
  int loop_ub;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(b_this->Location, i);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1->data[i];
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
  emxArray_real_T *a__8;
  emxArray_real_T *b_normals;
  emxArray_real_T *loc;
  emxArray_real_T *queryPoints;
  emxArray_uint32_T *indices;
  emxArray_uint32_T *valid;
  int K;
  int i;
  int loop_ub;
  boolean_T createIndex;
  K = this->Location->size[0];
  if (6 < K) {
    K = 6;
  }
  if (this->Location->size[0] <= 2) {
    K = this->Location->size[0];
    i = normals->size[0] * normals->size[1];
    normals->size[0] = K;
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(normals, i);
    loop_ub = K * 3;
    for (i = 0; i < loop_ub; i++) {
      normals->data[i] = rtNaN;
    }
  } else {
    emxInit_real_T(&loc, 2);
    if (!this->HasLocationHandleAllocated) {
      i = loc->size[0] * loc->size[1];
      loc->size[0] = this->Location->size[0];
      loc->size[1] = 3;
      emxEnsureCapacity_real_T(loc, i);
      loop_ub = this->Location->size[0] * 3;
      for (i = 0; i < loop_ub; i++) {
        loc->data[i] = this->Location->data[i];
      }
      this->LocationHandle = NULL;
      if (loc->size[0] != 0) {
        kdtreeGetLocationDataPointer_double(&loc->data[0],
                                            (unsigned int)loc->size[0], 3U,
                                            &this->LocationHandle);
      }
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
      i = this->Location->size[0];
      if (i < 0) {
        i = 0;
      }
      kdtreeIndex_double(this->Kdtree, this->LocationHandle, (unsigned int)i,
                         3U, 4.0, 1.0, 0.0);
    }
    i = loc->size[0] * loc->size[1];
    loc->size[0] = this->Location->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(loc, i);
    loop_ub = this->Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      loc->data[i] = this->Location->data[i];
    }
    emxInit_real_T(&queryPoints, 2);
    i = queryPoints->size[0] * queryPoints->size[1];
    queryPoints->size[0] = loc->size[0];
    queryPoints->size[1] = 3;
    emxEnsureCapacity_real_T(queryPoints, i);
    loop_ub = loc->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      queryPoints->data[i] = loc->data[i];
    }
    emxInit_real_T(&a__8, 2);
    emxInit_uint32_T(&indices, 2);
    emxInit_uint32_T(&valid, 1);
    i = indices->size[0] * indices->size[1];
    indices->size[0] = K;
    indices->size[1] = loc->size[0];
    emxEnsureCapacity_uint32_T(indices, i);
    i = a__8->size[0] * a__8->size[1];
    a__8->size[0] = K;
    a__8->size[1] = loc->size[0];
    emxEnsureCapacity_real_T(a__8, i);
    i = valid->size[0];
    valid->size[0] = loc->size[0];
    emxEnsureCapacity_uint32_T(valid, i);
    if (K < 0) {
      K = 0;
    }
    emxInit_real_T(&b_normals, 2);
    kdtreeKNNSearch_double(this->Kdtree, &queryPoints->data[0],
                           (unsigned int)loc->size[0], 3U, (unsigned int)K, 0.0,
                           0.0, &indices->data[0], &a__8->data[0],
                           &valid->data[0], 2000, 500U);
    i = b_normals->size[0] * b_normals->size[1];
    b_normals->size[0] = loc->size[0];
    b_normals->size[1] = 3;
    emxEnsureCapacity_real_T(b_normals, i);
    PCANormalImpl_double(&loc->data[0], &indices->data[0], &valid->data[0],
                         (unsigned int)loc->size[0],
                         (unsigned int)indices->size[0], &b_normals->data[0]);
    i = normals->size[0] * normals->size[1];
    normals->size[0] = b_normals->size[0];
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(normals, i);
    loop_ub = b_normals->size[0] * 3;
    emxFree_real_T(&queryPoints);
    emxFree_uint32_T(&valid);
    emxFree_uint32_T(&indices);
    emxFree_real_T(&a__8);
    emxFree_real_T(&loc);
    for (i = 0; i < loop_ub; i++) {
      normals->data[i] = b_normals->data[i];
    }
    emxFree_real_T(&b_normals);
  }
}

/*
 * File trailer for pointCloud.c
 *
 * [EOF]
 */
