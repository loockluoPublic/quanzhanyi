#include <emscripten.h>
#include <stdio.h>
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector2.h"
#include "Generate_multi_layered_measurement_points.h"
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "Calculat_A_and_B_Points_after_Offest.h"
#include "RepeatSurvey.h"
#include "planefit.h"

EMSCRIPTEN_KEEPALIVE
void generateUnitCircleWithNormalVector(double azimuth, double elevation,
                                        double num, double laynum, const double P1[3],
                                        const double P2[3],
                                        emxArray_real_T *Point_out)
{
    printf("generateUnitCircleWithNormalVector %f %f %f", azimuth, elevation, num);
    printf("P3: %f,%f,%f", P1[0], P1[1], P1[2]);
    generate_unit_circle_with_normal_vector2(azimuth, elevation, num, laynum, P1, P2, Point_out);
}

EMSCRIPTEN_KEEPALIVE
void GenerateMultiLayeredMeasurementPoints(
    const emxArray_real_T *Point_out,
    double num,
    double laynum,
    const double P3[3],
    const double P4[3],
    emxArray_real_T *Point_test)
{
    Generate_multi_layered_measurement_points(Point_out, num, laynum, P3, P4, Point_test);
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
void CalculatAAndBPoints(const double MTaon[3], const double Mcenter[3],
                         double Mradial,
                         const double Bottom_round_center1[3],
                         const double Bottom_round_center2[3],
                         const double testP[3], double numShengLu,
                         double phi, double toff,
                         double roff, emxArray_real_T *PointTable_A,
                         emxArray_real_T *PointTable_B)
{
    Calculat_A_and_B_Points_after_Offest(MTaon, Mcenter, Mradial,
                                         Bottom_round_center1,
                                         Bottom_round_center2,
                                         testP,
                                         numShengLu,
                                         phi,
                                         toff,
                                         roff,
                                         PointTable_A, PointTable_B);
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
extern void Planefit(const emxArray_real_T *Points,
                     const emxArray_real_T *PlaneParaIn,
                     const double BoundPoint1[3], const double BoundPoint2[3],
                     emxArray_real_T *PlaneParaOut,
                     emxArray_real_T *TrianglePoints)
{
    planefit(Points, PlaneParaIn, BoundPoint1, BoundPoint2, PlaneParaOut, TrianglePoints);
}
