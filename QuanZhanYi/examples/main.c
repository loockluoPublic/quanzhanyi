/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Mar-2024 17:37:00
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
#include "Generate_multi_layered_measurement_points.h"
#include "Three_Points_Initial_Rough_Cylindrical_Judgment.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_emxAPI.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_terminate.h"
#include "foot_of_perpendicular_from_a_point_to_a_line_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_3x1_real_T(double result[3]);

static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static double argInit_real_T(void);

static void c_main_Generate_multi_layered_m(void);

static void c_main_Three_Points_Initial_Rou(void);

static void c_main_foot_of_perpendicular_fr(void);

static void c_main_generate_unit_circle_wit(void);

/* Function Definitions */
/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_3x1_real_T(double result[3])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  const int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real_T();
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
static void c_main_Generate_multi_layered_m(void)
{
  emxArray_real_T *Point_test;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  double P3_tmp[3];
  double num_tmp;
  emxInitArray_real_T(&Point_test, 2);
  /* Initialize function 'Generate_multi_layered_measurement_points' input
   * arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'y'. */
  y = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'z'. */
  z = argInit_Unboundedx1_real_T();
  num_tmp = argInit_real_T();
  /* Initialize function input argument 'P3'. */
  argInit_3x1_real_T(P3_tmp);
  /* Initialize function input argument 'P4'. */
  /* Call the entry-point 'Generate_multi_layered_measurement_points'. */
  Generate_multi_layered_measurement_points(x, y, z, num_tmp, num_tmp, P3_tmp,
                                            P3_tmp, Point_test);
  emxDestroyArray_real_T(Point_test);
  emxDestroyArray_real_T(z);
  emxDestroyArray_real_T(y);
  emxDestroyArray_real_T(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void c_main_Three_Points_Initial_Rou(void)
{
  double S[3];
  double x_tmp[3];
  double b_y0;
  double x0;
  double z0;
  /* Initialize function 'Three_Points_Initial_Rough_Cylindrical_Judgment' input
   * arguments. */
  /* Initialize function input argument 'x'. */
  argInit_3x1_real_T(x_tmp);
  /* Initialize function input argument 'y'. */
  /* Initialize function input argument 'z'. */
  /* Call the entry-point 'Three_Points_Initial_Rough_Cylindrical_Judgment'. */
  Three_Points_Initial_Rough_Cylindrical_Judgment(x_tmp, x_tmp, x_tmp, S, &x0,
                                                  &b_y0, &z0);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void c_main_foot_of_perpendicular_fr(void)
{
  double P_outer_tmp[3];
  double xN1;
  double yN1;
  double zN1;
  /* Initialize function 'foot_of_perpendicular_from_a_point_to_a_line' input
   * arguments. */
  /* Initialize function input argument 'P_outer'. */
  argInit_3x1_real_T(P_outer_tmp);
  /* Initialize function input argument 'P_lines1'. */
  /* Initialize function input argument 'P_lines2'. */
  /* Call the entry-point 'foot_of_perpendicular_from_a_point_to_a_line'. */
  foot_of_perpendicular_from_a_point_to_a_line(P_outer_tmp, P_outer_tmp,
                                               P_outer_tmp, &xN1, &yN1, &zN1);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void c_main_generate_unit_circle_wit(void)
{
  emxArray_real_T *x_circle1;
  emxArray_real_T *y_circle1;
  emxArray_real_T *z_circle1;
  double t1_tmp;
  emxInitArray_real_T(&x_circle1, 2);
  emxInitArray_real_T(&y_circle1, 2);
  emxInitArray_real_T(&z_circle1, 2);
  /* Initialize function 'generate_unit_circle_with_normal_vector' input
   * arguments. */
  t1_tmp = argInit_real_T();
  /* Call the entry-point 'generate_unit_circle_with_normal_vector'. */
  generate_unit_circle_with_normal_vector(t1_tmp, t1_tmp, t1_tmp, x_circle1,
                                          y_circle1, z_circle1);
  emxDestroyArray_real_T(z_circle1);
  emxDestroyArray_real_T(y_circle1);
  emxDestroyArray_real_T(x_circle1);
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
  c_main_foot_of_perpendicular_fr();
  c_main_Generate_multi_layered_m();
  c_main_generate_unit_circle_wit();
  c_main_Three_Points_Initial_Rou();
  /* Terminate the application.
You do not need to do this more than one time. */
  foot_of_perpendicular_from_a_point_to_a_line_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
