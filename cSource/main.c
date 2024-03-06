#include <emscripten.h>
#include "_coder_mycylderfit_api.h"

EMSCRIPTEN_KEEPALIVE
int add(int a, int b)
{
    return a + b + 100;
}

EMSCRIPTEN_KEEPALIVE
int exportadd200(int a, int b)
{
    return add200(a, b);
}