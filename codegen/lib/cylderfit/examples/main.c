/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
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
#include "mycylderfit.h"
#include "mycylderfit_emxAPI.h"
#include "mycylderfit_terminate.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"
#include <emscripten.h>

/* Function Declarations */
static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static double argInit_real_T(void);

static void main_mycylderfit(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  const int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &i);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }
  return result;
}

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
EMSCRIPTEN_KEEPALIVE
static void main_mycylderfit(void)
{
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  double xn1;
  double xn2;
  double xn3;
  double xn4;
  double xn5;
  double xn6;
  double xn7;
  /* Initialize function 'mycylderfit' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'y'. */
  y = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'z'. */
  z = argInit_Unboundedx1_real_T();
  /* Call the entry-point 'mycylderfit'. */
  mycylderfit(x, y, z, &xn1, &xn2, &xn3, &xn4, &xn5, &xn6, &xn7);
  emxDestroyArray_real_T(z);
  emxDestroyArray_real_T(y);
  emxDestroyArray_real_T(x);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
EMSCRIPTEN_KEEPALIVE
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_mycylderfit();
  /* Terminate the application.
You do not need to do this more than one time. */
  mycylderfit_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
