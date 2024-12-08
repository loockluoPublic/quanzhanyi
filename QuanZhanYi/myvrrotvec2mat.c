/*
 * File: myvrrotvec2mat.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 08-Dec-2024 18:46:28
 */

/* Include Files */
#include "myvrrotvec2mat.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double r[4]
 *                double m[9]
 * Return Type  : void
 */
void myvrrotvec2mat(const double r[4], double m[9])
{
  double absxk;
  double c;
  double m_tmp;
  double n_idx_0;
  double n_idx_1;
  double norm_vec;
  double s;
  double scale;
  double t;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  s = sin(r[3]);
  c = cos(r[3]);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  absxk = fabs(r[0]);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  absxk = fabs(r[1]);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  absxk = fabs(r[2]);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    n_idx_0 = 0.0;
    n_idx_1 = 0.0;
    scale = 0.0;
  } else {
    n_idx_0 = r[0] / norm_vec;
    n_idx_1 = r[1] / norm_vec;
    scale = r[2] / norm_vec;
  }
  absxk = (1.0 - c) * n_idx_0;
  m[0] = absxk * n_idx_0 + c;
  t = absxk * n_idx_1;
  norm_vec = s * scale;
  m[3] = t - norm_vec;
  absxk *= scale;
  m_tmp = s * n_idx_1;
  m[6] = absxk + m_tmp;
  m[1] = t + norm_vec;
  t = (1.0 - c) * n_idx_1;
  m[4] = t * n_idx_1 + c;
  t *= scale;
  norm_vec = s * n_idx_0;
  m[7] = t - norm_vec;
  m[2] = absxk - m_tmp;
  m[5] = t + norm_vec;
  m[8] = (1.0 - c) * scale * scale + c;
}

/*
 * File trailer for myvrrotvec2mat.c
 *
 * [EOF]
 */
