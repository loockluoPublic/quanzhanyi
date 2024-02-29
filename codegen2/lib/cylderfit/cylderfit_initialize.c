/*
 * File: cylderfit_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 21:50:24
 */

/* Include Files */
#include "cylderfit_initialize.h"
#include "cylderfit_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void cylderfit_initialize(void)
{
  rt_InitInfAndNaN();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_cylderfit = true;
}

/*
 * File trailer for cylderfit_initialize.c
 *
 * [EOF]
 */
