#include <iostream>

using namespace std;

/*
*Victory Conditions
    1. Number of rounds
    2. Number of victories
    3. Victory difference
*/

void game_loop(int victory_condition, int amount_to_end, int movements, bool is_competitive, bool is_multiplayer)
{
    bool victory_condition_met = false;
    int number_of_rounds = 0;
    int player1_victories = 0;
    int draws = 0;
    int player2_victories = 0;

    while(!victory_condition_met)
    {
        switch(victory_condition)
        {
            case 1:
                if(number_of_rounds == amount_to_end)
                {
                    if(player1_victories > player2_victories)
                    {
                        cout << "Player 1 won" << endl;
                    }
                    else if(player2_victories > player1_victories)
                    {
                        cout << "Player 2 won" << endl;
                    }
                    else
                    {
                        cout << "It was a draw" << endl;
                    }
                }
                break;
            case 2:
                if(player1_victories == amount_to_end)
                {
                    cout << "Player 1 won" << endl;
                }
                if(player2_victories == amount_to_end)
                {
                    cout << "Player 2 won" << endl;
                }
                break;
            case 3:
                if(player1_victories - player2_victories == amount_to_end)
                {
                    cout << "Player 1 won" << endl;
                }
                if(player2_victories - player1_victories == amount_to_end)
                {
                    cout << "Player 2 won" << endl;
                }
                break;
        }
    }
}

int main()
{

}