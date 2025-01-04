/*
 * File: _coder_QuanZhanYi_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 27-Sep-2024 14:25:16
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

static const mxArray *d_emlrt_marshallOut(const real_T u[3]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ang,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *e_emlrt_marshallOut(const real_T u[24]);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *ANG,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *f_emlrt_marshallOut(const real_T u[2]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *g_emlrt_marshallOut(const real_T u[6]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *h_emlrt_marshallOut(const real_T u[9]);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *P_bound1,
                                   const char_T *identifier))[3];

static const mxArray *i_emlrt_marshallOut(const real_T u[4]);

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *j_emlrt_marshallOut(const real_T u[8]);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *PlanePara1,
                                   const char_T *identifier))[4];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *PlaneParaIn,
                               const char_T *identifier, emxArray_real_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

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
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u[3])
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Ang
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ang,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Ang), &thisId, y);
  emlrtDestroyArray(&Ang);
}

/*
 * Arguments    : const real_T u[24]
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const real_T u[24])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {8, 3};
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
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(const real_T u[2])
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
 *                const mxArray *points
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *points,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(points), &thisId, y);
  emlrtDestroyArray(&points);
}

/*
 * Arguments    : const real_T u[6]
 * Return Type  : const mxArray *
 */
static const mxArray *g_emlrt_marshallOut(const real_T u[6])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 2};
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
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *h_emlrt_marshallOut(const real_T u[9])
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
 *                const mxArray *P_bound1
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *P_bound1,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(P_bound1), &thisId);
  emlrtDestroyArray(&P_bound1);
  return y;
}

/*
 * Arguments    : const real_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *i_emlrt_marshallOut(const real_T u[4])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 4};
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
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[8]
 * Return Type  : const mxArray *
 */
static const mxArray *j_emlrt_marshallOut(const real_T u[8])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 8};
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
 *                const mxArray *PlanePara1
 *                const char_T *identifier
 * Return Type  : real_T (*)[4]
 */
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *PlanePara1,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(PlanePara1), &thisId);
  emlrtDestroyArray(&PlanePara1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[4]
 */
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *x
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *PlaneParaIn
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *PlaneParaIn,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(PlaneParaIn), &thisId, y);
  emlrtDestroyArray(&PlaneParaIn);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
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
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 * Return Type  : real_T (*)[3]
 */
static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2] = {1, 3};
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[4]
 */
static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {4, -1};
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
  emxInit_real_T(&st, &PointTable_A);
  emxInit_real_T(&st, &PointTable_B);
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
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void CrossLine_api(const mxArray *const prhs[3], int32_T nlhs,
                   const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*PlanePara1)[4];
  real_T(*PlanePara2)[4];
  real_T(*P0)[3];
  real_T(*d)[3];
  real_T x_val;
  st.tls = emlrtRootTLSGlobal;
  P0 = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  d = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  /* Marshall function inputs */
  PlanePara1 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "PlanePara1");
  PlanePara2 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "PlanePara2");
  x_val = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "x_val");
  /* Invoke the target function */
  CrossLine(*PlanePara1, *PlanePara2, x_val, *P0, *d);
  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*P0);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(*d);
  }
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                const mxArray **plhs
 * Return Type  : void
 */
void GenerateTrianglePoints_api(const mxArray *const prhs[4],
                                const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*PointTri)[6];
  real_T(*PlaneParaIn)[4];
  real_T(*BoundPoint1)[3];
  real_T(*Direction)[3];
  real_T(*P0)[3];
  st.tls = emlrtRootTLSGlobal;
  PointTri = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  PlaneParaIn = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "PlaneParaIn");
  BoundPoint1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "BoundPoint1");
  P0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P0");
  Direction = i_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Direction");
  /* Invoke the target function */
  GenerateTrianglePoints(*PlaneParaIn, *BoundPoint1, *P0, *Direction,
                         *PointTri);
  /* Marshall function outputs */
  *plhs = g_emlrt_marshallOut(*PointTri);
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                const mxArray **plhs
 * Return Type  : void
 */
void OffsetCalculate_api(const mxArray *const prhs[4], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Ang;
  emxArray_real_T *OffsetOut;
  emxArray_real_T *a;
  real_T Mradial;
  real_T phi;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Ang);
  emxInit_real_T(&st, &a);
  emxInit_real_T(&st, &OffsetOut);
  /* Marshall function inputs */
  Mradial = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Mradial");
  phi = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "phi");
  Ang->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Ang", Ang);
  a->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "a", a);
  /* Invoke the target function */
  OffsetCalculate(Mradial, phi, Ang, a, OffsetOut);
  /* Marshall function outputs */
  OffsetOut->canFreeData = false;
  *plhs = b_emlrt_marshallOut(OffsetOut);
  emxFree_real_T(&st, &OffsetOut);
  emxFree_real_T(&st, &a);
  emxFree_real_T(&st, &Ang);
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
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void RepeatSurvey_api(const mxArray *const prhs[4], int32_T nlhs,
                      const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*Bottom_round_center1)[3];
  real_T(*Bottom_round_center2)[3];
  real_T(*SoundPoint1)[3];
  real_T(*SoundPoint2)[3];
  real_T SoundAngle;
  real_T SoundLength;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  SoundPoint1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "SoundPoint1");
  SoundPoint2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "SoundPoint2");
  Bottom_round_center1 =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Bottom_round_center1");
  Bottom_round_center2 =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Bottom_round_center2");
  /* Invoke the target function */
  RepeatSurvey(*SoundPoint1, *SoundPoint2, *Bottom_round_center1,
               *Bottom_round_center2, &SoundAngle, &SoundLength);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(SoundAngle);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(SoundLength);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void ShengDaoGaoDu_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Ti;
  real_T numShengLu;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Ti);
  /* Marshall function inputs */
  numShengLu = emlrt_marshallIn(&st, emlrtAliasP(prhs), "numShengLu");
  /* Invoke the target function */
  ShengDaoGaoDu(numShengLu, Ti);
  /* Marshall function outputs */
  Ti->canFreeData = false;
  *plhs = b_emlrt_marshallOut(Ti);
  emxFree_real_T(&st, &Ti);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void ShengLuJiaoJiSuan_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Ang;
  real_T numShengLu;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Ang);
  /* Marshall function inputs */
  numShengLu = emlrt_marshallIn(&st, emlrtAliasP(prhs), "numShengLu");
  /* Invoke the target function */
  ShengLuJiaoJiSuan(numShengLu, Ang);
  /* Marshall function outputs */
  Ang->canFreeData = false;
  *plhs = b_emlrt_marshallOut(Ang);
  emxFree_real_T(&st, &Ang);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
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
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void c_Calculat_A_and_B_Points_after(const mxArray *const prhs[8], int32_T nlhs,
                                     const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *Ang;
  emxArray_real_T *PointTable_A_off;
  emxArray_real_T *PointTable_B_off;
  emxArray_real_T *roff;
  emxArray_real_T *toff;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  real_T(*MTaon)[3];
  real_T(*Mcenter)[3];
  real_T(*PAB)[3];
  real_T Mradial;
  real_T phi;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Ang);
  emxInit_real_T(&st, &toff);
  emxInit_real_T(&st, &roff);
  emxInit_real_T(&st, &PointTable_A_off);
  emxInit_real_T(&st, &PointTable_B_off);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = emlrtProtectR2012b(prhs[5], 5, false, -1);
  /* Marshall function inputs */
  MTaon = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "MTaon");
  Mcenter = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "Mcenter");
  Mradial = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_2), "Mradial");
  PAB = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "PAB");
  phi = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_4), "phi");
  Ang->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "Ang", Ang);
  toff->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "toff", toff);
  roff->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "roff", roff);
  /* Invoke the target function */
  Calculat_A_and_B_Points_after_Offest2(*MTaon, *Mcenter, Mradial, *PAB, phi,
                                        Ang, toff, roff, PointTable_A_off,
                                        PointTable_B_off);
  /* Marshall function outputs */
  PointTable_A_off->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PointTable_A_off);
  emxFree_real_T(&st, &PointTable_A_off);
  emxFree_real_T(&st, &roff);
  emxFree_real_T(&st, &toff);
  emxFree_real_T(&st, &Ang);
  if (nlhs > 1) {
    PointTable_B_off->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(PointTable_B_off);
  }
  emxFree_real_T(&st, &PointTable_B_off);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[10]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void c_Calculat_JuXing_A_and_B_Point(const mxArray *const prhs[10],
                                     int32_T nlhs, const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PointTable_A_off;
  emxArray_real_T *PointTable_B_off;
  emxArray_real_T *Ti;
  emxArray_real_T *toff;
  real_T(*PAB)[3];
  real_T(*Pin)[3];
  real_T(*Tao)[3];
  real_T(*UPP)[3];
  real_T b;
  real_T h;
  real_T phi;
  real_T shenglunum;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Ti);
  emxInit_real_T(&st, &toff);
  emxInit_real_T(&st, &PointTable_A_off);
  emxInit_real_T(&st, &PointTable_B_off);
  /* Marshall function inputs */
  Tao = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Tao");
  UPP = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "UPP");
  Pin = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Pin");
  b = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "b");
  h = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "h");
  PAB = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "PAB");
  phi = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "phi");
  shenglunum = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "shenglunum");
  Ti->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "Ti", Ti);
  toff->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "toff", toff);
  /* Invoke the target function */
  Calculat_JuXing_A_and_B_Points_after_Offest(
      *Tao, *UPP, *Pin, b, h, *PAB, phi, shenglunum, Ti, toff, PointTable_A_off,
      PointTable_B_off);
  /* Marshall function outputs */
  PointTable_A_off->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PointTable_A_off);
  emxFree_real_T(&st, &PointTable_A_off);
  emxFree_real_T(&st, &toff);
  emxFree_real_T(&st, &Ti);
  if (nlhs > 1) {
    PointTable_B_off->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(PointTable_B_off);
  }
  emxFree_real_T(&st, &PointTable_B_off);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
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
  emxInit_real_T(&st, &points);
  emxInit_real_T(&st, &Err_every);
  /* Marshall function inputs */
  points->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "points", points);
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
    plhs[3] = b_emlrt_marshallOut(Err_every);
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
 * Arguments    : const mxArray *prhs
 *                int32_T nlhs
 *                const mxArray *plhs[8]
 * Return Type  : void
 */
void c_Calculate_rectangle_from_vert(const mxArray *prhs, int32_T nlhs,
                                     const mxArray *plhs[8])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *TrianglePoints4;
  real_T(*PP)[24];
  real_T(*Pin)[3];
  real_T(*Pout)[3];
  real_T(*Tao)[3];
  real_T(*UPP)[3];
  real_T b;
  real_T h;
  real_T w;
  st.tls = emlrtRootTLSGlobal;
  Pin = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Pout = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  UPP = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Tao = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  PP = (real_T(*)[24])mxMalloc(sizeof(real_T[24]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &TrianglePoints4);
  /* Marshall function inputs */
  TrianglePoints4->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs), "TrianglePoints4", TrianglePoints4);
  /* Invoke the target function */
  Calculate_rectangle_from_vertex(TrianglePoints4, *Pin, *Pout, *UPP, &b, &h,
                                  &w, *Tao, *PP);
  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*Pin);
  emxFree_real_T(&st, &TrianglePoints4);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(*Pout);
  }
  if (nlhs > 2) {
    plhs[2] = d_emlrt_marshallOut(*UPP);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(b);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(h);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(w);
  }
  if (nlhs > 6) {
    plhs[6] = d_emlrt_marshallOut(*Tao);
  }
  if (nlhs > 7) {
    plhs[7] = e_emlrt_marshallOut(*PP);
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
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Point_out", Point_out);
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
  emxInit_real_T(&st, &Point_out);
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
 * Arguments    : const mxArray * const prhs[16]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void d_Calculate_rectangle_from_vert(const mxArray *const prhs[16],
                                     int32_T nlhs, const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PointTable_A_off8;
  emxArray_real_T *PointTable_B_off8;
  emxArray_real_T *Ti;
  emxArray_real_T *XieMianPianYi;
  emxArray_real_T *a;
  emxArray_real_T *side_faces_transformed1;
  emxArray_real_T *side_faces_transformed2;
  emxArray_real_T *side_faces_transformed3;
  emxArray_real_T *side_faces_transformed4;
  emxArray_real_T *side_faces_transformed5;
  emxArray_real_T *side_faces_transformed6;
  emxArray_real_T *side_faces_transformed7;
  emxArray_real_T *side_faces_transformed8;
  real_T(*PAB)[3];
  real_T(*P_bound1)[3];
  real_T(*P_bound2)[3];
  real_T distanceThreshold;
  real_T phi;
  real_T shenglunum;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &side_faces_transformed1);
  emxInit_real_T(&st, &side_faces_transformed2);
  emxInit_real_T(&st, &side_faces_transformed3);
  emxInit_real_T(&st, &side_faces_transformed4);
  emxInit_real_T(&st, &side_faces_transformed5);
  emxInit_real_T(&st, &side_faces_transformed6);
  emxInit_real_T(&st, &side_faces_transformed7);
  emxInit_real_T(&st, &side_faces_transformed8);
  emxInit_real_T(&st, &Ti);
  emxInit_real_T(&st, &a);
  emxInit_real_T(&st, &PointTable_A_off8);
  emxInit_real_T(&st, &PointTable_B_off8);
  emxInit_real_T(&st, &XieMianPianYi);
  /* Marshall function inputs */
  side_faces_transformed1->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "side_faces_transformed1",
                     side_faces_transformed1);
  side_faces_transformed2->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "side_faces_transformed2",
                     side_faces_transformed2);
  side_faces_transformed3->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "side_faces_transformed3",
                     side_faces_transformed3);
  side_faces_transformed4->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "side_faces_transformed4",
                     side_faces_transformed4);
  side_faces_transformed5->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "side_faces_transformed5",
                     side_faces_transformed5);
  side_faces_transformed6->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "side_faces_transformed6",
                     side_faces_transformed6);
  side_faces_transformed7->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "side_faces_transformed7",
                     side_faces_transformed7);
  side_faces_transformed8->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "side_faces_transformed8",
                     side_faces_transformed8);
  P_bound1 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "P_bound1");
  P_bound2 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "P_bound2");
  PAB = c_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "PAB");
  phi = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "phi");
  shenglunum = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "shenglunum");
  Ti->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "Ti", Ti);
  a->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "a", a);
  distanceThreshold =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "distanceThreshold");
  /* Invoke the target function */
  Calculate_rectangle_from_vertex8(
      side_faces_transformed1, side_faces_transformed2, side_faces_transformed3,
      side_faces_transformed4, side_faces_transformed5, side_faces_transformed6,
      side_faces_transformed7, side_faces_transformed8, *P_bound1, *P_bound2,
      *PAB, phi, shenglunum, Ti, a, distanceThreshold, PointTable_A_off8,
      PointTable_B_off8, XieMianPianYi);
  /* Marshall function outputs */
  PointTable_A_off8->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PointTable_A_off8);
  emxFree_real_T(&st, &PointTable_A_off8);
  emxFree_real_T(&st, &a);
  emxFree_real_T(&st, &Ti);
  emxFree_real_T(&st, &side_faces_transformed8);
  emxFree_real_T(&st, &side_faces_transformed7);
  emxFree_real_T(&st, &side_faces_transformed6);
  emxFree_real_T(&st, &side_faces_transformed5);
  emxFree_real_T(&st, &side_faces_transformed4);
  emxFree_real_T(&st, &side_faces_transformed3);
  emxFree_real_T(&st, &side_faces_transformed2);
  emxFree_real_T(&st, &side_faces_transformed1);
  if (nlhs > 1) {
    PointTable_B_off8->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(PointTable_B_off8);
  }
  emxFree_real_T(&st, &PointTable_B_off8);
  if (nlhs > 2) {
    XieMianPianYi->canFreeData = false;
    plhs[2] = b_emlrt_marshallOut(XieMianPianYi);
  }
  emxFree_real_T(&st, &XieMianPianYi);
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
  emxInit_real_T(&st, &Point_out);
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
  emxInit_real_T(&st, &x);
  /* Marshall function inputs */
  x->canFreeData = false;
  m_emlrt_marshallIn(&st, emlrtAlias(prhs), "x", x);
  /* Invoke the target function */
  fitcircle(x, *z, &r, &residual);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*z);
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
  r = k_emlrt_marshallIn(&st, emlrtAlias(prhs), "r");
  /* Invoke the target function */
  myvrrotvec2mat(*r, *m);
  /* Marshall function outputs */
  *plhs = h_emlrt_marshallOut(*m);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void planefit4_api(const mxArray *const prhs[7], int32_T nlhs,
                   const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points1;
  emxArray_real_T *Points2;
  emxArray_real_T *Points3;
  emxArray_real_T *Points4;
  emxArray_real_T *TrianglePoints;
  emxArray_real_T *distancesFianal;
  real_T(*MaxDis)[4];
  real_T(*BoundPoint1)[3];
  real_T(*BoundPoint2)[3];
  real_T distanceThreshold;
  st.tls = emlrtRootTLSGlobal;
  MaxDis = (real_T(*)[4])mxMalloc(sizeof(real_T[4]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Points1);
  emxInit_real_T(&st, &Points2);
  emxInit_real_T(&st, &Points3);
  emxInit_real_T(&st, &Points4);
  emxInit_real_T(&st, &PlaneParaOut);
  emxInit_real_T(&st, &TrianglePoints);
  emxInit_real_T(&st, &distancesFianal);
  /* Marshall function inputs */
  Points1->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Points1", Points1);
  Points2->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Points2", Points2);
  Points3->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Points3", Points3);
  Points4->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Points4", Points4);
  BoundPoint1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "BoundPoint1");
  BoundPoint2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "BoundPoint2");
  distanceThreshold =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "distanceThreshold");
  /* Invoke the target function */
  planefit4(Points1, Points2, Points3, Points4, *BoundPoint1, *BoundPoint2,
            distanceThreshold, PlaneParaOut, TrianglePoints, *MaxDis,
            distancesFianal);
  /* Marshall function outputs */
  PlaneParaOut->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PlaneParaOut);
  emxFree_real_T(&st, &PlaneParaOut);
  emxFree_real_T(&st, &Points4);
  emxFree_real_T(&st, &Points3);
  emxFree_real_T(&st, &Points2);
  emxFree_real_T(&st, &Points1);
  if (nlhs > 1) {
    TrianglePoints->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(TrianglePoints);
  }
  emxFree_real_T(&st, &TrianglePoints);
  if (nlhs > 2) {
    plhs[2] = i_emlrt_marshallOut(*MaxDis);
  }
  if (nlhs > 3) {
    distancesFianal->canFreeData = false;
    plhs[3] = b_emlrt_marshallOut(distancesFianal);
  }
  emxFree_real_T(&st, &distancesFianal);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[11]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void planefit8_api(const mxArray *const prhs[11], int32_T nlhs,
                   const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points1;
  emxArray_real_T *Points2;
  emxArray_real_T *Points3;
  emxArray_real_T *Points4;
  emxArray_real_T *Points5;
  emxArray_real_T *Points6;
  emxArray_real_T *Points7;
  emxArray_real_T *Points8;
  emxArray_real_T *TrianglePoints;
  emxArray_real_T *distancesFianal;
  real_T(*MaxDis)[8];
  real_T(*P_bound1)[3];
  real_T(*P_bound2)[3];
  real_T distanceThreshold;
  st.tls = emlrtRootTLSGlobal;
  MaxDis = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Points1);
  emxInit_real_T(&st, &Points2);
  emxInit_real_T(&st, &Points3);
  emxInit_real_T(&st, &Points4);
  emxInit_real_T(&st, &Points5);
  emxInit_real_T(&st, &Points6);
  emxInit_real_T(&st, &Points7);
  emxInit_real_T(&st, &Points8);
  emxInit_real_T(&st, &PlaneParaOut);
  emxInit_real_T(&st, &TrianglePoints);
  emxInit_real_T(&st, &distancesFianal);
  /* Marshall function inputs */
  Points1->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Points1", Points1);
  Points2->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Points2", Points2);
  Points3->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Points3", Points3);
  Points4->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Points4", Points4);
  Points5->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "Points5", Points5);
  Points6->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "Points6", Points6);
  Points7->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Points7", Points7);
  Points8->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Points8", Points8);
  P_bound1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "P_bound1");
  P_bound2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "P_bound2");
  distanceThreshold =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "distanceThreshold");
  /* Invoke the target function */
  planefit8(Points1, Points2, Points3, Points4, Points5, Points6, Points7,
            Points8, *P_bound1, *P_bound2, distanceThreshold, PlaneParaOut,
            TrianglePoints, *MaxDis, distancesFianal);
  /* Marshall function outputs */
  PlaneParaOut->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PlaneParaOut);
  emxFree_real_T(&st, &PlaneParaOut);
  emxFree_real_T(&st, &Points8);
  emxFree_real_T(&st, &Points7);
  emxFree_real_T(&st, &Points6);
  emxFree_real_T(&st, &Points5);
  emxFree_real_T(&st, &Points4);
  emxFree_real_T(&st, &Points3);
  emxFree_real_T(&st, &Points2);
  emxFree_real_T(&st, &Points1);
  if (nlhs > 1) {
    TrianglePoints->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(TrianglePoints);
  }
  emxFree_real_T(&st, &TrianglePoints);
  if (nlhs > 2) {
    plhs[2] = j_emlrt_marshallOut(*MaxDis);
  }
  if (nlhs > 3) {
    distancesFianal->canFreeData = false;
    plhs[3] = b_emlrt_marshallOut(distancesFianal);
  }
  emxFree_real_T(&st, &distancesFianal);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void planefit_api(const mxArray *const prhs[4], int32_T nlhs,
                  const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *PlaneParaIn;
  emxArray_real_T *PlaneParaOut;
  emxArray_real_T *Points;
  emxArray_real_T *TrianglePoints;
  real_T(*BoundPoint1)[3];
  real_T(*BoundPoint2)[3];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Points);
  emxInit_real_T(&st, &PlaneParaIn);
  emxInit_real_T(&st, &PlaneParaOut);
  emxInit_real_T(&st, &TrianglePoints);
  /* Marshall function inputs */
  Points->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Points", Points);
  PlaneParaIn->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "PlaneParaIn", PlaneParaIn);
  BoundPoint1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "BoundPoint1");
  BoundPoint2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "BoundPoint2");
  /* Invoke the target function */
  planefit(Points, PlaneParaIn, *BoundPoint1, *BoundPoint2, PlaneParaOut,
           TrianglePoints);
  /* Marshall function outputs */
  PlaneParaOut->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(PlaneParaOut);
  emxFree_real_T(&st, &PlaneParaOut);
  emxFree_real_T(&st, &PlaneParaIn);
  emxFree_real_T(&st, &Points);
  if (nlhs > 1) {
    TrianglePoints->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(TrianglePoints);
  }
  emxFree_real_T(&st, &TrianglePoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_QuanZhanYi_api.c
 *
 * [EOF]
 */
