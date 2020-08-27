// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include "SimpleTimer.h"
#include <cmath>
#include <vector>

using namespace std;

bool isPrimal(long double val)
{
	for (long double i = 2; i < sqrt(val); i++)
		if (fmod(val, i) == 0)
			return false;

	return true;
}

long double LargestFactor(long double val = 600851475143)
{
	SimpleTimer timer;

	vector<int> factors;

	for (long double i = 0; i <= sqrt(val); ++i)
		if (fmod(val, i) == 0 && isPrimal(i))
			factors.emplace_back((int)i);

	return factors.back();
}

int main()
{
	std::cout << "The largest prime factor of the number 600851475143 is "
		<< LargestFactor() << std::endl << std::endl;

	return 0;
}