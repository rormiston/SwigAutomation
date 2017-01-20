#include "locatevalue.h"
#include <math.h>


double LocateValue(double magic_number, int top, double precision)
{

    double guess = top / 2;

    while(fabs(guess - magic_number) > precision)
    {
        if (guess > magic_number)
        {
            guess = guess - (top - guess) / 2;
        }
        else
        {
            guess = guess + (top - guess) / 2;
        }
    }
    return guess;
}

