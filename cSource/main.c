#include <emscripten.h>
#include <stdio.h>
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "Generate_multi_layered_measurement_points.h"
#include "Calculate_accurate_cylinders_from_multiple_measurement_points.h"

EMSCRIPTEN_KEEPALIVE
void test(emxArray_real_T *Point_out)
{
    int *ptr;
    printf("The size of the pointer is: %zu bytes\n", sizeof(ptr));
    printf("Point_out->numDimensions = %d, Point_out size=%d,Point_out data=%d, Point_out size[0]=%d, size[1]=%d, Point_out->data[0]=%f \n ", Point_out->numDimensions, Point_out->size, Point_out->data, Point_out->size[0], Point_out->size[1], Point_out->data[0]);
    printf("Point_out->numDimensions = %d \n", Point_out->numDimensions);
}

EMSCRIPTEN_KEEPALIVE
void generateUnitCircleWithNormalVector(double azimuth, double elevation, double num, emxArray_real_T *Point_out)
{
    generate_unit_circle_with_normal_vector(azimuth, elevation, num, Point_out);
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
    Calculate_accurate_cylinders_from_multiple_measurement_points(
        points, P_bound1, P_bound2, Mcenter, MTaon, Mradial, Err_every, Bottom_round_center1, Bottom_round_center2);
}