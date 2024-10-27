#include <emscripten.h>
#include <stdio.h>
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector2.h"
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "Calculat_A_and_B_Points_after_Offest2.h"
#include "RepeatSurvey.h"
#include "planefit.h"
#include "OffsetCalculate.h"
#include "ShengLuJiaoJiSuan.h"
#include "Calculat_JuXing_A_and_B_Points_after_Offest.h"
#include "Calculate_rectangle_from_vertex.h"
#include "planefit4.h"
#include "planefit8.h"
#include "ShengDaoGaoDu.h"
#include "Calculate_rectangle_from_vertex8.h"
#include "JuXingFuCe.h"
#include "YuanXingFuCe.h"

EMSCRIPTEN_KEEPALIVE
void generateUnitCircleWithNormalVector(double azimuth, double elevation,
                                        double num, double laynum, const double P1[3],
                                        const double P2[3],
                                        const double r,
                                        emxArray_real_T *Point_out)
{

    generate_unit_circle_with_normal_vector2(azimuth, elevation, num, laynum, P1, P2, r, Point_out);
}

EMSCRIPTEN_KEEPALIVE
void CalculateAccurateCylindersFromMultipleMeasurementPoints(
    const emxArray_real_T *points,
    const double P_bound1[3],
    const double P_bound2[3],
    double Mcenter[3],
    double MTaon[3],
    double *Mradial,
    emxArray_real_T *Err_every,
    double Bottom_round_center1[3],
    double Bottom_round_center2[3])
{
    Calculate_accurate_cylinders_from_multiple_measurement_points2(points, P_bound1, P_bound2, Mcenter, MTaon, Mradial, Err_every, Bottom_round_center1, Bottom_round_center2);
}

EMSCRIPTEN_KEEPALIVE
void CalculatAAndBPoints(const double MTaon[3],
                         const double Mcenter[3],
                         double Mradial, const double PAB[3],
                         double phi, emxArray_real_T *Ang,
                         const emxArray_real_T *toff,
                         const emxArray_real_T *roff,
                         emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off)
{
    Calculat_A_and_B_Points_after_Offest2(MTaon, Mcenter, Mradial,
                                          PAB,
                                          phi,
                                          Ang,
                                          toff, roff, PointTable_A_off, PointTable_B_off);
}

EMSCRIPTEN_KEEPALIVE
void Repeat_Survey(const double SoundPoint1[3], const double SoundPoint2[3],
                   const double Bottom_round_center1[3],
                   const double Bottom_round_center2[3], double *SoundAngle,
                   double *SoundLength)
{
    RepeatSurvey(SoundPoint1, SoundPoint2, Bottom_round_center1, Bottom_round_center2, SoundAngle, SoundLength);
}

EMSCRIPTEN_KEEPALIVE
void Planefit(const emxArray_real_T *Points,
              const emxArray_real_T *PlaneParaIn,
              const double BoundPoint1[3], const double BoundPoint2[3],
              emxArray_real_T *PlaneParaOut,
              emxArray_real_T *TrianglePoints)
{
    planefit(Points, PlaneParaIn, BoundPoint1, BoundPoint2, PlaneParaOut, TrianglePoints);
}

EMSCRIPTEN_KEEPALIVE
void offsetCalculate(double Mradial, double phi,
                     const emxArray_real_T *Ang,
                     const emxArray_real_T *a,
                     emxArray_real_T *OffsetOut)
{
    OffsetCalculate(Mradial, phi, Ang, a, OffsetOut);
};

EMSCRIPTEN_KEEPALIVE
void shengLuJiaoJiSuan(double numShengLu, emxArray_real_T *Ang)
{
    ShengLuJiaoJiSuan(numShengLu, Ang);
};

EMSCRIPTEN_KEEPALIVE
void CalcJuXingAAndBPointsAfterOffest(const double Tao[3], const double UPP[3], const double Pin[3], double b,
                                      double h, const double PAB[3], double phi, double shenglunum,
                                      const emxArray_real_T *Ti, const emxArray_real_T *toff,
                                      emxArray_real_T *PointTable_A_off, emxArray_real_T *PointTable_B_off)
{
    Calculat_JuXing_A_and_B_Points_after_Offest(Tao, UPP, Pin, b, h, PAB, phi, shenglunum, Ti, toff, PointTable_A_off, PointTable_B_off);
};

EMSCRIPTEN_KEEPALIVE
void CalculateRectangleFromVertex(
    const emxArray_real_T *TrianglePoints4,
    double Pin[3],
    double Pout[3],
    double UPP[3], double *b,
    double *h, double *w, double Tao[3])
{
    double PP[24] = {0};
    Calculate_rectangle_from_vertex(
        TrianglePoints4, Pin, Pout, UPP, b, h, w, Tao, PP);
};

EMSCRIPTEN_KEEPALIVE
void Planefit4(const emxArray_real_T *Points1, const emxArray_real_T *Points2,
               const emxArray_real_T *Points3, const emxArray_real_T *Points4,
               const double BoundPoint1[3], const double BoundPoint2[3], double distanceThreshold,
               emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints, double MaxDis[4],
               emxArray_real_T *distancesFianal)
{
    planefit4(Points1, Points2, Points3, Points4, BoundPoint1, BoundPoint2, distanceThreshold, PlaneParaOut, TrianglePoints, MaxDis, distancesFianal);
};

EMSCRIPTEN_KEEPALIVE
void Planefit8(const emxArray_real_T *Points1, emxArray_real_T *Points2,
               const emxArray_real_T *Points3, emxArray_real_T *Points4,
               const emxArray_real_T *Points5, emxArray_real_T *Points6,
               const emxArray_real_T *Points7, emxArray_real_T *Points8,
               const double BoundPoint1[3], const double BoundPoint2[3],
               double distanceThreshold,
               emxArray_real_T *PlaneParaOut, emxArray_real_T *TrianglePoints,
               double MaxDis[4], emxArray_real_T *distancesFianal, double LenDaoJiao[8])
{
    planefit8(Points1, Points2, Points3, Points4, Points5, Points6, Points7, Points8, BoundPoint1, BoundPoint2, distanceThreshold, PlaneParaOut, TrianglePoints, MaxDis, distancesFianal, LenDaoJiao);
};

EMSCRIPTEN_KEEPALIVE
void shengDaoGaoDu(double numShengLu, emxArray_real_T *Ti)
{
    ShengDaoGaoDu(numShengLu, Ti);
};

EMSCRIPTEN_KEEPALIVE
void CalculateRectangleFromVertex8(
    const emxArray_real_T *side_faces_transformed1,
    const emxArray_real_T *side_faces_transformed2,
    const emxArray_real_T *side_faces_transformed3,
    const emxArray_real_T *side_faces_transformed4,
    const emxArray_real_T *side_faces_transformed5,
    const emxArray_real_T *side_faces_transformed6,
    const emxArray_real_T *side_faces_transformed7,
    const emxArray_real_T *side_faces_transformed8, const double P_bound1[3],
    const double P_bound2[3], const double PAB[3], double phi,
    double shenglunum, const emxArray_real_T *Ti, const emxArray_real_T *a,
    double distanceThreshold, emxArray_real_T *PointTable_A_off8,
    emxArray_real_T *PointTable_B_off8, emxArray_real_T *XieMianPianYi)
{
    Calculate_rectangle_from_vertex8(side_faces_transformed1, side_faces_transformed2, side_faces_transformed3, side_faces_transformed4, side_faces_transformed5, side_faces_transformed6, side_faces_transformed7, side_faces_transformed8, P_bound1, P_bound2, PAB, phi, shenglunum, Ti, a, distanceThreshold, PointTable_A_off8, PointTable_B_off8, XieMianPianYi);
}

EMSCRIPTEN_KEEPALIVE
void juXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                const double Pin[3], const double Tao[3], double h,
                const emxArray_real_T *PlaneParaOut8, emxArray_real_T *Distance,
                emxArray_real_T *theta, emxArray_real_T *LTPY,
                emxArray_real_T *TiC, emxArray_real_T *Wquanzhong3,
                emxArray_real_T *Wquanzhong4)
{
    JuXingFuCe(PointIn, shenglunum, Pin, Tao, h, PlaneParaOut8, Distance, theta, LTPY, TiC, Wquanzhong3, Wquanzhong4);
};

EMSCRIPTEN_KEEPALIVE
void yuanXingFuCe(const emxArray_real_T *PointIn, double shenglunum,
                  const double Mcenter[3], const double MTaon[3],
                  double Mradial, double phi, emxArray_real_T *Distance,
                  emxArray_real_T *theta, emxArray_real_T *LTPY,
                  emxArray_real_T *TiC, emxArray_real_T *Wquanzhong1,
                  emxArray_real_T *Wquanzhong2)
{
    YuanXingFuCe(PointIn, shenglunum, Mcenter, MTaon, Mradial, phi, Distance, theta, LTPY, TiC, Wquanzhong1, Wquanzhong2);
};