/*
 * pctransform.c
 *
 * Code generation for function 'pctransform'
 *
 */

/* Include files */
#include "pctransform.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "handle.h"
#include "isRigidTransform.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    75,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    90,                              /* lineNo */
    "pointCloudBase/pointCloudBase", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    10,               /* lineNo */
    "validatescalar", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatescalar.m" /* pathName */
};

static emlrtRSInfo
    ch_emlrtRSI =
        {
            58,            /* lineNo */
            "pctransform", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\pctransform"
            ".m" /* pathName */
};

static emlrtRSInfo
    dh_emlrtRSI =
        {
            85,            /* lineNo */
            "pctransform", /* fcnName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\pctransform"
            ".m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    15,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    41,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    43,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    49,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    53,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    55,          /* lineNo */
    "transform", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    142,      /* lineNo */
    "mtimes", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    178,           /* lineNo */
    "mtimes_blas", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pathName */
};

static emlrtECInfo e_emlrtECI = {
    -1,          /* nDims */
    16,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    -1,          /* nDims */
    17,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    -1,          /* nDims */
    18,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    15,          /* lineNo */
    11,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    16,          /* lineNo */
    16,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    17,          /* lineNo */
    16,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    218,      /* lineNo */
    20,       /* colNo */
    "mtimes", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    18,          /* lineNo */
    16,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    53,          /* lineNo */
    39,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    49,          /* lineNo */
    9,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    43,          /* lineNo */
    18,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    54,          /* lineNo */
    18,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    43,          /* lineNo */
    13,          /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo
    kd_emlrtRTEI =
        {
            1,             /* lineNo */
            23,            /* colNo */
            "pctransform", /* fName */
            "E:"
            "\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\pctransform"
            ".m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    15,          /* lineNo */
    5,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    39,          /* lineNo */
    1,           /* colNo */
    "transform", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+pc\\transform.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    1043,         /* lineNo */
    13,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    1056,         /* lineNo */
    13,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

/* Function Definitions */
pointCloud *pctransform(const emlrtStack *sp, const pointCloud *ptCloudIn,
                        const real_T tform_AffineTform_T[16],
                        pointCloud *iobj_0)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *a;
  emxArray_real_T *b_loc;
  emxArray_real_T *loc;
  emxArray_real_T *nv;
  emxArray_real_T *tempI;
  emxArray_uint8_T *C_;
  pointCloud lobj_0;
  pointCloud *ptCloudOut;
  real_T R[9];
  real_T alpha1;
  real_T beta1;
  int32_T R_tmp;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b;
  boolean_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInitStruct_pointCloud(sp, &lobj_0, &kd_emlrtRTEI, true);
  st.site = &ch_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  n = (ptCloudIn->PointCloudArrayData->size[0] *
           ptCloudIn->PointCloudArrayData->size[1] ==
       1);
  if (!n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pctransform:expectedScalar", 3, 4, 9, "ptCloudIn");
  }
  st.site = &dh_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, &lobj_0,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  lobj_0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 3; i++) {
    R_tmp = i << 2;
    R[3 * i] = tform_AffineTform_T[R_tmp];
    R[3 * i + 1] = tform_AffineTform_T[R_tmp + 1];
    R[3 * i + 2] = tform_AffineTform_T[R_tmp + 2];
  }
  emxInit_real_T(&st, &a, 2, &ad_emlrtRTEI, true);
  b_st.site = &eh_emlrtRSI;
  i = a->size[0] * a->size[1];
  a->size[0] = ptCloudIn->Location->size[0];
  a->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, a, i, &ad_emlrtRTEI);
  R_tmp = ptCloudIn->Location->size[0] * 3;
  for (i = 0; i < R_tmp; i++) {
    a->data[i] = ptCloudIn->Location->data[i];
  }
  c_st.site = &kh_emlrtRSI;
  emxInit_real_T(&c_st, &loc, 2, &ld_emlrtRTEI, true);
  if (a->size[0] == 0) {
    loc->size[0] = 0;
    loc->size[1] = 3;
  } else {
    d_st.site = &lh_emlrtRSI;
    e_st.site = &mh_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)a->size[0];
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)a->size[0];
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)a->size[0];
    i = loc->size[0] * loc->size[1];
    loc->size[0] = a->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(&e_st, loc, i, &dd_emlrtRTEI);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &a->data[0], &lda_t,
          &R[0], &ldb_t, &beta1, &loc->data[0], &ldc_t);
  }
  emxInit_real_T(&c_st, &b_loc, 1, &bd_emlrtRTEI, true);
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &e_emlrtECI,
                                &st);
  R_tmp = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(&st, b_loc, i, &bd_emlrtRTEI);
  for (i = 0; i <= R_tmp; i++) {
    b_loc->data[i] = loc->data[i] + tform_AffineTform_T[3];
  }
  R_tmp = b_loc->size[0];
  for (i = 0; i < R_tmp; i++) {
    loc->data[i] = b_loc->data[i];
  }
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &f_emlrtECI,
                                &st);
  R_tmp = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(&st, b_loc, i, &cd_emlrtRTEI);
  for (i = 0; i <= R_tmp; i++) {
    b_loc->data[i] = loc->data[i + loc->size[0]] + tform_AffineTform_T[7];
  }
  R_tmp = b_loc->size[0];
  for (i = 0; i < R_tmp; i++) {
    loc->data[i + loc->size[0]] = b_loc->data[i];
  }
  emlrtSubAssignSizeCheckR2012b(&loc->size[0], 1, &loc->size[0], 1, &g_emlrtECI,
                                &st);
  R_tmp = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(&st, b_loc, i, &ed_emlrtRTEI);
  for (i = 0; i <= R_tmp; i++) {
    b_loc->data[i] = loc->data[i + loc->size[0] * 2] + tform_AffineTform_T[11];
  }
  R_tmp = b_loc->size[0];
  for (i = 0; i < R_tmp; i++) {
    loc->data[i + loc->size[0] * 2] = b_loc->data[i];
  }
  emxFree_real_T(&b_loc);
  emxInit_real_T(&st, &nv, 2, &md_emlrtRTEI, true);
  nv->size[0] = 0;
  nv->size[1] = 0;
  n = (ptCloudIn->Normal->size[0] == 0);
  b = (ptCloudIn->Normal->size[1] == 0);
  emxInit_real_T(&st, &tempI, 2, &od_emlrtRTEI, true);
  if ((!n) && (!b)) {
    b_st.site = &fh_emlrtRSI;
    if (isRigidTransform(&b_st, tform_AffineTform_T)) {
      b_st.site = &gh_emlrtRSI;
      i = tempI->size[0] * tempI->size[1];
      tempI->size[0] = ptCloudIn->Normal->size[0];
      tempI->size[1] = ptCloudIn->Normal->size[1];
      emxEnsureCapacity_real_T(&b_st, tempI, i, &hd_emlrtRTEI);
      R_tmp = ptCloudIn->Normal->size[0] * ptCloudIn->Normal->size[1];
      for (i = 0; i < R_tmp; i++) {
        tempI->data[i] = ptCloudIn->Normal->data[i];
      }
      c_st.site = &qh_emlrtRSI;
      if (tempI->size[1] != 3) {
        if ((tempI->size[0] == 1) && (tempI->size[1] == 1)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &u_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &t_emlrtRTEI, "MATLAB:innerdim",
                                        "MATLAB:innerdim", 0);
        }
      }
      c_st.site = &kh_emlrtRSI;
      if (tempI->size[0] == 0) {
        a->size[0] = 0;
        a->size[1] = 3;
      } else {
        d_st.site = &lh_emlrtRSI;
        e_st.site = &mh_emlrtRSI;
        TRANSB1 = 'N';
        TRANSA1 = 'N';
        alpha1 = 1.0;
        beta1 = 0.0;
        m_t = (ptrdiff_t)tempI->size[0];
        n_t = (ptrdiff_t)3;
        k_t = (ptrdiff_t)3;
        lda_t = (ptrdiff_t)tempI->size[0];
        ldb_t = (ptrdiff_t)3;
        ldc_t = (ptrdiff_t)tempI->size[0];
        i = a->size[0] * a->size[1];
        a->size[0] = tempI->size[0];
        a->size[1] = 3;
        emxEnsureCapacity_real_T(&e_st, a, i, &dd_emlrtRTEI);
        dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &tempI->data[0],
              &lda_t, &R[0], &ldb_t, &beta1, &a->data[0], &ldc_t);
      }
      i = nv->size[0] * nv->size[1];
      nv->size[0] = a->size[0];
      nv->size[1] = 3;
      emxEnsureCapacity_real_T(&st, nv, i, &jd_emlrtRTEI);
      R_tmp = a->size[0] * 3;
      for (i = 0; i < R_tmp; i++) {
        nv->data[i] = a->data[i];
      }
    } else {
      b_st.site = &hh_emlrtRSI;
      pointCloud_surfaceNormalImpl(
          &b_st, pointCloud_pointCloud(&b_st, &lobj_0, loc), a);
      i = nv->size[0] * nv->size[1];
      nv->size[0] = a->size[0];
      nv->size[1] = 3;
      emxEnsureCapacity_real_T(&st, nv, i, &gd_emlrtRTEI);
      R_tmp = a->size[0] * 3;
      for (i = 0; i < R_tmp; i++) {
        nv->data[i] = a->data[i];
      }
    }
  }
  emxFree_real_T(&a);
  emxInit_uint8_T(&st, &C_, 2, &nd_emlrtRTEI, true);
  b_st.site = &ih_emlrtRSI;
  i = C_->size[0] * C_->size[1];
  C_->size[0] = ptCloudIn->Color->size[0];
  C_->size[1] = ptCloudIn->Color->size[1];
  emxEnsureCapacity_uint8_T(&b_st, C_, i, &fd_emlrtRTEI);
  R_tmp = ptCloudIn->Color->size[0] * ptCloudIn->Color->size[1];
  for (i = 0; i < R_tmp; i++) {
    C_->data[i] = ptCloudIn->Color->data[i];
  }
  i = tempI->size[0] * tempI->size[1];
  tempI->size[0] = ptCloudIn->Intensity->size[0];
  tempI->size[1] = ptCloudIn->Intensity->size[1];
  emxEnsureCapacity_real_T(&b_st, tempI, i, &id_emlrtRTEI);
  R_tmp = ptCloudIn->Intensity->size[0] * ptCloudIn->Intensity->size[1];
  for (i = 0; i < R_tmp; i++) {
    tempI->data[i] = ptCloudIn->Intensity->data[i];
  }
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  c_st.site = &t_emlrtRSI;
  d_st.site = &w_emlrtRSI;
  ptCloudOut = iobj_0;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1];
  iobj_0->Location->size[0] = loc->size[0];
  iobj_0->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&c_st, iobj_0->Location, i, &mb_emlrtRTEI);
  R_tmp = loc->size[0] * 3;
  for (i = 0; i < R_tmp; i++) {
    iobj_0->Location->data[i] = loc->data[i];
  }
  emxFree_real_T(&loc);
  d_st.site = &x_emlrtRSI;
  pointCloudBase_set_Color(&d_st, iobj_0, C_);
  d_st.site = &y_emlrtRSI;
  pointCloudBase_set_Normal(&d_st, iobj_0, nv);
  d_st.site = &ab_emlrtRSI;
  pointCloudBase_set_Intensity(&d_st, iobj_0, tempI);
  d_st.site = &bb_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  iobj_0->PointCloudArrayData->size[0] = 1;
  iobj_0->PointCloudArrayData->size[1] = 1;
  iobj_0->ZLimitsInternal->size[0] = 0;
  iobj_0->ZLimitsInternal->size[1] = 0;
  c_st.site = &v_emlrtRSI;
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  b_st.site = &jh_emlrtRSI;
  handle_matlabCodegenDestructor(&b_st, &lobj_0);
  emxFreeStruct_pointCloud(&lobj_0);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
  emxFree_real_T(&tempI);
  emxFree_uint8_T(&C_);
  emxFree_real_T(&nv);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return ptCloudOut;
}

/* End of code generation (pctransform.c) */
