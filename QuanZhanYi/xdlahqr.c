/*
 * File: xdlahqr.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 11:38:12
 */

/* Include Files */
#include "xdlahqr.h"
#include "QuanZhanYi_rtwutil.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : int ilo
 *                int ihi
 *                double h_data[]
 *                const int h_size[2]
 *                double wr_data[]
 *                int *wr_size
 *                double wi_data[]
 *                int *wi_size
 * Return Type  : int
 */
int xdlahqr(int ilo, int ihi, double h_data[], const int h_size[2],
            double wr_data[], int *wr_size, double wi_data[], int *wi_size)
{
  double aa;
  double b_x;
  double bb;
  double bcmax;
  double bcmis;
  double d;
  double d1;
  double s;
  double scale;
  double smlnum;
  double u0;
  double x;
  int b_i;
  int count;
  int i;
  int i1;
  int info;
  int k;
  int x_tmp;
  boolean_T aa_tmp;
  boolean_T exitg1;
  *wr_size = h_size[0];
  *wi_size = h_size[0];
  info = 0;
  i = (unsigned char)(ilo - 1);
  for (b_i = 0; b_i < i; b_i++) {
    wr_data[b_i] = h_data[b_i + h_size[0] * b_i];
    wi_data[b_i] = 0.0;
  }
  if (ihi + 1 <= h_size[0]) {
    wr_data[1] = h_data[h_size[0] + 1];
    wi_data[1] = 0.0;
  }
  if (ilo == ihi) {
    wr_data[ilo - 1] = h_data[(ilo + h_size[0] * (ilo - 1)) - 1];
    wi_data[ilo - 1] = 0.0;
  } else {
    smlnum = 2.2250738585072014E-308 *
             ((double)((ihi - ilo) + 1) / 2.2204460492503131E-16);
    for (b_i = ihi - 1; b_i + 1 >= ilo; b_i = k - 2) {
      k = b_i + 1;
      exitg1 = false;
      while ((!exitg1) && (k > ilo)) {
        u0 = fabs(h_data[1]);
        if (u0 <= smlnum) {
          exitg1 = true;
        } else {
          s = fabs(h_data[h_size[0] + 1]);
          if (u0 <= 2.2204460492503131E-16 * (fabs(h_data[0]) + s)) {
            bcmis = fabs(h_data[h_size[0]]);
            scale = fabs(h_data[0] - h_data[h_size[0] + 1]);
            aa_tmp = rtIsNaN(scale);
            if ((s >= scale) || aa_tmp) {
              aa = s;
            } else {
              aa = scale;
            }
            if ((s <= scale) || aa_tmp) {
              bb = s;
            } else {
              bb = scale;
            }
            s = aa + bb;
            scale = 2.2204460492503131E-16 * (bb * (aa / s));
            aa_tmp = rtIsNaN(bcmis);
            if ((u0 <= bcmis) || aa_tmp) {
              d = u0;
            } else {
              d = bcmis;
            }
            if ((u0 >= bcmis) || aa_tmp) {
              bcmis = u0;
            }
            if ((smlnum >= scale) || rtIsNaN(scale)) {
              scale = smlnum;
            }
            if (d * (bcmis / s) <= scale) {
              exitg1 = true;
            } else {
              k = 1;
            }
          } else {
            k = 1;
          }
        }
      }
      if (k > ilo) {
        h_data[1] = 0.0;
      }
      if (k == b_i + 1) {
        wr_data[b_i] = h_data[b_i + h_size[0] * b_i];
        wi_data[b_i] = 0.0;
      } else if (k == b_i) {
        d = h_data[0];
        x_tmp = h_size[0] * b_i;
        x = h_data[x_tmp];
        b_x = h_data[b_i];
        i = b_i + h_size[0] * b_i;
        d1 = h_data[i];
        if (!(b_x == 0.0)) {
          if (x == 0.0) {
            aa = d1;
            d1 = d;
            d = aa;
            x = -b_x;
            b_x = 0.0;
          } else {
            aa = d - d1;
            if ((!(aa == 0.0)) || ((x < 0.0) == (b_x < 0.0))) {
              bb = 0.5 * aa;
              s = fabs(x);
              bcmis = fabs(b_x);
              aa_tmp = rtIsNaN(bcmis);
              if ((s >= bcmis) || aa_tmp) {
                bcmax = s;
              } else {
                bcmax = bcmis;
              }
              if ((s <= bcmis) || aa_tmp) {
                bcmis = s;
              }
              if (!(x < 0.0)) {
                count = 1;
              } else {
                count = -1;
              }
              if (!(b_x < 0.0)) {
                i1 = 1;
              } else {
                i1 = -1;
              }
              bcmis = bcmis * (double)count * (double)i1;
              u0 = fabs(bb);
              if ((u0 >= bcmax) || rtIsNaN(bcmax)) {
                scale = u0;
              } else {
                scale = bcmax;
              }
              s = bb / scale * bb + bcmax / scale * bcmis;
              if (s >= 8.8817841970012523E-16) {
                s = sqrt(scale) * sqrt(s);
                if (bb < 0.0) {
                  s = -s;
                }
                s += bb;
                d = d1 + s;
                d1 -= bcmax / s * bcmis;
                x -= b_x;
                b_x = 0.0;
              } else {
                s = x + b_x;
                u0 = fabs(aa);
                scale = fabs(s);
                if ((u0 >= scale) || rtIsNaN(scale)) {
                  scale = u0;
                }
                count = 0;
                while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
                  s *= 1.3435752215134178E-138;
                  aa *= 1.3435752215134178E-138;
                  u0 = fabs(aa);
                  scale = fabs(s);
                  if ((u0 >= scale) || rtIsNaN(scale)) {
                    scale = u0;
                  }
                  count++;
                }
                while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
                  s *= 7.4428285367870146E+137;
                  aa *= 7.4428285367870146E+137;
                  u0 = fabs(aa);
                  scale = fabs(s);
                  if ((u0 >= scale) || rtIsNaN(scale)) {
                    scale = u0;
                  }
                  count++;
                }
                scale = rt_hypotd_snf(s, aa);
                bcmax = sqrt(0.5 * (fabs(s) / scale + 1.0));
                if (!(s < 0.0)) {
                  count = 1;
                } else {
                  count = -1;
                }
                scale = -(0.5 * aa / (scale * bcmax)) * (double)count;
                aa = d * bcmax + x * scale;
                bb = -d * scale + x * bcmax;
                bcmis = b_x * bcmax + d1 * scale;
                s = -b_x * scale + d1 * bcmax;
                x = bb * bcmax + s * scale;
                b_x = -aa * scale + bcmis * bcmax;
                aa = 0.5 *
                     ((aa * bcmax + bcmis * scale) + (-bb * scale + s * bcmax));
                d = aa;
                d1 = aa;
                if (b_x != 0.0) {
                  if (x != 0.0) {
                    if ((x < 0.0) == (b_x < 0.0)) {
                      s = sqrt(fabs(x)) * sqrt(fabs(b_x));
                      if (!(b_x < 0.0)) {
                        bb = s;
                      } else {
                        bb = -s;
                      }
                      d = aa + bb;
                      d1 = aa - bb;
                      x -= b_x;
                      b_x = 0.0;
                    }
                  } else {
                    x = -b_x;
                    b_x = 0.0;
                  }
                }
              }
            }
          }
        }
        wr_data[0] = d;
        wr_data[b_i] = d1;
        if (b_x == 0.0) {
          scale = 0.0;
          s = 0.0;
        } else {
          scale = sqrt(fabs(x)) * sqrt(fabs(b_x));
          s = -scale;
        }
        wi_data[0] = scale;
        wi_data[b_i] = s;
        h_data[0] = d;
        h_data[x_tmp] = x;
        h_data[b_i] = b_x;
        h_data[i] = d1;
      }
    }
  }
  return info;
}

/*
 * File trailer for xdlahqr.c
 *
 * [EOF]
 */
