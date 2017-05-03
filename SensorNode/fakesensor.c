#include <math.h>

#include "errorhandle.h"

void generate_data(int x, double* values, int sendable)
{
    #if debug
            debug_msg("generate_data making fake stuff\n");
    #endif

    values[x] = sin(x);
    if(x == 359)
    {
        sendable = 1;
    }
}