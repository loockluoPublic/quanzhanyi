/*
 * File: sortrows.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Dec-2024 21:47:53
 */

/* Include Files */
#include "sortrows.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *y
 * Return Type  : void
 */
void b_sortrows(emxArray_real_T *y)
{
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *ycol;
  double v1;
  double v2;
  double *y_data;
  double *ycol_data;
  int i;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int p;
  int pEnd;
  int q;
  int qEnd;
  int v1_tmp_tmp;
  int v2_tmp_tmp;
  int *idx_data;
  int *iwork_data;
  y_data = y->data;
  n = y->size[0] + 1;
  emxInit_int32_T(&idx, 1);
  pEnd = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(idx, pEnd);
  idx_data = idx->data;
  i2 = y->size[0];
  for (pEnd = 0; pEnd < i2; pEnd++) {
    idx_data[pEnd] = 0;
  }
  if (y->size[0] == 0) {
    for (k = 0; k <= n - 2; k++) {
      idx_data[k] = k + 1;
    }
  } else {
    emxInit_int32_T(&iwork, 1);
    pEnd = iwork->size[0];
    iwork->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(iwork, pEnd);
    iwork_data = iwork->data;
    pEnd = y->size[0] - 1;
    for (k = 1; k <= pEnd; k += 2) {
      v1 = y_data[k - 1];
      v2 = y_data[k];
      if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
          rtIsNaN(v2)) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((y->size[0] & 1) != 0) {
      idx_data[y->size[0] - 1] = y->size[0];
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          v1_tmp_tmp = idx_data[p - 1];
          v1 = y_data[v1_tmp_tmp - 1];
          v2_tmp_tmp = idx_data[q - 1];
          v2 = y_data[v2_tmp_tmp - 1];
          if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
              rtIsNaN(v2)) {
            iwork_data[k] = v1_tmp_tmp;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = idx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = v2_tmp_tmp;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    emxFree_int32_T(&iwork);
  }
  i2 = y->size[0] - 1;
  emxInit_real_T(&ycol, 1);
  pEnd = ycol->size[0];
  ycol->size[0] = y->size[0];
  emxEnsureCapacity_real_T(ycol, pEnd);
  ycol_data = ycol->data;
  for (j = 0; j < 2; j++) {
    for (i = 0; i <= i2; i++) {
      ycol_data[i] = y_data[(idx_data[i] + y->size[0] * j) - 1];
    }
    for (i = 0; i <= i2; i++) {
      y_data[i + y->size[0] * j] = ycol_data[i];
    }
  }
  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
}

/*
 * Arguments    : emxArray_real_T *y
 * Return Type  : void
 */
void sortrows(emxArray_real_T *y)
{
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *ycol;
  double v1;
  double v2;
  double *y_data;
  double *ycol_data;
  int i;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int p;
  int pEnd;
  int q;
  int qEnd;
  int v1_tmp_tmp;
  int v2_tmp_tmp;
  int *idx_data;
  int *iwork_data;
  y_data = y->data;
  n = y->size[0] + 1;
  emxInit_int32_T(&idx, 1);
  pEnd = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(idx, pEnd);
  idx_data = idx->data;
  i2 = y->size[0];
  for (pEnd = 0; pEnd < i2; pEnd++) {
    idx_data[pEnd] = 0;
  }
  if (y->size[0] == 0) {
    for (k = 0; k <= n - 2; k++) {
      idx_data[k] = k + 1;
    }
  } else {
    emxInit_int32_T(&iwork, 1);
    pEnd = iwork->size[0];
    iwork->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(iwork, pEnd);
    iwork_data = iwork->data;
    pEnd = y->size[0] - 1;
    for (k = 1; k <= pEnd; k += 2) {
      v1 = y_data[(k + y->size[0] * 4) - 1];
      v2 = y_data[k + y->size[0] * 4];
      if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
          rtIsNaN(v2)) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((y->size[0] & 1) != 0) {
      idx_data[y->size[0] - 1] = y->size[0];
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          v1_tmp_tmp = idx_data[p - 1];
          v1 = y_data[(v1_tmp_tmp + y->size[0] * 4) - 1];
          v2_tmp_tmp = idx_data[q - 1];
          v2 = y_data[(v2_tmp_tmp + y->size[0] * 4) - 1];
          if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
              rtIsNaN(v2)) {
            iwork_data[k] = v1_tmp_tmp;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = idx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = v2_tmp_tmp;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    emxFree_int32_T(&iwork);
  }
  i2 = y->size[0] - 1;
  emxInit_real_T(&ycol, 1);
  pEnd = ycol->size[0];
  ycol->size[0] = y->size[0];
  emxEnsureCapacity_real_T(ycol, pEnd);
  ycol_data = ycol->data;
  for (j = 0; j < 5; j++) {
    for (i = 0; i <= i2; i++) {
      ycol_data[i] = y_data[(idx_data[i] + y->size[0] * j) - 1];
    }
    for (i = 0; i <= i2; i++) {
      y_data[i + y->size[0] * j] = ycol_data[i];
    }
  }
  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
}

/*
 * File trailer for sortrows.c
 *
 * [EOF]
 */
