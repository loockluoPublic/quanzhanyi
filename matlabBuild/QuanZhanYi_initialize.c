/*
 * File: QuanZhanYi_initialize.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 03-Jan-2025 23:51:41
 */

/* Include Files */
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void QuanZhanYi_initialize(void)
{
  rt_InitInfAndNaN();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_QuanZhanYi = true;
}

/*
 * File trailer for QuanZhanYi_initialize.c
 *
 * [EOF]
 */
