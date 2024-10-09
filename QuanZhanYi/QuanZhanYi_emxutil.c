/*
 * File: QuanZhanYi_emxutil.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 09-Oct-2024 15:40:33
 */

/* Include Files */
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : cell_wrap_1 *dst
 *                const cell_wrap_1 *src
 * Return Type  : void
 */
void emxCopyStruct_cell_wrap_1(cell_wrap_1 *dst, const cell_wrap_1 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

/*
 * Arguments    : cell_wrap_4 *dst
 *                const cell_wrap_4 *src
 * Return Type  : void
 */
void emxCopyStruct_cell_wrap_4(cell_wrap_4 *dst, const cell_wrap_4 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

/*
 * Arguments    : emxArray_real_T **dst
 *                emxArray_real_T * const *src
 * Return Type  : void
 */
void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(boolean_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : cell_wrap_1 pMatrix[8]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_1(cell_wrap_1 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxFreeStruct_cell_wrap_1(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_1 pMatrix[4]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_11(cell_wrap_1 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxFreeStruct_cell_wrap_1(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[8]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxFreeStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[4]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_41(cell_wrap_4 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxFreeStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_1 *pStruct
 * Return Type  : void
 */
void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

/*
 * Arguments    : cell_wrap_4 *pStruct
 * Return Type  : void
 */
void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : cell_wrap_1 pMatrix[8]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_1(cell_wrap_1 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxInitStruct_cell_wrap_1(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_1 pMatrix[4]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_11(cell_wrap_1 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxInitStruct_cell_wrap_1(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[8]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_4(cell_wrap_4 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxInitStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[4]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_41(cell_wrap_4 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxInitStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_1 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

/*
 * Arguments    : cell_wrap_4 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 * Return Type  : void
 */
void emxReserve_real_T(emxArray_real_T *emxArray)
{
  int i;
  int numel;
  void *newData;
  if (emxArray->allocatedSize < 4) {
    numel = 1;
    for (i = 0; i < emxArray->numDimensions; i++) {
      numel *= emxArray->size[i];
    }
    newData = malloc(4U * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)numel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = 4;
    emxArray->canFreeData = true;
  }
}

/*
 * File trailer for QuanZhanYi_emxutil.c
 *
 * [EOF]
 */
