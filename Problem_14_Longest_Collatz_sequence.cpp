// Which starting number, under one million, produces the longest Collatz sequence?

#include <iostream>
#include "SimpleTimer.h"

using namespace std;

int findNumber()
{
    SimpleTimer timer;

    int length;
    int number;
    int resultNumber = 0;
    int resultLength = 0;

    for (int i = 999999; i > 13; --i)
    {
        number = i;
        length = 1;

        while (number > 1)
        {
            if (number % 2 == 0)
                number /= 2;
            else if (number % 2 == 1)
                number = number * 3 + 1;

            ++length;
        }

        if (length > resultLength)
        {
            resultNumber = i;
            resultLength = length;
        }
    }

    cout << "length = " << resultLength << endl;

    return resultNumber;
}

int main()
{
    cout << "With " << findNumber() << " (<1.000.000) produces the longest Collatz sequence"  << endl;

    return 0;
}