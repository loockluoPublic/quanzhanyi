/*
 * pointCloudBase.c
 *
 * Code generation for function 'pointCloudBase'
 *
 */

/* Include files */
#include "pointCloudBase.h"
#include "cylderfit_data.h"
#include "cylderfit_emxutil.h"
#include "cylderfit_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = {
    175,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    871,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo gg_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo hg_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    185,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    867,                    /* lineNo */
    "minRealVectorOmitNaN", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo di_emlrtRSI = {
    237,                          /* lineNo */
    "pointCloudBase/get.ZLimits", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pathName */
};

static emlrtRSInfo ei_emlrtRSI = {
    787,                        /* lineNo */
    "pointCloud/computeLimits", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo fi_emlrtRSI = {
    788,                        /* lineNo */
    "pointCloud/computeLimits", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    789,                        /* lineNo */
    "pointCloud/computeLimits", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI =
    {
        15,    /* lineNo */
        "sum", /* fcnName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sum."
        "m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    138,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ji_emlrtRSI = {
    182,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    200,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\combineVectorElements.m" /* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    137,                        /* lineNo */
    13,                         /* colNo */
    "pointCloudBase/set.Color", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    151,                         /* lineNo */
    13,                          /* colNo */
    "pointCloudBase/set.Normal", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    174,                            /* lineNo */
    21,                             /* colNo */
    "pointCloudBase/set.Intensity", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    124,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    789,                        /* lineNo */
    49,                         /* colNo */
    "",                         /* aName */
    "pointCloud/computeLimits", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    789,                        /* lineNo */
    78,                         /* colNo */
    "",                         /* aName */
    "pointCloud/computeLimits", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    142,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    157,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    185,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    240,              /* lineNo */
    13,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI =
    {
        15,      /* lineNo */
        13,      /* colNo */
        "isnan", /* fName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\isnan."
        "m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    784,          /* lineNo */
    13,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    170,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "E:"
    "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private"
    "\\combineVectorElements.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    787,          /* lineNo */
    17,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    237,              /* lineNo */
    40,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    237,              /* lineNo */
    17,               /* colNo */
    "pointCloudBase", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\pointCloudBase.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    789,          /* lineNo */
    35,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    789,          /* lineNo */
    64,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    789,          /* lineNo */
    49,           /* colNo */
    "pointCloud", /* fName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\shared\\pointclouds\\+"
    "pointclouds\\+internal\\+codegen\\+pc\\pointCloud.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI =
    {
        15,    /* lineNo */
        9,     /* colNo */
        "sum", /* fName */
        "E:"
        "\\SystemInstallation\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\sum."
        "m" /* pName */
};

/* Function Definitions */
void pointCloudBase_get_ZLimits(const emlrtStack *sp, pointCloud *this,
                                emxArray_real_T *zlim)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *b_tf;
  emxArray_boolean_T *tf;
  emxArray_int32_T *nz;
  emxArray_int32_T *r;
  emxArray_real_T *varargin_1;
  real_T limits_data[2];
  real_T b_ex;
  real_T d;
  real_T ex;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T vstride;
  int32_T xoffset;
  boolean_T exitg1;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if ((this->ZLimitsInternal->size[0] == 0) ||
      (this->ZLimitsInternal->size[1] == 0)) {
    emxInit_boolean_T(sp, &tf, 2, &sd_emlrtRTEI, true);
    st.site = &di_emlrtRSI;
    i = tf->size[0] * tf->size[1];
    tf->size[0] = this->Location->size[0];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(&st, tf, i, &rd_emlrtRTEI);
    xoffset = this->Location->size[0] * 3;
    for (i = 0; i < xoffset; i++) {
      tf->data[i] = muDoubleScalarIsNaN(this->Location->data[i]);
    }
    xoffset = tf->size[0] * 3;
    i = tf->size[0] * tf->size[1];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(&st, tf, i, &sd_emlrtRTEI);
    for (i = 0; i < xoffset; i++) {
      tf->data[i] = !tf->data[i];
    }
    b_st.site = &ei_emlrtRSI;
    c_st.site = &hi_emlrtRSI;
    d_st.site = &me_emlrtRSI;
    emxInit_int32_T(&d_st, &nz, 1, &be_emlrtRTEI, true);
    if (tf->size[0] == 0) {
      nz->size[0] = 0;
    } else {
      e_st.site = &ii_emlrtRSI;
      vstride = tf->size[0];
      i = nz->size[0];
      nz->size[0] = tf->size[0];
      emxEnsureCapacity_int32_T(&e_st, nz, i, &td_emlrtRTEI);
      f_st.site = &ji_emlrtRSI;
      if (tf->size[0] > 2147483646) {
        g_st.site = &nc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      for (j = 0; j < vstride; j++) {
        nz->data[j] = tf->data[j];
      }
      for (k = 0; k < 2; k++) {
        xoffset = (k + 1) * vstride;
        f_st.site = &ki_emlrtRSI;
        for (j = 0; j < vstride; j++) {
          nz->data[j] += tf->data[xoffset + j];
        }
      }
    }
    emxFree_boolean_T(&tf);
    emxInit_boolean_T(&d_st, &b_tf, 1, &sd_emlrtRTEI, true);
    i = b_tf->size[0];
    b_tf->size[0] = nz->size[0];
    emxEnsureCapacity_boolean_T(&st, b_tf, i, &ud_emlrtRTEI);
    xoffset = nz->size[0];
    for (i = 0; i < xoffset; i++) {
      b_tf->data[i] = (nz->data[i] == 3);
    }
    emxFree_int32_T(&nz);
    xoffset = 0;
    i = b_tf->size[0];
    for (k = 0; k < i; k++) {
      if (b_tf->data[k]) {
        xoffset++;
      }
    }
    b_st.site = &fi_emlrtRSI;
    if (xoffset != 0) {
      j = b_tf->size[0] - 1;
      vstride = 0;
      for (i = 0; i <= j; i++) {
        if (b_tf->data[i]) {
          vstride++;
        }
      }
      emxInit_int32_T(&st, &r, 1, &ae_emlrtRTEI, true);
      i = r->size[0];
      r->size[0] = vstride;
      emxEnsureCapacity_int32_T(&st, r, i, &vd_emlrtRTEI);
      xoffset = 0;
      for (i = 0; i <= j; i++) {
        if (b_tf->data[i]) {
          r->data[xoffset] = i + 1;
          xoffset++;
        }
      }
      emxInit_real_T(&st, &varargin_1, 1, &xd_emlrtRTEI, true);
      b_st.site = &gi_emlrtRSI;
      vstride = this->Location->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = r->size[0];
      emxEnsureCapacity_real_T(&b_st, varargin_1, i, &xd_emlrtRTEI);
      xoffset = r->size[0];
      for (i = 0; i < xoffset; i++) {
        if (r->data[i] > vstride) {
          emlrtDynamicBoundsCheckR2012b(r->data[i], 1, vstride, &rc_emlrtBCI,
                                        &b_st);
        }
        varargin_1->data[i] =
            this->Location
                ->data[(r->data[i] + this->Location->size[0] * 2) - 1];
      }
      c_st.site = &kg_emlrtRSI;
      d_st.site = &lg_emlrtRSI;
      e_st.site = &mg_emlrtRSI;
      if (varargin_1->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &v_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      f_st.site = &ng_emlrtRSI;
      g_st.site = &og_emlrtRSI;
      xoffset = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          ex = varargin_1->data[0];
        } else if ((varargin_1->data[0] > varargin_1->data[1]) ||
                   (muDoubleScalarIsNaN(varargin_1->data[0]) &&
                    (!muDoubleScalarIsNaN(varargin_1->data[1])))) {
          ex = varargin_1->data[1];
        } else {
          ex = varargin_1->data[0];
        }
      } else {
        h_st.site = &ig_emlrtRSI;
        if (!muDoubleScalarIsNaN(varargin_1->data[0])) {
          vstride = 1;
        } else {
          vstride = 0;
          i_st.site = &jg_emlrtRSI;
          if (varargin_1->size[0] > 2147483646) {
            j_st.site = &nc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= xoffset)) {
            if (!muDoubleScalarIsNaN(varargin_1->data[k - 1])) {
              vstride = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (vstride == 0) {
          ex = varargin_1->data[0];
        } else {
          h_st.site = &gg_emlrtRSI;
          ex = varargin_1->data[vstride - 1];
          j = vstride + 1;
          i_st.site = &hg_emlrtRSI;
          if ((vstride + 1 <= varargin_1->size[0]) &&
              (varargin_1->size[0] > 2147483646)) {
            j_st.site = &nc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }
          for (k = j; k <= xoffset; k++) {
            d = varargin_1->data[k - 1];
            if (ex > d) {
              ex = d;
            }
          }
        }
      }
      b_st.site = &gi_emlrtRSI;
      vstride = this->Location->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = r->size[0];
      emxEnsureCapacity_real_T(&b_st, varargin_1, i, &yd_emlrtRTEI);
      xoffset = r->size[0];
      for (i = 0; i < xoffset; i++) {
        if (r->data[i] > vstride) {
          emlrtDynamicBoundsCheckR2012b(r->data[i], 1, vstride, &sc_emlrtBCI,
                                        &b_st);
        }
        varargin_1->data[i] =
            this->Location
                ->data[(r->data[i] + this->Location->size[0] * 2) - 1];
      }
      emxFree_int32_T(&r);
      c_st.site = &bg_emlrtRSI;
      d_st.site = &cg_emlrtRSI;
      e_st.site = &dg_emlrtRSI;
      if (varargin_1->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &v_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      f_st.site = &eg_emlrtRSI;
      g_st.site = &fg_emlrtRSI;
      xoffset = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          b_ex = varargin_1->data[0];
        } else if ((varargin_1->data[0] < varargin_1->data[1]) ||
                   (muDoubleScalarIsNaN(varargin_1->data[0]) &&
                    (!muDoubleScalarIsNaN(varargin_1->data[1])))) {
          b_ex = varargin_1->data[1];
        } else {
          b_ex = varargin_1->data[0];
        }
      } else {
        h_st.site = &ig_emlrtRSI;
        if (!muDoubleScalarIsNaN(varargin_1->data[0])) {
          vstride = 1;
        } else {
          vstride = 0;
          i_st.site = &jg_emlrtRSI;
          if (varargin_1->size[0] > 2147483646) {
            j_st.site = &nc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= xoffset)) {
            if (!muDoubleScalarIsNaN(varargin_1->data[k - 1])) {
              vstride = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (vstride == 0) {
          b_ex = varargin_1->data[0];
        } else {
          h_st.site = &gg_emlrtRSI;
          b_ex = varargin_1->data[vstride - 1];
          j = vstride + 1;
          i_st.site = &hg_emlrtRSI;
          if ((vstride + 1 <= varargin_1->size[0]) &&
              (varargin_1->size[0] > 2147483646)) {
            j_st.site = &nc_emlrtRSI;
            check_forloop_overflow_error(&j_st);
          }
          for (k = j; k <= xoffset; k++) {
            d = varargin_1->data[k - 1];
            if (b_ex < d) {
              b_ex = d;
            }
          }
        }
      }
      emxFree_real_T(&varargin_1);
      xoffset = 1;
      limits_data[0] = ex;
      limits_data[1] = b_ex;
    } else {
      xoffset = 0;
    }
    emxFree_boolean_T(&b_tf);
    i = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
    this->ZLimitsInternal->size[0] = xoffset;
    this->ZLimitsInternal->size[1] = 2;
    emxEnsureCapacity_real_T(sp, this->ZLimitsInternal, i, &wd_emlrtRTEI);
    xoffset *= 2;
    for (i = 0; i < xoffset; i++) {
      this->ZLimitsInternal->data[i] = limits_data[i];
    }
  }
  i = zlim->size[0] * zlim->size[1];
  zlim->size[0] = this->ZLimitsInternal->size[0];
  zlim->size[1] = this->ZLimitsInternal->size[1];
  emxEnsureCapacity_real_T(sp, zlim, i, &qd_emlrtRTEI);
  xoffset = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
  for (i = 0; i < xoffset; i++) {
    zlim->data[i] = this->ZLimitsInternal->data[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                              const emxArray_uint8_T *value)
{
  int32_T varargin_2[2];
  int32_T i;
  int32_T k;
  uint32_T varargin_1[2];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if ((value->size[0] != 0) && (value->size[1] != 0)) {
    varargin_1[0] = (uint32_T)value->size[0];
    varargin_2[0] = this->Location->size[0];
    varargin_1[1] = (uint32_T)value->size[1];
    varargin_2[1] = 3;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if ((int32_T)varargin_1[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    b_p = (int32_T)p;
    if (!b_p) {
      emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZColor",
                                    "vision:pointcloud:unmatchedXYZColor", 0);
    }
  }
  i = this->Color->size[0] * this->Color->size[1];
  this->Color->size[0] = value->size[0];
  this->Color->size[1] = value->size[1];
  emxEnsureCapacity_uint8_T(sp, this->Color, i, &nb_emlrtRTEI);
  k = value->size[0] * value->size[1];
  for (i = 0; i < k; i++) {
    this->Color->data[i] = value->data[i];
  }
}

void pointCloudBase_set_Intensity(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *value)
{
  int32_T i;
  int32_T loop_ub;
  if ((value->size[0] != 0) && (value->size[1] != 0) &&
      ((value->size[1] != 1) || (value->size[0] != this->Location->size[0]))) {
    emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
                                  "vision:pointcloud:unmatchedXYZIntensity",
                                  "vision:pointcloud:unmatchedXYZIntensity", 0);
  }
  i = this->Intensity->size[0] * this->Intensity->size[1];
  this->Intensity->size[0] = value->size[0];
  this->Intensity->size[1] = value->size[1];
  emxEnsureCapacity_real_T(sp, this->Intensity, i, &pb_emlrtRTEI);
  loop_ub = value->size[0] * value->size[1];
  for (i = 0; i < loop_ub; i++) {
    this->Intensity->data[i] = value->data[i];
  }
}

void pointCloudBase_set_Normal(const emlrtStack *sp, pointCloud *this,
                               const emxArray_real_T *value)
{
  int32_T varargin_2[2];
  int32_T i;
  int32_T k;
  uint32_T varargin_1[2];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  if ((value->size[0] != 0) && (value->size[1] != 0)) {
    varargin_1[0] = (uint32_T)value->size[0];
    varargin_2[0] = this->Location->size[0];
    varargin_1[1] = (uint32_T)value->size[1];
    varargin_2[1] = 3;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if ((int32_T)varargin_1[k] != varargin_2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    b_p = (int32_T)p;
    if (!b_p) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
                                    "vision:pointcloud:unmatchedXYZNormal",
                                    "vision:pointcloud:unmatchedXYZNormal", 0);
    }
  }
  i = this->Normal->size[0] * this->Normal->size[1];
  this->Normal->size[0] = value->size[0];
  this->Normal->size[1] = value->size[1];
  emxEnsureCapacity_real_T(sp, this->Normal, i, &ob_emlrtRTEI);
  k = value->size[0] * value->size[1];
  for (i = 0; i < k; i++) {
    this->Normal->data[i] = value->data[i];
  }
}

/* End of code generation (pointCloudBase.c) */
