// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include "SimpleTimer.h"

using namespace std;

int findTriplet()
{
    SimpleTimer timer;

    int a, b, c;

    for (a = 1; a <= 1000; ++a)
        for (b = a; b <= 1000; ++b)
            for (c = b; c <= 1000; ++c)
                if (a * a + b * b == c * c && a + b + c == 1000)
                {
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    cout << "c = " << c << endl;
                    return a * b * c;
                }
                    
}

int main()
{
    cout << "a * b * c = " << findTriplet() << endl << endl;

    return 0;
}