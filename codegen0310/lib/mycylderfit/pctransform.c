/*
 * File: pctransform.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
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
  double s;
  double *loc_data;
  double *nv_data;
  double *tempI_data;
  int b_i;
  int boffset;
  int coffset;
  int exponent;
  int i;
  int j;
  int jA;
  int jp1j;
  int k;
  signed char ipiv[4];
  unsigned char *C__data;
  boolean_T b;
  boolean_T guard1 = false;
  boolean_T isodd;
  emxInitStruct_pointCloud(&lobj_0);
  emxInit_real_T(&nv, 2);
  lobj_0.matlabCodegenIsDeleted = true;
  i = nv->size[0] * nv->size[1];
  nv->size[0] = ptCloudIn->Location->size[0];
  nv->size[1] = 3;
  emxEnsureCapacity_real_T(nv, i);
  nv_data = nv->data;
  jA = ptCloudIn->Location->size[0] * 3;
  for (i = 0; i < jA; i++) {
    nv_data[i] = ptCloudIn->Location->data[i];
  }
  emxInit_real_T(&loc, 2);
  jA = nv->size[0];
  i = loc->size[0] * loc->size[1];
  loc->size[0] = nv->size[0];
  loc->size[1] = 3;
  emxEnsureCapacity_real_T(loc, i);
  loc_data = loc->data;
  for (j = 0; j < 3; j++) {
    coffset = j * jA;
    boffset = j * 3;
    for (b_i = 0; b_i < jA; b_i++) {
      loc_data[coffset + b_i] =
          (nv_data[b_i] *
               tform_AffineTform_T[boffset % 3 + ((boffset / 3) << 2)] +
           nv_data[nv->size[0] + b_i] *
               tform_AffineTform_T[(boffset + 1) % 3 +
                                   (((boffset + 1) / 3) << 2)]) +
          nv_data[(nv->size[0] << 1) + b_i] *
              tform_AffineTform_T[(boffset + 2) % 3 +
                                  (((boffset + 2) / 3) << 2)];
    }
  }
  emxInit_real_T(&b_loc, 1);
  jA = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  tempI_data = b_loc->data;
  for (i = 0; i <= jA; i++) {
    tempI_data[i] = loc_data[i] + tform_AffineTform_T[3];
  }
  jA = b_loc->size[0];
  for (i = 0; i < jA; i++) {
    loc_data[i] = tempI_data[i];
  }
  jA = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  tempI_data = b_loc->data;
  for (i = 0; i <= jA; i++) {
    tempI_data[i] = loc_data[i + loc->size[0]] + tform_AffineTform_T[7];
  }
  jA = b_loc->size[0];
  for (i = 0; i < jA; i++) {
    loc_data[i + loc->size[0]] = tempI_data[i];
  }
  jA = loc->size[0] - 1;
  i = b_loc->size[0];
  b_loc->size[0] = loc->size[0];
  emxEnsureCapacity_real_T(b_loc, i);
  tempI_data = b_loc->data;
  for (i = 0; i <= jA; i++) {
    tempI_data[i] = loc_data[i + loc->size[0] * 2] + tform_AffineTform_T[11];
  }
  jA = b_loc->size[0];
  for (i = 0; i < jA; i++) {
    loc_data[i + loc->size[0] * 2] = tempI_data[i];
  }
  emxFree_real_T(&b_loc);
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
        jA = i << 2;
        b_tform_AffineTform_T[3 * i] = tform_AffineTform_T[jA];
        b_tform_AffineTform_T[3 * i + 1] = tform_AffineTform_T[jA + 1];
        b_tform_AffineTform_T[3 * i + 2] = tform_AffineTform_T[jA + 2];
      }
      svd(b_tform_AffineTform_T, singularValues);
    } else {
      singularValues[0] = rtNaN;
      singularValues[1] = rtNaN;
      singularValues[2] = rtNaN;
    }
    s = maximum(singularValues);
    absx = fabs(s);
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
    guard1 = false;
    if (s - minimum(singularValues) < 100.0 * absx) {
      memcpy(&x[0], &tform_AffineTform_T[0], 16U * sizeof(double));
      ipiv[0] = 1;
      ipiv[1] = 2;
      ipiv[2] = 3;
      for (j = 0; j < 3; j++) {
        coffset = 2 - j;
        boffset = j * 5;
        jp1j = boffset + 2;
        jA = 4 - j;
        exponent = 0;
        absx = fabs(x[boffset]);
        for (k = 2; k <= jA; k++) {
          s = fabs(x[(boffset + k) - 1]);
          if (s > absx) {
            exponent = k - 1;
            absx = s;
          }
        }
        if (x[boffset + exponent] != 0.0) {
          if (exponent != 0) {
            jA = j + exponent;
            ipiv[j] = (signed char)(jA + 1);
            absx = x[j];
            x[j] = x[jA];
            x[jA] = absx;
            absx = x[j + 4];
            x[j + 4] = x[jA + 4];
            x[jA + 4] = absx;
            absx = x[j + 8];
            x[j + 8] = x[jA + 8];
            x[jA + 8] = absx;
            absx = x[j + 12];
            x[j + 12] = x[jA + 12];
            x[jA + 12] = absx;
          }
          i = (boffset - j) + 4;
          for (b_i = jp1j; b_i <= i; b_i++) {
            x[b_i - 1] /= x[boffset];
          }
        }
        jA = boffset;
        for (jp1j = 0; jp1j <= coffset; jp1j++) {
          absx = x[(boffset + (jp1j << 2)) + 4];
          if (absx != 0.0) {
            i = jA + 6;
            exponent = (jA - j) + 8;
            for (b_i = i; b_i <= exponent; b_i++) {
              x[b_i - 1] += x[((boffset + b_i) - jA) - 5] * -absx;
            }
          }
          jA += 4;
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
        tempI_data = tempI->data;
        jA = ptCloudIn->Normal->size[0] * ptCloudIn->Normal->size[1];
        for (i = 0; i < jA; i++) {
          tempI_data[i] = ptCloudIn->Normal->data[i];
        }
        exponent = tempI->size[0];
        jA = tempI->size[1];
        i = nv->size[0] * nv->size[1];
        nv->size[0] = tempI->size[0];
        nv->size[1] = 3;
        emxEnsureCapacity_real_T(nv, i);
        nv_data = nv->data;
        for (j = 0; j < 3; j++) {
          coffset = j * exponent;
          boffset = j * 3;
          for (b_i = 0; b_i < exponent; b_i++) {
            nv_data[coffset + b_i] = 0.0;
          }
          for (k = 0; k < jA; k++) {
            jp1j = k * tempI->size[0];
            i = boffset + k;
            absx = tform_AffineTform_T[i % 3 + ((i / 3) << 2)];
            for (b_i = 0; b_i < exponent; b_i++) {
              i = coffset + b_i;
              nv_data[i] += tempI_data[jp1j + b_i] * absx;
            }
          }
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      pointCloud_surfaceNormalImpl(pointCloud_pointCloud(&lobj_0, loc), nv);
      nv_data = nv->data;
    }
  }
  emxInit_uint8_T(&C_);
  i = C_->size[0] * C_->size[1];
  C_->size[0] = ptCloudIn->Color->size[0];
  C_->size[1] = ptCloudIn->Color->size[1];
  emxEnsureCapacity_uint8_T(C_, i);
  C__data = C_->data;
  jA = ptCloudIn->Color->size[0] * ptCloudIn->Color->size[1];
  for (i = 0; i < jA; i++) {
    C__data[i] = ptCloudIn->Color->data[i];
  }
  i = tempI->size[0] * tempI->size[1];
  tempI->size[0] = ptCloudIn->Intensity->size[0];
  tempI->size[1] = ptCloudIn->Intensity->size[1];
  emxEnsureCapacity_real_T(tempI, i);
  tempI_data = tempI->data;
  jA = ptCloudIn->Intensity->size[0] * ptCloudIn->Intensity->size[1];
  for (i = 0; i < jA; i++) {
    tempI_data[i] = ptCloudIn->Intensity->data[i];
  }
  iobj_0->HasKdtreeConstructed = false;
  iobj_0->HasLocationHandleAllocated = false;
  ptCloudOut = iobj_0;
  i = iobj_0->Location->size[0] * iobj_0->Location->size[1];
  iobj_0->Location->size[0] = loc->size[0];
  iobj_0->Location->size[1] = 3;
  emxEnsureCapacity_real_T(iobj_0->Location, i);
  jA = loc->size[0] * 3;
  for (i = 0; i < jA; i++) {
    iobj_0->Location->data[i] = loc_data[i];
  }
  emxFree_real_T(&loc);
  i = iobj_0->Color->size[0] * iobj_0->Color->size[1];
  iobj_0->Color->size[0] = C_->size[0];
  iobj_0->Color->size[1] = C_->size[1];
  emxEnsureCapacity_uint8_T(iobj_0->Color, i);
  jA = C_->size[0] * C_->size[1];
  for (i = 0; i < jA; i++) {
    iobj_0->Color->data[i] = C__data[i];
  }
  emxFree_uint8_T(&C_);
  i = iobj_0->Normal->size[0] * iobj_0->Normal->size[1];
  iobj_0->Normal->size[0] = nv->size[0];
  iobj_0->Normal->size[1] = nv->size[1];
  emxEnsureCapacity_real_T(iobj_0->Normal, i);
  jA = nv->size[0] * nv->size[1];
  for (i = 0; i < jA; i++) {
    iobj_0->Normal->data[i] = nv_data[i];
  }
  emxFree_real_T(&nv);
  i = iobj_0->Intensity->size[0] * iobj_0->Intensity->size[1];
  iobj_0->Intensity->size[0] = tempI->size[0];
  iobj_0->Intensity->size[1] = tempI->size[1];
  emxEnsureCapacity_real_T(iobj_0->Intensity, i);
  jA = tempI->size[0] * tempI->size[1];
  for (i = 0; i < jA; i++) {
    iobj_0->Intensity->data[i] = tempI_data[i];
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
