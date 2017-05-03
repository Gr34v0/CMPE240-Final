#include "fakesensor.h"

void collect_data(double* values, int sendable)
{

    int x = 0;

    do
    {
        generate_data(x, values, sendable);
        x++;
    } while(!sendable);
}