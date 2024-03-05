/*
 * File: mycylderfit.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 05-Mar-2024 22:12:28
 */

/* Include Files */
#include "mycylderfit.h"
#include "minOrMax.h"
#include "mycylderfit_data.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_initialize.h"
#include "mycylderfit_types.h"
#include "pca.h"
#include "pctransform.h"
#include "pinv.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "cvstCG_kdtree.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const emxArray_real_T *z
 *                double *xn1
 *                double *xn2
 *                double *xn3
 *                double *xn4
 *                double *xn5
 *                double *xn6
 *                double *xn7
 * Return Type  : void
 */
void mycylderfit(const emxArray_real_T *x, const emxArray_real_T *y,
                 const emxArray_real_T *z, double *xn1, double *xn2,
                 double *xn3, double *xn4, double *xn5, double *xn6,
                 double *xn7)
{
  void *locationPtr;
  emxArray_real_T *Bn;
  emxArray_real_T *L;
  emxArray_real_T *a__1;
  emxArray_real_T *a__3;
  emxArray_real_T *b_y;
  emxArray_real_T *normals;
  emxArray_real_T *xc;
  emxArray_real_T *yc;
  emxArray_real_T *zlimit;
  pointCloud circleCloud;
  pointCloud ptCloud;
  double C[49];
  double a[49];
  double T[16];
  double b_T[9];
  double coeff_data[9];
  double rot[9];
  double Xn[7];
  double b_C[7];
  double deltX[7];
  double W[3];
  double a__4_data[3];
  double a__5_data[3];
  double Bn_tmp;
  double Bn_tmp_tmp;
  double X_idx_0;
  double a0;
  double a21;
  double b0;
  double b_Bn_tmp_tmp;
  double c0;
  double c_Bn_tmp_tmp;
  double denom;
  double r0;
  int a__5_size[2];
  int coeff_size[2];
  int boffset;
  int coffset;
  int count;
  int i;
  int j;
  int k;
  int n;
  int nx;
  int rtemp;
  boolean_T exitg1;
  boolean_T p;
  if (!isInitialized_mycylderfit) {
    mycylderfit_initialize();
  }
  emxInitStruct_pointCloud(&circleCloud);
  emxInitStruct_pointCloud(&ptCloud);
  emxInit_real_T(&normals, 2);
  circleCloud.matlabCodegenIsDeleted = true;
  ptCloud.matlabCodegenIsDeleted = true;
  rtemp = normals->size[0] * normals->size[1];
  normals->size[0] = x->size[0];
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(normals, rtemp);
  nx = x->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp] = x->data[rtemp];
  }
  nx = y->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp + normals->size[0]] = y->data[rtemp];
  }
  nx = z->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp + normals->size[0] * 2] = z->data[rtemp];
  }
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&a__3, 2);
  pointCloud_pointCloud(&ptCloud, normals);
  n = ptCloud.Location->size[0];
  /*     %%
   * -----------------------------计算点云法向量----------------------------- */
  pointCloud_surfaceNormalImpl(&ptCloud, normals);
  /*  计算点云法向量 */
  pca(normals, coeff_data, coeff_size, a__1, W, &nx, a__3, a__4_data, &coffset,
      a__5_data, a__5_size);
  a0 = coeff_data[6];
  b0 = coeff_data[7];
  c0 = coeff_data[8];
  /*  构建旋转矩阵 */
  denom = rt_hypotd_snf(coeff_data[6], coeff_data[7]);
  rot[0] = coeff_data[7] / denom;
  rot[3] = -coeff_data[6] / denom;
  rot[6] = 0.0;
  rot[1] = coeff_data[6] * coeff_data[8] / denom;
  rot[4] = coeff_data[7] * coeff_data[8] / denom;
  rot[7] = -denom;
  rot[2] = coeff_data[6];
  rot[5] = coeff_data[7];
  rot[8] = coeff_data[8];
  emxFree_real_T(&a__3);
  emxFree_real_T(&a__1);
  for (rtemp = 0; rtemp < 3; rtemp++) {
    nx = rtemp << 2;
    T[nx] = rot[rtemp];
    T[nx + 1] = rot[rtemp + 3];
    T[nx + 2] = rot[rtemp + 6];
    T[rtemp + 12] = 0.0;
  }
  T[3] = 0.0;
  T[7] = 0.0;
  T[11] = 0.0;
  T[15] = 1.0;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p) {
      denom = T[k % 3 + ((k / 3) << 2)];
      if (rtIsInf(denom) || rtIsNaN(denom)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    for (rtemp = 0; rtemp < 3; rtemp++) {
      nx = rtemp << 2;
      b_T[3 * rtemp] = T[nx];
      b_T[3 * rtemp + 1] = T[nx + 1];
      b_T[3 * rtemp + 2] = T[nx + 2];
    }
    svd(b_T, W);
  } else {
    W[0] = rtNaN;
    W[1] = rtNaN;
    W[2] = rtNaN;
  }
  denom = fabs(maximum(W));
  if ((!rtIsInf(denom)) && (!rtIsNaN(denom)) &&
      (!(denom <= 2.2250738585072014E-308))) {
    frexp(denom, &boffset);
  }
  emxInit_real_T(&xc, 1);
  /* 变换点云 */
  pctransform(&ptCloud, T, &circleCloud);
  nx = circleCloud.Location->size[0];
  rtemp = xc->size[0];
  xc->size[0] = nx;
  emxEnsureCapacity_real_T(xc, rtemp);
  for (rtemp = 0; rtemp < nx; rtemp++) {
    xc->data[rtemp] = circleCloud.Location->data[rtemp];
  }
  emxInit_real_T(&yc, 1);
  nx = circleCloud.Location->size[0];
  rtemp = yc->size[0];
  yc->size[0] = nx;
  emxEnsureCapacity_real_T(yc, rtemp);
  for (rtemp = 0; rtemp < nx; rtemp++) {
    yc->data[rtemp] =
        circleCloud.Location->data[rtemp + circleCloud.Location->size[0]];
  }
  /*     %%
   * --------------------------初始化矩阵系数-------------------------------- */
  rtemp = normals->size[0] * normals->size[1];
  normals->size[0] = n;
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(normals, rtemp);
  nx = n * 3;
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp] = 1.0;
  }
  emxInit_real_T(&L, 1);
  rtemp = L->size[0];
  L->size[0] = n;
  emxEnsureCapacity_real_T(L, rtemp);
  for (rtemp = 0; rtemp < n; rtemp++) {
    L->data[rtemp] = 0.0;
  }
  /*  系数矩阵L */
  /*  赋值 */
  nx = xc->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp] = xc->data[rtemp] * 2.0;
  }
  nx = yc->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    normals->data[rtemp + normals->size[0]] = yc->data[rtemp] * 2.0;
  }
  emxInit_real_T(&b_y, 1);
  rtemp = b_y->size[0];
  b_y->size[0] = xc->size[0];
  emxEnsureCapacity_real_T(b_y, rtemp);
  nx = xc->size[0];
  for (k = 0; k < nx; k++) {
    b_y->data[k] = xc->data[k] * xc->data[k];
  }
  rtemp = xc->size[0];
  xc->size[0] = yc->size[0];
  emxEnsureCapacity_real_T(xc, rtemp);
  nx = yc->size[0];
  for (k = 0; k < nx; k++) {
    xc->data[k] = yc->data[k] * yc->data[k];
  }
  emxFree_real_T(&yc);
  nx = b_y->size[0];
  for (rtemp = 0; rtemp < nx; rtemp++) {
    L->data[rtemp] = b_y->data[rtemp] + xc->data[rtemp];
  }
  emxFree_real_T(&b_y);
  /*  间接平差求解 */
  nx = normals->size[0];
  W[0] = 0.0;
  W[1] = 0.0;
  W[2] = 0.0;
  for (k = 0; k < nx; k++) {
    W[0] += normals->data[k] * L->data[k];
    W[1] += normals->data[normals->size[0] + k] * L->data[k];
    W[2] += normals->data[(normals->size[0] << 1) + k] * L->data[k];
  }
  emxFree_real_T(&L);
  /*  参数求解 */
  nx = normals->size[0];
  for (j = 0; j < 3; j++) {
    coffset = j * 3;
    boffset = j * normals->size[0];
    b_T[coffset] = 0.0;
    b_T[coffset + 1] = 0.0;
    b_T[coffset + 2] = 0.0;
    for (k = 0; k < nx; k++) {
      denom = normals->data[boffset + k];
      b_T[coffset] += normals->data[k] * denom;
      b_T[coffset + 1] += normals->data[normals->size[0] + k] * denom;
      b_T[coffset + 2] += normals->data[(normals->size[0] << 1) + k] * denom;
    }
  }
  emxFree_real_T(&normals);
  nx = 0;
  coffset = 1;
  boffset = 2;
  denom = fabs(b_T[0]);
  a21 = fabs(b_T[1]);
  if (a21 > denom) {
    denom = a21;
    nx = 1;
    coffset = 0;
  }
  if (fabs(b_T[2]) > denom) {
    nx = 2;
    coffset = 1;
    boffset = 0;
  }
  b_T[coffset] /= b_T[nx];
  b_T[boffset] /= b_T[nx];
  b_T[coffset + 3] -= b_T[coffset] * b_T[nx + 3];
  b_T[boffset + 3] -= b_T[boffset] * b_T[nx + 3];
  b_T[coffset + 6] -= b_T[coffset] * b_T[nx + 6];
  b_T[boffset + 6] -= b_T[boffset] * b_T[nx + 6];
  if (fabs(b_T[boffset + 3]) > fabs(b_T[coffset + 3])) {
    rtemp = coffset;
    coffset = boffset;
    boffset = rtemp;
  }
  b_T[boffset + 3] /= b_T[coffset + 3];
  b_T[boffset + 6] -= b_T[boffset + 3] * b_T[coffset + 6];
  a21 = W[coffset] - W[nx] * b_T[coffset];
  denom = ((W[boffset] - W[nx] * b_T[boffset]) - a21 * b_T[boffset + 3]) /
          b_T[boffset + 6];
  a21 -= denom * b_T[coffset + 6];
  a21 /= b_T[coffset + 3];
  X_idx_0 = ((W[nx] - denom * b_T[nx + 6]) - a21 * b_T[nx + 3]) / b_T[nx];
  r0 = sqrt((X_idx_0 * X_idx_0 + a21 * a21) + denom);
  for (rtemp = 0; rtemp < 3; rtemp++) {
    W[rtemp] = (X_idx_0 * rot[3 * rtemp] + a21 * rot[3 * rtemp + 1]) +
               0.0 * rot[3 * rtemp + 2];
  }
  emxInit_real_T(&zlimit, 2);
  emxInit_real_T(&Bn, 2);
  /*  旋转矩阵的逆与转置相等 */
  denom = W[0];
  a21 = W[1];
  pointCloudBase_get_ZLimits(&ptCloud, zlimit);
  /*  计算点云z坐标最值 */
  X_idx_0 = (zlimit->data[0] + zlimit->data[1]) * 0.5;
  /*     %%
   * ------------------------------最小二乘迭代--------------------------- */
  rtemp = Bn->size[0] * Bn->size[1];
  Bn->size[0] = n;
  Bn->size[1] = 7;
  emxEnsureCapacity_real_T(Bn, rtemp);
  nx = n * 7;
  emxFree_real_T(&zlimit);
  for (rtemp = 0; rtemp < nx; rtemp++) {
    Bn->data[rtemp] = 1.0;
  }
  rtemp = xc->size[0];
  xc->size[0] = n;
  emxEnsureCapacity_real_T(xc, rtemp);
  for (rtemp = 0; rtemp < n; rtemp++) {
    xc->data[rtemp] = 1.0;
  }
  Xn[0] = W[0];
  Xn[1] = W[1];
  Xn[2] = X_idx_0;
  Xn[3] = coeff_data[6];
  Xn[4] = coeff_data[7];
  Xn[5] = coeff_data[8];
  Xn[6] = r0;
  count = 1;
  exitg1 = false;
  while ((!exitg1) && (r0 > 0.001)) {
    for (i = 0; i < n; i++) {
      Bn_tmp_tmp = x->data[i] - denom;
      b_Bn_tmp_tmp = y->data[i] - a21;
      c_Bn_tmp_tmp = z->data[i] - X_idx_0;
      Bn_tmp = (a0 * Bn_tmp_tmp + b0 * b_Bn_tmp_tmp) + c0 * c_Bn_tmp_tmp;
      Bn->data[i] = (2.0 * denom - x->data[i] * 2.0) + 2.0 * a0 * Bn_tmp;
      nx = Bn->size[0];
      for (rtemp = 0; rtemp < nx; rtemp++) {
        Bn->data[rtemp + Bn->size[0]] =
            (2.0 * a21 - 2.0 * y->data[i]) + 2.0 * b0 * Bn_tmp;
      }
      Bn->data[i + Bn->size[0] * 2] =
          (2.0 * X_idx_0 - 2.0 * z->data[i]) + 2.0 * c0 * Bn_tmp;
      Bn->data[i + Bn->size[0] * 3] = -2.0 * Bn_tmp_tmp * Bn_tmp;
      Bn->data[i + Bn->size[0] * 4] = -2.0 * b_Bn_tmp_tmp * Bn_tmp;
      Bn->data[i + Bn->size[0] * 5] = -2.0 * c_Bn_tmp_tmp * Bn_tmp;
      Bn->data[i + Bn->size[0] * 6] = -2.0 * r0;
      xc->data[i] =
          -((((Bn_tmp_tmp * Bn_tmp_tmp + b_Bn_tmp_tmp * b_Bn_tmp_tmp) +
              c_Bn_tmp_tmp * c_Bn_tmp_tmp) -
             Bn_tmp * Bn_tmp) -
            r0 * r0);
    }
    /*  间接平差求解 */
    nx = Bn->size[0];
    for (j = 0; j < 7; j++) {
      coffset = j * 7;
      boffset = j * Bn->size[0];
      for (i = 0; i < 7; i++) {
        C[coffset + i] = 0.0;
      }
      for (k = 0; k < nx; k++) {
        denom = Bn->data[boffset + k];
        for (i = 0; i < 7; i++) {
          rtemp = coffset + i;
          C[rtemp] += Bn->data[i * Bn->size[0] + k] * denom;
        }
      }
    }
    pinv(C, a);
    nx = Bn->size[0];
    for (i = 0; i < 7; i++) {
      b_C[i] = 0.0;
    }
    for (k = 0; k < nx; k++) {
      for (i = 0; i < 7; i++) {
        b_C[i] += Bn->data[i * Bn->size[0] + k] * xc->data[k];
      }
    }
    for (rtemp = 0; rtemp < 7; rtemp++) {
      denom = 0.0;
      for (nx = 0; nx < 7; nx++) {
        denom += a[rtemp + 7 * nx] * b_C[nx];
      }
      deltX[rtemp] = denom;
      Xn[rtemp] += denom;
    }
    /*  获取迭代增量 */
    denom = deltX[0];
    a21 = deltX[1];
    X_idx_0 = deltX[2];
    a0 = deltX[3];
    b0 = deltX[4];
    c0 = deltX[5];
    r0 = deltX[6];
    count++;
    /* 迭代次数足够多，跳出迭代。 */
    if (count >= 10) {
      exitg1 = true;
    }
  }
  emxFree_real_T(&Bn);
  emxFree_real_T(&xc);
  /*     %% ------------------------------返回值--------------------------- */
  *xn1 = Xn[0];
  *xn2 = Xn[1];
  *xn3 = Xn[2];
  *xn4 = Xn[3];
  *xn5 = Xn[4];
  *xn6 = Xn[5];
  *xn7 = Xn[6];
  if (!ptCloud.matlabCodegenIsDeleted) {
    ptCloud.matlabCodegenIsDeleted = true;
    if (ptCloud.HasLocationHandleAllocated) {
      locationPtr = ptCloud.LocationHandle;
      kdtreeDeleteLocationDataPointer_double(locationPtr);
      ptCloud.HasLocationHandleAllocated = false;
    }
    if (ptCloud.HasKdtreeConstructed) {
      locationPtr = ptCloud.Kdtree;
      kdtreeDeleteObj_double(locationPtr);
      ptCloud.HasKdtreeConstructed = false;
    }
  }
  if (!circleCloud.matlabCodegenIsDeleted) {
    circleCloud.matlabCodegenIsDeleted = true;
    if (circleCloud.HasLocationHandleAllocated) {
      locationPtr = circleCloud.LocationHandle;
      kdtreeDeleteLocationDataPointer_double(locationPtr);
      circleCloud.HasLocationHandleAllocated = false;
    }
    if (circleCloud.HasKdtreeConstructed) {
      locationPtr = circleCloud.Kdtree;
      kdtreeDeleteObj_double(locationPtr);
      circleCloud.HasKdtreeConstructed = false;
    }
  }
  emxFreeStruct_pointCloud(&ptCloud);
  emxFreeStruct_pointCloud(&circleCloud);
}

/*
 * File trailer for mycylderfit.c
 *
 * [EOF]
 */
