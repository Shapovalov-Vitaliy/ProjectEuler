#include "Pocker.h"
#include <algorithm>

#define SECOND_WIN -2
#define FIRST_WIN -1
#define NONE 0

vector<int> Pocker::value_to_int(vector<pair<char, char>> &hand)
{
	vector<int> values;
	char temp;
	
	for(int i=0; i < 5; ++i)
	{
		temp = hand[i].first;
		switch (temp)
		{
		case '2':
			values.emplace_back(2);
			break;
		case '3':
			values.emplace_back(3);
			break;
		case '4':
			values.emplace_back(4);
			break;
		case '5':
			values.emplace_back(5);
			break;
		case '6':
			values.emplace_back(6);
			break;
		case '7':
			values.emplace_back(7);
			break;
		case '8':
			values.emplace_back(8);
			break;
		case '9':
			values.emplace_back(9);
			break;
		case 'T':
			values.emplace_back(10);
			break;
		case 'J':
			values.emplace_back(11);
			break;
		case 'Q':
			values.emplace_back(12);
			break;
		case 'K':
			values.emplace_back(13);
			break;
		case 'A':
			values.emplace_back(14);
			break;
		defualt: 
			break;
		}
	}

	return values;
}

bool Pocker::find_value(char val, vector<pair<char, char>> &hand)
{
	for (int i = 0; i < 5; ++i)
		if (hand[i].first == val)
			return true;

	return false;
}

int Pocker::ret_winner(int high_first, int high_second)
{
	if (high_first == 0 && high_second == 0)
		return NONE;
	else if (high_first > high_second)
		return FIRST_WIN;
	else if (high_first < high_second)
		return SECOND_WIN;
	else
		return compare_on_high_card();
}

int Pocker::compare_on_royal_flush()
{
	int winner = FIRST_WIN;

	for (int i = 0; i < 4; ++i)
	{
		if (first_hand[i].second != first_hand[i+1].second)
			winner = SECOND_WIN;
		if (second_hand[i].second != second_hand[i+1].second && winner == SECOND_WIN)
			return NONE;
	}

	if (winner == FIRST_WIN
		&& find_value('A', first_hand)
		&& find_value('K', first_hand)
		&& find_value('Q', first_hand)
		&& find_value('J', first_hand)
		&& find_value('T', first_hand))
		return FIRST_WIN;

	if (winner == SECOND_WIN
		&& find_value('A', second_hand)
		&& find_value('K', second_hand)
		&& find_value('Q', second_hand)
		&& find_value('J', second_hand)
		&& find_value('T', second_hand))
		return SECOND_WIN;

	return NONE;
}

int Pocker::compare_on_straight_flush()
{
	if (compare_on_straight() == compare_on_flush() && compare_on_flush() == FIRST_WIN)
		return FIRST_WIN;
	else if (compare_on_straight() == compare_on_flush() && compare_on_flush() == SECOND_WIN)
		return SECOND_WIN;
	else 
		return NONE;
}

int Pocker::compare_on_four_of_a_kind()
{
	int high_first = 0;
	int high_second = 0;
	
	vector<int> temp = value_to_int(first_hand);
	
	sort(begin(temp), end(temp));
	
	if(temp[0] != temp[1] && temp[1] == temp[4] || temp[3] != temp[4] && temp[0] == temp[3])
		high_first = temp[4];
		
	temp.clear();
	temp = value_to_int(second_hand);
		
	sort(begin(temp), end(temp));
	
	if(temp[0] != temp[1] && temp[1] == temp[4] || temp[3] != temp[4] && temp[0] == temp[3])
		high_second = temp[4];

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_full_house()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));

	if (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4] ||
		temp[0] ==  temp[1] && temp[1] == temp[2] && temp[3] == temp[4])
		high_first = temp[4];

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));

	if (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4] ||
		temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4])
		high_second = temp[4];

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_flush()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));
	high_first = temp[4];

	for(int i = 0; i < 4; ++i)
		if(first_hand[i].second != first_hand[i+1].second)
			high_first = 0;

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));
	high_second = temp[4];

	for (int i = 0; i < 4; ++i)
		if (second_hand[i].second != second_hand[i+1].second)
			high_second = 0;

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_straight()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));
	high_first = temp[4];

	for (int i = 4; i > 0; --i)
		if (temp[i] - temp[i-1] != 1)
			high_first = 0;

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));
	high_second = temp[4];

	for (int i = 4; i > 0; --i)
		if (temp[i] - temp[i-1] != 1)
			high_second = 0;

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_three_of_a_kind()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 3; ++i)
		if (temp[i] == temp[i+2])
			high_first = temp[4];

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 3; ++i)
		if (temp[i] == temp[i+2])
			high_second = temp[4];

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_two_pairs()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 4; ++i)
		if (temp[i] == temp[i+1])
			for (int q = i + 2; q < 4; ++q)
				if (temp[q] == temp[q+1])
					high_first = temp[4];

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 4; ++i)
		if (temp[i] == temp[i+1] && i <= 1)
			for (int q = i + 2; q < 4; ++q)
				if (temp[q] == temp[q+1])
					high_second = temp[4];

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_one_pair()
{
	int high_first = 0;
	int high_second = 0;

	vector<int> temp = value_to_int(first_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 4; ++i)
		if (temp[i] == temp[i+1])
			high_first = temp[4];

	temp.clear();
	temp = value_to_int(second_hand);

	sort(begin(temp), end(temp));

	for (int i = 0; i < 4; ++i)
		if (temp[i] == temp[i+1])
			high_first = temp[4];

	return ret_winner(high_first, high_second);
}

int Pocker::compare_on_high_card()
{
	vector<int> first = value_to_int(first_hand);
	vector<int> second = value_to_int(second_hand);

	sort(begin(first), end(first));
	sort(begin(second), end(second));

	for (int i = 4; i >= 1; --i)
	{
		if (first[i] > second[i])
			return FIRST_WIN;
		else if (first[i] < second[i])
			return SECOND_WIN;
		else
			continue;
	}

	return NONE;
}

Pocker::Pocker()
{
	SimpleTimer timer;
}

void Pocker::fill_hands(vector<pair<char, char>> str)
{
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
			first_hand.emplace_back(str[i]);
		else
			second_hand.emplace_back(str[i]);
	}
}

void Pocker::clear_hands()
{
	this->first_hand.clear();
	this->second_hand.clear();
}

bool Pocker::is_first_hand_win()
{
	if (compare_on_royal_flush() == FIRST_WIN)
		return true;
	else if (compare_on_royal_flush() == SECOND_WIN)
		return false;

	if (compare_on_straight_flush() == FIRST_WIN)
		return true;
	else if (compare_on_straight_flush() == SECOND_WIN)
		return false;

	if (compare_on_four_of_a_kind() == FIRST_WIN)
		return true;
	else if (compare_on_four_of_a_kind() == SECOND_WIN)
		return false;

	if (compare_on_full_house() == FIRST_WIN)
		return true;
	else if (compare_on_full_house() == SECOND_WIN)
		return false;

	if (compare_on_flush() == FIRST_WIN)
		return true;
	else if (compare_on_flush() == SECOND_WIN)
		return false;

	if (compare_on_straight() == FIRST_WIN)
		return true;
	else if (compare_on_straight() == SECOND_WIN)
		return false;

	if (compare_on_three_of_a_kind() == FIRST_WIN)
		return true;
	else if (compare_on_three_of_a_kind() == SECOND_WIN)
		return false;

	if (compare_on_two_pairs() == FIRST_WIN)
		return true;
	else if (compare_on_two_pairs() == SECOND_WIN)
		return false;

	if (compare_on_one_pair() == FIRST_WIN)
		return true;
	else if (compare_on_one_pair() == SECOND_WIN)
		return false;

	if (compare_on_high_card() == FIRST_WIN)
		return true;
	
	return false;
}

