/*
 * File: pointCloudBase.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
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
  double b_ex;
  double d;
  double ex;
  double *zlim_data;
  int j;
  int k;
  int vstride;
  int xoffset;
  int *nz_data;
  boolean_T exitg1;
  boolean_T *tf_data;
  if ((this->ZLimitsInternal->size[0] == 0) ||
      (this->ZLimitsInternal->size[1] == 0)) {
    emxInit_boolean_T(&tf, 2);
    j = tf->size[0] * tf->size[1];
    tf->size[0] = this->Location->size[0];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(tf, j);
    tf_data = tf->data;
    xoffset = this->Location->size[0] * 3;
    for (j = 0; j < xoffset; j++) {
      tf_data[j] = rtIsNaN(this->Location->data[j]);
    }
    xoffset = tf->size[0] * 3;
    j = tf->size[0] * tf->size[1];
    tf->size[1] = 3;
    emxEnsureCapacity_boolean_T(tf, j);
    tf_data = tf->data;
    for (j = 0; j < xoffset; j++) {
      tf_data[j] = !tf_data[j];
    }
    emxInit_int32_T(&nz);
    nz_data = nz->data;
    if (tf->size[0] == 0) {
      nz->size[0] = 0;
    } else {
      vstride = tf->size[0];
      j = nz->size[0];
      nz->size[0] = tf->size[0];
      emxEnsureCapacity_int32_T(nz, j);
      nz_data = nz->data;
      for (j = 0; j < vstride; j++) {
        nz_data[j] = tf_data[j];
      }
      for (k = 0; k < 2; k++) {
        xoffset = (k + 1) * vstride;
        for (j = 0; j < vstride; j++) {
          nz_data[j] += tf_data[xoffset + j];
        }
      }
    }
    emxFree_boolean_T(&tf);
    emxInit_boolean_T(&b_tf, 1);
    j = b_tf->size[0];
    b_tf->size[0] = nz->size[0];
    emxEnsureCapacity_boolean_T(b_tf, j);
    tf_data = b_tf->data;
    xoffset = nz->size[0];
    for (j = 0; j < xoffset; j++) {
      tf_data[j] = (nz_data[j] == 3);
    }
    emxFree_int32_T(&nz);
    xoffset = 0;
    j = b_tf->size[0];
    for (k = 0; k < j; k++) {
      if (tf_data[k]) {
        xoffset++;
      }
    }
    if (xoffset != 0) {
      vstride = b_tf->size[0] - 1;
      xoffset = 0;
      for (j = 0; j <= vstride; j++) {
        if (tf_data[j]) {
          xoffset++;
        }
      }
      emxInit_int32_T(&r);
      j = r->size[0];
      r->size[0] = xoffset;
      emxEnsureCapacity_int32_T(r, j);
      nz_data = r->data;
      xoffset = 0;
      for (j = 0; j <= vstride; j++) {
        if (tf_data[j]) {
          nz_data[xoffset] = j + 1;
          xoffset++;
        }
      }
      vstride = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          ex = this->Location
                   ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
        } else {
          ex = this->Location
                   ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
          if ((ex > this->Location->data[(nz_data[r->size[0] - 1] +
                                          this->Location->size[0] * 2) -
                                         1]) ||
              (rtIsNaN(this->Location
                           ->data[(nz_data[0] + this->Location->size[0] * 2) -
                                  1]) &&
               (!rtIsNaN(this->Location->data[(nz_data[r->size[0] - 1] +
                                               this->Location->size[0] * 2) -
                                              1])))) {
            ex = this->Location->data[(nz_data[r->size[0] - 1] +
                                       this->Location->size[0] * 2) -
                                      1];
          }
        }
      } else {
        ex = this->Location
                 ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
        if (!rtIsNaN(ex)) {
          xoffset = 1;
        } else {
          xoffset = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= vstride)) {
            if (!rtIsNaN(this->Location->data[(nz_data[k - 1] +
                                               this->Location->size[0] * 2) -
                                              1])) {
              xoffset = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (xoffset != 0) {
          ex = this->Location
                   ->data[(nz_data[xoffset - 1] + this->Location->size[0] * 2) -
                          1];
          j = xoffset + 1;
          for (k = j; k <= vstride; k++) {
            d = this->Location
                    ->data[(nz_data[k - 1] + this->Location->size[0] * 2) - 1];
            if (ex > d) {
              ex = d;
            }
          }
        }
      }
      vstride = r->size[0];
      if (r->size[0] <= 2) {
        if (r->size[0] == 1) {
          b_ex = this->Location
                     ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
        } else {
          b_ex = this->Location
                     ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
          if ((b_ex < this->Location->data[(nz_data[r->size[0] - 1] +
                                            this->Location->size[0] * 2) -
                                           1]) ||
              (rtIsNaN(this->Location
                           ->data[(nz_data[0] + this->Location->size[0] * 2) -
                                  1]) &&
               (!rtIsNaN(this->Location->data[(nz_data[r->size[0] - 1] +
                                               this->Location->size[0] * 2) -
                                              1])))) {
            b_ex = this->Location->data[(nz_data[r->size[0] - 1] +
                                         this->Location->size[0] * 2) -
                                        1];
          }
        }
      } else {
        if (!rtIsNaN(
                this->Location
                    ->data[(nz_data[0] + this->Location->size[0] * 2) - 1])) {
          xoffset = 1;
        } else {
          xoffset = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= vstride)) {
            if (!rtIsNaN(this->Location->data[(nz_data[k - 1] +
                                               this->Location->size[0] * 2) -
                                              1])) {
              xoffset = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (xoffset == 0) {
          b_ex = this->Location
                     ->data[(nz_data[0] + this->Location->size[0] * 2) - 1];
        } else {
          b_ex =
              this->Location
                  ->data[(nz_data[xoffset - 1] + this->Location->size[0] * 2) -
                         1];
          j = xoffset + 1;
          for (k = j; k <= vstride; k++) {
            d = this->Location
                    ->data[(nz_data[k - 1] + this->Location->size[0] * 2) - 1];
            if (b_ex < d) {
              b_ex = d;
            }
          }
        }
      }
      emxFree_int32_T(&r);
      j = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
      this->ZLimitsInternal->size[0] = 1;
      this->ZLimitsInternal->size[1] = 2;
      emxEnsureCapacity_real_T(this->ZLimitsInternal, j);
      this->ZLimitsInternal->data[0] = ex;
      this->ZLimitsInternal->data[1] = b_ex;
    } else {
      this->ZLimitsInternal->size[0] = 0;
      this->ZLimitsInternal->size[1] = 2;
    }
    emxFree_boolean_T(&b_tf);
  }
  j = zlim->size[0] * zlim->size[1];
  zlim->size[0] = this->ZLimitsInternal->size[0];
  zlim->size[1] = this->ZLimitsInternal->size[1];
  emxEnsureCapacity_real_T(zlim, j);
  zlim_data = zlim->data;
  xoffset = this->ZLimitsInternal->size[0] * this->ZLimitsInternal->size[1];
  for (j = 0; j < xoffset; j++) {
    zlim_data[j] = this->ZLimitsInternal->data[j];
  }
}

/*
 * File trailer for pointCloudBase.c
 *
 * [EOF]
 */
