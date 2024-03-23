#include <emscripten.h>
#include "mycylderfit_types.h"
#include "mycylderfit_emxAPI.h"
// #include "mycylderfit_terminate.h"
#include "cvstCG_kdtree.h"
#include "mycylderfit_emxAPI.h"
#include "mycylderfit.h"
// /Users/alsc/myFile/quanzhaunyi/codegen0310/lib/mycylderfit/mycylderfit_emxAPI.h
// /Users/alsc/myFile/quanzhaunyi/codegen/lib/cylderfit/mycylderfit.h

EMSCRIPTEN_KEEPALIVE
int add1(int a, int b)
{
    return a + b + 100;
}
static void mycylderfit1(void);

EMSCRIPTEN_KEEPALIVE
int add2(int a, int b)
{
    mycylderfit1();
    return a + b + 200;
}
// EMSCRIPTEN_KEEPALIVE
// int add2(int a, int b)
// {
//     return add200(a, b);
// }

// EMSCRIPTEN_KEEPALIVE
// void mycylderfit_api_js(const mxArray *const prhs[3], int32_T nlhs,
//                         const mxArray *plhs[7]){
//     // mycylderfit_api(prhs, nlhs, plhs);
// };

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
double argInit_real_T(void)
{
    return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
    emxArray_real_T *result;
    const int i = 2;
    int idx0;
    /* Set the size of the array.
  Change this size to the value that the application requires. */
    result = emxCreateND_real_T(1, &i);
    /* Loop over the array to initialize each element. */
    for (idx0 = 0; idx0 < result->size[0U]; idx0++)
    {
        /* Set the value of the array element.
    Change this value to the value that the application requires. */
        result->data[idx0] = argInit_real_T();
    }
    return result;
}

EMSCRIPTEN_KEEPALIVE
static void mycylderfit1(void)
{
    emxArray_real_T *x;
    emxArray_real_T *y;
    emxArray_real_T *z;
    double xn1;
    double xn2;
    double xn3;
    double xn4;
    double xn5;
    double xn6;
    double xn7;
    /* Initialize function 'mycylderfit' input arguments. */
    /* Initialize function input argument 'x'. */
    x = argInit_Unboundedx1_real_T();
    /* Initialize function input argument 'y'. */
    y = argInit_Unboundedx1_real_T();
    /* Initialize function input argument 'z'. */
    z = argInit_Unboundedx1_real_T();
    /* Call the entry-point 'mycylderfit'. */
    mycylderfit(x, y, z, &xn1, &xn2, &xn3, &xn4, &xn5, &xn6, &xn7);
    emxDestroyArray_real_T(z);
    emxDestroyArray_real_T(y);
    emxDestroyArray_real_T(x);
}