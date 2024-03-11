/*
 * File: mycylderfit2_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

/* Include Files */
#include "mycylderfit2_initialize.h"
#include "mycylderfit2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void mycylderfit2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_mycylderfit2 = true;
}

/*
 * File trailer for mycylderfit2_initialize.c
 *
 * [EOF]
 */
