#include "Pocker.h"

#define SECOND_WIN -2
#define FIRST_WIN -1
#define NONE 0


bool Pocker::find_value(char val, vector<pair<char, char>> &hand)
{
	for (int i = 0; i < 5; ++i)
		if (hand[i].first == val)
			return true;

	return false;
}

int Pocker::compare_on_royal_flush()
{
	int winner = FIRST_WIN;

	// сравниваеем масти
	for (int i = 0; i < 4; ++i)
	{
		if (first_hand[i].second != first_hand[++i].second)
			winner = SECOND_WIN;
		else if (second_hand[i].second != second_hand[++i].second)
			return NONE;
	}

	// сравниваем значения
	if (winner == FIRST_WIN
		&& find_value(ACE, first_hand)
		&& find_value(KING, first_hand)
		&& find_value(QUEEN, first_hand)
		&& find_value(JACK, first_hand)
		&& find_value(TEN, first_hand))
		return FIRST_WIN;

	if (winner == SECOND_WIN
		&& find_value(ACE, second_hand)
		&& find_value(KING, second_hand)
		&& find_value(QUEEN, second_hand)
		&& find_value(JACK, second_hand)
		&& find_value(TEN, second_hand))
		return SECOND_WIN;

	return NONE;
}

int Pocker::compare_on_straight_flush()
{
	return 0;
}

int Pocker::compare_on_four_of_a_kind()
{
	return 0;
}

int Pocker::compare_on_full_house()
{
	return 0;
}

int Pocker::compare_on_flush()
{
	return 0;
}

int Pocker::compare_on_straight()
{
	return 0;
}

int Pocker::compare_on_three_of_a_kind()
{
	return 0;
}

int Pocker::compare_on_two_pairs()
{
	return 0;
}

int Pocker::compare_on_one_pair()
{
	return 0;
}

int Pocker::compare_on_high_card()
{
	return 0;
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

