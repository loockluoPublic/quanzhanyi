/*
 * File: main.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 09-Oct-2025 22:40:58
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
#include "Calculat_A_and_B_Points.h"
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "Calculate_rectangle_from_vertex.h"
#include "Calculate_rectangle_from_vertex8.h"
#include "CrossLine.h"
#include "GenerateTrianglePoints.h"
#include "Generate_multi_layered_measurement_points.h"
#include "JuXingFuCe.h"
#include "OffsetCalculate.h"
#include "QuanZhanYi_emxAPI.h"
#include "QuanZhanYi_terminate.h"
#include "QuanZhanYi_types.h"
#include "RepeatSurvey.h"
#include "ShengDaoGaoDu.h"
#include "ShengLuJiaoJiSuan.h"
#include "YuanXingFuCe.h"
#include "YuanZhuJiaoDian.h"
#include "angle2point.h"
#include "fitcircle.h"
#include "foot_of_perpendicular_from_a_point_to_a_line.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "generate_unit_circle_with_normal_vector2.h"
#include "myvrrotvec2mat.h"
#include "planefit.h"
#include "planefit4.h"
#include "planefit8.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1x8_real_T(double result[8]);

static emxArray_real_T *argInit_1xUnbounded_real_T(void);

static void argInit_3x1_real_T(double result[3]);

static emxArray_real_T *argInit_3xUnbounded_real_T(void);

static void argInit_4x1_real_T(double result[4]);

static emxArray_real_T *argInit_4xUnbounded_real_T(void);

static emxArray_real_T *argInit_Unboundedx2_real_T(void);

static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : double result[8]
 * Return Type  : void
 */
static void argInit_1x8_real_T(double result[8])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 8; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx1] = argInit_real_T();
    }
  }
  return result;
}

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
static emxArray_real_T *argInit_3xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(3, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : double result[4]
 * Return Type  : void
 */
static void argInit_4x1_real_T(double result[4])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_4xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(4, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + 4 * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx2_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
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
  main_angle2point();
  main_Calculat_A_and_B_Points();
  main_Calculat_A_and_B_Points_after_Offest2();
  main_Calculat_JuXing_A_and_B_Points_after_Offest();
  main_Calculate_accurate_cylinders_from_multiple_measurement_points2();
  main_Calculate_rectangle_from_vertex();
  main_Calculate_rectangle_from_vertex8();
  main_CrossLine();
  main_fitcircle();
  main_foot_of_perpendicular_from_a_point_to_a_line();
  main_Generate_multi_layered_measurement_points();
  main_generate_unit_circle_with_normal_vector();
  main_generate_unit_circle_with_normal_vector2();
  main_GenerateTrianglePoints();
  main_JuXingFuCe();
  main_myvrrotvec2mat();
  main_OffsetCalculate();
  main_planefit();
  main_planefit4();
  main_planefit8();
  main_RepeatSurvey();
  main_ShengDaoGaoDu();
  main_ShengLuJiaoJiSuan();
  main_YuanXingFuCe();
  main_YuanZhuJiaoDian();
  /* Terminate the application.
You do not need to do this more than one time. */
  QuanZhanYi_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculat_A_and_B_Points(void)
{
  emxArray_real_T *PointTable_A;
  emxArray_real_T *PointTable_B;
  double MTaon_tmp[3];
  double Mradial_tmp;
  /* Initialize function 'Calculat_A_and_B_Points' input arguments. */
  /* Initialize function input argument 'MTaon'. */
  argInit_3x1_real_T(MTaon_tmp);
  /* Initialize function input argument 'Mcenter'. */
  Mradial_tmp = argInit_real_T();
  /* Initialize function input argument 'Bottom_round_center1'. */
  /* Initialize function input argument 'Bottom_round_center2'. */
  /* Initialize function input argument 'testP'. */
  /* Call the entry-point 'Calculat_A_and_B_Points'. */
  emxInitArray_real_T(&PointTable_A, 2);
  emxInitArray_real_T(&PointTable_B, 2);
  Calculat_A_and_B_Points(MTaon_tmp, MTaon_tmp, Mradial_tmp, MTaon_tmp,
                          MTaon_tmp, MTaon_tmp, Mradial_tmp, Mradial_tmp,
                          PointTable_A, PointTable_B);
  emxDestroyArray_real_T(PointTable_A);
  emxDestroyArray_real_T(PointTable_B);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculat_A_and_B_Points_after_Offest2(void)
{
  emxArray_real_T *Ang;
  emxArray_real_T *BianHao;
  emxArray_real_T *PointTable_A_off2;
  emxArray_real_T *PointTable_B_off2;
  emxArray_real_T *roff;
  emxArray_real_T *toff;
  double Bottom_round_center1_tmp[3];
  double Mradial_tmp;
  /* Initialize function 'Calculat_A_and_B_Points_after_Offest2' input
   * arguments. */
  /* Initialize function input argument 'Bottom_round_center1'. */
  argInit_3x1_real_T(Bottom_round_center1_tmp);
  /* Initialize function input argument 'Bottom_round_center2'. */
  /* Initialize function input argument 'MTaon'. */
  /* Initialize function input argument 'Mcenter'. */
  Mradial_tmp = argInit_real_T();
  /* Initialize function input argument 'PAB'. */
  /* Initialize function input argument 'Ang'. */
  Ang = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'toff'. */
  toff = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'roff'. */
  roff = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'Calculat_A_and_B_Points_after_Offest2'. */
  emxInitArray_real_T(&PointTable_A_off2, 2);
  emxInitArray_real_T(&PointTable_B_off2, 2);
  emxInitArray_real_T(&BianHao, 2);
  Calculat_A_and_B_Points_after_Offest2(
      Bottom_round_center1_tmp, Bottom_round_center1_tmp,
      Bottom_round_center1_tmp, Bottom_round_center1_tmp, Mradial_tmp,
      Bottom_round_center1_tmp, Mradial_tmp, Ang, toff, roff, PointTable_A_off2,
      PointTable_B_off2, BianHao);
  emxDestroyArray_real_T(roff);
  emxDestroyArray_real_T(toff);
  emxDestroyArray_real_T(Ang);
  emxDestroyArray_real_T(PointTable_A_off2);
  emxDestroyArray_real_T(PointTable_B_off2);
  emxDestroyArray_real_T(BianHao);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculat_JuXing_A_and_B_Points_after_Offest(void)
{
  emxArray_real_T *PointTable_A_off;
  emxArray_real_T *PointTable_B_off;
  emxArray_real_T *Ti;
  emxArray_real_T *toff;
  double Tao_tmp[3];
  double b_tmp;
  /* Initialize function 'Calculat_JuXing_A_and_B_Points_after_Offest' input
   * arguments. */
  /* Initialize function input argument 'Tao'. */
  argInit_3x1_real_T(Tao_tmp);
  /* Initialize function input argument 'UPP'. */
  /* Initialize function input argument 'Pin'. */
  b_tmp = argInit_real_T();
  /* Initialize function input argument 'PAB'. */
  /* Initialize function input argument 'Ti'. */
  Ti = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'toff'. */
  toff = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'Calculat_JuXing_A_and_B_Points_after_Offest'. */
  emxInitArray_real_T(&PointTable_A_off, 2);
  emxInitArray_real_T(&PointTable_B_off, 2);
  Calculat_JuXing_A_and_B_Points_after_Offest(
      Tao_tmp, Tao_tmp, Tao_tmp, b_tmp, b_tmp, Tao_tmp, b_tmp, b_tmp, Ti, toff,
      PointTable_A_off, PointTable_B_off);
  emxDestroyArray_real_T(toff);
  emxDestroyArray_real_T(Ti);
  emxDestroyArray_real_T(PointTable_A_off);
  emxDestroyArray_real_T(PointTable_B_off);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculate_accurate_cylinders_from_multiple_measurement_points2(void)
{
  emxArray_real_T *Err_every;
  emxArray_real_T *points;
  double Bottom_round_center1[3];
  double Bottom_round_center2[3];
  double MTaon[3];
  double Mcenter[3];
  double P_bound1_tmp[3];
  double Mradial;
  /* Initialize function
   * 'Calculate_accurate_cylinders_from_multiple_measurement_points2' input
   * arguments. */
  /* Initialize function input argument 'points'. */
  points = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'P_bound1'. */
  argInit_3x1_real_T(P_bound1_tmp);
  /* Initialize function input argument 'P_bound2'. */
  /* Call the entry-point
   * 'Calculate_accurate_cylinders_from_multiple_measurement_points2'. */
  emxInitArray_real_T(&Err_every, 2);
  Calculate_accurate_cylinders_from_multiple_measurement_points2(
      points, P_bound1_tmp, P_bound1_tmp, Mcenter, MTaon, &Mradial, Err_every,
      Bottom_round_center1, Bottom_round_center2);
  emxDestroyArray_real_T(points);
  emxDestroyArray_real_T(Err_every);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculate_rectangle_from_vertex(void)
{
  emxArray_real_T *TrianglePoints4;
  double PP[24];
  double Pin[3];
  double Pout[3];
  double Tao[3];
  double UPP[3];
  double b;
  double h;
  double w;
  /* Initialize function 'Calculate_rectangle_from_vertex' input arguments. */
  /* Initialize function input argument 'TrianglePoints4'. */
  TrianglePoints4 = argInit_3xUnbounded_real_T();
  /* Call the entry-point 'Calculate_rectangle_from_vertex'. */
  Calculate_rectangle_from_vertex(TrianglePoints4, Pin, Pout, UPP, &b, &h, &w,
                                  Tao, PP);
  emxDestroyArray_real_T(TrianglePoints4);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Calculate_rectangle_from_vertex8(void)
{
  emxArray_real_T *BianHao;
  emxArray_real_T *PointTable_A_off8;
  emxArray_real_T *PointTable_B_off8;
  emxArray_real_T *Ti;
  emxArray_real_T *XieMianPianYi;
  emxArray_real_T *a;
  emxArray_real_T *side_faces_transformed1;
  emxArray_real_T *side_faces_transformed2;
  emxArray_real_T *side_faces_transformed3;
  emxArray_real_T *side_faces_transformed4;
  emxArray_real_T *side_faces_transformed5;
  emxArray_real_T *side_faces_transformed6;
  emxArray_real_T *side_faces_transformed7;
  emxArray_real_T *side_faces_transformed8;
  double P_bound1_tmp[3];
  double b_dv[3];
  double phi_tmp;
  /* Initialize function 'Calculate_rectangle_from_vertex8' input arguments. */
  /* Initialize function input argument 'side_faces_transformed1'. */
  side_faces_transformed1 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed2'. */
  side_faces_transformed2 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed3'. */
  side_faces_transformed3 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed4'. */
  side_faces_transformed4 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed5'. */
  side_faces_transformed5 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed6'. */
  side_faces_transformed6 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed7'. */
  side_faces_transformed7 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'side_faces_transformed8'. */
  side_faces_transformed8 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'P_bound1'. */
  argInit_3x1_real_T(P_bound1_tmp);
  /* Initialize function input argument 'P_bound2'. */
  /* Initialize function input argument 'PAB'. */
  phi_tmp = argInit_real_T();
  /* Initialize function input argument 'Ti'. */
  Ti = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'a'. */
  a = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'Calculate_rectangle_from_vertex8'. */
  emxInitArray_real_T(&PointTable_A_off8, 2);
  emxInitArray_real_T(&PointTable_B_off8, 2);
  emxInitArray_real_T(&XieMianPianYi, 2);
  emxInitArray_real_T(&BianHao, 2);
  argInit_3x1_real_T(b_dv);
  Calculate_rectangle_from_vertex8(
      side_faces_transformed1, side_faces_transformed2, side_faces_transformed3,
      side_faces_transformed4, side_faces_transformed5, side_faces_transformed6,
      side_faces_transformed7, side_faces_transformed8, P_bound1_tmp,
      P_bound1_tmp, b_dv, phi_tmp, phi_tmp, Ti, a, phi_tmp, PointTable_A_off8,
      PointTable_B_off8, XieMianPianYi, BianHao);
  emxDestroyArray_real_T(a);
  emxDestroyArray_real_T(Ti);
  emxDestroyArray_real_T(side_faces_transformed8);
  emxDestroyArray_real_T(side_faces_transformed7);
  emxDestroyArray_real_T(side_faces_transformed6);
  emxDestroyArray_real_T(side_faces_transformed5);
  emxDestroyArray_real_T(side_faces_transformed4);
  emxDestroyArray_real_T(side_faces_transformed3);
  emxDestroyArray_real_T(side_faces_transformed2);
  emxDestroyArray_real_T(side_faces_transformed1);
  emxDestroyArray_real_T(PointTable_A_off8);
  emxDestroyArray_real_T(PointTable_B_off8);
  emxDestroyArray_real_T(XieMianPianYi);
  emxDestroyArray_real_T(BianHao);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_CrossLine(void)
{
  double PlanePara1_tmp[4];
  double P0[3];
  double d[3];
  /* Initialize function 'CrossLine' input arguments. */
  /* Initialize function input argument 'PlanePara1'. */
  argInit_4x1_real_T(PlanePara1_tmp);
  /* Initialize function input argument 'PlanePara2'. */
  /* Call the entry-point 'CrossLine'. */
  CrossLine(PlanePara1_tmp, PlanePara1_tmp, argInit_real_T(), P0, d);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_GenerateTrianglePoints(void)
{
  double PointTri[6];
  double b_dv[4];
  double BoundPoint1_tmp[3];
  double b_dv1[3];
  /* Initialize function 'GenerateTrianglePoints' input arguments. */
  /* Initialize function input argument 'PlaneParaIn'. */
  /* Initialize function input argument 'BoundPoint1'. */
  argInit_3x1_real_T(BoundPoint1_tmp);
  /* Initialize function input argument 'P0'. */
  /* Initialize function input argument 'Direction'. */
  /* Call the entry-point 'GenerateTrianglePoints'. */
  argInit_4x1_real_T(b_dv);
  argInit_3x1_real_T(b_dv1);
  GenerateTrianglePoints(b_dv, BoundPoint1_tmp, BoundPoint1_tmp, b_dv1,
                         PointTri);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Generate_multi_layered_measurement_points(void)
{
  emxArray_real_T *Point_out;
  emxArray_real_T *Point_test;
  double P3_tmp[3];
  double num_tmp;
  /* Initialize function 'Generate_multi_layered_measurement_points' input
   * arguments. */
  /* Initialize function input argument 'Point_out'. */
  Point_out = argInit_3xUnbounded_real_T();
  num_tmp = argInit_real_T();
  /* Initialize function input argument 'P3'. */
  argInit_3x1_real_T(P3_tmp);
  /* Initialize function input argument 'P4'. */
  /* Call the entry-point 'Generate_multi_layered_measurement_points'. */
  emxInitArray_real_T(&Point_test, 2);
  Generate_multi_layered_measurement_points(Point_out, num_tmp, num_tmp, P3_tmp,
                                            P3_tmp, num_tmp, Point_test);
  emxDestroyArray_real_T(Point_out);
  emxDestroyArray_real_T(Point_test);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_JuXingFuCe(void)
{
  emxArray_real_T *Distance;
  emxArray_real_T *LTPY;
  emxArray_real_T *PlaneParaOut4;
  emxArray_real_T *PointIn;
  emxArray_real_T *TiC;
  emxArray_real_T *Wquanzhong3;
  emxArray_real_T *Wquanzhong4;
  emxArray_real_T *theta;
  double b_dv[8];
  double Pin_tmp[3];
  double shenglunum_tmp;
  /* Initialize function 'JuXingFuCe' input arguments. */
  /* Initialize function input argument 'PointIn'. */
  PointIn = argInit_3xUnbounded_real_T();
  shenglunum_tmp = argInit_real_T();
  /* Initialize function input argument 'Pin'. */
  argInit_3x1_real_T(Pin_tmp);
  /* Initialize function input argument 'Tao'. */
  /* Initialize function input argument 'PlaneParaOut4'. */
  PlaneParaOut4 = argInit_4xUnbounded_real_T();
  /* Initialize function input argument 'LenDaoJiao'. */
  /* Call the entry-point 'JuXingFuCe'. */
  emxInitArray_real_T(&Distance, 2);
  emxInitArray_real_T(&theta, 2);
  emxInitArray_real_T(&LTPY, 2);
  emxInitArray_real_T(&TiC, 2);
  emxInitArray_real_T(&Wquanzhong3, 1);
  emxInitArray_real_T(&Wquanzhong4, 1);
  argInit_1x8_real_T(b_dv);
  JuXingFuCe(PointIn, shenglunum_tmp, Pin_tmp, Pin_tmp, shenglunum_tmp,
             PlaneParaOut4, b_dv, Distance, theta, LTPY, TiC, Wquanzhong3,
             Wquanzhong4);
  emxDestroyArray_real_T(PlaneParaOut4);
  emxDestroyArray_real_T(PointIn);
  emxDestroyArray_real_T(Distance);
  emxDestroyArray_real_T(theta);
  emxDestroyArray_real_T(LTPY);
  emxDestroyArray_real_T(TiC);
  emxDestroyArray_real_T(Wquanzhong3);
  emxDestroyArray_real_T(Wquanzhong4);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_OffsetCalculate(void)
{
  emxArray_real_T *Ang;
  emxArray_real_T *OffsetOut;
  emxArray_real_T *a;
  double Mradial_tmp;
  /* Initialize function 'OffsetCalculate' input arguments. */
  Mradial_tmp = argInit_real_T();
  /* Initialize function input argument 'Ang'. */
  Ang = argInit_1xUnbounded_real_T();
  /* Initialize function input argument 'a'. */
  a = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'OffsetCalculate'. */
  emxInitArray_real_T(&OffsetOut, 2);
  OffsetCalculate(Mradial_tmp, Mradial_tmp, Ang, a, OffsetOut);
  emxDestroyArray_real_T(a);
  emxDestroyArray_real_T(Ang);
  emxDestroyArray_real_T(OffsetOut);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_RepeatSurvey(void)
{
  double SoundPoint1_tmp[3];
  double SoundAngle;
  double SoundLength;
  /* Initialize function 'RepeatSurvey' input arguments. */
  /* Initialize function input argument 'SoundPoint1'. */
  argInit_3x1_real_T(SoundPoint1_tmp);
  /* Initialize function input argument 'SoundPoint2'. */
  /* Initialize function input argument 'Bottom_round_center1'. */
  /* Initialize function input argument 'Bottom_round_center2'. */
  /* Call the entry-point 'RepeatSurvey'. */
  RepeatSurvey(SoundPoint1_tmp, SoundPoint1_tmp, SoundPoint1_tmp,
               SoundPoint1_tmp, &SoundAngle, &SoundLength);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ShengDaoGaoDu(void)
{
  emxArray_real_T *Ti;
  /* Initialize function 'ShengDaoGaoDu' input arguments. */
  /* Call the entry-point 'ShengDaoGaoDu'. */
  emxInitArray_real_T(&Ti, 2);
  ShengDaoGaoDu(argInit_real_T(), Ti);
  emxDestroyArray_real_T(Ti);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ShengLuJiaoJiSuan(void)
{
  emxArray_real_T *Ang;
  /* Initialize function 'ShengLuJiaoJiSuan' input arguments. */
  /* Call the entry-point 'ShengLuJiaoJiSuan'. */
  emxInitArray_real_T(&Ang, 2);
  ShengLuJiaoJiSuan(argInit_real_T(), Ang);
  emxDestroyArray_real_T(Ang);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_YuanXingFuCe(void)
{
  emxArray_real_T *Distance;
  emxArray_real_T *LTPY;
  emxArray_real_T *PointIn;
  emxArray_real_T *TiC;
  emxArray_real_T *Wquanzhong1;
  emxArray_real_T *Wquanzhong2;
  emxArray_real_T *theta;
  double Mcenter_tmp[3];
  double shenglunum_tmp;
  /* Initialize function 'YuanXingFuCe' input arguments. */
  /* Initialize function input argument 'PointIn'. */
  PointIn = argInit_3xUnbounded_real_T();
  shenglunum_tmp = argInit_real_T();
  /* Initialize function input argument 'Mcenter'. */
  argInit_3x1_real_T(Mcenter_tmp);
  /* Initialize function input argument 'MTaon'. */
  /* Call the entry-point 'YuanXingFuCe'. */
  emxInitArray_real_T(&Distance, 2);
  emxInitArray_real_T(&theta, 2);
  emxInitArray_real_T(&LTPY, 2);
  emxInitArray_real_T(&TiC, 2);
  emxInitArray_real_T(&Wquanzhong1, 1);
  emxInitArray_real_T(&Wquanzhong2, 1);
  YuanXingFuCe(PointIn, shenglunum_tmp, Mcenter_tmp, Mcenter_tmp,
               shenglunum_tmp, shenglunum_tmp, Distance, theta, LTPY, TiC,
               Wquanzhong1, Wquanzhong2);
  emxDestroyArray_real_T(PointIn);
  emxDestroyArray_real_T(Distance);
  emxDestroyArray_real_T(theta);
  emxDestroyArray_real_T(LTPY);
  emxDestroyArray_real_T(TiC);
  emxDestroyArray_real_T(Wquanzhong1);
  emxDestroyArray_real_T(Wquanzhong2);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_YuanZhuJiaoDian(void)
{
  double Cross_point_data[6];
  double Mcenter_tmp[3];
  int Cross_point_size[2];
  /* Initialize function 'YuanZhuJiaoDian' input arguments. */
  /* Initialize function input argument 'Mcenter'. */
  argInit_3x1_real_T(Mcenter_tmp);
  /* Initialize function input argument 'MTaon'. */
  /* Initialize function input argument 'Pin1'. */
  /* Initialize function input argument 'Pin2'. */
  /* Call the entry-point 'YuanZhuJiaoDian'. */
  YuanZhuJiaoDian(Mcenter_tmp, Mcenter_tmp, argInit_real_T(), Mcenter_tmp,
                  Mcenter_tmp, Cross_point_data, Cross_point_size);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_angle2point(void)
{
  double ANG_tmp;
  double x;
  double y;
  double z;
  /* Initialize function 'angle2point' input arguments. */
  ANG_tmp = argInit_real_T();
  /* Call the entry-point 'angle2point'. */
  angle2point(ANG_tmp, ANG_tmp, ANG_tmp, ANG_tmp, ANG_tmp, ANG_tmp, &x, &y, &z);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_fitcircle(void)
{
  emxArray_real_T *x;
  double z[2];
  double r;
  double residual;
  /* Initialize function 'fitcircle' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_Unboundedx2_real_T();
  /* Call the entry-point 'fitcircle'. */
  fitcircle(x, z, &r, &residual);
  emxDestroyArray_real_T(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_foot_of_perpendicular_from_a_point_to_a_line(void)
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
void main_generate_unit_circle_with_normal_vector(void)
{
  emxArray_real_T *Point_out;
  double azimuth_tmp;
  /* Initialize function 'generate_unit_circle_with_normal_vector' input
   * arguments. */
  azimuth_tmp = argInit_real_T();
  /* Call the entry-point 'generate_unit_circle_with_normal_vector'. */
  emxInitArray_real_T(&Point_out, 2);
  generate_unit_circle_with_normal_vector(azimuth_tmp, azimuth_tmp, azimuth_tmp,
                                          azimuth_tmp, Point_out);
  emxDestroyArray_real_T(Point_out);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_generate_unit_circle_with_normal_vector2(void)
{
  emxArray_real_T *PointIn;
  emxArray_real_T *Point_out;
  double PUp_tmp[3];
  double num_tmp;
  /* Initialize function 'generate_unit_circle_with_normal_vector2' input
   * arguments. */
  /* Initialize function input argument 'PointIn'. */
  PointIn = argInit_3xUnbounded_real_T();
  num_tmp = argInit_real_T();
  /* Initialize function input argument 'PUp'. */
  argInit_3x1_real_T(PUp_tmp);
  /* Initialize function input argument 'PDown'. */
  /* Call the entry-point 'generate_unit_circle_with_normal_vector2'. */
  emxInitArray_real_T(&Point_out, 2);
  generate_unit_circle_with_normal_vector2(PointIn, num_tmp, num_tmp, PUp_tmp,
                                           PUp_tmp, Point_out);
  emxDestroyArray_real_T(PointIn);
  emxDestroyArray_real_T(Point_out);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_myvrrotvec2mat(void)
{
  double m[9];
  double b_dv[4];
  /* Initialize function 'myvrrotvec2mat' input arguments. */
  /* Initialize function input argument 'r'. */
  /* Call the entry-point 'myvrrotvec2mat'. */
  argInit_4x1_real_T(b_dv);
  myvrrotvec2mat(b_dv, m);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_planefit(void)
{
  emxArray_real_T *PlaneParaIn;
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points;
  emxArray_real_T *TrianglePoints;
  double BoundPoint1_tmp[3];
  /* Initialize function 'planefit' input arguments. */
  /* Initialize function input argument 'Points'. */
  Points = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'PlaneParaIn'. */
  PlaneParaIn = argInit_4xUnbounded_real_T();
  /* Initialize function input argument 'BoundPoint1'. */
  argInit_3x1_real_T(BoundPoint1_tmp);
  /* Initialize function input argument 'BoundPoint2'. */
  /* Call the entry-point 'planefit'. */
  emxInitArray_real_T(&PlaneParaOut, 2);
  emxInitArray_real_T(&TrianglePoints, 2);
  planefit(Points, PlaneParaIn, BoundPoint1_tmp, BoundPoint1_tmp, PlaneParaOut,
           TrianglePoints);
  emxDestroyArray_real_T(PlaneParaIn);
  emxDestroyArray_real_T(Points);
  emxDestroyArray_real_T(PlaneParaOut);
  emxDestroyArray_real_T(TrianglePoints);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_planefit4(void)
{
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points1;
  emxArray_real_T *Points2;
  emxArray_real_T *Points3;
  emxArray_real_T *Points4;
  emxArray_real_T *TrianglePoints;
  emxArray_real_T *distancesFianal;
  double MaxDis[4];
  double BoundPoint1_tmp[3];
  /* Initialize function 'planefit4' input arguments. */
  /* Initialize function input argument 'Points1'. */
  Points1 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points2'. */
  Points2 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points3'. */
  Points3 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points4'. */
  Points4 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'BoundPoint1'. */
  argInit_3x1_real_T(BoundPoint1_tmp);
  /* Initialize function input argument 'BoundPoint2'. */
  /* Call the entry-point 'planefit4'. */
  emxInitArray_real_T(&PlaneParaOut, 2);
  emxInitArray_real_T(&TrianglePoints, 2);
  emxInitArray_real_T(&distancesFianal, 2);
  planefit4(Points1, Points2, Points3, Points4, BoundPoint1_tmp,
            BoundPoint1_tmp, argInit_real_T(), PlaneParaOut, TrianglePoints,
            MaxDis, distancesFianal);
  emxDestroyArray_real_T(Points4);
  emxDestroyArray_real_T(Points3);
  emxDestroyArray_real_T(Points2);
  emxDestroyArray_real_T(Points1);
  emxDestroyArray_real_T(PlaneParaOut);
  emxDestroyArray_real_T(TrianglePoints);
  emxDestroyArray_real_T(distancesFianal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_planefit8(void)
{
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points1;
  emxArray_real_T *Points2;
  emxArray_real_T *Points3;
  emxArray_real_T *Points4;
  emxArray_real_T *Points5;
  emxArray_real_T *Points6;
  emxArray_real_T *Points7;
  emxArray_real_T *Points8;
  emxArray_real_T *TrianglePoints;
  emxArray_real_T *tt1;
  emxArray_real_T *tt2;
  emxArray_real_T *tt3;
  emxArray_real_T *tt4;
  emxArray_real_T *tt5;
  emxArray_real_T *tt6;
  emxArray_real_T *tt7;
  emxArray_real_T *tt8;
  double LenDaoJiao[8];
  double MaxDis[8];
  double P_bound1_tmp[3];
  /* Initialize function 'planefit8' input arguments. */
  /* Initialize function input argument 'Points1'. */
  Points1 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points2'. */
  Points2 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points3'. */
  Points3 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points4'. */
  Points4 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points5'. */
  Points5 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points6'. */
  Points6 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points7'. */
  Points7 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'Points8'. */
  Points8 = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'P_bound1'. */
  argInit_3x1_real_T(P_bound1_tmp);
  /* Initialize function input argument 'P_bound2'. */
  /* Call the entry-point 'planefit8'. */
  emxInitArray_real_T(&PlaneParaOut, 2);
  emxInitArray_real_T(&TrianglePoints, 2);
  emxInitArray_real_T(&tt1, 2);
  emxInitArray_real_T(&tt2, 2);
  emxInitArray_real_T(&tt3, 2);
  emxInitArray_real_T(&tt4, 2);
  emxInitArray_real_T(&tt5, 2);
  emxInitArray_real_T(&tt6, 2);
  emxInitArray_real_T(&tt7, 2);
  emxInitArray_real_T(&tt8, 2);
  planefit8(Points1, Points2, Points3, Points4, Points5, Points6, Points7,
            Points8, P_bound1_tmp, P_bound1_tmp, argInit_real_T(), PlaneParaOut,
            TrianglePoints, MaxDis, tt1, tt2, tt3, tt4, tt5, tt6, tt7, tt8,
            LenDaoJiao);
  emxDestroyArray_real_T(Points8);
  emxDestroyArray_real_T(Points7);
  emxDestroyArray_real_T(Points6);
  emxDestroyArray_real_T(Points5);
  emxDestroyArray_real_T(Points4);
  emxDestroyArray_real_T(Points3);
  emxDestroyArray_real_T(Points2);
  emxDestroyArray_real_T(Points1);
  emxDestroyArray_real_T(PlaneParaOut);
  emxDestroyArray_real_T(TrianglePoints);
  emxDestroyArray_real_T(tt1);
  emxDestroyArray_real_T(tt2);
  emxDestroyArray_real_T(tt3);
  emxDestroyArray_real_T(tt4);
  emxDestroyArray_real_T(tt5);
  emxDestroyArray_real_T(tt6);
  emxDestroyArray_real_T(tt7);
  emxDestroyArray_real_T(tt8);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
