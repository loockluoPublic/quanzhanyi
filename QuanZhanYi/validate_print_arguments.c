/*
 * File: validate_print_arguments.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Dec-2024 20:49:37
 */

/* Include Files */
#include "validate_print_arguments.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double varargin_1
 *                double varargin_2
 *                double varargin_3
 *                double varargin_4
 *                double validatedArguments[4]
 * Return Type  : void
 */
void validate_print_arguments(double varargin_1, double varargin_2,
                              double varargin_3, double varargin_4,
                              double validatedArguments[4])
{
  validatedArguments[0] = varargin_1;
  validatedArguments[1] = varargin_2;
  validatedArguments[2] = varargin_3;
  validatedArguments[3] = varargin_4;
}

/*
 * File trailer for validate_print_arguments.c
 *
 * [EOF]
 */
