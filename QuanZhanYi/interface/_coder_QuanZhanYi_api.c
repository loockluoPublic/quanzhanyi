/*
 * File: _coder_QuanZhanYi_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 26-Mar-2024 15:14:21
 */

/* Include Files */
#include "_coder_QuanZhanYi_api.h"
#include "_coder_QuanZhanYi_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "QuanZhanYi",                                         /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *b_emlrt_marshallOut(const real_T u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *azimuth,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u[3]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *P_bound1,
                                   const char_T *identifier))[3];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Point_in,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const real_T u[3]);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *azimuth
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *azimuth,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(azimuth), &thisId);
  emlrtDestroyArray(&azimuth);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *P_bound1
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *P_bound1,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(P_bound1), &thisId);
  emlrtDestroyArray(&P_bound1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Point_in
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Point_in,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Point_in), &thisId, y);
  emlrtDestroyArray(&Point_in);
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {3, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void QuanZhanYi_atexit(void)
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
  QuanZhanYi_xil_terminate();
  QuanZhanYi_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void QuanZhanYi_initialize(void)
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
void QuanZhanYi_terminate(void)
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
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void c_Calculate_accurate_cylinders_(const mxArray *const prhs[5], int32_T nlhs,
                                     const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Err_every;
  emxArray_real_T *Point_in;
  real_T(*Bottom_round_center1)[3];
  real_T(*Bottom_round_center2)[3];
  real_T(*MTaon)[3];
  real_T(*Mcenter)[3];
  real_T(*P_bound1)[3];
  real_T(*P_bound2)[3];
  real_T Mradial;
  real_T azimuth;
  real_T elevation;
  st.tls = emlrtRootTLSGlobal;
  Mcenter = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  MTaon = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Bottom_round_center1 = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Bottom_round_center2 = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Point_in);
  emxInit_real_T(&st, &Err_every);
  /* Marshall function inputs */
  Point_in->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Point_in", Point_in);
  azimuth = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "azimuth");
  elevation = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "elevation");
  P_bound1 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "P_bound1");
  P_bound2 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "P_bound2");
  /* Invoke the target function */
  Calculate_accurate_cylinders_from_multiple_measurement_points(
      Point_in, azimuth, elevation, *P_bound1, *P_bound2, *Mcenter, *MTaon,
      &Mradial, Err_every, *Bottom_round_center1, *Bottom_round_center2);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Mcenter);
  emxFree_real_T(&st, &Point_in);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*MTaon);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(Mradial);
  }
  if (nlhs > 3) {
    Err_every->canFreeData = false;
    plhs[3] = c_emlrt_marshallOut(Err_every);
  }
  emxFree_real_T(&st, &Err_every);
  if (nlhs > 4) {
    plhs[4] = d_emlrt_marshallOut(*Bottom_round_center1);
  }
  if (nlhs > 5) {
    plhs[5] = d_emlrt_marshallOut(*Bottom_round_center2);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                const mxArray **plhs
 * Return Type  : void
 */
void c_Generate_multi_layered_measur(const mxArray *const prhs[5],
                                     const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Point_out;
  emxArray_real_T *Point_test;
  real_T(*P3)[3];
  real_T(*P4)[3];
  real_T laynum;
  real_T num;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Point_out);
  emxInit_real_T(&st, &Point_test);
  /* Marshall function inputs */
  Point_out->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Point_out", Point_out);
  num = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "num");
  laynum = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "laynum");
  P3 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "P3");
  P4 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "P4");
  /* Invoke the target function */
  Generate_multi_layered_measurement_points(Point_out, num, laynum, *P3, *P4,
                                            Point_test);
  /* Marshall function outputs */
  Point_test->canFreeData = false;
  *plhs = c_emlrt_marshallOut(Point_test);
  emxFree_real_T(&st, &Point_test);
  emxFree_real_T(&st, &Point_out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void c_foot_of_perpendicular_from_a_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*P_lines1)[3];
  real_T(*P_lines2)[3];
  real_T(*P_outer)[3];
  real_T xN1;
  real_T yN1;
  real_T zN1;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  P_outer = e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "P_outer");
  P_lines1 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "P_lines1");
  P_lines2 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P_lines2");
  /* Invoke the target function */
  foot_of_perpendicular_from_a_point_to_a_line(*P_outer, *P_lines1, *P_lines2,
                                               &xN1, &yN1, &zN1);
  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(xN1);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(yN1);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(zN1);
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray **plhs
 * Return Type  : void
 */
void c_generate_unit_circle_with_nor(const mxArray *const prhs[3],
                                     const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Point_out;
  real_T azimuth;
  real_T elevation;
  real_T num;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Point_out);
  /* Marshall function inputs */
  azimuth = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "azimuth");
  elevation = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "elevation");
  num = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "num");
  /* Invoke the target function */
  generate_unit_circle_with_normal_vector(azimuth, elevation, num, Point_out);
  /* Marshall function outputs */
  Point_out->canFreeData = false;
  *plhs = c_emlrt_marshallOut(Point_out);
  emxFree_real_T(&st, &Point_out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_QuanZhanYi_api.c
 *
 * [EOF]
 */
