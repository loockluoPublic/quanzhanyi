/*
 * File: ShengLuJiaoJiSuan.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jan-2025 23:31:20
 */

/* Include Files */
#include "ShengLuJiaoJiSuan.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double numShengLu
 *                emxArray_real_T *Ang
 * Return Type  : void
 */
void ShengLuJiaoJiSuan(double numShengLu, emxArray_real_T *Ang)
{
  static const double dv7[20] = {
      2.8559933214452666,  2.5703939893007397,  2.2847946571562132,
      1.9991953250116865,  1.7135959928671598,  1.4279966607226333,
      1.1423973285781066,  0.8567979964335799,  0.5711986642890533,
      0.28559933214452665, 0.28559933214452665, 0.5711986642890533,
      0.8567979964335799,  1.1423973285781066,  1.4279966607226333,
      1.7135959928671598,  1.9991953250116865,  2.2847946571562132,
      2.5703939893007397,  2.8559933214452666};
  static const double dv6[18] = {
      2.8274333882308138,  2.5132741228718345,  2.1991148575128552,
      1.8849555921538759,  1.5707963267948966,  1.2566370614359172,
      0.94247779607693793, 0.62831853071795862, 0.31415926535897931,
      0.31415926535897931, 0.62831853071795862, 0.94247779607693793,
      1.2566370614359172,  1.5707963267948966,  1.8849555921538759,
      2.1991148575128552,  2.5132741228718345,  2.8274333882308138};
  static const double dv5[16] = {
      2.7925268031909272,  2.4434609527920612, 2.0943951023931953,
      1.7453292519943295,  1.3962634015954636, 1.0471975511965976,
      0.69813170079773179, 0.3490658503988659, 0.3490658503988659,
      0.69813170079773179, 1.0471975511965976, 1.3962634015954636,
      1.7453292519943295,  2.0943951023931953, 2.4434609527920612,
      2.7925268031909272};
  static const double dv4[14] = {
      2.748893571891069,   2.3561944901923448,  1.9634954084936207,
      1.5707963267948966,  1.1780972450961724,  0.78539816339744828,
      0.39269908169872414, 0.39269908169872414, 0.78539816339744828,
      1.1780972450961724,  1.5707963267948966,  1.9634954084936207,
      2.3561944901923448,  2.748893571891069};
  static const double dv3[12] = {
      2.6927937030769655,  2.2439947525641379,  1.7951958020513104,
      1.3463968515384828,  0.89759790102565518, 0.44879895051282759,
      0.44879895051282759, 0.89759790102565518, 1.3463968515384828,
      1.7951958020513104,  2.2439947525641379,  2.6927937030769655};
  static const double dv2[10] = {2.617993877991494,   2.0943951023931953,
                                 1.5707963267948966,  1.0471975511965979,
                                 0.52359877559829893, 0.52359877559829893,
                                 1.0471975511965979,  1.5707963267948966,
                                 2.0943951023931953,  2.617993877991494};
  static const double b_dv1[8] = {2.5132741228718345,  1.8849555921538759,
                                  1.2566370614359172,  0.62831853071795862,
                                  0.62831853071795862, 1.2566370614359172,
                                  1.8849555921538759,  2.5132741228718345};
  static const double b_dv[6] = {2.3561944901923448,  1.5707963267948966,
                                 0.78539816339744828, 0.78539816339744828,
                                 1.5707963267948966,  2.3561944901923448};
  double *Ang_data;
  int i;
  int loop_ub;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  i = Ang->size[0] * Ang->size[1];
  Ang->size[0] = 1;
  loop_ub = (int)(numShengLu * 2.0);
  Ang->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Ang, i);
  Ang_data = Ang->data;
  for (i = 0; i < loop_ub; i++) {
    Ang_data[i] = 0.0;
  }
  switch ((int)numShengLu) {
  case 1:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 2;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    Ang_data[0] = 1.5707963267948966;
    Ang_data[1] = 1.5707963267948966;
    break;
  case 2:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 4;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    Ang_data[0] = 2.0943951023931953;
    Ang_data[1] = 1.0471975511965979;
    Ang_data[2] = 1.0471975511965979;
    Ang_data[3] = 2.0943951023931953;
    break;
  case 3:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 6;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 6; i++) {
      Ang_data[i] = b_dv[i];
    }
    break;
  case 4:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 8;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 8; i++) {
      Ang_data[i] = b_dv1[i];
    }
    break;
  case 5:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 10;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 10; i++) {
      Ang_data[i] = dv2[i];
    }
    break;
  case 6:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 12;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 12; i++) {
      Ang_data[i] = dv3[i];
    }
    break;
  case 7:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 14;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 14; i++) {
      Ang_data[i] = dv4[i];
    }
    break;
  case 8:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 16;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 16; i++) {
      Ang_data[i] = dv5[i];
    }
    break;
  case 9:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 18;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 18; i++) {
      Ang_data[i] = dv6[i];
    }
    break;
  case 10:
    i = Ang->size[0] * Ang->size[1];
    Ang->size[0] = 1;
    Ang->size[1] = 20;
    emxEnsureCapacity_real_T(Ang, i);
    Ang_data = Ang->data;
    for (i = 0; i < 20; i++) {
      Ang_data[i] = dv7[i];
    }
    break;
  }
  i = Ang->size[0] * Ang->size[1];
  Ang->size[0] = 1;
  emxEnsureCapacity_real_T(Ang, i);
  Ang_data = Ang->data;
  loop_ub = Ang->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    Ang_data[i] -= 1.5707963267948966;
  }
}

/*
 * File trailer for ShengLuJiaoJiSuan.c
 *
 * [EOF]
 */
