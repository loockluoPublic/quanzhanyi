/*
 * _coder_cylderfit_api.c
 *
 * Code generation for function '_coder_cylderfit_api'
 *
 */

/* Include files */
#include "_coder_cylderfit_api.h"
#include "cylderfit.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ce_emlrtRTEI = {
    1,                      /* lineNo */
    1,                      /* colNo */
    "_coder_cylderfit_api", /* fName */
    ""                      /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void cylderfit_api(const mxArray *const prhs[3], int32_T nlhs,
                   const mxArray *plhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *z;
  real_T xn1;
  real_T xn2;
  real_T xn3;
  real_T xn4;
  real_T xn5;
  real_T xn6;
  real_T xn7;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &x, 1, &ce_emlrtRTEI, true);
  emxInit_real_T(&st, &y, 1, &ce_emlrtRTEI, true);
  emxInit_real_T(&st, &z, 1, &ce_emlrtRTEI, true);
  /* Marshall function inputs */
  x->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
  y->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y", y);
  z->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "z", z);
  /* Invoke the target function */
  cylderfit(&st, x, y, z, &xn1, &xn2, &xn3, &xn4, &xn5, &xn6, &xn7);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(xn1);
  emxFree_real_T(&z);
  emxFree_real_T(&y);
  emxFree_real_T(&x);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(xn2);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(xn3);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(xn4);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(xn5);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(xn6);
  }
  if (nlhs > 6) {
    plhs[6] = emlrt_marshallOut(xn7);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_cylderfit_api.c) */
