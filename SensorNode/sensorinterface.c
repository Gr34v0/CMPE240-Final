#include "fakesensor.h"
#include "errorhandle.h"

void collect_data(double* values, int sendable)
{
    #if debug
            debug_msg("collect_data initialized\n");
    #endif

    int x = 0;

    do
    {
        generate_data(x, values, sendable);
        x++;
    } while(!sendable);
}