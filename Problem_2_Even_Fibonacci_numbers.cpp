// By considering the terms in the Fibonacci sequence
// whose values do not exceed four million,
// find the sum of the even-valued terms.

#include <iostream>
#include "SimpleTimer.h"

using namespace std;

const int NUMBER = 4000000;

int Fibonacci_sum()
{
	SimpleTimer timer;

	int first = 1;		// the element before last
	int second = 2;		// last element
	int current = 0;	// current element

	int result = 2;		// second element was 2, we start with third

	while (current < NUMBER)
	{
		current = first + second;

		if (current >= NUMBER)
			return result;

		if (current % 2 == 0)
			result += current;

		first = second;
		second = current;
	}

	return result;
}

int main()
{
	cout << "Sum of even Fibonacci numbers whose values do not exceed four million = "
		<< Fibonacci_sum() << endl << endl;

	return 0;
}