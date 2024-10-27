/*
 * File: xzlascl.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 18:52:15
 */

/* Include Files */
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                double A_data[]
 *                int iA0
 * Return Type  : void
 */
void xzlascl(double cfrom, double cto, int m, double A_data[], int iA0)
{
  double cfrom1;
  double cfromc;
  double cto1;
  double ctoc;
  double mul;
  int b_i;
  int i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (i = 0; i < m; i++) {
      b_i = (iA0 + i) - 1;
      A_data[b_i] *= mul;
    }
  }
}

/*
 * File trailer for xzlascl.c
 *
 * [EOF]
 */
