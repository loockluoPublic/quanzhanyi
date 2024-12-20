/*
 * File: _coder_QuanZhanYi_api.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Dec-2024 22:58:37
 */

#ifndef _CODER_QUANZHANYI_API_H
#define _CODER_QUANZHANYI_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Calculat_A_and_B_Points(real_T MTaon[3], real_T Mcenter[3], real_T Mradial,
                             real_T Bottom_round_center1[3],
                             real_T Bottom_round_center2[3], real_T testP[3],
                             real_T numShengLu, real_T phi,
                             emxArray_real_T *PointTable_A,
                             emxArray_real_T *PointTable_B);

void Calculat_A_and_B_Points_after_Offest2(
    real_T Bottom_round_center1[3], real_T Bottom_round_center2[3],
    real_T MTaon[3], real_T Mcenter[3], real_T Mradial, real_T PAB[3],
    real_T phi, emxArray_real_T *Ang, emxArray_real_T *toff,
    emxArray_real_T *roff, emxArray_real_T *PointTable_A_off,
    emxArray_real_T *PointTable_B_off, emxArray_real_T *BianHao);

void Calculat_A_and_B_Points_api(const mxArray *const prhs[8], int32_T nlhs,
                                 const mxArray *plhs[2]);

void Calculat_JuXing_A_and_B_Points_after_Offest(
    real_T Tao[3], real_T UPP[3], real_T Pin[3], real_T b, real_T h,
    real_T PAB[3], real_T phi, real_T shenglunum, emxArray_real_T *Ti,
    emxArray_real_T *toff, emxArray_real_T *PointTable_A_off,
    emxArray_real_T *PointTable_B_off);

void Calculate_accurate_cylinders_from_multiple_measurement_points2(
    emxArray_real_T *points, real_T P_bound1[3], real_T P_bound2[3],
    real_T Mcenter[3], real_T MTaon[3], real_T *Mradial,
    emxArray_real_T *Err_every, real_T Bottom_round_center1[3],
    real_T Bottom_round_center2[3]);

void Calculate_rectangle_from_vertex(emxArray_real_T *TrianglePoints4,
                                     real_T Pin[3], real_T Pout[3],
                                     real_T UPP[3], real_T *b, real_T *h,
                                     real_T *w, real_T Tao[3], real_T PP[24]);

void Calculate_rectangle_from_vertex8(
    emxArray_real_T *side_faces_transformed1,
    emxArray_real_T *side_faces_transformed2,
    emxArray_real_T *side_faces_transformed3,
    emxArray_real_T *side_faces_transformed4,
    emxArray_real_T *side_faces_transformed5,
    emxArray_real_T *side_faces_transformed6,
    emxArray_real_T *side_faces_transformed7,
    emxArray_real_T *side_faces_transformed8, real_T P_bound1[3],
    real_T P_bound2[3], real_T PAB[3], real_T phi, real_T shenglunum,
    emxArray_real_T *Ti, emxArray_real_T *a, real_T distanceThreshold,
    emxArray_real_T *PointTable_A_off8, emxArray_real_T *PointTable_B_off8,
    emxArray_real_T *XieMianPianYi);

void CrossLine(real_T PlanePara1[4], real_T PlanePara2[4], real_T x_val,
               real_T P0[3], real_T d[3]);

void CrossLine_api(const mxArray *const prhs[3], int32_T nlhs,
                   const mxArray *plhs[2]);

void GenerateTrianglePoints(real_T PlaneParaIn[4], real_T BoundPoint1[3],
                            real_T P0[3], real_T Direction[3],
                            real_T PointTri[6]);

void GenerateTrianglePoints_api(const mxArray *const prhs[4],
                                const mxArray **plhs);

void Generate_multi_layered_measurement_points(emxArray_real_T *Point_out,
                                               real_T num, real_T laynum,
                                               real_T P3[3], real_T P4[3],
                                               real_T r,
                                               emxArray_real_T *Point_test);

void JuXingFuCe(emxArray_real_T *PointIn, real_T shenglunum, real_T Pin[3],
                real_T Tao[3], real_T h, emxArray_real_T *PlaneParaOut4,
                real_T LenDaoJiao[8], emxArray_real_T *Distance,
                emxArray_real_T *theta, emxArray_real_T *LTPY,
                emxArray_real_T *TiC, emxArray_real_T *Wquanzhong3,
                emxArray_real_T *Wquanzhong4);

void JuXingFuCe_api(const mxArray *const prhs[7], int32_T nlhs,
                    const mxArray *plhs[6]);

void OffsetCalculate(real_T Mradial, real_T phi, emxArray_real_T *Ang,
                     emxArray_real_T *a, emxArray_real_T *OffsetOut);

void OffsetCalculate_api(const mxArray *const prhs[4], const mxArray **plhs);

void QuanZhanYi_atexit(void);

void QuanZhanYi_initialize(void);

void QuanZhanYi_terminate(void);

void QuanZhanYi_xil_shutdown(void);

void QuanZhanYi_xil_terminate(void);

void RepeatSurvey(real_T SoundPoint1[3], real_T SoundPoint2[3],
                  real_T Bottom_round_center1[3],
                  real_T Bottom_round_center2[3], real_T *SoundAngle,
                  real_T *SoundLength);

void RepeatSurvey_api(const mxArray *const prhs[4], int32_T nlhs,
                      const mxArray *plhs[2]);

void ShengDaoGaoDu(real_T numShengLu, emxArray_real_T *Ti);

void ShengDaoGaoDu_api(const mxArray *prhs, const mxArray **plhs);

void ShengLuJiaoJiSuan(real_T numShengLu, emxArray_real_T *Ang);

void ShengLuJiaoJiSuan_api(const mxArray *prhs, const mxArray **plhs);

void YuanXingFuCe(emxArray_real_T *PointIn, real_T shenglunum,
                  real_T Mcenter[3], real_T MTaon[3], real_T Mradial,
                  real_T phi, emxArray_real_T *Distance, emxArray_real_T *theta,
                  emxArray_real_T *LTPY, emxArray_real_T *TiC,
                  emxArray_real_T *Wquanzhong1, emxArray_real_T *Wquanzhong2);

void YuanXingFuCe_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[6]);

void YuanZhuJiaoDian(real_T Mcenter[3], real_T MTaon[3], real_T Mradial,
                     real_T Pin1[3], real_T Pin2[3], real_T Cross_point_data[],
                     int32_T Cross_point_size[2]);

void YuanZhuJiaoDian_api(const mxArray *const prhs[5], const mxArray **plhs);

void angle2point(real_T ANG, real_T a, real_T b, real_T c, real_T d,
                 real_T Mradial, real_T *x, real_T *y, real_T *z);

void angle2point_api(const mxArray *const prhs[6], int32_T nlhs,
                     const mxArray *plhs[3]);

void c_Calculat_A_and_B_Points_after(const mxArray *const prhs[10],
                                     int32_T nlhs, const mxArray *plhs[3]);

void c_Calculat_JuXing_A_and_B_Point(const mxArray *const prhs[10],
                                     int32_T nlhs, const mxArray *plhs[2]);

void c_Calculate_accurate_cylinders_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[6]);

void c_Calculate_rectangle_from_vert(const mxArray *prhs, int32_T nlhs,
                                     const mxArray *plhs[8]);

void c_Generate_multi_layered_measur(const mxArray *const prhs[6],
                                     const mxArray **plhs);

void c_foot_of_perpendicular_from_a_(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[3]);

void c_generate_unit_circle_with_nor(const mxArray *const prhs[4],
                                     const mxArray **plhs);

void d_Calculate_rectangle_from_vert(const mxArray *const prhs[16],
                                     int32_T nlhs, const mxArray *plhs[3]);

void d_generate_unit_circle_with_nor(const mxArray *const prhs[7],
                                     const mxArray **plhs);

void fitcircle(emxArray_real_T *x, real_T z[2], real_T *r, real_T *residual);

void fitcircle_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[3]);

void foot_of_perpendicular_from_a_point_to_a_line(real_T P_outer[3],
                                                  real_T P_lines1[3],
                                                  real_T P_lines2[3],
                                                  real_T *xN1, real_T *yN1,
                                                  real_T *zN1);

void generate_unit_circle_with_normal_vector(real_T azimuth, real_T elevation,
                                             real_T num, real_T r,
                                             emxArray_real_T *Point_out);

void generate_unit_circle_with_normal_vector2(real_T azimuth, real_T elevation,
                                              real_T num, real_T laynum,
                                              real_T P1[3], real_T P2[3],
                                              real_T r,
                                              emxArray_real_T *Point_out);

void myvrrotvec2mat(real_T r[4], real_T m[9]);

void myvrrotvec2mat_api(const mxArray *prhs, const mxArray **plhs);

void planefit(emxArray_real_T *Points, emxArray_real_T *PlaneParaIn,
              real_T BoundPoint1[3], real_T BoundPoint2[3],
              emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints);

void planefit4(emxArray_real_T *Points1, emxArray_real_T *Points2,
               emxArray_real_T *Points3, emxArray_real_T *Points4,
               real_T BoundPoint1[3], real_T BoundPoint2[3],
               real_T distanceThreshold, emxArray_real_T *PlaneParaOut,
               emxArray_real_T *TrianglePoints, real_T MaxDis[4],
               emxArray_real_T *distancesFianal);

void planefit4_api(const mxArray *const prhs[7], int32_T nlhs,
                   const mxArray *plhs[4]);

void planefit8(emxArray_real_T *Points1, emxArray_real_T *Points2,
               emxArray_real_T *Points3, emxArray_real_T *Points4,
               emxArray_real_T *Points5, emxArray_real_T *Points6,
               emxArray_real_T *Points7, emxArray_real_T *Points8,
               real_T P_bound1[3], real_T P_bound2[3], real_T distanceThreshold,
               emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints,
               real_T MaxDis[8], emxArray_real_T *distancesFianal,
               real_T LenDaoJiao[8]);

void planefit8_api(const mxArray *const prhs[11], int32_T nlhs,
                   const mxArray *plhs[5]);

void planefit_api(const mxArray *const prhs[4], int32_T nlhs,
                  const mxArray *plhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_QuanZhanYi_api.h
 *
 * [EOF]
 */
