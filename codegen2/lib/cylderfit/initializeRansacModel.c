/*
 * File: initializeRansacModel.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "initializeRansacModel.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const b_pointCloud *ptCloud
 *                pointCloud *iobj_0
 *                int *status
 *                pointCloud **pc
 *                double validPtCloudIndices_data[]
 *                int *validPtCloudIndices_size
 * Return Type  : void
 */
void initializeRansacModel(const b_pointCloud *ptCloud, pointCloud *iobj_0,
                           int *status, pointCloud **pc,
                           double validPtCloudIndices_data[],
                           int *validPtCloudIndices_size)
{
  emxArray_real_T *tempI;
  emxArray_real_T *tempNV;
  emxArray_uint8_T *C_;
  int nz[45];
  int tmp_data[45];
  int b_i;
  int i;
  int j;
  int k;
  int xoffset;
  signed char b_tmp_data[45];
  signed char c_tmp_data[45];
  signed char d_tmp_data[45];
  boolean_T tf[135];
  boolean_T indices[45];
  boolean_T b;
  for (i = 0; i < 135; i++) {
    tf[i] =
        ((!rtIsInf(ptCloud->Location[i])) && (!rtIsNaN(ptCloud->Location[i])));
  }
  for (j = 0; j < 45; j++) {
    nz[j] = tf[j];
  }
  for (k = 0; k < 2; k++) {
    xoffset = (k + 1) * 45;
    for (j = 0; j < 45; j++) {
      nz[j] += tf[xoffset + j];
    }
  }
  j = 0;
  xoffset = 0;
  for (b_i = 0; b_i < 45; b_i++) {
    b = (nz[b_i] == 3);
    indices[b_i] = b;
    if (b) {
      j++;
      tmp_data[xoffset] = b_i + 1;
      xoffset++;
    }
  }
  emxInit_uint8_T(&C_, 2);
  if ((ptCloud->Color->size[0] != 0) && (ptCloud->Color->size[1] != 0)) {
    k = 0;
    xoffset = 0;
    for (b_i = 0; b_i < 45; b_i++) {
      if (indices[b_i]) {
        k++;
        b_tmp_data[xoffset] = (signed char)(b_i + 1);
        xoffset++;
      }
    }
    xoffset = ptCloud->Color->size[1];
    i = C_->size[0] * C_->size[1];
    C_->size[0] = k;
    C_->size[1] = xoffset;
    emxEnsureCapacity_uint8_T(C_, i);
    for (i = 0; i < xoffset; i++) {
      for (b_i = 0; b_i < k; b_i++) {
        C_->data[b_i + C_->size[0] * i] =
            ptCloud->Color
                ->data[(b_tmp_data[b_i] + ptCloud->Color->size[0] * i) - 1];
      }
    }
  } else {
    C_->size[0] = 0;
    C_->size[1] = 0;
  }
  emxInit_real_T(&tempNV, 2);
  if ((ptCloud->Normal->size[0] != 0) && (ptCloud->Normal->size[1] != 0)) {
    k = 0;
    xoffset = 0;
    for (b_i = 0; b_i < 45; b_i++) {
      if (indices[b_i]) {
        k++;
        c_tmp_data[xoffset] = (signed char)(b_i + 1);
        xoffset++;
      }
    }
    xoffset = ptCloud->Normal->size[1];
    i = tempNV->size[0] * tempNV->size[1];
    tempNV->size[0] = k;
    tempNV->size[1] = xoffset;
    emxEnsureCapacity_real_T(tempNV, i);
    for (i = 0; i < xoffset; i++) {
      for (b_i = 0; b_i < k; b_i++) {
        tempNV->data[b_i + tempNV->size[0] * i] =
            ptCloud->Normal
                ->data[(c_tmp_data[b_i] + ptCloud->Normal->size[0] * i) - 1];
      }
    }
  } else {
    tempNV->size[0] = 0;
    tempNV->size[1] = 0;
  }
  emxInit_real_T(&tempI, 2);
  if ((ptCloud->Intensity->size[0] != 0) &&
      (ptCloud->Intensity->size[1] != 0)) {
    k = 0;
    xoffset = 0;
    for (b_i = 0; b_i < 45; b_i++) {
      if (indices[b_i]) {
        k++;
        d_tmp_data[xoffset] = (signed char)(b_i + 1);
        xoffset++;
      }
    }
    xoffset = ptCloud->Intensity->size[1];
    i = tempI->size[0] * tempI->size[1];
    tempI->size[0] = k;
    tempI->size[1] = xoffset;
    emxEnsureCapacity_real_T(tempI, i);
    for (i = 0; i < xoffset; i++) {
      for (b_i = 0; b_i < k; b_i++) {
        tempI->data[b_i + tempI->size[0] * i] =
            ptCloud->Intensity
                ->data[(d_tmp_data[b_i] + ptCloud->Intensity->size[0] * i) - 1];
      }
    }
  } else {
    tempI->size[0] = 0;
    tempI->size[1] = 0;
  }
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1];
  iobj_0->Location->size[0] = j;
  iobj_0->Location->size[1] = 3;
  emxEnsureCapacity_real_T(iobj_0->Location, i);
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < j; b_i++) {
      iobj_0->Location->data[b_i + iobj_0->Location->size[0] * i] =
          ptCloud->Location[(tmp_data[b_i] + 45 * i) - 1];
    }
  }
  i = iobj_0->Color->size[0] * iobj_0->Color->size[1];
  iobj_0->Color->size[0] = C_->size[0];
  iobj_0->Color->size[1] = C_->size[1];
  emxEnsureCapacity_uint8_T(iobj_0->Color, i);
  xoffset = C_->size[0] * C_->size[1];
  for (i = 0; i < xoffset; i++) {
    iobj_0->Color->data[i] = C_->data[i];
  }
  emxFree_uint8_T(&C_);
  i = iobj_0->Normal->size[0] * iobj_0->Normal->size[1];
  iobj_0->Normal->size[0] = tempNV->size[0];
  iobj_0->Normal->size[1] = tempNV->size[1];
  emxEnsureCapacity_real_T(iobj_0->Normal, i);
  xoffset = tempNV->size[0] * tempNV->size[1];
  for (i = 0; i < xoffset; i++) {
    iobj_0->Normal->data[i] = tempNV->data[i];
  }
  emxFree_real_T(&tempNV);
  i = iobj_0->Intensity->size[0] * iobj_0->Intensity->size[1];
  iobj_0->Intensity->size[0] = tempI->size[0];
  iobj_0->Intensity->size[1] = tempI->size[1];
  emxEnsureCapacity_real_T(iobj_0->Intensity, i);
  xoffset = tempI->size[0] * tempI->size[1];
  for (i = 0; i < xoffset; i++) {
    iobj_0->Intensity->data[i] = tempI->data[i];
  }
  emxFree_real_T(&tempI);
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  eml_find(indices, tmp_data, validPtCloudIndices_size);
  for (i = 0; i < *validPtCloudIndices_size; i++) {
    validPtCloudIndices_data[i] = tmp_data[i];
  }
  *pc = iobj_0;
  xoffset = iobj_0->Location->size[0];
  *status = (xoffset < 2);
}

/*
 * File trailer for initializeRansacModel.c
 *
 * [EOF]
 */
