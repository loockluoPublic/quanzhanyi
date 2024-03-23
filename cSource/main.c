#include <emscripten.h>
#include <stdio.h>
#include "generate_unit_circle_with_normal_vector.h"
#include "generate_unit_circle_with_normal_vector_emxAPI.h"

EMSCRIPTEN_KEEPALIVE
float test(int a, emxArray_real_T *x_circle)
{

    printf("a: %d", a);

    x_circle->data[4] = 4.130;

    return x_circle->data[4];
}

EMSCRIPTEN_KEEPALIVE
int add(int a, int b)
{

    printf("a+b= %d", a + b);

    return a + b;
}
