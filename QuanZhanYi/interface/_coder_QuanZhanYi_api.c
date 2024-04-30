/*
 * File: _coder_QuanZhanYi_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 30-Apr-2024 00:52:42
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
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *MTaon,
                                   const char_T *identifier))[3];

static const mxArray *c_emlrt_marshallOut(const real_T u[3]);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *e_emlrt_marshallOut(const real_T u[2]);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *ANG,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *f_emlrt_marshallOut(const real_T u[9]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r,
                                   const char_T *identifier))[4];

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
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
 *                const mxArray *MTaon
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *MTaon,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(MTaon), &thisId);
  emlrtDestroyArray(&MTaon);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[3])
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
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *points
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(points), &thisId, y);
  emlrtDestroyArray(&points);
}

/*
 * Arguments    : const real_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const real_T u[2])
{
  static const int32_T i = 0;
  static const int32_T i1 = 2;
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *ANG
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *ANG,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(ANG), &thisId);
  emlrtDestroyArray(&ANG);
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
 *                int32_T numDimensions
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(const real_T u[9])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 3};
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
 *                const mxArray *x
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *r
 *                const char_T *identifier
 * Return Type  : real_T (*)[4]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(r), &thisId);
  emlrtDestroyArray(&r);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[4]
 */
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, 2};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, false};
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
 * Return Type  : real_T (*)[4]
 */
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  real_T(*ret)[4];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void Calculat_A_and_B_Points_api(const mxArray *const prhs[8], int32_T nlhs,
                                 const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PointTable_A;
  emxArray_real_T *PointTable_B;
  real_T(*Bottom_round_center1)[3];
  real_T(*Bottom_round_center2)[3];
  real_T(*MTaon)[3];
  real_T(*Mcenter)[3];
  real_T(*testP)[3];
  real_T Mradial;
  real_T numShengLu;
  real_T phi;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &PointTable_A, 2);
  emxInit_real_T(&st, &PointTable_B, 2);
  /* Marshall function inputs */
  MTaon = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "MTaon");
  Mcenter = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Mcenter");
  Mradial = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Mradial");
  Bottom_round_center1 =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Bottom_round_center1");
  Bottom_round_center2 =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "Bottom_round_center2");
  testP = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "testP");
  numShengLu = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "numShengLu");
  phi = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "phi");
  /* Invoke the target function */
  Calculat_A_and_B_Points(*MTaon, *Mcenter, Mradial, *Bottom_round_center1,
                          *Bottom_round_center2, *testP, numShengLu, phi,
                          PointTable_A, PointTable_B);
  /* Marshall function outputs */
  PointTable_A->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PointTable_A);
  emxFree_real_T(&st, &PointTable_A);
  if (nlhs > 1) {
    PointTable_B->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(PointTable_B);
  }
  emxFree_real_T(&st, &PointTable_B);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
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
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void angle2point_api(const mxArray *const prhs[6], int32_T nlhs,
                     const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T ANG;
  real_T Mradial;
  real_T a;
  real_T b;
  real_T c;
  real_T d;
  real_T x;
  real_T y;
  real_T z;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  ANG = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ANG");
  a = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a");
  b = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "b");
  c = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "c");
  d = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "d");
  Mradial = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Mradial");
  /* Invoke the target function */
  angle2point(ANG, a, b, c, d, Mradial, &x, &y, &z);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(x);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(y);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(z);
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void c_Calculate_accurate_cylinders_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Err_every;
  emxArray_real_T *points;
  real_T(*Bottom_round_center1)[3];
  real_T(*Bottom_round_center2)[3];
  real_T(*MTaon)[3];
  real_T(*Mcenter)[3];
  real_T(*P_bound1)[3];
  real_T(*P_bound2)[3];
  real_T Mradial;
  st.tls = emlrtRootTLSGlobal;
  Mcenter = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  MTaon = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Bottom_round_center1 = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Bottom_round_center2 = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &points, 2);
  emxInit_real_T(&st, &Err_every, 1);
  /* Marshall function inputs */
  points->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "points", points);
  P_bound1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "P_bound1");
  P_bound2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P_bound2");
  /* Invoke the target function */
  Calculate_accurate_cylinders_from_multiple_measurement_points2(
      points, *P_bound1, *P_bound2, *Mcenter, *MTaon, &Mradial, Err_every,
      *Bottom_round_center1, *Bottom_round_center2);
  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*Mcenter);
  emxFree_real_T(&st, &points);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(*MTaon);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(Mradial);
  }
  if (nlhs > 3) {
    Err_every->canFreeData = false;
    plhs[3] = d_emlrt_marshallOut(Err_every);
  }
  emxFree_real_T(&st, &Err_every);
  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(*Bottom_round_center1);
  }
  if (nlhs > 5) {
    plhs[5] = c_emlrt_marshallOut(*Bottom_round_center2);
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
  emxInit_real_T(&st, &Point_out, 2);
  emxInit_real_T(&st, &Point_test, 2);
  /* Marshall function inputs */
  Point_out->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Point_out", Point_out);
  num = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "num");
  laynum = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "laynum");
  P3 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "P3");
  P4 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "P4");
  /* Invoke the target function */
  Generate_multi_layered_measurement_points(Point_out, num, laynum, *P3, *P4,
                                            Point_test);
  /* Marshall function outputs */
  Point_test->canFreeData = false;
  *plhs = b_emlrt_marshallOut(Point_test);
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
  P_outer = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "P_outer");
  P_lines1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "P_lines1");
  P_lines2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P_lines2");
  /* Invoke the target function */
  foot_of_perpendicular_from_a_point_to_a_line(*P_outer, *P_lines1, *P_lines2,
                                               &xN1, &yN1, &zN1);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(xN1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(yN1);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(zN1);
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
  emxInit_real_T(&st, &Point_out, 2);
  /* Marshall function inputs */
  azimuth = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "azimuth");
  elevation = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "elevation");
  num = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "num");
  /* Invoke the target function */
  generate_unit_circle_with_normal_vector(azimuth, elevation, num, Point_out);
  /* Marshall function outputs */
  Point_out->canFreeData = false;
  *plhs = b_emlrt_marshallOut(Point_out);
  emxFree_real_T(&st, &Point_out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                const mxArray **plhs
 * Return Type  : void
 */
void d_generate_unit_circle_with_nor(const mxArray *const prhs[6],
                                     const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Point_out;
  real_T(*P1)[3];
  real_T(*P2)[3];
  real_T azimuth;
  real_T elevation;
  real_T laynum;
  real_T num;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Point_out, 2);
  /* Marshall function inputs */
  azimuth = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "azimuth");
  elevation = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "elevation");
  num = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "num");
  laynum = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "laynum");
  P1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "P1");
  P2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "P2");
  /* Invoke the target function */
  generate_unit_circle_with_normal_vector2(azimuth, elevation, num, laynum, *P1,
                                           *P2, Point_out);
  /* Marshall function outputs */
  Point_out->canFreeData = false;
  *plhs = b_emlrt_marshallOut(Point_out);
  emxFree_real_T(&st, &Point_out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray *prhs
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void fitcircle_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *x;
  real_T(*z)[2];
  real_T r;
  real_T residual;
  st.tls = emlrtRootTLSGlobal;
  z = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &x, 2);
  /* Marshall function inputs */
  x->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);
  /* Invoke the target function */
  fitcircle(x, *z, &r, &residual);
  /* Marshall function outputs */
  plhs[0] = e_emlrt_marshallOut(*z);
  emxFree_real_T(&st, &x);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(r);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(residual);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void myvrrotvec2mat_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*m)[9];
  real_T(*r)[4];
  st.tls = emlrtRootTLSGlobal;
  m = (real_T(*)[9])mxMalloc(sizeof(real_T[9]));
  /* Marshall function inputs */
  r = i_emlrt_marshallIn(&st, emlrtAlias(prhs), "r");
  /* Invoke the target function */
  myvrrotvec2mat(*r, *m);
  /* Marshall function outputs */
  *plhs = f_emlrt_marshallOut(*m);
}

/*
 * File trailer for _coder_QuanZhanYi_api.c
 *
 * [EOF]
 */
