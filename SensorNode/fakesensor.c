#include <math.h>

double generate_data()
{

    int x = 0;

    double values[360];

    do
    {
        values[x] = sin(x)
        x++;
    } while (x < 360);

    return values;

}