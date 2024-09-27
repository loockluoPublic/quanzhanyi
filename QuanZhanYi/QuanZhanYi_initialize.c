/*
 * File: QuanZhanYi_initialize.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Sep-2024 21:13:02
 */

/* Include Files */
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void QuanZhanYi_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_QuanZhanYi = true;
}

/*
 * File trailer for QuanZhanYi_initialize.c
 *
 * [EOF]
 */
