#include <math.h>

void generate_data(int x, double* values, int sendable)
{
    values[x] = sin(x);
    if(x == 359)
    {
        sendable = 1;
    }
}