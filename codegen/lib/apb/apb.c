/*
 * File: apb.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Feb-2024 22:51:50
 */

/* Include Files */
#include "apb.h"
#include <emscripten.h>

// 定义两数相加的函数

/* Function Definitions */
/*
 * Arguments    : double u
 *                double v
 * Return Type  : double
 */
EMSCRIPTEN_KEEPALIVE
double apb(double u, double v)
{
  return u + v;
}

/*
 * File trailer for apb.c
 *
 * [EOF]
 */
