// Find the sum of all the primes below two million.

#include <iostream>
#include "SimpleTimer.h"
#include <cmath>

using namespace std;

const int limit = 2000000;

bool isPrime(int val)
{
    if (val % 2 == 0)
        return false;

    for (long int i = 3; i <= (int)sqrt(val); i += 2)
        if (val % i == 0)
            return false;

    return true;
}

long int findPrimeSum()
{
    SimpleTimer timer;

    long int result = 2; // include 2

    for (int i = 3; i < limit ; i += 2)
        if (isPrime(i))
            result += i;

    return result;
}

int main()
{
    cout << "The sum of all the primes below two million = " << findPrimeSum() << endl;

    return 0;
}