/*
 * File: cylderfit_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 03-Mar-2024 21:44:33
 */

/* Include Files */
#include "cylderfit_initialize.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void cylderfit_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_cylderfit = true;
}

/*
 * File trailer for cylderfit_initialize.c
 *
 * [EOF]
 */
