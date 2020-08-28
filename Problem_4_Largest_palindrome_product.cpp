// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include "SimpleTimer.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_polindrome(string str)
{
	if (str.size() > 1)
		for (size_t i = 0; i < str.size() / 2; i++)
			if (str[i] != str[str.size() - 1 - i])
				return false;

	return true;
}

int findPolindrome()
{
	SimpleTimer timer;

	vector<int> polindromes;

	for (int i = 999; i > 100; --i)
		for (int j = 999; j > 100; --j)
			if (is_polindrome(to_string(i * j)))
				polindromes.emplace_back(i*j);

	sort(begin(polindromes), end(polindromes));

	return polindromes.back();
}

int main()
{
	cout << "The largest palindrome made from the product of two 3-digit numbers = "
		 << findPolindrome() << endl << endl;

    return 0;
}