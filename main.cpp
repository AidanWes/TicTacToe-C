/* 
 * Author: Aidan Wesloskie
 * 
 * Main CPP to play TicTacToe
 *
 */

#include <cstdlib>
#include "TicTacToe.h"
using namespace std;

int main(int argc, char** argv) {
    //Create object for the game
    Game *g = new TicTacToe();
    //Start the game and return the outcome
    Game::who w=g->play();
    //If computer Wins
    if(w==Game::COMPUTER)
        cout<<"Congratulations! You win!\n";
    //If User wins
    else if (w==Game::HUMAN)
         cout<<"The computer wins the game!\n";
    //If its a tie
    else
        cout <<"The game ended in a tie!\n";

    return 0;
}

