/*
 * File: QuanZhanYi_emxutil.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Aug-2024 22:07:29
 */

/* Include Files */
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : cell_wrap_6 *dst
 *                const cell_wrap_6 *src
 * Return Type  : void
 */
void emxCopyStruct_cell_wrap_6(cell_wrap_6 *dst, const cell_wrap_6 *src)
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
 * Arguments    : cell_wrap_6 pMatrix[4]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_6(cell_wrap_6 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxFreeStruct_cell_wrap_6(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_6 pMatrix[8]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_61(cell_wrap_6 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxFreeStruct_cell_wrap_6(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_6 *pStruct
 * Return Type  : void
 */
void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
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
 * Arguments    : cell_wrap_6 pMatrix[4]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_6(cell_wrap_6 pMatrix[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    emxInitStruct_cell_wrap_6(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_6 pMatrix[8]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_61(cell_wrap_6 pMatrix[8])
{
  int i;
  for (i = 0; i < 8; i++) {
    emxInitStruct_cell_wrap_6(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_6 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_6(cell_wrap_6 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
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
 * File trailer for QuanZhanYi_emxutil.c
 *
 * [EOF]
 */
