/*
 * File: mtimes.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 12:33:43
 */

/* Include Files */
#include "mtimes.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
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
