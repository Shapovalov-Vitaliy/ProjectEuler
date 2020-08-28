// Find the difference between the sum of the squares
// of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include "SimpleTimer.h"
#include <cmath>

using namespace std;

long int sum_of_the_squares()
{
    long int result = 0;

    for (int i = 1; i <= 100; ++i)
        result += i * i;

    return result;
}

long int square_of_the_sum()
{
    long int result = 0;

    for (int i = 1; i <= 100; ++i)
        result += i;

    return result * result;
}

long int findDif()
{
    SimpleTimer timer;
    return abs(sum_of_the_squares() - square_of_the_sum());
}

int main()
{
    cout << "The difference between the sum of the squares of the first one hundred "
         << endl << "natural numbers and the square of the sum = "
         << findDif() << endl << endl;
    
    return 0;
}