// What is the value of the first triangle number to have over five hundred divisors?

#include <iostream>
#include <cmath>
#include "SimpleTimer.h"

using namespace std;

int numDiv(long long int val)
{
    int numberDiv = 2;

    for (long long int i = 2; i < sqrt(val); ++i)
        if (val % i == 0)
            numberDiv += 2;

    if (sqrt(val) * sqrt(val) == val)
        ++numberDiv;

    return numberDiv;
}

long long int findTriangleNumber()
{
    SimpleTimer timer;

    long long int result = 0;

    for (int i = 1; ; ++i)
    {
        result += i;
        if (numDiv(result) >= 500)
            return result;
    }
}

int main()
{
    cout << "The value of the first triangle number to have over five hundred divisors = " 
        << findTriangleNumber() << endl;

    return 0;
}