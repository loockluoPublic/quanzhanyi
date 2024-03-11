/*
 * File: _coder_mycylderfit2_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Mar-2024 23:24:40
 */

/* Include Files */
#include "_coder_mycylderfit2_api.h"
#include "_coder_mycylderfit2_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "mycylderfit2",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[45];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[45];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                 const char_T *identifier))[45];

static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[45]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[45]
{
  real_T(*y)[45];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[45]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[45]
{
  static const int32_T dims = 45;
  real_T(*ret)[45];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[45])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *x
 *                const char_T *identifier
 * Return Type  : real_T (*)[45]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                 const char_T *identifier))[45]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[45];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[7]
 * Return Type  : void
 */
void mycylderfit2_api(const mxArray *const prhs[3], int32_T nlhs,
                      const mxArray *plhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*x)[45];
  real_T(*y)[45];
  real_T(*z)[45];
  real_T XXX1;
  real_T XXX2;
  real_T XXX3;
  real_T XXX4;
  real_T XXX5;
  real_T XXX6;
  real_T XXX7;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x");
  y = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y");
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "z");
  /* Invoke the target function */
  mycylderfit2(*x, *y, *z, &XXX1, &XXX2, &XXX3, &XXX4, &XXX5, &XXX6, &XXX7);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(XXX1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(XXX2);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(XXX3);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(XXX4);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(XXX5);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(XXX6);
  }
  if (nlhs > 6) {
    plhs[6] = emlrt_marshallOut(XXX7);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mycylderfit2_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  mycylderfit2_xil_terminate();
  mycylderfit2_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mycylderfit2_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mycylderfit2_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_mycylderfit2_api.c
 *
 * [EOF]
 */
