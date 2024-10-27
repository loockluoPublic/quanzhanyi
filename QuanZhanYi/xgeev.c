/*
 * File: xgeev.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 27-Oct-2024 10:09:52
 */

/* Include Files */
#include "xgeev.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xnrm2.h"
#include "xzgebal.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A_data[]
 *                const int A_size[2]
 *                creal_T W_data[]
 *                int *W_size
 * Return Type  : int
 */
int xgeev(const double A_data[], const int A_size[2], creal_T W_data[],
          int *W_size)
{
  emxArray_real_T *x;
  double wi_data[2];
  double work_data[2];
  double absxk;
  double anrm;
  double cfrom1;
  double cscale;
  double ctoc;
  double mul;
  double tau_data;
  double *x_data;
  int b_i;
  int exitg2;
  int i;
  int i1;
  int ia;
  int iac;
  int ic0_tmp;
  int ihi;
  int ilo;
  int info;
  int knt;
  int lastc;
  int lastv;
  int n;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T notdone;
  boolean_T scalea;
  emxInit_real_T(&x, 2);
  i = x->size[0] * x->size[1];
  x->size[0] = A_size[0];
  x->size[1] = A_size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  knt = A_size[0] * A_size[1];
  for (i = 0; i < knt; i++) {
    x_data[i] = A_data[i];
  }
  info = 0;
  n = A_size[0];
  anrm = 0.0;
  lastv = 0;
  exitg1 = false;
  while ((!exitg1) && (lastv <= knt - 1)) {
    absxk = fabs(A_data[lastv]);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      lastv++;
    }
  }
  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    *W_size = A_size[0];
    knt = A_size[0];
    for (i = 0; i < knt; i++) {
      W_data[i].re = rtNaN;
      W_data[i].im = 0.0;
    }
  } else {
    cscale = anrm;
    scalea = false;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      guard1 = true;
    }
    if (guard1) {
      absxk = anrm;
      ctoc = cscale;
      notdone = true;
      while (notdone) {
        cfrom1 = absxk * 2.0041683600089728E-292;
        tau_data = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (tau_data > absxk) {
          mul = 4.9896007738368E+291;
          ctoc = tau_data;
        } else {
          mul = ctoc / absxk;
          notdone = false;
        }
        for (ic0_tmp = 0; ic0_tmp < n; ic0_tmp++) {
          knt = ic0_tmp * n - 1;
          for (b_i = 0; b_i < n; b_i++) {
            i = (knt + b_i) + 1;
            x_data[i] *= mul;
          }
        }
      }
    }
    emxReserve_real_T(x);
    x_data = x->data;
    ilo = xzgebal((double *)x->data, *(int(*)[2])x->size, &ihi, work_data,
                  W_size);
    n = x->size[0];
    if ((ihi - ilo) + 1 > 1) {
      knt = x->size[0];
      if (knt - 1 >= 0) {
        memset(&work_data[0], 0, (unsigned int)knt * sizeof(double));
      }
      i = ihi - 1;
      for (b_i = ilo; b_i <= i; b_i++) {
        cfrom1 = x_data[1];
        tau_data = 0.0;
        if (ihi - 1 > 0) {
          absxk = d_xnrm2(0, (double *)x->data, n);
          if (absxk != 0.0) {
            ctoc = rt_hypotd_snf(cfrom1, absxk);
            if (cfrom1 >= 0.0) {
              ctoc = -ctoc;
            }
            if (fabs(ctoc) < 1.0020841800044864E-292) {
              knt = 0;
              i1 = n - 1;
              do {
                knt++;
                for (lastv = n; lastv <= i1; lastv++) {
                  x_data[lastv - 1] *= 9.9792015476736E+291;
                }
                ctoc *= 9.9792015476736E+291;
                cfrom1 *= 9.9792015476736E+291;
              } while ((fabs(ctoc) < 1.0020841800044864E-292) && (knt < 20));
              ctoc = rt_hypotd_snf(cfrom1, d_xnrm2(0, (double *)x->data, n));
              if (cfrom1 >= 0.0) {
                ctoc = -ctoc;
              }
              tau_data = (ctoc - cfrom1) / ctoc;
              absxk = 1.0 / (cfrom1 - ctoc);
              for (lastv = n; lastv <= i1; lastv++) {
                x_data[lastv - 1] *= absxk;
              }
              for (lastv = 0; lastv < knt; lastv++) {
                ctoc *= 1.0020841800044864E-292;
              }
              cfrom1 = ctoc;
            } else {
              tau_data = (ctoc - cfrom1) / ctoc;
              absxk = 1.0 / (cfrom1 - ctoc);
              i1 = n - 1;
              for (lastv = n; lastv <= i1; lastv++) {
                x_data[lastv - 1] *= absxk;
              }
              cfrom1 = ctoc;
            }
          }
        }
        x_data[1] = 1.0;
        ic0_tmp = n + 1;
        if (tau_data != 0.0) {
          lastv = ihi - 1;
          knt = ihi;
          while ((lastv > 0) && (x_data[knt - 1] == 0.0)) {
            lastv = 0;
            knt--;
          }
          lastc = ihi;
          exitg1 = false;
          while ((!exitg1) && (lastc > 0)) {
            knt = n + lastc;
            ia = knt;
            do {
              exitg2 = 0;
              if ((n > 0) && (ia <= knt + (lastv - 1) * n)) {
                if (x_data[ia - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  ia += n;
                }
              } else {
                lastc--;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }
        if (lastv > 0) {
          if (lastc != 0) {
            i1 = (unsigned char)lastc;
            memset(&work_data[0], 0, (unsigned int)i1 * sizeof(double));
            knt = 1;
            for (iac = ic0_tmp; n < 0 ? iac >= ic0_tmp : iac <= ic0_tmp;
                 iac += n) {
              i1 = (iac + lastc) - 1;
              for (ia = iac; ia <= i1; ia++) {
                lastv = ia - iac;
                work_data[lastv] += x_data[ia - 1] * x_data[knt];
              }
              knt++;
            }
          }
          if ((!(-tau_data == 0.0)) && (x_data[1] != 0.0)) {
            absxk = x_data[1] * -tau_data;
            i1 = lastc + n;
            for (lastv = ic0_tmp; lastv <= i1; lastv++) {
              x_data[lastv - 1] += work_data[(lastv - n) - 1] * absxk;
            }
          }
        }
        ic0_tmp = n + 2;
        if (tau_data != 0.0) {
          lastv = ihi - 1;
          knt = ihi;
          while ((lastv > 0) && (x_data[knt - 1] == 0.0)) {
            lastv = 0;
            knt--;
          }
          lastc = n - 1;
          exitg1 = false;
          while ((!exitg1) && (lastc > 0)) {
            ia = n + 1;
            do {
              exitg2 = 0;
              if (ia + 1 <= (n + lastv) + 1) {
                if (x_data[ia] != 0.0) {
                  exitg2 = 1;
                } else {
                  ia++;
                }
              } else {
                lastc = 0;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }
        if (lastv > 0) {
          if (lastc != 0) {
            work_data[0] = 0.0;
            knt = 0;
            for (iac = ic0_tmp; n < 0 ? iac >= ic0_tmp : iac <= ic0_tmp;
                 iac += n) {
              absxk = 0.0;
              for (ia = iac; ia <= iac; ia++) {
                absxk += x_data[ia - 1] * x_data[(ia - iac) + 1];
              }
              work_data[knt] += absxk;
              knt++;
            }
          }
          if (!(-tau_data == 0.0)) {
            knt = n + 2;
            i1 = (unsigned char)lastc;
            for (ic0_tmp = 0; ic0_tmp < i1; ic0_tmp++) {
              absxk = work_data[ic0_tmp];
              if (absxk != 0.0) {
                absxk *= -tau_data;
                for (lastv = knt; lastv <= knt; lastv++) {
                  x_data[lastv - 1] += x_data[(lastv - knt) + 1] * absxk;
                }
              }
              knt += n;
            }
          }
        }
        x_data[1] = cfrom1;
      }
    }
    emxReserve_real_T(x);
    info = xdlahqr(ilo, ihi, (double *)x->data, *(int(*)[2])x->size, work_data,
                   W_size, wi_data, &knt);
    if (scalea) {
      i = A_size[0] - info;
      xzlascl(cscale, anrm, i, work_data, info + 1);
      xzlascl(cscale, anrm, i, wi_data, info + 1);
      if (info != 0) {
        xzlascl(cscale, anrm, ilo - 1, work_data, 1);
        xzlascl(cscale, anrm, ilo - 1, wi_data, 1);
      }
    }
    if (info != 0) {
      for (b_i = ilo; b_i <= info; b_i++) {
        work_data[b_i - 1] = rtNaN;
        wi_data[b_i - 1] = 0.0;
      }
    }
    for (i = 0; i < *W_size; i++) {
      W_data[i].re = work_data[i];
      W_data[i].im = wi_data[i];
    }
  }
  emxFree_real_T(&x);
  return info;
}

/*
 * File trailer for xgeev.c
 *
 * [EOF]
 */
