/*
 * File: planefit4.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 23-Mar-2025 19:14:18
 */

/* Include Files */
#include "planefit4.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "combineVectorElements.h"
#include "fminsearch.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static const double dv[629] = {0.0,
                               0.01,
                               0.02,
                               0.03,
                               0.04,
                               0.05,
                               0.06,
                               0.07,
                               0.08,
                               0.09,
                               0.1,
                               0.11,
                               0.12,
                               0.13,
                               0.14,
                               0.15,
                               0.16,
                               0.17,
                               0.18,
                               0.19,
                               0.2,
                               0.21,
                               0.22,
                               0.23,
                               0.24,
                               0.25,
                               0.26,
                               0.27,
                               0.28,
                               0.29,
                               0.3,
                               0.31,
                               0.32,
                               0.33,
                               0.34,
                               0.35000000000000003,
                               0.36,
                               0.37,
                               0.38,
                               0.39,
                               0.4,
                               0.41000000000000003,
                               0.42,
                               0.43,
                               0.44,
                               0.45,
                               0.46,
                               0.47000000000000003,
                               0.48,
                               0.49,
                               0.5,
                               0.51,
                               0.52,
                               0.53,
                               0.54,
                               0.55,
                               0.56,
                               0.57000000000000006,
                               0.58,
                               0.59,
                               0.6,
                               0.61,
                               0.62,
                               0.63,
                               0.64,
                               0.65,
                               0.66,
                               0.67,
                               0.68,
                               0.69000000000000006,
                               0.70000000000000007,
                               0.71,
                               0.72,
                               0.73,
                               0.74,
                               0.75,
                               0.76,
                               0.77,
                               0.78,
                               0.79,
                               0.8,
                               0.81,
                               0.82000000000000006,
                               0.83000000000000007,
                               0.84,
                               0.85,
                               0.86,
                               0.87,
                               0.88,
                               0.89,
                               0.9,
                               0.91,
                               0.92,
                               0.93,
                               0.94000000000000006,
                               0.95000000000000007,
                               0.96,
                               0.97,
                               0.98,
                               0.99,
                               1.0,
                               1.01,
                               1.02,
                               1.03,
                               1.04,
                               1.05,
                               1.06,
                               1.07,
                               1.08,
                               1.09,
                               1.1,
                               1.11,
                               1.12,
                               1.1300000000000001,
                               1.1400000000000001,
                               1.1500000000000001,
                               1.16,
                               1.17,
                               1.18,
                               1.19,
                               1.2,
                               1.21,
                               1.22,
                               1.23,
                               1.24,
                               1.25,
                               1.26,
                               1.27,
                               1.28,
                               1.29,
                               1.3,
                               1.31,
                               1.32,
                               1.33,
                               1.34,
                               1.35,
                               1.36,
                               1.37,
                               1.3800000000000001,
                               1.3900000000000001,
                               1.4000000000000001,
                               1.41,
                               1.42,
                               1.43,
                               1.44,
                               1.45,
                               1.46,
                               1.47,
                               1.48,
                               1.49,
                               1.5,
                               1.51,
                               1.52,
                               1.53,
                               1.54,
                               1.55,
                               1.56,
                               1.57,
                               1.58,
                               1.59,
                               1.6,
                               1.61,
                               1.62,
                               1.6300000000000001,
                               1.6400000000000001,
                               1.6500000000000001,
                               1.6600000000000001,
                               1.67,
                               1.68,
                               1.69,
                               1.7,
                               1.71,
                               1.72,
                               1.73,
                               1.74,
                               1.75,
                               1.76,
                               1.77,
                               1.78,
                               1.79,
                               1.8,
                               1.81,
                               1.82,
                               1.83,
                               1.84,
                               1.85,
                               1.86,
                               1.87,
                               1.8800000000000001,
                               1.8900000000000001,
                               1.9000000000000001,
                               1.9100000000000001,
                               1.92,
                               1.93,
                               1.94,
                               1.95,
                               1.96,
                               1.97,
                               1.98,
                               1.99,
                               2.0,
                               2.0100000000000002,
                               2.02,
                               2.0300000000000002,
                               2.04,
                               2.05,
                               2.06,
                               2.07,
                               2.08,
                               2.09,
                               2.1,
                               2.11,
                               2.12,
                               2.13,
                               2.14,
                               2.15,
                               2.16,
                               2.17,
                               2.18,
                               2.19,
                               2.2,
                               2.21,
                               2.22,
                               2.23,
                               2.24,
                               2.25,
                               2.2600000000000002,
                               2.27,
                               2.2800000000000002,
                               2.29,
                               2.3000000000000003,
                               2.31,
                               2.32,
                               2.33,
                               2.34,
                               2.35,
                               2.36,
                               2.37,
                               2.38,
                               2.39,
                               2.4,
                               2.41,
                               2.42,
                               2.43,
                               2.44,
                               2.45,
                               2.46,
                               2.47,
                               2.48,
                               2.49,
                               2.5,
                               2.5100000000000002,
                               2.52,
                               2.5300000000000002,
                               2.54,
                               2.5500000000000003,
                               2.56,
                               2.57,
                               2.58,
                               2.59,
                               2.6,
                               2.61,
                               2.62,
                               2.63,
                               2.64,
                               2.65,
                               2.66,
                               2.67,
                               2.68,
                               2.69,
                               2.7,
                               2.71,
                               2.72,
                               2.73,
                               2.74,
                               2.75,
                               2.7600000000000002,
                               2.77,
                               2.7800000000000002,
                               2.79,
                               2.8000000000000003,
                               2.81,
                               2.82,
                               2.83,
                               2.84,
                               2.85,
                               2.86,
                               2.87,
                               2.88,
                               2.89,
                               2.9,
                               2.91,
                               2.92,
                               2.93,
                               2.94,
                               2.95,
                               2.96,
                               2.97,
                               2.98,
                               2.99,
                               3.0,
                               3.0100000000000002,
                               3.02,
                               3.0300000000000002,
                               3.04,
                               3.0500000000000003,
                               3.06,
                               3.0700000000000003,
                               3.08,
                               3.09,
                               3.1,
                               3.11,
                               3.12,
                               3.13,
                               3.14,
                               3.1500000000000004,
                               3.16,
                               3.1700000000000004,
                               3.18,
                               3.1900000000000004,
                               3.2,
                               3.21,
                               3.22,
                               3.23,
                               3.24,
                               3.25,
                               3.2600000000000002,
                               3.27,
                               3.2800000000000002,
                               3.29,
                               3.3000000000000003,
                               3.31,
                               3.3200000000000003,
                               3.33,
                               3.3400000000000003,
                               3.35,
                               3.3600000000000003,
                               3.37,
                               3.3800000000000003,
                               3.39,
                               3.4000000000000004,
                               3.41,
                               3.4200000000000004,
                               3.43,
                               3.4400000000000004,
                               3.45,
                               3.4600000000000004,
                               3.47,
                               3.48,
                               3.49,
                               3.5,
                               3.5100000000000002,
                               3.52,
                               3.5300000000000002,
                               3.54,
                               3.5500000000000003,
                               3.56,
                               3.5700000000000003,
                               3.58,
                               3.5900000000000003,
                               3.6,
                               3.6100000000000003,
                               3.62,
                               3.6300000000000003,
                               3.64,
                               3.6500000000000004,
                               3.66,
                               3.6700000000000004,
                               3.68,
                               3.6900000000000004,
                               3.7,
                               3.7100000000000004,
                               3.72,
                               3.73,
                               3.74,
                               3.75,
                               3.7600000000000002,
                               3.77,
                               3.7800000000000002,
                               3.79,
                               3.8000000000000003,
                               3.81,
                               3.8200000000000003,
                               3.83,
                               3.8400000000000003,
                               3.85,
                               3.8600000000000003,
                               3.87,
                               3.8800000000000003,
                               3.89,
                               3.9000000000000004,
                               3.91,
                               3.9200000000000004,
                               3.93,
                               3.9400000000000004,
                               3.95,
                               3.9600000000000004,
                               3.97,
                               3.98,
                               3.99,
                               4.0,
                               4.01,
                               4.02,
                               4.03,
                               4.04,
                               4.0500000000000007,
                               4.0600000000000005,
                               4.07,
                               4.08,
                               4.09,
                               4.1,
                               4.11,
                               4.12,
                               4.1300000000000008,
                               4.1400000000000006,
                               4.15,
                               4.16,
                               4.17,
                               4.18,
                               4.19,
                               4.2,
                               4.2100000000000009,
                               4.2200000000000006,
                               4.23,
                               4.24,
                               4.25,
                               4.26,
                               4.27,
                               4.28,
                               4.29,
                               4.3000000000000007,
                               4.3100000000000005,
                               4.32,
                               4.33,
                               4.34,
                               4.3500000000000005,
                               4.36,
                               4.37,
                               4.38,
                               4.3900000000000006,
                               4.4,
                               4.41,
                               4.42,
                               4.43,
                               4.44,
                               4.45,
                               4.46,
                               4.4700000000000006,
                               4.48,
                               4.49,
                               4.5,
                               4.51,
                               4.5200000000000005,
                               4.53,
                               4.54,
                               4.5500000000000007,
                               4.5600000000000005,
                               4.57,
                               4.58,
                               4.59,
                               4.6000000000000005,
                               4.61,
                               4.62,
                               4.63,
                               4.6400000000000006,
                               4.65,
                               4.66,
                               4.67,
                               4.68,
                               4.69,
                               4.7,
                               4.71,
                               4.7200000000000006,
                               4.73,
                               4.74,
                               4.75,
                               4.76,
                               4.7700000000000005,
                               4.78,
                               4.79,
                               4.8000000000000007,
                               4.8100000000000005,
                               4.82,
                               4.83,
                               4.84,
                               4.8500000000000005,
                               4.86,
                               4.87,
                               4.88,
                               4.8900000000000006,
                               4.9,
                               4.91,
                               4.92,
                               4.93,
                               4.94,
                               4.95,
                               4.96,
                               4.9700000000000006,
                               4.98,
                               4.99,
                               5.0,
                               5.01,
                               5.0200000000000005,
                               5.03,
                               5.04,
                               5.0500000000000007,
                               5.0600000000000005,
                               5.07,
                               5.08,
                               5.09,
                               5.1000000000000005,
                               5.11,
                               5.12,
                               5.13,
                               5.1400000000000006,
                               5.15,
                               5.16,
                               5.17,
                               5.18,
                               5.19,
                               5.2,
                               5.21,
                               5.2200000000000006,
                               5.23,
                               5.24,
                               5.25,
                               5.26,
                               5.2700000000000005,
                               5.28,
                               5.29,
                               5.3000000000000007,
                               5.3100000000000005,
                               5.32,
                               5.33,
                               5.34,
                               5.3500000000000005,
                               5.36,
                               5.37,
                               5.38,
                               5.3900000000000006,
                               5.4,
                               5.41,
                               5.42,
                               5.4300000000000006,
                               5.44,
                               5.45,
                               5.46,
                               5.4700000000000006,
                               5.48,
                               5.49,
                               5.5,
                               5.51,
                               5.5200000000000005,
                               5.53,
                               5.54,
                               5.5500000000000007,
                               5.5600000000000005,
                               5.57,
                               5.58,
                               5.59,
                               5.6000000000000005,
                               5.61,
                               5.62,
                               5.63,
                               5.6400000000000006,
                               5.65,
                               5.66,
                               5.67,
                               5.6800000000000006,
                               5.69,
                               5.7,
                               5.71,
                               5.7200000000000006,
                               5.73,
                               5.74,
                               5.75,
                               5.76,
                               5.7700000000000005,
                               5.78,
                               5.79,
                               5.8000000000000007,
                               5.8100000000000005,
                               5.82,
                               5.83,
                               5.84,
                               5.8500000000000005,
                               5.86,
                               5.87,
                               5.88,
                               5.8900000000000006,
                               5.9,
                               5.91,
                               5.92,
                               5.9300000000000006,
                               5.94,
                               5.95,
                               5.96,
                               5.9700000000000006,
                               5.98,
                               5.99,
                               6.0,
                               6.01,
                               6.0200000000000005,
                               6.03,
                               6.04,
                               6.05,
                               6.0600000000000005,
                               6.07,
                               6.08,
                               6.09,
                               6.1000000000000005,
                               6.11,
                               6.12,
                               6.13,
                               6.1400000000000006,
                               6.15,
                               6.16,
                               6.17,
                               6.1800000000000006,
                               6.19,
                               6.2,
                               6.21,
                               6.2200000000000006,
                               6.23,
                               6.24,
                               6.25,
                               6.2600000000000007,
                               6.2700000000000005,
                               6.28};

/* Function Definitions */
/*
 * Points 输入点 3*n
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  BJD 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                const emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                const emxArray_real_T *Points4
 *                const double BoundPoint1[3]
 *                const double BoundPoint2[3]
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[4]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void b_planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
                 const emxArray_real_T *Points3, const emxArray_real_T *Points4,
                 const double BoundPoint1[3], const double BoundPoint2[3],
                 emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints,
                 double MaxDis[4], emxArray_real_T *distancesFianal)
{
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_Points2;
  emxArray_real_T *distancess1;
  emxArray_real_T *distancess2;
  emxArray_real_T *distancess3;
  emxArray_real_T *y;
  double b_PP[72];
  double PP[24];
  double PlaneParaOutP_data[16];
  double cross_vectors[12];
  double A[9];
  double OptPara2[5];
  double b_dv[3];
  double v[3];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  double OptErr;
  double PlaneParaOut1_idx_0;
  double PlaneParaOut2_idx_0;
  double PlaneParaOut2_idx_2;
  double absxk;
  double c;
  double d;
  double ddd2;
  double ddd4;
  double scale;
  double t;
  double *PlaneParaOut_data;
  double *distancesFianal_data;
  double *distancess1_data;
  double *distancess2_data;
  double *distancess3_data;
  int k;
  int ll;
  int loop_ub;
  int nx;
  int xpageoffset;
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  k = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(PlaneParaOut, k);
  PlaneParaOut_data = PlaneParaOut->data;
  for (k = 0; k < 16; k++) {
    PlaneParaOut_data[k] = 0.0;
  }
  /*   新平行函数 */
  /*  % % num = 180; */
  /*  % % sp = linspace(0,2*pi,num); */
  /*  % % sz = linspace(0,2*pi,num); */
  /*  % %  */
  /*  % % OptErr = 99999; */
  /*  % %  */
  /*  % % OptPara = zeros(1,5); */
  /*  % % OptAllErr2 =  zeros(size(Points2,2),1); */
  /*  % % OptAllErr4 =  zeros(size(Points4,2),1); */
  /*  % %  */
  /*  % % for i = 1:num */
  /*  % %     for j = 1:num */
  /*  % %         [x0,y0,z0] = sph2cart(sp(i),sz(j),1); */
  /*  % %         v = [x0, y0, z0]./ sqrt( x0^2+y0^2+z0^2); */
  /*  % %         aaa = v(1); */
  /*  % %         bbb = v(2); */
  /*  % %         ccc = v(3); */
  /*  % %         fun2 = @(dd) sum(abs(aaa * Points2(1,:) + bbb * Points2(2,:) +
   * ccc * Points2(3,:) + dd)); */
  /*  % %         d_opt4 = fminsearch(fun2, 0); */
  /*  % %  */
  /*  % %         fun4 = @(dd) sum(abs(aaa * Points4(1,:) + bbb * Points4(2,:) +
   * ccc * Points4(3,:) + dd)); */
  /*  % %         d_opt4 = fminsearch(fun4, 0); */
  /*  % %  */
  /*  % %         % 计算每个点到平面的距离 */
  /*  % %         distancess2 = aaa * Points2(1,:) + bbb * Points2(2,:) + ccc *
   * Points2(3,:) + d_opt4; */
  /*  % %         distancess4 = aaa * Points4(1,:) + bbb * Points4(2,:) + ccc *
   * Points4(3,:) + d_opt4; */
  /*  % %  */
  /*  % %         disAll = sum(abs(distancess2))+sum(abs(distancess4)); */
  /*  % %  */
  /*  % %         if disAll < OptErr */
  /*  % %             OptPara = [v,d_opt4,d_opt4]; */
  /*  % %             OptAllErr2 = distancess2; */
  /*  % %             OptAllErr4 = distancess4; */
  /*  % %             OptErr = disAll; */
  /*  % %         end */
  /*  % %  */
  /*  % %     end */
  /*  % % end */
  /*  % %  */
  /*  % % % 选择一个基准向量，通常选择 [1, 0, 0] 或 [0, 1, 0]，避免与法向量平行
   */
  /*  % % if OptPara(1) ~= 0 */
  /*  % %     % 如果法向量的 x 分量不为零，选择 [1, 0, 0] 作为基准 */
  /*  % %     v1 = [1, 0, 0]; */
  /*  % % else */
  /*  % %     % 否则，选择 [0, 1, 0] 作为基准 */
  /*  % %     v1 = [0, 1, 0]; */
  /*  % % end */
  /*  % % % 使用叉积计算垂直于法向量的第一个基底向量 */
  /*  % % v1 = cross(OptPara(1:3), v1); */
  /*  % % % 归一化 v1 */
  /*  % % v1 = v1 / norm(v1); */
  /*  % % % 第二个垂直基底向量可以通过叉积获得 */
  /*  % % v2 = cross(OptPara(1:3), v1); */
  /*  % % % 归一化 v2 */
  /*  % % v2 = v2 / norm(v2); */
  /*  % %  */
  /*  % % OptErr = 99999; */
  /*  % %  */
  /*  % % OptPara2 = zeros(1,5); */
  /*  % % OptAllErr1 =  zeros(size(Points1,2),1); */
  /*  % % OptAllErr3 =  zeros(size(Points3,2),1); */
  /*  % % VV = []; */
  /*  % % thet = 0:0.01:2*pi; */
  /*  % % for ll = 1:length(thet) */
  /*  % %  */
  /*  % %     v = v1.*cos(thet(ll))+v2.*sin(thet(ll)); */
  /*  % %     VV = [VV;v]; */
  /*  % %     v=v./norm(v); */
  /*  % %  */
  /*  % %     aaa = v(1); */
  /*  % %     bbb = v(2); */
  /*  % %     ccc = v(3); */
  /*  % %  */
  /*  % %     fun1 = @(dd) sum(abs(aaa * Points1(1,:) + bbb * Points1(2,:) + ccc
   * * Points1(3,:) + dd)); */
  /*  % %     d_opt1 = fminsearch(fun1, 0); */
  /*  % %  */
  /*  % %     fun3 = @(dd) sum(abs(aaa * Points3(1,:) + bbb * Points3(2,:) + ccc
   * * Points3(3,:) + dd)); */
  /*  % %     d_opt3 = fminsearch(fun3, 0); */
  /*  % %  */
  /*  % %     % 计算每个点到平面的距离 */
  /*  % %     distancess1 = aaa * Points1(1,:) + bbb * Points1(2,:) + ccc *
   * Points1(3,:) + d_opt1; */
  /*  % %     distancess3 = aaa * Points3(1,:) + bbb * Points3(2,:) + ccc *
   * Points3(3,:) + d_opt3; */
  /*  % %  */
  /*  % %     disAll = sum(abs(distancess1))+sum(abs(distancess3)); */
  /*  % %  */
  /*  % %     if disAll < OptErr */
  /*  % %         OptPara2 = [v,d_opt1,d_opt3]; */
  /*  % %         OptAllErr1 = distancess1; */
  /*  % %         OptAllErr3 = distancess3; */
  /*  % %         OptErr = disAll; */
  /*  % %         ooo = ll; */
  /*  % %     end */
  /*  % %  */
  /*  % % end */
  /*  % %  */
  /*  % % [n_fit1, d_fit1] = fit_perpendicular_plane(Points1', OptPara(1:4)) */
  /*  % %  */
  /*  % % [n_fit3, d_fit3] = fit_perpendicular_plane(Points3', OptPara(1:4)) */
  /*  % %  */
  /*  % % PlaneParaOut2(:,1) = OptPara2(1:4)'; */
  /*  % % PlaneParaOut2(:,2) = OptPara(1:4)'; */
  /*  % % PlaneParaOut2(:,3) = OptPara2([1,2,3,5])'; */
  /*  % % PlaneParaOut2(:,4) = OptPara([1,2,3,5])'; */
  /*  % %  */
  /*  % % T1 = max(distancess1); */
  /*  % % T2 = max(distancess2); */
  /*  % % T3 = max(distancess3); */
  /*  % % T4 = max(distancess2); */
  /*  % %  */
  /*  % % MaxDis = [T1,T2,T3,T4]; */
  /*  % % distancesFianal = [distancess1,distancess2,distancess3,distancess4];
   */
  /*  旧拟合 */
  /*  % %  */
  /*  % % for i =1:4 */
  /*  % %     Points = PointAll{i}; */
  /*  % %     % 平面拟合 */
  /*  % %     pointss = Points'; */
  /*  % %  */
  /*  % %     Cnum = 1:length(pointss); */
  /*  % %     bestDist = 99999;  % 最优内点距离 */
  /*  % %  */
  /*  % %     C = nchoosek(Cnum,3); */
  /*  % %  */
  /*  % %     for j = 1:length(C) */
  /*  % %         % 随机选择三个点 */
  /*  % %         sampleIdx = C(j,:); */
  /*  % %         samplePoints = pointss(sampleIdx, :); */
  /*  % %  */
  /*  % %         % 计算平面模型 */
  /*  % %         A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)]; */
  /*  % %         coefficients = A \ samplePoints(:,3); */
  /*  % %         a = coefficients(1); */
  /*  % %         b = coefficients(2); */
  /*  % %         d = coefficients(3); */
  /*  % %         c=-1; */
  /*  % %
   * distances=abs([a,b,c,d]*[pointss,ones(size(pointss,1),1)]')/sqrt(a*a+b*b+c*c);
   */
  /*  % %  */
  /*  % %         % 确定内点 */
  /*  % %         inlierIdx = find(distances < distanceThreshold); */
  /*  % %  */
  /*  % %         % 更新最优平面模型 */
  /*  % %         if mean(distances) < bestDist */
  /*  % %             bestDist = mean(distances); */
  /*  % %             inlierIdxFinal{i} = inlierIdx; */
  /*  % %             distancesFianal1{i} = distances; */
  /*  % %         end */
  /*  % %  */
  /*  % %     end */
  /*  % %     % 重新计算最终平面模型，使用所有内点 */
  /*  % %  */
  /*  % %     inlierPoints = pointss(inlierIdxFinal{i}, :); */
  /*  % %  */
  /*  % %     x = inlierPoints(:,1); */
  /*  % %     y = inlierPoints(:,2); */
  /*  % %     z = inlierPoints(:,3); */
  /*  % %  */
  /*  % %     PIner = [x,y,z]; */
  /*  % %  */
  /*  % %     threshold  = 2.5;
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2.5度阈值 */
  /*  % %     % Fit a plane through the points */
  /*  % %     [~, ~, V] = svd(PIner - mean(PIner, 1)); */
  /*  % %     normal = V(:, 3); % Normal vector of the plane */
  /*  % %  */
  /*  % %     % Calculate angle between normal vector and z-axis */
  /*  % %     angle = acosd(abs(dot(normal, [0; 0; 1]))); */
  /*  % %     angle = abs(90-angle); */
  /*  % %  */
  /*  % %     % Check if angle is below threshold */
  /*  % %     if angle < threshold */
  /*  % %         c = 0; */
  /*  % %         bb=polyfit(x,y,1); */
  /*  % %         % 拟合，其实是线性回归，但可以用来拟合平面 */
  /*  % %         a = bb(1); */
  /*  % %         b = -1; */
  /*  % %         d = bb(2); */
  /*  % %     else */
  /*  % %         A = [inlierPoints(:,1), inlierPoints(:,2),
   * ones(size(inlierPoints(:,1)))]; */
  /*  % %         coefficients = A \ inlierPoints(:,3); */
  /*  % %         a = coefficients(1); */
  /*  % %         b = coefficients(2); */
  /*  % %         d = coefficients(3); */
  /*  % %         c=-1; */
  /*  % %     end */
  /*  % %     PlaneParaOut(:,i) = [a;b;c;d]; */
  /*  % % end */
  /*  % %  */
  /*  % % %%%%%%%%% 测试 %%%%%%%%%%%% */
  /*  % %  */
  /*  % % PlaneParaOut(1,2) = 0; */
  /*  % % PlaneParaOut(2,2) = 0; */
  /*  % % % PlaneParaOut(3,2) = 1; */
  /*  % % PlaneParaOut(4,2) = mean(Points2(3,:)); */
  /*  % %  */
  /*  % % PlaneParaOut(1,4) = 0; */
  /*  % % PlaneParaOut(2,4) = 0; */
  /*  % % % PlaneParaOut(3,4) = 1; */
  /*  % % PlaneParaOut(4,4) = mean(Points4(3,:)); */
  /*  % %  */
  /*  % % % PlaneParaOut(1,3) = PlaneParaOut(1,1) ; */
  /*  % %  */
  /*  % % id1 = inlierIdxFinal{1}; */
  /*  % % id2 = inlierIdxFinal{2}; */
  /*  % % id3 = inlierIdxFinal{3}; */
  /*  % % id4 = inlierIdxFinal{4}; */
  /*  % %  */
  /*  % % tt1 = distancesFianal1{1}; */
  /*  % % tt2 = distancesFianal1{2}; */
  /*  % % tt3 = distancesFianal1{3}; */
  /*  % % tt4 = distancesFianal1{4}; */
  /*  % %  */
  /*  % % T1 = max(tt1(id1)); */
  /*  % % T2 = max(tt2(id2)); */
  /*  % % T3 = max(tt3(id3)); */
  /*  % % T4 = max(tt4(id4)); */
  /*  % %  */
  /*  % % MaxDis = [T1,T2,T3,T4]; */
  /*  % % distancesFianal =
   * [distancesFianal1{1},distancesFianal1{2},distancesFianal1{3},distancesFianal1{4}];
   */
  /*  % % %%%%%%%%% 测试 %%%%%%%%%%%% */
  /*  % %  */
  /*  % %
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  % % % % % % % % 平面方程的系数输出 */
  /*  % % % % % % %  */
  /*  % % % % % % % xfit = zeros(1,8); */
  /*  % % % % % % % yfit = zeros(1,8); */
  /*  % % % % % % % zfit = zeros(1,8); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 前2个面的交点 %%%% */
  /*  % % % % % % % % 计算交线 */
  /*  % % % % % % % x_val = (max(x)+min(x))./2; */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,2),x_val); */
  /*  % % % % % % % % 找到边界，确定三角点 */
  /*  % % % % % % % [PointTri] =
   * GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(1) = PointTri(1,1); */
  /*  % % % % % % % yfit(1) = PointTri(2,1); */
  /*  % % % % % % % zfit(1) = PointTri(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri2] =
   * GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(3) = PointTri2(1,1); */
  /*  % % % % % % % yfit(3) = PointTri2(2,1); */
  /*  % % % % % % % zfit(3) = PointTri2(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第2、3个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,2),PlaneParaOut(:,3),x_val); */
  /*  % % % % % % % % 找到边界，确定三角点 */
  /*  % % % % % % % [PointTri3] =
   * GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(5) = PointTri3(1,1); */
  /*  % % % % % % % yfit(5) = PointTri3(2,1); */
  /*  % % % % % % % zfit(5) = PointTri3(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri4] =
   * GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(6) = PointTri4(1,1); */
  /*  % % % % % % % yfit(6) = PointTri4(2,1); */
  /*  % % % % % % % zfit(6) = PointTri4(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第3、4个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,3),PlaneParaOut(:,4),x_val); */
  /*  % % % % % % % [PointTri5] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(7) = PointTri5(1,1); */
  /*  % % % % % % % yfit(7) = PointTri5(2,1); */
  /*  % % % % % % % zfit(7) = PointTri5(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri6] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(8) = PointTri6(1,1); */
  /*  % % % % % % % yfit(8) = PointTri6(2,1); */
  /*  % % % % % % % zfit(8) = PointTri6(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第1、4个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,4),x_val); */
  /*  % % % % % % % [PointTri7] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(2) = PointTri7(1,1); */
  /*  % % % % % % % yfit(2) = PointTri7(2,1); */
  /*  % % % % % % % zfit(2) = PointTri7(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri8] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(4) = PointTri8(1,1); */
  /*  % % % % % % % yfit(4) = PointTri8(2,1); */
  /*  % % % % % % % zfit(4) = PointTri8(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % BJD =
   * [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);... */
  /*  % % % % % % % yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
   */
  /*  % % % % % % % zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]])]; */
  /*  % % % % % % %  */
  /*  % % % % % % % % 取八个点 */
  /*  % % % % % % % Pdd = BJD(:,[1:3,6,9,16:18]); */
  /*  % % % % % % % P1 = Pdd(:,1); */
  /*  % % % % % % % P2 = Pdd(:,2); */
  /*  % % % % % % % P3 = Pdd(:,3); */
  /*  % % % % % % % P4 = Pdd(:,4); */
  /*  % % % % % % % P5 = Pdd(:,5); */
  /*  % % % % % % % P6 = Pdd(:,6); */
  /*  % % % % % % % P7 = Pdd(:,7); */
  /*  % % % % % % % P8 = Pdd(:,8); */
  /*  % % % % % % %  */
  /*  % % % % % % % % 计算投影点 */
  /*  % % % % % % % [xN1,yN1,zN1] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P1,P3); */
  /*  % % % % % % % PP1 = [xN1;yN1;zN1]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN2,yN2,zN2] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P2,P4); */
  /*  % % % % % % % PP2 = [xN2;yN2;zN2]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN3,yN3,zN3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P1,P3); */
  /*  % % % % % % % PP3 = [xN3;yN3;zN3]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN4,yN4,zN4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P2,P4); */
  /*  % % % % % % % PP4 = [xN4;yN4;zN4]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN5,yN5,zN5] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P5,P6); */
  /*  % % % % % % % PP5 = [xN5;yN5;zN5]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN6,yN6,zN6] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P5,P6); */
  /*  % % % % % % % PP6 = [xN6;yN6;zN6]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN7,yN7,zN7] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P7,P8); */
  /*  % % % % % % % PP7 = [xN7;yN7;zN7]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN8,yN8,zN8] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P7,P8); */
  /*  % % % % % % % PP8 = [xN8;yN8;zN8]; */
  /*  % %  */
  /*  % %
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  强行令c=1 */
  emxInit_real_T(&b_Points2, 2);
  k = b_Points2->size[0] * b_Points2->size[1];
  b_Points2->size[0] = 1;
  b_Points2->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(b_Points2, k);
  distancesFianal_data = b_Points2->data;
  xpageoffset = Points2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = Points2_data[3 * k + 2];
  }
  ddd2 = b_combineVectorElements(b_Points2) / (double)Points2->size[1];
  k = b_Points2->size[0] * b_Points2->size[1];
  b_Points2->size[0] = 1;
  b_Points2->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(b_Points2, k);
  distancesFianal_data = b_Points2->data;
  xpageoffset = Points4->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = Points4_data[3 * k + 2];
  }
  ddd4 = b_combineVectorElements(b_Points2) / (double)Points4->size[1];
  emxInit_real_T(&distancess2, 2);
  k = distancess2->size[0] * distancess2->size[1];
  distancess2->size[0] = 1;
  distancess2->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(distancess2, k);
  distancess2_data = distancess2->data;
  xpageoffset = Points2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancess2_data[k] = Points2_data[3 * k + 2] - ddd2;
  }
  /*  拟合，其实是线性回归，但可以用来拟合平面 */
  OptErr = 9999.0;
  for (k = 0; k < 5; k++) {
    OptPara2[k] = 0.0;
  }
  xpageoffset = Points1->size[1];
  loop_ub = Points3->size[1];
  emxInit_real_T(&distancess1, 2);
  distancess1_data = distancess1->data;
  emxInit_real_T(&distancess3, 2);
  distancess3_data = distancess3->data;
  emxInit_real_T(&y, 2);
  for (ll = 0; ll < 629; ll++) {
    d = dv[ll];
    PlaneParaOut1_idx_0 = cos(d);
    PlaneParaOut2_idx_0 = sin(d);
    scale = 3.3121686421112381E-170;
    d = PlaneParaOut1_idx_0 + 0.0 * PlaneParaOut2_idx_0;
    v[0] = d;
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      PlaneParaOut2_idx_2 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      PlaneParaOut2_idx_2 = t * t;
    }
    d = 0.0 * PlaneParaOut1_idx_0 + PlaneParaOut2_idx_0;
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    PlaneParaOut2_idx_2 = scale * sqrt(PlaneParaOut2_idx_2);
    v[0] /= PlaneParaOut2_idx_2;
    v[1] = d / PlaneParaOut2_idx_2;
    v[2] = (0.0 * PlaneParaOut1_idx_0 + 0.0 * PlaneParaOut2_idx_0) /
           PlaneParaOut2_idx_2;
    scale = fminsearch(v[0], Points1, v[1], v[2]);
    absxk = fminsearch(v[0], Points3, v[1], v[2]);
    /*  计算每个点到平面的距离 */
    k = distancess1->size[0] * distancess1->size[1];
    distancess1->size[0] = 1;
    distancess1->size[1] = Points1->size[1];
    emxEnsureCapacity_real_T(distancess1, k);
    distancess1_data = distancess1->data;
    for (k = 0; k < xpageoffset; k++) {
      distancess1_data[k] =
          ((v[0] * Points1_data[3 * k] + v[1] * Points1_data[3 * k + 1]) +
           v[2] * Points1_data[3 * k + 2]) +
          scale;
    }
    k = distancess3->size[0] * distancess3->size[1];
    distancess3->size[0] = 1;
    distancess3->size[1] = Points3->size[1];
    emxEnsureCapacity_real_T(distancess3, k);
    distancess3_data = distancess3->data;
    for (k = 0; k < loop_ub; k++) {
      distancess3_data[k] =
          ((v[0] * Points3_data[3 * k] + v[1] * Points3_data[3 * k + 1]) +
           v[2] * Points3_data[3 * k + 2]) +
          absxk;
    }
    nx = distancess1->size[1];
    k = b_Points2->size[0] * b_Points2->size[1];
    b_Points2->size[0] = 1;
    b_Points2->size[1] = distancess1->size[1];
    emxEnsureCapacity_real_T(b_Points2, k);
    distancesFianal_data = b_Points2->data;
    for (k = 0; k < nx; k++) {
      distancesFianal_data[k] = fabs(distancess1_data[k]);
    }
    nx = distancess3->size[1];
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = distancess3->size[1];
    emxEnsureCapacity_real_T(y, k);
    distancesFianal_data = y->data;
    for (k = 0; k < nx; k++) {
      distancesFianal_data[k] = fabs(distancess3_data[k]);
    }
    t = b_combineVectorElements(b_Points2) + b_combineVectorElements(y);
    if (t < OptErr) {
      OptPara2[0] = v[0];
      OptPara2[1] = v[1];
      OptPara2[3] = scale;
      OptPara2[4] = absxk;
      OptErr = t;
    }
  }
  emxFree_real_T(&b_Points2);
  emxFree_real_T(&y);
  PlaneParaOut_data[0] = OptPara2[0];
  PlaneParaOut_data[1] = OptPara2[1];
  PlaneParaOut_data[2] = 0.0;
  PlaneParaOut_data[3] = OptPara2[3];
  PlaneParaOut_data[4] = 0.0;
  PlaneParaOut_data[5] = 0.0;
  PlaneParaOut_data[6] = -1.0;
  PlaneParaOut_data[7] = ddd2;
  PlaneParaOut_data[8] = OptPara2[0];
  PlaneParaOut_data[9] = OptPara2[1];
  PlaneParaOut_data[10] = 0.0;
  PlaneParaOut_data[11] = OptPara2[4];
  PlaneParaOut_data[12] = 0.0;
  PlaneParaOut_data[13] = 0.0;
  PlaneParaOut_data[14] = -1.0;
  PlaneParaOut_data[15] = ddd4;
  scale = maximum(distancess2);
  MaxDis[0] = maximum(distancess1);
  MaxDis[1] = scale;
  MaxDis[2] = maximum(distancess3);
  MaxDis[3] = scale;
  k = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  distancesFianal->size[1] =
      ((distancess1->size[1] + distancess2->size[1]) + distancess3->size[1]) +
      Points4->size[1];
  emxEnsureCapacity_real_T(distancesFianal, k);
  distancesFianal_data = distancesFianal->data;
  xpageoffset = distancess1->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = distancess1_data[k];
  }
  xpageoffset = distancess2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k + distancess1->size[1]] = distancess2_data[k];
  }
  xpageoffset = distancess3->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[(k + distancess1->size[1]) + distancess2->size[1]] =
        distancess3_data[k];
  }
  xpageoffset = Points4->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[((k + distancess1->size[1]) + distancess2->size[1]) +
                         distancess3->size[1]] = Points4_data[3 * k + 2] - ddd4;
  }
  emxFree_real_T(&distancess3);
  emxFree_real_T(&distancess1);
  emxFree_real_T(&distancess2);
  /*   */
  emxInit_real_T(&b_PlaneParaOut, 2);
  k = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 4;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, k);
  distancesFianal_data = b_PlaneParaOut->data;
  for (k = 0; k < 4; k++) {
    for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
      distancesFianal_data[xpageoffset + b_PlaneParaOut->size[0] * k] =
          PlaneParaOut_data[k + 4 * xpageoffset];
    }
  }
  for (k = 0; k < 16; k++) {
    PlaneParaOutP_data[k] = distancesFianal_data[k];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&cross_vectors[0], 0, 12U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
    if (xpageoffset + 1 < 4) {
      scale = PlaneParaOutP_data[xpageoffset + 9];
      absxk = PlaneParaOutP_data[xpageoffset + 5];
      t = PlaneParaOutP_data[xpageoffset + 8];
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[xpageoffset + 4];
      cross_vectors[xpageoffset] = PlaneParaOut1_idx_0 * scale - absxk * t;
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[xpageoffset + 1];
      cross_vectors[xpageoffset + 4] =
          PlaneParaOut2_idx_0 * t - PlaneParaOutP_data[xpageoffset] * scale;
      cross_vectors[xpageoffset + 8] =
          PlaneParaOutP_data[xpageoffset] * absxk -
          PlaneParaOut2_idx_0 * PlaneParaOut1_idx_0;
    } else {
      cross_vectors[3] = PlaneParaOutP_data[7] * PlaneParaOutP_data[8] -
                         PlaneParaOutP_data[4] * PlaneParaOutP_data[11];
      cross_vectors[7] = PlaneParaOutP_data[0] * PlaneParaOutP_data[11] -
                         PlaneParaOutP_data[3] * PlaneParaOutP_data[8];
      cross_vectors[11] = PlaneParaOutP_data[3] * PlaneParaOutP_data[4] -
                          PlaneParaOutP_data[0] * PlaneParaOutP_data[7];
      /*  最后一个与第一个相邻 */
    }
    scale = 3.3121686421112381E-170;
    absxk = fabs(cross_vectors[xpageoffset]);
    if (absxk > 3.3121686421112381E-170) {
      PlaneParaOut2_idx_2 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      PlaneParaOut2_idx_2 = t * t;
    }
    absxk = fabs(cross_vectors[xpageoffset + 4]);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    absxk = fabs(cross_vectors[xpageoffset + 8]);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    PlaneParaOut2_idx_2 = scale * sqrt(PlaneParaOut2_idx_2);
    cross_vectors[xpageoffset] /= PlaneParaOut2_idx_2;
    cross_vectors[xpageoffset + 4] /= PlaneParaOut2_idx_2;
    cross_vectors[xpageoffset + 8] /= PlaneParaOut2_idx_2;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  d = cross_vectors[0];
  absxk = cross_vectors[4];
  t = cross_vectors[8];
  for (xpageoffset = 0; xpageoffset < 3; xpageoffset++) {
    PlaneParaOut1_idx_0 = cross_vectors[xpageoffset + 1];
    PlaneParaOut2_idx_0 = cross_vectors[xpageoffset + 5];
    scale = cross_vectors[xpageoffset + 9];
    if ((d * PlaneParaOut1_idx_0 + absxk * PlaneParaOut2_idx_0) + t * scale <
        0.0) {
      /*  如果方向相反 */
      cross_vectors[xpageoffset + 1] = -PlaneParaOut1_idx_0;
      PlaneParaOut2_idx_0 = -PlaneParaOut2_idx_0;
      cross_vectors[xpageoffset + 5] = PlaneParaOut2_idx_0;
      scale = -scale;
      cross_vectors[xpageoffset + 9] = scale;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  /*  计算顶面方程的 d 值 */
  ddd4 = 0.0;
  /*  计算底面方程的 d 值 */
  c = 0.0;
  for (loop_ub = 0; loop_ub < 3; loop_ub++) {
    xpageoffset = loop_ub << 2;
    d = (((cross_vectors[xpageoffset] + cross_vectors[xpageoffset + 1]) +
          cross_vectors[xpageoffset + 2]) +
         cross_vectors[xpageoffset + 3]) /
        4.0;
    v[loop_ub] = d;
    ddd4 += d * BoundPoint1[loop_ub];
    c += d * BoundPoint2[loop_ub];
  }
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 24U * sizeof(double));
  /*  计算顶面和底面的4个顶点 */
  d = v[0];
  absxk = v[1];
  t = v[2];
  A[2] = d;
  A[5] = absxk;
  A[8] = t;
  for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
    /*  顶面顶点 */
    if (xpageoffset + 1 < 4) {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[xpageoffset];
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[xpageoffset + 1];
      scale = PlaneParaOutP_data[xpageoffset + 4];
      absxk = PlaneParaOutP_data[xpageoffset + 5];
      t = PlaneParaOutP_data[xpageoffset + 8];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[xpageoffset + 9];
      ddd2 = PlaneParaOutP_data[xpageoffset + 12];
      OptErr = PlaneParaOutP_data[xpageoffset + 13];
    } else {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[3];
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[0];
      scale = PlaneParaOutP_data[7];
      absxk = PlaneParaOutP_data[4];
      t = PlaneParaOutP_data[11];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[8];
      ddd2 = PlaneParaOutP_data[15];
      OptErr = PlaneParaOutP_data[12];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = PlaneParaOut1_idx_0;
    A[1] = PlaneParaOut2_idx_0;
    A[3] = scale;
    A[4] = absxk;
    A[6] = t;
    A[7] = PlaneParaOut2_idx_2;
    v[0] = -ddd2;
    v[1] = -OptErr;
    v[2] = ddd4;
    b_mldivide(A, v, b_dv);
    PP[xpageoffset] = b_dv[0];
    PP[xpageoffset + 8] = b_dv[1];
    PP[xpageoffset + 16] = b_dv[2];
    /*  求底面和两个相邻侧面的交线 */
    v[0] = -ddd2;
    v[1] = -OptErr;
    v[2] = c;
    b_mldivide(A, v, b_dv);
    PP[xpageoffset + 4] = b_dv[0];
    PP[xpageoffset + 12] = b_dv[1];
    PP[xpageoffset + 20] = b_dv[2];
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(1,1); B1 = PlaneParaOutP(1,2); C1 =PlaneParaOutP(1,3);
   * D1 = PlaneParaOutP(1,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(2,1); B2 = PlaneParaOutP(2,2); C2 =PlaneParaOutP(2,3);
   * D2 = PlaneParaOutP(2,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn1,yn1,zn1] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP1 = [xn1,yn1,zn1]; */
  /*  [xn2,yn2,zn2] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP3 = [xn2,yn2,zn2]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(2,1); B1 = PlaneParaOutP(2,2); C1 =PlaneParaOutP(2,3);
   * D1 = PlaneParaOutP(2,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(3,1); B2 = PlaneParaOutP(3,2); C2 =PlaneParaOutP(3,3);
   * D2 = PlaneParaOutP(3,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP5 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP6 = [xn4,yn4,zn4]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(3,1); B1 = PlaneParaOutP(3,2); C1 =PlaneParaOutP(3,3);
   * D1 = PlaneParaOutP(3,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(4,1); B2 = PlaneParaOutP(4,2); C2 =PlaneParaOutP(4,3);
   * D2 = PlaneParaOutP(4,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP7 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP8 = [xn4,yn4,zn4]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(4,1); B1 = PlaneParaOutP(4,2); C1 =PlaneParaOutP(4,3);
   * D1 = PlaneParaOutP(4,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(1,1); B2 = PlaneParaOutP(1,2); C2 =PlaneParaOutP(1,3);
   * D2 = PlaneParaOutP(1,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP2 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP4 = [xn4,yn4,zn4]; */
  /*   */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  temp1 = [PP1,PP2,PP3,PP4,PP5,PP6,PP7,PP8]'; */
  /*  temp2 = [PPP1;PPP2;PPP3;PPP4;PPP5;PPP6;PPP7;PPP8]; */
  /*  TrianglePoints =
   * [PPP1;PPP2;PPP3;PPP2;PPP3;PPP4;PPP1;PPP3;PPP5;PPP3;PPP5;PPP6;PPP5;PPP6;PPP7;PPP6;PPP7;PPP8;PPP2;PPP4;PPP7;PPP4;PPP7;PPP8]';
   */
  b_PP[0] = PP[0];
  b_PP[3] = PP[3];
  b_PP[6] = PP[4];
  b_PP[9] = PP[3];
  b_PP[12] = PP[4];
  b_PP[15] = PP[7];
  b_PP[18] = PP[0];
  b_PP[21] = PP[4];
  b_PP[24] = PP[1];
  b_PP[27] = PP[4];
  b_PP[30] = PP[1];
  b_PP[33] = PP[5];
  b_PP[36] = PP[1];
  b_PP[39] = PP[5];
  b_PP[42] = PP[2];
  b_PP[45] = PP[5];
  b_PP[48] = PP[2];
  b_PP[51] = PP[6];
  b_PP[54] = PP[3];
  b_PP[57] = PP[7];
  b_PP[60] = PP[2];
  b_PP[63] = PP[7];
  b_PP[66] = PP[2];
  b_PP[69] = PP[6];
  b_PP[1] = PP[8];
  b_PP[4] = PP[11];
  b_PP[7] = PP[12];
  b_PP[10] = PP[11];
  b_PP[13] = PP[12];
  b_PP[16] = PP[15];
  b_PP[19] = PP[8];
  b_PP[22] = PP[12];
  b_PP[25] = PP[9];
  b_PP[28] = PP[12];
  b_PP[31] = PP[9];
  b_PP[34] = PP[13];
  b_PP[37] = PP[9];
  b_PP[40] = PP[13];
  b_PP[43] = PP[10];
  b_PP[46] = PP[13];
  b_PP[49] = PP[10];
  b_PP[52] = PP[14];
  b_PP[55] = PP[11];
  b_PP[58] = PP[15];
  b_PP[61] = PP[10];
  b_PP[64] = PP[15];
  b_PP[67] = PP[10];
  b_PP[70] = PP[14];
  b_PP[2] = PP[16];
  b_PP[5] = PP[19];
  b_PP[8] = PP[20];
  b_PP[11] = PP[19];
  b_PP[14] = PP[20];
  b_PP[17] = PP[23];
  b_PP[20] = PP[16];
  b_PP[23] = PP[20];
  b_PP[26] = PP[17];
  b_PP[29] = PP[20];
  b_PP[32] = PP[17];
  b_PP[35] = PP[21];
  b_PP[38] = PP[17];
  b_PP[41] = PP[21];
  b_PP[44] = PP[18];
  b_PP[47] = PP[21];
  b_PP[50] = PP[18];
  b_PP[53] = PP[22];
  b_PP[56] = PP[19];
  b_PP[59] = PP[23];
  b_PP[62] = PP[18];
  b_PP[65] = PP[23];
  b_PP[68] = PP[18];
  b_PP[71] = PP[22];
  k = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 24;
  emxEnsureCapacity_real_T(TrianglePoints, k);
  distancesFianal_data = TrianglePoints->data;
  for (k = 0; k < 72; k++) {
    distancesFianal_data[k] = b_PP[k];
  }
}

/*
 * Points 输入点 3*n
 *  BoundPoint1 边界点1
 *  BoundPoint2 边界点2
 *  PlaneParaOut 平面参数4*n
 *  BJD 三角形点3*n（n 123，456，789这样取）
 *
 * Arguments    : const emxArray_real_T *Points1
 *                const emxArray_real_T *Points2
 *                const emxArray_real_T *Points3
 *                const emxArray_real_T *Points4
 *                const double BoundPoint1[3]
 *                const double BoundPoint2[3]
 *                double distanceThreshold
 *                emxArray_real_T *PlaneParaOut
 *                emxArray_real_T *TrianglePoints
 *                double MaxDis[4]
 *                emxArray_real_T *distancesFianal
 * Return Type  : void
 */
void planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const double BoundPoint1[3], const double BoundPoint2[3],
               double distanceThreshold, emxArray_real_T *PlaneParaOut,
               emxArray_real_T *TrianglePoints, double MaxDis[4],
               emxArray_real_T *distancesFianal)
{
  emxArray_real_T *b_PlaneParaOut;
  emxArray_real_T *b_Points2;
  emxArray_real_T *distancess1;
  emxArray_real_T *distancess2;
  emxArray_real_T *distancess3;
  emxArray_real_T *y;
  double b_PP[72];
  double PP[24];
  double PlaneParaOutP_data[16];
  double cross_vectors[12];
  double A[9];
  double OptPara2[5];
  double b_dv[3];
  double v[3];
  const double *Points1_data;
  const double *Points2_data;
  const double *Points3_data;
  const double *Points4_data;
  double OptErr;
  double PlaneParaOut1_idx_0;
  double PlaneParaOut2_idx_0;
  double PlaneParaOut2_idx_2;
  double absxk;
  double c;
  double d;
  double ddd2;
  double ddd4;
  double scale;
  double t;
  double *PlaneParaOut_data;
  double *distancesFianal_data;
  double *distancess1_data;
  double *distancess2_data;
  double *distancess3_data;
  int k;
  int ll;
  int loop_ub;
  int nx;
  int xpageoffset;
  (void)distanceThreshold;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  Points4_data = Points4->data;
  Points3_data = Points3->data;
  Points2_data = Points2->data;
  Points1_data = Points1->data;
  k = PlaneParaOut->size[0] * PlaneParaOut->size[1];
  PlaneParaOut->size[0] = 4;
  PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(PlaneParaOut, k);
  PlaneParaOut_data = PlaneParaOut->data;
  for (k = 0; k < 16; k++) {
    PlaneParaOut_data[k] = 0.0;
  }
  /*   新平行函数 */
  /*  % % num = 180; */
  /*  % % sp = linspace(0,2*pi,num); */
  /*  % % sz = linspace(0,2*pi,num); */
  /*  % %  */
  /*  % % OptErr = 99999; */
  /*  % %  */
  /*  % % OptPara = zeros(1,5); */
  /*  % % OptAllErr2 =  zeros(size(Points2,2),1); */
  /*  % % OptAllErr4 =  zeros(size(Points4,2),1); */
  /*  % %  */
  /*  % % for i = 1:num */
  /*  % %     for j = 1:num */
  /*  % %         [x0,y0,z0] = sph2cart(sp(i),sz(j),1); */
  /*  % %         v = [x0, y0, z0]./ sqrt( x0^2+y0^2+z0^2); */
  /*  % %         aaa = v(1); */
  /*  % %         bbb = v(2); */
  /*  % %         ccc = v(3); */
  /*  % %         fun2 = @(dd) sum(abs(aaa * Points2(1,:) + bbb * Points2(2,:) +
   * ccc * Points2(3,:) + dd)); */
  /*  % %         d_opt4 = fminsearch(fun2, 0); */
  /*  % %  */
  /*  % %         fun4 = @(dd) sum(abs(aaa * Points4(1,:) + bbb * Points4(2,:) +
   * ccc * Points4(3,:) + dd)); */
  /*  % %         d_opt4 = fminsearch(fun4, 0); */
  /*  % %  */
  /*  % %         % 计算每个点到平面的距离 */
  /*  % %         distancess2 = aaa * Points2(1,:) + bbb * Points2(2,:) + ccc *
   * Points2(3,:) + d_opt4; */
  /*  % %         distancess4 = aaa * Points4(1,:) + bbb * Points4(2,:) + ccc *
   * Points4(3,:) + d_opt4; */
  /*  % %  */
  /*  % %         disAll = sum(abs(distancess2))+sum(abs(distancess4)); */
  /*  % %  */
  /*  % %         if disAll < OptErr */
  /*  % %             OptPara = [v,d_opt4,d_opt4]; */
  /*  % %             OptAllErr2 = distancess2; */
  /*  % %             OptAllErr4 = distancess4; */
  /*  % %             OptErr = disAll; */
  /*  % %         end */
  /*  % %  */
  /*  % %     end */
  /*  % % end */
  /*  % %  */
  /*  % % % 选择一个基准向量，通常选择 [1, 0, 0] 或 [0, 1, 0]，避免与法向量平行
   */
  /*  % % if OptPara(1) ~= 0 */
  /*  % %     % 如果法向量的 x 分量不为零，选择 [1, 0, 0] 作为基准 */
  /*  % %     v1 = [1, 0, 0]; */
  /*  % % else */
  /*  % %     % 否则，选择 [0, 1, 0] 作为基准 */
  /*  % %     v1 = [0, 1, 0]; */
  /*  % % end */
  /*  % % % 使用叉积计算垂直于法向量的第一个基底向量 */
  /*  % % v1 = cross(OptPara(1:3), v1); */
  /*  % % % 归一化 v1 */
  /*  % % v1 = v1 / norm(v1); */
  /*  % % % 第二个垂直基底向量可以通过叉积获得 */
  /*  % % v2 = cross(OptPara(1:3), v1); */
  /*  % % % 归一化 v2 */
  /*  % % v2 = v2 / norm(v2); */
  /*  % %  */
  /*  % % OptErr = 99999; */
  /*  % %  */
  /*  % % OptPara2 = zeros(1,5); */
  /*  % % OptAllErr1 =  zeros(size(Points1,2),1); */
  /*  % % OptAllErr3 =  zeros(size(Points3,2),1); */
  /*  % % VV = []; */
  /*  % % thet = 0:0.01:2*pi; */
  /*  % % for ll = 1:length(thet) */
  /*  % %  */
  /*  % %     v = v1.*cos(thet(ll))+v2.*sin(thet(ll)); */
  /*  % %     VV = [VV;v]; */
  /*  % %     v=v./norm(v); */
  /*  % %  */
  /*  % %     aaa = v(1); */
  /*  % %     bbb = v(2); */
  /*  % %     ccc = v(3); */
  /*  % %  */
  /*  % %     fun1 = @(dd) sum(abs(aaa * Points1(1,:) + bbb * Points1(2,:) + ccc
   * * Points1(3,:) + dd)); */
  /*  % %     d_opt1 = fminsearch(fun1, 0); */
  /*  % %  */
  /*  % %     fun3 = @(dd) sum(abs(aaa * Points3(1,:) + bbb * Points3(2,:) + ccc
   * * Points3(3,:) + dd)); */
  /*  % %     d_opt3 = fminsearch(fun3, 0); */
  /*  % %  */
  /*  % %     % 计算每个点到平面的距离 */
  /*  % %     distancess1 = aaa * Points1(1,:) + bbb * Points1(2,:) + ccc *
   * Points1(3,:) + d_opt1; */
  /*  % %     distancess3 = aaa * Points3(1,:) + bbb * Points3(2,:) + ccc *
   * Points3(3,:) + d_opt3; */
  /*  % %  */
  /*  % %     disAll = sum(abs(distancess1))+sum(abs(distancess3)); */
  /*  % %  */
  /*  % %     if disAll < OptErr */
  /*  % %         OptPara2 = [v,d_opt1,d_opt3]; */
  /*  % %         OptAllErr1 = distancess1; */
  /*  % %         OptAllErr3 = distancess3; */
  /*  % %         OptErr = disAll; */
  /*  % %         ooo = ll; */
  /*  % %     end */
  /*  % %  */
  /*  % % end */
  /*  % %  */
  /*  % % [n_fit1, d_fit1] = fit_perpendicular_plane(Points1', OptPara(1:4)) */
  /*  % %  */
  /*  % % [n_fit3, d_fit3] = fit_perpendicular_plane(Points3', OptPara(1:4)) */
  /*  % %  */
  /*  % % PlaneParaOut2(:,1) = OptPara2(1:4)'; */
  /*  % % PlaneParaOut2(:,2) = OptPara(1:4)'; */
  /*  % % PlaneParaOut2(:,3) = OptPara2([1,2,3,5])'; */
  /*  % % PlaneParaOut2(:,4) = OptPara([1,2,3,5])'; */
  /*  % %  */
  /*  % % T1 = max(distancess1); */
  /*  % % T2 = max(distancess2); */
  /*  % % T3 = max(distancess3); */
  /*  % % T4 = max(distancess2); */
  /*  % %  */
  /*  % % MaxDis = [T1,T2,T3,T4]; */
  /*  % % distancesFianal = [distancess1,distancess2,distancess3,distancess4];
   */
  /*  旧拟合 */
  /*  % %  */
  /*  % % for i =1:4 */
  /*  % %     Points = PointAll{i}; */
  /*  % %     % 平面拟合 */
  /*  % %     pointss = Points'; */
  /*  % %  */
  /*  % %     Cnum = 1:length(pointss); */
  /*  % %     bestDist = 99999;  % 最优内点距离 */
  /*  % %  */
  /*  % %     C = nchoosek(Cnum,3); */
  /*  % %  */
  /*  % %     for j = 1:length(C) */
  /*  % %         % 随机选择三个点 */
  /*  % %         sampleIdx = C(j,:); */
  /*  % %         samplePoints = pointss(sampleIdx, :); */
  /*  % %  */
  /*  % %         % 计算平面模型 */
  /*  % %         A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)]; */
  /*  % %         coefficients = A \ samplePoints(:,3); */
  /*  % %         a = coefficients(1); */
  /*  % %         b = coefficients(2); */
  /*  % %         d = coefficients(3); */
  /*  % %         c=-1; */
  /*  % %
   * distances=abs([a,b,c,d]*[pointss,ones(size(pointss,1),1)]')/sqrt(a*a+b*b+c*c);
   */
  /*  % %  */
  /*  % %         % 确定内点 */
  /*  % %         inlierIdx = find(distances < distanceThreshold); */
  /*  % %  */
  /*  % %         % 更新最优平面模型 */
  /*  % %         if mean(distances) < bestDist */
  /*  % %             bestDist = mean(distances); */
  /*  % %             inlierIdxFinal{i} = inlierIdx; */
  /*  % %             distancesFianal1{i} = distances; */
  /*  % %         end */
  /*  % %  */
  /*  % %     end */
  /*  % %     % 重新计算最终平面模型，使用所有内点 */
  /*  % %  */
  /*  % %     inlierPoints = pointss(inlierIdxFinal{i}, :); */
  /*  % %  */
  /*  % %     x = inlierPoints(:,1); */
  /*  % %     y = inlierPoints(:,2); */
  /*  % %     z = inlierPoints(:,3); */
  /*  % %  */
  /*  % %     PIner = [x,y,z]; */
  /*  % %  */
  /*  % %     threshold  = 2.5;
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2.5度阈值 */
  /*  % %     % Fit a plane through the points */
  /*  % %     [~, ~, V] = svd(PIner - mean(PIner, 1)); */
  /*  % %     normal = V(:, 3); % Normal vector of the plane */
  /*  % %  */
  /*  % %     % Calculate angle between normal vector and z-axis */
  /*  % %     angle = acosd(abs(dot(normal, [0; 0; 1]))); */
  /*  % %     angle = abs(90-angle); */
  /*  % %  */
  /*  % %     % Check if angle is below threshold */
  /*  % %     if angle < threshold */
  /*  % %         c = 0; */
  /*  % %         bb=polyfit(x,y,1); */
  /*  % %         % 拟合，其实是线性回归，但可以用来拟合平面 */
  /*  % %         a = bb(1); */
  /*  % %         b = -1; */
  /*  % %         d = bb(2); */
  /*  % %     else */
  /*  % %         A = [inlierPoints(:,1), inlierPoints(:,2),
   * ones(size(inlierPoints(:,1)))]; */
  /*  % %         coefficients = A \ inlierPoints(:,3); */
  /*  % %         a = coefficients(1); */
  /*  % %         b = coefficients(2); */
  /*  % %         d = coefficients(3); */
  /*  % %         c=-1; */
  /*  % %     end */
  /*  % %     PlaneParaOut(:,i) = [a;b;c;d]; */
  /*  % % end */
  /*  % %  */
  /*  % % %%%%%%%%% 测试 %%%%%%%%%%%% */
  /*  % %  */
  /*  % % PlaneParaOut(1,2) = 0; */
  /*  % % PlaneParaOut(2,2) = 0; */
  /*  % % % PlaneParaOut(3,2) = 1; */
  /*  % % PlaneParaOut(4,2) = mean(Points2(3,:)); */
  /*  % %  */
  /*  % % PlaneParaOut(1,4) = 0; */
  /*  % % PlaneParaOut(2,4) = 0; */
  /*  % % % PlaneParaOut(3,4) = 1; */
  /*  % % PlaneParaOut(4,4) = mean(Points4(3,:)); */
  /*  % %  */
  /*  % % % PlaneParaOut(1,3) = PlaneParaOut(1,1) ; */
  /*  % %  */
  /*  % % id1 = inlierIdxFinal{1}; */
  /*  % % id2 = inlierIdxFinal{2}; */
  /*  % % id3 = inlierIdxFinal{3}; */
  /*  % % id4 = inlierIdxFinal{4}; */
  /*  % %  */
  /*  % % tt1 = distancesFianal1{1}; */
  /*  % % tt2 = distancesFianal1{2}; */
  /*  % % tt3 = distancesFianal1{3}; */
  /*  % % tt4 = distancesFianal1{4}; */
  /*  % %  */
  /*  % % T1 = max(tt1(id1)); */
  /*  % % T2 = max(tt2(id2)); */
  /*  % % T3 = max(tt3(id3)); */
  /*  % % T4 = max(tt4(id4)); */
  /*  % %  */
  /*  % % MaxDis = [T1,T2,T3,T4]; */
  /*  % % distancesFianal =
   * [distancesFianal1{1},distancesFianal1{2},distancesFianal1{3},distancesFianal1{4}];
   */
  /*  % % %%%%%%%%% 测试 %%%%%%%%%%%% */
  /*  % %  */
  /*  % %
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  % % % % % % % % 平面方程的系数输出 */
  /*  % % % % % % %  */
  /*  % % % % % % % xfit = zeros(1,8); */
  /*  % % % % % % % yfit = zeros(1,8); */
  /*  % % % % % % % zfit = zeros(1,8); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 前2个面的交点 %%%% */
  /*  % % % % % % % % 计算交线 */
  /*  % % % % % % % x_val = (max(x)+min(x))./2; */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,2),x_val); */
  /*  % % % % % % % % 找到边界，确定三角点 */
  /*  % % % % % % % [PointTri] =
   * GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(1) = PointTri(1,1); */
  /*  % % % % % % % yfit(1) = PointTri(2,1); */
  /*  % % % % % % % zfit(1) = PointTri(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri2] =
   * GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(3) = PointTri2(1,1); */
  /*  % % % % % % % yfit(3) = PointTri2(2,1); */
  /*  % % % % % % % zfit(3) = PointTri2(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第2、3个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,2),PlaneParaOut(:,3),x_val); */
  /*  % % % % % % % % 找到边界，确定三角点 */
  /*  % % % % % % % [PointTri3] =
   * GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(5) = PointTri3(1,1); */
  /*  % % % % % % % yfit(5) = PointTri3(2,1); */
  /*  % % % % % % % zfit(5) = PointTri3(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri4] =
   * GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(6) = PointTri4(1,1); */
  /*  % % % % % % % yfit(6) = PointTri4(2,1); */
  /*  % % % % % % % zfit(6) = PointTri4(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第3、4个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,3),PlaneParaOut(:,4),x_val); */
  /*  % % % % % % % [PointTri5] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(7) = PointTri5(1,1); */
  /*  % % % % % % % yfit(7) = PointTri5(2,1); */
  /*  % % % % % % % zfit(7) = PointTri5(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri6] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(8) = PointTri6(1,1); */
  /*  % % % % % % % yfit(8) = PointTri6(2,1); */
  /*  % % % % % % % zfit(8) = PointTri6(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % %%%%%% 第1、4个面的交点 %%%% */
  /*  % % % % % % % [P0,D] =
   * CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,4),x_val); */
  /*  % % % % % % % [PointTri7] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D); */
  /*  % % % % % % % xfit(2) = PointTri7(1,1); */
  /*  % % % % % % % yfit(2) = PointTri7(2,1); */
  /*  % % % % % % % zfit(2) = PointTri7(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % [PointTri8] =
   * GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D); */
  /*  % % % % % % % xfit(4) = PointTri8(1,1); */
  /*  % % % % % % % yfit(4) = PointTri8(2,1); */
  /*  % % % % % % % zfit(4) = PointTri8(3,1); */
  /*  % % % % % % %  */
  /*  % % % % % % % BJD =
   * [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);... */
  /*  % % % % % % % yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
   */
  /*  % % % % % % % zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]])]; */
  /*  % % % % % % %  */
  /*  % % % % % % % % 取八个点 */
  /*  % % % % % % % Pdd = BJD(:,[1:3,6,9,16:18]); */
  /*  % % % % % % % P1 = Pdd(:,1); */
  /*  % % % % % % % P2 = Pdd(:,2); */
  /*  % % % % % % % P3 = Pdd(:,3); */
  /*  % % % % % % % P4 = Pdd(:,4); */
  /*  % % % % % % % P5 = Pdd(:,5); */
  /*  % % % % % % % P6 = Pdd(:,6); */
  /*  % % % % % % % P7 = Pdd(:,7); */
  /*  % % % % % % % P8 = Pdd(:,8); */
  /*  % % % % % % %  */
  /*  % % % % % % % % 计算投影点 */
  /*  % % % % % % % [xN1,yN1,zN1] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P1,P3); */
  /*  % % % % % % % PP1 = [xN1;yN1;zN1]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN2,yN2,zN2] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P2,P4); */
  /*  % % % % % % % PP2 = [xN2;yN2;zN2]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN3,yN3,zN3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P1,P3); */
  /*  % % % % % % % PP3 = [xN3;yN3;zN3]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN4,yN4,zN4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P2,P4); */
  /*  % % % % % % % PP4 = [xN4;yN4;zN4]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN5,yN5,zN5] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P5,P6); */
  /*  % % % % % % % PP5 = [xN5;yN5;zN5]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN6,yN6,zN6] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P5,P6); */
  /*  % % % % % % % PP6 = [xN6;yN6;zN6]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN7,yN7,zN7] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P7,P8); */
  /*  % % % % % % % PP7 = [xN7;yN7;zN7]; */
  /*  % % % % % % %  */
  /*  % % % % % % % [xN8,yN8,zN8] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P7,P8); */
  /*  % % % % % % % PP8 = [xN8;yN8;zN8]; */
  /*  % %  */
  /*  % %
   * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  强行令c=1 */
  emxInit_real_T(&b_Points2, 2);
  k = b_Points2->size[0] * b_Points2->size[1];
  b_Points2->size[0] = 1;
  b_Points2->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(b_Points2, k);
  distancesFianal_data = b_Points2->data;
  xpageoffset = Points2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = Points2_data[3 * k + 2];
  }
  ddd2 = b_combineVectorElements(b_Points2) / (double)Points2->size[1];
  k = b_Points2->size[0] * b_Points2->size[1];
  b_Points2->size[0] = 1;
  b_Points2->size[1] = Points4->size[1];
  emxEnsureCapacity_real_T(b_Points2, k);
  distancesFianal_data = b_Points2->data;
  xpageoffset = Points4->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = Points4_data[3 * k + 2];
  }
  ddd4 = b_combineVectorElements(b_Points2) / (double)Points4->size[1];
  emxInit_real_T(&distancess2, 2);
  k = distancess2->size[0] * distancess2->size[1];
  distancess2->size[0] = 1;
  distancess2->size[1] = Points2->size[1];
  emxEnsureCapacity_real_T(distancess2, k);
  distancess2_data = distancess2->data;
  xpageoffset = Points2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancess2_data[k] = Points2_data[3 * k + 2] - ddd2;
  }
  /*  拟合，其实是线性回归，但可以用来拟合平面 */
  OptErr = 9999.0;
  for (k = 0; k < 5; k++) {
    OptPara2[k] = 0.0;
  }
  xpageoffset = Points1->size[1];
  loop_ub = Points3->size[1];
  emxInit_real_T(&distancess1, 2);
  distancess1_data = distancess1->data;
  emxInit_real_T(&distancess3, 2);
  distancess3_data = distancess3->data;
  emxInit_real_T(&y, 2);
  for (ll = 0; ll < 629; ll++) {
    d = dv[ll];
    PlaneParaOut1_idx_0 = cos(d);
    PlaneParaOut2_idx_0 = sin(d);
    scale = 3.3121686421112381E-170;
    d = PlaneParaOut1_idx_0 + 0.0 * PlaneParaOut2_idx_0;
    v[0] = d;
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      PlaneParaOut2_idx_2 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      PlaneParaOut2_idx_2 = t * t;
    }
    d = 0.0 * PlaneParaOut1_idx_0 + PlaneParaOut2_idx_0;
    absxk = fabs(d);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    PlaneParaOut2_idx_2 = scale * sqrt(PlaneParaOut2_idx_2);
    v[0] /= PlaneParaOut2_idx_2;
    v[1] = d / PlaneParaOut2_idx_2;
    v[2] = (0.0 * PlaneParaOut1_idx_0 + 0.0 * PlaneParaOut2_idx_0) /
           PlaneParaOut2_idx_2;
    scale = fminsearch(v[0], Points1, v[1], v[2]);
    absxk = fminsearch(v[0], Points3, v[1], v[2]);
    /*  计算每个点到平面的距离 */
    k = distancess1->size[0] * distancess1->size[1];
    distancess1->size[0] = 1;
    distancess1->size[1] = Points1->size[1];
    emxEnsureCapacity_real_T(distancess1, k);
    distancess1_data = distancess1->data;
    for (k = 0; k < xpageoffset; k++) {
      distancess1_data[k] =
          ((v[0] * Points1_data[3 * k] + v[1] * Points1_data[3 * k + 1]) +
           v[2] * Points1_data[3 * k + 2]) +
          scale;
    }
    k = distancess3->size[0] * distancess3->size[1];
    distancess3->size[0] = 1;
    distancess3->size[1] = Points3->size[1];
    emxEnsureCapacity_real_T(distancess3, k);
    distancess3_data = distancess3->data;
    for (k = 0; k < loop_ub; k++) {
      distancess3_data[k] =
          ((v[0] * Points3_data[3 * k] + v[1] * Points3_data[3 * k + 1]) +
           v[2] * Points3_data[3 * k + 2]) +
          absxk;
    }
    nx = distancess1->size[1];
    k = b_Points2->size[0] * b_Points2->size[1];
    b_Points2->size[0] = 1;
    b_Points2->size[1] = distancess1->size[1];
    emxEnsureCapacity_real_T(b_Points2, k);
    distancesFianal_data = b_Points2->data;
    for (k = 0; k < nx; k++) {
      distancesFianal_data[k] = fabs(distancess1_data[k]);
    }
    nx = distancess3->size[1];
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = distancess3->size[1];
    emxEnsureCapacity_real_T(y, k);
    distancesFianal_data = y->data;
    for (k = 0; k < nx; k++) {
      distancesFianal_data[k] = fabs(distancess3_data[k]);
    }
    t = b_combineVectorElements(b_Points2) + b_combineVectorElements(y);
    if (t < OptErr) {
      OptPara2[0] = v[0];
      OptPara2[1] = v[1];
      OptPara2[3] = scale;
      OptPara2[4] = absxk;
      OptErr = t;
    }
  }
  emxFree_real_T(&b_Points2);
  emxFree_real_T(&y);
  PlaneParaOut_data[0] = OptPara2[0];
  PlaneParaOut_data[1] = OptPara2[1];
  PlaneParaOut_data[2] = 0.0;
  PlaneParaOut_data[3] = OptPara2[3];
  PlaneParaOut_data[4] = 0.0;
  PlaneParaOut_data[5] = 0.0;
  PlaneParaOut_data[6] = -1.0;
  PlaneParaOut_data[7] = ddd2;
  PlaneParaOut_data[8] = OptPara2[0];
  PlaneParaOut_data[9] = OptPara2[1];
  PlaneParaOut_data[10] = 0.0;
  PlaneParaOut_data[11] = OptPara2[4];
  PlaneParaOut_data[12] = 0.0;
  PlaneParaOut_data[13] = 0.0;
  PlaneParaOut_data[14] = -1.0;
  PlaneParaOut_data[15] = ddd4;
  scale = maximum(distancess2);
  MaxDis[0] = maximum(distancess1);
  MaxDis[1] = scale;
  MaxDis[2] = maximum(distancess3);
  MaxDis[3] = scale;
  k = distancesFianal->size[0] * distancesFianal->size[1];
  distancesFianal->size[0] = 1;
  distancesFianal->size[1] =
      ((distancess1->size[1] + distancess2->size[1]) + distancess3->size[1]) +
      Points4->size[1];
  emxEnsureCapacity_real_T(distancesFianal, k);
  distancesFianal_data = distancesFianal->data;
  xpageoffset = distancess1->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k] = distancess1_data[k];
  }
  xpageoffset = distancess2->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[k + distancess1->size[1]] = distancess2_data[k];
  }
  xpageoffset = distancess3->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[(k + distancess1->size[1]) + distancess2->size[1]] =
        distancess3_data[k];
  }
  xpageoffset = Points4->size[1];
  for (k = 0; k < xpageoffset; k++) {
    distancesFianal_data[((k + distancess1->size[1]) + distancess2->size[1]) +
                         distancess3->size[1]] = Points4_data[3 * k + 2] - ddd4;
  }
  emxFree_real_T(&distancess3);
  emxFree_real_T(&distancess1);
  emxFree_real_T(&distancess2);
  /*   */
  emxInit_real_T(&b_PlaneParaOut, 2);
  k = b_PlaneParaOut->size[0] * b_PlaneParaOut->size[1];
  b_PlaneParaOut->size[0] = 4;
  b_PlaneParaOut->size[1] = 4;
  emxEnsureCapacity_real_T(b_PlaneParaOut, k);
  distancesFianal_data = b_PlaneParaOut->data;
  for (k = 0; k < 4; k++) {
    for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
      distancesFianal_data[xpageoffset + b_PlaneParaOut->size[0] * k] =
          PlaneParaOut_data[k + 4 * xpageoffset];
    }
  }
  for (k = 0; k < 16; k++) {
    PlaneParaOutP_data[k] = distancesFianal_data[k];
  }
  emxFree_real_T(&b_PlaneParaOut);
  /*  初始化一个矩阵存储叉乘结果 */
  memset(&cross_vectors[0], 0, 12U * sizeof(double));
  /*  计算每对相邻侧面法向量的叉乘 */
  for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
    if (xpageoffset + 1 < 4) {
      scale = PlaneParaOutP_data[xpageoffset + 9];
      absxk = PlaneParaOutP_data[xpageoffset + 5];
      t = PlaneParaOutP_data[xpageoffset + 8];
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[xpageoffset + 4];
      cross_vectors[xpageoffset] = PlaneParaOut1_idx_0 * scale - absxk * t;
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[xpageoffset + 1];
      cross_vectors[xpageoffset + 4] =
          PlaneParaOut2_idx_0 * t - PlaneParaOutP_data[xpageoffset] * scale;
      cross_vectors[xpageoffset + 8] =
          PlaneParaOutP_data[xpageoffset] * absxk -
          PlaneParaOut2_idx_0 * PlaneParaOut1_idx_0;
    } else {
      cross_vectors[3] = PlaneParaOutP_data[7] * PlaneParaOutP_data[8] -
                         PlaneParaOutP_data[4] * PlaneParaOutP_data[11];
      cross_vectors[7] = PlaneParaOutP_data[0] * PlaneParaOutP_data[11] -
                         PlaneParaOutP_data[3] * PlaneParaOutP_data[8];
      cross_vectors[11] = PlaneParaOutP_data[3] * PlaneParaOutP_data[4] -
                          PlaneParaOutP_data[0] * PlaneParaOutP_data[7];
      /*  最后一个与第一个相邻 */
    }
    scale = 3.3121686421112381E-170;
    absxk = fabs(cross_vectors[xpageoffset]);
    if (absxk > 3.3121686421112381E-170) {
      PlaneParaOut2_idx_2 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      PlaneParaOut2_idx_2 = t * t;
    }
    absxk = fabs(cross_vectors[xpageoffset + 4]);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    absxk = fabs(cross_vectors[xpageoffset + 8]);
    if (absxk > scale) {
      t = scale / absxk;
      PlaneParaOut2_idx_2 = PlaneParaOut2_idx_2 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      PlaneParaOut2_idx_2 += t * t;
    }
    PlaneParaOut2_idx_2 = scale * sqrt(PlaneParaOut2_idx_2);
    cross_vectors[xpageoffset] /= PlaneParaOut2_idx_2;
    cross_vectors[xpageoffset + 4] /= PlaneParaOut2_idx_2;
    cross_vectors[xpageoffset + 8] /= PlaneParaOut2_idx_2;
    /*  归一化 */
  }
  /*  使所有方向一致 */
  /*  选择第一个向量作为参考 */
  d = cross_vectors[0];
  absxk = cross_vectors[4];
  t = cross_vectors[8];
  for (xpageoffset = 0; xpageoffset < 3; xpageoffset++) {
    PlaneParaOut1_idx_0 = cross_vectors[xpageoffset + 1];
    PlaneParaOut2_idx_0 = cross_vectors[xpageoffset + 5];
    scale = cross_vectors[xpageoffset + 9];
    if ((d * PlaneParaOut1_idx_0 + absxk * PlaneParaOut2_idx_0) + t * scale <
        0.0) {
      /*  如果方向相反 */
      cross_vectors[xpageoffset + 1] = -PlaneParaOut1_idx_0;
      PlaneParaOut2_idx_0 = -PlaneParaOut2_idx_0;
      cross_vectors[xpageoffset + 5] = PlaneParaOut2_idx_0;
      scale = -scale;
      cross_vectors[xpageoffset + 9] = scale;
      /*  翻转方向 */
    }
  }
  /*  计算平均方向向量，并归一化 */
  /*  计算顶面方程的 d 值 */
  ddd4 = 0.0;
  /*  计算底面方程的 d 值 */
  c = 0.0;
  for (loop_ub = 0; loop_ub < 3; loop_ub++) {
    xpageoffset = loop_ub << 2;
    d = (((cross_vectors[xpageoffset] + cross_vectors[xpageoffset + 1]) +
          cross_vectors[xpageoffset + 2]) +
         cross_vectors[xpageoffset + 3]) /
        4.0;
    v[loop_ub] = d;
    ddd4 += d * BoundPoint1[loop_ub];
    c += d * BoundPoint2[loop_ub];
  }
  /*  初始化顶点矩阵 */
  memset(&PP[0], 0, 24U * sizeof(double));
  /*  计算顶面和底面的4个顶点 */
  d = v[0];
  absxk = v[1];
  t = v[2];
  A[2] = d;
  A[5] = absxk;
  A[8] = t;
  for (xpageoffset = 0; xpageoffset < 4; xpageoffset++) {
    /*  顶面顶点 */
    if (xpageoffset + 1 < 4) {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[xpageoffset];
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[xpageoffset + 1];
      scale = PlaneParaOutP_data[xpageoffset + 4];
      absxk = PlaneParaOutP_data[xpageoffset + 5];
      t = PlaneParaOutP_data[xpageoffset + 8];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[xpageoffset + 9];
      ddd2 = PlaneParaOutP_data[xpageoffset + 12];
      OptErr = PlaneParaOutP_data[xpageoffset + 13];
    } else {
      PlaneParaOut1_idx_0 = PlaneParaOutP_data[3];
      PlaneParaOut2_idx_0 = PlaneParaOutP_data[0];
      scale = PlaneParaOutP_data[7];
      absxk = PlaneParaOutP_data[4];
      t = PlaneParaOutP_data[11];
      PlaneParaOut2_idx_2 = PlaneParaOutP_data[8];
      ddd2 = PlaneParaOutP_data[15];
      OptErr = PlaneParaOutP_data[12];
    }
    /*  求顶面和两个相邻侧面的交线 */
    A[0] = PlaneParaOut1_idx_0;
    A[1] = PlaneParaOut2_idx_0;
    A[3] = scale;
    A[4] = absxk;
    A[6] = t;
    A[7] = PlaneParaOut2_idx_2;
    v[0] = -ddd2;
    v[1] = -OptErr;
    v[2] = ddd4;
    b_mldivide(A, v, b_dv);
    PP[xpageoffset] = b_dv[0];
    PP[xpageoffset + 8] = b_dv[1];
    PP[xpageoffset + 16] = b_dv[2];
    /*  求底面和两个相邻侧面的交线 */
    v[0] = -ddd2;
    v[1] = -OptErr;
    v[2] = c;
    b_mldivide(A, v, b_dv);
    PP[xpageoffset + 4] = b_dv[0];
    PP[xpageoffset + 12] = b_dv[1];
    PP[xpageoffset + 20] = b_dv[2];
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(1,1); B1 = PlaneParaOutP(1,2); C1 =PlaneParaOutP(1,3);
   * D1 = PlaneParaOutP(1,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(2,1); B2 = PlaneParaOutP(2,2); C2 =PlaneParaOutP(2,3);
   * D2 = PlaneParaOutP(2,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn1,yn1,zn1] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP1 = [xn1,yn1,zn1]; */
  /*  [xn2,yn2,zn2] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP3 = [xn2,yn2,zn2]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(2,1); B1 = PlaneParaOutP(2,2); C1 =PlaneParaOutP(2,3);
   * D1 = PlaneParaOutP(2,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(3,1); B2 = PlaneParaOutP(3,2); C2 =PlaneParaOutP(3,3);
   * D2 = PlaneParaOutP(3,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP5 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP6 = [xn4,yn4,zn4]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(3,1); B1 = PlaneParaOutP(3,2); C1 =PlaneParaOutP(3,3);
   * D1 = PlaneParaOutP(3,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(4,1); B2 = PlaneParaOutP(4,2); C2 =PlaneParaOutP(4,3);
   * D2 = PlaneParaOutP(4,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP7 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP8 = [xn4,yn4,zn4]; */
  /*   */
  /*  % 平面1的参数 (A1x + B1y + C1z + D1 = 0) */
  /*  A1 = PlaneParaOutP(4,1); B1 = PlaneParaOutP(4,2); C1 =PlaneParaOutP(4,3);
   * D1 = PlaneParaOutP(4,4); */
  /*  % 平面2的参数 (A2x + B2y + C2z + D2 = 0) */
  /*  A2 = PlaneParaOutP(1,1); B2 = PlaneParaOutP(1,2); C2 =PlaneParaOutP(1,3);
   * D2 = PlaneParaOutP(1,4); */
  /*  % 选择一个自由变量 (假设为 x) */
  /*  syms x y z */
  /*  % 方程1和方程2 */
  /*  eq1 = A1*x + B1*y + C1*z + D1 == 0; */
  /*  eq2 = A2*x + B2*y + C2*z + D2 == 0; */
  /*  % 解方程组 */
  /*  sol = solve([eq1, eq2], [y, z]); */
  /*  % 提取解 */
  /*  y_sol = sol.y; */
  /*  z_sol = sol.z; */
  /*  % 设定 x 的范围 */
  /*  x_vals = linspace(-5, 5, 100); */
  /*  y_vals = double(subs(y_sol, x, x_vals)); */
  /*  z_vals = double(subs(z_sol, x, x_vals)); */
  /*  PL1 = [x_vals(1),y_vals(1),z_vals(1)]; */
  /*  PL2 = [x_vals(end),y_vals(end),z_vals(end)]; */
  /*  [xn3,yn3,zn3] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2); */
  /*  PPP2 = [xn3,yn3,zn3]; */
  /*  [xn4,yn4,zn4] =
   * foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2); */
  /*  PPP4 = [xn4,yn4,zn4]; */
  /*   */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /*  temp1 = [PP1,PP2,PP3,PP4,PP5,PP6,PP7,PP8]'; */
  /*  temp2 = [PPP1;PPP2;PPP3;PPP4;PPP5;PPP6;PPP7;PPP8]; */
  /*  TrianglePoints =
   * [PPP1;PPP2;PPP3;PPP2;PPP3;PPP4;PPP1;PPP3;PPP5;PPP3;PPP5;PPP6;PPP5;PPP6;PPP7;PPP6;PPP7;PPP8;PPP2;PPP4;PPP7;PPP4;PPP7;PPP8]';
   */
  b_PP[0] = PP[0];
  b_PP[3] = PP[3];
  b_PP[6] = PP[4];
  b_PP[9] = PP[3];
  b_PP[12] = PP[4];
  b_PP[15] = PP[7];
  b_PP[18] = PP[0];
  b_PP[21] = PP[4];
  b_PP[24] = PP[1];
  b_PP[27] = PP[4];
  b_PP[30] = PP[1];
  b_PP[33] = PP[5];
  b_PP[36] = PP[1];
  b_PP[39] = PP[5];
  b_PP[42] = PP[2];
  b_PP[45] = PP[5];
  b_PP[48] = PP[2];
  b_PP[51] = PP[6];
  b_PP[54] = PP[3];
  b_PP[57] = PP[7];
  b_PP[60] = PP[2];
  b_PP[63] = PP[7];
  b_PP[66] = PP[2];
  b_PP[69] = PP[6];
  b_PP[1] = PP[8];
  b_PP[4] = PP[11];
  b_PP[7] = PP[12];
  b_PP[10] = PP[11];
  b_PP[13] = PP[12];
  b_PP[16] = PP[15];
  b_PP[19] = PP[8];
  b_PP[22] = PP[12];
  b_PP[25] = PP[9];
  b_PP[28] = PP[12];
  b_PP[31] = PP[9];
  b_PP[34] = PP[13];
  b_PP[37] = PP[9];
  b_PP[40] = PP[13];
  b_PP[43] = PP[10];
  b_PP[46] = PP[13];
  b_PP[49] = PP[10];
  b_PP[52] = PP[14];
  b_PP[55] = PP[11];
  b_PP[58] = PP[15];
  b_PP[61] = PP[10];
  b_PP[64] = PP[15];
  b_PP[67] = PP[10];
  b_PP[70] = PP[14];
  b_PP[2] = PP[16];
  b_PP[5] = PP[19];
  b_PP[8] = PP[20];
  b_PP[11] = PP[19];
  b_PP[14] = PP[20];
  b_PP[17] = PP[23];
  b_PP[20] = PP[16];
  b_PP[23] = PP[20];
  b_PP[26] = PP[17];
  b_PP[29] = PP[20];
  b_PP[32] = PP[17];
  b_PP[35] = PP[21];
  b_PP[38] = PP[17];
  b_PP[41] = PP[21];
  b_PP[44] = PP[18];
  b_PP[47] = PP[21];
  b_PP[50] = PP[18];
  b_PP[53] = PP[22];
  b_PP[56] = PP[19];
  b_PP[59] = PP[23];
  b_PP[62] = PP[18];
  b_PP[65] = PP[23];
  b_PP[68] = PP[18];
  b_PP[71] = PP[22];
  k = TrianglePoints->size[0] * TrianglePoints->size[1];
  TrianglePoints->size[0] = 3;
  TrianglePoints->size[1] = 24;
  emxEnsureCapacity_real_T(TrianglePoints, k);
  distancesFianal_data = TrianglePoints->data;
  for (k = 0; k < 72; k++) {
    distancesFianal_data[k] = b_PP[k];
  }
}

/*
 * File trailer for planefit4.c
 *
 * [EOF]
 */
