/*
 * cylderfit_initialize.c
 *
 * Code generation for function 'cylderfit_initialize'
 *
 */

/* Include files */
#include "cylderfit_initialize.h"
#include "_coder_cylderfit_mex.h"
#include "cylderfit_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void cylderfit_once(void);

/* Function Definitions */
static void cylderfit_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\XWT\\Desktop\\cylderfit.m", 0U, 1U, 5U, 1U, 0U,
                  0U, 0U, 1U, 1U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "cylderfit", 0, -1, 2786);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2667, -1, 2781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 2557, -1, 2562);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 2243, -1, 2498);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1404, -1, 2205);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 63, -1, 1354);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 2530, 2544, 2582, 2583);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1382, 1391, 2217);
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 0U, 0U, 1359, 1373, 2583);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void cylderfit_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"image_toolbox", 2);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"video_and_image_blockset", 2);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"statistics_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    cylderfit_once();
  }
}

/* End of code generation (cylderfit_initialize.c) */
