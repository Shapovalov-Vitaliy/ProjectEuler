#include "Pocker.h"

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
		switch(temp)
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
		defualt: break;
		
	}
}

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


	for (int i = 0; i < 4; ++i)
	{
		if (first_hand[i].second != first_hand[++i].second)
			winner = SECOND_WIN;
		else if (second_hand[i].second != second_hand[++i].second)
			return NONE;
	}


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
	int winner = FIRST_WIN;


	for (int i = 0; i < 4; ++i)
	{
		if (first_hand[i].second != first_hand[++i].second)
			winner = SECOND_WIN;
		else if (second_hand[i].second != second_hand[++i].second)
			return NONE;
	}
	
	
	
	if(winner == FIRST_WIN)
	{
		vector<int> temp = value_to_int(second_hand);
		
		sort(begin(temp), end(temp));
		
		int p1 = temp.pop_front(); // TODO ruturn value???
		int p2 = temp.pop_front();
		
		if(p2.first - p1.first != 1)
			winner = SECOND_WIN;
		else
		{
			p1 = temp.pop_front()
			if(p1.first - p2.first != 1)
				winner = SECOND_WIN;
			else
			{
				p2 = temp.pop_front()
				if(p2.first - p1.first != 1)
					winner = SECOND_WIN;
				else
				{
					p1 = temp.pop_front()
					if(p1.first - p2.first != 1)
						winner = SECOND_WIN;
					else
						return FIRST_WIN;
				}	
			}
		}
	}
	
	if(winner == SECOND_WIN)
	{
		vector<int> temp = value_to_int(second_hand);
		
		sort(begin(temp), end(temp));
		
		int p1 = temp.pop_front(); // TODO ruturn value???
		int p2 = temp.pop_front();
		
		if(p2.first - p1.first != 1)
			return NONE;
		else
		{
			p1 = temp.pop_front()
			if(p1.first - p2.first != 1)
				return NONE;
			else
			{
				p2 = temp.pop_front()
				if(p2.first - p1.first != 1)
					return NONE;
				else
				{
					p1 = temp.pop_front()
					if(p1.first - p2.first != 1)
						return NONE;
					else
						return SECOND_WIN;
				}	
			}
		}
	}
}

int Pocker::compare_on_four_of_a_kind()
{
	int winner = FIRST_WIN;
	int high_first = 0;
	int high_second = 0;
	
	vector<int> temp = value_to_int(first_hand);
	
	sort(begin(temp), end(temp));
	
	if(temp[0] != temp[1] && temp[2] == temp[4] || temp[3] != temp[4] && temp[0] == temp[3])
		high_first = temp[4];
		
	temp.clear();
	temp = value_to_int(second_hand);
		
	sort(begin(temp), end(temp));
	
	if(temp[0] != temp[1] && temp[2] == temp[4] || temp[3] != temp[4] && temp[0] == temp[3])
		high_second = temp[4];

	if(high_first == high_second)
		return NONE;
	else if(high_first > high_second)
		return FIRST_WIN;
	else 
		return SECOND_WIN;
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

