/*
 * File: mycylderfit.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Mar-2024 17:13:38
 */

/* Include Files */
#include "mycylderfit.h"
#include "mycylderfit_data.h"
#include "mycylderfit_emxutil.h"
#include "mycylderfit_initialize.h"
#include "mycylderfit_types.h"
#include "pca.h"
#include "pctransform.h"
#include "pinv.h"
#include "pointCloud.h"
#include "pointCloudBase.h"
#include "rigid3dImpl.h"
#include "rt_nonfinite.h"
#include "cvstCG_kdtree.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in3,
                             const emxArray_real_T *in4);

static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in3,
                             const emxArray_real_T *in4)
{
  const double *in3_data;
  const double *in4_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in3_data = in3->data;
  in1_data = in1->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in3_data[i * stride_0_0] + in4_data[i * stride_1_0];
  }
}

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
  emxArray_real_T *normals;
  emxArray_real_T *r;
  emxArray_real_T *xc;
  emxArray_real_T *yc;
  emxArray_real_T *zlimit;
  pointCloud circleCloud;
  pointCloud ptCloud;
  double C[49];
  double a[49];
  double T[16];
  double b_varargin_1[16];
  double coeff_data[9];
  double rot[9];
  double varargin_1[9];
  double Xn[7];
  double b_C[7];
  double deltX[7];
  double a__4_data[3];
  double a__5_data[3];
  double co[3];
  const double *x_data;
  const double *y_data;
  const double *z_data;
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
  double *L_data;
  double *b_r1;
  double *normals_data;
  double *xc_data;
  double *yc_data;
  int a__5_size[2];
  int coeff_size[2];
  int boffset;
  int coffset;
  int count;
  int i;
  int j;
  int k;
  int n;
  int r1;
  int r2;
  boolean_T exitg1;
  if (!isInitialized_mycylderfit) {
    mycylderfit_initialize();
  }
  z_data = z->data;
  y_data = y->data;
  x_data = x->data;
  emxInitStruct_pointCloud(&circleCloud);
  emxInitStruct_pointCloud(&ptCloud);
  emxInit_real_T(&normals, 2);
  circleCloud.matlabCodegenIsDeleted = true;
  ptCloud.matlabCodegenIsDeleted = true;
  coffset = normals->size[0] * normals->size[1];
  normals->size[0] = x->size[0];
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(normals, coffset);
  normals_data = normals->data;
  r2 = x->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset] = x_data[coffset];
  }
  r2 = y->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset + normals->size[0]] = y_data[coffset];
  }
  r2 = z->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset + normals->size[0] * 2] = z_data[coffset];
  }
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&a__3, 2);
  pointCloud_pointCloud(&ptCloud, normals);
  n = ptCloud.Location->size[0];
  /*     %%
   * -----------------------------计算点云法向量----------------------------- */
  pointCloud_surfaceNormalImpl(&ptCloud, normals);
  /*  计算点云法向量 */
  pca(normals, coeff_data, coeff_size, a__1, co, &r2, a__3, a__4_data, &r1,
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
  for (coffset = 0; coffset < 3; coffset++) {
    denom = rot[coffset];
    varargin_1[3 * coffset] = denom;
    r2 = coffset << 2;
    T[r2] = denom;
    denom = rot[coffset + 3];
    varargin_1[3 * coffset + 1] = denom;
    T[r2 + 1] = denom;
    denom = rot[coffset + 6];
    varargin_1[3 * coffset + 2] = denom;
    T[r2 + 2] = denom;
    T[coffset + 12] = 0.0;
  }
  T[3] = 0.0;
  T[7] = 0.0;
  T[11] = 0.0;
  T[15] = 1.0;
  c_rigid3dImpl_isTransformationM(T);
  for (coffset = 0; coffset < 3; coffset++) {
    r2 = coffset << 2;
    b_varargin_1[r2] = varargin_1[3 * coffset];
    b_varargin_1[r2 + 1] = varargin_1[3 * coffset + 1];
    b_varargin_1[r2 + 2] = varargin_1[3 * coffset + 2];
    b_varargin_1[coffset + 12] = 0.0;
  }
  emxInit_real_T(&xc, 1);
  b_varargin_1[3] = 0.0;
  b_varargin_1[7] = 0.0;
  b_varargin_1[11] = 0.0;
  b_varargin_1[15] = 1.0;
  c_rigid3dImpl_isTransformationM(b_varargin_1);
  /* 变换点云 */
  pctransform(&ptCloud, T, &circleCloud);
  r2 = circleCloud.Location->size[0];
  coffset = xc->size[0];
  xc->size[0] = r2;
  emxEnsureCapacity_real_T(xc, coffset);
  xc_data = xc->data;
  for (coffset = 0; coffset < r2; coffset++) {
    xc_data[coffset] = circleCloud.Location->data[coffset];
  }
  emxInit_real_T(&yc, 1);
  r2 = circleCloud.Location->size[0];
  coffset = yc->size[0];
  yc->size[0] = r2;
  emxEnsureCapacity_real_T(yc, coffset);
  yc_data = yc->data;
  for (coffset = 0; coffset < r2; coffset++) {
    yc_data[coffset] =
        circleCloud.Location->data[coffset + circleCloud.Location->size[0]];
  }
  /*     %%
   * --------------------------初始化矩阵系数-------------------------------- */
  coffset = normals->size[0] * normals->size[1];
  normals->size[0] = n;
  normals->size[1] = 3;
  emxEnsureCapacity_real_T(normals, coffset);
  normals_data = normals->data;
  r2 = n * 3;
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset] = 1.0;
  }
  emxInit_real_T(&L, 1);
  coffset = L->size[0];
  L->size[0] = n;
  emxEnsureCapacity_real_T(L, coffset);
  L_data = L->data;
  for (coffset = 0; coffset < n; coffset++) {
    L_data[coffset] = 0.0;
  }
  /*  系数矩阵L */
  /*  赋值 */
  r2 = xc->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset] = xc_data[coffset] * 2.0;
  }
  r2 = yc->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset + normals->size[0]] = yc_data[coffset] * 2.0;
  }
  emxInit_real_T(&r, 1);
  coffset = r->size[0];
  r->size[0] = xc->size[0];
  emxEnsureCapacity_real_T(r, coffset);
  b_r1 = r->data;
  r2 = xc->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    denom = xc_data[coffset];
    b_r1[coffset] = denom * denom;
  }
  coffset = xc->size[0];
  xc->size[0] = yc->size[0];
  emxEnsureCapacity_real_T(xc, coffset);
  xc_data = xc->data;
  r2 = yc->size[0];
  for (coffset = 0; coffset < r2; coffset++) {
    denom = yc_data[coffset];
    xc_data[coffset] = denom * denom;
  }
  emxFree_real_T(&yc);
  if (r->size[0] == xc->size[0]) {
    r2 = r->size[0];
    for (coffset = 0; coffset < r2; coffset++) {
      L_data[coffset] = b_r1[coffset] + xc_data[coffset];
    }
  } else {
    binary_expand_op(L, r, xc);
    L_data = L->data;
  }
  emxFree_real_T(&r);
  /*  间接平差求解 */
  /*  参数求解 */
  r2 = normals->size[0];
  r1 = normals->size[0];
  for (j = 0; j < 3; j++) {
    coffset = j * 3;
    boffset = j * normals->size[0];
    varargin_1[coffset] = 0.0;
    varargin_1[coffset + 1] = 0.0;
    varargin_1[coffset + 2] = 0.0;
    for (k = 0; k < r2; k++) {
      denom = normals_data[boffset + k];
      varargin_1[coffset] += normals_data[k] * denom;
      varargin_1[coffset + 1] += normals_data[normals->size[0] + k] * denom;
      varargin_1[coffset + 2] +=
          normals_data[(normals->size[0] << 1) + k] * denom;
    }
    co[j] = 0.0;
  }
  for (k = 0; k < r1; k++) {
    co[0] += normals_data[k] * L_data[k];
    co[1] += normals_data[normals->size[0] + k] * L_data[k];
    co[2] += normals_data[(normals->size[0] << 1) + k] * L_data[k];
  }
  emxFree_real_T(&L);
  emxFree_real_T(&normals);
  r1 = 0;
  r2 = 1;
  coffset = 2;
  denom = fabs(varargin_1[0]);
  a21 = fabs(varargin_1[1]);
  if (a21 > denom) {
    denom = a21;
    r1 = 1;
    r2 = 0;
  }
  if (fabs(varargin_1[2]) > denom) {
    r1 = 2;
    r2 = 1;
    coffset = 0;
  }
  varargin_1[r2] /= varargin_1[r1];
  varargin_1[coffset] /= varargin_1[r1];
  varargin_1[r2 + 3] -= varargin_1[r2] * varargin_1[r1 + 3];
  varargin_1[coffset + 3] -= varargin_1[coffset] * varargin_1[r1 + 3];
  varargin_1[r2 + 6] -= varargin_1[r2] * varargin_1[r1 + 6];
  varargin_1[coffset + 6] -= varargin_1[coffset] * varargin_1[r1 + 6];
  if (fabs(varargin_1[coffset + 3]) > fabs(varargin_1[r2 + 3])) {
    boffset = r2;
    r2 = coffset;
    coffset = boffset;
  }
  varargin_1[coffset + 3] /= varargin_1[r2 + 3];
  varargin_1[coffset + 6] -= varargin_1[coffset + 3] * varargin_1[r2 + 6];
  a21 = co[r2] - co[r1] * varargin_1[r2];
  denom = ((co[coffset] - co[r1] * varargin_1[coffset]) -
           a21 * varargin_1[coffset + 3]) /
          varargin_1[coffset + 6];
  a21 -= denom * varargin_1[r2 + 6];
  a21 /= varargin_1[r2 + 3];
  X_idx_0 = ((co[r1] - denom * varargin_1[r1 + 6]) - a21 * varargin_1[r1 + 3]) /
            varargin_1[r1];
  r0 = sqrt((X_idx_0 * X_idx_0 + a21 * a21) + denom);
  for (coffset = 0; coffset < 3; coffset++) {
    co[coffset] = (X_idx_0 * rot[3 * coffset] + a21 * rot[3 * coffset + 1]) +
                  0.0 * rot[3 * coffset + 2];
  }
  emxInit_real_T(&zlimit, 2);
  emxInit_real_T(&Bn, 2);
  /*  旋转矩阵的逆与转置相等 */
  denom = co[0];
  a21 = co[1];
  pointCloudBase_get_ZLimits(&ptCloud, zlimit);
  normals_data = zlimit->data;
  /*  计算点云z坐标最值 */
  X_idx_0 = (normals_data[0] + normals_data[1]) * 0.5;
  /*     %%
   * ------------------------------最小二乘迭代--------------------------- */
  coffset = Bn->size[0] * Bn->size[1];
  Bn->size[0] = n;
  Bn->size[1] = 7;
  emxEnsureCapacity_real_T(Bn, coffset);
  normals_data = Bn->data;
  r2 = n * 7;
  emxFree_real_T(&zlimit);
  for (coffset = 0; coffset < r2; coffset++) {
    normals_data[coffset] = 1.0;
  }
  coffset = xc->size[0];
  xc->size[0] = n;
  emxEnsureCapacity_real_T(xc, coffset);
  xc_data = xc->data;
  for (coffset = 0; coffset < n; coffset++) {
    xc_data[coffset] = 1.0;
  }
  Xn[0] = co[0];
  Xn[1] = co[1];
  Xn[2] = X_idx_0;
  Xn[3] = coeff_data[6];
  Xn[4] = coeff_data[7];
  Xn[5] = coeff_data[8];
  Xn[6] = r0;
  count = 1;
  exitg1 = false;
  while ((!exitg1) && (r0 > 0.001)) {
    for (i = 0; i < n; i++) {
      Bn_tmp_tmp = x_data[i] - denom;
      b_Bn_tmp_tmp = y_data[i] - a21;
      c_Bn_tmp_tmp = z_data[i] - X_idx_0;
      Bn_tmp = (a0 * Bn_tmp_tmp + b0 * b_Bn_tmp_tmp) + c0 * c_Bn_tmp_tmp;
      normals_data[i] = (2.0 * denom - x_data[i] * 2.0) + 2.0 * a0 * Bn_tmp;
      r2 = Bn->size[0];
      for (coffset = 0; coffset < r2; coffset++) {
        normals_data[coffset + Bn->size[0]] =
            (2.0 * a21 - 2.0 * y_data[i]) + 2.0 * b0 * Bn_tmp;
      }
      normals_data[i + Bn->size[0] * 2] =
          (2.0 * X_idx_0 - 2.0 * z_data[i]) + 2.0 * c0 * Bn_tmp;
      normals_data[i + Bn->size[0] * 3] = -2.0 * Bn_tmp_tmp * Bn_tmp;
      normals_data[i + Bn->size[0] * 4] = -2.0 * b_Bn_tmp_tmp * Bn_tmp;
      normals_data[i + Bn->size[0] * 5] = -2.0 * c_Bn_tmp_tmp * Bn_tmp;
      normals_data[i + Bn->size[0] * 6] = -2.0 * r0;
      xc_data[i] = -((((Bn_tmp_tmp * Bn_tmp_tmp + b_Bn_tmp_tmp * b_Bn_tmp_tmp) +
                       c_Bn_tmp_tmp * c_Bn_tmp_tmp) -
                      Bn_tmp * Bn_tmp) -
                     r0 * r0);
    }
    /*  间接平差求解 */
    r2 = Bn->size[0];
    for (j = 0; j < 7; j++) {
      coffset = j * 7;
      boffset = j * Bn->size[0];
      for (i = 0; i < 7; i++) {
        C[coffset + i] = 0.0;
      }
      for (k = 0; k < r2; k++) {
        denom = normals_data[boffset + k];
        for (i = 0; i < 7; i++) {
          r1 = coffset + i;
          C[r1] += normals_data[i * Bn->size[0] + k] * denom;
        }
      }
    }
    pinv(C, a);
    r2 = Bn->size[0];
    for (i = 0; i < 7; i++) {
      b_C[i] = 0.0;
    }
    for (k = 0; k < r2; k++) {
      for (i = 0; i < 7; i++) {
        b_C[i] += normals_data[i * Bn->size[0] + k] * xc_data[k];
      }
    }
    for (coffset = 0; coffset < 7; coffset++) {
      denom = 0.0;
      for (r1 = 0; r1 < 7; r1++) {
        denom += a[coffset + 7 * r1] * b_C[r1];
      }
      deltX[coffset] = denom;
      Xn[coffset] += denom;
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
