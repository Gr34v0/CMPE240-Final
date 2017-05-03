#include "fakesensor.h"

void collect_data()
{

    int x = 0;

    do
    {
        generate_data(x, values, sendable);
        x++
    } while(!sendable);
}