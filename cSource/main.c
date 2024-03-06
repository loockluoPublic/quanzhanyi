#include <emscripten.h>
#include "mycylderfit.h"
#include "mycylderfit_emxAPI.h"
#include "mycylderfit_terminate.h"
#include "mycylderfit_types.h"
#include "rt_nonfinite.h"

EMSCRIPTEN_KEEPALIVE
int add(int a, int b)
{
    return a + b + 100;
}

// EMSCRIPTEN_KEEPALIVE
// int exportadd200(int a, int b)
// {

//     return add200(a, b);
// }