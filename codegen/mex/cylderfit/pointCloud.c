/*
 * pointCloud.c
 *
 * Code generation for function 'pointCloud'
 *
 */

/* Include files */
#include "pointCloud.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "PCANormalCore_api.hpp"
#include "cvstCG_kdtree.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = {
    436,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    438,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    444,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    459,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    469,                            /* lineNo */
    "pointCloud/surfaceNormalImpl", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    811,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    829,                      /* lineNo */
    "pointCloud/buildKdtree", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    69,                            /* lineNo */
    13,                            /* colNo */
    "kdtreeBuildable/kdtreeIndex", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    439,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    811,          /* lineNo */
    110,          /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    450,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    460,          /* lineNo */
    47,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    151,               /* lineNo */
    38,                /* colNo */
    "kdtreeBuildable", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    152,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    153,               /* lineNo */
    36,                /* colNo */
    "kdtreeBuildable", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+buildable\\kdtreeBuildable.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    49,                   /* lineNo */
    17,                   /* colNo */
    "PCANormalBuildable", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\+buildable\\PCANormalBuildable.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    469,          /* lineNo */
    13,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    448,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    431,          /* lineNo */
    28,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    469,          /* lineNo */
    27,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

/* Function Definitions */
pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *varargin_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T b_nv_tmp_data;
  emxArray_real_T nv_tmp_data;
  emxArray_uint8_T r;
  pointCloud *b_this;
  int32_T iv[2];
  int32_T nv_tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_this = this;
  b_this->HasKdtreeConstructed = false;
  b_this->HasLocationHandleAllocated = false;
  st.site = &t_emlrtRSI;
  nv_tmp_size[0] = 0;
  nv_tmp_size[1] = 0;
  i = b_this->Location->size[0] * b_this->Location->size[1];
  b_this->Location->size[0] = varargin_1->size[0];
  b_this->Location->size[1] = 3;
  emxEnsureCapacity_real_T(&st, b_this->Location, i, &mb_emlrtRTEI);
  loop_ub = varargin_1->size[0] * 3;
  for (i = 0; i < loop_ub; i++) {
    b_this->Location->data[i] = varargin_1->data[i];
  }
  iv[0] = 0;
  iv[1] = 0;
  r.size = &iv[0];
  r.allocatedSize = 0;
  r.numDimensions = 2;
  r.canFreeData = false;
  b_st.site = &x_emlrtRSI;
  pointCloudBase_set_Color(&b_st, b_this, &r);
  nv_tmp_data.size = &nv_tmp_size[0];
  nv_tmp_data.allocatedSize = 0;
  nv_tmp_data.numDimensions = 2;
  nv_tmp_data.canFreeData = false;
  b_st.site = &y_emlrtRSI;
  pointCloudBase_set_Normal(&b_st, b_this, &nv_tmp_data);
  b_nv_tmp_data.size = &nv_tmp_size[0];
  b_nv_tmp_data.allocatedSize = 0;
  b_nv_tmp_data.numDimensions = 2;
  b_nv_tmp_data.canFreeData = false;
  b_st.site = &ab_emlrtRSI;
  pointCloudBase_set_Intensity(&b_st, b_this, &b_nv_tmp_data);
  st.site = &u_emlrtRSI;
  b_this->PointCloudArrayData->size[0] = 1;
  b_this->PointCloudArrayData->size[1] = 1;
  b_this->ZLimitsInternal->size[0] = 0;
  b_this->ZLimitsInternal->size[1] = 0;
  st.site = &v_emlrtRSI;
  b_this->Kdtree = NULL;
  b_this->LocationHandle = NULL;
  b_this->matlabCodegenIsDeleted = false;
  return b_this;
}

void pointCloud_surfaceNormalImpl(const emlrtStack *sp, pointCloud *this,
                                  emxArray_real_T *normals)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *a__8;
  emxArray_real_T *b_normals;
  emxArray_real_T *loc;
  emxArray_real_T *queryPoints;
  emxArray_uint32_T *indices;
  emxArray_uint32_T *valid;
  int32_T K;
  int32_T i;
  int32_T loop_ub;
  boolean_T createIndex;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &gb_emlrtRSI;
  K = (int32_T)muDoubleScalarMin(6.0, this->Location->size[0]);
  st.site = &hb_emlrtRSI;
  if (this->Location->size[0] <= 2) {
    loop_ub = this->Location->size[0];
    i = normals->size[0] * normals->size[1];
    normals->size[0] = loop_ub;
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(sp, normals, i, &qb_emlrtRTEI);
    loop_ub *= 3;
    for (i = 0; i < loop_ub; i++) {
      normals->data[i] = rtNaN;
    }
  } else {
    st.site = &ib_emlrtRSI;
    emxInit_real_T(&st, &loc, 2, &ac_emlrtRTEI, true);
    if (!this->HasLocationHandleAllocated) {
      b_st.site = &lb_emlrtRSI;
      i = loc->size[0] * loc->size[1];
      loc->size[0] = this->Location->size[0];
      loc->size[1] = 3;
      emxEnsureCapacity_real_T(&b_st, loc, i, &rb_emlrtRTEI);
      loop_ub = this->Location->size[0] * 3;
      for (i = 0; i < loop_ub; i++) {
        loc->data[i] = this->Location->data[i];
      }
      this->LocationHandle = NULL;
      if (loc->size[0] != 0) {
        kdtreeGetLocationDataPointer_double(
            &loc->data[0], (uint32_T)loc->size[0], 3U, &this->LocationHandle);
      }
      this->HasLocationHandleAllocated = true;
    }
    if (!this->HasKdtreeConstructed) {
      this->Kdtree = NULL;
      kdtreeConstruct_double(&this->Kdtree);
      this->HasKdtreeConstructed = true;
      createIndex = true;
    } else {
      createIndex =
          kdtreeNeedsReindex_double(this->Kdtree, this->LocationHandle);
    }
    if (createIndex) {
      b_st.site = &ob_emlrtRSI;
      loop_ub = this->Location->size[0];
      if (loop_ub == 0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                      "vision:ocvShared:emptyInput",
                                      "vision:ocvShared:emptyInput", 0);
      }
      if (loop_ub < 0) {
        loop_ub = 0;
      }
      kdtreeIndex_double(this->Kdtree, this->LocationHandle, (uint32_T)loop_ub,
                         3U, 4.0, 1.0, 0.0);
    }
    i = loc->size[0] * loc->size[1];
    loc->size[0] = this->Location->size[0];
    loc->size[1] = 3;
    emxEnsureCapacity_real_T(sp, loc, i, &sb_emlrtRTEI);
    loop_ub = this->Location->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      loc->data[i] = this->Location->data[i];
    }
    emxInit_real_T(sp, &queryPoints, 2, &tb_emlrtRTEI, true);
    st.site = &jb_emlrtRSI;
    i = queryPoints->size[0] * queryPoints->size[1];
    queryPoints->size[0] = loc->size[0];
    queryPoints->size[1] = 3;
    emxEnsureCapacity_real_T(&st, queryPoints, i, &tb_emlrtRTEI);
    loop_ub = loc->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      queryPoints->data[i] = loc->data[i];
    }
    emxInit_real_T(&st, &a__8, 2, &bc_emlrtRTEI, true);
    emxInit_uint32_T(&st, &indices, 2, &bc_emlrtRTEI, true);
    emxInit_uint32_T(&st, &valid, 1, &bc_emlrtRTEI, true);
    i = indices->size[0] * indices->size[1];
    indices->size[0] = K;
    indices->size[1] = loc->size[0];
    emxEnsureCapacity_uint32_T(&st, indices, i, &ub_emlrtRTEI);
    i = a__8->size[0] * a__8->size[1];
    a__8->size[0] = K;
    a__8->size[1] = loc->size[0];
    emxEnsureCapacity_real_T(&st, a__8, i, &vb_emlrtRTEI);
    i = valid->size[0];
    valid->size[0] = loc->size[0];
    emxEnsureCapacity_uint32_T(&st, valid, i, &wb_emlrtRTEI);
    if (K < 0) {
      K = 0;
    }
    emxInit_real_T(&st, &b_normals, 2, &cc_emlrtRTEI, true);
    kdtreeKNNSearch_double(this->Kdtree, &queryPoints->data[0],
                           (uint32_T)loc->size[0], 3U, (uint32_T)K, 0.0, 0.0,
                           &indices->data[0], &a__8->data[0], &valid->data[0],
                           2000, 500U);
    st.site = &kb_emlrtRSI;
    i = b_normals->size[0] * b_normals->size[1];
    b_normals->size[0] = loc->size[0];
    b_normals->size[1] = 3;
    emxEnsureCapacity_real_T(&st, b_normals, i, &xb_emlrtRTEI);
    PCANormalImpl_double(&loc->data[0], &indices->data[0], &valid->data[0],
                         (uint32_T)loc->size[0], (uint32_T)indices->size[0],
                         &b_normals->data[0]);
    i = normals->size[0] * normals->size[1];
    normals->size[0] = b_normals->size[0];
    normals->size[1] = 3;
    emxEnsureCapacity_real_T(sp, normals, i, &yb_emlrtRTEI);
    loop_ub = b_normals->size[0] * 3;
    emxFree_real_T(&queryPoints);
    emxFree_uint32_T(&valid);
    emxFree_uint32_T(&indices);
    emxFree_real_T(&a__8);
    emxFree_real_T(&loc);
    for (i = 0; i < loop_ub; i++) {
      normals->data[i] = b_normals->data[i];
    }
    emxFree_real_T(&b_normals);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (pointCloud.c) */
