// What is the smallest positive number that is evenly divisible 
// by all of the numbers from 1 to 20?

#include <iostream>
#include "SimpleTimer.h"

using namespace std;

bool isMultiple(int q)
{
    for (int i = 11; i <= 20; ++i)
        if (q % i != 0)
            return false;

    return true;
}

int findMultiple()
{
    SimpleTimer timer;

    int result;
    for (int i = 20;; i += 20)
    {
        if (isMultiple(i))
            return i;
    }
}

int main()
{
    cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 = "
         << findMultiple() << endl << endl;

    return 0;
}