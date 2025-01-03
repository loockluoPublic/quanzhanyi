/*
 * File: RepeatSurvey.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 29-Sep-2024 01:27:40
 */

/* Include Files */
#include "RepeatSurvey.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double SoundPoint1[3]
 *                const double SoundPoint2[3]
 *                const double Bottom_round_center1[3]
 *                const double Bottom_round_center2[3]
 *                double *SoundAngle
 *                double *SoundLength
 * Return Type  : void
 */
void RepeatSurvey(const double SoundPoint1[3], const double SoundPoint2[3],
                  const double Bottom_round_center1[3],
                  const double Bottom_round_center2[3], double *SoundAngle,
                  double *SoundLength)
{
  double absxk;
  double b_scale;
  double c;
  double d;
  double d1;
  double scale;
  double t;
  double y;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  scale = 3.3121686421112381E-170;
  b_scale = 3.3121686421112381E-170;
  d = Bottom_round_center2[0] - Bottom_round_center1[0];
  d1 = SoundPoint2[0] - SoundPoint1[0];
  absxk = fabs(d1);
  if (absxk > 3.3121686421112381E-170) {
    *SoundLength = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    *SoundLength = t * t;
  }
  c = d * d1;
  absxk = fabs(d);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  d = Bottom_round_center2[1] - Bottom_round_center1[1];
  d1 = SoundPoint2[1] - SoundPoint1[1];
  absxk = fabs(d1);
  if (absxk > scale) {
    t = scale / absxk;
    *SoundLength = *SoundLength * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    *SoundLength += t * t;
  }
  c += d * d1;
  absxk = fabs(d);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  d = Bottom_round_center2[2] - Bottom_round_center1[2];
  d1 = SoundPoint2[2] - SoundPoint1[2];
  absxk = fabs(d1);
  if (absxk > scale) {
    t = scale / absxk;
    *SoundLength = *SoundLength * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    *SoundLength += t * t;
  }
  c += d * d1;
  absxk = fabs(d);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    y = y * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    y += t * t;
  }
  *SoundLength = scale * sqrt(*SoundLength);
  y = b_scale * sqrt(y);
  *SoundAngle = acos(c / *SoundLength / y);
}

/*
 * File trailer for RepeatSurvey.c
 *
 * [EOF]
 */
