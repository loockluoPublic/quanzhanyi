/*
 * File: pointCloudBase.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

/* Include Files */
#include "pointCloudBase.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : pointCloud *this
 *                emxArray_real_T *zlim
 * Return Type  : void
 */
void pointCloudBase_get_ZLimits(pointCloud *this, emxArray_real_T *zlim)
{
  emxArray_boolean_T *b_tf;
  emxArray_boolean_T *tf;
  emxArray_int32_T *nz;
  emxArray_int32_T *r;
  emxArray_real_T *varargin_1;
  double limits_data[2];
  double b_ex;
  double d;
  double ex;
  int j;
  int k;
  int vstride;
  int xoffset;
  boolean_T exitg1;
  if ((this->ZLimitsInternal->size[0] == 0) ||
      (this->ZLimitsInternal->size[1] == 0)) {
    emxInit_boolean_T(&tf, 2);
    j = tf->size[0] * tf->size[1];
    tf->size[0] = this->Location->size[0];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(tf, j);
    xoffset = this->Location->size[0] * 3;
    for (j = 0; j < xoffset; j++) {
      tf->data[j] = rtIsNaN(this->Location->data[j]);
    }
    xoffset = tf->size[0] * 3;
    j = tf->size[0] * tf->size[1];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(tf, j);
    for (j = 0; j < xoffset; j++) {
      tf->data[j] = !tf->data[j];
    }
    emxInit_int32_T(&nz, 1);
    if (tf->size[0] == 0) {
      nz->size[0] = 0;
    } else {
      vstride = tf->size[0];
      j = nz->size[0];
      nz->size[0] = tf->size[0];
      emxEnsureCapacity_int32_T(nz, j);
      for (j = 0; j < vstride; j++) {
        nz->data[j] = tf->data[j];
      }
      for (k = 0; k < 2; k++) {
        xoffset = (k + 1) * vstride;
        for (j = 0; j < vstride; j++) {
          nz->data[j] += tf->data[xoffset + j];
        }
      }
    }
    emxFree_boolean_T(&tf);
    emxInit_boolean_T(&b_tf, 1);
    j = b_tf->size[0];
    b_tf->size[0] = nz->size[0];
    emxEnsureCapacity_boolean_T(b_tf, j);
    xoffset = nz->size[0];
    for (j = 0; j < xoffset; j++) {
      b_tf->data[j] = (nz->data[j] == 3);
    }
    emxFree_int32_T(&nz);
    xoffset = 0;
    j = b_tf->size[0];
    for (k = 0; k < j; k++) {
      if (b_tf->data[k]) {
        xoffset++;
      }
    }
    if (xoffset != 0) {
      vstride = b_tf->size[0] - 1;
      xoffset = 0;
      for (j = 0; j <= vstride; j++) {
        if (b_tf->data[j]) {
          xoffset++;
        }
      }
      emxInit_int32_T(&r, 1);
      j = r->size[0];
      r->size[0] = xoffset;
      emxEnsureCapacity_int32_T(r, j);
      xoffset = 0;
      for (j = 0; j <= vstride; j++) {
        if (b_tf->data[j]) {
          r->data[xoffset] = j + 1;
          xoffset++;
        }
      }
      emxInit_real_T(&varargin_1, 1);
      j = varargin_1->size[0];
      varargin_1->size[0] = r->size[0];
      emxEnsureCapacity_real_T(varargin_1, j);
      xoffset = r->size[0];
      for (j = 0; j < xoffset; j++) {
        varargin_1->data[j] =
            this->Location
                ->data[(r->data[j] + this->Location->size[0] * 2) - 1];
      }
      vstride = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          ex = varargin_1->data[0];
        } else if ((varargin_1->data[0] >
                    varargin_1->data[varargin_1->size[0] - 1]) ||
                   (rtIsNaN(varargin_1->data[0]) &&
                    (!rtIsNaN(varargin_1->data[varargin_1->size[0] - 1])))) {
          ex = varargin_1->data[varargin_1->size[0] - 1];
        } else {
          ex = varargin_1->data[0];
        }
      } else {
        if (!rtIsNaN(varargin_1->data[0])) {
          xoffset = 1;
        } else {
          xoffset = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= vstride)) {
            if (!rtIsNaN(varargin_1->data[k - 1])) {
              xoffset = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (xoffset == 0) {
          ex = varargin_1->data[0];
        } else {
          ex = varargin_1->data[xoffset - 1];
          j = xoffset + 1;
          for (k = j; k <= vstride; k++) {
            d = varargin_1->data[k - 1];
            if (ex > d) {
              ex = d;
            }
          }
        }
      }
      j = varargin_1->size[0];
      varargin_1->size[0] = r->size[0];
      emxEnsureCapacity_real_T(varargin_1, j);
      xoffset = r->size[0];
      for (j = 0; j < xoffset; j++) {
        varargin_1->data[j] =
            this->Location
                ->data[(r->data[j] + this->Location->size[0] * 2) - 1];
      }
      emxFree_int32_T(&r);
      vstride = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          b_ex = varargin_1->data[0];
        } else if ((varargin_1->data[0] <
                    varargin_1->data[varargin_1->size[0] - 1]) ||
                   (rtIsNaN(varargin_1->data[0]) &&
                    (!rtIsNaN(varargin_1->data[varargin_1->size[0] - 1])))) {
          b_ex = varargin_1->data[varargin_1->size[0] - 1];
        } else {
          b_ex = varargin_1->data[0];
        }
      } else {
        if (!rtIsNaN(varargin_1->data[0])) {
          xoffset = 1;
        } else {
          xoffset = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= vstride)) {
            if (!rtIsNaN(varargin_1->data[k - 1])) {
              xoffset = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (xoffset == 0) {
          b_ex = varargin_1->data[0];
        } else {
          b_ex = varargin_1->data[xoffset - 1];
          j = xoffset + 1;
          for (k = j; k <= vstride; k++) {
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
    j = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
    this->ZLimitsInternal->size[0] = xoffset;
    this->ZLimitsInternal->size[1] = 2;
    emxEnsureCapacity_real_T(this->ZLimitsInternal, j);
    xoffset *= 2;
    for (j = 0; j < xoffset; j++) {
      this->ZLimitsInternal->data[j] = limits_data[j];
    }
  }
  j = zlim->size[0] * zlim->size[1];
  zlim->size[0] = this->ZLimitsInternal->size[0];
  zlim->size[1] = this->ZLimitsInternal->size[1];
  emxEnsureCapacity_real_T(zlim, j);
  xoffset = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
  for (j = 0; j < xoffset; j++) {
    zlim->data[j] = this->ZLimitsInternal->data[j];
  }
}

/*
 * File trailer for pointCloudBase.c
 *
 * [EOF]
 */
