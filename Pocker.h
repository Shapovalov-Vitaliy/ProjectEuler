#pragma once

#include <vector>
#include <string>
#include "SimpleTimer.h"

using namespace std;

class Pocker
{
private:
	vector<pair<char, char>> first_hand;
	vector<pair<char, char>> second_hand;

	vector<int> value_to_int(vector<pair<char, char>>&)
	bool find_value(char, vector<pair<char, char>>&);

	const enum high_values{
		TEN = 'T', JACK = 'J', QUEEN = 'Q', KING = 'K', ACE = 'A'
	};

	int compare_on_royal_flush();
	int compare_on_straight_flush();
	int compare_on_four_of_a_kind();
	int compare_on_full_house();
	int compare_on_flush();
	int compare_on_straight();
	int compare_on_three_of_a_kind();
	int compare_on_two_pairs();
	int compare_on_one_pair();
	int compare_on_high_card();

public:
	Pocker();
	void fill_hands(vector<pair<char, char>>);
	void clear_hands();
	bool is_first_hand_win();
};

