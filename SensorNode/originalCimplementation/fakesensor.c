#include <math.h>
#include <stdio.h>

#include "errorhandle.h"

void generate_data(int* x, double* values, int* sendable)
{
    values[*x] = sin((double)*x);

    #if debug
        //printf("%d: %f\n", *x,  values[*x]);
    #endif

    if(*x == 359)
    {
        *sendable = 1;
    }

}
