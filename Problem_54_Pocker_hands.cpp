// The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated
// by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid
// (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
// How many hands does Player 1 win ?

#include <iostream>
#include "Pocker.h"
#include <fstream>

using namespace std;

int main()
{
    Pocker game;
    int counter = 0;

    ifstream table;
    table.open("Problem_54_Pocker_hands.txt");

    if (!table.is_open())
        return -1;

    vector<pair<char, char>> hands;
    string pair;

    while (!table.eof())
    {
        for (int i = 0; i < 10; i++)
        {
            table >> pair;
            hands.emplace_back(make_pair(pair[0], pair[1]));
        }
        
        game.fill_hands(hands);
        if (game.is_first_hand_win())
            ++counter;

        hands.clear();
        game.clear_hands();
    }

    cout << "First player won " << counter << " games" << endl;

    table.close();

    return 0;
}