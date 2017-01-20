#include "locatevalue.h" // This line will be automatically added if you forget
#include <math.h>

/* Just a silly script for demonstration purposes. The function will
try to guess 'magic_number' given the range 'top' up to the precision
given by 'precision' by repeatedly splitting the distance to the
magic_number in half. */

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

