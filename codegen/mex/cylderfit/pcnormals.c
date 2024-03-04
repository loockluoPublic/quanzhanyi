/*
 * pcnormals.c
 *
 * Code generation for function 'pcnormals'
 *
 */

/* Include files */
#include "pcnormals.h"
#include "cylderfit_data.h"
#include "cylderfit_types.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = {
    78,          /* lineNo */
    "pcnormals", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\pcnormals.m" /* pathName
                                                                            */
};

static emlrtRSInfo db_emlrtRSI = {
    98,          /* lineNo */
    "pcnormals", /* fcnName */
    "E:\\SystemInstallation\\Matlab\\toolbox\\vision\\vision\\pcnormals.m" /* pathName
                                                                            */
};

/* Function Definitions */
void pcnormals(const emlrtStack *sp, pointCloud *ptCloud,
               emxArray_real_T *normals)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &eb_emlrtRSI;
  if (ptCloud->PointCloudArrayData->size[0] *
          ptCloud->PointCloudArrayData->size[1] !=
      1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedScalar",
        "MATLAB:pcnormals:expectedScalar", 3, 4, 7, "ptCloud");
  }
  st.site = &db_emlrtRSI;
  pointCloud_surfaceNormalImpl(&st, ptCloud, normals);
}

/* End of code generation (pcnormals.c) */
