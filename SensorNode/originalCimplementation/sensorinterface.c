#include "fakesensor.h"
#include "errorhandle.h"

void collect_data(double* values, int* sendable)
{
    #if debug
            debug_msg("collect_data initialized\n");
    #endif

    int x = 0;

    #if debug
            debug_msg("Calling generate_data\n");
    #endif

    do
    {
        generate_data(&x, values, sendable);
        x++;
    } while(!*sendable);
}