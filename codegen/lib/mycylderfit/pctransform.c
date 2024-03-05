/*
 * File: pctransform.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

/* Include Files */
#include "pctransform.h"
#include "minOrMax.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_types.h"
#include "pointCloud.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "cvstCG_kdtree.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const pointCloud *ptCloudIn
 *                const double tform_AffineTform_T[16]
 *                pointCloud *iobj_0
 * Return Type  : pointCloud *
 */
pointCloud *pctransform(const pointCloud *ptCloudIn,
                        const double tform_AffineTform_T[16],
                        pointCloud *iobj_0)
{
  void *locationPtr;
  emxArray_real_T *a;
  emxArray_real_T *b_loc;
  emxArray_real_T *loc;
  emxArray_real_T *nv;
  emxArray_real_T *tempI;
  emxArray_uint8_T *C_;
  pointCloud lobj_0;
  pointCloud *ptCloudOut;
  double x[16];
  double b_tform_AffineTform_T[9];
  double singularValues[3];
  double absx;
  double d;
  double maxval_tmp;
  double s;
  int b_i;
  int boffset;
  int coffset;
  int exponent;
  int i;
  int idx;
  int j;
  int jp1j;
  int k;
  signed char ipiv[4];
  boolean_T b;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T isodd;
  emxInitStruct_pointCloud(&lobj_0);
  emxInit_real_T(&a, 2);
  lobj_0.matlabCodegenIsDeleted = true;
  i = a->size[0] * a->size[1];
  a->size[0] = ptCloudIn->Location->size[0];
  a->size[1] = 3;
  emxEnsureCapacity_real_T(a, i);
  idx = ptCloudIn->Location->size[0] * 3;
  for (i = 0; i < idx; i++) {
    a->data[i] = ptCloudIn->Location->data[i];
  }
  emxInit_real_T(&loc, 2);
  idx = a->size[0];
  i = loc->size[0] * loc->size[1];
  loc->size[0] = a->size[0];
  loc->size[1] = 3;
  emxEnsureCapacity_real_T(loc, i);
  for (j = 0; j < 3; j++) {
    coffset = j * idx;
    boffset = j * 3;
    for (b_i = 0; b_i < idx; b_i++) {
      loc->data[coffset + b_i] =
          (a->data[b_i] *
               tform_AffineTform_T[boffset % 3 + ((boffset / 3) << 2)] +
           a->data[a->size[0] + b_i] *
               tform_AffineTform_T[(boffset + 1) % 3 +
                                   (((boffset + 1) / 3) << 2)]) +
          a->data[(a->size[0] << 1) + b_i] *
              tform_AffineTform_T[(boffset + 2) % 3 +
                                  (((boffset + 2) / 3) << 2)];
    }
  }
  emxInit_real_T(&b_loc, 1);
  idx = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  for (i = 0; i <= idx; i++) {
    b_loc->data[i] = loc->data[i] + tform_AffineTform_T[3];
  }
  idx = b_loc->size[0];
  for (i = 0; i < idx; i++) {
    loc->data[i] = b_loc->data[i];
  }
  idx = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  for (i = 0; i <= idx; i++) {
    b_loc->data[i] = loc->data[i + loc->size[0]] + tform_AffineTform_T[7];
  }
  idx = b_loc->size[0];
  for (i = 0; i < idx; i++) {
    loc->data[i + loc->size[0]] = b_loc->data[i];
  }
  idx = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  for (i = 0; i <= idx; i++) {
    b_loc->data[i] = loc->data[i + loc->size[0] * 2] + tform_AffineTform_T[11];
  }
  idx = b_loc->size[0];
  for (i = 0; i < idx; i++) {
    loc->data[i + loc->size[0] * 2] = b_loc->data[i];
  }
  emxFree_real_T(&b_loc);
  emxInit_real_T(&nv, 2);
  nv->size[0] = 0;
  nv->size[1] = 0;
  isodd = (ptCloudIn->Normal->size[0] == 0);
  b = (ptCloudIn->Normal->size[1] == 0);
  emxInit_real_T(&tempI, 2);
  if ((!isodd) && (!b)) {
    isodd = true;
    for (k = 0; k < 9; k++) {
      if (isodd) {
        absx = tform_AffineTform_T[k % 3 + ((k / 3) << 2)];
        if (rtIsInf(absx) || rtIsNaN(absx)) {
          isodd = false;
        }
      } else {
        isodd = false;
      }
    }
    if (isodd) {
      for (i = 0; i < 3; i++) {
        idx = i << 2;
        b_tform_AffineTform_T[3 * i] = tform_AffineTform_T[idx];
        b_tform_AffineTform_T[3 * i + 1] = tform_AffineTform_T[idx + 1];
        b_tform_AffineTform_T[3 * i + 2] = tform_AffineTform_T[idx + 2];
      }
      svd(b_tform_AffineTform_T, singularValues);
    } else {
      singularValues[0] = rtNaN;
      singularValues[1] = rtNaN;
      singularValues[2] = rtNaN;
    }
    maxval_tmp = maximum(singularValues);
    absx = fabs(maxval_tmp);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        absx = ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }
    if (!rtIsNaN(singularValues[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= 3)) {
        if (!rtIsNaN(singularValues[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      s = singularValues[0];
    } else {
      s = singularValues[idx - 1];
      i = idx + 1;
      for (k = i; k < 4; k++) {
        d = singularValues[k - 1];
        if (s > d) {
          s = d;
        }
      }
    }
    guard1 = false;
    if (maxval_tmp - s < 100.0 * absx) {
      memcpy(&x[0], &tform_AffineTform_T[0], 16U * sizeof(double));
      ipiv[0] = 1;
      ipiv[1] = 2;
      ipiv[2] = 3;
      for (j = 0; j < 3; j++) {
        coffset = 2 - j;
        boffset = j * 5;
        jp1j = boffset + 2;
        idx = 4 - j;
        exponent = 0;
        absx = fabs(x[boffset]);
        for (k = 2; k <= idx; k++) {
          s = fabs(x[(boffset + k) - 1]);
          if (s > absx) {
            exponent = k - 1;
            absx = s;
          }
        }
        if (x[boffset + exponent] != 0.0) {
          if (exponent != 0) {
            idx = j + exponent;
            ipiv[j] = (signed char)(idx + 1);
            absx = x[j];
            x[j] = x[idx];
            x[idx] = absx;
            absx = x[j + 4];
            x[j + 4] = x[idx + 4];
            x[idx + 4] = absx;
            absx = x[j + 8];
            x[j + 8] = x[idx + 8];
            x[idx + 8] = absx;
            absx = x[j + 12];
            x[j + 12] = x[idx + 12];
            x[idx + 12] = absx;
          }
          i = (boffset - j) + 4;
          for (b_i = jp1j; b_i <= i; b_i++) {
            x[b_i - 1] /= x[boffset];
          }
        }
        idx = boffset;
        for (jp1j = 0; jp1j <= coffset; jp1j++) {
          absx = x[(boffset + (jp1j << 2)) + 4];
          if (absx != 0.0) {
            i = idx + 6;
            exponent = (idx - j) + 8;
            for (b_i = i; b_i <= exponent; b_i++) {
              x[b_i - 1] += x[((boffset + b_i) - idx) - 5] * -absx;
            }
          }
          idx += 4;
        }
      }
      isodd = (ipiv[0] > 1);
      if (ipiv[1] > 2) {
        isodd = !isodd;
      }
      absx = x[0] * x[5] * x[10] * x[15];
      if (ipiv[2] > 3) {
        isodd = !isodd;
      }
      if (isodd) {
        absx = -absx;
      }
      if (fabs(absx - 1.0) < 2.2204460492503131E-14) {
        i = tempI->size[0] * tempI->size[1];
        tempI->size[0] = ptCloudIn->Normal->size[0];
        tempI->size[1] = ptCloudIn->Normal->size[1];
        emxEnsureCapacity_real_T(tempI, i);
        idx = ptCloudIn->Normal->size[0] * ptCloudIn->Normal->size[1];
        for (i = 0; i < idx; i++) {
          tempI->data[i] = ptCloudIn->Normal->data[i];
        }
        idx = tempI->size[0];
        exponent = tempI->size[1];
        i = a->size[0] * a->size[1];
        a->size[0] = tempI->size[0];
        a->size[1] = 3;
        emxEnsureCapacity_real_T(a, i);
        for (j = 0; j < 3; j++) {
          coffset = j * idx;
          boffset = j * 3;
          for (b_i = 0; b_i < idx; b_i++) {
            a->data[coffset + b_i] = 0.0;
          }
          for (k = 0; k < exponent; k++) {
            jp1j = k * tempI->size[0];
            i = boffset + k;
            absx = tform_AffineTform_T[i % 3 + ((i / 3) << 2)];
            for (b_i = 0; b_i < idx; b_i++) {
              i = coffset + b_i;
              a->data[i] += tempI->data[jp1j + b_i] * absx;
            }
          }
        }
        i = nv->size[0] * nv->size[1];
        nv->size[0] = a->size[0];
        nv->size[1] = 3;
        emxEnsureCapacity_real_T(nv, i);
        idx = a->size[0] * 3;
        for (i = 0; i < idx; i++) {
          nv->data[i] = a->data[i];
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      pointCloud_surfaceNormalImpl(pointCloud_pointCloud(&lobj_0, loc), a);
      i = nv->size[0] * nv->size[1];
      nv->size[0] = a->size[0];
      nv->size[1] = 3;
      emxEnsureCapacity_real_T(nv, i);
      idx = a->size[0] * 3;
      for (i = 0; i < idx; i++) {
        nv->data[i] = a->data[i];
      }
    }
  }
  emxFree_real_T(&a);
  emxInit_uint8_T(&C_, 2);
  i = C_->size[0] * C_->size[1];
  C_->size[0] = ptCloudIn->Color->size[0];
  C_->size[1] = ptCloudIn->Color->size[1];
  emxEnsureCapacity_uint8_T(C_, i);
  idx = ptCloudIn->Color->size[0] * ptCloudIn->Color->size[1];
  for (i = 0; i < idx; i++) {
    C_->data[i] = ptCloudIn->Color->data[i];
  }
  i = tempI->size[0] * tempI->size[1];
  tempI->size[0] = ptCloudIn->Intensity->size[0];
  tempI->size[1] = ptCloudIn->Intensity->size[1];
  emxEnsureCapacity_real_T(tempI, i);
  idx = ptCloudIn->Intensity->size[0] * ptCloudIn->Intensity->size[1];
  for (i = 0; i < idx; i++) {
    tempI->data[i] = ptCloudIn->Intensity->data[i];
  }
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  ptCloudOut = iobj_0;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1];
  iobj_0->Location->size[0] = loc->size[0];
  iobj_0->Location->size[1] = 3;
  emxEnsureCapacity_real_T(iobj_0->Location, i);
  idx = loc->size[0] * 3;
  for (i = 0; i < idx; i++) {
    iobj_0->Location->data[i] = loc->data[i];
  }
  emxFree_real_T(&loc);
  i = iobj_0->Color->size[0] * iobj_0->Color->size[1];
  iobj_0->Color->size[0] = C_->size[0];
  iobj_0->Color->size[1] = C_->size[1];
  emxEnsureCapacity_uint8_T(iobj_0->Color, i);
  idx = C_->size[0] * C_->size[1];
  for (i = 0; i < idx; i++) {
    iobj_0->Color->data[i] = C_->data[i];
  }
  emxFree_uint8_T(&C_);
  i = iobj_0->Normal->size[0] * iobj_0->Normal->size[1];
  iobj_0->Normal->size[0] = nv->size[0];
  iobj_0->Normal->size[1] = nv->size[1];
  emxEnsureCapacity_real_T(iobj_0->Normal, i);
  idx = nv->size[0] * nv->size[1];
  for (i = 0; i < idx; i++) {
    iobj_0->Normal->data[i] = nv->data[i];
  }
  emxFree_real_T(&nv);
  i = iobj_0->Intensity->size[0] * iobj_0->Intensity->size[1];
  iobj_0->Intensity->size[0] = tempI->size[0];
  iobj_0->Intensity->size[1] = tempI->size[1];
  emxEnsureCapacity_real_T(iobj_0->Intensity, i);
  idx = tempI->size[0] * tempI->size[1];
  for (i = 0; i < idx; i++) {
    iobj_0->Intensity->data[i] = tempI->data[i];
  }
  emxFree_real_T(&tempI);
  iobj_0->PointCloudArrayData->size[0] = 1;
  iobj_0->PointCloudArrayData->size[1] = 1;
  iobj_0->ZLimitsInternal->size[0] = 0;
  iobj_0->ZLimitsInternal->size[1] = 0;
  iobj_0->Kdtree = NULL;
  iobj_0->LocationHandle = NULL;
  iobj_0->matlabCodegenIsDeleted = false;
  if (!lobj_0.matlabCodegenIsDeleted) {
    lobj_0.matlabCodegenIsDeleted = true;
    if (lobj_0.HasLocationHandleAllocated) {
      locationPtr = lobj_0.LocationHandle;
      kdtreeDeleteLocationDataPointer_double(locationPtr);
      lobj_0.HasLocationHandleAllocated = false;
    }
    if (lobj_0.HasKdtreeConstructed) {
      locationPtr = lobj_0.Kdtree;
      kdtreeDeleteObj_double(locationPtr);
      lobj_0.HasKdtreeConstructed = false;
    }
  }
  emxFreeStruct_pointCloud(&lobj_0);
  return ptCloudOut;
}

/*
 * File trailer for pctransform.c
 *
 * [EOF]
 */
