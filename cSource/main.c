#include <emscripten.h>
#include <stdio.h>
#include "QuanZhanYi_types.h"
#include "generate_unit_circle_with_normal_vector.h"
#include "Generate_multi_layered_measurement_points.h"

EMSCRIPTEN_KEEPALIVE
void generateUnitCircleWithNormalVector(double t1, double t2, double num,
                                        emxArray_real_T *x_circle1,
                                        emxArray_real_T *y_circle1,
                                        emxArray_real_T *z_circle1)
{
    generate_unit_circle_with_normal_vector(t1, t2, num, x_circle1, y_circle1, z_circle1);
}

EMSCRIPTEN_KEEPALIVE
void GenerateMultiLayeredMeasurementPoints(
    const emxArray_real_T *x, const emxArray_real_T *y,
    const emxArray_real_T *z, double num, double laynum, const double P3[3],
    const double P4[3], emxArray_real_T *Point_test)
{
    Generate_multi_layered_measurement_points(x, y, z, num, laynum, P3, P4, Point_test);
}
