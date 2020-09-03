#include <iostream>
#include "Pocker.h"
#include <fstream>

using namespace std;

int main()
{
    Pocker game;

    ifstream table;
    table.open("Problem_54_Pocker_hands.txt");

    if (!table.is_open())
        return -1;

    vector<pair<char, char>> hands;

/*    while (!table.eof())
    {
        for (int i = 0; i < 20; ++i)
        {
            string str;
            
        }*/
        //    8C TS KC 9H 4S 7D 2S 5D 3S AC
        hands.emplace_back(make_pair('8', 'C'));
        hands.emplace_back(make_pair('T', 'S'));
        hands.emplace_back(make_pair('K', 'C'));
        hands.emplace_back(make_pair('9', 'H'));
        hands.emplace_back(make_pair('4', 'S'));
        hands.emplace_back(make_pair('7', 'D'));
        hands.emplace_back(make_pair('2', 'S'));
        hands.emplace_back(make_pair('5', 'D'));
        hands.emplace_back(make_pair('3', 'S'));
        hands.emplace_back(make_pair('A', 'C'));

        game.fill_hands(hands);

        cout << game.is_first_hand_win() << endl;
//    }
    table.close();

    return 0;
}