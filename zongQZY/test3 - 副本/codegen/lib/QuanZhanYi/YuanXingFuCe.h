/*
 * File: YuanXingFuCe.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 29-Sep-2024 01:27:40
 */

#ifndef YUANXINGFUCE_H
#define YUANXINGFUCE_H

/* Include Files */
#include "QuanZhanYi_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void YuanXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                         const double Mcenter[3], const double MTaon[3],
                         double Mradial, double phi, emxArray_real_T *Distance,
                         emxArray_real_T *theta, emxArray_real_T *LTPY,
                         emxArray_real_T *TiC, emxArray_real_T *Wquanzhong1,
                         emxArray_real_T *Wquanzhong2);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for YuanXingFuCe.h
 *
 * [EOF]
 */
