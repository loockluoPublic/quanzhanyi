/*
 * File: mtimes.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Mar-2025 21:42:51
 */

/* Include Files */
#include "mtimes.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double A[4]
 *                const emxArray_real_T *B
 *                emxArray_real_T *C
 * Return Type  : void
 */
void b_mtimes(const double A[4], const emxArray_real_T *B, emxArray_real_T *C)
{
  const double *B_data;
  double *C_data;
  int j;
  int n;
  B_data = B->data;
  n = B->size[0];
  j = C->size[0] * C->size[1];
  C->size[0] = 1;
  C->size[1] = B->size[0];
  emxEnsureCapacity_real_T(C, j);
  C_data = C->data;
  for (j = 0; j < n; j++) {
    C_data[j] = ((A[0] * B_data[j] + A[1] * B_data[B->size[0] + j]) +
                 A[2] * B_data[(B->size[0] << 1) + j]) +
                A[3] * B_data[3 * B->size[0] + j];
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double C[9]
 * Return Type  : void
 */
void c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, double C[9])
{
  const double *A_data;
  const double *B_data;
  double bkj;
  int boffset;
  int coffset;
  int inner;
  int j;
  int k;
  B_data = B->data;
  A_data = A->data;
  inner = A->size[0];
  for (j = 0; j < 3; j++) {
    coffset = j * 3;
    boffset = j * B->size[0];
    C[coffset] = 0.0;
    C[coffset + 1] = 0.0;
    C[coffset + 2] = 0.0;
    for (k = 0; k < inner; k++) {
      bkj = B_data[boffset + k];
      C[coffset] += A_data[k] * bkj;
      C[coffset + 1] += A_data[A->size[0] + k] * bkj;
      C[coffset + 2] += A_data[(A->size[0] << 1) + k] * bkj;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double C[3]
 * Return Type  : void
 */
void d_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, double C[3])
{
  const double *A_data;
  const double *B_data;
  int inner;
  int k;
  B_data = B->data;
  A_data = A->data;
  inner = A->size[0];
  C[0] = 0.0;
  C[1] = 0.0;
  C[2] = 0.0;
  for (k = 0; k < inner; k++) {
    C[0] += A_data[k] * B_data[k];
    C[1] += A_data[A->size[0] + k] * B_data[k];
    C[2] += A_data[(A->size[0] << 1) + k] * B_data[k];
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const double B[9]
 *                emxArray_real_T *C
 * Return Type  : void
 */
void mtimes(const emxArray_real_T *A, const double B[9], emxArray_real_T *C)
{
  const double *A_data;
  double *C_data;
  int aoffset;
  int boffset;
  int coffset;
  int i;
  int j;
  int m;
  A_data = A->data;
  m = A->size[1];
  coffset = C->size[0] * C->size[1];
  C->size[0] = A->size[1];
  C->size[1] = 3;
  emxEnsureCapacity_real_T(C, coffset);
  C_data = C->data;
  for (j = 0; j < 3; j++) {
    coffset = j * m;
    boffset = j * 3;
    for (i = 0; i < m; i++) {
      aoffset = i * 3;
      C_data[coffset + i] = (A_data[aoffset] * B[boffset] +
                             A_data[aoffset + 1] * B[boffset + 1]) +
                            A_data[aoffset + 2] * B[boffset + 2];
    }
  }
}

/*
 * File trailer for mtimes.c
 *
 * [EOF]
 */
