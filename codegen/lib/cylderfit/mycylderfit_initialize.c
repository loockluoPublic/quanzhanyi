/*
 * File: mycylderfit_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

/* Include Files */
#include "mycylderfit_initialize.h"
#include "mycylderfit_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void mycylderfit_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_mycylderfit = true;
}

/*
 * File trailer for mycylderfit_initialize.c
 *
 * [EOF]
 */
