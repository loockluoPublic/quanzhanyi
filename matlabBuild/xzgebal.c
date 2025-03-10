/*
 * File: xzgebal.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 10-Mar-2025 20:27:52
 */

/* Include Files */
#include "xzgebal.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double A_data[]
 *                int A_size[2]
 *                int *ihi
 *                double scale_data[]
 *                int *scale_size
 * Return Type  : int
 */
int xzgebal(double A_data[], int A_size[2], int *ihi, double scale_data[],
            int *scale_size)
{
  emxArray_real_T *x;
  double absxk;
  double c;
  double f;
  double r;
  double s;
  double scale;
  double t;
  double u0;
  double u1;
  double *x_data;
  int b_i;
  int b_k;
  int exitg1;
  int exitg2;
  int exitg4;
  int exitg5;
  int i;
  int i1;
  int ilo;
  int ix;
  int iy;
  int j;
  int k;
  int kend;
  int loop_ub;
  int n;
  boolean_T converged;
  boolean_T exitg3;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T notdone;
  n = A_size[0];
  *scale_size = A_size[0];
  loop_ub = A_size[0];
  for (i = 0; i < loop_ub; i++) {
    scale_data[i] = 1.0;
  }
  k = 0;
  *ihi = A_size[0];
  notdone = true;
  emxInit_real_T(&x, 2);
  do {
    exitg5 = 0;
    if (notdone) {
      notdone = false;
      j = *ihi;
      do {
        exitg4 = 0;
        if (j > 0) {
          converged = false;
          b_i = 0;
          exitg6 = false;
          while ((!exitg6) && (b_i <= *ihi - 1)) {
            if ((b_i + 1 == j) ||
                (!(A_data[(j + A_size[0] * b_i) - 1] != 0.0))) {
              b_i++;
            } else {
              converged = true;
              exitg6 = true;
            }
          }
          if (converged) {
            j--;
          } else {
            scale_data[*ihi - 1] = j;
            if (j != *ihi) {
              ix = (j - 1) * n;
              iy = (*ihi - 1) * n;
              i = x->size[0] * x->size[1];
              x->size[0] = A_size[0];
              x->size[1] = A_size[1];
              emxEnsureCapacity_real_T(x, i);
              x_data = x->data;
              kend = A_size[0] * A_size[1];
              for (i = 0; i < kend; i++) {
                x_data[i] = A_data[i];
              }
              for (b_k = 0; b_k < *ihi; b_k++) {
                kend = ix + b_k;
                scale = x_data[kend];
                i = iy + b_k;
                x_data[kend] = x_data[i];
                x_data[i] = scale;
              }
              A_size[0] = x->size[0];
              A_size[1] = x->size[1];
              loop_ub = x->size[1];
              for (i = 0; i < loop_ub; i++) {
                kend = x->size[0];
                for (i1 = 0; i1 < kend; i1++) {
                  A_data[i1 + A_size[0] * i] = x_data[i1 + x->size[0] * i];
                }
              }
              for (b_k = 0; b_k < n; b_k++) {
                kend = b_k * n;
                loop_ub = (j + kend) - 1;
                scale = A_data[loop_ub];
                i = (*ihi + kend) - 1;
                A_data[loop_ub] = A_data[i];
                A_data[i] = scale;
              }
            }
            exitg4 = 1;
          }
        } else {
          exitg4 = 2;
        }
      } while (exitg4 == 0);
      if (exitg4 == 1) {
        if (*ihi == 1) {
          ilo = 1;
          *ihi = 1;
          exitg5 = 1;
        } else {
          *ihi = 1;
          notdone = true;
        }
      }
    } else {
      notdone = true;
      while (notdone) {
        notdone = false;
        j = k;
        exitg6 = false;
        while ((!exitg6) && (j + 1 <= *ihi)) {
          converged = false;
          b_i = k;
          exitg7 = false;
          while ((!exitg7) && (b_i + 1 <= *ihi)) {
            if ((b_i + 1 == j + 1) || (!(A_data[b_i + A_size[0] * j] != 0.0))) {
              b_i++;
            } else {
              converged = true;
              exitg7 = true;
            }
          }
          if (converged) {
            j++;
          } else {
            scale_data[k] = j + 1;
            if (j + 1 != k + 1) {
              ix = j * n;
              iy = k * n;
              i = x->size[0] * x->size[1];
              x->size[0] = A_size[0];
              x->size[1] = A_size[1];
              emxEnsureCapacity_real_T(x, i);
              x_data = x->data;
              kend = A_size[0] * A_size[1];
              for (i = 0; i < kend; i++) {
                x_data[i] = A_data[i];
              }
              for (b_k = 0; b_k < *ihi; b_k++) {
                kend = ix + b_k;
                scale = x_data[kend];
                i = iy + b_k;
                x_data[kend] = x_data[i];
                x_data[i] = scale;
              }
              A_size[0] = x->size[0];
              A_size[1] = x->size[1];
              loop_ub = x->size[1];
              for (i = 0; i < loop_ub; i++) {
                kend = x->size[0];
                for (i1 = 0; i1 < kend; i1++) {
                  A_data[i1 + A_size[0] * i] = x_data[i1 + x->size[0] * i];
                }
              }
              ix = iy + j;
              iy += k;
              i = (unsigned char)(n - k);
              for (b_k = 0; b_k < i; b_k++) {
                kend = b_k * n;
                loop_ub = ix + kend;
                scale = A_data[loop_ub];
                i1 = iy + kend;
                A_data[loop_ub] = A_data[i1];
                A_data[i1] = scale;
              }
            }
            k++;
            notdone = true;
            exitg6 = true;
          }
        }
      }
      ilo = k + 1;
      converged = false;
      exitg5 = 2;
    }
  } while (exitg5 == 0);
  if (exitg5 != 1) {
    exitg3 = false;
    while ((!exitg3) && (!converged)) {
      converged = true;
      b_i = k;
      do {
        exitg2 = 0;
        if (b_i + 1 <= *ihi) {
          kend = *ihi - k;
          ix = b_i * n;
          c = e_xnrm2(kend, A_data, (ix + k) + 1);
          iy = k * n + b_i;
          r = 0.0;
          if (kend >= 1) {
            if (kend == 1) {
              r = fabs(A_data[iy]);
            } else {
              scale = 3.3121686421112381E-170;
              kend = (iy + n) + 1;
              for (b_k = iy + 1; n < 0 ? b_k >= kend : b_k <= kend; b_k += n) {
                absxk = fabs(A_data[b_k - 1]);
                if (absxk > scale) {
                  t = scale / absxk;
                  r = r * t * t + 1.0;
                  scale = absxk;
                } else {
                  t = absxk / scale;
                  r += t * t;
                }
              }
              r = scale * sqrt(r);
            }
          }
          kend = 0;
          if ((*ihi > 1) && (fabs(A_data[ix + 1]) > fabs(A_data[ix]))) {
            kend = 1;
          }
          scale = fabs(A_data[kend + A_size[0] * b_i]);
          loop_ub = n - k;
          if (loop_ub < 1) {
            kend = -1;
          } else {
            kend = 0;
            if ((loop_ub > 1) && (fabs(A_data[iy + n]) > fabs(A_data[iy]))) {
              kend = 1;
            }
          }
          absxk = fabs(A_data[b_i + A_size[0] * (kend + k)]);
          if ((c == 0.0) || (r == 0.0)) {
            b_i++;
          } else {
            t = r / 2.0;
            f = 1.0;
            s = c + r;
            do {
              exitg1 = 0;
              if (c < t) {
                if ((c >= scale) || rtIsNaN(scale)) {
                  u1 = c;
                } else {
                  u1 = scale;
                }
                if (f >= u1) {
                  u1 = f;
                }
                if (u1 < 4.9896007738368E+291) {
                  if ((t <= absxk) || rtIsNaN(absxk)) {
                    u1 = t;
                  } else {
                    u1 = absxk;
                  }
                  if (r <= u1) {
                    u1 = r;
                  }
                  if (u1 > 2.0041683600089728E-292) {
                    if (rtIsNaN(((((c + f) + scale) + r) + t) + absxk)) {
                      exitg1 = 1;
                    } else {
                      f *= 2.0;
                      c *= 2.0;
                      scale *= 2.0;
                      r /= 2.0;
                      t /= 2.0;
                      absxk /= 2.0;
                    }
                  } else {
                    exitg1 = 2;
                  }
                } else {
                  exitg1 = 2;
                }
              } else {
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = 2;
            } else {
              t = c / 2.0;
              exitg6 = false;
              while ((!exitg6) && (t >= r)) {
                if ((r >= absxk) || rtIsNaN(absxk)) {
                  u1 = r;
                } else {
                  u1 = absxk;
                }
                if (u1 < 4.9896007738368E+291) {
                  if ((f <= c) || rtIsNaN(c)) {
                    u0 = f;
                  } else {
                    u0 = c;
                  }
                  if ((t <= scale) || rtIsNaN(scale)) {
                    u1 = t;
                  } else {
                    u1 = scale;
                  }
                  if (u0 <= u1) {
                    u1 = u0;
                  }
                  if (u1 > 2.0041683600089728E-292) {
                    f /= 2.0;
                    c /= 2.0;
                    t /= 2.0;
                    scale /= 2.0;
                    r *= 2.0;
                    absxk *= 2.0;
                  } else {
                    exitg6 = true;
                  }
                } else {
                  exitg6 = true;
                }
              }
              if ((!(c + r >= 0.95 * s)) &&
                  ((!(f < 1.0)) || (!(scale_data[b_i] < 1.0)) ||
                   (!(f * scale_data[b_i] <= 1.0020841800044864E-292))) &&
                  ((!(f > 1.0)) || (!(scale_data[b_i] > 1.0)) ||
                   (!(scale_data[b_i] >= 9.9792015476736E+291 / f)))) {
                scale = 1.0 / f;
                scale_data[b_i] *= f;
                kend = iy + 1;
                i = (iy + n * (loop_ub - 1)) + 1;
                for (b_k = kend; n < 0 ? b_k >= i : b_k <= i; b_k += n) {
                  A_data[b_k - 1] *= scale;
                }
                i = x->size[0] * x->size[1];
                x->size[0] = A_size[0];
                x->size[1] = A_size[1];
                emxEnsureCapacity_real_T(x, i);
                x_data = x->data;
                loop_ub = A_size[0] * A_size[1];
                for (i = 0; i < loop_ub; i++) {
                  x_data[i] = A_data[i];
                }
                i = ix + *ihi;
                for (b_k = ix + 1; b_k <= i; b_k++) {
                  x_data[b_k - 1] *= f;
                }
                A_size[0] = x->size[0];
                A_size[1] = x->size[1];
                loop_ub = x->size[1];
                for (i = 0; i < loop_ub; i++) {
                  kend = x->size[0];
                  for (i1 = 0; i1 < kend; i1++) {
                    A_data[i1 + A_size[0] * i] = x_data[i1 + x->size[0] * i];
                  }
                }
                converged = false;
              }
              b_i++;
            }
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (exitg2 != 1) {
        exitg3 = true;
      }
    }
  }
  emxFree_real_T(&x);
  return ilo;
}

/*
 * File trailer for xzgebal.c
 *
 * [EOF]
 */
