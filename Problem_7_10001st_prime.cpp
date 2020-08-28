// What is the 10001st prime number ?

#include <iostream>
#include "SimpleTimer.h"
#include <cmath>

using namespace std;

const int num = 10001 - 1;

bool isPrime(long int val)
{
    if (val % 2 == 0)
        return false;

    for (long int i = 3; i <= (long int)sqrt(val); i += 2)
        if (val % i == 0)
            return false;

    return true;
}

long int findPrime()
{
    SimpleTimer timer;

    int counter = 1; // include 2
    long int result = 0;

    
    for (long int i = 3; counter <= num; i += 2)
    {
        if (isPrime(i))
        {
            if (counter == num)
                result = i;
            ++counter;
        }
    }

    return result;
}

int main()
{
    cout << findPrime() << endl;

    return 0;
}