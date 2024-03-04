/*
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xscal.h"
#include "xswap.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo rd_emlrtRSI = {
    428,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    21,                   /* lineNo */
    "scaleVectorByRecip", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\scaleVectorByRecip.m" /* pathName */
};

static emlrtRSInfo of_emlrtRSI = {
    407,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo pf_emlrtRSI = {
    394,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo qf_emlrtRSI = {
    391,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo rf_emlrtRSI = {
    380,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo sf_emlrtRSI = {
    353,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    351,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    334,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    120,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    114,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    94,       /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    82,       /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    77,       /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    251,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ui_emlrtRSI = {
    240,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo vi_emlrtRSI = {
    215,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo wi_emlrtRSI = {
    194,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo xi_emlrtRSI = {
    184,      /* lineNo */
    "xzsvdc", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    269,      /* lineNo */
    13,       /* colNo */
    "xzsvdc", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pName */
};

/* Function Definitions */
void b_xzsvdc(const emlrtStack *sp, real_T A[49], real_T U[49], real_T S[7],
              real_T V[49])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T Vf[49];
  real_T e[7];
  real_T s[7];
  real_T work[7];
  real_T b;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T exitg2;
  int32_T i;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  boolean_T exitg3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 7; i++) {
    s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }
  memset(&U[0], 0, 49U * sizeof(real_T));
  memset(&Vf[0], 0, 49U * sizeof(real_T));
  for (q = 0; q < 6; q++) {
    qp1 = q + 2;
    i = q + 7 * q;
    qq = i + 1;
    apply_transform = false;
    st.site = &ag_emlrtRSI;
    nrm = c_xnrm2(&st, 7 - q, A, i + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[i] < 0.0) {
        sqds = -nrm;
        s[q] = -nrm;
      } else {
        sqds = nrm;
        s[q] = nrm;
      }
      st.site = &yf_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &ud_emlrtRSI;
        c_xscal(&b_st, 7 - q, 1.0 / sqds, A, i + 1);
      } else {
        qjj = (i - q) + 7;
        for (k = qq; k <= qjj; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[i]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (k = qp1; k < 8; k++) {
      qjj = q + 7 * (k - 1);
      if (apply_transform) {
        st.site = &xf_emlrtRSI;
        nrm = b_xdotc(&st, 7 - q, A, i + 1, A, qjj + 1);
        nrm = -(nrm / A[i]);
        d_xaxpy(7 - q, nrm, i + 1, A, qjj + 1);
      }
      e[k - 1] = A[qjj];
    }
    for (k = q + 1; k < 8; k++) {
      qjj = (k + 7 * q) - 1;
      U[qjj] = A[qjj];
    }
    if (q + 1 <= 5) {
      st.site = &wf_emlrtRSI;
      nrm = d_xnrm2(&st, 6 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        st.site = &vf_emlrtRSI;
        sm = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          b_st.site = &ud_emlrtRSI;
          d_xscal(&b_st, 6 - q, 1.0 / e[q], e, q + 2);
        } else {
          for (k = qp1; k < 8; k++) {
            e[k - 1] /= sm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 8; k++) {
          work[k - 1] = 0.0;
        }
        for (k = qp1; k < 8; k++) {
          e_xaxpy(6 - q, e[k - 1], A, (q + 7 * (k - 1)) + 2, work, q + 2);
        }
        for (k = qp1; k < 8; k++) {
          f_xaxpy(6 - q, -e[k - 1] / e[q + 1], work, q + 2, A,
                  (q + 7 * (k - 1)) + 2);
        }
      }
      for (k = qp1; k < 8; k++) {
        Vf[(k + 7 * q) - 1] = e[k - 1];
      }
    }
  }
  m = 5;
  s[6] = A[48];
  e[5] = A[47];
  e[6] = 0.0;
  for (k = 0; k < 7; k++) {
    U[k + 42] = 0.0;
  }
  U[48] = 1.0;
  for (q = 5; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 7 * q;
    if (s[q] != 0.0) {
      for (k = qp1; k < 8; k++) {
        qjj = (q + 7 * (k - 1)) + 1;
        st.site = &xi_emlrtRSI;
        nrm = b_xdotc(&st, 7 - q, U, qq + 1, U, qjj);
        nrm = -(nrm / U[qq]);
        d_xaxpy(7 - q, nrm, qq + 1, U, qjj);
      }
      for (k = q + 1; k < 8; k++) {
        qjj = (k + 7 * q) - 1;
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      st.site = &wi_emlrtRSI;
      for (k = 0; k < q; k++) {
        U[k + 7 * q] = 0.0;
      }
    } else {
      for (k = 0; k < 7; k++) {
        U[k + 7 * q] = 0.0;
      }
      U[qq] = 1.0;
    }
  }
  for (q = 6; q >= 0; q--) {
    if ((q + 1 <= 5) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 7 * q) + 2;
      for (k = qp1; k < 8; k++) {
        i = (q + 7 * (k - 1)) + 2;
        st.site = &vi_emlrtRSI;
        nrm = b_xdotc(&st, 6 - q, Vf, qjj, Vf, i);
        nrm = -(nrm / Vf[qjj - 1]);
        d_xaxpy(6 - q, nrm, qjj, Vf, i);
      }
    }
    for (k = 0; k < 7; k++) {
      Vf[k + 7 * q] = 0.0;
    }
    Vf[q + 7 * q] = 1.0;
  }
  for (q = 0; q < 7; q++) {
    sqds = s[q];
    if (sqds != 0.0) {
      rt = muDoubleScalarAbs(sqds);
      nrm = sqds / rt;
      s[q] = rt;
      if (q + 1 < 7) {
        e[q] /= nrm;
      }
      st.site = &ui_emlrtRSI;
      e_xscal(&st, nrm, U, 7 * q + 1);
    }
    if ((q + 1 < 7) && (e[q] != 0.0)) {
      rt = muDoubleScalarAbs(e[q]);
      nrm = rt / e[q];
      e[q] = rt;
      s[q + 1] *= nrm;
      st.site = &ti_emlrtRSI;
      e_xscal(&st, nrm, Vf, 7 * (q + 1) + 1);
    }
  }
  qq = 0;
  snorm = 0.0;
  for (k = 0; k < 7; k++) {
    snorm =
        muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s[k]),
                                                   muDoubleScalarAbs(e[k])));
  }
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (qq >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      k = m;
      do {
        exitg2 = 0;
        q = k + 1;
        if (k + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[k]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[k]) +
                                                muDoubleScalarAbs(s[k + 1]))) ||
              (nrm <= 1.0020841800044864E-292) ||
              ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[k] = 0.0;
            exitg2 = 1;
          } else {
            k--;
          }
        }
      } while (exitg2 == 0);
      if (k + 1 == m + 1) {
        qjj = 4;
      } else {
        i = m + 2;
        qjj = m + 2;
        exitg3 = false;
        while ((!exitg3) && (qjj >= k + 1)) {
          i = qjj;
          if (qjj == k + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }
            if (qjj > k + 2) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }
            rt = muDoubleScalarAbs(s[qjj - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg3 = true;
            } else {
              qjj--;
            }
          }
        }
        if (i == k + 1) {
          qjj = 3;
        } else if (i == m + 2) {
          qjj = 1;
        } else {
          qjj = 2;
          q = i;
        }
      }
      switch (qjj) {
      case 1:
        rt = e[m];
        e[m] = 0.0;
        qjj = m + 1;
        for (k = qjj; k >= q + 1; k--) {
          st.site = &uf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          if (k > q + 1) {
            nrm = e[k - 2];
            rt = -sn * nrm;
            e[k - 2] = nrm * scale;
          }
          xrot(Vf, 7 * (k - 1) + 1, 7 * (m + 1) + 1, scale, sn);
        }
        break;
      case 2:
        rt = e[q - 1];
        e[q - 1] = 0.0;
        st.site = &tf_emlrtRSI;
        for (k = q + 1; k <= m + 2; k++) {
          st.site = &sf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          nrm = e[k - 1];
          rt = -sn * nrm;
          e[k - 1] = nrm * scale;
          xrot(U, 7 * (k - 1) + 1, 7 * (q - 1) + 1, scale, sn);
        }
        break;
      case 3:
        qjj = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[q])),
            muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &rf_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        st.site = &qf_emlrtRSI;
        for (k = q + 1; k <= qjj; k++) {
          st.site = &pf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&rt, &nrm, &scale, &sn);
          if (k > q + 1) {
            e[k - 2] = rt;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          sm = scale * rt + sn * nrm;
          e[k - 1] = scale * nrm - sn * rt;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          xrot(Vf, 7 * (k - 1) + 1, 7 * k + 1, scale, sn);
          st.site = &of_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          rt = scale * e[k - 1] + sn * sqds;
          sqds = -sn * e[k - 1] + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
          xrot(U, 7 * (k - 1) + 1, 7 * k + 1, scale, sn);
        }
        e[m] = rt;
        qq++;
        break;
      default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
          st.site = &rd_emlrtRSI;
          e_xscal(&st, -1.0, Vf, 7 * q + 1);
        }
        qp1 = q + 1;
        while ((q + 1 < 7) && (s[q] < s[qp1])) {
          rt = s[q];
          s[q] = s[qp1];
          s[qp1] = rt;
          xswap(Vf, 7 * q + 1, 7 * (q + 1) + 1);
          xswap(U, 7 * q + 1, 7 * (q + 1) + 1);
          q = qp1;
          qp1++;
        }
        qq = 0;
        m--;
        break;
      }
    }
  }
  for (k = 0; k < 7; k++) {
    S[k] = s[k];
    for (i = 0; i < 7; i++) {
      qjj = i + 7 * k;
      V[qjj] = Vf[qjj];
    }
  }
}

void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T b;
  real_T nrm;
  real_T r;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T exitg2;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T apply_transform;
  boolean_T exitg1;
  boolean_T exitg3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (q = 0; q < 2; q++) {
    qp1 = q + 2;
    iter = q + 3 * q;
    qq = iter + 1;
    apply_transform = false;
    st.site = &ag_emlrtRSI;
    nrm = xnrm2(&st, 3 - q, A, iter + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[iter] < 0.0) {
        sqds = -nrm;
        s[q] = -nrm;
      } else {
        sqds = nrm;
        s[q] = nrm;
      }
      st.site = &yf_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &ud_emlrtRSI;
        xscal(&b_st, 3 - q, 1.0 / sqds, A, iter + 1);
      } else {
        qs = (iter - q) + 3;
        for (k = qq; k <= qs; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[iter]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (qs = qp1; qs < 4; qs++) {
      qq = q + 3 * (qs - 1);
      if (apply_transform) {
        st.site = &xf_emlrtRSI;
        nrm = xdotc(&st, 3 - q, A, iter + 1, A, qq + 1);
        nrm = -(nrm / A[iter]);
        xaxpy(3 - q, nrm, iter + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (q + 1 <= 1) {
      st.site = &wf_emlrtRSI;
      nrm = b_xnrm2(&st, e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &vf_emlrtRSI;
        sm = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          b_st.site = &ud_emlrtRSI;
          b_xscal(&b_st, 1.0 / e[0], e, 2);
        } else {
          for (k = qp1; k < 4; k++) {
            e[k - 1] /= sm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (k = qp1; k < 4; k++) {
          work[k - 1] = 0.0;
        }
        for (qs = qp1; qs < 4; qs++) {
          b_xaxpy(2, e[qs - 1], A, 3 * (qs - 1) + 2, work, 2);
        }
        for (qs = qp1; qs < 4; qs++) {
          c_xaxpy(2, -e[qs - 1] / e[1], work, 2, A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    r = s[0] / nrm;
    sqds = nrm;
    s[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    s[1] *= r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    r = s[1] / nrm;
    sqds = nrm;
    s[1] = nrm;
    e[1] = A[7] / r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    s[2] = A[8] * r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  sqds = s[2];
  if (s[2] != 0.0) {
    nrm = muDoubleScalarAbs(s[2]);
    sqds = nrm;
    s[2] = nrm;
  }
  snorm =
      muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(sqds), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      k = m;
      do {
        exitg2 = 0;
        q = k + 1;
        if (k + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[k]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[k]) +
                                                muDoubleScalarAbs(s[k + 1]))) ||
              (nrm <= 1.0020841800044864E-292) ||
              ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[k] = 0.0;
            exitg2 = 1;
          } else {
            k--;
          }
        }
      } while (exitg2 == 0);
      if (k + 1 == m + 1) {
        qq = 4;
      } else {
        qs = m + 2;
        qq = m + 2;
        exitg3 = false;
        while ((!exitg3) && (qq >= k + 1)) {
          qs = qq;
          if (qq == k + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (qq < m + 2) {
              nrm = muDoubleScalarAbs(e[qq - 1]);
            }
            if (qq > k + 2) {
              nrm += muDoubleScalarAbs(e[qq - 2]);
            }
            r = muDoubleScalarAbs(s[qq - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) ||
                (r <= 1.0020841800044864E-292)) {
              s[qq - 1] = 0.0;
              exitg3 = true;
            } else {
              qq--;
            }
          }
        }
        if (qs == k + 1) {
          qq = 3;
        } else if (qs == m + 2) {
          qq = 1;
        } else {
          qq = 2;
          q = qs;
        }
      }
      switch (qq) {
      case 1:
        r = e[m];
        e[m] = 0.0;
        qq = m + 1;
        for (k = qq; k >= q + 1; k--) {
          st.site = &uf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          if (k > q + 1) {
            r = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        r = e[q - 1];
        e[q - 1] = 0.0;
        st.site = &tf_emlrtRSI;
        for (k = q + 1; k <= m + 2; k++) {
          st.site = &sf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          nrm = e[k - 1];
          r = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        qq = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[q])),
            muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        r = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = b * b + nrm;
          st.site = &rf_emlrtRSI;
          if (r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          r = muDoubleScalarSqrt(r);
          if (b < 0.0) {
            r = -r;
          }
          r = nrm / (b + r);
        } else {
          r = 0.0;
        }
        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        st.site = &qf_emlrtRSI;
        for (k = q + 1; k <= qq; k++) {
          st.site = &pf_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&r, &nrm, &scale, &sn);
          if (k > q + 1) {
            e[0] = r;
          }
          nrm = e[k - 1];
          r = s[k - 1];
          sm = scale * r + sn * nrm;
          e[k - 1] = scale * nrm - sn * r;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &of_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          r = scale * e[k - 1] + sn * sqds;
          sqds = -sn * e[k - 1] + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = r;
        iter++;
        break;
      default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }
        qp1 = q + 1;
        while ((q + 1 < 3) && (s[q] < s[qp1])) {
          nrm = s[q];
          s[q] = s[qp1];
          s[qp1] = nrm;
          q = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

/* End of code generation (xzsvdc.c) */
