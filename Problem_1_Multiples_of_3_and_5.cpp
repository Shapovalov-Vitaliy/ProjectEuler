// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include "SimpleTimer.h"

using namespace std;

bool is_multiplie_of_three(int q) // q < 1000
{
    int a = 0;
    int b = 0;
    int c = 0;

    int temp;

    if (q >= 100)
    {
        temp = q % 100;
        a = (q - temp) / 100;
        q -=  a * 100;
    }
    if (q >= 10)
    {
        temp = q % 10;
        b = (q - temp) / 10;
        q -= b * 10;
    }
    c = q;

    return (a + b + c) % 3 == 0;
}

bool is_multiplie_of_five(int q)
{
    return q % 5 == 0 || q % 5 == 5;
}

int Sum_of_multiplies_of_three_and_five() // better for big values
{
    SimpleTimer timer;

    int result = 0;

    for (int i = 1; i < 1000; ++i)
        if (is_multiplie_of_five(i) || is_multiplie_of_three(i))
            result += i;

    return result;
}

int Hard_sum() // for check (better for small values)
{
    SimpleTimer timer;

    int result = 0;

    for (int i = 1; i < 1000; ++i)
        if (i % 3 == 0 || i % 5 == 0)
            result += i;

    return result;
}

int main()
{
    cout << "Sum of all the multiples of 3 or 5 below 1000 (variant 1) = "
        << Sum_of_multiplies_of_three_and_five() << endl << endl;

    cout << "Sum of all the multiples of 3 or 5 below 1000 (variant 2) = "
        << Hard_sum() << endl << endl;

    return 0;
}