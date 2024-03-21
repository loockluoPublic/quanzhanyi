/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 21-Mar-2024 21:48:40
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "generate_unit_circle_with_normal_vector_emxAPI.h"
#include "generate_unit_circle_with_normal_vector_terminate.h"
#include "generate_unit_circle_with_normal_vector_types.h"

/* Function Declarations */
static double argInit_real_T(void);

static void c_main_generate_unit_circle_wit(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void c_main_generate_unit_circle_wit(void)
{
  emxArray_real_T *x_circle;
  emxArray_real_T *y_circle;
  emxArray_real_T *z_circle;
  double t1_tmp;
  emxInitArray_real_T(&x_circle, 2);
  emxInitArray_real_T(&y_circle, 2);
  emxInitArray_real_T(&z_circle, 2);
  /* Initialize function 'generate_unit_circle_with_normal_vector' input
   * arguments. */
  t1_tmp = argInit_real_T();
  /* Call the entry-point 'generate_unit_circle_with_normal_vector'. */
  generate_unit_circle_with_normal_vector(t1_tmp, t1_tmp, t1_tmp, x_circle,
                                          y_circle, z_circle);
  emxDestroyArray_real_T(z_circle);
  emxDestroyArray_real_T(y_circle);
  emxDestroyArray_real_T(x_circle);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  c_main_generate_unit_circle_wit();
  /* Terminate the application.
You do not need to do this more than one time. */
  generate_unit_circle_with_normal_vector_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
