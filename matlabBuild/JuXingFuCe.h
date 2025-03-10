/*
 * File: JuXingFuCe.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 20:27:52
 */

#ifndef JUXINGFUCE_H
#define JUXINGFUCE_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void JuXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                       const double Pin[3], const double Tao[3], double h,
                       const emxArray_real_T *PlaneParaOut4,
                       const double LenDaoJiao[8], emxArray_real_T *Distance,
                       emxArray_real_T *theta, emxArray_real_T *LTPY,
                       emxArray_real_T *TiC, emxArray_real_T *Wquanzhong3,
                       emxArray_real_T *Wquanzhong4);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for JuXingFuCe.h
 *
 * [EOF]
 */
